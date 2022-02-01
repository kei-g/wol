#ifdef HAVE_CONFIG_H
  #include "config.h"
#endif

#ifndef WIN32
  #include <arpa/inet.h>
  #include <netinet/in.h>
#endif /* WIN32 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef WIN32
  #include <winsock2.h>
#else /* WIN32 */
  #include <sys/socket.h>
  #include <sys/types.h>
  #include <unistd.h>
#endif /* WIN32 */

#ifdef WIN32
  #define close closesocket
  #define perror(name) \
    fprintf(stderr, name ": %08lx\n", GetLastError())
#else /* WIN32 */
  #define WSACleanup()
#endif /* WIN32 */

static bool allow_broadcast(int sock) {
  int yes = 1;
  if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &yes, sizeof(yes)) < 0) {
    perror("setsockopt");
    close(sock);
    WSACleanup();
    return false;
  }
  return true;
}

static bool parse_opts(int argc, char *argv[], uint8_t macaddr[6]) {
  if (argc < 2) {
    fputs("too few argument\n", stderr);
    return false;
  }
  uint8_t *dst = macaddr;
  for (char *tok, *s = strtok_r(argv[1], ":", &tok), n = 0; s && n < 6;
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

int main(int argc, char *argv[]) {
  uint8_t macaddr[6];
  if (!parse_opts(argc, argv, macaddr))
    return 1;
#ifdef WIN32
  WSADATA wsa;
  WSAStartup(MAKEWORD(2, 0), &wsa);
#endif /* WIN32 */
  int sock = socket(AF_INET, SOCK_DGRAM, 0);
  if (sock < 0) {
    perror("socket");
    WSACleanup();
    return 1;
  }
  if (!allow_broadcast(sock))
    return 1;
  struct sockaddr_in raddr;
  memset(&raddr, 0, sizeof(raddr));
  raddr.sin_family = AF_INET;
  raddr.sin_port = htons(9);
  raddr.sin_addr.s_addr = -1;
  char msg[102];
  memset(msg, -1, 6);
  for (int i = 0; i < 16; i++)
    memcpy(msg + (i + 1) * 6, macaddr, 6);
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
