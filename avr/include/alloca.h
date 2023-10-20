#ifndef _ALLOCA_H
#define _ALLOCA_H 1
#include <stddef.h>
extern void *alloca (size_t __size);
#define alloca(size) __builtin_alloca (size)
#endif
