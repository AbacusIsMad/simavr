#ifndef _AVR_POWER_H_
#define _AVR_POWER_H_ 1
#include <avr/io.h>
#include <stdint.h>
#if defined(__AVR_HAVE_PRR_PRADC)
#define power_adc_enable() (PRR &= (uint8_t)~(1 << PRADC))
#define power_adc_disable() (PRR |= (uint8_t)(1 << PRADC))
#endif
#if defined(__AVR_HAVE_PRR_PRCAN)
#define power_can_enable() (PRR &= (uint8_t)~(1 << PRCAN))
#define power_can_disable() (PRR |= (uint8_t)(1 << PRCAN))
#endif
#if defined(__AVR_HAVE_PRR_PRLCD)
#define power_lcd_enable() (PRR &= (uint8_t)~(1 << PRLCD))
#define power_lcd_disable() (PRR |= (uint8_t)(1 << PRLCD))
#endif
#if defined(__AVR_HAVE_PRR_PRLIN)
#define power_lin_enable() (PRR &= (uint8_t)~(1 << PRLIN))
#define power_lin_disable() (PRR |= (uint8_t)(1 << PRLIN))
#endif
#if defined(__AVR_HAVE_PRR_PRPSC)
#define power_psc_enable() (PRR &= (uint8_t)~(1 << PRPSC))
#define power_psc_disable() (PRR |= (uint8_t)(1 << PRPSC))
#endif
#if defined(__AVR_HAVE_PRR_PRPSC0)
#define power_psc0_enable() (PRR &= (uint8_t)~(1 << PRPSC0))
#define power_psc0_disable() (PRR |= (uint8_t)(1 << PRPSC0))
#endif
#if defined(__AVR_HAVE_PRR_PRPSC1)
#define power_psc1_enable() (PRR &= (uint8_t)~(1 << PRPSC1))
#define power_psc1_disable() (PRR |= (uint8_t)(1 << PRPSC1))
#endif
#if defined(__AVR_HAVE_PRR_PRPSC2)
#define power_psc2_enable() (PRR &= (uint8_t)~(1 << PRPSC2))
#define power_psc2_disable() (PRR |= (uint8_t)(1 << PRPSC2))
#endif
#if defined(__AVR_HAVE_PRR_PRPSCR)
#define power_pscr_enable() (PRR &= (uint8_t)~(1 << PRPSCR))
#define power_pscr_disable() (PRR |= (uint8_t)(1 << PRPSCR))
#endif
#if defined(__AVR_HAVE_PRR_PRSPI)
#define power_spi_enable() (PRR &= (uint8_t)~(1 << PRSPI))
#define power_spi_disable() (PRR |= (uint8_t)(1 << PRSPI))
#endif
#if defined(__AVR_HAVE_PRR_PRTIM0)
#define power_timer0_enable() (PRR &= (uint8_t)~(1 << PRTIM0))
#define power_timer0_disable() (PRR |= (uint8_t)(1 << PRTIM0))
#endif
#if defined(__AVR_HAVE_PRR_PRTIM1)
#define power_timer1_enable() (PRR &= (uint8_t)~(1 << PRTIM1))
#define power_timer1_disable() (PRR |= (uint8_t)(1 << PRTIM1))
#endif
#if defined(__AVR_HAVE_PRR_PRTIM2)
#define power_timer2_enable() (PRR &= (uint8_t)~(1 << PRTIM2))
#define power_timer2_disable() (PRR |= (uint8_t)(1 << PRTIM2))
#endif
#if defined(__AVR_HAVE_PRR_PRTWI)
#define power_twi_enable() (PRR &= (uint8_t)~(1 << PRTWI))
#define power_twi_disable() (PRR |= (uint8_t)(1 << PRTWI))
#endif
#if defined(__AVR_HAVE_PRR_PRUSART)
#define power_usart_enable() (PRR &= (uint8_t)~(1 << PRUSART))
#define power_usart_disable() (PRR |= (uint8_t)(1 << PRUSART))
#endif
#if defined(__AVR_HAVE_PRR_PRUSART0)
#define power_usart0_enable() (PRR &= (uint8_t)~(1 << PRUSART0))
#define power_usart0_disable() (PRR |= (uint8_t)(1 << PRUSART0))
#endif
#if defined(__AVR_HAVE_PRR_PRUSART1)
#define power_usart1_enable() (PRR &= (uint8_t)~(1 << PRUSART1))
#define power_usart1_disable() (PRR |= (uint8_t)(1 << PRUSART1))
#endif
#if defined(__AVR_HAVE_PRR_PRUSI)
#define power_usi_enable() (PRR &= (uint8_t)~(1 << PRUSI))
#define power_usi_disable() (PRR |= (uint8_t)(1 << PRUSI))
#endif
#if defined(__AVR_HAVE_PRR0_PRADC)
#define power_adc_enable() (PRR0 &= (uint8_t)~(1 << PRADC))
#define power_adc_disable() (PRR0 |= (uint8_t)(1 << PRADC))
#endif
#if defined(__AVR_HAVE_PRR0_PRCO)
#define power_clock_output_enable() (PRR0 &= (uint8_t)~(1 << PRCO))
#define power_clock_output_disable() (PRR0 |= (uint8_t)(1 << PRCO))
#endif
#if defined(__AVR_HAVE_PRR0_PRCRC)
#define power_crc_enable() (PRR0 &= (uint8_t)~(1 << PRCRC))
#define power_crc_disable() (PRR0 |= (uint8_t)(1 << PRCRC))
#endif
#if defined(__AVR_HAVE_PRR0_PRCU)
#define power_crypto_enable() (PRR0 &= (uint8_t)~(1 << PRCU))
#define power_crypto_disable() (PRR0 |= (uint8_t)(1 << PRCU))
#endif
#if defined(__AVR_HAVE_PRR0_PRDS)
#define power_irdriver_enable() (PRR0 &= (uint8_t)~(1 << PRDS))
#define power_irdriver_disable() (PRR0 |= (uint8_t)(1 << PRDS))
#endif
#if defined(__AVR_HAVE_PRR0_PRLFR)
#define power_lfreceiver_enable() (PRR0 &= (uint8_t)~(1 << PRLFR))
#define power_lfreceiver_disable() (PRR0 |= (uint8_t)(1 << PRLFR))
#endif
#if defined(__AVR_HAVE_PRR0_PRLFRS)
#define power_lfrs_enable() (PRR0 &= (uint8_t)~(1 << PRLFRS))
#define power_lfrs_disable() (PRR0 |= (uint8_t)(1 << PRLFRS))
#endif
#if defined(__AVR_HAVE_PRR0_PRLIN)
#define power_lin_enable() (PRR0 &= (uint8_t)~(1 << PRLIN))
#define power_lin_disable() (PRR0 |= (uint8_t)(1 << PRLIN))
#endif
#if defined(__AVR_HAVE_PRR0_PRPGA)
#define power_pga_enable() (PRR0 &= (uint8_t)~(1 << PRPGA))
#define power_pga_disable() (PRR0 |= (uint8_t)(1 << PRPGA))
#endif
#if defined(__AVR_HAVE_PRR0_PRRXDC)
#define power_receive_dsp_control_enable() (PRR0 &= (uint8_t)~(1 << PRRXDC))
#define power_receive_dsp_control_disable() (PRR0 |= (uint8_t)(1 << PRRXDC))
#endif
#if defined(__AVR_HAVE_PRR0_PRSPI)
#define power_spi_enable() (PRR0 &= (uint8_t)~(1 << PRSPI))
#define power_spi_disable() (PRR0 |= (uint8_t)(1 << PRSPI))
#endif
#if defined(__AVR_HAVE_PRR0_PRT0)
#define power_timer0_enable() (PRR0 &= (uint8_t)~(1 << PRT0))
#define power_timer0_disable() (PRR0 |= (uint8_t)(1 << PRT0))
#endif
#if defined(__AVR_HAVE_PRR0_PRTIM0)
#define power_timer0_enable() (PRR0 &= (uint8_t)~(1 << PRTIM0))
#define power_timer0_disable() (PRR0 |= (uint8_t)(1 << PRTIM0))
#endif
#if defined(__AVR_HAVE_PRR0_PRT1)
#define power_timer1_enable() (PRR0 &= (uint8_t)~(1 << PRT1))
#define power_timer1_disable() (PRR0 |= (uint8_t)(1 << PRT1))
#endif
#if defined(__AVR_HAVE_PRR0_PRTIM1)
#define power_timer1_enable() (PRR0 &= (uint8_t)~(1 << PRTIM1))
#define power_timer1_disable() (PRR0 |= (uint8_t)(1 << PRTIM1))
#endif
#if defined(__AVR_HAVE_PRR0_PRT2)
#define power_timer2_enable() (PRR0 &= (uint8_t)~(1 << PRT2))
#define power_timer2_disable() (PRR0 |= (uint8_t)(1 << PRT2))
#endif
#if defined(__AVR_HAVE_PRR0_PRTIM2)
#define power_timer2_enable() (PRR0 &= (uint8_t)~(1 << PRTIM2))
#define power_timer2_disable() (PRR0 |= (uint8_t)(1 << PRTIM2))
#endif
#if defined(__AVR_HAVE_PRR0_PRT3)
#define power_timer3_enable() (PRR0 &= (uint8_t)~(1 << PRT3))
#define power_timer3_disable() (PRR0 |= (uint8_t)(1 << PRT3))
#endif
#if defined(__AVR_HAVE_PRR0_PRTM)
#define power_timermodulator_enable() (PRR0 &= (uint8_t)~(1 << PRTM))
#define power_timermodulator_disable() (PRR0 |= (uint8_t)(1 << PRTM))
#endif
#if defined(__AVR_HAVE_PRR0_PRTWI)
#define power_twi_enable() (PRR0 &= (uint8_t)~(1 << PRTWI))
#define power_twi_disable() (PRR0 |= (uint8_t)(1 << PRTWI))
#endif
#if defined(__AVR_HAVE_PRR0_PRTWI1)
#define power_twi1_enable() (PRR0 &= (uint8_t)~(1 << PRTWI1))
#define power_twi1_disable() (PRR0 |= (uint8_t)(1 << PRTWI1))
#endif
#if defined(__AVR_HAVE_PRR0_PRTXDC)
#define power_transmit_dsp_control_enable() (PRR0 &= (uint8_t)~(1 << PRTXDC))
#define power_transmit_dsp_control_disable() (PRR0 |= (uint8_t)(1 << PRTXDC))
#endif
#if defined(__AVR_HAVE_PRR0_PRUSART0)
#define power_usart0_enable() (PRR0 &= (uint8_t)~(1 << PRUSART0))
#define power_usart0_disable() (PRR0 |= (uint8_t)(1 << PRUSART0))
#endif
#if defined(__AVR_HAVE_PRR0_PRUSART1)
#define power_usart1_enable() (PRR0 &= (uint8_t)~(1 << PRUSART1))
#define power_usart1_disable() (PRR0 |= (uint8_t)(1 << PRUSART1))
#endif
#if defined(__AVR_HAVE_PRR0_PRVADC)
#define power_vadc_enable() (PRR0 &= (uint8_t)~(1 << PRVADC))
#define power_vadc_disable() (PRR0 |= (uint8_t)(1 << PRVADC))
#endif
#if defined(__AVR_HAVE_PRR0_PRVM)
#define power_voltage_monitor_enable() (PRR0 &= (uint8_t)~(1 << PRVM))
#define power_voltage_monitor_disable() (PRR0 |= (uint8_t)(1 << PRVM))
#endif
#if defined(__AVR_HAVE_PRR0_PRVRM)
#define power_vrm_enable() (PRR0 &= (uint8_t)~(1 << PRVRM))
#define power_vrm_disable() (PRR0 |= (uint8_t)(1 << PRVRM))
#endif
#if defined(__AVR_HAVE_PRR1_PRAES)
#define power_aes_enable() (PRR1 &= (uint8_t)~(1 << PRAES))
#define power_aes_disable() (PRR1 |= (uint8_t)(1 << PRAES))
#endif
#if defined(__AVR_HAVE_PRR1_PRCI)
#define power_cinterface_enable() (PRR1 &= (uint8_t)~(1 << PRCI))
#define power_cinterface_disable() (PRR1 |= (uint8_t)(1 << PRCI))
#endif
#if defined(__AVR_HAVE_PRR1_PRHSSPI)
#define power_hsspi_enable() (PRR1 &= (uint8_t)~(1 << PRHSSPI))
#define power_hsspi_disable() (PRR1 |= (uint8_t)(1 << PRHSSPI))
#endif
#if defined(__AVR_HAVE_PRR1_PRKB)
#define power_kb_enable() (PRR1 &= (uint8_t)~(1 << PRKB))
#define power_kb_disable() (PRR1 |= (uint8_t)(1 << PRKB))
#endif
#if defined(__AVR_HAVE_PRR1_PRLFPH)
#define power_lfph_enable() (PRR1 &= (uint8_t)~(1 << PRLFPH))
#define power_lfph_disable() (PRR1 |= (uint8_t)(1 << PRLFPH))
#endif
#if defined(__AVR_HAVE_PRR1_PRLFR)
#define power_lfreceiver_enable() (PRR1 &= (uint8_t)~(1 << PRLFR))
#define power_lfreceiver_disable() (PRR1 |= (uint8_t)(1 << PRLFR))
#endif
#if defined(__AVR_HAVE_PRR1_PRLFTP)
#define power_lftp_enable() (PRR1 &= (uint8_t)~(1 << PRLFTP))
#define power_lftp_disable() (PRR1 |= (uint8_t)(1 << PRLFTP))
#endif
#if defined(__AVR_HAVE_PRR1_PRSCI)
#define power_sci_enable() (PRR1 &= (uint8_t)~(1 << PRSCI))
#define power_sci_disable() (PRR1 |= (uint8_t)(1 << PRSCI))
#endif
#if defined(__AVR_HAVE_PRR1_PRSPI)
#define power_spi_enable() (PRR1 &= (uint8_t)~(1 << PRSPI))
#define power_spi_disable() (PRR1 |= (uint8_t)(1 << PRSPI))
#endif
#if defined(__AVR_HAVE_PRR1_PRT1)
#define power_timer1_enable() (PRR1 &= (uint8_t)~(1 << PRT1))
#define power_timer1_disable() (PRR1 |= (uint8_t)(1 << PRT1))
#endif
#if defined(__AVR_HAVE_PRR1_PRT2)
#define power_timer2_enable() (PRR1 &= (uint8_t)~(1 << PRT2))
#define power_timer2_disable() (PRR1 |= (uint8_t)(1 << PRT2))
#endif
#if defined(__AVR_HAVE_PRR1_PRT3)
#define power_timer3_enable() (PRR1 &= (uint8_t)~(1 << PRT3))
#define power_timer3_disable() (PRR1 |= (uint8_t)(1 << PRT3))
#endif
#if defined(__AVR_HAVE_PRR1_PRT4)
#define power_timer4_enable() (PRR1 &= (uint8_t)~(1 << PRT4))
#define power_timer4_disable() (PRR1 |= (uint8_t)(1 << PRT4))
#endif
#if defined(__AVR_HAVE_PRR1_PRT5)
#define power_timer5_enable() (PRR1 &= (uint8_t)~(1 << PRT5))
#define power_timer5_disable() (PRR1 |= (uint8_t)(1 << PRT5))
#endif
#if defined(__AVR_HAVE_PRR1_PRTIM3)
#define power_timer3_enable() (PRR1 &= (uint8_t)~(1 << PRTIM3))
#define power_timer3_disable() (PRR1 |= (uint8_t)(1 << PRTIM3))
#endif
#if defined(__AVR_HAVE_PRR1_PRTIM4)
#define power_timer4_enable() (PRR1 &= (uint8_t)~(1 << PRTIM4))
#define power_timer4_disable() (PRR1 |= (uint8_t)(1 << PRTIM4))
#endif
#if defined(__AVR_HAVE_PRR1_PRTIM5)
#define power_timer5_enable() (PRR1 &= (uint8_t)~(1 << PRTIM5))
#define power_timer5_disable() (PRR1 |= (uint8_t)(1 << PRTIM5))
#endif
#if defined(__AVR_HAVE_PRR1_PRTRX24)
#define power_transceiver_enable() (PRR1 &= (uint8_t)~(1 << PRTRX24))
#define power_transceiver_disable() (PRR1 |= (uint8_t)(1 << PRTRX24))
#endif
#if defined(__AVR_HAVE_PRR1_PRUSART1)
#define power_usart1_enable() (PRR1 &= (uint8_t)~(1 << PRUSART1))
#define power_usart1_disable() (PRR1 |= (uint8_t)(1 << PRUSART1))
#endif
#if defined(__AVR_HAVE_PRR1_PRUSART2)
#define power_usart2_enable() (PRR1 &= (uint8_t)~(1 << PRUSART2))
#define power_usart2_disable() (PRR1 |= (uint8_t)(1 << PRUSART2))
#endif
#if defined(__AVR_HAVE_PRR1_PRUSART3)
#define power_usart3_enable() (PRR1 &= (uint8_t)~(1 << PRUSART3))
#define power_usart3_disable() (PRR1 |= (uint8_t)(1 << PRUSART3))
#endif
#if defined(__AVR_HAVE_PRR1_PRUSB)
#define power_usb_enable() (PRR1 &= (uint8_t)~(1 << PRUSB))
#define power_usb_disable() (PRR1 |= (uint8_t)(1 << PRUSB))
#endif
#if defined(__AVR_HAVE_PRR1_PRUSBH)
#define power_usbh_enable() (PRR1 &= (uint8_t)~(1 << PRUSBH))
#define power_usbh_disable() (PRR1 |= (uint8_t)(1 << PRUSBH))
#endif
#if defined(__AVR_HAVE_PRR2_PRDF)
#define power_data_fifo_enable() (PRR2 &= (uint8_t)~(1 << PRDF))
#define power_data_fifo_disable() (PRR2 |= (uint8_t)(1 << PRDF))
#endif
#if defined(__AVR_HAVE_PRR2_PRIDS)
#define power_id_scan_enable() (PRR2 &= (uint8_t)~(1 << PRIDS))
#define power_id_scan_disable() (PRR2 |= (uint8_t)(1 << PRIDS))
#endif
#if defined(__AVR_HAVE_PRR2_PRRAM0)
#define power_ram0_enable() (PRR2 &= (uint8_t)~(1 << PRRAM0))
#define power_ram0_disable() (PRR2 |= (uint8_t)(1 << PRRAM0))
#endif
#if defined(__AVR_HAVE_PRR2_PRRAM1)
#define power_ram1_enable() (PRR2 &= (uint8_t)~(1 << PRRAM1))
#define power_ram1_disable() (PRR2 |= (uint8_t)(1 << PRRAM1))
#endif
#if defined(__AVR_HAVE_PRR2_PRRAM2)
#define power_ram2_enable() (PRR2 &= (uint8_t)~(1 << PRRAM2))
#define power_ram2_disable() (PRR2 |= (uint8_t)(1 << PRRAM2))
#endif
#if defined(__AVR_HAVE_PRR2_PRRAM3)
#define power_ram3_enable() (PRR2 &= (uint8_t)~(1 << PRRAM3))
#define power_ram3_disable() (PRR2 |= (uint8_t)(1 << PRRAM3))
#endif
#if defined(__AVR_HAVE_PRR2_PRRS)
#define power_rssi_buffer_enable() (PRR2 &= (uint8_t)~(1 << PRRS))
#define power_rssi_buffer_disable() (PRR2 |= (uint8_t)(1 << PRRS))
#endif
#if defined(__AVR_HAVE_PRR2_PRSF)
#define power_preamble_rssi_fifo_enable() (PRR2 &= (uint8_t)~(1 << PRSF))
#define power_preamble_rssi_fifo_disable() (PRR2 |= (uint8_t)(1 << PRSF))
#endif
#if defined(__AVR_HAVE_PRR2_PRSPI2)
#define power_spi2_enable() (PRR2 &= (uint8_t)~(1 << PRSPI2))
#define power_spi2_disable() (PRR2 |= (uint8_t)(1 << PRSPI2))
#endif
#if defined(__AVR_HAVE_PRR2_PRSSM)
#define power_sequencer_state_machine_enable() (PRR2 &= (uint8_t)~(1 << PRSSM))
#define power_sequencer_state_machine_disable() (PRR2 |= (uint8_t)(1 << PRSSM))
#endif
#if defined(__AVR_HAVE_PRR2_PRTM)
#define power_tx_modulator_enable() (PRR2 &= (uint8_t)~(1 << PRTM))
#define power_tx_modulator_disable() (PRR2 |= (uint8_t)(1 << PRTM))
#endif
#if defined(__AVR_HAVE_PRR2_PRTWI2)
#define power_twi2_enable() (PRR2 &= (uint8_t)~(1 << PRTWI2))
#define power_twi2_disable() (PRR2 |= (uint8_t)(1 << PRTWI2))
#endif
#if defined(__AVR_HAVE_PRR2_PRXA)
#define power_rx_buffer_A_enable() (PRR2 &= (uint8_t)~(1 << PRXA))
#define power_rx_buffer_A_disable() (PRR2 |= (uint8_t)(1 << PRXA))
#endif
#if defined(__AVR_HAVE_PRR2_PRXB)
#define power_rx_buffer_B_enable() (PRR2 &= (uint8_t)~(1 << PRXB))
#define power_rx_buffer_B_disable() (PRR2 |= (uint8_t)(1 << PRXB))
#endif
#if defined(__AVR_HAVE_PRGEN_AES)
#define power_aes_enable() (PR_PRGEN &= (uint8_t)~(PR_AES_bm))
#define power_aes_disable() (PR_PRGEN |= (uint8_t)PR_AES_bm)
#endif
#if defined(__AVR_HAVE_PRGEN_DMA)
#define power_dma_enable() (PR_PRGEN &= (uint8_t)~(PR_DMA_bm))
#define power_dma_disable() (PR_PRGEN |= (uint8_t)PR_DMA_bm)
#endif
#if defined(__AVR_HAVE_PRGEN_EBI)
#define power_ebi_enable() (PR_PRGEN &= (uint8_t)~(PR_EBI_bm))
#define power_ebi_disable() (PR_PRGEN |= (uint8_t)PR_EBI_bm)
#endif
#if defined(__AVR_HAVE_PRGEN_EDMA)
#define power_edma_enable() (PR_PRGEN &= (uint8_t)~(PR_EDMA_bm))
#define power_edma_disable() (PR_PRGEN |= (uint8_t)PR_EDMA_bm)
#endif
#if defined(__AVR_HAVE_PRGEN_EVSYS)
#define power_evsys_enable() (PR_PRGEN &= (uint8_t)~(PR_EVSYS_bm))
#define power_evsys_disable() (PR_PRGEN |= (uint8_t)PR_EVSYS_bm)
#endif
#if defined(__AVR_HAVE_PRGEN_LCD)
#define power_lcd_enable() (PR_PRGEN &= (uint8_t)~(PR_LCD_bm))
#define power_lcd_disable() (PR_PRGEN |= (uint8_t)PR_LCD_bm)
#endif
#if defined(__AVR_HAVE_PRGEN_RTC)
#define power_rtc_enable() (PR_PRGEN &= (uint8_t)~(PR_RTC_bm))
#define power_rtc_disable() (PR_PRGEN |= (uint8_t)PR_RTC_bm)
#endif
#if defined(__AVR_HAVE_PRGEN_USB)
#define power_usb_enable() (PR_PRGEN &= (uint8_t)~(PR_USB_bm))
#define power_usb_disable() (PR_PRGEN &= (uint8_t)(PR_USB_bm))
#endif
#if defined(__AVR_HAVE_PRGEN_XCL)
#define power_xcl_enable() (PR_PRGEN &= (uint8_t)~(PR_XCL_bm))
#define power_xcl_disable() (PR_PRGEN |= (uint8_t)PR_XCL_bm)
#endif
#if defined(__AVR_HAVE_PRPA_AC)
#define power_aca_enable() (PR_PRPA &= (uint8_t)~(PR_AC_bm))
#define power_aca_disable() (PR_PRPA |= (uint8_t)PR_AC_bm)
#endif
#if defined(__AVR_HAVE_PRPA_ADC)
#define power_adca_enable() (PR_PRPA &= (uint8_t)~(PR_ADC_bm))
#define power_adca_disable() (PR_PRPA |= (uint8_t)PR_ADC_bm)
#endif
#if defined(__AVR_HAVE_PRPA_DAC)
#define power_daca_enable() (PR_PRPA &= (uint8_t)~(PR_DAC_bm))
#define power_daca_disable() (PR_PRPA |= (uint8_t)PR_DAC_bm)
#endif
#if defined(__AVR_HAVE_PRPB_AC)
#define power_acb_enable() (PR_PRPB &= (uint8_t)~(PR_AC_bm))
#define power_acb_disable() (PR_PRPB |= (uint8_t)PR_AC_bm)
#endif
#if defined(__AVR_HAVE_PRPB_ADC)
#define power_adcb_enable() (PR_PRPB &= (uint8_t)~(PR_ADC_bm))
#define power_adcb_disable() (PR_PRPB |= (uint8_t)PR_ADC_bm)
#endif
#if defined(__AVR_HAVE_PRPB_DAC)
#define power_dacb_enable() (PR_PRPB &= (uint8_t)~(PR_DAC_bm))
#define power_dacb_disable() (PR_PRPB |= (uint8_t)PR_DAC_bm)
#endif
#if defined(__AVR_HAVE_PRPC_HIRES)
#define power_hiresc_enable() (PR_PRPC &= (uint8_t)~(PR_HIRES_bm))
#define power_hiresc_disable() (PR_PRPC |= (uint8_t)PR_HIRES_bm)
#endif
#if defined(__AVR_HAVE_PRPC_SPI)
#define power_spic_enable() (PR_PRPC &= (uint8_t)~(PR_SPI_bm))
#define power_spic_disable() (PR_PRPC |= (uint8_t)PR_SPI_bm)
#endif
#if defined(__AVR_HAVE_PRPC_TC0)
#define power_tc0c_enable() (PR_PRPC &= (uint8_t)~(PR_TC0_bm))
#define power_tc0c_disable() (PR_PRPC |= (uint8_t)PR_TC0_bm)
#endif
#if defined(__AVR_HAVE_PRPC_TC1)
#define power_tc1c_enable() (PR_PRPC &= (uint8_t)~(PR_TC1_bm))
#define power_tc1c_disable() (PR_PRPC |= (uint8_t)PR_TC1_bm)
#endif
#if defined(__AVR_HAVE_PRPC_TC4)
#define power_tc4c_enable() (PR_PRPC &= (uint8_t)~(PR_TC4_bm))
#define power_tc4c_disable() (PR_PRPC |= (uint8_t)PR_TC4_bm)
#endif
#if defined(__AVR_HAVE_PRPC_TC5)
#define power_tc5c_enable() (PR_PRPC &= (uint8_t)~(PR_TC5_bm))
#define power_tc5c_disable() (PR_PRPC |= (uint8_t)PR_TC5_bm)
#endif
#if defined(__AVR_HAVE_PRPC_TWI)
#define power_twic_enable() (PR_PRPC &= (uint8_t)~(PR_TWI_bm))
#define power_twic_disable() (PR_PRPC |= (uint8_t)PR_TWI_bm)
#endif
#if defined(__AVR_HAVE_PRPC_USART0)
#define power_usartc0_enable() (PR_PRPC &= (uint8_t)~(PR_USART0_bm))
#define power_usartc0_disable() (PR_PRPC |= (uint8_t)PR_USART0_bm)
#endif
#if defined(__AVR_HAVE_PRPC_USART1)
#define power_usartc1_enable() (PR_PRPC &= (uint8_t)~(PR_USART1_bm))
#define power_usartc1_disable() (PR_PRPC |= (uint8_t)PR_USART1_bm)
#endif
#if defined(__AVR_HAVE_PRPD_HIRES)
#define power_hiresd_enable() (PR_PRPD &= (uint8_t)~(PR_HIRES_bm))
#define power_hiresd_disable() (PR_PRPD |= (uint8_t)PR_HIRES_bm)
#endif
#if defined(__AVR_HAVE_PRPD_SPI)
#define power_spid_enable() (PR_PRPD &= (uint8_t)~(PR_SPI_bm))
#define power_spid_disable() (PR_PRPD |= (uint8_t)PR_SPI_bm)
#endif
#if defined(__AVR_HAVE_PRPD_TC0)
#define power_tc0d_enable() (PR_PRPD &= (uint8_t)~(PR_TC0_bm))
#define power_tc0d_disable() (PR_PRPD |= (uint8_t)PR_TC0_bm)
#endif
#if defined(__AVR_HAVE_PRPD_TC1)
#define power_tc1d_enable() (PR_PRPD &= (uint8_t)~(PR_TC1_bm))
#define power_tc1d_disable() (PR_PRPD |= (uint8_t)PR_TC1_bm)
#endif
#if defined(__AVR_HAVE_PRPD_TC5)
#define power_tc5d_enable() (PR_PRPD &= (uint8_t)~(PR_TC5_bm))
#define power_tc5d_disable() (PR_PRPD |= (uint8_t)PR_TC5_bm)
#endif
#if defined(__AVR_HAVE_PRPD_TWI)
#define power_twid_enable() (PR_PRPD &= (uint8_t)~(PR_TWI_bm))
#define power_twid_disable() (PR_PRPD |= (uint8_t)PR_TWI_bm)
#endif
#if defined(__AVR_HAVE_PRPD_USART0)
#define power_usartd0_enable() (PR_PRPD &= (uint8_t)~(PR_USART0_bm))
#define power_usartd0_disable() (PR_PRPD |= (uint8_t)PR_USART0_bm)
#endif
#if defined(__AVR_HAVE_PRPD_USART1)
#define power_usartd1_enable() (PR_PRPD &= (uint8_t)~(PR_USART1_bm))
#define power_usartd1_disable() (PR_PRPD |= (uint8_t)PR_USART1_bm)
#endif
#if defined(__AVR_HAVE_PRPE_HIRES)
#define power_hirese_enable() (PR_PRPE &= (uint8_t)~(PR_HIRES_bm))
#define power_hirese_disable() (PR_PRPE |= (uint8_t)PR_HIRES_bm)
#endif
#if defined(__AVR_HAVE_PRPE_SPI)
#define power_spie_enable() (PR_PRPE &= (uint8_t)~(PR_SPI_bm))
#define power_spie_disable() (PR_PRPE |= (uint8_t)PR_SPI_bm)
#endif
#if defined(__AVR_HAVE_PRPE_TC0)
#define power_tc0e_enable() (PR_PRPE &= (uint8_t)~(PR_TC0_bm))
#define power_tc0e_disable() (PR_PRPE |= (uint8_t)PR_TC0_bm)
#endif
#if defined(__AVR_HAVE_PRPE_TC1)
#define power_tc1e_enable() (PR_PRPE &= (uint8_t)~(PR_TC1_bm))
#define power_tc1e_disable() (PR_PRPE |= (uint8_t)PR_TC1_bm)
#endif
#if defined(__AVR_HAVE_PRPE_TWI)
#define power_twie_enable() (PR_PRPE &= (uint8_t)~(PR_TWI_bm))
#define power_twie_disable() (PR_PRPE |= (uint8_t)PR_TWI_bm)
#endif
#if defined(__AVR_HAVE_PRPE_USART0)
#define power_usarte0_enable() (PR_PRPE &= (uint8_t)~(PR_USART0_bm))
#define power_usarte0_disable() (PR_PRPE |= (uint8_t)PR_USART0_bm)
#endif
#if defined(__AVR_HAVE_PRPE_USART1)
#define power_usarte1_enable() (PR_PRPE &= (uint8_t)~(PR_USART1_bm))
#define power_usarte1_disable() (PR_PRPE |= (uint8_t)PR_USART1_bm)
#endif
#if defined(__AVR_HAVE_PRPF_HIRES)
#define power_hiresf_enable() (PR_PRPF &= (uint8_t)~(PR_HIRES_bm))
#define power_hiresf_disable() (PR_PRPF |= (uint8_t)PR_HIRES_bm)
#endif
#if defined(__AVR_HAVE_PRPF_SPI)
#define power_spif_enable() (PR_PRPF &= (uint8_t)~(PR_SPI_bm))
#define power_spif_disable() (PR_PRPF |= (uint8_t)PR_SPI_bm)
#endif
#if defined(__AVR_HAVE_PRPF_TC0)
#define power_tc0f_enable() (PR_PRPF &= (uint8_t)~(PR_TC0_bm))
#define power_tc0f_disable() (PR_PRPF |= (uint8_t)PR_TC0_bm)
#endif
#if defined(__AVR_HAVE_PRPF_TC1)
#define power_tc1f_enable() (PR_PRPF &= (uint8_t)~(PR_TC1_bm))
#define power_tc1f_disable() (PR_PRPF |= (uint8_t)PR_TC1_bm)
#endif
#if defined(__AVR_HAVE_PRPF_TWI)
#define power_twif_enable() (PR_PRPF &= (uint8_t)~(PR_TWI_bm))
#define power_twif_disable() (PR_PRPF |= (uint8_t)PR_TWI_bm)
#endif
#if defined(__AVR_HAVE_PRPF_USART0)
#define power_usartf0_enable() (PR_PRPF &= (uint8_t)~(PR_USART0_bm))
#define power_usartf0_disable() (PR_PRPF |= (uint8_t)PR_USART0_bm)
#endif
#if defined(__AVR_HAVE_PRPF_USART1)
#define power_usartf1_enable() (PR_PRPF &= (uint8_t)~(PR_USART1_bm))
#define power_usartf1_disable() (PR_PRPF |= (uint8_t)PR_USART1_bm)
#endif
static __inline void
__attribute__ ((__always_inline__))
__power_all_enable()
{
#ifdef __AVR_HAVE_PRR
    PRR &= (uint8_t)~(__AVR_HAVE_PRR);
#endif
#ifdef __AVR_HAVE_PRR0
    PRR0 &= (uint8_t)~(__AVR_HAVE_PRR0);
#endif
#ifdef __AVR_HAVE_PRR1
    PRR1 &= (uint8_t)~(__AVR_HAVE_PRR1);
#endif
#ifdef __AVR_HAVE_PRR2
   PRR2 &= (uint8_t)~(__AVR_HAVE_PRR2);
#endif
#ifdef __AVR_HAVE_PRGEN
    PR_PRGEN &= (uint8_t)~(__AVR_HAVE_PRGEN);
#endif
#ifdef __AVR_HAVE_PRPA
    PR_PRPA &= (uint8_t)~(__AVR_HAVE_PRPA);
#endif
#ifdef __AVR_HAVE_PRPB
    PR_PRPB &= (uint8_t)~(__AVR_HAVE_PRPB);
#endif
#ifdef __AVR_HAVE_PRPC
    PR_PRPC &= (uint8_t)~(__AVR_HAVE_PRPC);
#endif
#ifdef __AVR_HAVE_PRPD
    PR_PRPD &= (uint8_t)~(__AVR_HAVE_PRPD);
#endif
#ifdef __AVR_HAVE_PRPE
    PR_PRPE &= (uint8_t)~(__AVR_HAVE_PRPE);
#endif
#ifdef __AVR_HAVE_PRPF
    PR_PRPF &= (uint8_t)~(__AVR_HAVE_PRPF);
#endif
}
static __inline void
__attribute__ ((__always_inline__))
__power_all_disable()
{
#ifdef __AVR_HAVE_PRR
    PRR |= (uint8_t)(__AVR_HAVE_PRR);
#endif
#ifdef __AVR_HAVE_PRR0
    PRR0 |= (uint8_t)(__AVR_HAVE_PRR0);
#endif
#ifdef __AVR_HAVE_PRR1
    PRR1 |= (uint8_t)(__AVR_HAVE_PRR1);
#endif
#ifdef __AVR_HAVE_PRR2
    PRR2 |= (uint8_t)(__AVR_HAVE_PRR2);
#endif
#ifdef __AVR_HAVE_PRGEN
    PR_PRGEN |= (uint8_t)(__AVR_HAVE_PRGEN);
#endif
#ifdef __AVR_HAVE_PRPA
    PR_PRPA |= (uint8_t)(__AVR_HAVE_PRPA);
#endif
#ifdef __AVR_HAVE_PRPB
    PR_PRPB |= (uint8_t)(__AVR_HAVE_PRPB);
#endif
#ifdef __AVR_HAVE_PRPC
    PR_PRPC |= (uint8_t)(__AVR_HAVE_PRPC);
#endif
#ifdef __AVR_HAVE_PRPD
    PR_PRPD |= (uint8_t)(__AVR_HAVE_PRPD);
#endif
#ifdef __AVR_HAVE_PRPE
    PR_PRPE |= (uint8_t)(__AVR_HAVE_PRPE);
#endif
#ifdef __AVR_HAVE_PRPF
    PR_PRPF |= (uint8_t)(__AVR_HAVE_PRPF);
#endif
}
#ifndef __DOXYGEN__
#ifndef power_all_enable
#define power_all_enable() __power_all_enable()
#endif
#ifndef power_all_disable
#define power_all_disable() __power_all_disable()
#endif
#endif
#if defined(__AVR_AT90CAN32__) || defined(__AVR_AT90CAN64__) || defined(__AVR_AT90CAN128__) || defined(__AVR_AT90PWM1__) || defined(__AVR_AT90PWM2__) || defined(__AVR_AT90PWM2B__) || defined(__AVR_AT90PWM3__) || defined(__AVR_AT90PWM3B__) || defined(__AVR_AT90PWM81__) || defined(__AVR_AT90PWM161__) || defined(__AVR_AT90PWM216__) || defined(__AVR_AT90PWM316__) || defined(__AVR_AT90SCR100__) || defined(__AVR_AT90USB646__) || defined(__AVR_AT90USB647__) || defined(__AVR_AT90USB82__) || defined(__AVR_AT90USB1286__) || defined(__AVR_AT90USB1287__) || defined(__AVR_AT90USB162__) || defined(__AVR_ATA5505__) || defined(__AVR_ATA5272__) || defined(__AVR_ATA6617C__) || defined(__AVR_ATA664251__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega1281__) || defined(__AVR_ATmega1284__) || defined(__AVR_ATmega128RFA1__) || defined(__AVR_ATmega1284RFR2__) || defined(__AVR_ATmega128RFR2__) || defined(__AVR_ATmega1284P__) || defined(__AVR_ATmega162__) || defined(__AVR_ATmega164A__) || defined(__AVR_ATmega164P__) || defined(__AVR_ATmega164PA__) || defined(__AVR_ATmega165__) || defined(__AVR_ATmega165A__) || defined(__AVR_ATmega165P__) || defined(__AVR_ATmega165PA__) || defined(__AVR_ATmega168__) || defined(__AVR_ATmega168A__) || defined(__AVR_ATmega168P__) || defined(__AVR_ATmega168PA__) || defined(__AVR_ATmega168PB__) || defined(__AVR_ATmega169__) || defined(__AVR_ATmega169A__) || defined(__AVR_ATmega169P__) || defined(__AVR_ATmega169PA__) || defined(__AVR_ATmega16M1__) || defined(__AVR_ATmega16U2__) || defined(__AVR_ATmega16U4__) || defined(__AVR_ATmega2560__) || defined(__AVR_ATmega2561__) || defined(__AVR_ATmega2564RFR2__) || defined(__AVR_ATmega256RFR2__) || defined(__AVR_ATmega324A__) || defined(__AVR_ATmega324P__) || defined(__AVR_ATmega324PA__) || defined(__AVR_ATmega324PB__) || defined(__AVR_ATmega325__) || defined(__AVR_ATmega325A__) || defined(__AVR_ATmega325P__) || defined(__AVR_ATmega325PA__) || defined(__AVR_ATmega3250__) || defined(__AVR_ATmega3250A__) || defined(__AVR_ATmega3250P__) || defined(__AVR_ATmega3250PA__) || defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__) || defined(__AVR_ATmega328PB__) || defined(__AVR_ATmega329__) || defined(__AVR_ATmega329A__) || defined(__AVR_ATmega329P__) || defined(__AVR_ATmega329PA__) || defined(__AVR_ATmega3290__) || defined(__AVR_ATmega3290A__) || defined(__AVR_ATmega3290P__) || defined(__AVR_ATmega3290PA__) || defined(__AVR_ATmega32C1__) || defined(__AVR_ATmega32M1__) || defined(__AVR_ATmega32U2__) || defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega32U6__) || defined(__AVR_ATmega48__) || defined(__AVR_ATmega48A__) || defined(__AVR_ATmega48PA__) || defined(__AVR_ATmega48PB__) || defined(__AVR_ATmega48P__) || defined(__AVR_ATmega640__) || defined(__AVR_ATmega649P__) || defined(__AVR_ATmega644__) || defined(__AVR_ATmega644A__) || defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644PA__) || defined(__AVR_ATmega645__) || defined(__AVR_ATmega645A__) || defined(__AVR_ATmega645P__) || defined(__AVR_ATmega6450__) || defined(__AVR_ATmega6450A__) || defined(__AVR_ATmega6450P__) || defined(__AVR_ATmega649__) || defined(__AVR_ATmega649A__) || defined(__AVR_ATmega64M1__) || defined(__AVR_ATmega64C1__) || defined(__AVR_ATmega88A__) || defined(__AVR_ATmega88PA__) || defined(__AVR_ATmega88PB__) || defined(__AVR_ATmega6490__) || defined(__AVR_ATmega6490A__) || defined(__AVR_ATmega6490P__) || defined(__AVR_ATmega644RFR2__) || defined(__AVR_ATmega64RFR2__) || defined(__AVR_ATmega88__) || defined(__AVR_ATmega88P__) || defined(__AVR_ATmega8U2__) || defined(__AVR_ATmega16U2__) || defined(__AVR_ATmega32U2__) || defined(__AVR_ATtiny48__) || defined(__AVR_ATtiny88__) || defined(__AVR_ATtiny87__) || defined(__AVR_ATtiny167__) || defined(__DOXYGEN__)
#ifndef __DOXYGEN__
typedef enum
{
    clock_div_1 = 0,
    clock_div_2 = 1,
    clock_div_4 = 2,
    clock_div_8 = 3,
    clock_div_16 = 4,
    clock_div_32 = 5,
    clock_div_64 = 6,
    clock_div_128 = 7,
    clock_div_256 = 8
#if defined(__AVR_ATmega128RFA1__) || defined(__AVR_ATmega2564RFR2__) || defined(__AVR_ATmega1284RFR2__) || defined(__AVR_ATmega644RFR2__) || defined(__AVR_ATmega256RFR2__) || defined(__AVR_ATmega128RFR2__) || defined(__AVR_ATmega64RFR2__)
    , clock_div_1_rc = 15
#endif
} clock_div_t;
static __inline__ void clock_prescale_set(clock_div_t) __attribute__((__always_inline__));
#endif
void clock_prescale_set(clock_div_t __x)
{
    uint8_t __tmp = _BV(CLKPCE);
    __asm__ __volatile__ (
        "in __tmp_reg__,__SREG__" "\n\t"
        "cli" "\n\t"
        "sts %1, %0" "\n\t"
        "sts %1, %2" "\n\t"
        "out __SREG__, __tmp_reg__"
        :
        : "d" (__tmp),
          "M" (_SFR_MEM_ADDR(CLKPR)),
          "d" (__x)
        : "r0");
}
#define clock_prescale_get() (clock_div_t)(CLKPR & (uint8_t)((1<<CLKPS0)|(1<<CLKPS1)|(1<<CLKPS2)|(1<<CLKPS3)))
#elif defined(__AVR_ATmega16HVB__) || defined(__AVR_ATmega16HVBREVB__) || defined(__AVR_ATmega32HVB__) || defined(__AVR_ATmega32HVBREVB__)
typedef enum
{
    clock_div_1 = 0,
    clock_div_2 = 1,
    clock_div_4 = 2,
    clock_div_8 = 3
} clock_div_t;
static __inline__ void clock_prescale_set(clock_div_t) __attribute__((__always_inline__));
void clock_prescale_set(clock_div_t __x)
{
    uint8_t __tmp = _BV(CLKPCE);
    __asm__ __volatile__ (
        "in __tmp_reg__,__SREG__" "\n\t"
        "cli" "\n\t"
        "sts %1, %0" "\n\t"
        "sts %1, %2" "\n\t"
        "out __SREG__, __tmp_reg__"
        :
        : "d" (__tmp),
          "M" (_SFR_MEM_ADDR(CLKPR)),
          "d" (__x)
        : "r0");
}
#define clock_prescale_get() (clock_div_t)(CLKPR & (uint8_t)((1<<CLKPS0)|(1<<CLKPS1)))
#elif defined(__AVR_ATA5790__) || defined (__AVR_ATA5790N__) || defined (__AVR_ATA5791__) || defined (__AVR_ATA5795__)
typedef enum
{
    clock_div_1 = 0,
    clock_div_2 = 1,
    clock_div_4 = 2,
    clock_div_8 = 3,
    clock_div_16 = 4,
    clock_div_32 = 5,
    clock_div_64 = 6,
    clock_div_128 = 7,
} clock_div_t;
static __inline__ void system_clock_prescale_set(clock_div_t) __attribute__((__always_inline__));
void system_clock_prescale_set(clock_div_t __x)
{
    uint8_t __tmp = _BV(CLKPCE);
    __asm__ __volatile__ (
        "in __tmp_reg__,__SREG__" "\n\t"
        "cli" "\n\t"
        "out %1, %0" "\n\t"
        "out %1, %2" "\n\t"
        "out __SREG__, __tmp_reg__"
        :
        : "d" (__tmp),
          "I" (_SFR_IO_ADDR(CLKPR)),
          "d" (__x)
        : "r0");
}
#define system_clock_prescale_get() (clock_div_t)(CLKPR & (uint8_t)((1<<CLKPS0)|(1<<CLKPS1)|(1<<CLKPS2)))
typedef enum
{
    timer_clock_div_reset = 0,
    timer_clock_div_1 = 1,
    timer_clock_div_2 = 2,
    timer_clock_div_4 = 3,
    timer_clock_div_8 = 4,
    timer_clock_div_16 = 5,
    timer_clock_div_32 = 6,
    timer_clock_div_64 = 7
} timer_clock_div_t;
static __inline__ void timer_clock_prescale_set(timer_clock_div_t) __attribute__((__always_inline__));
void timer_clock_prescale_set(timer_clock_div_t __x)
{
    uint8_t __t;
    __asm__ __volatile__ (
        "in __tmp_reg__,__SREG__" "\n\t"
        "cli" "\n\t"
        "in %[temp],%[clkpr]" "\n\t"
        "out %[clkpr],%[enable]" "\n\t"
        "andi %[temp],%[not_CLTPS]" "\n\t"
        "or %[temp], %[set_value]" "\n\t"
        "out %[clkpr],%[temp]" "\n\t"
        "sei" "\n\t"
        "out __SREG__,__tmp_reg__" "\n\t"
        :
        : [temp] "r" (__t),
          [clkpr] "I" (_SFR_IO_ADDR(CLKPR)),
          [enable] "r" (_BV(CLKPCE)),
          [not_CLTPS] "M" (0xFF & (~ ((1 << CLTPS2) | (1 << CLTPS1) | (1 << CLTPS0)))),
          [set_value] "r" ((__x & 7) << 3)
        : "r0");
}
#define timer_clock_prescale_get() (timer_clock_div_t)(CLKPR & (uint8_t)((1<<CLTPS0)|(1<<CLTPS1)|(1<<CLTPS2)))
#elif defined(__AVR_ATA6285__) || defined(__AVR_ATA6286__)
typedef enum
{
    clock_div_1 = 0,
    clock_div_2 = 1,
    clock_div_4 = 2,
    clock_div_8 = 3,
    clock_div_16 = 4,
    clock_div_32 = 5,
    clock_div_64 = 6,
    clock_div_128 = 7
} clock_div_t;
static __inline__ void system_clock_prescale_set(clock_div_t) __attribute__((__always_inline__));
void system_clock_prescale_set(clock_div_t __x)
{
    uint8_t __t;
    __asm__ __volatile__ (
        "in __tmp_reg__,__SREG__" "\n\t"
        "cli" "\n\t"
        "in %[temp],%[clpr]" "\n\t"
        "out %[clpr],%[enable]" "\n\t"
        "andi %[temp],%[not_CLKPS]" "\n\t"
        "or %[temp], %[set_value]" "\n\t"
        "out %[clpr],%[temp]" "\n\t"
        "sei" "\n\t"
        "out __SREG__,__tmp_reg__" "\n\t"
        :
        : [temp] "r" (__t),
          [clpr] "I" (_SFR_IO_ADDR(CLKPR)),
          [enable] "r" _BV(CLPCE),
          [not_CLKPS] "M" (0xFF & (~ ((1 << CLKPS2) | (1 << CLKPS1) | (1 << CLKPS0)))),
          [set_value] "r" (__x & 7)
        : "r0");
}
#define system_clock_prescale_get() (clock_div_t)(CLKPR & (uint8_t)((1<<CLKPS0)|(1<<CLKPS1)|(1<<CLKPS2)))
typedef enum
{
    timer_clock_div_reset = 0,
    timer_clock_div_1 = 1,
    timer_clock_div_2 = 2,
    timer_clock_div_4 = 3,
    timer_clock_div_8 = 4,
    timer_clock_div_16 = 5,
    timer_clock_div_32 = 6,
    timer_clock_div_64 = 7
} timer_clock_div_t;
static __inline__ void timer_clock_prescale_set(timer_clock_div_t) __attribute__((__always_inline__));
void timer_clock_prescale_set(timer_clock_div_t __x)
{
    uint8_t __t;
    __asm__ __volatile__ (
        "in __tmp_reg__,__SREG__" "\n\t"
        "cli" "\n\t"
        "in %[temp],%[clpr]" "\n\t"
        "out %[clpr],%[enable]" "\n\t"
        "andi %[temp],%[not_CLTPS]" "\n\t"
        "or %[temp], %[set_value]" "\n\t"
        "out %[clpr],%[temp]" "\n\t"
        "sei" "\n\t"
        "out __SREG__,__tmp_reg__" "\n\t"
        :
        : [temp] "r" (__t),
          [clpr] "I" (_SFR_IO_ADDR(CLKPR)),
          [enable] "r" (_BV(CLPCE)),
          [not_CLTPS] "M" (0xFF & (~ ((1 << CLTPS2) | (1 << CLTPS1) | (1 << CLTPS0)))),
          [set_value] "r" ((__x & 7) << 3)
        : "r0");
}
#define timer_clock_prescale_get() (timer_clock_div_t)(CLKPR & (uint8_t)((1<<CLTPS0)|(1<<CLTPS1)|(1<<CLTPS2)))
#elif defined(__AVR_ATtiny24__) || defined(__AVR_ATtiny24A__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny44A__) || defined(__AVR_ATtiny84__) || defined(__AVR_ATtiny84A__) || defined(__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__) || defined(__AVR_ATtiny261A__) || defined(__AVR_ATtiny261__) || defined(__AVR_ATtiny461__) || defined(__AVR_ATtiny461A__) || defined(__AVR_ATtiny861__) || defined(__AVR_ATtiny861A__) || defined(__AVR_ATtiny2313__) || defined(__AVR_ATtiny2313A__) || defined(__AVR_ATtiny4313__) || defined(__AVR_ATtiny13__) || defined(__AVR_ATtiny13A__) || defined(__AVR_ATtiny43U__)
typedef enum
{
    clock_div_1 = 0,
    clock_div_2 = 1,
    clock_div_4 = 2,
    clock_div_8 = 3,
    clock_div_16 = 4,
    clock_div_32 = 5,
    clock_div_64 = 6,
    clock_div_128 = 7,
    clock_div_256 = 8
} clock_div_t;
static __inline__ void clock_prescale_set(clock_div_t) __attribute__((__always_inline__));
void clock_prescale_set(clock_div_t __x)
{
    uint8_t __tmp = _BV(CLKPCE);
    __asm__ __volatile__ (
        "in __tmp_reg__,__SREG__" "\n\t"
        "cli" "\n\t"
        "out %1, %0" "\n\t"
        "out %1, %2" "\n\t"
        "out __SREG__, __tmp_reg__"
        :
        : "d" (__tmp),
          "I" (_SFR_IO_ADDR(CLKPR)),
          "d" (__x)
        : "r0");
}
#define clock_prescale_get() (clock_div_t)(CLKPR & (uint8_t)((1<<CLKPS0)|(1<<CLKPS1)|(1<<CLKPS2)|(1<<CLKPS3)))
#elif defined(__AVR_ATmega64__) || defined(__AVR_ATmega103__) || defined(__AVR_ATmega128__)
typedef enum
{
    clock_div_1 = 1,
    clock_div_2 = 2,
    clock_div_4 = 4,
    clock_div_8 = 8,
    clock_div_16 = 16,
    clock_div_32 = 32,
    clock_div_64 = 64,
    clock_div_128 = 128
} clock_div_t;
static __inline__ void clock_prescale_set(clock_div_t) __attribute__((__always_inline__));
void clock_prescale_set(clock_div_t __x)
{
    if((__x <= 0) || (__x > 129))
    {
        return;
    }
    else
    {
        uint8_t __tmp = 0;
        __asm__ __volatile__ (
            "in __tmp_reg__,__SREG__" "\n\t"
            "cli" "\n\t"
            "out %1, __zero_reg__" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "cpi %0, 0x01" "\n\t"
            "breq L_%=" "\n\t"
            "ldi %2, 0x81" "\n\t"
            "sub %2, %0" "\n\t"
            "ori %2, 0x80" "\n\t"
            "out %1, %2" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
            "L_%=: " "out __SREG__, __tmp_reg__"
            :
            :"d" (__x),
             "I" (_SFR_IO_ADDR(XDIV)),
             "d" (__tmp)
            : "r0");
    }
}
static __inline__ clock_div_t clock_prescale_get(void) __attribute__((__always_inline__));
clock_div_t clock_prescale_get(void)
{
    if(bit_is_clear(XDIV, XDIVEN))
    {
        return 1;
    }
    else
    {
        return (clock_div_t)(129 - (XDIV & 0x7F));
    }
}
#elif defined(__AVR_ATtiny4__) || defined(__AVR_ATtiny5__) || defined(__AVR_ATtiny9__) || defined(__AVR_ATtiny10__) || defined(__AVR_ATtiny20__) || defined(__AVR_ATtiny40__)
typedef enum
{
    clock_div_1 = 0,
    clock_div_2 = 1,
    clock_div_4 = 2,
    clock_div_8 = 3,
    clock_div_16 = 4,
    clock_div_32 = 5,
    clock_div_64 = 6,
    clock_div_128 = 7,
    clock_div_256 = 8
} clock_div_t;
static __inline__ void clock_prescale_set(clock_div_t) __attribute__((__always_inline__));
void clock_prescale_set(clock_div_t __x)
{
    uint8_t __tmp = 0xD8;
    __asm__ __volatile__ (
        "in __tmp_reg__,__SREG__" "\n\t"
        "cli" "\n\t"
        "out %1, %0" "\n\t"
        "out %2, %3" "\n\t"
        "out __SREG__, __tmp_reg__"
        :
        : "d" (__tmp),
          "I" (_SFR_IO_ADDR(CCP)),
          "I" (_SFR_IO_ADDR(CLKPSR)),
          "d" (__x)
        : "r16");
}
#define clock_prescale_get() (clock_div_t)(CLKPSR & (uint8_t)((1<<CLKPS0)|(1<<CLKPS1)|(1<<CLKPS2)|(1<<CLKPS3)))
#endif
#endif
