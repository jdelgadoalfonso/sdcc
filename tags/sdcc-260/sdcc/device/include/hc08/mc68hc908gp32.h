/*-------------------------------------------------------------------------
  Register Declarations for Motorola MC68HC908GP32

  Copyright (c) 2004, Juan Gonzalez <juan@iearobotics.com>

  Based on mc68hc908qy.h,
   Written By - Erik Petrich
    epetrich@users.sourceforge.net (2003)

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 2, or (at your option) any
   later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

   In other words, you are welcome to use, share and improve this program.
   You are forbidden to forbid anyone else to use, share and improve
   what you give them.   Help stamp out software-hoarding!
-------------------------------------------------------------------------*/

#ifndef _MC68HC908GP32_H
#define _MC68HC908GP32_H

#ifndef _UINT8
 #define _UINT8 unsigned char
#endif
#ifndef _UINT16
 #define _UINT16 unsigned int
#endif
#ifndef _VOLDATA
 #define _VOLDATA volatile __data
#endif
#ifndef _VOLXDATA
 #define _VOLXDATA volatile __xdata
#endif

struct __hc08_bits
{
  unsigned int bit0:1;
  unsigned int bit1:1;
  unsigned int bit2:1;
  unsigned int bit3:1;
  unsigned int bit4:1;
  unsigned int bit5:1;
  unsigned int bit6:1;
  unsigned int bit7:1;
};


_VOLDATA _UINT8 __at 0x00 PTA;     /* Port A Data Register */
#define PORTA PTA		 /* Alias for PTA        */
  #define PTA0 ((struct __hc08_bits *)(&PTA))->bit0
  #define PTA1 ((struct __hc08_bits *)(&PTA))->bit1
  #define PTA2 ((struct __hc08_bits *)(&PTA))->bit2
  #define PTA3 ((struct __hc08_bits *)(&PTA))->bit3
  #define PTA4 ((struct __hc08_bits *)(&PTA))->bit4
  #define PTA5 ((struct __hc08_bits *)(&PTA))->bit5
  #define PTA6 ((struct __hc08_bits *)(&PTA))->bit6
  #define PTA7 ((struct __hc08_bits *)(&PTA))->bit7

_VOLDATA _UINT8 __at 0x01 PTB;     /* Port B Data Register */
#define PORTB PTB              /* Alias for PTB        */
  #define PTB0 ((struct __hc08_bits *)(&PTB))->bit0
  #define PTB1 ((struct __hc08_bits *)(&PTB))->bit1
  #define PTB2 ((struct __hc08_bits *)(&PTB))->bit2
  #define PTB3 ((struct __hc08_bits *)(&PTB))->bit3
  #define PTB4 ((struct __hc08_bits *)(&PTB))->bit4
  #define PTB5 ((struct __hc08_bits *)(&PTB))->bit5
  #define PTB6 ((struct __hc08_bits *)(&PTB))->bit6
  #define PTB7 ((struct __hc08_bits *)(&PTB))->bit7

_VOLDATA _UINT8 __at 0x02 PTC;     /* Port C Data Register */
#define PORTC PTC              /* Alias for PTC        */
  #define PTC0 ((struct __hc08_bits *)(&PTC))->bit0
  #define PTC1 ((struct __hc08_bits *)(&PTC))->bit1
  #define PTC2 ((struct __hc08_bits *)(&PTC))->bit2
  #define PTC3 ((struct __hc08_bits *)(&PTC))->bit3
  #define PTC4 ((struct __hc08_bits *)(&PTC))->bit4
  #define PTC5 ((struct __hc08_bits *)(&PTC))->bit5
  #define PTC6 ((struct __hc08_bits *)(&PTC))->bit6
  #define PTC7 ((struct __hc08_bits *)(&PTC))->bit7

_VOLDATA _UINT8 __at 0x03 PTD;     /* Port D Data Register */
#define PORTD PTD              /* Alias for PTD        */
  #define PTD0 ((struct __hc08_bits *)(&PTD))->bit0
  #define PTD1 ((struct __hc08_bits *)(&PTD))->bit1
  #define PTD2 ((struct __hc08_bits *)(&PTD))->bit2
  #define PTD3 ((struct __hc08_bits *)(&PTD))->bit3
  #define PTD4 ((struct __hc08_bits *)(&PTD))->bit4
  #define PTD5 ((struct __hc08_bits *)(&PTD))->bit5
  #define PTD6 ((struct __hc08_bits *)(&PTD))->bit6
  #define PTD7 ((struct __hc08_bits *)(&PTD))->bit7

_VOLDATA _UINT8 __at 0x04 DDRA;    /* Data Direction Register A */
  #define DDRA0 ((struct __hc08_bits *)(&DDRA))->bit0
  #define DDRA1 ((struct __hc08_bits *)(&DDRA))->bit1
  #define DDRA2 ((struct __hc08_bits *)(&DDRA))->bit2
  #define DDRA3 ((struct __hc08_bits *)(&DDRA))->bit3
  #define DDRA4 ((struct __hc08_bits *)(&DDRA))->bit4
  #define DDRA5 ((struct __hc08_bits *)(&DDRA))->bit5
  #define DDRA6 ((struct __hc08_bits *)(&DDRA))->bit6
  #define DDRA7 ((struct __hc08_bits *)(&DDRA))->bit7

_VOLDATA _UINT8 __at 0x05 DDRB;    /* Data Direction Register B */
  #define DDRB0 ((struct __hc08_bits *)(&DDRB))->bit0
  #define DDRB1 ((struct __hc08_bits *)(&DDRB))->bit1
  #define DDRB2 ((struct __hc08_bits *)(&DDRB))->bit2
  #define DDRB3 ((struct __hc08_bits *)(&DDRB))->bit3
  #define DDRB4 ((struct __hc08_bits *)(&DDRB))->bit4
  #define DDRB5 ((struct __hc08_bits *)(&DDRB))->bit5
  #define DDRB6 ((struct __hc08_bits *)(&DDRB))->bit6
  #define DDRB7 ((struct __hc08_bits *)(&DDRB))->bit7

_VOLDATA _UINT8 __at 0x06 DDRC;    /* Data Direction Register C */
  #define DDRC0 ((struct __hc08_bits *)(&DDRC))->bit0
  #define DDRC1 ((struct __hc08_bits *)(&DDRC))->bit1
  #define DDRC2 ((struct __hc08_bits *)(&DDRC))->bit2
  #define DDRC3 ((struct __hc08_bits *)(&DDRC))->bit3
  #define DDRC4 ((struct __hc08_bits *)(&DDRC))->bit4
  #define DDRC5 ((struct __hc08_bits *)(&DDRC))->bit5
  #define DDRC6 ((struct __hc08_bits *)(&DDRC))->bit6
  #define DDRC7 ((struct __hc08_bits *)(&DDRC))->bit7

_VOLDATA _UINT8 __at 0x07 DDRD;    /* Data Direction Register D */
  #define DDRD0 ((struct __hc08_bits *)(&DDRD))->bit0
  #define DDRD1 ((struct __hc08_bits *)(&DDRD))->bit1
  #define DDRD2 ((struct __hc08_bits *)(&DDRD))->bit2
  #define DDRD3 ((struct __hc08_bits *)(&DDRD))->bit3
  #define DDRD4 ((struct __hc08_bits *)(&DDRD))->bit4
  #define DDRD5 ((struct __hc08_bits *)(&DDRD))->bit5
  #define DDRD6 ((struct __hc08_bits *)(&DDRD))->bit6
  #define DDRD7 ((struct __hc08_bits *)(&DDRD))->bit7

_VOLDATA _UINT8 __at 0x08 PTE;     /* Port E Data Register */
#define PORTE PTE              /* Alias for PTE        */
  #define PTE0 ((struct __hc08_bits *)(&PTE))->bit0
  #define PTE1 ((struct __hc08_bits *)(&PTE))->bit1
  #define PTE2 ((struct __hc08_bits *)(&PTE))->bit2
  #define PTE3 ((struct __hc08_bits *)(&PTE))->bit3
  #define PTE4 ((struct __hc08_bits *)(&PTE))->bit4
  #define PTE5 ((struct __hc08_bits *)(&PTE))->bit5
  #define PTE6 ((struct __hc08_bits *)(&PTE))->bit6
  #define PTE7 ((struct __hc08_bits *)(&PTE))->bit7

_VOLDATA _UINT8 __at 0x0C DDRE;    /* Data Direction Register E */
  #define DDRE0 ((struct __hc08_bits *)(&DDRE))->bit0
  #define DDRE1 ((struct __hc08_bits *)(&DDRE))->bit1
  #define DDRE2 ((struct __hc08_bits *)(&DDRE))->bit2
  #define DDRE3 ((struct __hc08_bits *)(&DDRE))->bit3
  #define DDRE4 ((struct __hc08_bits *)(&DDRE))->bit4
  #define DDRE5 ((struct __hc08_bits *)(&DDRE))->bit5
  #define DDRE6 ((struct __hc08_bits *)(&DDRE))->bit6
  #define DDRE7 ((struct __hc08_bits *)(&DDRE))->bit7

_VOLDATA _UINT8 __at 0x0D PTAPUE;  /* Port A pull-up enables */
	#define PTAPUE0 ((struct __hc08_bits *)(&PTAPUE))->bit0
	#define PTAPUE1 ((struct __hc08_bits *)(&PTAPUE))->bit1
	#define PTAPUE2 ((struct __hc08_bits *)(&PTAPUE))->bit2
	#define PTAPUE3 ((struct __hc08_bits *)(&PTAPUE))->bit3
  #define PTAPUE4 ((struct __hc08_bits *)(&PTAPUE))->bit4
	#define PTAPUE5 ((struct __hc08_bits *)(&PTAPUE))->bit5
	#define PTAPUE6 ((struct __hc08_bits *)(&PTAPUE))->bit6
	#define PTAPUE7 ((struct __hc08_bits *)(&PTAPUE))->bit7

_VOLDATA _UINT8 __at 0x0E PTCPUE;	 /* Port C pull-up enables */
	#define PTCPUE0 ((struct __hc08_bits *)(&PTCPUE))->bit0
	#define PTCPUE1 ((struct __hc08_bits *)(&PTCPUE))->bit1
	#define PTCPUE2 ((struct __hc08_bits *)(&PTCPUE))->bit2
	#define PTCPUE3 ((struct __hc08_bits *)(&PTCPUE))->bit3
	#define PTCPUE4 ((struct __hc08_bits *)(&PTCPUE))->bit4
	#define PTCPUE5 ((struct __hc08_bits *)(&PTCPUE))->bit5
	#define PTCPUE6 ((struct __hc08_bits *)(&PTCPUE))->bit6
	/* PTCPUE7 does not exit! */

_VOLDATA _UINT8 __at 0x0F PTDPUE;  /* port D pull-up enables */
	#define PTDPUE0 ((struct __hc08_bits *)(&PTDPUE))->bit0
	#define PTDPUE1 ((struct __hc08_bits *)(&PTDPUE))->bit1
  #define PTDPUE2 ((struct __hc08_bits *)(&PTDPUE))->bit2
	#define PTDPUE3 ((struct __hc08_bits *)(&PTDPUE))->bit3
	#define PTDPUE4 ((struct __hc08_bits *)(&PTDPUE))->bit4
	#define PTDPUE5 ((struct __hc08_bits *)(&PTDPUE))->bit5
  #define PTDPUE6 ((struct __hc08_bits *)(&PTDPUE))->bit6
	#define PTDPUE7 ((struct __hc08_bits *)(&PTDPUE))->bit7

_VOLDATA _UINT8 __at 0x10 SPCR;   /* SPI Control Register */
	#define SPRIE  ((struct __hc08_bits *)(&SPCR))->bit7
	#define DMAS   ((struct __hc08_bits *)(&SPCR))->bit6
	#define SPMSTR ((struct __hc08_bits *)(&SPCR))->bit5
	#define CPOL   ((struct __hc08_bits *)(&SPCR))->bit4
	#define CPHA   ((struct __hc08_bits *)(&SPCR))->bit3
  #define SPWOM  ((struct __hc08_bits *)(&SPCR))->bit2
	#define SPE    ((struct __hc08_bits *)(&SPCR))->bit1
  #define SPTIE  ((struct __hc08_bits *)(&SPCR))->bit0

_VOLDATA _UINT8 __at 0x11 SPSCR;  /* SPI Status and Control Register */
	#define SPRF   ((struct __hc08_bits *)(&SPSCR))->bit7
	#define ERRIE  ((struct __hc08_bits *)(&SPSCR))->bit6
	#define OVRF   ((struct __hc08_bits *)(&SPSCR))->bit5
	#define MODF   ((struct __hc08_bits *)(&SPSCR))->bit4
	#define SPTE   ((struct __hc08_bits *)(&SPSCR))->bit3
	#define MODFEN ((struct __hc08_bits *)(&SPSCR))->bit2
	#define SPR1   ((struct __hc08_bits *)(&SPSCR))->bit1
	#define SPR0   ((struct __hc08_bits *)(&SPSCR))->bit0

_VOLDATA _UINT8 __at 0x12 SPDR;   /* SPI Data Register */

_VOLDATA _UINT8 __at 0x13 SCC1;  /* SCI Control Register 1 */
	#define LOOPS  ((struct __hc08_bits *)(&SCC1))->bit7
  #define ENSCI  ((struct __hc08_bits *)(&SCC1))->bit6
	#define TXINV  ((struct __hc08_bits *)(&SCC1))->bit5
  #define M      ((struct __hc08_bits *)(&SCC1))->bit4
	#define WAKE   ((struct __hc08_bits *)(&SCC1))->bit3
  #define ILTY   ((struct __hc08_bits *)(&SCC1))->bit2
	#define PEN    ((struct __hc08_bits *)(&SCC1))->bit1
  #define PTY    ((struct __hc08_bits *)(&SCC1))->bit0


_VOLDATA _UINT8 __at 0x14 SCC2;  /* SCI Control Register 2 */
	#define SCTIE  ((struct __hc08_bits *)(&SCC2))->bit7
	#define TCIE   ((struct __hc08_bits *)(&SCC2))->bit6
	#define SCRIE  ((struct __hc08_bits *)(&SCC2))->bit5
	#define ILIE   ((struct __hc08_bits *)(&SCC2))->bit4
	#define TE     ((struct __hc08_bits *)(&SCC2))->bit3
	#define RE     ((struct __hc08_bits *)(&SCC2))->bit2
	#define WRU    ((struct __hc08_bits *)(&SCC2))->bit1
	#define SBK    ((struct __hc08_bits *)(&SCC2))->bit0

_VOLDATA _UINT8 __at 0x15 SCC3;  /* SCI Control Register 3 */
	#define SCC3_R8 ((struct __hc08_bits *)(&SCC3))->bit7
	#define SCC3_TB ((struct __hc08_bits *)(&SCC3))->bit6
  #define DMARE   ((struct __hc08_bits *)(&SCC3))->bit5
	#define DMATE   ((struct __hc08_bits *)(&SCC3))->bit4
	#define ORIE    ((struct __hc08_bits *)(&SCC3))->bit3
	#define NEIE    ((struct __hc08_bits *)(&SCC3))->bit2
  #define FEIE    ((struct __hc08_bits *)(&SCC3))->bit1
	#define PEIE    ((struct __hc08_bits *)(&SCC3))->bit0

_VOLDATA _UINT8 __at 0x16 SCS1;  /* SCI Status Register 1 */
	#define SCTE  ((struct __hc08_bits *)(&SCS1))->bit7
	#define TC    ((struct __hc08_bits *)(&SCS1))->bit6
	#define SCRF  ((struct __hc08_bits *)(&SCS1))->bit5
	#define IDLE  ((struct __hc08_bits *)(&SCS1))->bit4
	#define OR    ((struct __hc08_bits *)(&SCS1))->bit3
	#define NF    ((struct __hc08_bits *)(&SCS1))->bit2
	#define FE    ((struct __hc08_bits *)(&SCS1))->bit1
	#define PE    ((struct __hc08_bits *)(&SCS1))->bit0

_VOLDATA _UINT8 __at 0x17 SCS2;  /* SCI Status Register 2 */
	#define RPF  ((struct __hc08_bits *)(&SCS2))->bit0
	#define BKF  ((struct __hc08_bits *)(&SCS2))->bit1
  /*  Bits 2-7 not implemented	*/

_VOLDATA _UINT8 __at 0x18 SCDR;  /* SCI Data Register */

_VOLDATA _UINT8 __at 0x19 SCBR;  /* SCI Baud Rate Register */
	#define SCP1  ((struct __hc08_bits *)(&SCBR))->bit5
	#define SCP0  ((struct __hc08_bits *)(&SCBR))->bit4
  #define R     ((struct __hc08_bits *)(&SCBR))->bit3
  #define SCR2  ((struct __hc08_bits *)(&SCBR))->bit2
  #define SCR1  ((struct __hc08_bits *)(&SCBR))->bit1
  #define SCR0  ((struct __hc08_bits *)(&SCBR))->bit0
	/*-- Bits 6 and 7 do not exist */

_VOLDATA _UINT8 __at 0x1a INTKBSCR; /* Keyboard Status and Control Register */
	#define KEYF   ((struct __hc08_bits *)(&INTKBSCR))->bit3
	#define ACKK   ((struct __hc08_bits *)(&INTKBSCR))->bit2
	#define IMASKK ((struct __hc08_bits *)(&INTKBSCR))->bit1
	#define MODEK  ((struct __hc08_bits *)(&INTKBSCR))->bit0
	/*-- Bits 4-7 do not exist  */

_VOLDATA _UINT8 __at 0x1b INTKBIER; /* Keyboard Interrupt Enable Register */
  #define KBIE7  ((struct __hc08_bits *)(&INTKBIER))->bit7
	#define KBIE6  ((struct __hc08_bits *)(&INTKBIER))->bit6
	#define KBIE5  ((struct __hc08_bits *)(&INTKBIER))->bit5
	#define KBIE4  ((struct __hc08_bits *)(&INTKBIER))->bit4
	#define KBIE3  ((struct __hc08_bits *)(&INTKBIER))->bit3
	#define KBIE2  ((struct __hc08_bits *)(&INTKBIER))->bit2
	#define KBIE1  ((struct __hc08_bits *)(&INTKBIER))->bit1
	#define KBIE0  ((struct __hc08_bits *)(&INTKBIER))->bit0

_VOLDATA _UINT8 __at 0x1C TBCR;    /* Time Base Module Control */
	#define TBIF   ((struct __hc08_bits *)(&TBCR))->bit7
	#define TBR2   ((struct __hc08_bits *)(&TBCR))->bit6
	#define TBR1   ((struct __hc08_bits *)(&TBCR))->bit5
	#define TBR0   ((struct __hc08_bits *)(&TBCR))->bit4
	#define TACK   ((struct __hc08_bits *)(&TBCR))->bit3
	#define TBIE   ((struct __hc08_bits *)(&TBCR))->bit2
	#define TBON   ((struct __hc08_bits *)(&TBCR))->bit1
	/* Bit 0 Reserved */

_VOLDATA _UINT8 __at 0x1D INTSCR;	/* IRQ status/control       */
	#define IRQF1  ((struct __hc08_bits *)(&INTSCR))->bit3
	#define ACK1   ((struct __hc08_bits *)(&INTSCR))->bit2
	#define IMASK1 ((struct __hc08_bits *)(&INTSCR))->bit1
	#define MODE1  ((struct __hc08_bits *)(&INTSCR))->bit0
	/* Bits 4-7 unimplemented */

_VOLDATA _UINT8 __at 0x1e CONFIG2; /* Configuration Register 2 */
/* CONFIG2 is one-time writeble, so can't use bitfields  */

_VOLDATA _UINT8 __at 0x1f CONFIG1; /* Configuration Register 1 */
/* CONFIG1 is one-time writeable, so can't use bitfields */

_VOLDATA _UINT8 __at 0x20 T1SC;     /* TIM 1 Status and Control */
  #define PS0   ((struct __hc08_bits *)(&T1SC))->bit0
  #define PS1   ((struct __hc08_bits *)(&T1SC))->bit1
  #define PS2   ((struct __hc08_bits *)(&T1SC))->bit2
  #define TRST  ((struct __hc08_bits *)(&T1SC))->bit4
  #define TSTOP ((struct __hc08_bits *)(&T1SC))->bit5
  #define TOIE  ((struct __hc08_bits *)(&T1SC))->bit6
  #define TOF   ((struct __hc08_bits *)(&T1SC))->bit7

_VOLDATA _UINT16 __at 0x21 T1CNT;    /* TIM1 Counter High & Low Registers */
_VOLDATA _UINT8  __at 0x21  T1CNTH;  /* TIM1 Counter Register High */
_VOLDATA _UINT8  __at 0x22  T1CNTL;  /* TIM1 Counter Register Low */

_VOLDATA _UINT16 __at 0x23 T1MOD;    /* TIM1 Counter Modulo High & Low Registers */
_VOLDATA _UINT8  __at 0x23 T1MODH;   /* TIM1 Counter Modulo Register High */
_VOLDATA _UINT8  __at 0x24 T1MODL;   /* TIM1 Counter Modulo Register Low */

_VOLDATA _UINT8 __at 0x25 T1SC0;    /* TIM1 Channel 0 Status and Control Register */
  #define CH0MAX ((struct __hc08_bits *)(&T1SC0))->bit0
  #define TOV0   ((struct __hc08_bits *)(&T1SC0))->bit1
  #define ELS0A  ((struct __hc08_bits *)(&T1SC0))->bit2
  #define ELS0B  ((struct __hc08_bits *)(&T1SC0))->bit3
  #define MS0A   ((struct __hc08_bits *)(&T1SC0))->bit4
  #define MS0B   ((struct __hc08_bits *)(&T1SC0))->bit5
  #define CH0IE  ((struct __hc08_bits *)(&T1SC0))->bit6
  #define CH0F   ((struct __hc08_bits *)(&T1SC0))->bit7

_VOLDATA _UINT16 __at 0x26 T1CH0;   /* TIM1 Channel 0 High & Low Registers */
_VOLDATA _UINT8 __at 0x26 T1CH0H;   /* TIM1 Channel 0 Register High */
_VOLDATA _UINT8 __at 0x27 T1CH0L;   /* TIM1 Channel 0 Register Low */

_VOLDATA _UINT8 __at 0x28 T1SC1;    /* TIM1 Channel 1 Status and Control Register */
  #define CH1MAX ((struct __hc08_bits *)(&T1SC1))->bit0
  #define TOV1   ((struct __hc08_bits *)(&T1SC1))->bit1
  #define ELS1A  ((struct __hc08_bits *)(&T1SC1))->bit2
  #define ELS1B  ((struct __hc08_bits *)(&T1SC1))->bit3
  #define MS1A   ((struct __hc08_bits *)(&T1SC1))->bit4
  #define CH1IE  ((struct __hc08_bits *)(&T1SC1))->bit6
  #define CH1F   ((struct __hc08_bits *)(&T1SC1))->bit7

_VOLDATA _UINT16 __at 0x29 T1CH1;    /* TIM1 Channel 1 High & Low Registers */
_VOLDATA _UINT8  __at 0x29  T1CH1H;  /* TIM1 Channel 1 Register High */
_VOLDATA _UINT8  __at 0x2A  T1CH1L;  /* TIM1 Channel 1 Register Low */

/*------------------*/
/* TIM 2 REGISTERS  */
/*------------------*/

_VOLDATA _UINT8 __at 0x2B T2SC;     /* TIM 2 Status and Control */
  #define PS0_2   ((struct __hc08_bits *)(&T2SC))->bit0
  #define PS1_2   ((struct __hc08_bits *)(&T2SC))->bit1
  #define PS2_2   ((struct __hc08_bits *)(&T2SC))->bit2
  #define TRST_2  ((struct __hc08_bits *)(&T2SC))->bit4
  #define TSTOP_2 ((struct __hc08_bits *)(&T2SC))->bit5
  #define TOIE_2  ((struct __hc08_bits *)(&T2SC))->bit6
  #define TOF_2   ((struct __hc08_bits *)(&T2SC))->bit7

_VOLDATA _UINT16 __at 0x2C T2CNT;   /* TIM2 Counter High & Low Registers */
_VOLDATA _UINT8  __at 0x2C T2CNTH;  /* TIM2 Counter Register High */
_VOLDATA _UINT8  __at 0x2D T2CNTL;  /* TIM2 Counter Register Low */

_VOLDATA _UINT16 __at 0x2E T2MOD;    /* TIM2 Counter Modulo High & Low Registers */
_VOLDATA _UINT8  __at 0x2E T2MODH;   /* TIM2 Counter Modulo Register High */
_VOLDATA _UINT8  __at 0x2F T2MODL;   /* TIM2 Counter Modulo Register Low */

_VOLDATA _UINT8 __at 0x30 T2SC0;    /* TIM2 Channel 0 Status and Control Register */
  #define CH0MAX_2 ((struct __hc08_bits *)(&T2SC0))->bit0
  #define TOV0_2   ((struct __hc08_bits *)(&T2SC0))->bit1
  #define ELS0A_2  ((struct __hc08_bits *)(&T2SC0))->bit2
  #define ELS0B_2  ((struct __hc08_bits *)(&T2SC0))->bit3
  #define MS0A_2   ((struct __hc08_bits *)(&T2SC0))->bit4
  #define MS0B_2   ((struct __hc08_bits *)(&T2SC0))->bit5
  #define CH0IE_2  ((struct __hc08_bits *)(&T2SC0))->bit6
  #define CH0F_2   ((struct __hc08_bits *)(&T2SC0))->bit7

_VOLDATA _UINT16 __at 0x31 T2CH0;    /* TIM2 Channel 0 High & Low Registers */
_VOLDATA _UINT8  __at 0x31 T2CH0H;   /* TIM2 Channel 0 Register High */
_VOLDATA _UINT8  __at 0x32 T2CH0L;   /* TIM2 Channel 0 Register Low */

_VOLDATA _UINT8 __at 0x33 T2SC1;    /* TIM2 Channel 1 Status and Control Register */
  #define CH1MAX_2 ((struct __hc08_bits *)(&T2SC1))->bit0
  #define TOV1_2   ((struct __hc08_bits *)(&T2SC1))->bit1
  #define ELS1A_2  ((struct __hc08_bits *)(&T2SC1))->bit2
  #define ELS1B_2  ((struct __hc08_bits *)(&T2SC1))->bit3
  #define MS1A_2   ((struct __hc08_bits *)(&T2SC1))->bit4
  #define CH1IE_2  ((struct __hc08_bits *)(&T2SC1))->bit6
  #define CH1F_2   ((struct __hc08_bits *)(&T2SC1))->bit7

_VOLDATA _UINT16 __at 0x34  T2CH1;   /* TIM2 Channel 1 High & Low Registers */
_VOLDATA _UINT8  __at 0x34  T2CH1H;  /* TIM2 Channel 1 Register High */
_VOLDATA _UINT8  __at 0x35  T2CH1L;  /* TIM2 Channel 1 Register Low */

_VOLDATA _UINT8 __at 0x36 PCTL;  /* PLL Control Register */
	#define PLLIE ((struct __hc08_bits *)(&PCTL))->bit7
	#define PLLF  ((struct __hc08_bits *)(&PCTL))->bit6
	#define PLLON ((struct __hc08_bits *)(&PCTL))->bit5
	#define BCS   ((struct __hc08_bits *)(&PCTL))->bit4
	#define PRE1  ((struct __hc08_bits *)(&PCTL))->bit3
	#define PRE0  ((struct __hc08_bits *)(&PCTL))->bit2
	#define VPR1  ((struct __hc08_bits *)(&PCTL))->bit1
	#define VPR0  ((struct __hc08_bits *)(&PCTL))->bit0

_VOLDATA	_UINT8 __at 0x37 PBWC;  /* PLL Bandwidth Control Register */
	#define AUTO ((struct __hc08_bits *)(&PBWC))->bit7
	#define LOCK ((struct __hc08_bits *)(&PBWC))->bit6
	#define ACQ  ((struct __hc08_bits *)(&PBWC))->bit5
	/* Bits 1-4, Unimplemented */
	/* Bit 0, Reserved         */

_VOLDATA _UINT8 __at 0x38 PMSH;  /* PLL Multiplier Select High */
	#define MUL11 ((struct __hc08_bits *)(&PMSH))->bit3
	#define MUL10 ((struct __hc08_bits *)(&PMSH))->bit2
	#define MUL9  ((struct __hc08_bits *)(&PMSH))->bit1
	#define MUL8  ((struct __hc08_bits *)(&PMSH))->bit0
	/* Bits 4-7 unimplemented */

_VOLDATA _UINT8 __at 0x39 PMSL;  /* PLL Multiplir Select Low */
	#define MUL7 ((struct __hc08_bits *)(&PMSL))->bit7
	#define MUL6 ((struct __hc08_bits *)(&PMSL))->bit6
	#define MUL5 ((struct __hc08_bits *)(&PMSL))->bit5
	#define MUL4 ((struct __hc08_bits *)(&PMSL))->bit4
	#define MUL3 ((struct __hc08_bits *)(&PMSL))->bit3
	#define MUL2 ((struct __hc08_bits *)(&PMSL))->bit2
	#define MUL1 ((struct __hc08_bits *)(&PMSL))->bit1
	#define MUL0 ((struct __hc08_bits *)(&PMSL))->bit0

_VOLDATA _UINT8 __at 0x3a PMRS;  /* PLL VCO Select Range  */
	#define VRS7 ((struct __hc08_bits *)(&PMRS))->bit7
	#define VRS6 ((struct __hc08_bits *)(&PMRS))->bit6
	#define VRS5 ((struct __hc08_bits *)(&PMRS))->bit5
	#define VRS4 ((struct __hc08_bits *)(&PMRS))->bit4
	#define VRS3 ((struct __hc08_bits *)(&PMRS))->bit3
	#define VRS2 ((struct __hc08_bits *)(&PMRS))->bit2
	#define VRS1 ((struct __hc08_bits *)(&PMRS))->bit1
	#define VRS0 ((struct __hc08_bits *)(&PMRS))->bit0

_VOLDATA _UINT8 __at 0x3b PMDS;  /* PLL Reference Divider Select Register */
	#define RDS3 ((struct __hc08_bits *)(&PMDS))->bit3
	#define RDS2 ((struct __hc08_bits *)(&PMDS))->bit2
	#define RDS1 ((struct __hc08_bits *)(&PMDS))->bit1
	#define RDS0 ((struct __hc08_bits *)(&PMDS))->bit0
	/* Bits 4-7 unimplemented */

_VOLDATA _UINT8 __at 0x3c ADSCR; /* Analog-to-Digital Status and Control Reg. */
	#define COCO  ((struct __hc08_bits *)(&ADSCR))->bit7
	#define AIEN  ((struct __hc08_bits *)(&ADSCR))->bit6
	#define ADCO  ((struct __hc08_bits *)(&ADSCR))->bit5
	#define ADCH4 ((struct __hc08_bits *)(&ADSCR))->bit4
	#define ADCH3 ((struct __hc08_bits *)(&ADSCR))->bit3
	#define ADCH2 ((struct __hc08_bits *)(&ADSCR))->bit2
	#define ADCH1 ((struct __hc08_bits *)(&ADSCR))->bit1
	#define ADCH0 ((struct __hc08_bits *)(&ADSCR))->bit0

_VOLDATA _UINT8 __at 0x3d ADR;   /* Analog-to-Digital Data Register  */

_VOLDATA _UINT8 __at 0x3e ADCLK; /* Analog-to-Digital Clock */
	#define ADIV2  ((struct __hc08_bits *)(&ADCLK))->bit7
	#define ADIV1  ((struct __hc08_bits *)(&ADCLK))->bit6
	#define ADIV0  ((struct __hc08_bits *)(&ADCLK))->bit5
	#define ADICLK ((struct __hc08_bits *)(&ADCLK))->bit4
	/* Bits 0-3 unimplemented */

_VOLXDATA _UINT8 __at 0xfe00 SBSR;     /* SIM Break Status Register */
  #define SBSW ((struct __hc08_bits *)(&SBSR))->bit1

_VOLXDATA _UINT8 __at 0xfe01 SRSR;    /* SIM Reset Status Register */
  #define LVI    ((struct __hc08_bits *)(&SRSR))->bit1
  #define MODRST ((struct __hc08_bits *)(&SRSR))->bit2
  #define ILAD   ((struct __hc08_bits *)(&SRSR))->bit3
  #define ILOP   ((struct __hc08_bits *)(&SRSR))->bit4
  #define COP    ((struct __hc08_bits *)(&SRSR))->bit5
  #define PIN    ((struct __hc08_bits *)(&SRSR))->bit6
  #define POR    ((struct __hc08_bits *)(&SRSR))->bit7
  /* Bit 0 unimplemented */

_VOLXDATA _UINT8 __at 0xfe02 SUBAR;  /* SIM Upper Byte Address */

_VOLXDATA _UINT8 __at 0xfe03 SBFCR;    /* SIM Break Flag Control Register */
  #define BFCE ((struct __hc08_bits *)(&BFCR))->bit7

_VOLXDATA _UINT8 __at 0xfe04 INT1;    /* Interrupt Status Register 1 */
  #define IF1 ((struct __hc08_bits *)(&INT1))->bit2
  #define IF2 ((struct __hc08_bits *)(&INT1))->bit3
  #define IF3 ((struct __hc08_bits *)(&INT1))->bit4
  #define IF4 ((struct __hc08_bits *)(&INT1))->bit5
  #define IF5 ((struct __hc08_bits *)(&INT1))->bit6
  #define IF6 ((struct __hc08_bits *)(&INT1))->bit7
	/* Bits 0-1 Reserved */

_VOLXDATA _UINT8 __at 0xfe05 INT2;  /* Interrupt Status Register 2 */
  #define IF14 ((struct __hc08_bits *)(&INT2))->bit7
	#define IF13 ((struct __hc08_bits *)(&INT2))->bit6
	#define IF12 ((struct __hc08_bits *)(&INT2))->bit5
	#define IF11 ((struct __hc08_bits *)(&INT2))->bit4
	#define IF10 ((struct __hc08_bits *)(&INT2))->bit3
	#define IF9 ((struct __hc08_bits *)(&INT2))->bit2
	#define IF8 ((struct __hc08_bits *)(&INT2))->bit1
	#define IF7 ((struct __hc08_bits *)(&INT2))->bit0

_VOLXDATA _UINT8 __at 0xfe06 INT3;  /* Interrupt Status Register 3 */
  #define IF16 ((struct __hc08_bits *)(&INT3))->bit1
	#define IF15 ((struct __hc08_bits *)(&INT3))->bit0

_VOLXDATA _UINT8 __at 0xfe07 FLCTR;  /* Flash test/programming */

_VOLXDATA _UINT8 __at 0xfe08 FLCR;    /* FLASH Control Register */
  #define PGM   ((struct __hc08_bits *)(&FLCR))->bit0
  #define ERASE ((struct __hc08_bits *)(&FLCR))->bit1
  #define MASS  ((struct __hc08_bits *)(&FLCR))->bit2
  #define HVEN  ((struct __hc08_bits *)(&FLCR))->bit3

_VOLXDATA _UINT16 __at 0xfe09 BRK;    /* Break Address High & Low Registers */
_VOLXDATA _UINT8 __at 0xfe09 BRKH;    /* Break Address High Register */
_VOLXDATA _UINT8 __at 0xfe0a BRKL;    /* Break Address Low Register */

_VOLXDATA _UINT8 __at 0xfe0b BRKSCR;  /* Break Status and Control Register */
  #define BRKA ((struct __hc08_bits *)(&BRKSCR))->bit6
  #define BRKE ((struct __hc08_bits *)(&BRKSCR))->bit7

_VOLXDATA _UINT8 __at 0xfe0c LVISR;   /* Low voltage detect */
	#define LVIOUT ((struct __hc08_bits *)(&LVISR))->bit7


_VOLXDATA _UINT8 __at 0xfe7e FLBPR;    /* FLASH Block Protect Register */
  #define BPR0 ((struct __hc08_bits *)(&FLBPR))->bit0
  #define BPR1 ((struct __hc08_bits *)(&FLBPR))->bit1
  #define BPR2 ((struct __hc08_bits *)(&FLBPR))->bit2
  #define BPR3 ((struct __hc08_bits *)(&FLBPR))->bit3
  #define BPR4 ((struct __hc08_bits *)(&FLBPR))->bit4
  #define BPR5 ((struct __hc08_bits *)(&FLBPR))->bit5
  #define BPR6 ((struct __hc08_bits *)(&FLBPR))->bit6
  #define BPR7 ((struct __hc08_bits *)(&FLBPR))->bit7

_VOLXDATA _UINT8 __at 0xffff COPCTL;  /* COP Control Register */

#endif
