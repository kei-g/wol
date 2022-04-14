FROM snowstep/cross-debian:latest

ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update \
  && apt-get upgrade -y

WORKDIR /root

COPY wol.c ./

ARG CFLAGS="-Oz -Wall -Werror -Wextra -Wl,-s -flto -fuse-ld=lld -lws2_32 -pedantic"

RUN for arch in i686 x86_64; do \
    mkdir -pv $arch; \
    clang \
      --target=$arch-w64-mingw32 \
      ${CFLAGS} \
      -o $arch/wol.exe \
      wol.c; \
  done
