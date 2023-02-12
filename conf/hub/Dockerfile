FROM snowstep/llvm:latest AS builder

COPY version.h wol.c /

RUN clang \
    -Oz \
    -Wall \
    -Werror \
    -Wextra \
    -Wl,--lto-O3 \
    -Wl,-s \
    -flto \
    -fno-plt \
    -fuse-ld=lld \
    -o wol \
    -pedantic \
    -std=c2x \
    wol.c

FROM busybox:glibc

COPY --from=builder wol /usr/local/bin/

ENTRYPOINT ["/usr/local/bin/wol"]
