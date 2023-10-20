#ifndef _AVR_IO_H_
# error "Include <avr/io.h> instead of this file."
#endif
#ifndef _AVR_IOXXX_H_
# define _AVR_IOXXX_H_ "iox128b3.h"
#else
# error "Attempt to include more than one <avr/ioXXX.h> file."
#endif
#ifndef _AVR_ATXMEGA128B3_H_INCLUDED
#define _AVR_ATXMEGA128B3_H_INCLUDED
#define GPIOR0 _SFR_MEM8(0x0000)
#define GPIOR1 _SFR_MEM8(0x0001)
#define GPIOR2 _SFR_MEM8(0x0002)
#define GPIOR3 _SFR_MEM8(0x0003)
#define GPIO0 _SFR_MEM8(0x0000)
#define GPIO1 _SFR_MEM8(0x0001)
#define GPIO2 _SFR_MEM8(0x0002)
#define GPIO3 _SFR_MEM8(0x0003)
#define CCP _SFR_MEM8(0x0034)
#define RAMPD _SFR_MEM8(0x0038)
#define RAMPX _SFR_MEM8(0x0039)
#define RAMPY _SFR_MEM8(0x003A)
#define RAMPZ _SFR_MEM8(0x003B)
#define EIND _SFR_MEM8(0x003C)
#define SPL _SFR_MEM8(0x003D)
#define SPH _SFR_MEM8(0x003E)
#define SREG _SFR_MEM8(0x003F)
#if !defined (__ASSEMBLER__)
#include <stdint.h>
typedef volatile uint8_t register8_t;
typedef volatile uint16_t register16_t;
typedef volatile uint32_t register32_t;
#ifdef _WORDREGISTER
#undef _WORDREGISTER
#endif
#define _WORDREGISTER(regname) __extension__ union { register16_t regname; struct { register8_t regname ## L; register8_t regname ## H; }; }
#ifdef _DWORDREGISTER
#undef _DWORDREGISTER
#endif
#define _DWORDREGISTER(regname) __extension__ union { register32_t regname; struct { register8_t regname ## 0; register8_t regname ## 1; register8_t regname ## 2; register8_t regname ## 3; }; }
typedef struct AC_struct
{
    register8_t AC0CTRL;
    register8_t AC1CTRL;
    register8_t AC0MUXCTRL;
    register8_t AC1MUXCTRL;
    register8_t CTRLA;
    register8_t CTRLB;
    register8_t WINCTRL;
    register8_t STATUS;
    register8_t CURRCTRL;
    register8_t CURRCALIB;
} AC_t;
typedef enum AC_HYSMODE_enum
{
    AC_HYSMODE_NO_gc = (0x00<<1),
    AC_HYSMODE_SMALL_gc = (0x01<<1),
    AC_HYSMODE_LARGE_gc = (0x02<<1),
} AC_HYSMODE_t;
typedef enum AC_INTLVL_enum
{
    AC_INTLVL_OFF_gc = (0x00<<4),
    AC_INTLVL_LO_gc = (0x01<<4),
    AC_INTLVL_MED_gc = (0x02<<4),
    AC_INTLVL_HI_gc = (0x03<<4),
} AC_INTLVL_t;
typedef enum AC_INTMODE_enum
{
    AC_INTMODE_BOTHEDGES_gc = (0x00<<6),
    AC_INTMODE_FALLING_gc = (0x02<<6),
    AC_INTMODE_RISING_gc = (0x03<<6),
} AC_INTMODE_t;
typedef enum AC_MUXNEG_enum
{
    AC_MUXNEG_PIN0_gc = (0x00<<0),
    AC_MUXNEG_PIN1_gc = (0x01<<0),
    AC_MUXNEG_PIN3_gc = (0x02<<0),
    AC_MUXNEG_PIN5_gc = (0x03<<0),
    AC_MUXNEG_PIN7_gc = (0x04<<0),
    AC_MUXNEG_BANDGAP_gc = (0x06<<0),
    AC_MUXNEG_SCALER_gc = (0x07<<0),
} AC_MUXNEG_t;
typedef enum AC_MUXPOS_enum
{
    AC_MUXPOS_PIN0_gc = (0x00<<3),
    AC_MUXPOS_PIN1_gc = (0x01<<3),
    AC_MUXPOS_PIN2_gc = (0x02<<3),
    AC_MUXPOS_PIN3_gc = (0x03<<3),
    AC_MUXPOS_PIN4_gc = (0x04<<3),
    AC_MUXPOS_PIN5_gc = (0x05<<3),
    AC_MUXPOS_PIN6_gc = (0x06<<3),
} AC_MUXPOS_t;
typedef enum AC_WINTLVL_enum
{
    AC_WINTLVL_OFF_gc = (0x00<<0),
    AC_WINTLVL_LO_gc = (0x01<<0),
    AC_WINTLVL_MED_gc = (0x02<<0),
    AC_WINTLVL_HI_gc = (0x03<<0),
} AC_WINTLVL_t;
typedef enum AC_WINTMODE_enum
{
    AC_WINTMODE_ABOVE_gc = (0x00<<2),
    AC_WINTMODE_INSIDE_gc = (0x01<<2),
    AC_WINTMODE_BELOW_gc = (0x02<<2),
    AC_WINTMODE_OUTSIDE_gc = (0x03<<2),
} AC_WINTMODE_t;
typedef enum AC_WSTATE_enum
{
    AC_WSTATE_ABOVE_gc = (0x00<<6),
    AC_WSTATE_INSIDE_gc = (0x01<<6),
    AC_WSTATE_BELOW_gc = (0x02<<6),
} AC_WSTATE_t;
typedef struct ADC_CH_struct
{
    register8_t CTRL;
    register8_t MUXCTRL;
    register8_t INTCTRL;
    register8_t INTFLAGS;
    _WORDREGISTER(RES);
    register8_t SCAN;
    register8_t reserved_1[1];
} ADC_CH_t;
typedef struct ADC_struct
{
    register8_t CTRLA;
    register8_t CTRLB;
    register8_t REFCTRL;
    register8_t EVCTRL;
    register8_t PRESCALER;
    register8_t reserved_1[1];
    register8_t INTFLAGS;
    register8_t TEMP;
    register8_t SAMPCTRL;
    register8_t reserved_2[3];
    _WORDREGISTER(CAL);
    register8_t reserved_3[2];
    _WORDREGISTER(CH0RES);
    register8_t reserved_4[6];
    _WORDREGISTER(CMP);
    register8_t reserved_5[6];
    ADC_CH_t CH0;
} ADC_t;
typedef enum ADC_CH_GAIN_enum
{
    ADC_CH_GAIN_1X_gc = (0x00<<2),
    ADC_CH_GAIN_2X_gc = (0x01<<2),
    ADC_CH_GAIN_4X_gc = (0x02<<2),
    ADC_CH_GAIN_8X_gc = (0x03<<2),
    ADC_CH_GAIN_16X_gc = (0x04<<2),
    ADC_CH_GAIN_32X_gc = (0x05<<2),
    ADC_CH_GAIN_64X_gc = (0x06<<2),
    ADC_CH_GAIN_DIV2_gc = (0x07<<2),
} ADC_CH_GAIN_t;
typedef enum ADC_CH_INPUTMODE_enum
{
    ADC_CH_INPUTMODE_INTERNAL_gc = (0x00<<0),
    ADC_CH_INPUTMODE_SINGLEENDED_gc = (0x01<<0),
    ADC_CH_INPUTMODE_DIFF_gc = (0x02<<0),
    ADC_CH_INPUTMODE_DIFFWGAIN_gc = (0x03<<0),
} ADC_CH_INPUTMODE_t;
typedef enum ADC_CH_INTLVL_enum
{
    ADC_CH_INTLVL_OFF_gc = (0x00<<0),
    ADC_CH_INTLVL_LO_gc = (0x01<<0),
    ADC_CH_INTLVL_MED_gc = (0x02<<0),
    ADC_CH_INTLVL_HI_gc = (0x03<<0),
} ADC_CH_INTLVL_t;
typedef enum ADC_CH_INTMODE_enum
{
    ADC_CH_INTMODE_COMPLETE_gc = (0x00<<2),
    ADC_CH_INTMODE_BELOW_gc = (0x01<<2),
    ADC_CH_INTMODE_ABOVE_gc = (0x03<<2),
} ADC_CH_INTMODE_t;
typedef enum ADC_CH_MUXINT_enum
{
    ADC_CH_MUXINT_TEMP_gc = (0x00<<3),
    ADC_CH_MUXINT_BANDGAP_gc = (0x01<<3),
    ADC_CH_MUXINT_SCALEDVCC_gc = (0x02<<3),
} ADC_CH_MUXINT_t;
typedef enum ADC_CH_MUXNEG_enum
{
    ADC_CH_MUXNEG_PIN0_gc = (0x00<<0),
    ADC_CH_MUXNEG_PIN4_gc = (0x00<<0),
    ADC_CH_MUXNEG_PIN1_gc = (0x01<<0),
    ADC_CH_MUXNEG_PIN5_gc = (0x01<<0),
    ADC_CH_MUXNEG_PIN2_gc = (0x02<<0),
    ADC_CH_MUXNEG_PIN6_gc = (0x02<<0),
    ADC_CH_MUXNEG_PIN3_gc = (0x03<<0),
    ADC_CH_MUXNEG_PIN7_gc = (0x03<<0),
    ADC_CH_MUXNEG_INTGND_MODE4_gc = (0x04<<0),
    ADC_CH_MUXNEG_GND_MODE3_gc = (0x05<<0),
    ADC_CH_MUXNEG_INTGND_MODE3_gc = (0x07<<0),
    ADC_CH_MUXNEG_GND_MODE4_gc = (0x07<<0),
} ADC_CH_MUXNEG_t;
typedef enum ADC_CH_MUXNEGH_enum
{
    ADC_CH_MUXNEGH_PIN4_gc = (0x00<<0),
    ADC_CH_MUXNEGH_PIN5_gc = (0x01<<0),
    ADC_CH_MUXNEGH_PIN6_gc = (0x02<<0),
    ADC_CH_MUXNEGH_PIN7_gc = (0x03<<0),
    ADC_CH_MUXNEGH_INTGND_gc = (0x04<<0),
    ADC_CH_MUXNEGH_GND_gc = (0x07<<0),
} ADC_CH_MUXNEGH_t;
typedef enum ADC_CH_MUXNEGL_enum
{
    ADC_CH_MUXNEGL_PIN0_gc = (0x00<<0),
    ADC_CH_MUXNEGL_PIN1_gc = (0x01<<0),
    ADC_CH_MUXNEGL_PIN2_gc = (0x02<<0),
    ADC_CH_MUXNEGL_PIN3_gc = (0x03<<0),
    ADC_CH_MUXNEGL_GND_gc = (0x05<<0),
    ADC_CH_MUXNEGL_INTGND_gc = (0x07<<0),
} ADC_CH_MUXNEGL_t;
typedef enum ADC_CH_MUXPOS_enum
{
    ADC_CH_MUXPOS_PIN0_gc = (0x00<<3),
    ADC_CH_MUXPOS_PIN1_gc = (0x01<<3),
    ADC_CH_MUXPOS_PIN2_gc = (0x02<<3),
    ADC_CH_MUXPOS_PIN3_gc = (0x03<<3),
    ADC_CH_MUXPOS_PIN4_gc = (0x04<<3),
    ADC_CH_MUXPOS_PIN5_gc = (0x05<<3),
    ADC_CH_MUXPOS_PIN6_gc = (0x06<<3),
    ADC_CH_MUXPOS_PIN7_gc = (0x07<<3),
    ADC_CH_MUXPOS_PIN8_gc = (0x08<<3),
    ADC_CH_MUXPOS_PIN9_gc = (0x09<<3),
    ADC_CH_MUXPOS_PIN10_gc = (0x0A<<3),
    ADC_CH_MUXPOS_PIN11_gc = (0x0B<<3),
    ADC_CH_MUXPOS_PIN12_gc = (0x0C<<3),
    ADC_CH_MUXPOS_PIN13_gc = (0x0D<<3),
    ADC_CH_MUXPOS_PIN14_gc = (0x0E<<3),
    ADC_CH_MUXPOS_PIN15_gc = (0x0F<<3),
} ADC_CH_MUXPOS_t;
typedef enum ADC_CURRLIMIT_enum
{
    ADC_CURRLIMIT_NO_gc = (0x00<<5),
    ADC_CURRLIMIT_LOW_gc = (0x01<<5),
    ADC_CURRLIMIT_MED_gc = (0x02<<5),
    ADC_CURRLIMIT_HIGH_gc = (0x03<<5),
} ADC_CURRLIMIT_t;
typedef enum ADC_EVACT_enum
{
    ADC_EVACT_NONE_gc = (0x00<<0),
    ADC_EVACT_CH0_gc = (0x01<<0),
    ADC_EVACT_SYNCSWEEP_gc = (0x06<<0),
} ADC_EVACT_t;
typedef enum ADC_EVSEL_enum
{
    ADC_EVSEL_0_gc = (0x00<<3),
    ADC_EVSEL_1_gc = (0x01<<3),
    ADC_EVSEL_2_gc = (0x02<<3),
    ADC_EVSEL_3_gc = (0x03<<3),
} ADC_EVSEL_t;
typedef enum ADC_PRESCALER_enum
{
    ADC_PRESCALER_DIV4_gc = (0x00<<0),
    ADC_PRESCALER_DIV8_gc = (0x01<<0),
    ADC_PRESCALER_DIV16_gc = (0x02<<0),
    ADC_PRESCALER_DIV32_gc = (0x03<<0),
    ADC_PRESCALER_DIV64_gc = (0x04<<0),
    ADC_PRESCALER_DIV128_gc = (0x05<<0),
    ADC_PRESCALER_DIV256_gc = (0x06<<0),
    ADC_PRESCALER_DIV512_gc = (0x07<<0),
} ADC_PRESCALER_t;
typedef enum ADC_REFSEL_enum
{
    ADC_REFSEL_INT1V_gc = (0x00<<4),
    ADC_REFSEL_INTVCC_gc = (0x01<<4),
    ADC_REFSEL_AREFA_gc = (0x02<<4),
    ADC_REFSEL_AREFB_gc = (0x03<<4),
    ADC_REFSEL_INTVCC2_gc = (0x04<<4),
} ADC_REFSEL_t;
typedef enum ADC_RESOLUTION_enum
{
    ADC_RESOLUTION_12BIT_gc = (0x00<<1),
    ADC_RESOLUTION_8BIT_gc = (0x02<<1),
    ADC_RESOLUTION_LEFT12BIT_gc = (0x03<<1),
} ADC_RESOLUTION_t;
typedef struct AES_struct
{
    register8_t CTRL;
    register8_t STATUS;
    register8_t STATE;
    register8_t KEY;
    register8_t INTCTRL;
} AES_t;
typedef enum AES_INTLVL_enum
{
    AES_INTLVL_OFF_gc = (0x00<<0),
    AES_INTLVL_LO_gc = (0x01<<0),
    AES_INTLVL_MED_gc = (0x02<<0),
    AES_INTLVL_HI_gc = (0x03<<0),
} AES_INTLVL_t;
typedef struct AWEX_struct
{
    register8_t CTRL;
    register8_t reserved_1[1];
    register8_t FDEMASK;
    register8_t FDCTRL;
    register8_t STATUS;
    register8_t STATUSSET;
    register8_t DTBOTH;
    register8_t DTBOTHBUF;
    register8_t DTLS;
    register8_t DTHS;
    register8_t DTLSBUF;
    register8_t DTHSBUF;
    register8_t OUTOVEN;
} AWEX_t;
typedef enum AWEX_FDACT_enum
{
    AWEX_FDACT_NONE_gc = (0x00<<0),
    AWEX_FDACT_CLEAROE_gc = (0x01<<0),
    AWEX_FDACT_CLEARDIR_gc = (0x03<<0),
} AWEX_FDACT_t;
typedef struct CLK_struct
{
    register8_t CTRL;
    register8_t PSCTRL;
    register8_t LOCK;
    register8_t RTCCTRL;
    register8_t USBCTRL;
} CLK_t;
typedef enum CLK_PSADIV_enum
{
    CLK_PSADIV_1_gc = (0x00<<2),
    CLK_PSADIV_2_gc = (0x01<<2),
    CLK_PSADIV_4_gc = (0x03<<2),
    CLK_PSADIV_8_gc = (0x05<<2),
    CLK_PSADIV_16_gc = (0x07<<2),
    CLK_PSADIV_32_gc = (0x09<<2),
    CLK_PSADIV_64_gc = (0x0B<<2),
    CLK_PSADIV_128_gc = (0x0D<<2),
    CLK_PSADIV_256_gc = (0x0F<<2),
    CLK_PSADIV_512_gc = (0x11<<2),
} CLK_PSADIV_t;
typedef enum CLK_PSBCDIV_enum
{
    CLK_PSBCDIV_1_1_gc = (0x00<<0),
    CLK_PSBCDIV_1_2_gc = (0x01<<0),
    CLK_PSBCDIV_4_1_gc = (0x02<<0),
    CLK_PSBCDIV_2_2_gc = (0x03<<0),
} CLK_PSBCDIV_t;
typedef enum CLK_RTCSRC_enum
{
    CLK_RTCSRC_ULP_gc = (0x00<<1),
    CLK_RTCSRC_TOSC_gc = (0x01<<1),
    CLK_RTCSRC_RCOSC_gc = (0x02<<1),
    CLK_RTCSRC_TOSC32_gc = (0x05<<1),
    CLK_RTCSRC_RCOSC32_gc = (0x06<<1),
    CLK_RTCSRC_EXTCLK_gc = (0x07<<1),
} CLK_RTCSRC_t;
typedef enum CLK_SCLKSEL_enum
{
    CLK_SCLKSEL_RC2M_gc = (0x00<<0),
    CLK_SCLKSEL_RC32M_gc = (0x01<<0),
    CLK_SCLKSEL_RC32K_gc = (0x02<<0),
    CLK_SCLKSEL_XOSC_gc = (0x03<<0),
    CLK_SCLKSEL_PLL_gc = (0x04<<0),
} CLK_SCLKSEL_t;
typedef enum CLK_USBPSDIV_enum
{
    CLK_USBPSDIV_1_gc = (0x00<<3),
    CLK_USBPSDIV_2_gc = (0x01<<3),
    CLK_USBPSDIV_4_gc = (0x02<<3),
    CLK_USBPSDIV_8_gc = (0x03<<3),
    CLK_USBPSDIV_16_gc = (0x04<<3),
    CLK_USBPSDIV_32_gc = (0x05<<3),
} CLK_USBPSDIV_t;
typedef enum CLK_USBSRC_enum
{
    CLK_USBSRC_PLL_gc = (0x00<<1),
    CLK_USBSRC_RC32M_gc = (0x01<<1),
} CLK_USBSRC_t;
#define CORE_VERSION V3XJ
typedef enum CCP_enum
{
    CCP_SPM_gc = (0x9D<<0),
    CCP_IOREG_gc = (0xD8<<0),
} CCP_t;
typedef struct CRC_struct
{
    register8_t CTRL;
    register8_t STATUS;
    register8_t reserved_1[1];
    register8_t DATAIN;
    register8_t CHECKSUM0;
    register8_t CHECKSUM1;
    register8_t CHECKSUM2;
    register8_t CHECKSUM3;
} CRC_t;
typedef enum CRC_RESET_enum
{
    CRC_RESET_NO_gc = (0x00<<6),
    CRC_RESET_RESET0_gc = (0x02<<6),
    CRC_RESET_RESET1_gc = (0x03<<6),
} CRC_RESET_t;
typedef enum CRC_SOURCE_enum
{
    CRC_SOURCE_DISABLE_gc = (0x00<<0),
    CRC_SOURCE_IO_gc = (0x01<<0),
    CRC_SOURCE_FLASH_gc = (0x02<<0),
    CRC_SOURCE_DMAC0_gc = (0x04<<0),
    CRC_SOURCE_DMAC1_gc = (0x05<<0),
} CRC_SOURCE_t;
typedef struct DFLL_struct
{
    register8_t CTRL;
    register8_t reserved_1[1];
    register8_t CALA;
    register8_t CALB;
    register8_t COMP0;
    register8_t COMP1;
    register8_t COMP2;
    register8_t reserved_2[1];
} DFLL_t;
typedef struct DMA_CH_struct
{
    register8_t CTRLA;
    register8_t CTRLB;
    register8_t ADDRCTRL;
    register8_t TRIGSRC;
    _WORDREGISTER(TRFCNT);
    register8_t REPCNT;
    register8_t reserved_1[1];
    register8_t SRCADDR0;
    register8_t SRCADDR1;
    register8_t reserved_2[2];
    register8_t DESTADDR0;
    register8_t DESTADDR1;
    register8_t reserved_3[2];
} DMA_CH_t;
typedef struct DMA_struct
{
    register8_t CTRL;
    register8_t reserved_1[2];
    register8_t INTFLAGS;
    register8_t STATUS;
    register8_t reserved_2[1];
    _WORDREGISTER(TEMP);
    register8_t reserved_3[8];
    DMA_CH_t CH0;
    DMA_CH_t CH1;
} DMA_t;
typedef enum DMA_CH_BURSTLEN_enum
{
    DMA_CH_BURSTLEN_1BYTE_gc = (0x00<<0),
    DMA_CH_BURSTLEN_2BYTE_gc = (0x01<<0),
    DMA_CH_BURSTLEN_4BYTE_gc = (0x02<<0),
    DMA_CH_BURSTLEN_8BYTE_gc = (0x03<<0),
} DMA_CH_BURSTLEN_t;
typedef enum DMA_CH_DESTDIR_enum
{
    DMA_CH_DESTDIR_FIXED_gc = (0x00<<0),
    DMA_CH_DESTDIR_INC_gc = (0x01<<0),
    DMA_CH_DESTDIR_DEC_gc = (0x02<<0),
} DMA_CH_DESTDIR_t;
typedef enum DMA_CH_DESTRELOAD_enum
{
    DMA_CH_DESTRELOAD_NONE_gc = (0x00<<2),
    DMA_CH_DESTRELOAD_BLOCK_gc = (0x01<<2),
    DMA_CH_DESTRELOAD_BURST_gc = (0x02<<2),
    DMA_CH_DESTRELOAD_TRANSACTION_gc = (0x03<<2),
} DMA_CH_DESTRELOAD_t;
typedef enum DMA_CH_ERRINTLVL_enum
{
    DMA_CH_ERRINTLVL_OFF_gc = (0x00<<2),
    DMA_CH_ERRINTLVL_LO_gc = (0x01<<2),
    DMA_CH_ERRINTLVL_MED_gc = (0x02<<2),
    DMA_CH_ERRINTLVL_HI_gc = (0x03<<2),
} DMA_CH_ERRINTLVL_t;
typedef enum DMA_CH_SRCDIR_enum
{
    DMA_CH_SRCDIR_FIXED_gc = (0x00<<4),
    DMA_CH_SRCDIR_INC_gc = (0x01<<4),
    DMA_CH_SRCDIR_DEC_gc = (0x02<<4),
} DMA_CH_SRCDIR_t;
typedef enum DMA_CH_SRCRELOAD_enum
{
    DMA_CH_SRCRELOAD_NONE_gc = (0x00<<6),
    DMA_CH_SRCRELOAD_BLOCK_gc = (0x01<<6),
    DMA_CH_SRCRELOAD_BURST_gc = (0x02<<6),
    DMA_CH_SRCRELOAD_TRANSACTION_gc = (0x03<<6),
} DMA_CH_SRCRELOAD_t;
typedef enum DMA_CH_TRIGSRC_enum
{
    DMA_CH_TRIGSRC_OFF_gc = (0x00<<0),
    DMA_CH_TRIGSRC_EVSYS_CH0_gc = (0x01<<0),
    DMA_CH_TRIGSRC_EVSYS_CH1_gc = (0x02<<0),
    DMA_CH_TRIGSRC_EVSYS_CH2_gc = (0x03<<0),
    DMA_CH_TRIGSRC_AES_gc = (0x04<<0),
    DMA_CH_TRIGSRC_ADCA_CH0_gc = (0x10<<0),
    DMA_CH_TRIGSRC_ADCB_CH0_gc = (0x20<<0),
    DMA_CH_TRIGSRC_TCC0_OVF_gc = (0x40<<0),
    DMA_CH_TRIGSRC_TCC0_ERR_gc = (0x41<<0),
    DMA_CH_TRIGSRC_TCC0_CCA_gc = (0x42<<0),
    DMA_CH_TRIGSRC_TCC0_CCB_gc = (0x43<<0),
    DMA_CH_TRIGSRC_TCC0_CCC_gc = (0x44<<0),
    DMA_CH_TRIGSRC_TCC0_CCD_gc = (0x45<<0),
    DMA_CH_TRIGSRC_TCC1_OVF_gc = (0x46<<0),
    DMA_CH_TRIGSRC_TCC1_ERR_gc = (0x47<<0),
    DMA_CH_TRIGSRC_TCC1_CCA_gc = (0x48<<0),
    DMA_CH_TRIGSRC_TCC1_CCB_gc = (0x49<<0),
    DMA_CH_TRIGSRC_SPIC_gc = (0x4A<<0),
    DMA_CH_TRIGSRC_USARTC0_RXC_gc = (0x4B<<0),
    DMA_CH_TRIGSRC_USARTC0_DRE_gc = (0x4C<<0),
    DMA_CH_TRIGSRC_TCE0_OVF_gc = (0x80<<0),
    DMA_CH_TRIGSRC_TCE0_ERR_gc = (0x81<<0),
    DMA_CH_TRIGSRC_TCE0_CCA_gc = (0x82<<0),
    DMA_CH_TRIGSRC_TCE0_CCB_gc = (0x83<<0),
    DMA_CH_TRIGSRC_TCE0_CCC_gc = (0x84<<0),
    DMA_CH_TRIGSRC_TCE0_CCD_gc = (0x85<<0),
    DMA_CH_TRIGSRC_USARTE0_RXC_gc = (0x8B<<0),
    DMA_CH_TRIGSRC_USARTE0_DRE_gc = (0x8C<<0),
} DMA_CH_TRIGSRC_t;
typedef enum DMA_CH_TRNINTLVL_enum
{
    DMA_CH_TRNINTLVL_OFF_gc = (0x00<<0),
    DMA_CH_TRNINTLVL_LO_gc = (0x01<<0),
    DMA_CH_TRNINTLVL_MED_gc = (0x02<<0),
    DMA_CH_TRNINTLVL_HI_gc = (0x03<<0),
} DMA_CH_TRNINTLVL_t;
typedef enum DMA_DBUFMODE_enum
{
    DMA_DBUFMODE_DISABLED_gc = (0x00<<2),
    DMA_DBUFMODE_CH01_gc = (0x01<<2),
} DMA_DBUFMODE_t;
typedef enum DMA_PRIMODE_enum
{
    DMA_PRIMODE_RR01_gc = (0x00<<0),
    DMA_PRIMODE_CH0RR1_gc = (0x01<<0),
} DMA_PRIMODE_t;
typedef struct EVSYS_struct
{
    register8_t CH0MUX;
    register8_t CH1MUX;
    register8_t CH2MUX;
    register8_t CH3MUX;
    register8_t reserved_1[4];
    register8_t CH0CTRL;
    register8_t CH1CTRL;
    register8_t CH2CTRL;
    register8_t CH3CTRL;
    register8_t reserved_2[4];
    register8_t STROBE;
    register8_t DATA;
} EVSYS_t;
typedef enum EVSYS_CHMUX_enum
{
    EVSYS_CHMUX_OFF_gc = (0x00<<0),
    EVSYS_CHMUX_RTC_OVF_gc = (0x08<<0),
    EVSYS_CHMUX_RTC_CMP_gc = (0x09<<0),
    EVSYS_CHMUX_USB_gc = (0x0A<<0),
    EVSYS_CHMUX_ACA_CH0_gc = (0x10<<0),
    EVSYS_CHMUX_ACA_CH1_gc = (0x11<<0),
    EVSYS_CHMUX_ACA_WIN_gc = (0x12<<0),
    EVSYS_CHMUX_ACB_CH0_gc = (0x13<<0),
    EVSYS_CHMUX_ACB_CH1_gc = (0x14<<0),
    EVSYS_CHMUX_ACB_WIN_gc = (0x15<<0),
    EVSYS_CHMUX_ADCA_CH0_gc = (0x20<<0),
    EVSYS_CHMUX_ADCB_CH0_gc = (0x24<<0),
    EVSYS_CHMUX_PORTA_PIN0_gc = (0x50<<0),
    EVSYS_CHMUX_PORTA_PIN1_gc = (0x51<<0),
    EVSYS_CHMUX_PORTA_PIN2_gc = (0x52<<0),
    EVSYS_CHMUX_PORTA_PIN3_gc = (0x53<<0),
    EVSYS_CHMUX_PORTA_PIN4_gc = (0x54<<0),
    EVSYS_CHMUX_PORTA_PIN5_gc = (0x55<<0),
    EVSYS_CHMUX_PORTA_PIN6_gc = (0x56<<0),
    EVSYS_CHMUX_PORTA_PIN7_gc = (0x57<<0),
    EVSYS_CHMUX_PORTB_PIN0_gc = (0x58<<0),
    EVSYS_CHMUX_PORTB_PIN1_gc = (0x59<<0),
    EVSYS_CHMUX_PORTB_PIN2_gc = (0x5A<<0),
    EVSYS_CHMUX_PORTB_PIN3_gc = (0x5B<<0),
    EVSYS_CHMUX_PORTB_PIN4_gc = (0x5C<<0),
    EVSYS_CHMUX_PORTB_PIN5_gc = (0x5D<<0),
    EVSYS_CHMUX_PORTB_PIN6_gc = (0x5E<<0),
    EVSYS_CHMUX_PORTB_PIN7_gc = (0x5F<<0),
    EVSYS_CHMUX_PORTC_PIN0_gc = (0x60<<0),
    EVSYS_CHMUX_PORTC_PIN1_gc = (0x61<<0),
    EVSYS_CHMUX_PORTC_PIN2_gc = (0x62<<0),
    EVSYS_CHMUX_PORTC_PIN3_gc = (0x63<<0),
    EVSYS_CHMUX_PORTC_PIN4_gc = (0x64<<0),
    EVSYS_CHMUX_PORTC_PIN5_gc = (0x65<<0),
    EVSYS_CHMUX_PORTC_PIN6_gc = (0x66<<0),
    EVSYS_CHMUX_PORTC_PIN7_gc = (0x67<<0),
    EVSYS_CHMUX_PORTD_PIN0_gc = (0x68<<0),
    EVSYS_CHMUX_PORTD_PIN1_gc = (0x69<<0),
    EVSYS_CHMUX_PORTD_PIN2_gc = (0x6A<<0),
    EVSYS_CHMUX_PORTE_PIN0_gc = (0x70<<0),
    EVSYS_CHMUX_PORTE_PIN1_gc = (0x71<<0),
    EVSYS_CHMUX_PORTE_PIN2_gc = (0x72<<0),
    EVSYS_CHMUX_PORTE_PIN3_gc = (0x73<<0),
    EVSYS_CHMUX_PORTE_PIN4_gc = (0x74<<0),
    EVSYS_CHMUX_PORTE_PIN5_gc = (0x75<<0),
    EVSYS_CHMUX_PORTE_PIN6_gc = (0x76<<0),
    EVSYS_CHMUX_PORTE_PIN7_gc = (0x77<<0),
    EVSYS_CHMUX_PRESCALER_1_gc = (0x80<<0),
    EVSYS_CHMUX_PRESCALER_2_gc = (0x81<<0),
    EVSYS_CHMUX_PRESCALER_4_gc = (0x82<<0),
    EVSYS_CHMUX_PRESCALER_8_gc = (0x83<<0),
    EVSYS_CHMUX_PRESCALER_16_gc = (0x84<<0),
    EVSYS_CHMUX_PRESCALER_32_gc = (0x85<<0),
    EVSYS_CHMUX_PRESCALER_64_gc = (0x86<<0),
    EVSYS_CHMUX_PRESCALER_128_gc = (0x87<<0),
    EVSYS_CHMUX_PRESCALER_256_gc = (0x88<<0),
    EVSYS_CHMUX_PRESCALER_512_gc = (0x89<<0),
    EVSYS_CHMUX_PRESCALER_1024_gc = (0x8A<<0),
    EVSYS_CHMUX_PRESCALER_2048_gc = (0x8B<<0),
    EVSYS_CHMUX_PRESCALER_4096_gc = (0x8C<<0),
    EVSYS_CHMUX_PRESCALER_8192_gc = (0x8D<<0),
    EVSYS_CHMUX_PRESCALER_16384_gc = (0x8E<<0),
    EVSYS_CHMUX_PRESCALER_32768_gc = (0x8F<<0),
    EVSYS_CHMUX_TCC0_OVF_gc = (0xC0<<0),
    EVSYS_CHMUX_TCC0_ERR_gc = (0xC1<<0),
    EVSYS_CHMUX_TCC0_CCA_gc = (0xC4<<0),
    EVSYS_CHMUX_TCC0_CCB_gc = (0xC5<<0),
    EVSYS_CHMUX_TCC0_CCC_gc = (0xC6<<0),
    EVSYS_CHMUX_TCC0_CCD_gc = (0xC7<<0),
    EVSYS_CHMUX_TCC1_OVF_gc = (0xC8<<0),
    EVSYS_CHMUX_TCC1_ERR_gc = (0xC9<<0),
    EVSYS_CHMUX_TCC1_CCA_gc = (0xCC<<0),
    EVSYS_CHMUX_TCC1_CCB_gc = (0xCD<<0),
    EVSYS_CHMUX_TCE0_OVF_gc = (0xE0<<0),
    EVSYS_CHMUX_TCE0_ERR_gc = (0xE1<<0),
    EVSYS_CHMUX_TCE0_CCA_gc = (0xE4<<0),
    EVSYS_CHMUX_TCE0_CCB_gc = (0xE5<<0),
    EVSYS_CHMUX_TCE0_CCC_gc = (0xE6<<0),
    EVSYS_CHMUX_TCE0_CCD_gc = (0xE7<<0),
} EVSYS_CHMUX_t;
typedef enum EVSYS_DIGFILT_enum
{
    EVSYS_DIGFILT_1SAMPLE_gc = (0x00<<0),
    EVSYS_DIGFILT_2SAMPLES_gc = (0x01<<0),
    EVSYS_DIGFILT_3SAMPLES_gc = (0x02<<0),
    EVSYS_DIGFILT_4SAMPLES_gc = (0x03<<0),
    EVSYS_DIGFILT_5SAMPLES_gc = (0x04<<0),
    EVSYS_DIGFILT_6SAMPLES_gc = (0x05<<0),
    EVSYS_DIGFILT_7SAMPLES_gc = (0x06<<0),
    EVSYS_DIGFILT_8SAMPLES_gc = (0x07<<0),
} EVSYS_DIGFILT_t;
typedef enum EVSYS_QDIRM_enum
{
    EVSYS_QDIRM_00_gc = (0x00<<5),
    EVSYS_QDIRM_01_gc = (0x01<<5),
    EVSYS_QDIRM_10_gc = (0x02<<5),
    EVSYS_QDIRM_11_gc = (0x03<<5),
} EVSYS_QDIRM_t;
typedef struct NVM_FUSES_struct
{
    register8_t FUSEBYTE0;
    register8_t FUSEBYTE1;
    register8_t FUSEBYTE2;
    register8_t reserved_1[1];
    register8_t FUSEBYTE4;
    register8_t FUSEBYTE5;
} NVM_FUSES_t;
typedef enum BODACT_enum
{
    BODACT_SAMPLED_gc = (0x01<<4),
    BODACT_CONTINUOUS_gc = (0x02<<4),
    BODACT_DISABLED_gc = (0x03<<4),
} BODACT_t;
typedef enum BODLEVEL_enum
{
    BODLEVEL_3V0_gc = (0x00<<0),
    BODLEVEL_2V8_gc = (0x01<<0),
    BODLEVEL_2V6_gc = (0x02<<0),
    BODLEVEL_2V4_gc = (0x03<<0),
    BODLEVEL_2V2_gc = (0x04<<0),
    BODLEVEL_2V0_gc = (0x05<<0),
    BODLEVEL_1V8_gc = (0x06<<0),
    BODLEVEL_1V6_gc = (0x07<<0),
} BODLEVEL_t;
typedef enum BODPD_enum
{
    BODPD_SAMPLED_gc = (0x01<<0),
    BODPD_CONTINUOUS_gc = (0x02<<0),
    BODPD_DISABLED_gc = (0x03<<0),
} BODPD_t;
typedef enum BOOTRST_enum
{
    BOOTRST_BOOTLDR_gc = (0x00<<6),
    BOOTRST_APPLICATION_gc = (0x01<<6),
} BOOTRST_t;
typedef enum STARTUPTIME_enum
{
    STARTUPTIME_64MS_gc = (0x00<<2),
    STARTUPTIME_4MS_gc = (0x01<<2),
    STARTUPTIME_0MS_gc = (0x03<<2),
} STARTUPTIME_t;
typedef enum TOSCSEL_enum
{
    TOSCSEL_ALTERNATE_gc = (0x00<<5),
    TOSCSEL_XTAL_gc = (0x01<<5),
} TOSCSEL_t;
typedef enum WDPER_enum
{
    WDPER_8CLK_gc = (0x00<<0),
    WDPER_16CLK_gc = (0x01<<0),
    WDPER_32CLK_gc = (0x02<<0),
    WDPER_64CLK_gc = (0x03<<0),
    WDPER_128CLK_gc = (0x04<<0),
    WDPER_256CLK_gc = (0x05<<0),
    WDPER_512CLK_gc = (0x06<<0),
    WDPER_1KCLK_gc = (0x07<<0),
    WDPER_2KCLK_gc = (0x08<<0),
    WDPER_4KCLK_gc = (0x09<<0),
    WDPER_8KCLK_gc = (0x0A<<0),
} WDPER_t;
typedef enum WDWPER_enum
{
    WDWPER_8CLK_gc = (0x00<<4),
    WDWPER_16CLK_gc = (0x01<<4),
    WDWPER_32CLK_gc = (0x02<<4),
    WDWPER_64CLK_gc = (0x03<<4),
    WDWPER_128CLK_gc = (0x04<<4),
    WDWPER_256CLK_gc = (0x05<<4),
    WDWPER_512CLK_gc = (0x06<<4),
    WDWPER_1KCLK_gc = (0x07<<4),
    WDWPER_2KCLK_gc = (0x08<<4),
    WDWPER_4KCLK_gc = (0x09<<4),
    WDWPER_8KCLK_gc = (0x0A<<4),
} WDWPER_t;
typedef struct HIRES_struct
{
    register8_t CTRLA;
} HIRES_t;
typedef enum HIRES_HREN_enum
{
    HIRES_HREN_NONE_gc = (0x00<<0),
    HIRES_HREN_TC0_gc = (0x01<<0),
    HIRES_HREN_TC1_gc = (0x02<<0),
    HIRES_HREN_BOTH_gc = (0x03<<0),
} HIRES_HREN_t;
typedef struct IRCOM_struct
{
    register8_t CTRL;
    register8_t TXPLCTRL;
    register8_t RXPLCTRL;
} IRCOM_t;
typedef enum IRCOM_EVSEL_enum
{
    IRCOM_EVSEL_OFF_gc = (0x00<<0),
    IRCOM_EVSEL_0_gc = (0x08<<0),
    IRCOM_EVSEL_1_gc = (0x09<<0),
    IRCOM_EVSEL_2_gc = (0x0A<<0),
    IRCOM_EVSEL_3_gc = (0x0B<<0),
} IRCOM_EVSEL_t;
typedef struct LCD_struct
{
    register8_t CTRLA;
    register8_t CTRLB;
    register8_t CTRLC;
    register8_t INTCTRL;
    register8_t INTFLAG;
    register8_t CTRLD;
    register8_t CTRLE;
    register8_t CTRLF;
    register8_t CTRLG;
    register8_t CTRLH;
    register8_t reserved_1[6];
    register8_t DATA0;
    register8_t DATA1;
    register8_t DATA2;
    register8_t DATA3;
    register8_t DATA4;
    register8_t DATA5;
    register8_t DATA6;
    register8_t DATA7;
    register8_t DATA8;
    register8_t DATA9;
    register8_t DATA10;
    register8_t DATA11;
    register8_t DATA12;
    register8_t DATA13;
    register8_t DATA14;
    register8_t DATA15;
    register8_t DATA16;
    register8_t DATA17;
    register8_t DATA18;
    register8_t DATA19;
} LCD_t;
typedef enum LCD_BLINKRATE_enum
{
    LCD_BLINKRATE_4Hz_gc = (0x00<<0),
    LCD_BLINKRATE_2Hz_gc = (0x01<<0),
    LCD_BLINKRATE_1Hz_gc = (0x02<<0),
    LCD_BLINKRATE_0Hz5_gc = (0x03<<0),
} LCD_BLINKRATE_t;
typedef enum LCD_CLKDIV_enum
{
    LCD_CLKDIV_DivBy1_gc = (0x00<<4),
    LCD_CLKDIV_DivBy2_gc = (0x01<<4),
    LCD_CLKDIV_DivBy3_gc = (0x02<<4),
    LCD_CLKDIV_DivBy4_gc = (0x03<<4),
    LCD_CLKDIV_DivBy5_gc = (0x04<<4),
    LCD_CLKDIV_DivBy6_gc = (0x05<<4),
    LCD_CLKDIV_DivBy7_gc = (0x06<<4),
    LCD_CLKDIV_DivBy8_gc = (0x07<<4),
} LCD_CLKDIV_t;
typedef enum LCD_DUTY_enum
{
    LCD_DUTY_1_4_gc = (0x00<<0),
    LCD_DUTY_Static_gc = (0x01<<0),
    LCD_DUTY_1_2_gc = (0x02<<0),
    LCD_DUTY_1_3_gc = (0x03<<0),
} LCD_DUTY_t;
typedef enum LCD_FCINTLVL_enum
{
    LCD_FCINTLVL_OFF_gc = (0x00<<0),
    LCD_FCINTLVL_LO_gc = (0x01<<0),
    LCD_FCINTLVL_MED_gc = (0x02<<0),
    LCD_FCINTLVL_HI_gc = (0x03<<0),
} LCD_FCINTLVL_t;
typedef enum LCD_PRESC_enum
{
    LCD_PRESC_8_gc = (0x00<<7),
    LCD_PRESC_16_gc = (0x01<<7),
} LCD_PRESC_t;
typedef enum LCD_TDG_enum
{
    LCD_TDG_7S_3C_gc = (0x00<<6),
    LCD_TDG_7S_4C_gc = (0x01<<6),
    LCD_TDG_14S_4C_gc = (0x02<<6),
    LCD_TDG_16S_3C_gc = (0x03<<6),
} LCD_TDG_t;
typedef struct NVM_LOCKBITS_struct
{
    register8_t LOCK_BITS;
} NVM_LOCKBITS_t;
typedef enum BLBA_enum
{
    BLBA_RWLOCK_gc = (0x00<<4),
    BLBA_RLOCK_gc = (0x01<<4),
    BLBA_WLOCK_gc = (0x02<<4),
    BLBA_NOLOCK_gc = (0x03<<4),
} BLBA_t;
typedef enum BLBAT_enum
{
    BLBAT_RWLOCK_gc = (0x00<<2),
    BLBAT_RLOCK_gc = (0x01<<2),
    BLBAT_WLOCK_gc = (0x02<<2),
    BLBAT_NOLOCK_gc = (0x03<<2),
} BLBAT_t;
typedef enum BLBB_enum
{
    BLBB_RWLOCK_gc = (0x00<<6),
    BLBB_RLOCK_gc = (0x01<<6),
    BLBB_WLOCK_gc = (0x02<<6),
    BLBB_NOLOCK_gc = (0x03<<6),
} BLBB_t;
typedef enum LB_enum
{
    LB_RWLOCK_gc = (0x00<<0),
    LB_WLOCK_gc = (0x02<<0),
    LB_NOLOCK_gc = (0x03<<0),
} LB_t;
typedef struct MCU_struct
{
    register8_t DEVID0;
    register8_t DEVID1;
    register8_t DEVID2;
    register8_t REVID;
    register8_t JTAGUID;
    register8_t reserved_1[1];
    register8_t MCUCR;
    register8_t ANAINIT;
    register8_t EVSYSLOCK;
    register8_t AWEXLOCK;
    register8_t reserved_2[2];
} MCU_t;
typedef struct NVM_struct
{
    register8_t ADDR0;
    register8_t ADDR1;
    register8_t ADDR2;
    register8_t reserved_1[1];
    register8_t DATA0;
    register8_t DATA1;
    register8_t DATA2;
    register8_t reserved_2[3];
    register8_t CMD;
    register8_t CTRLA;
    register8_t CTRLB;
    register8_t INTCTRL;
    register8_t reserved_3[1];
    register8_t STATUS;
    register8_t LOCK_BITS;
} NVM_t;
typedef enum NVM_BLBA_enum
{
    NVM_BLBA_RWLOCK_gc = (0x00<<4),
    NVM_BLBA_RLOCK_gc = (0x01<<4),
    NVM_BLBA_WLOCK_gc = (0x02<<4),
    NVM_BLBA_NOLOCK_gc = (0x03<<4),
} NVM_BLBA_t;
typedef enum NVM_BLBAT_enum
{
    NVM_BLBAT_RWLOCK_gc = (0x00<<2),
    NVM_BLBAT_RLOCK_gc = (0x01<<2),
    NVM_BLBAT_WLOCK_gc = (0x02<<2),
    NVM_BLBAT_NOLOCK_gc = (0x03<<2),
} NVM_BLBAT_t;
typedef enum NVM_BLBB_enum
{
    NVM_BLBB_RWLOCK_gc = (0x00<<6),
    NVM_BLBB_RLOCK_gc = (0x01<<6),
    NVM_BLBB_WLOCK_gc = (0x02<<6),
    NVM_BLBB_NOLOCK_gc = (0x03<<6),
} NVM_BLBB_t;
typedef enum NVM_CMD_enum
{
    NVM_CMD_NO_OPERATION_gc = (0x00<<0),
    NVM_CMD_READ_USER_SIG_ROW_gc = (0x01<<0),
    NVM_CMD_READ_CALIB_ROW_gc = (0x02<<0),
    NVM_CMD_READ_EEPROM_gc = (0x06<<0),
    NVM_CMD_READ_FUSES_gc = (0x07<<0),
    NVM_CMD_WRITE_LOCK_BITS_gc = (0x08<<0),
    NVM_CMD_ERASE_USER_SIG_ROW_gc = (0x18<<0),
    NVM_CMD_WRITE_USER_SIG_ROW_gc = (0x1A<<0),
    NVM_CMD_ERASE_APP_gc = (0x20<<0),
    NVM_CMD_ERASE_APP_PAGE_gc = (0x22<<0),
    NVM_CMD_LOAD_FLASH_BUFFER_gc = (0x23<<0),
    NVM_CMD_WRITE_APP_PAGE_gc = (0x24<<0),
    NVM_CMD_ERASE_WRITE_APP_PAGE_gc = (0x25<<0),
    NVM_CMD_ERASE_FLASH_BUFFER_gc = (0x26<<0),
    NVM_CMD_ERASE_BOOT_PAGE_gc = (0x2A<<0),
    NVM_CMD_ERASE_FLASH_PAGE_gc = (0x2B<<0),
    NVM_CMD_WRITE_BOOT_PAGE_gc = (0x2C<<0),
    NVM_CMD_ERASE_WRITE_BOOT_PAGE_gc = (0x2D<<0),
    NVM_CMD_WRITE_FLASH_PAGE_gc = (0x2E<<0),
    NVM_CMD_ERASE_WRITE_FLASH_PAGE_gc = (0x2F<<0),
    NVM_CMD_ERASE_EEPROM_gc = (0x30<<0),
    NVM_CMD_ERASE_EEPROM_PAGE_gc = (0x32<<0),
    NVM_CMD_LOAD_EEPROM_BUFFER_gc = (0x33<<0),
    NVM_CMD_WRITE_EEPROM_PAGE_gc = (0x34<<0),
    NVM_CMD_ERASE_WRITE_EEPROM_PAGE_gc = (0x35<<0),
    NVM_CMD_ERASE_EEPROM_BUFFER_gc = (0x36<<0),
    NVM_CMD_APP_CRC_gc = (0x38<<0),
    NVM_CMD_BOOT_CRC_gc = (0x39<<0),
    NVM_CMD_FLASH_RANGE_CRC_gc = (0x3A<<0),
    NVM_CMD_CHIP_ERASE_gc = (0x40<<0),
    NVM_CMD_READ_NVM_gc = (0x43<<0),
    NVM_CMD_WRITE_FUSE_gc = (0x4C<<0),
    NVM_CMD_ERASE_BOOT_gc = (0x68<<0),
    NVM_CMD_FLASH_CRC_gc = (0x78<<0),
} NVM_CMD_t;
typedef enum NVM_EELVL_enum
{
    NVM_EELVL_OFF_gc = (0x00<<0),
    NVM_EELVL_LO_gc = (0x01<<0),
    NVM_EELVL_MED_gc = (0x02<<0),
    NVM_EELVL_HI_gc = (0x03<<0),
} NVM_EELVL_t;
typedef enum NVM_LB_enum
{
    NVM_LB_RWLOCK_gc = (0x00<<0),
    NVM_LB_WLOCK_gc = (0x02<<0),
    NVM_LB_NOLOCK_gc = (0x03<<0),
} NVM_LB_t;
typedef enum NVM_SPMLVL_enum
{
    NVM_SPMLVL_OFF_gc = (0x00<<2),
    NVM_SPMLVL_LO_gc = (0x01<<2),
    NVM_SPMLVL_MED_gc = (0x02<<2),
    NVM_SPMLVL_HI_gc = (0x03<<2),
} NVM_SPMLVL_t;
typedef struct OSC_struct
{
    register8_t CTRL;
    register8_t STATUS;
    register8_t XOSCCTRL;
    register8_t XOSCFAIL;
    register8_t RC32KCAL;
    register8_t PLLCTRL;
    register8_t DFLLCTRL;
} OSC_t;
typedef enum OSC_FRQRANGE_enum
{
    OSC_FRQRANGE_04TO2_gc = (0x00<<6),
    OSC_FRQRANGE_2TO9_gc = (0x01<<6),
    OSC_FRQRANGE_9TO12_gc = (0x02<<6),
    OSC_FRQRANGE_12TO16_gc = (0x03<<6),
} OSC_FRQRANGE_t;
typedef enum OSC_PLLSRC_enum
{
    OSC_PLLSRC_RC2M_gc = (0x00<<6),
    OSC_PLLSRC_RC32M_gc = (0x02<<6),
    OSC_PLLSRC_XOSC_gc = (0x03<<6),
} OSC_PLLSRC_t;
typedef enum OSC_RC2MCREF_enum
{
    OSC_RC2MCREF_RC32K_gc = (0x00<<0),
    OSC_RC2MCREF_XOSC32K_gc = (0x01<<0),
} OSC_RC2MCREF_t;
typedef enum OSC_RC32MCREF_enum
{
    OSC_RC32MCREF_RC32K_gc = (0x00<<1),
    OSC_RC32MCREF_XOSC32K_gc = (0x01<<1),
    OSC_RC32MCREF_USBSOF_gc = (0x02<<1),
} OSC_RC32MCREF_t;
typedef enum OSC_XOSCSEL_enum
{
    OSC_XOSCSEL_EXTCLK_gc = (0x00<<0),
    OSC_XOSCSEL_EXTCLK_C0_gc = (0x01<<0),
    OSC_XOSCSEL_32KHz_gc = (0x02<<0),
    OSC_XOSCSEL_XTAL_256CLK_gc = (0x03<<0),
    OSC_XOSCSEL_EXTCLK_C1_gc = (0x05<<0),
    OSC_XOSCSEL_XTAL_1KCLK_gc = (0x07<<0),
    OSC_XOSCSEL_EXTCLK_C2_gc = (0x09<<0),
    OSC_XOSCSEL_XTAL_16KCLK_gc = (0x0B<<0),
    OSC_XOSCSEL_EXTCLK_C3_gc = (0x0D<<0),
    OSC_XOSCSEL_EXTCLK_C4_gc = (0x11<<0),
    OSC_XOSCSEL_EXTCLK_C5_gc = (0x15<<0),
    OSC_XOSCSEL_EXTCLK_C6_gc = (0x19<<0),
    OSC_XOSCSEL_EXTCLK_C7_gc = (0x1D<<0),
} OSC_XOSCSEL_t;
typedef struct PMIC_struct
{
    register8_t STATUS;
    register8_t INTPRI;
    register8_t CTRL;
    register8_t reserved_1[13];
} PMIC_t;
typedef struct PORT_struct
{
    register8_t DIR;
    register8_t DIRSET;
    register8_t DIRCLR;
    register8_t DIRTGL;
    register8_t OUT;
    register8_t OUTSET;
    register8_t OUTCLR;
    register8_t OUTTGL;
    register8_t IN;
    register8_t INTCTRL;
    register8_t INT0MASK;
    register8_t INT1MASK;
    register8_t INTFLAGS;
    register8_t reserved_1[1];
    register8_t REMAP;
    register8_t reserved_2[1];
    register8_t PIN0CTRL;
    register8_t PIN1CTRL;
    register8_t PIN2CTRL;
    register8_t PIN3CTRL;
    register8_t PIN4CTRL;
    register8_t PIN5CTRL;
    register8_t PIN6CTRL;
    register8_t PIN7CTRL;
} PORT_t;
typedef enum PORT_INT0LVL_enum
{
    PORT_INT0LVL_OFF_gc = (0x00<<0),
    PORT_INT0LVL_LO_gc = (0x01<<0),
    PORT_INT0LVL_MED_gc = (0x02<<0),
    PORT_INT0LVL_HI_gc = (0x03<<0),
} PORT_INT0LVL_t;
typedef enum PORT_INT1LVL_enum
{
    PORT_INT1LVL_OFF_gc = (0x00<<2),
    PORT_INT1LVL_LO_gc = (0x01<<2),
    PORT_INT1LVL_MED_gc = (0x02<<2),
    PORT_INT1LVL_HI_gc = (0x03<<2),
} PORT_INT1LVL_t;
typedef enum PORT_ISC_enum
{
    PORT_ISC_BOTHEDGES_gc = (0x00<<0),
    PORT_ISC_RISING_gc = (0x01<<0),
    PORT_ISC_FALLING_gc = (0x02<<0),
    PORT_ISC_LEVEL_gc = (0x03<<0),
    PORT_ISC_INPUT_DISABLE_gc = (0x07<<0),
} PORT_ISC_t;
typedef enum PORT_OPC_enum
{
    PORT_OPC_TOTEM_gc = (0x00<<3),
    PORT_OPC_BUSKEEPER_gc = (0x01<<3),
    PORT_OPC_PULLDOWN_gc = (0x02<<3),
    PORT_OPC_PULLUP_gc = (0x03<<3),
    PORT_OPC_WIREDOR_gc = (0x04<<3),
    PORT_OPC_WIREDAND_gc = (0x05<<3),
    PORT_OPC_WIREDORPULL_gc = (0x06<<3),
    PORT_OPC_WIREDANDPULL_gc = (0x07<<3),
} PORT_OPC_t;
typedef struct PORTCFG_struct
{
    register8_t MPCMASK;
    register8_t reserved_1[1];
    register8_t VPCTRLA;
    register8_t VPCTRLB;
    register8_t CLKEVOUT;
    register8_t reserved_2[1];
    register8_t EVOUTSEL;
} PORTCFG_t;
typedef enum PORTCFG_CLKEVPIN_enum
{
    PORTCFG_CLKEVPIN_PIN7_gc = (0x00<<7),
    PORTCFG_CLKEVPIN_PIN4_gc = (0x01<<7),
} PORTCFG_CLKEVPIN_t;
typedef enum PORTCFG_CLKOUT_enum
{
    PORTCFG_CLKOUT_OFF_gc = (0x00<<0),
    PORTCFG_CLKOUT_PC_gc = (0x01<<0),
    PORTCFG_CLKOUT_PE_gc = (0x03<<0),
} PORTCFG_CLKOUT_t;
typedef enum PORTCFG_CLKOUTSEL_enum
{
    PORTCFG_CLKOUTSEL_CLK1X_gc = (0x00<<2),
    PORTCFG_CLKOUTSEL_CLK2X_gc = (0x01<<2),
    PORTCFG_CLKOUTSEL_CLK4X_gc = (0x02<<2),
} PORTCFG_CLKOUTSEL_t;
typedef enum PORTCFG_EVOUT_enum
{
    PORTCFG_EVOUT_OFF_gc = (0x00<<4),
    PORTCFG_EVOUT_PC_gc = (0x01<<4),
    PORTCFG_EVOUT_PE_gc = (0x03<<4),
} PORTCFG_EVOUT_t;
typedef enum PORTCFG_EVOUTSEL_enum
{
    PORTCFG_EVOUTSEL_0_gc = (0x00<<2),
    PORTCFG_EVOUTSEL_1_gc = (0x01<<2),
    PORTCFG_EVOUTSEL_2_gc = (0x02<<2),
    PORTCFG_EVOUTSEL_3_gc = (0x03<<2),
} PORTCFG_EVOUTSEL_t;
typedef enum PORTCFG_VP0MAP_enum
{
    PORTCFG_VP0MAP_PORTA_gc = (0x00<<0),
    PORTCFG_VP0MAP_PORTB_gc = (0x01<<0),
    PORTCFG_VP0MAP_PORTC_gc = (0x02<<0),
    PORTCFG_VP0MAP_PORTD_gc = (0x03<<0),
    PORTCFG_VP0MAP_PORTE_gc = (0x04<<0),
    PORTCFG_VP0MAP_PORTG_gc = (0x06<<0),
    PORTCFG_VP0MAP_PORTM_gc = (0x0B<<0),
    PORTCFG_VP0MAP_PORTR_gc = (0x0F<<0),
    PORTCFG_VP02MAP_PORTA_gc = (0x00<<0),
    PORTCFG_VP02MAP_PORTB_gc = (0x01<<0),
    PORTCFG_VP02MAP_PORTC_gc = (0x02<<0),
    PORTCFG_VP02MAP_PORTD_gc = (0x03<<0),
    PORTCFG_VP02MAP_PORTE_gc = (0x04<<0),
    PORTCFG_VP02MAP_PORTG_gc = (0x06<<0),
    PORTCFG_VP02MAP_PORTM_gc = (0x0B<<0),
    PORTCFG_VP02MAP_PORTR_gc = (0x0F<<0),
} PORTCFG_VP0MAP_t;
typedef enum PORTCFG_VP0MAP_enum PORTCFG_VP02MAP_t;
typedef enum PORTCFG_VP1MAP_enum
{
    PORTCFG_VP1MAP_PORTA_gc = (0x00<<4),
    PORTCFG_VP1MAP_PORTB_gc = (0x01<<4),
    PORTCFG_VP1MAP_PORTC_gc = (0x02<<4),
    PORTCFG_VP1MAP_PORTD_gc = (0x03<<4),
    PORTCFG_VP1MAP_PORTE_gc = (0x04<<4),
    PORTCFG_VP1MAP_PORTG_gc = (0x06<<4),
    PORTCFG_VP1MAP_PORTM_gc = (0x0B<<4),
    PORTCFG_VP1MAP_PORTR_gc = (0x0F<<4),
    PORTCFG_VP13MAP_PORTA_gc = (0x00<<4),
    PORTCFG_VP13MAP_PORTB_gc = (0x01<<4),
    PORTCFG_VP13MAP_PORTC_gc = (0x02<<4),
    PORTCFG_VP13MAP_PORTD_gc = (0x03<<4),
    PORTCFG_VP13MAP_PORTE_gc = (0x04<<4),
    PORTCFG_VP13MAP_PORTG_gc = (0x06<<4),
    PORTCFG_VP13MAP_PORTM_gc = (0x0B<<4),
    PORTCFG_VP13MAP_PORTR_gc = (0x0F<<4),
} PORTCFG_VP1MAP_t;
typedef enum PORTCFG_VP1MAP_enum PORTCFG_VP13MAP_t;
typedef enum PORTCFG_VP2MAP_enum
{
    PORTCFG_VP2MAP_PORTA_gc = (0x00<<0),
    PORTCFG_VP2MAP_PORTB_gc = (0x01<<0),
    PORTCFG_VP2MAP_PORTC_gc = (0x02<<0),
    PORTCFG_VP2MAP_PORTD_gc = (0x03<<0),
    PORTCFG_VP2MAP_PORTE_gc = (0x04<<0),
    PORTCFG_VP2MAP_PORTG_gc = (0x06<<0),
    PORTCFG_VP2MAP_PORTM_gc = (0x0B<<0),
    PORTCFG_VP2MAP_PORTR_gc = (0x0F<<0),
} PORTCFG_VP2MAP_t;
typedef enum PORTCFG_VP3MAP_enum
{
    PORTCFG_VP3MAP_PORTA_gc = (0x00<<4),
    PORTCFG_VP3MAP_PORTB_gc = (0x01<<4),
    PORTCFG_VP3MAP_PORTC_gc = (0x02<<4),
    PORTCFG_VP3MAP_PORTD_gc = (0x03<<4),
    PORTCFG_VP3MAP_PORTE_gc = (0x04<<4),
    PORTCFG_VP3MAP_PORTG_gc = (0x06<<4),
    PORTCFG_VP3MAP_PORTM_gc = (0x0B<<4),
    PORTCFG_VP3MAP_PORTR_gc = (0x0F<<4),
} PORTCFG_VP3MAP_t;
typedef struct PR_struct
{
    register8_t PRGEN;
    register8_t PRPA;
    register8_t PRPB;
    register8_t PRPC;
    register8_t reserved_1[1];
    register8_t PRPE;
} PR_t;
typedef struct RST_struct
{
    register8_t STATUS;
    register8_t CTRL;
} RST_t;
typedef struct RTC_struct
{
    register8_t CTRL;
    register8_t STATUS;
    register8_t INTCTRL;
    register8_t INTFLAGS;
    register8_t TEMP;
    register8_t reserved_1[3];
    _WORDREGISTER(CNT);
    _WORDREGISTER(PER);
    _WORDREGISTER(COMP);
} RTC_t;
typedef enum RTC_COMPINTLVL_enum
{
    RTC_COMPINTLVL_OFF_gc = (0x00<<2),
    RTC_COMPINTLVL_LO_gc = (0x01<<2),
    RTC_COMPINTLVL_MED_gc = (0x02<<2),
    RTC_COMPINTLVL_HI_gc = (0x03<<2),
} RTC_COMPINTLVL_t;
typedef enum RTC_OVFINTLVL_enum
{
    RTC_OVFINTLVL_OFF_gc = (0x00<<0),
    RTC_OVFINTLVL_LO_gc = (0x01<<0),
    RTC_OVFINTLVL_MED_gc = (0x02<<0),
    RTC_OVFINTLVL_HI_gc = (0x03<<0),
} RTC_OVFINTLVL_t;
typedef enum RTC_PRESCALER_enum
{
    RTC_PRESCALER_OFF_gc = (0x00<<0),
    RTC_PRESCALER_DIV1_gc = (0x01<<0),
    RTC_PRESCALER_DIV2_gc = (0x02<<0),
    RTC_PRESCALER_DIV8_gc = (0x03<<0),
    RTC_PRESCALER_DIV16_gc = (0x04<<0),
    RTC_PRESCALER_DIV64_gc = (0x05<<0),
    RTC_PRESCALER_DIV256_gc = (0x06<<0),
    RTC_PRESCALER_DIV1024_gc = (0x07<<0),
} RTC_PRESCALER_t;
typedef struct NVM_PROD_SIGNATURES_struct
{
    register8_t RCOSC2M;
    register8_t RCOSC2MA;
    register8_t RCOSC32K;
    register8_t RCOSC32M;
    register8_t RCOSC32MA;
    register8_t reserved_1[3];
    register8_t LOTNUM0;
    register8_t LOTNUM1;
    register8_t LOTNUM2;
    register8_t LOTNUM3;
    register8_t LOTNUM4;
    register8_t LOTNUM5;
    register8_t reserved_2[2];
    register8_t WAFNUM;
    register8_t reserved_3[1];
    register8_t COORDX0;
    register8_t COORDX1;
    register8_t COORDY0;
    register8_t COORDY1;
    register8_t reserved_4[4];
    register8_t USBCAL0;
    register8_t USBCAL1;
    register8_t USBRCOSC;
    register8_t USBRCOSCA;
    register8_t reserved_5[2];
    register8_t ADCACAL0;
    register8_t ADCACAL1;
    register8_t reserved_6[2];
    register8_t ADCBCAL0;
    register8_t ADCBCAL1;
    register8_t reserved_7[8];
    register8_t TEMPSENSE0;
    register8_t TEMPSENSE1;
    register8_t reserved_8[24];
} NVM_PROD_SIGNATURES_t;
typedef struct SLEEP_struct
{
    register8_t CTRL;
} SLEEP_t;
typedef enum SLEEP_SMODE_enum
{
    SLEEP_SMODE_IDLE_gc = (0x00<<1),
    SLEEP_SMODE_PDOWN_gc = (0x02<<1),
    SLEEP_SMODE_PSAVE_gc = (0x03<<1),
    SLEEP_SMODE_STDBY_gc = (0x06<<1),
    SLEEP_SMODE_ESTDBY_gc = (0x07<<1),
} SLEEP_SMODE_t;
#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_PWR_DOWN (0x02<<1)
#define SLEEP_MODE_PWR_SAVE (0x03<<1)
#define SLEEP_MODE_STANDBY (0x06<<1)
#define SLEEP_MODE_EXT_STANDBY (0x07<<1)
typedef struct SPI_struct
{
    register8_t CTRL;
    register8_t INTCTRL;
    register8_t STATUS;
    register8_t DATA;
} SPI_t;
typedef enum SPI_INTLVL_enum
{
    SPI_INTLVL_OFF_gc = (0x00<<0),
    SPI_INTLVL_LO_gc = (0x01<<0),
    SPI_INTLVL_MED_gc = (0x02<<0),
    SPI_INTLVL_HI_gc = (0x03<<0),
} SPI_INTLVL_t;
typedef enum SPI_MODE_enum
{
    SPI_MODE_0_gc = (0x00<<2),
    SPI_MODE_1_gc = (0x01<<2),
    SPI_MODE_2_gc = (0x02<<2),
    SPI_MODE_3_gc = (0x03<<2),
} SPI_MODE_t;
typedef enum SPI_PRESCALER_enum
{
    SPI_PRESCALER_DIV4_gc = (0x00<<0),
    SPI_PRESCALER_DIV16_gc = (0x01<<0),
    SPI_PRESCALER_DIV64_gc = (0x02<<0),
    SPI_PRESCALER_DIV128_gc = (0x03<<0),
} SPI_PRESCALER_t;
typedef struct TC0_struct
{
    register8_t CTRLA;
    register8_t CTRLB;
    register8_t CTRLC;
    register8_t CTRLD;
    register8_t CTRLE;
    register8_t reserved_1[1];
    register8_t INTCTRLA;
    register8_t INTCTRLB;
    register8_t CTRLFCLR;
    register8_t CTRLFSET;
    register8_t CTRLGCLR;
    register8_t CTRLGSET;
    register8_t INTFLAGS;
    register8_t reserved_2[2];
    register8_t TEMP;
    register8_t reserved_3[16];
    _WORDREGISTER(CNT);
    register8_t reserved_4[4];
    _WORDREGISTER(PER);
    _WORDREGISTER(CCA);
    _WORDREGISTER(CCB);
    _WORDREGISTER(CCC);
    _WORDREGISTER(CCD);
    register8_t reserved_5[6];
    _WORDREGISTER(PERBUF);
    _WORDREGISTER(CCABUF);
    _WORDREGISTER(CCBBUF);
    _WORDREGISTER(CCCBUF);
    _WORDREGISTER(CCDBUF);
} TC0_t;
typedef struct TC1_struct
{
    register8_t CTRLA;
    register8_t CTRLB;
    register8_t CTRLC;
    register8_t CTRLD;
    register8_t CTRLE;
    register8_t reserved_1[1];
    register8_t INTCTRLA;
    register8_t INTCTRLB;
    register8_t CTRLFCLR;
    register8_t CTRLFSET;
    register8_t CTRLGCLR;
    register8_t CTRLGSET;
    register8_t INTFLAGS;
    register8_t reserved_2[2];
    register8_t TEMP;
    register8_t reserved_3[16];
    _WORDREGISTER(CNT);
    register8_t reserved_4[4];
    _WORDREGISTER(PER);
    _WORDREGISTER(CCA);
    _WORDREGISTER(CCB);
    register8_t reserved_5[10];
    _WORDREGISTER(PERBUF);
    _WORDREGISTER(CCABUF);
    _WORDREGISTER(CCBBUF);
} TC1_t;
typedef enum TC_BYTEM_enum
{
    TC_BYTEM_NORMAL_gc = (0x00<<0),
    TC_BYTEM_BYTEMODE_gc = (0x01<<0),
    TC_BYTEM_SPLITMODE_gc = (0x02<<0),
} TC_BYTEM_t;
typedef enum TC_CCAINTLVL_enum
{
    TC_CCAINTLVL_OFF_gc = (0x00<<0),
    TC_CCAINTLVL_LO_gc = (0x01<<0),
    TC_CCAINTLVL_MED_gc = (0x02<<0),
    TC_CCAINTLVL_HI_gc = (0x03<<0),
} TC_CCAINTLVL_t;
typedef enum TC_CCBINTLVL_enum
{
    TC_CCBINTLVL_OFF_gc = (0x00<<2),
    TC_CCBINTLVL_LO_gc = (0x01<<2),
    TC_CCBINTLVL_MED_gc = (0x02<<2),
    TC_CCBINTLVL_HI_gc = (0x03<<2),
} TC_CCBINTLVL_t;
typedef enum TC_CCCINTLVL_enum
{
    TC_CCCINTLVL_OFF_gc = (0x00<<4),
    TC_CCCINTLVL_LO_gc = (0x01<<4),
    TC_CCCINTLVL_MED_gc = (0x02<<4),
    TC_CCCINTLVL_HI_gc = (0x03<<4),
} TC_CCCINTLVL_t;
typedef enum TC_CCDINTLVL_enum
{
    TC_CCDINTLVL_OFF_gc = (0x00<<6),
    TC_CCDINTLVL_LO_gc = (0x01<<6),
    TC_CCDINTLVL_MED_gc = (0x02<<6),
    TC_CCDINTLVL_HI_gc = (0x03<<6),
} TC_CCDINTLVL_t;
typedef enum TC_CLKSEL_enum
{
    TC_CLKSEL_OFF_gc = (0x00<<0),
    TC_CLKSEL_DIV1_gc = (0x01<<0),
    TC_CLKSEL_DIV2_gc = (0x02<<0),
    TC_CLKSEL_DIV4_gc = (0x03<<0),
    TC_CLKSEL_DIV8_gc = (0x04<<0),
    TC_CLKSEL_DIV64_gc = (0x05<<0),
    TC_CLKSEL_DIV256_gc = (0x06<<0),
    TC_CLKSEL_DIV1024_gc = (0x07<<0),
    TC_CLKSEL_EVCH0_gc = (0x08<<0),
    TC_CLKSEL_EVCH1_gc = (0x09<<0),
    TC_CLKSEL_EVCH2_gc = (0x0A<<0),
    TC_CLKSEL_EVCH3_gc = (0x0B<<0),
} TC_CLKSEL_t;
typedef enum TC_CMD_enum
{
    TC_CMD_NONE_gc = (0x00<<2),
    TC_CMD_UPDATE_gc = (0x01<<2),
    TC_CMD_RESTART_gc = (0x02<<2),
    TC_CMD_RESET_gc = (0x03<<2),
} TC_CMD_t;
typedef enum TC_ERRINTLVL_enum
{
    TC_ERRINTLVL_OFF_gc = (0x00<<2),
    TC_ERRINTLVL_LO_gc = (0x01<<2),
    TC_ERRINTLVL_MED_gc = (0x02<<2),
    TC_ERRINTLVL_HI_gc = (0x03<<2),
} TC_ERRINTLVL_t;
typedef enum TC_EVACT_enum
{
    TC_EVACT_OFF_gc = (0x00<<5),
    TC_EVACT_CAPT_gc = (0x01<<5),
    TC_EVACT_UPDOWN_gc = (0x02<<5),
    TC_EVACT_QDEC_gc = (0x03<<5),
    TC_EVACT_RESTART_gc = (0x04<<5),
    TC_EVACT_FRQ_gc = (0x05<<5),
    TC_EVACT_PW_gc = (0x06<<5),
} TC_EVACT_t;
typedef enum TC_EVSEL_enum
{
    TC_EVSEL_OFF_gc = (0x00<<0),
    TC_EVSEL_CH0_gc = (0x08<<0),
    TC_EVSEL_CH1_gc = (0x09<<0),
    TC_EVSEL_CH2_gc = (0x0A<<0),
    TC_EVSEL_CH3_gc = (0x0B<<0),
} TC_EVSEL_t;
typedef enum TC_OVFINTLVL_enum
{
    TC_OVFINTLVL_OFF_gc = (0x00<<0),
    TC_OVFINTLVL_LO_gc = (0x01<<0),
    TC_OVFINTLVL_MED_gc = (0x02<<0),
    TC_OVFINTLVL_HI_gc = (0x03<<0),
} TC_OVFINTLVL_t;
typedef enum TC_WGMODE_enum
{
    TC_WGMODE_NORMAL_gc = (0x00<<0),
    TC_WGMODE_FRQ_gc = (0x01<<0),
    TC_WGMODE_SINGLESLOPE_gc = (0x03<<0),
    TC_WGMODE_SS_gc = (0x03<<0),
    TC_WGMODE_DSTOP_gc = (0x05<<0),
    TC_WGMODE_DS_T_gc = (0x05<<0),
    TC_WGMODE_DSBOTH_gc = (0x06<<0),
    TC_WGMODE_DS_TB_gc = (0x06<<0),
    TC_WGMODE_DSBOTTOM_gc = (0x07<<0),
    TC_WGMODE_DS_B_gc = (0x07<<0),
} TC_WGMODE_t;
typedef struct TC2_struct
{
    register8_t CTRLA;
    register8_t CTRLB;
    register8_t CTRLC;
    register8_t reserved_1[1];
    register8_t CTRLE;
    register8_t reserved_2[1];
    register8_t INTCTRLA;
    register8_t INTCTRLB;
    register8_t reserved_3[1];
    register8_t CTRLF;
    register8_t reserved_4[2];
    register8_t INTFLAGS;
    register8_t reserved_5[19];
    register8_t LCNT;
    register8_t HCNT;
    register8_t reserved_6[4];
    register8_t LPER;
    register8_t HPER;
    register8_t LCMPA;
    register8_t HCMPA;
    register8_t LCMPB;
    register8_t HCMPB;
    register8_t LCMPC;
    register8_t HCMPC;
    register8_t LCMPD;
    register8_t HCMPD;
} TC2_t;
typedef enum TC2_BYTEM_enum
{
    TC2_BYTEM_NORMAL_gc = (0x00<<0),
    TC2_BYTEM_BYTEMODE_gc = (0x01<<0),
    TC2_BYTEM_SPLITMODE_gc = (0x02<<0),
} TC2_BYTEM_t;
typedef enum TC2_CLKSEL_enum
{
    TC2_CLKSEL_OFF_gc = (0x00<<0),
    TC2_CLKSEL_DIV1_gc = (0x01<<0),
    TC2_CLKSEL_DIV2_gc = (0x02<<0),
    TC2_CLKSEL_DIV4_gc = (0x03<<0),
    TC2_CLKSEL_DIV8_gc = (0x04<<0),
    TC2_CLKSEL_DIV64_gc = (0x05<<0),
    TC2_CLKSEL_DIV256_gc = (0x06<<0),
    TC2_CLKSEL_DIV1024_gc = (0x07<<0),
    TC2_CLKSEL_EVCH0_gc = (0x08<<0),
    TC2_CLKSEL_EVCH1_gc = (0x09<<0),
    TC2_CLKSEL_EVCH2_gc = (0x0A<<0),
    TC2_CLKSEL_EVCH3_gc = (0x0B<<0),
} TC2_CLKSEL_t;
typedef enum TC2_CMD_enum
{
    TC2_CMD_NONE_gc = (0x00<<2),
    TC2_CMD_RESTART_gc = (0x02<<2),
    TC2_CMD_RESET_gc = (0x03<<2),
} TC2_CMD_t;
typedef enum TC2_CMDEN_enum
{
    TC2_CMDEN_LOW_gc = (0x01<<0),
    TC2_CMDEN_HIGH_gc = (0x02<<0),
    TC2_CMDEN_BOTH_gc = (0x03<<0),
} TC2_CMDEN_t;
typedef enum TC2_HUNFINTLVL_enum
{
    TC2_HUNFINTLVL_OFF_gc = (0x00<<2),
    TC2_HUNFINTLVL_LO_gc = (0x01<<2),
    TC2_HUNFINTLVL_MED_gc = (0x02<<2),
    TC2_HUNFINTLVL_HI_gc = (0x03<<2),
} TC2_HUNFINTLVL_t;
typedef enum TC2_LCMPAINTLVL_enum
{
    TC2_LCMPAINTLVL_OFF_gc = (0x00<<0),
    TC2_LCMPAINTLVL_LO_gc = (0x01<<0),
    TC2_LCMPAINTLVL_MED_gc = (0x02<<0),
    TC2_LCMPAINTLVL_HI_gc = (0x03<<0),
} TC2_LCMPAINTLVL_t;
typedef enum TC2_LCMPBINTLVL_enum
{
    TC2_LCMPBINTLVL_OFF_gc = (0x00<<2),
    TC2_LCMPBINTLVL_LO_gc = (0x01<<2),
    TC2_LCMPBINTLVL_MED_gc = (0x02<<2),
    TC2_LCMPBINTLVL_HI_gc = (0x03<<2),
} TC2_LCMPBINTLVL_t;
typedef enum TC2_LCMPCINTLVL_enum
{
    TC2_LCMPCINTLVL_OFF_gc = (0x00<<4),
    TC2_LCMPCINTLVL_LO_gc = (0x01<<4),
    TC2_LCMPCINTLVL_MED_gc = (0x02<<4),
    TC2_LCMPCINTLVL_HI_gc = (0x03<<4),
} TC2_LCMPCINTLVL_t;
typedef enum TC2_LCMPDINTLVL_enum
{
    TC2_LCMPDINTLVL_OFF_gc = (0x00<<6),
    TC2_LCMPDINTLVL_LO_gc = (0x01<<6),
    TC2_LCMPDINTLVL_MED_gc = (0x02<<6),
    TC2_LCMPDINTLVL_HI_gc = (0x03<<6),
} TC2_LCMPDINTLVL_t;
typedef enum TC2_LUNFINTLVL_enum
{
    TC2_LUNFINTLVL_OFF_gc = (0x00<<0),
    TC2_LUNFINTLVL_LO_gc = (0x01<<0),
    TC2_LUNFINTLVL_MED_gc = (0x02<<0),
    TC2_LUNFINTLVL_HI_gc = (0x03<<0),
} TC2_LUNFINTLVL_t;
typedef struct TWI_MASTER_struct
{
    register8_t CTRLA;
    register8_t CTRLB;
    register8_t CTRLC;
    register8_t STATUS;
    register8_t BAUD;
    register8_t ADDR;
    register8_t DATA;
} TWI_MASTER_t;
typedef struct TWI_SLAVE_struct
{
    register8_t CTRLA;
    register8_t CTRLB;
    register8_t STATUS;
    register8_t ADDR;
    register8_t DATA;
    register8_t ADDRMASK;
} TWI_SLAVE_t;
typedef struct TWI_struct
{
    register8_t CTRL;
    TWI_MASTER_t MASTER;
    TWI_SLAVE_t SLAVE;
} TWI_t;
typedef enum TWI_MASTER_BUSSTATE_enum
{
    TWI_MASTER_BUSSTATE_UNKNOWN_gc = (0x00<<0),
    TWI_MASTER_BUSSTATE_IDLE_gc = (0x01<<0),
    TWI_MASTER_BUSSTATE_OWNER_gc = (0x02<<0),
    TWI_MASTER_BUSSTATE_BUSY_gc = (0x03<<0),
} TWI_MASTER_BUSSTATE_t;
typedef enum TWI_MASTER_CMD_enum
{
    TWI_MASTER_CMD_NOACT_gc = (0x00<<0),
    TWI_MASTER_CMD_REPSTART_gc = (0x01<<0),
    TWI_MASTER_CMD_RECVTRANS_gc = (0x02<<0),
    TWI_MASTER_CMD_STOP_gc = (0x03<<0),
} TWI_MASTER_CMD_t;
typedef enum TWI_MASTER_INTLVL_enum
{
    TWI_MASTER_INTLVL_OFF_gc = (0x00<<6),
    TWI_MASTER_INTLVL_LO_gc = (0x01<<6),
    TWI_MASTER_INTLVL_MED_gc = (0x02<<6),
    TWI_MASTER_INTLVL_HI_gc = (0x03<<6),
} TWI_MASTER_INTLVL_t;
typedef enum TWI_MASTER_TIMEOUT_enum
{
    TWI_MASTER_TIMEOUT_DISABLED_gc = (0x00<<2),
    TWI_MASTER_TIMEOUT_50US_gc = (0x01<<2),
    TWI_MASTER_TIMEOUT_100US_gc = (0x02<<2),
    TWI_MASTER_TIMEOUT_200US_gc = (0x03<<2),
} TWI_MASTER_TIMEOUT_t;
typedef enum TWI_SLAVE_CMD_enum
{
    TWI_SLAVE_CMD_NOACT_gc = (0x00<<0),
    TWI_SLAVE_CMD_COMPTRANS_gc = (0x02<<0),
    TWI_SLAVE_CMD_RESPONSE_gc = (0x03<<0),
} TWI_SLAVE_CMD_t;
typedef enum TWI_SLAVE_INTLVL_enum
{
    TWI_SLAVE_INTLVL_OFF_gc = (0x00<<6),
    TWI_SLAVE_INTLVL_LO_gc = (0x01<<6),
    TWI_SLAVE_INTLVL_MED_gc = (0x02<<6),
    TWI_SLAVE_INTLVL_HI_gc = (0x03<<6),
} TWI_SLAVE_INTLVL_t;
typedef enum TWI_SDAHOLD_enum
{
    TWI_SDAHOLD_OFF_gc = (0x00<<1),
    TWI_SDAHOLD_50NS_gc = (0x01<<1),
    TWI_SDAHOLD_300NS_gc = (0x02<<1),
    TWI_SDAHOLD_400NS_gc = (0x03<<1),
} TWI_SDAHOLD_t;
typedef struct USART_struct
{
    register8_t DATA;
    register8_t STATUS;
    register8_t reserved_1[1];
    register8_t CTRLA;
    register8_t CTRLB;
    register8_t CTRLC;
    register8_t BAUDCTRLA;
    register8_t BAUDCTRLB;
} USART_t;
typedef enum USART_CHSIZE_enum
{
    USART_CHSIZE_5BIT_gc = (0x00<<0),
    USART_CHSIZE_6BIT_gc = (0x01<<0),
    USART_CHSIZE_7BIT_gc = (0x02<<0),
    USART_CHSIZE_8BIT_gc = (0x03<<0),
    USART_CHSIZE_9BIT_gc = (0x07<<0),
} USART_CHSIZE_t;
typedef enum USART_CMODE_enum
{
    USART_CMODE_ASYNCHRONOUS_gc = (0x00<<6),
    USART_CMODE_SYNCHRONOUS_gc = (0x01<<6),
    USART_CMODE_IRDA_gc = (0x02<<6),
    USART_CMODE_MSPI_gc = (0x03<<6),
} USART_CMODE_t;
typedef enum USART_DREINTLVL_enum
{
    USART_DREINTLVL_OFF_gc = (0x00<<0),
    USART_DREINTLVL_LO_gc = (0x01<<0),
    USART_DREINTLVL_MED_gc = (0x02<<0),
    USART_DREINTLVL_HI_gc = (0x03<<0),
} USART_DREINTLVL_t;
typedef enum USART_PMODE_enum
{
    USART_PMODE_DISABLED_gc = (0x00<<4),
    USART_PMODE_EVEN_gc = (0x02<<4),
    USART_PMODE_ODD_gc = (0x03<<4),
} USART_PMODE_t;
typedef enum USART_RXCINTLVL_enum
{
    USART_RXCINTLVL_OFF_gc = (0x00<<4),
    USART_RXCINTLVL_LO_gc = (0x01<<4),
    USART_RXCINTLVL_MED_gc = (0x02<<4),
    USART_RXCINTLVL_HI_gc = (0x03<<4),
} USART_RXCINTLVL_t;
typedef enum USART_TXCINTLVL_enum
{
    USART_TXCINTLVL_OFF_gc = (0x00<<2),
    USART_TXCINTLVL_LO_gc = (0x01<<2),
    USART_TXCINTLVL_MED_gc = (0x02<<2),
    USART_TXCINTLVL_HI_gc = (0x03<<2),
} USART_TXCINTLVL_t;
typedef struct USB_EP_struct
{
    register8_t STATUS;
    register8_t CTRL;
    _WORDREGISTER(CNT);
    _WORDREGISTER(DATAPTR);
    _WORDREGISTER(AUXDATA);
} USB_EP_t;
typedef struct USB_struct
{
    register8_t CTRLA;
    register8_t CTRLB;
    register8_t STATUS;
    register8_t ADDR;
    register8_t FIFOWP;
    register8_t FIFORP;
    _WORDREGISTER(EPPTR);
    register8_t INTCTRLA;
    register8_t INTCTRLB;
    register8_t INTFLAGSACLR;
    register8_t INTFLAGSASET;
    register8_t INTFLAGSBCLR;
    register8_t INTFLAGSBSET;
    register8_t reserved_1[44];
    register8_t CAL0;
    register8_t CAL1;
} USB_t;
typedef struct USB_EP_TABLE_struct
{
    USB_EP_t EP0OUT;
    USB_EP_t EP0IN;
    USB_EP_t EP1OUT;
    USB_EP_t EP1IN;
    USB_EP_t EP2OUT;
    USB_EP_t EP2IN;
    USB_EP_t EP3OUT;
    USB_EP_t EP3IN;
    USB_EP_t EP4OUT;
    USB_EP_t EP4IN;
    USB_EP_t EP5OUT;
    USB_EP_t EP5IN;
    USB_EP_t EP6OUT;
    USB_EP_t EP6IN;
    USB_EP_t EP7OUT;
    USB_EP_t EP7IN;
    USB_EP_t EP8OUT;
    USB_EP_t EP8IN;
    USB_EP_t EP9OUT;
    USB_EP_t EP9IN;
    USB_EP_t EP10OUT;
    USB_EP_t EP10IN;
    USB_EP_t EP11OUT;
    USB_EP_t EP11IN;
    USB_EP_t EP12OUT;
    USB_EP_t EP12IN;
    USB_EP_t EP13OUT;
    USB_EP_t EP13IN;
    USB_EP_t EP14OUT;
    USB_EP_t EP14IN;
    USB_EP_t EP15OUT;
    USB_EP_t EP15IN;
    register8_t reserved_1[16];
    register8_t FRAMENUML;
    register8_t FRAMENUMH;
} USB_EP_TABLE_t;
typedef enum USB_EP_BUFSIZE_enum
{
    USB_EP_BUFSIZE_8_gc = (0x00<<0),
    USB_EP_BUFSIZE_16_gc = (0x01<<0),
    USB_EP_BUFSIZE_32_gc = (0x02<<0),
    USB_EP_BUFSIZE_64_gc = (0x03<<0),
    USB_EP_BUFSIZE_128_gc = (0x04<<0),
    USB_EP_BUFSIZE_256_gc = (0x05<<0),
    USB_EP_BUFSIZE_512_gc = (0x06<<0),
    USB_EP_BUFSIZE_1023_gc = (0x07<<0),
} USB_EP_BUFSIZE_t;
typedef enum USB_EP_TYPE_enum
{
    USB_EP_TYPE_DISABLE_gc = (0x00<<6),
    USB_EP_TYPE_CONTROL_gc = (0x01<<6),
    USB_EP_TYPE_BULK_gc = (0x02<<6),
    USB_EP_TYPE_ISOCHRONOUS_gc = (0x03<<6),
} USB_EP_TYPE_t;
typedef enum USB_INTLVL_enum
{
    USB_INTLVL_OFF_gc = (0x00<<0),
    USB_INTLVL_LO_gc = (0x01<<0),
    USB_INTLVL_MED_gc = (0x02<<0),
    USB_INTLVL_HI_gc = (0x03<<0),
} USB_INTLVL_t;
typedef struct VPORT_struct
{
    register8_t DIR;
    register8_t OUT;
    register8_t IN;
    register8_t INTFLAGS;
} VPORT_t;
typedef struct WDT_struct
{
    register8_t CTRL;
    register8_t WINCTRL;
    register8_t STATUS;
} WDT_t;
typedef enum WDT_PER_enum
{
    WDT_PER_8CLK_gc = (0x00<<2),
    WDT_PER_16CLK_gc = (0x01<<2),
    WDT_PER_32CLK_gc = (0x02<<2),
    WDT_PER_64CLK_gc = (0x03<<2),
    WDT_PER_128CLK_gc = (0x04<<2),
    WDT_PER_256CLK_gc = (0x05<<2),
    WDT_PER_512CLK_gc = (0x06<<2),
    WDT_PER_1KCLK_gc = (0x07<<2),
    WDT_PER_2KCLK_gc = (0x08<<2),
    WDT_PER_4KCLK_gc = (0x09<<2),
    WDT_PER_8KCLK_gc = (0x0A<<2),
} WDT_PER_t;
typedef enum WDT_WPER_enum
{
    WDT_WPER_8CLK_gc = (0x00<<2),
    WDT_WPER_16CLK_gc = (0x01<<2),
    WDT_WPER_32CLK_gc = (0x02<<2),
    WDT_WPER_64CLK_gc = (0x03<<2),
    WDT_WPER_128CLK_gc = (0x04<<2),
    WDT_WPER_256CLK_gc = (0x05<<2),
    WDT_WPER_512CLK_gc = (0x06<<2),
    WDT_WPER_1KCLK_gc = (0x07<<2),
    WDT_WPER_2KCLK_gc = (0x08<<2),
    WDT_WPER_4KCLK_gc = (0x09<<2),
    WDT_WPER_8KCLK_gc = (0x0A<<2),
} WDT_WPER_t;
typedef struct OCD_struct
{
    register8_t OCDR0;
    register8_t OCDR1;
} OCD_t;
#define VPORT0 (*(VPORT_t *) 0x0010)
#define VPORT1 (*(VPORT_t *) 0x0014)
#define VPORT2 (*(VPORT_t *) 0x0018)
#define VPORT3 (*(VPORT_t *) 0x001C)
#define OCD (*(OCD_t *) 0x002E)
#define CLK (*(CLK_t *) 0x0040)
#define SLEEP (*(SLEEP_t *) 0x0048)
#define OSC (*(OSC_t *) 0x0050)
#define DFLLRC32M (*(DFLL_t *) 0x0060)
#define DFLLRC2M (*(DFLL_t *) 0x0068)
#define PR (*(PR_t *) 0x0070)
#define RST (*(RST_t *) 0x0078)
#define WDT (*(WDT_t *) 0x0080)
#define MCU (*(MCU_t *) 0x0090)
#define PMIC (*(PMIC_t *) 0x00A0)
#define PORTCFG (*(PORTCFG_t *) 0x00B0)
#define AES (*(AES_t *) 0x00C0)
#define CRC (*(CRC_t *) 0x00D0)
#define DMA (*(DMA_t *) 0x0100)
#define EVSYS (*(EVSYS_t *) 0x0180)
#define NVM (*(NVM_t *) 0x01C0)
#define ADCB (*(ADC_t *) 0x0240)
#define ACB (*(AC_t *) 0x0390)
#define RTC (*(RTC_t *) 0x0400)
#define TWIC (*(TWI_t *) 0x0480)
#define USB (*(USB_t *) 0x04C0)
#define PORTB (*(PORT_t *) 0x0620)
#define PORTC (*(PORT_t *) 0x0640)
#define PORTD (*(PORT_t *) 0x0660)
#define PORTG (*(PORT_t *) 0x06C0)
#define PORTM (*(PORT_t *) 0x0760)
#define PORTR (*(PORT_t *) 0x07E0)
#define TCC0 (*(TC0_t *) 0x0800)
#define TCC2 (*(TC2_t *) 0x0800)
#define TCC1 (*(TC1_t *) 0x0840)
#define AWEXC (*(AWEX_t *) 0x0880)
#define HIRESC (*(HIRES_t *) 0x0890)
#define USARTC0 (*(USART_t *) 0x08A0)
#define SPIC (*(SPI_t *) 0x08C0)
#define IRCOM (*(IRCOM_t *) 0x08F8)
#define LCD (*(LCD_t *) 0x0D00)
#endif
#define GPIO_GPIOR0 _SFR_MEM8(0x0000)
#define GPIO_GPIOR1 _SFR_MEM8(0x0001)
#define GPIO_GPIOR2 _SFR_MEM8(0x0002)
#define GPIO_GPIOR3 _SFR_MEM8(0x0003)
#define GPIO_GPIO0 _SFR_MEM8(0x0000)
#define GPIO_GPIO1 _SFR_MEM8(0x0001)
#define GPIO_GPIO2 _SFR_MEM8(0x0002)
#define GPIO_GPIO3 _SFR_MEM8(0x0003)
#define FUSE_FUSEBYTE0 _SFR_MEM8(0x0000)
#define FUSE_FUSEBYTE1 _SFR_MEM8(0x0001)
#define FUSE_FUSEBYTE2 _SFR_MEM8(0x0002)
#define FUSE_FUSEBYTE4 _SFR_MEM8(0x0004)
#define FUSE_FUSEBYTE5 _SFR_MEM8(0x0005)
#define LOCKBIT_LOCKBITS _SFR_MEM8(0x0000)
#define PRODSIGNATURES_RCOSC2M _SFR_MEM8(0x0000)
#define PRODSIGNATURES_RCOSC2MA _SFR_MEM8(0x0001)
#define PRODSIGNATURES_RCOSC32K _SFR_MEM8(0x0002)
#define PRODSIGNATURES_RCOSC32M _SFR_MEM8(0x0003)
#define PRODSIGNATURES_RCOSC32MA _SFR_MEM8(0x0004)
#define PRODSIGNATURES_LOTNUM0 _SFR_MEM8(0x0008)
#define PRODSIGNATURES_LOTNUM1 _SFR_MEM8(0x0009)
#define PRODSIGNATURES_LOTNUM2 _SFR_MEM8(0x000A)
#define PRODSIGNATURES_LOTNUM3 _SFR_MEM8(0x000B)
#define PRODSIGNATURES_LOTNUM4 _SFR_MEM8(0x000C)
#define PRODSIGNATURES_LOTNUM5 _SFR_MEM8(0x000D)
#define PRODSIGNATURES_WAFNUM _SFR_MEM8(0x0010)
#define PRODSIGNATURES_COORDX0 _SFR_MEM8(0x0012)
#define PRODSIGNATURES_COORDX1 _SFR_MEM8(0x0013)
#define PRODSIGNATURES_COORDY0 _SFR_MEM8(0x0014)
#define PRODSIGNATURES_COORDY1 _SFR_MEM8(0x0015)
#define PRODSIGNATURES_USBCAL0 _SFR_MEM8(0x001A)
#define PRODSIGNATURES_USBCAL1 _SFR_MEM8(0x001B)
#define PRODSIGNATURES_USBRCOSC _SFR_MEM8(0x001C)
#define PRODSIGNATURES_USBRCOSCA _SFR_MEM8(0x001D)
#define PRODSIGNATURES_ADCACAL0 _SFR_MEM8(0x0020)
#define PRODSIGNATURES_ADCACAL1 _SFR_MEM8(0x0021)
#define PRODSIGNATURES_ADCBCAL0 _SFR_MEM8(0x0024)
#define PRODSIGNATURES_ADCBCAL1 _SFR_MEM8(0x0025)
#define PRODSIGNATURES_TEMPSENSE0 _SFR_MEM8(0x002E)
#define PRODSIGNATURES_TEMPSENSE1 _SFR_MEM8(0x002F)
#define VPORT0_DIR _SFR_MEM8(0x0010)
#define VPORT0_OUT _SFR_MEM8(0x0011)
#define VPORT0_IN _SFR_MEM8(0x0012)
#define VPORT0_INTFLAGS _SFR_MEM8(0x0013)
#define VPORT1_DIR _SFR_MEM8(0x0014)
#define VPORT1_OUT _SFR_MEM8(0x0015)
#define VPORT1_IN _SFR_MEM8(0x0016)
#define VPORT1_INTFLAGS _SFR_MEM8(0x0017)
#define VPORT2_DIR _SFR_MEM8(0x0018)
#define VPORT2_OUT _SFR_MEM8(0x0019)
#define VPORT2_IN _SFR_MEM8(0x001A)
#define VPORT2_INTFLAGS _SFR_MEM8(0x001B)
#define VPORT3_DIR _SFR_MEM8(0x001C)
#define VPORT3_OUT _SFR_MEM8(0x001D)
#define VPORT3_IN _SFR_MEM8(0x001E)
#define VPORT3_INTFLAGS _SFR_MEM8(0x001F)
#define OCD_OCDR0 _SFR_MEM8(0x002E)
#define OCD_OCDR1 _SFR_MEM8(0x002F)
#define CPU_CCP _SFR_MEM8(0x0034)
#define CPU_RAMPD _SFR_MEM8(0x0038)
#define CPU_RAMPX _SFR_MEM8(0x0039)
#define CPU_RAMPY _SFR_MEM8(0x003A)
#define CPU_RAMPZ _SFR_MEM8(0x003B)
#define CPU_EIND _SFR_MEM8(0x003C)
#define CPU_SPL _SFR_MEM8(0x003D)
#define CPU_SPH _SFR_MEM8(0x003E)
#define CPU_SREG _SFR_MEM8(0x003F)
#define CLK_CTRL _SFR_MEM8(0x0040)
#define CLK_PSCTRL _SFR_MEM8(0x0041)
#define CLK_LOCK _SFR_MEM8(0x0042)
#define CLK_RTCCTRL _SFR_MEM8(0x0043)
#define CLK_USBCTRL _SFR_MEM8(0x0044)
#define SLEEP_CTRL _SFR_MEM8(0x0048)
#define OSC_CTRL _SFR_MEM8(0x0050)
#define OSC_STATUS _SFR_MEM8(0x0051)
#define OSC_XOSCCTRL _SFR_MEM8(0x0052)
#define OSC_XOSCFAIL _SFR_MEM8(0x0053)
#define OSC_RC32KCAL _SFR_MEM8(0x0054)
#define OSC_PLLCTRL _SFR_MEM8(0x0055)
#define OSC_DFLLCTRL _SFR_MEM8(0x0056)
#define DFLLRC32M_CTRL _SFR_MEM8(0x0060)
#define DFLLRC32M_CALA _SFR_MEM8(0x0062)
#define DFLLRC32M_CALB _SFR_MEM8(0x0063)
#define DFLLRC32M_COMP0 _SFR_MEM8(0x0064)
#define DFLLRC32M_COMP1 _SFR_MEM8(0x0065)
#define DFLLRC32M_COMP2 _SFR_MEM8(0x0066)
#define DFLLRC2M_CTRL _SFR_MEM8(0x0068)
#define DFLLRC2M_CALA _SFR_MEM8(0x006A)
#define DFLLRC2M_CALB _SFR_MEM8(0x006B)
#define DFLLRC2M_COMP0 _SFR_MEM8(0x006C)
#define DFLLRC2M_COMP1 _SFR_MEM8(0x006D)
#define DFLLRC2M_COMP2 _SFR_MEM8(0x006E)
#define PR_PRGEN _SFR_MEM8(0x0070)
#define PR_PRPA _SFR_MEM8(0x0071)
#define PR_PRPB _SFR_MEM8(0x0072)
#define PR_PRPC _SFR_MEM8(0x0073)
#define PR_PRPE _SFR_MEM8(0x0075)
#define RST_STATUS _SFR_MEM8(0x0078)
#define RST_CTRL _SFR_MEM8(0x0079)
#define WDT_CTRL _SFR_MEM8(0x0080)
#define WDT_WINCTRL _SFR_MEM8(0x0081)
#define WDT_STATUS _SFR_MEM8(0x0082)
#define MCU_DEVID0 _SFR_MEM8(0x0090)
#define MCU_DEVID1 _SFR_MEM8(0x0091)
#define MCU_DEVID2 _SFR_MEM8(0x0092)
#define MCU_REVID _SFR_MEM8(0x0093)
#define MCU_JTAGUID _SFR_MEM8(0x0094)
#define MCU_MCUCR _SFR_MEM8(0x0096)
#define MCU_ANAINIT _SFR_MEM8(0x0097)
#define MCU_EVSYSLOCK _SFR_MEM8(0x0098)
#define MCU_AWEXLOCK _SFR_MEM8(0x0099)
#define PMIC_STATUS _SFR_MEM8(0x00A0)
#define PMIC_INTPRI _SFR_MEM8(0x00A1)
#define PMIC_CTRL _SFR_MEM8(0x00A2)
#define PORTCFG_MPCMASK _SFR_MEM8(0x00B0)
#define PORTCFG_VPCTRLA _SFR_MEM8(0x00B2)
#define PORTCFG_VPCTRLB _SFR_MEM8(0x00B3)
#define PORTCFG_CLKEVOUT _SFR_MEM8(0x00B4)
#define PORTCFG_EVOUTSEL _SFR_MEM8(0x00B6)
#define AES_CTRL _SFR_MEM8(0x00C0)
#define AES_STATUS _SFR_MEM8(0x00C1)
#define AES_STATE _SFR_MEM8(0x00C2)
#define AES_KEY _SFR_MEM8(0x00C3)
#define AES_INTCTRL _SFR_MEM8(0x00C4)
#define CRC_CTRL _SFR_MEM8(0x00D0)
#define CRC_STATUS _SFR_MEM8(0x00D1)
#define CRC_DATAIN _SFR_MEM8(0x00D3)
#define CRC_CHECKSUM0 _SFR_MEM8(0x00D4)
#define CRC_CHECKSUM1 _SFR_MEM8(0x00D5)
#define CRC_CHECKSUM2 _SFR_MEM8(0x00D6)
#define CRC_CHECKSUM3 _SFR_MEM8(0x00D7)
#define DMA_CTRL _SFR_MEM8(0x0100)
#define DMA_INTFLAGS _SFR_MEM8(0x0103)
#define DMA_STATUS _SFR_MEM8(0x0104)
#define DMA_TEMP _SFR_MEM16(0x0106)
#define DMA_TEMPL _SFR_MEM8(0x0106)
#define DMA_TEMPH _SFR_MEM8(0x0107)
#define DMA_CH0_CTRLA _SFR_MEM8(0x0110)
#define DMA_CH0_CTRLB _SFR_MEM8(0x0111)
#define DMA_CH0_ADDRCTRL _SFR_MEM8(0x0112)
#define DMA_CH0_TRIGSRC _SFR_MEM8(0x0113)
#define DMA_CH0_TRFCNT _SFR_MEM16(0x0114)
#define DMA_CH0_REPCNT _SFR_MEM8(0x0116)
#define DMA_CH0_SRCADDR0 _SFR_MEM8(0x0118)
#define DMA_CH0_SRCADDR1 _SFR_MEM8(0x0119)
#define DMA_CH0_DESTADDR0 _SFR_MEM8(0x011C)
#define DMA_CH0_DESTADDR1 _SFR_MEM8(0x011D)
#define DMA_CH1_CTRLA _SFR_MEM8(0x0120)
#define DMA_CH1_CTRLB _SFR_MEM8(0x0121)
#define DMA_CH1_ADDRCTRL _SFR_MEM8(0x0122)
#define DMA_CH1_TRIGSRC _SFR_MEM8(0x0123)
#define DMA_CH1_TRFCNT _SFR_MEM16(0x0124)
#define DMA_CH1_REPCNT _SFR_MEM8(0x0126)
#define DMA_CH1_SRCADDR0 _SFR_MEM8(0x0128)
#define DMA_CH1_SRCADDR1 _SFR_MEM8(0x0129)
#define DMA_CH1_DESTADDR0 _SFR_MEM8(0x012C)
#define DMA_CH1_DESTADDR1 _SFR_MEM8(0x012D)
#define EVSYS_CH0MUX _SFR_MEM8(0x0180)
#define EVSYS_CH1MUX _SFR_MEM8(0x0181)
#define EVSYS_CH2MUX _SFR_MEM8(0x0182)
#define EVSYS_CH3MUX _SFR_MEM8(0x0183)
#define EVSYS_CH0CTRL _SFR_MEM8(0x0188)
#define EVSYS_CH1CTRL _SFR_MEM8(0x0189)
#define EVSYS_CH2CTRL _SFR_MEM8(0x018A)
#define EVSYS_CH3CTRL _SFR_MEM8(0x018B)
#define EVSYS_STROBE _SFR_MEM8(0x0190)
#define EVSYS_DATA _SFR_MEM8(0x0191)
#define NVM_ADDR0 _SFR_MEM8(0x01C0)
#define NVM_ADDR1 _SFR_MEM8(0x01C1)
#define NVM_ADDR2 _SFR_MEM8(0x01C2)
#define NVM_DATA0 _SFR_MEM8(0x01C4)
#define NVM_DATA1 _SFR_MEM8(0x01C5)
#define NVM_DATA2 _SFR_MEM8(0x01C6)
#define NVM_CMD _SFR_MEM8(0x01CA)
#define NVM_CTRLA _SFR_MEM8(0x01CB)
#define NVM_CTRLB _SFR_MEM8(0x01CC)
#define NVM_INTCTRL _SFR_MEM8(0x01CD)
#define NVM_STATUS _SFR_MEM8(0x01CF)
#define NVM_LOCKBITS _SFR_MEM8(0x01D0)
#define ADCB_CTRLA _SFR_MEM8(0x0240)
#define ADCB_CTRLB _SFR_MEM8(0x0241)
#define ADCB_REFCTRL _SFR_MEM8(0x0242)
#define ADCB_EVCTRL _SFR_MEM8(0x0243)
#define ADCB_PRESCALER _SFR_MEM8(0x0244)
#define ADCB_INTFLAGS _SFR_MEM8(0x0246)
#define ADCB_TEMP _SFR_MEM8(0x0247)
#define ADCB_SAMPCTRL _SFR_MEM8(0x0248)
#define ADCB_CAL _SFR_MEM16(0x024C)
#define ADCB_CALL _SFR_MEM8(0x024C)
#define ADCB_CALH _SFR_MEM8(0x024D)
#define ADCB_CH0RES _SFR_MEM16(0x0250)
#define ADCB_CH0RESL _SFR_MEM8(0x0250)
#define ADCB_CH0RESH _SFR_MEM8(0x0251)
#define ADCB_CMP _SFR_MEM16(0x0258)
#define ADCB_CMPL _SFR_MEM8(0x0258)
#define ADCB_CMPH _SFR_MEM8(0x0259)
#define ADCB_CH0_CTRL _SFR_MEM8(0x0260)
#define ADCB_CH0_MUXCTRL _SFR_MEM8(0x0261)
#define ADCB_CH0_INTCTRL _SFR_MEM8(0x0262)
#define ADCB_CH0_INTFLAGS _SFR_MEM8(0x0263)
#define ADCB_CH0_RES _SFR_MEM16(0x0264)
#define ADCB_CH0_SCAN _SFR_MEM8(0x0266)
#define ACB_AC0CTRL _SFR_MEM8(0x0390)
#define ACB_AC1CTRL _SFR_MEM8(0x0391)
#define ACB_AC0MUXCTRL _SFR_MEM8(0x0392)
#define ACB_AC1MUXCTRL _SFR_MEM8(0x0393)
#define ACB_CTRLA _SFR_MEM8(0x0394)
#define ACB_CTRLB _SFR_MEM8(0x0395)
#define ACB_WINCTRL _SFR_MEM8(0x0396)
#define ACB_STATUS _SFR_MEM8(0x0397)
#define ACB_CURRCTRL _SFR_MEM8(0x0398)
#define ACB_CURRCALIB _SFR_MEM8(0x0399)
#define RTC_CTRL _SFR_MEM8(0x0400)
#define RTC_STATUS _SFR_MEM8(0x0401)
#define RTC_INTCTRL _SFR_MEM8(0x0402)
#define RTC_INTFLAGS _SFR_MEM8(0x0403)
#define RTC_TEMP _SFR_MEM8(0x0404)
#define RTC_CNT _SFR_MEM16(0x0408)
#define RTC_CNTL _SFR_MEM8(0x0408)
#define RTC_CNTH _SFR_MEM8(0x0409)
#define RTC_PER _SFR_MEM16(0x040A)
#define RTC_PERL _SFR_MEM8(0x040A)
#define RTC_PERH _SFR_MEM8(0x040B)
#define RTC_COMP _SFR_MEM16(0x040C)
#define RTC_COMPL _SFR_MEM8(0x040C)
#define RTC_COMPH _SFR_MEM8(0x040D)
#define TWIC_CTRL _SFR_MEM8(0x0480)
#define TWIC_MASTER_CTRLA _SFR_MEM8(0x0481)
#define TWIC_MASTER_CTRLB _SFR_MEM8(0x0482)
#define TWIC_MASTER_CTRLC _SFR_MEM8(0x0483)
#define TWIC_MASTER_STATUS _SFR_MEM8(0x0484)
#define TWIC_MASTER_BAUD _SFR_MEM8(0x0485)
#define TWIC_MASTER_ADDR _SFR_MEM8(0x0486)
#define TWIC_MASTER_DATA _SFR_MEM8(0x0487)
#define TWIC_SLAVE_CTRLA _SFR_MEM8(0x0488)
#define TWIC_SLAVE_CTRLB _SFR_MEM8(0x0489)
#define TWIC_SLAVE_STATUS _SFR_MEM8(0x048A)
#define TWIC_SLAVE_ADDR _SFR_MEM8(0x048B)
#define TWIC_SLAVE_DATA _SFR_MEM8(0x048C)
#define TWIC_SLAVE_ADDRMASK _SFR_MEM8(0x048D)
#define USB_CTRLA _SFR_MEM8(0x04C0)
#define USB_CTRLB _SFR_MEM8(0x04C1)
#define USB_STATUS _SFR_MEM8(0x04C2)
#define USB_ADDR _SFR_MEM8(0x04C3)
#define USB_FIFOWP _SFR_MEM8(0x04C4)
#define USB_FIFORP _SFR_MEM8(0x04C5)
#define USB_EPPTR _SFR_MEM16(0x04C6)
#define USB_EPPTRL _SFR_MEM8(0x04C6)
#define USB_EPPTRH _SFR_MEM8(0x04C7)
#define USB_INTCTRLA _SFR_MEM8(0x04C8)
#define USB_INTCTRLB _SFR_MEM8(0x04C9)
#define USB_INTFLAGSACLR _SFR_MEM8(0x04CA)
#define USB_INTFLAGSASET _SFR_MEM8(0x04CB)
#define USB_INTFLAGSBCLR _SFR_MEM8(0x04CC)
#define USB_INTFLAGSBSET _SFR_MEM8(0x04CD)
#define USB_CAL0 _SFR_MEM8(0x04FA)
#define USB_CAL1 _SFR_MEM8(0x04FB)
#define PORTB_DIR _SFR_MEM8(0x0620)
#define PORTB_DIRSET _SFR_MEM8(0x0621)
#define PORTB_DIRCLR _SFR_MEM8(0x0622)
#define PORTB_DIRTGL _SFR_MEM8(0x0623)
#define PORTB_OUT _SFR_MEM8(0x0624)
#define PORTB_OUTSET _SFR_MEM8(0x0625)
#define PORTB_OUTCLR _SFR_MEM8(0x0626)
#define PORTB_OUTTGL _SFR_MEM8(0x0627)
#define PORTB_IN _SFR_MEM8(0x0628)
#define PORTB_INTCTRL _SFR_MEM8(0x0629)
#define PORTB_INT0MASK _SFR_MEM8(0x062A)
#define PORTB_INT1MASK _SFR_MEM8(0x062B)
#define PORTB_INTFLAGS _SFR_MEM8(0x062C)
#define PORTB_REMAP _SFR_MEM8(0x062E)
#define PORTB_PIN0CTRL _SFR_MEM8(0x0630)
#define PORTB_PIN1CTRL _SFR_MEM8(0x0631)
#define PORTB_PIN2CTRL _SFR_MEM8(0x0632)
#define PORTB_PIN3CTRL _SFR_MEM8(0x0633)
#define PORTB_PIN4CTRL _SFR_MEM8(0x0634)
#define PORTB_PIN5CTRL _SFR_MEM8(0x0635)
#define PORTB_PIN6CTRL _SFR_MEM8(0x0636)
#define PORTB_PIN7CTRL _SFR_MEM8(0x0637)
#define PORTC_DIR _SFR_MEM8(0x0640)
#define PORTC_DIRSET _SFR_MEM8(0x0641)
#define PORTC_DIRCLR _SFR_MEM8(0x0642)
#define PORTC_DIRTGL _SFR_MEM8(0x0643)
#define PORTC_OUT _SFR_MEM8(0x0644)
#define PORTC_OUTSET _SFR_MEM8(0x0645)
#define PORTC_OUTCLR _SFR_MEM8(0x0646)
#define PORTC_OUTTGL _SFR_MEM8(0x0647)
#define PORTC_IN _SFR_MEM8(0x0648)
#define PORTC_INTCTRL _SFR_MEM8(0x0649)
#define PORTC_INT0MASK _SFR_MEM8(0x064A)
#define PORTC_INT1MASK _SFR_MEM8(0x064B)
#define PORTC_INTFLAGS _SFR_MEM8(0x064C)
#define PORTC_REMAP _SFR_MEM8(0x064E)
#define PORTC_PIN0CTRL _SFR_MEM8(0x0650)
#define PORTC_PIN1CTRL _SFR_MEM8(0x0651)
#define PORTC_PIN2CTRL _SFR_MEM8(0x0652)
#define PORTC_PIN3CTRL _SFR_MEM8(0x0653)
#define PORTC_PIN4CTRL _SFR_MEM8(0x0654)
#define PORTC_PIN5CTRL _SFR_MEM8(0x0655)
#define PORTC_PIN6CTRL _SFR_MEM8(0x0656)
#define PORTC_PIN7CTRL _SFR_MEM8(0x0657)
#define PORTD_DIR _SFR_MEM8(0x0660)
#define PORTD_DIRSET _SFR_MEM8(0x0661)
#define PORTD_DIRCLR _SFR_MEM8(0x0662)
#define PORTD_DIRTGL _SFR_MEM8(0x0663)
#define PORTD_OUT _SFR_MEM8(0x0664)
#define PORTD_OUTSET _SFR_MEM8(0x0665)
#define PORTD_OUTCLR _SFR_MEM8(0x0666)
#define PORTD_OUTTGL _SFR_MEM8(0x0667)
#define PORTD_IN _SFR_MEM8(0x0668)
#define PORTD_INTCTRL _SFR_MEM8(0x0669)
#define PORTD_INT0MASK _SFR_MEM8(0x066A)
#define PORTD_INT1MASK _SFR_MEM8(0x066B)
#define PORTD_INTFLAGS _SFR_MEM8(0x066C)
#define PORTD_REMAP _SFR_MEM8(0x066E)
#define PORTD_PIN0CTRL _SFR_MEM8(0x0670)
#define PORTD_PIN1CTRL _SFR_MEM8(0x0671)
#define PORTD_PIN2CTRL _SFR_MEM8(0x0672)
#define PORTD_PIN3CTRL _SFR_MEM8(0x0673)
#define PORTD_PIN4CTRL _SFR_MEM8(0x0674)
#define PORTD_PIN5CTRL _SFR_MEM8(0x0675)
#define PORTD_PIN6CTRL _SFR_MEM8(0x0676)
#define PORTD_PIN7CTRL _SFR_MEM8(0x0677)
#define PORTG_DIR _SFR_MEM8(0x06C0)
#define PORTG_DIRSET _SFR_MEM8(0x06C1)
#define PORTG_DIRCLR _SFR_MEM8(0x06C2)
#define PORTG_DIRTGL _SFR_MEM8(0x06C3)
#define PORTG_OUT _SFR_MEM8(0x06C4)
#define PORTG_OUTSET _SFR_MEM8(0x06C5)
#define PORTG_OUTCLR _SFR_MEM8(0x06C6)
#define PORTG_OUTTGL _SFR_MEM8(0x06C7)
#define PORTG_IN _SFR_MEM8(0x06C8)
#define PORTG_INTCTRL _SFR_MEM8(0x06C9)
#define PORTG_INT0MASK _SFR_MEM8(0x06CA)
#define PORTG_INT1MASK _SFR_MEM8(0x06CB)
#define PORTG_INTFLAGS _SFR_MEM8(0x06CC)
#define PORTG_REMAP _SFR_MEM8(0x06CE)
#define PORTG_PIN0CTRL _SFR_MEM8(0x06D0)
#define PORTG_PIN1CTRL _SFR_MEM8(0x06D1)
#define PORTG_PIN2CTRL _SFR_MEM8(0x06D2)
#define PORTG_PIN3CTRL _SFR_MEM8(0x06D3)
#define PORTG_PIN4CTRL _SFR_MEM8(0x06D4)
#define PORTG_PIN5CTRL _SFR_MEM8(0x06D5)
#define PORTG_PIN6CTRL _SFR_MEM8(0x06D6)
#define PORTG_PIN7CTRL _SFR_MEM8(0x06D7)
#define PORTM_DIR _SFR_MEM8(0x0760)
#define PORTM_DIRSET _SFR_MEM8(0x0761)
#define PORTM_DIRCLR _SFR_MEM8(0x0762)
#define PORTM_DIRTGL _SFR_MEM8(0x0763)
#define PORTM_OUT _SFR_MEM8(0x0764)
#define PORTM_OUTSET _SFR_MEM8(0x0765)
#define PORTM_OUTCLR _SFR_MEM8(0x0766)
#define PORTM_OUTTGL _SFR_MEM8(0x0767)
#define PORTM_IN _SFR_MEM8(0x0768)
#define PORTM_INTCTRL _SFR_MEM8(0x0769)
#define PORTM_INT0MASK _SFR_MEM8(0x076A)
#define PORTM_INT1MASK _SFR_MEM8(0x076B)
#define PORTM_INTFLAGS _SFR_MEM8(0x076C)
#define PORTM_REMAP _SFR_MEM8(0x076E)
#define PORTM_PIN0CTRL _SFR_MEM8(0x0770)
#define PORTM_PIN1CTRL _SFR_MEM8(0x0771)
#define PORTM_PIN2CTRL _SFR_MEM8(0x0772)
#define PORTM_PIN3CTRL _SFR_MEM8(0x0773)
#define PORTM_PIN4CTRL _SFR_MEM8(0x0774)
#define PORTM_PIN5CTRL _SFR_MEM8(0x0775)
#define PORTM_PIN6CTRL _SFR_MEM8(0x0776)
#define PORTM_PIN7CTRL _SFR_MEM8(0x0777)
#define PORTR_DIR _SFR_MEM8(0x07E0)
#define PORTR_DIRSET _SFR_MEM8(0x07E1)
#define PORTR_DIRCLR _SFR_MEM8(0x07E2)
#define PORTR_DIRTGL _SFR_MEM8(0x07E3)
#define PORTR_OUT _SFR_MEM8(0x07E4)
#define PORTR_OUTSET _SFR_MEM8(0x07E5)
#define PORTR_OUTCLR _SFR_MEM8(0x07E6)
#define PORTR_OUTTGL _SFR_MEM8(0x07E7)
#define PORTR_IN _SFR_MEM8(0x07E8)
#define PORTR_INTCTRL _SFR_MEM8(0x07E9)
#define PORTR_INT0MASK _SFR_MEM8(0x07EA)
#define PORTR_INT1MASK _SFR_MEM8(0x07EB)
#define PORTR_INTFLAGS _SFR_MEM8(0x07EC)
#define PORTR_REMAP _SFR_MEM8(0x07EE)
#define PORTR_PIN0CTRL _SFR_MEM8(0x07F0)
#define PORTR_PIN1CTRL _SFR_MEM8(0x07F1)
#define PORTR_PIN2CTRL _SFR_MEM8(0x07F2)
#define PORTR_PIN3CTRL _SFR_MEM8(0x07F3)
#define PORTR_PIN4CTRL _SFR_MEM8(0x07F4)
#define PORTR_PIN5CTRL _SFR_MEM8(0x07F5)
#define PORTR_PIN6CTRL _SFR_MEM8(0x07F6)
#define PORTR_PIN7CTRL _SFR_MEM8(0x07F7)
#define TCC0_CTRLA _SFR_MEM8(0x0800)
#define TCC0_CTRLB _SFR_MEM8(0x0801)
#define TCC0_CTRLC _SFR_MEM8(0x0802)
#define TCC0_CTRLD _SFR_MEM8(0x0803)
#define TCC0_CTRLE _SFR_MEM8(0x0804)
#define TCC0_INTCTRLA _SFR_MEM8(0x0806)
#define TCC0_INTCTRLB _SFR_MEM8(0x0807)
#define TCC0_CTRLFCLR _SFR_MEM8(0x0808)
#define TCC0_CTRLFSET _SFR_MEM8(0x0809)
#define TCC0_CTRLGCLR _SFR_MEM8(0x080A)
#define TCC0_CTRLGSET _SFR_MEM8(0x080B)
#define TCC0_INTFLAGS _SFR_MEM8(0x080C)
#define TCC0_TEMP _SFR_MEM8(0x080F)
#define TCC0_CNT _SFR_MEM16(0x0820)
#define TCC0_CNTL _SFR_MEM8(0x0820)
#define TCC0_CNTH _SFR_MEM8(0x0821)
#define TCC0_PER _SFR_MEM16(0x0826)
#define TCC0_PERL _SFR_MEM8(0x0826)
#define TCC0_PERH _SFR_MEM8(0x0827)
#define TCC0_CCA _SFR_MEM16(0x0828)
#define TCC0_CCAL _SFR_MEM8(0x0828)
#define TCC0_CCAH _SFR_MEM8(0x0829)
#define TCC0_CCB _SFR_MEM16(0x082A)
#define TCC0_CCBL _SFR_MEM8(0x082A)
#define TCC0_CCBH _SFR_MEM8(0x082B)
#define TCC0_CCC _SFR_MEM16(0x082C)
#define TCC0_CCCL _SFR_MEM8(0x082C)
#define TCC0_CCCH _SFR_MEM8(0x082D)
#define TCC0_CCD _SFR_MEM16(0x082E)
#define TCC0_CCDL _SFR_MEM8(0x082E)
#define TCC0_CCDH _SFR_MEM8(0x082F)
#define TCC0_PERBUF _SFR_MEM16(0x0836)
#define TCC0_PERBUFL _SFR_MEM8(0x0836)
#define TCC0_PERBUFH _SFR_MEM8(0x0837)
#define TCC0_CCABUF _SFR_MEM16(0x0838)
#define TCC0_CCABUFL _SFR_MEM8(0x0838)
#define TCC0_CCABUFH _SFR_MEM8(0x0839)
#define TCC0_CCBBUF _SFR_MEM16(0x083A)
#define TCC0_CCBBUFL _SFR_MEM8(0x083A)
#define TCC0_CCBBUFH _SFR_MEM8(0x083B)
#define TCC0_CCCBUF _SFR_MEM16(0x083C)
#define TCC0_CCCBUFL _SFR_MEM8(0x083C)
#define TCC0_CCCBUFH _SFR_MEM8(0x083D)
#define TCC0_CCDBUF _SFR_MEM16(0x083E)
#define TCC0_CCDBUFL _SFR_MEM8(0x083E)
#define TCC0_CCDBUFH _SFR_MEM8(0x083F)
#define TCC2_CTRLA _SFR_MEM8(0x0800)
#define TCC2_CTRLB _SFR_MEM8(0x0801)
#define TCC2_CTRLC _SFR_MEM8(0x0802)
#define TCC2_CTRLE _SFR_MEM8(0x0804)
#define TCC2_INTCTRLA _SFR_MEM8(0x0806)
#define TCC2_INTCTRLB _SFR_MEM8(0x0807)
#define TCC2_CTRLF _SFR_MEM8(0x0809)
#define TCC2_INTFLAGS _SFR_MEM8(0x080C)
#define TCC2_LCNT _SFR_MEM8(0x0820)
#define TCC2_HCNT _SFR_MEM8(0x0821)
#define TCC2_LPER _SFR_MEM8(0x0826)
#define TCC2_HPER _SFR_MEM8(0x0827)
#define TCC2_LCMPA _SFR_MEM8(0x0828)
#define TCC2_HCMPA _SFR_MEM8(0x0829)
#define TCC2_LCMPB _SFR_MEM8(0x082A)
#define TCC2_HCMPB _SFR_MEM8(0x082B)
#define TCC2_LCMPC _SFR_MEM8(0x082C)
#define TCC2_HCMPC _SFR_MEM8(0x082D)
#define TCC2_LCMPD _SFR_MEM8(0x082E)
#define TCC2_HCMPD _SFR_MEM8(0x082F)
#define TCC1_CTRLA _SFR_MEM8(0x0840)
#define TCC1_CTRLB _SFR_MEM8(0x0841)
#define TCC1_CTRLC _SFR_MEM8(0x0842)
#define TCC1_CTRLD _SFR_MEM8(0x0843)
#define TCC1_CTRLE _SFR_MEM8(0x0844)
#define TCC1_INTCTRLA _SFR_MEM8(0x0846)
#define TCC1_INTCTRLB _SFR_MEM8(0x0847)
#define TCC1_CTRLFCLR _SFR_MEM8(0x0848)
#define TCC1_CTRLFSET _SFR_MEM8(0x0849)
#define TCC1_CTRLGCLR _SFR_MEM8(0x084A)
#define TCC1_CTRLGSET _SFR_MEM8(0x084B)
#define TCC1_INTFLAGS _SFR_MEM8(0x084C)
#define TCC1_TEMP _SFR_MEM8(0x084F)
#define TCC1_CNT _SFR_MEM16(0x0860)
#define TCC1_CNTL _SFR_MEM8(0x0860)
#define TCC1_CNTH _SFR_MEM8(0x0861)
#define TCC1_PER _SFR_MEM16(0x0866)
#define TCC1_PERL _SFR_MEM8(0x0866)
#define TCC1_PERH _SFR_MEM8(0x0867)
#define TCC1_CCA _SFR_MEM16(0x0868)
#define TCC1_CCAL _SFR_MEM8(0x0868)
#define TCC1_CCAH _SFR_MEM8(0x0869)
#define TCC1_CCB _SFR_MEM16(0x086A)
#define TCC1_CCBL _SFR_MEM8(0x086A)
#define TCC1_CCBH _SFR_MEM8(0x086B)
#define TCC1_PERBUF _SFR_MEM16(0x0876)
#define TCC1_PERBUFL _SFR_MEM8(0x0876)
#define TCC1_PERBUFH _SFR_MEM8(0x0877)
#define TCC1_CCABUF _SFR_MEM16(0x0878)
#define TCC1_CCABUFL _SFR_MEM8(0x0878)
#define TCC1_CCABUFH _SFR_MEM8(0x0879)
#define TCC1_CCBBUF _SFR_MEM16(0x087A)
#define TCC1_CCBBUFL _SFR_MEM8(0x087A)
#define TCC1_CCBBUFH _SFR_MEM8(0x087B)
#define AWEXC_CTRL _SFR_MEM8(0x0880)
#define AWEXC_FDEMASK _SFR_MEM8(0x0882)
#define AWEXC_FDCTRL _SFR_MEM8(0x0883)
#define AWEXC_STATUS _SFR_MEM8(0x0884)
#define AWEXC_STATUSSET _SFR_MEM8(0x0885)
#define AWEXC_DTBOTH _SFR_MEM8(0x0886)
#define AWEXC_DTBOTHBUF _SFR_MEM8(0x0887)
#define AWEXC_DTLS _SFR_MEM8(0x0888)
#define AWEXC_DTHS _SFR_MEM8(0x0889)
#define AWEXC_DTLSBUF _SFR_MEM8(0x088A)
#define AWEXC_DTHSBUF _SFR_MEM8(0x088B)
#define AWEXC_OUTOVEN _SFR_MEM8(0x088C)
#define HIRESC_CTRLA _SFR_MEM8(0x0890)
#define USARTC0_DATA _SFR_MEM8(0x08A0)
#define USARTC0_STATUS _SFR_MEM8(0x08A1)
#define USARTC0_CTRLA _SFR_MEM8(0x08A3)
#define USARTC0_CTRLB _SFR_MEM8(0x08A4)
#define USARTC0_CTRLC _SFR_MEM8(0x08A5)
#define USARTC0_BAUDCTRLA _SFR_MEM8(0x08A6)
#define USARTC0_BAUDCTRLB _SFR_MEM8(0x08A7)
#define SPIC_CTRL _SFR_MEM8(0x08C0)
#define SPIC_INTCTRL _SFR_MEM8(0x08C1)
#define SPIC_STATUS _SFR_MEM8(0x08C2)
#define SPIC_DATA _SFR_MEM8(0x08C3)
#define IRCOM_CTRL _SFR_MEM8(0x08F8)
#define IRCOM_TXPLCTRL _SFR_MEM8(0x08F9)
#define IRCOM_RXPLCTRL _SFR_MEM8(0x08FA)
#define LCD_CTRLA _SFR_MEM8(0x0D00)
#define LCD_CTRLB _SFR_MEM8(0x0D01)
#define LCD_CTRLC _SFR_MEM8(0x0D02)
#define LCD_INTCTRL _SFR_MEM8(0x0D03)
#define LCD_INTFLAG _SFR_MEM8(0x0D04)
#define LCD_CTRLD _SFR_MEM8(0x0D05)
#define LCD_CTRLE _SFR_MEM8(0x0D06)
#define LCD_CTRLF _SFR_MEM8(0x0D07)
#define LCD_CTRLG _SFR_MEM8(0x0D08)
#define LCD_CTRLH _SFR_MEM8(0x0D09)
#define LCD_DATA0 _SFR_MEM8(0x0D10)
#define LCD_DATA1 _SFR_MEM8(0x0D11)
#define LCD_DATA2 _SFR_MEM8(0x0D12)
#define LCD_DATA3 _SFR_MEM8(0x0D13)
#define LCD_DATA4 _SFR_MEM8(0x0D14)
#define LCD_DATA5 _SFR_MEM8(0x0D15)
#define LCD_DATA6 _SFR_MEM8(0x0D16)
#define LCD_DATA7 _SFR_MEM8(0x0D17)
#define LCD_DATA8 _SFR_MEM8(0x0D18)
#define LCD_DATA9 _SFR_MEM8(0x0D19)
#define LCD_DATA10 _SFR_MEM8(0x0D1A)
#define LCD_DATA11 _SFR_MEM8(0x0D1B)
#define LCD_DATA12 _SFR_MEM8(0x0D1C)
#define LCD_DATA13 _SFR_MEM8(0x0D1D)
#define LCD_DATA14 _SFR_MEM8(0x0D1E)
#define LCD_DATA15 _SFR_MEM8(0x0D1F)
#define LCD_DATA16 _SFR_MEM8(0x0D20)
#define LCD_DATA17 _SFR_MEM8(0x0D21)
#define LCD_DATA18 _SFR_MEM8(0x0D22)
#define LCD_DATA19 _SFR_MEM8(0x0D23)
#define AC_ENABLE_bm 0x01
#define AC_ENABLE_bp 0
#define AC_HYSMODE_gm 0x06
#define AC_HYSMODE_gp 1
#define AC_HYSMODE0_bm (1<<1)
#define AC_HYSMODE0_bp 1
#define AC_HYSMODE1_bm (1<<2)
#define AC_HYSMODE1_bp 2
#define AC_INTLVL_gm 0x30
#define AC_INTLVL_gp 4
#define AC_INTLVL0_bm (1<<4)
#define AC_INTLVL0_bp 4
#define AC_INTLVL1_bm (1<<5)
#define AC_INTLVL1_bp 5
#define AC_INTMODE_gm 0xC0
#define AC_INTMODE_gp 6
#define AC_INTMODE0_bm (1<<6)
#define AC_INTMODE0_bp 6
#define AC_INTMODE1_bm (1<<7)
#define AC_INTMODE1_bp 7
#define AC_MUXNEG_gm 0x07
#define AC_MUXNEG_gp 0
#define AC_MUXNEG0_bm (1<<0)
#define AC_MUXNEG0_bp 0
#define AC_MUXNEG1_bm (1<<1)
#define AC_MUXNEG1_bp 1
#define AC_MUXNEG2_bm (1<<2)
#define AC_MUXNEG2_bp 2
#define AC_MUXPOS_gm 0x38
#define AC_MUXPOS_gp 3
#define AC_MUXPOS0_bm (1<<3)
#define AC_MUXPOS0_bp 3
#define AC_MUXPOS1_bm (1<<4)
#define AC_MUXPOS1_bp 4
#define AC_MUXPOS2_bm (1<<5)
#define AC_MUXPOS2_bp 5
#define AC_AC0OUT_bm 0x01
#define AC_AC0OUT_bp 0
#define AC_AC1OUT_bm 0x02
#define AC_AC1OUT_bp 1
#define AC_SCALEFAC_gm 0x3F
#define AC_SCALEFAC_gp 0
#define AC_SCALEFAC0_bm (1<<0)
#define AC_SCALEFAC0_bp 0
#define AC_SCALEFAC1_bm (1<<1)
#define AC_SCALEFAC1_bp 1
#define AC_SCALEFAC2_bm (1<<2)
#define AC_SCALEFAC2_bp 2
#define AC_SCALEFAC3_bm (1<<3)
#define AC_SCALEFAC3_bp 3
#define AC_SCALEFAC4_bm (1<<4)
#define AC_SCALEFAC4_bp 4
#define AC_SCALEFAC5_bm (1<<5)
#define AC_SCALEFAC5_bp 5
#define AC_WINTLVL_gm 0x03
#define AC_WINTLVL_gp 0
#define AC_WINTLVL0_bm (1<<0)
#define AC_WINTLVL0_bp 0
#define AC_WINTLVL1_bm (1<<1)
#define AC_WINTLVL1_bp 1
#define AC_WINTMODE_gm 0x0C
#define AC_WINTMODE_gp 2
#define AC_WINTMODE0_bm (1<<2)
#define AC_WINTMODE0_bp 2
#define AC_WINTMODE1_bm (1<<3)
#define AC_WINTMODE1_bp 3
#define AC_WEN_bm 0x10
#define AC_WEN_bp 4
#define AC_AC0IF_bm 0x01
#define AC_AC0IF_bp 0
#define AC_AC1IF_bm 0x02
#define AC_AC1IF_bp 1
#define AC_WIF_bm 0x04
#define AC_WIF_bp 2
#define AC_AC0STATE_bm 0x10
#define AC_AC0STATE_bp 4
#define AC_AC1STATE_bm 0x20
#define AC_AC1STATE_bp 5
#define AC_WSTATE_gm 0xC0
#define AC_WSTATE_gp 6
#define AC_WSTATE0_bm (1<<6)
#define AC_WSTATE0_bp 6
#define AC_WSTATE1_bm (1<<7)
#define AC_WSTATE1_bp 7
#define AC_AC0CURR_bm 0x01
#define AC_AC0CURR_bp 0
#define AC_AC1CURR_bm 0x02
#define AC_AC1CURR_bp 1
#define AC_CURRMODE_bm 0x40
#define AC_CURRMODE_bp 6
#define AC_CURREN_bm 0x80
#define AC_CURREN_bp 7
#define AC_CALIB_gm 0x0F
#define AC_CALIB_gp 0
#define AC_CALIB0_bm (1<<0)
#define AC_CALIB0_bp 0
#define AC_CALIB1_bm (1<<1)
#define AC_CALIB1_bp 1
#define AC_CALIB2_bm (1<<2)
#define AC_CALIB2_bp 2
#define AC_CALIB3_bm (1<<3)
#define AC_CALIB3_bp 3
#define ADC_CH_INPUTMODE_gm 0x03
#define ADC_CH_INPUTMODE_gp 0
#define ADC_CH_INPUTMODE0_bm (1<<0)
#define ADC_CH_INPUTMODE0_bp 0
#define ADC_CH_INPUTMODE1_bm (1<<1)
#define ADC_CH_INPUTMODE1_bp 1
#define ADC_CH_GAIN_gm 0x1C
#define ADC_CH_GAIN_gp 2
#define ADC_CH_GAIN0_bm (1<<2)
#define ADC_CH_GAIN0_bp 2
#define ADC_CH_GAIN1_bm (1<<3)
#define ADC_CH_GAIN1_bp 3
#define ADC_CH_GAIN2_bm (1<<4)
#define ADC_CH_GAIN2_bp 4
#define ADC_CH_START_bm 0x80
#define ADC_CH_START_bp 7
#define ADC_CH_MUXNEG_gm 0x07
#define ADC_CH_MUXNEG_gp 0
#define ADC_CH_MUXNEG0_bm (1<<0)
#define ADC_CH_MUXNEG0_bp 0
#define ADC_CH_MUXNEG1_bm (1<<1)
#define ADC_CH_MUXNEG1_bp 1
#define ADC_CH_MUXNEG2_bm (1<<2)
#define ADC_CH_MUXNEG2_bp 2
#define ADC_CH_MUXNEGL_gm 0x07
#define ADC_CH_MUXNEGL_gp 0
#define ADC_CH_MUXNEGL0_bm (1<<0)
#define ADC_CH_MUXNEGL0_bp 0
#define ADC_CH_MUXNEGL1_bm (1<<1)
#define ADC_CH_MUXNEGL1_bp 1
#define ADC_CH_MUXNEGL2_bm (1<<2)
#define ADC_CH_MUXNEGL2_bp 2
#define ADC_CH_MUXNEGH_gm 0x07
#define ADC_CH_MUXNEGH_gp 0
#define ADC_CH_MUXNEGH0_bm (1<<0)
#define ADC_CH_MUXNEGH0_bp 0
#define ADC_CH_MUXNEGH1_bm (1<<1)
#define ADC_CH_MUXNEGH1_bp 1
#define ADC_CH_MUXNEGH2_bm (1<<2)
#define ADC_CH_MUXNEGH2_bp 2
#define ADC_CH_MUXPOS_gm 0x78
#define ADC_CH_MUXPOS_gp 3
#define ADC_CH_MUXPOS0_bm (1<<3)
#define ADC_CH_MUXPOS0_bp 3
#define ADC_CH_MUXPOS1_bm (1<<4)
#define ADC_CH_MUXPOS1_bp 4
#define ADC_CH_MUXPOS2_bm (1<<5)
#define ADC_CH_MUXPOS2_bp 5
#define ADC_CH_MUXPOS3_bm (1<<6)
#define ADC_CH_MUXPOS3_bp 6
#define ADC_CH_MUXINT_gm 0x78
#define ADC_CH_MUXINT_gp 3
#define ADC_CH_MUXINT0_bm (1<<3)
#define ADC_CH_MUXINT0_bp 3
#define ADC_CH_MUXINT1_bm (1<<4)
#define ADC_CH_MUXINT1_bp 4
#define ADC_CH_MUXINT2_bm (1<<5)
#define ADC_CH_MUXINT2_bp 5
#define ADC_CH_MUXINT3_bm (1<<6)
#define ADC_CH_MUXINT3_bp 6
#define ADC_CH_INTLVL_gm 0x03
#define ADC_CH_INTLVL_gp 0
#define ADC_CH_INTLVL0_bm (1<<0)
#define ADC_CH_INTLVL0_bp 0
#define ADC_CH_INTLVL1_bm (1<<1)
#define ADC_CH_INTLVL1_bp 1
#define ADC_CH_INTMODE_gm 0x0C
#define ADC_CH_INTMODE_gp 2
#define ADC_CH_INTMODE0_bm (1<<2)
#define ADC_CH_INTMODE0_bp 2
#define ADC_CH_INTMODE1_bm (1<<3)
#define ADC_CH_INTMODE1_bp 3
#define ADC_CH_CHIF_bm 0x01
#define ADC_CH_CHIF_bp 0
#define ADC_CH_COUNT_gm 0x0F
#define ADC_CH_COUNT_gp 0
#define ADC_CH_COUNT0_bm (1<<0)
#define ADC_CH_COUNT0_bp 0
#define ADC_CH_COUNT1_bm (1<<1)
#define ADC_CH_COUNT1_bp 1
#define ADC_CH_COUNT2_bm (1<<2)
#define ADC_CH_COUNT2_bp 2
#define ADC_CH_COUNT3_bm (1<<3)
#define ADC_CH_COUNT3_bp 3
#define ADC_CH_OFFSET_gm 0xF0
#define ADC_CH_OFFSET_gp 4
#define ADC_CH_OFFSET0_bm (1<<4)
#define ADC_CH_OFFSET0_bp 4
#define ADC_CH_OFFSET1_bm (1<<5)
#define ADC_CH_OFFSET1_bp 5
#define ADC_CH_OFFSET2_bm (1<<6)
#define ADC_CH_OFFSET2_bp 6
#define ADC_CH_OFFSET3_bm (1<<7)
#define ADC_CH_OFFSET3_bp 7
#define ADC_ENABLE_bm 0x01
#define ADC_ENABLE_bp 0
#define ADC_FLUSH_bm 0x02
#define ADC_FLUSH_bp 1
#define ADC_CH0START_bm 0x04
#define ADC_CH0START_bp 2
#define ADC_RESOLUTION_gm 0x06
#define ADC_RESOLUTION_gp 1
#define ADC_RESOLUTION0_bm (1<<1)
#define ADC_RESOLUTION0_bp 1
#define ADC_RESOLUTION1_bm (1<<2)
#define ADC_RESOLUTION1_bp 2
#define ADC_FREERUN_bm 0x08
#define ADC_FREERUN_bp 3
#define ADC_CONMODE_bm 0x10
#define ADC_CONMODE_bp 4
#define ADC_CURRLIMIT_gm 0x60
#define ADC_CURRLIMIT_gp 5
#define ADC_CURRLIMIT0_bm (1<<5)
#define ADC_CURRLIMIT0_bp 5
#define ADC_CURRLIMIT1_bm (1<<6)
#define ADC_CURRLIMIT1_bp 6
#define ADC_TEMPREF_bm 0x01
#define ADC_TEMPREF_bp 0
#define ADC_BANDGAP_bm 0x02
#define ADC_BANDGAP_bp 1
#define ADC_REFSEL_gm 0x70
#define ADC_REFSEL_gp 4
#define ADC_REFSEL0_bm (1<<4)
#define ADC_REFSEL0_bp 4
#define ADC_REFSEL1_bm (1<<5)
#define ADC_REFSEL1_bp 5
#define ADC_REFSEL2_bm (1<<6)
#define ADC_REFSEL2_bp 6
#define ADC_EVACT_gm 0x07
#define ADC_EVACT_gp 0
#define ADC_EVACT0_bm (1<<0)
#define ADC_EVACT0_bp 0
#define ADC_EVACT1_bm (1<<1)
#define ADC_EVACT1_bp 1
#define ADC_EVACT2_bm (1<<2)
#define ADC_EVACT2_bp 2
#define ADC_EVSEL_gm 0x18
#define ADC_EVSEL_gp 3
#define ADC_EVSEL0_bm (1<<3)
#define ADC_EVSEL0_bp 3
#define ADC_EVSEL1_bm (1<<4)
#define ADC_EVSEL1_bp 4
#define ADC_PRESCALER_gm 0x07
#define ADC_PRESCALER_gp 0
#define ADC_PRESCALER0_bm (1<<0)
#define ADC_PRESCALER0_bp 0
#define ADC_PRESCALER1_bm (1<<1)
#define ADC_PRESCALER1_bp 1
#define ADC_PRESCALER2_bm (1<<2)
#define ADC_PRESCALER2_bp 2
#define ADC_CH0IF_bm 0x01
#define ADC_CH0IF_bp 0
#define ADC_SAMPVAL_gm 0x3F
#define ADC_SAMPVAL_gp 0
#define ADC_SAMPVAL0_bm (1<<0)
#define ADC_SAMPVAL0_bp 0
#define ADC_SAMPVAL1_bm (1<<1)
#define ADC_SAMPVAL1_bp 1
#define ADC_SAMPVAL2_bm (1<<2)
#define ADC_SAMPVAL2_bp 2
#define ADC_SAMPVAL3_bm (1<<3)
#define ADC_SAMPVAL3_bp 3
#define ADC_SAMPVAL4_bm (1<<4)
#define ADC_SAMPVAL4_bp 4
#define ADC_SAMPVAL5_bm (1<<5)
#define ADC_SAMPVAL5_bp 5
#define AES_XOR_bm 0x04
#define AES_XOR_bp 2
#define AES_DECRYPT_bm 0x10
#define AES_DECRYPT_bp 4
#define AES_RESET_bm 0x20
#define AES_RESET_bp 5
#define AES_AUTO_bm 0x40
#define AES_AUTO_bp 6
#define AES_START_bm 0x80
#define AES_START_bp 7
#define AES_SRIF_bm 0x01
#define AES_SRIF_bp 0
#define AES_ERROR_bm 0x80
#define AES_ERROR_bp 7
#define AES_INTLVL_gm 0x03
#define AES_INTLVL_gp 0
#define AES_INTLVL0_bm (1<<0)
#define AES_INTLVL0_bp 0
#define AES_INTLVL1_bm (1<<1)
#define AES_INTLVL1_bp 1
#define AWEX_DTICCAEN_bm 0x01
#define AWEX_DTICCAEN_bp 0
#define AWEX_DTICCBEN_bm 0x02
#define AWEX_DTICCBEN_bp 1
#define AWEX_DTICCCEN_bm 0x04
#define AWEX_DTICCCEN_bp 2
#define AWEX_DTICCDEN_bm 0x08
#define AWEX_DTICCDEN_bp 3
#define AWEX_CWCM_bm 0x10
#define AWEX_CWCM_bp 4
#define AWEX_PGM_bm 0x20
#define AWEX_PGM_bp 5
#define AWEX_FDACT_gm 0x03
#define AWEX_FDACT_gp 0
#define AWEX_FDACT0_bm (1<<0)
#define AWEX_FDACT0_bp 0
#define AWEX_FDACT1_bm (1<<1)
#define AWEX_FDACT1_bp 1
#define AWEX_FDMODE_bm 0x04
#define AWEX_FDMODE_bp 2
#define AWEX_FDDBD_bm 0x10
#define AWEX_FDDBD_bp 4
#define AWEX_DTLSBUFV_bm 0x01
#define AWEX_DTLSBUFV_bp 0
#define AWEX_DTHSBUFV_bm 0x02
#define AWEX_DTHSBUFV_bp 1
#define AWEX_FDF_bm 0x04
#define AWEX_FDF_bp 2
#define CLK_SCLKSEL_gm 0x07
#define CLK_SCLKSEL_gp 0
#define CLK_SCLKSEL0_bm (1<<0)
#define CLK_SCLKSEL0_bp 0
#define CLK_SCLKSEL1_bm (1<<1)
#define CLK_SCLKSEL1_bp 1
#define CLK_SCLKSEL2_bm (1<<2)
#define CLK_SCLKSEL2_bp 2
#define CLK_PSBCDIV_gm 0x03
#define CLK_PSBCDIV_gp 0
#define CLK_PSBCDIV0_bm (1<<0)
#define CLK_PSBCDIV0_bp 0
#define CLK_PSBCDIV1_bm (1<<1)
#define CLK_PSBCDIV1_bp 1
#define CLK_PSADIV_gm 0x7C
#define CLK_PSADIV_gp 2
#define CLK_PSADIV0_bm (1<<2)
#define CLK_PSADIV0_bp 2
#define CLK_PSADIV1_bm (1<<3)
#define CLK_PSADIV1_bp 3
#define CLK_PSADIV2_bm (1<<4)
#define CLK_PSADIV2_bp 4
#define CLK_PSADIV3_bm (1<<5)
#define CLK_PSADIV3_bp 5
#define CLK_PSADIV4_bm (1<<6)
#define CLK_PSADIV4_bp 6
#define CLK_LOCK_bm 0x01
#define CLK_LOCK_bp 0
#define CLK_RTCEN_bm 0x01
#define CLK_RTCEN_bp 0
#define CLK_RTCSRC_gm 0x0E
#define CLK_RTCSRC_gp 1
#define CLK_RTCSRC0_bm (1<<1)
#define CLK_RTCSRC0_bp 1
#define CLK_RTCSRC1_bm (1<<2)
#define CLK_RTCSRC1_bp 2
#define CLK_RTCSRC2_bm (1<<3)
#define CLK_RTCSRC2_bp 3
#define CLK_USBSEN_bm 0x01
#define CLK_USBSEN_bp 0
#define CLK_USBSRC_gm 0x06
#define CLK_USBSRC_gp 1
#define CLK_USBSRC0_bm (1<<1)
#define CLK_USBSRC0_bp 1
#define CLK_USBSRC1_bm (1<<2)
#define CLK_USBSRC1_bp 2
#define CLK_USBPSDIV_gm 0x38
#define CLK_USBPSDIV_gp 3
#define CLK_USBPSDIV0_bm (1<<3)
#define CLK_USBPSDIV0_bp 3
#define CLK_USBPSDIV1_bm (1<<4)
#define CLK_USBPSDIV1_bp 4
#define CLK_USBPSDIV2_bm (1<<5)
#define CLK_USBPSDIV2_bp 5
#define CPU_CCP_gm 0xFF
#define CPU_CCP_gp 0
#define CPU_CCP0_bm (1<<0)
#define CPU_CCP0_bp 0
#define CPU_CCP1_bm (1<<1)
#define CPU_CCP1_bp 1
#define CPU_CCP2_bm (1<<2)
#define CPU_CCP2_bp 2
#define CPU_CCP3_bm (1<<3)
#define CPU_CCP3_bp 3
#define CPU_CCP4_bm (1<<4)
#define CPU_CCP4_bp 4
#define CPU_CCP5_bm (1<<5)
#define CPU_CCP5_bp 5
#define CPU_CCP6_bm (1<<6)
#define CPU_CCP6_bp 6
#define CPU_CCP7_bm (1<<7)
#define CPU_CCP7_bp 7
#define CPU_C_bm 0x01
#define CPU_C_bp 0
#define CPU_Z_bm 0x02
#define CPU_Z_bp 1
#define CPU_N_bm 0x04
#define CPU_N_bp 2
#define CPU_V_bm 0x08
#define CPU_V_bp 3
#define CPU_S_bm 0x10
#define CPU_S_bp 4
#define CPU_H_bm 0x20
#define CPU_H_bp 5
#define CPU_T_bm 0x40
#define CPU_T_bp 6
#define CPU_I_bm 0x80
#define CPU_I_bp 7
#define CRC_SOURCE_gm 0x0F
#define CRC_SOURCE_gp 0
#define CRC_SOURCE0_bm (1<<0)
#define CRC_SOURCE0_bp 0
#define CRC_SOURCE1_bm (1<<1)
#define CRC_SOURCE1_bp 1
#define CRC_SOURCE2_bm (1<<2)
#define CRC_SOURCE2_bp 2
#define CRC_SOURCE3_bm (1<<3)
#define CRC_SOURCE3_bp 3
#define CRC_CRC32_bm 0x20
#define CRC_CRC32_bp 5
#define CRC_RESET_gm 0xC0
#define CRC_RESET_gp 6
#define CRC_RESET0_bm (1<<6)
#define CRC_RESET0_bp 6
#define CRC_RESET1_bm (1<<7)
#define CRC_RESET1_bp 7
#define CRC_BUSY_bm 0x01
#define CRC_BUSY_bp 0
#define CRC_ZERO_bm 0x02
#define CRC_ZERO_bp 1
#define DFLL_ENABLE_bm 0x01
#define DFLL_ENABLE_bp 0
#define DFLL_CALL_gm 0x7F
#define DFLL_CALL_gp 0
#define DFLL_CALL0_bm (1<<0)
#define DFLL_CALL0_bp 0
#define DFLL_CALL1_bm (1<<1)
#define DFLL_CALL1_bp 1
#define DFLL_CALL2_bm (1<<2)
#define DFLL_CALL2_bp 2
#define DFLL_CALL3_bm (1<<3)
#define DFLL_CALL3_bp 3
#define DFLL_CALL4_bm (1<<4)
#define DFLL_CALL4_bp 4
#define DFLL_CALL5_bm (1<<5)
#define DFLL_CALL5_bp 5
#define DFLL_CALL6_bm (1<<6)
#define DFLL_CALL6_bp 6
#define DFLL_CALH_gm 0x3F
#define DFLL_CALH_gp 0
#define DFLL_CALH0_bm (1<<0)
#define DFLL_CALH0_bp 0
#define DFLL_CALH1_bm (1<<1)
#define DFLL_CALH1_bp 1
#define DFLL_CALH2_bm (1<<2)
#define DFLL_CALH2_bp 2
#define DFLL_CALH3_bm (1<<3)
#define DFLL_CALH3_bp 3
#define DFLL_CALH4_bm (1<<4)
#define DFLL_CALH4_bp 4
#define DFLL_CALH5_bm (1<<5)
#define DFLL_CALH5_bp 5
#define DMA_CH_BURSTLEN_gm 0x03
#define DMA_CH_BURSTLEN_gp 0
#define DMA_CH_BURSTLEN0_bm (1<<0)
#define DMA_CH_BURSTLEN0_bp 0
#define DMA_CH_BURSTLEN1_bm (1<<1)
#define DMA_CH_BURSTLEN1_bp 1
#define DMA_CH_SINGLE_bm 0x04
#define DMA_CH_SINGLE_bp 2
#define DMA_CH_TRFREQ_bm 0x10
#define DMA_CH_TRFREQ_bp 4
#define DMA_CH_REPEAT_bm 0x20
#define DMA_CH_REPEAT_bp 5
#define DMA_CH_CHRST_bm 0x40
#define DMA_CH_CHRST_bp 6
#define DMA_CH_CHEN_bm 0x80
#define DMA_CH_CHEN_bp 7
#define DMA_CH_TRNINTLVL_gm 0x03
#define DMA_CH_TRNINTLVL_gp 0
#define DMA_CH_TRNINTLVL0_bm (1<<0)
#define DMA_CH_TRNINTLVL0_bp 0
#define DMA_CH_TRNINTLVL1_bm (1<<1)
#define DMA_CH_TRNINTLVL1_bp 1
#define DMA_CH_ERRINTLVL_gm 0x0C
#define DMA_CH_ERRINTLVL_gp 2
#define DMA_CH_ERRINTLVL0_bm (1<<2)
#define DMA_CH_ERRINTLVL0_bp 2
#define DMA_CH_ERRINTLVL1_bm (1<<3)
#define DMA_CH_ERRINTLVL1_bp 3
#define DMA_CH_TRNIF_bm 0x10
#define DMA_CH_TRNIF_bp 4
#define DMA_CH_ERRIF_bm 0x20
#define DMA_CH_ERRIF_bp 5
#define DMA_CH_CHPEND_bm 0x40
#define DMA_CH_CHPEND_bp 6
#define DMA_CH_CHBUSY_bm 0x80
#define DMA_CH_CHBUSY_bp 7
#define DMA_CH_DESTDIR_gm 0x03
#define DMA_CH_DESTDIR_gp 0
#define DMA_CH_DESTDIR0_bm (1<<0)
#define DMA_CH_DESTDIR0_bp 0
#define DMA_CH_DESTDIR1_bm (1<<1)
#define DMA_CH_DESTDIR1_bp 1
#define DMA_CH_DESTRELOAD_gm 0x0C
#define DMA_CH_DESTRELOAD_gp 2
#define DMA_CH_DESTRELOAD0_bm (1<<2)
#define DMA_CH_DESTRELOAD0_bp 2
#define DMA_CH_DESTRELOAD1_bm (1<<3)
#define DMA_CH_DESTRELOAD1_bp 3
#define DMA_CH_SRCDIR_gm 0x30
#define DMA_CH_SRCDIR_gp 4
#define DMA_CH_SRCDIR0_bm (1<<4)
#define DMA_CH_SRCDIR0_bp 4
#define DMA_CH_SRCDIR1_bm (1<<5)
#define DMA_CH_SRCDIR1_bp 5
#define DMA_CH_SRCRELOAD_gm 0xC0
#define DMA_CH_SRCRELOAD_gp 6
#define DMA_CH_SRCRELOAD0_bm (1<<6)
#define DMA_CH_SRCRELOAD0_bp 6
#define DMA_CH_SRCRELOAD1_bm (1<<7)
#define DMA_CH_SRCRELOAD1_bp 7
#define DMA_CH_TRIGSRC_gm 0xFF
#define DMA_CH_TRIGSRC_gp 0
#define DMA_CH_TRIGSRC0_bm (1<<0)
#define DMA_CH_TRIGSRC0_bp 0
#define DMA_CH_TRIGSRC1_bm (1<<1)
#define DMA_CH_TRIGSRC1_bp 1
#define DMA_CH_TRIGSRC2_bm (1<<2)
#define DMA_CH_TRIGSRC2_bp 2
#define DMA_CH_TRIGSRC3_bm (1<<3)
#define DMA_CH_TRIGSRC3_bp 3
#define DMA_CH_TRIGSRC4_bm (1<<4)
#define DMA_CH_TRIGSRC4_bp 4
#define DMA_CH_TRIGSRC5_bm (1<<5)
#define DMA_CH_TRIGSRC5_bp 5
#define DMA_CH_TRIGSRC6_bm (1<<6)
#define DMA_CH_TRIGSRC6_bp 6
#define DMA_CH_TRIGSRC7_bm (1<<7)
#define DMA_CH_TRIGSRC7_bp 7
#define DMA_PRIMODE_bm 0x01
#define DMA_PRIMODE_bp 0
#define DMA_DBUFMODE_bm 0x04
#define DMA_DBUFMODE_bp 2
#define DMA_RESET_bm 0x40
#define DMA_RESET_bp 6
#define DMA_ENABLE_bm 0x80
#define DMA_ENABLE_bp 7
#define DMA_CH0TRNIF_bm 0x01
#define DMA_CH0TRNIF_bp 0
#define DMA_CH1TRNIF_bm 0x02
#define DMA_CH1TRNIF_bp 1
#define DMA_CH0ERRIF_bm 0x10
#define DMA_CH0ERRIF_bp 4
#define DMA_CH1ERRIF_bm 0x20
#define DMA_CH1ERRIF_bp 5
#define DMA_CH0PEND_bm 0x01
#define DMA_CH0PEND_bp 0
#define DMA_CH1PEND_bm 0x02
#define DMA_CH1PEND_bp 1
#define DMA_CH0BUSY_bm 0x10
#define DMA_CH0BUSY_bp 4
#define DMA_CH1BUSY_bm 0x20
#define DMA_CH1BUSY_bp 5
#define EVSYS_CHMUX_gm 0xFF
#define EVSYS_CHMUX_gp 0
#define EVSYS_CHMUX0_bm (1<<0)
#define EVSYS_CHMUX0_bp 0
#define EVSYS_CHMUX1_bm (1<<1)
#define EVSYS_CHMUX1_bp 1
#define EVSYS_CHMUX2_bm (1<<2)
#define EVSYS_CHMUX2_bp 2
#define EVSYS_CHMUX3_bm (1<<3)
#define EVSYS_CHMUX3_bp 3
#define EVSYS_CHMUX4_bm (1<<4)
#define EVSYS_CHMUX4_bp 4
#define EVSYS_CHMUX5_bm (1<<5)
#define EVSYS_CHMUX5_bp 5
#define EVSYS_CHMUX6_bm (1<<6)
#define EVSYS_CHMUX6_bp 6
#define EVSYS_CHMUX7_bm (1<<7)
#define EVSYS_CHMUX7_bp 7
#define EVSYS_DIGFILT_gm 0x07
#define EVSYS_DIGFILT_gp 0
#define EVSYS_DIGFILT0_bm (1<<0)
#define EVSYS_DIGFILT0_bp 0
#define EVSYS_DIGFILT1_bm (1<<1)
#define EVSYS_DIGFILT1_bp 1
#define EVSYS_DIGFILT2_bm (1<<2)
#define EVSYS_DIGFILT2_bp 2
#define EVSYS_QDEN_bm 0x08
#define EVSYS_QDEN_bp 3
#define EVSYS_QDIEN_bm 0x10
#define EVSYS_QDIEN_bp 4
#define EVSYS_QDIRM_gm 0x60
#define EVSYS_QDIRM_gp 5
#define EVSYS_QDIRM0_bm (1<<5)
#define EVSYS_QDIRM0_bp 5
#define EVSYS_QDIRM1_bm (1<<6)
#define EVSYS_QDIRM1_bp 6
#define NVM_FUSES_JTAGUSERID_gm 0xFF
#define NVM_FUSES_JTAGUSERID_gp 0
#define NVM_FUSES_JTAGUSERID0_bm (1<<0)
#define NVM_FUSES_JTAGUSERID0_bp 0
#define NVM_FUSES_JTAGUSERID1_bm (1<<1)
#define NVM_FUSES_JTAGUSERID1_bp 1
#define NVM_FUSES_JTAGUSERID2_bm (1<<2)
#define NVM_FUSES_JTAGUSERID2_bp 2
#define NVM_FUSES_JTAGUSERID3_bm (1<<3)
#define NVM_FUSES_JTAGUSERID3_bp 3
#define NVM_FUSES_JTAGUSERID4_bm (1<<4)
#define NVM_FUSES_JTAGUSERID4_bp 4
#define NVM_FUSES_JTAGUSERID5_bm (1<<5)
#define NVM_FUSES_JTAGUSERID5_bp 5
#define NVM_FUSES_JTAGUSERID6_bm (1<<6)
#define NVM_FUSES_JTAGUSERID6_bp 6
#define NVM_FUSES_JTAGUSERID7_bm (1<<7)
#define NVM_FUSES_JTAGUSERID7_bp 7
#define NVM_FUSES_WDPER_gm 0x0F
#define NVM_FUSES_WDPER_gp 0
#define NVM_FUSES_WDPER0_bm (1<<0)
#define NVM_FUSES_WDPER0_bp 0
#define NVM_FUSES_WDPER1_bm (1<<1)
#define NVM_FUSES_WDPER1_bp 1
#define NVM_FUSES_WDPER2_bm (1<<2)
#define NVM_FUSES_WDPER2_bp 2
#define NVM_FUSES_WDPER3_bm (1<<3)
#define NVM_FUSES_WDPER3_bp 3
#define NVM_FUSES_WDWPER_gm 0xF0
#define NVM_FUSES_WDWPER_gp 4
#define NVM_FUSES_WDWPER0_bm (1<<4)
#define NVM_FUSES_WDWPER0_bp 4
#define NVM_FUSES_WDWPER1_bm (1<<5)
#define NVM_FUSES_WDWPER1_bp 5
#define NVM_FUSES_WDWPER2_bm (1<<6)
#define NVM_FUSES_WDWPER2_bp 6
#define NVM_FUSES_WDWPER3_bm (1<<7)
#define NVM_FUSES_WDWPER3_bp 7
#define NVM_FUSES_BODPD_gm 0x03
#define NVM_FUSES_BODPD_gp 0
#define NVM_FUSES_BODPD0_bm (1<<0)
#define NVM_FUSES_BODPD0_bp 0
#define NVM_FUSES_BODPD1_bm (1<<1)
#define NVM_FUSES_BODPD1_bp 1
#define NVM_FUSES_TOSCSEL_bm 0x20
#define NVM_FUSES_TOSCSEL_bp 5
#define NVM_FUSES_BOOTRST_bm 0x40
#define NVM_FUSES_BOOTRST_bp 6
#define NVM_FUSES_JTAGEN_bm 0x01
#define NVM_FUSES_JTAGEN_bp 0
#define NVM_FUSES_WDLOCK_bm 0x02
#define NVM_FUSES_WDLOCK_bp 1
#define NVM_FUSES_STARTUPTIME_gm 0x0C
#define NVM_FUSES_STARTUPTIME_gp 2
#define NVM_FUSES_STARTUPTIME0_bm (1<<2)
#define NVM_FUSES_STARTUPTIME0_bp 2
#define NVM_FUSES_STARTUPTIME1_bm (1<<3)
#define NVM_FUSES_STARTUPTIME1_bp 3
#define NVM_FUSES_RSTDISBL_bm 0x10
#define NVM_FUSES_RSTDISBL_bp 4
#define NVM_FUSES_BODLEVEL_gm 0x07
#define NVM_FUSES_BODLEVEL_gp 0
#define NVM_FUSES_BODLEVEL0_bm (1<<0)
#define NVM_FUSES_BODLEVEL0_bp 0
#define NVM_FUSES_BODLEVEL1_bm (1<<1)
#define NVM_FUSES_BODLEVEL1_bp 1
#define NVM_FUSES_BODLEVEL2_bm (1<<2)
#define NVM_FUSES_BODLEVEL2_bp 2
#define NVM_FUSES_EESAVE_bm 0x08
#define NVM_FUSES_EESAVE_bp 3
#define NVM_FUSES_BODACT_gm 0x30
#define NVM_FUSES_BODACT_gp 4
#define NVM_FUSES_BODACT0_bm (1<<4)
#define NVM_FUSES_BODACT0_bp 4
#define NVM_FUSES_BODACT1_bm (1<<5)
#define NVM_FUSES_BODACT1_bp 5
#define HIRES_HREN_gm 0x03
#define HIRES_HREN_gp 0
#define HIRES_HREN0_bm (1<<0)
#define HIRES_HREN0_bp 0
#define HIRES_HREN1_bm (1<<1)
#define HIRES_HREN1_bp 1
#define HIRES_HRPLUS_bm 0x04
#define HIRES_HRPLUS_bp 2
#define IRCOM_EVSEL_gm 0x0F
#define IRCOM_EVSEL_gp 0
#define IRCOM_EVSEL0_bm (1<<0)
#define IRCOM_EVSEL0_bp 0
#define IRCOM_EVSEL1_bm (1<<1)
#define IRCOM_EVSEL1_bp 1
#define IRCOM_EVSEL2_bm (1<<2)
#define IRCOM_EVSEL2_bp 2
#define IRCOM_EVSEL3_bm (1<<3)
#define IRCOM_EVSEL3_bp 3
#define LCD_BLANK_bm 0x01
#define LCD_BLANK_bp 0
#define LCD_SEGON_bm 0x02
#define LCD_SEGON_bp 1
#define LCD_CLRDT_bm 0x04
#define LCD_CLRDT_bp 2
#define LCD_SEGSWP_bm 0x08
#define LCD_SEGSWP_bp 3
#define LCD_COMSWP_bm 0x10
#define LCD_COMSWP_bp 4
#define LCD_DATCLK_bm 0x20
#define LCD_DATCLK_bp 5
#define LCD_XBIAS_bm 0x40
#define LCD_XBIAS_bp 6
#define LCD_ENABLE_bm 0x80
#define LCD_ENABLE_bp 7
#define LCD_DUTY_gm 0x03
#define LCD_DUTY_gp 0
#define LCD_DUTY0_bm (1<<0)
#define LCD_DUTY0_bp 0
#define LCD_DUTY1_bm (1<<1)
#define LCD_DUTY1_bp 1
#define LCD_LPWAV_bm 0x08
#define LCD_LPWAV_bp 3
#define LCD_CLKDIV_gm 0x70
#define LCD_CLKDIV_gp 4
#define LCD_CLKDIV0_bm (1<<4)
#define LCD_CLKDIV0_bp 4
#define LCD_CLKDIV1_bm (1<<5)
#define LCD_CLKDIV1_bp 5
#define LCD_CLKDIV2_bm (1<<6)
#define LCD_CLKDIV2_bp 6
#define LCD_PRESC_bm 0x80
#define LCD_PRESC_bp 7
#define LCD_PMSK_gm 0x3F
#define LCD_PMSK_gp 0
#define LCD_PMSK0_bm (1<<0)
#define LCD_PMSK0_bp 0
#define LCD_PMSK1_bm (1<<1)
#define LCD_PMSK1_bp 1
#define LCD_PMSK2_bm (1<<2)
#define LCD_PMSK2_bp 2
#define LCD_PMSK3_bm (1<<3)
#define LCD_PMSK3_bp 3
#define LCD_PMSK4_bm (1<<4)
#define LCD_PMSK4_bp 4
#define LCD_PMSK5_bm (1<<5)
#define LCD_PMSK5_bp 5
#define LCD_FCINTLVL_gm 0x03
#define LCD_FCINTLVL_gp 0
#define LCD_FCINTLVL0_bm (1<<0)
#define LCD_FCINTLVL0_bp 0
#define LCD_FCINTLVL1_bm (1<<1)
#define LCD_FCINTLVL1_bp 1
#define LCD_XIME_gm 0xF8
#define LCD_XIME_gp 3
#define LCD_XIME0_bm (1<<3)
#define LCD_XIME0_bp 3
#define LCD_XIME1_bm (1<<4)
#define LCD_XIME1_bp 4
#define LCD_XIME2_bm (1<<5)
#define LCD_XIME2_bp 5
#define LCD_XIME3_bm (1<<6)
#define LCD_XIME3_bp 6
#define LCD_XIME4_bm (1<<7)
#define LCD_XIME4_bp 7
#define LCD_FCIF_bm 0x01
#define LCD_FCIF_bp 0
#define LCD_BLINKRATE_gm 0x03
#define LCD_BLINKRATE_gp 0
#define LCD_BLINKRATE0_bm (1<<0)
#define LCD_BLINKRATE0_bp 0
#define LCD_BLINKRATE1_bm (1<<1)
#define LCD_BLINKRATE1_bp 1
#define LCD_BLINKEN_bm 0x08
#define LCD_BLINKEN_bp 3
#define LCD_BPS0_gm 0x0F
#define LCD_BPS0_gp 0
#define LCD_BPS00_bm (1<<0)
#define LCD_BPS00_bp 0
#define LCD_BPS01_bm (1<<1)
#define LCD_BPS01_bp 1
#define LCD_BPS02_bm (1<<2)
#define LCD_BPS02_bp 2
#define LCD_BPS03_bm (1<<3)
#define LCD_BPS03_bp 3
#define LCD_BPS1_gm 0xF0
#define LCD_BPS1_gp 4
#define LCD_BPS10_bm (1<<4)
#define LCD_BPS10_bp 4
#define LCD_BPS11_bm (1<<5)
#define LCD_BPS11_bp 5
#define LCD_BPS12_bm (1<<6)
#define LCD_BPS12_bp 6
#define LCD_BPS13_bm (1<<7)
#define LCD_BPS13_bp 7
#define LCD_FCONT_gm 0x3F
#define LCD_FCONT_gp 0
#define LCD_FCONT0_bm (1<<0)
#define LCD_FCONT0_bp 0
#define LCD_FCONT1_bm (1<<1)
#define LCD_FCONT1_bp 1
#define LCD_FCONT2_bm (1<<2)
#define LCD_FCONT2_bp 2
#define LCD_FCONT3_bm (1<<3)
#define LCD_FCONT3_bp 3
#define LCD_FCONT4_bm (1<<4)
#define LCD_FCONT4_bp 4
#define LCD_FCONT5_bm (1<<5)
#define LCD_FCONT5_bp 5
#define LCD_STSEG_gm 0x3F
#define LCD_STSEG_gp 0
#define LCD_STSEG0_bm (1<<0)
#define LCD_STSEG0_bp 0
#define LCD_STSEG1_bm (1<<1)
#define LCD_STSEG1_bp 1
#define LCD_STSEG2_bm (1<<2)
#define LCD_STSEG2_bp 2
#define LCD_STSEG3_bm (1<<3)
#define LCD_STSEG3_bp 3
#define LCD_STSEG4_bm (1<<4)
#define LCD_STSEG4_bp 4
#define LCD_STSEG5_bm (1<<5)
#define LCD_STSEG5_bp 5
#define LCD_TDG_gm 0xC0
#define LCD_TDG_gp 6
#define LCD_TDG0_bm (1<<6)
#define LCD_TDG0_bp 6
#define LCD_TDG1_bm (1<<7)
#define LCD_TDG1_bp 7
#define LCD_DCODE_gm 0x7F
#define LCD_DCODE_gp 0
#define LCD_DCODE0_bm (1<<0)
#define LCD_DCODE0_bp 0
#define LCD_DCODE1_bm (1<<1)
#define LCD_DCODE1_bp 1
#define LCD_DCODE2_bm (1<<2)
#define LCD_DCODE2_bp 2
#define LCD_DCODE3_bm (1<<3)
#define LCD_DCODE3_bp 3
#define LCD_DCODE4_bm (1<<4)
#define LCD_DCODE4_bp 4
#define LCD_DCODE5_bm (1<<5)
#define LCD_DCODE5_bp 5
#define LCD_DCODE6_bm (1<<6)
#define LCD_DCODE6_bp 6
#define LCD_DEC_bm 0x80
#define LCD_DEC_bp 7
#define NVM_LOCKBITS_LB_gm 0x03
#define NVM_LOCKBITS_LB_gp 0
#define NVM_LOCKBITS_LB0_bm (1<<0)
#define NVM_LOCKBITS_LB0_bp 0
#define NVM_LOCKBITS_LB1_bm (1<<1)
#define NVM_LOCKBITS_LB1_bp 1
#define NVM_LOCKBITS_BLBAT_gm 0x0C
#define NVM_LOCKBITS_BLBAT_gp 2
#define NVM_LOCKBITS_BLBAT0_bm (1<<2)
#define NVM_LOCKBITS_BLBAT0_bp 2
#define NVM_LOCKBITS_BLBAT1_bm (1<<3)
#define NVM_LOCKBITS_BLBAT1_bp 3
#define NVM_LOCKBITS_BLBA_gm 0x30
#define NVM_LOCKBITS_BLBA_gp 4
#define NVM_LOCKBITS_BLBA0_bm (1<<4)
#define NVM_LOCKBITS_BLBA0_bp 4
#define NVM_LOCKBITS_BLBA1_bm (1<<5)
#define NVM_LOCKBITS_BLBA1_bp 5
#define NVM_LOCKBITS_BLBB_gm 0xC0
#define NVM_LOCKBITS_BLBB_gp 6
#define NVM_LOCKBITS_BLBB0_bm (1<<6)
#define NVM_LOCKBITS_BLBB0_bp 6
#define NVM_LOCKBITS_BLBB1_bm (1<<7)
#define NVM_LOCKBITS_BLBB1_bp 7
#define MCU_JTAGD_bm 0x01
#define MCU_JTAGD_bp 0
#define MCU_STARTUPDLYA_gm 0x03
#define MCU_STARTUPDLYA_gp 0
#define MCU_STARTUPDLYA0_bm (1<<0)
#define MCU_STARTUPDLYA0_bp 0
#define MCU_STARTUPDLYA1_bm (1<<1)
#define MCU_STARTUPDLYA1_bp 1
#define MCU_STARTUPDLYB_gm 0x0C
#define MCU_STARTUPDLYB_gp 2
#define MCU_STARTUPDLYB0_bm (1<<2)
#define MCU_STARTUPDLYB0_bp 2
#define MCU_STARTUPDLYB1_bm (1<<3)
#define MCU_STARTUPDLYB1_bp 3
#define MCU_EVSYS0LOCK_bm 0x01
#define MCU_EVSYS0LOCK_bp 0
#define MCU_EVSYS1LOCK_bm 0x10
#define MCU_EVSYS1LOCK_bp 4
#define MCU_AWEXCLOCK_bm 0x01
#define MCU_AWEXCLOCK_bp 0
#define NVM_CMD_gm 0x7F
#define NVM_CMD_gp 0
#define NVM_CMD0_bm (1<<0)
#define NVM_CMD0_bp 0
#define NVM_CMD1_bm (1<<1)
#define NVM_CMD1_bp 1
#define NVM_CMD2_bm (1<<2)
#define NVM_CMD2_bp 2
#define NVM_CMD3_bm (1<<3)
#define NVM_CMD3_bp 3
#define NVM_CMD4_bm (1<<4)
#define NVM_CMD4_bp 4
#define NVM_CMD5_bm (1<<5)
#define NVM_CMD5_bp 5
#define NVM_CMD6_bm (1<<6)
#define NVM_CMD6_bp 6
#define NVM_CMDEX_bm 0x01
#define NVM_CMDEX_bp 0
#define NVM_SPMLOCK_bm 0x01
#define NVM_SPMLOCK_bp 0
#define NVM_EPRM_bm 0x02
#define NVM_EPRM_bp 1
#define NVM_FPRM_bm 0x04
#define NVM_FPRM_bp 2
#define NVM_EEMAPEN_bm 0x08
#define NVM_EEMAPEN_bp 3
#define NVM_EELVL_gm 0x03
#define NVM_EELVL_gp 0
#define NVM_EELVL0_bm (1<<0)
#define NVM_EELVL0_bp 0
#define NVM_EELVL1_bm (1<<1)
#define NVM_EELVL1_bp 1
#define NVM_SPMLVL_gm 0x0C
#define NVM_SPMLVL_gp 2
#define NVM_SPMLVL0_bm (1<<2)
#define NVM_SPMLVL0_bp 2
#define NVM_SPMLVL1_bm (1<<3)
#define NVM_SPMLVL1_bp 3
#define NVM_FLOAD_bm 0x01
#define NVM_FLOAD_bp 0
#define NVM_EELOAD_bm 0x02
#define NVM_EELOAD_bp 1
#define NVM_FBUSY_bm 0x40
#define NVM_FBUSY_bp 6
#define NVM_NVMBUSY_bm 0x80
#define NVM_NVMBUSY_bp 7
#define NVM_LB_gm 0x03
#define NVM_LB_gp 0
#define NVM_LB0_bm (1<<0)
#define NVM_LB0_bp 0
#define NVM_LB1_bm (1<<1)
#define NVM_LB1_bp 1
#define NVM_BLBAT_gm 0x0C
#define NVM_BLBAT_gp 2
#define NVM_BLBAT0_bm (1<<2)
#define NVM_BLBAT0_bp 2
#define NVM_BLBAT1_bm (1<<3)
#define NVM_BLBAT1_bp 3
#define NVM_BLBA_gm 0x30
#define NVM_BLBA_gp 4
#define NVM_BLBA0_bm (1<<4)
#define NVM_BLBA0_bp 4
#define NVM_BLBA1_bm (1<<5)
#define NVM_BLBA1_bp 5
#define NVM_BLBB_gm 0xC0
#define NVM_BLBB_gp 6
#define NVM_BLBB0_bm (1<<6)
#define NVM_BLBB0_bp 6
#define NVM_BLBB1_bm (1<<7)
#define NVM_BLBB1_bp 7
#define OSC_RC2MEN_bm 0x01
#define OSC_RC2MEN_bp 0
#define OSC_RC32MEN_bm 0x02
#define OSC_RC32MEN_bp 1
#define OSC_RC32KEN_bm 0x04
#define OSC_RC32KEN_bp 2
#define OSC_XOSCEN_bm 0x08
#define OSC_XOSCEN_bp 3
#define OSC_PLLEN_bm 0x10
#define OSC_PLLEN_bp 4
#define OSC_RC2MRDY_bm 0x01
#define OSC_RC2MRDY_bp 0
#define OSC_RC32MRDY_bm 0x02
#define OSC_RC32MRDY_bp 1
#define OSC_RC32KRDY_bm 0x04
#define OSC_RC32KRDY_bp 2
#define OSC_XOSCRDY_bm 0x08
#define OSC_XOSCRDY_bp 3
#define OSC_PLLRDY_bm 0x10
#define OSC_PLLRDY_bp 4
#define OSC_XOSCPWR_bm 0x10
#define OSC_XOSCPWR_bp 4
#define OSC_XOSCSEL_gm 0x1F
#define OSC_XOSCSEL_gp 0
#define OSC_XOSCSEL0_bm (1<<0)
#define OSC_XOSCSEL0_bp 0
#define OSC_XOSCSEL1_bm (1<<1)
#define OSC_XOSCSEL1_bp 1
#define OSC_XOSCSEL2_bm (1<<2)
#define OSC_XOSCSEL2_bp 2
#define OSC_XOSCSEL3_bm (1<<3)
#define OSC_XOSCSEL3_bp 3
#define OSC_XOSCSEL4_bm (1<<4)
#define OSC_XOSCSEL4_bp 4
#define OSC_X32KLPM_bm 0x20
#define OSC_X32KLPM_bp 5
#define OSC_FRQRANGE_gm 0xC0
#define OSC_FRQRANGE_gp 6
#define OSC_FRQRANGE0_bm (1<<6)
#define OSC_FRQRANGE0_bp 6
#define OSC_FRQRANGE1_bm (1<<7)
#define OSC_FRQRANGE1_bp 7
#define OSC_XOSCFDEN_bm 0x01
#define OSC_XOSCFDEN_bp 0
#define OSC_XOSCFDIF_bm 0x02
#define OSC_XOSCFDIF_bp 1
#define OSC_PLLFDEN_bm 0x04
#define OSC_PLLFDEN_bp 2
#define OSC_PLLFDIF_bm 0x08
#define OSC_PLLFDIF_bp 3
#define OSC_PLLFAC_gm 0x1F
#define OSC_PLLFAC_gp 0
#define OSC_PLLFAC0_bm (1<<0)
#define OSC_PLLFAC0_bp 0
#define OSC_PLLFAC1_bm (1<<1)
#define OSC_PLLFAC1_bp 1
#define OSC_PLLFAC2_bm (1<<2)
#define OSC_PLLFAC2_bp 2
#define OSC_PLLFAC3_bm (1<<3)
#define OSC_PLLFAC3_bp 3
#define OSC_PLLFAC4_bm (1<<4)
#define OSC_PLLFAC4_bp 4
#define OSC_PLLDIV_bm 0x20
#define OSC_PLLDIV_bp 5
#define OSC_PLLSRC_gm 0xC0
#define OSC_PLLSRC_gp 6
#define OSC_PLLSRC0_bm (1<<6)
#define OSC_PLLSRC0_bp 6
#define OSC_PLLSRC1_bm (1<<7)
#define OSC_PLLSRC1_bp 7
#define OSC_RC2MCREF_bm 0x01
#define OSC_RC2MCREF_bp 0
#define OSC_RC32MCREF_gm 0x06
#define OSC_RC32MCREF_gp 1
#define OSC_RC32MCREF0_bm (1<<1)
#define OSC_RC32MCREF0_bp 1
#define OSC_RC32MCREF1_bm (1<<2)
#define OSC_RC32MCREF1_bp 2
#define PMIC_LOLVLEX_bm 0x01
#define PMIC_LOLVLEX_bp 0
#define PMIC_MEDLVLEX_bm 0x02
#define PMIC_MEDLVLEX_bp 1
#define PMIC_HILVLEX_bm 0x04
#define PMIC_HILVLEX_bp 2
#define PMIC_NMIEX_bm 0x80
#define PMIC_NMIEX_bp 7
#define PMIC_INTPRI_gm 0xFF
#define PMIC_INTPRI_gp 0
#define PMIC_INTPRI0_bm (1<<0)
#define PMIC_INTPRI0_bp 0
#define PMIC_INTPRI1_bm (1<<1)
#define PMIC_INTPRI1_bp 1
#define PMIC_INTPRI2_bm (1<<2)
#define PMIC_INTPRI2_bp 2
#define PMIC_INTPRI3_bm (1<<3)
#define PMIC_INTPRI3_bp 3
#define PMIC_INTPRI4_bm (1<<4)
#define PMIC_INTPRI4_bp 4
#define PMIC_INTPRI5_bm (1<<5)
#define PMIC_INTPRI5_bp 5
#define PMIC_INTPRI6_bm (1<<6)
#define PMIC_INTPRI6_bp 6
#define PMIC_INTPRI7_bm (1<<7)
#define PMIC_INTPRI7_bp 7
#define PMIC_LOLVLEN_bm 0x01
#define PMIC_LOLVLEN_bp 0
#define PMIC_MEDLVLEN_bm 0x02
#define PMIC_MEDLVLEN_bp 1
#define PMIC_HILVLEN_bm 0x04
#define PMIC_HILVLEN_bp 2
#define PMIC_IVSEL_bm 0x40
#define PMIC_IVSEL_bp 6
#define PMIC_RREN_bm 0x80
#define PMIC_RREN_bp 7
#define PORT_INT0LVL_gm 0x03
#define PORT_INT0LVL_gp 0
#define PORT_INT0LVL0_bm (1<<0)
#define PORT_INT0LVL0_bp 0
#define PORT_INT0LVL1_bm (1<<1)
#define PORT_INT0LVL1_bp 1
#define PORT_INT1LVL_gm 0x0C
#define PORT_INT1LVL_gp 2
#define PORT_INT1LVL0_bm (1<<2)
#define PORT_INT1LVL0_bp 2
#define PORT_INT1LVL1_bm (1<<3)
#define PORT_INT1LVL1_bp 3
#define PORT_INT0IF_bm 0x01
#define PORT_INT0IF_bp 0
#define PORT_INT1IF_bm 0x02
#define PORT_INT1IF_bp 1
#define PORT_TC0A_bm 0x01
#define PORT_TC0A_bp 0
#define PORT_TC0B_bm 0x02
#define PORT_TC0B_bp 1
#define PORT_TC0C_bm 0x04
#define PORT_TC0C_bp 2
#define PORT_TC0D_bm 0x08
#define PORT_TC0D_bp 3
#define PORT_USART0_bm 0x10
#define PORT_USART0_bp 4
#define PORT_SPI_bm 0x20
#define PORT_SPI_bp 5
#define PORT_ISC_gm 0x07
#define PORT_ISC_gp 0
#define PORT_ISC0_bm (1<<0)
#define PORT_ISC0_bp 0
#define PORT_ISC1_bm (1<<1)
#define PORT_ISC1_bp 1
#define PORT_ISC2_bm (1<<2)
#define PORT_ISC2_bp 2
#define PORT_OPC_gm 0x38
#define PORT_OPC_gp 3
#define PORT_OPC0_bm (1<<3)
#define PORT_OPC0_bp 3
#define PORT_OPC1_bm (1<<4)
#define PORT_OPC1_bp 4
#define PORT_OPC2_bm (1<<5)
#define PORT_OPC2_bp 5
#define PORT_INVEN_bm 0x40
#define PORT_INVEN_bp 6
#define PORT_SRLEN_bm 0x80
#define PORT_SRLEN_bp 7
#define PORTCFG_VP0MAP_gm 0x0F
#define PORTCFG_VP0MAP_gp 0
#define PORTCFG_VP0MAP0_bm (1<<0)
#define PORTCFG_VP0MAP0_bp 0
#define PORTCFG_VP0MAP1_bm (1<<1)
#define PORTCFG_VP0MAP1_bp 1
#define PORTCFG_VP0MAP2_bm (1<<2)
#define PORTCFG_VP0MAP2_bp 2
#define PORTCFG_VP0MAP3_bm (1<<3)
#define PORTCFG_VP0MAP3_bp 3
#define PORTCFG_VP1MAP_gm 0xF0
#define PORTCFG_VP1MAP_gp 4
#define PORTCFG_VP1MAP0_bm (1<<4)
#define PORTCFG_VP1MAP0_bp 4
#define PORTCFG_VP1MAP1_bm (1<<5)
#define PORTCFG_VP1MAP1_bp 5
#define PORTCFG_VP1MAP2_bm (1<<6)
#define PORTCFG_VP1MAP2_bp 6
#define PORTCFG_VP1MAP3_bm (1<<7)
#define PORTCFG_VP1MAP3_bp 7
#define PORTCFG_VP2MAP_gm 0x0F
#define PORTCFG_VP2MAP_gp 0
#define PORTCFG_VP2MAP0_bm (1<<0)
#define PORTCFG_VP2MAP0_bp 0
#define PORTCFG_VP2MAP1_bm (1<<1)
#define PORTCFG_VP2MAP1_bp 1
#define PORTCFG_VP2MAP2_bm (1<<2)
#define PORTCFG_VP2MAP2_bp 2
#define PORTCFG_VP2MAP3_bm (1<<3)
#define PORTCFG_VP2MAP3_bp 3
#define PORTCFG_VP3MAP_gm 0xF0
#define PORTCFG_VP3MAP_gp 4
#define PORTCFG_VP3MAP0_bm (1<<4)
#define PORTCFG_VP3MAP0_bp 4
#define PORTCFG_VP3MAP1_bm (1<<5)
#define PORTCFG_VP3MAP1_bp 5
#define PORTCFG_VP3MAP2_bm (1<<6)
#define PORTCFG_VP3MAP2_bp 6
#define PORTCFG_VP3MAP3_bm (1<<7)
#define PORTCFG_VP3MAP3_bp 7
#define PORTCFG_CLKOUT_gm 0x03
#define PORTCFG_CLKOUT_gp 0
#define PORTCFG_CLKOUT0_bm (1<<0)
#define PORTCFG_CLKOUT0_bp 0
#define PORTCFG_CLKOUT1_bm (1<<1)
#define PORTCFG_CLKOUT1_bp 1
#define PORTCFG_CLKOUTSEL_gm 0x0C
#define PORTCFG_CLKOUTSEL_gp 2
#define PORTCFG_CLKOUTSEL0_bm (1<<2)
#define PORTCFG_CLKOUTSEL0_bp 2
#define PORTCFG_CLKOUTSEL1_bm (1<<3)
#define PORTCFG_CLKOUTSEL1_bp 3
#define PORTCFG_EVOUT_gm 0x30
#define PORTCFG_EVOUT_gp 4
#define PORTCFG_EVOUT0_bm (1<<4)
#define PORTCFG_EVOUT0_bp 4
#define PORTCFG_EVOUT1_bm (1<<5)
#define PORTCFG_EVOUT1_bp 5
#define PORTCFG_RTCOUT_bm 0x40
#define PORTCFG_RTCOUT_bp 6
#define PORTCFG_CLKEVPIN_bm 0x80
#define PORTCFG_CLKEVPIN_bp 7
#define PORTCFG_EVOUTSEL_bm 0x04
#define PORTCFG_EVOUTSEL_bp 2
#define PR_DMA_bm 0x01
#define PR_DMA_bp 0
#define PR_EVSYS_bm 0x02
#define PR_EVSYS_bp 1
#define PR_RTC_bm 0x04
#define PR_RTC_bp 2
#define PR_AES_bm 0x10
#define PR_AES_bp 4
#define PR_USB_bm 0x40
#define PR_USB_bp 6
#define PR_LCD_bm 0x80
#define PR_LCD_bp 7
#define PR_AC_bm 0x01
#define PR_AC_bp 0
#define PR_ADC_bm 0x02
#define PR_ADC_bp 1
#define PR_TC0_bm 0x01
#define PR_TC0_bp 0
#define PR_TC1_bm 0x02
#define PR_TC1_bp 1
#define PR_HIRES_bm 0x04
#define PR_HIRES_bp 2
#define PR_SPI_bm 0x08
#define PR_SPI_bp 3
#define PR_USART0_bm 0x10
#define PR_USART0_bp 4
#define PR_TWI_bm 0x40
#define PR_TWI_bp 6
#define RST_PORF_bm 0x01
#define RST_PORF_bp 0
#define RST_EXTRF_bm 0x02
#define RST_EXTRF_bp 1
#define RST_BORF_bm 0x04
#define RST_BORF_bp 2
#define RST_WDRF_bm 0x08
#define RST_WDRF_bp 3
#define RST_PDIRF_bm 0x10
#define RST_PDIRF_bp 4
#define RST_SRF_bm 0x20
#define RST_SRF_bp 5
#define RST_SDRF_bm 0x40
#define RST_SDRF_bp 6
#define RST_SWRST_bm 0x01
#define RST_SWRST_bp 0
#define RTC_PRESCALER_gm 0x07
#define RTC_PRESCALER_gp 0
#define RTC_PRESCALER0_bm (1<<0)
#define RTC_PRESCALER0_bp 0
#define RTC_PRESCALER1_bm (1<<1)
#define RTC_PRESCALER1_bp 1
#define RTC_PRESCALER2_bm (1<<2)
#define RTC_PRESCALER2_bp 2
#define RTC_SYNCBUSY_bm 0x01
#define RTC_SYNCBUSY_bp 0
#define RTC_OVFINTLVL_gm 0x03
#define RTC_OVFINTLVL_gp 0
#define RTC_OVFINTLVL0_bm (1<<0)
#define RTC_OVFINTLVL0_bp 0
#define RTC_OVFINTLVL1_bm (1<<1)
#define RTC_OVFINTLVL1_bp 1
#define RTC_COMPINTLVL_gm 0x0C
#define RTC_COMPINTLVL_gp 2
#define RTC_COMPINTLVL0_bm (1<<2)
#define RTC_COMPINTLVL0_bp 2
#define RTC_COMPINTLVL1_bm (1<<3)
#define RTC_COMPINTLVL1_bp 3
#define RTC_OVFIF_bm 0x01
#define RTC_OVFIF_bp 0
#define RTC_COMPIF_bm 0x02
#define RTC_COMPIF_bp 1
#define SLEEP_SEN_bm 0x01
#define SLEEP_SEN_bp 0
#define SLEEP_SMODE_gm 0x0E
#define SLEEP_SMODE_gp 1
#define SLEEP_SMODE0_bm (1<<1)
#define SLEEP_SMODE0_bp 1
#define SLEEP_SMODE1_bm (1<<2)
#define SLEEP_SMODE1_bp 2
#define SLEEP_SMODE2_bm (1<<3)
#define SLEEP_SMODE2_bp 3
#define SPI_PRESCALER_gm 0x03
#define SPI_PRESCALER_gp 0
#define SPI_PRESCALER0_bm (1<<0)
#define SPI_PRESCALER0_bp 0
#define SPI_PRESCALER1_bm (1<<1)
#define SPI_PRESCALER1_bp 1
#define SPI_MODE_gm 0x0C
#define SPI_MODE_gp 2
#define SPI_MODE0_bm (1<<2)
#define SPI_MODE0_bp 2
#define SPI_MODE1_bm (1<<3)
#define SPI_MODE1_bp 3
#define SPI_MASTER_bm 0x10
#define SPI_MASTER_bp 4
#define SPI_DORD_bm 0x20
#define SPI_DORD_bp 5
#define SPI_ENABLE_bm 0x40
#define SPI_ENABLE_bp 6
#define SPI_CLK2X_bm 0x80
#define SPI_CLK2X_bp 7
#define SPI_INTLVL_gm 0x03
#define SPI_INTLVL_gp 0
#define SPI_INTLVL0_bm (1<<0)
#define SPI_INTLVL0_bp 0
#define SPI_INTLVL1_bm (1<<1)
#define SPI_INTLVL1_bp 1
#define SPI_WRCOL_bm 0x40
#define SPI_WRCOL_bp 6
#define SPI_IF_bm 0x80
#define SPI_IF_bp 7
#define TC0_CLKSEL_gm 0x0F
#define TC0_CLKSEL_gp 0
#define TC0_CLKSEL0_bm (1<<0)
#define TC0_CLKSEL0_bp 0
#define TC0_CLKSEL1_bm (1<<1)
#define TC0_CLKSEL1_bp 1
#define TC0_CLKSEL2_bm (1<<2)
#define TC0_CLKSEL2_bp 2
#define TC0_CLKSEL3_bm (1<<3)
#define TC0_CLKSEL3_bp 3
#define TC0_WGMODE_gm 0x07
#define TC0_WGMODE_gp 0
#define TC0_WGMODE0_bm (1<<0)
#define TC0_WGMODE0_bp 0
#define TC0_WGMODE1_bm (1<<1)
#define TC0_WGMODE1_bp 1
#define TC0_WGMODE2_bm (1<<2)
#define TC0_WGMODE2_bp 2
#define TC0_CCAEN_bm 0x10
#define TC0_CCAEN_bp 4
#define TC0_CCBEN_bm 0x20
#define TC0_CCBEN_bp 5
#define TC0_CCCEN_bm 0x40
#define TC0_CCCEN_bp 6
#define TC0_CCDEN_bm 0x80
#define TC0_CCDEN_bp 7
#define TC0_CMPA_bm 0x01
#define TC0_CMPA_bp 0
#define TC0_CMPB_bm 0x02
#define TC0_CMPB_bp 1
#define TC0_CMPC_bm 0x04
#define TC0_CMPC_bp 2
#define TC0_CMPD_bm 0x08
#define TC0_CMPD_bp 3
#define TC0_EVSEL_gm 0x0F
#define TC0_EVSEL_gp 0
#define TC0_EVSEL0_bm (1<<0)
#define TC0_EVSEL0_bp 0
#define TC0_EVSEL1_bm (1<<1)
#define TC0_EVSEL1_bp 1
#define TC0_EVSEL2_bm (1<<2)
#define TC0_EVSEL2_bp 2
#define TC0_EVSEL3_bm (1<<3)
#define TC0_EVSEL3_bp 3
#define TC0_EVDLY_bm 0x10
#define TC0_EVDLY_bp 4
#define TC0_EVACT_gm 0xE0
#define TC0_EVACT_gp 5
#define TC0_EVACT0_bm (1<<5)
#define TC0_EVACT0_bp 5
#define TC0_EVACT1_bm (1<<6)
#define TC0_EVACT1_bp 6
#define TC0_EVACT2_bm (1<<7)
#define TC0_EVACT2_bp 7
#define TC0_BYTEM_gm 0x03
#define TC0_BYTEM_gp 0
#define TC0_BYTEM0_bm (1<<0)
#define TC0_BYTEM0_bp 0
#define TC0_BYTEM1_bm (1<<1)
#define TC0_BYTEM1_bp 1
#define TC0_OVFINTLVL_gm 0x03
#define TC0_OVFINTLVL_gp 0
#define TC0_OVFINTLVL0_bm (1<<0)
#define TC0_OVFINTLVL0_bp 0
#define TC0_OVFINTLVL1_bm (1<<1)
#define TC0_OVFINTLVL1_bp 1
#define TC0_ERRINTLVL_gm 0x0C
#define TC0_ERRINTLVL_gp 2
#define TC0_ERRINTLVL0_bm (1<<2)
#define TC0_ERRINTLVL0_bp 2
#define TC0_ERRINTLVL1_bm (1<<3)
#define TC0_ERRINTLVL1_bp 3
#define TC0_CCAINTLVL_gm 0x03
#define TC0_CCAINTLVL_gp 0
#define TC0_CCAINTLVL0_bm (1<<0)
#define TC0_CCAINTLVL0_bp 0
#define TC0_CCAINTLVL1_bm (1<<1)
#define TC0_CCAINTLVL1_bp 1
#define TC0_CCBINTLVL_gm 0x0C
#define TC0_CCBINTLVL_gp 2
#define TC0_CCBINTLVL0_bm (1<<2)
#define TC0_CCBINTLVL0_bp 2
#define TC0_CCBINTLVL1_bm (1<<3)
#define TC0_CCBINTLVL1_bp 3
#define TC0_CCCINTLVL_gm 0x30
#define TC0_CCCINTLVL_gp 4
#define TC0_CCCINTLVL0_bm (1<<4)
#define TC0_CCCINTLVL0_bp 4
#define TC0_CCCINTLVL1_bm (1<<5)
#define TC0_CCCINTLVL1_bp 5
#define TC0_CCDINTLVL_gm 0xC0
#define TC0_CCDINTLVL_gp 6
#define TC0_CCDINTLVL0_bm (1<<6)
#define TC0_CCDINTLVL0_bp 6
#define TC0_CCDINTLVL1_bm (1<<7)
#define TC0_CCDINTLVL1_bp 7
#define TC0_DIR_bm 0x01
#define TC0_DIR_bp 0
#define TC0_LUPD_bm 0x02
#define TC0_LUPD_bp 1
#define TC0_CMD_gm 0x0C
#define TC0_CMD_gp 2
#define TC0_CMD0_bm (1<<2)
#define TC0_CMD0_bp 2
#define TC0_CMD1_bm (1<<3)
#define TC0_CMD1_bp 3
#define TC0_PERBV_bm 0x01
#define TC0_PERBV_bp 0
#define TC0_CCABV_bm 0x02
#define TC0_CCABV_bp 1
#define TC0_CCBBV_bm 0x04
#define TC0_CCBBV_bp 2
#define TC0_CCCBV_bm 0x08
#define TC0_CCCBV_bp 3
#define TC0_CCDBV_bm 0x10
#define TC0_CCDBV_bp 4
#define TC0_OVFIF_bm 0x01
#define TC0_OVFIF_bp 0
#define TC0_ERRIF_bm 0x02
#define TC0_ERRIF_bp 1
#define TC0_CCAIF_bm 0x10
#define TC0_CCAIF_bp 4
#define TC0_CCBIF_bm 0x20
#define TC0_CCBIF_bp 5
#define TC0_CCCIF_bm 0x40
#define TC0_CCCIF_bp 6
#define TC0_CCDIF_bm 0x80
#define TC0_CCDIF_bp 7
#define TC1_CLKSEL_gm 0x0F
#define TC1_CLKSEL_gp 0
#define TC1_CLKSEL0_bm (1<<0)
#define TC1_CLKSEL0_bp 0
#define TC1_CLKSEL1_bm (1<<1)
#define TC1_CLKSEL1_bp 1
#define TC1_CLKSEL2_bm (1<<2)
#define TC1_CLKSEL2_bp 2
#define TC1_CLKSEL3_bm (1<<3)
#define TC1_CLKSEL3_bp 3
#define TC1_WGMODE_gm 0x07
#define TC1_WGMODE_gp 0
#define TC1_WGMODE0_bm (1<<0)
#define TC1_WGMODE0_bp 0
#define TC1_WGMODE1_bm (1<<1)
#define TC1_WGMODE1_bp 1
#define TC1_WGMODE2_bm (1<<2)
#define TC1_WGMODE2_bp 2
#define TC1_CCAEN_bm 0x10
#define TC1_CCAEN_bp 4
#define TC1_CCBEN_bm 0x20
#define TC1_CCBEN_bp 5
#define TC1_CMPA_bm 0x01
#define TC1_CMPA_bp 0
#define TC1_CMPB_bm 0x02
#define TC1_CMPB_bp 1
#define TC1_EVSEL_gm 0x0F
#define TC1_EVSEL_gp 0
#define TC1_EVSEL0_bm (1<<0)
#define TC1_EVSEL0_bp 0
#define TC1_EVSEL1_bm (1<<1)
#define TC1_EVSEL1_bp 1
#define TC1_EVSEL2_bm (1<<2)
#define TC1_EVSEL2_bp 2
#define TC1_EVSEL3_bm (1<<3)
#define TC1_EVSEL3_bp 3
#define TC1_EVDLY_bm 0x10
#define TC1_EVDLY_bp 4
#define TC1_EVACT_gm 0xE0
#define TC1_EVACT_gp 5
#define TC1_EVACT0_bm (1<<5)
#define TC1_EVACT0_bp 5
#define TC1_EVACT1_bm (1<<6)
#define TC1_EVACT1_bp 6
#define TC1_EVACT2_bm (1<<7)
#define TC1_EVACT2_bp 7
#define TC1_BYTEM_bm 0x01
#define TC1_BYTEM_bp 0
#define TC1_OVFINTLVL_gm 0x03
#define TC1_OVFINTLVL_gp 0
#define TC1_OVFINTLVL0_bm (1<<0)
#define TC1_OVFINTLVL0_bp 0
#define TC1_OVFINTLVL1_bm (1<<1)
#define TC1_OVFINTLVL1_bp 1
#define TC1_ERRINTLVL_gm 0x0C
#define TC1_ERRINTLVL_gp 2
#define TC1_ERRINTLVL0_bm (1<<2)
#define TC1_ERRINTLVL0_bp 2
#define TC1_ERRINTLVL1_bm (1<<3)
#define TC1_ERRINTLVL1_bp 3
#define TC1_CCAINTLVL_gm 0x03
#define TC1_CCAINTLVL_gp 0
#define TC1_CCAINTLVL0_bm (1<<0)
#define TC1_CCAINTLVL0_bp 0
#define TC1_CCAINTLVL1_bm (1<<1)
#define TC1_CCAINTLVL1_bp 1
#define TC1_CCBINTLVL_gm 0x0C
#define TC1_CCBINTLVL_gp 2
#define TC1_CCBINTLVL0_bm (1<<2)
#define TC1_CCBINTLVL0_bp 2
#define TC1_CCBINTLVL1_bm (1<<3)
#define TC1_CCBINTLVL1_bp 3
#define TC1_DIR_bm 0x01
#define TC1_DIR_bp 0
#define TC1_LUPD_bm 0x02
#define TC1_LUPD_bp 1
#define TC1_CMD_gm 0x0C
#define TC1_CMD_gp 2
#define TC1_CMD0_bm (1<<2)
#define TC1_CMD0_bp 2
#define TC1_CMD1_bm (1<<3)
#define TC1_CMD1_bp 3
#define TC1_PERBV_bm 0x01
#define TC1_PERBV_bp 0
#define TC1_CCABV_bm 0x02
#define TC1_CCABV_bp 1
#define TC1_CCBBV_bm 0x04
#define TC1_CCBBV_bp 2
#define TC1_OVFIF_bm 0x01
#define TC1_OVFIF_bp 0
#define TC1_ERRIF_bm 0x02
#define TC1_ERRIF_bp 1
#define TC1_CCAIF_bm 0x10
#define TC1_CCAIF_bp 4
#define TC1_CCBIF_bm 0x20
#define TC1_CCBIF_bp 5
#define TC2_CLKSEL_gm 0x0F
#define TC2_CLKSEL_gp 0
#define TC2_CLKSEL0_bm (1<<0)
#define TC2_CLKSEL0_bp 0
#define TC2_CLKSEL1_bm (1<<1)
#define TC2_CLKSEL1_bp 1
#define TC2_CLKSEL2_bm (1<<2)
#define TC2_CLKSEL2_bp 2
#define TC2_CLKSEL3_bm (1<<3)
#define TC2_CLKSEL3_bp 3
#define TC2_LCMPAEN_bm 0x01
#define TC2_LCMPAEN_bp 0
#define TC2_LCMPBEN_bm 0x02
#define TC2_LCMPBEN_bp 1
#define TC2_LCMPCEN_bm 0x04
#define TC2_LCMPCEN_bp 2
#define TC2_LCMPDEN_bm 0x08
#define TC2_LCMPDEN_bp 3
#define TC2_HCMPAEN_bm 0x10
#define TC2_HCMPAEN_bp 4
#define TC2_HCMPBEN_bm 0x20
#define TC2_HCMPBEN_bp 5
#define TC2_HCMPCEN_bm 0x40
#define TC2_HCMPCEN_bp 6
#define TC2_HCMPDEN_bm 0x80
#define TC2_HCMPDEN_bp 7
#define TC2_LCMPA_bm 0x01
#define TC2_LCMPA_bp 0
#define TC2_LCMPB_bm 0x02
#define TC2_LCMPB_bp 1
#define TC2_LCMPC_bm 0x04
#define TC2_LCMPC_bp 2
#define TC2_LCMPD_bm 0x08
#define TC2_LCMPD_bp 3
#define TC2_HCMPA_bm 0x10
#define TC2_HCMPA_bp 4
#define TC2_HCMPB_bm 0x20
#define TC2_HCMPB_bp 5
#define TC2_HCMPC_bm 0x40
#define TC2_HCMPC_bp 6
#define TC2_HCMPD_bm 0x80
#define TC2_HCMPD_bp 7
#define TC2_BYTEM_gm 0x03
#define TC2_BYTEM_gp 0
#define TC2_BYTEM0_bm (1<<0)
#define TC2_BYTEM0_bp 0
#define TC2_BYTEM1_bm (1<<1)
#define TC2_BYTEM1_bp 1
#define TC2_LUNFINTLVL_gm 0x03
#define TC2_LUNFINTLVL_gp 0
#define TC2_LUNFINTLVL0_bm (1<<0)
#define TC2_LUNFINTLVL0_bp 0
#define TC2_LUNFINTLVL1_bm (1<<1)
#define TC2_LUNFINTLVL1_bp 1
#define TC2_HUNFINTLVL_gm 0x0C
#define TC2_HUNFINTLVL_gp 2
#define TC2_HUNFINTLVL0_bm (1<<2)
#define TC2_HUNFINTLVL0_bp 2
#define TC2_HUNFINTLVL1_bm (1<<3)
#define TC2_HUNFINTLVL1_bp 3
#define TC2_LCMPAINTLVL_gm 0x03
#define TC2_LCMPAINTLVL_gp 0
#define TC2_LCMPAINTLVL0_bm (1<<0)
#define TC2_LCMPAINTLVL0_bp 0
#define TC2_LCMPAINTLVL1_bm (1<<1)
#define TC2_LCMPAINTLVL1_bp 1
#define TC2_LCMPBINTLVL_gm 0x0C
#define TC2_LCMPBINTLVL_gp 2
#define TC2_LCMPBINTLVL0_bm (1<<2)
#define TC2_LCMPBINTLVL0_bp 2
#define TC2_LCMPBINTLVL1_bm (1<<3)
#define TC2_LCMPBINTLVL1_bp 3
#define TC2_LCMPCINTLVL_gm 0x30
#define TC2_LCMPCINTLVL_gp 4
#define TC2_LCMPCINTLVL0_bm (1<<4)
#define TC2_LCMPCINTLVL0_bp 4
#define TC2_LCMPCINTLVL1_bm (1<<5)
#define TC2_LCMPCINTLVL1_bp 5
#define TC2_LCMPDINTLVL_gm 0xC0
#define TC2_LCMPDINTLVL_gp 6
#define TC2_LCMPDINTLVL0_bm (1<<6)
#define TC2_LCMPDINTLVL0_bp 6
#define TC2_LCMPDINTLVL1_bm (1<<7)
#define TC2_LCMPDINTLVL1_bp 7
#define TC2_CMDEN_gm 0x03
#define TC2_CMDEN_gp 0
#define TC2_CMDEN0_bm (1<<0)
#define TC2_CMDEN0_bp 0
#define TC2_CMDEN1_bm (1<<1)
#define TC2_CMDEN1_bp 1
#define TC2_CMD_gm 0x0C
#define TC2_CMD_gp 2
#define TC2_CMD0_bm (1<<2)
#define TC2_CMD0_bp 2
#define TC2_CMD1_bm (1<<3)
#define TC2_CMD1_bp 3
#define TC2_LUNFIF_bm 0x01
#define TC2_LUNFIF_bp 0
#define TC2_HUNFIF_bm 0x02
#define TC2_HUNFIF_bp 1
#define TC2_LCMPAIF_bm 0x10
#define TC2_LCMPAIF_bp 4
#define TC2_LCMPBIF_bm 0x20
#define TC2_LCMPBIF_bp 5
#define TC2_LCMPCIF_bm 0x40
#define TC2_LCMPCIF_bp 6
#define TC2_LCMPDIF_bm 0x80
#define TC2_LCMPDIF_bp 7
#define TWI_MASTER_ENABLE_bm 0x08
#define TWI_MASTER_ENABLE_bp 3
#define TWI_MASTER_WIEN_bm 0x10
#define TWI_MASTER_WIEN_bp 4
#define TWI_MASTER_RIEN_bm 0x20
#define TWI_MASTER_RIEN_bp 5
#define TWI_MASTER_INTLVL_gm 0xC0
#define TWI_MASTER_INTLVL_gp 6
#define TWI_MASTER_INTLVL0_bm (1<<6)
#define TWI_MASTER_INTLVL0_bp 6
#define TWI_MASTER_INTLVL1_bm (1<<7)
#define TWI_MASTER_INTLVL1_bp 7
#define TWI_MASTER_SMEN_bm 0x01
#define TWI_MASTER_SMEN_bp 0
#define TWI_MASTER_QCEN_bm 0x02
#define TWI_MASTER_QCEN_bp 1
#define TWI_MASTER_TIMEOUT_gm 0x0C
#define TWI_MASTER_TIMEOUT_gp 2
#define TWI_MASTER_TIMEOUT0_bm (1<<2)
#define TWI_MASTER_TIMEOUT0_bp 2
#define TWI_MASTER_TIMEOUT1_bm (1<<3)
#define TWI_MASTER_TIMEOUT1_bp 3
#define TWI_MASTER_CMD_gm 0x03
#define TWI_MASTER_CMD_gp 0
#define TWI_MASTER_CMD0_bm (1<<0)
#define TWI_MASTER_CMD0_bp 0
#define TWI_MASTER_CMD1_bm (1<<1)
#define TWI_MASTER_CMD1_bp 1
#define TWI_MASTER_ACKACT_bm 0x04
#define TWI_MASTER_ACKACT_bp 2
#define TWI_MASTER_BUSSTATE_gm 0x03
#define TWI_MASTER_BUSSTATE_gp 0
#define TWI_MASTER_BUSSTATE0_bm (1<<0)
#define TWI_MASTER_BUSSTATE0_bp 0
#define TWI_MASTER_BUSSTATE1_bm (1<<1)
#define TWI_MASTER_BUSSTATE1_bp 1
#define TWI_MASTER_BUSERR_bm 0x04
#define TWI_MASTER_BUSERR_bp 2
#define TWI_MASTER_ARBLOST_bm 0x08
#define TWI_MASTER_ARBLOST_bp 3
#define TWI_MASTER_RXACK_bm 0x10
#define TWI_MASTER_RXACK_bp 4
#define TWI_MASTER_CLKHOLD_bm 0x20
#define TWI_MASTER_CLKHOLD_bp 5
#define TWI_MASTER_WIF_bm 0x40
#define TWI_MASTER_WIF_bp 6
#define TWI_MASTER_RIF_bm 0x80
#define TWI_MASTER_RIF_bp 7
#define TWI_SLAVE_SMEN_bm 0x01
#define TWI_SLAVE_SMEN_bp 0
#define TWI_SLAVE_PMEN_bm 0x02
#define TWI_SLAVE_PMEN_bp 1
#define TWI_SLAVE_PIEN_bm 0x04
#define TWI_SLAVE_PIEN_bp 2
#define TWI_SLAVE_ENABLE_bm 0x08
#define TWI_SLAVE_ENABLE_bp 3
#define TWI_SLAVE_APIEN_bm 0x10
#define TWI_SLAVE_APIEN_bp 4
#define TWI_SLAVE_DIEN_bm 0x20
#define TWI_SLAVE_DIEN_bp 5
#define TWI_SLAVE_INTLVL_gm 0xC0
#define TWI_SLAVE_INTLVL_gp 6
#define TWI_SLAVE_INTLVL0_bm (1<<6)
#define TWI_SLAVE_INTLVL0_bp 6
#define TWI_SLAVE_INTLVL1_bm (1<<7)
#define TWI_SLAVE_INTLVL1_bp 7
#define TWI_SLAVE_CMD_gm 0x03
#define TWI_SLAVE_CMD_gp 0
#define TWI_SLAVE_CMD0_bm (1<<0)
#define TWI_SLAVE_CMD0_bp 0
#define TWI_SLAVE_CMD1_bm (1<<1)
#define TWI_SLAVE_CMD1_bp 1
#define TWI_SLAVE_ACKACT_bm 0x04
#define TWI_SLAVE_ACKACT_bp 2
#define TWI_SLAVE_AP_bm 0x01
#define TWI_SLAVE_AP_bp 0
#define TWI_SLAVE_DIR_bm 0x02
#define TWI_SLAVE_DIR_bp 1
#define TWI_SLAVE_BUSERR_bm 0x04
#define TWI_SLAVE_BUSERR_bp 2
#define TWI_SLAVE_COLL_bm 0x08
#define TWI_SLAVE_COLL_bp 3
#define TWI_SLAVE_RXACK_bm 0x10
#define TWI_SLAVE_RXACK_bp 4
#define TWI_SLAVE_CLKHOLD_bm 0x20
#define TWI_SLAVE_CLKHOLD_bp 5
#define TWI_SLAVE_APIF_bm 0x40
#define TWI_SLAVE_APIF_bp 6
#define TWI_SLAVE_DIF_bm 0x80
#define TWI_SLAVE_DIF_bp 7
#define TWI_SLAVE_ADDREN_bm 0x01
#define TWI_SLAVE_ADDREN_bp 0
#define TWI_SLAVE_ADDRMASK_gm 0xFE
#define TWI_SLAVE_ADDRMASK_gp 1
#define TWI_SLAVE_ADDRMASK0_bm (1<<1)
#define TWI_SLAVE_ADDRMASK0_bp 1
#define TWI_SLAVE_ADDRMASK1_bm (1<<2)
#define TWI_SLAVE_ADDRMASK1_bp 2
#define TWI_SLAVE_ADDRMASK2_bm (1<<3)
#define TWI_SLAVE_ADDRMASK2_bp 3
#define TWI_SLAVE_ADDRMASK3_bm (1<<4)
#define TWI_SLAVE_ADDRMASK3_bp 4
#define TWI_SLAVE_ADDRMASK4_bm (1<<5)
#define TWI_SLAVE_ADDRMASK4_bp 5
#define TWI_SLAVE_ADDRMASK5_bm (1<<6)
#define TWI_SLAVE_ADDRMASK5_bp 6
#define TWI_SLAVE_ADDRMASK6_bm (1<<7)
#define TWI_SLAVE_ADDRMASK6_bp 7
#define TWI_EDIEN_bm 0x01
#define TWI_EDIEN_bp 0
#define TWI_SDAHOLD_gm 0x06
#define TWI_SDAHOLD_gp 1
#define TWI_SDAHOLD0_bm (1<<1)
#define TWI_SDAHOLD0_bp 1
#define TWI_SDAHOLD1_bm (1<<2)
#define TWI_SDAHOLD1_bp 2
#define USART_RXB8_bm 0x01
#define USART_RXB8_bp 0
#define USART_PERR_bm 0x04
#define USART_PERR_bp 2
#define USART_BUFOVF_bm 0x08
#define USART_BUFOVF_bp 3
#define USART_FERR_bm 0x10
#define USART_FERR_bp 4
#define USART_DREIF_bm 0x20
#define USART_DREIF_bp 5
#define USART_TXCIF_bm 0x40
#define USART_TXCIF_bp 6
#define USART_RXCIF_bm 0x80
#define USART_RXCIF_bp 7
#define USART_DREINTLVL_gm 0x03
#define USART_DREINTLVL_gp 0
#define USART_DREINTLVL0_bm (1<<0)
#define USART_DREINTLVL0_bp 0
#define USART_DREINTLVL1_bm (1<<1)
#define USART_DREINTLVL1_bp 1
#define USART_TXCINTLVL_gm 0x0C
#define USART_TXCINTLVL_gp 2
#define USART_TXCINTLVL0_bm (1<<2)
#define USART_TXCINTLVL0_bp 2
#define USART_TXCINTLVL1_bm (1<<3)
#define USART_TXCINTLVL1_bp 3
#define USART_RXCINTLVL_gm 0x30
#define USART_RXCINTLVL_gp 4
#define USART_RXCINTLVL0_bm (1<<4)
#define USART_RXCINTLVL0_bp 4
#define USART_RXCINTLVL1_bm (1<<5)
#define USART_RXCINTLVL1_bp 5
#define USART_TXB8_bm 0x01
#define USART_TXB8_bp 0
#define USART_MPCM_bm 0x02
#define USART_MPCM_bp 1
#define USART_CLK2X_bm 0x04
#define USART_CLK2X_bp 2
#define USART_TXEN_bm 0x08
#define USART_TXEN_bp 3
#define USART_RXEN_bm 0x10
#define USART_RXEN_bp 4
#define USART_CHSIZE_gm 0x07
#define USART_CHSIZE_gp 0
#define USART_CHSIZE0_bm (1<<0)
#define USART_CHSIZE0_bp 0
#define USART_CHSIZE1_bm (1<<1)
#define USART_CHSIZE1_bp 1
#define USART_CHSIZE2_bm (1<<2)
#define USART_CHSIZE2_bp 2
#define USART_SBMODE_bm 0x08
#define USART_SBMODE_bp 3
#define USART_PMODE_gm 0x30
#define USART_PMODE_gp 4
#define USART_PMODE0_bm (1<<4)
#define USART_PMODE0_bp 4
#define USART_PMODE1_bm (1<<5)
#define USART_PMODE1_bp 5
#define USART_CMODE_gm 0xC0
#define USART_CMODE_gp 6
#define USART_CMODE0_bm (1<<6)
#define USART_CMODE0_bp 6
#define USART_CMODE1_bm (1<<7)
#define USART_CMODE1_bp 7
#define USART_BSEL_gm 0xFF
#define USART_BSEL_gp 0
#define USART_BSEL0_bm (1<<0)
#define USART_BSEL0_bp 0
#define USART_BSEL1_bm (1<<1)
#define USART_BSEL1_bp 1
#define USART_BSEL2_bm (1<<2)
#define USART_BSEL2_bp 2
#define USART_BSEL3_bm (1<<3)
#define USART_BSEL3_bp 3
#define USART_BSEL4_bm (1<<4)
#define USART_BSEL4_bp 4
#define USART_BSEL5_bm (1<<5)
#define USART_BSEL5_bp 5
#define USART_BSEL6_bm (1<<6)
#define USART_BSEL6_bp 6
#define USART_BSEL7_bm (1<<7)
#define USART_BSEL7_bp 7
#define USART_BSCALE_gm 0xF0
#define USART_BSCALE_gp 4
#define USART_BSCALE0_bm (1<<4)
#define USART_BSCALE0_bp 4
#define USART_BSCALE1_bm (1<<5)
#define USART_BSCALE1_bp 5
#define USART_BSCALE2_bm (1<<6)
#define USART_BSCALE2_bp 6
#define USART_BSCALE3_bm (1<<7)
#define USART_BSCALE3_bp 7
#define USB_EP_TOGGLE_bm 0x01
#define USB_EP_TOGGLE_bp 0
#define USB_EP_BUSNACK0_bm 0x02
#define USB_EP_BUSNACK0_bp 1
#define USB_EP_BUSNACK1_bm 0x04
#define USB_EP_BUSNACK1_bp 2
#define USB_EP_BANK_bm 0x08
#define USB_EP_BANK_bp 3
#define USB_EP_TRNCOMPL1_bm 0x10
#define USB_EP_TRNCOMPL1_bp 4
#define USB_EP_SETUP_bm 0x10
#define USB_EP_SETUP_bp 4
#define USB_EP_TRNCOMPL0_bm 0x20
#define USB_EP_TRNCOMPL0_bp 5
#define USB_EP_UNF_bm 0x40
#define USB_EP_UNF_bp 6
#define USB_EP_OVF_bm 0x40
#define USB_EP_OVF_bp 6
#define USB_EP_STALLF_bm 0x80
#define USB_EP_STALLF_bp 7
#define USB_EP_CRC_bm 0x80
#define USB_EP_CRC_bp 7
#define USB_EP_STALL_bm 0x04
#define USB_EP_STALL_bp 2
#define USB_EP_BUFSIZE_gm 0x07
#define USB_EP_BUFSIZE_gp 0
#define USB_EP_BUFSIZE0_bm (1<<0)
#define USB_EP_BUFSIZE0_bp 0
#define USB_EP_BUFSIZE1_bm (1<<1)
#define USB_EP_BUFSIZE1_bp 1
#define USB_EP_BUFSIZE2_bm (1<<2)
#define USB_EP_BUFSIZE2_bp 2
#define USB_EP_INTDSBL_bm 0x08
#define USB_EP_INTDSBL_bp 3
#define USB_EP_PINGPONG_bm 0x10
#define USB_EP_PINGPONG_bp 4
#define USB_EP_MULTIPKT_bm 0x20
#define USB_EP_MULTIPKT_bp 5
#define USB_EP_TYPE_gm 0xC0
#define USB_EP_TYPE_gp 6
#define USB_EP_TYPE0_bm (1<<6)
#define USB_EP_TYPE0_bp 6
#define USB_EP_TYPE1_bm (1<<7)
#define USB_EP_TYPE1_bp 7
#define USB_EP_ZLP_bm 0x8000
#define USB_EP_ZLP_bp 15
#define USB_MAXEP_gm 0x0F
#define USB_MAXEP_gp 0
#define USB_MAXEP0_bm (1<<0)
#define USB_MAXEP0_bp 0
#define USB_MAXEP1_bm (1<<1)
#define USB_MAXEP1_bp 1
#define USB_MAXEP2_bm (1<<2)
#define USB_MAXEP2_bp 2
#define USB_MAXEP3_bm (1<<3)
#define USB_MAXEP3_bp 3
#define USB_STFRNUM_bm 0x10
#define USB_STFRNUM_bp 4
#define USB_FIFOEN_bm 0x20
#define USB_FIFOEN_bp 5
#define USB_SPEED_bm 0x40
#define USB_SPEED_bp 6
#define USB_ENABLE_bm 0x80
#define USB_ENABLE_bp 7
#define USB_ATTACH_bm 0x01
#define USB_ATTACH_bp 0
#define USB_GNACK_bm 0x02
#define USB_GNACK_bp 1
#define USB_RWAKEUP_bm 0x04
#define USB_RWAKEUP_bp 2
#define USB_PULLRST_bm 0x10
#define USB_PULLRST_bp 4
#define USB_BUSRST_bm 0x01
#define USB_BUSRST_bp 0
#define USB_SUSPEND_bm 0x02
#define USB_SUSPEND_bp 1
#define USB_RESUME_bm 0x04
#define USB_RESUME_bp 2
#define USB_URESUME_bm 0x08
#define USB_URESUME_bp 3
#define USB_ADDR_gm 0x7F
#define USB_ADDR_gp 0
#define USB_ADDR0_bm (1<<0)
#define USB_ADDR0_bp 0
#define USB_ADDR1_bm (1<<1)
#define USB_ADDR1_bp 1
#define USB_ADDR2_bm (1<<2)
#define USB_ADDR2_bp 2
#define USB_ADDR3_bm (1<<3)
#define USB_ADDR3_bp 3
#define USB_ADDR4_bm (1<<4)
#define USB_ADDR4_bp 4
#define USB_ADDR5_bm (1<<5)
#define USB_ADDR5_bp 5
#define USB_ADDR6_bm (1<<6)
#define USB_ADDR6_bp 6
#define USB_FIFOWP_gm 0x1F
#define USB_FIFOWP_gp 0
#define USB_FIFOWP0_bm (1<<0)
#define USB_FIFOWP0_bp 0
#define USB_FIFOWP1_bm (1<<1)
#define USB_FIFOWP1_bp 1
#define USB_FIFOWP2_bm (1<<2)
#define USB_FIFOWP2_bp 2
#define USB_FIFOWP3_bm (1<<3)
#define USB_FIFOWP3_bp 3
#define USB_FIFOWP4_bm (1<<4)
#define USB_FIFOWP4_bp 4
#define USB_FIFORP_gm 0x1F
#define USB_FIFORP_gp 0
#define USB_FIFORP0_bm (1<<0)
#define USB_FIFORP0_bp 0
#define USB_FIFORP1_bm (1<<1)
#define USB_FIFORP1_bp 1
#define USB_FIFORP2_bm (1<<2)
#define USB_FIFORP2_bp 2
#define USB_FIFORP3_bm (1<<3)
#define USB_FIFORP3_bp 3
#define USB_FIFORP4_bm (1<<4)
#define USB_FIFORP4_bp 4
#define USB_INTLVL_gm 0x03
#define USB_INTLVL_gp 0
#define USB_INTLVL0_bm (1<<0)
#define USB_INTLVL0_bp 0
#define USB_INTLVL1_bm (1<<1)
#define USB_INTLVL1_bp 1
#define USB_STALLIE_bm 0x10
#define USB_STALLIE_bp 4
#define USB_BUSERRIE_bm 0x20
#define USB_BUSERRIE_bp 5
#define USB_BUSEVIE_bm 0x40
#define USB_BUSEVIE_bp 6
#define USB_SOFIE_bm 0x80
#define USB_SOFIE_bp 7
#define USB_SETUPIE_bm 0x01
#define USB_SETUPIE_bp 0
#define USB_TRNIE_bm 0x02
#define USB_TRNIE_bp 1
#define USB_STALLIF_bm 0x01
#define USB_STALLIF_bp 0
#define USB_OVFIF_bm 0x02
#define USB_OVFIF_bp 1
#define USB_UNFIF_bm 0x04
#define USB_UNFIF_bp 2
#define USB_CRCIF_bm 0x08
#define USB_CRCIF_bp 3
#define USB_RSTIF_bm 0x10
#define USB_RSTIF_bp 4
#define USB_RESUMEIF_bm 0x20
#define USB_RESUMEIF_bp 5
#define USB_SUSPENDIF_bm 0x40
#define USB_SUSPENDIF_bp 6
#define USB_SOFIF_bm 0x80
#define USB_SOFIF_bp 7
#define USB_SETUPIF_bm 0x01
#define USB_SETUPIF_bp 0
#define USB_TRNIF_bm 0x02
#define USB_TRNIF_bp 1
#define VPORT_INT0IF_bm 0x01
#define VPORT_INT0IF_bp 0
#define VPORT_INT1IF_bm 0x02
#define VPORT_INT1IF_bp 1
#define WDT_CEN_bm 0x01
#define WDT_CEN_bp 0
#define WDT_ENABLE_bm 0x02
#define WDT_ENABLE_bp 1
#define WDT_PER_gm 0x3C
#define WDT_PER_gp 2
#define WDT_PER0_bm (1<<2)
#define WDT_PER0_bp 2
#define WDT_PER1_bm (1<<3)
#define WDT_PER1_bp 3
#define WDT_PER2_bm (1<<4)
#define WDT_PER2_bp 4
#define WDT_PER3_bm (1<<5)
#define WDT_PER3_bp 5
#define WDT_WCEN_bm 0x01
#define WDT_WCEN_bp 0
#define WDT_WEN_bm 0x02
#define WDT_WEN_bp 1
#define WDT_WPER_gm 0x3C
#define WDT_WPER_gp 2
#define WDT_WPER0_bm (1<<2)
#define WDT_WPER0_bp 2
#define WDT_WPER1_bm (1<<3)
#define WDT_WPER1_bp 3
#define WDT_WPER2_bm (1<<4)
#define WDT_WPER2_bp 4
#define WDT_WPER3_bm (1<<5)
#define WDT_WPER3_bp 5
#define WDT_SYNCBUSY_bm 0x01
#define WDT_SYNCBUSY_bp 0
#define OCD_OCDRD_gm 0xFF
#define OCD_OCDRD_gp 0
#define OCD_OCDRD0_bm (1<<0)
#define OCD_OCDRD0_bp 0
#define OCD_OCDRD1_bm (1<<1)
#define OCD_OCDRD1_bp 1
#define OCD_OCDRD2_bm (1<<2)
#define OCD_OCDRD2_bp 2
#define OCD_OCDRD3_bm (1<<3)
#define OCD_OCDRD3_bp 3
#define OCD_OCDRD4_bm (1<<4)
#define OCD_OCDRD4_bp 4
#define OCD_OCDRD5_bm (1<<5)
#define OCD_OCDRD5_bp 5
#define OCD_OCDRD6_bm (1<<6)
#define OCD_OCDRD6_bp 6
#define OCD_OCDRD7_bm (1<<7)
#define OCD_OCDRD7_bp 7
#define PIN0_bm 0x01
#define PIN0_bp 0
#define PIN1_bm 0x02
#define PIN1_bp 1
#define PIN2_bm 0x04
#define PIN2_bp 2
#define PIN3_bm 0x08
#define PIN3_bp 3
#define PIN4_bm 0x10
#define PIN4_bp 4
#define PIN5_bm 0x20
#define PIN5_bp 5
#define PIN6_bm 0x40
#define PIN6_bp 6
#define PIN7_bm 0x80
#define PIN7_bp 7
#define OSC_OSCF_vect_num 1
#define OSC_OSCF_vect _VECTOR(1)
#define PORTC_INT0_vect_num 2
#define PORTC_INT0_vect _VECTOR(2)
#define PORTC_INT1_vect_num 3
#define PORTC_INT1_vect _VECTOR(3)
#define PORTR_INT0_vect_num 4
#define PORTR_INT0_vect _VECTOR(4)
#define PORTR_INT1_vect_num 5
#define PORTR_INT1_vect _VECTOR(5)
#define DMA_CH0_vect_num 6
#define DMA_CH0_vect _VECTOR(6)
#define DMA_CH1_vect_num 7
#define DMA_CH1_vect _VECTOR(7)
#define RTC_OVF_vect_num 10
#define RTC_OVF_vect _VECTOR(10)
#define RTC_COMP_vect_num 11
#define RTC_COMP_vect _VECTOR(11)
#define TWIC_TWIS_vect_num 12
#define TWIC_TWIS_vect _VECTOR(12)
#define TWIC_TWIM_vect_num 13
#define TWIC_TWIM_vect _VECTOR(13)
#define TCC0_OVF_vect_num 14
#define TCC0_OVF_vect _VECTOR(14)
#define TCC2_LUNF_vect_num 14
#define TCC2_LUNF_vect _VECTOR(14)
#define TCC0_ERR_vect_num 15
#define TCC0_ERR_vect _VECTOR(15)
#define TCC2_HUNF_vect_num 15
#define TCC2_HUNF_vect _VECTOR(15)
#define TCC0_CCA_vect_num 16
#define TCC0_CCA_vect _VECTOR(16)
#define TCC2_LCMPA_vect_num 16
#define TCC2_LCMPA_vect _VECTOR(16)
#define TCC0_CCB_vect_num 17
#define TCC0_CCB_vect _VECTOR(17)
#define TCC2_LCMPB_vect_num 17
#define TCC2_LCMPB_vect _VECTOR(17)
#define TCC0_CCC_vect_num 18
#define TCC0_CCC_vect _VECTOR(18)
#define TCC2_LCMPC_vect_num 18
#define TCC2_LCMPC_vect _VECTOR(18)
#define TCC0_CCD_vect_num 19
#define TCC0_CCD_vect _VECTOR(19)
#define TCC2_LCMPD_vect_num 19
#define TCC2_LCMPD_vect _VECTOR(19)
#define TCC1_OVF_vect_num 20
#define TCC1_OVF_vect _VECTOR(20)
#define TCC1_ERR_vect_num 21
#define TCC1_ERR_vect _VECTOR(21)
#define TCC1_CCA_vect_num 22
#define TCC1_CCA_vect _VECTOR(22)
#define TCC1_CCB_vect_num 23
#define TCC1_CCB_vect _VECTOR(23)
#define SPIC_INT_vect_num 24
#define SPIC_INT_vect _VECTOR(24)
#define USARTC0_RXC_vect_num 25
#define USARTC0_RXC_vect _VECTOR(25)
#define USARTC0_DRE_vect_num 26
#define USARTC0_DRE_vect _VECTOR(26)
#define USARTC0_TXC_vect_num 27
#define USARTC0_TXC_vect _VECTOR(27)
#define USB_BUSEVENT_vect_num 31
#define USB_BUSEVENT_vect _VECTOR(31)
#define USB_TRNCOMPL_vect_num 32
#define USB_TRNCOMPL_vect _VECTOR(32)
#define LCD_INT_vect_num 35
#define LCD_INT_vect _VECTOR(35)
#define AES_INT_vect_num 36
#define AES_INT_vect _VECTOR(36)
#define NVM_EE_vect_num 37
#define NVM_EE_vect _VECTOR(37)
#define NVM_SPM_vect_num 38
#define NVM_SPM_vect _VECTOR(38)
#define PORTB_INT0_vect_num 39
#define PORTB_INT0_vect _VECTOR(39)
#define PORTB_INT1_vect_num 40
#define PORTB_INT1_vect _VECTOR(40)
#define ACB_AC0_vect_num 41
#define ACB_AC0_vect _VECTOR(41)
#define ACB_AC1_vect_num 42
#define ACB_AC1_vect _VECTOR(42)
#define ACB_ACW_vect_num 43
#define ACB_ACW_vect _VECTOR(43)
#define ADCB_CH0_vect_num 44
#define ADCB_CH0_vect _VECTOR(44)
#define PORTD_INT0_vect_num 48
#define PORTD_INT0_vect _VECTOR(48)
#define PORTD_INT1_vect_num 49
#define PORTD_INT1_vect _VECTOR(49)
#define PORTG_INT0_vect_num 50
#define PORTG_INT0_vect _VECTOR(50)
#define PORTG_INT1_vect_num 51
#define PORTG_INT1_vect _VECTOR(51)
#define PORTM_INT0_vect_num 52
#define PORTM_INT0_vect _VECTOR(52)
#define PORTM_INT1_vect_num 53
#define PORTM_INT1_vect _VECTOR(53)
#define _VECTOR_SIZE 4
#define _VECTORS_SIZE (54 * _VECTOR_SIZE)
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
# define PROGMEM_START (0x0000)
# define PROGMEM_SIZE (139264)
#else
# define PROGMEM_START (0x0000U)
# define PROGMEM_SIZE (139264U)
#endif
#define PROGMEM_END (PROGMEM_START + PROGMEM_SIZE - 1)
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
# define APP_SECTION_START (0x0000)
# define APP_SECTION_SIZE (131072)
# define APP_SECTION_PAGE_SIZE (256)
#else
# define APP_SECTION_START (0x0000U)
# define APP_SECTION_SIZE (131072U)
# define APP_SECTION_PAGE_SIZE (256U)
#endif
#define APP_SECTION_END (APP_SECTION_START + APP_SECTION_SIZE - 1)
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
# define APPTABLE_SECTION_START (0x1E000)
# define APPTABLE_SECTION_SIZE (8192)
# define APPTABLE_SECTION_PAGE_SIZE (256)
#else
# define APPTABLE_SECTION_START (0x1E000U)
# define APPTABLE_SECTION_SIZE (8192U)
# define APPTABLE_SECTION_PAGE_SIZE (256U)
#endif
#define APPTABLE_SECTION_END (APPTABLE_SECTION_START + APPTABLE_SECTION_SIZE - 1)
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
# define BOOT_SECTION_START (0x20000)
# define BOOT_SECTION_SIZE (8192)
# define BOOT_SECTION_PAGE_SIZE (256)
#else
# define BOOT_SECTION_START (0x20000U)
# define BOOT_SECTION_SIZE (8192U)
# define BOOT_SECTION_PAGE_SIZE (256U)
#endif
#define BOOT_SECTION_END (BOOT_SECTION_START + BOOT_SECTION_SIZE - 1)
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
# define DATAMEM_START (0x0000)
# define DATAMEM_SIZE (16384)
#else
# define DATAMEM_START (0x0000U)
# define DATAMEM_SIZE (16384U)
#endif
#define DATAMEM_END (DATAMEM_START + DATAMEM_SIZE - 1)
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
# define IO_START (0x0000)
# define IO_SIZE (4096)
# define IO_PAGE_SIZE (0)
#else
# define IO_START (0x0000U)
# define IO_SIZE (4096U)
# define IO_PAGE_SIZE (0U)
#endif
#define IO_END (IO_START + IO_SIZE - 1)
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
# define MAPPED_EEPROM_START (0x1000)
# define MAPPED_EEPROM_SIZE (2048)
# define MAPPED_EEPROM_PAGE_SIZE (0)
#else
# define MAPPED_EEPROM_START (0x1000U)
# define MAPPED_EEPROM_SIZE (2048U)
# define MAPPED_EEPROM_PAGE_SIZE (0U)
#endif
#define MAPPED_EEPROM_END (MAPPED_EEPROM_START + MAPPED_EEPROM_SIZE - 1)
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
# define INTERNAL_SRAM_START (0x2000)
# define INTERNAL_SRAM_SIZE (8192)
# define INTERNAL_SRAM_PAGE_SIZE (0)
#else
# define INTERNAL_SRAM_START (0x2000U)
# define INTERNAL_SRAM_SIZE (8192U)
# define INTERNAL_SRAM_PAGE_SIZE (0U)
#endif
#define INTERNAL_SRAM_END (INTERNAL_SRAM_START + INTERNAL_SRAM_SIZE - 1)
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
# define EEPROM_START (0x0000)
# define EEPROM_SIZE (2048)
# define EEPROM_PAGE_SIZE (32)
#else
# define EEPROM_START (0x0000U)
# define EEPROM_SIZE (2048U)
# define EEPROM_PAGE_SIZE (32U)
#endif
#define EEPROM_END (EEPROM_START + EEPROM_SIZE - 1)
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
# define SIGNATURES_START (0x0000)
# define SIGNATURES_SIZE (3)
# define SIGNATURES_PAGE_SIZE (0)
#else
# define SIGNATURES_START (0x0000U)
# define SIGNATURES_SIZE (3U)
# define SIGNATURES_PAGE_SIZE (0U)
#endif
#define SIGNATURES_END (SIGNATURES_START + SIGNATURES_SIZE - 1)
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
# define FUSES_START (0x0000)
# define FUSES_SIZE (6)
# define FUSES_PAGE_SIZE (0)
#else
# define FUSES_START (0x0000U)
# define FUSES_SIZE (6U)
# define FUSES_PAGE_SIZE (0U)
#endif
#define FUSES_END (FUSES_START + FUSES_SIZE - 1)
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
# define LOCKBITS_START (0x0000)
# define LOCKBITS_SIZE (1)
# define LOCKBITS_PAGE_SIZE (0)
#else
# define LOCKBITS_START (0x0000U)
# define LOCKBITS_SIZE (1U)
# define LOCKBITS_PAGE_SIZE (0U)
#endif
#define LOCKBITS_END (LOCKBITS_START + LOCKBITS_SIZE - 1)
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
# define USER_SIGNATURES_START (0x0000)
# define USER_SIGNATURES_SIZE (256)
# define USER_SIGNATURES_PAGE_SIZE (256)
#else
# define USER_SIGNATURES_START (0x0000U)
# define USER_SIGNATURES_SIZE (256U)
# define USER_SIGNATURES_PAGE_SIZE (256U)
#endif
#define USER_SIGNATURES_END (USER_SIGNATURES_START + USER_SIGNATURES_SIZE - 1)
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
# define PROD_SIGNATURES_START (0x0000)
# define PROD_SIGNATURES_SIZE (52)
# define PROD_SIGNATURES_PAGE_SIZE (256)
#else
# define PROD_SIGNATURES_START (0x0000U)
# define PROD_SIGNATURES_SIZE (52U)
# define PROD_SIGNATURES_PAGE_SIZE (256U)
#endif
#define PROD_SIGNATURES_END (PROD_SIGNATURES_START + PROD_SIGNATURES_SIZE - 1)
#define FLASHSTART PROGMEM_START
#define FLASHEND PROGMEM_END
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
# define SPM_PAGESIZE 256
#else
# define SPM_PAGESIZE 256U
#endif
#define RAMSTART INTERNAL_SRAM_START
#define RAMSIZE INTERNAL_SRAM_SIZE
#define RAMEND INTERNAL_SRAM_END
#define E2END EEPROM_END
#define E2PAGESIZE EEPROM_PAGE_SIZE
#define FUSE_MEMORY_SIZE 6
#define FUSE_JTAGUSERID0 (unsigned char)~_BV(0)
#define FUSE_JTAGUSERID1 (unsigned char)~_BV(1)
#define FUSE_JTAGUSERID2 (unsigned char)~_BV(2)
#define FUSE_JTAGUSERID3 (unsigned char)~_BV(3)
#define FUSE_JTAGUSERID4 (unsigned char)~_BV(4)
#define FUSE_JTAGUSERID5 (unsigned char)~_BV(5)
#define FUSE_JTAGUSERID6 (unsigned char)~_BV(6)
#define FUSE_JTAGUSERID7 (unsigned char)~_BV(7)
#define FUSE0_DEFAULT (0xff)
#define FUSE_FUSEBYTE0_DEFAULT (0xff)
#define FUSE_WDPER0 (unsigned char)~_BV(0)
#define FUSE_WDPER1 (unsigned char)~_BV(1)
#define FUSE_WDPER2 (unsigned char)~_BV(2)
#define FUSE_WDPER3 (unsigned char)~_BV(3)
#define FUSE_WDWPER0 (unsigned char)~_BV(4)
#define FUSE_WDWPER1 (unsigned char)~_BV(5)
#define FUSE_WDWPER2 (unsigned char)~_BV(6)
#define FUSE_WDWPER3 (unsigned char)~_BV(7)
#define FUSE1_DEFAULT (0x0)
#define FUSE_FUSEBYTE1_DEFAULT (0x0)
#define FUSE_BODPD0 (unsigned char)~_BV(0)
#define FUSE_BODPD1 (unsigned char)~_BV(1)
#define FUSE_TOSCSEL (unsigned char)~_BV(5)
#define FUSE_BOOTRST (unsigned char)~_BV(6)
#define FUSE2_DEFAULT (0xff)
#define FUSE_FUSEBYTE2_DEFAULT (0xff)
#define FUSE_JTAGEN (unsigned char)~_BV(0)
#define FUSE_WDLOCK (unsigned char)~_BV(1)
#define FUSE_STARTUPTIME0 (unsigned char)~_BV(2)
#define FUSE_STARTUPTIME1 (unsigned char)~_BV(3)
#define FUSE_RSTDISBL (unsigned char)~_BV(4)
#define FUSE4_DEFAULT (0xff)
#define FUSE_FUSEBYTE4_DEFAULT (0xff)
#define FUSE_BODLEVEL0 (unsigned char)~_BV(0)
#define FUSE_BODLEVEL1 (unsigned char)~_BV(1)
#define FUSE_BODLEVEL2 (unsigned char)~_BV(2)
#define FUSE_EESAVE (unsigned char)~_BV(3)
#define FUSE_BODACT0 (unsigned char)~_BV(4)
#define FUSE_BODACT1 (unsigned char)~_BV(5)
#define FUSE5_DEFAULT (0xff)
#define FUSE_FUSEBYTE5_DEFAULT (0xff)
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_APPLICATION_TABLE_BITS_EXIST
#define __BOOT_LOCK_APPLICATION_BITS_EXIST
#define __BOOT_LOCK_BOOT_BITS_EXIST
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x97
#define SIGNATURE_2 0x4B
#define __AVR_HAVE_PRGEN (PR_LCD_bm|PR_USB_bm|PR_AES_bm|PR_RTC_bm|PR_EVSYS_bm|PR_DMA_bm)
#define __AVR_HAVE_PRGEN_LCD
#define __AVR_HAVE_PRGEN_USB
#define __AVR_HAVE_PRGEN_AES
#define __AVR_HAVE_PRGEN_RTC
#define __AVR_HAVE_PRGEN_EVSYS
#define __AVR_HAVE_PRGEN_DMA
#define __AVR_HAVE_PRPA (PR_ADC_bm|PR_AC_bm)
#define __AVR_HAVE_PRPA_ADC
#define __AVR_HAVE_PRPA_AC
#define __AVR_HAVE_PRPB (PR_ADC_bm|PR_AC_bm)
#define __AVR_HAVE_PRPB_ADC
#define __AVR_HAVE_PRPB_AC
#define __AVR_HAVE_PRPC (PR_TWI_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC1_bm|PR_TC0_bm)
#define __AVR_HAVE_PRPC_TWI
#define __AVR_HAVE_PRPC_USART0
#define __AVR_HAVE_PRPC_SPI
#define __AVR_HAVE_PRPC_HIRES
#define __AVR_HAVE_PRPC_TC1
#define __AVR_HAVE_PRPC_TC0
#define __AVR_HAVE_PRPE (PR_USART0_bm|PR_TC0_bm)
#define __AVR_HAVE_PRPE_USART0
#define __AVR_HAVE_PRPE_TC0
#endif
