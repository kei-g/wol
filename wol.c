#ifdef HAVE_CONFIG_H
  #include "config.h"
#endif

#ifndef WIN32
  #include <arpa/inet.h>
  #include <netdb.h>
  #include <netinet/in.h>
#endif /* WIN32 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef WIN32
  #include <winsock2.h>
  #include <ws2tcpip.h>
#else /* WIN32 */
  #include <sys/socket.h>
  #include <sys/types.h>
  #include <unistd.h>
#endif /* WIN32 */

#ifdef WIN32
  #define close closesocket
  #define perror(name) fprintf(stderr, name ": %08lx\n", GetLastError())
#else  /* WIN32 */
  #define WSACleanup()
#endif /* WIN32 */

#include "version.h"

typedef struct wol_option wolopt;

struct wol_option {
  struct addrinfo *bindaddr;
  uint8_t macaddr[6];
};

static bool allow_broadcast(int sock) {
#ifdef WIN32
  char yes = 1;
#else  /* WIN32 */
  int yes = 1;
#endif /* WIN32 */
  if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &yes, sizeof(yes)) < 0) {
    perror("setsockopt");
    close(sock);
    return false;
  }
  return true;
}

static bool bind_any(int sock, struct addrinfo *bindaddr) {
  for (struct addrinfo *a = bindaddr; a; a = a->ai_next)
    if (bind(sock, a->ai_addr, a->ai_addrlen) == 0)
      return true;
  perror("bind");
  return false;
}

static bool parse_bindaddr(char *addrstr, struct addrinfo **addrp) {
  struct addrinfo hints = {.ai_socktype = SOCK_DGRAM}, *res;
  int ret = getaddrinfo(addrstr, "0", &hints, &res);
  if (ret) {
    fprintf(stderr, "getaddrinfo(\"%s\"): %s\n", addrstr,
            gai_strerror(ret));
    return false;
  }
  *addrp = res;
  return true;
}

static bool parse_macaddr(char *argv, uint8_t macaddr[6]) {
  uint8_t *dst = macaddr;
  for (char *tok, *s = strtok_r(argv, ":", &tok), n = 0; s && n < 6;
       s = strtok_r(NULL, ":", &tok), n++) {
    char *ep;
    unsigned long ul = strtoul(s, &ep, 16);
    if (*ep || UINT8_MAX < ul) {
      fprintf(stderr, "invalid argument, %s\n", s);
      return false;
    }
    *dst++ = (uint8_t)ul;
  }
  if (dst < macaddr + 6) {
    fputs("too short macaddr\n", stderr);
    return false;
  }
  return true;
}

static bool parse_opts(int argc, char *argv[], wolopt *opt) {
  if (argc < 2) {
    fputs("too few argument\n", stderr);
    return false;
  }
  opt->bindaddr = NULL;
  for (int i = 1; i < argc; i++) {
    char *val, *key = strtok_r(argv[i], "=", &val);
    if (strcmp(key, "--bind") == 0) {
      if (opt->bindaddr) {
        fputs("multiple bind address is not allowed\n", stderr);
        return false;
      }
      if ((!val || !*val) && ++i == argc) {
        fputs("missing an address to bind\n", stderr);
        return false;
      }
      if (!parse_bindaddr(val && *val ? val : argv[i], &opt->bindaddr))
        return false;
    }
    else if (strcmp(key, "--version") == 0) {
      puts("wol version " WOL_VERSION);
      return false;
    }
    else
      return parse_macaddr(argv[i], opt->macaddr);
  }
  fputs("missing a macaddr\n", stderr);
  return false;
}

int main(int argc, char *argv[]) {
#ifdef WIN32
  WSADATA wsa;
  WSAStartup(MAKEWORD(2, 0), &wsa);
#endif /* WIN32 */
  wolopt opt;
  if (!parse_opts(argc, argv, &opt)) {
    WSACleanup();
    return 1;
  }
  int sock = socket(AF_INET, SOCK_DGRAM, 0);
  if (sock < 0) {
    perror("socket");
    if (opt.bindaddr)
      freeaddrinfo(opt.bindaddr);
    WSACleanup();
    return 1;
  }
  if (!allow_broadcast(sock)) {
    if (opt.bindaddr)
      freeaddrinfo(opt.bindaddr);
    WSACleanup();
    return 1;
  }
  if (opt.bindaddr) {
    bool bound = bind_any(sock, opt.bindaddr);
    freeaddrinfo(opt.bindaddr);
    opt.bindaddr = NULL;
    if (!bound) {
      close(sock);
      WSACleanup();
      return 1;
    }
  }
  struct sockaddr_in raddr;
  memset(&raddr, 0, sizeof(raddr));
  raddr.sin_family = AF_INET;
  raddr.sin_port = htons(9);
  raddr.sin_addr.s_addr = -1;
  char msg[102];
  memset(msg, -1, 6);
  for (int i = 0; i < 16; i++)
    memcpy(msg + (i + 1) * 6, opt.macaddr, 6);
  ssize_t wlen = sendto(sock, msg, sizeof(msg), 0,
                        (struct sockaddr *)&raddr, sizeof(raddr));
  if (wlen < 0) {
    perror("sendto");
    close(sock);
    WSACleanup();
    return 1;
  }
  close(sock);
  WSACleanup();
  return 0;
}
