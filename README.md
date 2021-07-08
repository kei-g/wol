# wol

Wake-On-LAN client

## How to build

### with default cc

```shell
./configure && make
```

### with clang

```shell
./configure CC=clang LD=clang && make
```

### without symbols for debug

```shell
./configure CC=clang LD=clang LDFLAGS="-Wl,-s" && make
```

### with optimizations

```shell
./configure CC=clang CFLAGS="-Ofast -march=native" LD=clang LDFLAGS="-Wl,-s" && make
```

## How to install

```shell
make install
```

## Usage

```shell
wol 12:34:56:78:9a:bc
```

[![Travis CI](https://img.shields.io/travis/com/kei-g/wol?logo=travis&style=plastic)](https://www.travis-ci.com/github/kei-g/wol)
[![License](https://img.shields.io/github/license/kei-g/wol?style=plastic)](https://opensource.org/licenses/BSD-3-Clause)
