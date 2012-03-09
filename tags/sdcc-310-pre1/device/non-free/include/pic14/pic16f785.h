//
// Register Declarations for Microchip 16F785 Processor
//
//
// This header file was automatically generated by:
//
//	inc2h.pl V4850
//
//	Copyright (c) 2002, Kevin L. Pauba, All Rights Reserved
//
//	SDCC is licensed under the GNU Public license (GPL) v2.  Note that
//	this license covers the code to the compiler and other executables,
//	but explicitly does not cover any code or objects generated by sdcc.
//	We have not yet decided on a license for the run time libraries, but
//	it will not put any requirements on code linked against it. See:
// 
//	http://www.gnu.org/copyleft/gpl/html
//
//	See http://sdcc.sourceforge.net/ for the latest information on sdcc.
//
// 
#ifndef P16F785_H
#define P16F785_H

//
// Register addresses.
//
#define INDF_ADDR	0x0000
#define TMR0_ADDR	0x0001
#define PCL_ADDR	0x0002
#define STATUS_ADDR	0x0003
#define FSR_ADDR	0x0004
#define PORTA_ADDR	0x0005
#define PORTB_ADDR	0x0006
#define PORTC_ADDR	0x0007
#define PCLATH_ADDR	0x000A
#define INTCON_ADDR	0x000B
#define PIR1_ADDR	0x000C
#define TMR1L_ADDR	0x000E
#define TMR1H_ADDR	0x000F
#define T1CON_ADDR	0x0010
#define TMR2_ADDR	0x0011
#define T2CON_ADDR	0x0012
#define CCPR1L_ADDR	0x0013
#define CCPR1H_ADDR	0x0014
#define CCP1CON_ADDR	0x0015
#define WDTCON_ADDR	0x0018
#define ADRESH_ADDR	0x001E
#define ADCON0_ADDR	0x001F
#define OPTION_REG_ADDR	0x0081
#define TRISA_ADDR	0x0085
#define TRISB_ADDR	0x0086
#define TRISC_ADDR	0x0087
#define PIE1_ADDR	0x008C
#define PCON_ADDR	0x008E
#define OSCCON_ADDR	0x008F
#define OSCTUNE_ADDR	0x0090
#define ANSEL_ADDR	0x0091
#define ANSEL0_ADDR	0x0091
#define PR2_ADDR	0x0092
#define ANSEL1_ADDR	0x0093
#define WPU_ADDR	0x0095
#define WPUA_ADDR	0x0095
#define IOC_ADDR	0x0096
#define IOCA_ADDR	0x0096
#define REFCON_ADDR	0x0098
#define VRCON_ADDR	0x0099
#define EEDAT_ADDR	0x009A
#define EEDATA_ADDR	0x009A
#define EEADR_ADDR	0x009B
#define EECON1_ADDR	0x009C
#define EECON2_ADDR	0x009D
#define ADRESL_ADDR	0x009E
#define ADCON1_ADDR	0x009F
#define PWMCON1_ADDR	0x0110
#define PWMCON0_ADDR	0x0111
#define PWMCLK_ADDR	0x0112
#define PWMPH1_ADDR	0x0113
#define PWMPH2_ADDR	0x0114
#define CM1CON0_ADDR	0x0119
#define CM2CON0_ADDR	0x011A
#define CM2CON1_ADDR	0x011B
#define OPA1CON_ADDR	0x011C
#define OPA2CON_ADDR	0x011D

//
// Memory organization.
//



//         LIST
// P16F785.INC  Standard Header File, Version 1.10    Microchip Technology, Inc.
//         NOLIST

// This header file defines configurations, registers, and other useful bits of
// information for the PIC16F785 microcontroller.  These names are taken to match 
// the data sheets as closely as possible.  

// Note that the processor must be selected before this file is 
// included.  The processor may be selected the following ways:

//       1. Command line switch:
//               C:\ MPASM MYFILE.ASM /PIC16F785
//       2. LIST directive in the source file
//               LIST   P=PIC16F785
//       3. Processor Type entry in the MPASM full-screen interface

//==========================================================================
//
//       Revision History
//
//==========================================================================
//1.00   03/26/04 Original
//1.10	07/12/04 Updated for changes to REFCON and VRCON
//1.20   08/26/04 Updated for changes from BOD to BOR
//1.30   09/23/04 Corrected addresses for OPA1CON and OPA2CON
//1.40   10/25/04 Added WPUA3 bit to WPUA register
//                Deleted OVRLP bit from PWMCON1 register
//==========================================================================
//
//       Verify Processor
//
//==========================================================================

//        IFNDEF __16F785
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
extern __sfr  __at (PORTB_ADDR)                   PORTB;
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

extern __sfr  __at (WDTCON_ADDR)                  WDTCON;

extern __sfr  __at (ADRESH_ADDR)                  ADRESH;		
extern __sfr  __at (ADCON0_ADDR)                  ADCON0;		


extern __sfr  __at (OPTION_REG_ADDR)              OPTION_REG;

extern __sfr  __at (TRISA_ADDR)                   TRISA;
extern __sfr  __at (TRISB_ADDR)                   TRISB;
extern __sfr  __at (TRISC_ADDR)                   TRISC;

extern __sfr  __at (PIE1_ADDR)                    PIE1;

extern __sfr  __at (PCON_ADDR)                    PCON;
extern __sfr  __at (OSCCON_ADDR)                  OSCCON;
extern __sfr  __at (OSCTUNE_ADDR)                 OSCTUNE;
extern __sfr  __at (ANSEL_ADDR)                   ANSEL;
extern __sfr  __at (ANSEL0_ADDR)                  ANSEL0;
extern __sfr  __at (PR2_ADDR)                     PR2;
extern __sfr  __at (ANSEL1_ADDR)                  ANSEL1;

extern __sfr  __at (WPU_ADDR)                     WPU;
extern __sfr  __at (WPUA_ADDR)                    WPUA;
extern __sfr  __at (IOC_ADDR)                     IOC;
extern __sfr  __at (IOCA_ADDR)                    IOCA;

extern __sfr  __at (REFCON_ADDR)                  REFCON;
extern __sfr  __at (VRCON_ADDR)                   VRCON;
extern __sfr  __at (EEDAT_ADDR)                   EEDAT;	
extern __sfr  __at (EEDATA_ADDR)                  EEDATA;	
extern __sfr  __at (EEADR_ADDR)                   EEADR;	
extern __sfr  __at (EECON1_ADDR)                  EECON1;
extern __sfr  __at (EECON2_ADDR)                  EECON2;
extern __sfr  __at (ADRESL_ADDR)                  ADRESL;		
extern __sfr  __at (ADCON1_ADDR)                  ADCON1;


extern __sfr  __at (PWMCON1_ADDR)                 PWMCON1;
extern __sfr  __at (PWMCON0_ADDR)                 PWMCON0;
extern __sfr  __at (PWMCLK_ADDR)                  PWMCLK;
extern __sfr  __at (PWMPH1_ADDR)                  PWMPH1;
extern __sfr  __at (PWMPH2_ADDR)                  PWMPH2;

extern __sfr  __at (CM1CON0_ADDR)                 CM1CON0;
extern __sfr  __at (CM2CON0_ADDR)                 CM2CON0;
extern __sfr  __at (CM2CON1_ADDR)                 CM2CON1;
extern __sfr  __at (OPA1CON_ADDR)                 OPA1CON;
extern __sfr  __at (OPA2CON_ADDR)                 OPA2CON;

//----- STATUS Bits --------------------------------------------------------


//----- INTCON Bits --------------------------------------------------------


//----- PIR1 Bits ----------------------------------------------------------


//----- T1CON Bits ---------------------------------------------------------


//----- T2CON Bits ---------------------------------------------------------


//----- CCP1CON Bits -------------------------------------------------------


//----- WDTCON Bits --------------------------------------------------------


//----- ADCON0 Bits --------------------------------------------------------


//----- OPTION Bits --------------------------------------------------------


//----- PIE1 Bits ----------------------------------------------------------


//----- PCON Bits ----------------------------------------------------------


//----- OSCCON Bits --------------------------------------------------------


//----- OSCTUNE Bits -------------------------------------------------------


//----- ANSEL Bits or ANSEL0 Bits ------------------------------------------


//----- ANSEL1 Bits --------------------------------------------------------


//----- WPUA Bits ---------------------------------------------------------


//----- IOC Bits ---------------------------------------------------------


//----- IOCA Bits ---------------------------------------------------------


//----- REFCON Bits --------------------------------------------------------


//----- VRCON Bits ---------------------------------------------------------


//----- EECON1 Bits --------------------------------------------------------


//----- ADCON1 Bits --------------------------------------------------------


//----- PWMCON1 Bits --------------------------------------------------------


//----- PWMCON0 Bits --------------------------------------------------------


//----- PWMCLK Bits --------------------------------------------------------


//----- PWMPH1 Bits & PWMPH2 Bits ------------------------------------------


//----- CM1CON0 Bits --------------------------------------------------------


//----- CM2CON0 Bits --------------------------------------------------------


//----- CM2CON1 Bits --------------------------------------------------------


//----- OPA1CON Bits & OPA2CON Bits -----------------------------------------


//==========================================================================
//
//       RAM Definition
//
//==========================================================================

//         __MAXRAM H'1FF'
//         __BADRAM  H'08'-H'09', H'0D', H'16'-H'17', H'19'-H'1D'
//         __BADRAM  H'88'-H'89', H'8D', H'94', H'97', H'C0'-H'EF'
//         __BADRAM  H'108'-H'109', H'10C'-H'10F', H'115'-H'118', H'11E'-H'16F'
//         __BADRAM  H'188'-H'189', H'18C'-H'1EF'

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
#define _BOR_ON              0x3FFF
#define _BOR_NSLEEP          0x3EFF
#define _BOR_SBOREN          0x3DFF
#define _BOR_OFF             0x3CFF
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
    unsigned char CHS3:1;
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
} __ADCON0_bits_t;
extern volatile __ADCON0_bits_t __at(ADCON0_ADDR) ADCON0_bits;

#ifndef NO_BIT_DEFINES
#define ADON                 ADCON0_bits.ADON
#define GO                   ADCON0_bits.GO
#define NOT_DONE             ADCON0_bits.NOT_DONE
#define GO_DONE              ADCON0_bits.GO_DONE
#define CHS0                 ADCON0_bits.CHS0
#define CHS1                 ADCON0_bits.CHS1
#define CHS2                 ADCON0_bits.CHS2
#define CHS3                 ADCON0_bits.CHS3
#define VCFG                 ADCON0_bits.VCFG
#define ADFM                 ADCON0_bits.ADFM
#endif /* NO_BIT_DEFINES */

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
} __ADCON1_bits_t;
extern volatile __ADCON1_bits_t __at(ADCON1_ADDR) ADCON1_bits;

#ifndef NO_BIT_DEFINES
#define ADCS0                ADCON1_bits.ADCS0
#define ADCS1                ADCON1_bits.ADCS1
#define ADCS2                ADCON1_bits.ADCS2
#endif /* NO_BIT_DEFINES */

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
} __ANSEL_bits_t;
extern volatile __ANSEL_bits_t __at(ANSEL_ADDR) ANSEL_bits;

#ifndef NO_BIT_DEFINES
#define ANS0                 ANSEL_bits.ANS0
#define ANS1                 ANSEL_bits.ANS1
#define ANS2                 ANSEL_bits.ANS2
#define ANS3                 ANSEL_bits.ANS3
#define ANS4                 ANSEL_bits.ANS4
#define ANS5                 ANSEL_bits.ANS5
#define ANS6                 ANSEL_bits.ANS6
#define ANS7                 ANSEL_bits.ANS7
#endif /* NO_BIT_DEFINES */

// ----- ANSEL1 bits --------------------
typedef union {
  struct {
    unsigned char ANS8:1;
    unsigned char ANS9:1;
    unsigned char ANS10:1;
    unsigned char ANS11:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __ANSEL1_bits_t;
extern volatile __ANSEL1_bits_t __at(ANSEL1_ADDR) ANSEL1_bits;

#ifndef NO_BIT_DEFINES
#define ANS8                 ANSEL1_bits.ANS8
#define ANS9                 ANSEL1_bits.ANS9
#define ANS10                ANSEL1_bits.ANS10
#define ANS11                ANSEL1_bits.ANS11
#endif /* NO_BIT_DEFINES */

// ----- CCP1CON bits --------------------
typedef union {
  struct {
    unsigned char CCP1M0:1;
    unsigned char CCP1M1:1;
    unsigned char CCP1M2:1;
    unsigned char CCP1M3:1;
    unsigned char DC1B0:1;
    unsigned char DC1B1:1;
    unsigned char :1;
    unsigned char :1;
  };
} __CCP1CON_bits_t;
extern volatile __CCP1CON_bits_t __at(CCP1CON_ADDR) CCP1CON_bits;

#ifndef NO_BIT_DEFINES
#define CCP1M0               CCP1CON_bits.CCP1M0
#define CCP1M1               CCP1CON_bits.CCP1M1
#define CCP1M2               CCP1CON_bits.CCP1M2
#define CCP1M3               CCP1CON_bits.CCP1M3
#define DC1B0                CCP1CON_bits.DC1B0
#define DC1B1                CCP1CON_bits.DC1B1
#endif /* NO_BIT_DEFINES */

// ----- CM1CON0 bits --------------------
typedef union {
  struct {
    unsigned char C1CH0:1;
    unsigned char C1CH1:1;
    unsigned char C1R:1;
    unsigned char C1SP:1;
    unsigned char C1POL:1;
    unsigned char C1OE:1;
    unsigned char C1OUT:1;
    unsigned char C1ON:1;
  };
} __CM1CON0_bits_t;
extern volatile __CM1CON0_bits_t __at(CM1CON0_ADDR) CM1CON0_bits;

#ifndef NO_BIT_DEFINES
#define C1CH0                CM1CON0_bits.C1CH0
#define C1CH1                CM1CON0_bits.C1CH1
#define C1R                  CM1CON0_bits.C1R
#define C1SP                 CM1CON0_bits.C1SP
#define C1POL                CM1CON0_bits.C1POL
#define C1OE                 CM1CON0_bits.C1OE
#define C1OUT                CM1CON0_bits.C1OUT
#define C1ON                 CM1CON0_bits.C1ON
#endif /* NO_BIT_DEFINES */

// ----- CM2CON0 bits --------------------
typedef union {
  struct {
    unsigned char C2CH0:1;
    unsigned char C2CH1:1;
    unsigned char C2R:1;
    unsigned char C2SP:1;
    unsigned char C2POL:1;
    unsigned char C2OE:1;
    unsigned char C2OUT:1;
    unsigned char C2ON:1;
  };
} __CM2CON0_bits_t;
extern volatile __CM2CON0_bits_t __at(CM2CON0_ADDR) CM2CON0_bits;

#ifndef NO_BIT_DEFINES
#define C2CH0                CM2CON0_bits.C2CH0
#define C2CH1                CM2CON0_bits.C2CH1
#define C2R                  CM2CON0_bits.C2R
#define C2SP                 CM2CON0_bits.C2SP
#define C2POL                CM2CON0_bits.C2POL
#define C2OE                 CM2CON0_bits.C2OE
#define C2OUT                CM2CON0_bits.C2OUT
#define C2ON                 CM2CON0_bits.C2ON
#endif /* NO_BIT_DEFINES */

// ----- CM2CON1 bits --------------------
typedef union {
  struct {
    unsigned char C2SYNC:1;
    unsigned char T1GSS:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char MC2OUT:1;
    unsigned char MC1OUT:1;
  };
} __CM2CON1_bits_t;
extern volatile __CM2CON1_bits_t __at(CM2CON1_ADDR) CM2CON1_bits;

#ifndef NO_BIT_DEFINES
#define C2SYNC               CM2CON1_bits.C2SYNC
#define T1GSS                CM2CON1_bits.T1GSS
#define MC2OUT               CM2CON1_bits.MC2OUT
#define MC1OUT               CM2CON1_bits.MC1OUT
#endif /* NO_BIT_DEFINES */

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
} __EECON1_bits_t;
extern volatile __EECON1_bits_t __at(EECON1_ADDR) EECON1_bits;

#ifndef NO_BIT_DEFINES
#define RD                   EECON1_bits.RD
#define WR                   EECON1_bits.WR
#define WREN                 EECON1_bits.WREN
#define WRERR                EECON1_bits.WRERR
#endif /* NO_BIT_DEFINES */

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
} __INTCON_bits_t;
extern volatile __INTCON_bits_t __at(INTCON_ADDR) INTCON_bits;

#ifndef NO_BIT_DEFINES
#define RAIF                 INTCON_bits.RAIF
#define INTF                 INTCON_bits.INTF
#define T0IF                 INTCON_bits.T0IF
#define RAIE                 INTCON_bits.RAIE
#define INTE                 INTCON_bits.INTE
#define T0IE                 INTCON_bits.T0IE
#define PEIE                 INTCON_bits.PEIE
#define GIE                  INTCON_bits.GIE
#endif /* NO_BIT_DEFINES */

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
} __IOC_bits_t;
extern volatile __IOC_bits_t __at(IOC_ADDR) IOC_bits;

#ifndef NO_BIT_DEFINES
#define IOC0                 IOC_bits.IOC0
#define IOC1                 IOC_bits.IOC1
#define IOC2                 IOC_bits.IOC2
#define IOC3                 IOC_bits.IOC3
#define IOC4                 IOC_bits.IOC4
#define IOC5                 IOC_bits.IOC5
#endif /* NO_BIT_DEFINES */

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
} __IOCA_bits_t;
extern volatile __IOCA_bits_t __at(IOCA_ADDR) IOCA_bits;

#ifndef NO_BIT_DEFINES
#define IOCA0                IOCA_bits.IOCA0
#define IOCA1                IOCA_bits.IOCA1
#define IOCA2                IOCA_bits.IOCA2
#define IOCA3                IOCA_bits.IOCA3
#define IOCA4                IOCA_bits.IOCA4
#define IOCA5                IOCA_bits.IOCA5
#endif /* NO_BIT_DEFINES */

// ----- OPA1CON bits --------------------
typedef union {
  struct {
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char OPAON:1;
  };
} __OPA1CON_bits_t;
extern volatile __OPA1CON_bits_t __at(OPA1CON_ADDR) OPA1CON_bits;

#ifndef NO_BIT_DEFINES
#define OPAON                OPA1CON_bits.OPAON
#endif /* NO_BIT_DEFINES */

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
} __OPTION_REG_bits_t;
extern volatile __OPTION_REG_bits_t __at(OPTION_REG_ADDR) OPTION_REG_bits;

#ifndef NO_BIT_DEFINES
#define PS0                  OPTION_REG_bits.PS0
#define PS1                  OPTION_REG_bits.PS1
#define PS2                  OPTION_REG_bits.PS2
#define PSA                  OPTION_REG_bits.PSA
#define T0SE                 OPTION_REG_bits.T0SE
#define T0CS                 OPTION_REG_bits.T0CS
#define INTEDG               OPTION_REG_bits.INTEDG
#define NOT_RAPU             OPTION_REG_bits.NOT_RAPU
#endif /* NO_BIT_DEFINES */

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
} __OSCCON_bits_t;
extern volatile __OSCCON_bits_t __at(OSCCON_ADDR) OSCCON_bits;

#ifndef NO_BIT_DEFINES
#define SCS                  OSCCON_bits.SCS
#define LTS                  OSCCON_bits.LTS
#define HTS                  OSCCON_bits.HTS
#define OSTS                 OSCCON_bits.OSTS
#define IRCF0                OSCCON_bits.IRCF0
#define IRCF1                OSCCON_bits.IRCF1
#define IRCF2                OSCCON_bits.IRCF2
#endif /* NO_BIT_DEFINES */

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
} __OSCTUNE_bits_t;
extern volatile __OSCTUNE_bits_t __at(OSCTUNE_ADDR) OSCTUNE_bits;

#ifndef NO_BIT_DEFINES
#define TUN0                 OSCTUNE_bits.TUN0
#define TUN1                 OSCTUNE_bits.TUN1
#define TUN2                 OSCTUNE_bits.TUN2
#define TUN3                 OSCTUNE_bits.TUN3
#define TUN4                 OSCTUNE_bits.TUN4
#endif /* NO_BIT_DEFINES */

// ----- PCON bits --------------------
typedef union {
  struct {
    unsigned char NOT_BOD:1;
    unsigned char NOT_POR:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char SBODEN:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
  struct {
    unsigned char NOT_BOR:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char SBOREN:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __PCON_bits_t;
extern volatile __PCON_bits_t __at(PCON_ADDR) PCON_bits;

#ifndef NO_BIT_DEFINES
#define NOT_BOD              PCON_bits.NOT_BOD
#define NOT_BOR              PCON_bits.NOT_BOR
#define NOT_POR              PCON_bits.NOT_POR
#define SBODEN               PCON_bits.SBODEN
#define SBOREN               PCON_bits.SBOREN
#endif /* NO_BIT_DEFINES */

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
} __PIE1_bits_t;
extern volatile __PIE1_bits_t __at(PIE1_ADDR) PIE1_bits;

#ifndef NO_BIT_DEFINES
#define T1IE                 PIE1_bits.T1IE
#define TMR1IE               PIE1_bits.TMR1IE
#define T2IE                 PIE1_bits.T2IE
#define TMR2IE               PIE1_bits.TMR2IE
#define OSFIE                PIE1_bits.OSFIE
#define C1IE                 PIE1_bits.C1IE
#define C2IE                 PIE1_bits.C2IE
#define CCP1IE               PIE1_bits.CCP1IE
#define ADIE                 PIE1_bits.ADIE
#define EEIE                 PIE1_bits.EEIE
#endif /* NO_BIT_DEFINES */

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
} __PIR1_bits_t;
extern volatile __PIR1_bits_t __at(PIR1_ADDR) PIR1_bits;

#ifndef NO_BIT_DEFINES
#define T1IF                 PIR1_bits.T1IF
#define TMR1IF               PIR1_bits.TMR1IF
#define T2IF                 PIR1_bits.T2IF
#define TMR2IF               PIR1_bits.TMR2IF
#define OSFIF                PIR1_bits.OSFIF
#define C1IF                 PIR1_bits.C1IF
#define C2IF                 PIR1_bits.C2IF
#define CCP1IF               PIR1_bits.CCP1IF
#define ADIF                 PIR1_bits.ADIF
#define EEIF                 PIR1_bits.EEIF
#endif /* NO_BIT_DEFINES */

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
} __PORTA_bits_t;
extern volatile __PORTA_bits_t __at(PORTA_ADDR) PORTA_bits;

#ifndef NO_BIT_DEFINES
#define RA0                  PORTA_bits.RA0
#define RA1                  PORTA_bits.RA1
#define RA2                  PORTA_bits.RA2
#define RA3                  PORTA_bits.RA3
#define RA4                  PORTA_bits.RA4
#define RA5                  PORTA_bits.RA5
#endif /* NO_BIT_DEFINES */

// ----- PORTB bits --------------------
typedef union {
  struct {
    unsigned char RB0:1;
    unsigned char RB1:1;
    unsigned char RB2:1;
    unsigned char RB3:1;
    unsigned char RB4:1;
    unsigned char RB5:1;
    unsigned char RB6:1;
    unsigned char RB7:1;
  };
} __PORTB_bits_t;
extern volatile __PORTB_bits_t __at(PORTB_ADDR) PORTB_bits;

#ifndef NO_BIT_DEFINES
#define RB0                  PORTB_bits.RB0
#define RB1                  PORTB_bits.RB1
#define RB2                  PORTB_bits.RB2
#define RB3                  PORTB_bits.RB3
#define RB4                  PORTB_bits.RB4
#define RB5                  PORTB_bits.RB5
#define RB6                  PORTB_bits.RB6
#define RB7                  PORTB_bits.RB7
#endif /* NO_BIT_DEFINES */

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
} __PORTC_bits_t;
extern volatile __PORTC_bits_t __at(PORTC_ADDR) PORTC_bits;

#ifndef NO_BIT_DEFINES
#define RC0                  PORTC_bits.RC0
#define RC1                  PORTC_bits.RC1
#define RC2                  PORTC_bits.RC2
#define RC3                  PORTC_bits.RC3
#define RC4                  PORTC_bits.RC4
#define RC5                  PORTC_bits.RC5
#define RC6                  PORTC_bits.RC6
#define RC7                  PORTC_bits.RC7
#endif /* NO_BIT_DEFINES */

// ----- PWMCLK bits --------------------
typedef union {
  struct {
    unsigned char PER0:1;
    unsigned char PER1:1;
    unsigned char PER2:1;
    unsigned char PER3:1;
    unsigned char PER4:1;
    unsigned char PWMP0:1;
    unsigned char PWMP1:1;
    unsigned char PWMASE:1;
  };
} __PWMCLK_bits_t;
extern volatile __PWMCLK_bits_t __at(PWMCLK_ADDR) PWMCLK_bits;

#ifndef NO_BIT_DEFINES
#define PER0                 PWMCLK_bits.PER0
#define PER1                 PWMCLK_bits.PER1
#define PER2                 PWMCLK_bits.PER2
#define PER3                 PWMCLK_bits.PER3
#define PER4                 PWMCLK_bits.PER4
#define PWMP0                PWMCLK_bits.PWMP0
#define PWMP1                PWMCLK_bits.PWMP1
#define PWMASE               PWMCLK_bits.PWMASE
#endif /* NO_BIT_DEFINES */

// ----- PWMCON0 bits --------------------
typedef union {
  struct {
    unsigned char PH1EN:1;
    unsigned char PH2EN:1;
    unsigned char SYNC0:1;
    unsigned char SYNC1:1;
    unsigned char BLANK1:1;
    unsigned char BLANK2:1;
    unsigned char PASEN:1;
    unsigned char PRSEN:1;
  };
} __PWMCON0_bits_t;
extern volatile __PWMCON0_bits_t __at(PWMCON0_ADDR) PWMCON0_bits;

#ifndef NO_BIT_DEFINES
#define PH1EN                PWMCON0_bits.PH1EN
#define PH2EN                PWMCON0_bits.PH2EN
#define SYNC0                PWMCON0_bits.SYNC0
#define SYNC1                PWMCON0_bits.SYNC1
#define BLANK1               PWMCON0_bits.BLANK1
#define BLANK2               PWMCON0_bits.BLANK2
#define PASEN                PWMCON0_bits.PASEN
#define PRSEN                PWMCON0_bits.PRSEN
#endif /* NO_BIT_DEFINES */

// ----- PWMCON1 bits --------------------
typedef union {
  struct {
    unsigned char CMDLY0:1;
    unsigned char CMDLY1:1;
    unsigned char CMDLY2:1;
    unsigned char CMDLY3:1;
    unsigned char CMDLY4:1;
    unsigned char COMOD0:1;
    unsigned char COMOD1:1;
    unsigned char :1;
  };
} __PWMCON1_bits_t;
extern volatile __PWMCON1_bits_t __at(PWMCON1_ADDR) PWMCON1_bits;

#ifndef NO_BIT_DEFINES
#define CMDLY0               PWMCON1_bits.CMDLY0
#define CMDLY1               PWMCON1_bits.CMDLY1
#define CMDLY2               PWMCON1_bits.CMDLY2
#define CMDLY3               PWMCON1_bits.CMDLY3
#define CMDLY4               PWMCON1_bits.CMDLY4
#define COMOD0               PWMCON1_bits.COMOD0
#define COMOD1               PWMCON1_bits.COMOD1
#endif /* NO_BIT_DEFINES */

// ----- PWMPH1 bits --------------------
typedef union {
  struct {
    unsigned char PH0:1;
    unsigned char PH1:1;
    unsigned char PH2:1;
    unsigned char PH3:1;
    unsigned char PH4:1;
    unsigned char C1EN:1;
    unsigned char C2EN:1;
    unsigned char POL:1;
  };
} __PWMPH1_bits_t;
extern volatile __PWMPH1_bits_t __at(PWMPH1_ADDR) PWMPH1_bits;

#ifndef NO_BIT_DEFINES
#define PH0                  PWMPH1_bits.PH0
#define PH1                  PWMPH1_bits.PH1
#define PH2                  PWMPH1_bits.PH2
#define PH3                  PWMPH1_bits.PH3
#define PH4                  PWMPH1_bits.PH4
#define C1EN                 PWMPH1_bits.C1EN
#define C2EN                 PWMPH1_bits.C2EN
#define POL                  PWMPH1_bits.POL
#endif /* NO_BIT_DEFINES */

// ----- REFCON bits --------------------
typedef union {
  struct {
    unsigned char :1;
    unsigned char CVROE:1;
    unsigned char VROE:1;
    unsigned char VREN:1;
    unsigned char VRBB:1;
    unsigned char BGST:1;
    unsigned char :1;
    unsigned char :1;
  };
} __REFCON_bits_t;
extern volatile __REFCON_bits_t __at(REFCON_ADDR) REFCON_bits;

#ifndef NO_BIT_DEFINES
#define CVROE                REFCON_bits.CVROE
#define VROE                 REFCON_bits.VROE
#define VREN                 REFCON_bits.VREN
#define VRBB                 REFCON_bits.VRBB
#define BGST                 REFCON_bits.BGST
#endif /* NO_BIT_DEFINES */

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
} __STATUS_bits_t;
extern volatile __STATUS_bits_t __at(STATUS_ADDR) STATUS_bits;

#ifndef NO_BIT_DEFINES
#define C                    STATUS_bits.C
#define DC                   STATUS_bits.DC
#define Z                    STATUS_bits.Z
#define NOT_PD               STATUS_bits.NOT_PD
#define NOT_TO               STATUS_bits.NOT_TO
#define RP0                  STATUS_bits.RP0
#define RP1                  STATUS_bits.RP1
#define IRP                  STATUS_bits.IRP
#endif /* NO_BIT_DEFINES */

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
  struct {
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char T1GE:1;
    unsigned char :1;
  };
} __T1CON_bits_t;
extern volatile __T1CON_bits_t __at(T1CON_ADDR) T1CON_bits;

#ifndef NO_BIT_DEFINES
#define TMR1ON               T1CON_bits.TMR1ON
#define TMR1CS               T1CON_bits.TMR1CS
#define NOT_T1SYNC           T1CON_bits.NOT_T1SYNC
#define T1OSCEN              T1CON_bits.T1OSCEN
#define T1CKPS0              T1CON_bits.T1CKPS0
#define T1CKPS1              T1CON_bits.T1CKPS1
#define TMR1GE               T1CON_bits.TMR1GE
#define T1GE                 T1CON_bits.T1GE
#define T1GINV               T1CON_bits.T1GINV
#endif /* NO_BIT_DEFINES */

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
} __T2CON_bits_t;
extern volatile __T2CON_bits_t __at(T2CON_ADDR) T2CON_bits;

#ifndef NO_BIT_DEFINES
#define T2CKPS0              T2CON_bits.T2CKPS0
#define T2CKPS1              T2CON_bits.T2CKPS1
#define TMR2ON               T2CON_bits.TMR2ON
#define TOUTPS0              T2CON_bits.TOUTPS0
#define TOUTPS1              T2CON_bits.TOUTPS1
#define TOUTPS2              T2CON_bits.TOUTPS2
#define TOUTPS3              T2CON_bits.TOUTPS3
#endif /* NO_BIT_DEFINES */

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
} __TRISA_bits_t;
extern volatile __TRISA_bits_t __at(TRISA_ADDR) TRISA_bits;

#ifndef NO_BIT_DEFINES
#define TRISA0               TRISA_bits.TRISA0
#define TRISA1               TRISA_bits.TRISA1
#define TRISA2               TRISA_bits.TRISA2
#define TRISA3               TRISA_bits.TRISA3
#define TRISA4               TRISA_bits.TRISA4
#define TRISA5               TRISA_bits.TRISA5
#endif /* NO_BIT_DEFINES */

// ----- TRISB bits --------------------
typedef union {
  struct {
    unsigned char TRISB0:1;
    unsigned char TRISB1:1;
    unsigned char TRISB2:1;
    unsigned char TRISB3:1;
    unsigned char TRISB4:1;
    unsigned char TRISB5:1;
    unsigned char TRISB6:1;
    unsigned char TRISB7:1;
  };
} __TRISB_bits_t;
extern volatile __TRISB_bits_t __at(TRISB_ADDR) TRISB_bits;

#ifndef NO_BIT_DEFINES
#define TRISB0               TRISB_bits.TRISB0
#define TRISB1               TRISB_bits.TRISB1
#define TRISB2               TRISB_bits.TRISB2
#define TRISB3               TRISB_bits.TRISB3
#define TRISB4               TRISB_bits.TRISB4
#define TRISB5               TRISB_bits.TRISB5
#define TRISB6               TRISB_bits.TRISB6
#define TRISB7               TRISB_bits.TRISB7
#endif /* NO_BIT_DEFINES */

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
} __TRISC_bits_t;
extern volatile __TRISC_bits_t __at(TRISC_ADDR) TRISC_bits;

#ifndef NO_BIT_DEFINES
#define TRISC0               TRISC_bits.TRISC0
#define TRISC1               TRISC_bits.TRISC1
#define TRISC2               TRISC_bits.TRISC2
#define TRISC3               TRISC_bits.TRISC3
#define TRISC4               TRISC_bits.TRISC4
#define TRISC5               TRISC_bits.TRISC5
#define TRISC6               TRISC_bits.TRISC6
#define TRISC7               TRISC_bits.TRISC7
#endif /* NO_BIT_DEFINES */

// ----- VRCON bits --------------------
typedef union {
  struct {
    unsigned char VR0:1;
    unsigned char VR1:1;
    unsigned char VR2:1;
    unsigned char VR3:1;
    unsigned char :1;
    unsigned char VRR:1;
    unsigned char C2VREN:1;
    unsigned char C1VREN:1;
  };
} __VRCON_bits_t;
extern volatile __VRCON_bits_t __at(VRCON_ADDR) VRCON_bits;

#ifndef NO_BIT_DEFINES
#define VR0                  VRCON_bits.VR0
#define VR1                  VRCON_bits.VR1
#define VR2                  VRCON_bits.VR2
#define VR3                  VRCON_bits.VR3
#define VRR                  VRCON_bits.VRR
#define C2VREN               VRCON_bits.C2VREN
#define C1VREN               VRCON_bits.C1VREN
#endif /* NO_BIT_DEFINES */

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
} __WDTCON_bits_t;
extern volatile __WDTCON_bits_t __at(WDTCON_ADDR) WDTCON_bits;

#ifndef NO_BIT_DEFINES
#define SWDTEN               WDTCON_bits.SWDTEN
#define WDTPS0               WDTCON_bits.WDTPS0
#define WDTPS1               WDTCON_bits.WDTPS1
#define WDTPS2               WDTCON_bits.WDTPS2
#define WDTPS3               WDTCON_bits.WDTPS3
#endif /* NO_BIT_DEFINES */

// ----- WPUA bits --------------------
typedef union {
  struct {
    unsigned char WPUA0:1;
    unsigned char WPUA1:1;
    unsigned char WPUA2:1;
    unsigned char WPUA3:1;
    unsigned char WPUA4:1;
    unsigned char WPUA5:1;
    unsigned char :1;
    unsigned char :1;
  };
} __WPUA_bits_t;
extern volatile __WPUA_bits_t __at(WPUA_ADDR) WPUA_bits;

#ifndef NO_BIT_DEFINES
#define WPUA0                WPUA_bits.WPUA0
#define WPUA1                WPUA_bits.WPUA1
#define WPUA2                WPUA_bits.WPUA2
#define WPUA3                WPUA_bits.WPUA3
#define WPUA4                WPUA_bits.WPUA4
#define WPUA5                WPUA_bits.WPUA5
#endif /* NO_BIT_DEFINES */

#endif