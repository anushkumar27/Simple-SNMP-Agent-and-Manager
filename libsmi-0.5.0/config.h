/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* "" */
#define BACKEND_SMI 1

/* "" */
/* #undef BACKEND_SMING */

/* "" */
#define BACKEND_YANG 1

/* The default error level at libsmi initialization. */
#define DEFAULT_ERRORLEVEL 3

/* The full pathname of the global configuration file. */
#define DEFAULT_GLOBALCONFIG "${prefix}/etc/smi.conf"

/* The default search path to lookup SMI module files. */
#define DEFAULT_SMIPATH "/usr/local/share/mibs/ietf:/usr/local/share/mibs/iana:/usr/local/share/mibs/irtf:/usr/local/share/mibs/site:/usr/local/share/mibs/jacobs:/usr/local/share/mibs/tubs:/usr/local/share/pibs/ietf:/usr/local/share/pibs/site:/usr/local/share/pibs/tubs:/usr/local/share/yang/ietf:/usr/local/share/yang/iana:/usr/local/share/yang/site"

/* The basename of the per-user configuration file searched in $HOME. */
#define DEFAULT_USERCONFIG ".smirc"

/* The default path separator character. */
#define DIR_SEPARATOR '/'

/* Define to 1 if you have the `asnprintf' function. */
/* #undef HAVE_ASNPRINTF */

/* Define to 1 if you have the `asprintf' function. */
#define HAVE_ASPRINTF 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* "" */
/* #undef HAVE_DMALLOC_H */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <limits.h> header file. */
#define HAVE_LIMITS_H 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <pwd.h> header file. */
#define HAVE_PWD_H 1

/* Define to 1 if you have the <regex.h> header file. */
#define HAVE_REGEX_H 1

/* Define to 1 if you have the `snprintf' function. */
#define HAVE_SNPRINTF 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strtoll' function. */
#define HAVE_STRTOLL 1

/* Define to 1 if you have the `strtoq' function. */
#define HAVE_STRTOQ 1

/* Define to 1 if you have the `strtoull' function. */
#define HAVE_STRTOULL 1

/* Define to 1 if you have the `strtouq' function. */
#define HAVE_STRTOUQ 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the `timegm' function. */
#define HAVE_TIMEGM 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the `vasnprintf' function. */
/* #undef HAVE_VASNPRINTF */

/* Define to 1 if you have the `vasprintf' function. */
#define HAVE_VASPRINTF 1

/* Define to 1 if you have the `vsnprintf' function. */
#define HAVE_VSNPRINTF 1

/* The signed 64 bit integer format conversion specification string. */
#define INT64_FORMAT "%lld"

/* The signed 64 bit integer maximum value. */
#define LIBSMI_INT64_MAX 9223372036854775807LL

/* The unsigned 64 bit integer minimum value. */
#define LIBSMI_INT64_MIN -9223372036854775807LL

/* The unsigned 64 bit integer maximum value. */
#define LIBSMI_UINT64_MAX 18446744073709551615ULL

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#define LT_OBJDIR ".libs/"

/* The maximum module import recursion depth. */
#define MAX_LEX_DEPTH 30

/* Name of package */
#define PACKAGE "libsmi"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME ""

/* Define to the full name and version of this package. */
#define PACKAGE_STRING ""

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME ""

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION ""

/* The default path separator character. */
#define PATH_SEPARATOR ':'

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* The unsigned 64 bit integer format conversion specification string. */
#define UINT64_FORMAT "%llu"

/* Version number of package */
#define VERSION "0.5.0"
