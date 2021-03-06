/* lklist.c */

/*
 * (C) Copyright 1989-2000
 * All Rights Reserved
 *
 * Alan R. Baldwin
 * 721 Berkeley St.
 * Kent, Ohio  44240
 *
 */

#include <stdio.h>
#include <string.h>

#ifdef WIN32
#include <stdlib.h>
#else
#include <alloc.h>
#endif

#include "aslink.h"

/*)Module	lklist.c
 *
 *	The module lklist.c contains the functions which
 *	output the linker .map file and produce a relocated
 *	listing .rst file.
 *
 *	lklist.c contains the following functions:
 *		int	dgt()
 *		VOID	newpag()
 *		VOID	slew()
 *		VOID	lstarea()
 *		VOID	lkulist()
 *		VOID	lkalist()
 *		VOID	lkglist()
 *
 *	lklist.c contains no local variables.
 */

/*)Function	VOID	newpag()
 *
 *	The function newpag() outputs a page skip, writes the
 *	first page header line, sets the line count to 1, and
 *	increments the page counter.
 *
 *	local variables:
 *		none
 *
 *	global variables:
 *		int	lop		current line number on page
 *		int	page		current page number
 *
 *	functions called:
 *		int	fprintf()	c_library
 *
 *	side effects:
 *		The page and line counters are updated.
 */

VOID
newpag(fp)
FILE *fp;
{
	fprintf(fp, "\fASxxxx Linker %s,  page %u.\n", VERSION, ++page);
	lop = 1;
}

/*)Function	int	dgt(rdx,str,n)
 *
 *		int	rdx		radix bit code
 *		char	*str		pointer to the test string
 *		int	n		number of characters to check
 *
 *	The function dgt() verifies that the string under test
 *	is of the specified radix.
 *
 *	local variables:
 *		int	i		loop counter
 *
 *	global variables:
 *		ctype[]			array of character types
 *
 *	functions called:
 *		none
 *
 *	side effects:
 *		none
 */

int
dgt(rdx, str, n)
int rdx, n;
char *str;
{
	int i;

	for (i=0; i<n; i++) {
		if ((ctype[*str++ & 0x007F] & rdx) == 0)
			return(0);
	}
	return(1);
}

/*)Function	VOID	slew(xp)
 *
 *		area *	xp		pointer to an area structure
 *
 *	The function slew() increments the page line counter.
 *	If the number of lines exceeds the maximum number of
 *	lines per page then a page skip and a page header are
 *	output.
 *
 *	local variables:
 *		addr_t	ai		temporary
 *		addr_t	aj		temporary
 *		int	i		loop counter
 *		int	n		repeat counter
 *		char *	frmta		temporary format specifier
 *		char *	frmtb		temporary format specifier
 *		char *	ptr		pointer to an id string
 *
 *	global variables:
 *		int	lop		current line number on page
 *		FILE	*mfp		Map output file handle
 *		int	wflag		Wide format listing
 *		int	xflag		Map file radix type flag
 *
 *	functions called:
 *		int	fprintf()	c_library
 *		VOID	newpag()	lklist.c
 *		char	putc()		c_library
 *
 *	side effects:
 *		The page line and the page count may be updated.
 */

VOID
slew(xp)
register struct area *xp;
{
	register int i, n;
	register char *frmta, *frmtb, *ptr;
 	addr_t	ai, aj;

       	if (lop++ >= NLPP) {
		newpag(mfp);
		switch(xflag) {
		default:
		case 0: frmta = "Hexidecimal"; break;
		case 1: frmta = "Octal"; break;
		case 2: frmta = "Decimal"; break;
		}
		fprintf(mfp, "%s  [%d-Bits]\n\n", frmta, a_bytes*8);
		fprintf(mfp,
			"Area                       Addr   ");
		fprintf(mfp,
			"     Size        Decimal Bytes (Attributes)\n");
		fprintf(mfp,
			"--------------------       ----   ");
		fprintf(mfp,
			"     ----        ------- ----- ------------\n");

		ai = xp->a_addr & a_mask;
		aj = xp->a_size & a_mask;

		/*
		 * Output Area Header
		 */
		ptr = &xp->a_id[0];
		fprintf(mfp, "%-19.19s", ptr);
		switch(a_bytes) {
		default:
		case 2:
			switch(xflag) {
			default:
			case 0: frmta = "        %04X        %04X"; break;
			case 1: frmta = "      %06o      %06o"; break;
			case 2: frmta = "       %05u       %05u"; break;
			}
			frmtb = " =      %6u. bytes "; break;
		case 3:
			switch(xflag) {
			default:
			case 0: frmta = "      %06X      %06X"; break;
			case 1: frmta = "    %08o    %08o"; break;
			case 2: frmta = "    %08u    %08u"; break;
			}
			frmtb = " =    %8u. bytes "; break;
		case 4:
			switch(xflag) {
			default:
			case 0: frmta = "    %08X    %08X"; break;
			case 1: frmta = " %011o %011o"; break;
			case 2: frmta = "  %010u  %010u"; break;
			}
			frmtb = " =  %10u. bytes "; break;
		}
		fprintf(mfp, frmta, ai, aj);
		fprintf(mfp, frmtb, aj);

		if (xp->a_flag & A_ABS) {
			fprintf(mfp, "(ABS");
		} else {
			fprintf(mfp, "(REL");
		}
		if (xp->a_flag & A_OVR) {
			fprintf(mfp, ",OVR");
		} else {
			fprintf(mfp, ",CON");
		}
		if (xp->a_flag & A_PAG) {
			fprintf(mfp, ",PAG");
		}
		fprintf(mfp, ")\n");

		if (xp->a_flag & A_PAG) {
			ai = (ai & 0xFF);
			aj = (aj > 256);
			if (ai || aj) { fprintf(mfp, "  "); lop += 1; }
			if (ai)      { fprintf(mfp, " Boundary"); }
			if (ai & aj)  { fprintf(mfp, " /"); }
			if (aj)      { fprintf(mfp, " Length"); }
			if (ai || aj) { fprintf(mfp, " Error\n"); }
		}

		if (wflag) {
			putc('\n', mfp);
			fprintf(mfp,
			"         Value  Global                          ");
			fprintf(mfp,
			"   Global Defined In Module\n");
			fprintf(mfp,
			"         -----  --------------------------------");
			fprintf(mfp,
			"   ------------------------\n");
		} else {
			switch(a_bytes) {
			default:
			case 2:	frmta = "   Value  Global   ";
				frmtb = "   -----  ------   ";
				n = 4; break;
			case 3:
			case 4:	frmta = "        Value  Global    ";
				frmtb = "        -----  ------    ";
				n = 3; break;
			}
			putc('\n', mfp);
			for(i=0;i<n;++i)
				fprintf(mfp, frmta);
			putc('\n', mfp);
			for(i=0;i<n;++i)
				fprintf(mfp, frmtb);
			putc('\n', mfp);
		}

		lop += 9;
	}
}

/*)Function	VOID	lstarea(xp)
 *
 *		area *	xp		pointer to an area structure
 *
 *	The function lstarea() creates the linker map output for
 *	the area specified by pointer xp.  The generated output
 *	area header includes the area name, starting address,
 *	size of area, number of words (in decimal), and the
 *	area attributes.  The symbols defined in this area are
 *	sorted by ascending address and output four per line
 *	in the selected radix (one per line in wide format).
 *
 *	local variables:
 *		areax *	oxp		pointer to an area extension structure
 *		int	i		loop counter
 *		int	j		bubble sort update status
 *		int	n		repeat counter
 *		char *	frmt		temporary format specifier
 *		char *	ptr		pointer to an id string
 *		int	nmsym		number of symbols in area
 *		addr_t	a0		temporary
 *		addr_t	ai		temporary
 *		addr_t	aj		temporary
 *		sym *	sp		pointer to a symbol structure
 *		sym **	p		pointer to an array of
 *					pointers to symbol structures
 *
 *	global variables:
 *		FILE	*mfp		Map output file handle
 *		sym *symhash[NHASH] 	array of pointers to NHASH
 *				      	linked symbol lists
 *		int	wflag		Wide format listing
 *		int	xflag		Map file radix type flag
 *
 *	functions called:
 *		int	fprintf()	c_library
 *		VOID	free()		c_library
 *		char *	malloc()	c_library
 *		char	putc()		c_library
 *		VOID	slew()		lklist.c
 *
 *	side effects:
 *		Map output generated.
 */

VOID
lstarea(xp)
struct area *xp;
{
	register struct areax *oxp;
	register int i, j, n;
	register char *frmt, *ptr;
	int nmsym;
	addr_t a0, ai, aj;
	struct sym *sp;
	struct sym **p;

	lop = NLPP;
	slew(xp);

	/*
	 * Find number of symbols in area
	 */
	nmsym = 0;
	oxp = xp->a_axp;
	while (oxp) {
		for (i=0; i<NHASH; i++) {
			sp = symhash[i];
			while (sp != NULL) {
				if (oxp == sp->s_axp)
					++nmsym;
				sp = sp->s_sp;
			}
		}
		oxp = oxp->a_axp;
	}
	if (nmsym == 0) {
		return;
	}

	/*
	 * Allocate space for an array of pointers to symbols
	 * and load array.
	 */
	if ( (p = (struct sym **) malloc(nmsym*sizeof(struct sym *)))
		== NULL) {
		fprintf(mfp, "Insufficient space to build Map Segment.\n");
		return;
	}
	nmsym = 0;
	oxp = xp->a_axp;
	while (oxp) {
		for (i=0; i<NHASH; i++) {
			sp = symhash[i];
			while (sp != NULL) {
				if (oxp == sp->s_axp) {
					p[nmsym++] = sp;
				}
				sp = sp->s_sp;
			}
		}
		oxp = oxp->a_axp;
	}

	/*
	 * Bubble Sort of Addresses in Symbol Table Array
	 */
	j = 1;
	while (j) {
		j = 0;
		sp = p[0];
		a0 = sp->s_addr + sp->s_axp->a_addr;
		for (i=1; i<nmsym; ++i) {
			sp = p[i];
			ai = sp->s_addr + sp->s_axp->a_addr;
			if (a0 > ai) {
				j = 1;
				p[i] = p[i-1];
				p[i-1] = sp;
			}
			a0 = ai;
		}
	}

	/*
	 * Repeat Counter
	 */
	switch(a_bytes) {
	default:
	case 2: n = 4; break;
	case 3:
	case 4: n = 3; break;
	}

	/*
	 * Symbol Table Output
	 */
	i = 0;
	while (i < nmsym) {
		if (wflag) {
			slew(xp);
			switch(a_bytes) {
			default:
			case 2: frmt = "        "; break;
			case 3:
			case 4: frmt = "   "; break;
			}
			fprintf(mfp, frmt);
		} else
		if ((i % n) == 0) {
			slew(xp);
			switch(a_bytes) {
			default:
			case 2: frmt = "  "; break;
			case 3:
			case 4: frmt = "  "; break;
			}
			fprintf(mfp, frmt);
		}

		sp = p[i];
		aj = (sp->s_addr + sp->s_axp->a_addr) & a_mask;
		switch(a_bytes) {
		default:
		case 2:
			switch(xflag) {
			default:
			case 0: frmt = "  %04X  "; break;
			case 1: frmt = "%06o  "; break;
			case 2: frmt = " %05u  "; break;
			}
			break;
		case 3:
			switch(xflag) {
			default:
			case 0: frmt = "     %06X  "; break;
			case 1: frmt = "   %08o  "; break;
			case 2: frmt = "   %08u  "; break;
			}
			break;
		case 4:
			switch(xflag) {
			default:
			case 0: frmt = "   %08X  "; break;
			case 1: frmt = "%011o  "; break;
			case 2: frmt = " %010u  "; break;
			}
			break;
		}
		fprintf(mfp, frmt, aj);

		ptr = &sp->s_id[0];
		if (wflag) {
			fprintf(mfp, "%-32.32s", ptr);
			i++;
			ptr = &sp->m_id[0];
			if(ptr) {
				fprintf(mfp, "   %-.28s", ptr);
			}
		} else {
			switch(a_bytes) {
			default:
			case 2: frmt = "%-8.8s"; break;
			case 3:
			case 4: frmt = "%-9.9s"; break;
			}
			fprintf(mfp, frmt, ptr);
			if (++i < nmsym)
				if (i % n != 0)
					fprintf(mfp, " | ");
		}
		if (wflag || (i % n == 0)) {
			putc('\n', mfp);
		}
	}
	if (i % n != 0) {
		putc('\n', mfp);
	}
	free(p);
}

/*)Function	VOID	lkulist(i)
 *
 *		int	i	i # 0	process LST to RST file
 *				i = 0	copy remainder of LST file
 *					to RST file and close files
 *
 *	The function lkulist() creates a relocated listing (.rst)
 *	output file from the ASxxxx assembler listing (.lst)
 *	files.  The .lst file's program address and code bytes
 *	are changed to reflect the changes made by ASlink as
 *	the .rel files are combined into a single relocated
 *	output file.
 *
 *	local variables:
 *		addr_t	pc		current program counter address
 *
 *	global variables:
 *		int	a_bytes		T Line Address Bytes
 *		int	hilo		byte order
 *		int	gline		get a line from the LST file
 *					to translate for the RST file
 *		char	rb[]		read listing file text line
 *		FILE	*rfp		The file handle to the current
 *					output RST file
 *		int	rtcnt		count of data words
 *		int	rtflg[]		output the data flag
 *		addr_t	rtval[]		relocated data
 *		FILE	*tfp		The file handle to the current
 *					LST file being scanned
 *
 *	functions called:
 *		addr_t	adb_xb()	lkrloc.c
 *		int	fclose()	c_library
 *		int	fgets()		c_library
 *		int	fprintf()	c_library
 *		VOID	lkalist()	lklist.c
 *		VOID	lkglist()	lklist.c
 *
 *	side effects:
 *		A .rst file is created for each available .lst
 *		file associated with a .rel file.
 */

VOID
lkulist(i)
int i;
{
	addr_t pc;

	/*
	 * Exit if listing file is not open
	 */
	if (tfp == NULL)
		return;

	/*
	 * Normal processing of LST to RST
	 */
	if (i) {
		/*
		 * Evaluate current code address
		 */
		pc = adb_xb(0, 0);

		/*
		 * Line with only address
		 */	
		if (rtcnt == a_bytes) {
			lkalist(pc);

		/*
		 * Line with address and code
		 */
		} else {
			for (i=a_bytes; i < rtcnt; i++) {
				if (rtflg[i]) {
					lkglist(pc++, rtval[i] & 0xFF);
				}
			}
		}
	/*
	 * Copy remainder of LST to RST
	 */
	} else {
		if (gline == 0)
			fprintf(rfp, "%s", rb);

		while (fgets(rb, sizeof(rb)-2, tfp) != 0) {
			fprintf(rfp, "%s", rb);
		}
		fclose(tfp);
		tfp = NULL;
		fclose(rfp);
		rfp = NULL;
	}
}

/*)Function	VOID	lkalist(pc)
 *
 *		int	pc		current program counter value
 *
 *	The function lkalist() performs the following functions:
 *
 *	(1)	if the value of gline = 0 then the current listing
 *		file line is copied to the relocated listing file output.
 *
 *	(2)	the listing file is read line by line and copied to
 *		the relocated listing file until a valid source
 *		line number and a program counter value of the correct
 *		radix is found.  The new relocated pc value is substituted
 *		and the line is written to the RST file.
 *
 *	local variables:
 *		int	i		loop counter
 *		int	m		character count
 *		int	n		character index
 *		int	r		character radix
 *		char *	frmt		temporary format specifier
 *		char	str[]		temporary string
 *
 *	global variables:
 *		int	gcntr		data byte counter
 *		int	gline		get a line from the LST file
 *					to translate for the RST file
 *		char	rb[]		read listing file text line
 *		char	*rp		pointer to listing file text line
 *		FILE	*rfp		The file handle to the current
 *					output RST file
 *		FILE	*tfp		The file handle to the current
 *					LST file being scanned
 *
 *	functions called:
 *		int	dgt()		lklist.c
 *		int	fclose()	c_library
 *		int	fgets()		c_library
 *		int	fprintf()	c_library
 *		int	sprintf()	c_library
 *		char *	strncpy()	c_library
 *
 *	side effects:
 *		Lines of the LST file are copied to the RST file,
 *		the last line copied has the code address
 *		updated to reflect the program relocation.
 */

/* The Output Formats
| Tabs- |       |       |       |       |       |
          11111111112222222222333333333344444-----
012345678901234567890123456789012345678901234-----
   |    |               |     | |
ee XXXX xx xx xx xx xx xx LLLLL *************	HEX(16)
ee 000000 ooo ooo ooo ooo LLLLL *************	OCTAL(16)
ee  DDDDD ddd ddd ddd ddd LLLLL *************	DECIMAL(16)
                     XXXX
		   OOOOOO
		    DDDDD

| Tabs- |       |       |       |       |       |
          11111111112222222222333333333344444-----
012345678901234567890123456789012345678901234-----
     |       |                  |     | |
ee    XXXXXX xx xx xx xx xx xx xx LLLLL *********	HEX(24)
ee   OO000000 ooo ooo ooo ooo ooo LLLLL *********	OCTAL(24)
ee   DDDDDDDD ddd ddd ddd ddd ddd LLLLL *********	DECIMAL(24)
                           XXXXXX
			 OOOOOOOO
			 DDDDDDDD

| Tabs- |       |       |       |       |       |
          11111111112222222222333333333344444-----
012345678901234567890123456789012345678901234-----
  |          |                  |     | |
ee  XXXXXXXX xx xx xx xx xx xx xx LLLLL *********	HEX(32)
eeOOOOO000000 ooo ooo ooo ooo ooo LLLLL *********	OCTAL(32)
ee DDDDDDDDDD ddd ddd ddd ddd ddd LLLLL *********	DECIMAL(32)
                         XXXXXXXX
		      OOOOOOOOOOO
		       DDDDDDDDDD
*/

VOID
lkalist(pc)
addr_t pc;
{
	char str[16];
	char *frmt;
	int i, m, n, r;

	/*
	 * Truncate (int) to N-Bytes
	 */
	 pc &= a_mask;

	/*
	 * Exit if listing file is not open
	 */
loop:	if (tfp == NULL)
		return;

	/*
	 * Copy current LST to RST
	 */
	if (gline == 0) {
		fprintf(rfp, "%s", rb);
		gline = 1;
	}

	/*
	 * Clear text line buffer
	 */
	for (i=0,rp=rb; i<sizeof(rb); i++) {
		*rp++ = 0;
	}

	/*
	 * Get next LST text line
	 */
	if (fgets(rb, sizeof(rb)-2, tfp) == NULL) {
		fclose(tfp);
		tfp = NULL;
		fclose(rfp);
		rfp = NULL;
		return;
	}

	/*
	 * Must have an ASxxxx Listing line number
	 */
	 switch(a_bytes) {
	 default:
	 case 2: n = 30; break;
	 case 3:
	 case 4: n = 38; break;
	 }
	 if (!dgt(RAD10, &rb[n], 1)) {
		fprintf(rfp, "%s", rb);
		goto loop;
	}

	/*
	 * Must have an address in the expected radix
	 */
	switch(radix) {
	default:
	case 16:
		r = RAD16;
		switch(a_bytes) {
		default:
		case 2: n = 3; m = 4; frmt = "%04X"; break;
		case 3: n = 6; m = 6; frmt = "%06X"; break;
		case 4: n = 4; m = 8; frmt = "%08X"; break;
		}
		break;
	case 10:
		r = RAD10;
		switch(a_bytes) {
		default:
		case 2: n = 4; m = 5; frmt = "%05u"; break;
		case 3: n = 5; m = 8; frmt = "%08u"; break;
		case 4: n = 3; m = 10; frmt = "%010u"; break;
		}
		break;
	case 8:
		r = RAD8;
		switch(a_bytes) {
		default:
		case 2: n = 3; m = 6; frmt = "%06o"; break;
		case 3: n = 5; m = 8; frmt = "%08o"; break;
		case 4: n = 2; m = 11; frmt = "%011o"; break;
		}
		break;
	}
	if (!dgt(r, &rb[n], m)) {
		fprintf(rfp, "%s", rb);
		goto loop;
	}
	sprintf(str, frmt, pc);
	strncpy(&rb[n], str, m);

	/*
	 * Copy updated LST text line to RST
	 */
	fprintf(rfp, "%s", rb);
	gcntr = 0;
}

/*)Function	VOID	lkglist(pc,v)
 *
 *		int	pc		current program counter value
 *		int 	v		value of byte at this address
 *
 *	The function lkglist() performs the following functions:
 *
 *	(1)	if the value of gline = 1 then the listing file
 *		is read line by line and copied to the
 *		relocated listing file until a valid source
 *		line number and a program counter value of the correct
 *		radix is found.
 *
 *	(2)	The new relocated values and code address are
 *		substituted and the line may be written to the RST file.
 *
 *	local variables:
 *		int	a		string index for first byte
 *		int	i		loop counter
 *		int	m		character count
 *		int	n		character index
 *		int	r		character radix
 *		int	s		spacing
 *		int	u		repeat counter
 *		char *	afrmt		temporary format specifier
 *		char *	frmt		temporary format specifier
 *		char	str[]		temporary string
 *
 *	global variables:
 *		int	a_bytes		T Line Address Bytes
 *		addr_t	a_mask		address masking parameter
 *		int	gcntr		data byte counter
 *					set to -1 for a continuation line
 *		int	gline		get a line from the LST file
 *					to translate for the RST file
 *		char	rb[]		read listing file text line
 *		char	*rp		pointer to listing file text line
 *		FILE	*rfp		The file handle to the current
 *					output RST file
 *		FILE	*tfp		The file handle to the current
 *					LST file being scanned
 *
 *	functions called:
 *		int	dgt()		lklist.c
 *		int	fclose()	c_library
 *		int	fgets()		c_library
 *		int	fprintf()	c_library
 *		int	sprintf()	c_library
 *		char *	strncpy()	c_library
 *
 *	side effects:
 *		Lines of the LST file are copied to the RST file
 *		with updated data values and code addresses.
 */

/* The Output Formats
| Tabs- |       |       |       |       |       |
          11111111112222222222333333333344444-----
012345678901234567890123456789012345678901234-----
   |    |               |     | |
ee XXXX xx xx xx xx xx xx LLLLL *************	HEX(16)
ee 000000 ooo ooo ooo ooo LLLLL *************	OCTAL(16)
ee  DDDDD ddd ddd ddd ddd LLLLL *************	DECIMAL(16)
                     XXXX
		   OOOOOO
		    DDDDD

| Tabs- |       |       |       |       |       |
          11111111112222222222333333333344444-----
012345678901234567890123456789012345678901234-----
     |       |                  |     | |
ee    XXXXXX xx xx xx xx xx xx xx LLLLL *********	HEX(24)
ee   OO000000 ooo ooo ooo ooo ooo LLLLL *********	OCTAL(24)
ee   DDDDDDDD ddd ddd ddd ddd ddd LLLLL *********	DECIMAL(24)
                           XXXXXX
			 OOOOOOOO
			 DDDDDDDD

| Tabs- |       |       |       |       |       |
          11111111112222222222333333333344444-----
012345678901234567890123456789012345678901234-----
  |          |                  |     | |
ee  XXXXXXXX xx xx xx xx xx xx xx LLLLL *********	HEX(32)
eeOOOOO000000 ooo ooo ooo ooo ooo LLLLL *********	OCTAL(32)
ee DDDDDDDDDD ddd ddd ddd ddd ddd LLLLL *********	DECIMAL(32)
                         XXXXXXXX
		      OOOOOOOOOOO
		       DDDDDDDDDD
*/

VOID
lkglist(pc,v)
addr_t pc;
int v;
{
	char str[16];
	char *afrmt, *frmt;
	int a, i, n, m, r, s, u;

	/*
	 * Truncate (int) to N-Bytes
	 */
	 pc &= a_mask;

 	/*
	 * Exit if listing file is not open
	 */
loop:	if (tfp == NULL)
		return;

	/*
	 * Get next LST text line
	 */
	if (gline) {
		/*
		 * Clear text line buffer
		 */
		for (i=0,rp=rb; i<sizeof(rb); i++) {
			*rp++ = 0;
		}

		/*
		 * Get next LST text line
		 */
		if (fgets(rb, sizeof(rb)-2, tfp) == NULL) {
			fclose(tfp);
			tfp = NULL;
			fclose(rfp);
			rfp = NULL;
			return;
		}

		/*
		 * Check for a listing line number if required
		 */
		if (gcntr != -1) {
			 switch(a_bytes) {
			 default:
			 case 2: n = 30; break;
			 case 3:
			 case 4: n = 38; break;
			 }
			if (!dgt(RAD10, &rb[n], 1)) {
				fprintf(rfp, "%s", rb);
				goto loop;
			}
			gcntr = 0;
		}
		gline = 0;
	}

	/*
	 * Hex Listing
	 */
	 switch(radix) {
	 default:
	 case 16:
		r = RAD16;
		switch(a_bytes) {
		default:
		case 2:	a = 8; s = 3; n = 3; m = 4; u = 6; afrmt = "%04X"; break;
		case 3: a = 13; s = 3; n = 6; m = 6; u = 7; afrmt = "%06X"; break;
		case 4: a = 13; s = 3; n = 4; m = 8; u = 7; afrmt = "%08X"; break;
		}
		frmt = " %02X"; break;
	case 10:
		r = RAD10;
		switch(a_bytes) {
		default:
		case 2:	a = 10; s = 4; n = 4; m = 5; u = 4; afrmt = "%05u"; break;
		case 3: a = 14; s = 4; n = 5; m = 8; u = 5; afrmt = "%08u"; break;
		case 4: a = 14; s = 4; n = 3; m = 10; u = 5; afrmt = "%010u"; break;
		}
		frmt = " %03u"; break;
	case 8:
		r = RAD8;
		switch(a_bytes) {
		default:
		case 2:	a = 10; s = 4; n = 3; m = 6; u = 4; afrmt = "%06o"; break;
		case 3: a = 14; s = 4; n = 5; m = 8; u = 5; afrmt = "%08o"; break;
		case 4: a = 14; s = 4; n = 2; m = 11; u = 5; afrmt = "%011o"; break;
		}
		frmt = " %03o"; break;
	}
	/*
	 * Data Byte Pointer
	 */
	if (gcntr == -1) {
		rp = &rb[a];
	} else {
		rp = &rb[a + (s * gcntr)];
	}
	/*
	 * Number must be of proper radix
	 */
	if (!dgt(r, rp, s-1)) {
		fprintf(rfp, "%s", rb);
		gline = 1;
		goto loop;
	}
	/*
	 * Output new data value, overwrite relocation codes
	 */
	sprintf(str, frmt, v);
	strncpy(rp-1, str, s);
	if (gcntr == -1) {
		gcntr = 0;
	}
	/*
	 * Output relocated code address
	 */
	if (gcntr == 0) {
		if (dgt(r, &rb[n], m)) {
			sprintf(str, afrmt, pc);
			strncpy(&rb[n], str, m);
		}
	}
	/*
	 * Output text line when updates finished
	 */
	if (++gcntr == u) {
		fprintf(rfp, "%s", rb);
		gline = 1;
		gcntr = -1;
	}
}


