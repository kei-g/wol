#!/bin/sh
clang --target=x86_64-w64-mingw32 -Oz -Wall -Werror -Wextra -Wl,-s -flto -fuse-ld=lld -lws2_32 -o wol.exe -pedantic wol.c
