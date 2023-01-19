# Change Logs

## Version 1.2.3

- ci:
  - :green_heart: Fix uploadAsync to return a Promise
- refactor:
  - :recycle: Separate the version to header file

## Version 1.2.2

- feature:
  - :sparkles: Support --version option
- ci:
  - :green_heart: Make 'docker' job depends 'mingw' also
  - :green_heart: Use `bash` to extract MinGW binaries
  - :green_heart: Specify 'key' to restore docker layers from the cache
  - :green_heart: Upload MinGW binaries as assets of GitHub Release
  - :green_heart: Rename 'Publish' workflow to 'Release'

## Version 1.2.1

- ci:
  - :green_heart: Add paths to ignore not to run workflows
  - :green_heart: Ignore 'push' or 'pull_request' events to prevent running workflow 'Publish'
  - :green_heart: Upload debian packages as assets of GitHub Release
- doc:
  - :memo: Explain how to run the command with specific interface

## Version 1.2.0

- feature:
  - :sparkles: Support --bind option
- ci:
  - :green_heart: Enclose the expression to determine whether if 'publish' workflow runs on 'create' event in quotation marks
  - :green_heart: Modify jobs dependency of 'publish' workflow
  - :green_heart: Specify 'true' to load the built image on 'apt' job
  - :green_heart: Add a job to create release on GitHub
  - :green_heart: Use $GITHUB_OUTPUT instead of $GITHUB_ENV to specify the version
  - :green_heart: Run workflows only on 'push' or 'pull request' events for branches
  - :green_heart: Use `kei-g/dockerhub-patch@main` to patch the description to DockerHub
  - :green_heart: Use `docker/metadata-action@v4` to decide tags of docker image
  - :robot: Revert target branch for Dependabot to 'main'
  - :green_heart: Explicitly specify 'load' as true at build step on MinGW workflow
  - :robot: Specify 'devel' as the target branch of Dependabot
  - :green_heart: Use $GITHUB_ENV instead of deprecated `::set-output` style
  - :green_heart: Remove implicit latest tag to publish
  - :green_heart: Remove unsupported option, --pull=missing
  - :green_heart: Separate a long command into multiple lines
  - :green_heart: Restrict conditions to run the publish workflow
  - :green_heart: Arrange arguments by ascending order
  - :arrow_up: Bump `docker/login-action` from 1 to 2
  - :green_heart: Abolish publishing the image, `snowstep/wol:apt`
  - :green_heart: Avoid login to DockerHub on the build workflow
  - :green_heart: Remove conditions to run workflows
  - :arrow_up: Bump `actions/upload-artifact` from 2 to 3
  - :arrow_up: Bump `actions/checkout` from 2 to 3
  - :arrow_up: Bump `actions/cache` from 2 to 3
  - :arrow_up: Bump `docker/setup-buildx-action` from 1 to 2
  - :arrow_up: Bump `docker/build-push-action` from 2 to 3
  - :arrow_up: Bump `github/codeql-action` from 1 to 2
  - :hammer: Use 'tools/patch-dockerhub.sh'
  - :green_heart: Add a workflow to cross compile for MinGW
  - :green_heart: Update dependencies before build .deb packages
  - :green_heart: Remove unnecessary dependencies
  - :green_heart: Make it possible to archive .deb packages by `actions/upload-artifact`
  - :green_heart: Modify CFLAGS and LDFLAGS
- doc:
  - :memo: Modify CI status badges table
  - :memo: Add a badge to link to the github repository
  - :lipstick: Remove a trailing whitespace
- fix:
  - :whale: Remove dependency on specific `llvm` version
    - :whale: Add a library path to `gcc` for MinGW
      - :whale: Separate arguments to multiple lines
  - :lipstick: Tweak '.clang-format' and fix style
  - :hammer: Add flags, -Wall -Werror -Wextra -pedantic, to build for x86_64-w64-mingw32
  - :rotating_light: Correct the type of argument for `setsockopt` to allow broadcast except on x86_64-w64-mingw32
- refactor:
  - :recycle: Separate a function to parse the mac address
  - :recycle: Add a struct to represent the program options
- misc:
  - :truck: Rename the change logs file by capitalizing
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
