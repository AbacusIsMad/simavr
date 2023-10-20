#ifndef _AVR_WDT_H_
#define _AVR_WDT_H_
#include <avr/io.h>
#include <stdint.h>
#define wdt_reset() __asm__ __volatile__ ("wdr")
#ifndef __DOXYGEN__
#if defined(WDP3)
# define _WD_PS3_MASK _BV(WDP3)
#else
# define _WD_PS3_MASK 0x00
#endif
#if defined(WDTCSR)
# define _WD_CONTROL_REG WDTCSR
#elif defined(WDTCR)
# define _WD_CONTROL_REG WDTCR
#else
# define _WD_CONTROL_REG WDT
#endif
#if defined(WDTOE)
#define _WD_CHANGE_BIT WDTOE
#else
#define _WD_CHANGE_BIT WDCE
#endif
#endif
#if defined(__AVR_XMEGA__)
#if defined (WDT_CTRLA) && !defined(RAMPD)
#define wdt_enable(timeout) do { uint8_t temp; __asm__ __volatile__ ( "wdr" "\n\t" "out %[ccp_reg], %[ioreg_cen_mask]" "\n\t" "lds %[tmp], %[wdt_reg]" "\n\t" "sbr %[tmp], %[wdt_enable_timeout]" "\n\t" "sts %[wdt_reg], %[tmp]" "\n\t" "1:lds %[tmp], %[wdt_status_reg]" "\n\t" "sbrc %[tmp], %[wdt_syncbusy_bit]" "\n\t" "rjmp 1b" "\n\t" : [tmp] "=r" (temp) : [ccp_reg] "I" (_SFR_IO_ADDR(CCP)), [ioreg_cen_mask] "r" ((uint8_t)CCP_IOREG_gc), [wdt_reg] "n" (_SFR_MEM_ADDR(WDT_CTRLA)), [wdt_enable_timeout] "M" (timeout), [wdt_status_reg] "n" (_SFR_MEM_ADDR(WDT_STATUS)), [wdt_syncbusy_bit] "I" (WDT_SYNCBUSY_bm) ); } while(0)
#define wdt_disable() do { uint8_t temp; __asm__ __volatile__ ( "wdr" "\n\t" "out %[ccp_reg], %[ioreg_cen_mask]" "\n\t" "lds %[tmp], %[wdt_reg]" "\n\t" "cbr %[tmp], %[timeout_mask]" "\n\t" "sts %[wdt_reg], %[tmp]" "\n\t" : [tmp] "=r" (temp) : [ccp_reg] "I" (_SFR_IO_ADDR(CCP)), [ioreg_cen_mask] "r" ((uint8_t)CCP_IOREG_gc), [wdt_reg] "n" (_SFR_MEM_ADDR(WDT_CTRLA)), [timeout_mask] "I" (WDT_PERIOD_gm) ); } while(0)
#else
#define wdt_enable(timeout) do { uint8_t temp; __asm__ __volatile__ ( "in __tmp_reg__, %[rampd]" "\n\t" "out %[rampd], __zero_reg__" "\n\t" "out %[ccp_reg], %[ioreg_cen_mask]" "\n\t" "sts %[wdt_reg], %[wdt_enable_timeout]" "\n\t" "1:lds %[tmp], %[wdt_status_reg]" "\n\t" "sbrc %[tmp], %[wdt_syncbusy_bit]" "\n\t" "rjmp 1b" "\n\t" "out %[rampd], __tmp_reg__" "\n\t" : [tmp] "=r" (temp) : [rampd] "I" (_SFR_IO_ADDR(RAMPD)), [ccp_reg] "I" (_SFR_IO_ADDR(CCP)), [ioreg_cen_mask] "r" ((uint8_t)CCP_IOREG_gc), [wdt_reg] "n" (_SFR_MEM_ADDR(WDT_CTRL)), [wdt_enable_timeout] "r" ((uint8_t)(WDT_CEN_bm | WDT_ENABLE_bm | timeout)), [wdt_status_reg] "n" (_SFR_MEM_ADDR(WDT_STATUS)), [wdt_syncbusy_bit] "I" (WDT_SYNCBUSY_bm) : "r0" ); } while(0)
#define wdt_disable() __asm__ __volatile__ ( "in __tmp_reg__, %[rampd]" "\n\t" "out %[rampd], __zero_reg__" "\n\t" "out %[ccp_reg], %[ioreg_cen_mask]" "\n\t" "sts %[wdt_reg], %[disable_mask]" "\n\t" "out %[rampd], __tmp_reg__" "\n\t" : : [rampd] "I" (_SFR_IO_ADDR(RAMPD)), [ccp_reg] "I" (_SFR_IO_ADDR(CCP)), [ioreg_cen_mask] "r" ((uint8_t)CCP_IOREG_gc), [wdt_reg] "n" (_SFR_MEM_ADDR(WDT_CTRL)), [disable_mask] "r" ((uint8_t)((~WDT_ENABLE_bm) | WDT_CEN_bm)) : "r0" );
#endif
#elif defined(__AVR_TINY__)
#define wdt_enable(value) __asm__ __volatile__ ( "in __tmp_reg__,__SREG__" "\n\t" "cli" "\n\t" "wdr" "\n\t" "out %[CCPADDRESS],%[SIGNATURE]" "\n\t" "out %[WDTREG],%[WDVALUE]" "\n\t" "out __SREG__,__tmp_reg__" "\n\t" : : [CCPADDRESS] "I" (_SFR_IO_ADDR(CCP)), [SIGNATURE] "r" ((uint8_t)0xD8), [WDTREG] "I" (_SFR_IO_ADDR(_WD_CONTROL_REG)), [WDVALUE] "r" ((uint8_t)((value & 0x08 ? _WD_PS3_MASK : 0x00) | _BV(WDE) | (value & 0x07) )) : "r16" )
#define wdt_disable() do { uint8_t temp_wd; __asm__ __volatile__ ( "in __tmp_reg__,__SREG__" "\n\t" "cli" "\n\t" "wdr" "\n\t" "out %[CCPADDRESS],%[SIGNATURE]" "\n\t" "in  %[TEMP_WD],%[WDTREG]" "\n\t" "cbr %[TEMP_WD],%[WDVALUE]" "\n\t" "out %[WDTREG],%[TEMP_WD]" "\n\t" "out __SREG__,__tmp_reg__" "\n\t" : : [CCPADDRESS] "I" (_SFR_IO_ADDR(CCP)), [SIGNATURE] "r" ((uint8_t)0xD8), [WDTREG] "I" (_SFR_IO_ADDR(_WD_CONTROL_REG)), [TEMP_WD] "d" (temp_wd), [WDVALUE] "n" (1 << WDE) : "r16" ); }while(0)
#elif defined(CCP)
static __inline__
__attribute__ ((__always_inline__))
void wdt_enable (const uint8_t value)
{
 if (!_SFR_IO_REG_P (CCP) && !_SFR_IO_REG_P (_WD_CONTROL_REG))
 {
  __asm__ __volatile__ (
   "in __tmp_reg__,__SREG__" "\n\t"
   "cli" "\n\t"
   "wdr" "\n\t"
   "sts %[CCPADDRESS],%[SIGNATURE]" "\n\t"
   "sts %[WDTREG],%[WDVALUE]" "\n\t"
   "out __SREG__,__tmp_reg__" "\n\t"
   :
   : [CCPADDRESS] "n" (_SFR_MEM_ADDR(CCP)),
   [SIGNATURE] "r" ((uint8_t)0xD8),
   [WDTREG] "n" (_SFR_MEM_ADDR(_WD_CONTROL_REG)),
   [WDVALUE] "r" ((uint8_t)((value & 0x08 ? _WD_PS3_MASK : 0x00)
    | _BV(WDE) | (value & 0x07) ))
   : "r0"
   );
 }
 else if (!_SFR_IO_REG_P (CCP) && _SFR_IO_REG_P (_WD_CONTROL_REG))
 {
  __asm__ __volatile__ (
   "in __tmp_reg__,__SREG__" "\n\t"
   "cli" "\n\t"
   "wdr" "\n\t"
   "sts %[CCPADDRESS],%[SIGNATURE]" "\n\t"
   "out %[WDTREG],%[WDVALUE]" "\n\t"
   "out __SREG__,__tmp_reg__" "\n\t"
   :
   : [CCPADDRESS] "n" (_SFR_MEM_ADDR(CCP)),
   [SIGNATURE] "r" ((uint8_t)0xD8),
   [WDTREG] "I" (_SFR_IO_ADDR(_WD_CONTROL_REG)),
   [WDVALUE] "r" ((uint8_t)((value & 0x08 ? _WD_PS3_MASK : 0x00)
    | _BV(WDE) | (value & 0x07) ))
   : "r0"
   );
 }
 else if (_SFR_IO_REG_P (CCP) && !_SFR_IO_REG_P (_WD_CONTROL_REG))
 {
  __asm__ __volatile__ (
   "in __tmp_reg__,__SREG__" "\n\t"
   "cli" "\n\t"
   "wdr" "\n\t"
   "out %[CCPADDRESS],%[SIGNATURE]" "\n\t"
   "sts %[WDTREG],%[WDVALUE]" "\n\t"
   "out __SREG__,__tmp_reg__" "\n\t"
   :
   : [CCPADDRESS] "I" (_SFR_IO_ADDR(CCP)),
   [SIGNATURE] "r" ((uint8_t)0xD8),
   [WDTREG] "n" (_SFR_MEM_ADDR(_WD_CONTROL_REG)),
   [WDVALUE] "r" ((uint8_t)((value & 0x08 ? _WD_PS3_MASK : 0x00)
    | _BV(WDE) | (value & 0x07) ))
   : "r0"
   );
 }
 else
  {
  __asm__ __volatile__ (
   "in __tmp_reg__,__SREG__" "\n\t"
   "cli" "\n\t"
   "wdr" "\n\t"
   "out %[CCPADDRESS],%[SIGNATURE]" "\n\t"
   "out %[WDTREG],%[WDVALUE]" "\n\t"
   "out __SREG__,__tmp_reg__" "\n\t"
   :
   : [CCPADDRESS] "I" (_SFR_IO_ADDR(CCP)),
   [SIGNATURE] "r" ((uint8_t)0xD8),
   [WDTREG] "I" (_SFR_IO_ADDR(_WD_CONTROL_REG)),
   [WDVALUE] "r" ((uint8_t)((value & 0x08 ? _WD_PS3_MASK : 0x00)
    | _BV(WDE) | (value & 0x07) ))
   : "r0"
   );
 }
}
static __inline__
__attribute__ ((__always_inline__))
void wdt_disable (void)
{
 if (!_SFR_IO_REG_P (CCP) && !_SFR_IO_REG_P(_WD_CONTROL_REG))
 {
        uint8_t temp_wd;
        __asm__ __volatile__ (
    "in __tmp_reg__,__SREG__" "\n\t"
    "cli" "\n\t"
    "wdr" "\n\t"
    "sts %[CCPADDRESS],%[SIGNATURE]" "\n\t"
    "lds %[TEMP_WD],%[WDTREG]" "\n\t"
    "cbr %[TEMP_WD],%[WDVALUE]" "\n\t"
    "sts %[WDTREG],%[TEMP_WD]" "\n\t"
    "out __SREG__,__tmp_reg__" "\n\t"
    :
    : [CCPADDRESS] "n" (_SFR_MEM_ADDR(CCP)),
    [SIGNATURE] "r" ((uint8_t)0xD8),
    [WDTREG] "n" (_SFR_MEM_ADDR(_WD_CONTROL_REG)),
    [TEMP_WD] "d" (temp_wd),
    [WDVALUE] "n" (1 << WDE)
    : "r0"
    );
 }
 else if (!_SFR_IO_REG_P (CCP) && _SFR_IO_REG_P(_WD_CONTROL_REG))
 {
        uint8_t temp_wd;
        __asm__ __volatile__ (
    "in __tmp_reg__,__SREG__" "\n\t"
    "cli" "\n\t"
    "wdr" "\n\t"
    "sts %[CCPADDRESS],%[SIGNATURE]" "\n\t"
    "in %[TEMP_WD],%[WDTREG]" "\n\t"
    "cbr %[TEMP_WD],%[WDVALUE]" "\n\t"
    "out %[WDTREG],%[TEMP_WD]" "\n\t"
    "out __SREG__,__tmp_reg__" "\n\t"
    :
    : [CCPADDRESS] "n" (_SFR_MEM_ADDR(CCP)),
    [SIGNATURE] "r" ((uint8_t)0xD8),
    [WDTREG] "I" (_SFR_IO_ADDR(_WD_CONTROL_REG)),
    [TEMP_WD] "d" (temp_wd),
    [WDVALUE] "n" (1 << WDE)
    : "r0"
    );
 }
 else if (_SFR_IO_REG_P (CCP) && !_SFR_IO_REG_P(_WD_CONTROL_REG))
 {
        uint8_t temp_wd;
        __asm__ __volatile__ (
    "in __tmp_reg__,__SREG__" "\n\t"
    "cli" "\n\t"
    "wdr" "\n\t"
    "out %[CCPADDRESS],%[SIGNATURE]" "\n\t"
    "lds %[TEMP_WD],%[WDTREG]" "\n\t"
    "cbr %[TEMP_WD],%[WDVALUE]" "\n\t"
    "sts %[WDTREG],%[TEMP_WD]" "\n\t"
    "out __SREG__,__tmp_reg__" "\n\t"
    :
    : [CCPADDRESS] "I" (_SFR_IO_ADDR(CCP)),
    [SIGNATURE] "r" ((uint8_t)0xD8),
    [WDTREG] "n" (_SFR_MEM_ADDR(_WD_CONTROL_REG)),
    [TEMP_WD] "d" (temp_wd),
    [WDVALUE] "n" (1 << WDE)
    : "r0"
    );
 }
 else
 {
        uint8_t temp_wd;
        __asm__ __volatile__ (
    "in __tmp_reg__,__SREG__" "\n\t"
    "cli" "\n\t"
    "wdr" "\n\t"
    "out %[CCPADDRESS],%[SIGNATURE]" "\n\t"
    "in %[TEMP_WD],%[WDTREG]" "\n\t"
    "cbr %[TEMP_WD],%[WDVALUE]" "\n\t"
    "out %[WDTREG],%[TEMP_WD]" "\n\t"
    "out __SREG__,__tmp_reg__" "\n\t"
    :
    : [CCPADDRESS] "I" (_SFR_IO_ADDR(CCP)),
    [SIGNATURE] "r" ((uint8_t)0xD8),
    [WDTREG] "I" (_SFR_IO_ADDR(_WD_CONTROL_REG)),
    [TEMP_WD] "d" (temp_wd),
    [WDVALUE] "n" (1 << WDE)
    : "r0"
    );
 }
}
#else
static __inline__
__attribute__ ((__always_inline__))
void wdt_enable (const uint8_t value)
{
 if (_SFR_IO_REG_P (_WD_CONTROL_REG))
 {
  __asm__ __volatile__ (
    "in __tmp_reg__,__SREG__" "\n\t"
    "cli" "\n\t"
    "wdr" "\n\t"
    "out %0, %1" "\n\t"
    "out __SREG__,__tmp_reg__" "\n\t"
    "out %0, %2" "\n \t"
    :
    : "I" (_SFR_IO_ADDR(_WD_CONTROL_REG)),
    "r" ((uint8_t)(_BV(_WD_CHANGE_BIT) | _BV(WDE))),
    "r" ((uint8_t) ((value & 0x08 ? _WD_PS3_MASK : 0x00) |
      _BV(WDE) | (value & 0x07)) )
    : "r0"
  );
 }
 else
 {
  __asm__ __volatile__ (
    "in __tmp_reg__,__SREG__" "\n\t"
    "cli" "\n\t"
    "wdr" "\n\t"
    "sts %0, %1" "\n\t"
    "out __SREG__,__tmp_reg__" "\n\t"
    "sts %0, %2" "\n \t"
    :
    : "n" (_SFR_MEM_ADDR(_WD_CONTROL_REG)),
    "r" ((uint8_t)(_BV(_WD_CHANGE_BIT) | _BV(WDE))),
    "r" ((uint8_t) ((value & 0x08 ? _WD_PS3_MASK : 0x00) |
      _BV(WDE) | (value & 0x07)) )
    : "r0"
  );
 }
}
static __inline__
__attribute__ ((__always_inline__))
void wdt_disable (void)
{
 if (_SFR_IO_REG_P (_WD_CONTROL_REG))
 {
        uint8_t register temp_reg;
  __asm__ __volatile__ (
    "in __tmp_reg__,__SREG__" "\n\t"
    "cli" "\n\t"
    "wdr" "\n\t"
    "in  %[TEMPREG],%[WDTREG]" "\n\t"
    "ori %[TEMPREG],%[WDCE_WDE]" "\n\t"
    "out %[WDTREG],%[TEMPREG]" "\n\t"
    "out %[WDTREG],__zero_reg__" "\n\t"
    "out __SREG__,__tmp_reg__" "\n\t"
    : [TEMPREG] "=d" (temp_reg)
    : [WDTREG] "I" (_SFR_IO_ADDR(_WD_CONTROL_REG)),
    [WDCE_WDE] "n" ((uint8_t)(_BV(_WD_CHANGE_BIT) | _BV(WDE)))
    : "r0"
  );
 }
 else
 {
        uint8_t register temp_reg;
  __asm__ __volatile__ (
    "in __tmp_reg__,__SREG__" "\n\t"
    "cli" "\n\t"
    "wdr" "\n\t"
    "lds %[TEMPREG],%[WDTREG]" "\n\t"
    "ori %[TEMPREG],%[WDCE_WDE]" "\n\t"
    "sts %[WDTREG],%[TEMPREG]" "\n\t"
    "sts %[WDTREG],__zero_reg__" "\n\t"
    "out __SREG__,__tmp_reg__" "\n\t"
    : [TEMPREG] "=d" (temp_reg)
    : [WDTREG] "n" (_SFR_MEM_ADDR(_WD_CONTROL_REG)),
    [WDCE_WDE] "n" ((uint8_t)(_BV(_WD_CHANGE_BIT) | _BV(WDE)))
    : "r0"
  );
 }
}
#endif
#define WDTO_15MS 0
#define WDTO_30MS 1
#define WDTO_60MS 2
#define WDTO_120MS 3
#define WDTO_250MS 4
#define WDTO_500MS 5
#define WDTO_1S 6
#define WDTO_2S 7
#if defined(__DOXYGEN__) || defined(WDP3)
#define WDTO_4S 8
#define WDTO_8S 9
#endif
#endif
