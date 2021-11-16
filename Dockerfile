FROM debian:latest

ENV DEBCONF_NOWARNINGS yes
ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update && \
	apt-get upgrade -y && \
	apt-get dist-upgrade -y && \
	apt-get autoremove --purge -y && \
	apt-get install -y \
		autoconf \
		automake \
		clang \
		make

COPY AUTHORS ./
COPY COPYING ./
COPY Makefile.am ./
COPY README.md ./README
COPY config.h.in ./
COPY configure.ac ./
COPY wol.c ./

RUN aclocal && \
	autoheader && \
	touch NEWS ChangeLog && \
	automake -a -c && \
	autoconf && \
	./configure --disable-dependency-tracking \
		CC=clang \
		CFLAGS="-Ofast -Wall -Werror -march=native" \
		LD=clang \
		LDFLAGS="-Wl,-s" && \
	make