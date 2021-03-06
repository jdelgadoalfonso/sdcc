;--------------------------------------------------------
; File Created by SDCC : FreeWare ANSI-C Compiler
; Version 2.1.9Ga Sun Jan 16 17:31:15 2000

;--------------------------------------------------------
	.module _startup
;--------------------------------------------------------
; publics variables in this module
;--------------------------------------------------------
	.globl __sdcc_external_startup
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; special function bits 
;--------------------------------------------------------
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area	DSEG    (DATA)
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area	OSEG	(OVR,DATA)
;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area	ISEG    (DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area	BSEG    (BIT)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area	XSEG    (XDATA)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area GSINIT (CODE)
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG (CODE)
	G$_sdcc_external_startup$0$0 ==.
;	_startup.c 30
;	-----------------------------------------
;	 function _sdcc_external_startup
;	-----------------------------------------
__sdcc_external_startup:
	ar2 = 0x02
	ar3 = 0x03
	ar4 = 0x04
	ar5 = 0x05
	ar6 = 0x06
	ar7 = 0x07
	ar0 = 0x00
	ar1 = 0x01
;	_startup.c 32
	mov	dpl,#0x00
00101$:
	C$_startup.c$33$1$1 ==.
	XG$_sdcc_external_startup$0$0 ==.
	ret
	.area	CSEG    (CODE)
