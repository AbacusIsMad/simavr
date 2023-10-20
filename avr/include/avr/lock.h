#ifndef _AVR_LOCK_H_
#define _AVR_LOCK_H_ 1
#if !(defined(__ASSEMBLER__) || defined(__DOXYGEN__))
#ifndef LOCKMEM
#define LOCKMEM __attribute__((__used__, __section__ (".lock")))
#endif
#ifndef LOCKBITS
#if defined(LOCKBITS_SIZE) && (LOCKBITS_SIZE == 4)
#define LOCKBITS unsigned long __lock LOCKMEM
#else
#define LOCKBITS unsigned char __lock LOCKMEM
#endif
#endif
#if defined(__LOCK_BITS_EXIST)
#define LB_MODE_1 (0xFF)
#define LB_MODE_2 (0xFE)
#define LB_MODE_3 (0xFC)
#endif
#if defined(__BOOT_LOCK_BITS_0_EXIST)
#define BLB0_MODE_1 (0xFF)
#define BLB0_MODE_2 (0xFB)
#define BLB0_MODE_3 (0xF3)
#define BLB0_MODE_4 (0xF7)
#endif
#if defined(__BOOT_LOCK_BITS_1_EXIST)
#define BLB1_MODE_1 (0xFF)
#define BLB1_MODE_2 (0xEF)
#define BLB1_MODE_3 (0xCF)
#define BLB1_MODE_4 (0xDF)
#endif
#if defined(__BOOT_LOCK_APPLICATION_TABLE_BITS_EXIST)
#define BLBAT0 ~_BV(2)
#define BLBAT1 ~_BV(3)
#endif
#if defined(__BOOT_LOCK_APPLICATION_BITS_EXIST)
#define BLBA0 ~_BV(4)
#define BLBA1 ~_BV(5)
#endif
#if defined(__BOOT_LOCK_BOOT_BITS_EXIST)
#define BLBB0 ~_BV(6)
#define BLBB1 ~_BV(7)
#endif
#ifndef LOCKBITS_DEFAULT
#define LOCKBITS_DEFAULT (0xFF)
#endif
#endif
#endif
