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
VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root____Vm_traceActivitySetAll(Vadd4_fp16_tb_softfloat___024root* vlSelf);

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___eval_stl(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___eval_stl\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vadd4_fp16_tb_softfloat___024root___stl_sequent__TOP__0(vlSelf);
        Vadd4_fp16_tb_softfloat___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___stl_sequent__TOP__0(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___stl_sequent__TOP__0\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 = 0;
    CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 = 0;
    // Body
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val 
        = (0x7ffffffffULL & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag 
                             << (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_lzd)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_mant 
        = (0x3ffU & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val 
                             >> 0x18U)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__guard_bit 
        = (1U & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val 
                         >> 0x17U)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round_bit 
        = (1U & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val 
                         >> 0x16U)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_bit 
        = ((0U != (0x3fffffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val))) 
           | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sticky));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round_up 
        = ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__guard_bit) 
           & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round_bit) 
               | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_bit)) 
              | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_mant)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mant_int 
        = (0x7ffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_mant) 
                     + (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round_up)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_mant 
        = ((0x400U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mant_int))
            ? 0U : (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mant_int)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc 
        = (0xffU & ((((IData)(2U) + VL_EXTENDS_II(8,7, (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(8,8, (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_lzd))) 
                    + VL_EXTENDS_II(8,11, (1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mant_int) 
                                                 >> 0xaU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__result_out 
        = ((0ULL == vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag)
            ? ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign) 
               << 0xfU) : (VL_LTES_III(32, 0x1fU, VL_EXTENDS_II(32,8, (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc)))
                            ? (0x7c00U | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign) 
                                          << 0xfU))
                            : (VL_GTES_III(32, 0U, 
                                           VL_EXTENDS_II(32,8, (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc)))
                                ? ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign) 
                                   << 0xfU) : (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign) 
                                                << 0xfU) 
                                               | ((0x7c00U 
                                                   & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc) 
                                                      << 0xaU)) 
                                                  | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_mant))))));
    if (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__result_out 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_spec_res;
    }
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
        = (0x1fffffffffULL & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_b_op)
                               ? (- vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_y_f)
                               : vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_y_f));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
        = (0x1fffffffffULL & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_c_op)
                               ? (- vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_m_f)
                               : vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_m_f));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_d 
        = (0x1fffffffffULL & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_d_op)
                               ? (- vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_n_f)
                               : vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_n_f));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a) 
                  ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b)) 
                 ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffffffffeULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | (IData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a) 
                   & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b)) 
                  | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b) 
                     & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c))) 
                 | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c) 
                    & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffffffffeULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | (IData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 1U)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                              >> 1U))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 1U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffffffffdULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 1U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 1U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                               >> 1U))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 1U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                 >> 1U)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 1U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                >> 1U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffffffffdULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 1U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 2U)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                              >> 2U))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 2U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffffffffbULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 2U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 2U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                               >> 2U))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 2U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                 >> 2U)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 2U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                >> 2U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffffffffbULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 2U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 3U)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                              >> 3U))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 3U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffffffff7ULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 3U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 3U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                               >> 3U))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 3U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                 >> 3U)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 3U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                >> 3U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffffffff7ULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 3U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 4U)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                              >> 4U))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 4U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fffffffefULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 4U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 4U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                               >> 4U))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 4U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                 >> 4U)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 4U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                >> 4U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fffffffefULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 4U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 5U)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                              >> 5U))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 5U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fffffffdfULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 5U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 5U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                               >> 5U))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 5U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                 >> 5U)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 5U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                >> 5U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fffffffdfULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 5U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 6U)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                              >> 6U))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 6U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fffffffbfULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 6U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 6U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                               >> 6U))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 6U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                 >> 6U)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 6U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                >> 6U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fffffffbfULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 6U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 7U)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                              >> 7U))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 7U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fffffff7fULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 7U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 7U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                               >> 7U))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 7U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                 >> 7U)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 7U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                >> 7U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fffffff7fULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 7U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 8U)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                              >> 8U))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 8U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffffffeffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 8U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 8U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                               >> 8U))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 8U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                 >> 8U)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 8U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                >> 8U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffffffeffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 8U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 9U)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                              >> 9U))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 9U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffffffdffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 9U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 9U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                               >> 9U))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 9U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                 >> 9U)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 9U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                >> 9U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffffffdffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 9U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0xaU)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                >> 0xaU))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0xaU))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffffffbffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0xaU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0xaU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0xaU))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0xaU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                   >> 0xaU)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0xaU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                  >> 0xaU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffffffbffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0xaU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0xbU)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                >> 0xbU))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0xbU))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffffff7ffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0xbU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0xbU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0xbU))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0xbU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                   >> 0xbU)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0xbU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                  >> 0xbU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffffff7ffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0xbU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0xcU)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                >> 0xcU))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0xcU))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fffffefffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0xcU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0xcU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0xcU))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0xcU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                   >> 0xcU)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0xcU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                  >> 0xcU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fffffefffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0xcU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0xdU)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                >> 0xdU))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0xdU))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fffffdfffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0xdU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0xdU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0xdU))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0xdU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                   >> 0xdU)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0xdU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                  >> 0xdU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fffffdfffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0xdU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0xeU)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                >> 0xeU))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0xeU))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fffffbfffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0xeU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0xeU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0xeU))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0xeU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                   >> 0xeU)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0xeU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                  >> 0xeU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fffffbfffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0xeU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0xfU)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                >> 0xfU))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0xfU))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fffff7fffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0xfU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0xfU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0xfU))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0xfU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                   >> 0xfU)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0xfU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                  >> 0xfU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fffff7fffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0xfU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x10U)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x10U))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x10U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffffeffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0x10U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x10U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x10U))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x10U)) & (IData)(
                                                   (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x10U)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x10U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x10U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffffeffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0x10U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x11U)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x11U))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x11U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffffdffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0x11U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x11U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x11U))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x11U)) & (IData)(
                                                   (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x11U)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x11U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x11U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffffdffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0x11U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x12U)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x12U))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x12U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffffbffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0x12U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x12U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x12U))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x12U)) & (IData)(
                                                   (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x12U)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x12U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x12U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffffbffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0x12U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x13U)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x13U))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x13U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffff7ffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0x13U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x13U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x13U))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x13U)) & (IData)(
                                                   (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x13U)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x13U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x13U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffff7ffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0x13U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x14U)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x14U))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x14U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fffefffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0x14U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x14U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x14U))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x14U)) & (IData)(
                                                   (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x14U)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x14U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x14U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fffefffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0x14U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x15U)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x15U))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x15U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fffdfffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0x15U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x15U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x15U))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x15U)) & (IData)(
                                                   (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x15U)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x15U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x15U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fffdfffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0x15U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x16U)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x16U))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x16U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fffbfffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0x16U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x16U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x16U))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x16U)) & (IData)(
                                                   (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x16U)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x16U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x16U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fffbfffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0x16U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x17U)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x17U))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x17U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fff7fffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0x17U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x17U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x17U))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x17U)) & (IData)(
                                                   (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x17U)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x17U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x17U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fff7fffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0x17U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x18U)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x18U))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x18U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffeffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0x18U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x18U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x18U))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x18U)) & (IData)(
                                                   (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x18U)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x18U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x18U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffeffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0x18U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x19U)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x19U))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x19U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffdffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0x19U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x19U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x19U))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x19U)) & (IData)(
                                                   (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x19U)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x19U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x19U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffdffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0x19U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x1aU)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x1aU))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x1aU))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ffbffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0x1aU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x1aU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x1aU))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x1aU)) & (IData)(
                                                   (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x1aU)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x1aU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x1aU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ffbffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0x1aU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x1bU)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x1bU))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x1bU))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1ff7ffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0x1bU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x1bU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x1bU))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x1bU)) & (IData)(
                                                   (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x1bU)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x1bU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x1bU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1ff7ffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0x1bU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x1cU)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x1cU))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x1cU))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fefffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0x1cU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x1cU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x1cU))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x1cU)) & (IData)(
                                                   (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x1cU)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x1cU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x1cU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fefffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0x1cU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x1dU)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x1dU))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x1dU))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fdfffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0x1dU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x1dU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x1dU))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x1dU)) & (IData)(
                                                   (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x1dU)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x1dU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x1dU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fdfffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0x1dU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x1eU)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x1eU))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x1eU))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1fbfffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0x1eU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x1eU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x1eU))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x1eU)) & (IData)(
                                                   (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x1eU)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x1eU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x1eU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1fbfffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0x1eU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x1fU)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x1fU))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x1fU))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1f7fffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0x1fU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x1fU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x1fU))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x1fU)) & (IData)(
                                                   (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x1fU)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x1fU)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x1fU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1f7fffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0x1fU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x20U)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x20U))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x20U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1effffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0x20U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x20U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x20U))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x20U)) & (IData)(
                                                   (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x20U)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x20U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x20U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1effffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0x20U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x21U)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x21U))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x21U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1dffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0x21U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x21U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x21U))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x21U)) & (IData)(
                                                   (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x21U)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x21U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x21U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1dffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0x21U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x22U)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x22U))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x22U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x1bffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0x22U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x22U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x22U))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x22U)) & (IData)(
                                                   (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x22U)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x22U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x22U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x1bffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0x22U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x23U)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x23U))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x23U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0x17ffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0x23U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x23U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x23U))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x23U)) & (IData)(
                                                   (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x23U)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x23U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x23U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0x17ffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0x23U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0 
        = (1U & (((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                           >> 0x24U)) ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                 >> 0x24U))) 
                 ^ (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                            >> 0x24U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
        = ((0xfffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6337a46d__0)) 
              << 0x24U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0 
        = (1U & ((((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                            >> 0x24U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                                                  >> 0x24U))) 
                  | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b 
                              >> 0x24U)) & (IData)(
                                                   (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                                                    >> 0x24U)))) 
                 | ((IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c 
                             >> 0x24U)) & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a 
                                                   >> 0x24U)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 
        = ((0xfffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1) 
           | ((QData)((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h6c118431__0)) 
              << 0x24U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_logic__DOT__unnamedblk1__DOT__i = 0x25U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1_shifted 
        = (0x1fffffffffULL & VL_SHIFTL_QQI(37,37,32, vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1, 1U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum 
        = (0xfffffffffULL & ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 
                              + vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1_shifted) 
                             + vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_d));
    if ((1U & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum 
                       >> 0x23U)))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum 
            = (0x7ffffffffULL & (1ULL + (~ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum)));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s)));
    } else {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum 
            = (0x7ffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum);
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__res_sign 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s;
    }
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros = 0x22U;
    if ((0ULL == vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum)) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros = 0x22U;
    } else {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_logic__DOT__unnamedblk2__DOT__i = 0x22U;
        {
            while (VL_LTES_III(32, 0U, vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_logic__DOT__unnamedblk2__DOT__i)) {
                if (((0x22U >= (0x3fU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_logic__DOT__unnamedblk2__DOT__i)) 
                     && (1U & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum 
                                       >> (0x3fU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_logic__DOT__unnamedblk2__DOT__i)))))) {
                    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros 
                        = (0x3fU & ((IData)(0x22U) 
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
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz 
        = ((0U == (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a) 
                            >> 0xaU))) ? (0x8000U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a))
            : (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz 
        = ((0U == (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b) 
                            >> 0xaU))) ? (0x8000U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b))
            : (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz 
        = ((0U == (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c) 
                            >> 0xaU))) ? (0x8000U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c))
            : (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz 
        = ((0U == (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d) 
                            >> 0xaU))) ? (0x8000U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d))
            : (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz) 
                    >> 0xaU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a 
        = (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz) 
                    >> 0xaU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b 
        = (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz) 
                    >> 0xaU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c 
        = (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz) 
                    >> 0xaU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d 
        = (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_any 
        = (((((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a))) 
             | ((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b)))) 
            | ((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c)))) 
           | ((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__any_pos_inf 
        = ((((((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a))))) 
             | (((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b)))))) 
            | (((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c)))))) 
           | (((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d))))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__any_neg_inf 
        = ((((((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a)) 
               & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a))))) 
             | (((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b)))))) 
            | (((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c)) 
                & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c)))))) 
           | (((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d)) 
               & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d))))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = 0U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__any_neg_inf)))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = 1U;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = 0xfe00U;
    } else if (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__any_pos_inf) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = 1U;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = 0x7c00U;
    } else if (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__any_neg_inf) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = 1U;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = 0xfc00U;
    }
    if (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a) 
         >= (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b;
    } else {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c) 
         >= (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d;
    } else {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c;
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
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x))
            ? 1U : (0x1fU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y))
            ? 1U : (0x1fU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx))
            ? 1U : (0x1fU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx))
            ? 1U : (0x1fU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift 
        = (0x3fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff) 
                    - (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y_eff)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift 
        = (0x3fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff) 
                    - (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx_eff)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift 
        = (0x3fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff) 
                    - (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx_eff)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant 
        = (((QData)((IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x)))) 
            << 0x20U) | (QData)((IData)(((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x) 
                                         << 0x16U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base 
        = (((QData)((IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y)))) 
            << 0x20U) | (QData)((IData)(((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y) 
                                         << 0x16U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base 
        = (((QData)((IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx)))) 
            << 0x20U) | (QData)((IData)(((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx) 
                                         << 0x16U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base 
        = (((QData)((IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx)))) 
            << 0x20U) | (QData)((IData)(((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx) 
                                         << 0x16U))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted 
        = ((0x21U <= (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift))
            ? 0ULL : (0x1ffffffffULL & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base 
                                        >> (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_y 
        = (0U != (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base 
                  & (~ (0x1ffffffffULL << (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted 
        = ((0x21U <= (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift))
            ? 0ULL : (0x1ffffffffULL & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base 
                                        >> (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_m 
        = (0U != (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base 
                  & (~ (0x1ffffffffULL << (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted 
        = ((0x21U <= (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift))
            ? 0ULL : (0x1ffffffffULL & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base 
                                        >> (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_n 
        = (0U != (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base 
                  & (~ (0x1ffffffffULL << (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift)))));
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

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root____Vm_traceActivitySetAll(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root____Vm_traceActivitySetAll\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
}

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
    vlSelf->add4_fp16_tb_softfloat__DOT__exp = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__pass_count = 0;
    vlSelf->add4_fp16_tb_softfloat__DOT__fail_count = 0;
    vlSelf->add4_fp16_tb_softfloat__DOT__fd = 0;
    vlSelf->add4_fp16_tb_softfloat__DOT__fail_fd = 0;
    vlSelf->add4_fp16_tb_softfloat__DOT__a = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__b = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__c = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__d = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__expected = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__ret = 0;
    vlSelf->add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__is_zero_result = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__total_count = 0;
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d = VL_RAND_RESET_I(1);
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
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y_eff = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx_eff = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx_eff = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift = VL_RAND_RESET_I(6);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift = VL_RAND_RESET_I(6);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift = VL_RAND_RESET_I(6);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant = VL_RAND_RESET_Q(33);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted = VL_RAND_RESET_Q(33);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted = VL_RAND_RESET_Q(33);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted = VL_RAND_RESET_Q(33);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base = VL_RAND_RESET_Q(33);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base = VL_RAND_RESET_Q(33);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base = VL_RAND_RESET_Q(33);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_y = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_m = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_n = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_any = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_e = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f = VL_RAND_RESET_Q(33);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_y_f = VL_RAND_RESET_Q(33);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_m_f = VL_RAND_RESET_Q(33);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_n_f = VL_RAND_RESET_Q(33);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_result = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_b_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_c_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_d_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_align_sticky = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_case = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a = VL_RAND_RESET_Q(37);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b = VL_RAND_RESET_Q(37);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c = VL_RAND_RESET_Q(37);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_d = VL_RAND_RESET_Q(37);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum = VL_RAND_RESET_Q(35);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum = VL_RAND_RESET_Q(36);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros = VL_RAND_RESET_I(6);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__res_sign = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_exp_base = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag = VL_RAND_RESET_Q(35);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_lzd = VL_RAND_RESET_I(6);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_spec_res = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sticky = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val = VL_RAND_RESET_Q(35);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_mant = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_mant = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mant_int = VL_RAND_RESET_I(11);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc = VL_RAND_RESET_I(8);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__guard_bit = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round_bit = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_bit = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round_up = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__result_out = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__any_pos_inf = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__any_neg_inf = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1 = VL_RAND_RESET_Q(37);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1 = VL_RAND_RESET_Q(37);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1_shifted = VL_RAND_RESET_Q(37);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_logic__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_logic__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->__Vtrigprevexpr___TOP__add4_fp16_tb_softfloat__DOT__tb_clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__add4_fp16_tb_softfloat__DOT__tb_nrst__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
