// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vadd_bf16_tb.h for the primary calling header

#ifndef VERILATED_VADD_BF16_TB___024ROOT_H_
#define VERILATED_VADD_BF16_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vadd_bf16_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vadd_bf16_tb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ add_bf16_tb__DOT__tb_clk;
    CData/*0:0*/ add_bf16_tb__DOT__tb_nrst;
    CData/*0:0*/ add_bf16_tb__DOT__tb_sub;
    CData/*0:0*/ add_bf16_tb__DOT__tb_invalid;
    CData/*0:0*/ add_bf16_tb__DOT__csv_sub;
    CData/*0:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_nan1;
    CData/*0:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_nan2;
    CData/*0:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_inf1;
    CData/*0:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_inf2;
    CData/*7:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__smaller_exponent;
    CData/*7:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_exponent;
    CData/*0:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_select;
    CData/*7:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_diff;
    CData/*7:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_max;
    CData/*0:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_shifted;
    CData/*0:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_not_shifted;
    CData/*0:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa_sign;
    CData/*0:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__result_sign;
    CData/*0:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__mantissa_overflow;
    CData/*0:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa_sign_l;
    CData/*0:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_shifted_l;
    CData/*0:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_not_shifted_l;
    CData/*0:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__signs_differ_l;
    CData/*7:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_max_l;
    CData/*3:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__norm_shift;
    CData/*7:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__u_exp1;
    CData/*7:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__u_shifted_amount;
    CData/*7:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__u_result;
    CData/*6:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__rounded_fraction;
    CData/*7:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_out_adj;
    CData/*7:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__round_sum;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__add_bf16_tb__DOT__tb_clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__add_bf16_tb__DOT__tb_nrst__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ add_bf16_tb__DOT__tb_a;
    SData/*15:0*/ add_bf16_tb__DOT__tb_b;
    SData/*15:0*/ add_bf16_tb__DOT__tb_result;
    SData/*15:0*/ add_bf16_tb__DOT__csv_a;
    SData/*15:0*/ add_bf16_tb__DOT__csv_b;
    SData/*15:0*/ add_bf16_tb__DOT__csv_exp;
    SData/*15:0*/ add_bf16_tb__DOT__dut__DOT__bf2_eff;
    SData/*9:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__frac_shifted;
    SData/*9:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__frac_not_shifted;
    SData/*9:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__smaller_mantissa;
    SData/*9:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa;
    SData/*10:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__mantissa_sum;
    SData/*9:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__smaller_mantissa_l;
    SData/*9:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa_l;
    SData/*8:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__normalized_mantissa_sum;
    SData/*8:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__round_this;
    SData/*8:0*/ add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__xor_out;
    IData/*31:0*/ add_bf16_tb__DOT__idx;
    IData/*31:0*/ add_bf16_tb__DOT__i;
    IData/*31:0*/ add_bf16_tb__DOT__fd;
    IData/*31:0*/ add_bf16_tb__DOT__csv_sub_i;
    IData/*31:0*/ add_bf16_tb__DOT__pass_cnt;
    IData/*31:0*/ add_bf16_tb__DOT__fail_cnt;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<SData/*15:0*/, 25> add_bf16_tb__DOT__A;
    VlUnpacked<SData/*15:0*/, 25> add_bf16_tb__DOT__B;
    VlUnpacked<SData/*15:0*/, 25> add_bf16_tb__DOT__EXP;
    VlUnpacked<CData/*0:0*/, 6> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hf547ea9c__0;
    VlTriggerScheduler __VtrigSched_hf547eadd__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vadd_bf16_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vadd_bf16_tb___024root(Vadd_bf16_tb__Syms* symsp, const char* v__name);
    ~Vadd_bf16_tb___024root();
    VL_UNCOPYABLE(Vadd_bf16_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
