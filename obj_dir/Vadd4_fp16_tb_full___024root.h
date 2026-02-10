// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vadd4_fp16_tb_full.h for the primary calling header

#ifndef VERILATED_VADD4_FP16_TB_FULL___024ROOT_H_
#define VERILATED_VADD4_FP16_TB_FULL___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vadd4_fp16_tb_full__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vadd4_fp16_tb_full___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ add4_fp16_tb_full__DOT__tb_clk;
        CData/*0:0*/ add4_fp16_tb_full__DOT__tb_nrst;
        CData/*0:0*/ add4_fp16_tb_full__DOT__tb_start;
        CData/*0:0*/ add4_fp16_tb_full__DOT__unnamedblk1__DOT__is_zero_result;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__is_nan_a;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__is_nan_b;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__is_inf_a;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__is_inf_b;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_case;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__op_swap;
        CData/*4:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__high_exp;
        CData/*4:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__low_exp;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sticky_align_local;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sticky_lost;
        CData/*4:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_diff;
        CData/*4:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_max;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_shifted;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_not_shifted;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__larger_mantissa_sign;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__result_sign;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_overflow;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sub_has_lost_sticky;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sub_has_added_sticky;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__larger_mantissa_sign_l;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_shifted_l;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_not_shifted_l;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__signs_differ_l;
        CData/*4:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_max_l;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_case_l;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sub_has_lost_sticky_l;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sub_has_added_sticky_l;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__start_l;
        CData/*4:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT____Vcellout__normalizer__shifted_amount;
        CData/*6:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_norm_s;
        CData/*5:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_base;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__ftz_under;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__round_inc;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_carry;
        CData/*5:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_out;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__overflow;
        CData/*4:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_out_final;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__is_nan_a;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__is_nan_b;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__is_inf_a;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__is_inf_b;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_case;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__op_swap;
        CData/*4:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__high_exp;
        CData/*4:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__low_exp;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sticky_align_local;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sticky_lost;
        CData/*4:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_diff;
        CData/*4:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_max;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_shifted;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_not_shifted;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__larger_mantissa_sign;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__result_sign;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_overflow;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sub_has_lost_sticky;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sub_has_added_sticky;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__larger_mantissa_sign_l;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_shifted_l;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_not_shifted_l;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__signs_differ_l;
    };
    struct {
        CData/*4:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_max_l;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_case_l;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sub_has_lost_sticky_l;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sub_has_added_sticky_l;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__start_l;
        CData/*4:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT____Vcellout__normalizer__shifted_amount;
        CData/*6:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_norm_s;
        CData/*5:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_base;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__ftz_under;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__round_inc;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_carry;
        CData/*5:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_out;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__overflow;
        CData/*4:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_out_final;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__is_nan_a;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__is_nan_b;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__is_inf_a;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__is_inf_b;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__op_swap;
        CData/*4:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__high_exp;
        CData/*4:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__low_exp;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sticky_align_local;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sticky_lost;
        CData/*4:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_diff;
        CData/*4:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_max;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_shifted;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_not_shifted;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__larger_mantissa_sign;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_overflow;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sub_has_lost_sticky;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sub_has_added_sticky;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__larger_mantissa_sign_l;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_shifted_l;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_not_shifted_l;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__signs_differ_l;
        CData/*4:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_max_l;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sub_has_lost_sticky_l;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sub_has_added_sticky_l;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__start_l;
        CData/*4:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT____Vcellout__normalizer__shifted_amount;
        CData/*6:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_norm_s;
        CData/*5:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_base;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__round_inc;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_carry;
        CData/*5:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out;
        CData/*0:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__overflow;
        CData/*4:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__add4_fp16_tb_full__DOT__tb_clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__add4_fp16_tb_full__DOT__tb_nrst__0;
        CData/*0:0*/ __VactContinue;
        SData/*15:0*/ add4_fp16_tb_full__DOT__tb_a;
        SData/*15:0*/ add4_fp16_tb_full__DOT__tb_b;
        SData/*15:0*/ add4_fp16_tb_full__DOT__tb_c;
        SData/*15:0*/ add4_fp16_tb_full__DOT__tb_d;
        SData/*15:0*/ add4_fp16_tb_full__DOT__exp;
        SData/*15:0*/ add4_fp16_tb_full__DOT__a;
        SData/*15:0*/ add4_fp16_tb_full__DOT__b;
        SData/*15:0*/ add4_fp16_tb_full__DOT__c;
        SData/*15:0*/ add4_fp16_tb_full__DOT__d;
    };
    struct {
        SData/*15:0*/ add4_fp16_tb_full__DOT__expected;
        SData/*15:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__a;
        SData/*15:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__b;
        SData/*15:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_result;
        SData/*15:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__high_op;
        SData/*15:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__low_op;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_hi;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_lo;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_lo_aligned;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mask_align;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_shifted;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_not_shifted;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__smaller_mantissa;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__larger_mantissa;
        SData/*13:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__smaller_mantissa_l;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__larger_mantissa_l;
        SData/*15:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_result_l;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__normalized_mantissa_sum;
        SData/*11:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__round_this;
        SData/*10:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_sum;
        SData/*9:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__rounded_fraction;
        SData/*9:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__rounded_fraction_final;
        SData/*15:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__a;
        SData/*15:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__b;
        SData/*15:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_result;
        SData/*15:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__high_op;
        SData/*15:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__low_op;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_hi;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_lo;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_lo_aligned;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mask_align;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_shifted;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_not_shifted;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__smaller_mantissa;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__larger_mantissa;
        SData/*13:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__smaller_mantissa_l;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__larger_mantissa_l;
        SData/*15:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_result_l;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__normalized_mantissa_sum;
        SData/*11:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__round_this;
        SData/*10:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_sum;
        SData/*9:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__rounded_fraction;
        SData/*9:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__rounded_fraction_final;
        SData/*15:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__a;
        SData/*15:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__b;
        SData/*15:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result;
        SData/*15:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__high_op;
        SData/*15:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__low_op;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_hi;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_lo;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_lo_aligned;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mask_align;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_shifted;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_not_shifted;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__smaller_mantissa;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__larger_mantissa;
        SData/*13:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__smaller_mantissa_l;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__larger_mantissa_l;
        SData/*15:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l;
        SData/*12:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__normalized_mantissa_sum;
        SData/*11:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__round_this;
    };
    struct {
        SData/*10:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_sum;
        SData/*9:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction;
        SData/*9:0*/ add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final;
        IData/*31:0*/ add4_fp16_tb_full__DOT__pass_count;
        IData/*31:0*/ add4_fp16_tb_full__DOT__fail_count;
        IData/*31:0*/ add4_fp16_tb_full__DOT__fd;
        IData/*31:0*/ add4_fp16_tb_full__DOT__unnamedblk1__DOT__ret;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<CData/*0:0*/, 6> __Vm_traceActivity;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h91ae8b3f__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vadd4_fp16_tb_full__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vadd4_fp16_tb_full___024root(Vadd4_fp16_tb_full__Syms* symsp, const char* v__name);
    ~Vadd4_fp16_tb_full___024root();
    VL_UNCOPYABLE(Vadd4_fp16_tb_full___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
