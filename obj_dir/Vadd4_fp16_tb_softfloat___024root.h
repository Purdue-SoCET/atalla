// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vadd4_fp16_tb_softfloat.h for the primary calling header

#ifndef VERILATED_VADD4_FP16_TB_SOFTFLOAT___024ROOT_H_
#define VERILATED_VADD4_FP16_TB_SOFTFLOAT___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vadd4_fp16_tb_softfloat_systolic_array_4_input_adder_if__pi1;


class Vadd4_fp16_tb_softfloat__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vadd4_fp16_tb_softfloat___024root final : public VerilatedModule {
  public:
    // CELLS
    Vadd4_fp16_tb_softfloat_systolic_array_4_input_adder_if__pi1* __PVT__add4_fp16_tb_softfloat__DOT__add_if;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__tb_clk;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__tb_nrst;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__is_zero_result;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_y;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_mx;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_nx;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y_eff;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx_eff;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx_eff;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_y;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_m;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_n;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_op;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_op;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_op;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_a;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_b;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_c;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_d;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_inf_a;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_inf_b;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_inf_c;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_inf_d;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_b_op;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_c_op;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_d_op;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_e;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_alignment_sticky;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_case;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__next_result_s;
        CData/*3:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__next_num_leading_zeros;
        CData/*1:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__next_right_shift_radix;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_alignment_sticky;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_result_s;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_a_e_out;
        CData/*3:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_num_leading_zeros;
        CData/*1:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_right_shift_radix;
    };
    struct {
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special_case;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__guard;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_shifted_out;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round_up;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__overflow;
        CData/*6:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__new_exponent_internal;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__new_exponent;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__inf;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage1_combinational__DOT__unnamedblk1__DOT__has_pos_inf;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage1_combinational__DOT__unnamedblk1__DOT__has_neg_inf;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val;
        CData/*4:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__get_sticky_mask__50__shift_amt;
        CData/*4:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__get_sticky_mask__51__shift_amt;
        CData/*4:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__get_sticky_mask__52__shift_amt;
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
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx;
        SData/*14:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant;
        SData/*14:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base;
        SData/*14:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base;
        SData/*14:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base;
        SData/*14:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted;
        SData/*14:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted;
        SData/*14:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result;
        SData/*14:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f;
        SData/*14:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_y_f;
        SData/*14:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_m_f;
        SData/*14:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_n_f;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_result;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__corrected_sum;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_i;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special_result;
        SData/*14:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_raw;
        SData/*14:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_raw;
    };
    struct {
        SData/*14:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_raw;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_reg_st3;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__unrounded_mantissa;
        SData/*10:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mantissa_internal;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_mantissa;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_sum_next;
        SData/*14:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__get_sticky_mask__50__Vfuncout;
        SData/*14:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__get_sticky_mask__51__Vfuncout;
        SData/*14:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__get_sticky_mask__52__Vfuncout;
        IData/*31:0*/ add4_fp16_tb_softfloat__DOT__pass_count;
        IData/*31:0*/ add4_fp16_tb_softfloat__DOT__fail_count;
        IData/*31:0*/ add4_fp16_tb_softfloat__DOT__fd;
        IData/*31:0*/ add4_fp16_tb_softfloat__DOT__fail_fd;
        IData/*31:0*/ add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__ret;
        IData/*31:0*/ add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__total_count;
        IData/*17:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext;
        IData/*17:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext;
        IData/*17:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext;
        IData/*17:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext;
        IData/*17:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1;
        IData/*17:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1;
        IData/*17:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2;
        IData/*17:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2;
        IData/*17:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__magnitude_sum;
        IData/*19:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shifted_sum;
        IData/*31:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk2__DOT__i;
        IData/*31:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__i;
        IData/*31:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk5__DOT__k;
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
