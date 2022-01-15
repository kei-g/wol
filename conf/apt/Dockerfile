FROM snowstep/cross-debian:latest

ARG VERSION

WORKDIR /root

COPY conf/apt/control wol.c ./

ARG CFLAGS="-Oz -Wall -Werror -Wextra -Wl,-s -fno-exceptions -fno-rtti -fuse-ld=lld"

ENV DEST=wol_${VERSION}_amd64
RUN mkdir -p $DEST/DEBIAN $DEST/usr/local/bin \
  && clang ${CFLAGS} -o $DEST/usr/local/bin/wol --target=x86_64-pc-linux-gnu wol.c \
  && sed -e "s/%ARCH%/amd64/" < control | sed -e "s/%VERSION%/${VERSION}/" > $DEST/DEBIAN/control \
  && dpkg --build $DEST

ENV DEST=wol_${VERSION}_arm64
RUN mkdir -p $DEST/DEBIAN $DEST/usr/local/bin \
  && clang ${CFLAGS} -o $DEST/usr/local/bin/wol --target=aarch64-pc-linux-gnu wol.c \
  && sed -e "s/%ARCH%/arm64/" < control | sed -e "s/%VERSION%/${VERSION}/" > $DEST/DEBIAN/control \
  && dpkg --build $DEST

ENV DEST=wol_${VERSION}_armhf
RUN mkdir -p $DEST/DEBIAN $DEST/usr/local/bin \
  && clang ${CFLAGS} -o $DEST/usr/local/bin/wol --target=arm-pc-linux-gnueabihf wol.c \
  && sed -e "s/%ARCH%/arm/" < control | sed -e "s/%VERSION%/${VERSION}/" > $DEST/DEBIAN/control \
  && dpkg --build $DEST

ENV DEST=wol_${VERSION}_i386
RUN mkdir -p $DEST/DEBIAN $DEST/usr/local/bin \
  && clang ${CFLAGS} -o $DEST/usr/local/bin/wol --target=i386-pc-linux-gnu wol.c \
  && sed -e "s/%ARCH%/i386/" < control | sed -e "s/%VERSION%/${VERSION}/" > $DEST/DEBIAN/control \
  && dpkg --build $DEST
