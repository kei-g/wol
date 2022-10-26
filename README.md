# wol [![githuhb][github-repo-image]][github-repo-url] [![license][license-image]][license-url] [![docker][docker-image]][docker-url]

`wol` - Wake-On-LAN Client

## CI Status

| | Build | CodeQL | MinGW |
| ---- | ---- | ---- | ---- |
| **devel** | [![GitHub CI (Build)][github-devel-build-image]][github-devel-build-url] | [![GitHub CI (CodeQL)][github-devel-codeql-image]][github-devel-codeql-url] | [![GitHub CI (MinGW)][github-devel-mingw-image]][github-devel-mingw-url] |
| **main** | [![GitHub CI (Build)][github-main-build-image]][github-main-build-url] | [![GitHub CI (CodeQL)][github-main-codeql-image]][github-main-codeql-url] | [![GitHub CI (MinGW)][github-main-mingw-image]][github-main-mingw-url] |

## How to use

```shell
docker run --rm snowstep/wol 00:00:5e:00:53:00
```

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
wol 00:00:5e:00:53:00
```

## License

The source codes and documentation in this project are released under the [BSD-3-Clause License](https://github.com/kei-g/wol/blob/main/COPYING).

## Contributions

Contributions are welcome! See [Contributor's Guide](https://github.com/kei-g/wol/blob/main/CONTRIBUTING.md).

## Code of Conduct

:clap: Be nice. See [our code of conduct](https://github.com/kei-g/wol/blob/main/CODE_OF_CONDUCT.md).

[docker-image]:https://img.shields.io/docker/v/snowstep/wol?logo=docker
[docker-url]:https://hub.docker.com/r/snowstep/wol
[github-devel-build-image]:https://github.com/kei-g/wol/actions/workflows/build.yml/badge.svg?branch=devel
[github-devel-build-url]:https://github.com/kei-g/wol/actions/workflows/build.yml?query=branch%3Adevel
[github-devel-codeql-image]:https://github.com/kei-g/wol/actions/workflows/codeql.yml/badge.svg?branch=devel
[github-devel-codeql-url]:https://github.com/kei-g/wol/actions/workflows/codeql.yml?query=branch%3Adevel
[github-devel-mingw-image]:https://github.com/kei-g/wol/actions/workflows/mingw.yml/badge.svg?branch=devel
[github-devel-mingw-url]:https://github.com/kei-g/wol/actions/workflows/mingw.yml?query=branch%3Adevel
[github-main-build-image]:https://github.com/kei-g/wol/actions/workflows/build.yml/badge.svg?branch=main
[github-main-build-url]:https://github.com/kei-g/wol/actions/workflows/build.yml?query=branch%3Amain
[github-main-codeql-image]:https://github.com/kei-g/wol/actions/workflows/codeql.yml/badge.svg?branch=main
[github-main-codeql-url]:https://github.com/kei-g/wol/actions/workflows/codeql.yml?query=branch%3Amain
[github-main-mingw-image]:https://github.com/kei-g/wol/actions/workflows/mingw.yml/badge.svg?branch=main
[github-main-mingw-url]:https://github.com/kei-g/wol/actions/workflows/mingw.yml?query=branch%3Amain
[github-repo-image]:https://img.shields.io/badge/github-kei--g%2Fwol-brightgreen?logo=github
[github-repo-url]:https://github.com/kei-g/wol
[license-image]:https://img.shields.io/github/license/kei-g/wol
[license-url]:https://opensource.org/licenses/BSD-3-Clause
