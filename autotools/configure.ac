#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(wol, 1.0.0, km.8k6ce+github@gmail.com)
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([../wol.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h netinet/in.h stdbool.h stdint.h stdlib.h string.h sys/socket.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SSIZE_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_CHECK_FUNCS([close fprintf fputs memcpy memset perror sendto setsockopt socket stderr strtok_r strtoul])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
