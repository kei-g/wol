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
		lld \
		make

COPY AUTHORS ./
COPY COPYING ./
COPY ChangeLog ./
COPY Makefile.am ./
COPY NEWS ./
COPY README ./
COPY configure.ac ./
COPY wol.c ./

RUN aclocal && \
	autoheader && \
	automake -a -c && \
	autoconf && \
	./configure --disable-dependency-tracking \
		CC=clang \
		CFLAGS="-Oz -Wall -Werror -Wextra -fno-exceptions -fno-rtti" \
		LD=clang \
		LDFLAGS="-Wl,-s -fuse-ld=lld" && \
	make
