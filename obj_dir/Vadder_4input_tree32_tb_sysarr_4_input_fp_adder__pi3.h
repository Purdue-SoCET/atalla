// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vadder_4input_tree32_tb.h for the primary calling header

#ifndef VERILATED_VADDER_4INPUT_TREE32_TB_SYSARR_4_INPUT_FP_ADDER__PI3_H_
#define VERILATED_VADDER_4INPUT_TREE32_TB_SYSARR_4_INPUT_FP_ADDER__PI3_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vadder_4input_tree32_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(nRST,0,0);
        CData/*7:0*/ __PVT__exp_a;
        CData/*7:0*/ __PVT__exp_b;
        CData/*7:0*/ __PVT__exp_c;
        CData/*7:0*/ __PVT__exp_d;
        CData/*0:0*/ __PVT__sign_a;
        CData/*0:0*/ __PVT__sign_b;
        CData/*0:0*/ __PVT__sign_c;
        CData/*0:0*/ __PVT__sign_d;
        CData/*7:0*/ __PVT__exp_p;
        CData/*7:0*/ __PVT__exp_m;
        CData/*7:0*/ __PVT__exp_r;
        CData/*7:0*/ __PVT__exp_n;
        CData/*7:0*/ __PVT__exp_x;
        CData/*7:0*/ __PVT__exp_y;
        CData/*7:0*/ __PVT__exp_mx;
        CData/*7:0*/ __PVT__exp_nx;
        CData/*0:0*/ __PVT__sign_p;
        CData/*0:0*/ __PVT__sign_m;
        CData/*0:0*/ __PVT__sign_r;
        CData/*0:0*/ __PVT__sign_n;
        CData/*0:0*/ __PVT__sign_x;
        CData/*0:0*/ __PVT__sign_y;
        CData/*0:0*/ __PVT__sign_mx;
        CData/*0:0*/ __PVT__sign_nx;
        CData/*7:0*/ __PVT__exp_x_eff;
        CData/*7:0*/ __PVT__exp_y_eff;
        CData/*7:0*/ __PVT__exp_mx_eff;
        CData/*7:0*/ __PVT__exp_nx_eff;
        CData/*5:0*/ __PVT__safe_y_shift;
        CData/*5:0*/ __PVT__safe_m_shift;
        CData/*5:0*/ __PVT__safe_n_shift;
        CData/*0:0*/ __PVT__sticky_y;
        CData/*0:0*/ __PVT__sticky_m;
        CData/*0:0*/ __PVT__sticky_n;
        CData/*0:0*/ __PVT__y_op;
        CData/*0:0*/ __PVT__m_op;
        CData/*0:0*/ __PVT__n_op;
        CData/*0:0*/ __PVT__is_nan_any;
        CData/*0:0*/ __PVT__special_case;
        CData/*0:0*/ __PVT__any_pos_inf;
        CData/*0:0*/ __PVT__any_neg_inf;
        CData/*7:0*/ __PVT__st1_a_e;
        CData/*0:0*/ __PVT__st1_a_s;
        CData/*0:0*/ __PVT__st1_align_sticky;
        CData/*0:0*/ __PVT__st1_special_case;
        CData/*1:0*/ __PVT__st1_hot_ones;
        CData/*0:0*/ __PVT__res_sign;
        CData/*7:0*/ __PVT__st2_exp_base;
        CData/*0:0*/ __PVT__st2_res_sign;
        CData/*0:0*/ __PVT__st2_sticky;
        CData/*0:0*/ __PVT__st2_special;
        CData/*5:0*/ __PVT__lead_zeros;
        CData/*0:0*/ __PVT__guard_bit;
        CData/*0:0*/ __PVT__round_bit;
        CData/*0:0*/ __PVT__sticky_bit;
        CData/*0:0*/ __PVT__round_up;
        CData/*0:0*/ __PVT__l_bit;
        SData/*8:0*/ __PVT__y_shift;
        SData/*8:0*/ __PVT__m_shift;
        SData/*8:0*/ __PVT__n_shift;
        SData/*10:0*/ __PVT__final_exp_calc;
        IData/*25:0*/ __PVT__frac_a;
    };
    struct {
        IData/*25:0*/ __PVT__frac_b;
        IData/*25:0*/ __PVT__frac_c;
        IData/*25:0*/ __PVT__frac_d;
        IData/*25:0*/ __PVT__frac_p;
        IData/*25:0*/ __PVT__frac_m;
        IData/*25:0*/ __PVT__frac_r;
        IData/*25:0*/ __PVT__frac_n;
        IData/*25:0*/ __PVT__frac_x;
        IData/*25:0*/ __PVT__frac_y;
        IData/*25:0*/ __PVT__frac_mx;
        IData/*25:0*/ __PVT__frac_nx;
        VlWide<3>/*64:0*/ __PVT__raw_sum;
        IData/*25:0*/ __PVT__raw_mant;
        IData/*25:0*/ __PVT__final_mant;
        IData/*26:0*/ __PVT__rounded_mant_int;
        IData/*31:0*/ __PVT__stage3_logic__DOT__unnamedblk1__DOT__i;
        QData/*34:0*/ __PVT__safe_a;
        QData/*34:0*/ __PVT__safe_b;
        QData/*34:0*/ __PVT__safe_c;
        QData/*34:0*/ __PVT__safe_d;
        QData/*34:0*/ __PVT__a_daz;
        QData/*34:0*/ __PVT__b_daz;
        QData/*34:0*/ __PVT__c_daz;
        QData/*34:0*/ __PVT__d_daz;
        QData/*58:0*/ __PVT__x_mant;
        QData/*58:0*/ __PVT__y_shifted;
        QData/*58:0*/ __PVT__m_shifted;
        QData/*58:0*/ __PVT__n_shifted;
        QData/*58:0*/ __PVT__y_mant_base;
        QData/*58:0*/ __PVT__m_mant_base;
        QData/*58:0*/ __PVT__n_mant_base;
        QData/*34:0*/ __PVT__special_result;
        QData/*34:0*/ __PVT__st1_special_result;
        QData/*62:0*/ __PVT__st1_sum_vec;
        QData/*62:0*/ __PVT__st1_carry_vec;
        QData/*62:0*/ __PVT__mag_sum;
        QData/*62:0*/ __PVT__st2_sum_mag;
        QData/*34:0*/ __PVT__st2_spec_res;
        QData/*62:0*/ __PVT__lzd_scan;
        QData/*62:0*/ __PVT__norm_val;
        QData/*34:0*/ __PVT__result_out;
        QData/*62:0*/ __PVT__op_x;
        QData/*62:0*/ __PVT__op_y;
        QData/*62:0*/ __PVT__op_m;
        QData/*62:0*/ __PVT__op_n;
        QData/*62:0*/ __PVT__csa_s1;
        QData/*62:0*/ __PVT__csa_c1;
        QData/*62:0*/ __PVT__csa_s2;
        QData/*62:0*/ __PVT__csa_c2;
    };

    // INTERNAL VARIABLES
    Vadder_4input_tree32_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3(Vadder_4input_tree32_tb__Syms* symsp, const char* v__name);
    ~Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3();
    VL_UNCOPYABLE(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
