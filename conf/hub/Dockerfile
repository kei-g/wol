FROM debian:stable-slim AS builder

ARG PACKAGES="automake gnupg lsb-release make software-properties-common wget"

RUN DEBIAN_FRONTEND=noninteractive \
  && apt-get update \
  && apt-get install -y ${PACKAGES} \
  && wget -O - https://apt.llvm.org/llvm.sh \
  | bash -s

COPY wol.c /

RUN clang-13 -Oz -Wall -Werror -Wextra -Wl,-s -flto -fno-plt -fuse-ld=lld -o wol wol.c

FROM busybox:glibc

COPY --from=builder wol /usr/local/bin/

ENTRYPOINT ["/usr/local/bin/wol"]
