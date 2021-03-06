//
// Register Declarations for Microchip 16F627A Processor
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
#ifndef P16F627A_H
#define P16F627A_H

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
#define PCLATH_ADDR	0x000A
#define INTCON_ADDR	0x000B
#define PIR1_ADDR	0x000C
#define TMR1L_ADDR	0x000E
#define TMR1H_ADDR	0x000F
#define T1CON_ADDR	0x0010
#define TMR2_ADDR	0x0011
#define T2CON_ADDR	0x0012
#define CCPR1L_ADDR	0x0015
#define CCPR1H_ADDR	0x0016
#define CCP1CON_ADDR	0x0017
#define RCSTA_ADDR	0x0018
#define TXREG_ADDR	0x0019
#define RCREG_ADDR	0x001A
#define CMCON_ADDR	0x001F
#define OPTION_REG_ADDR	0x0081
#define TRISA_ADDR	0x0085
#define TRISB_ADDR	0x0086
#define PIE1_ADDR	0x008C
#define PCON_ADDR	0x008E
#define PR2_ADDR	0x0092
#define TXSTA_ADDR	0x0098
#define SPBRG_ADDR	0x0099
#define EEDATA_ADDR	0x009A
#define EEADR_ADDR	0x009B
#define EECON1_ADDR	0x009C
#define EECON2_ADDR	0x009D
#define VRCON_ADDR	0x009F

//
// Memory organization.
//

#pragma memmap INDF_ADDR INDF_ADDR SFR 0x000	// INDF
#pragma memmap TMR0_ADDR TMR0_ADDR SFR 0x000	// TMR0
#pragma memmap PCL_ADDR PCL_ADDR SFR 0x000	// PCL
#pragma memmap STATUS_ADDR STATUS_ADDR SFR 0x000	// STATUS
#pragma memmap FSR_ADDR FSR_ADDR SFR 0x000	// FSR
#pragma memmap PORTA_ADDR PORTA_ADDR SFR 0x000	// PORTA
#pragma memmap PORTB_ADDR PORTB_ADDR SFR 0x000	// PORTB
#pragma memmap PCLATH_ADDR PCLATH_ADDR SFR 0x000	// PCLATH
#pragma memmap INTCON_ADDR INTCON_ADDR SFR 0x000	// INTCON
#pragma memmap PIR1_ADDR PIR1_ADDR SFR 0x000	// PIR1
#pragma memmap TMR1L_ADDR TMR1L_ADDR SFR 0x000	// TMR1L
#pragma memmap TMR1H_ADDR TMR1H_ADDR SFR 0x000	// TMR1H
#pragma memmap T1CON_ADDR T1CON_ADDR SFR 0x000	// T1CON
#pragma memmap TMR2_ADDR TMR2_ADDR SFR 0x000	// TMR2
#pragma memmap T2CON_ADDR T2CON_ADDR SFR 0x000	// T2CON
#pragma memmap CCPR1L_ADDR CCPR1L_ADDR SFR 0x000	// CCPR1L
#pragma memmap CCPR1H_ADDR CCPR1H_ADDR SFR 0x000	// CCPR1H
#pragma memmap CCP1CON_ADDR CCP1CON_ADDR SFR 0x000	// CCP1CON
#pragma memmap RCSTA_ADDR RCSTA_ADDR SFR 0x000	// RCSTA
#pragma memmap TXREG_ADDR TXREG_ADDR SFR 0x000	// TXREG
#pragma memmap RCREG_ADDR RCREG_ADDR SFR 0x000	// RCREG
#pragma memmap CMCON_ADDR CMCON_ADDR SFR 0x000	// CMCON
#pragma memmap OPTION_REG_ADDR OPTION_REG_ADDR SFR 0x000	// OPTION_REG
#pragma memmap TRISA_ADDR TRISA_ADDR SFR 0x000	// TRISA
#pragma memmap TRISB_ADDR TRISB_ADDR SFR 0x000	// TRISB
#pragma memmap PIE1_ADDR PIE1_ADDR SFR 0x000	// PIE1
#pragma memmap PCON_ADDR PCON_ADDR SFR 0x000	// PCON
#pragma memmap PR2_ADDR PR2_ADDR SFR 0x000	// PR2
#pragma memmap TXSTA_ADDR TXSTA_ADDR SFR 0x000	// TXSTA
#pragma memmap SPBRG_ADDR SPBRG_ADDR SFR 0x000	// SPBRG
#pragma memmap EEDATA_ADDR EEDATA_ADDR SFR 0x000	// EEDATA
#pragma memmap EEADR_ADDR EEADR_ADDR SFR 0x000	// EEADR
#pragma memmap EECON1_ADDR EECON1_ADDR SFR 0x000	// EECON1
#pragma memmap EECON2_ADDR EECON2_ADDR SFR 0x000	// EECON2
#pragma memmap VRCON_ADDR VRCON_ADDR SFR 0x000	// VRCON


//         LIST
// P16F627A.INC  Standard Header File, Version 1.10    Microchip Technology, Inc.
//         NOLIST

// This header file defines configurations, registers, and other useful bits of
// information for the PIC16F627A microcontroller.  These names are taken to match
// the data sheets as closely as possible.

// Note that the processor must be selected before this file is
// included.  The processor may be selected the following ways:

//       1. Command line switch:
//               C:\ MPASM MYFILE.ASM /PIC16F627A
//       2. LIST directive in the source file
//               LIST   P=PIC16F627A
//       3. Processor Type entry in the MPASM full-screen interface

//==========================================================================
//
//       Revision History
//
//==========================================================================

//Rev:   Date:    Reason:
//1.01   14 Nov 2002 Updated to reflect BOD terminology changed to BOR
//1.00   22 Aug 2002 Initial Release

//==========================================================================
//
//       Verify Processor
//
//==========================================================================

//        IFNDEF __16F627A
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
extern __sfr  __at (PORTB_ADDR)                   PORTB;
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
extern __sfr  __at (RCSTA_ADDR)                   RCSTA;
extern __sfr  __at (TXREG_ADDR)                   TXREG;
extern __sfr  __at (RCREG_ADDR)                   RCREG;
extern __sfr  __at (CMCON_ADDR)                   CMCON;

extern __sfr  __at (OPTION_REG_ADDR)              OPTION_REG;
extern __sfr  __at (TRISA_ADDR)                   TRISA;
extern __sfr  __at (TRISB_ADDR)                   TRISB;
extern __sfr  __at (PIE1_ADDR)                    PIE1;
extern __sfr  __at (PCON_ADDR)                    PCON;
extern __sfr  __at (PR2_ADDR)                     PR2;
extern __sfr  __at (TXSTA_ADDR)                   TXSTA;
extern __sfr  __at (SPBRG_ADDR)                   SPBRG;
extern __sfr  __at (EEDATA_ADDR)                  EEDATA;
extern __sfr  __at (EEADR_ADDR)                   EEADR;
extern __sfr  __at (EECON1_ADDR)                  EECON1;
extern __sfr  __at (EECON2_ADDR)                  EECON2;
extern __sfr  __at (VRCON_ADDR)                   VRCON;

//----- STATUS Bits --------------------------------------------------------


//----- INTCON Bits --------------------------------------------------------


//----- PIR1 Bits ----------------------------------------------------------


//----- T1CON Bits ---------------------------------------------------------

//----- T2CON Bits ---------------------------------------------------------

//----- CCP1CON Bits ---------------------------------------------------------

//----- RCSTA Bits ---------------------------------------------------------

//----- CMCON Bits ---------------------------------------------------------


//----- OPTION Bits --------------------------------------------------------


//----- PIE1 Bits ----------------------------------------------------------


//----- PCON Bits ----------------------------------------------------------


//----- TXSTA Bits ----------------------------------------------------------

//----- EECON1 Bits ---------------------------------------------------------

//----- VRCON Bits ---------------------------------------------------------


//==========================================================================
//
//       RAM Definition
//
//==========================================================================

//     __MAXRAM H'01FF'
//     __BADRAM H'07'-H'09', H'0D', H'13'-H'14', H'1B'-H'1E'
//     __BADRAM H'87'-H'89', H'8D', H'8F'-H'91', H'93'-H'97', H'9E'
//     __BADRAM H'105', H'107'-H'109', H'10C'-H'11F', H'150'-H'16F'
//     __BADRAM H'185', H'187'-H'189', H'18C'-H'1EF'

//==========================================================================
//
//       Configuration Bits
//
//==========================================================================

#define _BODEN_ON            0x3FFF //Backwards compatability to 16F62X
#define _BODEN_OFF           0x3FBF //Backwards compatability to 16F62X
#define _BOREN_ON            0x3FFF
#define _BOREN_OFF           0x3FBF
#define _CP_ON               0x1FFF
#define _CP_OFF              0x3FFF
#define _DATA_CP_ON          0x3EFF
#define _DATA_CP_OFF         0x3FFF
#define _PWRTE_OFF           0x3FFF
#define _PWRTE_ON            0x3FF7
#define _WDT_ON              0x3FFF
#define _WDT_OFF             0x3FFB
#define _LVP_ON              0x3FFF
#define _LVP_OFF             0x3F7F
#define _MCLRE_ON            0x3FFF
#define _MCLRE_OFF           0x3FDF
#define _RC_OSC_CLKOUT       0x3FFF
#define _RC_OSC_NOCLKOUT     0x3FFE
#define _ER_OSC_CLKOUT       0x3FFF //Backwards compatability to 16F62X
#define _ER_OSC_NOCLKOUT     0x3FFE //Backwards compatability to 16F62X
#define _INTOSC_OSC_CLKOUT   0x3FFD
#define _INTOSC_OSC_NOCLKOUT 0x3FFC    
#define _INTRC_OSC_CLKOUT    0x3FFD //Backwards compatability to 16F62X
#define _INTRC_OSC_NOCLKOUT  0x3FFC //Backwards compatability to 16F62X
#define _EXTCLK_OSC          0x3FEF
#define _HS_OSC              0x3FEE
#define _XT_OSC              0x3FED
#define _LP_OSC              0x3FEC

//         LIST

// ----- CCP1CON bits --------------------
typedef union {
  struct {
    unsigned char CCP1M0:1;
    unsigned char CCP1M1:1;
    unsigned char CCP1M2:1;
    unsigned char CCP1M3:1;
    unsigned char CCP1Y:1;
    unsigned char CCP1X:1;
    unsigned char :1;
    unsigned char :1;
  };
} __CCP1CON_bits_t;
extern volatile __CCP1CON_bits_t __at(CCP1CON_ADDR) CCP1CON_bits;

#define CCP1M0               CCP1CON_bits.CCP1M0
#define CCP1M1               CCP1CON_bits.CCP1M1
#define CCP1M2               CCP1CON_bits.CCP1M2
#define CCP1M3               CCP1CON_bits.CCP1M3
#define CCP1Y                CCP1CON_bits.CCP1Y
#define CCP1X                CCP1CON_bits.CCP1X

// ----- CMCON bits --------------------
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
} __CMCON_bits_t;
extern volatile __CMCON_bits_t __at(CMCON_ADDR) CMCON_bits;

#define CM0                  CMCON_bits.CM0
#define CM1                  CMCON_bits.CM1
#define CM2                  CMCON_bits.CM2
#define CIS                  CMCON_bits.CIS
#define C1INV                CMCON_bits.C1INV
#define C2INV                CMCON_bits.C2INV
#define C1OUT                CMCON_bits.C1OUT
#define C2OUT                CMCON_bits.C2OUT

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

#define RD                   EECON1_bits.RD
#define WR                   EECON1_bits.WR
#define WREN                 EECON1_bits.WREN
#define WRERR                EECON1_bits.WRERR

// ----- INTCON bits --------------------
typedef union {
  struct {
    unsigned char RBIF:1;
    unsigned char INTF:1;
    unsigned char T0IF:1;
    unsigned char RBIE:1;
    unsigned char INTE:1;
    unsigned char T0IE:1;
    unsigned char PEIE:1;
    unsigned char GIE:1;
  };
} __INTCON_bits_t;
extern volatile __INTCON_bits_t __at(INTCON_ADDR) INTCON_bits;

#define RBIF                 INTCON_bits.RBIF
#define INTF                 INTCON_bits.INTF
#define T0IF                 INTCON_bits.T0IF
#define RBIE                 INTCON_bits.RBIE
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
    unsigned char NOT_RBPU:1;
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
#define NOT_RBPU             OPTION_REG_bits.NOT_RBPU

// ----- PCON bits --------------------
typedef union {
  struct {
    unsigned char NOT_BO:1;
    unsigned char NOT_POR:1;
    unsigned char :1;
    unsigned char OSCF:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
  struct {
    unsigned char NOT_BOR:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
  struct {
    unsigned char NOT_BOD:1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
    unsigned char :1;
  };
} __PCON_bits_t;
extern volatile __PCON_bits_t __at(PCON_ADDR) PCON_bits;

#define NOT_BO               PCON_bits.NOT_BO
#define NOT_BOR              PCON_bits.NOT_BOR
#define NOT_BOD              PCON_bits.NOT_BOD
#define NOT_POR              PCON_bits.NOT_POR
#define OSCF                 PCON_bits.OSCF

// ----- PIE1 bits --------------------
typedef union {
  struct {
    unsigned char TMR1IE:1;
    unsigned char TMR2IE:1;
    unsigned char CCP1IE:1;
    unsigned char :1;
    unsigned char TXIE:1;
    unsigned char RCIE:1;
    unsigned char CMIE:1;
    unsigned char EEIE:1;
  };
} __PIE1_bits_t;
extern volatile __PIE1_bits_t __at(PIE1_ADDR) PIE1_bits;

#define TMR1IE               PIE1_bits.TMR1IE
#define TMR2IE               PIE1_bits.TMR2IE
#define CCP1IE               PIE1_bits.CCP1IE
#define TXIE                 PIE1_bits.TXIE
#define RCIE                 PIE1_bits.RCIE
#define CMIE                 PIE1_bits.CMIE
#define EEIE                 PIE1_bits.EEIE

// ----- PIR1 bits --------------------
typedef union {
  struct {
    unsigned char TMR1IF:1;
    unsigned char TMR2IF:1;
    unsigned char CCP1IF:1;
    unsigned char :1;
    unsigned char TXIF:1;
    unsigned char RCIF:1;
    unsigned char CMIF:1;
    unsigned char EEIF:1;
  };
} __PIR1_bits_t;
extern volatile __PIR1_bits_t __at(PIR1_ADDR) PIR1_bits;

#define TMR1IF               PIR1_bits.TMR1IF
#define TMR2IF               PIR1_bits.TMR2IF
#define CCP1IF               PIR1_bits.CCP1IF
#define TXIF                 PIR1_bits.TXIF
#define RCIF                 PIR1_bits.RCIF
#define CMIF                 PIR1_bits.CMIF
#define EEIF                 PIR1_bits.EEIF

// ----- RCSTA bits --------------------
typedef union {
  struct {
    unsigned char RX9D:1;
    unsigned char OERR:1;
    unsigned char FERR:1;
    unsigned char ADEN:1;
    unsigned char CREN:1;
    unsigned char SREN:1;
    unsigned char RX9:1;
    unsigned char SPEN:1;
  };
} __RCSTA_bits_t;
extern volatile __RCSTA_bits_t __at(RCSTA_ADDR) RCSTA_bits;

#define RX9D                 RCSTA_bits.RX9D
#define OERR                 RCSTA_bits.OERR
#define FERR                 RCSTA_bits.FERR
#define ADEN                 RCSTA_bits.ADEN
#define CREN                 RCSTA_bits.CREN
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
    unsigned char :1;
    unsigned char :1;
  };
} __T1CON_bits_t;
extern volatile __T1CON_bits_t __at(T1CON_ADDR) T1CON_bits;

#define TMR1ON               T1CON_bits.TMR1ON
#define TMR1CS               T1CON_bits.TMR1CS
#define NOT_T1SYNC           T1CON_bits.NOT_T1SYNC
#define T1OSCEN              T1CON_bits.T1OSCEN
#define T1CKPS0              T1CON_bits.T1CKPS0
#define T1CKPS1              T1CON_bits.T1CKPS1

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

#define T2CKPS0              T2CON_bits.T2CKPS0
#define T2CKPS1              T2CON_bits.T2CKPS1
#define TMR2ON               T2CON_bits.TMR2ON
#define TOUTPS0              T2CON_bits.TOUTPS0
#define TOUTPS1              T2CON_bits.TOUTPS1
#define TOUTPS2              T2CON_bits.TOUTPS2
#define TOUTPS3              T2CON_bits.TOUTPS3

// ----- TXSTA bits --------------------
typedef union {
  struct {
    unsigned char TX9D:1;
    unsigned char TRMT:1;
    unsigned char BRGH:1;
    unsigned char :1;
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
    unsigned char :1;
    unsigned char VRR:1;
    unsigned char VROE:1;
    unsigned char VREN:1;
  };
} __VRCON_bits_t;
extern volatile __VRCON_bits_t __at(VRCON_ADDR) VRCON_bits;

#define VR0                  VRCON_bits.VR0
#define VR1                  VRCON_bits.VR1
#define VR2                  VRCON_bits.VR2
#define VR3                  VRCON_bits.VR3
#define VRR                  VRCON_bits.VRR
#define VROE                 VRCON_bits.VROE
#define VREN                 VRCON_bits.VREN

#endif
