/* Register definitions for pic16f684.
 * This file was automatically generated by:
 *   inc2h.pl V4850
 *   Copyright (c) 2002, Kevin L. Pauba, All Rights Reserved
 */
#include <pic16f684.h>

__sfr  __at (INDF_ADDR)                    INDF;
__sfr  __at (TMR0_ADDR)                    TMR0;
__sfr  __at (PCL_ADDR)                     PCL;
__sfr  __at (STATUS_ADDR)                  STATUS;
__sfr  __at (FSR_ADDR)                     FSR;
__sfr  __at (PORTA_ADDR)                   PORTA;
__sfr  __at (PORTC_ADDR)                   PORTC;
__sfr  __at (PCLATH_ADDR)                  PCLATH;
__sfr  __at (INTCON_ADDR)                  INTCON;
__sfr  __at (PIR1_ADDR)                    PIR1;
__sfr  __at (TMR1L_ADDR)                   TMR1L;
__sfr  __at (TMR1H_ADDR)                   TMR1H;
__sfr  __at (T1CON_ADDR)                   T1CON;
__sfr  __at (TMR2_ADDR)                    TMR2;
__sfr  __at (T2CON_ADDR)                   T2CON;
__sfr  __at (CCPR1L_ADDR)                  CCPR1L;
__sfr  __at (CCPR1H_ADDR)                  CCPR1H;
__sfr  __at (CCP1CON_ADDR)                 CCP1CON;
__sfr  __at (PWM1CON_ADDR)                 PWM1CON;
__sfr  __at (ECCPAS_ADDR)                  ECCPAS;
__sfr  __at (WDTCON_ADDR)                  WDTCON;
__sfr  __at (CMCON0_ADDR)                  CMCON0;
__sfr  __at (CMCON1_ADDR)                  CMCON1;
__sfr  __at (ADRESH_ADDR)                  ADRESH;
__sfr  __at (ADCON0_ADDR)                  ADCON0;
__sfr  __at (OPTION_REG_ADDR)              OPTION_REG;
__sfr  __at (TRISA_ADDR)                   TRISA;
__sfr  __at (TRISC_ADDR)                   TRISC;
__sfr  __at (PIE1_ADDR)                    PIE1;
__sfr  __at (PCON_ADDR)                    PCON;
__sfr  __at (OSCCON_ADDR)                  OSCCON;
__sfr  __at (OSCTUNE_ADDR)                 OSCTUNE;
__sfr  __at (ANSEL_ADDR)                   ANSEL;
__sfr  __at (PR2_ADDR)                     PR2;
__sfr  __at (WPU_ADDR)                     WPU;
__sfr  __at (WPUA_ADDR)                    WPUA;
__sfr  __at (IOC_ADDR)                     IOC;
__sfr  __at (IOCA_ADDR)                    IOCA;
__sfr  __at (VRCON_ADDR)                   VRCON;
__sfr  __at (EEDAT_ADDR)                   EEDAT;
__sfr  __at (EEDATA_ADDR)                  EEDATA;
__sfr  __at (EEADR_ADDR)                   EEADR;
__sfr  __at (EECON1_ADDR)                  EECON1;
__sfr  __at (EECON2_ADDR)                  EECON2;
__sfr  __at (ADRESL_ADDR)                  ADRESL;
__sfr  __at (ADCON1_ADDR)                  ADCON1;

// 
// bitfield definitions
// 
volatile __ADCON0bits_t __at(ADCON0_ADDR) ADCON0bits;
volatile __ADCON1bits_t __at(ADCON1_ADDR) ADCON1bits;
volatile __ANSELbits_t __at(ANSEL_ADDR) ANSELbits;
volatile __CCP1CONbits_t __at(CCP1CON_ADDR) CCP1CONbits;
volatile __CMCON0bits_t __at(CMCON0_ADDR) CMCON0bits;
volatile __CMCON1bits_t __at(CMCON1_ADDR) CMCON1bits;
volatile __ECCPASbits_t __at(ECCPAS_ADDR) ECCPASbits;
volatile __EECON1bits_t __at(EECON1_ADDR) EECON1bits;
volatile __INTCONbits_t __at(INTCON_ADDR) INTCONbits;
volatile __IOCbits_t __at(IOC_ADDR) IOCbits;
volatile __IOCAbits_t __at(IOCA_ADDR) IOCAbits;
volatile __OPTION_REGbits_t __at(OPTION_REG_ADDR) OPTION_REGbits;
volatile __OSCCONbits_t __at(OSCCON_ADDR) OSCCONbits;
volatile __OSCTUNEbits_t __at(OSCTUNE_ADDR) OSCTUNEbits;
volatile __PCONbits_t __at(PCON_ADDR) PCONbits;
volatile __PIE1bits_t __at(PIE1_ADDR) PIE1bits;
volatile __PIR1bits_t __at(PIR1_ADDR) PIR1bits;
volatile __PORTAbits_t __at(PORTA_ADDR) PORTAbits;
volatile __PORTCbits_t __at(PORTC_ADDR) PORTCbits;
volatile __PWM1CONbits_t __at(PWM1CON_ADDR) PWM1CONbits;
volatile __STATUSbits_t __at(STATUS_ADDR) STATUSbits;
volatile __T1CONbits_t __at(T1CON_ADDR) T1CONbits;
volatile __T2CONbits_t __at(T2CON_ADDR) T2CONbits;
volatile __TRISAbits_t __at(TRISA_ADDR) TRISAbits;
volatile __TRISCbits_t __at(TRISC_ADDR) TRISCbits;
volatile __VRCONbits_t __at(VRCON_ADDR) VRCONbits;
volatile __WDTCONbits_t __at(WDTCON_ADDR) WDTCONbits;
