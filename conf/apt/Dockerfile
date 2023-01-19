FROM snowstep/cross-debian:latest

ARG VERSION

ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update \
  && apt-get upgrade --no-install-recommends -y

WORKDIR /root

COPY conf/apt/control version.h wol.c ./

ARG CFLAGS="-Oz -Wall -Werror -Wextra -Wl,-s -flto -fno-plt -fuse-ld=lld"

RUN dest=wol_${VERSION}_amd64 \
  && mkdir -p $dest/DEBIAN $dest/usr/local/bin \
  && clang ${CFLAGS} -o $dest/usr/local/bin/wol --target=x86_64-pc-linux-gnu wol.c \
  && sed -e "s/%ARCH%/amd64/" < control | sed -e "s/%VERSION%/${VERSION}/" > $dest/DEBIAN/control \
  && dpkg --build $dest

RUN dest=wol_${VERSION}_arm64 \
  && mkdir -p $dest/DEBIAN $dest/usr/local/bin \
  && clang ${CFLAGS} -o $dest/usr/local/bin/wol --target=aarch64-pc-linux-gnu wol.c \
  && sed -e "s/%ARCH%/arm64/" < control | sed -e "s/%VERSION%/${VERSION}/" > $dest/DEBIAN/control \
  && dpkg --build $dest

RUN dest=wol_${VERSION}_armhf \
  && mkdir -p $dest/DEBIAN $dest/usr/local/bin \
  && clang ${CFLAGS} -o $dest/usr/local/bin/wol --target=arm-pc-linux-gnueabihf wol.c \
  && sed -e "s/%ARCH%/arm/" < control | sed -e "s/%VERSION%/${VERSION}/" > $dest/DEBIAN/control \
  && dpkg --build $dest

RUN dest=wol_${VERSION}_i386 \
  && mkdir -p $dest/DEBIAN $dest/usr/local/bin \
  && clang ${CFLAGS} -o $dest/usr/local/bin/wol --target=i386-pc-linux-gnu wol.c \
  && sed -e "s/%ARCH%/i386/" < control | sed -e "s/%VERSION%/${VERSION}/" > $dest/DEBIAN/control \
  && dpkg --build $dest
