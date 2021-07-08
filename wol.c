#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif

#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif

#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif

#include <stdio.h>

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

#ifdef HAVE_STRING_H
#include <string.h>
#endif

#ifdef HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif

#include <sys/types.h>

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fputs("too few argument\n", stderr);
		return 1;
	}
	uint8_t macaddr[6], *dst = macaddr;
	for (char *tok, *s = strtok_r(argv[1], ":", &tok), n = 0; s && n < 6;
		s = strtok_r(NULL, ":", &tok), n++) {
		char *ep;
		unsigned long ul = strtoul(s, &ep, 16);
		if (*ep || UINT8_MAX < ul) {
			fprintf(stderr, "invalid argument, %s\n", s);
			return 1;
		}
		*dst++ = (uint8_t)ul;
	}
	if (dst < macaddr + 6) {
		fputs("too short macaddr\n", stderr);
		return 1;
	}
	int sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0) {
		perror("socket");
		return 1;
	}
	int bc = 1;
	if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &bc, sizeof(bc)) < 0) {
		perror("setsockopt");
		close(sock);
		return 1;
	}
	struct sockaddr_in raddr;
	memset(&raddr, 0, sizeof(raddr));
	raddr.sin_family = AF_INET;
	raddr.sin_port = htons(9);
	raddr.sin_addr.s_addr = -1;
	uint8_t msg[102];
	memset(msg, -1, 6);
	for (int i = 0; i < 16; i++)
		memcpy(msg + (i + 1) * 6, macaddr, 6);
	ssize_t wlen = sendto(sock, msg, sizeof(msg), 0,
		(struct sockaddr *)&raddr, sizeof(raddr));
	if (wlen < 0) {
		perror("sendto");
		close(sock);
		return 1;
	}
	close(sock);
	return 0;
}
