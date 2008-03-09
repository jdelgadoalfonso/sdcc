/* 
 * Copyright (C) 1996-1998 Szeredi Miklos
 * Email: mszeredi@inf.bme.hu
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version. See the file COPYING. 
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#include "z80_def.h"
#include "z80optab.h"
#include <stdio.h>

#ifdef PROCP
#define NEXTTAB(tab) \
{                                                \
  register byte nextop;                          \
  nextop = *PCP;                                 \
  PC++;                                          \
  return (*z80c_op_tab_ ## tab [nextop])(z80p);  \
}
#else
#define NEXTTAB(tab) \
{                                                \
  register byte nextop;                          \
  nextop = *PCP;                                 \
  PC++;                                          \
  (*z80c_op_tab_ ## tab [nextop])();             \
}
#endif


OPDEF(special_cb, 0xCB)
{
  RR++;
  DANM(cbaddr) = HL;
  NEXTTAB(cb);
}

OPDEF(special_dd, 0xDD)
{
  RR++;
  DANM(tc) -= 4;
  NEXTTAB(dd);
}


OPDEF(special_ed, 0xED)
{
  RR++;
  NEXTTAB(ed);
}

OPDEF(special_fd, 0xFD)
{
  RR++;
  DANM(tc) -= 4;
  NEXTTAB(fd);
}

OPDEF(special_xx, 0xDD 0xFD)
{
  RR--;
  PC--;
  ENDOP();
}

OPDEF(special_dd_cb, 0xCB)
{
  DANM(tc) -= 4;
  IXDGET(IX, DANM(cbaddr));
#ifdef DEBUG_Z80
  if((*PCP & 0x07) != 6) 
    printf("DD_CB unimplemented!\n");
#endif
  NEXTTAB(cb);
}

OPDEF(special_fd_cb, 0xCB)
{
  DANM(tc) -= 4;
  IXDGET(IY, DANM(cbaddr));
#ifdef DEBUG_Z80
  if((*PCP & 0x07) != 6) 
    printf("FD_CB unimplemented!\n");
#endif
  NEXTTAB(cb);
}

op_f z80c_op_tab[] = {
  z80op_nop,
  z80op_ld_bc_nn,
  z80op_ld_ibc_a,
  z80op_inc_bc,
  z80op_inc_b,
  z80op_dec_b,
  z80op_ld_b_n,
  z80op_rlca,
  z80op_ex_af_afb,
  z80op_add_hl_bc,
  z80op_ld_a_ibc,
  z80op_dec_bc,
  z80op_inc_c,
  z80op_dec_c,
  z80op_ld_c_n,
  z80op_rrca,
  
  z80op_djnz_e,
  z80op_ld_de_nn,
  z80op_ld_ide_a,
  z80op_inc_de,
  z80op_inc_d,
  z80op_dec_d,
  z80op_ld_d_n,
  z80op_rla,
  z80op_jr_e,
  z80op_add_hl_de,
  z80op_ld_a_ide,
  z80op_dec_de,
  z80op_inc_e,
  z80op_dec_e,
  z80op_ld_e_n,
  z80op_rra,

  z80op_jr_nz_e,
  z80op_ld_hl_nn,
  z80op_ld_inn_hl,
  z80op_inc_hl,
  z80op_inc_h,
  z80op_dec_h,
  z80op_ld_h_n,
  z80op_daa,
  z80op_jr_z_e,
  z80op_add_hl_hl,
  z80op_ld_hl_inn,
  z80op_dec_hl,
  z80op_inc_l,
  z80op_dec_l,
  z80op_ld_l_n,
  z80op_cpl,

  z80op_jr_nc_e,
  z80op_ld_sp_nn,
  z80op_ld_inn_a,
  z80op_inc_sp,
  z80op_inc_ihl,
  z80op_dec_ihl,
  z80op_ld_ihl_n,
  z80op_scf,
  z80op_jr_c_e,
  z80op_add_hl_sp,
  z80op_ld_a_inn,
  z80op_dec_sp,
  z80op_inc_a,
  z80op_dec_a,
  z80op_ld_a_n,
  z80op_ccf,

  z80op_nop,
  z80op_ld_b_c,
  z80op_ld_b_d,
  z80op_ld_b_e,
  z80op_ld_b_h,
  z80op_ld_b_l,
  z80op_ld_b_ihl,
  z80op_ld_b_a,
  z80op_ld_c_b,
  z80op_nop,
  z80op_ld_c_d,
  z80op_ld_c_e,
  z80op_ld_c_h,
  z80op_ld_c_l,
  z80op_ld_c_ihl,
  z80op_ld_c_a,

  z80op_ld_d_b,
  z80op_ld_d_c,
  z80op_nop,
  z80op_ld_d_e,
  z80op_ld_d_h,
  z80op_ld_d_l,
  z80op_ld_d_ihl,
  z80op_ld_d_a,
  z80op_ld_e_b,
  z80op_ld_e_c,
  z80op_ld_e_d,
  z80op_nop,
  z80op_ld_e_h,
  z80op_ld_e_l,
  z80op_ld_e_ihl,
  z80op_ld_e_a,

  z80op_ld_h_b,
  z80op_ld_h_c,
  z80op_ld_h_d,
  z80op_ld_h_e,
  z80op_nop,
  z80op_ld_h_l,
  z80op_ld_h_ihl,
  z80op_ld_h_a,
  z80op_ld_l_b,
  z80op_ld_l_c,
  z80op_ld_l_d,
  z80op_ld_l_e,
  z80op_ld_l_h,
  z80op_nop,
  z80op_ld_l_ihl,
  z80op_ld_l_a,

  z80op_ld_ihl_b,
  z80op_ld_ihl_c,
  z80op_ld_ihl_d,
  z80op_ld_ihl_e,
  z80op_ld_ihl_h,
  z80op_ld_ihl_l,
  z80op_halt,
  z80op_ld_ihl_a,
  z80op_ld_a_b,
  z80op_ld_a_c,
  z80op_ld_a_d,
  z80op_ld_a_e,
  z80op_ld_a_h,
  z80op_ld_a_l,
  z80op_ld_a_ihl,
  z80op_nop,

  z80op_add_a_b,
  z80op_add_a_c,
  z80op_add_a_d,
  z80op_add_a_e,
  z80op_add_a_h,
  z80op_add_a_l,
  z80op_add_a_ihl,
  z80op_add_a_a,
  z80op_adc_a_b,
  z80op_adc_a_c,
  z80op_adc_a_d,
  z80op_adc_a_e,
  z80op_adc_a_h,
  z80op_adc_a_l,
  z80op_adc_a_ihl,
  z80op_adc_a_a,

  z80op_sub_b,
  z80op_sub_c,
  z80op_sub_d,
  z80op_sub_e,
  z80op_sub_h,
  z80op_sub_l,
  z80op_sub_ihl,
  z80op_sub_a,
  z80op_sbc_a_b,
  z80op_sbc_a_c,
  z80op_sbc_a_d,
  z80op_sbc_a_e,
  z80op_sbc_a_h,
  z80op_sbc_a_l,
  z80op_sbc_a_ihl,
  z80op_sbc_a_a,

  z80op_and_b,
  z80op_and_c,
  z80op_and_d,
  z80op_and_e,
  z80op_and_h,
  z80op_and_l,
  z80op_and_ihl,
  z80op_and_a,
  z80op_xor_b,
  z80op_xor_c,
  z80op_xor_d,
  z80op_xor_e,
  z80op_xor_h,
  z80op_xor_l,
  z80op_xor_ihl,
  z80op_xor_a,

  z80op_or_b,
  z80op_or_c,
  z80op_or_d,
  z80op_or_e,
  z80op_or_h,
  z80op_or_l,
  z80op_or_ihl,
  z80op_or_a,
  z80op_cp_b,
  z80op_cp_c,
  z80op_cp_d,
  z80op_cp_e,
  z80op_cp_h,
  z80op_cp_l,
  z80op_cp_ihl,
  z80op_cp_a,

  z80op_ret_nz,
  z80op_pop_bc,
  z80op_jp_nz_nn,
  z80op_jp_nn,
  z80op_call_nz_nn,
  z80op_push_bc,
  z80op_add_a_n,
  z80op_rst_00,
  z80op_ret_z,
  z80op_ret,
  z80op_jp_z_nn,
  z80op_special_cb,
  z80op_call_z_nn,
  z80op_call_nn,
  z80op_adc_a_n,
  z80op_rst_08,

  z80op_ret_nc,
  z80op_pop_de,
  z80op_jp_nc_nn,
  z80op_out_in_a,
  z80op_call_nc_nn,
  z80op_push_de,
  z80op_sub_n,
  z80op_rst_10,
  z80op_ret_c,
  z80op_exx,
  z80op_jp_c_nn,
  z80op_in_a_in,
  z80op_call_c_nn,
  z80op_special_dd,
  z80op_sbc_a_n,
  z80op_rst_18,

  z80op_ret_po,
  z80op_pop_hl,
  z80op_jp_po_nn,
  z80op_ex_isp_hl,
  z80op_call_po_nn,
  z80op_push_hl,
  z80op_and_n,
  z80op_rst_20,
  z80op_ret_pe,
  z80op_jp_hl,
  z80op_jp_pe_nn,
  z80op_ex_de_hl,
  z80op_call_pe_nn,
  z80op_special_ed,
  z80op_xor_n,
  z80op_rst_28,

  z80op_ret_p,
  z80op_pop_af,
  z80op_jp_p_nn,
  z80op_di,
  z80op_call_p_nn,
  z80op_push_af,
  z80op_or_n,
  z80op_rst_30,
  z80op_ret_m,
  z80op_ld_sp_hl,
  z80op_jp_m_nn,
  z80op_ei,
  z80op_call_m_nn,
  z80op_special_fd,
  z80op_cp_n,
  z80op_rst_38
};


op_f z80c_op_tab_ed[] = {
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,

  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,

  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,

  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,

  z80op_in_b_ic,
  z80op_out_ic_b,
  z80op_sbc_hl_bc,
  z80op_ld_inn_bc,
  z80op_neg,
  z80op_retn,
  z80op_im_0,
  z80op_ld_i_a,
  z80op_in_c_ic,
  z80op_out_ic_c,
  z80op_adc_hl_bc,
  z80op_ld_bc_inn,
  z80op_neg,
  z80op_reti,
  z80op_im_0,
  z80op_ld_r_a,

  z80op_in_d_ic,
  z80op_out_ic_d,
  z80op_sbc_hl_de,
  z80op_ld_inn_de,
  z80op_neg,
  z80op_retn,
  z80op_im_1,
  z80op_ld_a_i,
  z80op_in_e_ic,
  z80op_out_ic_e,
  z80op_adc_hl_de,
  z80op_ld_de_inn,
  z80op_neg,
  z80op_retn,
  z80op_im_2,
  z80op_ld_a_r,

  z80op_in_h_ic,
  z80op_out_ic_h,
  z80op_sbc_hl_hl,
  z80op_ld_inn_hl_ed,
  z80op_neg,
  z80op_retn,
  z80op_im_0,
  z80op_rrd,
  z80op_in_l_ic,
  z80op_out_ic_l,
  z80op_adc_hl_hl,
  z80op_ld_hl_inn_ed,
  z80op_neg,
  z80op_retn,
  z80op_im_0,
  z80op_rld,

  z80op_in_f_ic,
  z80op_out_ic_0,
  z80op_sbc_hl_sp,
  z80op_ld_inn_sp,
  z80op_neg,
  z80op_retn,
  z80op_im_1,
  z80op_ill_ed,
  z80op_in_a_ic,
  z80op_out_ic_a,
  z80op_adc_hl_sp,
  z80op_ld_sp_inn,
  z80op_neg,
  z80op_retn,
  z80op_im_2,
  z80op_ill_ed,

  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,

  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,

  z80op_ldi,
  z80op_cpi,
  z80op_ini,
  z80op_outi,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ldd,
  z80op_cpd,
  z80op_ind,
  z80op_outd,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,

  z80op_ldir,
  z80op_cpir,
  z80op_inir,
  z80op_otir,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_lddr,
  z80op_cpdr,
  z80op_indr,
  z80op_otdr,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,

  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,

  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,

  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,

  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed,
  z80op_ill_ed
};

op_f z80c_op_tab_dd[] = {
  z80op_nop,
  z80op_ld_bc_nn,
  z80op_ld_ibc_a,
  z80op_inc_bc,
  z80op_inc_b,
  z80op_dec_b,
  z80op_ld_b_n,
  z80op_rlca,
  z80op_ex_af_afb,
  z80op_add_ix_bc,
  z80op_ld_a_ibc,
  z80op_dec_bc,
  z80op_inc_c,
  z80op_dec_c,
  z80op_ld_c_n,
  z80op_rrca,

  z80op_djnz_e,
  z80op_ld_de_nn,
  z80op_ld_ide_a,
  z80op_inc_de,
  z80op_inc_d,
  z80op_dec_d,
  z80op_ld_d_n,
  z80op_rla,
  z80op_jr_e,
  z80op_add_ix_de,
  z80op_ld_a_ide,
  z80op_dec_de,
  z80op_inc_e,
  z80op_dec_e,
  z80op_ld_e_n,
  z80op_rra,

  z80op_jr_nz_e,
  z80op_ld_ix_nn,
  z80op_ld_inn_ix,
  z80op_inc_ix,
  z80op_inc_ixh,
  z80op_dec_ixh,
  z80op_ld_ixh_n,
  z80op_daa,
  z80op_jr_z_e,
  z80op_add_ix_ix,
  z80op_ld_ix_inn,
  z80op_dec_ix,
  z80op_inc_ixl,
  z80op_dec_ixl,
  z80op_ld_ixl_n,
  z80op_cpl,

  z80op_jr_nc_e,
  z80op_ld_sp_nn,
  z80op_ld_inn_a,
  z80op_inc_sp,
  z80op_inc_iixd,
  z80op_dec_iixd,
  z80op_ld_iixd_n,
  z80op_scf,
  z80op_jr_c_e,
  z80op_add_ix_sp,
  z80op_ld_a_inn,
  z80op_dec_sp,
  z80op_inc_a,
  z80op_dec_a,
  z80op_ld_a_n,
  z80op_ccf,

  z80op_nop,
  z80op_ld_b_c,
  z80op_ld_b_d,
  z80op_ld_b_e,
  z80op_ld_b_ixh,
  z80op_ld_b_ixl,
  z80op_ld_b_iixd,
  z80op_ld_b_a,
  z80op_ld_c_b,
  z80op_nop,
  z80op_ld_c_d,
  z80op_ld_c_e,
  z80op_ld_c_ixh,
  z80op_ld_c_ixl,
  z80op_ld_c_iixd,
  z80op_ld_c_a,

  z80op_ld_d_b,
  z80op_ld_d_c,
  z80op_nop,
  z80op_ld_d_e,
  z80op_ld_d_ixh,
  z80op_ld_d_ixl,
  z80op_ld_d_iixd,
  z80op_ld_d_a,
  z80op_ld_e_b,
  z80op_ld_e_c,
  z80op_ld_e_d,
  z80op_nop,
  z80op_ld_e_ixh,
  z80op_ld_e_ixl,
  z80op_ld_e_iixd,
  z80op_ld_e_a,

  z80op_ld_ixh_b,
  z80op_ld_ixh_c,
  z80op_ld_ixh_d,
  z80op_ld_ixh_e,
  z80op_nop,
  z80op_ld_ixh_ixl,
  z80op_ld_h_iixd,
  z80op_ld_ixh_a,
  z80op_ld_ixl_b,
  z80op_ld_ixl_c,
  z80op_ld_ixl_d,
  z80op_ld_ixl_e,
  z80op_ld_ixl_ixh,
  z80op_nop,
  z80op_ld_l_iixd,
  z80op_ld_ixl_a,

  z80op_ld_iixd_b,
  z80op_ld_iixd_c,
  z80op_ld_iixd_d,
  z80op_ld_iixd_e,
  z80op_ld_iixd_h,
  z80op_ld_iixd_l,
  z80op_halt,
  z80op_ld_iixd_a,
  z80op_ld_a_b,
  z80op_ld_a_c,
  z80op_ld_a_d,
  z80op_ld_a_e,
  z80op_ld_a_ixh,
  z80op_ld_a_ixl,
  z80op_ld_a_iixd,
  z80op_nop,

  z80op_add_a_b,
  z80op_add_a_c,
  z80op_add_a_d,
  z80op_add_a_e,
  z80op_add_a_ixh,
  z80op_add_a_ixl,
  z80op_add_a_iixd,
  z80op_add_a_a,
  z80op_adc_a_b,
  z80op_adc_a_c,
  z80op_adc_a_d,
  z80op_adc_a_e,
  z80op_adc_a_ixh,
  z80op_adc_a_ixl,
  z80op_adc_a_iixd,
  z80op_adc_a_a,

  z80op_sub_b,
  z80op_sub_c,
  z80op_sub_d,
  z80op_sub_e,
  z80op_sub_ixh,
  z80op_sub_ixl,
  z80op_sub_iixd,
  z80op_sub_a,
  z80op_sbc_a_b,
  z80op_sbc_a_c,
  z80op_sbc_a_d,
  z80op_sbc_a_e,
  z80op_sbc_a_ixh,
  z80op_sbc_a_ixl,
  z80op_sbc_a_iixd,
  z80op_sbc_a_a,

  z80op_and_b,
  z80op_and_c,
  z80op_and_d,
  z80op_and_e,
  z80op_and_ixh,
  z80op_and_ixl,
  z80op_and_iixd,
  z80op_and_a,
  z80op_xor_b,
  z80op_xor_c,
  z80op_xor_d,
  z80op_xor_e,
  z80op_xor_ixh,
  z80op_xor_ixl,
  z80op_xor_iixd,
  z80op_xor_a,

  z80op_or_b,
  z80op_or_c,
  z80op_or_d,
  z80op_or_e,
  z80op_or_ixh,
  z80op_or_ixl,
  z80op_or_iixd,
  z80op_or_a,
  z80op_cp_b,
  z80op_cp_c,
  z80op_cp_d,
  z80op_cp_e,
  z80op_cp_ixh,
  z80op_cp_ixl,
  z80op_cp_iixd,
  z80op_cp_a,

  z80op_ret_nz,
  z80op_pop_bc,
  z80op_jp_nz_nn,
  z80op_jp_nn,
  z80op_call_nz_nn,
  z80op_push_bc,
  z80op_add_a_n,
  z80op_rst_00,
  z80op_ret_z,
  z80op_ret,
  z80op_jp_z_nn,
  z80op_special_dd_cb,
  z80op_call_z_nn,
  z80op_call_nn,
  z80op_adc_a_n,
  z80op_rst_08,

  z80op_ret_nc,
  z80op_pop_de,
  z80op_jp_nc_nn,
  z80op_out_in_a,
  z80op_call_nc_nn,
  z80op_push_de,
  z80op_sub_n,
  z80op_rst_10,
  z80op_ret_c,
  z80op_exx,
  z80op_jp_c_nn,
  z80op_in_a_in,
  z80op_call_c_nn,
  z80op_special_xx,
  z80op_sbc_a_n,
  z80op_rst_18,

  z80op_ret_po,
  z80op_pop_ix,
  z80op_jp_po_nn,
  z80op_ex_isp_ix,
  z80op_call_po_nn,
  z80op_push_ix,
  z80op_and_n,
  z80op_rst_20,
  z80op_ret_pe,
  z80op_jp_ix,
  z80op_jp_pe_nn,
  z80op_ex_de_hl,
  z80op_call_pe_nn,
  z80op_special_ed,
  z80op_xor_n,
  z80op_rst_28,

  z80op_ret_p,
  z80op_pop_af,
  z80op_jp_p_nn,
  z80op_di,
  z80op_call_p_nn,
  z80op_push_af,
  z80op_or_n,
  z80op_rst_30,
  z80op_ret_m,
  z80op_ld_sp_ix,
  z80op_jp_m_nn,
  z80op_ei,
  z80op_call_m_nn,
  z80op_special_xx,
  z80op_cp_n,
  z80op_rst_38
};


op_f z80c_op_tab_fd[] = {
  z80op_nop,
  z80op_ld_bc_nn,
  z80op_ld_ibc_a,
  z80op_inc_bc,
  z80op_inc_b,
  z80op_dec_b,
  z80op_ld_b_n,
  z80op_rlca,
  z80op_ex_af_afb,
  z80op_add_iy_bc,
  z80op_ld_a_ibc,
  z80op_dec_bc,
  z80op_inc_c,
  z80op_dec_c,
  z80op_ld_c_n,
  z80op_rrca,

  z80op_djnz_e,
  z80op_ld_de_nn,
  z80op_ld_ide_a,
  z80op_inc_de,
  z80op_inc_d,
  z80op_dec_d,
  z80op_ld_d_n,
  z80op_rla,
  z80op_jr_e,
  z80op_add_iy_de,
  z80op_ld_a_ide,
  z80op_dec_de,
  z80op_inc_e,
  z80op_dec_e,
  z80op_ld_e_n,
  z80op_rra,

  z80op_jr_nz_e,
  z80op_ld_iy_nn,
  z80op_ld_inn_iy,
  z80op_inc_iy,
  z80op_inc_iyh,
  z80op_dec_iyh,
  z80op_ld_iyh_n,
  z80op_daa,
  z80op_jr_z_e,
  z80op_add_iy_iy,
  z80op_ld_iy_inn,
  z80op_dec_iy,
  z80op_inc_iyl,
  z80op_dec_iyl,
  z80op_ld_iyl_n,
  z80op_cpl,

  z80op_jr_nc_e,
  z80op_ld_sp_nn,
  z80op_ld_inn_a,
  z80op_inc_sp,
  z80op_inc_iiyd,
  z80op_dec_iiyd,
  z80op_ld_iiyd_n,
  z80op_scf,
  z80op_jr_c_e,
  z80op_add_iy_sp,
  z80op_ld_a_inn,
  z80op_dec_sp,
  z80op_inc_a,
  z80op_dec_a,
  z80op_ld_a_n,
  z80op_ccf,

  z80op_nop,
  z80op_ld_b_c,
  z80op_ld_b_d,
  z80op_ld_b_e,
  z80op_ld_b_iyh,
  z80op_ld_b_iyl,
  z80op_ld_b_iiyd,
  z80op_ld_b_a,
  z80op_ld_c_b,
  z80op_nop,
  z80op_ld_c_d,
  z80op_ld_c_e,
  z80op_ld_c_iyh,
  z80op_ld_c_iyl,
  z80op_ld_c_iiyd,
  z80op_ld_c_a,

  z80op_ld_d_b,
  z80op_ld_d_c,
  z80op_nop,
  z80op_ld_d_e,
  z80op_ld_d_iyh,
  z80op_ld_d_iyl,
  z80op_ld_d_iiyd,
  z80op_ld_d_a,
  z80op_ld_e_b,
  z80op_ld_e_c,
  z80op_ld_e_d,
  z80op_nop,
  z80op_ld_e_iyh,
  z80op_ld_e_iyl,
  z80op_ld_e_iiyd,
  z80op_ld_e_a,

  z80op_ld_iyh_b,
  z80op_ld_iyh_c,
  z80op_ld_iyh_d,
  z80op_ld_iyh_e,
  z80op_nop,
  z80op_ld_iyh_iyl,
  z80op_ld_h_iiyd,
  z80op_ld_iyh_a,
  z80op_ld_iyl_b,
  z80op_ld_iyl_c,
  z80op_ld_iyl_d,
  z80op_ld_iyl_e,
  z80op_ld_iyl_iyh,
  z80op_nop,
  z80op_ld_l_iiyd,
  z80op_ld_iyl_a,

  z80op_ld_iiyd_b,
  z80op_ld_iiyd_c,
  z80op_ld_iiyd_d,
  z80op_ld_iiyd_e,
  z80op_ld_iiyd_h,
  z80op_ld_iiyd_l,
  z80op_halt,
  z80op_ld_iiyd_a,
  z80op_ld_a_b,
  z80op_ld_a_c,
  z80op_ld_a_d,
  z80op_ld_a_e,
  z80op_ld_a_iyh,
  z80op_ld_a_iyl,
  z80op_ld_a_iiyd,
  z80op_nop,

  z80op_add_a_b,
  z80op_add_a_c,
  z80op_add_a_d,
  z80op_add_a_e,
  z80op_add_a_iyh,
  z80op_add_a_iyl,
  z80op_add_a_iiyd,
  z80op_add_a_a,
  z80op_adc_a_b,
  z80op_adc_a_c,
  z80op_adc_a_d,
  z80op_adc_a_e,
  z80op_adc_a_iyh,
  z80op_adc_a_iyl,
  z80op_adc_a_iiyd,
  z80op_adc_a_a,

  z80op_sub_b,
  z80op_sub_c,
  z80op_sub_d,
  z80op_sub_e,
  z80op_sub_iyh,
  z80op_sub_iyl,
  z80op_sub_iiyd,
  z80op_sub_a,
  z80op_sbc_a_b,
  z80op_sbc_a_c,
  z80op_sbc_a_d,
  z80op_sbc_a_e,
  z80op_sbc_a_iyh,
  z80op_sbc_a_iyl,
  z80op_sbc_a_iiyd,
  z80op_sbc_a_a,

  z80op_and_b,
  z80op_and_c,
  z80op_and_d,
  z80op_and_e,
  z80op_and_iyh,
  z80op_and_iyl,
  z80op_and_iiyd,
  z80op_and_a,
  z80op_xor_b,
  z80op_xor_c,
  z80op_xor_d,
  z80op_xor_e,
  z80op_xor_iyh,
  z80op_xor_iyl,
  z80op_xor_iiyd,
  z80op_xor_a,

  z80op_or_b,
  z80op_or_c,
  z80op_or_d,
  z80op_or_e,
  z80op_or_iyh,
  z80op_or_iyl,
  z80op_or_iiyd,
  z80op_or_a,
  z80op_cp_b,
  z80op_cp_c,
  z80op_cp_d,
  z80op_cp_e,
  z80op_cp_iyh,
  z80op_cp_iyl,
  z80op_cp_iiyd,
  z80op_cp_a,

  z80op_ret_nz,
  z80op_pop_bc,
  z80op_jp_nz_nn,
  z80op_jp_nn,
  z80op_call_nz_nn,
  z80op_push_bc,
  z80op_add_a_n,
  z80op_rst_00,
  z80op_ret_z,
  z80op_ret,
  z80op_jp_z_nn,
  z80op_special_fd_cb,
  z80op_call_z_nn,
  z80op_call_nn,
  z80op_adc_a_n,
  z80op_rst_08,

  z80op_ret_nc,
  z80op_pop_de,
  z80op_jp_nc_nn,
  z80op_out_in_a,
  z80op_call_nc_nn,
  z80op_push_de,
  z80op_sub_n,
  z80op_rst_10,
  z80op_ret_c,
  z80op_exx,
  z80op_jp_c_nn,
  z80op_in_a_in,
  z80op_call_c_nn,
  z80op_special_xx,
  z80op_sbc_a_n,
  z80op_rst_18,

  z80op_ret_po,
  z80op_pop_iy,
  z80op_jp_po_nn,
  z80op_ex_isp_iy,
  z80op_call_po_nn,
  z80op_push_iy,
  z80op_and_n,
  z80op_rst_20,
  z80op_ret_pe,
  z80op_jp_iy,
  z80op_jp_pe_nn,
  z80op_ex_de_hl,
  z80op_call_pe_nn,
  z80op_special_ed,
  z80op_xor_n,
  z80op_rst_28,

  z80op_ret_p,
  z80op_pop_af,
  z80op_jp_p_nn,
  z80op_di,
  z80op_call_p_nn,
  z80op_push_af,
  z80op_or_n,
  z80op_rst_30,
  z80op_ret_m,
  z80op_ld_sp_iy,
  z80op_jp_m_nn,
  z80op_ei,
  z80op_call_m_nn,
  z80op_special_xx,
  z80op_cp_n,
  z80op_rst_38
};

op_f z80c_op_tab_cb[] = {
  z80op_rlc_b,
  z80op_rlc_c,
  z80op_rlc_d,
  z80op_rlc_e,
  z80op_rlc_h,
  z80op_rlc_l,
  z80op_rlc_ihl,
  z80op_rlc_a,
  z80op_rrc_b,
  z80op_rrc_c,
  z80op_rrc_d,
  z80op_rrc_e,
  z80op_rrc_h,
  z80op_rrc_l,
  z80op_rrc_ihl,
  z80op_rrc_a,

  z80op_rl_b,
  z80op_rl_c,
  z80op_rl_d,
  z80op_rl_e,
  z80op_rl_h,
  z80op_rl_l,
  z80op_rl_ihl,
  z80op_rl_a,
  z80op_rr_b,
  z80op_rr_c,
  z80op_rr_d,
  z80op_rr_e,
  z80op_rr_h,
  z80op_rr_l,
  z80op_rr_ihl,
  z80op_rr_a,

  z80op_sla_b,
  z80op_sla_c,
  z80op_sla_d,
  z80op_sla_e,
  z80op_sla_h,
  z80op_sla_l,
  z80op_sla_ihl,
  z80op_sla_a,
  z80op_sra_b,
  z80op_sra_c,
  z80op_sra_d,
  z80op_sra_e,
  z80op_sra_h,
  z80op_sra_l,
  z80op_sra_ihl,
  z80op_sra_a,

  z80op_sll_b,
  z80op_sll_c,
  z80op_sll_d,
  z80op_sll_e,
  z80op_sll_h,
  z80op_sll_l,
  z80op_sll_ihl,
  z80op_sll_a,
  z80op_srl_b,
  z80op_srl_c,
  z80op_srl_d,
  z80op_srl_e,
  z80op_srl_h,
  z80op_srl_l,
  z80op_srl_ihl,
  z80op_srl_a,

  z80op_bit_0_b,
  z80op_bit_0_c,
  z80op_bit_0_d,
  z80op_bit_0_e,
  z80op_bit_0_h,
  z80op_bit_0_l,
  z80op_bit_0_ihl,
  z80op_bit_0_a,
  z80op_bit_1_b,
  z80op_bit_1_c,
  z80op_bit_1_d,
  z80op_bit_1_e,
  z80op_bit_1_h,
  z80op_bit_1_l,
  z80op_bit_1_ihl,
  z80op_bit_1_a,

  z80op_bit_2_b,
  z80op_bit_2_c,
  z80op_bit_2_d,
  z80op_bit_2_e,
  z80op_bit_2_h,
  z80op_bit_2_l,
  z80op_bit_2_ihl,
  z80op_bit_2_a,
  z80op_bit_3_b,
  z80op_bit_3_c,
  z80op_bit_3_d,
  z80op_bit_3_e,
  z80op_bit_3_h,
  z80op_bit_3_l,
  z80op_bit_3_ihl,
  z80op_bit_3_a,

  z80op_bit_4_b,
  z80op_bit_4_c,
  z80op_bit_4_d,
  z80op_bit_4_e,
  z80op_bit_4_h,
  z80op_bit_4_l,
  z80op_bit_4_ihl,
  z80op_bit_4_a,
  z80op_bit_5_b,
  z80op_bit_5_c,
  z80op_bit_5_d,
  z80op_bit_5_e,
  z80op_bit_5_h,
  z80op_bit_5_l,
  z80op_bit_5_ihl,
  z80op_bit_5_a,

  z80op_bit_6_b,
  z80op_bit_6_c,
  z80op_bit_6_d,
  z80op_bit_6_e,
  z80op_bit_6_h,
  z80op_bit_6_l,
  z80op_bit_6_ihl,
  z80op_bit_6_a,
  z80op_bit_7_b,
  z80op_bit_7_c,
  z80op_bit_7_d,
  z80op_bit_7_e,
  z80op_bit_7_h,
  z80op_bit_7_l,
  z80op_bit_7_ihl,
  z80op_bit_7_a,

  z80op_res_0_b,
  z80op_res_0_c,
  z80op_res_0_d,
  z80op_res_0_e,
  z80op_res_0_h,
  z80op_res_0_l,
  z80op_res_0_ihl,
  z80op_res_0_a,
  z80op_res_1_b,
  z80op_res_1_c,
  z80op_res_1_d,
  z80op_res_1_e,
  z80op_res_1_h,
  z80op_res_1_l,
  z80op_res_1_ihl,
  z80op_res_1_a,

  z80op_res_2_b,
  z80op_res_2_c,
  z80op_res_2_d,
  z80op_res_2_e,
  z80op_res_2_h,
  z80op_res_2_l,
  z80op_res_2_ihl,
  z80op_res_2_a,
  z80op_res_3_b,
  z80op_res_3_c,
  z80op_res_3_d,
  z80op_res_3_e,
  z80op_res_3_h,
  z80op_res_3_l,
  z80op_res_3_ihl,
  z80op_res_3_a,

  z80op_res_4_b,
  z80op_res_4_c,
  z80op_res_4_d,
  z80op_res_4_e,
  z80op_res_4_h,
  z80op_res_4_l,
  z80op_res_4_ihl,
  z80op_res_4_a,
  z80op_res_5_b,
  z80op_res_5_c,
  z80op_res_5_d,
  z80op_res_5_e,
  z80op_res_5_h,
  z80op_res_5_l,
  z80op_res_5_ihl,
  z80op_res_5_a,

  z80op_res_6_b,
  z80op_res_6_c,
  z80op_res_6_d,
  z80op_res_6_e,
  z80op_res_6_h,
  z80op_res_6_l,
  z80op_res_6_ihl,
  z80op_res_6_a,
  z80op_res_7_b,
  z80op_res_7_c,
  z80op_res_7_d,
  z80op_res_7_e,
  z80op_res_7_h,
  z80op_res_7_l,
  z80op_res_7_ihl,
  z80op_res_7_a,

  z80op_set_0_b,
  z80op_set_0_c,
  z80op_set_0_d,
  z80op_set_0_e,
  z80op_set_0_h,
  z80op_set_0_l,
  z80op_set_0_ihl,
  z80op_set_0_a,
  z80op_set_1_b,
  z80op_set_1_c,
  z80op_set_1_d,
  z80op_set_1_e,
  z80op_set_1_h,
  z80op_set_1_l,
  z80op_set_1_ihl,
  z80op_set_1_a,

  z80op_set_2_b,
  z80op_set_2_c,
  z80op_set_2_d,
  z80op_set_2_e,
  z80op_set_2_h,
  z80op_set_2_l,
  z80op_set_2_ihl,
  z80op_set_2_a,
  z80op_set_3_b,
  z80op_set_3_c,
  z80op_set_3_d,
  z80op_set_3_e,
  z80op_set_3_h,
  z80op_set_3_l,
  z80op_set_3_ihl,
  z80op_set_3_a,

  z80op_set_4_b,
  z80op_set_4_c,
  z80op_set_4_d,
  z80op_set_4_e,
  z80op_set_4_h,
  z80op_set_4_l,
  z80op_set_4_ihl,
  z80op_set_4_a,
  z80op_set_5_b,
  z80op_set_5_c,
  z80op_set_5_d,
  z80op_set_5_e,
  z80op_set_5_h,
  z80op_set_5_l,
  z80op_set_5_ihl,
  z80op_set_5_a,

  z80op_set_6_b,
  z80op_set_6_c,
  z80op_set_6_d,
  z80op_set_6_e,
  z80op_set_6_h,
  z80op_set_6_l,
  z80op_set_6_ihl,
  z80op_set_6_a,
  z80op_set_7_b,
  z80op_set_7_c,
  z80op_set_7_d,
  z80op_set_7_e,
  z80op_set_7_h,
  z80op_set_7_l,
  z80op_set_7_ihl,
  z80op_set_7_a
};
