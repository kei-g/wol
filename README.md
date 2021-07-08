# wol

Wake-On-LAN client

## How to build

### with default cc

```shell
./configure && make
```

### with clang

```shell
env CC=clang LD=clang ./configure && make
```

### without symbols for debug

```shell
env CC=clang LD=clang LDFLAGS="-Wl,-s" ./configure && make
```

### with optimizations

```shell
env CC=clang CFLAGS="-Ofast -march=native" LD=clang LDFLAGS="-Wl,-s" ./configure && make
```

## How to install

```shell
make install
```

[![License](https://img.shields.io/github/license/kei-g/wol?style=plastic)](https://opensource.org/licenses/BSD-3-Clause)
