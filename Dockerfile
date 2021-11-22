FROM debian:latest

ENV DEBCONF_NOWARNINGS yes
ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update && \
	apt-get upgrade -y && \
	apt-get dist-upgrade -y && \
	apt-get autoremove --purge -y && \
	apt-get install -y \
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
	touch ChangeLog NEWS && \
	mv README.md README && \
	automake -a -c && \
	autoconf && \
	./configure --disable-dependency-tracking \
		CC=clang \
		CFLAGS="-Ofast -Wall -Werror -march=native" \
		LD=clang \
		LDFLAGS="-Wl,-s" && \
	make
