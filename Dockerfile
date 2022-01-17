FROM debian:stable-slim AS builder

ENV DEBCONF_NOWARNINGS=yes
ENV DEBIAN_FRONTEND=noninteractive

ARG PACKAGES="automake gnupg lsb-release make software-properties-common wget"

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y ${PACKAGES}
RUN wget -O - https://apt.llvm.org/llvm.sh | bash -s

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

RUN aclocal
RUN autoheader
RUN automake -a -c
RUN autoconf
RUN ./configure --disable-dependency-tracking
RUN make

FROM busybox:glibc

COPY --from=builder /wol /usr/local/bin/

ENTRYPOINT ["/usr/local/bin/wol"]
