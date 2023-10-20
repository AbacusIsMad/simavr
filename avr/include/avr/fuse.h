#ifndef _AVR_FUSE_H_
#define _AVR_FUSE_H_ 1
#if !defined(_AVR_IO_H_)
#error "You must #include <avr/io.h> and not <avr/fuse.h> by itself."
#endif
#if !(defined(__ASSEMBLER__) || defined(__DOXYGEN__))
#ifndef FUSEMEM
#define FUSEMEM __attribute__((__used__, __section__ (".fuse")))
#endif
#if FUSE_MEMORY_SIZE > 3
typedef struct
{
    unsigned char byte[FUSE_MEMORY_SIZE];
} __fuse_t;
#elif FUSE_MEMORY_SIZE == 3
typedef struct
{
    unsigned char low;
    unsigned char high;
    unsigned char extended;
} __fuse_t;
#elif FUSE_MEMORY_SIZE == 2
typedef struct
{
    unsigned char low;
    unsigned char high;
} __fuse_t;
#elif FUSE_MEMORY_SIZE == 1
typedef struct
{
    unsigned char byte;
} __fuse_t;
#endif
#if !defined(FUSES)
  #if defined(__AVR_XMEGA__)
    #define FUSES NVM_FUSES_t __fuse FUSEMEM
  #else
    #define FUSES __fuse_t __fuse FUSEMEM
  #endif
#endif
#endif
#endif
