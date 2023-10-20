#ifndef __CTYPE_H_
#define __CTYPE_H_ 1
#ifndef __ATTR_CONST__
#define __ATTR_CONST__ __attribute__((__const__))
#endif
#ifdef __cplusplus
extern "C" {
#endif
extern int isalnum(int __c) __ATTR_CONST__;
extern int isalpha(int __c) __ATTR_CONST__;
extern int isascii(int __c) __ATTR_CONST__;
extern int isblank(int __c) __ATTR_CONST__;
extern int iscntrl(int __c) __ATTR_CONST__;
extern int isdigit(int __c) __ATTR_CONST__;
extern int isgraph(int __c) __ATTR_CONST__;
extern int islower(int __c) __ATTR_CONST__;
extern int isprint(int __c) __ATTR_CONST__;
extern int ispunct(int __c) __ATTR_CONST__;
extern int isspace(int __c) __ATTR_CONST__;
extern int isupper(int __c) __ATTR_CONST__;
extern int isxdigit(int __c) __ATTR_CONST__;
extern int toascii(int __c) __ATTR_CONST__;
extern int tolower(int __c) __ATTR_CONST__;
extern int toupper(int __c) __ATTR_CONST__;
#ifdef __cplusplus
}
#endif
#endif
