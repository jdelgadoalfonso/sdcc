/* Register definitions for pic12f675.
 * This file was automatically generated by:
 *   inc2h.pl V4514
 *   Copyright (c) 2002, Kevin L. Pauba, All Rights Reserved
 */
#include <pic12f675.h>

__data __at (INDF_ADDR) volatile char      INDF;
__sfr  __at (TMR0_ADDR)                    TMR0;
__data __at (PCL_ADDR) volatile char       PCL;
__sfr  __at (STATUS_ADDR)                  STATUS;
__sfr  __at (FSR_ADDR)                     FSR;
__sfr  __at (GPIO_ADDR)                    GPIO;
__sfr  __at (PCLATH_ADDR)                  PCLATH;
__sfr  __at (INTCON_ADDR)                  INTCON;
__sfr  __at (PIR1_ADDR)                    PIR1;
__sfr  __at (TMR1L_ADDR)                   TMR1L;
__sfr  __at (TMR1H_ADDR)                   TMR1H;
__sfr  __at (T1CON_ADDR)                   T1CON;
__sfr  __at (CMCON_ADDR)                   CMCON;
__sfr  __at (ADRESH_ADDR)                  ADRESH;
__sfr  __at (ADCON0_ADDR)                  ADCON0;
__sfr  __at (OPTION_REG_ADDR)              OPTION_REG;
__sfr  __at (TRISIO_ADDR)                  TRISIO;
__sfr  __at (PIE1_ADDR)                    PIE1;
__sfr  __at (PCON_ADDR)                    PCON;
__sfr  __at (OSCCAL_ADDR)                  OSCCAL;
__sfr  __at (WPU_ADDR)                     WPU;
__sfr  __at (IOC_ADDR)                     IOC;
__sfr  __at (IOCB_ADDR)                    IOCB;
__sfr  __at (VRCON_ADDR)                   VRCON;
__sfr  __at (EEDATA_ADDR)                  EEDATA;
__sfr  __at (EEDAT_ADDR)                   EEDAT;
__sfr  __at (EEADR_ADDR)                   EEADR;
__sfr  __at (EECON1_ADDR)                  EECON1;
__sfr  __at (EECON2_ADDR)                  EECON2;
__sfr  __at (ADRESL_ADDR)                  ADRESL;
__sfr  __at (ANSEL_ADDR)                   ANSEL;

// 
// bitfield definitions
// 
volatile __ADCON0_bits_t __at(ADCON0_ADDR) ADCON0_bits;
volatile __ANSEL_bits_t __at(ANSEL_ADDR) ANSEL_bits;
volatile __CMCON_bits_t __at(CMCON_ADDR) CMCON_bits;
volatile __EECON1_bits_t __at(EECON1_ADDR) EECON1_bits;
volatile __GPIO_bits_t __at(GPIO_ADDR) GPIO_bits;
volatile __INTCON_bits_t __at(INTCON_ADDR) INTCON_bits;
volatile __IOC_bits_t __at(IOC_ADDR) IOC_bits;
volatile __IOCB_bits_t __at(IOCB_ADDR) IOCB_bits;
volatile __OPTION_REG_bits_t __at(OPTION_REG_ADDR) OPTION_REG_bits;
volatile __OSCCAL_bits_t __at(OSCCAL_ADDR) OSCCAL_bits;
volatile __PCON_bits_t __at(PCON_ADDR) PCON_bits;
volatile __PIE1_bits_t __at(PIE1_ADDR) PIE1_bits;
volatile __PIR1_bits_t __at(PIR1_ADDR) PIR1_bits;
volatile __STATUS_bits_t __at(STATUS_ADDR) STATUS_bits;
volatile __T1CON_bits_t __at(T1CON_ADDR) T1CON_bits;
volatile __VRCON_bits_t __at(VRCON_ADDR) VRCON_bits;

