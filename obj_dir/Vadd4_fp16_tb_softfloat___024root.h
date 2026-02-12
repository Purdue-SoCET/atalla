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
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_y;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_m;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_n;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_op;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_op;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_op;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_e;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_b_op;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_c_op;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_d_op;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_align_sticky;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_case;
        CData/*5:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__res_sign;
        CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_exp_base;
        CData/*5:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_lzd;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sticky;
        CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__add4_fp16_tb_softfloat__DOT__tb_clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__add4_fp16_tb_softfloat__DOT__tb_nrst__0;
        CData/*0:0*/ __VactContinue;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__tb_a;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__tb_b;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__tb_c;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__tb_d;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__a;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__b;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__c;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__d;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__expected;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx;
        SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_result;
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_spec_res;
    };
    struct {
        SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__result_out;
        IData/*31:0*/ add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__ret;
        IData/*31:0*/ add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__total_count;
        IData/*31:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_logic__DOT__unnamedblk2__DOT__i;
        IData/*31:0*/ __VactIterCount;
        QData/*36:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant;
        QData/*36:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted;
        QData/*36:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted;
        QData/*36:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted;
        QData/*36:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f;
        QData/*36:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_y_f;
        QData/*36:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_m_f;
        QData/*36:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_n_f;
        QData/*38:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum;
        QData/*38:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag;
        QData/*40:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1;
        QData/*40:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1;
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
