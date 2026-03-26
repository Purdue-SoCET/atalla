// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsysarr_16_input_fp_adder.h for the primary calling header

#ifndef VERILATED_VSYSARR_16_INPUT_FP_ADDER___024ROOT_H_
#define VERILATED_VSYSARR_16_INPUT_FP_ADDER___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vsysarr_16_input_fp_adder__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsysarr_16_input_fp_adder___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_sysarr_16_input_adder__DOT__clk;
        CData/*0:0*/ tb_sysarr_16_input_adder__DOT__nRST;
        CData/*0:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__c_spec_case;
        CData/*0:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st1_spec_case;
        CData/*7:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__c_max_exp;
        CData/*3:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__c_max_idx;
        CData/*7:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_exp;
        CData/*3:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx;
        CData/*0:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st2_spec_case;
        CData/*4:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st3_hot_ones;
        CData/*7:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st3_exp;
        CData/*0:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st3_sign_max;
        CData/*0:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st3_spec_case;
        CData/*4:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st4_hot_ones;
        CData/*7:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st4_exp;
        CData/*0:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st4_sign_max;
        CData/*0:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st4_spec_case;
        CData/*0:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st5_sign;
        CData/*0:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st5_spec_case;
        CData/*7:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st5_exp;
        CData/*5:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st6_lzd;
        CData/*0:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st6_sign;
        CData/*0:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st6_spec_case;
        CData/*7:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st6_exp;
        CData/*0:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st7_sign;
        CData/*0:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st7_spec_case;
        CData/*0:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st7_is_zero;
        CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v0;
        CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v16;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_sysarr_16_input_adder__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_sysarr_16_input_adder__DOT__nRST__0;
        CData/*0:0*/ __VactContinue;
        SData/*10:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st7_e_final;
        IData/*31:0*/ tb_sysarr_16_input_adder__DOT__out_data;
        VlWide<16>/*511:0*/ tb_sysarr_16_input_adder__DOT__flat_in_data;
        IData/*31:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__c_spec_res;
        IData/*31:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st1_spec_res;
        IData/*31:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st2_spec_res;
        IData/*31:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st3_spec_res;
        IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st4_sum;
        IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st4_carry;
        IData/*31:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st4_spec_res;
        IData/*28:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st5_mag;
        IData/*31:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st5_spec_res;
        IData/*28:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st6_mag;
        IData/*31:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st6_spec_res;
        IData/*28:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st7_norm;
        IData/*31:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__st7_spec_res;
        IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v0;
        IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v1;
        IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v2;
        IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v3;
        IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v4;
        IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v5;
        IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v6;
        IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v7;
        IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v8;
        IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v9;
        IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v10;
        IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v11;
        IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v12;
        IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v13;
        IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v14;
    };
    struct {
        IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v15;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 16> tb_sysarr_16_input_adder__DOT__in_data;
        VlUnpacked<IData/*31:0*/, 16> tb_sysarr_16_input_adder__DOT__test_stimulus;
        VlUnpacked<IData/*31:0*/, 16> tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data;
        VlUnpacked<CData/*7:0*/, 16> tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr;
        VlUnpacked<CData/*3:0*/, 16> tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr;
        VlUnpacked<CData/*7:0*/, 8> tb_sysarr_16_input_adder__DOT__dut__DOT__e1;
        VlUnpacked<CData/*7:0*/, 4> tb_sysarr_16_input_adder__DOT__dut__DOT__e2;
        VlUnpacked<CData/*3:0*/, 8> tb_sysarr_16_input_adder__DOT__dut__DOT__i1;
        VlUnpacked<CData/*3:0*/, 4> tb_sysarr_16_input_adder__DOT__dut__DOT__i2;
        VlUnpacked<IData/*31:0*/, 16> tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data;
        VlUnpacked<CData/*7:0*/, 4> tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2;
        VlUnpacked<CData/*3:0*/, 4> tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2;
        VlUnpacked<CData/*7:0*/, 2> tb_sysarr_16_input_adder__DOT__dut__DOT__e3;
        VlUnpacked<CData/*3:0*/, 2> tb_sysarr_16_input_adder__DOT__dut__DOT__i3;
        VlUnpacked<IData/*31:0*/, 16> tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data;
        VlUnpacked<IData/*29:0*/, 16> tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op;
        VlUnpacked<CData/*0:0*/, 16> tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h21a46a7e__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vsysarr_16_input_fp_adder__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsysarr_16_input_fp_adder___024root(Vsysarr_16_input_fp_adder__Syms* symsp, const char* v__name);
    ~Vsysarr_16_input_fp_adder___024root();
    VL_UNCOPYABLE(Vsysarr_16_input_fp_adder___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
