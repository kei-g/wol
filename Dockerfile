FROM debian:latest

ENV DEBCONF_NOWARNINGS yes
ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update && \
	apt-get install -y \
		gnupg \
		lsb-release \
		software-properties-common \
		wget && \
	bash -c "$(wget -O - https://apt.llvm.org/llvm.sh)" && \
	apt-get install -y \
		automake \
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
		CC=clang-13 \
		CFLAGS="-Oz -Wall -Werror -Wextra -fno-exceptions -fno-rtti" \
		LD=clang-13 \
		LDFLAGS="-Wl,-s -fuse-ld=lld" && \
	make
