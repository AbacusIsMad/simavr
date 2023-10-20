#ifndef _STDIO_H_
#define _STDIO_H_ 1
#ifndef __ASSEMBLER__
#include <inttypes.h>
#include <stdarg.h>
#ifndef __DOXYGEN__
#define __need_NULL
#define __need_size_t
#include <stddef.h>
#endif
#if !defined(__DOXYGEN__)
struct __file {
 char *buf;
 unsigned char unget;
 uint8_t flags;
#define __SRD 0x0001
#define __SWR 0x0002
#define __SSTR 0x0004
#define __SPGM 0x0008
#define __SERR 0x0010
#define __SEOF 0x0020
#define __SUNGET 0x040
#define __SMALLOC 0x80
#if 0
#define __SRW 0x0100
#define __SLBF 0x0200
#define __SNBF 0x0400
#define __SMBF 0x0800
#endif
 int size;
 int len;
 int (*put)(char, struct __file *);
 int (*get)(struct __file *);
 void *udata;
};
#endif
typedef struct __file FILE;
#define stdin (__iob[0])
#define stdout (__iob[1])
#define stderr (__iob[2])
#define EOF (-1)
#define fdev_set_udata(stream, u) do { (stream)->udata = u; } while(0)
#define fdev_get_udata(stream) ((stream)->udata)
#if defined(__DOXYGEN__)
#define fdev_setup_stream(stream, put, get, rwflag)
#else
#define fdev_setup_stream(stream, p, g, f) do { (stream)->put = p; (stream)->get = g; (stream)->flags = f; (stream)->udata = 0; } while(0)
#endif
#define _FDEV_SETUP_READ __SRD
#define _FDEV_SETUP_WRITE __SWR
#define _FDEV_SETUP_RW (__SRD|__SWR)
#define _FDEV_ERR (-1)
#define _FDEV_EOF (-2)
#if defined(__DOXYGEN__)
#define FDEV_SETUP_STREAM(put, get, rwflag)
#else
#define FDEV_SETUP_STREAM(p, g, f) { .put = p, .get = g, .flags = f, .udata = 0, }
#endif
#ifdef __cplusplus
extern "C" {
#endif
#if !defined(__DOXYGEN__)
extern struct __file *__iob[];
#if defined(__STDIO_FDEVOPEN_COMPAT_12)
extern FILE *fdevopen(int (*__put)(char), int (*__get)(void),
                      int __opts __attribute__((unused)));
#else
extern FILE *fdevopen(int (*__put)(char, FILE*), int (*__get)(FILE*));
#endif
#endif
extern int fclose(FILE *__stream);
#if defined(__DOXYGEN__)
# define fdev_close()
#else
# define fdev_close() ((void)0)
#endif
extern int vfprintf(FILE *__stream, const char *__fmt, va_list __ap);
extern int vfprintf_P(FILE *__stream, const char *__fmt, va_list __ap);
extern int fputc(int __c, FILE *__stream);
#if !defined(__DOXYGEN__)
extern int putc(int __c, FILE *__stream);
extern int putchar(int __c);
#endif
#define putc(__c, __stream) fputc(__c, __stream)
#define putchar(__c) fputc(__c, stdout)
extern int printf(const char *__fmt, ...);
extern int printf_P(const char *__fmt, ...);
extern int vprintf(const char *__fmt, va_list __ap);
extern int sprintf(char *__s, const char *__fmt, ...);
extern int sprintf_P(char *__s, const char *__fmt, ...);
extern int snprintf(char *__s, size_t __n, const char *__fmt, ...);
extern int snprintf_P(char *__s, size_t __n, const char *__fmt, ...);
extern int vsprintf(char *__s, const char *__fmt, va_list ap);
extern int vsprintf_P(char *__s, const char *__fmt, va_list ap);
extern int vsnprintf(char *__s, size_t __n, const char *__fmt, va_list ap);
extern int vsnprintf_P(char *__s, size_t __n, const char *__fmt, va_list ap);
extern int fprintf(FILE *__stream, const char *__fmt, ...);
extern int fprintf_P(FILE *__stream, const char *__fmt, ...);
extern int fputs(const char *__str, FILE *__stream);
extern int fputs_P(const char *__str, FILE *__stream);
extern int puts(const char *__str);
extern int puts_P(const char *__str);
extern size_t fwrite(const void *__ptr, size_t __size, size_t __nmemb,
         FILE *__stream);
extern int fgetc(FILE *__stream);
#if !defined(__DOXYGEN__)
extern int getc(FILE *__stream);
extern int getchar(void);
#endif
#define getc(__stream) fgetc(__stream)
#define getchar() fgetc(stdin)
extern int ungetc(int __c, FILE *__stream);
extern char *fgets(char *__str, int __size, FILE *__stream);
extern char *gets(char *__str);
extern size_t fread(void *__ptr, size_t __size, size_t __nmemb,
        FILE *__stream);
extern void clearerr(FILE *__stream);
#if !defined(__DOXYGEN__)
#define clearerror(s) do { (s)->flags &= ~(__SERR | __SEOF); } while(0)
#endif
extern int feof(FILE *__stream);
#if !defined(__DOXYGEN__)
#define feof(s) ((s)->flags & __SEOF)
#endif
extern int ferror(FILE *__stream);
#if !defined(__DOXYGEN__)
#define ferror(s) ((s)->flags & __SERR)
#endif
extern int vfscanf(FILE *__stream, const char *__fmt, va_list __ap);
extern int vfscanf_P(FILE *__stream, const char *__fmt, va_list __ap);
extern int fscanf(FILE *__stream, const char *__fmt, ...);
extern int fscanf_P(FILE *__stream, const char *__fmt, ...);
extern int scanf(const char *__fmt, ...);
extern int scanf_P(const char *__fmt, ...);
extern int vscanf(const char *__fmt, va_list __ap);
extern int sscanf(const char *__buf, const char *__fmt, ...);
extern int sscanf_P(const char *__buf, const char *__fmt, ...);
#if defined(__DOXYGEN__)
extern int fflush(FILE *stream);
#else
static __inline__ int fflush(FILE *stream __attribute__((unused)))
{
 return 0;
}
#endif
#ifndef __DOXYGEN__
#define BUFSIZ 1024
#define _IONBF 0
__extension__ typedef long long fpos_t;
extern int fgetpos(FILE *stream, fpos_t *pos);
extern FILE *fopen(const char *path, const char *mode);
extern FILE *freopen(const char *path, const char *mode, FILE *stream);
extern FILE *fdopen(int, const char *);
extern int fseek(FILE *stream, long offset, int whence);
extern int fsetpos(FILE *stream, fpos_t *pos);
extern long ftell(FILE *stream);
extern int fileno(FILE *);
extern void perror(const char *s);
extern int remove(const char *pathname);
extern int rename(const char *oldpath, const char *newpath);
extern void rewind(FILE *stream);
extern void setbuf(FILE *stream, char *buf);
extern int setvbuf(FILE *stream, char *buf, int mode, size_t size);
extern FILE *tmpfile(void);
extern char *tmpnam (char *s);
#endif
#ifdef __cplusplus
}
#endif
#ifndef __DOXYGEN__
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
#endif
#endif
#endif
