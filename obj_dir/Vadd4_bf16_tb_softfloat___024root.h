// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vadd4_bf16_tb_softfloat.h for the primary calling header

#ifndef VERILATED_VADD4_BF16_TB_SOFTFLOAT___024ROOT_H_
#define VERILATED_VADD4_BF16_TB_SOFTFLOAT___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vadd4_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1;


class Vadd4_bf16_tb_softfloat__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vadd4_bf16_tb_softfloat___024root final : public VerilatedModule {
  public:
    // CELLS
    Vadd4_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1* __PVT__add4_bf16_tb_softfloat__DOT__add_if;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__tb_clk;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__tb_nrst;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__unnamedblk1__DOT__is_zero_result;
        CData/*7:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a;
        CData/*7:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b;
        CData/*7:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c;
        CData/*7:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d;
        CData/*6:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a;
        CData/*6:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b;
        CData/*6:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c;
        CData/*6:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d;
        CData/*7:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p;
        CData/*7:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m;
        CData/*7:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r;
        CData/*7:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n;
        CData/*7:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x;
        CData/*7:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y;
        CData/*7:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx;
        CData/*7:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx;
        CData/*6:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p;
        CData/*6:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m;
        CData/*6:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r;
        CData/*6:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n;
        CData/*6:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x;
        CData/*6:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y;
        CData/*6:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx;
        CData/*6:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_y;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_mx;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_nx;
        CData/*7:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff;
        CData/*7:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y_eff;
        CData/*7:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx_eff;
        CData/*7:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx_eff;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_y;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_m;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_n;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__y_op;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__m_op;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__n_op;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_any;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__any_pos_inf;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__any_neg_inf;
        CData/*7:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_e;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_align_sticky;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_case;
        CData/*1:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_hot_ones;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__res_sign;
        CData/*7:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_exp_base;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sticky;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special;
        CData/*5:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros;
    };
    struct {
        CData/*6:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_mant;
        CData/*6:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__final_mant;
        CData/*7:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mant_int;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__guard_bit;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__round_bit;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_bit;
        CData/*0:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__round_up;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__add4_bf16_tb_softfloat__DOT__tb_clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__add4_bf16_tb_softfloat__DOT__tb_nrst__0;
        CData/*0:0*/ __VactContinue;
        SData/*15:0*/ add4_bf16_tb_softfloat__DOT__tb_a;
        SData/*15:0*/ add4_bf16_tb_softfloat__DOT__tb_b;
        SData/*15:0*/ add4_bf16_tb_softfloat__DOT__tb_c;
        SData/*15:0*/ add4_bf16_tb_softfloat__DOT__tb_d;
        SData/*15:0*/ add4_bf16_tb_softfloat__DOT__exp;
        SData/*15:0*/ add4_bf16_tb_softfloat__DOT__a;
        SData/*15:0*/ add4_bf16_tb_softfloat__DOT__b;
        SData/*15:0*/ add4_bf16_tb_softfloat__DOT__c;
        SData/*15:0*/ add4_bf16_tb_softfloat__DOT__d;
        SData/*15:0*/ add4_bf16_tb_softfloat__DOT__expected;
        SData/*15:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz;
        SData/*15:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz;
        SData/*15:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz;
        SData/*15:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz;
        SData/*8:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift;
        SData/*8:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift;
        SData/*8:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift;
        SData/*15:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result;
        SData/*15:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_result;
        SData/*15:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_spec_res;
        SData/*10:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc;
        SData/*15:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__result_out;
        IData/*31:0*/ add4_bf16_tb_softfloat__DOT__pass_count;
        IData/*31:0*/ add4_bf16_tb_softfloat__DOT__fail_count;
        IData/*31:0*/ add4_bf16_tb_softfloat__DOT__off_by_one;
        IData/*31:0*/ add4_bf16_tb_softfloat__DOT__off_by_two;
        IData/*31:0*/ add4_bf16_tb_softfloat__DOT__off_by_five_plus;
        IData/*31:0*/ add4_bf16_tb_softfloat__DOT__diff;
        IData/*31:0*/ add4_bf16_tb_softfloat__DOT__fd;
        IData/*31:0*/ add4_bf16_tb_softfloat__DOT__fail_fd;
        IData/*31:0*/ add4_bf16_tb_softfloat__DOT__unnamedblk1__DOT__ret;
        IData/*31:0*/ add4_bf16_tb_softfloat__DOT__unnamedblk1__DOT__total_count;
        IData/*21:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant;
        IData/*21:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted;
        IData/*21:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted;
        IData/*21:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted;
        IData/*21:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base;
        IData/*21:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base;
        IData/*21:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base;
        IData/*24:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_sum_vec;
        IData/*24:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_carry_vec;
        IData/*25:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum;
        IData/*23:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum;
        IData/*23:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag;
        IData/*23:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan;
        IData/*23:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val;
        IData/*24:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__op_x;
        IData/*24:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__op_y;
        IData/*24:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__op_m;
        IData/*24:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__op_n;
        IData/*24:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1;
        IData/*24:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c1;
        IData/*24:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s2;
    };
    struct {
        IData/*24:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c2;
        IData/*31:0*/ add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__stage3_logic__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<CData/*0:0*/, 6> __Vm_traceActivity;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hb1168b56__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vadd4_bf16_tb_softfloat__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vadd4_bf16_tb_softfloat___024root(Vadd4_bf16_tb_softfloat__Syms* symsp, const char* v__name);
    ~Vadd4_bf16_tb_softfloat___024root();
    VL_UNCOPYABLE(Vadd4_bf16_tb_softfloat___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
