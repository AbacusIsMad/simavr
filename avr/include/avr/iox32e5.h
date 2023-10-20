#ifndef _AVR_IO_H_
# error "Include <avr/io.h> instead of this file."
#endif
#ifndef _AVR_IOXXX_H_
# define _AVR_IOXXX_H_ "iox32e5.h"
#else
# error "Attempt to include more than one <avr/ioXXX.h> file."
#endif
#ifndef _AVR_ATXMEGA32E5_H_INCLUDED
#define _AVR_ATXMEGA32E5_H_INCLUDED
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
    AC_MUXNEG_DAC_gc = (0x05<<0),
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
    AC_MUXPOS_DAC_gc = (0x07<<3),
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
    register8_t CORRCTRL;
    register8_t OFFSETCORR0;
    register8_t OFFSETCORR1;
    register8_t GAINCORR0;
    register8_t GAINCORR1;
    register8_t AVGCTRL;
    register8_t reserved_1[3];
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
    register8_t CAL;
    register8_t reserved_3[3];
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
    ADC_CH_INPUTMODE_DIFFWGAINL_gc = (0x02<<0),
    ADC_CH_INPUTMODE_DIFFWGAINH_gc = (0x03<<0),
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
    ADC_CH_MUXINT_DAC_gc = (0x03<<3),
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
typedef enum ADC_CH_SAMPNUM_enum
{
    ADC_CH_SAMPNUM_1X_gc = (0x00<<0),
    ADC_CH_SAMPNUM_2X_gc = (0x01<<0),
    ADC_CH_SAMPNUM_4X_gc = (0x02<<0),
    ADC_CH_SAMPNUM_8X_gc = (0x03<<0),
    ADC_CH_SAMPNUM_16X_gc = (0x04<<0),
    ADC_CH_SAMPNUM_32X_gc = (0x05<<0),
    ADC_CH_SAMPNUM_64X_gc = (0x06<<0),
    ADC_CH_SAMPNUM_128X_gc = (0x07<<0),
    ADC_CH_SAMPNUM_256X_gc = (0x08<<0),
    ADC_CH_SAMPNUM_512X_gc = (0x09<<0),
    ADC_CH_SAMPNUM_1024X_gc = (0x0A<<0),
} ADC_CH_SAMPNUM_t;
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
    ADC_EVSEL_4_gc = (0x04<<3),
    ADC_EVSEL_5_gc = (0x05<<3),
    ADC_EVSEL_6_gc = (0x06<<3),
    ADC_EVSEL_7_gc = (0x07<<3),
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
    ADC_REFSEL_AREFD_gc = (0x03<<4),
    ADC_REFSEL_INTVCC2_gc = (0x04<<4),
} ADC_REFSEL_t;
typedef enum ADC_RESOLUTION_enum
{
    ADC_RESOLUTION_12BIT_gc = (0x00<<1),
    ADC_RESOLUTION_MT12BIT_gc = (0x01<<1),
    ADC_RESOLUTION_8BIT_gc = (0x02<<1),
    ADC_RESOLUTION_LEFT12BIT_gc = (0x03<<1),
} ADC_RESOLUTION_t;
typedef struct CLK_struct
{
    register8_t CTRL;
    register8_t PSCTRL;
    register8_t LOCK;
    register8_t RTCCTRL;
    register8_t reserved_1[1];
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
    CLK_PSADIV_6_gc = (0x13<<2),
    CLK_PSADIV_10_gc = (0x15<<2),
    CLK_PSADIV_12_gc = (0x17<<2),
    CLK_PSADIV_24_gc = (0x19<<2),
    CLK_PSADIV_48_gc = (0x1B<<2),
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
    CLK_SCLKSEL_RC8M_gc = (0x05<<0),
} CLK_SCLKSEL_t;
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
    CRC_SOURCE_DMAC2_gc = (0x06<<0),
    CRC_SOURCE_DMAC3_gc = (0x07<<0),
} CRC_SOURCE_t;
typedef struct DAC_struct
{
    register8_t CTRLA;
    register8_t CTRLB;
    register8_t CTRLC;
    register8_t EVCTRL;
    register8_t reserved_1[1];
    register8_t STATUS;
    register8_t reserved_2[2];
    register8_t CH0GAINCAL;
    register8_t CH0OFFSETCAL;
    register8_t CH1GAINCAL;
    register8_t CH1OFFSETCAL;
    register8_t reserved_3[12];
    _WORDREGISTER(CH0DATA);
    _WORDREGISTER(CH1DATA);
} DAC_t;
typedef enum DAC_CHSEL_enum
{
    DAC_CHSEL_SINGLE_gc = (0x00<<5),
    DAC_CHSEL_SINGLE1_gc = (0x01<<5),
    DAC_CHSEL_DUAL_gc = (0x02<<5),
} DAC_CHSEL_t;
typedef enum DAC_EVSEL_enum
{
    DAC_EVSEL_0_gc = (0x00<<0),
    DAC_EVSEL_1_gc = (0x01<<0),
    DAC_EVSEL_2_gc = (0x02<<0),
    DAC_EVSEL_3_gc = (0x03<<0),
    DAC_EVSEL_4_gc = (0x04<<0),
    DAC_EVSEL_5_gc = (0x05<<0),
    DAC_EVSEL_6_gc = (0x06<<0),
    DAC_EVSEL_7_gc = (0x07<<0),
} DAC_EVSEL_t;
typedef enum DAC_REFSEL_enum
{
    DAC_REFSEL_INT1V_gc = (0x00<<3),
    DAC_REFSEL_AVCC_gc = (0x01<<3),
    DAC_REFSEL_AREFA_gc = (0x02<<3),
    DAC_REFSEL_AREFD_gc = (0x03<<3),
    DAC_REFSEL_AREFB_gc = (0x03<<3),
} DAC_REFSEL_t;
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
typedef struct EDMA_CH_struct
{
    register8_t CTRLA;
    register8_t CTRLB;
    register8_t ADDRCTRL;
    register8_t DESTADDRCTRL;
    register8_t TRIGSRC;
    register8_t reserved_1[1];
    _WORDREGISTER(TRFCNT);
    _WORDREGISTER(ADDR);
    register8_t reserved_2[2];
    _WORDREGISTER(DESTADDR);
    register8_t reserved_3[2];
} EDMA_CH_t;
typedef struct EDMA_struct
{
    register8_t CTRL;
    register8_t reserved_1[2];
    register8_t INTFLAGS;
    register8_t STATUS;
    register8_t reserved_2[1];
    register8_t TEMP;
    register8_t reserved_3[9];
    EDMA_CH_t CH0;
    EDMA_CH_t CH1;
    EDMA_CH_t CH2;
    EDMA_CH_t CH3;
} EDMA_t;
typedef enum EDMA_CHMODE_enum
{
    EDMA_CHMODE_PER0123_gc = (0x00<<4),
    EDMA_CHMODE_STD0_gc = (0x01<<4),
    EDMA_CHMODE_STD2_gc = (0x02<<4),
    EDMA_CHMODE_STD02_gc = (0x03<<4),
} EDMA_CHMODE_t;
typedef enum EDMA_DBUFMODE_enum
{
    EDMA_DBUFMODE_DISABLE_gc = (0x00<<2),
    EDMA_DBUFMODE_BUF01_gc = (0x01<<2),
    EDMA_DBUFMODE_BUF23_gc = (0x02<<2),
    EDMA_DBUFMODE_BUF0123_gc = (0x03<<2),
} EDMA_DBUFMODE_t;
typedef enum EDMA_PRIMODE_enum
{
    EDMA_PRIMODE_RR0123_gc = (0x00<<0),
    EDMA_PRIMODE_RR123_gc = (0x01<<0),
    EDMA_PRIMODE_RR23_gc = (0x02<<0),
    EDMA_PRIMODE_CH0123_gc = (0x03<<0),
} EDMA_PRIMODE_t;
typedef enum EDMA_CH_DESTDIR_enum
{
    EDMA_CH_DESTDIR_FIXED_gc = (0x00<<0),
    EDMA_CH_DESTDIR_INC_gc = (0x01<<0),
    EDMA_CH_DESTDIR_MP1_gc = (0x04<<0),
    EDMA_CH_DESTDIR_MP2_gc = (0x05<<0),
    EDMA_CH_DESTDIR_MP3_gc = (0x06<<0),
} EDMA_CH_DESTDIR_t;
typedef enum EDMA_CH_DESTRELOAD_enum
{
    EDMA_CH_DESTRELOAD_NONE_gc = (0x00<<4),
    EDMA_CH_DESTRELOAD_BLOCK_gc = (0x01<<4),
    EDMA_CH_DESTRELOAD_BURST_gc = (0x02<<4),
    EDMA_CH_DESTRELOAD_TRANSACTION_gc = (0x03<<4),
} EDMA_CH_DESTRELOAD_t;
typedef enum EDMA_CH_DIR_enum
{
    EDMA_CH_DIR_FIXED_gc = (0x00<<0),
    EDMA_CH_DIR_INC_gc = (0x01<<0),
    EDMA_CH_DIR_MP1_gc = (0x04<<0),
    EDMA_CH_DIR_MP2_gc = (0x05<<0),
    EDMA_CH_DIR_MP3_gc = (0x06<<0),
} EDMA_CH_DIR_t;
typedef enum EDMA_CH_ERRINTLVL_enum
{
    EDMA_CH_ERRINTLVL_OFF_gc = (0x00<<2),
    EDMA_CH_ERRINTLVL_LO_gc = (0x01<<2),
    EDMA_CH_ERRINTLVL_MED_gc = (0x02<<2),
    EDMA_CH_ERRINTLVL_HI_gc = (0x03<<2),
} EDMA_CH_ERRINTLVL_t;
typedef enum EDMA_CH_RELOAD_enum
{
    EDMA_CH_RELOAD_NONE_gc = (0x00<<4),
    EDMA_CH_RELOAD_BLOCK_gc = (0x01<<4),
    EDMA_CH_RELOAD_BURST_gc = (0x02<<4),
    EDMA_CH_RELOAD_TRANSACTION_gc = (0x03<<4),
} EDMA_CH_RELOAD_t;
typedef enum EDMA_CH_TRIGSRC_enum
{
    EDMA_CH_TRIGSRC_OFF_gc = (0x00<<0),
    EDMA_CH_TRIGSRC_EVSYS_CH0_gc = (0x01<<0),
    EDMA_CH_TRIGSRC_EVSYS_CH1_gc = (0x02<<0),
    EDMA_CH_TRIGSRC_EVSYS_CH2_gc = (0x03<<0),
    EDMA_CH_TRIGSRC_ADCA_CH0_gc = (0x10<<0),
    EDMA_CH_TRIGSRC_DACA_CH0_gc = (0x15<<0),
    EDMA_CH_TRIGSRC_DACA_CH1_gc = (0x16<<0),
    EDMA_CH_TRIGSRC_TCC4_OVF_gc = (0x40<<0),
    EDMA_CH_TRIGSRC_TCC4_ERR_gc = (0x41<<0),
    EDMA_CH_TRIGSRC_TCC4_CCA_gc = (0x42<<0),
    EDMA_CH_TRIGSRC_TCC4_CCB_gc = (0x43<<0),
    EDMA_CH_TRIGSRC_TCC4_CCC_gc = (0x44<<0),
    EDMA_CH_TRIGSRC_TCC4_CCD_gc = (0x45<<0),
    EDMA_CH_TRIGSRC_TCC5_OVF_gc = (0x46<<0),
    EDMA_CH_TRIGSRC_TCC5_ERR_gc = (0x47<<0),
    EDMA_CH_TRIGSRC_TCC5_CCA_gc = (0x48<<0),
    EDMA_CH_TRIGSRC_TCC5_CCB_gc = (0x49<<0),
    EDMA_CH_TRIGSRC_SPIC_RXC_gc = (0x4A<<0),
    EDMA_CH_TRIGSRC_SPIC_DRE_gc = (0x4B<<0),
    EDMA_CH_TRIGSRC_USARTC0_RXC_gc = (0x4C<<0),
    EDMA_CH_TRIGSRC_USARTC0_DRE_gc = (0x4D<<0),
    EDMA_CH_TRIGSRC_TCD5_OVF_gc = (0x66<<0),
    EDMA_CH_TRIGSRC_TCD5_ERR_gc = (0x67<<0),
    EDMA_CH_TRIGSRC_TCD5_CCA_gc = (0x68<<0),
    EDMA_CH_TRIGSRC_TCD5_CCB_gc = (0x69<<0),
    EDMA_CH_TRIGSRC_USARTD0_RXC_gc = (0x6C<<0),
    EDMA_CH_TRIGSRC_USARTD0_DRE_gc = (0x6D<<0),
} EDMA_CH_TRIGSRC_t;
typedef enum EDMA_CH_TRNINTLVL_enum
{
    EDMA_CH_TRNINTLVL_OFF_gc = (0x00<<0),
    EDMA_CH_TRNINTLVL_LO_gc = (0x01<<0),
    EDMA_CH_TRNINTLVL_MED_gc = (0x02<<0),
    EDMA_CH_TRNINTLVL_HI_gc = (0x03<<0),
} EDMA_CH_TRNINTLVL_t;
typedef struct EVSYS_struct
{
    register8_t CH0MUX;
    register8_t CH1MUX;
    register8_t CH2MUX;
    register8_t CH3MUX;
    register8_t CH4MUX;
    register8_t CH5MUX;
    register8_t CH6MUX;
    register8_t CH7MUX;
    register8_t CH0CTRL;
    register8_t CH1CTRL;
    register8_t CH2CTRL;
    register8_t CH3CTRL;
    register8_t CH4CTRL;
    register8_t CH5CTRL;
    register8_t CH6CTRL;
    register8_t CH7CTRL;
    register8_t STROBE;
    register8_t DATA;
    register8_t DFCTRL;
} EVSYS_t;
typedef enum EVSYS_CHMUX_enum
{
    EVSYS_CHMUX_OFF_gc = (0x00<<0),
    EVSYS_CHMUX_RTC_OVF_gc = (0x08<<0),
    EVSYS_CHMUX_RTC_CMP_gc = (0x09<<0),
    EVSYS_CHMUX_ACA_CH0_gc = (0x10<<0),
    EVSYS_CHMUX_ACA_CH1_gc = (0x11<<0),
    EVSYS_CHMUX_ACA_WIN_gc = (0x12<<0),
    EVSYS_CHMUX_ADCA_CH0_gc = (0x20<<0),
    EVSYS_CHMUX_PORTA_PIN0_gc = (0x50<<0),
    EVSYS_CHMUX_PORTA_PIN1_gc = (0x51<<0),
    EVSYS_CHMUX_PORTA_PIN2_gc = (0x52<<0),
    EVSYS_CHMUX_PORTA_PIN3_gc = (0x53<<0),
    EVSYS_CHMUX_PORTA_PIN4_gc = (0x54<<0),
    EVSYS_CHMUX_PORTA_PIN5_gc = (0x55<<0),
    EVSYS_CHMUX_PORTA_PIN6_gc = (0x56<<0),
    EVSYS_CHMUX_PORTA_PIN7_gc = (0x57<<0),
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
    EVSYS_CHMUX_PORTD_PIN3_gc = (0x6B<<0),
    EVSYS_CHMUX_PORTD_PIN4_gc = (0x6C<<0),
    EVSYS_CHMUX_PORTD_PIN5_gc = (0x6D<<0),
    EVSYS_CHMUX_PORTD_PIN6_gc = (0x6E<<0),
    EVSYS_CHMUX_PORTD_PIN7_gc = (0x6F<<0),
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
    EVSYS_CHMUX_XCL_UNF0_gc = (0xB0<<0),
    EVSYS_CHMUX_XCL_UNF1_gc = (0xB1<<0),
    EVSYS_CHMUX_XCL_CC0_gc = (0xB2<<0),
    EVSYS_CHMUX_XCL_CC1_gc = (0xB3<<0),
    EVSYS_CHMUX_XCL_PEC0_gc = (0xB4<<0),
    EVSYS_CHMUX_XCL_PEC1_gc = (0xB5<<0),
    EVSYS_CHMUX_XCL_LUT0_gc = (0xB6<<0),
    EVSYS_CHMUX_XCL_LUT1_gc = (0xB7<<0),
    EVSYS_CHMUX_TCC4_OVF_gc = (0xC0<<0),
    EVSYS_CHMUX_TCC4_ERR_gc = (0xC1<<0),
    EVSYS_CHMUX_TCC4_CCA_gc = (0xC4<<0),
    EVSYS_CHMUX_TCC4_CCB_gc = (0xC5<<0),
    EVSYS_CHMUX_TCC4_CCC_gc = (0xC6<<0),
    EVSYS_CHMUX_TCC4_CCD_gc = (0xC7<<0),
    EVSYS_CHMUX_TCC5_OVF_gc = (0xC8<<0),
    EVSYS_CHMUX_TCC5_ERR_gc = (0xC9<<0),
    EVSYS_CHMUX_TCC5_CCA_gc = (0xCC<<0),
    EVSYS_CHMUX_TCC5_CCB_gc = (0xCD<<0),
    EVSYS_CHMUX_TCD5_OVF_gc = (0xD8<<0),
    EVSYS_CHMUX_TCD5_ERR_gc = (0xD9<<0),
    EVSYS_CHMUX_TCD5_CCA_gc = (0xDC<<0),
    EVSYS_CHMUX_TCD5_CCB_gc = (0xDD<<0),
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
typedef enum EVSYS_PRESC_enum
{
    EVSYS_PRESC_CLKPER_8_gc = (0x00<<0),
    EVSYS_PRESC_CLKPER_64_gc = (0x01<<0),
    EVSYS_PRESC_CLKPER_512_gc = (0x02<<0),
    EVSYS_PRESC_CLKPER_4096_gc = (0x03<<0),
    EVSYS_PRESC_CLKPER_32768_gc = (0x04<<0),
} EVSYS_PRESC_t;
typedef enum EVSYS_PRESCFILT_enum
{
    EVSYS_PRESCFILT_CH04_gc = (0x01<<4),
    EVSYS_PRESCFILT_CH15_gc = (0x02<<4),
    EVSYS_PRESCFILT_CH26_gc = (0x04<<4),
    EVSYS_PRESCFILT_CH37_gc = (0x08<<4),
} EVSYS_PRESCFILT_t;
typedef enum EVSYS_QDIRM_enum
{
    EVSYS_QDIRM_00_gc = (0x00<<5),
    EVSYS_QDIRM_01_gc = (0x01<<5),
    EVSYS_QDIRM_10_gc = (0x02<<5),
    EVSYS_QDIRM_11_gc = (0x03<<5),
} EVSYS_QDIRM_t;
typedef struct FAULT_struct
{
    register8_t CTRLA;
    register8_t CTRLB;
    register8_t CTRLC;
    register8_t CTRLD;
    register8_t CTRLE;
    register8_t STATUS;
    register8_t CTRLGCLR;
    register8_t CTRLGSET;
} FAULT_t;
typedef enum FAULT_HALTA_enum
{
    FAULT_HALTA_DISABLE_gc = (0x00<<5),
    FAULT_HALTA_HW_gc = (0x01<<5),
    FAULT_HALTA_SW_gc = (0x02<<5),
} FAULT_HALTA_t;
typedef enum FAULT_HALTB_enum
{
    FAULT_HALTB_DISABLE_gc = (0x00<<5),
    FAULT_HALTB_HW_gc = (0x01<<5),
    FAULT_HALTB_SW_gc = (0x02<<5),
} FAULT_HALTB_t;
typedef enum FAULT_IDXCMD_enum
{
    FAULT_IDXCMD_DISABLE_gc = (0x00<<3),
    FAULT_IDXCMD_SET_gc = (0x01<<3),
    FAULT_IDXCMD_CLEAR_gc = (0x02<<3),
    FAULT_IDXCMD_HOLD_gc = (0x03<<3),
} FAULT_IDXCMD_t;
typedef enum FAULT_RAMP_enum
{
    FAULT_RAMP_RAMP1_gc = (0x00<<6),
    FAULT_RAMP_RAMP2_gc = (0x02<<6),
} FAULT_RAMP_t;
typedef enum FAULT_SRCA_enum
{
    FAULT_SRCA_DISABLE_gc = (0x00<<0),
    FAULT_SRCA_CHN_gc = (0x01<<0),
    FAULT_SRCA_CHN1_gc = (0x02<<0),
    FAULT_SRCA_LINK_gc = (0x03<<0),
} FAULT_SRCA_t;
typedef enum FAULT_SRCB_enum
{
    FAULT_SRCB_DISABLE_gc = (0x00<<0),
    FAULT_SRCB_CHN_gc = (0x01<<0),
    FAULT_SRCB_CHN1_gc = (0x02<<0),
    FAULT_SRCB_LINK_gc = (0x03<<0),
} FAULT_SRCB_t;
typedef enum FAULT_SRCE_enum
{
    FAULT_SRCE_DISABLE_gc = (0x00<<0),
    FAULT_SRCE_CHN_gc = (0x01<<0),
    FAULT_SRCE_CHN1_gc = (0x02<<0),
    FAULT_SRCE_CHN2_gc = (0x03<<0),
} FAULT_SRCE_t;
typedef struct NVM_LOCKBITS_struct
{
    register8_t LOCK_BITS;
} NVM_LOCKBITS_t;
typedef struct NVM_FUSES_struct
{
    register8_t reserved_1[1];
    register8_t FUSEBYTE1;
    register8_t FUSEBYTE2;
    register8_t reserved_2[1];
    register8_t FUSEBYTE4;
    register8_t FUSEBYTE5;
    register8_t FUSEBYTE6;
} NVM_FUSES_t;
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
    HIRES_HREN_HRP4_gc = (0x01<<0),
    HIRES_HREN_HRP5_gc = (0x02<<0),
    HIRES_HREN_BOTH_gc = (0x03<<0),
} HIRES_HREN_t;
typedef enum HIRES_HRPLUS_enum
{
    HIRES_HRPLUS_NONE_gc = (0x00<<2),
    HIRES_HRPLUS_HRP4_gc = (0x01<<2),
    HIRES_HRPLUS_HRP5_gc = (0x02<<2),
    HIRES_HRPLUS_BOTH_gc = (0x03<<2),
} HIRES_HRPLUS_t;
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
    IRCOM_EVSEL_4_gc = (0x0C<<0),
    IRCOM_EVSEL_5_gc = (0x0D<<0),
    IRCOM_EVSEL_6_gc = (0x0E<<0),
    IRCOM_EVSEL_7_gc = (0x0F<<0),
} IRCOM_EVSEL_t;
typedef struct MCU_struct
{
    register8_t DEVID0;
    register8_t DEVID1;
    register8_t DEVID2;
    register8_t REVID;
    register8_t reserved_1[3];
    register8_t ANAINIT;
    register8_t EVSYSLOCK;
    register8_t WEXLOCK;
    register8_t FAULTLOCK;
    register8_t reserved_2[1];
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
    register8_t RC8MCAL;
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
    OSC_PLLSRC_RC8M_gc = (0x01<<6),
    OSC_PLLSRC_RC32M_gc = (0x02<<6),
    OSC_PLLSRC_XOSC_gc = (0x03<<6),
} OSC_PLLSRC_t;
typedef enum OSC_RC32MCREF_enum
{
    OSC_RC32MCREF_RC32K_gc = (0x00<<1),
    OSC_RC32MCREF_XOSC32K_gc = (0x01<<1),
} OSC_RC32MCREF_t;
typedef enum OSC_XOSCSEL_enum
{
    OSC_XOSCSEL_EXTCLK_gc = (0x00<<0),
    OSC_XOSCSEL_32KHz_gc = (0x02<<0),
    OSC_XOSCSEL_XTAL_256CLK_gc = (0x03<<0),
    OSC_XOSCSEL_XTAL_1KCLK_gc = (0x07<<0),
    OSC_XOSCSEL_XTAL_16KCLK_gc = (0x0B<<0),
    OSC_XOSCSEL_EXTCLK_C4_gc = (0x14<<0),
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
    register8_t INTMASK;
    register8_t reserved_1[1];
    register8_t INTFLAGS;
    register8_t reserved_2[1];
    register8_t REMAP;
    register8_t reserved_3[1];
    register8_t PIN0CTRL;
    register8_t PIN1CTRL;
    register8_t PIN2CTRL;
    register8_t PIN3CTRL;
    register8_t PIN4CTRL;
    register8_t PIN5CTRL;
    register8_t PIN6CTRL;
    register8_t PIN7CTRL;
} PORT_t;
typedef enum PORT_INTLVL_enum
{
    PORT_INTLVL_OFF_gc = (0x00<<0),
    PORT_INTLVL_LO_gc = (0x01<<0),
    PORT_INTLVL_MED_gc = (0x02<<0),
    PORT_INTLVL_HI_gc = (0x03<<0),
} PORT_INTLVL_t;
typedef enum PORT_ISC_enum
{
    PORT_ISC_BOTHEDGES_gc = (0x00<<0),
    PORT_ISC_RISING_gc = (0x01<<0),
    PORT_ISC_FALLING_gc = (0x02<<0),
    PORT_ISC_LEVEL_gc = (0x03<<0),
    PORT_ISC_FORCE_ENABLE_gc = (0x06<<0),
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
    register8_t reserved_1[3];
    register8_t CLKOUT;
    register8_t reserved_2[1];
    register8_t ACEVOUT;
    register8_t SRLCTRL;
} PORTCFG_t;
typedef enum PORTCFG_ACOUT_enum
{
    PORTCFG_ACOUT_PA_gc = (0x00<<6),
    PORTCFG_ACOUT_PC_gc = (0x01<<6),
    PORTCFG_ACOUT_PD_gc = (0x02<<6),
    PORTCFG_ACOUT_PR_gc = (0x03<<6),
} PORTCFG_ACOUT_t;
typedef enum PORTCFG_CLKEVPIN_enum
{
    PORTCFG_CLKEVPIN_PIN7_gc = (0x00<<7),
    PORTCFG_CLKEVPIN_PIN4_gc = (0x01<<7),
} PORTCFG_CLKEVPIN_t;
typedef enum PORTCFG_CLKOUT_enum
{
    PORTCFG_CLKOUT_OFF_gc = (0x00<<0),
    PORTCFG_CLKOUT_PC7_gc = (0x01<<0),
    PORTCFG_CLKOUT_PD7_gc = (0x02<<0),
    PORTCFG_CLKOUT_PR0_gc = (0x03<<0),
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
    PORTCFG_EVOUT_PC7_gc = (0x01<<4),
    PORTCFG_EVOUT_PD7_gc = (0x02<<4),
    PORTCFG_EVOUT_PR0_gc = (0x03<<4),
} PORTCFG_EVOUT_t;
typedef enum PORTCFG_EVOUTSEL_enum
{
    PORTCFG_EVOUTSEL_0_gc = (0x00<<0),
    PORTCFG_EVOUTSEL_1_gc = (0x01<<0),
    PORTCFG_EVOUTSEL_2_gc = (0x02<<0),
    PORTCFG_EVOUTSEL_3_gc = (0x03<<0),
    PORTCFG_EVOUTSEL_4_gc = (0x04<<0),
    PORTCFG_EVOUTSEL_5_gc = (0x05<<0),
    PORTCFG_EVOUTSEL_6_gc = (0x06<<0),
    PORTCFG_EVOUTSEL_7_gc = (0x07<<0),
} PORTCFG_EVOUTSEL_t;
typedef enum PORTCFG_RTCOUT_enum
{
    PORTCFG_RTCOUT_OFF_gc = (0x00<<5),
    PORTCFG_RTCOUT_PC6_gc = (0x01<<5),
    PORTCFG_RTCOUT_PD6_gc = (0x02<<5),
    PORTCFG_RTCOUT_PR0_gc = (0x03<<5),
} PORTCFG_RTCOUT_t;
typedef struct PR_struct
{
    register8_t PRGEN;
    register8_t PRPA;
    register8_t reserved_1[1];
    register8_t PRPC;
    register8_t PRPD;
    register8_t reserved_2[2];
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
    register8_t reserved_1[1];
    register8_t CALIB;
    register8_t reserved_2[1];
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
    register8_t RCOSC8M;
    register8_t reserved_1[1];
    register8_t RCOSC32K;
    register8_t RCOSC32M;
    register8_t RCOSC32MA;
    register8_t reserved_2[3];
    register8_t LOTNUM0;
    register8_t LOTNUM1;
    register8_t LOTNUM2;
    register8_t LOTNUM3;
    register8_t LOTNUM4;
    register8_t LOTNUM5;
    register8_t reserved_3[2];
    register8_t WAFNUM;
    register8_t reserved_4[1];
    register8_t COORDX0;
    register8_t COORDX1;
    register8_t COORDY0;
    register8_t COORDY1;
    register8_t reserved_5[8];
    register8_t ROOMTEMP;
    register8_t HOTTEMP;
    register8_t ADCACAL0;
    register8_t ADCACAL1;
    register8_t reserved_6[6];
    register8_t ACACURRCAL;
    register8_t reserved_7[3];
    register8_t TEMPSENSE2;
    register8_t TEMPSENSE3;
    register8_t TEMPSENSE0;
    register8_t TEMPSENSE1;
    register8_t DACA0OFFCAL;
    register8_t DACA0GAINCAL;
    register8_t reserved_8[2];
    register8_t DACA1OFFCAL;
    register8_t DACA1GAINCAL;
    register8_t reserved_9[10];
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
    register8_t CTRLB;
} SPI_t;
typedef enum SPI_BUFMODE_enum
{
    SPI_BUFMODE_OFF_gc = (0x00<<6),
    SPI_BUFMODE_BUFMODE1_gc = (0x02<<6),
    SPI_BUFMODE_BUFMODE2_gc = (0x03<<6),
} SPI_BUFMODE_t;
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
typedef struct TC4_struct
{
    register8_t CTRLA;
    register8_t CTRLB;
    register8_t CTRLC;
    register8_t CTRLD;
    register8_t CTRLE;
    register8_t CTRLF;
    register8_t INTCTRLA;
    register8_t INTCTRLB;
    register8_t CTRLGCLR;
    register8_t CTRLGSET;
    register8_t CTRLHCLR;
    register8_t CTRLHSET;
    register8_t INTFLAGS;
    register8_t reserved_1[2];
    register8_t TEMP;
    register8_t reserved_2[16];
    _WORDREGISTER(CNT);
    register8_t reserved_3[4];
    _WORDREGISTER(PER);
    _WORDREGISTER(CCA);
    _WORDREGISTER(CCB);
    _WORDREGISTER(CCC);
    _WORDREGISTER(CCD);
    register8_t reserved_4[6];
    _WORDREGISTER(PERBUF);
    _WORDREGISTER(CCABUF);
    _WORDREGISTER(CCBBUF);
    _WORDREGISTER(CCCBUF);
    _WORDREGISTER(CCDBUF);
} TC4_t;
typedef struct TC5_struct
{
    register8_t CTRLA;
    register8_t CTRLB;
    register8_t CTRLC;
    register8_t CTRLD;
    register8_t CTRLE;
    register8_t CTRLF;
    register8_t INTCTRLA;
    register8_t INTCTRLB;
    register8_t CTRLGCLR;
    register8_t CTRLGSET;
    register8_t CTRLHCLR;
    register8_t CTRLHSET;
    register8_t INTFLAGS;
    register8_t reserved_1[2];
    register8_t TEMP;
    register8_t reserved_2[16];
    _WORDREGISTER(CNT);
    register8_t reserved_3[4];
    _WORDREGISTER(PER);
    _WORDREGISTER(CCA);
    _WORDREGISTER(CCB);
    register8_t reserved_4[10];
    _WORDREGISTER(PERBUF);
    _WORDREGISTER(CCABUF);
    _WORDREGISTER(CCBBUF);
    register8_t reserved_5[4];
} TC5_t;
typedef enum TC_BYTEM_enum
{
    TC_BYTEM_NORMAL_gc = (0x00<<6),
    TC_BYTEM_BYTEMODE_gc = (0x01<<6),
} TC_BYTEM_t;
typedef enum TC_CCAINTLVL_enum
{
    TC_CCAINTLVL_OFF_gc = (0x00<<0),
    TC_CCAINTLVL_LO_gc = (0x01<<0),
    TC_CCAINTLVL_MED_gc = (0x02<<0),
    TC_CCAINTLVL_HI_gc = (0x03<<0),
} TC_CCAINTLVL_t;
typedef enum TC_CCAMODE_enum
{
    TC_CCAMODE_DISABLE_gc = (0x00<<0),
    TC_CCAMODE_COMP_gc = (0x01<<0),
    TC_CCAMODE_CAPT_gc = (0x02<<0),
    TC_CCAMODE_BOTHCC_gc = (0x03<<0),
} TC_CCAMODE_t;
typedef enum TC_CCBINTLVL_enum
{
    TC_CCBINTLVL_OFF_gc = (0x00<<2),
    TC_CCBINTLVL_LO_gc = (0x01<<2),
    TC_CCBINTLVL_MED_gc = (0x02<<2),
    TC_CCBINTLVL_HI_gc = (0x03<<2),
} TC_CCBINTLVL_t;
typedef enum TC_CCBMODE_enum
{
    TC_CCBMODE_DISABLE_gc = (0x00<<2),
    TC_CCBMODE_COMP_gc = (0x01<<2),
    TC_CCBMODE_CAPT_gc = (0x02<<2),
    TC_CCBMODE_BOTHCC_gc = (0x03<<2),
} TC_CCBMODE_t;
typedef enum TC_CCCINTLVL_enum
{
    TC_CCCINTLVL_OFF_gc = (0x00<<4),
    TC_CCCINTLVL_LO_gc = (0x01<<4),
    TC_CCCINTLVL_MED_gc = (0x02<<4),
    TC_CCCINTLVL_HI_gc = (0x03<<4),
} TC_CCCINTLVL_t;
typedef enum TC_CCCMODE_enum
{
    TC_CCCMODE_DISABLE_gc = (0x00<<4),
    TC_CCCMODE_COMP_gc = (0x01<<4),
    TC_CCCMODE_CAPT_gc = (0x02<<4),
    TC_CCCMODE_BOTHCC_gc = (0x03<<4),
} TC_CCCMODE_t;
typedef enum TC_CCDINTLVL_enum
{
    TC_CCDINTLVL_OFF_gc = (0x00<<6),
    TC_CCDINTLVL_LO_gc = (0x01<<6),
    TC_CCDINTLVL_MED_gc = (0x02<<6),
    TC_CCDINTLVL_HI_gc = (0x03<<6),
} TC_CCDINTLVL_t;
typedef enum TC_CCDMODE_enum
{
    TC_CCDMODE_DISABLE_gc = (0x00<<6),
    TC_CCDMODE_COMP_gc = (0x01<<6),
    TC_CCDMODE_CAPT_gc = (0x02<<6),
    TC_CCDMODE_BOTHCC_gc = (0x03<<6),
} TC_CCDMODE_t;
typedef enum TC_CIRCEN_enum
{
    TC_CIRCEN_DISABLE_gc = (0x00<<4),
    TC_CIRCEN_PER_gc = (0x01<<4),
    TC_CIRCEN_CCA_gc = (0x02<<4),
    TC_CIRCEN_BOTH_gc = (0x03<<4),
} TC_CIRCEN_t;
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
    TC_CLKSEL_EVCH4_gc = (0x0C<<0),
    TC_CLKSEL_EVCH5_gc = (0x0D<<0),
    TC_CLKSEL_EVCH6_gc = (0x0E<<0),
    TC_CLKSEL_EVCH7_gc = (0x0F<<0),
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
    TC_EVACT_FMODE1_gc = (0x01<<5),
    TC_EVACT_FMODE2_gc = (0x02<<5),
    TC_EVACT_UPDOWN_gc = (0x03<<5),
    TC_EVACT_QDEC_gc = (0x04<<5),
    TC_EVACT_RESTART_gc = (0x05<<5),
    TC_EVACT_PWF_gc = (0x06<<5),
} TC_EVACT_t;
typedef enum TC_EVSEL_enum
{
    TC_EVSEL_OFF_gc = (0x00<<0),
    TC_EVSEL_CH0_gc = (0x08<<0),
    TC_EVSEL_CH1_gc = (0x09<<0),
    TC_EVSEL_CH2_gc = (0x0A<<0),
    TC_EVSEL_CH3_gc = (0x0B<<0),
    TC_EVSEL_CH4_gc = (0x0C<<0),
    TC_EVSEL_CH5_gc = (0x0D<<0),
    TC_EVSEL_CH6_gc = (0x0E<<0),
    TC_EVSEL_CH7_gc = (0x0F<<0),
} TC_EVSEL_t;
typedef enum TC_HCCAMODE_enum
{
    TC_HCCAMODE_DISABLE_gc = (0x00<<0),
    TC_HCCAMODE_COMP_gc = (0x01<<0),
    TC_HCCAMODE_CAPT_gc = (0x02<<0),
    TC_HCCAMODE_BOTHCC_gc = (0x03<<0),
} TC_HCCAMODE_t;
typedef enum TC_HCCBMODE_enum
{
    TC_HCCBMODE_DISABLE_gc = (0x00<<2),
    TC_HCCBMODE_COMP_gc = (0x01<<2),
    TC_HCCBMODE_CAPT_gc = (0x02<<2),
    TC_HCCBMODE_BOTHCC_gc = (0x03<<2),
} TC_HCCBMODE_t;
typedef enum TC_HCCCMODE_enum
{
    TC_HCCCMODE_DISABLE_gc = (0x00<<4),
    TC_HCCCMODE_COMP_gc = (0x01<<4),
    TC_HCCCMODE_CAPT_gc = (0x02<<4),
    TC_HCCCMODE_BOTHCC_gc = (0x03<<4),
} TC_HCCCMODE_t;
typedef enum TC_HCCDMODE_enum
{
    TC_HCCDMODE_DISABLE_gc = (0x00<<6),
    TC_HCCDMODE_COMP_gc = (0x01<<6),
    TC_HCCDMODE_CAPT_gc = (0x02<<6),
    TC_HCCDMODE_BOTHCC_gc = (0x03<<6),
} TC_HCCDMODE_t;
typedef enum TC_LCCAINTLVL_enum
{
    TC_LCCAINTLVL_OFF_gc = (0x00<<0),
    TC_LCCAINTLVL_LO_gc = (0x01<<0),
    TC_LCCAINTLVL_MED_gc = (0x02<<0),
    TC_LCCAINTLVL_HI_gc = (0x03<<0),
} TC_LCCAINTLVL_t;
typedef enum TC_LCCAMODE_enum
{
    TC_LCCAMODE_DISABLE_gc = (0x00<<0),
    TC_LCCAMODE_COMP_gc = (0x01<<0),
    TC_LCCAMODE_CAPT_gc = (0x02<<0),
    TC_LCCAMODE_BOTHCC_gc = (0x03<<0),
} TC_LCCAMODE_t;
typedef enum TC_LCCBINTLVL_enum
{
    TC_LCCBINTLVL_OFF_gc = (0x00<<2),
    TC_LCCBINTLVL_LO_gc = (0x01<<2),
    TC_LCCBINTLVL_MED_gc = (0x02<<2),
    TC_LCCBINTLVL_HI_gc = (0x03<<2),
} TC_LCCBINTLVL_t;
typedef enum TC_LCCBMODE_enum
{
    TC_LCCBMODE_DISABLE_gc = (0x00<<2),
    TC_LCCBMODE_COMP_gc = (0x01<<2),
    TC_LCCBMODE_CAPT_gc = (0x02<<2),
    TC_LCCBMODE_BOTHCC_gc = (0x03<<2),
} TC_LCCBMODE_t;
typedef enum TC_LCCCINTLVL_enum
{
    TC_LCCCINTLVL_OFF_gc = (0x00<<4),
    TC_LCCCINTLVL_LO_gc = (0x01<<4),
    TC_LCCCINTLVL_MED_gc = (0x02<<4),
    TC_LCCCINTLVL_HI_gc = (0x03<<4),
} TC_LCCCINTLVL_t;
typedef enum TC_LCCCMODE_enum
{
    TC_LCCCMODE_DISABLE_gc = (0x00<<4),
    TC_LCCCMODE_COMP_gc = (0x01<<4),
    TC_LCCCMODE_CAPT_gc = (0x02<<4),
    TC_LCCCMODE_BOTHCC_gc = (0x03<<4),
} TC_LCCCMODE_t;
typedef enum TC_LCCDINTLVL_enum
{
    TC_LCCDINTLVL_OFF_gc = (0x00<<6),
    TC_LCCDINTLVL_LO_gc = (0x01<<6),
    TC_LCCDINTLVL_MED_gc = (0x02<<6),
    TC_LCCDINTLVL_HI_gc = (0x03<<6),
} TC_LCCDINTLVL_t;
typedef enum TC_LCCDMODE_enum
{
    TC_LCCDMODE_DISABLE_gc = (0x00<<6),
    TC_LCCDMODE_COMP_gc = (0x01<<6),
    TC_LCCDMODE_CAPT_gc = (0x02<<6),
    TC_LCCDMODE_BOTHCC_gc = (0x03<<6),
} TC_LCCDMODE_t;
typedef enum TC_OVFINTLVL_enum
{
    TC_OVFINTLVL_OFF_gc = (0x00<<0),
    TC_OVFINTLVL_LO_gc = (0x01<<0),
    TC_OVFINTLVL_MED_gc = (0x02<<0),
    TC_OVFINTLVL_HI_gc = (0x03<<0),
} TC_OVFINTLVL_t;
typedef enum TC_TRGINTLVL_enum
{
    TC_TRGINTLVL_OFF_gc = (0x00<<4),
    TC_TRGINTLVL_LO_gc = (0x01<<4),
    TC_TRGINTLVL_MED_gc = (0x02<<4),
    TC_TRGINTLVL_HI_gc = (0x03<<4),
} TC_TRGINTLVL_t;
typedef enum TC_WGMODE_enum
{
    TC_WGMODE_NORMAL_gc = (0x00<<0),
    TC_WGMODE_FRQ_gc = (0x01<<0),
    TC_WGMODE_SINGLESLOPE_gc = (0x03<<0),
    TC_WGMODE_DSTOP_gc = (0x05<<0),
    TC_WGMODE_DSBOTH_gc = (0x06<<0),
    TC_WGMODE_DSBOTTOM_gc = (0x07<<0),
} TC_WGMODE_t;
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
typedef struct TWI_TIMEOUT_struct
{
    register8_t TOS;
    register8_t TOCONF;
} TWI_TIMEOUT_t;
typedef struct TWI_struct
{
    register8_t CTRL;
    TWI_MASTER_t MASTER;
    TWI_SLAVE_t SLAVE;
    TWI_TIMEOUT_t TIMEOUT;
} TWI_t;
typedef enum TWI_SDAHOLD_enum
{
    TWI_SDAHOLD_OFF_gc = (0x00<<1),
    TWI_SDAHOLD_50NS_gc = (0x01<<1),
    TWI_SDAHOLD_300NS_gc = (0x02<<1),
    TWI_SDAHOLD_400NS_gc = (0x03<<1),
} TWI_SDAHOLD_t;
typedef enum TWI_SSDAHOLD_enum
{
    TWI_SSDAHOLD_OFF_gc = (0x00<<4),
    TWI_SSDAHOLD_50NS_gc = (0x01<<4),
    TWI_SSDAHOLD_300NS_gc = (0x02<<4),
    TWI_SSDAHOLD_400NS_gc = (0x03<<4),
} TWI_SSDAHOLD_t;
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
typedef enum TWI_TIMEOUT_TMSEXTSEL_enum
{
    TWI_TIMEOUT_TMSEXTSEL_10MS25MS_gc = (0x00<<3),
    TWI_TIMEOUT_TMSEXTSEL_9MS24MS_gc = (0x01<<3),
    TWI_TIMEOUT_TMSEXTSEL_11MS26MS_gc = (0x02<<3),
    TWI_TIMEOUT_TMSEXTSEL_12MS27MS_gc = (0x03<<3),
} TWI_TIMEOUT_TMSEXTSEL_t;
typedef enum TWI_TIMEOUT_TTOUTMSEL_enum
{
    TWI_TIMEOUT_TTOUTMSEL_25MS_gc = (0x00<<0),
    TWI_TIMEOUT_TTOUTMSEL_24MS_gc = (0x01<<0),
    TWI_TIMEOUT_TTOUTMSEL_23MS_gc = (0x02<<0),
    TWI_TIMEOUT_TTOUTMSEL_22MS_gc = (0x03<<0),
    TWI_TIMEOUT_TTOUTMSEL_26MS_gc = (0x04<<0),
    TWI_TIMEOUT_TTOUTMSEL_27MS_gc = (0x05<<0),
    TWI_TIMEOUT_TTOUTMSEL_28MS_gc = (0x06<<0),
    TWI_TIMEOUT_TTOUTMSEL_29MS_gc = (0x07<<0),
} TWI_TIMEOUT_TTOUTMSEL_t;
typedef enum TWI_TIMEOUT_TTOUTSSEL_enum
{
    TWI_TIMEOUT_TTOUTSSEL_25MS_gc = (0x00<<5),
    TWI_TIMEOUT_TTOUTSSEL_24MS_gc = (0x01<<5),
    TWI_TIMEOUT_TTOUTSSEL_23MS_gc = (0x02<<5),
    TWI_TIMEOUT_TTOUTSSEL_22MS_gc = (0x03<<5),
    TWI_TIMEOUT_TTOUTSSEL_26MS_gc = (0x04<<5),
    TWI_TIMEOUT_TTOUTSSEL_27MS_gc = (0x05<<5),
    TWI_TIMEOUT_TTOUTSSEL_28MS_gc = (0x06<<5),
    TWI_TIMEOUT_TTOUTSSEL_29MS_gc = (0x07<<5),
} TWI_TIMEOUT_TTOUTSSEL_t;
typedef struct USART_struct
{
    register8_t DATA;
    register8_t STATUS;
    register8_t CTRLA;
    register8_t CTRLB;
    register8_t CTRLC;
    register8_t CTRLD;
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
typedef enum USART_DECTYPE_enum
{
    USART_DECTYPE_DATA_gc = (0x00<<4),
    USART_DECTYPE_SDATA_gc = (0x02<<4),
    USART_DECTYPE_NOTSDATA_gc = (0x03<<4),
} USART_DECTYPE_t;
typedef enum USART_DREINTLVL_enum
{
    USART_DREINTLVL_OFF_gc = (0x00<<0),
    USART_DREINTLVL_LO_gc = (0x01<<0),
    USART_DREINTLVL_MED_gc = (0x02<<0),
    USART_DREINTLVL_HI_gc = (0x03<<0),
} USART_DREINTLVL_t;
typedef enum USART_LUTACT_enum
{
    USART_LUTACT_OFF_gc = (0x00<<2),
    USART_LUTACT_RX_gc = (0x01<<2),
    USART_LUTACT_TX_gc = (0x02<<2),
    USART_LUTACT_BOTH_gc = (0x03<<2),
} USART_LUTACT_t;
typedef enum USART_PECACT_enum
{
    USART_PECACT_OFF_gc = (0x00<<0),
    USART_PECACT_PEC0_gc = (0x01<<0),
    USART_PECACT_PEC1_gc = (0x02<<0),
    USART_PECACT_PERC01_gc = (0x03<<0),
} USART_PECACT_t;
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
typedef struct WEX_struct
{
    register8_t CTRL;
    register8_t DTBOTH;
    register8_t DTLS;
    register8_t DTHS;
    register8_t STATUSCLR;
    register8_t STATUSSET;
    register8_t SWAP;
    register8_t PGO;
    register8_t PGV;
    register8_t reserved_1[1];
    register8_t SWAPBUF;
    register8_t PGOBUF;
    register8_t PGVBUF;
    register8_t reserved_2[2];
    register8_t OUTOVDIS;
} WEX_t;
typedef enum WEX_OTMX_enum
{
    WEX_OTMX_DEFAULT_gc = (0x00<<4),
    WEX_OTMX_FIRST_gc = (0x01<<4),
    WEX_OTMX_SECOND_gc = (0x02<<4),
    WEX_OTMX_THIRD_gc = (0x03<<4),
    WEX_OTMX_FOURTH_gc = (0x04<<4),
} WEX_OTMX_t;
typedef struct XCL_struct
{
    register8_t CTRLA;
    register8_t CTRLB;
    register8_t CTRLC;
    register8_t CTRLD;
    register8_t CTRLE;
    register8_t CTRLF;
    register8_t CTRLG;
    register8_t INTCTRL;
    register8_t INTFLAGS;
    register8_t PLC;
    register8_t CNTL;
    register8_t CNTH;
    register8_t CMPL;
    register8_t CMPH;
    register8_t PERCAPTL;
    register8_t PERCAPTH;
} XCL_t;
typedef enum XCL_CCINTLVL_enum
{
    XCL_CCINTLVL_OFF_gc = (0x00<<0),
    XCL_CCINTLVL_LO_gc = (0x01<<0),
    XCL_CCINTLVL_MED_gc = (0x02<<0),
    XCL_CCINTLVL_HI_gc = (0x03<<0),
} XCL_CCINTLVL_t;
typedef enum XCL_CLKSEL_enum
{
    XCL_CLKSEL_OFF_gc = (0x00<<0),
    XCL_CLKSEL_DIV1_gc = (0x01<<0),
    XCL_CLKSEL_DIV2_gc = (0x02<<0),
    XCL_CLKSEL_DIV4_gc = (0x03<<0),
    XCL_CLKSEL_DIV8_gc = (0x04<<0),
    XCL_CLKSEL_DIV64_gc = (0x05<<0),
    XCL_CLKSEL_DIV256_gc = (0x06<<0),
    XCL_CLKSEL_DIV1024_gc = (0x07<<0),
    XCL_CLKSEL_EVCH0_gc = (0x08<<0),
    XCL_CLKSEL_EVCH1_gc = (0x09<<0),
    XCL_CLKSEL_EVCH2_gc = (0x0A<<0),
    XCL_CLKSEL_EVCH3_gc = (0x0B<<0),
    XCL_CLKSEL_EVCH4_gc = (0x0C<<0),
    XCL_CLKSEL_EVCH5_gc = (0x0D<<0),
    XCL_CLKSEL_EVCH6_gc = (0x0E<<0),
    XCL_CLKSEL_EVCH7_gc = (0x0F<<0),
} XCL_CLKSEL_t;
typedef enum XCL_CMDEN_enum
{
    XCL_CMDEN_DISABLE_gc = (0x00<<6),
    XCL_CMDEN_CMD0_gc = (0x01<<6),
    XCL_CMDEN_CMD1_gc = (0x02<<6),
    XCL_CMDEN_CMD01_gc = (0x03<<6),
} XCL_CMDEN_t;
typedef enum XCL_CMDSEL_enum
{
    XCL_CMDSEL_NONE_gc = (0x00<<7),
    XCL_CMDSEL_RESTART_gc = (0x01<<7),
} XCL_CMDSEL_t;
typedef enum XCL_CMP0_enum
{
    XCL_CMP0_CLEAR_gc = (0x00<<4),
    XCL_CMP0_SET_gc = (0x01<<4),
} XCL_CMP0_t;
typedef enum XCL_CMP1_enum
{
    XCL_CMP1_CLEAR_gc = (0x00<<5),
    XCL_CMP1_SET_gc = (0x01<<5),
} XCL_CMP1_t;
typedef enum XCL_DLY0CONF_enum
{
    XCL_DLY0CONF_DISABLE_gc = (0x00<<0),
    XCL_DLY0CONF_IN_gc = (0x01<<0),
    XCL_DLY0CONF_OUT_gc = (0x02<<0),
} XCL_DLY0CONF_t;
typedef enum XCL_DLY1CONF_enum
{
    XCL_DLY1CONF_DISABLE_gc = (0x00<<2),
    XCL_DLY1CONF_IN_gc = (0x01<<2),
    XCL_DLY1CONF_OUT_gc = (0x02<<2),
} XCL_DLY1CONF_t;
typedef enum XCL_DLYSEL_enum
{
    XCL_DLYSEL_DLY11_gc = (0x00<<4),
    XCL_DLYSEL_DLY12_gc = (0x01<<4),
    XCL_DLYSEL_DLY21_gc = (0x02<<4),
    XCL_DLYSEL_DLY22_gc = (0x03<<4),
} XCL_DLYSEL_t;
typedef enum XCL_EVACT0_enum
{
    XCL_EVACT0_INPUT_gc = (0x00<<3),
    XCL_EVACT0_FREQ_gc = (0x01<<3),
    XCL_EVACT0_PW_gc = (0x02<<3),
    XCL_EVACT0_RESTART_gc = (0x03<<3),
} XCL_EVACT0_t;
typedef enum XCL_EVACT1_enum
{
    XCL_EVACT1_INPUT_gc = (0x00<<5),
    XCL_EVACT1_FREQ_gc = (0x01<<5),
    XCL_EVACT1_PW_gc = (0x02<<5),
    XCL_EVACT1_RESTART_gc = (0x03<<5),
} XCL_EVACT1_t;
typedef enum XCL_EVSRC_enum
{
    XCL_EVSRC_EVCH0_gc = (0x00<<0),
    XCL_EVSRC_EVCH1_gc = (0x01<<0),
    XCL_EVSRC_EVCH2_gc = (0x02<<0),
    XCL_EVSRC_EVCH3_gc = (0x03<<0),
    XCL_EVSRC_EVCH4_gc = (0x04<<0),
    XCL_EVSRC_EVCH5_gc = (0x05<<0),
    XCL_EVSRC_EVCH6_gc = (0x06<<0),
    XCL_EVSRC_EVCH7_gc = (0x07<<0),
} XCL_EVSRC_t;
typedef enum XCL_IN0SEL_enum
{
    XCL_IN0SEL_EVSYS_gc = (0x00<<0),
    XCL_IN0SEL_XCL_gc = (0x01<<0),
    XCL_IN0SEL_PINL_gc = (0x02<<0),
    XCL_IN0SEL_PINH_gc = (0x03<<0),
} XCL_IN0SEL_t;
typedef enum XCL_IN1SEL_enum
{
    XCL_IN1SEL_EVSYS_gc = (0x00<<2),
    XCL_IN1SEL_XCL_gc = (0x01<<2),
    XCL_IN1SEL_PINL_gc = (0x02<<2),
    XCL_IN1SEL_PINH_gc = (0x03<<2),
} XCL_IN1SEL_t;
typedef enum XCL_IN2SEL_enum
{
    XCL_IN2SEL_EVSYS_gc = (0x00<<4),
    XCL_IN2SEL_XCL_gc = (0x01<<4),
    XCL_IN2SEL_PINL_gc = (0x02<<4),
    XCL_IN2SEL_PINH_gc = (0x03<<4),
} XCL_IN2SEL_t;
typedef enum XCL_IN3SEL_enum
{
    XCL_IN3SEL_EVSYS_gc = (0x00<<6),
    XCL_IN3SEL_XCL_gc = (0x01<<6),
    XCL_IN3SEL_PINL_gc = (0x02<<6),
    XCL_IN3SEL_PINH_gc = (0x03<<6),
} XCL_IN3SEL_t;
typedef enum XCL_LUT0OUTEN_enum
{
    XCL_LUT0OUTEN_DISABLE_gc = (0x00<<6),
    XCL_LUT0OUTEN_PIN0_gc = (0x01<<6),
    XCL_LUT0OUTEN_PIN4_gc = (0x02<<6),
} XCL_LUT0OUTEN_t;
typedef enum XCL_LUTCONF_enum
{
    XCL_LUTCONF_2LUT2IN_gc = (0x00<<0),
    XCL_LUTCONF_2LUT1IN_gc = (0x01<<0),
    XCL_LUTCONF_2LUT3IN_gc = (0x02<<0),
    XCL_LUTCONF_1LUT3IN_gc = (0x03<<0),
    XCL_LUTCONF_MUX_gc = (0x04<<0),
    XCL_LUTCONF_DLATCH_gc = (0x05<<0),
    XCL_LUTCONF_RSLATCH_gc = (0x06<<0),
    XCL_LUTCONF_DFF_gc = (0x07<<0),
} XCL_LUTCONF_t;
typedef enum XCL_MODE_enum
{
    XCL_MODE_NORMAL_gc = (0x00<<0),
    XCL_MODE_CAPT_gc = (0x01<<0),
    XCL_MODE_PWM_gc = (0x02<<0),
    XCL_MODE_1SHOT_gc = (0x03<<0),
} XCL_MODE_t;
typedef enum XCL_PORTSEL_enum
{
    XCL_PORTSEL_PC_gc = (0x00<<4),
    XCL_PORTSEL_PD_gc = (0x01<<4),
} XCL_PORTSEL_t;
typedef enum XCL_TCSEL_enum
{
    XCL_TCSEL_TC16_gc = (0x00<<4),
    XCL_TCSEL_BTC0_gc = (0x01<<4),
    XCL_TCSEL_BTC01_gc = (0x02<<4),
    XCL_TCSEL_BTC0PEC1_gc = (0x03<<4),
    XCL_TCSEL_PEC0BTC1_gc = (0x04<<4),
    XCL_TCSEL_PEC01_gc = (0x05<<4),
    XCL_TCSEL_BTC0PEC2_gc = (0x06<<4),
} XCL_TCSEL_t;
typedef enum XCL_UNFINTLVL_enum
{
    XCL_UNFINTLVL_OFF_gc = (0x00<<2),
    XCL_UNFINTLVL_LO_gc = (0x01<<2),
    XCL_UNFINTLVL_MED_gc = (0x02<<2),
    XCL_UNFINTLVL_HI_gc = (0x03<<2),
} XCL_UNFINTLVL_t;
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
#define PR (*(PR_t *) 0x0070)
#define RST (*(RST_t *) 0x0078)
#define WDT (*(WDT_t *) 0x0080)
#define MCU (*(MCU_t *) 0x0090)
#define PMIC (*(PMIC_t *) 0x00A0)
#define PORTCFG (*(PORTCFG_t *) 0x00B0)
#define CRC (*(CRC_t *) 0x00D0)
#define EDMA (*(EDMA_t *) 0x0100)
#define EVSYS (*(EVSYS_t *) 0x0180)
#define NVM (*(NVM_t *) 0x01C0)
#define ADCA (*(ADC_t *) 0x0200)
#define DACA (*(DAC_t *) 0x0300)
#define ACA (*(AC_t *) 0x0380)
#define RTC (*(RTC_t *) 0x0400)
#define XCL (*(XCL_t *) 0x0460)
#define TWIC (*(TWI_t *) 0x0480)
#define PORTA (*(PORT_t *) 0x0600)
#define PORTC (*(PORT_t *) 0x0640)
#define PORTD (*(PORT_t *) 0x0660)
#define PORTR (*(PORT_t *) 0x07E0)
#define TCC4 (*(TC4_t *) 0x0800)
#define TCC5 (*(TC5_t *) 0x0840)
#define FAULTC4 (*(FAULT_t *) 0x0880)
#define FAULTC5 (*(FAULT_t *) 0x0890)
#define WEXC (*(WEX_t *) 0x08A0)
#define HIRESC (*(HIRES_t *) 0x08B0)
#define USARTC0 (*(USART_t *) 0x08C0)
#define SPIC (*(SPI_t *) 0x08E0)
#define IRCOM (*(IRCOM_t *) 0x08F8)
#define TCD5 (*(TC5_t *) 0x0940)
#define USARTD0 (*(USART_t *) 0x09C0)
#endif
#define GPIO_GPIOR0 _SFR_MEM8(0x0000)
#define GPIO_GPIOR1 _SFR_MEM8(0x0001)
#define GPIO_GPIOR2 _SFR_MEM8(0x0002)
#define GPIO_GPIOR3 _SFR_MEM8(0x0003)
#define GPIO_GPIO0 _SFR_MEM8(0x0000)
#define GPIO_GPIO1 _SFR_MEM8(0x0001)
#define GPIO_GPIO2 _SFR_MEM8(0x0002)
#define GPIO_GPIO3 _SFR_MEM8(0x0003)
#define FUSE_FUSEBYTE1 _SFR_MEM8(0x0001)
#define FUSE_FUSEBYTE2 _SFR_MEM8(0x0002)
#define FUSE_FUSEBYTE4 _SFR_MEM8(0x0004)
#define FUSE_FUSEBYTE5 _SFR_MEM8(0x0005)
#define FUSE_FUSEBYTE6 _SFR_MEM8(0x0006)
#define LOCKBIT_LOCKBITS _SFR_MEM8(0x0000)
#define PRODSIGNATURES_RCOSC8M _SFR_MEM8(0x0000)
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
#define PRODSIGNATURES_ROOMTEMP _SFR_MEM8(0x001E)
#define PRODSIGNATURES_HOTTEMP _SFR_MEM8(0x001F)
#define PRODSIGNATURES_ADCACAL0 _SFR_MEM8(0x0020)
#define PRODSIGNATURES_ADCACAL1 _SFR_MEM8(0x0021)
#define PRODSIGNATURES_ACACURRCAL _SFR_MEM8(0x0028)
#define PRODSIGNATURES_TEMPSENSE2 _SFR_MEM8(0x002C)
#define PRODSIGNATURES_TEMPSENSE3 _SFR_MEM8(0x002D)
#define PRODSIGNATURES_TEMPSENSE0 _SFR_MEM8(0x002E)
#define PRODSIGNATURES_TEMPSENSE1 _SFR_MEM8(0x002F)
#define PRODSIGNATURES_DACA0OFFCAL _SFR_MEM8(0x0030)
#define PRODSIGNATURES_DACA0GAINCAL _SFR_MEM8(0x0031)
#define PRODSIGNATURES_DACA1OFFCAL _SFR_MEM8(0x0034)
#define PRODSIGNATURES_DACA1GAINCAL _SFR_MEM8(0x0035)
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
#define SLEEP_CTRL _SFR_MEM8(0x0048)
#define OSC_CTRL _SFR_MEM8(0x0050)
#define OSC_STATUS _SFR_MEM8(0x0051)
#define OSC_XOSCCTRL _SFR_MEM8(0x0052)
#define OSC_XOSCFAIL _SFR_MEM8(0x0053)
#define OSC_RC32KCAL _SFR_MEM8(0x0054)
#define OSC_PLLCTRL _SFR_MEM8(0x0055)
#define OSC_DFLLCTRL _SFR_MEM8(0x0056)
#define OSC_RC8MCAL _SFR_MEM8(0x0057)
#define DFLLRC32M_CTRL _SFR_MEM8(0x0060)
#define DFLLRC32M_CALA _SFR_MEM8(0x0062)
#define DFLLRC32M_CALB _SFR_MEM8(0x0063)
#define DFLLRC32M_COMP0 _SFR_MEM8(0x0064)
#define DFLLRC32M_COMP1 _SFR_MEM8(0x0065)
#define DFLLRC32M_COMP2 _SFR_MEM8(0x0066)
#define PR_PRGEN _SFR_MEM8(0x0070)
#define PR_PRPA _SFR_MEM8(0x0071)
#define PR_PRPC _SFR_MEM8(0x0073)
#define PR_PRPD _SFR_MEM8(0x0074)
#define RST_STATUS _SFR_MEM8(0x0078)
#define RST_CTRL _SFR_MEM8(0x0079)
#define WDT_CTRL _SFR_MEM8(0x0080)
#define WDT_WINCTRL _SFR_MEM8(0x0081)
#define WDT_STATUS _SFR_MEM8(0x0082)
#define MCU_DEVID0 _SFR_MEM8(0x0090)
#define MCU_DEVID1 _SFR_MEM8(0x0091)
#define MCU_DEVID2 _SFR_MEM8(0x0092)
#define MCU_REVID _SFR_MEM8(0x0093)
#define MCU_ANAINIT _SFR_MEM8(0x0097)
#define MCU_EVSYSLOCK _SFR_MEM8(0x0098)
#define MCU_WEXLOCK _SFR_MEM8(0x0099)
#define MCU_FAULTLOCK _SFR_MEM8(0x009A)
#define PMIC_STATUS _SFR_MEM8(0x00A0)
#define PMIC_INTPRI _SFR_MEM8(0x00A1)
#define PMIC_CTRL _SFR_MEM8(0x00A2)
#define PORTCFG_MPCMASK _SFR_MEM8(0x00B0)
#define PORTCFG_CLKOUT _SFR_MEM8(0x00B4)
#define PORTCFG_ACEVOUT _SFR_MEM8(0x00B6)
#define PORTCFG_SRLCTRL _SFR_MEM8(0x00B7)
#define CRC_CTRL _SFR_MEM8(0x00D0)
#define CRC_STATUS _SFR_MEM8(0x00D1)
#define CRC_DATAIN _SFR_MEM8(0x00D3)
#define CRC_CHECKSUM0 _SFR_MEM8(0x00D4)
#define CRC_CHECKSUM1 _SFR_MEM8(0x00D5)
#define CRC_CHECKSUM2 _SFR_MEM8(0x00D6)
#define CRC_CHECKSUM3 _SFR_MEM8(0x00D7)
#define EDMA_CTRL _SFR_MEM8(0x0100)
#define EDMA_INTFLAGS _SFR_MEM8(0x0103)
#define EDMA_STATUS _SFR_MEM8(0x0104)
#define EDMA_TEMP _SFR_MEM8(0x0106)
#define EDMA_CH0_CTRLA _SFR_MEM8(0x0110)
#define EDMA_CH0_CTRLB _SFR_MEM8(0x0111)
#define EDMA_CH0_ADDRCTRL _SFR_MEM8(0x0112)
#define EDMA_CH0_DESTADDRCTRL _SFR_MEM8(0x0113)
#define EDMA_CH0_TRIGSRC _SFR_MEM8(0x0114)
#define EDMA_CH0_TRFCNT _SFR_MEM16(0x0116)
#define EDMA_CH0_ADDR _SFR_MEM16(0x0118)
#define EDMA_CH0_DESTADDR _SFR_MEM16(0x011C)
#define EDMA_CH1_CTRLA _SFR_MEM8(0x0120)
#define EDMA_CH1_CTRLB _SFR_MEM8(0x0121)
#define EDMA_CH1_ADDRCTRL _SFR_MEM8(0x0122)
#define EDMA_CH1_DESTADDRCTRL _SFR_MEM8(0x0123)
#define EDMA_CH1_TRIGSRC _SFR_MEM8(0x0124)
#define EDMA_CH1_TRFCNT _SFR_MEM16(0x0126)
#define EDMA_CH1_ADDR _SFR_MEM16(0x0128)
#define EDMA_CH1_DESTADDR _SFR_MEM16(0x012C)
#define EDMA_CH2_CTRLA _SFR_MEM8(0x0130)
#define EDMA_CH2_CTRLB _SFR_MEM8(0x0131)
#define EDMA_CH2_ADDRCTRL _SFR_MEM8(0x0132)
#define EDMA_CH2_DESTADDRCTRL _SFR_MEM8(0x0133)
#define EDMA_CH2_TRIGSRC _SFR_MEM8(0x0134)
#define EDMA_CH2_TRFCNT _SFR_MEM16(0x0136)
#define EDMA_CH2_ADDR _SFR_MEM16(0x0138)
#define EDMA_CH2_DESTADDR _SFR_MEM16(0x013C)
#define EDMA_CH3_CTRLA _SFR_MEM8(0x0140)
#define EDMA_CH3_CTRLB _SFR_MEM8(0x0141)
#define EDMA_CH3_ADDRCTRL _SFR_MEM8(0x0142)
#define EDMA_CH3_DESTADDRCTRL _SFR_MEM8(0x0143)
#define EDMA_CH3_TRIGSRC _SFR_MEM8(0x0144)
#define EDMA_CH3_TRFCNT _SFR_MEM16(0x0146)
#define EDMA_CH3_ADDR _SFR_MEM16(0x0148)
#define EDMA_CH3_DESTADDR _SFR_MEM16(0x014C)
#define EVSYS_CH0MUX _SFR_MEM8(0x0180)
#define EVSYS_CH1MUX _SFR_MEM8(0x0181)
#define EVSYS_CH2MUX _SFR_MEM8(0x0182)
#define EVSYS_CH3MUX _SFR_MEM8(0x0183)
#define EVSYS_CH4MUX _SFR_MEM8(0x0184)
#define EVSYS_CH5MUX _SFR_MEM8(0x0185)
#define EVSYS_CH6MUX _SFR_MEM8(0x0186)
#define EVSYS_CH7MUX _SFR_MEM8(0x0187)
#define EVSYS_CH0CTRL _SFR_MEM8(0x0188)
#define EVSYS_CH1CTRL _SFR_MEM8(0x0189)
#define EVSYS_CH2CTRL _SFR_MEM8(0x018A)
#define EVSYS_CH3CTRL _SFR_MEM8(0x018B)
#define EVSYS_CH4CTRL _SFR_MEM8(0x018C)
#define EVSYS_CH5CTRL _SFR_MEM8(0x018D)
#define EVSYS_CH6CTRL _SFR_MEM8(0x018E)
#define EVSYS_CH7CTRL _SFR_MEM8(0x018F)
#define EVSYS_STROBE _SFR_MEM8(0x0190)
#define EVSYS_DATA _SFR_MEM8(0x0191)
#define EVSYS_DFCTRL _SFR_MEM8(0x0192)
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
#define ADCA_CTRLA _SFR_MEM8(0x0200)
#define ADCA_CTRLB _SFR_MEM8(0x0201)
#define ADCA_REFCTRL _SFR_MEM8(0x0202)
#define ADCA_EVCTRL _SFR_MEM8(0x0203)
#define ADCA_PRESCALER _SFR_MEM8(0x0204)
#define ADCA_INTFLAGS _SFR_MEM8(0x0206)
#define ADCA_TEMP _SFR_MEM8(0x0207)
#define ADCA_SAMPCTRL _SFR_MEM8(0x0208)
#define ADCA_CAL _SFR_MEM8(0x020C)
#define ADCA_CH0RES _SFR_MEM16(0x0210)
#define ADCA_CH0RESL _SFR_MEM8(0x0210)
#define ADCA_CH0RESH _SFR_MEM8(0x0211)
#define ADCA_CMP _SFR_MEM16(0x0218)
#define ADCA_CMPL _SFR_MEM8(0x0218)
#define ADCA_CMPH _SFR_MEM8(0x0219)
#define ADCA_CH0_CTRL _SFR_MEM8(0x0220)
#define ADCA_CH0_MUXCTRL _SFR_MEM8(0x0221)
#define ADCA_CH0_INTCTRL _SFR_MEM8(0x0222)
#define ADCA_CH0_INTFLAGS _SFR_MEM8(0x0223)
#define ADCA_CH0_RES _SFR_MEM16(0x0224)
#define ADCA_CH0_SCAN _SFR_MEM8(0x0226)
#define ADCA_CH0_CORRCTRL _SFR_MEM8(0x0227)
#define ADCA_CH0_OFFSETCORR0 _SFR_MEM8(0x0228)
#define ADCA_CH0_OFFSETCORR1 _SFR_MEM8(0x0229)
#define ADCA_CH0_GAINCORR0 _SFR_MEM8(0x022A)
#define ADCA_CH0_GAINCORR1 _SFR_MEM8(0x022B)
#define ADCA_CH0_AVGCTRL _SFR_MEM8(0x022C)
#define DACA_CTRLA _SFR_MEM8(0x0300)
#define DACA_CTRLB _SFR_MEM8(0x0301)
#define DACA_CTRLC _SFR_MEM8(0x0302)
#define DACA_EVCTRL _SFR_MEM8(0x0303)
#define DACA_STATUS _SFR_MEM8(0x0305)
#define DACA_CH0GAINCAL _SFR_MEM8(0x0308)
#define DACA_CH0OFFSETCAL _SFR_MEM8(0x0309)
#define DACA_CH1GAINCAL _SFR_MEM8(0x030A)
#define DACA_CH1OFFSETCAL _SFR_MEM8(0x030B)
#define DACA_CH0DATA _SFR_MEM16(0x0318)
#define DACA_CH0DATAL _SFR_MEM8(0x0318)
#define DACA_CH0DATAH _SFR_MEM8(0x0319)
#define DACA_CH1DATA _SFR_MEM16(0x031A)
#define DACA_CH1DATAL _SFR_MEM8(0x031A)
#define DACA_CH1DATAH _SFR_MEM8(0x031B)
#define ACA_AC0CTRL _SFR_MEM8(0x0380)
#define ACA_AC1CTRL _SFR_MEM8(0x0381)
#define ACA_AC0MUXCTRL _SFR_MEM8(0x0382)
#define ACA_AC1MUXCTRL _SFR_MEM8(0x0383)
#define ACA_CTRLA _SFR_MEM8(0x0384)
#define ACA_CTRLB _SFR_MEM8(0x0385)
#define ACA_WINCTRL _SFR_MEM8(0x0386)
#define ACA_STATUS _SFR_MEM8(0x0387)
#define ACA_CURRCTRL _SFR_MEM8(0x0388)
#define ACA_CURRCALIB _SFR_MEM8(0x0389)
#define RTC_CTRL _SFR_MEM8(0x0400)
#define RTC_STATUS _SFR_MEM8(0x0401)
#define RTC_INTCTRL _SFR_MEM8(0x0402)
#define RTC_INTFLAGS _SFR_MEM8(0x0403)
#define RTC_TEMP _SFR_MEM8(0x0404)
#define RTC_CALIB _SFR_MEM8(0x0406)
#define RTC_CNT _SFR_MEM16(0x0408)
#define RTC_CNTL _SFR_MEM8(0x0408)
#define RTC_CNTH _SFR_MEM8(0x0409)
#define RTC_PER _SFR_MEM16(0x040A)
#define RTC_PERL _SFR_MEM8(0x040A)
#define RTC_PERH _SFR_MEM8(0x040B)
#define RTC_COMP _SFR_MEM16(0x040C)
#define RTC_COMPL _SFR_MEM8(0x040C)
#define RTC_COMPH _SFR_MEM8(0x040D)
#define XCL_CTRLA _SFR_MEM8(0x0460)
#define XCL_CTRLB _SFR_MEM8(0x0461)
#define XCL_CTRLC _SFR_MEM8(0x0462)
#define XCL_CTRLD _SFR_MEM8(0x0463)
#define XCL_CTRLE _SFR_MEM8(0x0464)
#define XCL_CTRLF _SFR_MEM8(0x0465)
#define XCL_CTRLG _SFR_MEM8(0x0466)
#define XCL_INTCTRL _SFR_MEM8(0x0467)
#define XCL_INTFLAGS _SFR_MEM8(0x0468)
#define XCL_PLC _SFR_MEM8(0x0469)
#define XCL_CNTL _SFR_MEM8(0x046A)
#define XCL_CNTH _SFR_MEM8(0x046B)
#define XCL_CMPL _SFR_MEM8(0x046C)
#define XCL_CMPH _SFR_MEM8(0x046D)
#define XCL_PERCAPTL _SFR_MEM8(0x046E)
#define XCL_PERCAPTH _SFR_MEM8(0x046F)
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
#define TWIC_TIMEOUT_TOS _SFR_MEM8(0x048E)
#define TWIC_TIMEOUT_TOCONF _SFR_MEM8(0x048F)
#define PORTA_DIR _SFR_MEM8(0x0600)
#define PORTA_DIRSET _SFR_MEM8(0x0601)
#define PORTA_DIRCLR _SFR_MEM8(0x0602)
#define PORTA_DIRTGL _SFR_MEM8(0x0603)
#define PORTA_OUT _SFR_MEM8(0x0604)
#define PORTA_OUTSET _SFR_MEM8(0x0605)
#define PORTA_OUTCLR _SFR_MEM8(0x0606)
#define PORTA_OUTTGL _SFR_MEM8(0x0607)
#define PORTA_IN _SFR_MEM8(0x0608)
#define PORTA_INTCTRL _SFR_MEM8(0x0609)
#define PORTA_INTMASK _SFR_MEM8(0x060A)
#define PORTA_INTFLAGS _SFR_MEM8(0x060C)
#define PORTA_REMAP _SFR_MEM8(0x060E)
#define PORTA_PIN0CTRL _SFR_MEM8(0x0610)
#define PORTA_PIN1CTRL _SFR_MEM8(0x0611)
#define PORTA_PIN2CTRL _SFR_MEM8(0x0612)
#define PORTA_PIN3CTRL _SFR_MEM8(0x0613)
#define PORTA_PIN4CTRL _SFR_MEM8(0x0614)
#define PORTA_PIN5CTRL _SFR_MEM8(0x0615)
#define PORTA_PIN6CTRL _SFR_MEM8(0x0616)
#define PORTA_PIN7CTRL _SFR_MEM8(0x0617)
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
#define PORTC_INTMASK _SFR_MEM8(0x064A)
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
#define PORTD_INTMASK _SFR_MEM8(0x066A)
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
#define PORTR_INTMASK _SFR_MEM8(0x07EA)
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
#define TCC4_CTRLA _SFR_MEM8(0x0800)
#define TCC4_CTRLB _SFR_MEM8(0x0801)
#define TCC4_CTRLC _SFR_MEM8(0x0802)
#define TCC4_CTRLD _SFR_MEM8(0x0803)
#define TCC4_CTRLE _SFR_MEM8(0x0804)
#define TCC4_CTRLF _SFR_MEM8(0x0805)
#define TCC4_INTCTRLA _SFR_MEM8(0x0806)
#define TCC4_INTCTRLB _SFR_MEM8(0x0807)
#define TCC4_CTRLGCLR _SFR_MEM8(0x0808)
#define TCC4_CTRLGSET _SFR_MEM8(0x0809)
#define TCC4_CTRLHCLR _SFR_MEM8(0x080A)
#define TCC4_CTRLHSET _SFR_MEM8(0x080B)
#define TCC4_INTFLAGS _SFR_MEM8(0x080C)
#define TCC4_TEMP _SFR_MEM8(0x080F)
#define TCC4_CNT _SFR_MEM16(0x0820)
#define TCC4_CNTL _SFR_MEM8(0x0820)
#define TCC4_CNTH _SFR_MEM8(0x0821)
#define TCC4_PER _SFR_MEM16(0x0826)
#define TCC4_PERL _SFR_MEM8(0x0826)
#define TCC4_PERH _SFR_MEM8(0x0827)
#define TCC4_CCA _SFR_MEM16(0x0828)
#define TCC4_CCAL _SFR_MEM8(0x0828)
#define TCC4_CCAH _SFR_MEM8(0x0829)
#define TCC4_CCB _SFR_MEM16(0x082A)
#define TCC4_CCBL _SFR_MEM8(0x082A)
#define TCC4_CCBH _SFR_MEM8(0x082B)
#define TCC4_CCC _SFR_MEM16(0x082C)
#define TCC4_CCCL _SFR_MEM8(0x082C)
#define TCC4_CCCH _SFR_MEM8(0x082D)
#define TCC4_CCD _SFR_MEM16(0x082E)
#define TCC4_CCDL _SFR_MEM8(0x082E)
#define TCC4_CCDH _SFR_MEM8(0x082F)
#define TCC4_PERBUF _SFR_MEM16(0x0836)
#define TCC4_PERBUFL _SFR_MEM8(0x0836)
#define TCC4_PERBUFH _SFR_MEM8(0x0837)
#define TCC4_CCABUF _SFR_MEM16(0x0838)
#define TCC4_CCABUFL _SFR_MEM8(0x0838)
#define TCC4_CCABUFH _SFR_MEM8(0x0839)
#define TCC4_CCBBUF _SFR_MEM16(0x083A)
#define TCC4_CCBBUFL _SFR_MEM8(0x083A)
#define TCC4_CCBBUFH _SFR_MEM8(0x083B)
#define TCC4_CCCBUF _SFR_MEM16(0x083C)
#define TCC4_CCCBUFL _SFR_MEM8(0x083C)
#define TCC4_CCCBUFH _SFR_MEM8(0x083D)
#define TCC4_CCDBUF _SFR_MEM16(0x083E)
#define TCC4_CCDBUFL _SFR_MEM8(0x083E)
#define TCC4_CCDBUFH _SFR_MEM8(0x083F)
#define TCC5_CTRLA _SFR_MEM8(0x0840)
#define TCC5_CTRLB _SFR_MEM8(0x0841)
#define TCC5_CTRLC _SFR_MEM8(0x0842)
#define TCC5_CTRLD _SFR_MEM8(0x0843)
#define TCC5_CTRLE _SFR_MEM8(0x0844)
#define TCC5_CTRLF _SFR_MEM8(0x0845)
#define TCC5_INTCTRLA _SFR_MEM8(0x0846)
#define TCC5_INTCTRLB _SFR_MEM8(0x0847)
#define TCC5_CTRLGCLR _SFR_MEM8(0x0848)
#define TCC5_CTRLGSET _SFR_MEM8(0x0849)
#define TCC5_CTRLHCLR _SFR_MEM8(0x084A)
#define TCC5_CTRLHSET _SFR_MEM8(0x084B)
#define TCC5_INTFLAGS _SFR_MEM8(0x084C)
#define TCC5_TEMP _SFR_MEM8(0x084F)
#define TCC5_CNT _SFR_MEM16(0x0860)
#define TCC5_CNTL _SFR_MEM8(0x0860)
#define TCC5_CNTH _SFR_MEM8(0x0861)
#define TCC5_PER _SFR_MEM16(0x0866)
#define TCC5_PERL _SFR_MEM8(0x0866)
#define TCC5_PERH _SFR_MEM8(0x0867)
#define TCC5_CCA _SFR_MEM16(0x0868)
#define TCC5_CCAL _SFR_MEM8(0x0868)
#define TCC5_CCAH _SFR_MEM8(0x0869)
#define TCC5_CCB _SFR_MEM16(0x086A)
#define TCC5_CCBL _SFR_MEM8(0x086A)
#define TCC5_CCBH _SFR_MEM8(0x086B)
#define TCC5_PERBUF _SFR_MEM16(0x0876)
#define TCC5_PERBUFL _SFR_MEM8(0x0876)
#define TCC5_PERBUFH _SFR_MEM8(0x0877)
#define TCC5_CCABUF _SFR_MEM16(0x0878)
#define TCC5_CCABUFL _SFR_MEM8(0x0878)
#define TCC5_CCABUFH _SFR_MEM8(0x0879)
#define TCC5_CCBBUF _SFR_MEM16(0x087A)
#define TCC5_CCBBUFL _SFR_MEM8(0x087A)
#define TCC5_CCBBUFH _SFR_MEM8(0x087B)
#define FAULTC4_CTRLA _SFR_MEM8(0x0880)
#define FAULTC4_CTRLB _SFR_MEM8(0x0881)
#define FAULTC4_CTRLC _SFR_MEM8(0x0882)
#define FAULTC4_CTRLD _SFR_MEM8(0x0883)
#define FAULTC4_CTRLE _SFR_MEM8(0x0884)
#define FAULTC4_STATUS _SFR_MEM8(0x0885)
#define FAULTC4_CTRLGCLR _SFR_MEM8(0x0886)
#define FAULTC4_CTRLGSET _SFR_MEM8(0x0887)
#define FAULTC5_CTRLA _SFR_MEM8(0x0890)
#define FAULTC5_CTRLB _SFR_MEM8(0x0891)
#define FAULTC5_CTRLC _SFR_MEM8(0x0892)
#define FAULTC5_CTRLD _SFR_MEM8(0x0893)
#define FAULTC5_CTRLE _SFR_MEM8(0x0894)
#define FAULTC5_STATUS _SFR_MEM8(0x0895)
#define FAULTC5_CTRLGCLR _SFR_MEM8(0x0896)
#define FAULTC5_CTRLGSET _SFR_MEM8(0x0897)
#define WEXC_CTRL _SFR_MEM8(0x08A0)
#define WEXC_DTBOTH _SFR_MEM8(0x08A1)
#define WEXC_DTLS _SFR_MEM8(0x08A2)
#define WEXC_DTHS _SFR_MEM8(0x08A3)
#define WEXC_STATUSCLR _SFR_MEM8(0x08A4)
#define WEXC_STATUSSET _SFR_MEM8(0x08A5)
#define WEXC_SWAP _SFR_MEM8(0x08A6)
#define WEXC_PGO _SFR_MEM8(0x08A7)
#define WEXC_PGV _SFR_MEM8(0x08A8)
#define WEXC_SWAPBUF _SFR_MEM8(0x08AA)
#define WEXC_PGOBUF _SFR_MEM8(0x08AB)
#define WEXC_PGVBUF _SFR_MEM8(0x08AC)
#define WEXC_OUTOVDIS _SFR_MEM8(0x08AF)
#define HIRESC_CTRLA _SFR_MEM8(0x08B0)
#define USARTC0_DATA _SFR_MEM8(0x08C0)
#define USARTC0_STATUS _SFR_MEM8(0x08C1)
#define USARTC0_CTRLA _SFR_MEM8(0x08C2)
#define USARTC0_CTRLB _SFR_MEM8(0x08C3)
#define USARTC0_CTRLC _SFR_MEM8(0x08C4)
#define USARTC0_CTRLD _SFR_MEM8(0x08C5)
#define USARTC0_BAUDCTRLA _SFR_MEM8(0x08C6)
#define USARTC0_BAUDCTRLB _SFR_MEM8(0x08C7)
#define SPIC_CTRL _SFR_MEM8(0x08E0)
#define SPIC_INTCTRL _SFR_MEM8(0x08E1)
#define SPIC_STATUS _SFR_MEM8(0x08E2)
#define SPIC_DATA _SFR_MEM8(0x08E3)
#define SPIC_CTRLB _SFR_MEM8(0x08E4)
#define IRCOM_CTRL _SFR_MEM8(0x08F8)
#define IRCOM_TXPLCTRL _SFR_MEM8(0x08F9)
#define IRCOM_RXPLCTRL _SFR_MEM8(0x08FA)
#define TCD5_CTRLA _SFR_MEM8(0x0940)
#define TCD5_CTRLB _SFR_MEM8(0x0941)
#define TCD5_CTRLC _SFR_MEM8(0x0942)
#define TCD5_CTRLD _SFR_MEM8(0x0943)
#define TCD5_CTRLE _SFR_MEM8(0x0944)
#define TCD5_CTRLF _SFR_MEM8(0x0945)
#define TCD5_INTCTRLA _SFR_MEM8(0x0946)
#define TCD5_INTCTRLB _SFR_MEM8(0x0947)
#define TCD5_CTRLGCLR _SFR_MEM8(0x0948)
#define TCD5_CTRLGSET _SFR_MEM8(0x0949)
#define TCD5_CTRLHCLR _SFR_MEM8(0x094A)
#define TCD5_CTRLHSET _SFR_MEM8(0x094B)
#define TCD5_INTFLAGS _SFR_MEM8(0x094C)
#define TCD5_TEMP _SFR_MEM8(0x094F)
#define TCD5_CNT _SFR_MEM16(0x0960)
#define TCD5_CNTL _SFR_MEM8(0x0960)
#define TCD5_CNTH _SFR_MEM8(0x0961)
#define TCD5_PER _SFR_MEM16(0x0966)
#define TCD5_PERL _SFR_MEM8(0x0966)
#define TCD5_PERH _SFR_MEM8(0x0967)
#define TCD5_CCA _SFR_MEM16(0x0968)
#define TCD5_CCAL _SFR_MEM8(0x0968)
#define TCD5_CCAH _SFR_MEM8(0x0969)
#define TCD5_CCB _SFR_MEM16(0x096A)
#define TCD5_CCBL _SFR_MEM8(0x096A)
#define TCD5_CCBH _SFR_MEM8(0x096B)
#define TCD5_PERBUF _SFR_MEM16(0x0976)
#define TCD5_PERBUFL _SFR_MEM8(0x0976)
#define TCD5_PERBUFH _SFR_MEM8(0x0977)
#define TCD5_CCABUF _SFR_MEM16(0x0978)
#define TCD5_CCABUFL _SFR_MEM8(0x0978)
#define TCD5_CCABUFH _SFR_MEM8(0x0979)
#define TCD5_CCBBUF _SFR_MEM16(0x097A)
#define TCD5_CCBBUFL _SFR_MEM8(0x097A)
#define TCD5_CCBBUFH _SFR_MEM8(0x097B)
#define USARTD0_DATA _SFR_MEM8(0x09C0)
#define USARTD0_STATUS _SFR_MEM8(0x09C1)
#define USARTD0_CTRLA _SFR_MEM8(0x09C2)
#define USARTD0_CTRLB _SFR_MEM8(0x09C3)
#define USARTD0_CTRLC _SFR_MEM8(0x09C4)
#define USARTD0_CTRLD _SFR_MEM8(0x09C5)
#define USARTD0_BAUDCTRLA _SFR_MEM8(0x09C6)
#define USARTD0_BAUDCTRLB _SFR_MEM8(0x09C7)
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
#define AC_AC0INVEN_bm 0x04
#define AC_AC0INVEN_bp 2
#define AC_AC1INVEN_bm 0x08
#define AC_AC1INVEN_bp 3
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
#define ADC_CH_IF_bm 0x01
#define ADC_CH_IF_bp 0
#define ADC_CH_INPUTSCAN_gm 0x0F
#define ADC_CH_INPUTSCAN_gp 0
#define ADC_CH_INPUTSCAN0_bm (1<<0)
#define ADC_CH_INPUTSCAN0_bp 0
#define ADC_CH_INPUTSCAN1_bm (1<<1)
#define ADC_CH_INPUTSCAN1_bp 1
#define ADC_CH_INPUTSCAN2_bm (1<<2)
#define ADC_CH_INPUTSCAN2_bp 2
#define ADC_CH_INPUTSCAN3_bm (1<<3)
#define ADC_CH_INPUTSCAN3_bp 3
#define ADC_CH_INPUTOFFSET_gm 0xF0
#define ADC_CH_INPUTOFFSET_gp 4
#define ADC_CH_INPUTOFFSET0_bm (1<<4)
#define ADC_CH_INPUTOFFSET0_bp 4
#define ADC_CH_INPUTOFFSET1_bm (1<<5)
#define ADC_CH_INPUTOFFSET1_bp 5
#define ADC_CH_INPUTOFFSET2_bm (1<<6)
#define ADC_CH_INPUTOFFSET2_bp 6
#define ADC_CH_INPUTOFFSET3_bm (1<<7)
#define ADC_CH_INPUTOFFSET3_bp 7
#define ADC_CH_CORREN_bm 0x01
#define ADC_CH_CORREN_bp 0
#define ADC_CH_OFFSETCORR_gm 0x0F
#define ADC_CH_OFFSETCORR_gp 0
#define ADC_CH_OFFSETCORR0_bm (1<<0)
#define ADC_CH_OFFSETCORR0_bp 0
#define ADC_CH_OFFSETCORR1_bm (1<<1)
#define ADC_CH_OFFSETCORR1_bp 1
#define ADC_CH_OFFSETCORR2_bm (1<<2)
#define ADC_CH_OFFSETCORR2_bp 2
#define ADC_CH_OFFSETCORR3_bm (1<<3)
#define ADC_CH_OFFSETCORR3_bp 3
#define ADC_CH_GAINCORR_gm 0x0F
#define ADC_CH_GAINCORR_gp 0
#define ADC_CH_GAINCORR0_bm (1<<0)
#define ADC_CH_GAINCORR0_bp 0
#define ADC_CH_GAINCORR1_bm (1<<1)
#define ADC_CH_GAINCORR1_bp 1
#define ADC_CH_GAINCORR2_bm (1<<2)
#define ADC_CH_GAINCORR2_bp 2
#define ADC_CH_GAINCORR3_bm (1<<3)
#define ADC_CH_GAINCORR3_bp 3
#define ADC_CH_SAMPNUM_gm 0x0F
#define ADC_CH_SAMPNUM_gp 0
#define ADC_CH_SAMPNUM0_bm (1<<0)
#define ADC_CH_SAMPNUM0_bp 0
#define ADC_CH_SAMPNUM1_bm (1<<1)
#define ADC_CH_SAMPNUM1_bp 1
#define ADC_CH_SAMPNUM2_bm (1<<2)
#define ADC_CH_SAMPNUM2_bp 2
#define ADC_CH_SAMPNUM3_bm (1<<3)
#define ADC_CH_SAMPNUM3_bp 3
#define ADC_CH_RIGHTSHIFT_gm 0x70
#define ADC_CH_RIGHTSHIFT_gp 4
#define ADC_CH_RIGHTSHIFT0_bm (1<<4)
#define ADC_CH_RIGHTSHIFT0_bp 4
#define ADC_CH_RIGHTSHIFT1_bm (1<<5)
#define ADC_CH_RIGHTSHIFT1_bp 5
#define ADC_CH_RIGHTSHIFT2_bm (1<<6)
#define ADC_CH_RIGHTSHIFT2_bp 6
#define ADC_ENABLE_bm 0x01
#define ADC_ENABLE_bp 0
#define ADC_FLUSH_bm 0x02
#define ADC_FLUSH_bp 1
#define ADC_START_bm 0x04
#define ADC_START_bp 2
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
#define ADC_EVSEL_gm 0x38
#define ADC_EVSEL_gp 3
#define ADC_EVSEL0_bm (1<<3)
#define ADC_EVSEL0_bp 3
#define ADC_EVSEL1_bm (1<<4)
#define ADC_EVSEL1_bp 4
#define ADC_EVSEL2_bm (1<<5)
#define ADC_EVSEL2_bp 5
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
#define DAC_ENABLE_bm 0x01
#define DAC_ENABLE_bp 0
#define DAC_LPMODE_bm 0x02
#define DAC_LPMODE_bp 1
#define DAC_CH0EN_bm 0x04
#define DAC_CH0EN_bp 2
#define DAC_CH1EN_bm 0x08
#define DAC_CH1EN_bp 3
#define DAC_IDOEN_bm 0x10
#define DAC_IDOEN_bp 4
#define DAC_CH0TRIG_bm 0x01
#define DAC_CH0TRIG_bp 0
#define DAC_CH1TRIG_bm 0x02
#define DAC_CH1TRIG_bp 1
#define DAC_CHSEL_gm 0x60
#define DAC_CHSEL_gp 5
#define DAC_CHSEL0_bm (1<<5)
#define DAC_CHSEL0_bp 5
#define DAC_CHSEL1_bm (1<<6)
#define DAC_CHSEL1_bp 6
#define DAC_LEFTADJ_bm 0x01
#define DAC_LEFTADJ_bp 0
#define DAC_REFSEL_gm 0x18
#define DAC_REFSEL_gp 3
#define DAC_REFSEL0_bm (1<<3)
#define DAC_REFSEL0_bp 3
#define DAC_REFSEL1_bm (1<<4)
#define DAC_REFSEL1_bp 4
#define DAC_EVSEL_gm 0x07
#define DAC_EVSEL_gp 0
#define DAC_EVSEL0_bm (1<<0)
#define DAC_EVSEL0_bp 0
#define DAC_EVSEL1_bm (1<<1)
#define DAC_EVSEL1_bp 1
#define DAC_EVSEL2_bm (1<<2)
#define DAC_EVSEL2_bp 2
#define DAC_EVSPLIT_bm 0x08
#define DAC_EVSPLIT_bp 3
#define DAC_CH0DRE_bm 0x01
#define DAC_CH0DRE_bp 0
#define DAC_CH1DRE_bm 0x02
#define DAC_CH1DRE_bp 1
#define DAC_CH0GAINCAL_gm 0x7F
#define DAC_CH0GAINCAL_gp 0
#define DAC_CH0GAINCAL0_bm (1<<0)
#define DAC_CH0GAINCAL0_bp 0
#define DAC_CH0GAINCAL1_bm (1<<1)
#define DAC_CH0GAINCAL1_bp 1
#define DAC_CH0GAINCAL2_bm (1<<2)
#define DAC_CH0GAINCAL2_bp 2
#define DAC_CH0GAINCAL3_bm (1<<3)
#define DAC_CH0GAINCAL3_bp 3
#define DAC_CH0GAINCAL4_bm (1<<4)
#define DAC_CH0GAINCAL4_bp 4
#define DAC_CH0GAINCAL5_bm (1<<5)
#define DAC_CH0GAINCAL5_bp 5
#define DAC_CH0GAINCAL6_bm (1<<6)
#define DAC_CH0GAINCAL6_bp 6
#define DAC_CH0OFFSETCAL_gm 0x7F
#define DAC_CH0OFFSETCAL_gp 0
#define DAC_CH0OFFSETCAL0_bm (1<<0)
#define DAC_CH0OFFSETCAL0_bp 0
#define DAC_CH0OFFSETCAL1_bm (1<<1)
#define DAC_CH0OFFSETCAL1_bp 1
#define DAC_CH0OFFSETCAL2_bm (1<<2)
#define DAC_CH0OFFSETCAL2_bp 2
#define DAC_CH0OFFSETCAL3_bm (1<<3)
#define DAC_CH0OFFSETCAL3_bp 3
#define DAC_CH0OFFSETCAL4_bm (1<<4)
#define DAC_CH0OFFSETCAL4_bp 4
#define DAC_CH0OFFSETCAL5_bm (1<<5)
#define DAC_CH0OFFSETCAL5_bp 5
#define DAC_CH0OFFSETCAL6_bm (1<<6)
#define DAC_CH0OFFSETCAL6_bp 6
#define DAC_CH1GAINCAL_gm 0x7F
#define DAC_CH1GAINCAL_gp 0
#define DAC_CH1GAINCAL0_bm (1<<0)
#define DAC_CH1GAINCAL0_bp 0
#define DAC_CH1GAINCAL1_bm (1<<1)
#define DAC_CH1GAINCAL1_bp 1
#define DAC_CH1GAINCAL2_bm (1<<2)
#define DAC_CH1GAINCAL2_bp 2
#define DAC_CH1GAINCAL3_bm (1<<3)
#define DAC_CH1GAINCAL3_bp 3
#define DAC_CH1GAINCAL4_bm (1<<4)
#define DAC_CH1GAINCAL4_bp 4
#define DAC_CH1GAINCAL5_bm (1<<5)
#define DAC_CH1GAINCAL5_bp 5
#define DAC_CH1GAINCAL6_bm (1<<6)
#define DAC_CH1GAINCAL6_bp 6
#define DAC_CH1OFFSETCAL_gm 0x7F
#define DAC_CH1OFFSETCAL_gp 0
#define DAC_CH1OFFSETCAL0_bm (1<<0)
#define DAC_CH1OFFSETCAL0_bp 0
#define DAC_CH1OFFSETCAL1_bm (1<<1)
#define DAC_CH1OFFSETCAL1_bp 1
#define DAC_CH1OFFSETCAL2_bm (1<<2)
#define DAC_CH1OFFSETCAL2_bp 2
#define DAC_CH1OFFSETCAL3_bm (1<<3)
#define DAC_CH1OFFSETCAL3_bp 3
#define DAC_CH1OFFSETCAL4_bm (1<<4)
#define DAC_CH1OFFSETCAL4_bp 4
#define DAC_CH1OFFSETCAL5_bm (1<<5)
#define DAC_CH1OFFSETCAL5_bp 5
#define DAC_CH1OFFSETCAL6_bm (1<<6)
#define DAC_CH1OFFSETCAL6_bp 6
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
#define EDMA_PRIMODE_gm 0x03
#define EDMA_PRIMODE_gp 0
#define EDMA_PRIMODE0_bm (1<<0)
#define EDMA_PRIMODE0_bp 0
#define EDMA_PRIMODE1_bm (1<<1)
#define EDMA_PRIMODE1_bp 1
#define EDMA_DBUFMODE_gm 0x0C
#define EDMA_DBUFMODE_gp 2
#define EDMA_DBUFMODE0_bm (1<<2)
#define EDMA_DBUFMODE0_bp 2
#define EDMA_DBUFMODE1_bm (1<<3)
#define EDMA_DBUFMODE1_bp 3
#define EDMA_CHMODE_gm 0x30
#define EDMA_CHMODE_gp 4
#define EDMA_CHMODE0_bm (1<<4)
#define EDMA_CHMODE0_bp 4
#define EDMA_CHMODE1_bm (1<<5)
#define EDMA_CHMODE1_bp 5
#define EDMA_RESET_bm 0x40
#define EDMA_RESET_bp 6
#define EDMA_ENABLE_bm 0x80
#define EDMA_ENABLE_bp 7
#define EDMA_CH0TRNFIF_bm 0x01
#define EDMA_CH0TRNFIF_bp 0
#define EDMA_CH1TRNFIF_bm 0x02
#define EDMA_CH1TRNFIF_bp 1
#define EDMA_CH2TRNFIF_bm 0x04
#define EDMA_CH2TRNFIF_bp 2
#define EDMA_CH3TRNFIF_bm 0x08
#define EDMA_CH3TRNFIF_bp 3
#define EDMA_CH0ERRIF_bm 0x10
#define EDMA_CH0ERRIF_bp 4
#define EDMA_CH1ERRIF_bm 0x20
#define EDMA_CH1ERRIF_bp 5
#define EDMA_CH2ERRIF_bm 0x40
#define EDMA_CH2ERRIF_bp 6
#define EDMA_CH3ERRIF_bm 0x80
#define EDMA_CH3ERRIF_bp 7
#define EDMA_CH0PEND_bm 0x01
#define EDMA_CH0PEND_bp 0
#define EDMA_CH1PEND_bm 0x02
#define EDMA_CH1PEND_bp 1
#define EDMA_CH2PEND_bm 0x04
#define EDMA_CH2PEND_bp 2
#define EDMA_CH3PEND_bm 0x08
#define EDMA_CH3PEND_bp 3
#define EDMA_CH0BUSY_bm 0x10
#define EDMA_CH0BUSY_bp 4
#define EDMA_CH1BUSY_bm 0x20
#define EDMA_CH1BUSY_bp 5
#define EDMA_CH2BUSY_bm 0x40
#define EDMA_CH2BUSY_bp 6
#define EDMA_CH3BUSY_bm 0x80
#define EDMA_CH3BUSY_bp 7
#define EDMA_CH_BURSTLEN_bm 0x01
#define EDMA_CH_BURSTLEN_bp 0
#define EDMA_CH_SINGLE_bm 0x04
#define EDMA_CH_SINGLE_bp 2
#define EDMA_CH_TRFREQ_bm 0x10
#define EDMA_CH_TRFREQ_bp 4
#define EDMA_CH_REPEAT_bm 0x20
#define EDMA_CH_REPEAT_bp 5
#define EDMA_CH_RESET_bm 0x40
#define EDMA_CH_RESET_bp 6
#define EDMA_CH_ENABLE_bm 0x80
#define EDMA_CH_ENABLE_bp 7
#define EDMA_CH_TRNINTLVL_gm 0x03
#define EDMA_CH_TRNINTLVL_gp 0
#define EDMA_CH_TRNINTLVL0_bm (1<<0)
#define EDMA_CH_TRNINTLVL0_bp 0
#define EDMA_CH_TRNINTLVL1_bm (1<<1)
#define EDMA_CH_TRNINTLVL1_bp 1
#define EDMA_CH_ERRINTLVL_gm 0x0C
#define EDMA_CH_ERRINTLVL_gp 2
#define EDMA_CH_ERRINTLVL0_bm (1<<2)
#define EDMA_CH_ERRINTLVL0_bp 2
#define EDMA_CH_ERRINTLVL1_bm (1<<3)
#define EDMA_CH_ERRINTLVL1_bp 3
#define EDMA_CH_TRNIF_bm 0x10
#define EDMA_CH_TRNIF_bp 4
#define EDMA_CH_ERRIF_bm 0x20
#define EDMA_CH_ERRIF_bp 5
#define EDMA_CH_CHPEND_bm 0x40
#define EDMA_CH_CHPEND_bp 6
#define EDMA_CH_CHBUSY_bm 0x80
#define EDMA_CH_CHBUSY_bp 7
#define EDMA_CH_DIR_gm 0x07
#define EDMA_CH_DIR_gp 0
#define EDMA_CH_DIR0_bm (1<<0)
#define EDMA_CH_DIR0_bp 0
#define EDMA_CH_DIR1_bm (1<<1)
#define EDMA_CH_DIR1_bp 1
#define EDMA_CH_DIR2_bm (1<<2)
#define EDMA_CH_DIR2_bp 2
#define EDMA_CH_RELOAD_gm 0x30
#define EDMA_CH_RELOAD_gp 4
#define EDMA_CH_RELOAD0_bm (1<<4)
#define EDMA_CH_RELOAD0_bp 4
#define EDMA_CH_RELOAD1_bm (1<<5)
#define EDMA_CH_RELOAD1_bp 5
#define EDMA_CH_DESTDIR_gm 0x07
#define EDMA_CH_DESTDIR_gp 0
#define EDMA_CH_DESTDIR0_bm (1<<0)
#define EDMA_CH_DESTDIR0_bp 0
#define EDMA_CH_DESTDIR1_bm (1<<1)
#define EDMA_CH_DESTDIR1_bp 1
#define EDMA_CH_DESTDIR2_bm (1<<2)
#define EDMA_CH_DESTDIR2_bp 2
#define EDMA_CH_DESTRELOAD_gm 0x30
#define EDMA_CH_DESTRELOAD_gp 4
#define EDMA_CH_DESTRELOAD0_bm (1<<4)
#define EDMA_CH_DESTRELOAD0_bp 4
#define EDMA_CH_DESTRELOAD1_bm (1<<5)
#define EDMA_CH_DESTRELOAD1_bp 5
#define EDMA_CH_TRIGSRC_gm 0xFF
#define EDMA_CH_TRIGSRC_gp 0
#define EDMA_CH_TRIGSRC0_bm (1<<0)
#define EDMA_CH_TRIGSRC0_bp 0
#define EDMA_CH_TRIGSRC1_bm (1<<1)
#define EDMA_CH_TRIGSRC1_bp 1
#define EDMA_CH_TRIGSRC2_bm (1<<2)
#define EDMA_CH_TRIGSRC2_bp 2
#define EDMA_CH_TRIGSRC3_bm (1<<3)
#define EDMA_CH_TRIGSRC3_bp 3
#define EDMA_CH_TRIGSRC4_bm (1<<4)
#define EDMA_CH_TRIGSRC4_bp 4
#define EDMA_CH_TRIGSRC5_bm (1<<5)
#define EDMA_CH_TRIGSRC5_bp 5
#define EDMA_CH_TRIGSRC6_bm (1<<6)
#define EDMA_CH_TRIGSRC6_bp 6
#define EDMA_CH_TRIGSRC7_bm (1<<7)
#define EDMA_CH_TRIGSRC7_bp 7
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
#define EVSYS_ROTARY_bm 0x80
#define EVSYS_ROTARY_bp 7
#define EVSYS_PRESC_gm 0x07
#define EVSYS_PRESC_gp 0
#define EVSYS_PRESC0_bm (1<<0)
#define EVSYS_PRESC0_bp 0
#define EVSYS_PRESC1_bm (1<<1)
#define EVSYS_PRESC1_bp 1
#define EVSYS_PRESC2_bm (1<<2)
#define EVSYS_PRESC2_bp 2
#define EVSYS_FILTSEL_bm 0x08
#define EVSYS_FILTSEL_bp 3
#define EVSYS_PRESCFILT_gm 0xF0
#define EVSYS_PRESCFILT_gp 4
#define EVSYS_PRESCFILT0_bm (1<<4)
#define EVSYS_PRESCFILT0_bp 4
#define EVSYS_PRESCFILT1_bm (1<<5)
#define EVSYS_PRESCFILT1_bp 5
#define EVSYS_PRESCFILT2_bm (1<<6)
#define EVSYS_PRESCFILT2_bp 6
#define EVSYS_PRESCFILT3_bm (1<<7)
#define EVSYS_PRESCFILT3_bp 7
#define FAULT_SRCE_gm 0x03
#define FAULT_SRCE_gp 0
#define FAULT_SRCE0_bm (1<<0)
#define FAULT_SRCE0_bp 0
#define FAULT_SRCE1_bm (1<<1)
#define FAULT_SRCE1_bp 1
#define FAULT_FILTERE_bm 0x04
#define FAULT_FILTERE_bp 2
#define FAULT_FUSE_bm 0x08
#define FAULT_FUSE_bp 3
#define FAULT_PORTCTRL_bm 0x10
#define FAULT_PORTCTRL_bp 4
#define FAULT_FDDBD_bm 0x20
#define FAULT_FDDBD_bp 5
#define FAULT_RAMP_gm 0xC0
#define FAULT_RAMP_gp 6
#define FAULT_RAMP0_bm (1<<6)
#define FAULT_RAMP0_bp 6
#define FAULT_RAMP1_bm (1<<7)
#define FAULT_RAMP1_bp 7
#define FAULT_SRCA_gm 0x03
#define FAULT_SRCA_gp 0
#define FAULT_SRCA0_bm (1<<0)
#define FAULT_SRCA0_bp 0
#define FAULT_SRCA1_bm (1<<1)
#define FAULT_SRCA1_bp 1
#define FAULT_KEEPA_bm 0x08
#define FAULT_KEEPA_bp 3
#define FAULT_RESTARTA_bm 0x10
#define FAULT_RESTARTA_bp 4
#define FAULT_HALTA_gm 0x60
#define FAULT_HALTA_gp 5
#define FAULT_HALTA0_bm (1<<5)
#define FAULT_HALTA0_bp 5
#define FAULT_HALTA1_bm (1<<6)
#define FAULT_HALTA1_bp 6
#define FAULT_SOFTA_bm 0x80
#define FAULT_SOFTA_bp 7
#define FAULT_QUALA_bm 0x01
#define FAULT_QUALA_bp 0
#define FAULT_BLANKA_bm 0x02
#define FAULT_BLANKA_bp 1
#define FAULT_FILTERA_bm 0x04
#define FAULT_FILTERA_bp 2
#define FAULT_CAPTA_bm 0x20
#define FAULT_CAPTA_bp 5
#define FAULT_SRCB_gm 0x03
#define FAULT_SRCB_gp 0
#define FAULT_SRCB0_bm (1<<0)
#define FAULT_SRCB0_bp 0
#define FAULT_SRCB1_bm (1<<1)
#define FAULT_SRCB1_bp 1
#define FAULT_KEEPB_bm 0x08
#define FAULT_KEEPB_bp 3
#define FAULT_RESTARTB_bm 0x10
#define FAULT_RESTARTB_bp 4
#define FAULT_HALTB_gm 0x60
#define FAULT_HALTB_gp 5
#define FAULT_HALTB0_bm (1<<5)
#define FAULT_HALTB0_bp 5
#define FAULT_HALTB1_bm (1<<6)
#define FAULT_HALTB1_bp 6
#define FAULT_SOFTB_bm 0x80
#define FAULT_SOFTB_bp 7
#define FAULT_QUALB_bm 0x01
#define FAULT_QUALB_bp 0
#define FAULT_BLANKB_bm 0x02
#define FAULT_BLANKB_bp 1
#define FAULT_FILTERB_bm 0x04
#define FAULT_FILTERB_bp 2
#define FAULT_CAPTB_bm 0x20
#define FAULT_CAPTB_bp 5
#define FAULT_FAULTEIN_bm 0x01
#define FAULT_FAULTEIN_bp 0
#define FAULT_FAULTAIN_bm 0x02
#define FAULT_FAULTAIN_bp 1
#define FAULT_FAULTBIN_bm 0x04
#define FAULT_FAULTBIN_bp 2
#define FAULT_IDX_bm 0x08
#define FAULT_IDX_bp 3
#define FAULT_STATEE_bm 0x20
#define FAULT_STATEE_bp 5
#define FAULT_STATEA_bm 0x40
#define FAULT_STATEA_bp 6
#define FAULT_STATEB_bm 0x80
#define FAULT_STATEB_bp 7
#define FAULT_FAULTE_bm 0x01
#define FAULT_FAULTE_bp 0
#define FAULT_FAULTA_bm 0x02
#define FAULT_FAULTA_bp 1
#define FAULT_FAULTB_bm 0x04
#define FAULT_FAULTB_bp 2
#define FAULT_STATEECLR_bm 0x20
#define FAULT_STATEECLR_bp 5
#define FAULT_HALTACLR_bm 0x40
#define FAULT_HALTACLR_bp 6
#define FAULT_HALTBCLR_bm 0x80
#define FAULT_HALTBCLR_bp 7
#define FAULT_IDXCMD_gm 0x18
#define FAULT_IDXCMD_gp 3
#define FAULT_IDXCMD0_bm (1<<3)
#define FAULT_IDXCMD0_bp 3
#define FAULT_IDXCMD1_bm (1<<4)
#define FAULT_IDXCMD1_bp 4
#define FAULT_FAULTESW_bm 0x20
#define FAULT_FAULTESW_bp 5
#define FAULT_FAULTASW_bm 0x40
#define FAULT_FAULTASW_bp 6
#define FAULT_FAULTBSW_bm 0x80
#define FAULT_FAULTBSW_bp 7
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
#define NVM_FUSES_BOOTRST_bm 0x40
#define NVM_FUSES_BOOTRST_bp 6
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
#define NVM_FUSES_VALUE_gm 0x3F
#define NVM_FUSES_VALUE_gp 0
#define NVM_FUSES_VALUE0_bm (1<<0)
#define NVM_FUSES_VALUE0_bp 0
#define NVM_FUSES_VALUE1_bm (1<<1)
#define NVM_FUSES_VALUE1_bp 1
#define NVM_FUSES_VALUE2_bm (1<<2)
#define NVM_FUSES_VALUE2_bp 2
#define NVM_FUSES_VALUE3_bm (1<<3)
#define NVM_FUSES_VALUE3_bp 3
#define NVM_FUSES_VALUE4_bm (1<<4)
#define NVM_FUSES_VALUE4_bp 4
#define NVM_FUSES_VALUE5_bm (1<<5)
#define NVM_FUSES_VALUE5_bp 5
#define NVM_FUSES_FDACT4_bm 0x40
#define NVM_FUSES_FDACT4_bp 6
#define NVM_FUSES_FDACT5_bm 0x80
#define NVM_FUSES_FDACT5_bp 7
#define HIRES_HREN_gm 0x03
#define HIRES_HREN_gp 0
#define HIRES_HREN0_bm (1<<0)
#define HIRES_HREN0_bp 0
#define HIRES_HREN1_bm (1<<1)
#define HIRES_HREN1_bp 1
#define HIRES_HRPLUS_gm 0x0C
#define HIRES_HRPLUS_gp 2
#define HIRES_HRPLUS0_bm (1<<2)
#define HIRES_HRPLUS0_bp 2
#define HIRES_HRPLUS1_bm (1<<3)
#define HIRES_HRPLUS1_bp 3
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
#define MCU_STARTUPDLYA_gm 0x03
#define MCU_STARTUPDLYA_gp 0
#define MCU_STARTUPDLYA0_bm (1<<0)
#define MCU_STARTUPDLYA0_bp 0
#define MCU_STARTUPDLYA1_bm (1<<1)
#define MCU_STARTUPDLYA1_bp 1
#define MCU_EVSYS0LOCK_bm 0x01
#define MCU_EVSYS0LOCK_bp 0
#define MCU_EVSYS1LOCK_bm 0x10
#define MCU_EVSYS1LOCK_bp 4
#define MCU_WEXCLOCK_bm 0x01
#define MCU_WEXCLOCK_bp 0
#define MCU_FAULTC4LOCK_bm 0x01
#define MCU_FAULTC4LOCK_bp 0
#define MCU_FAULTC5LOCK_bm 0x02
#define MCU_FAULTC5LOCK_bp 1
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
#define OSC_RC8MEN_bm 0x20
#define OSC_RC8MEN_bp 5
#define OSC_RC8MLPM_bm 0x40
#define OSC_RC8MLPM_bp 6
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
#define OSC_RC8MRDY_bm 0x20
#define OSC_RC8MRDY_bp 5
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
#define OSC_RC32MCREF_gm 0x06
#define OSC_RC32MCREF_gp 1
#define OSC_RC32MCREF0_bm (1<<1)
#define OSC_RC32MCREF0_bp 1
#define OSC_RC32MCREF1_bm (1<<2)
#define OSC_RC32MCREF1_bp 2
#define OSC_RC8MCAL_gm 0xFF
#define OSC_RC8MCAL_gp 0
#define OSC_RC8MCAL0_bm (1<<0)
#define OSC_RC8MCAL0_bp 0
#define OSC_RC8MCAL1_bm (1<<1)
#define OSC_RC8MCAL1_bp 1
#define OSC_RC8MCAL2_bm (1<<2)
#define OSC_RC8MCAL2_bp 2
#define OSC_RC8MCAL3_bm (1<<3)
#define OSC_RC8MCAL3_bp 3
#define OSC_RC8MCAL4_bm (1<<4)
#define OSC_RC8MCAL4_bp 4
#define OSC_RC8MCAL5_bm (1<<5)
#define OSC_RC8MCAL5_bp 5
#define OSC_RC8MCAL6_bm (1<<6)
#define OSC_RC8MCAL6_bp 6
#define OSC_RC8MCAL7_bm (1<<7)
#define OSC_RC8MCAL7_bp 7
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
#define PORT_INTLVL_gm 0x03
#define PORT_INTLVL_gp 0
#define PORT_INTLVL0_bm (1<<0)
#define PORT_INTLVL0_bp 0
#define PORT_INTLVL1_bm (1<<1)
#define PORT_INTLVL1_bp 1
#define PORT_INT0IF_bm 0x01
#define PORT_INT0IF_bp 0
#define PORT_INT1IF_bm 0x02
#define PORT_INT1IF_bp 1
#define PORT_INT2IF_bm 0x04
#define PORT_INT2IF_bp 2
#define PORT_INT3IF_bm 0x08
#define PORT_INT3IF_bp 3
#define PORT_INT4IF_bm 0x10
#define PORT_INT4IF_bp 4
#define PORT_INT5IF_bm 0x20
#define PORT_INT5IF_bp 5
#define PORT_INT6IF_bm 0x40
#define PORT_INT6IF_bp 6
#define PORT_INT7IF_bm 0x80
#define PORT_INT7IF_bp 7
#define PORT_TC4A_bm 0x01
#define PORT_TC4A_bp 0
#define PORT_TC4B_bm 0x02
#define PORT_TC4B_bp 1
#define PORT_TC4C_bm 0x04
#define PORT_TC4C_bp 2
#define PORT_TC4D_bm 0x08
#define PORT_TC4D_bp 3
#define PORT_USART0_bm 0x10
#define PORT_USART0_bp 4
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
#define PORTCFG_RTCOUT_gm 0x60
#define PORTCFG_RTCOUT_gp 5
#define PORTCFG_RTCOUT0_bm (1<<5)
#define PORTCFG_RTCOUT0_bp 5
#define PORTCFG_RTCOUT1_bm (1<<6)
#define PORTCFG_RTCOUT1_bp 6
#define PORTCFG_CLKEVPIN_bm 0x80
#define PORTCFG_CLKEVPIN_bp 7
#define PORTCFG_EVOUTSEL_gm 0x07
#define PORTCFG_EVOUTSEL_gp 0
#define PORTCFG_EVOUTSEL0_bm (1<<0)
#define PORTCFG_EVOUTSEL0_bp 0
#define PORTCFG_EVOUTSEL1_bm (1<<1)
#define PORTCFG_EVOUTSEL1_bp 1
#define PORTCFG_EVOUTSEL2_bm (1<<2)
#define PORTCFG_EVOUTSEL2_bp 2
#define PORTCFG_EVASYEN_bm 0x08
#define PORTCFG_EVASYEN_bp 3
#define PORTCFG_EVOUT_gm 0x30
#define PORTCFG_EVOUT_gp 4
#define PORTCFG_EVOUT0_bm (1<<4)
#define PORTCFG_EVOUT0_bp 4
#define PORTCFG_EVOUT1_bm (1<<5)
#define PORTCFG_EVOUT1_bp 5
#define PORTCFG_ACOUT_gm 0xC0
#define PORTCFG_ACOUT_gp 6
#define PORTCFG_ACOUT0_bm (1<<6)
#define PORTCFG_ACOUT0_bp 6
#define PORTCFG_ACOUT1_bm (1<<7)
#define PORTCFG_ACOUT1_bp 7
#define PORTCFG_SRLENRA_bm 0x01
#define PORTCFG_SRLENRA_bp 0
#define PORTCFG_SRLENRC_bm 0x04
#define PORTCFG_SRLENRC_bp 2
#define PORTCFG_SRLENRD_bm 0x08
#define PORTCFG_SRLENRD_bp 3
#define PORTCFG_SRLENRR_bm 0x80
#define PORTCFG_SRLENRR_bp 7
#define PR_EDMA_bm 0x01
#define PR_EDMA_bp 0
#define PR_EVSYS_bm 0x02
#define PR_EVSYS_bp 1
#define PR_RTC_bm 0x04
#define PR_RTC_bp 2
#define PR_XCL_bm 0x80
#define PR_XCL_bp 7
#define PR_AC_bm 0x01
#define PR_AC_bp 0
#define PR_ADC_bm 0x02
#define PR_ADC_bp 1
#define PR_DAC_bm 0x04
#define PR_DAC_bp 2
#define PR_TC4_bm 0x01
#define PR_TC4_bp 0
#define PR_TC5_bm 0x02
#define PR_TC5_bp 1
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
#define RTC_CORREN_bm 0x08
#define RTC_CORREN_bp 3
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
#define RTC_ERROR_gm 0x7F
#define RTC_ERROR_gp 0
#define RTC_ERROR0_bm (1<<0)
#define RTC_ERROR0_bp 0
#define RTC_ERROR1_bm (1<<1)
#define RTC_ERROR1_bp 1
#define RTC_ERROR2_bm (1<<2)
#define RTC_ERROR2_bp 2
#define RTC_ERROR3_bm (1<<3)
#define RTC_ERROR3_bp 3
#define RTC_ERROR4_bm (1<<4)
#define RTC_ERROR4_bp 4
#define RTC_ERROR5_bm (1<<5)
#define RTC_ERROR5_bp 5
#define RTC_ERROR6_bm (1<<6)
#define RTC_ERROR6_bp 6
#define RTC_SIGN_bm 0x80
#define RTC_SIGN_bp 7
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
#define SPI_SSIE_bm 0x10
#define SPI_SSIE_bp 4
#define SPI_DREIE_bm 0x20
#define SPI_DREIE_bp 5
#define SPI_TXCIE_bm 0x40
#define SPI_TXCIE_bp 6
#define SPI_RXCIE_bm 0x80
#define SPI_RXCIE_bp 7
#define SPI_BUFOVF_bm 0x01
#define SPI_BUFOVF_bp 0
#define SPI_SSIF_bm 0x10
#define SPI_SSIF_bp 4
#define SPI_DREIF_bm 0x20
#define SPI_DREIF_bp 5
#define SPI_WRCOL_bm 0x40
#define SPI_WRCOL_bp 6
#define SPI_TXCIF_bm 0x40
#define SPI_TXCIF_bp 6
#define SPI_IF_bm 0x80
#define SPI_IF_bp 7
#define SPI_RXCIF_bm 0x80
#define SPI_RXCIF_bp 7
#define SPI_SSD_bm 0x04
#define SPI_SSD_bp 2
#define SPI_BUFMODE_gm 0xC0
#define SPI_BUFMODE_gp 6
#define SPI_BUFMODE0_bm (1<<6)
#define SPI_BUFMODE0_bp 6
#define SPI_BUFMODE1_bm (1<<7)
#define SPI_BUFMODE1_bp 7
#define TC4_CLKSEL_gm 0x0F
#define TC4_CLKSEL_gp 0
#define TC4_CLKSEL0_bm (1<<0)
#define TC4_CLKSEL0_bp 0
#define TC4_CLKSEL1_bm (1<<1)
#define TC4_CLKSEL1_bp 1
#define TC4_CLKSEL2_bm (1<<2)
#define TC4_CLKSEL2_bp 2
#define TC4_CLKSEL3_bm (1<<3)
#define TC4_CLKSEL3_bp 3
#define TC4_UPSTOP_bm 0x10
#define TC4_UPSTOP_bp 4
#define TC4_EVSTART_bm 0x20
#define TC4_EVSTART_bp 5
#define TC4_SYNCHEN_bm 0x40
#define TC4_SYNCHEN_bp 6
#define TC4_WGMODE_gm 0x07
#define TC4_WGMODE_gp 0
#define TC4_WGMODE0_bm (1<<0)
#define TC4_WGMODE0_bp 0
#define TC4_WGMODE1_bm (1<<1)
#define TC4_WGMODE1_bp 1
#define TC4_WGMODE2_bm (1<<2)
#define TC4_WGMODE2_bp 2
#define TC4_CIRCEN_gm 0x30
#define TC4_CIRCEN_gp 4
#define TC4_CIRCEN0_bm (1<<4)
#define TC4_CIRCEN0_bp 4
#define TC4_CIRCEN1_bm (1<<5)
#define TC4_CIRCEN1_bp 5
#define TC4_BYTEM_gm 0xC0
#define TC4_BYTEM_gp 6
#define TC4_BYTEM0_bm (1<<6)
#define TC4_BYTEM0_bp 6
#define TC4_BYTEM1_bm (1<<7)
#define TC4_BYTEM1_bp 7
#define TC4_CMPA_bm 0x01
#define TC4_CMPA_bp 0
#define TC4_LCMPA_bm 0x01
#define TC4_LCMPA_bp 0
#define TC4_CMPB_bm 0x02
#define TC4_CMPB_bp 1
#define TC4_LCMPB_bm 0x02
#define TC4_LCMPB_bp 1
#define TC4_CMPC_bm 0x04
#define TC4_CMPC_bp 2
#define TC4_LCMPC_bm 0x04
#define TC4_LCMPC_bp 2
#define TC4_CMPD_bm 0x08
#define TC4_CMPD_bp 3
#define TC4_LCMPD_bm 0x08
#define TC4_LCMPD_bp 3
#define TC4_POLA_bm 0x10
#define TC4_POLA_bp 4
#define TC4_HCMPA_bm 0x10
#define TC4_HCMPA_bp 4
#define TC4_POLB_bm 0x20
#define TC4_POLB_bp 5
#define TC4_HCMPB_bm 0x20
#define TC4_HCMPB_bp 5
#define TC4_POLC_bm 0x40
#define TC4_POLC_bp 6
#define TC4_HCMPC_bm 0x40
#define TC4_HCMPC_bp 6
#define TC4_POLD_bm 0x80
#define TC4_POLD_bp 7
#define TC4_HCMPD_bm 0x80
#define TC4_HCMPD_bp 7
#define TC4_EVSEL_gm 0x0F
#define TC4_EVSEL_gp 0
#define TC4_EVSEL0_bm (1<<0)
#define TC4_EVSEL0_bp 0
#define TC4_EVSEL1_bm (1<<1)
#define TC4_EVSEL1_bp 1
#define TC4_EVSEL2_bm (1<<2)
#define TC4_EVSEL2_bp 2
#define TC4_EVSEL3_bm (1<<3)
#define TC4_EVSEL3_bp 3
#define TC4_EVDLY_bm 0x10
#define TC4_EVDLY_bp 4
#define TC4_EVACT_gm 0xE0
#define TC4_EVACT_gp 5
#define TC4_EVACT0_bm (1<<5)
#define TC4_EVACT0_bp 5
#define TC4_EVACT1_bm (1<<6)
#define TC4_EVACT1_bp 6
#define TC4_EVACT2_bm (1<<7)
#define TC4_EVACT2_bp 7
#define TC4_CCAMODE_gm 0x03
#define TC4_CCAMODE_gp 0
#define TC4_CCAMODE0_bm (1<<0)
#define TC4_CCAMODE0_bp 0
#define TC4_CCAMODE1_bm (1<<1)
#define TC4_CCAMODE1_bp 1
#define TC4_LCCAMODE_gm 0x03
#define TC4_LCCAMODE_gp 0
#define TC4_LCCAMODE0_bm (1<<0)
#define TC4_LCCAMODE0_bp 0
#define TC4_LCCAMODE1_bm (1<<1)
#define TC4_LCCAMODE1_bp 1
#define TC4_CCBMODE_gm 0x0C
#define TC4_CCBMODE_gp 2
#define TC4_CCBMODE0_bm (1<<2)
#define TC4_CCBMODE0_bp 2
#define TC4_CCBMODE1_bm (1<<3)
#define TC4_CCBMODE1_bp 3
#define TC4_LCCBMODE_gm 0x0C
#define TC4_LCCBMODE_gp 2
#define TC4_LCCBMODE0_bm (1<<2)
#define TC4_LCCBMODE0_bp 2
#define TC4_LCCBMODE1_bm (1<<3)
#define TC4_LCCBMODE1_bp 3
#define TC4_CCCMODE_gm 0x30
#define TC4_CCCMODE_gp 4
#define TC4_CCCMODE0_bm (1<<4)
#define TC4_CCCMODE0_bp 4
#define TC4_CCCMODE1_bm (1<<5)
#define TC4_CCCMODE1_bp 5
#define TC4_LCCCMODE_gm 0x30
#define TC4_LCCCMODE_gp 4
#define TC4_LCCCMODE0_bm (1<<4)
#define TC4_LCCCMODE0_bp 4
#define TC4_LCCCMODE1_bm (1<<5)
#define TC4_LCCCMODE1_bp 5
#define TC4_CCDMODE_gm 0xC0
#define TC4_CCDMODE_gp 6
#define TC4_CCDMODE0_bm (1<<6)
#define TC4_CCDMODE0_bp 6
#define TC4_CCDMODE1_bm (1<<7)
#define TC4_CCDMODE1_bp 7
#define TC4_LCCDMODE_gm 0xC0
#define TC4_LCCDMODE_gp 6
#define TC4_LCCDMODE0_bm (1<<6)
#define TC4_LCCDMODE0_bp 6
#define TC4_LCCDMODE1_bm (1<<7)
#define TC4_LCCDMODE1_bp 7
#define TC4_HCCAMODE_gm 0x03
#define TC4_HCCAMODE_gp 0
#define TC4_HCCAMODE0_bm (1<<0)
#define TC4_HCCAMODE0_bp 0
#define TC4_HCCAMODE1_bm (1<<1)
#define TC4_HCCAMODE1_bp 1
#define TC4_HCCBMODE_gm 0x0C
#define TC4_HCCBMODE_gp 2
#define TC4_HCCBMODE0_bm (1<<2)
#define TC4_HCCBMODE0_bp 2
#define TC4_HCCBMODE1_bm (1<<3)
#define TC4_HCCBMODE1_bp 3
#define TC4_HCCCMODE_gm 0x30
#define TC4_HCCCMODE_gp 4
#define TC4_HCCCMODE0_bm (1<<4)
#define TC4_HCCCMODE0_bp 4
#define TC4_HCCCMODE1_bm (1<<5)
#define TC4_HCCCMODE1_bp 5
#define TC4_HCCDMODE_gm 0xC0
#define TC4_HCCDMODE_gp 6
#define TC4_HCCDMODE0_bm (1<<6)
#define TC4_HCCDMODE0_bp 6
#define TC4_HCCDMODE1_bm (1<<7)
#define TC4_HCCDMODE1_bp 7
#define TC4_OVFINTLVL_gm 0x03
#define TC4_OVFINTLVL_gp 0
#define TC4_OVFINTLVL0_bm (1<<0)
#define TC4_OVFINTLVL0_bp 0
#define TC4_OVFINTLVL1_bm (1<<1)
#define TC4_OVFINTLVL1_bp 1
#define TC4_ERRINTLVL_gm 0x0C
#define TC4_ERRINTLVL_gp 2
#define TC4_ERRINTLVL0_bm (1<<2)
#define TC4_ERRINTLVL0_bp 2
#define TC4_ERRINTLVL1_bm (1<<3)
#define TC4_ERRINTLVL1_bp 3
#define TC4_TRGINTLVL_gm 0x30
#define TC4_TRGINTLVL_gp 4
#define TC4_TRGINTLVL0_bm (1<<4)
#define TC4_TRGINTLVL0_bp 4
#define TC4_TRGINTLVL1_bm (1<<5)
#define TC4_TRGINTLVL1_bp 5
#define TC4_CCAINTLVL_gm 0x03
#define TC4_CCAINTLVL_gp 0
#define TC4_CCAINTLVL0_bm (1<<0)
#define TC4_CCAINTLVL0_bp 0
#define TC4_CCAINTLVL1_bm (1<<1)
#define TC4_CCAINTLVL1_bp 1
#define TC4_LCCAINTLVL_gm 0x03
#define TC4_LCCAINTLVL_gp 0
#define TC4_LCCAINTLVL0_bm (1<<0)
#define TC4_LCCAINTLVL0_bp 0
#define TC4_LCCAINTLVL1_bm (1<<1)
#define TC4_LCCAINTLVL1_bp 1
#define TC4_CCBINTLVL_gm 0x0C
#define TC4_CCBINTLVL_gp 2
#define TC4_CCBINTLVL0_bm (1<<2)
#define TC4_CCBINTLVL0_bp 2
#define TC4_CCBINTLVL1_bm (1<<3)
#define TC4_CCBINTLVL1_bp 3
#define TC4_LCCBINTLVL_gm 0x0C
#define TC4_LCCBINTLVL_gp 2
#define TC4_LCCBINTLVL0_bm (1<<2)
#define TC4_LCCBINTLVL0_bp 2
#define TC4_LCCBINTLVL1_bm (1<<3)
#define TC4_LCCBINTLVL1_bp 3
#define TC4_CCCINTLVL_gm 0x30
#define TC4_CCCINTLVL_gp 4
#define TC4_CCCINTLVL0_bm (1<<4)
#define TC4_CCCINTLVL0_bp 4
#define TC4_CCCINTLVL1_bm (1<<5)
#define TC4_CCCINTLVL1_bp 5
#define TC4_LCCCINTLVL_gm 0x30
#define TC4_LCCCINTLVL_gp 4
#define TC4_LCCCINTLVL0_bm (1<<4)
#define TC4_LCCCINTLVL0_bp 4
#define TC4_LCCCINTLVL1_bm (1<<5)
#define TC4_LCCCINTLVL1_bp 5
#define TC4_CCDINTLVL_gm 0xC0
#define TC4_CCDINTLVL_gp 6
#define TC4_CCDINTLVL0_bm (1<<6)
#define TC4_CCDINTLVL0_bp 6
#define TC4_CCDINTLVL1_bm (1<<7)
#define TC4_CCDINTLVL1_bp 7
#define TC4_LCCDINTLVL_gm 0xC0
#define TC4_LCCDINTLVL_gp 6
#define TC4_LCCDINTLVL0_bm (1<<6)
#define TC4_LCCDINTLVL0_bp 6
#define TC4_LCCDINTLVL1_bm (1<<7)
#define TC4_LCCDINTLVL1_bp 7
#define TC4_DIR_bm 0x01
#define TC4_DIR_bp 0
#define TC4_LUPD_bm 0x02
#define TC4_LUPD_bp 1
#define TC4_CMD_gm 0x0C
#define TC4_CMD_gp 2
#define TC4_CMD0_bm (1<<2)
#define TC4_CMD0_bp 2
#define TC4_CMD1_bm (1<<3)
#define TC4_CMD1_bp 3
#define TC4_STOP_bm 0x20
#define TC4_STOP_bp 5
#define TC4_PERBV_bm 0x01
#define TC4_PERBV_bp 0
#define TC4_LPERBV_bm 0x01
#define TC4_LPERBV_bp 0
#define TC4_CCABV_bm 0x02
#define TC4_CCABV_bp 1
#define TC4_LCCABV_bm 0x02
#define TC4_LCCABV_bp 1
#define TC4_CCBBV_bm 0x04
#define TC4_CCBBV_bp 2
#define TC4_LCCBBV_bm 0x04
#define TC4_LCCBBV_bp 2
#define TC4_CCCBV_bm 0x08
#define TC4_CCCBV_bp 3
#define TC4_LCCCBV_bm 0x08
#define TC4_LCCCBV_bp 3
#define TC4_CCDBV_bm 0x10
#define TC4_CCDBV_bp 4
#define TC4_LCCDBV_bm 0x10
#define TC4_LCCDBV_bp 4
#define TC4_OVFIF_bm 0x01
#define TC4_OVFIF_bp 0
#define TC4_ERRIF_bm 0x02
#define TC4_ERRIF_bp 1
#define TC4_TRGIF_bm 0x04
#define TC4_TRGIF_bp 2
#define TC4_CCAIF_bm 0x10
#define TC4_CCAIF_bp 4
#define TC4_LCCAIF_bm 0x10
#define TC4_LCCAIF_bp 4
#define TC4_CCBIF_bm 0x20
#define TC4_CCBIF_bp 5
#define TC4_LCCBIF_bm 0x20
#define TC4_LCCBIF_bp 5
#define TC4_CCCIF_bm 0x40
#define TC4_CCCIF_bp 6
#define TC4_LCCCIF_bm 0x40
#define TC4_LCCCIF_bp 6
#define TC4_CCDIF_bm 0x80
#define TC4_CCDIF_bp 7
#define TC4_LCCDIF_bm 0x80
#define TC4_LCCDIF_bp 7
#define TC5_CLKSEL_gm 0x0F
#define TC5_CLKSEL_gp 0
#define TC5_CLKSEL0_bm (1<<0)
#define TC5_CLKSEL0_bp 0
#define TC5_CLKSEL1_bm (1<<1)
#define TC5_CLKSEL1_bp 1
#define TC5_CLKSEL2_bm (1<<2)
#define TC5_CLKSEL2_bp 2
#define TC5_CLKSEL3_bm (1<<3)
#define TC5_CLKSEL3_bp 3
#define TC5_UPSTOP_bm 0x10
#define TC5_UPSTOP_bp 4
#define TC5_EVSTART_bm 0x20
#define TC5_EVSTART_bp 5
#define TC5_SYNCHEN_bm 0x40
#define TC5_SYNCHEN_bp 6
#define TC5_WGMODE_gm 0x07
#define TC5_WGMODE_gp 0
#define TC5_WGMODE0_bm (1<<0)
#define TC5_WGMODE0_bp 0
#define TC5_WGMODE1_bm (1<<1)
#define TC5_WGMODE1_bp 1
#define TC5_WGMODE2_bm (1<<2)
#define TC5_WGMODE2_bp 2
#define TC5_CIRCEN_gm 0x30
#define TC5_CIRCEN_gp 4
#define TC5_CIRCEN0_bm (1<<4)
#define TC5_CIRCEN0_bp 4
#define TC5_CIRCEN1_bm (1<<5)
#define TC5_CIRCEN1_bp 5
#define TC5_BYTEM_gm 0xC0
#define TC5_BYTEM_gp 6
#define TC5_BYTEM0_bm (1<<6)
#define TC5_BYTEM0_bp 6
#define TC5_BYTEM1_bm (1<<7)
#define TC5_BYTEM1_bp 7
#define TC5_CMPA_bm 0x01
#define TC5_CMPA_bp 0
#define TC5_LCMPA_bm 0x01
#define TC5_LCMPA_bp 0
#define TC5_CMPB_bm 0x02
#define TC5_CMPB_bp 1
#define TC5_LCMPB_bm 0x02
#define TC5_LCMPB_bp 1
#define TC5_POLA_bm 0x10
#define TC5_POLA_bp 4
#define TC5_HCMPA_bm 0x10
#define TC5_HCMPA_bp 4
#define TC5_POLB_bm 0x20
#define TC5_POLB_bp 5
#define TC5_HCMPB_bm 0x20
#define TC5_HCMPB_bp 5
#define TC5_EVSEL_gm 0x0F
#define TC5_EVSEL_gp 0
#define TC5_EVSEL0_bm (1<<0)
#define TC5_EVSEL0_bp 0
#define TC5_EVSEL1_bm (1<<1)
#define TC5_EVSEL1_bp 1
#define TC5_EVSEL2_bm (1<<2)
#define TC5_EVSEL2_bp 2
#define TC5_EVSEL3_bm (1<<3)
#define TC5_EVSEL3_bp 3
#define TC5_EVDLY_bm 0x10
#define TC5_EVDLY_bp 4
#define TC5_EVACT_gm 0xE0
#define TC5_EVACT_gp 5
#define TC5_EVACT0_bm (1<<5)
#define TC5_EVACT0_bp 5
#define TC5_EVACT1_bm (1<<6)
#define TC5_EVACT1_bp 6
#define TC5_EVACT2_bm (1<<7)
#define TC5_EVACT2_bp 7
#define TC5_CCAMODE_gm 0x03
#define TC5_CCAMODE_gp 0
#define TC5_CCAMODE0_bm (1<<0)
#define TC5_CCAMODE0_bp 0
#define TC5_CCAMODE1_bm (1<<1)
#define TC5_CCAMODE1_bp 1
#define TC5_LCCAMODE_gm 0x03
#define TC5_LCCAMODE_gp 0
#define TC5_LCCAMODE0_bm (1<<0)
#define TC5_LCCAMODE0_bp 0
#define TC5_LCCAMODE1_bm (1<<1)
#define TC5_LCCAMODE1_bp 1
#define TC5_CCBMODE_gm 0x0C
#define TC5_CCBMODE_gp 2
#define TC5_CCBMODE0_bm (1<<2)
#define TC5_CCBMODE0_bp 2
#define TC5_CCBMODE1_bm (1<<3)
#define TC5_CCBMODE1_bp 3
#define TC5_LCCBMODE_gm 0x0C
#define TC5_LCCBMODE_gp 2
#define TC5_LCCBMODE0_bm (1<<2)
#define TC5_LCCBMODE0_bp 2
#define TC5_LCCBMODE1_bm (1<<3)
#define TC5_LCCBMODE1_bp 3
#define TC5_HCCAMODE_gm 0x03
#define TC5_HCCAMODE_gp 0
#define TC5_HCCAMODE0_bm (1<<0)
#define TC5_HCCAMODE0_bp 0
#define TC5_HCCAMODE1_bm (1<<1)
#define TC5_HCCAMODE1_bp 1
#define TC5_HCCBMODE_gm 0x0C
#define TC5_HCCBMODE_gp 2
#define TC5_HCCBMODE0_bm (1<<2)
#define TC5_HCCBMODE0_bp 2
#define TC5_HCCBMODE1_bm (1<<3)
#define TC5_HCCBMODE1_bp 3
#define TC5_OVFINTLVL_gm 0x03
#define TC5_OVFINTLVL_gp 0
#define TC5_OVFINTLVL0_bm (1<<0)
#define TC5_OVFINTLVL0_bp 0
#define TC5_OVFINTLVL1_bm (1<<1)
#define TC5_OVFINTLVL1_bp 1
#define TC5_ERRINTLVL_gm 0x0C
#define TC5_ERRINTLVL_gp 2
#define TC5_ERRINTLVL0_bm (1<<2)
#define TC5_ERRINTLVL0_bp 2
#define TC5_ERRINTLVL1_bm (1<<3)
#define TC5_ERRINTLVL1_bp 3
#define TC5_TRGINTLVL_gm 0x30
#define TC5_TRGINTLVL_gp 4
#define TC5_TRGINTLVL0_bm (1<<4)
#define TC5_TRGINTLVL0_bp 4
#define TC5_TRGINTLVL1_bm (1<<5)
#define TC5_TRGINTLVL1_bp 5
#define TC5_CCAINTLVL_gm 0x03
#define TC5_CCAINTLVL_gp 0
#define TC5_CCAINTLVL0_bm (1<<0)
#define TC5_CCAINTLVL0_bp 0
#define TC5_CCAINTLVL1_bm (1<<1)
#define TC5_CCAINTLVL1_bp 1
#define TC5_LCCAINTLVL_gm 0x03
#define TC5_LCCAINTLVL_gp 0
#define TC5_LCCAINTLVL0_bm (1<<0)
#define TC5_LCCAINTLVL0_bp 0
#define TC5_LCCAINTLVL1_bm (1<<1)
#define TC5_LCCAINTLVL1_bp 1
#define TC5_CCBINTLVL_gm 0x0C
#define TC5_CCBINTLVL_gp 2
#define TC5_CCBINTLVL0_bm (1<<2)
#define TC5_CCBINTLVL0_bp 2
#define TC5_CCBINTLVL1_bm (1<<3)
#define TC5_CCBINTLVL1_bp 3
#define TC5_LCCBINTLVL_gm 0x0C
#define TC5_LCCBINTLVL_gp 2
#define TC5_LCCBINTLVL0_bm (1<<2)
#define TC5_LCCBINTLVL0_bp 2
#define TC5_LCCBINTLVL1_bm (1<<3)
#define TC5_LCCBINTLVL1_bp 3
#define TC5_DIR_bm 0x01
#define TC5_DIR_bp 0
#define TC5_LUPD_bm 0x02
#define TC5_LUPD_bp 1
#define TC5_CMD_gm 0x0C
#define TC5_CMD_gp 2
#define TC5_CMD0_bm (1<<2)
#define TC5_CMD0_bp 2
#define TC5_CMD1_bm (1<<3)
#define TC5_CMD1_bp 3
#define TC5_STOP_bm 0x20
#define TC5_STOP_bp 5
#define TC5_PERBV_bm 0x01
#define TC5_PERBV_bp 0
#define TC5_LPERBV_bm 0x01
#define TC5_LPERBV_bp 0
#define TC5_CCABV_bm 0x02
#define TC5_CCABV_bp 1
#define TC5_LCCABV_bm 0x02
#define TC5_LCCABV_bp 1
#define TC5_CCBBV_bm 0x04
#define TC5_CCBBV_bp 2
#define TC5_LCCBBV_bm 0x04
#define TC5_LCCBBV_bp 2
#define TC5_OVFIF_bm 0x01
#define TC5_OVFIF_bp 0
#define TC5_ERRIF_bm 0x02
#define TC5_ERRIF_bp 1
#define TC5_TRGIF_bm 0x04
#define TC5_TRGIF_bp 2
#define TC5_CCAIF_bm 0x10
#define TC5_CCAIF_bp 4
#define TC5_LCCAIF_bm 0x10
#define TC5_LCCAIF_bp 4
#define TC5_CCBIF_bm 0x20
#define TC5_CCBIF_bp 5
#define TC5_LCCBIF_bm 0x20
#define TC5_LCCBIF_bp 5
#define TWI_EDIEN_bm 0x01
#define TWI_EDIEN_bp 0
#define TWI_SDAHOLD_gm 0x06
#define TWI_SDAHOLD_gp 1
#define TWI_SDAHOLD0_bm (1<<1)
#define TWI_SDAHOLD0_bp 1
#define TWI_SDAHOLD1_bm (1<<2)
#define TWI_SDAHOLD1_bp 2
#define TWI_FMPEN_bm 0x08
#define TWI_FMPEN_bp 3
#define TWI_SSDAHOLD_gm 0x30
#define TWI_SSDAHOLD_gp 4
#define TWI_SSDAHOLD0_bm (1<<4)
#define TWI_SSDAHOLD0_bp 4
#define TWI_SSDAHOLD1_bm (1<<5)
#define TWI_SSDAHOLD1_bp 5
#define TWI_SFMPEN_bm 0x40
#define TWI_SFMPEN_bp 6
#define TWI_BRIDGEEN_bm 0x80
#define TWI_BRIDGEEN_bp 7
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
#define TWI_MASTER_TTOUTEN_bm 0x10
#define TWI_MASTER_TTOUTEN_bp 4
#define TWI_MASTER_TSEXTEN_bm 0x20
#define TWI_MASTER_TSEXTEN_bp 5
#define TWI_MASTER_TMEXTEN_bm 0x40
#define TWI_MASTER_TMEXTEN_bp 6
#define TWI_MASTER_TOIE_bm 0x80
#define TWI_MASTER_TOIE_bp 7
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
#define TWI_SLAVE_TTOUTEN_bm 0x10
#define TWI_SLAVE_TTOUTEN_bp 4
#define TWI_SLAVE_TOIE_bm 0x80
#define TWI_SLAVE_TOIE_bp 7
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
#define TWI_TIMEOUT_TTOUTMIF_bm 0x01
#define TWI_TIMEOUT_TTOUTMIF_bp 0
#define TWI_TIMEOUT_TSEXTIF_bm 0x02
#define TWI_TIMEOUT_TSEXTIF_bp 1
#define TWI_TIMEOUT_TMEXTIF_bm 0x04
#define TWI_TIMEOUT_TMEXTIF_bp 2
#define TWI_TIMEOUT_TTOUTSIF_bm 0x10
#define TWI_TIMEOUT_TTOUTSIF_bp 4
#define TWI_TIMEOUT_TTOUTMSEL_gm 0x07
#define TWI_TIMEOUT_TTOUTMSEL_gp 0
#define TWI_TIMEOUT_TTOUTMSEL0_bm (1<<0)
#define TWI_TIMEOUT_TTOUTMSEL0_bp 0
#define TWI_TIMEOUT_TTOUTMSEL1_bm (1<<1)
#define TWI_TIMEOUT_TTOUTMSEL1_bp 1
#define TWI_TIMEOUT_TTOUTMSEL2_bm (1<<2)
#define TWI_TIMEOUT_TTOUTMSEL2_bp 2
#define TWI_TIMEOUT_TMSEXTSEL_gm 0x18
#define TWI_TIMEOUT_TMSEXTSEL_gp 3
#define TWI_TIMEOUT_TMSEXTSEL0_bm (1<<3)
#define TWI_TIMEOUT_TMSEXTSEL0_bp 3
#define TWI_TIMEOUT_TMSEXTSEL1_bm (1<<4)
#define TWI_TIMEOUT_TMSEXTSEL1_bp 4
#define TWI_TIMEOUT_TTOUTSSEL_gm 0xE0
#define TWI_TIMEOUT_TTOUTSSEL_gp 5
#define TWI_TIMEOUT_TTOUTSSEL0_bm (1<<5)
#define TWI_TIMEOUT_TTOUTSSEL0_bp 5
#define TWI_TIMEOUT_TTOUTSSEL1_bm (1<<6)
#define TWI_TIMEOUT_TTOUTSSEL1_bp 6
#define TWI_TIMEOUT_TTOUTSSEL2_bm (1<<7)
#define TWI_TIMEOUT_TTOUTSSEL2_bp 7
#define USART_RXB8_bm 0x01
#define USART_RXB8_bp 0
#define USART_DRIF_bm 0x01
#define USART_DRIF_bp 0
#define USART_RXSIF_bm 0x02
#define USART_RXSIF_bp 1
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
#define USART_DRIE_bm 0x40
#define USART_DRIE_bp 6
#define USART_RXSIE_bm 0x80
#define USART_RXSIE_bp 7
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
#define USART_SFDEN_bm 0x40
#define USART_SFDEN_bp 6
#define USART_ONEWIRE_bm 0x80
#define USART_ONEWIRE_bp 7
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
#define USART_PECACT_gm 0x03
#define USART_PECACT_gp 0
#define USART_PECACT0_bm (1<<0)
#define USART_PECACT0_bp 0
#define USART_PECACT1_bm (1<<1)
#define USART_PECACT1_bp 1
#define USART_LUTACT_gm 0x0C
#define USART_LUTACT_gp 2
#define USART_LUTACT0_bm (1<<2)
#define USART_LUTACT0_bp 2
#define USART_LUTACT1_bm (1<<3)
#define USART_LUTACT1_bp 3
#define USART_DECTYPE_gm 0x30
#define USART_DECTYPE_gp 4
#define USART_DECTYPE0_bm (1<<4)
#define USART_DECTYPE0_bp 4
#define USART_DECTYPE1_bm (1<<5)
#define USART_DECTYPE1_bp 5
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
#define VPORT_INT0IF_bm 0x01
#define VPORT_INT0IF_bp 0
#define VPORT_INT1IF_bm 0x02
#define VPORT_INT1IF_bp 1
#define VPORT_INT2IF_bm 0x04
#define VPORT_INT2IF_bp 2
#define VPORT_INT3IF_bm 0x08
#define VPORT_INT3IF_bp 3
#define VPORT_INT4IF_bm 0x10
#define VPORT_INT4IF_bp 4
#define VPORT_INT5IF_bm 0x20
#define VPORT_INT5IF_bp 5
#define VPORT_INT6IF_bm 0x40
#define VPORT_INT6IF_bp 6
#define VPORT_INT7IF_bm 0x80
#define VPORT_INT7IF_bp 7
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
#define WEX_DTI0EN_bm 0x01
#define WEX_DTI0EN_bp 0
#define WEX_DTI1EN_bm 0x02
#define WEX_DTI1EN_bp 1
#define WEX_DTI2EN_bm 0x04
#define WEX_DTI2EN_bp 2
#define WEX_DTI3EN_bm 0x08
#define WEX_DTI3EN_bp 3
#define WEX_OTMX_gm 0x70
#define WEX_OTMX_gp 4
#define WEX_OTMX0_bm (1<<4)
#define WEX_OTMX0_bp 4
#define WEX_OTMX1_bm (1<<5)
#define WEX_OTMX1_bp 5
#define WEX_OTMX2_bm (1<<6)
#define WEX_OTMX2_bp 6
#define WEX_UPSEL_bm 0x80
#define WEX_UPSEL_bp 7
#define WEX_PGOBUFV_bm 0x01
#define WEX_PGOBUFV_bp 0
#define WEX_PGVBUFV_bm 0x02
#define WEX_PGVBUFV_bp 1
#define WEX_SWAPBUF_bm 0x04
#define WEX_SWAPBUF_bp 2
#define WEX_SWAP0_bm 0x01
#define WEX_SWAP0_bp 0
#define WEX_SWAP1_bm 0x02
#define WEX_SWAP1_bp 1
#define WEX_SWAP2_bm 0x04
#define WEX_SWAP2_bp 2
#define WEX_SWAP3_bm 0x08
#define WEX_SWAP3_bp 3
#define WEX_SWAP0BUF_bm 0x01
#define WEX_SWAP0BUF_bp 0
#define WEX_SWAP1BUF_bm 0x02
#define WEX_SWAP1BUF_bp 1
#define WEX_SWAP2BUF_bm 0x04
#define WEX_SWAP2BUF_bp 2
#define WEX_SWAP3BUF_bm 0x08
#define WEX_SWAP3BUF_bp 3
#define XCL_LUTCONF_gm 0x07
#define XCL_LUTCONF_gp 0
#define XCL_LUTCONF0_bm (1<<0)
#define XCL_LUTCONF0_bp 0
#define XCL_LUTCONF1_bm (1<<1)
#define XCL_LUTCONF1_bp 1
#define XCL_LUTCONF2_bm (1<<2)
#define XCL_LUTCONF2_bp 2
#define XCL_PORTSEL_gm 0x30
#define XCL_PORTSEL_gp 4
#define XCL_PORTSEL0_bm (1<<4)
#define XCL_PORTSEL0_bp 4
#define XCL_PORTSEL1_bm (1<<5)
#define XCL_PORTSEL1_bp 5
#define XCL_LUT0OUTEN_gm 0xC0
#define XCL_LUT0OUTEN_gp 6
#define XCL_LUT0OUTEN0_bm (1<<6)
#define XCL_LUT0OUTEN0_bp 6
#define XCL_LUT0OUTEN1_bm (1<<7)
#define XCL_LUT0OUTEN1_bp 7
#define XCL_IN0SEL_gm 0x03
#define XCL_IN0SEL_gp 0
#define XCL_IN0SEL0_bm (1<<0)
#define XCL_IN0SEL0_bp 0
#define XCL_IN0SEL1_bm (1<<1)
#define XCL_IN0SEL1_bp 1
#define XCL_IN1SEL_gm 0x0C
#define XCL_IN1SEL_gp 2
#define XCL_IN1SEL0_bm (1<<2)
#define XCL_IN1SEL0_bp 2
#define XCL_IN1SEL1_bm (1<<3)
#define XCL_IN1SEL1_bp 3
#define XCL_IN2SEL_gm 0x30
#define XCL_IN2SEL_gp 4
#define XCL_IN2SEL0_bm (1<<4)
#define XCL_IN2SEL0_bp 4
#define XCL_IN2SEL1_bm (1<<5)
#define XCL_IN2SEL1_bp 5
#define XCL_IN3SEL_gm 0xC0
#define XCL_IN3SEL_gp 6
#define XCL_IN3SEL0_bm (1<<6)
#define XCL_IN3SEL0_bp 6
#define XCL_IN3SEL1_bm (1<<7)
#define XCL_IN3SEL1_bp 7
#define XCL_DLY0CONF_gm 0x03
#define XCL_DLY0CONF_gp 0
#define XCL_DLY0CONF0_bm (1<<0)
#define XCL_DLY0CONF0_bp 0
#define XCL_DLY0CONF1_bm (1<<1)
#define XCL_DLY0CONF1_bp 1
#define XCL_DLY1CONF_gm 0x0C
#define XCL_DLY1CONF_gp 2
#define XCL_DLY1CONF0_bm (1<<2)
#define XCL_DLY1CONF0_bp 2
#define XCL_DLY1CONF1_bm (1<<3)
#define XCL_DLY1CONF1_bp 3
#define XCL_DLYSEL_gm 0x30
#define XCL_DLYSEL_gp 4
#define XCL_DLYSEL0_bm (1<<4)
#define XCL_DLYSEL0_bp 4
#define XCL_DLYSEL1_bm (1<<5)
#define XCL_DLYSEL1_bp 5
#define XCL_EVASYSEL0_bm 0x40
#define XCL_EVASYSEL0_bp 6
#define XCL_EVASYSEL1_bm 0x80
#define XCL_EVASYSEL1_bp 7
#define XCL_TRUTH0_gm 0x0F
#define XCL_TRUTH0_gp 0
#define XCL_TRUTH00_bm (1<<0)
#define XCL_TRUTH00_bp 0
#define XCL_TRUTH01_bm (1<<1)
#define XCL_TRUTH01_bp 1
#define XCL_TRUTH02_bm (1<<2)
#define XCL_TRUTH02_bp 2
#define XCL_TRUTH03_bm (1<<3)
#define XCL_TRUTH03_bp 3
#define XCL_TRUTH1_gm 0xF0
#define XCL_TRUTH1_gp 4
#define XCL_TRUTH10_bm (1<<4)
#define XCL_TRUTH10_bp 4
#define XCL_TRUTH11_bm (1<<5)
#define XCL_TRUTH11_bp 5
#define XCL_TRUTH12_bm (1<<6)
#define XCL_TRUTH12_bp 6
#define XCL_TRUTH13_bm (1<<7)
#define XCL_TRUTH13_bp 7
#define XCL_CLKSEL_gm 0x0F
#define XCL_CLKSEL_gp 0
#define XCL_CLKSEL0_bm (1<<0)
#define XCL_CLKSEL0_bp 0
#define XCL_CLKSEL1_bm (1<<1)
#define XCL_CLKSEL1_bp 1
#define XCL_CLKSEL2_bm (1<<2)
#define XCL_CLKSEL2_bp 2
#define XCL_CLKSEL3_bm (1<<3)
#define XCL_CLKSEL3_bp 3
#define XCL_TCSEL_gm 0x70
#define XCL_TCSEL_gp 4
#define XCL_TCSEL0_bm (1<<4)
#define XCL_TCSEL0_bp 4
#define XCL_TCSEL1_bm (1<<5)
#define XCL_TCSEL1_bp 5
#define XCL_TCSEL2_bm (1<<6)
#define XCL_TCSEL2_bp 6
#define XCL_CMDSEL_bm 0x80
#define XCL_CMDSEL_bp 7
#define XCL_MODE_gm 0x03
#define XCL_MODE_gp 0
#define XCL_MODE0_bm (1<<0)
#define XCL_MODE0_bp 0
#define XCL_MODE1_bm (1<<1)
#define XCL_MODE1_bp 1
#define XCL_CCEN0_bm 0x04
#define XCL_CCEN0_bp 2
#define XCL_CCEN1_bm 0x08
#define XCL_CCEN1_bp 3
#define XCL_CMP0_bm 0x10
#define XCL_CMP0_bp 4
#define XCL_CMP1_bm 0x20
#define XCL_CMP1_bp 5
#define XCL_CMDEN_gm 0xC0
#define XCL_CMDEN_gp 6
#define XCL_CMDEN0_bm (1<<6)
#define XCL_CMDEN0_bp 6
#define XCL_CMDEN1_bm (1<<7)
#define XCL_CMDEN1_bp 7
#define XCL_EVSRC_gm 0x07
#define XCL_EVSRC_gp 0
#define XCL_EVSRC0_bm (1<<0)
#define XCL_EVSRC0_bp 0
#define XCL_EVSRC1_bm (1<<1)
#define XCL_EVSRC1_bp 1
#define XCL_EVSRC2_bm (1<<2)
#define XCL_EVSRC2_bp 2
#define XCL_EVACT0_gm 0x18
#define XCL_EVACT0_gp 3
#define XCL_EVACT00_bm (1<<3)
#define XCL_EVACT00_bp 3
#define XCL_EVACT01_bm (1<<4)
#define XCL_EVACT01_bp 4
#define XCL_EVACT1_gm 0x60
#define XCL_EVACT1_gp 5
#define XCL_EVACT10_bm (1<<5)
#define XCL_EVACT10_bp 5
#define XCL_EVACT11_bm (1<<6)
#define XCL_EVACT11_bp 6
#define XCL_EVACTEN_bm 0x80
#define XCL_EVACTEN_bp 7
#define XCL_CCINTLVL_gm 0x03
#define XCL_CCINTLVL_gp 0
#define XCL_CCINTLVL0_bm (1<<0)
#define XCL_CCINTLVL0_bp 0
#define XCL_CCINTLVL1_bm (1<<1)
#define XCL_CCINTLVL1_bp 1
#define XCL_UNFINTLVL_gm 0x0C
#define XCL_UNFINTLVL_gp 2
#define XCL_UNFINTLVL0_bm (1<<2)
#define XCL_UNFINTLVL0_bp 2
#define XCL_UNFINTLVL1_bm (1<<3)
#define XCL_UNFINTLVL1_bp 3
#define XCL_CC0IE_bm 0x10
#define XCL_CC0IE_bp 4
#define XCL_CC1IE_bm 0x20
#define XCL_CC1IE_bp 5
#define XCL_PEC20IE_bm 0x20
#define XCL_PEC20IE_bp 5
#define XCL_UNF0IE_bm 0x40
#define XCL_UNF0IE_bp 6
#define XCL_PEC0IE_bm 0x40
#define XCL_PEC0IE_bp 6
#define XCL_UNF1IE_bm 0x80
#define XCL_UNF1IE_bp 7
#define XCL_PEC1IE_bm 0x80
#define XCL_PEC1IE_bp 7
#define XCL_PEC21IE_bm 0x80
#define XCL_PEC21IE_bp 7
#define XCL_CC0IF_bm 0x10
#define XCL_CC0IF_bp 4
#define XCL_CC1IF_bm 0x20
#define XCL_CC1IF_bp 5
#define XCL_PEC20IF_bm 0x20
#define XCL_PEC20IF_bp 5
#define XCL_UNF0IF_bm 0x40
#define XCL_UNF0IF_bp 6
#define XCL_PEC0IF_bm 0x40
#define XCL_PEC0IF_bp 6
#define XCL_UNF1IF_bm 0x80
#define XCL_UNF1IF_bp 7
#define XCL_PEC1IF_bm 0x80
#define XCL_PEC1IF_bp 7
#define XCL_PEC21IF_bm 0x80
#define XCL_PEC21IF_bp 7
#define XCL_PLC_gm 0xFF
#define XCL_PLC_gp 0
#define XCL_PLC0_bm (1<<0)
#define XCL_PLC0_bp 0
#define XCL_PLC1_bm (1<<1)
#define XCL_PLC1_bp 1
#define XCL_PLC2_bm (1<<2)
#define XCL_PLC2_bp 2
#define XCL_PLC3_bm (1<<3)
#define XCL_PLC3_bp 3
#define XCL_PLC4_bm (1<<4)
#define XCL_PLC4_bp 4
#define XCL_PLC5_bm (1<<5)
#define XCL_PLC5_bp 5
#define XCL_PLC6_bm (1<<6)
#define XCL_PLC6_bp 6
#define XCL_PLC7_bm (1<<7)
#define XCL_PLC7_bp 7
#define XCL_BCNTO_gm 0xFF
#define XCL_BCNTO_gp 0
#define XCL_BCNTO0_bm (1<<0)
#define XCL_BCNTO0_bp 0
#define XCL_BCNTO1_bm (1<<1)
#define XCL_BCNTO1_bp 1
#define XCL_BCNTO2_bm (1<<2)
#define XCL_BCNTO2_bp 2
#define XCL_BCNTO3_bm (1<<3)
#define XCL_BCNTO3_bp 3
#define XCL_BCNTO4_bm (1<<4)
#define XCL_BCNTO4_bp 4
#define XCL_BCNTO5_bm (1<<5)
#define XCL_BCNTO5_bp 5
#define XCL_BCNTO6_bm (1<<6)
#define XCL_BCNTO6_bp 6
#define XCL_BCNTO7_bm (1<<7)
#define XCL_BCNTO7_bp 7
#define XCL_CNTL_gm 0xFF
#define XCL_CNTL_gp 0
#define XCL_CNTL0_bm (1<<0)
#define XCL_CNTL0_bp 0
#define XCL_CNTL1_bm (1<<1)
#define XCL_CNTL1_bp 1
#define XCL_CNTL2_bm (1<<2)
#define XCL_CNTL2_bp 2
#define XCL_CNTL3_bm (1<<3)
#define XCL_CNTL3_bp 3
#define XCL_CNTL4_bm (1<<4)
#define XCL_CNTL4_bp 4
#define XCL_CNTL5_bm (1<<5)
#define XCL_CNTL5_bp 5
#define XCL_CNTL6_bm (1<<6)
#define XCL_CNTL6_bp 6
#define XCL_CNTL7_bm (1<<7)
#define XCL_CNTL7_bp 7
#define XCL_PCNTO_gm 0xFF
#define XCL_PCNTO_gp 0
#define XCL_PCNTO0_bm (1<<0)
#define XCL_PCNTO0_bp 0
#define XCL_PCNTO1_bm (1<<1)
#define XCL_PCNTO1_bp 1
#define XCL_PCNTO2_bm (1<<2)
#define XCL_PCNTO2_bp 2
#define XCL_PCNTO3_bm (1<<3)
#define XCL_PCNTO3_bp 3
#define XCL_PCNTO4_bm (1<<4)
#define XCL_PCNTO4_bp 4
#define XCL_PCNTO5_bm (1<<5)
#define XCL_PCNTO5_bp 5
#define XCL_PCNTO6_bm (1<<6)
#define XCL_PCNTO6_bp 6
#define XCL_PCNTO7_bm (1<<7)
#define XCL_PCNTO7_bp 7
#define XCL_PCNT20_gm 0x0F
#define XCL_PCNT20_gp 0
#define XCL_PCNT200_bm (1<<0)
#define XCL_PCNT200_bp 0
#define XCL_PCNT201_bm (1<<1)
#define XCL_PCNT201_bp 1
#define XCL_PCNT202_bm (1<<2)
#define XCL_PCNT202_bp 2
#define XCL_PCNT203_bm (1<<3)
#define XCL_PCNT203_bp 3
#define XCL_PCNT21_gm 0xF0
#define XCL_PCNT21_gp 4
#define XCL_PCNT210_bm (1<<4)
#define XCL_PCNT210_bp 4
#define XCL_PCNT211_bm (1<<5)
#define XCL_PCNT211_bp 5
#define XCL_PCNT212_bm (1<<6)
#define XCL_PCNT212_bp 6
#define XCL_PCNT213_bm (1<<7)
#define XCL_PCNT213_bp 7
#define XCL_BCNT1_gm 0xFF
#define XCL_BCNT1_gp 0
#define XCL_BCNT10_bm (1<<0)
#define XCL_BCNT10_bp 0
#define XCL_BCNT11_bm (1<<1)
#define XCL_BCNT11_bp 1
#define XCL_BCNT12_bm (1<<2)
#define XCL_BCNT12_bp 2
#define XCL_BCNT13_bm (1<<3)
#define XCL_BCNT13_bp 3
#define XCL_BCNT14_bm (1<<4)
#define XCL_BCNT14_bp 4
#define XCL_BCNT15_bm (1<<5)
#define XCL_BCNT15_bp 5
#define XCL_BCNT16_bm (1<<6)
#define XCL_BCNT16_bp 6
#define XCL_BCNT17_bm (1<<7)
#define XCL_BCNT17_bp 7
#define XCL_CNTH_gm 0xFF
#define XCL_CNTH_gp 0
#define XCL_CNTH0_bm (1<<0)
#define XCL_CNTH0_bp 0
#define XCL_CNTH1_bm (1<<1)
#define XCL_CNTH1_bp 1
#define XCL_CNTH2_bm (1<<2)
#define XCL_CNTH2_bp 2
#define XCL_CNTH3_bm (1<<3)
#define XCL_CNTH3_bp 3
#define XCL_CNTH4_bm (1<<4)
#define XCL_CNTH4_bp 4
#define XCL_CNTH5_bm (1<<5)
#define XCL_CNTH5_bp 5
#define XCL_CNTH6_bm (1<<6)
#define XCL_CNTH6_bp 6
#define XCL_CNTH7_bm (1<<7)
#define XCL_CNTH7_bp 7
#define XCL_PCNT1_gm 0xFF
#define XCL_PCNT1_gp 0
#define XCL_PCNT10_bm (1<<0)
#define XCL_PCNT10_bp 0
#define XCL_PCNT11_bm (1<<1)
#define XCL_PCNT11_bp 1
#define XCL_PCNT12_bm (1<<2)
#define XCL_PCNT12_bp 2
#define XCL_PCNT13_bm (1<<3)
#define XCL_PCNT13_bp 3
#define XCL_PCNT14_bm (1<<4)
#define XCL_PCNT14_bp 4
#define XCL_PCNT15_bm (1<<5)
#define XCL_PCNT15_bp 5
#define XCL_PCNT16_bm (1<<6)
#define XCL_PCNT16_bp 6
#define XCL_PCNT17_bm (1<<7)
#define XCL_PCNT17_bp 7
#define XCL_CMPL_gm 0xFF
#define XCL_CMPL_gp 0
#define XCL_CMPL0_bm (1<<0)
#define XCL_CMPL0_bp 0
#define XCL_CMPL1_bm (1<<1)
#define XCL_CMPL1_bp 1
#define XCL_CMPL2_bm (1<<2)
#define XCL_CMPL2_bp 2
#define XCL_CMPL3_bm (1<<3)
#define XCL_CMPL3_bp 3
#define XCL_CMPL4_bm (1<<4)
#define XCL_CMPL4_bp 4
#define XCL_CMPL5_bm (1<<5)
#define XCL_CMPL5_bp 5
#define XCL_CMPL6_bm (1<<6)
#define XCL_CMPL6_bp 6
#define XCL_CMPL7_bm (1<<7)
#define XCL_CMPL7_bp 7
#define XCL_BCMP0_gm 0xFF
#define XCL_BCMP0_gp 0
#define XCL_BCMP00_bm (1<<0)
#define XCL_BCMP00_bp 0
#define XCL_BCMP01_bm (1<<1)
#define XCL_BCMP01_bp 1
#define XCL_BCMP02_bm (1<<2)
#define XCL_BCMP02_bp 2
#define XCL_BCMP03_bm (1<<3)
#define XCL_BCMP03_bp 3
#define XCL_BCMP04_bm (1<<4)
#define XCL_BCMP04_bp 4
#define XCL_BCMP05_bm (1<<5)
#define XCL_BCMP05_bp 5
#define XCL_BCMP06_bm (1<<6)
#define XCL_BCMP06_bp 6
#define XCL_BCMP07_bm (1<<7)
#define XCL_BCMP07_bp 7
#define XCL_CMPH_gm 0xFF
#define XCL_CMPH_gp 0
#define XCL_CMPH0_bm (1<<0)
#define XCL_CMPH0_bp 0
#define XCL_CMPH1_bm (1<<1)
#define XCL_CMPH1_bp 1
#define XCL_CMPH2_bm (1<<2)
#define XCL_CMPH2_bp 2
#define XCL_CMPH3_bm (1<<3)
#define XCL_CMPH3_bp 3
#define XCL_CMPH4_bm (1<<4)
#define XCL_CMPH4_bp 4
#define XCL_CMPH5_bm (1<<5)
#define XCL_CMPH5_bp 5
#define XCL_CMPH6_bm (1<<6)
#define XCL_CMPH6_bp 6
#define XCL_CMPH7_bm (1<<7)
#define XCL_CMPH7_bp 7
#define XCL_BCMP1_gm 0xFF
#define XCL_BCMP1_gp 0
#define XCL_BCMP10_bm (1<<0)
#define XCL_BCMP10_bp 0
#define XCL_BCMP11_bm (1<<1)
#define XCL_BCMP11_bp 1
#define XCL_BCMP12_bm (1<<2)
#define XCL_BCMP12_bp 2
#define XCL_BCMP13_bm (1<<3)
#define XCL_BCMP13_bp 3
#define XCL_BCMP14_bm (1<<4)
#define XCL_BCMP14_bp 4
#define XCL_BCMP15_bm (1<<5)
#define XCL_BCMP15_bp 5
#define XCL_BCMP16_bm (1<<6)
#define XCL_BCMP16_bp 6
#define XCL_BCMP17_bm (1<<7)
#define XCL_BCMP17_bp 7
#define XCL_PERL_gm 0xFF
#define XCL_PERL_gp 0
#define XCL_PERL0_bm (1<<0)
#define XCL_PERL0_bp 0
#define XCL_PERL1_bm (1<<1)
#define XCL_PERL1_bp 1
#define XCL_PERL2_bm (1<<2)
#define XCL_PERL2_bp 2
#define XCL_PERL3_bm (1<<3)
#define XCL_PERL3_bp 3
#define XCL_PERL4_bm (1<<4)
#define XCL_PERL4_bp 4
#define XCL_PERL5_bm (1<<5)
#define XCL_PERL5_bp 5
#define XCL_PERL6_bm (1<<6)
#define XCL_PERL6_bp 6
#define XCL_PERL7_bm (1<<7)
#define XCL_PERL7_bp 7
#define XCL_CAPTL_gm 0xFF
#define XCL_CAPTL_gp 0
#define XCL_CAPTL0_bm (1<<0)
#define XCL_CAPTL0_bp 0
#define XCL_CAPTL1_bm (1<<1)
#define XCL_CAPTL1_bp 1
#define XCL_CAPTL2_bm (1<<2)
#define XCL_CAPTL2_bp 2
#define XCL_CAPTL3_bm (1<<3)
#define XCL_CAPTL3_bp 3
#define XCL_CAPTL4_bm (1<<4)
#define XCL_CAPTL4_bp 4
#define XCL_CAPTL5_bm (1<<5)
#define XCL_CAPTL5_bp 5
#define XCL_CAPTL6_bm (1<<6)
#define XCL_CAPTL6_bp 6
#define XCL_CAPTL7_bm (1<<7)
#define XCL_CAPTL7_bp 7
#define XCL_BPER0_gm 0xFF
#define XCL_BPER0_gp 0
#define XCL_BPER00_bm (1<<0)
#define XCL_BPER00_bp 0
#define XCL_BPER01_bm (1<<1)
#define XCL_BPER01_bp 1
#define XCL_BPER02_bm (1<<2)
#define XCL_BPER02_bp 2
#define XCL_BPER03_bm (1<<3)
#define XCL_BPER03_bp 3
#define XCL_BPER04_bm (1<<4)
#define XCL_BPER04_bp 4
#define XCL_BPER05_bm (1<<5)
#define XCL_BPER05_bp 5
#define XCL_BPER06_bm (1<<6)
#define XCL_BPER06_bp 6
#define XCL_BPER07_bm (1<<7)
#define XCL_BPER07_bp 7
#define XCL_BCAPT0_gm 0xFF
#define XCL_BCAPT0_gp 0
#define XCL_BCAPT00_bm (1<<0)
#define XCL_BCAPT00_bp 0
#define XCL_BCAPT01_bm (1<<1)
#define XCL_BCAPT01_bp 1
#define XCL_BCAPT02_bm (1<<2)
#define XCL_BCAPT02_bp 2
#define XCL_BCAPT03_bm (1<<3)
#define XCL_BCAPT03_bp 3
#define XCL_BCAPT04_bm (1<<4)
#define XCL_BCAPT04_bp 4
#define XCL_BCAPT05_bm (1<<5)
#define XCL_BCAPT05_bp 5
#define XCL_BCAPT06_bm (1<<6)
#define XCL_BCAPT06_bp 6
#define XCL_BCAPT07_bm (1<<7)
#define XCL_BCAPT07_bp 7
#define XCL_PERH_gm 0xFF
#define XCL_PERH_gp 0
#define XCL_PERH0_bm (1<<0)
#define XCL_PERH0_bp 0
#define XCL_PERH1_bm (1<<1)
#define XCL_PERH1_bp 1
#define XCL_PERH2_bm (1<<2)
#define XCL_PERH2_bp 2
#define XCL_PERH3_bm (1<<3)
#define XCL_PERH3_bp 3
#define XCL_PERH4_bm (1<<4)
#define XCL_PERH4_bp 4
#define XCL_PERH5_bm (1<<5)
#define XCL_PERH5_bp 5
#define XCL_PERH6_bm (1<<6)
#define XCL_PERH6_bp 6
#define XCL_PERH7_bm (1<<7)
#define XCL_PERH7_bp 7
#define XCL_CAPTH_gm 0xFF
#define XCL_CAPTH_gp 0
#define XCL_CAPTH0_bm (1<<0)
#define XCL_CAPTH0_bp 0
#define XCL_CAPTH1_bm (1<<1)
#define XCL_CAPTH1_bp 1
#define XCL_CAPTH2_bm (1<<2)
#define XCL_CAPTH2_bp 2
#define XCL_CAPTH3_bm (1<<3)
#define XCL_CAPTH3_bp 3
#define XCL_CAPTH4_bm (1<<4)
#define XCL_CAPTH4_bp 4
#define XCL_CAPTH5_bm (1<<5)
#define XCL_CAPTH5_bp 5
#define XCL_CAPTH6_bm (1<<6)
#define XCL_CAPTH6_bp 6
#define XCL_CAPTH7_bm (1<<7)
#define XCL_CAPTH7_bp 7
#define XCL_BPER1_gm 0xFF
#define XCL_BPER1_gp 0
#define XCL_BPER10_bm (1<<0)
#define XCL_BPER10_bp 0
#define XCL_BPER11_bm (1<<1)
#define XCL_BPER11_bp 1
#define XCL_BPER12_bm (1<<2)
#define XCL_BPER12_bp 2
#define XCL_BPER13_bm (1<<3)
#define XCL_BPER13_bp 3
#define XCL_BPER14_bm (1<<4)
#define XCL_BPER14_bp 4
#define XCL_BPER15_bm (1<<5)
#define XCL_BPER15_bp 5
#define XCL_BPER16_bm (1<<6)
#define XCL_BPER16_bp 6
#define XCL_BPER17_bm (1<<7)
#define XCL_BPER17_bp 7
#define XCL_BCAPT1_gm 0xFF
#define XCL_BCAPT1_gp 0
#define XCL_BCAPT10_bm (1<<0)
#define XCL_BCAPT10_bp 0
#define XCL_BCAPT11_bm (1<<1)
#define XCL_BCAPT11_bp 1
#define XCL_BCAPT12_bm (1<<2)
#define XCL_BCAPT12_bp 2
#define XCL_BCAPT13_bm (1<<3)
#define XCL_BCAPT13_bp 3
#define XCL_BCAPT14_bm (1<<4)
#define XCL_BCAPT14_bp 4
#define XCL_BCAPT15_bm (1<<5)
#define XCL_BCAPT15_bp 5
#define XCL_BCAPT16_bm (1<<6)
#define XCL_BCAPT16_bp 6
#define XCL_BCAPT17_bm (1<<7)
#define XCL_BCAPT17_bp 7
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
#define PORTR_INT_vect_num 2
#define PORTR_INT_vect _VECTOR(2)
#define EDMA_CH0_vect_num 3
#define EDMA_CH0_vect _VECTOR(3)
#define EDMA_CH1_vect_num 4
#define EDMA_CH1_vect _VECTOR(4)
#define EDMA_CH2_vect_num 5
#define EDMA_CH2_vect _VECTOR(5)
#define EDMA_CH3_vect_num 6
#define EDMA_CH3_vect _VECTOR(6)
#define RTC_OVF_vect_num 7
#define RTC_OVF_vect _VECTOR(7)
#define RTC_COMP_vect_num 8
#define RTC_COMP_vect _VECTOR(8)
#define PORTC_INT_vect_num 9
#define PORTC_INT_vect _VECTOR(9)
#define TWIC_TWIS_vect_num 10
#define TWIC_TWIS_vect _VECTOR(10)
#define TWIC_TWIM_vect_num 11
#define TWIC_TWIM_vect _VECTOR(11)
#define TCC4_OVF_vect_num 12
#define TCC4_OVF_vect _VECTOR(12)
#define TCC4_ERR_vect_num 13
#define TCC4_ERR_vect _VECTOR(13)
#define TCC4_CCA_vect_num 14
#define TCC4_CCA_vect _VECTOR(14)
#define TCC4_CCB_vect_num 15
#define TCC4_CCB_vect _VECTOR(15)
#define TCC4_CCC_vect_num 16
#define TCC4_CCC_vect _VECTOR(16)
#define TCC4_CCD_vect_num 17
#define TCC4_CCD_vect _VECTOR(17)
#define TCC5_OVF_vect_num 18
#define TCC5_OVF_vect _VECTOR(18)
#define TCC5_ERR_vect_num 19
#define TCC5_ERR_vect _VECTOR(19)
#define TCC5_CCA_vect_num 20
#define TCC5_CCA_vect _VECTOR(20)
#define TCC5_CCB_vect_num 21
#define TCC5_CCB_vect _VECTOR(21)
#define SPIC_INT_vect_num 22
#define SPIC_INT_vect _VECTOR(22)
#define USARTC0_RXC_vect_num 23
#define USARTC0_RXC_vect _VECTOR(23)
#define USARTC0_DRE_vect_num 24
#define USARTC0_DRE_vect _VECTOR(24)
#define USARTC0_TXC_vect_num 25
#define USARTC0_TXC_vect _VECTOR(25)
#define NVM_EE_vect_num 26
#define NVM_EE_vect _VECTOR(26)
#define NVM_SPM_vect_num 27
#define NVM_SPM_vect _VECTOR(27)
#define XCL_UNF_vect_num 28
#define XCL_UNF_vect _VECTOR(28)
#define XCL_CC_vect_num 29
#define XCL_CC_vect _VECTOR(29)
#define PORTA_INT_vect_num 30
#define PORTA_INT_vect _VECTOR(30)
#define ACA_AC0_vect_num 31
#define ACA_AC0_vect _VECTOR(31)
#define ACA_AC1_vect_num 32
#define ACA_AC1_vect _VECTOR(32)
#define ACA_ACW_vect_num 33
#define ACA_ACW_vect _VECTOR(33)
#define ADCA_CH0_vect_num 34
#define ADCA_CH0_vect _VECTOR(34)
#define PORTD_INT_vect_num 35
#define PORTD_INT_vect _VECTOR(35)
#define TCD5_OVF_vect_num 36
#define TCD5_OVF_vect _VECTOR(36)
#define TCD5_ERR_vect_num 37
#define TCD5_ERR_vect _VECTOR(37)
#define TCD5_CCA_vect_num 38
#define TCD5_CCA_vect _VECTOR(38)
#define TCD5_CCB_vect_num 39
#define TCD5_CCB_vect _VECTOR(39)
#define USARTD0_RXC_vect_num 40
#define USARTD0_RXC_vect _VECTOR(40)
#define USARTD0_DRE_vect_num 41
#define USARTD0_DRE_vect _VECTOR(41)
#define USARTD0_TXC_vect_num 42
#define USARTD0_TXC_vect _VECTOR(42)
#define _VECTOR_SIZE 4
#define _VECTORS_SIZE (43 * _VECTOR_SIZE)
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
# define PROGMEM_START (0x0000)
# define PROGMEM_SIZE (36864)
#else
# define PROGMEM_START (0x0000U)
# define PROGMEM_SIZE (36864U)
#endif
#define PROGMEM_END (PROGMEM_START + PROGMEM_SIZE - 1)
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
# define APP_SECTION_START (0x0000)
# define APP_SECTION_SIZE (32768)
# define APP_SECTION_PAGE_SIZE (128)
#else
# define APP_SECTION_START (0x0000U)
# define APP_SECTION_SIZE (32768U)
# define APP_SECTION_PAGE_SIZE (128U)
#endif
#define APP_SECTION_END (APP_SECTION_START + APP_SECTION_SIZE - 1)
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
# define APPTABLE_SECTION_START (0x7000)
# define APPTABLE_SECTION_SIZE (4096)
# define APPTABLE_SECTION_PAGE_SIZE (128)
#else
# define APPTABLE_SECTION_START (0x7000U)
# define APPTABLE_SECTION_SIZE (4096U)
# define APPTABLE_SECTION_PAGE_SIZE (128U)
#endif
#define APPTABLE_SECTION_END (APPTABLE_SECTION_START + APPTABLE_SECTION_SIZE - 1)
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
# define BOOT_SECTION_START (0x8000)
# define BOOT_SECTION_SIZE (4096)
# define BOOT_SECTION_PAGE_SIZE (128)
#else
# define BOOT_SECTION_START (0x8000U)
# define BOOT_SECTION_SIZE (4096U)
# define BOOT_SECTION_PAGE_SIZE (128U)
#endif
#define BOOT_SECTION_END (BOOT_SECTION_START + BOOT_SECTION_SIZE - 1)
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
# define DATAMEM_START (0x0000)
# define DATAMEM_SIZE (12288)
#else
# define DATAMEM_START (0x0000U)
# define DATAMEM_SIZE (12288U)
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
# define MAPPED_EEPROM_SIZE (1024)
# define MAPPED_EEPROM_PAGE_SIZE (0)
#else
# define MAPPED_EEPROM_START (0x1000U)
# define MAPPED_EEPROM_SIZE (1024U)
# define MAPPED_EEPROM_PAGE_SIZE (0U)
#endif
#define MAPPED_EEPROM_END (MAPPED_EEPROM_START + MAPPED_EEPROM_SIZE - 1)
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
# define INTERNAL_SRAM_START (0x2000)
# define INTERNAL_SRAM_SIZE (4096)
# define INTERNAL_SRAM_PAGE_SIZE (0)
#else
# define INTERNAL_SRAM_START (0x2000U)
# define INTERNAL_SRAM_SIZE (4096U)
# define INTERNAL_SRAM_PAGE_SIZE (0U)
#endif
#define INTERNAL_SRAM_END (INTERNAL_SRAM_START + INTERNAL_SRAM_SIZE - 1)
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
# define EEPROM_START (0x0000)
# define EEPROM_SIZE (1024)
# define EEPROM_PAGE_SIZE (32)
#else
# define EEPROM_START (0x0000U)
# define EEPROM_SIZE (1024U)
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
# define FUSES_SIZE (7)
# define FUSES_PAGE_SIZE (0)
#else
# define FUSES_START (0x0000U)
# define FUSES_SIZE (7U)
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
# define USER_SIGNATURES_SIZE (128)
# define USER_SIGNATURES_PAGE_SIZE (128)
#else
# define USER_SIGNATURES_START (0x0000U)
# define USER_SIGNATURES_SIZE (128U)
# define USER_SIGNATURES_PAGE_SIZE (128U)
#endif
#define USER_SIGNATURES_END (USER_SIGNATURES_START + USER_SIGNATURES_SIZE - 1)
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
# define PROD_SIGNATURES_START (0x0000)
# define PROD_SIGNATURES_SIZE (54)
# define PROD_SIGNATURES_PAGE_SIZE (128)
#else
# define PROD_SIGNATURES_START (0x0000U)
# define PROD_SIGNATURES_SIZE (54U)
# define PROD_SIGNATURES_PAGE_SIZE (128U)
#endif
#define PROD_SIGNATURES_END (PROD_SIGNATURES_START + PROD_SIGNATURES_SIZE - 1)
#define FLASHSTART PROGMEM_START
#define FLASHEND PROGMEM_END
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
# define SPM_PAGESIZE 128
#else
# define SPM_PAGESIZE 128U
#endif
#define RAMSTART INTERNAL_SRAM_START
#define RAMSIZE INTERNAL_SRAM_SIZE
#define RAMEND INTERNAL_SRAM_END
#define E2END EEPROM_END
#define E2PAGESIZE EEPROM_PAGE_SIZE
#define FUSE_MEMORY_SIZE 7
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
#define FUSE_BOOTRST (unsigned char)~_BV(6)
#define FUSE2_DEFAULT (0xff)
#define FUSE_FUSEBYTE2_DEFAULT (0xff)
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
#define FUSE_VALUE0 (unsigned char)~_BV(0)
#define FUSE_VALUE1 (unsigned char)~_BV(1)
#define FUSE_VALUE2 (unsigned char)~_BV(2)
#define FUSE_VALUE3 (unsigned char)~_BV(3)
#define FUSE_VALUE4 (unsigned char)~_BV(4)
#define FUSE_VALUE5 (unsigned char)~_BV(5)
#define FUSE_FDACT4 (unsigned char)~_BV(6)
#define FUSE_FDACT5 (unsigned char)~_BV(7)
#define FUSE6_DEFAULT (0xff)
#define FUSE_FUSEBYTE6_DEFAULT (0xff)
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_APPLICATION_TABLE_BITS_EXIST
#define __BOOT_LOCK_APPLICATION_BITS_EXIST
#define __BOOT_LOCK_BOOT_BITS_EXIST
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x95
#define SIGNATURE_2 0x4C
#define __AVR_HAVE_PRGEN (PR_XCL_bm|PR_RTC_bm|PR_EVSYS_bm|PR_EDMA_bm)
#define __AVR_HAVE_PRGEN_XCL
#define __AVR_HAVE_PRGEN_RTC
#define __AVR_HAVE_PRGEN_EVSYS
#define __AVR_HAVE_PRGEN_EDMA
#define __AVR_HAVE_PRPA (PR_DAC_bm|PR_ADC_bm|PR_AC_bm)
#define __AVR_HAVE_PRPA_DAC
#define __AVR_HAVE_PRPA_ADC
#define __AVR_HAVE_PRPA_AC
#define __AVR_HAVE_PRPC (PR_TWI_bm|PR_USART0_bm|PR_SPI_bm|PR_HIRES_bm|PR_TC5_bm|PR_TC4_bm)
#define __AVR_HAVE_PRPC_TWI
#define __AVR_HAVE_PRPC_USART0
#define __AVR_HAVE_PRPC_SPI
#define __AVR_HAVE_PRPC_HIRES
#define __AVR_HAVE_PRPC_TC5
#define __AVR_HAVE_PRPC_TC4
#define __AVR_HAVE_PRPD (PR_USART0_bm|PR_TC5_bm)
#define __AVR_HAVE_PRPD_USART0
#define __AVR_HAVE_PRPD_TC5
#endif
