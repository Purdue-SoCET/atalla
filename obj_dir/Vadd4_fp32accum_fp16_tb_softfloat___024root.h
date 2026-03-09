// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vadd4_fp32accum_fp16_tb_softfloat.h for the primary calling header

#ifndef VERILATED_VADD4_FP32ACCUM_FP16_TB_SOFTFLOAT___024ROOT_H_
#define VERILATED_VADD4_FP32ACCUM_FP16_TB_SOFTFLOAT___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vadd4_fp32accum_fp16_tb_softfloat_systolic_array_4_input_adder_if__pi1;


class Vadd4_fp32accum_fp16_tb_softfloat__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vadd4_fp32accum_fp16_tb_softfloat___024root final : public VerilatedModule {
  public:
    // CELLS
    Vadd4_fp32accum_fp16_tb_softfloat_systolic_array_4_input_adder_if__pi1* __PVT__add4_fp32accum_fp16_tb_softfloat__DOT__add_if;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__tb_clk;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__tb_nrst;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__unnamedblk1__DOT__is_zero_result;
        CData/*7:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a;
        CData/*7:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b;
        CData/*7:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c;
        CData/*7:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d;
        CData/*7:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p;
        CData/*7:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m;
        CData/*7:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r;
        CData/*7:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n;
        CData/*7:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x;
        CData/*7:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y;
        CData/*7:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx;
        CData/*7:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_y;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_mx;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_nx;
        CData/*7:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff;
        CData/*7:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y_eff;
        CData/*7:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx_eff;
        CData/*7:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx_eff;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_y;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_m;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_n;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_op;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_op;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_op;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_any;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__any_pos_inf;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__any_neg_inf;
        CData/*7:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_e;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_align_sticky;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_case;
        CData/*1:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_hot_ones;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__res_sign;
        CData/*7:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_exp_base;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sticky;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special;
        CData/*6:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__guard_bit;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round_bit;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_bit;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round_up;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__0__KET____DOT__local_s;
        CData/*4:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__0__KET____DOT__local_e;
        CData/*4:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__0__KET____DOT__local_lzd;
        CData/*7:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__0__KET____DOT__unnamedblk2__DOT__promoted_exp;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__1__KET____DOT__local_s;
        CData/*4:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__1__KET____DOT__local_e;
        CData/*4:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__1__KET____DOT__local_lzd;
        CData/*7:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__1__KET____DOT__unnamedblk2__DOT__promoted_exp;
    };
    struct {
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__2__KET____DOT__local_s;
        CData/*4:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__2__KET____DOT__local_e;
        CData/*4:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__2__KET____DOT__local_lzd;
        CData/*7:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__2__KET____DOT__unnamedblk2__DOT__promoted_exp;
        CData/*0:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__3__KET____DOT__local_s;
        CData/*4:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__3__KET____DOT__local_e;
        CData/*4:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__3__KET____DOT__local_lzd;
        CData/*7:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__3__KET____DOT__unnamedblk2__DOT__promoted_exp;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__add4_fp32accum_fp16_tb_softfloat__DOT__tb_clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__add4_fp32accum_fp16_tb_softfloat__DOT__tb_nrst__0;
        CData/*0:0*/ __VactContinue;
        SData/*15:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__tb_a;
        SData/*15:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__tb_b;
        SData/*15:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__tb_c;
        SData/*15:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__tb_d;
        SData/*8:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift;
        SData/*8:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift;
        SData/*8:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift;
        SData/*10:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc;
        SData/*15:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__0__KET____DOT__local_in;
        SData/*9:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__0__KET____DOT__local_f;
        SData/*15:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__1__KET____DOT__local_in;
        SData/*9:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__1__KET____DOT__local_f;
        SData/*15:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__2__KET____DOT__local_in;
        SData/*9:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__2__KET____DOT__local_f;
        SData/*15:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__3__KET____DOT__local_in;
        SData/*9:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__3__KET____DOT__local_f;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__exp;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__pass_count;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__fail_count;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__off_by_one;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__off_by_two;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__off_by_five_plus;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__diff;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__fd;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__fail_fd;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__a;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__b;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__c;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__d;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__expected;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__unnamedblk1__DOT__ret;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__unnamedblk1__DOT__total_count;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz;
        IData/*22:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a;
        IData/*22:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b;
        IData/*22:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c;
        IData/*22:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d;
        IData/*22:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p;
        IData/*22:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m;
        IData/*22:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r;
        IData/*22:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n;
        IData/*22:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x;
        IData/*22:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y;
        IData/*22:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx;
        IData/*22:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_result;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_spec_res;
        IData/*22:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_mant;
    };
    struct {
        IData/*22:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_mant;
        IData/*23:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mant_int;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__result_out;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__0__KET____DOT__unnamedblk1__DOT__j;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__1__KET____DOT__unnamedblk1__DOT__j;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__2__KET____DOT__unnamedblk1__DOT__j;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__fp16_to_fp32_conversion__BRA__3__KET____DOT__unnamedblk1__DOT__j;
        IData/*31:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage3_logic__DOT__unnamedblk3__DOT__i;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a;
        QData/*63:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b;
        QData/*34:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant;
        QData/*34:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted;
        QData/*34:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted;
        QData/*34:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted;
        QData/*34:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base;
        QData/*34:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base;
        QData/*34:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base;
        QData/*37:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_sum_vec;
        QData/*37:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_carry_vec;
        QData/*38:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum;
        QData/*36:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum;
        QData/*36:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag;
        QData/*36:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan;
        QData/*36:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val;
        QData/*37:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__op_x;
        QData/*37:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__op_y;
        QData/*37:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__op_m;
        QData/*37:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__op_n;
        QData/*37:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1;
        QData/*37:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c1;
        QData/*37:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s2;
        QData/*37:0*/ add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c2;
        VlUnpacked<IData/*31:0*/, 4> add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__out_v;
        VlUnpacked<CData/*0:0*/, 6> __Vm_traceActivity;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h8c095862__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vadd4_fp32accum_fp16_tb_softfloat__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vadd4_fp32accum_fp16_tb_softfloat___024root(Vadd4_fp32accum_fp16_tb_softfloat__Syms* symsp, const char* v__name);
    ~Vadd4_fp32accum_fp16_tb_softfloat___024root();
    VL_UNCOPYABLE(Vadd4_fp32accum_fp16_tb_softfloat___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
