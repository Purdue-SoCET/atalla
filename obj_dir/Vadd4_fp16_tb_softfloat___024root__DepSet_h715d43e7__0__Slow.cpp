// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd4_fp16_tb_softfloat.h for the primary calling header

#include "Vadd4_fp16_tb_softfloat__pch.h"
#include "Vadd4_fp16_tb_softfloat___024root.h"

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___eval_static(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___eval_static\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__add4_fp16_tb_softfloat__DOT__tb_clk__0 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__add4_fp16_tb_softfloat__DOT__tb_nrst__0 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_nrst;
}

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___eval_final(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___eval_final\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___dump_triggers__stl(Vadd4_fp16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vadd4_fp16_tb_softfloat___024root___eval_phase__stl(Vadd4_fp16_tb_softfloat___024root* vlSelf);

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___eval_settle(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___eval_settle\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vadd4_fp16_tb_softfloat___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 21, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vadd4_fp16_tb_softfloat___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___dump_triggers__stl(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___dump_triggers__stl\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___stl_sequent__TOP__0(Vadd4_fp16_tb_softfloat___024root* vlSelf);

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___eval_stl(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___eval_stl\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vadd4_fp16_tb_softfloat___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___stl_sequent__TOP__0(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___stl_sequent__TOP__0\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz = 0;
    SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz = 0;
    SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz = 0;
    SData/*15:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz = 0;
    CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a = 0;
    CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b = 0;
    CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c = 0;
    CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d = 0;
    SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a = 0;
    SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b = 0;
    SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c = 0;
    SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d = 0;
    CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a = 0;
    CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b = 0;
    CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c = 0;
    CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d = 0;
    CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff = 0;
    CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y_eff;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y_eff = 0;
    CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx_eff;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx_eff = 0;
    CData/*4:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx_eff;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx_eff = 0;
    CData/*5:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift = 0;
    CData/*5:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift = 0;
    CData/*5:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift = 0;
    QData/*36:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base = 0;
    QData/*36:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base = 0;
    QData/*36:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base = 0;
    CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_any;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_any = 0;
    QData/*40:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a = 0;
    QData/*40:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b = 0;
    QData/*40:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c = 0;
    QData/*40:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_d;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_d = 0;
    QData/*39:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum = 0;
    QData/*38:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val = 0;
    SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_mant;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_mant = 0;
    SData/*9:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_mant;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_mant = 0;
    SData/*10:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mant_int;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mant_int = 0;
    CData/*7:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc = 0;
    CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__guard_bit;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__guard_bit = 0;
    CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round_bit;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round_bit = 0;
    CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_bit;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_bit = 0;
    CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round_up;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round_up = 0;
    CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__any_pos_inf;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__any_pos_inf = 0;
    CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__any_neg_inf;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__any_neg_inf = 0;
    QData/*40:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1_shifted;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1_shifted = 0;
    CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 = 0;
    CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 = 0;
    // Body
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val 
        = (0x7fffffffffULL & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag 
                              << (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_lzd)));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_mant 
        = (0x3ffU & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val 
                             >> 0x1cU)));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__guard_bit 
        = (1U & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val 
                         >> 0x1bU)));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round_bit 
        = (1U & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val 
                         >> 0x1aU)));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_bit 
        = ((0U != (0x3ffffffU & (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val))) 
           | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sticky));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round_up 
        = ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__guard_bit) 
           & (((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round_bit) 
               | (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_bit)) 
              | (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_mant)));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mant_int 
        = (0x7ffU & ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_mant) 
                     + (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round_up)));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_mant 
        = ((0x400U & (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mant_int))
            ? 0U : (0x3ffU & (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mant_int)));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc 
        = (0xffU & ((((IData)(2U) + VL_EXTENDS_II(8,7, (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(8,8, (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_lzd))) 
                    + VL_EXTENDS_II(8,11, (1U & ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mant_int) 
                                                 >> 0xaU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__result_out 
        = ((0ULL == vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag)
            ? ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign) 
               << 0xfU) : (VL_LTES_III(32, 0x1fU, VL_EXTENDS_II(32,8, (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc)))
                            ? (0x7c00U | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign) 
                                          << 0xfU))
                            : (VL_GTES_III(32, 0U, 
                                           VL_EXTENDS_II(32,8, (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc)))
                                ? ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign) 
                                   << 0xfU) : (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign) 
                                                << 0xfU) 
                                               | ((0x7c00U 
                                                   & ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc) 
                                                      << 0xaU)) 
                                                  | (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_mant))))));
    if (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__result_out 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_spec_res;
    }
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
        = (0x1ffffffffffULL & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_b_op)
                                ? (- vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_y_f)
                                : vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_y_f));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
        = (0x1ffffffffffULL & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_c_op)
                                ? (- vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_m_f)
                                : vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_m_f));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_d 
        = (0x1ffffffffffULL & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_d_op)
                                ? (- vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_n_f)
                                : vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_n_f));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a) 
                  ^ (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b)) 
                 ^ (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fffffffffeULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | (IData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a) 
                   & (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b)) 
                  | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b) 
                     & (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c))) 
                 | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c) 
                    & (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fffffffffeULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | (IData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 1U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                              >> 1U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 1U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fffffffffdULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 1U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 1U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                               >> 1U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 1U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                 >> 1U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 1U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                >> 1U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fffffffffdULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 1U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 2U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                              >> 2U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 2U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fffffffffbULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 2U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 2U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                               >> 2U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 2U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                 >> 2U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 2U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                >> 2U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fffffffffbULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 2U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 3U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                              >> 3U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 3U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fffffffff7ULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 3U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 3U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                               >> 3U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 3U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                 >> 3U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 3U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                >> 3U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fffffffff7ULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 3U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 4U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                              >> 4U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 4U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffffffffefULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 4U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 4U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                               >> 4U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 4U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                 >> 4U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 4U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                >> 4U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffffffffefULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 4U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 5U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                              >> 5U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 5U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffffffffdfULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 5U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 5U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                               >> 5U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 5U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                 >> 5U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 5U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                >> 5U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffffffffdfULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 5U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 6U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                              >> 6U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 6U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffffffffbfULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 6U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 6U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                               >> 6U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 6U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                 >> 6U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 6U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                >> 6U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffffffffbfULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 6U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 7U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                              >> 7U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 7U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffffffff7fULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 7U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 7U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                               >> 7U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 7U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                 >> 7U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 7U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                >> 7U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffffffff7fULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 7U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 8U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                              >> 8U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 8U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fffffffeffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 8U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 8U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                               >> 8U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 8U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                 >> 8U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 8U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                >> 8U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fffffffeffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 8U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 9U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                              >> 9U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 9U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fffffffdffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 9U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 9U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                               >> 9U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 9U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                 >> 9U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 9U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                >> 9U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fffffffdffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 9U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0xaU)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                >> 0xaU))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0xaU))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fffffffbffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0xaU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0xaU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0xaU))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0xaU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                   >> 0xaU)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0xaU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                  >> 0xaU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fffffffbffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0xaU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0xbU)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                >> 0xbU))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0xbU))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fffffff7ffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0xbU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0xbU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0xbU))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0xbU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                   >> 0xbU)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0xbU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                  >> 0xbU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fffffff7ffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0xbU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0xcU)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                >> 0xcU))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0xcU))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffffffefffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0xcU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0xcU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0xcU))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0xcU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                   >> 0xcU)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0xcU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                  >> 0xcU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffffffefffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0xcU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0xdU)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                >> 0xdU))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0xdU))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffffffdfffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0xdU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0xdU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0xdU))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0xdU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                   >> 0xdU)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0xdU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                  >> 0xdU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffffffdfffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0xdU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0xeU)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                >> 0xeU))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0xeU))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffffffbfffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0xeU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0xeU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0xeU))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0xeU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                   >> 0xeU)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0xeU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                  >> 0xeU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffffffbfffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0xeU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0xfU)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                >> 0xfU))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0xfU))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffffff7fffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0xfU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0xfU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0xfU))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0xfU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                   >> 0xfU)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0xfU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                  >> 0xfU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffffff7fffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0xfU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x10U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x10U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x10U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fffffeffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0x10U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x10U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x10U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x10U)) & (IData)(
                                                   (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x10U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x10U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x10U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fffffeffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0x10U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x11U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x11U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x11U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fffffdffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0x11U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x11U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x11U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x11U)) & (IData)(
                                                   (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x11U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x11U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x11U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fffffdffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0x11U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x12U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x12U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x12U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fffffbffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0x12U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x12U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x12U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x12U)) & (IData)(
                                                   (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x12U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x12U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x12U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fffffbffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0x12U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x13U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x13U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x13U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fffff7ffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0x13U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x13U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x13U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x13U)) & (IData)(
                                                   (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x13U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x13U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x13U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fffff7ffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0x13U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x14U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x14U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x14U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffffefffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0x14U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x14U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x14U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x14U)) & (IData)(
                                                   (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x14U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x14U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x14U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffffefffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0x14U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x15U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x15U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x15U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffffdfffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0x15U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x15U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x15U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x15U)) & (IData)(
                                                   (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x15U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x15U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x15U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffffdfffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0x15U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x16U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x16U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x16U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffffbfffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0x16U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x16U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x16U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x16U)) & (IData)(
                                                   (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x16U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x16U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x16U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffffbfffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0x16U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x17U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x17U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x17U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffff7fffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0x17U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x17U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x17U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x17U)) & (IData)(
                                                   (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x17U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x17U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x17U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffff7fffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0x17U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x18U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x18U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x18U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fffeffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0x18U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x18U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x18U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x18U)) & (IData)(
                                                   (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x18U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x18U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x18U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fffeffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0x18U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x19U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x19U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x19U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fffdffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0x19U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x19U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x19U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x19U)) & (IData)(
                                                   (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x19U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x19U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x19U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fffdffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0x19U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x1aU)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x1aU))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x1aU))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fffbffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0x1aU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x1aU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x1aU))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x1aU)) & (IData)(
                                                   (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x1aU)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x1aU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x1aU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fffbffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0x1aU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x1bU)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x1bU))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x1bU))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fff7ffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0x1bU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x1bU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x1bU))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x1bU)) & (IData)(
                                                   (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x1bU)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x1bU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x1bU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fff7ffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0x1bU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x1cU)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x1cU))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x1cU))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffefffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0x1cU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x1cU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x1cU))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x1cU)) & (IData)(
                                                   (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x1cU)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x1cU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x1cU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffefffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0x1cU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x1dU)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x1dU))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x1dU))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffdfffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0x1dU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x1dU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x1dU))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x1dU)) & (IData)(
                                                   (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x1dU)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x1dU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x1dU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffdfffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0x1dU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x1eU)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x1eU))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x1eU))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffbfffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0x1eU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x1eU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x1eU))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x1eU)) & (IData)(
                                                   (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x1eU)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x1eU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x1eU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffbfffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0x1eU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x1fU)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x1fU))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x1fU))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ff7fffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0x1fU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x1fU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x1fU))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x1fU)) & (IData)(
                                                   (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x1fU)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x1fU)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x1fU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ff7fffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0x1fU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x20U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x20U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x20U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1feffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0x20U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x20U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x20U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x20U)) & (IData)(
                                                   (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x20U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x20U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x20U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1feffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0x20U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x21U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x21U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x21U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fdffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0x21U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x21U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x21U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x21U)) & (IData)(
                                                   (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x21U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x21U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x21U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fdffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0x21U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x22U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x22U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x22U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fbffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0x22U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x22U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x22U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x22U)) & (IData)(
                                                   (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x22U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x22U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x22U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fbffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0x22U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x23U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x23U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x23U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1f7ffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0x23U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x23U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x23U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x23U)) & (IData)(
                                                   (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x23U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x23U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x23U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1f7ffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0x23U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x24U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x24U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x24U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1efffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0x24U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x24U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x24U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x24U)) & (IData)(
                                                   (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x24U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x24U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x24U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1efffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0x24U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x25U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x25U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x25U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1dfffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0x25U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x25U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x25U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x25U)) & (IData)(
                                                   (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x25U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x25U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x25U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1dfffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0x25U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x26U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x26U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x26U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1bfffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0x26U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x26U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x26U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x26U)) & (IData)(
                                                   (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x26U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x26U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x26U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1bfffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0x26U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x27U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x27U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x27U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x17fffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0x27U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x27U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x27U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x27U)) & (IData)(
                                                   (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x27U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x27U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x27U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x17fffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0x27U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0 
        = (1U & (((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x28U)) ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x28U))) 
                 ^ (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x28U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0xffffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h914b6452__0)) 
              << 0x28U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0 
        = (1U & ((((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x28U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x28U))) 
                  | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x28U)) & (IData)(
                                                   (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x28U)))) 
                 | ((IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x28U)) & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x28U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0xffffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h4877f06b__0)) 
              << 0x28U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1_shifted 
        = (0x1ffffffffffULL & VL_SHIFTL_QQI(41,41,32, vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1, 1U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum 
        = (0xffffffffffULL & ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
                               + add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1_shifted) 
                              + add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_d));
    if ((1U & (IData)((add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum 
                       >> 0x27U)))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum 
            = (0x7fffffffffULL & (1ULL + (~ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum)));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s)));
    } else {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum 
            = (0x7fffffffffULL & add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum);
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__res_sign 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s;
    }
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros = 0x26U;
    if ((0ULL == vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum)) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros = 0x26U;
    } else {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_logic__DOT__unnamedblk2__DOT__i = 0x26U;
        {
            while (VL_LTES_III(32, 0U, vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_logic__DOT__unnamedblk2__DOT__i)) {
                if (((0x26U >= (0x3fU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_logic__DOT__unnamedblk2__DOT__i)) 
                     && (1U & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum 
                                       >> (0x3fU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_logic__DOT__unnamedblk2__DOT__i)))))) {
                    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros 
                        = (0x3fU & ((IData)(0x26U) 
                                    - vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_logic__DOT__unnamedblk2__DOT__i));
                    goto __Vlabel1;
                }
                vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_logic__DOT__unnamedblk2__DOT__i 
                    = (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_logic__DOT__unnamedblk2__DOT__i 
                       - (IData)(1U));
            }
            __Vlabel1: ;
        }
    }
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz 
        = ((0U == (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a) 
                            >> 0xaU))) ? (0x8000U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a))
            : (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz 
        = ((0U == (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b) 
                            >> 0xaU))) ? (0x8000U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b))
            : (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz 
        = ((0U == (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c) 
                            >> 0xaU))) ? (0x8000U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c))
            : (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz 
        = ((0U == (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d) 
                            >> 0xaU))) ? (0x8000U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d))
            : (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a 
        = (1U & ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz) 
                 >> 0xfU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a 
        = (0x1fU & ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz) 
                    >> 0xaU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a 
        = (0x3ffU & (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b 
        = (1U & ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz) 
                 >> 0xfU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b 
        = (0x1fU & ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz) 
                    >> 0xaU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b 
        = (0x3ffU & (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c 
        = (1U & ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz) 
                 >> 0xfU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c 
        = (0x1fU & ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz) 
                    >> 0xaU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c 
        = (0x3ffU & (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d 
        = (1U & ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz) 
                 >> 0xfU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d 
        = (0x1fU & ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz) 
                    >> 0xaU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d 
        = (0x3ffU & (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_any 
        = (((((0x1fU == (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a)) 
              & (0U != (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a))) 
             | ((0x1fU == (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b)) 
                & (0U != (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b)))) 
            | ((0x1fU == (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c)) 
               & (0U != (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c)))) 
           | ((0x1fU == (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d)) 
              & (0U != (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d))));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__any_pos_inf 
        = ((((((0x1fU == (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a)) 
               & (~ (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a))))) 
             | (((0x1fU == (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b)) 
                 & (~ (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b)))))) 
            | (((0x1fU == (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c)) 
                & (~ (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c)))))) 
           | (((0x1fU == (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d)) 
               & (~ (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d))))));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__any_neg_inf 
        = ((((((0x1fU == (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a)) 
               & (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a))))) 
             | (((0x1fU == (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b)) 
                 & (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b)))))) 
            | (((0x1fU == (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c)) 
                & (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c)))))) 
           | (((0x1fU == (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d)) 
               & (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d))))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = 0U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = 0U;
    if (((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_any) 
         | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__any_pos_inf) 
            & (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__any_neg_inf)))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = 1U;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = 0xfe00U;
    } else if (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__any_pos_inf) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = 1U;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = 0x7c00U;
    } else if (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__any_neg_inf) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = 1U;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = 0xfc00U;
    }
    if (((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a) 
         >= (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p 
            = add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p 
            = add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p 
            = add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m 
            = add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m 
            = add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m 
            = add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b;
    } else {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p 
            = add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p 
            = add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p 
            = add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m 
            = add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m 
            = add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m 
            = add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a;
    }
    if (((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c) 
         >= (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r 
            = add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r 
            = add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r 
            = add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n 
            = add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n 
            = add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n 
            = add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d;
    } else {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r 
            = add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r 
            = add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r 
            = add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n 
            = add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n 
            = add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n 
            = add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p) 
         >= (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_y 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_mx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_nx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n;
    } else {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_y 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_mx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_nx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m;
    }
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x))
            ? 1U : (0x1fU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x)));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y))
            ? 1U : (0x1fU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y)));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx))
            ? 1U : (0x1fU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx)));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx))
            ? 1U : (0x1fU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx)));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift 
        = (0x3fU & ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff) 
                    - (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y_eff)));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift 
        = (0x3fU & ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff) 
                    - (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx_eff)));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift 
        = (0x3fU & ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff) 
                    - (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx_eff)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant 
        = (((QData)((IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x)))) 
            << 0x24U) | ((QData)((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x)) 
                         << 0x1aU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base 
        = (((QData)((IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y)))) 
            << 0x24U) | ((QData)((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y)) 
                         << 0x1aU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base 
        = (((QData)((IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx)))) 
            << 0x24U) | ((QData)((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx)) 
                         << 0x1aU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base 
        = (((QData)((IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx)))) 
            << 0x24U) | ((QData)((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx)) 
                         << 0x1aU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted 
        = ((0x25U <= (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift))
            ? 0ULL : (0x1fffffffffULL & (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base 
                                         >> (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_y 
        = (0U != (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base 
                  & (~ (0x1fffffffffULL << (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted 
        = ((0x25U <= (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift))
            ? 0ULL : (0x1fffffffffULL & (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base 
                                         >> (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_m 
        = (0U != (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base 
                  & (~ (0x1fffffffffULL << (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted 
        = ((0x25U <= (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift))
            ? 0ULL : (0x1fffffffffULL & (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base 
                                         >> (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_n 
        = (0U != (add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base 
                  & (~ (0x1fffffffffULL << (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_op 
        = ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_y));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_op 
        = ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_mx));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_op 
        = ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_nx));
}

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___eval_triggers__stl(Vadd4_fp16_tb_softfloat___024root* vlSelf);

VL_ATTR_COLD bool Vadd4_fp16_tb_softfloat___024root___eval_phase__stl(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___eval_phase__stl\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vadd4_fp16_tb_softfloat___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vadd4_fp16_tb_softfloat___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___dump_triggers__act(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___dump_triggers__act\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge add4_fp16_tb_softfloat.tb_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge add4_fp16_tb_softfloat.tb_nrst)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(negedge add4_fp16_tb_softfloat.tb_clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___dump_triggers__nba(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___dump_triggers__nba\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge add4_fp16_tb_softfloat.tb_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge add4_fp16_tb_softfloat.tb_nrst)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(negedge add4_fp16_tb_softfloat.tb_clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___ctor_var_reset(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___ctor_var_reset\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->add4_fp16_tb_softfloat__DOT__tb_clk = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__tb_nrst = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__tb_a = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__tb_b = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__tb_c = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__tb_d = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__a = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__b = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__c = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__d = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__expected = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__ret = 0;
    vlSelf->add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__is_zero_result = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__total_count = 0;
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_y = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_mx = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_nx = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant = VL_RAND_RESET_Q(37);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted = VL_RAND_RESET_Q(37);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted = VL_RAND_RESET_Q(37);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted = VL_RAND_RESET_Q(37);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_y = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_m = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_n = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_e = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f = VL_RAND_RESET_Q(37);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_y_f = VL_RAND_RESET_Q(37);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_m_f = VL_RAND_RESET_Q(37);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_n_f = VL_RAND_RESET_Q(37);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_result = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_b_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_c_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_d_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_align_sticky = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_case = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum = VL_RAND_RESET_Q(39);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros = VL_RAND_RESET_I(6);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__res_sign = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_exp_base = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag = VL_RAND_RESET_Q(39);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_lzd = VL_RAND_RESET_I(6);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_spec_res = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sticky = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__result_out = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 = VL_RAND_RESET_Q(41);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 = VL_RAND_RESET_Q(41);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_logic__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->__Vtrigprevexpr___TOP__add4_fp16_tb_softfloat__DOT__tb_clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__add4_fp16_tb_softfloat__DOT__tb_nrst__0 = VL_RAND_RESET_I(1);
}
