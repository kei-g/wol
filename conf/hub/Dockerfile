FROM snowstep/llvm:latest AS builder

COPY version.h wol.c /

RUN clang \
    -Oz \
    -Wall \
    -Werror \
    -Wextra \
    -Wl,-s \
    -flto \
    -fno-plt \
    -fuse-ld=lld \
    -o wol \
    wol.c

FROM busybox:glibc

COPY --from=builder wol /usr/local/bin/

ENTRYPOINT ["/usr/local/bin/wol"]
