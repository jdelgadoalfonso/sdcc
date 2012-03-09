/* asmain.c */

/*
 * (C) Copyright 1989-2000
 * All Rights Reserved
 *
 * Alan R. Baldwin
 * 721 Berkeley St.
 * Kent, Ohio  44240
 */

#include <stdio.h>
#include <setjmp.h>
#include <string.h>

#ifdef WIN32
#include <stdlib.h>
#else
#include <alloc.h>
#endif

#include "asxxxx.h"


/*)Module	asmain.c
 *
 *	The module asmain.c includes the command argument parser,
 *	the three pass sequencer, and the machine independent
 *	assembler parsing code.
 *
 *	asmain.c contains the following functions:
 *		int	main(argc, argv)
 *		VOID	asexit(n)
 *		VOID	asmbl()
 *		FILE *	afile(fn, ft, wf)
 *		int	fndidx(str)
 *		VOID	newdot(nap)
 *		VOID	phase(ap, a)
 *		VOID	usage()
 *
 *	asmain.c contains the array char *usetxt[] which
 *	references the usage text strings printed by usage().
 */

/*)Function	int	main(argc, argv)
 *
 *		int	argc		argument count
 *		char *	argv		array of pointers to argument strings
 *
 *	The function main() is the entry point to the assembler.
 *	The purpose of main() is to (1) parse the command line
 *	arguments for options and source file specifications and
 *	(2) to process the source files through the 3 pass assembler.
 *	Before each assembler pass various variables are initialized
 *	and source files are rewound to their beginning.  During each
 *	assembler pass each assembler-source text line is processed.
 *	After each assembler pass the assembler information is flushed
 *	to any opened output files and the if-else-endif processing
 *	is checked for proper termination.
 *
 *	The function main() is also responsible for opening all
 *	output files (REL, LST, and SYM), sequencing the global (-g)
 *	and all-global (-a) variable definitions, and dumping the
 *	REL file header information.
 *
 *	local variables:
 *		char *	p		pointer to argument string
 *		int	c		character from argument string
 *		int	i		argument loop counter
 *		area *	ap		pointer to area structure
 *
 *	global variables:
 *		int	aflag		-a, make all symbols global flag
 *		char	afn[]		afile() constructed filespec
 *		int	afp		afile constructed path length
 *		area *	areap		pointer to an area structure
 *		int	aserr		assembler error counter
 *		int	cb[]		array of assembler output values
 *		int	cbt[]		array of assembler relocation types
 *					describing the data in cb[]
 *		int	cfile		current file handle index
 *					of input assembly files
 *		int *	cp		pointer to assembler output array cb[]
 *		int *	cpt		pointer to assembler relocation type
 *					output array cbt[]
 *		char	eb[]		array of generated error codes
 *		char *	ep		pointer into error list array eb[]
 *		int	fflag		-f(f), relocations flagged flag
 *		int	flevel		IF-ELSE-ENDIF flag will be non
 *					zero for false conditional case
 *		addr_t	fuzz		tracks pass to pass changes in the
 *					address of symbols caused by
 *					variable length instruction formats
 *		int	gflag		-g, make undefined symbols global flag
 *		char	ib[]		assembler-source text line
 *		int	inpfil		count of assembler
 *					input files specified
 *		int	ifcnd[]		array of IF statement condition
 *					values (0 = FALSE) indexed by tlevel
 *		int	iflvl[]		array of IF-ELSE-ENDIF flevel
 *					values indexed by tlevel
 *		int	incfil		current file handle index
 *					for include files
 *		char *	ip		pointer into the assembler-source
 *					text line in ib[]
 *		jmp_buf	jump_env	compiler dependent structure
 *					used by setjmp() and longjmp()
 *		int	lflag		-l, generate listing flag
 *		int	line		current assembler source
 *					line number
 *		int	lop		current line number on page
 *		int	oflag		-o, generate relocatable output flag
 *		int	page		current page number
 *		int	pflag		enable listing pagination
 *		int	pass		assembler pass number
 *		int	radix		current number conversion radix:
 *					2 (binary), 8 (octal), 10 (decimal),
 *					16 (hexadecimal)
 *		int	sflag		-s, generate symbol table flag
 *		char	srcfn[][]	array of source file names
 *		int	srcfp[]		array of source file path lengths
 *		int	srcline[]	current source file line
 *		char	stb[]		Subtitle string buffer
 *		sym *	symp		pointer to a symbol structure
 *		int	tlevel		current conditional level
 *		int	wflag		-w, enable wide listing format
 *		int	xflag		-x, listing radix flag
 *		int	zflag		-z, enable symbol case sensitivity
 *		FILE *	lfp		list output file handle
 *		FILE *	ofp		relocation output file handle
 *		FILE *	tfp		symbol table output file handle
 *		FILE *	sfp[]		array of assembler-source file handles
 *
 *	called functions:
 *		FILE *	afile()		asmain.c
 *		VOID	allglob()	assym.c
 *		VOID	asexit()	asmain.c
 *		VOID	diag()		assubr.c
 *		VOID	err()		assubr.c
 *		int	fprintf()	c-library
 *		int	getline()	aslex.c
 *		VOID	list()		aslist.c
 *		VOID	lstsym()	aslist.c
 *		VOID	minit()		___mch.c
 *		VOID	newdot()	asmain.c
 *		VOID	outbuf()	asout.c
 *		VOID	outchk()	asout.c
 *		VOID	outgsd()	asout.c
 *		int	rewind()	c-library
 *		int	setjmp()	c-library
 *		VOID	symglob()	assym.c
 *		VOID	syminit()	assym.c
 *		VOID	usage()		asmain.c
 *
 *	side effects:
 *		Completion of main() completes the assembly process.
 *		REL, LST, and/or SYM files may be generated.
 */

int
main(argc, argv)
int argc;
char *argv[];
{
	register char *p;
	register int c, i;
	struct area *ap;

	fprintf(stdout, "\n");
	inpfil = -1;
	pflag = 1;
	for (i=1; i<argc; ++i) {
		p = argv[i];
		if (*p == '-') {
			if (inpfil >= 0)
				usage(ER_FATAL);
			++p;
			while ((c = *p++) != 0)
				switch(c) {

				case 'a':
				case 'A':
					++aflag;
					break;

				case 'g':
				case 'G':
					++gflag;
					break;

				case 'l':
				case 'L':
					++lflag;
					break;

				case 'o':
				case 'O':
					++oflag;
					break;

				case 's':
				case 'S':
					++sflag;
					break;

				case 'p':
				case 'P':
					pflag = 0;
					break;

				case 'w':
				case 'W':
					++wflag;
					break;

				case 'z':
				case 'Z':
					++zflag;
					break;

				case 'x':
				case 'X':
					xflag = 0;
					break;

				case 'q':
				case 'Q':
					xflag = 1;
					break;

				case 'd':
				case 'D':
					xflag = 2;
					break;

				case 'f':
				case 'F':
					++fflag;
					break;

				default:
					usage(ER_FATAL);
				}
		} else {
			if (++inpfil == MAXFIL) {
				fprintf(stderr, "too many input files\n");
				asexit(ER_FATAL);
			}
			sfp[inpfil] = afile(p, "", 0);
			strcpy(srcfn[inpfil],afn);
			srcfp[inpfil] = afp;
			if (inpfil == 0) {
				if (lflag)
					lfp = afile(p, "lst", 1);
				if (oflag)
					ofp = afile(p, "rel", 1);
				if (sflag)
					tfp = afile(p, "sym", 1);
			}
		}
	}
	if (inpfil < 0)
		usage(ER_WARNING);
	exprmasks(2);
	syminit();
	for (pass=0; pass<3; ++pass) {
		aserr = 0;
		if (gflag && pass == 1)
			symglob();
		if (aflag && pass == 1)
			allglob();
		if (oflag && pass == 2)
			outgsd();
		flevel = 0;
		tlevel = 0;
		ifcnd[0] = 0;
		iflvl[0] = 0;
		radix = 10;
		srcline[0] = 0;
		page = 0;
		stb[0] = 0;
		lop  = NLPP;
		cfile = 0;
		strcpy(afn, srcfn[cfile]);
		afp = srcfp[cfile];
		incfil = -1;
		for (i = 0; i <= inpfil; i++)
			rewind(sfp[i]);
		ap = areap;
		while (ap) {
			ap->a_fuzz = 0;
			ap->a_size = 0;
			ap = ap->a_ap;
		}
		fuzz = 0;
		dot.s_addr = 0;
		dot.s_area = &dca;
		outbuf("I");
		outchk(0,0);
		symp = &dot;
		minit();
		while (getline()) {
			cp = cb;
			cpt = cbt;
			ep = eb;
			ip = ib;
			if (setjmp(jump_env) == 0)
				asmbl();
			if (pass == 2) {
				diag();
				list();
			}
		}
		newdot(dot.s_area); /* Flush area info */
		if (flevel || tlevel)
			err('i');
	}
	if (oflag)
		outchk(HUGE, HUGE);  /* Flush */
	if (sflag) {
		lstsym(tfp);
	} else
	if (lflag) {
		lstsym(lfp);
	}
	asexit(aserr ? ER_ERROR : ER_NONE);
	return(0);
}

/*)Function	VOID	asexit(i)
 *
 *			int	i	exit code
 *
 *	The function asexit() explicitly closes all open
 *	files and then terminates the program.
 *
 *	local variables:
 *		int	j		loop counter
 *
 *	global variables:
 *		FILE *	ifp[]		array of include-file file handles
 *		FILE *	lfp		list output file handle
 *		FILE *	ofp		relocation output file handle
 *		FILE *	tfp		symbol table output file handle
 *		FILE *	sfp[]		array of assembler-source file handles
 *
 *	functions called:
 *		int	fclose()	c-library
 *		VOID	exit()		c-library
 *
 *	side effects:
 *		All files closed. Program terminates.
 */

VOID
asexit(i)
int i;
{
	int j;

	if (lfp != NULL) fclose(lfp);
	if (ofp != NULL) fclose(ofp);
	if (tfp != NULL) fclose(tfp);

	for (j=0; j<MAXFIL && sfp[j] != NULL; j++) {
		fclose(sfp[j]);
	}

	for (j=0; j<MAXINC && ifp[j] != NULL; j++) {
		fclose(ifp[j]);
	}
	exit(i);
}

/*)Function	VOID	asmbl()
 *
 *	The function asmbl() scans the assembler-source text for
 *	(1) labels, global labels, equates, global equates, and local
 *	symbols, (2) .if, .else, .endif, and .page directives,
 *	(3) machine independent assembler directives, and (4) machine
 *	dependent mnemonics.
 *
 *	local variables:
 *		mne *	mp		pointer to a mne structure
 *		sym *	sp		pointer to a sym structure
 *		tsym *	tp		pointer to a tsym structure
 *		int	c		character from assembler-source
 *					text line
 *		area *	ap		pointer to an area structure
 *		expr	e1		expression structure
 *		char	id[]		id string
 *		char	opt[]		options string
 *		char	fn[]		filename string
 *		char *	p		pointer into a string
 *		int	d		temporary value
 *		int	n		temporary value
 *		int	uaf		user area options flag
 *		int	uf		area options
 *
 *	global variables:
 *		area *	areap		pointer to an area structure
 *		char	ctype[]		array of character types, one per
 *					ASCII character
 *		int	flevel		IF-ELSE-ENDIF flag will be non
 *					zero for false conditional case
 *		addr_t	fuzz		tracks pass to pass changes in the
 *					address of symbols caused by
 *					variable length instruction formats
 *		int	ifcnd[]		array of IF statement condition
 *					values (0 = FALSE) indexed by tlevel
 *		int	iflvl[]		array of IF-ELSE-ENDIF flevel
 *					values indexed by tlevel
 *		FILE *	ifp[]		array of include-file file handles
 *		char	incfn[][]	array of include file names
 *		int	incfp[]		array of include file path lengths
 *		int	incline[]	current include file line
 *		int	incfil		current file handle index
 *					for include files
 *		addr_t	laddr		address of current assembler line
 *					or value of .if argument
 *		int	lmode		listing mode
 *		int	lop		current line number on page
 *		char	module[]	module name string
 *		int	pass		assembler pass number
 *		int	radix		current number conversion radix:
 *					2 (binary), 8 (octal), 10 (decimal),
 *					16 (hexadecimal)
 *		char	stb[]		Subtitle string buffer
 *		sym *	symp		pointer to a symbol structure
 *		char	tb[]		Title string buffer
 *		int	tlevel		current conditional level
 *
 *	functions called:
 *		addr_t	absexpr()	asexpr.c
 *		area *	alookup()	assym.c
 *		VOID	clrexpr()	asexpr.c
 *		int	digit()		asexpr.c
 *		char	endline()	aslex.c
 *		VOID	err()		assubr.c
 *		VOID	expr()		asexpr.c
 *		int	fndidx()	asmain.c
 *		FILE *	fopen()		c-library
 *		int	get()		aslex.c
 *		VOID	getid()		aslex.c
 *		int	getmap()	aslex.c
 *		int	getnb()		aslex.c
 *		VOID	getst()		aslex.c
 *		sym *	lookup()	assym.c
 *		VOID	machin()	___mch.c
 *		mne *	mlookup()	assym.c
 *		int	more()		aslex.c
 *		VOID *	new()		assym.c
 *		VOID	newdot()	asmain.c
 *		VOID	outall()	asout.c
 *		VOID	outab()		asout.c
 *		VOID	outchk()	asout.c
 *		VOID	outrb()		asout.c
 *		VOID	outrw()		asout.c
 *		VOID	phase()		asmain.c
 *		VOID	qerr()		assubr.c
 *		char *	strcpy()	c-library
 *		char *	strncpy()	c-library
 *		char *	strsto()	assym.c
 *		VOID	unget()		aslex.c
 */

VOID
asmbl()
{
	register struct mne *mp;
	register struct sym *sp;
	register struct tsym *tp;
	register int c;
	struct area  *ap;
	struct expr e1;
	char id[NCPS];
	char opt[NCPS];
	char fn[FILSPC+FILSPC];
	char *p;
	int d, n, uaf, uf;

	laddr = dot.s_addr;
	lmode = SLIST;
loop:
	if ((c=endline()) == 0) { return; }
	/*
	 * If the first character is a digit then assume
	 * a local symbol is being specified.  The symbol
	 * must end with $: to be valid.
	 *	pass 0:
	 *		Construct a tsym structure at the first
	 *		occurance of the symbol.  Flag the symbol
	 *		as multiply defined if not the first occurance.
	 *	pass 1:
	 *		Load area, address, and fuzz values
	 *		into structure tsym.
	 *	pass 2:
	 *		Check for assembler phase error and
	 *		multiply defined error.
	 */
	if (ctype[c] & DIGIT) {
		if (flevel)
			return;
		n = 0;
		while ((d = digit(c, 10)) >= 0) {
			n = 10*n + d;
			c = get();
		}
		if (c != '$' || get() != ':')
			qerr();
		tp = symp->s_tsym;
		if (pass == 0) {
			while (tp) {
				if (n == tp->t_num) {
					tp->t_flg |= S_MDF;
					break;
				}
				tp = tp->t_lnk;
			}
			if (tp == NULL) {
				tp=(struct tsym *) new (sizeof(struct tsym));
				tp->t_lnk = symp->s_tsym;
				tp->t_num = n;
				tp->t_flg = 0;
				tp->t_area = dot.s_area;
				tp->t_addr = dot.s_addr;
				symp->s_tsym = tp;
			}
		} else {
			while (tp) {
				if (n == tp->t_num) {
					break;
				}
				tp = tp->t_lnk;
			}
			if (tp) {
				if (pass == 1) {
					fuzz = tp->t_addr - dot.s_addr;
					tp->t_area = dot.s_area;
					tp->t_addr = dot.s_addr;
				} else {
					phase(tp->t_area, tp->t_addr);
					if (tp->t_flg & S_MDF)
						err('m');
				}
			} else {
				err('u');
			}
		}
		lmode = ALIST;
		goto loop;
	}
	/*
	 * If the first character is a letter then assume a lable,
	 * symbol, assembler directive, or assembler mnemonic is
	 * being processed.
	 */
	if ((ctype[c] & LETTER) == 0) {
		if (flevel) {
			return;
		} else {
			qerr();
		}
	}
	getid(id, c);
	c = getnb();
	/*
	 * If the next character is a : then a label is being processed.
	 * A double :: defines a global label.  If this is new label
	 * then create a symbol structure.
	 *	pass 0:
	 *		Flag multiply defined labels.
	 *	pass 1:
	 *		Load area, address, and fuzz values
	 *		into structure symp.
	 *	pass 2:
	 *		Check for assembler phase error and
	 *		multiply defined error.
	 */
	if (c == ':') {
		if (flevel)
			return;
		if ((c = get()) != ':') {
			unget(c);
			c = 0;
		}
		symp = lookup(id);
		if (symp == &dot)
			err('.');
		if (pass == 0)
			if ((symp->s_type != S_NEW) &&
			   ((symp->s_flag & S_ASG) == 0))
				symp->s_flag |= S_MDF;
		if (pass != 2) {
			fuzz = symp->s_addr - dot.s_addr;
			symp->s_type = S_USER;
			symp->s_area = dot.s_area;
			symp->s_addr = dot.s_addr;
		} else {
			if (symp->s_flag & S_MDF)
				err('m');
			phase(symp->s_area, symp->s_addr);
		}
		if (c) {
			symp->s_flag |= S_GBL;
		}
		lmode = ALIST;
		goto loop;
	}
	/*
	 * If the next character is a = then an equate is being processed.
	 * A double == defines a global equate.  If this is a new variable
	 * then create a symbol structure.
	 */
	if (c == '=') {
		if (flevel)
			return;
		if ((c = get()) != '=') {
			unget(c);
			c = 0;
		}
		clrexpr(&e1);
		expr(&e1, 0);
		sp = lookup(id);
		if (sp == &dot) {
			outall();
			if (e1.e_flag || e1.e_base.e_ap != dot.s_area)
				err('.');
		} else
		if (sp->s_type != S_NEW && (sp->s_flag & S_ASG) == 0) {
			err('m');
		}
		sp->s_type = S_USER;
		sp->s_area = e1.e_base.e_ap;
		sp->s_addr = laddr = e1.e_addr;
		sp->s_flag |= S_ASG;
		if (c) {
			sp->s_flag |= S_GBL;
		}
		lmode = ELIST;
		goto loop;
	}
	unget(c);
	lmode = flevel ? SLIST : CLIST;
	if ((mp = mlookup(id)) == NULL) {
		if (!flevel)
			err('o');
		return;
	}
	/*
	 * If we have gotten this far then we have found an
	 * assembler directive or an assembler mnemonic.
	 *
	 * Check for .if, .else, .endif, and .page directives
	 * which are not controlled by the conditional flags
	 */
	switch (mp->m_type) {

	case S_IF:
		n = absexpr();
		if (tlevel < MAXIF) {
			++tlevel;
			ifcnd[tlevel] = n;
			iflvl[tlevel] = flevel;
			if (n == 0) {
				++flevel;
			}
		} else {
			err('i');
		}
		lmode = ELIST;
		laddr = n;
		return;

	case S_ELSE:
		if (ifcnd[tlevel]) {
			if (++flevel > (iflvl[tlevel]+1)) {
				err('i');
			}
		} else {
			if (--flevel < iflvl[tlevel]) {
				err('i');
			}
		}
		lmode = SLIST;
		return;

	case S_ENDIF:
		if (tlevel) {
			flevel = iflvl[tlevel--];
		} else {
			err('i');
		}
		lmode = SLIST;
		return;

	case S_PAGE:
		lop = NLPP;
		lmode = NLIST;
		return;

	default:
		break;
	}
	if (flevel)
		return;
	/*
	 * If we are not in a false state for .if/.else then
	 * process the assembler directives here.
	 */
	switch (mp->m_type) {

	case S_EVEN:
		outall();
		laddr = dot.s_addr = (dot.s_addr + 1) & ~1;
		lmode = ALIST;
		break;

	case S_ODD:
		outall();
		laddr = dot.s_addr |= 1;
		lmode = ALIST;
		break;

	case S_DATA:
		if ((addr_t) a_bytes < mp->m_valu) {
			err('o');
		}
		do {
			clrexpr(&e1);
			expr(&e1, 0);
			switch(mp->m_valu) {
			default:
			case 1:	outrb(&e1, R_NORM); break;
			case 2: outrw(&e1, R_NORM); break;
			case 3: outr3b(&e1, R_NORM); break;
			case 4: outr4b(&e1, R_NORM); break;
			}
		} while ((c = getnb()) == ',');
		unget(c);
		break;

	case S_ERROR:
		clrexpr(&e1);
		if (more()) {
			expr(&e1, 0);
		}
		if (e1.e_addr != 0) {
			err('e');
		}
		lmode = SLIST;
		break;

	case S_ASCII:
	case S_ASCIZ:
		if ((d = getnb()) == '\0')
			qerr();
		while ((c = getmap(d)) >= 0)
			outab(c);
		if (mp->m_type == S_ASCIZ)
			outab(0);
		break;

	case S_ASCIS:
		if ((d = getnb()) == '\0')
			qerr();
		c = getmap(d);
		while (c >= 0) {
			if ((n = getmap(d)) >= 0) {
				outab(c);
			} else {
				outab(c | 0x80);
			}
			c = n;
		}
		break;

	case S_BLK:
		if ((addr_t) a_bytes < mp->m_valu) {
			err('o');
		}
		clrexpr(&e1);
		expr(&e1, 0);
		outchk(HUGE,HUGE);
		dot.s_addr += e1.e_addr*mp->m_valu;
		lmode = BLIST;
		break;

	case S_TITLE:
		p = tb;
		if ((c = getnb()) != 0) {
			do {
				if (p < &tb[NTITL-1])
					*p++ = c;
			} while ((c = get()) != 0);
		}
		*p = 0;
		unget(c);
		lmode = SLIST;
		break;

	case S_SBTL:
		p = stb;
		if ((c = getnb()) != 0) {
			do {
				if (p < &stb[NSBTL-1])
					*p++ = c;
			} while ((c = get()) != 0);
		}
		*p = 0;
		unget(c);
		lmode = SLIST;
		break;

	case S_MODUL:
		getst(id, -1);
		if (pass == 0) {
			if (module[0]) {
				err('m');
			} else {
				strncpy(module, id, NCPS);
			}
		}
		lmode = SLIST;
		break;

	case S_GLOBL:
		do {
			getid(id, -1);
			sp = lookup(id);
			sp->s_flag |= S_GBL;
		} while ((c = getnb()) == ',');
		unget(c);
		lmode = SLIST;
		break;

	case S_DAREA:
		getid(id, -1);
		uaf = 0;
		uf  = A_CON|A_REL;
		if ((c = getnb()) == '(') {
			do {
				getid(opt, -1);
				mp = mlookup(opt);
				if (mp && mp->m_type == S_ATYP) {
					++uaf;
					uf |= mp->m_valu;
				} else {
					err('u');
				}
			} while ((c = getnb()) == ',');
			if (c != ')')
				qerr();
		} else {
			unget(c);
		}
		if ((ap = alookup(id)) != NULL) {
			if (uaf && uf != ap->a_flag)
				err('m');
		} else {
			ap = (struct area *) new (sizeof(struct area));
			ap->a_ap = areap;
			ap->a_id = strsto(id);
			ap->a_ref = areap->a_ref + 1;
			ap->a_size = 0;
			ap->a_fuzz = 0;
			ap->a_flag = uaf ? uf : (A_CON|A_REL);
			areap = ap;
		}
		newdot(ap);
		lmode = SLIST;
		break;

	case S_ORG:
		if (dot.s_area->a_flag & A_ABS) {
			outall();
			laddr = dot.s_addr = absexpr();
		} else {
			err('o');
		}
		outall();
		lmode = ALIST;
		break;

	case S_RADIX:
		if (more()) {
			switch (getnb()) {
			case 'b':
			case 'B':
				radix = 2;
				break;
			case '@':
			case 'o':
			case 'O':
			case 'q':
			case 'Q':
				radix = 8;
				break;
			case 'd':
			case 'D':
				radix = 10;
				break;
			case 'h':
			case 'H':
			case 'x':
			case 'X':
				radix = 16;
				break;
			default:
				radix = 10;
				qerr();
				break;
			}
		} else {
			radix = 10;
		}
		lmode = SLIST;
		break;

	case S_INCL:
		lmode = SLIST;
    		if (++incfil == MAXINC) {
			--incfil;
			err('i');
			break;
		}
		/*
		 * Copy path of file opening the include file
		 */
		strncpy(fn,afn,afp);
		p = fn + afp;
		/*
		 * Concatenate the .include file specification
		 */
		d = getnb();
		while ((c = get()) != d) {
			if (p < &fn[FILSPC+FILSPC-1]) {
				*p++ = c;
			} else {
				break;
			}
		}
		*p = 0;
		/*
		 * If .include specifies a path
		 * 	use it
		 * else
		 *	use path of file opening the include file
		 */
		if (fndidx(fn + afp) != 0) {
			afilex(fn + afp, "");
		} else {
			afilex(fn, "");
		}
		/*
		 * Open File
		 */
    		if ((ifp[incfil] = fopen(afntmp, "r")) == NULL) {
			--incfil;
			err('i');
		} else {
			lop = NLPP;
			incline[incfil] = 0;
			strcpy(afn, afntmp);
			afp = afptmp;
			strcpy(incfn[incfil],afn);
			incfp[incfil] = afp;
		}
		break;

	/*
	 * If not an assembler directive then go to
	 * the machine dependent function which handles
	 * all the assembler mnemonics.
	 */
	default:
		machine(mp);
	}
	goto loop;
}

/*)Function	FILE *	afile(fn, ft, wf)
 *
 *		char *	fn		file specification string
 *		char *	ft		file type string
 *		int	wf		read(0)/write(1) flag
 *
 *	The function afile() opens a file for reading or writing.
 *
 *	afile() returns a file handle for the opened file or aborts
 *	the assembler on an open error.
 *
 *	local variables:
 *		FILE *	fp		file handle for opened file
 *
 *	global variables:
 *		char	afn[]		afile() constructed filespec
 *		int	afp		afile() constructed path length
 *		char	afntmp[]	afilex() constructed filespec
 *		int	afptmp		afilex() constructed path length
 *
 *	functions called:
 *		VOID	afilex()	asmain.c
 *		int	fndidx()	asmain.c
 *		FILE *	fopen()		c_library
 *		int	fprintf()	c_library
 *		char *	strcpy()	c_library
 *
 *	side effects:
 *		File is opened for read or write.
 */

FILE *
afile(fn, ft, wf)
char *fn;
char *ft;
int wf;
{
	FILE *fp;

	afilex(fn, ft);

	if ((fp = fopen(afntmp, wf?"w":"r")) == NULL) {
	    fprintf(stderr, "%s: cannot %s.\n", afntmp, wf?"create":"open");
	    asexit(ER_FATAL);
	}

	strcpy(afn, afntmp);
	afp = afptmp;

	return (fp);
}

/*)Function	VOID	afilex(fn, ft)
 *
 *		char *	fn		file specification string
 *		char *	ft		file type string
 *
 *	The function afilex() processes the file specification string:
 *		(1)	If the file type specification string ft
 *			is not NULL then a file specification is
 *			constructed with the file path\name in fn
 *			and the extension in ft.
 *		(2)	If the file type specification string ft
 *			is NULL then the file specification is
 *			constructed from fn.  If fn does not have
 *			a file type then the default source file
 *			type dsft is appended to the file specification.
 *
 *	afilex() aborts the assembler on a file specification length error.
 *
 *	local variables:
 *		int	c		character value
 *		char *	p1		pointer into filespec string afntmp
 *		char *	p2		pointer into filespec string fn
 *		char *	p3		pointer to filetype string ft
 *
 *	global variables:
 *		char	afntmp[]	afilex() constructed filespec
 *		int	afptmp		afilex() constructed path length
 *		char	dsft[]		default assembler file type string
 *
 *	functions called:
 *		VOID	asexit()	asmain.c
 *		int	fndidx()	asmain.c
 *		int	fprintf()	c_library
 *		char *	strcpy()	c_library
 *
 *	side effects:
 *		File specification string may be modified.
 */

VOID
afilex(fn, ft)
char *fn;
char *ft;
{
	register char *p1, *p2, *p3;
	register int c;

	if (strlen(fn) > (FILSPC-5)) {
		fprintf(stderr, "File Specification %s is too long.", fn);
		asexit(ER_FATAL);
	}

	/*
	 * Save the File Name Index
	 */
	strcpy(afntmp, fn);
	afptmp = fndidx(afntmp);
	p1 = &afntmp[afptmp];
	p2 = &fn[afptmp];

	/*
	 * Skip to File Extension Seperator
	 */
	while (((c = *p2++) != 0) && (c != FSEPX)) {
		p1++;
	}
	*p1++ = FSEPX;

	/*
	 * Copy File Extension
	 */
	 p3 = ft;
	 if (*p3 == 0) {
		if (c == FSEPX) {
			p3 = p2;
		} else {
			p3 = dsft;
		}
	}
	while ((c = *p3++) != 0) {
		if (p1 < &afntmp[FILSPC-1])
			*p1++ = c;
	}
	*p1++ = 0;
}

/*)Function	int	fndidx(str)
 *
 *		char *	str		file specification string
 *
 *	The function fndidx() scans the file specification string
 *	to find the index to the file name.  If the file
 *	specification contains a 'path' then the index will
 *	be non zero.
 *
 *	fndidx() returns the index value.
 *
 *	local variables:
 *		char *	p1		temporary pointer
 *		char *	p2		temporary pointer
 *
 *	global variables:
 *		none
 *
 *	functions called:
 *		char *	strrchr()	c_library
 *
 *	side effects:
 *		none
 */

int
fndidx(str)
char *str;
{
	register char *p1, *p2;

	/*
	 * Skip Path Delimiters
	 */
	p1 = str;
	if ((p2 = strrchr(p1,  ':')) != NULL) { p1 = p2 + 1; }
	if ((p2 = strrchr(p1,  '/')) != NULL) { p1 = p2 + 1; }
	if ((p2 = strrchr(p1, '\\')) != NULL) { p1 = p2 + 1; }

	return(p1 - str);
}

/*)Function	VOID	newdot(nap)
 *
 *		area *	nap		pointer to the new area structure
 *
 *	The function newdot():
 *		(1)	copies the current values of fuzz and the last
 *			address into the current area referenced by dot
 *		(2)	loads dot with the pointer to the new area and
 *			loads the fuzz and last address parameters
 *		(3)	outall() is called to flush any remaining
 *			bufferred code from the old area to the output
 *
 *	local variables:
 *		area *	oap		pointer to old area
 *
 *	global variables:
 *		sym	dot		defined as sym[0]
 *		addr_t	fuzz		tracks pass to pass changes in the
 *					address of symbols caused by
 *					variable length instruction formats
 *
 *	functions called:
 *		none
 *
 *	side effects:
 *		Current area saved, new area loaded, buffers flushed.
 */

VOID
newdot(nap)
register struct area *nap;
{
	register struct area *oap;

	oap = dot.s_area;
	oap->a_fuzz = fuzz;
	oap->a_size = dot.s_addr;
	fuzz = nap->a_fuzz;
	dot.s_area = nap;
	dot.s_addr = nap->a_size;
	outall();
}

/*)Function	VOID	phase(ap, a)
 *
 *		area *	ap		pointer to area
 *		addr_t	a		address in area
 *
 *	Function phase() compares the area ap and address a
 *	with the current area dot.s_area and address dot.s_addr
 *	to determine if the position of the symbol has changed
 *	between assembler passes.
 *
 *	local variables:
 *		none
 *
 *	global varaibles:
 *		sym *	dot		defined as sym[0]
 *
 *	functions called:
 *		none
 *
 *	side effects:
 *		The p error is invoked if the area and/or address
 *		has changed.
 */

VOID
phase(ap, a)
struct area *ap;
addr_t a;
{
	if (ap != dot.s_area || a != dot.s_addr)
		err('p');
}

char *usetxt[] = {
	"Usage: [-dqxgalospwzf] file1 [file2 file3 ...]",
	"  d    decimal listing",
	"  q    octal   listing",
	"  x    hex     listing (default)",
	"  g    undefined symbols made global",
	"  a    all user symbols made global",
	"  l    create list   output file1[.lst]",
	"  o    create object output file1[.rel]",
	"  s    create symbol output file1[.sym]",
	"  p    disable listing pagination",
	"  w    wide listing format for symbol table",
	"  z    enable case sensitivity for symbols",
	"  f    flag relocatable references by  `   in listing file",
	" ff    flag relocatable references by mode in listing file",
	"",
	NULL
};

/*)Function	VOID	usage(n)
 *
 *		int	n		exit code
 *
 *	The function usage() outputs to the stderr device the
 *	assembler name and version and a list of valid assembler options.
 *
 *	local variables:
 *		char **	dp		pointer to an array of
 *					text string pointers.
 *
 *	global variables:
 *		char	cpu[]		assembler type string
 *		char *	usetxt[]	array of string pointers
 *
 *	functions called:
 *		VOID	asexit()	asmain.c
 *		int	fprintf()	c_library
 *
 *	side effects:
 *		program is terminated
 */

VOID
usage(n)
int n;
{
	register char   **dp;

	fprintf(stderr, "\nASxxxx Assembler %s  (%s)\n\n", VERSION, cpu);
	for (dp = usetxt; *dp; dp++)
		fprintf(stderr, "%s\n", *dp);
	asexit(n);
}