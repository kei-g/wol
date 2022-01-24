FROM debian:stable-slim AS builder

ARG PACKAGES="automake gnupg lsb-release make software-properties-common wget"

RUN DEBIAN_FRONTEND=noninteractive \
  && apt-get update \
  && apt-get install -y ${PACKAGES} \
  && wget -O - https://apt.llvm.org/llvm.sh \
  | bash -s

COPY autotools/* wol.c /

RUN aclocal \
  && autoheader \
  && automake -a -c \
  && autoconf \
  && CC=clang-13 \
  CFLAGS="-Oz -Wall -Werror -Wextra -fno-exceptions -fno-rtti" \
  LD=clang-13 \
  LDFLAGS="-Wl,-s -fuse-ld=lld" \
  ./configure --disable-dependency-tracking \
  && make

FROM busybox:glibc

COPY --from=builder wol /usr/local/bin/

ENTRYPOINT ["/usr/local/bin/wol"]
