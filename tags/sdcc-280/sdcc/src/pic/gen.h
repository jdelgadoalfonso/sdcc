/*-------------------------------------------------------------------------
  SDCCgen51.h - header file for code generation for 8051

             Written By -  Sandeep Dutta . sandeep.dutta@usa.net (1998)
             PIC port   - T. Scott Dattalo scott@dattalo.com (2000)

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

#ifndef SDCCGENPIC14_H
#define SDCCGENPIC14_H

extern int debug_verbose;

#define FENTRY do {                                                                     \
        /*fprintf (stderr, "%s:%u:%s: *{*\n", __FILE__, __LINE__, __FUNCTION__);*/      \
        if (options.debug || debug_verbose) {                                           \
                emitpComment ("; %s:%u:%s *{*", __FILE__, __LINE__, __FUNCTION__);      \
        }                                                                               \
} while (0)
#define FEXIT do {                                                                      \
        /*fprintf (stderr, "%s:%u:%s: *}*\n", __FILE__, __LINE__, __FUNCTION__);*/      \
        if (options.debug || debug.verbose) {                                           \
                emitpComment ("; %s:%u:%s *}*", __FILE__, __LINE__, __FUNCTION__);      \
        }                                                                               \
} while (0)

struct pCodeOp;

enum
{
  AOP_LIT = 1,
  AOP_REG,
  AOP_DIR,
  AOP_STK,
  AOP_IMMD,
  AOP_STR,
  AOP_CRY,
  AOP_PCODE

};

/* type asmop : a homogenised type for
   all the different spaces an operand can be
   in */
typedef struct asmop
{

  short type;  /* can have values
                  AOP_LIT    -  operand is a literal value
                  AOP_REG    -  is in registers
                  AOP_DIR    -  direct just a name
                  AOP_STK    -  should be pushed on stack this
                  can happen only for the result
                  AOP_IMMD   -  immediate value for eg. remateriazable
                  AOP_CRY    -  carry contains the value of this
                  AOP_STR    -  array of strings
               */
  short coff;           /* current offset */
  short size;           /* total size */
  unsigned code:1;      /* is in Code space */
  unsigned paged:1;     /* in paged memory  */
  unsigned freed:1;     /* already freed    */
  union
  {
    value *aop_lit;     /* if literal */
    regs *aop_reg[4];   /* array of registers */
    char *aop_dir;      /* if direct  */
    regs *aop_ptr;      /* either -> to r0 or r1 */
    char *aop_immd;     /* if immediate others are implied */
    int aop_stk;        /* stack offset when AOP_STK */
    char *aop_str[4];   /* just a string array containing the location */
    pCodeOp *pcop;
  }
  aopu;
}
asmop;

void genpic14Code (iCode *);

extern unsigned fReturnSizePic;


#define AOP(op) op->aop
#define AOP_TYPE(op) AOP(op)->type
#define AOP_SIZE(op) AOP(op)->size

#define AOP_NEEDSACC(x) (AOP(x) && (AOP_TYPE(x) == AOP_CRY || AOP(x)->paged))

#define RESULTONSTACK(x) \
                         (IC_RESULT(x) && IC_RESULT(x)->aop && \
                         IC_RESULT(x)->aop->type == AOP_STK )

#define MOVA(x) if (strcmp(x,"a") && strcmp(x,"acc")) pic14_emitcode(";XXX mov","a,%s  %s,%d",x,__FILE__,__LINE__);
#define CLRC    pic14_emitcode(";XXX clr","c %s,%d",__FILE__,__LINE__);

#define BIT_NUMBER(x) (x & 7)
#define BIT_REGISTER(x) (x>>3)


#define LSB     0
#define MSB16   1
#define MSB24   2
#define MSB32   3


#define FUNCTION_LABEL_INC  40

/*-----------------------------------------------------------------*/
/* Macros for emitting skip instructions                           */
/*-----------------------------------------------------------------*/

#define emitSKPC    emitpcode(POC_BTFSS,popCopyGPR2Bit(PCOP(&pc_status),PIC_C_BIT))
#define emitSKPNC   emitpcode(POC_BTFSC,popCopyGPR2Bit(PCOP(&pc_status),PIC_C_BIT))
#define emitSKPZ    emitpcode(POC_BTFSS,popCopyGPR2Bit(PCOP(&pc_status),PIC_Z_BIT))
#define emitSKPNZ   emitpcode(POC_BTFSC,popCopyGPR2Bit(PCOP(&pc_status),PIC_Z_BIT))
#define emitSKPDC   emitpcode(POC_BTFSS,popCopyGPR2Bit(PCOP(&pc_status),PIC_DC_BIT))
#define emitSKPNDC  emitpcode(POC_BTFSC,popCopyGPR2Bit(PCOP(&pc_status),PIC_DC_BIT))
#define emitCLRZ    emitpcode(POC_BCF,  popCopyGPR2Bit(PCOP(&pc_status),PIC_Z_BIT))
#define emitCLRC    emitpcode(POC_BCF,  popCopyGPR2Bit(PCOP(&pc_status),PIC_C_BIT))
#define emitCLRDC   emitpcode(POC_BCF,  popCopyGPR2Bit(PCOP(&pc_status),PIC_DC_BIT))
#define emitCLRIRP  emitpcode(POC_BCF,  popCopyGPR2Bit(PCOP(&pc_status),PIC_IRP_BIT))
#define emitSETZ    emitpcode(POC_BSF,  popCopyGPR2Bit(PCOP(&pc_status),PIC_Z_BIT))
#define emitSETC    emitpcode(POC_BSF,  popCopyGPR2Bit(PCOP(&pc_status),PIC_C_BIT))
#define emitSETDC   emitpcode(POC_BSF,  popCopyGPR2Bit(PCOP(&pc_status),PIC_DC_BIT))
#define emitSETIRP  emitpcode(POC_BSF,  popCopyGPR2Bit(PCOP(&pc_status),PIC_IRP_BIT))

int pic14_getDataSize(operand *op);
void emitpcode_real(PIC_OPCODE poc, pCodeOp *pcop);
#define emitpcode(poc,pcop)     do { if (options.debug || debug_verbose) { emitpComment (" >>> %s:%d:%s", __FILE__, __LINE__, __FUNCTION__); } emitpcode_real(poc,pcop); } while(0)
void emitpComment (const char *fmt, ...);
void emitpLabel(int key);
void pic14_emitcode (char *inst,char *fmt, ...);
void DEBUGpic14_emitcode (char *inst,char *fmt, ...);
void pic14_emitDebuggerSymbol (char *);
asmop *newAsmop (short type);
bool pic14_sameRegs (asmop *aop1, asmop *aop2 );
char *aopGet (asmop *aop, int offset, bool bit16, bool dname);


bool genPlusIncr (iCode *ic);
void pic14_outBitAcc(operand *result);
void genPlus (iCode *ic);
void addSign(operand *result, int offset, int sign);
void genMinus (iCode *ic);


pCodeOp *popGetLabel(unsigned int key);
pCodeOp *popCopyReg(pCodeOpReg *pc);
pCodeOp *popCopyGPR2Bit(pCodeOp *pc, int bitval);
pCodeOp *popGetLit(unsigned int lit);
pCodeOp *popGetWithString(char *str, int isExtern);
pCodeOp *popRegFromString(char *str, int size, int offset);
pCodeOp *popGet (asmop *aop, int offset);//, bool bit16, bool dname);
pCodeOp *popGetAddr (asmop *aop, int offset, int index);
pCodeOp *popGetTempReg(void);
void popReleaseTempReg(pCodeOp *pcop);


void aopPut (asmop *aop, char *s, int offset);
void pic14_outAcc(operand *result);
void aopOp (operand *op, iCode *ic, bool result);
void pic14_outBitC(operand *result);
void pic14_toBoolean(operand *oper);
void freeAsmop (operand *op, asmop *aaop, iCode *ic, bool pop);
void mov2w (asmop *aop, int offset);
const char *pCodeOpType(  pCodeOp *pcop);

int aop_isLitLike (asmop *aop);
int op_isLitLike (operand *op);

#endif