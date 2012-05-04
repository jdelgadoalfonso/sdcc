//
// Register Declarations for Microchip 16F684 Processor
//
//
// This header file was automatically generated by:
//
//      inc2h.pl V4850
//
//      Copyright (c) 2002, Kevin L. Pauba, All Rights Reserved
//
//      SDCC is licensed under the GNU Public license (GPL) v2.  Note that
//      this license covers the code to the compiler and other executables,
//      but explicitly does not cover any code or objects generated by sdcc.
//
//      For pic device libraries and header files which are derived from
//      Microchip header (.inc) and linker script (.lkr) files Microchip
//      requires that "The header files should state that they are only to be
//      used with authentic Microchip devices" which makes them incompatible
//      with the GPL. Pic device libraries and header files are located at
//      non-free/lib and non-free/include directories respectively.
//      Sdcc should be run with the --use-non-free command line option in
//      order to include non-free header files and libraries.
//
//      See http://sdcc.sourceforge.net/ for the latest information on sdcc.
//
//
#ifndef P16F684_H
#define P16F684_H

//
// Register addresses.
//
#define INDF_ADDR       0x0000
#define TMR0_ADDR       0x0001
#define PCL_ADDR        0x0002
#define STATUS_ADDR     0x0003
#define FSR_ADDR        0x0004
#define PORTA_ADDR      0x0005
#define PORTC_ADDR      0x0007
#define PCLATH_ADDR     0x000A
#define INTCON_ADDR     0x000B
#define PIR1_ADDR       0x000C
#define TMR1L_ADDR      0x000E
#define TMR1H_ADDR      0x000F
#define T1CON_ADDR      0x0010
#define TMR2_ADDR       0x0011
#define T2CON_ADDR      0x0012
#define CCPR1L_ADDR     0x0013
#define CCPR1H_ADDR     0x0014
#define CCP1CON_ADDR    0x0015
#define PWM1CON_ADDR    0x0016
#define ECCPAS_ADDR     0x0017
#define WDTCON_ADDR     0x0018
#define CMCON0_ADDR     0x0019
#define CMCON1_ADDR     0x001A
#define ADRESH_ADDR     0x001E
#define ADCON0_ADDR     0x001F
#define OPTION_REG_ADDR 0x0081
#define TRISA_ADDR      0x0085
#define TRISC_ADDR      0x0087
#define PIE1_ADDR       0x008C
#define PCON_ADDR       0x008E
#define OSCCON_ADDR     0x008F
#define OSCTUNE_ADDR    0x0090
#define ANSEL_ADDR      0x0091
#define PR2_ADDR        0x0092
#define WPU_ADDR        0x0095
#define WPUA_ADDR       0x0095
#define IOC_ADDR        0x0096
#define IOCA_ADDR       0x0096
#define VRCON_ADDR      0x0099
#define EEDAT_ADDR      0x009A
#define EEDATA_ADDR     0x009A
#define EEADR_ADDR      0x009B
#define EECON1_ADDR     0x009C
#define EECON2_ADDR     0x009D
#define ADRESL_ADDR     0x009E
#define ADCON1_ADDR     0x009F

//
// Memory organization.
//



//         LIST
// P16F684.INC  Standard Header File, Version 1.03    Microchip Technology, Inc.
//         NOLIST

// This header file defines configurations, registers, and other useful bits of
// information for the PIC16F684 microcontroller.  These names are taken to match
// the data sheets as closely as possible.

// Note that the processor must be selected before this file is
// included.  The processor may be selected the following ways:

//       1. Command line switch:
//               C:\ MPASM MYFILE.ASM /PIC16F684
//       2. LIST directive in the source file
//               LIST   P=PIC16F684
//       3. Processor Type entry in the MPASM full-screen interface

//==========================================================================
//
//       Revision History
//
//==========================================================================
//1.00   03/20/03 Original
//1.01  08/04/03 Updated CMCON1 address
//1.02  08/05/03 Updated names to match datasheet
//1.03  08/11/03 Updated ULPWUE bit name to match datasheet
//==========================================================================
//
//       Verify Processor
//
//==========================================================================

//        IFNDEF __16F684
//            MESSG "Processor-header file mismatch.  Verify selected processor."
//         ENDIF

//==========================================================================
//
//       Register Definitions
//
//==========================================================================

#define W                    0x0000
#define F                    0x0001

//----- Register Files------------------------------------------------------

extern __sfr  __at (INDF_ADDR)                    INDF;
extern __sfr  __at (TMR0_ADDR)                    TMR0;
extern __sfr  __at (PCL_ADDR)                     PCL;
extern __sfr  __at (STATUS_ADDR)                  STATUS;
extern __sfr  __at (FSR_ADDR)                     FSR;
extern __sfr  __at (PORTA_ADDR)                   PORTA;

extern __sfr  __at (PORTC_ADDR)                   PORTC;

extern __sfr  __at (PCLATH_ADDR)                  PCLATH;
extern __sfr  __at (INTCON_ADDR)                  INTCON;
extern __sfr  __at (PIR1_ADDR)                    PIR1;

extern __sfr  __at (TMR1L_ADDR)                   TMR1L;                
extern __sfr  __at (TMR1H_ADDR)                   TMR1H;                
extern __sfr  __at (T1CON_ADDR)                   T1CON;                
extern __sfr  __at (TMR2_ADDR)                    TMR2;
extern __sfr  __at (T2CON_ADDR)                   T2CON;
extern __sfr  __at (CCPR1L_ADDR)                  CCPR1L;
extern __sfr  __at (CCPR1H_ADDR)                  CCPR1H;
extern __sfr  __at (CCP1CON_ADDR)                 CCP1CON;
extern __sfr  __at (PWM1CON_ADDR)                 PWM1CON;
extern __sfr  __at (ECCPAS_ADDR)                  ECCPAS;
extern __sfr  __at (WDTCON_ADDR)                  WDTCON;
extern __sfr  __at (CMCON0_ADDR)                  CMCON0;               
extern __sfr  __at (CMCON1_ADDR)                  CMCON1;               

extern __sfr  __at (ADRESH_ADDR)                  ADRESH;               
extern __sfr  __at (ADCON0_ADDR)                  ADCON0;               


extern __sfr  __at (OPTION_REG_ADDR)              OPTION_REG;

extern __sfr  __at (TRISA_ADDR)                   TRISA;
extern __sfr  __at (TRISC_ADDR)                   TRISC;

extern __sfr  __at (PIE1_ADDR)                    PIE1;

extern __sfr  __at (PCON_ADDR)                    PCON;
extern __sfr  __at (OSCCON_ADDR)                  OSCCON;
extern __sfr  __at (OSCTUNE_ADDR)                 OSCTUNE;
extern __sfr  __at (ANSEL_ADDR)                   ANSEL;
extern __sfr  __at (PR2_ADDR)                     PR2;

extern __sfr  __at (WPU_ADDR)                     WPU;
extern __sfr  __at (WPUA_ADDR)                    WPUA;
extern __sfr  __at (IOC_ADDR)                     IOC;
extern __sfr  __at (IOCA_ADDR)                    IOCA;

extern __sfr  __at (VRCON_ADDR)                   VRCON;
extern __sfr  __at (EEDAT_ADDR)                   EEDAT;        
extern __sfr  __at (EEDATA_ADDR)                  EEDATA;       
extern __sfr  __at (EEADR_ADDR)                   EEADR;        
extern __sfr  __at (EECON1_ADDR)                  EECON1;
extern __sfr  __at (EECON2_ADDR)                  EECON2;
extern __sfr  __at (ADRESL_ADDR)                  ADRESL;               
extern __sfr  __at (ADCON1_ADDR)                  ADCON1;


//----- STATUS Bits --------------------------------------------------------


//----- INTCON Bits --------------------------------------------------------


//----- PIR1 Bits ----------------------------------------------------------


//----- T1CON Bits ---------------------------------------------------------


//----- T2CON Bits ---------------------------------------------------------


//----- CCP1CON Bits -------------------------------------------------------


//----- PWM1CON Bits -------------------------------------------------------


//----- ECCPAS Bits --------------------------------------------------------


//----- WDTCON Bits --------------------------------------------------------


//----- COMCON0 Bits -------------------------------------------------------


//----- COMCON1 Bits -------------------------------------------------------


//----- ADCON0 Bits --------------------------------------------------------


//----- OPTION Bits --------------------------------------------------------


//----- PIE1 Bits ----------------------------------------------------------


//----- PCON Bits ----------------------------------------------------------


//----- OSCCON Bits --------------------------------------------------------


//----- OSCTUNE Bits -------------------------------------------------------


//----- ANSEL Bits ---------------------------------------------------------


//----- IOC Bits ---------------------------------------------------------


//----- IOCA Bits ---------------------------------------------------------


//----- VRCON Bits ---------------------------------------------------------


//----- EECON1 Bits --------------------------------------------------------


//----- ADCON1 Bits --------------------------------------------------------


//==========================================================================
//
//       RAM Definition
//
//==========================================================================

//         __MAXRAM H'FF'
//         __BADRAM H'06', H'08'-H'09', H'0D', H'1B'-H'1D'
//         __BADRAM H'86', H'88'-H'89', H'8D', H'93'-H'94', H'97'-H'98', H'C0'-H'EF'

//==========================================================================
//
//       Configuration Bits
//
//==========================================================================

#define _FCMEN_ON            0x3FFF
#define _FCMEN_OFF           0x37FF
#define _IESO_ON             0x3FFF
#define _IESO_OFF            0x3BFF
#define _BOD_ON              0x3FFF
#define _BOD_NSLEEP          0x3EFF
#define _BOD_SBODEN          0x3DFF
#define _BOD_OFF             0x3CFF
#define _CPD_ON              0x3F7F
#define _CPD_OFF             0x3FFF
#define _CP_ON               0x3FBF
#define _CP_OFF              0x3FFF
#define _MCLRE_ON            0x3FFF
#define _MCLRE_OFF           0x3FDF
#define _PWRTE_OFF           0x3FFF
#define _PWRTE_ON            0x3FEF
#define _WDT_ON              0x3FFF
#define _WDT_OFF             0x3FF7
#define _LP_OSC              0x3FF8
#define _XT_OSC              0x3FF9
#define _HS_OSC              0x3FFA
#define _EC_OSC              0x3FFB
#define _INTRC_OSC_NOCLKOUT  0x3FFC
#define _INTRC_OSC_CLKOUT    0x3FFD
#define _EXTRC_OSC_NOCLKOUT  0x3FFE
#define _EXTRC_OSC_CLKOUT    0x3FFF
#define _INTOSCIO            0x3FFC
#define _INTOSC              0x3FFD
#define _EXTRCIO             0x3FFE
#define _EXTRC               0x3FFF

//         LIST

// ----- ADCON0 bits --------------------
typedef union {
  struct {
    unsigned char ADON:1;
    unsigned char GO:1;
    unsigned char CHS0:1;
    unsigned char CHS1:1;
    unsigned char CHS2:1;
    unsigned char :1;
    unsigned char VCFG:1;
    unsigned char ADFM:1;
  };
  struct {
    unsigned char :1;
    unsigned char NOT_DONE:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
  struct {
    unsigned char :1;
    unsigned char GO_DONE:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __ADCON0bits_t;
extern volatile __ADCON0bits_t __at(ADCON0_ADDR) ADCON0bits;

// ----- ADCON1 bits --------------------
typedef union {
  struct {
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char ADCS0:1;
    unsigned char ADCS1:1;
    unsigned char ADCS2:1;
    unsigned char :1;
  };
} __ADCON1bits_t;
extern volatile __ADCON1bits_t __at(ADCON1_ADDR) ADCON1bits;

// ----- ANSEL bits --------------------
typedef union {
  struct {
    unsigned char ANS0:1;
    unsigned char ANS1:1;
    unsigned char ANS2:1;
    unsigned char ANS3:1;
    unsigned char ANS4:1;
    unsigned char ANS5:1;
    unsigned char ANS6:1;
    unsigned char ANS7:1;
  };
} __ANSELbits_t;
extern volatile __ANSELbits_t __at(ANSEL_ADDR) ANSELbits;

// ----- CCP1CON bits --------------------
typedef union {
  struct {
    unsigned char CCP1M0:1;
    unsigned char CCP1M1:1;
    unsigned char CCP1M2:1;
    unsigned char CCP1M3:1;
    unsigned char DC1B0:1;
    unsigned char DC1B1:1;
    unsigned char P1M0:1;
    unsigned char P1M1:1;
  };
} __CCP1CONbits_t;
extern volatile __CCP1CONbits_t __at(CCP1CON_ADDR) CCP1CONbits;

// ----- CMCON0 bits --------------------
typedef union {
  struct {
    unsigned char CM0:1;
    unsigned char CM1:1;
    unsigned char CM2:1;
    unsigned char CIS:1;
    unsigned char C1INV:1;
    unsigned char C2INV:1;
    unsigned char C1OUT:1;
    unsigned char C2OUT:1;
  };
} __CMCON0bits_t;
extern volatile __CMCON0bits_t __at(CMCON0_ADDR) CMCON0bits;

// ----- CMCON1 bits --------------------
typedef union {
  struct {
    unsigned char C2SYNC:1;
    unsigned char T1GSS:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __CMCON1bits_t;
extern volatile __CMCON1bits_t __at(CMCON1_ADDR) CMCON1bits;

// ----- ECCPAS bits --------------------
typedef union {
  struct {
    unsigned char PSSBD0:1;
    unsigned char PSSBD1:1;
    unsigned char PSSAC0:1;
    unsigned char PSSAC1:1;
    unsigned char ECCPAS0:1;
    unsigned char ECCPAS1:1;
    unsigned char ECCPAS2:1;
    unsigned char ECCPASE:1;
  };
} __ECCPASbits_t;
extern volatile __ECCPASbits_t __at(ECCPAS_ADDR) ECCPASbits;

// ----- EECON1 bits --------------------
typedef union {
  struct {
    unsigned char RD:1;
    unsigned char WR:1;
    unsigned char WREN:1;
    unsigned char WRERR:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __EECON1bits_t;
extern volatile __EECON1bits_t __at(EECON1_ADDR) EECON1bits;

// ----- INTCON bits --------------------
typedef union {
  struct {
    unsigned char RAIF:1;
    unsigned char INTF:1;
    unsigned char T0IF:1;
    unsigned char RAIE:1;
    unsigned char INTE:1;
    unsigned char T0IE:1;
    unsigned char PEIE:1;
    unsigned char GIE:1;
  };
} __INTCONbits_t;
extern volatile __INTCONbits_t __at(INTCON_ADDR) INTCONbits;

// ----- IOC bits --------------------
typedef union {
  struct {
    unsigned char IOC0:1;
    unsigned char IOC1:1;
    unsigned char IOC2:1;
    unsigned char IOC3:1;
    unsigned char IOC4:1;
    unsigned char IOC5:1;
    unsigned char :1;
    unsigned char :1;
  };
} __IOCbits_t;
extern volatile __IOCbits_t __at(IOC_ADDR) IOCbits;

// ----- IOCA bits --------------------
typedef union {
  struct {
    unsigned char IOCA0:1;
    unsigned char IOCA1:1;
    unsigned char IOCA2:1;
    unsigned char IOCA3:1;
    unsigned char IOCA4:1;
    unsigned char IOCA5:1;
    unsigned char :1;
    unsigned char :1;
  };
} __IOCAbits_t;
extern volatile __IOCAbits_t __at(IOCA_ADDR) IOCAbits;

// ----- OPTION_REG bits --------------------
typedef union {
  struct {
    unsigned char PS0:1;
    unsigned char PS1:1;
    unsigned char PS2:1;
    unsigned char PSA:1;
    unsigned char T0SE:1;
    unsigned char T0CS:1;
    unsigned char INTEDG:1;
    unsigned char NOT_RAPU:1;
  };
} __OPTION_REGbits_t;
extern volatile __OPTION_REGbits_t __at(OPTION_REG_ADDR) OPTION_REGbits;

// ----- OSCCON bits --------------------
typedef union {
  struct {
    unsigned char SCS:1;
    unsigned char LTS:1;
    unsigned char HTS:1;
    unsigned char OSTS:1;
    unsigned char IRCF0:1;
    unsigned char IRCF1:1;
    unsigned char IRCF2:1;
    unsigned char :1;
  };
} __OSCCONbits_t;
extern volatile __OSCCONbits_t __at(OSCCON_ADDR) OSCCONbits;

// ----- OSCTUNE bits --------------------
typedef union {
  struct {
    unsigned char TUN0:1;
    unsigned char TUN1:1;
    unsigned char TUN2:1;
    unsigned char TUN3:1;
    unsigned char TUN4:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __OSCTUNEbits_t;
extern volatile __OSCTUNEbits_t __at(OSCTUNE_ADDR) OSCTUNEbits;

// ----- PCON bits --------------------
typedef union {
  struct {
    unsigned char NOT_BOD:1;
    unsigned char NOT_POR:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char SBODEN:1;
    unsigned char ULPWUE:1;
    unsigned char :1;
    unsigned char :1;
  };
} __PCONbits_t;
extern volatile __PCONbits_t __at(PCON_ADDR) PCONbits;

// ----- PIE1 bits --------------------
typedef union {
  struct {
    unsigned char T1IE:1;
    unsigned char T2IE:1;
    unsigned char OSFIE:1;
    unsigned char C1IE:1;
    unsigned char C2IE:1;
    unsigned char CCP1IE:1;
    unsigned char ADIE:1;
    unsigned char EEIE:1;
  };
  struct {
    unsigned char TMR1IE:1;
    unsigned char TMR2IE:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __PIE1bits_t;
extern volatile __PIE1bits_t __at(PIE1_ADDR) PIE1bits;

// ----- PIR1 bits --------------------
typedef union {
  struct {
    unsigned char T1IF:1;
    unsigned char T2IF:1;
    unsigned char OSFIF:1;
    unsigned char C1IF:1;
    unsigned char C2IF:1;
    unsigned char CCP1IF:1;
    unsigned char ADIF:1;
    unsigned char EEIF:1;
  };
  struct {
    unsigned char TMR1IF:1;
    unsigned char TMR2IF:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __PIR1bits_t;
extern volatile __PIR1bits_t __at(PIR1_ADDR) PIR1bits;

// ----- PORTA bits --------------------
typedef union {
  struct {
    unsigned char RA0:1;
    unsigned char RA1:1;
    unsigned char RA2:1;
    unsigned char RA3:1;
    unsigned char RA4:1;
    unsigned char RA5:1;
    unsigned char :1;
    unsigned char :1;
  };
} __PORTAbits_t;
extern volatile __PORTAbits_t __at(PORTA_ADDR) PORTAbits;

// ----- PORTC bits --------------------
typedef union {
  struct {
    unsigned char RC0:1;
    unsigned char RC1:1;
    unsigned char RC2:1;
    unsigned char RC3:1;
    unsigned char RC4:1;
    unsigned char RC5:1;
    unsigned char RC6:1;
    unsigned char RC7:1;
  };
} __PORTCbits_t;
extern volatile __PORTCbits_t __at(PORTC_ADDR) PORTCbits;

// ----- PWM1CON bits --------------------
typedef union {
  struct {
    unsigned char PDC0:1;
    unsigned char PDC1:1;
    unsigned char PDC2:1;
    unsigned char PDC3:1;
    unsigned char PDC4:1;
    unsigned char PDC5:1;
    unsigned char PDC6:1;
    unsigned char PRSEN:1;
  };
} __PWM1CONbits_t;
extern volatile __PWM1CONbits_t __at(PWM1CON_ADDR) PWM1CONbits;

// ----- STATUS bits --------------------
typedef union {
  struct {
    unsigned char C:1;
    unsigned char DC:1;
    unsigned char Z:1;
    unsigned char NOT_PD:1;
    unsigned char NOT_TO:1;
    unsigned char RP0:1;
    unsigned char RP1:1;
    unsigned char IRP:1;
  };
} __STATUSbits_t;
extern volatile __STATUSbits_t __at(STATUS_ADDR) STATUSbits;

// ----- T1CON bits --------------------
typedef union {
  struct {
    unsigned char TMR1ON:1;
    unsigned char TMR1CS:1;
    unsigned char NOT_T1SYNC:1;
    unsigned char T1OSCEN:1;
    unsigned char T1CKPS0:1;
    unsigned char T1CKPS1:1;
    unsigned char TMR1GE:1;
    unsigned char T1GINV:1;
  };
} __T1CONbits_t;
extern volatile __T1CONbits_t __at(T1CON_ADDR) T1CONbits;

// ----- T2CON bits --------------------
typedef union {
  struct {
    unsigned char T2CKPS0:1;
    unsigned char T2CKPS1:1;
    unsigned char TMR2ON:1;
    unsigned char TOUTPS0:1;
    unsigned char TOUTPS1:1;
    unsigned char TOUTPS2:1;
    unsigned char TOUTPS3:1;
    unsigned char :1;
  };
} __T2CONbits_t;
extern volatile __T2CONbits_t __at(T2CON_ADDR) T2CONbits;

// ----- TRISA bits --------------------
typedef union {
  struct {
    unsigned char TRISA0:1;
    unsigned char TRISA1:1;
    unsigned char TRISA2:1;
    unsigned char TRISA3:1;
    unsigned char TRISA4:1;
    unsigned char TRISA5:1;
    unsigned char :1;
    unsigned char :1;
  };
} __TRISAbits_t;
extern volatile __TRISAbits_t __at(TRISA_ADDR) TRISAbits;

// ----- TRISC bits --------------------
typedef union {
  struct {
    unsigned char TRISC0:1;
    unsigned char TRISC1:1;
    unsigned char TRISC2:1;
    unsigned char TRISC3:1;
    unsigned char TRISC4:1;
    unsigned char TRISC5:1;
    unsigned char TRISC6:1;
    unsigned char TRISC7:1;
  };
} __TRISCbits_t;
extern volatile __TRISCbits_t __at(TRISC_ADDR) TRISCbits;

// ----- VRCON bits --------------------
typedef union {
  struct {
    unsigned char VR0:1;
    unsigned char VR1:1;
    unsigned char VR2:1;
    unsigned char VR3:1;
    unsigned char :1;
    unsigned char VRR:1;
    unsigned char :1;
    unsigned char VREN:1;
  };
} __VRCONbits_t;
extern volatile __VRCONbits_t __at(VRCON_ADDR) VRCONbits;

// ----- WDTCON bits --------------------
typedef union {
  struct {
    unsigned char SWDTEN:1;
    unsigned char WDTPS0:1;
    unsigned char WDTPS1:1;
    unsigned char WDTPS2:1;
    unsigned char WDTPS3:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __WDTCONbits_t;
extern volatile __WDTCONbits_t __at(WDTCON_ADDR) WDTCONbits;


#ifndef NO_BIT_DEFINES

#define ADON                 ADCON0bits.ADON                /* bit 0 */
#define GO                   ADCON0bits.GO                  /* bit 1 */
#define GO_DONE              ADCON0bits.GO_DONE             /* bit 1 */
#define NOT_DONE             ADCON0bits.NOT_DONE            /* bit 1 */
#define CHS0                 ADCON0bits.CHS0                /* bit 2 */
#define CHS1                 ADCON0bits.CHS1                /* bit 3 */
#define CHS2                 ADCON0bits.CHS2                /* bit 4 */
#define VCFG                 ADCON0bits.VCFG                /* bit 6 */
#define ADFM                 ADCON0bits.ADFM                /* bit 7 */

#define ADCS0                ADCON1bits.ADCS0               /* bit 4 */
#define ADCS1                ADCON1bits.ADCS1               /* bit 5 */
#define ADCS2                ADCON1bits.ADCS2               /* bit 6 */

#define ANS0                 ANSELbits.ANS0                 /* bit 0 */
#define ANS1                 ANSELbits.ANS1                 /* bit 1 */
#define ANS2                 ANSELbits.ANS2                 /* bit 2 */
#define ANS3                 ANSELbits.ANS3                 /* bit 3 */
#define ANS4                 ANSELbits.ANS4                 /* bit 4 */
#define ANS5                 ANSELbits.ANS5                 /* bit 5 */
#define ANS6                 ANSELbits.ANS6                 /* bit 6 */
#define ANS7                 ANSELbits.ANS7                 /* bit 7 */

#define CCP1M0               CCP1CONbits.CCP1M0             /* bit 0 */
#define CCP1M1               CCP1CONbits.CCP1M1             /* bit 1 */
#define CCP1M2               CCP1CONbits.CCP1M2             /* bit 2 */
#define CCP1M3               CCP1CONbits.CCP1M3             /* bit 3 */
#define DC1B0                CCP1CONbits.DC1B0              /* bit 4 */
#define DC1B1                CCP1CONbits.DC1B1              /* bit 5 */
#define P1M0                 CCP1CONbits.P1M0               /* bit 6 */
#define P1M1                 CCP1CONbits.P1M1               /* bit 7 */

#define CM0                  CMCON0bits.CM0                 /* bit 0 */
#define CM1                  CMCON0bits.CM1                 /* bit 1 */
#define CM2                  CMCON0bits.CM2                 /* bit 2 */
#define CIS                  CMCON0bits.CIS                 /* bit 3 */
#define C1INV                CMCON0bits.C1INV               /* bit 4 */
#define C2INV                CMCON0bits.C2INV               /* bit 5 */
#define C1OUT                CMCON0bits.C1OUT               /* bit 6 */
#define C2OUT                CMCON0bits.C2OUT               /* bit 7 */

#define C2SYNC               CMCON1bits.C2SYNC              /* bit 0 */
#define T1GSS                CMCON1bits.T1GSS               /* bit 1 */

#define PSSBD0               ECCPASbits.PSSBD0              /* bit 0 */
#define PSSBD1               ECCPASbits.PSSBD1              /* bit 1 */
#define PSSAC0               ECCPASbits.PSSAC0              /* bit 2 */
#define PSSAC1               ECCPASbits.PSSAC1              /* bit 3 */
#define ECCPAS0              ECCPASbits.ECCPAS0             /* bit 4 */
#define ECCPAS1              ECCPASbits.ECCPAS1             /* bit 5 */
#define ECCPAS2              ECCPASbits.ECCPAS2             /* bit 6 */
#define ECCPASE              ECCPASbits.ECCPASE             /* bit 7 */

#define RD                   EECON1bits.RD                  /* bit 0 */
#define WR                   EECON1bits.WR                  /* bit 1 */
#define WREN                 EECON1bits.WREN                /* bit 2 */
#define WRERR                EECON1bits.WRERR               /* bit 3 */

#define RAIF                 INTCONbits.RAIF                /* bit 0 */
#define INTF                 INTCONbits.INTF                /* bit 1 */
#define T0IF                 INTCONbits.T0IF                /* bit 2 */
#define RAIE                 INTCONbits.RAIE                /* bit 3 */
#define INTE                 INTCONbits.INTE                /* bit 4 */
#define T0IE                 INTCONbits.T0IE                /* bit 5 */
#define PEIE                 INTCONbits.PEIE                /* bit 6 */
#define GIE                  INTCONbits.GIE                 /* bit 7 */

#define IOCA0                IOCAbits.IOCA0                 /* bit 0 */
#define IOCA1                IOCAbits.IOCA1                 /* bit 1 */
#define IOCA2                IOCAbits.IOCA2                 /* bit 2 */
#define IOCA3                IOCAbits.IOCA3                 /* bit 3 */
#define IOCA4                IOCAbits.IOCA4                 /* bit 4 */
#define IOCA5                IOCAbits.IOCA5                 /* bit 5 */

#define IOC0                 IOCbits.IOC0                   /* bit 0 */
#define IOC1                 IOCbits.IOC1                   /* bit 1 */
#define IOC2                 IOCbits.IOC2                   /* bit 2 */
#define IOC3                 IOCbits.IOC3                   /* bit 3 */
#define IOC4                 IOCbits.IOC4                   /* bit 4 */
#define IOC5                 IOCbits.IOC5                   /* bit 5 */

#define PS0                  OPTION_REGbits.PS0             /* bit 0 */
#define PS1                  OPTION_REGbits.PS1             /* bit 1 */
#define PS2                  OPTION_REGbits.PS2             /* bit 2 */
#define PSA                  OPTION_REGbits.PSA             /* bit 3 */
#define T0SE                 OPTION_REGbits.T0SE            /* bit 4 */
#define T0CS                 OPTION_REGbits.T0CS            /* bit 5 */
#define INTEDG               OPTION_REGbits.INTEDG          /* bit 6 */
#define NOT_RAPU             OPTION_REGbits.NOT_RAPU        /* bit 7 */

#define SCS                  OSCCONbits.SCS                 /* bit 0 */
#define LTS                  OSCCONbits.LTS                 /* bit 1 */
#define HTS                  OSCCONbits.HTS                 /* bit 2 */
#define OSTS                 OSCCONbits.OSTS                /* bit 3 */
#define IRCF0                OSCCONbits.IRCF0               /* bit 4 */
#define IRCF1                OSCCONbits.IRCF1               /* bit 5 */
#define IRCF2                OSCCONbits.IRCF2               /* bit 6 */

#define TUN0                 OSCTUNEbits.TUN0               /* bit 0 */
#define TUN1                 OSCTUNEbits.TUN1               /* bit 1 */
#define TUN2                 OSCTUNEbits.TUN2               /* bit 2 */
#define TUN3                 OSCTUNEbits.TUN3               /* bit 3 */
#define TUN4                 OSCTUNEbits.TUN4               /* bit 4 */

#define NOT_BOD              PCONbits.NOT_BOD               /* bit 0 */
#define NOT_POR              PCONbits.NOT_POR               /* bit 1 */
#define SBODEN               PCONbits.SBODEN                /* bit 4 */
#define ULPWUE               PCONbits.ULPWUE                /* bit 5 */

#define T1IE                 PIE1bits.T1IE                  /* bit 0 */
#define TMR1IE               PIE1bits.TMR1IE                /* bit 0 */
#define T2IE                 PIE1bits.T2IE                  /* bit 1 */
#define TMR2IE               PIE1bits.TMR2IE                /* bit 1 */
#define OSFIE                PIE1bits.OSFIE                 /* bit 2 */
#define C1IE                 PIE1bits.C1IE                  /* bit 3 */
#define C2IE                 PIE1bits.C2IE                  /* bit 4 */
#define CCP1IE               PIE1bits.CCP1IE                /* bit 5 */
#define ADIE                 PIE1bits.ADIE                  /* bit 6 */
#define EEIE                 PIE1bits.EEIE                  /* bit 7 */

#define T1IF                 PIR1bits.T1IF                  /* bit 0 */
#define TMR1IF               PIR1bits.TMR1IF                /* bit 0 */
#define T2IF                 PIR1bits.T2IF                  /* bit 1 */
#define TMR2IF               PIR1bits.TMR2IF                /* bit 1 */
#define OSFIF                PIR1bits.OSFIF                 /* bit 2 */
#define C1IF                 PIR1bits.C1IF                  /* bit 3 */
#define C2IF                 PIR1bits.C2IF                  /* bit 4 */
#define CCP1IF               PIR1bits.CCP1IF                /* bit 5 */
#define ADIF                 PIR1bits.ADIF                  /* bit 6 */
#define EEIF                 PIR1bits.EEIF                  /* bit 7 */

#define RA0                  PORTAbits.RA0                  /* bit 0 */
#define RA1                  PORTAbits.RA1                  /* bit 1 */
#define RA2                  PORTAbits.RA2                  /* bit 2 */
#define RA3                  PORTAbits.RA3                  /* bit 3 */
#define RA4                  PORTAbits.RA4                  /* bit 4 */
#define RA5                  PORTAbits.RA5                  /* bit 5 */

#define RC0                  PORTCbits.RC0                  /* bit 0 */
#define RC1                  PORTCbits.RC1                  /* bit 1 */
#define RC2                  PORTCbits.RC2                  /* bit 2 */
#define RC3                  PORTCbits.RC3                  /* bit 3 */
#define RC4                  PORTCbits.RC4                  /* bit 4 */
#define RC5                  PORTCbits.RC5                  /* bit 5 */
#define RC6                  PORTCbits.RC6                  /* bit 6 */
#define RC7                  PORTCbits.RC7                  /* bit 7 */

#define PDC0                 PWM1CONbits.PDC0               /* bit 0 */
#define PDC1                 PWM1CONbits.PDC1               /* bit 1 */
#define PDC2                 PWM1CONbits.PDC2               /* bit 2 */
#define PDC3                 PWM1CONbits.PDC3               /* bit 3 */
#define PDC4                 PWM1CONbits.PDC4               /* bit 4 */
#define PDC5                 PWM1CONbits.PDC5               /* bit 5 */
#define PDC6                 PWM1CONbits.PDC6               /* bit 6 */
#define PRSEN                PWM1CONbits.PRSEN              /* bit 7 */

#define C                    STATUSbits.C                   /* bit 0 */
#define DC                   STATUSbits.DC                  /* bit 1 */
#define Z                    STATUSbits.Z                   /* bit 2 */
#define NOT_PD               STATUSbits.NOT_PD              /* bit 3 */
#define NOT_TO               STATUSbits.NOT_TO              /* bit 4 */
#define RP0                  STATUSbits.RP0                 /* bit 5 */
#define RP1                  STATUSbits.RP1                 /* bit 6 */
#define IRP                  STATUSbits.IRP                 /* bit 7 */

#define TMR1ON               T1CONbits.TMR1ON               /* bit 0 */
#define TMR1CS               T1CONbits.TMR1CS               /* bit 1 */
#define NOT_T1SYNC           T1CONbits.NOT_T1SYNC           /* bit 2 */
#define T1OSCEN              T1CONbits.T1OSCEN              /* bit 3 */
#define T1CKPS0              T1CONbits.T1CKPS0              /* bit 4 */
#define T1CKPS1              T1CONbits.T1CKPS1              /* bit 5 */
#define TMR1GE               T1CONbits.TMR1GE               /* bit 6 */
#define T1GINV               T1CONbits.T1GINV               /* bit 7 */

#define T2CKPS0              T2CONbits.T2CKPS0              /* bit 0 */
#define T2CKPS1              T2CONbits.T2CKPS1              /* bit 1 */
#define TMR2ON               T2CONbits.TMR2ON               /* bit 2 */
#define TOUTPS0              T2CONbits.TOUTPS0              /* bit 3 */
#define TOUTPS1              T2CONbits.TOUTPS1              /* bit 4 */
#define TOUTPS2              T2CONbits.TOUTPS2              /* bit 5 */
#define TOUTPS3              T2CONbits.TOUTPS3              /* bit 6 */

#define TRISA0               TRISAbits.TRISA0               /* bit 0 */
#define TRISA1               TRISAbits.TRISA1               /* bit 1 */
#define TRISA2               TRISAbits.TRISA2               /* bit 2 */
#define TRISA3               TRISAbits.TRISA3               /* bit 3 */
#define TRISA4               TRISAbits.TRISA4               /* bit 4 */
#define TRISA5               TRISAbits.TRISA5               /* bit 5 */

#define TRISC0               TRISCbits.TRISC0               /* bit 0 */
#define TRISC1               TRISCbits.TRISC1               /* bit 1 */
#define TRISC2               TRISCbits.TRISC2               /* bit 2 */
#define TRISC3               TRISCbits.TRISC3               /* bit 3 */
#define TRISC4               TRISCbits.TRISC4               /* bit 4 */
#define TRISC5               TRISCbits.TRISC5               /* bit 5 */
#define TRISC6               TRISCbits.TRISC6               /* bit 6 */
#define TRISC7               TRISCbits.TRISC7               /* bit 7 */

#define VR0                  VRCONbits.VR0                  /* bit 0 */
#define VR1                  VRCONbits.VR1                  /* bit 1 */
#define VR2                  VRCONbits.VR2                  /* bit 2 */
#define VR3                  VRCONbits.VR3                  /* bit 3 */
#define VRR                  VRCONbits.VRR                  /* bit 5 */
#define VREN                 VRCONbits.VREN                 /* bit 7 */

#define SWDTEN               WDTCONbits.SWDTEN              /* bit 0 */
#define WDTPS0               WDTCONbits.WDTPS0              /* bit 1 */
#define WDTPS1               WDTCONbits.WDTPS1              /* bit 2 */
#define WDTPS2               WDTCONbits.WDTPS2              /* bit 3 */
#define WDTPS3               WDTCONbits.WDTPS3              /* bit 4 */
#endif /* NO_BIT_DEFINES */

#ifndef NO_LEGACY_NAMES
#define ADCON0_bits          ADCON0bits
#define ADCON1_bits          ADCON1bits
#define ANSEL_bits           ANSELbits
#define CCP1CON_bits         CCP1CONbits
#define CMCON0_bits          CMCON0bits
#define CMCON1_bits          CMCON1bits
#define ECCPAS_bits          ECCPASbits
#define EECON1_bits          EECON1bits
#define INTCON_bits          INTCONbits
#define IOC_bits             IOCbits
#define IOCA_bits            IOCAbits
#define OPTION_REG_bits      OPTION_REGbits
#define OSCCON_bits          OSCCONbits
#define OSCTUNE_bits         OSCTUNEbits
#define PCON_bits            PCONbits
#define PIE1_bits            PIE1bits
#define PIR1_bits            PIR1bits
#define PORTA_bits           PORTAbits
#define PORTC_bits           PORTCbits
#define PWM1CON_bits         PWM1CONbits
#define STATUS_bits          STATUSbits
#define T1CON_bits           T1CONbits
#define T2CON_bits           T2CONbits
#define TRISA_bits           TRISAbits
#define TRISC_bits           TRISCbits
#define VRCON_bits           VRCONbits
#define WDTCON_bits          WDTCONbits
#endif /* NO_LEGACY_NAMES */

#endif
