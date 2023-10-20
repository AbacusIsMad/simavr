#ifndef _STRING_H_
#define _STRING_H_ 1
#ifndef __DOXYGEN__
#define __need_NULL
#define __need_size_t
#include <stddef.h>
#ifndef __ATTR_PURE__
#define __ATTR_PURE__ __attribute__((__pure__))
#endif
#ifndef __ATTR_CONST__
# define __ATTR_CONST__ __attribute__((__const__))
#endif
#endif
#ifdef __cplusplus
extern "C" {
#endif
#if defined(__DOXYGEN__)
#define _FFS(x)
#else
#define _FFS(x) (1 + (((x) & 1) == 0) + (((x) & 3) == 0) + (((x) & 7) == 0) + (((x) & 017) == 0) + (((x) & 037) == 0) + (((x) & 077) == 0) + (((x) & 0177) == 0) + (((x) & 0377) == 0) + (((x) & 0777) == 0) + (((x) & 01777) == 0) + (((x) & 03777) == 0) + (((x) & 07777) == 0) + (((x) & 017777) == 0) + (((x) & 037777) == 0) + (((x) & 077777) == 0) - (((x) & 0177777) == 0) * 16)
#endif
extern int ffs(int __val) __ATTR_CONST__;
extern int ffsl(long __val) __ATTR_CONST__;
__extension__ extern int ffsll(long long __val) __ATTR_CONST__;
extern void *memccpy(void *, const void *, int, size_t);
extern void *memchr(const void *, int, size_t) __ATTR_PURE__;
extern int memcmp(const void *, const void *, size_t) __ATTR_PURE__;
extern void *memcpy(void *, const void *, size_t);
extern void *memmem(const void *, size_t, const void *, size_t) __ATTR_PURE__;
extern void *memmove(void *, const void *, size_t);
extern void *memrchr(const void *, int, size_t) __ATTR_PURE__;
extern void *memset(void *, int, size_t);
extern char *strcat(char *, const char *);
extern char *strchr(const char *, int) __ATTR_PURE__;
extern char *strchrnul(const char *, int) __ATTR_PURE__;
extern int strcmp(const char *, const char *) __ATTR_PURE__;
extern char *strcpy(char *, const char *);
extern int strcasecmp(const char *, const char *) __ATTR_PURE__;
extern char *strcasestr(const char *, const char *) __ATTR_PURE__;
extern size_t strcspn(const char *__s, const char *__reject) __ATTR_PURE__;
extern char *strdup(const char *s1);
extern size_t strlcat(char *, const char *, size_t);
extern size_t strlcpy(char *, const char *, size_t);
extern size_t strlen(const char *) __ATTR_PURE__;
extern char *strlwr(char *);
extern char *strncat(char *, const char *, size_t);
extern int strncmp(const char *, const char *, size_t) __ATTR_PURE__;
extern char *strncpy(char *, const char *, size_t);
extern int strncasecmp(const char *, const char *, size_t) __ATTR_PURE__;
extern size_t strnlen(const char *, size_t) __ATTR_PURE__;
extern char *strpbrk(const char *__s, const char *__accept) __ATTR_PURE__;
extern char *strrchr(const char *, int) __ATTR_PURE__;
extern char *strrev(char *);
extern char *strsep(char **, const char *);
extern size_t strspn(const char *__s, const char *__accept) __ATTR_PURE__;
extern char *strstr(const char *, const char *) __ATTR_PURE__;
extern char *strtok(char *, const char *);
extern char *strtok_r(char *, const char *, char **);
extern char *strupr(char *);
#ifndef __DOXYGEN__
extern int strcoll(const char *s1, const char *s2);
extern char *strerror(int errnum);
extern size_t strxfrm(char *dest, const char *src, size_t n);
#endif
#ifdef __cplusplus
}
#endif
#endif
