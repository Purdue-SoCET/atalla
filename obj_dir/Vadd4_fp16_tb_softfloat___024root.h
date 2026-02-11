// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vadd4_fp16_tb_softfloat.h for the primary calling header

#ifndef VERILATED_VADD4_FP16_TB_SOFTFLOAT___024ROOT_H_
#define VERILATED_VADD4_FP16_TB_SOFTFLOAT___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vadd4_fp16_tb_softfloat_systolic_array_4_input_adder_if;


class Vadd4_fp16_tb_softfloat__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vadd4_fp16_tb_softfloat___024root final : public VerilatedModule {
  public:
    // CELLS
    Vadd4_fp16_tb_softfloat_systolic_array_4_input_adder_if* __PVT__add4_fp16_tb_softfloat__DOT__add_if;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__tb_clk;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__tb_nrst;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__is_zero_result;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_b_op;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_c_op;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_d_op;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_e;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_case;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special_case;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__result_s;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_e_out;
        CData/*3:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__num_leading_zeros;
        CData/*1:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__right_shift_radix;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_a;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_b;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_c;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_d;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_a;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_b;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_c;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_d;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_p;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_m;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_r;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_n;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_x;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_y;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_mx;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_nx;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_p;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_m;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_r;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_n;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_x;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_y;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_mx;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_nx;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__y_shift;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__m_shift;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__n_shift;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__y_op;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__m_op;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__n_op;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_nan_a;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_nan_b;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_nan_c;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_nan_d;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_a;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_b;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_c;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_d;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__special_case;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__unnamedblk1__DOT__has_pos_inf;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__unnamedblk1__DOT__has_neg_inf;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__s1__BRA__0__KET__;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c1__BRA__0__KET__;
        CData/*2:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__signed_sb_sum;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__next_result_s;
        CData/*3:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__next_num_leading_zeros;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__co;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__sum;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__co;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__sum;
    };
    struct {
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__co;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__sum;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__co;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__sum;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__co;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__sum;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__co;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__sum;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__co;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__sum;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__co;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__sum;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__co;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__sum;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__co;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__sum;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__co;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__sum;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__co;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__sum;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__13__KET____DOT__fa_1__co;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__13__KET____DOT__fa_1__sum;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__14__KET____DOT__fa_1__sum;
        CData/*3:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__leading_zeros_reg;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__sign_reg;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__exponent_reg;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__special_case_reg;
        CData/*1:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__right_shift_reg;
        CData/*6:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__new_exponent_internal;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__new_exponent;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__inf;
        CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__sticky;
        CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__sticky;
        CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__sticky;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__add4_fp16_tb_softfloat__DOT__tb_clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__add4_fp16_tb_softfloat__DOT__tb_nrst__0;
        CData/*0:0*/ __VactContinue;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__tb_a;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__tb_b;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__tb_c;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__tb_d;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__exp;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__a;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__b;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__c;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__d;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__expected;
        SData/*14:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f;
        SData/*14:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_y_f;
        SData/*14:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_m_f;
        SData/*14:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_n_f;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_result;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special_result;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_i;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__a_daz;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__b_daz;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__c_daz;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__d_daz;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_a;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_b;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_c;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_d;
    };
    struct {
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_p;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_m;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_r;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_n;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_x;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_y;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_mx;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_nx;
        SData/*14:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__x_mant;
        SData/*14:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__y_shifted;
        SData/*14:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__m_shifted;
        SData/*14:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__n_shifted;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__special_result;
        SData/*14:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__s2;
        SData/*14:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c2;
        SData/*13:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__shifted_sum;
        SData/*13:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__sum_reg;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__special_result_reg;
        SData/*10:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__rounded_mantissa_internal;
        SData/*14:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__result;
        SData/*14:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__result;
        SData/*14:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__result;
        IData/*31:0*/ add4_fp16_tb_softfloat__DOT__pass_count;
        IData/*31:0*/ add4_fp16_tb_softfloat__DOT__fail_count;
        IData/*31:0*/ add4_fp16_tb_softfloat__DOT__fd;
        IData/*31:0*/ add4_fp16_tb_softfloat__DOT__fail_fd;
        IData/*31:0*/ add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__ret;
        IData/*31:0*/ add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__total_count;
        IData/*16:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__magnitude_sum;
        IData/*31:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__unnamedblk1__DOT__k;
        IData/*16:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0;
        IData/*31:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_1_0;
        IData/*31:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_2_0;
        IData/*31:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<CData/*0:0*/, 6> __Vm_traceActivity;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h88600c86__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vadd4_fp16_tb_softfloat__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vadd4_fp16_tb_softfloat___024root(Vadd4_fp16_tb_softfloat__Syms* symsp, const char* v__name);
    ~Vadd4_fp16_tb_softfloat___024root();
    VL_UNCOPYABLE(Vadd4_fp16_tb_softfloat___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
