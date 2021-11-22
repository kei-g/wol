# wol [![license][license-image]][license-url]

[![github][github-test-image]][github-url] [![travis][travis-image]][travis-url]

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
touch NEWS ChangeLog
mv README.md README
automake -a -c
autoconf
```

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

[github-test-image]:https://img.shields.io/github/workflow/status/kei-g/wol/build/main?label=build&logo=github
[github-url]:https://github.com/kei-g/wol
[license-image]:https://img.shields.io/github/license/kei-g/wol
[license-url]:https://opensource.org/licenses/BSD-3-Clause
[travis-image]:https://img.shields.io/travis/com/kei-g/wol/main?label=build&logo=travis
[travis-url]:https://app.travis-ci.com/kei-g/wol
