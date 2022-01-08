# wol [![license][license-image]][license-url]

[![GitHub CI (Build)][github-build-image]][github-build-url] [![travis][travis-image]][travis-url]

Wake-On-LAN client

## How to build

### Install packages to build

To build with clang, on linux :penguin:,

```shell
apt-get install automake clang make
```

or, to build with gcc, on linux :penguin:,

```shell
apt-get install automake gcc make
```

### Pre-configure

```shell
aclocal
autoheader
automake -a -c
autoconf
```

### with default cc

```shell
./configure --disable-dependency-tracking && make
```

### with clang

```shell
./configure --disable-dependency-tracking CC=clang LD=clang && make
```

### without symbols for debug

```shell
./configure --disable-dependency-tracking CC=clang LD=clang LDFLAGS="-Wl,-s" && make
```

### with optimizations

```shell
./configure --disable-dependency-tracking CC=clang CFLAGS="-Oz -march=native" LD=clang LDFLAGS="-Wl,-s" && make
```

## How to install

```shell
make install
```

## Usage

```shell
wol 12:34:56:78:9a:bc
```

[github-build-image]:https://github.com/kei-g/wol/actions/workflows/build.yml/badge.svg
[github-build-url]:https://github.com/kei-g/wol/actions/workflows/build.yml
[github-url]:https://github.com/kei-g/wol
[license-image]:https://img.shields.io/github/license/kei-g/wol
[license-url]:https://opensource.org/licenses/BSD-3-Clause
[travis-image]:https://img.shields.io/travis/com/kei-g/wol/main?label=build&logo=travis
[travis-url]:https://app.travis-ci.com/kei-g/wol
