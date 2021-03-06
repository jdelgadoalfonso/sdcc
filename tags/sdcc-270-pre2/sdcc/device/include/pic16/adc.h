
/*
 * A/D conversion module library header
 *
 * written by Vangelis Rokas, 2004 <vrokas AT otenet.gr>
 *
 * Devices implemented:
 *	PIC18F[24][45][28]
 *
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

/*
** $Id$
*/

#ifndef __ADC_H__
#define __ADC_H__

/* link I/O libarary */
#pragma library io

/* interrupt on/off flag */
#define ADC_INT_OFF	0x00
#define ADC_INT_ON	0x01


/* output format */
#define ADC_FRM_RJUST	0x80
#define ADC_FRM_LJUST	0x00

/* oscillator frequency */
#define ADC_FOSC_2	0x00
#define ADC_FOSC_4	0x04
#define ADC_FOSC_8	0x01
#define ADC_FOSC_16	0x05
#define ADC_FOSC_32	0x02
#define ADC_FOSC_64	0x06
#define ADC_FOSC_RC	0x07


/* channel selection */
#define ADC_CHN_1		0x00
#define ADC_CHN_2		0x01
#define ADC_CHN_3		0x03
#define ADC_CHN_4		0x04
#define ADC_CHN_5		0x05
#define ADC_CHN_6		0x06
#define ADC_CHN_7		0x07


/* reference and pin configuration */
#define ADC_CFG_8A_0R	0x00
#define ADC_CFG_7A_1R	0x01
#define ADC_CFG_5A_0R	0x02
#define ADC_CFG_4A_1R	0x03
#define ADC_CFG_3A_0R	0x04
#define ADC_CFG_2A_1R	0x05
#define ADC_CFG_0A_0R	0x06
#define ADC_CFG_6A_2R	0x08
#define ADC_CFG_6A_0R	0x09
#define ADC_CFG_5A_1R	0x0a
#define ADC_CFG_4A_2R	0x0b
#define ADC_CFG_3A_2R	0x0c
#define ADC_CFG_2A_2R	0x0d
#define ADC_CFG_1A_0R	0x0e
#define ADC_CFG_1A_2R	0x0f


/* initialize AD module */
void adc_open(unsigned char channel, unsigned char fosc, unsigned char pcfg, unsigned char config);

/* shutdown AD module */
void adc_close(void);

/* begin a conversion */
void adc_conv(void);

/* return 1 if AD is performing a conversion, 0 if done */
char adc_busy(void) __naked;

/* get value of conversion */
int adc_read(void) __naked;

/* setup conversion channel */
void adc_setchannel(unsigned char channel) __naked;

#endif
