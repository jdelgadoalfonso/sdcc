/*-------------------------------------------------------------------------

   device.c - Accomodates subtle variations in PIC devices
   Written By -  Scott Dattalo scott@dattalo.com

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
-------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "common.h"   // Include everything in the SDCC src directory
#include "newalloc.h"


#include "main.h"
#include "pcode.h"
#include "ralloc.h"
#include "device.h"

extern int Gstack_base_addr;
extern int Gstack_size;

#define MAX_PICLIST 200
static PIC_device *Pics[MAX_PICLIST];
static int num_of_supported_PICS = 0;

static PIC_device *pic=NULL;

int maxRAMaddress = 0;

#define CONFIG_WORD_ADDRESS 0x2007
#define CONFIG2_WORD_ADDRESS 0x2008
#define DEFAULT_CONFIG_WORD 0x3fff
#define DEFAULT_CONFIG2_WORD 0x3ffc

#define DEVICE_FILE_NAME "pic14devices.txt"
#define PIC14_STRING_LEN 256
#define SPLIT_WORDS_MAX 16

static unsigned int config_word = DEFAULT_CONFIG_WORD;
static unsigned int config2_word = DEFAULT_CONFIG2_WORD;
static memRange *rangeRAM = NULL;


/* parse a value from the configuration file */
static int parse_config_value(char *str)
{
	if (str[strlen(str) - 1] == 'K')
		return atoi(str) * 1024;        /* like "1K" */
		
	else if (STRNCASECMP(str, "0x", 2) == 0)
		return strtol(str+2, NULL, 16); /* like "0x400" */
	
	else
		return atoi(str);               /* like "1024" */
}


/* split a line into words */
static int split_words(char result_word[SPLIT_WORDS_MAX][PIC14_STRING_LEN], char *str)
{
	char *pos = str;
	int num_words = 0;
	int ccount;
	
	while (*pos != '\0' && num_words < SPLIT_WORDS_MAX) {
		/* remove leading spaces */
		while (isspace(*pos) || *pos == ',')
			pos++;
	
		/* copy everything up until the first space or comma */
		for (ccount = 0; *pos != '\0' && !isspace(*pos) && *pos != ',' && ccount < PIC14_STRING_LEN-1; ccount++, pos++)
			result_word[num_words][ccount] = *pos;
		result_word[num_words][ccount] = '\0';
		
		num_words++;
	}
	
	return num_words;
}


/* remove annoying prefixes from the processor name */
static char *sanitise_processor_name(char *name)
{
	char *proc_pos = name;

	if (name == NULL)
		return NULL;
	
	if (STRNCASECMP(proc_pos, "pic", 3) == 0)
		proc_pos += 3;

	else if (tolower(*proc_pos) == 'p')
		proc_pos += 1;
				
	return proc_pos;
}


/* create a structure for a pic processor */
static PIC_device *create_pic(char *pic_name, int maxram, int bankmsk, int confsiz, int program, int data, int eeprom, int io)
{
	PIC_device *new_pic;
	char *simple_pic_name = sanitise_processor_name(pic_name);
	
	new_pic = Safe_calloc(1, sizeof(PIC_device));
	new_pic->name = Safe_calloc(strlen(simple_pic_name)+1, sizeof(char));
	strcpy(new_pic->name, simple_pic_name);
			
	new_pic->defMaxRAMaddrs = maxram;
	new_pic->bankMask = bankmsk;
	new_pic->hasSecondConfigReg = confsiz > 1;
	
	new_pic->programMemSize = program;
	new_pic->dataMemSize = data;
	new_pic->eepromMemSize = eeprom;
	new_pic->ioPins = io;

	new_pic->ram = rangeRAM;
	
	Pics[num_of_supported_PICS] = new_pic;
	num_of_supported_PICS++;
			
	return new_pic;
}


/* mark some registers as being duplicated across banks */
static void register_map(int num_words, char word[SPLIT_WORDS_MAX][PIC14_STRING_LEN])
{
	memRange *r;
	int pcount;
	
	if (num_words < 3) {
		fprintf(stderr, "WARNING: not enough values in %s regmap directive\n", DEVICE_FILE_NAME);
		return;
	}

	for (pcount = 2; pcount < num_words; pcount++) {
		r = Safe_calloc(1, sizeof(memRange));
		
		r->start_address = parse_config_value(word[pcount]);
		r->end_address = parse_config_value(word[pcount]);
		r->alias = parse_config_value(word[1]);
		r->bank = (r->start_address >> 7) & 3;
		// add memRange to device entry for future lookup (sharebanks)
		r->next = rangeRAM;
		rangeRAM = r;
	}
}


/* define ram areas - may be duplicated across banks */
static void ram_map(int num_words, char word[SPLIT_WORDS_MAX][PIC14_STRING_LEN])
{
	memRange *r;
	
	if (num_words < 4) {
		fprintf(stderr, "WARNING: not enough values in %s memmap directive\n", DEVICE_FILE_NAME);
		return;
	}

	r = Safe_calloc(1, sizeof(memRange));
	//fprintf (stderr, "%s: %s %s %s\n", __FUNCTION__, word[1], word[2], word[3]);
	
	r->start_address = parse_config_value(word[1]);
	r->end_address = parse_config_value(word[2]);
	r->alias = parse_config_value(word[3]);
	r->bank = (r->start_address >> 7) & 3;
		
	// add memRange to device entry for future lookup (sharebanks)
	r->next = rangeRAM;
	rangeRAM = r;
}

extern set *includeDirsSet;
extern set *userIncDirsSet;
extern set *libDirsSet;
extern set *libPathsSet;

/* read the file with all the pic14 definitions and pick out the definition
 * for a processor if specified. if pic_name is NULL reads everything */
static PIC_device *find_device(char *pic_name)
{
	FILE *pic_file;
	char pic_buf[PIC14_STRING_LEN];
	char *pic_buf_pos;
	int found_processor = FALSE;
	int done = FALSE;
	char processor_name[SPLIT_WORDS_MAX][PIC14_STRING_LEN];
	int num_processor_names = 0;
	int pic_maxram = 0;
	int pic_bankmsk = 0;
	int pic_confsiz = 0;
	int pic_program = 0;
	int pic_data = 0;
	int pic_eeprom = 0;
	int pic_io = 0;
	char *simple_pic_name;
	char *dir;
	char filename[512];
	int len = 512;
	
	/* allow abbreviations of the form "f877" - convert to "16f877" */
	simple_pic_name = sanitise_processor_name(pic_name);
	num_of_supported_PICS = 0;
	
	/* open the piclist file */
	/* first scan all include directories */
	pic_file = NULL;
	//fprintf( stderr, "%s: searching %s\n", __FUNCTION__, DEVICE_FILE_NAME );
	for (dir = setFirstItem(userIncDirsSet);
		!pic_file && dir;
		dir = setNextItem(userIncDirsSet))
	{
	  //fprintf( stderr, "searching1 %s\n", dir );
	  SNPRINTF(&filename[0], len, "%s%s", dir,
	    DIR_SEPARATOR_STRING DEVICE_FILE_NAME);
	  pic_file = fopen( filename, "rt" );
	  if (pic_file) break;
	} // for

	for (dir = setFirstItem(includeDirsSet);
		!pic_file && dir;
		dir = setNextItem(includeDirsSet))
	{
	  //fprintf( stderr, "searching2 %s\n", dir );
	  SNPRINTF(&filename[0], len, "%s%s", dir,
	    DIR_SEPARATOR_STRING DEVICE_FILE_NAME);
	  pic_file = fopen( filename, "rt" );
	  if (pic_file) break;
	} // for

	for (dir = setFirstItem(libDirsSet);
		!pic_file && dir;
		dir = setNextItem(libDirsSet))
	{
	  //fprintf( stderr, "searching3 %s\n", dir );
	  SNPRINTF(&filename[0], len, "%s%s", dir,
	    DIR_SEPARATOR_STRING DEVICE_FILE_NAME);
	  pic_file = fopen( filename, "rt" );
	  if (pic_file) break;
	} // for

	for (dir = setFirstItem(libPathsSet);
		!pic_file && dir;
		dir = setNextItem(libPathsSet))
	{
	  //fprintf( stderr, "searching4 %s\n", dir );
	  SNPRINTF(&filename[0], len, "%s%s", dir,
	    DIR_SEPARATOR_STRING DEVICE_FILE_NAME);
	  pic_file = fopen( filename, "rt" );
	  if (pic_file) break;
	} // for

	if (!pic_file) {
	  SNPRINTF(&filename[0], len, "%s",
	    DATADIR LIB_DIR_SUFFIX
	    DIR_SEPARATOR_STRING "pic"
	    DIR_SEPARATOR_STRING DEVICE_FILE_NAME);
	  pic_file = fopen( filename, "rt" );
	} // if

        if (pic_file == NULL) {
            fprintf(stderr, "can't find %s\n", DEVICE_FILE_NAME);
            return NULL;
        } // if

	if (options.verbose) {
	    printf ("Using devices from %s.\n", filename);
	} // if
	
	/* read line by line */
	pic_buf[sizeof(pic_buf)-1] = '\0';
	while (fgets(pic_buf, sizeof(pic_buf)-1, pic_file) != NULL && !done) {
		unsigned llen;
		llen = strlen (pic_buf);
		
		/* remove trailing spaces */
		while (llen && isspace(pic_buf[llen-1])) {
			pic_buf[llen-1] = '\0';
			llen--;
		}
		
		/* remove leading spaces */
		for (pic_buf_pos = pic_buf; isspace(*pic_buf_pos); pic_buf_pos++)
		{}
		
		/* ignore comment / empty lines */
		if (*pic_buf_pos != '\0' && *pic_buf_pos != '#') {
			
			/* split into fields */
			char pic_word[SPLIT_WORDS_MAX][PIC14_STRING_LEN];
			int num_pic_words;
			int wcount;
			
			num_pic_words = split_words(pic_word, pic_buf_pos);
			
			if (STRCASECMP(pic_word[0], "processor") == 0) {
			
				if (pic_name == NULL) {
					/* this is the mode where we read all the processors in - store the names for now */
					if (num_processor_names > 0) {
						/* store away all the previous processor definitions */
						int dcount;
						
						for (dcount = 1; dcount < num_processor_names; dcount++)
							create_pic(processor_name[dcount], pic_maxram, pic_bankmsk,
							           pic_confsiz, pic_program, pic_data, pic_eeprom, pic_io);
					}
					
					num_processor_names = split_words(processor_name, pic_buf_pos);
				}
				else {
					/* if we've just completed reading a processor definition stop now */
					if (found_processor)
						done = TRUE;
					else {
						/* check if this processor name is a match */
						for (wcount = 1; wcount < num_pic_words; wcount++) {
							
							/* skip uninteresting prefixes */
							char *found_name = sanitise_processor_name(pic_word[wcount]);

							if (STRCASECMP(found_name, simple_pic_name) == 0)
								found_processor = TRUE;
						}
					}
				}
			}
			
			else {
				if (found_processor || pic_name == NULL) {
					/* only parse a processor section if we've found the one we want */
					if (STRCASECMP(pic_word[0], "maxram") == 0 && num_pic_words > 1) {
						pic_maxram = parse_config_value(pic_word[1]);
						setMaxRAM(pic_maxram);
					}
					else if (STRCASECMP(pic_word[0], "bankmsk") == 0 && num_pic_words > 1)
						pic_bankmsk = parse_config_value(pic_word[1]);
			
					else if (STRCASECMP(pic_word[0], "confsiz") == 0 && num_pic_words > 1)
						pic_confsiz = parse_config_value(pic_word[1]);
			
					else if (STRCASECMP(pic_word[0], "program") == 0 && num_pic_words > 1)
						pic_program = parse_config_value(pic_word[1]);
			
					else if (STRCASECMP(pic_word[0], "data") == 0 && num_pic_words > 1)
						pic_data = parse_config_value(pic_word[1]);
			
					else if (STRCASECMP(pic_word[0], "eeprom") == 0 && num_pic_words > 1)
						pic_eeprom = parse_config_value(pic_word[1]);
			
					else if (STRCASECMP(pic_word[0], "io") == 0 && num_pic_words > 1)
						pic_io = parse_config_value(pic_word[1]);
			
					else if (STRCASECMP(pic_word[0], "regmap") == 0 && num_pic_words > 2) {
						if (found_processor)
							register_map(num_pic_words, pic_word);
					}
					else if (STRCASECMP(pic_word[0], "memmap") == 0 && num_pic_words > 2) {
						if (found_processor)
							ram_map(num_pic_words, pic_word);
					}
					else {
						fprintf(stderr, "WARNING: %s: bad syntax `%s'\n", DEVICE_FILE_NAME, pic_word[0]);
					}
				}
			}
		}
	}
	
	fclose(pic_file);

	/* if we're in read-the-lot mode then create the final processor definition */
	if (pic_name == NULL) {
	    
		if (num_processor_names > 0) {
			/* store away all the previous processor definitions */
			int dcount;
		
			for (dcount = 1; dcount < num_processor_names; dcount++)
				create_pic(processor_name[dcount], pic_maxram, pic_bankmsk,
				           pic_confsiz, pic_program, pic_data, pic_eeprom, pic_io);
		}
	}
	else {
		/* in search mode */
		if (found_processor) {
			/* create a new pic entry */
			return create_pic(pic_name, pic_maxram, pic_bankmsk,
			                  pic_confsiz, pic_program, pic_data, pic_eeprom, pic_io);
		}
	}
	
	return NULL;
}

void setMaxRAM(int size)
{
	maxRAMaddress = size;
	
	if (maxRAMaddress < 0) {
		fprintf(stderr, "invalid maxram 0x%x setting in %s\n",
			maxRAMaddress, DEVICE_FILE_NAME);
		return;
	}
}

/*-----------------------------------------------------------------*
*-----------------------------------------------------------------*/

int isREGinBank(regs *reg, int bank)
{
	
	if(!reg || !pic)
		return 0;
	
	if((int)((reg->address | reg->alias) & pic->bankMask & bank) == bank)
		return 1;
	
	return 0;
}

/*-----------------------------------------------------------------*
*-----------------------------------------------------------------*/
int REGallBanks(regs *reg)
{
	
	if(!reg || !pic)
		return 0;
	
	return ((reg->address | reg->alias) & pic->bankMask);
	
}

/*-----------------------------------------------------------------*
 *  void list_valid_pics(int ncols, int list_alias)
 *
 * Print out a formatted list of valid PIC devices
 *
 * ncols - number of columns in the list.
 *
 * list_alias - if non-zero, print all of the supported aliases
 *              for a device (e.g. F84, 16F84, etc...)
 *-----------------------------------------------------------------*/
void list_valid_pics(int ncols)
{
	int col=0,longest;
	int i,k,l;
	
	if (num_of_supported_PICS == 0)
		find_device(NULL);          /* load all the definitions */
	
	/* decrement the column number if it's greater than zero */
	ncols = (ncols > 1) ? ncols-1 : 4;
	
	/* Find the device with the longest name */
	for(i=0,longest=0; i<num_of_supported_PICS; i++) {
		k = strlen(Pics[i]->name);
		if(k>longest)
			longest = k;
	}
	
#if 1
	/* heading */
	fprintf(stderr, "\nPIC14 processors and their characteristics:\n\n");
	fprintf(stderr, " processor");
	for(k=0; k<longest-1; k++)
		fputc(' ',stderr);
	fprintf(stderr, "program     RAM      EEPROM    I/O\n");
	fprintf(stderr, "-----------------------------------------------------\n");
	
	for(i=0;  i < num_of_supported_PICS; i++) {
		fprintf(stderr,"  %s", Pics[i]->name);
		l = longest + 2 - strlen(Pics[i]->name);
		for(k=0; k<l; k++)
			fputc(' ',stderr);
	
		fprintf(stderr, "     ");
		if (Pics[i]->programMemSize % 1024 == 0)
			fprintf(stderr, "%4dK", Pics[i]->programMemSize / 1024);
		else
			fprintf(stderr, "%5d", Pics[i]->programMemSize);
	
		fprintf(stderr, "     %5d     %5d     %4d\n", 
			Pics[i]->dataMemSize, Pics[i]->eepromMemSize, Pics[i]->ioPins);
	}

	col = 0;
	
	fprintf(stderr, "\nPIC14 processors supported:\n");
	for(i=0;  i < num_of_supported_PICS; i++) {
			
		fprintf(stderr,"%s", Pics[i]->name);
		if(col<ncols) {
			l = longest + 2 - strlen(Pics[i]->name);
			for(k=0; k<l; k++)
				fputc(' ',stderr);
				
			col++;
				
		} else {
			fputc('\n',stderr);
			col = 0;
		}
		
	}
#endif
	if(col != 0)
		fputc('\n',stderr);
}

/*-----------------------------------------------------------------*
*  
*-----------------------------------------------------------------*/
PIC_device *init_pic(char *pic_type)
{
	char long_name[PIC14_STRING_LEN];
	
	pic = find_device(pic_type);
	
	if (pic == NULL) {
		/* check for shortened "16xxx" form */
		sprintf(long_name, "16%s", pic_type);
		pic = find_device(long_name);
		if (pic == NULL) {
			if(pic_type != NULL && pic_type[0] != '\0')
				fprintf(stderr, "'%s' was not found.\n", pic_type);
			else
				fprintf(stderr, "No processor has been specified (use -pPROCESSOR_NAME)\n");
		
			list_valid_pics(7);
			exit(1);
		}
	}
	return pic;
}

/*-----------------------------------------------------------------*
*  
*-----------------------------------------------------------------*/
int picIsInitialized(void)
{
	if(pic && maxRAMaddress > 0)
		return 1;
	
	return 0;
	
}

/*-----------------------------------------------------------------*
*  char *processor_base_name(void) - Include file is derived from this.
*-----------------------------------------------------------------*/
char *processor_base_name(void)
{
	
	if(!pic)
		return NULL;
	
	return pic->name;
}

/*-----------------------------------------------------------------*
*-----------------------------------------------------------------*/
int validAddress(int address, int reg_size)
{
	if (maxRAMaddress < 0) {
		fprintf(stderr, "missing maxram setting in %s\n", DEVICE_FILE_NAME);
		return 0;
	}
	//  fprintf(stderr, "validAddress: Checking 0x%04x\n",address);
	assert (reg_size > 0);
	if(address + (reg_size - 1) > maxRAMaddress)
		return 0;
	
	return 1;
}

#if 0
/* The following code should be (and is) implemented in the linker. */

/*-----------------------------------------------------------------*
*-----------------------------------------------------------------*/
void mapRegister(regs *reg)
{
	
	unsigned i;
	int alias;
	
	if(!reg || !reg->size) {
		fprintf(stderr,"WARNING: %s:%s:%d Bad register\n",__FILE__,__FUNCTION__,__LINE__);
		return;
	}
	
	if (maxRAMaddress < 0) {
		fprintf(stderr, "missing maxram setting in %s\n", DEVICE_FILE_NAME);
		return;
	}
	
	for(i=0; i<reg->size; i++) {
		
		assert(reg->address >= 0 && reg->address < maxRAMaddress);
		
		alias = finalMapping[reg->address].alias;
		reg->alias = alias;
		
		do {
			
			//fprintf(stdout,"mapping %s to address 0x%02x, reg size = %d\n",reg->name, (reg->address+alias+i),reg->size);
			
			finalMapping[reg->address + alias + i].reg = reg;
			finalMapping[reg->address + alias + i].instance = i;
			
			/* Decrement alias */
			if(alias)
				alias -= ((alias & (alias - 1)) ^ alias);
			else
				alias--;
			
		} while (alias>=0);
	}
	
	//fprintf(stderr,"%s - %s addr = 0x%03x, size %d\n",__FUNCTION__,reg->name, reg->address,reg->size);
	
	reg->isMapped = 1;
	
}

/*-----------------------------------------------------------------*
*-----------------------------------------------------------------*/
int assignRegister(regs *reg, int start_address)
{
	int i;
	
	//fprintf(stderr,"%s -  %s start_address = 0x%03x\n",__FUNCTION__,reg->name, start_address);
	if(reg->isFixed) {
		
		if (validAddress(reg->address,reg->size)) {
			//fprintf(stderr,"%s -  %s address = 0x%03x\n",__FUNCTION__,reg->name, reg->address);
			mapRegister(reg);
			return reg->address;
		}
		
		if (getenv("SDCCPICDEBUG")) {
			fprintf(stderr, "WARNING: Ignoring Out of Range register assignment at fixed address %d, %s\n",
			    reg->address, reg->name);
		}
		
	} else {
		
	/* This register does not have a fixed address requirement
	* so we'll search through all availble ram address and
		* assign the first one */
		
		for (i=start_address; i<=maxRAMaddress; i++) {
			
			if (validAddress(i,reg->size)) {
				reg->address = i;
				mapRegister(reg);
				return i;
			}
		}
		
		fprintf(stderr, "WARNING: No more RAM available for %s\n",reg->name);
		
	}
	
	return -1;
}

/*-----------------------------------------------------------------*
*-----------------------------------------------------------------*/
void assignFixedRegisters(set *regset)
{
	regs *reg;
	
	for (reg = setFirstItem(regset) ; reg ; 
	reg = setNextItem(regset)) {
		
		if(reg->isFixed) 
			assignRegister(reg,0);
	}
	
}

/*-----------------------------------------------------------------*
*-----------------------------------------------------------------*/
void assignRelocatableRegisters(set *regset, int used)
{
	
	regs *reg;
	int address = 0;
	
	for (reg = setFirstItem(regset) ; reg ; 
	reg = setNextItem(regset)) {
		
		//fprintf(stdout,"assigning %s (%d) isFixed=%d, wasUsed=%d\n",reg->name,reg->size,reg->isFixed,reg->wasUsed);
		
		if((!reg->isExtern) && (!reg->isFixed) && ( used || reg->wasUsed)) {
			/* If register have been reused then shall not print it a second time. */
			set *s;
			int done = 0;
			for (s = regset; s; s = s->next) {
				regs *r;
				r = s->item;
				if (r == reg)
					break;
				if((!r->isFixed) && ( used || r->wasUsed)) {
					if (r->rIdx == reg->rIdx) {
						reg->address = r->address;
						done = 1;
						break;
					}
				}
			}
			if (!done)
				address = assignRegister(reg,address);
		}
	}
	
}
#endif

/* Keep track of whether we found an assignment to the __config words. */
static int pic14_hasSetConfigWord = 0;

/*-----------------------------------------------------------------*
 *  void assignConfigWordValue(int address, int value)
 *
 * Most midrange PICs have one config word at address 0x2007.
 * Newer PIC14s have a second config word at address 0x2008.
 * This routine will assign values to those addresses.
 *
 *-----------------------------------------------------------------*/

void pic14_assignConfigWordValue(int address, int value)
{
	if (CONFIG_WORD_ADDRESS == address)
		config_word = value;
	
	else if (CONFIG2_WORD_ADDRESS == address)
		config2_word = value;
	
	//fprintf(stderr,"setting config word 0x%x to 0x%x\n", address, value);
	pic14_hasSetConfigWord = 1;
}

/*-----------------------------------------------------------------*
 * int pic14_emitConfigWord (FILE * vFile)
 * 
 * Emit the __config directives iff we found a previous assignment
 * to the config word.
 *-----------------------------------------------------------------*/
extern char *iComments2;
int pic14_emitConfigWord (FILE * vFile)
{
  if (pic14_hasSetConfigWord)
  {
    fprintf (vFile, "%s", iComments2);
    fprintf (vFile, "; config word \n");
    fprintf (vFile, "%s", iComments2);
    if (pic14_getHasSecondConfigReg())
    {
      fprintf (vFile, "\t__config _CONFIG1, 0x%x\n", pic14_getConfigWord(0x2007));
      fprintf (vFile, "\t__config _CONFIG2, 0x%x\n", pic14_getConfigWord(0x2008));
    }
    else
      fprintf (vFile, "\t__config 0x%x\n", pic14_getConfigWord(0x2007));

    return 1;
  }
  return 0;
}

/*-----------------------------------------------------------------*
 * int pic14_getConfigWord(int address)
 *
 * Get the current value of a config word.
 *
 *-----------------------------------------------------------------*/

int pic14_getConfigWord(int address)
{
	switch (address)
	{
	case CONFIG_WORD_ADDRESS:
		return config_word;
	
	case CONFIG2_WORD_ADDRESS:
		return config2_word;
	
	default:
		return 0;
	}
}

/*-----------------------------------------------------------------*
*  
*-----------------------------------------------------------------*/
unsigned pic14_getMaxRam(void)
{
	return pic->defMaxRAMaddrs;
}


/*-----------------------------------------------------------------*
*  int getHasSecondConfigReg(void) - check if the device has a 
*  second config register, rather than just one.
*-----------------------------------------------------------------*/
int pic14_getHasSecondConfigReg(void)
{
	if(!pic)
		return 0;
	else
		return pic->hasSecondConfigReg;
}

/*-----------------------------------------------------------------*
 * True iff the device has memory aliased in every bank.
 * If true, low and high will be set to the low and high address
 * occupied by the (last) sharebank found.
 *-----------------------------------------------------------------*/
int pic14_hasSharebank(int *low, int *high, int *size)
{
	memRange *r;

	assert(pic);
	r = pic->ram;

	while (r) {
	    //fprintf (stderr, "%s: region %x..%x, bank %x, alias %x, pic->bankmask %x, min_size %d\n",  __FUNCTION__, r->start_address, r->end_address, r->bank, r->alias, pic->bankMask, size ? *size : 0);
	    // find sufficiently large shared region
	    if ((r->alias == pic->bankMask)
		    && (r->end_address != r->start_address) // ignore SFRs
		    && (!size || (*size <= (r->end_address - r->start_address + 1))))
	    {
		if (low) *low = r->start_address;
		if (high) *high = r->end_address;
		if (size) *size = r->end_address - r->start_address + 1;
		return 1;
	    } // if
	    r = r->next;
	} // while

	if (low) *low = 0x0;
	if (high) *high = 0x0;
	if (size) *size = 0x0;
	//fprintf (stderr, "%s: no shared bank found\n", __FUNCTION__);
	return 0;
}

/*
 * True iff the memory region [low, high] is aliased in all banks.
 */
int pic14_isShared(int low, int high)
{
	memRange *r;

	assert(pic);
	r = pic->ram;

	while (r) {
	    //fprintf (stderr, "%s: region %x..%x, bank %x, alias %x, pic->bankmask %x\n", __FUNCTION__, r->start_address, r->end_address, r->bank, r->alias, pic->bankMask);
	    if ((r->alias == pic->bankMask) && (r->start_address <= low) && (r->end_address >= high)) {
		return 1;
	    } // if
	    r = r->next;
	} // while

	return 0;
}

/*
 * True iff all RAM is aliased in all banks (no BANKSELs required except for
 * SFRs).
 */
int pic14_allRAMShared(void)
{
	memRange *r;

	assert(pic);
	r = pic->ram;

	while (r) {
	    if (r->alias != pic->bankMask) return 0;
	    r = r->next;
	} // while
	
	return 1;
}

/*
 * True iff the pseudo stack is a sharebank --> let linker place it.
 * [low, high] denotes a size byte long block of (shared or banked)
 * memory to be used.
 */
int pic14_getSharedStack(int *low, int *high, int *size)
{
    int haveShared;
    int l, h, s;

    s = options.stack_size ? options.stack_size : 0x10;
    haveShared = pic14_hasSharebank(&l, &h, &s);
    if ((options.stack_loc != 0) || !haveShared)
    {
	// sharebank not available or not to be used
	s = options.stack_size ? options.stack_size : 0x10;
	l = options.stack_loc ? options.stack_loc : 0x20;
	h = l + s - 1;
	if (low) *low = l;
	if (high) *high = h;
	if (size) *size = s;
	// return 1 iff [low, high] is present in all banks
	//fprintf(stderr, "%s: low %x, high %x, size %x, shared %d\n", __FUNCTION__, l, h, s, pic14_isShared(l, h));
	return (pic14_isShared(l, h));
    } else {
	// sharebanks available for use by the stack
	if (options.stack_size) s = options.stack_size;
	else if (!s || s > 16) s = 16; // limit stack to 16 bytes in SHAREBANK

	// provide addresses for sharebank
	if (low) *low = l;
	if (high) *high = l + s - 1;
	if (size) *size = s;
	//fprintf(stderr, "%s: low %x, high %x, size %x, shared 1\n", __FUNCTION__, l, h, s);
	return 1;
    }
}

PIC_device * pic14_getPIC(void)
{
    return pic;
}
