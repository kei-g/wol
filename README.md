# wol [![license][license-image]][license-url]

[![GitHub CI (Build)][github-build-image]][github-build-url] [![GitHub CI (CodeQL)][github-codeql-image]][github-codeql-url]

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

## License

The source codes and documentation in this project are released under the [BSD-3-Clause License](https://github.com/kei-g/wol/blob/main/COPYING).

## Contributions

Contributions are welcome! See [Contributor's Guide](https://github.com/kei-g/wol/blob/main/CONTRIBUTING.md).

## Code of Conduct

:clap: Be nice. See [our code of conduct](https://github.com/kei-g/wol/blob/main/CODE_OF_CONDUCT.md).

[github-build-image]:https://github.com/kei-g/wol/actions/workflows/build.yml/badge.svg
[github-build-url]:https://github.com/kei-g/wol/actions/workflows/build.yml
[github-codeql-image]:https://github.com/kei-g/wol/actions/workflows/codeql.yml/badge.svg
[github-codeql-url]:https://github.com/kei-g/wol/actions/workflows/codeql.yml
[github-url]:https://github.com/kei-g/wol
[license-image]:https://img.shields.io/github/license/kei-g/wol
[license-url]:https://opensource.org/licenses/BSD-3-Clause
