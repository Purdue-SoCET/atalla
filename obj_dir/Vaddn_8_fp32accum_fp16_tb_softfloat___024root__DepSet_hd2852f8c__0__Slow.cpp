// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaddn_8_fp32accum_fp16_tb_softfloat.h for the primary calling header

#include "Vaddn_8_fp32accum_fp16_tb_softfloat__pch.h"
#include "Vaddn_8_fp32accum_fp16_tb_softfloat___024root.h"

VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_static(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_static\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_clk__0 
        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst__0 
        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst;
}

VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_final(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_final\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___dump_triggers__stl(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_phase__stl(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf);

VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_settle(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_settle\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vaddn_8_fp32accum_fp16_tb_softfloat___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv", 12, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___dump_triggers__stl(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___dump_triggers__stl\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___stl_sequent__TOP__0(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf);
VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root____Vm_traceActivitySetAll(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf);

VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_stl(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_stl\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vaddn_8_fp32accum_fp16_tb_softfloat___024root___stl_sequent__TOP__0(vlSelf);
        Vaddn_8_fp32accum_fp16_tb_softfloat___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___stl_sequent__TOP__0(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___stl_sequent__TOP__0\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_e_final 
        = (0x7ffU & ((IData)(0x70U) + (((IData)(4U) 
                                        + VL_EXTENDS_II(11,7, (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_exp))) 
                                       - VL_EXTENDS_II(11,8, (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_lzd)))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_scan 
        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_mag_sum;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_lzd = 0U;
    if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_scan, 0xdU))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_lzd 
            = (0x3fU & ((IData)(0x10U) + (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_lzd)));
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_scan 
            = (0x1fffffffU & VL_SHIFTL_III(29,29,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_scan, 0x10U));
    }
    if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_scan, 0x15U))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_lzd 
            = (0x3fU & ((IData)(8U) + (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_lzd)));
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_scan 
            = (0x1fffffffU & VL_SHIFTL_III(29,29,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_scan, 8U));
    }
    if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_scan, 0x19U))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_lzd 
            = (0x3fU & ((IData)(4U) + (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_lzd)));
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_scan 
            = (0x1fffffffU & VL_SHIFTL_III(29,29,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_scan, 4U));
    }
    if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_scan, 0x1bU))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_lzd 
            = (0x3fU & ((IData)(2U) + (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_lzd)));
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_scan 
            = (0x1fffffffU & VL_SHIFTL_III(29,29,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_scan, 2U));
    }
    if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_scan, 0x1cU))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_lzd 
            = (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_lzd)));
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_scan 
            = (0x1fffffffU & VL_SHIFTL_III(29,29,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_scan, 1U));
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_raw_sum 
        = (0x7fffffffU & ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sum_vec 
                           + VL_EXTENDS_II(31,30, (0x3fffffffU 
                                                   & VL_SHIFTL_III(30,30,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_carry_vec, 1U)))) 
                          + VL_EXTENDS_II(31,30, (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_hot_ones))));
    if ((0x20000000U & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_raw_sum)) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_mag_sum 
            = (0x1fffffffU & ((IData)(1U) + (~ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_raw_sum)));
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_res_sign 
            = (1U & (~ (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sign_max)));
    } else {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_mag_sum 
            = (0x1fffffffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_raw_sum);
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_res_sign 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sign_max;
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__guard 
        = (1U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
                 >> 0xcU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rnd 
        = (1U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
                 >> 0xbU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__sticky 
        = (0U != (0x7ffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__round_up 
        = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__guard) 
           & (((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rnd) 
               | (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__sticky)) 
              | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
                 >> 0xdU)));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded 
        = (0x7ffU & ((0x3ffU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
                                >> 0xdU)) + (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__round_up)));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp 
        = (0x3ffU & ((VL_EXTENDS_II(10,10, (0xffU & 
                                            (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
                                             >> 0x17U))) 
                      - (IData)(0x70U)) + VL_EXTENDS_II(10,10, 
                                                        (1U 
                                                         & ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded) 
                                                            >> 0xaU)))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result 
        = ((0xffU == (0xffU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
                               >> 0x17U))) ? (0x7c00U 
                                              | ((0x8000U 
                                                  & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
                                                     >> 0x10U)) 
                                                 | ((0U 
                                                     != 
                                                     (0x7fffffU 
                                                      & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out))
                                                     ? 0x200U
                                                     : 0U)))
            : (VL_LTES_III(10, 0x1fU, (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp))
                ? (0x7c00U | (0x8000U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
                                         >> 0x10U)))
                : (VL_GTES_III(32, 0U, VL_EXTENDS_II(32,10, (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp)))
                    ? (0x8000U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
                                  >> 0x10U)) : ((0x8000U 
                                                 & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
                                                    >> 0x10U)) 
                                                | ((0x7c00U 
                                                    & ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp) 
                                                       << 0xaU)) 
                                                   | ((0x400U 
                                                       & (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded))
                                                       ? 0U
                                                       : 
                                                      (0x3ffU 
                                                       & (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded))))))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_is_nan_any = 0U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_pos_inf = 0U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_neg_inf = 0U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data[0U] 
        = (0xffffU & ((0U == (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U] 
                                       >> 0xaU))) ? 
                      (0x8000U & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U])
                       : vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr[0U] 
        = (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                    [0U] >> 0xaU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__idx_arr[0U] = 0U;
    if (((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
          [0U]) & (0U != (0x3ffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                          [0U])))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_is_nan_any = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
           [0U]) & (~ (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                       [0U] >> 0xfU))) & (~ (IData)(
                                                    (0U 
                                                     != 
                                                     (0x3ffU 
                                                      & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                                                      [0U])))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_pos_inf = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
           [0U]) & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                    [0U] >> 0xfU)) & (~ (IData)((0U 
                                                 != 
                                                 (0x3ffU 
                                                  & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                                                  [0U])))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data[1U] 
        = (0xffffU & ((0U == (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U] 
                                       >> 0x1aU))) ? 
                      (0x8000U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U] 
                                  >> 0x10U)) : ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U] 
                                                   >> 0x10U))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr[1U] 
        = (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                    [1U] >> 0xaU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__idx_arr[1U] = 1U;
    if (((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
          [1U]) & (0U != (0x3ffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                          [1U])))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_is_nan_any = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
           [1U]) & (~ (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                       [1U] >> 0xfU))) & (~ (IData)(
                                                    (0U 
                                                     != 
                                                     (0x3ffU 
                                                      & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                                                      [1U])))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_pos_inf = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
           [1U]) & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                    [1U] >> 0xfU)) & (~ (IData)((0U 
                                                 != 
                                                 (0x3ffU 
                                                  & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                                                  [1U])))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data[2U] 
        = (0xffffU & ((0U == (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U] 
                                       >> 0xaU))) ? 
                      (0x8000U & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U])
                       : vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr[2U] 
        = (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                    [2U] >> 0xaU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__idx_arr[2U] = 2U;
    if (((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
          [2U]) & (0U != (0x3ffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                          [2U])))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_is_nan_any = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
           [2U]) & (~ (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                       [2U] >> 0xfU))) & (~ (IData)(
                                                    (0U 
                                                     != 
                                                     (0x3ffU 
                                                      & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                                                      [2U])))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_pos_inf = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
           [2U]) & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                    [2U] >> 0xfU)) & (~ (IData)((0U 
                                                 != 
                                                 (0x3ffU 
                                                  & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                                                  [2U])))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data[3U] 
        = (0xffffU & ((0U == (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U] 
                                       >> 0x1aU))) ? 
                      (0x8000U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U] 
                                  >> 0x10U)) : ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U] 
                                                   >> 0x10U))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr[3U] 
        = (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                    [3U] >> 0xaU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__idx_arr[3U] = 3U;
    if (((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
          [3U]) & (0U != (0x3ffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                          [3U])))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_is_nan_any = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
           [3U]) & (~ (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                       [3U] >> 0xfU))) & (~ (IData)(
                                                    (0U 
                                                     != 
                                                     (0x3ffU 
                                                      & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                                                      [3U])))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_pos_inf = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
           [3U]) & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                    [3U] >> 0xfU)) & (~ (IData)((0U 
                                                 != 
                                                 (0x3ffU 
                                                  & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                                                  [3U])))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data[4U] 
        = (0xffffU & ((0U == (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U] 
                                       >> 0xaU))) ? 
                      (0x8000U & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U])
                       : vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr[4U] 
        = (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                    [4U] >> 0xaU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__idx_arr[4U] = 4U;
    if (((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
          [4U]) & (0U != (0x3ffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                          [4U])))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_is_nan_any = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
           [4U]) & (~ (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                       [4U] >> 0xfU))) & (~ (IData)(
                                                    (0U 
                                                     != 
                                                     (0x3ffU 
                                                      & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                                                      [4U])))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_pos_inf = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
           [4U]) & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                    [4U] >> 0xfU)) & (~ (IData)((0U 
                                                 != 
                                                 (0x3ffU 
                                                  & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                                                  [4U])))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data[5U] 
        = (0xffffU & ((0U == (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U] 
                                       >> 0x1aU))) ? 
                      (0x8000U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U] 
                                  >> 0x10U)) : ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U] 
                                                   >> 0x10U))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr[5U] 
        = (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                    [5U] >> 0xaU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__idx_arr[5U] = 5U;
    if (((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
          [5U]) & (0U != (0x3ffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                          [5U])))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_is_nan_any = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
           [5U]) & (~ (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                       [5U] >> 0xfU))) & (~ (IData)(
                                                    (0U 
                                                     != 
                                                     (0x3ffU 
                                                      & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                                                      [5U])))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_pos_inf = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
           [5U]) & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                    [5U] >> 0xfU)) & (~ (IData)((0U 
                                                 != 
                                                 (0x3ffU 
                                                  & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                                                  [5U])))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data[6U] 
        = (0xffffU & ((0U == (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U] 
                                       >> 0xaU))) ? 
                      (0x8000U & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U])
                       : vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr[6U] 
        = (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                    [6U] >> 0xaU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__idx_arr[6U] = 6U;
    if (((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
          [6U]) & (0U != (0x3ffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                          [6U])))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_is_nan_any = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
           [6U]) & (~ (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                       [6U] >> 0xfU))) & (~ (IData)(
                                                    (0U 
                                                     != 
                                                     (0x3ffU 
                                                      & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                                                      [6U])))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_pos_inf = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
           [6U]) & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                    [6U] >> 0xfU)) & (~ (IData)((0U 
                                                 != 
                                                 (0x3ffU 
                                                  & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                                                  [6U])))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data[7U] 
        = (0xffffU & ((0U == (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U] 
                                       >> 0x1aU))) ? 
                      (0x8000U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U] 
                                  >> 0x10U)) : ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U] 
                                                   >> 0x10U))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr[7U] 
        = (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                    [7U] >> 0xaU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__idx_arr[7U] = 7U;
    if (((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
          [7U]) & (0U != (0x3ffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                          [7U])))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_is_nan_any = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
           [7U]) & (~ (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                       [7U] >> 0xfU))) & (~ (IData)(
                                                    (0U 
                                                     != 
                                                     (0x3ffU 
                                                      & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                                                      [7U])))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_pos_inf = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
           [7U]) & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                    [7U] >> 0xfU)) & (~ (IData)((0U 
                                                 != 
                                                 (0x3ffU 
                                                  & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
                                                  [7U])))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_spec_case = 0U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_spec_res = 0U;
    if (((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_is_nan_any) 
         | ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_pos_inf) 
            & (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_neg_inf)))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_spec_case = 1U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_spec_res = 0x7fc00000U;
    } else if (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_pos_inf) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_spec_case = 1U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_spec_res = 0x7f800000U;
    } else if (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_neg_inf) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_spec_case = 1U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_spec_res = 0xff800000U;
    }
    if ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
         [0U] >= vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
         [1U])) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e1[0U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
            [0U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i1[0U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__idx_arr
            [0U];
    } else {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e1[0U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
            [1U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i1[0U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__idx_arr
            [1U];
    }
    if ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
         [2U] >= vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
         [3U])) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e1[1U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
            [2U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i1[1U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__idx_arr
            [2U];
    } else {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e1[1U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
            [3U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i1[1U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__idx_arr
            [3U];
    }
    if ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
         [4U] >= vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
         [5U])) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e1[2U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
            [4U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i1[2U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__idx_arr
            [4U];
    } else {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e1[2U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
            [5U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i1[2U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__idx_arr
            [5U];
    }
    if ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
         [6U] >= vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
         [7U])) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e1[3U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
            [6U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i1[3U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__idx_arr
            [6U];
    } else {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e1[3U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr
            [7U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i1[3U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__idx_arr
            [7U];
    }
    if ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e1
         [0U] >= vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e1
         [1U])) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e2[0U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e1
            [0U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i2[0U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i1
            [0U];
    } else {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e2[0U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e1
            [1U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i2[0U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i1
            [1U];
    }
    if ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e1
         [2U] >= vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e1
         [3U])) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e2[1U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e1
            [2U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i2[1U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i1
            [2U];
    } else {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e2[1U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e1
            [3U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i2[1U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i1
            [3U];
    }
    if ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e2
         [0U] >= vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e2
         [1U])) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_max_exp 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e2
            [0U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_max_idx 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i2
            [0U];
    } else {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_max_exp 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e2
            [1U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_max_idx 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i2
            [1U];
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_sticky = 0U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base[0U] 
        = (((0U != (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                             [0U] >> 0xaU))) << 0x18U) 
           | (0xffc000U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                           [0U] << 0xeU)));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh[0U] 
        = (0x3fU & ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_exp) 
                    - (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                                [0U] >> 0xaU))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff[0U] 
        = (1U & ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                  [0U] ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                  [vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_idx]) 
                 >> 0xfU));
    if ((0U == (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_idx))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[0U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
            [0U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff[0U] = 0U;
    } else {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_sticky 
            = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_sticky) 
               | (0U != (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
                         [0U] & (~ VL_SHIFTL_III(25,25,6, (IData)(0x1ffffffU), 
                                                 vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh
                                                 [0U])))));
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[0U] 
            = (0x3fffffffU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff
                              [0U] ? (~ (0x1ffffffU 
                                         & VL_SHIFTR_III(25,25,6, 
                                                         vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
                                                         [0U], 
                                                         vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh
                                                         [0U])))
                               : (0x1ffffffU & VL_SHIFTR_III(25,25,6, 
                                                             vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
                                                             [0U], 
                                                             vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh
                                                             [0U]))));
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base[1U] 
        = (((0U != (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                             [1U] >> 0xaU))) << 0x18U) 
           | (0xffc000U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                           [1U] << 0xeU)));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh[1U] 
        = (0x3fU & ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_exp) 
                    - (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                                [1U] >> 0xaU))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff[1U] 
        = (1U & ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                  [1U] ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                  [vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_idx]) 
                 >> 0xfU));
    if ((1U == (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_idx))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[1U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
            [1U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff[1U] = 0U;
    } else {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_sticky 
            = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_sticky) 
               | (0U != (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
                         [1U] & (~ VL_SHIFTL_III(25,25,6, (IData)(0x1ffffffU), 
                                                 vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh
                                                 [1U])))));
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[1U] 
            = (0x3fffffffU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff
                              [1U] ? (~ (0x1ffffffU 
                                         & VL_SHIFTR_III(25,25,6, 
                                                         vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
                                                         [1U], 
                                                         vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh
                                                         [1U])))
                               : (0x1ffffffU & VL_SHIFTR_III(25,25,6, 
                                                             vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
                                                             [1U], 
                                                             vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh
                                                             [1U]))));
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base[2U] 
        = (((0U != (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                             [2U] >> 0xaU))) << 0x18U) 
           | (0xffc000U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                           [2U] << 0xeU)));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh[2U] 
        = (0x3fU & ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_exp) 
                    - (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                                [2U] >> 0xaU))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff[2U] 
        = (1U & ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                  [2U] ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                  [vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_idx]) 
                 >> 0xfU));
    if ((2U == (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_idx))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[2U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
            [2U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff[2U] = 0U;
    } else {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_sticky 
            = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_sticky) 
               | (0U != (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
                         [2U] & (~ VL_SHIFTL_III(25,25,6, (IData)(0x1ffffffU), 
                                                 vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh
                                                 [2U])))));
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[2U] 
            = (0x3fffffffU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff
                              [2U] ? (~ (0x1ffffffU 
                                         & VL_SHIFTR_III(25,25,6, 
                                                         vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
                                                         [2U], 
                                                         vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh
                                                         [2U])))
                               : (0x1ffffffU & VL_SHIFTR_III(25,25,6, 
                                                             vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
                                                             [2U], 
                                                             vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh
                                                             [2U]))));
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base[3U] 
        = (((0U != (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                             [3U] >> 0xaU))) << 0x18U) 
           | (0xffc000U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                           [3U] << 0xeU)));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh[3U] 
        = (0x3fU & ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_exp) 
                    - (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                                [3U] >> 0xaU))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff[3U] 
        = (1U & ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                  [3U] ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                  [vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_idx]) 
                 >> 0xfU));
    if ((3U == (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_idx))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[3U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
            [3U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff[3U] = 0U;
    } else {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_sticky 
            = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_sticky) 
               | (0U != (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
                         [3U] & (~ VL_SHIFTL_III(25,25,6, (IData)(0x1ffffffU), 
                                                 vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh
                                                 [3U])))));
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[3U] 
            = (0x3fffffffU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff
                              [3U] ? (~ (0x1ffffffU 
                                         & VL_SHIFTR_III(25,25,6, 
                                                         vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
                                                         [3U], 
                                                         vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh
                                                         [3U])))
                               : (0x1ffffffU & VL_SHIFTR_III(25,25,6, 
                                                             vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
                                                             [3U], 
                                                             vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh
                                                             [3U]))));
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base[4U] 
        = (((0U != (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                             [4U] >> 0xaU))) << 0x18U) 
           | (0xffc000U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                           [4U] << 0xeU)));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh[4U] 
        = (0x3fU & ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_exp) 
                    - (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                                [4U] >> 0xaU))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff[4U] 
        = (1U & ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                  [4U] ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                  [vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_idx]) 
                 >> 0xfU));
    if ((4U == (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_idx))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[4U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
            [4U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff[4U] = 0U;
    } else {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_sticky 
            = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_sticky) 
               | (0U != (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
                         [4U] & (~ VL_SHIFTL_III(25,25,6, (IData)(0x1ffffffU), 
                                                 vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh
                                                 [4U])))));
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[4U] 
            = (0x3fffffffU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff
                              [4U] ? (~ (0x1ffffffU 
                                         & VL_SHIFTR_III(25,25,6, 
                                                         vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
                                                         [4U], 
                                                         vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh
                                                         [4U])))
                               : (0x1ffffffU & VL_SHIFTR_III(25,25,6, 
                                                             vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
                                                             [4U], 
                                                             vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh
                                                             [4U]))));
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base[5U] 
        = (((0U != (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                             [5U] >> 0xaU))) << 0x18U) 
           | (0xffc000U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                           [5U] << 0xeU)));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh[5U] 
        = (0x3fU & ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_exp) 
                    - (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                                [5U] >> 0xaU))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff[5U] 
        = (1U & ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                  [5U] ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                  [vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_idx]) 
                 >> 0xfU));
    if ((5U == (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_idx))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[5U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
            [5U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff[5U] = 0U;
    } else {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_sticky 
            = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_sticky) 
               | (0U != (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
                         [5U] & (~ VL_SHIFTL_III(25,25,6, (IData)(0x1ffffffU), 
                                                 vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh
                                                 [5U])))));
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[5U] 
            = (0x3fffffffU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff
                              [5U] ? (~ (0x1ffffffU 
                                         & VL_SHIFTR_III(25,25,6, 
                                                         vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
                                                         [5U], 
                                                         vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh
                                                         [5U])))
                               : (0x1ffffffU & VL_SHIFTR_III(25,25,6, 
                                                             vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
                                                             [5U], 
                                                             vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh
                                                             [5U]))));
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base[6U] 
        = (((0U != (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                             [6U] >> 0xaU))) << 0x18U) 
           | (0xffc000U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                           [6U] << 0xeU)));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh[6U] 
        = (0x3fU & ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_exp) 
                    - (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                                [6U] >> 0xaU))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff[6U] 
        = (1U & ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                  [6U] ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                  [vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_idx]) 
                 >> 0xfU));
    if ((6U == (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_idx))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[6U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
            [6U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff[6U] = 0U;
    } else {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_sticky 
            = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_sticky) 
               | (0U != (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
                         [6U] & (~ VL_SHIFTL_III(25,25,6, (IData)(0x1ffffffU), 
                                                 vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh
                                                 [6U])))));
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[6U] 
            = (0x3fffffffU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff
                              [6U] ? (~ (0x1ffffffU 
                                         & VL_SHIFTR_III(25,25,6, 
                                                         vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
                                                         [6U], 
                                                         vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh
                                                         [6U])))
                               : (0x1ffffffU & VL_SHIFTR_III(25,25,6, 
                                                             vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
                                                             [6U], 
                                                             vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh
                                                             [6U]))));
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base[7U] 
        = (((0U != (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                             [7U] >> 0xaU))) << 0x18U) 
           | (0xffc000U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                           [7U] << 0xeU)));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh[7U] 
        = (0x3fU & ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_exp) 
                    - (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                                [7U] >> 0xaU))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff[7U] 
        = (1U & ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                  [7U] ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                  [vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_idx]) 
                 >> 0xfU));
    if ((7U == (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_idx))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[7U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
            [7U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff[7U] = 0U;
    } else {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_sticky 
            = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_sticky) 
               | (0U != (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
                         [7U] & (~ VL_SHIFTL_III(25,25,6, (IData)(0x1ffffffU), 
                                                 vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh
                                                 [7U])))));
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[7U] 
            = (0x3fffffffU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff
                              [7U] ? (~ (0x1ffffffU 
                                         & VL_SHIFTR_III(25,25,6, 
                                                         vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
                                                         [7U], 
                                                         vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh
                                                         [7U])))
                               : (0x1ffffffU & VL_SHIFTR_III(25,25,6, 
                                                             vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base
                                                             [7U], 
                                                             vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh
                                                             [7U]))));
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_hot_ones 
        = (0xfU & (((((((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff
                         [0U] + vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff
                         [1U]) + vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff
                        [2U]) + vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff
                       [3U]) + vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff
                      [4U]) + vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff
                     [5U]) + vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff
                    [6U]) + vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff
                   [7U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s1_0 
        = ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
            [0U] ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
            [1U]) ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
           [2U]);
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c1_0 
        = (((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
             [0U] & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
             [1U]) | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                      [1U] & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                      [2U])) | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                                [0U] & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                                [2U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s1_1 
        = ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
            [3U] ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
            [4U]) ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
           [5U]);
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c1_1 
        = (((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
             [3U] & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
             [4U]) | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                      [4U] & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                      [5U])) | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                                [3U] & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                                [5U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s2_0 
        = (0x3fffffffU & ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s1_0 
                           ^ VL_SHIFTL_III(30,30,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c1_0, 1U)) 
                          ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s1_1));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c2_0 
        = (((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s1_0 
             & VL_SHIFTL_III(30,30,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c1_0, 1U)) 
            | (VL_SHIFTL_III(30,30,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c1_0, 1U) 
               & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s1_1)) 
           | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s1_0 
              & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s1_1));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s2_1 
        = (0x3fffffffU & ((VL_SHIFTL_III(30,30,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c1_1, 1U) 
                           ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                           [6U]) ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                          [7U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c2_1 
        = (((VL_SHIFTL_III(30,30,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c1_1, 1U) 
             & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
             [6U]) | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                      [6U] & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                      [7U])) | (VL_SHIFTL_III(30,30,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c1_1, 1U) 
                                & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                                [7U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s3_0 
        = (0x3fffffffU & ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s2_0 
                           ^ VL_SHIFTL_III(30,30,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c2_0, 1U)) 
                          ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s2_1));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c3_0 
        = (((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s2_0 
             & VL_SHIFTL_III(30,30,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c2_0, 1U)) 
            | (VL_SHIFTL_III(30,30,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c2_0, 1U) 
               & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s2_1)) 
           | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s2_0 
              & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s2_1));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s4_0 
        = (0x3fffffffU & ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s3_0 
                           ^ VL_SHIFTL_III(30,30,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c3_0, 1U)) 
                          ^ VL_SHIFTL_III(30,30,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c2_1, 1U)));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c4_0 
        = (0x3fffffffU & (((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s3_0 
                            & VL_SHIFTL_III(30,30,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c3_0, 1U)) 
                           | VL_SHIFTL_III(30,30,32, 
                                           (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c3_0 
                                            & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c2_1), 1U)) 
                          | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s3_0 
                             & VL_SHIFTL_III(30,30,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c2_1, 1U))));
}

VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_triggers__stl(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf);

VL_ATTR_COLD bool Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_phase__stl(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_phase__stl\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___dump_triggers__act(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___dump_triggers__act\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge addn_8_fp32accum_fp16_tb_softfloat.tb_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge addn_8_fp32accum_fp16_tb_softfloat.tb_nrst)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(negedge addn_8_fp32accum_fp16_tb_softfloat.tb_clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___dump_triggers__nba(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___dump_triggers__nba\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge addn_8_fp32accum_fp16_tb_softfloat.tb_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge addn_8_fp32accum_fp16_tb_softfloat.tb_nrst)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(negedge addn_8_fp32accum_fp16_tb_softfloat.tb_clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root____Vm_traceActivitySetAll(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root____Vm_traceActivitySetAll\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
}

VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___ctor_var_reset(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___ctor_var_reset\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_clk = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out = VL_RAND_RESET_I(32);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result = VL_RAND_RESET_I(16);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__exp = VL_RAND_RESET_I(16);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__pass_count = 0;
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_count = 0;
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__off_by_one = 0;
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__off_by_two = 0;
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__off_by_five_plus = 0;
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__ulp_diff = 0;
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__ulp_big_count = 0;
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__total_ulp_diff = 0;
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a = 0;
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b = 0;
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__fd = 0;
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_fd = 0;
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__a = VL_RAND_RESET_I(16);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__b = VL_RAND_RESET_I(16);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__c = VL_RAND_RESET_I(16);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__d = VL_RAND_RESET_I(16);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__e = VL_RAND_RESET_I(16);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__f = VL_RAND_RESET_I(16);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__g = VL_RAND_RESET_I(16);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__h = VL_RAND_RESET_I(16);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__expected = VL_RAND_RESET_I(16);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__total_count = 0;
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__unnamedblk2__DOT__ret = 0;
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__unnamedblk2__DOT__is_zero_result = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr[__Vi0] = VL_RAND_RESET_I(5);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__idx_arr[__Vi0] = VL_RAND_RESET_I(3);
    }
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_is_nan_any = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_pos_inf = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_neg_inf = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_spec_case = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_spec_res = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e1[__Vi0] = VL_RAND_RESET_I(5);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e2[__Vi0] = VL_RAND_RESET_I(5);
    }
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_max_exp = VL_RAND_RESET_I(5);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i1[__Vi0] = VL_RAND_RESET_I(3);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i2[__Vi0] = VL_RAND_RESET_I(3);
    }
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_max_idx = VL_RAND_RESET_I(3);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_exp = VL_RAND_RESET_I(5);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_idx = VL_RAND_RESET_I(3);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_spec_case = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_spec_res = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[__Vi0] = VL_RAND_RESET_I(30);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh[__Vi0] = VL_RAND_RESET_I(6);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base[__Vi0] = VL_RAND_RESET_I(25);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_sticky = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_hot_ones = VL_RAND_RESET_I(4);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s1_0 = VL_RAND_RESET_I(30);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c1_0 = VL_RAND_RESET_I(30);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s1_1 = VL_RAND_RESET_I(30);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c1_1 = VL_RAND_RESET_I(30);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s2_0 = VL_RAND_RESET_I(30);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c2_0 = VL_RAND_RESET_I(30);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s2_1 = VL_RAND_RESET_I(30);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c2_1 = VL_RAND_RESET_I(30);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s3_0 = VL_RAND_RESET_I(30);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c3_0 = VL_RAND_RESET_I(30);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s4_0 = VL_RAND_RESET_I(30);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c4_0 = VL_RAND_RESET_I(30);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sum_vec = VL_RAND_RESET_I(30);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_carry_vec = VL_RAND_RESET_I(30);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_exp = VL_RAND_RESET_I(5);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sign_max = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sticky = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_hot_ones = VL_RAND_RESET_I(4);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_spec_case = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_spec_res = VL_RAND_RESET_I(32);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_raw_sum = VL_RAND_RESET_I(31);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_mag_sum = VL_RAND_RESET_I(29);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_res_sign = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_mag_sum = VL_RAND_RESET_I(29);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_res_sign = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_sticky = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_exp = VL_RAND_RESET_I(5);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_spec_case = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_spec_res = VL_RAND_RESET_I(32);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_scan = VL_RAND_RESET_I(29);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_lzd = VL_RAND_RESET_I(6);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_lzd = VL_RAND_RESET_I(6);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_mag = VL_RAND_RESET_I(29);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_sign = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_sticky = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_exp = VL_RAND_RESET_I(5);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_spec_case = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_spec_res = VL_RAND_RESET_I(32);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_e_final = VL_RAND_RESET_I(11);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__unnamedblk5__DOT__i = 0;
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__unnamedblk4__DOT__i = 0;
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp = VL_RAND_RESET_I(10);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded = VL_RAND_RESET_I(11);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__guard = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rnd = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__sticky = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__round_up = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
