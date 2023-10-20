#ifndef __SETJMP_H_
#define __SETJMP_H_ 1
#ifdef __cplusplus
extern "C" {
#endif
#if !defined(__DOXYGEN__)
#if defined(__AVR_TINY__)
# define _JBLEN 9
#elif defined(__AVR_3_BYTE_PC__) && __AVR_3_BYTE_PC__
# define _JBLEN 24
#else
# define _JBLEN 23
#endif
typedef struct _jmp_buf { unsigned char _jb[_JBLEN]; } jmp_buf[1];
#endif
#if !(defined(__ATTR_NORETURN__) || defined(__DOXYGEN__))
#define __ATTR_NORETURN__ __attribute__((__noreturn__))
#endif
extern int setjmp(jmp_buf __jmpb);
extern void longjmp(jmp_buf __jmpb, int __ret) __ATTR_NORETURN__;
#ifdef __cplusplus
}
#endif
#endif
