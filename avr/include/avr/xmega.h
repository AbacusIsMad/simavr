#ifndef _AVR_XMEGA_H
#define _AVR_XMEGA_H
#ifdef __DOXYGEN__
#define _PROTECTED_WRITE(reg, value)
#define _PROTECTED_WRITE_SPM(reg, value)
#else
#define _PROTECTED_WRITE(reg, value) __asm__ __volatile__("out %[ccp], %[ccp_ioreg]" "\n\t" "sts %[ioreg], %[val]" : : [ccp] "I" (_SFR_IO_ADDR(CCP)), [ccp_ioreg] "d" ((uint8_t)CCP_IOREG_gc), [ioreg] "n" (_SFR_MEM_ADDR(reg)), [val] "r" ((uint8_t)value))
#define _PROTECTED_WRITE_SPM(reg, value) __asm__ __volatile__("out %[ccp], %[ccp_spm_mask]" "\n\t" "sts %[ioreg], %[val]" : : [ccp] "I" (_SFR_IO_ADDR(CCP)), [ccp_spm_mask] "d" ((uint8_t)CCP_SPM_gc), [ioreg] "n" (_SFR_MEM_ADDR(reg)), [val] "r" ((uint8_t)value))
#endif
#endif
