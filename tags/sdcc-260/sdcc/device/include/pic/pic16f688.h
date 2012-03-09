//
// Register Declarations for Microchip 16F688 Processor
//
//
// This header file was automatically generated by:
//
//	inc2h.pl V1.6
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
#ifndef P16F688_H
#define P16F688_H

//
// Register addresses.
//
#define INDF_ADDR	0x0000
#define TMR0_ADDR	0x0001
#define PCL_ADDR	0x0002
#define STATUS_ADDR	0x0003
#define FSR_ADDR	0x0004
#define PORTA_ADDR	0x0005
#define PORTC_ADDR	0x0007
#define PCLATH_ADDR	0x000A
#define INTCON_ADDR	0x000B
#define PIR1_ADDR	0x000C
#define TMR1L_ADDR	0x000E
#define TMR1H_ADDR	0x000F
#define T1CON_ADDR	0x0010
#define BAUDCTL_ADDR	0x0011
#define SPBRGH_ADDR	0x0012
#define SPBRG_ADDR	0x0013
#define RCREG_ADDR	0x0014
#define TXREG_ADDR	0x0015
#define TXSTA_ADDR	0x0016
#define RCSTA_ADDR	0x0017
#define WDTCON_ADDR	0x0018
#define CMCON0_ADDR	0x0019
#define CMCON1_ADDR	0x001A
#define ADRESH_ADDR	0x001E
#define ADCON0_ADDR	0x001F
#define OPTION_REG_ADDR	0x0081
#define TRISA_ADDR	0x0085
#define TRISC_ADDR	0x0087
#define PIE1_ADDR	0x008C
#define PCON_ADDR	0x008E
#define OSCCON_ADDR	0x008F
#define OSCTUNE_ADDR	0x0090
#define ANSEL_ADDR	0x0091
#define WPU_ADDR	0x0095
#define WPUA_ADDR	0x0095
#define IOC_ADDR	0x0096
#define IOCA_ADDR	0x0096
#define EEDATH_ADDR	0x0097
#define EEADRH_ADDR	0x0098
#define VRCON_ADDR	0x0099
#define EEDAT_ADDR	0x009A
#define EEDATA_ADDR	0x009A
#define EEADR_ADDR	0x009B
#define EECON1_ADDR	0x009C
#define EECON2_ADDR	0x009D
#define ADRESL_ADDR	0x009E
#define ADCON1_ADDR	0x009F

//
// Memory organization.
//

#pragma memmap INDF_ADDR INDF_ADDR SFR 0x000	// INDF
#pragma memmap TMR0_ADDR TMR0_ADDR SFR 0x000	// TMR0
#pragma memmap PCL_ADDR PCL_ADDR SFR 0x000	// PCL
#pragma memmap STATUS_ADDR STATUS_ADDR SFR 0x000	// STATUS
#pragma memmap FSR_ADDR FSR_ADDR SFR 0x000	// FSR
#pragma memmap PORTA_ADDR PORTA_ADDR SFR 0x000	// PORTA
#pragma memmap PORTC_ADDR PORTC_ADDR SFR 0x000	// PORTC
#pragma memmap PCLATH_ADDR PCLATH_ADDR SFR 0x000	// PCLATH
#pragma memmap INTCON_ADDR INTCON_ADDR SFR 0x000	// INTCON
#pragma memmap PIR1_ADDR PIR1_ADDR SFR 0x000	// PIR1
#pragma memmap TMR1L_ADDR TMR1L_ADDR SFR 0x000	// TMR1L
#pragma memmap TMR1H_ADDR TMR1H_ADDR SFR 0x000	// TMR1H
#pragma memmap T1CON_ADDR T1CON_ADDR SFR 0x000	// T1CON
#pragma memmap BAUDCTL_ADDR BAUDCTL_ADDR SFR 0x000	// BAUDCTL
#pragma memmap SPBRGH_ADDR SPBRGH_ADDR SFR 0x000	// SPBRGH
#pragma memmap SPBRG_ADDR SPBRG_ADDR SFR 0x000	// SPBRG
#pragma memmap RCREG_ADDR RCREG_ADDR SFR 0x000	// RCREG
#pragma memmap TXREG_ADDR TXREG_ADDR SFR 0x000	// TXREG
#pragma memmap TXSTA_ADDR TXSTA_ADDR SFR 0x000	// TXSTA
#pragma memmap RCSTA_ADDR RCSTA_ADDR SFR 0x000	// RCSTA
#pragma memmap WDTCON_ADDR WDTCON_ADDR SFR 0x000	// WDTCON
#pragma memmap CMCON0_ADDR CMCON0_ADDR SFR 0x000	// CMCON0
#pragma memmap CMCON1_ADDR CMCON1_ADDR SFR 0x000	// CMCON1
#pragma memmap ADRESH_ADDR ADRESH_ADDR SFR 0x000	// ADRESH
#pragma memmap ADCON0_ADDR ADCON0_ADDR SFR 0x000	// ADCON0
#pragma memmap OPTION_REG_ADDR OPTION_REG_ADDR SFR 0x000	// OPTION_REG
#pragma memmap TRISA_ADDR TRISA_ADDR SFR 0x000	// TRISA
#pragma memmap TRISC_ADDR TRISC_ADDR SFR 0x000	// TRISC
#pragma memmap PIE1_ADDR PIE1_ADDR SFR 0x000	// PIE1
#pragma memmap PCON_ADDR PCON_ADDR SFR 0x000	// PCON
#pragma memmap OSCCON_ADDR OSCCON_ADDR SFR 0x000	// OSCCON
#pragma memmap OSCTUNE_ADDR OSCTUNE_ADDR SFR 0x000	// OSCTUNE
#pragma memmap ANSEL_ADDR ANSEL_ADDR SFR 0x000	// ANSEL
#pragma memmap WPU_ADDR WPU_ADDR SFR 0x000	// WPU
#pragma memmap WPUA_ADDR WPUA_ADDR SFR 0x000	// WPUA
#pragma memmap IOC_ADDR IOC_ADDR SFR 0x000	// IOC
#pragma memmap IOCA_ADDR IOCA_ADDR SFR 0x000	// IOCA
#pragma memmap EEDATH_ADDR EEDATH_ADDR SFR 0x000	// EEDATH
#pragma memmap EEADRH_ADDR EEADRH_ADDR SFR 0x000	// EEADRH
#pragma memmap VRCON_ADDR VRCON_ADDR SFR 0x000	// VRCON
#pragma memmap EEDAT_ADDR EEDAT_ADDR SFR 0x000	// EEDAT
#pragma memmap EEDATA_ADDR EEDATA_ADDR SFR 0x000	// EEDATA
#pragma memmap EEADR_ADDR EEADR_ADDR SFR 0x000	// EEADR
#pragma memmap EECON1_ADDR EECON1_ADDR SFR 0x000	// EECON1
#pragma memmap EECON2_ADDR EECON2_ADDR SFR 0x000	// EECON2
#pragma memmap ADRESL_ADDR ADRESL_ADDR SFR 0x000	// ADRESL
#pragma memmap ADCON1_ADDR ADCON1_ADDR SFR 0x000	// ADCON1


//         LIST
// P16F688.INC  Standard Header File, Version 1.00    Microchip Technology, Inc.
//         NOLIST

// This header file defines configurations, registers, and other useful bits of
// information for the PIC16F688 microcontroller.  These names are taken to match 
// the data sheets as closely as possible.  

// Note that the processor must be selected before this file is 
// included.  The processor may be selected the following ways:

//       1. Command line switch:
//               C:\ MPASM MYFILE.ASM /PIC16F688
//       2. LIST directive in the source file
//               LIST   P=PIC16F688
//       3. Processor Type entry in the MPASM full-screen interface

//==========================================================================
//
//       Revision History
//
//==========================================================================
//1.00   07/28/03 Original
//1.01	09/02/03 Modified to match datasheet
//1.02 09/19/03 Changed CMCON1 from 0x20 to 0x1A (pas)
//==========================================================================
//
//       Verify Processor
//
//==========================================================================

//        IFNDEF __16F688
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

extern __data __at (INDF_ADDR) volatile char      INDF;
extern __sfr  __at (TMR0_ADDR)                    TMR0;
extern __data __at (PCL_ADDR) volatile char       PCL;
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
extern __sfr  __at (BAUDCTL_ADDR)                 BAUDCTL;
extern __sfr  __at (SPBRGH_ADDR)                  SPBRGH;
extern __sfr  __at (SPBRG_ADDR)                   SPBRG;
extern __sfr  __at (RCREG_ADDR)                   RCREG;
extern __sfr  __at (TXREG_ADDR)                   TXREG;
extern __sfr  __at (TXSTA_ADDR)                   TXSTA;
extern __sfr  __at (RCSTA_ADDR)                   RCSTA;
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

extern __sfr  __at (WPU_ADDR)                     WPU;
extern __sfr  __at (WPUA_ADDR)                    WPUA;
extern __sfr  __at (IOC_ADDR)                     IOC;
extern __sfr  __at (IOCA_ADDR)                    IOCA;
extern __sfr  __at (EEDATH_ADDR)                  EEDATH;
extern __sfr  __at (EEADRH_ADDR)                  EEADRH;
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


//----- BAUDCTL Bits --------------------------------------------------------


//----- TXSTA Bits --------------------------------------------------------


//----- RCSTA Bits --------------------------------------------------------

//----- WDTCON Bits --------------------------------------------------------


//----- CMCON0 Bits -------------------------------------------------------


//----- CMCON1 Bits -------------------------------------------------------


//----- ADCON0 Bits --------------------------------------------------------


//----- OPTION Bits --------------------------------------------------------


//----- PIE1 Bits ----------------------------------------------------------


//----- PCON Bits ----------------------------------------------------------


//----- OSCCON Bits --------------------------------------------------------


//----- OSCTUNE Bits -------------------------------------------------------


//----- ANSEL --------------------------------------------------------------


//----- IOC --------------------------------------------------------------


//----- IOCA --------------------------------------------------------------


//----- VRCON Bits ---------------------------------------------------------


//----- EECON1 -------------------------------------------------------------


//----- ADCON1 -------------------------------------------------------------


//==========================================================================
//
//       RAM Definition
//
//==========================================================================

//         __MAXRAM H'1FF'
//         __BADRAM H'06', H'08'-H'09', H'0D', H'1B'-H'1D'
//         __BADRAM H'86', H'88'-H'89', H'8D', H'92'-H'94'
// 	__BADRAM H'106', H'108'-H'109', H'10C'-H'11F'
//         __BADRAM H'186', H'188'-H'189', H'18C'-H'18D', H'190'-H'1EF'

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
} __ADCON0_bits_t;
extern volatile __ADCON0_bits_t __at(ADCON0_ADDR) ADCON0_bits;

#define ADON                 ADCON0_bits.ADON
#define GO                   ADCON0_bits.GO
#define NOT_DONE             ADCON0_bits.NOT_DONE
#define GO_DONE              ADCON0_bits.GO_DONE
#define CHS0                 ADCON0_bits.CHS0
#define CHS1                 ADCON0_bits.CHS1
#define CHS2                 ADCON0_bits.CHS2
#define VCFG                 ADCON0_bits.VCFG
#define ADFM                 ADCON0_bits.ADFM

// ----- BAUDCTL bits --------------------
typedef union {
  struct {
    unsigned char ABDEN:1;
    unsigned char WUE:1;
    unsigned char :1;
    unsigned char BRG16:1;
    unsigned char SCKP:1;
    unsigned char :1;
    unsigned char RCIDL:1;
    unsigned char ABDOVF:1;
  };
} __BAUDCTL_bits_t;
extern volatile __BAUDCTL_bits_t __at(BAUDCTL_ADDR) BAUDCTL_bits;

#define ABDEN                BAUDCTL_bits.ABDEN
#define WUE                  BAUDCTL_bits.WUE
#define BRG16                BAUDCTL_bits.BRG16
#define SCKP                 BAUDCTL_bits.SCKP
#define RCIDL                BAUDCTL_bits.RCIDL
#define ABDOVF               BAUDCTL_bits.ABDOVF

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
} __CMCON0_bits_t;
extern volatile __CMCON0_bits_t __at(CMCON0_ADDR) CMCON0_bits;

#define CM0                  CMCON0_bits.CM0
#define CM1                  CMCON0_bits.CM1
#define CM2                  CMCON0_bits.CM2
#define CIS                  CMCON0_bits.CIS
#define C1INV                CMCON0_bits.C1INV
#define C2INV                CMCON0_bits.C2INV
#define C1OUT                CMCON0_bits.C1OUT
#define C2OUT                CMCON0_bits.C2OUT

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
} __CMCON1_bits_t;
extern volatile __CMCON1_bits_t __at(CMCON1_ADDR) CMCON1_bits;

#define C2SYNC               CMCON1_bits.C2SYNC
#define T1GSS                CMCON1_bits.T1GSS

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

#define RAIF                 INTCON_bits.RAIF
#define INTF                 INTCON_bits.INTF
#define T0IF                 INTCON_bits.T0IF
#define RAIE                 INTCON_bits.RAIE
#define INTE                 INTCON_bits.INTE
#define T0IE                 INTCON_bits.T0IE
#define PEIE                 INTCON_bits.PEIE
#define GIE                  INTCON_bits.GIE

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

#define PS0                  OPTION_REG_bits.PS0
#define PS1                  OPTION_REG_bits.PS1
#define PS2                  OPTION_REG_bits.PS2
#define PSA                  OPTION_REG_bits.PSA
#define T0SE                 OPTION_REG_bits.T0SE
#define T0CS                 OPTION_REG_bits.T0CS
#define INTEDG               OPTION_REG_bits.INTEDG
#define NOT_RAPU             OPTION_REG_bits.NOT_RAPU

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

#define SCS                  OSCCON_bits.SCS
#define LTS                  OSCCON_bits.LTS
#define HTS                  OSCCON_bits.HTS
#define OSTS                 OSCCON_bits.OSTS
#define IRCF0                OSCCON_bits.IRCF0
#define IRCF1                OSCCON_bits.IRCF1
#define IRCF2                OSCCON_bits.IRCF2

// ----- OSCTUNE bits --------------------
typedef union {
  struct {
    unsigned char TUN0:1;
    unsigned char TUN1:1;
    unsigned char TUN2:1;
    unsigned char TUN3:1;
    unsigned char TUN4:1;
    unsigned char ANS5:1;
    unsigned char ANS6:1;
    unsigned char ANS7:1;
  };
  struct {
    unsigned char ANS0:1;
    unsigned char ANS1:1;
    unsigned char ANS2:1;
    unsigned char ANS3:1;
    unsigned char ANS4:1;
    unsigned char IOC5:1;
    unsigned char :1;
    unsigned char :1;
  };
  struct {
    unsigned char IOC0:1;
    unsigned char IOC1:1;
    unsigned char IOC2:1;
    unsigned char IOC3:1;
    unsigned char IOC4:1;
    unsigned char IOCA5:1;
    unsigned char :1;
    unsigned char :1;
  };
  struct {
    unsigned char IOCA0:1;
    unsigned char IOCA1:1;
    unsigned char IOCA2:1;
    unsigned char IOCA3:1;
    unsigned char IOCA4:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __OSCTUNE_bits_t;
extern volatile __OSCTUNE_bits_t __at(OSCTUNE_ADDR) OSCTUNE_bits;

#define TUN0                 OSCTUNE_bits.TUN0
#define ANS0                 OSCTUNE_bits.ANS0
#define IOC0                 OSCTUNE_bits.IOC0
#define IOCA0                OSCTUNE_bits.IOCA0
#define TUN1                 OSCTUNE_bits.TUN1
#define ANS1                 OSCTUNE_bits.ANS1
#define IOC1                 OSCTUNE_bits.IOC1
#define IOCA1                OSCTUNE_bits.IOCA1
#define TUN2                 OSCTUNE_bits.TUN2
#define ANS2                 OSCTUNE_bits.ANS2
#define IOC2                 OSCTUNE_bits.IOC2
#define IOCA2                OSCTUNE_bits.IOCA2
#define TUN3                 OSCTUNE_bits.TUN3
#define ANS3                 OSCTUNE_bits.ANS3
#define IOC3                 OSCTUNE_bits.IOC3
#define IOCA3                OSCTUNE_bits.IOCA3
#define TUN4                 OSCTUNE_bits.TUN4
#define ANS4                 OSCTUNE_bits.ANS4
#define IOC4                 OSCTUNE_bits.IOC4
#define IOCA4                OSCTUNE_bits.IOCA4
#define ANS5                 OSCTUNE_bits.ANS5
#define IOC5                 OSCTUNE_bits.IOC5
#define IOCA5                OSCTUNE_bits.IOCA5
#define ANS6                 OSCTUNE_bits.ANS6
#define ANS7                 OSCTUNE_bits.ANS7

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
} __PCON_bits_t;
extern volatile __PCON_bits_t __at(PCON_ADDR) PCON_bits;

#define NOT_BOD              PCON_bits.NOT_BOD
#define NOT_POR              PCON_bits.NOT_POR
#define SBODEN               PCON_bits.SBODEN
#define ULPWUE               PCON_bits.ULPWUE

// ----- PIE1 bits --------------------
typedef union {
  struct {
    unsigned char T1IE:1;
    unsigned char TXIE:1;
    unsigned char OSFIE:1;
    unsigned char C1IE:1;
    unsigned char C2IE:1;
    unsigned char RCIE:1;
    unsigned char ADIE:1;
    unsigned char EEIE:1;
  };
  struct {
    unsigned char TMR1IE:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __PIE1_bits_t;
extern volatile __PIE1_bits_t __at(PIE1_ADDR) PIE1_bits;

#define T1IE                 PIE1_bits.T1IE
#define TMR1IE               PIE1_bits.TMR1IE
#define TXIE                 PIE1_bits.TXIE
#define OSFIE                PIE1_bits.OSFIE
#define C1IE                 PIE1_bits.C1IE
#define C2IE                 PIE1_bits.C2IE
#define RCIE                 PIE1_bits.RCIE
#define ADIE                 PIE1_bits.ADIE
#define EEIE                 PIE1_bits.EEIE

// ----- PIR1 bits --------------------
typedef union {
  struct {
    unsigned char T1IF:1;
    unsigned char TXIF:1;
    unsigned char OSFIF:1;
    unsigned char C1IF:1;
    unsigned char C2IF:1;
    unsigned char RCIF:1;
    unsigned char ADIF:1;
    unsigned char EEIF:1;
  };
  struct {
    unsigned char TMR1IF:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __PIR1_bits_t;
extern volatile __PIR1_bits_t __at(PIR1_ADDR) PIR1_bits;

#define T1IF                 PIR1_bits.T1IF
#define TMR1IF               PIR1_bits.TMR1IF
#define TXIF                 PIR1_bits.TXIF
#define OSFIF                PIR1_bits.OSFIF
#define C1IF                 PIR1_bits.C1IF
#define C2IF                 PIR1_bits.C2IF
#define RCIF                 PIR1_bits.RCIF
#define ADIF                 PIR1_bits.ADIF
#define EEIF                 PIR1_bits.EEIF

// ----- RCSTA bits --------------------
typedef union {
  struct {
    unsigned char RX9D:1;
    unsigned char OERR:1;
    unsigned char FERR:1;
    unsigned char ADDEN:1;
    unsigned char CREN:1;
    unsigned char SREN:1;
    unsigned char RX9:1;
    unsigned char SPEN:1;
  };
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
} __RCSTA_bits_t;
extern volatile __RCSTA_bits_t __at(RCSTA_ADDR) RCSTA_bits;

#define RX9D                 RCSTA_bits.RX9D
#define SWDTEN               RCSTA_bits.SWDTEN
#define OERR                 RCSTA_bits.OERR
#define WDTPS0               RCSTA_bits.WDTPS0
#define FERR                 RCSTA_bits.FERR
#define WDTPS1               RCSTA_bits.WDTPS1
#define ADDEN                RCSTA_bits.ADDEN
#define WDTPS2               RCSTA_bits.WDTPS2
#define CREN                 RCSTA_bits.CREN
#define WDTPS3               RCSTA_bits.WDTPS3
#define SREN                 RCSTA_bits.SREN
#define RX9                  RCSTA_bits.RX9
#define SPEN                 RCSTA_bits.SPEN

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

#define C                    STATUS_bits.C
#define DC                   STATUS_bits.DC
#define Z                    STATUS_bits.Z
#define NOT_PD               STATUS_bits.NOT_PD
#define NOT_TO               STATUS_bits.NOT_TO
#define RP0                  STATUS_bits.RP0
#define RP1                  STATUS_bits.RP1
#define IRP                  STATUS_bits.IRP

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
} __T1CON_bits_t;
extern volatile __T1CON_bits_t __at(T1CON_ADDR) T1CON_bits;

#define TMR1ON               T1CON_bits.TMR1ON
#define TMR1CS               T1CON_bits.TMR1CS
#define NOT_T1SYNC           T1CON_bits.NOT_T1SYNC
#define T1OSCEN              T1CON_bits.T1OSCEN
#define T1CKPS0              T1CON_bits.T1CKPS0
#define T1CKPS1              T1CON_bits.T1CKPS1
#define TMR1GE               T1CON_bits.TMR1GE
#define T1GINV               T1CON_bits.T1GINV

// ----- TXSTA bits --------------------
typedef union {
  struct {
    unsigned char TX9D:1;
    unsigned char TRMT:1;
    unsigned char BRGH:1;
    unsigned char SENDB:1;
    unsigned char SYNC:1;
    unsigned char TXEN:1;
    unsigned char TX9:1;
    unsigned char CSRC:1;
  };
} __TXSTA_bits_t;
extern volatile __TXSTA_bits_t __at(TXSTA_ADDR) TXSTA_bits;

#define TX9D                 TXSTA_bits.TX9D
#define TRMT                 TXSTA_bits.TRMT
#define BRGH                 TXSTA_bits.BRGH
#define SENDB                TXSTA_bits.SENDB
#define SYNC                 TXSTA_bits.SYNC
#define TXEN                 TXSTA_bits.TXEN
#define TX9                  TXSTA_bits.TX9
#define CSRC                 TXSTA_bits.CSRC

// ----- VRCON bits --------------------
typedef union {
  struct {
    unsigned char VR0:1;
    unsigned char VR1:1;
    unsigned char VR2:1;
    unsigned char VR3:1;
    unsigned char ADCS0:1;
    unsigned char VRR:1;
    unsigned char ADCS2:1;
    unsigned char VREN:1;
  };
  struct {
    unsigned char RD:1;
    unsigned char WR:1;
    unsigned char WREN:1;
    unsigned char WRERR:1;
    unsigned char :1;
    unsigned char ADCS1:1;
    unsigned char :1;
    unsigned char EEPGD:1;
  };
} __VRCON_bits_t;
extern volatile __VRCON_bits_t __at(VRCON_ADDR) VRCON_bits;

#define VR0                  VRCON_bits.VR0
#define RD                   VRCON_bits.RD
#define VR1                  VRCON_bits.VR1
#define WR                   VRCON_bits.WR
#define VR2                  VRCON_bits.VR2
#define WREN                 VRCON_bits.WREN
#define VR3                  VRCON_bits.VR3
#define WRERR                VRCON_bits.WRERR
#define ADCS0                VRCON_bits.ADCS0
#define VRR                  VRCON_bits.VRR
#define ADCS1                VRCON_bits.ADCS1
#define ADCS2                VRCON_bits.ADCS2
#define VREN                 VRCON_bits.VREN
#define EEPGD                VRCON_bits.EEPGD

#endif