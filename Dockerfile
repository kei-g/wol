FROM debian:latest AS builder

ENV DEBCONF_NOWARNINGS=yes
ENV DEBIAN_FRONTEND=noninteractive

ARG PACKAGES="automake gnupg lsb-release make software-properties-common wget"

RUN apt-get update && \
	apt-get upgrade -y && \
	apt-get install -y ${PACKAGES} && \
	bash -c "$(wget -O - https://apt.llvm.org/llvm.sh)"

COPY AUTHORS ./
COPY COPYING ./
COPY ChangeLog ./
COPY Makefile.am ./
COPY NEWS ./
COPY README ./
COPY configure.ac ./
COPY wol.c ./

ENV CC=clang-13
ENV CFLAGS="-Oz -Wall -Werror -Wextra -fno-exceptions -fno-rtti"
ENV LD=clang-13
ENV LDFLAGS="-Wl,-s -fuse-ld=lld"

RUN aclocal && \
	autoheader && \
	automake -a -c && \
	autoconf && \
	./configure --disable-dependency-tracking && \
	make

FROM debian:latest

COPY --from=builder /wol /usr/local/bin/

ENTRYPOINT ["/usr/local/bin/wol"]
