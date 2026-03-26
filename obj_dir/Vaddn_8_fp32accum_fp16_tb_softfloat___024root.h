// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vaddn_8_fp32accum_fp16_tb_softfloat.h for the primary calling header

#ifndef VERILATED_VADDN_8_FP32ACCUM_FP16_TB_SOFTFLOAT___024ROOT_H_
#define VERILATED_VADDN_8_FP32ACCUM_FP16_TB_SOFTFLOAT___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vaddn_8_fp32accum_fp16_tb_softfloat__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vaddn_8_fp32accum_fp16_tb_softfloat___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_clk;
        CData/*0:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst;
        CData/*0:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__unnamedblk2__DOT__is_zero_result;
        CData/*0:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_is_nan_any;
        CData/*0:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_pos_inf;
        CData/*0:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_neg_inf;
        CData/*0:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_spec_case;
        CData/*4:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_max_exp;
        CData/*2:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_max_idx;
        CData/*4:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_exp;
        CData/*2:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_idx;
        CData/*0:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_spec_case;
        CData/*0:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_sticky;
        CData/*3:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_hot_ones;
        CData/*4:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_exp;
        CData/*0:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sign_max;
        CData/*0:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sticky;
        CData/*3:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_hot_ones;
        CData/*0:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_spec_case;
        CData/*0:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_res_sign;
        CData/*0:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_res_sign;
        CData/*0:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_sticky;
        CData/*4:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_exp;
        CData/*0:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_spec_case;
        CData/*5:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_lzd;
        CData/*5:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_lzd;
        CData/*0:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_sign;
        CData/*0:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_sticky;
        CData/*4:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_exp;
        CData/*0:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_spec_case;
        CData/*0:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__guard;
        CData/*0:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rnd;
        CData/*0:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__sticky;
        CData/*0:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__round_up;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst__0;
        CData/*0:0*/ __VactContinue;
        VlWide<4>/*127:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data;
        SData/*15:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result;
        SData/*15:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__exp;
        SData/*15:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__a;
        SData/*15:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__b;
        SData/*15:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__c;
        SData/*15:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__d;
        SData/*15:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__e;
        SData/*15:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__f;
        SData/*15:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__g;
        SData/*15:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__h;
        SData/*15:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__expected;
        SData/*10:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_e_final;
        SData/*9:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp;
        SData/*10:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded;
        IData/*31:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out;
        IData/*31:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__pass_count;
        IData/*31:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_count;
        IData/*31:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__off_by_one;
        IData/*31:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__off_by_two;
        IData/*31:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__off_by_five_plus;
        IData/*31:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__ulp_diff;
        IData/*31:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__ulp_big_count;
        IData/*31:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__fd;
        IData/*31:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_fd;
        IData/*31:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__total_count;
    };
    struct {
        IData/*31:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__unnamedblk2__DOT__ret;
        IData/*31:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_spec_res;
        IData/*31:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_spec_res;
        IData/*29:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s1_0;
        IData/*29:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c1_0;
        IData/*29:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s1_1;
        IData/*29:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c1_1;
        IData/*29:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s2_0;
        IData/*29:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c2_0;
        IData/*29:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s2_1;
        IData/*29:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c2_1;
        IData/*29:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s3_0;
        IData/*29:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c3_0;
        IData/*29:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s4_0;
        IData/*29:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c4_0;
        IData/*29:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sum_vec;
        IData/*29:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_carry_vec;
        IData/*31:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_spec_res;
        IData/*30:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_raw_sum;
        IData/*28:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_mag_sum;
        IData/*28:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_mag_sum;
        IData/*31:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_spec_res;
        IData/*28:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_scan;
        IData/*28:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_mag;
        IData/*31:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_spec_res;
        IData/*31:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__unnamedblk5__DOT__i;
        IData/*31:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__unnamedblk4__DOT__i;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a;
        QData/*63:0*/ addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b;
        VlUnpacked<SData/*15:0*/, 8> addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data;
        VlUnpacked<CData/*4:0*/, 8> addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr;
        VlUnpacked<CData/*2:0*/, 8> addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__idx_arr;
        VlUnpacked<CData/*4:0*/, 4> addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e1;
        VlUnpacked<CData/*4:0*/, 2> addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e2;
        VlUnpacked<CData/*2:0*/, 4> addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i1;
        VlUnpacked<CData/*2:0*/, 2> addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i2;
        VlUnpacked<SData/*15:0*/, 8> addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data;
        VlUnpacked<IData/*29:0*/, 8> addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op;
        VlUnpacked<CData/*5:0*/, 8> addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh;
        VlUnpacked<IData/*24:0*/, 8> addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base;
        VlUnpacked<CData/*0:0*/, 8> addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff;
        VlUnpacked<CData/*0:0*/, 6> __Vm_traceActivity;
    };
    double addn_8_fp32accum_fp16_tb_softfloat__DOT__total_ulp_diff;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h1382584b__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vaddn_8_fp32accum_fp16_tb_softfloat___024root(Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* symsp, const char* v__name);
    ~Vaddn_8_fp32accum_fp16_tb_softfloat___024root();
    VL_UNCOPYABLE(Vaddn_8_fp32accum_fp16_tb_softfloat___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
