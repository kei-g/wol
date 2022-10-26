# Change Logs

## Version 1.2.0

- feature:
  - :sparkles: Support --bind option
- ci:
  - :hammer: Use 'tools/patch-dockerhub.sh'
  - :green_heart: Add a workflow to cross compile for MinGW
  - :green_heart: Update dependencies before build .deb packages
  - :green_heart: Remove unnecessary dependencies
  - :green_heart: Make it possible to archive .deb packages by `actions/upload-artifact`
  - :green_heart: Modify CFLAGS and LDFLAGS
- doc:
  - :lipstick: Remove a trailing whitespace
- fix:
  - :whale: Remove dependency on specific `llvm` version
    - :whale: Add a library path to `gcc` for MinGW
  - :lipstick: Tweak '.clang-format' and fix style
  - :hammer: Add flags, -Wall -Werror -Wextra -pedantic, to build for x86_64-w64-mingw32
  - :rotating_light: Correct the type of argument for `setsockopt` to allow broadcast except on x86_64-w64-mingw32
- refactor:
  - :whale: Separate arguments to multiple lines
  - :recycle: Separate a function to parse the mac address
  - :recycle: Add a struct to represent the program options
- misc:
  - :wrench: Add setting files

## Version 1.1.1

- fix:
  - :whale: A missing output of VERSION has been complemented
  - :whale: CFLAGS is modified
  - :whale: The script to build a docker image is fixed
- docs:
  - :memo: CI status badges is changed to a table
  - :memo: How to use the docker image
  - :memo: The physial address for an example of usage is modified
- refactor:
  - :recycle: A function to allow broadcast is separated
  - :recycle: A function to parse options is separated

## Version 1.1.0

- chore: CI
  - :green_heart: Remove 'README.md' from paths-ignore
  - :green_heart: Rename 'docker.yml' to 'publish.yml' at paths-ignore in 'build.yml'
- chore: hier
  - :truck: Move 'Dockerfile' under to 'conf/hub/'
  - :truck: Move files for autotools
- platform: debian
  - :penguin: Add a Dockerfile to build debian packages
- platform: win32

## Version 1.0.2

- :whale: Base image is changed from debian:stable-slim to busybox:glibc

## Version 1.0.1

- :whale: Base image is changed from ubuntu:latest to debian:stable-slim
- :whale: ENTRYPOINT has been set
- :wrench: Some functions becomes to be checked by `configure`
- :pencil2: URL to DockerHub is corrected

## Version 1.0.0

- :tada: Initial release
