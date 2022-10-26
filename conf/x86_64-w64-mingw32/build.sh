#!/bin/sh
clang \
  --target=x86_64-w64-mingw32 \
  -L /usr/lib/gcc/$arch-w64-mingw32/10-win32 \
  -Oz \
  -Wall \
  -Werror \
  -Wextra \
  -Wl,-s \
  -flto \
  -fuse-ld=lld \
  -lws2_32 \
  -o wol.exe \
  -pedantic \
  wol.c
