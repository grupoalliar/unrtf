/* config.h for Windows. hand-edited.  */

/* Define to 1 if you have the <ctype.h> header file. */
#define HAVE_CTYPE_H 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if your system has a GNU libc compatible `malloc' function, and
to 0 otherwise. */
#define HAVE_MALLOC 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the `memset' function. */
#define HAVE_MEMSET 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdio.h> header file. */
#define HAVE_STDIO_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the `strchr' function. */
#define HAVE_STRCHR 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strstr' function. */
#define HAVE_STRSTR 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1
#undef HAVE_UNISTD_H

#define PACKAGE "unrtf"
#define PACKAGE_BUGREPORT "bug-unrtf@lesbonscomptes.com"
#define PACKAGE_NAME "unrtf"
#define PACKAGE_STRING "unrtf 0.21.9"
#define PACKAGE_TARNAME "unrtf"
#define PACKAGE_URL ""
#define VERSION "0.21.9"
#define PACKAGE_VERSION "0.21.9"

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1


#ifdef _MSC_VER

extern char *strcasestr(const char *s, const char *find);
#define access(A,B) _access(A,B)
extern unsigned int unrtf_ntohl(unsigned int);
#define strcasecmp _stricmp
#define strncasecmp _strnicmp

#endif /* _MSC_VER */

#ifndef R_OK
/* Values for the second argument to access.
These may be OR'd together.  */
#define R_OK    4       /* Test for read permission.  */
#define W_OK    2       /* Test for write permission.  */
#define   X_OK    R_OK       /* execute permission - unsupported in windows*/
#define F_OK    0       /* Test for existence.  */
#endif /* R_OK */

typedef unsigned int uint32_t;
extern const char *unrtfDataDir();
#define DEFAULT_UNRTF_SEARCH_PATH unrtfDataDir();

