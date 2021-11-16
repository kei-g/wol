FROM debian:latest

RUN apt-get update && apt-get upgrade -y && apt-get install autoconf automake clang make -y

COPY AUTHORS ./
COPY COPYING ./
COPY Makefile.am ./
COPY README.md ./README
COPY config.h.in ./
COPY configure.ac ./
COPY wol.c ./

RUN aclocal
RUN autoheader
RUN touch NEWS ChangeLog
RUN automake -a -c
RUN autoconf
RUN ./configure --disable-dependency-tracking CC=clang CFLAGS="-Ofast -Wall -Werror -march=native" LD=clang LDFLAGS="-Wl,-s"
RUN make
