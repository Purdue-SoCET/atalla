// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vaddn_fp32accum_fp16_tb_softfloat.h for the primary calling header

#ifndef VERILATED_VADDN_FP32ACCUM_FP16_TB_SOFTFLOAT___024ROOT_H_
#define VERILATED_VADDN_FP32ACCUM_FP16_TB_SOFTFLOAT___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vaddn_fp32accum_fp16_tb_softfloat__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vaddn_fp32accum_fp16_tb_softfloat___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__tb_clk;
        CData/*0:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__tb_nrst;
        CData/*0:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__unnamedblk2__DOT__is_zero_result;
        CData/*4:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp;
        CData/*4:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp_eff;
        CData/*1:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx;
        CData/*0:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_max;
        CData/*0:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__is_nan_any;
        CData/*0:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_pos_inf;
        CData/*0:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_neg_inf;
        CData/*0:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_case;
        CData/*4:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_a_e;
        CData/*0:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_a_s;
        CData/*0:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_align_sticky;
        CData/*0:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_special_case;
        CData/*2:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_hot_ones;
        CData/*0:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__res_sign;
        CData/*4:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_exp_base;
        CData/*0:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_res_sign;
        CData/*0:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sticky;
        CData/*0:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_special;
        CData/*5:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros;
        CData/*4:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h0bb7bd8f__0;
        CData/*1:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h00fc99f2__0;
        CData/*4:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h0bb7bd8f__1;
        CData/*1:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h00fc99f2__1;
        CData/*0:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__guard;
        CData/*0:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rnd;
        CData/*0:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__sticky;
        CData/*0:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__round_up;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__addn_fp32accum_fp16_tb_softfloat__DOT__tb_clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__addn_fp32accum_fp16_tb_softfloat__DOT__tb_nrst__0;
        CData/*0:0*/ __VactContinue;
        QData/*63:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data;
        SData/*15:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__tb_result;
        SData/*15:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__exp;
        SData/*15:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__a;
        SData/*15:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__b;
        SData/*15:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__c;
        SData/*15:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__d;
        SData/*15:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__expected;
        SData/*10:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__final_exp_calc;
        SData/*9:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp;
        SData/*10:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded;
        IData/*31:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out;
        IData/*31:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__pass_count;
        IData/*31:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__fail_count;
        IData/*31:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__off_by_one;
        IData/*31:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__off_by_two;
        IData/*31:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__off_by_five_plus;
        IData/*31:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__ulp_diff;
        IData/*31:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__ulp_big_count;
        IData/*31:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__fd;
        IData/*31:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__fail_fd;
        IData/*31:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__total_count;
        IData/*31:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__unnamedblk2__DOT__ret;
        IData/*31:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_result;
        IData/*31:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_special_result;
        IData/*27:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_sum_vec;
        IData/*27:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_carry_vec;
        IData/*28:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__raw_sum;
        IData/*26:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mag_sum;
    };
    struct {
        IData/*26:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sum_mag;
        IData/*31:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_spec_res;
        IData/*26:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan;
        IData/*26:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__norm_val;
        IData/*22:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__final_mant;
        IData/*31:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__result_out;
        IData/*31:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__unnamedblk7__DOT__i;
        IData/*31:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__unnamedblk8__DOT__i;
        IData/*31:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__stage3_logic__DOT__unnamedblk9__DOT__i;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a;
        QData/*63:0*/ addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b;
        VlUnpacked<SData/*15:0*/, 4> addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in;
        VlUnpacked<CData/*4:0*/, 4> addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp;
        VlUnpacked<SData/*9:0*/, 4> addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac;
        VlUnpacked<CData/*0:0*/, 4> addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign;
        VlUnpacked<VlUnpacked<CData/*4:0*/, 4>, 3> addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp;
        VlUnpacked<VlUnpacked<CData/*1:0*/, 4>, 3> addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx;
        VlUnpacked<CData/*5:0*/, 4> addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift;
        VlUnpacked<IData/*24:0*/, 4> addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base;
        VlUnpacked<IData/*24:0*/, 4> addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant;
        VlUnpacked<CData/*0:0*/, 4> addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky;
        VlUnpacked<CData/*0:0*/, 4> addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff;
        VlUnpacked<IData/*27:0*/, 4> addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op;
        VlUnpacked<IData/*27:0*/, 4> addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s;
        VlUnpacked<IData/*27:0*/, 4> addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c;
        VlUnpacked<CData/*0:0*/, 6> __Vm_traceActivity;
    };
    double addn_fp32accum_fp16_tb_softfloat__DOT__total_ulp_diff;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h3cf440f3__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vaddn_fp32accum_fp16_tb_softfloat__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vaddn_fp32accum_fp16_tb_softfloat___024root(Vaddn_fp32accum_fp16_tb_softfloat__Syms* symsp, const char* v__name);
    ~Vaddn_fp32accum_fp16_tb_softfloat___024root();
    VL_UNCOPYABLE(Vaddn_fp32accum_fp16_tb_softfloat___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
