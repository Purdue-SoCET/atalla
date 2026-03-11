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
    if ((0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sum_mag)) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__stage3_logic__DOT__unnamedblk9__DOT__i = 0xffffffffU;
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__raw_sum 
        = (0x1fffffffU & (((0x7fffffffU & VL_EXTENDS_II(31,29, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_sum_vec)) 
                           + (0x7fffffffU & VL_EXTENDS_II(31,28, 
                                                          (0xfffffffU 
                                                           & VL_SHIFTL_III(28,28,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_carry_vec, 1U))))) 
                          + (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_hot_ones)));
    if ((0x8000000U & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__raw_sum)) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mag_sum 
            = (0x7ffffffU & ((IData)(1U) + (~ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__raw_sum)));
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_a_s)));
    } else {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mag_sum 
            = (0x7ffffffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__raw_sum);
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__res_sign 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_a_s;
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__guard 
        = (1U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs
                 [3U] >> 0xcU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rnd 
        = (1U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs
                 [3U] >> 0xbU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__sticky 
        = (0U != (0x7ffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs
                  [3U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__round_up 
        = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__guard) 
           & (((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rnd) 
               | (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__sticky)) 
              | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs
                 [3U] >> 0xdU)));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded 
        = (0x7ffU & ((0x3ffU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs
                                [3U] >> 0xdU)) + (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__round_up)));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp 
        = (0x3ffU & ((VL_EXTENDS_II(10,10, (0xffU & 
                                            (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs
                                             [3U] >> 0x17U))) 
                      - (IData)(0x70U)) + VL_EXTENDS_II(10,10, 
                                                        (1U 
                                                         & ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded) 
                                                            >> 0xaU)))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result 
        = ((0xffU == (0xffU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs
                               [3U] >> 0x17U))) ? (0x7c00U 
                                                   | ((0x8000U 
                                                       & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs
                                                          [3U] 
                                                          >> 0x10U)) 
                                                      | ((0U 
                                                          != 
                                                          (0x7fffffU 
                                                           & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs
                                                           [3U]))
                                                          ? 0x200U
                                                          : 0U)))
            : (VL_LTES_III(10, 0x1fU, (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp))
                ? (0x7c00U | (0x8000U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs
                                         [3U] >> 0x10U)))
                : (VL_GTES_III(32, 0U, VL_EXTENDS_II(32,10, (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp)))
                    ? (0x8000U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs
                                  [3U] >> 0x10U)) : 
                   ((0x8000U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs
                                [3U] >> 0x10U)) | (
                                                   (0x7c00U 
                                                    & ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp) 
                                                       << 0xaU)) 
                                                   | ((0x400U 
                                                       & (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded))
                                                       ? 0U
                                                       : 
                                                      (0x3ffU 
                                                       & (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded))))))));
    if ((0U == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sum_mag)) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan = 0U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros = 0x1aU;
    } else {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sum_mag;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros = 0U;
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan, 0xbU))) {
            vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros 
                = (0x3fU & ((IData)(0x10U) + (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros)));
            vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan 
                = (0x7ffffffU & VL_SHIFTL_III(27,27,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan, 0x10U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan, 0x13U))) {
            vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros 
                = (0x3fU & ((IData)(8U) + (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros)));
            vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan 
                = (0x7ffffffU & VL_SHIFTL_III(27,27,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan, 8U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan, 0x17U))) {
            vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros 
                = (0x3fU & ((IData)(4U) + (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros)));
            vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan 
                = (0x7ffffffU & VL_SHIFTL_III(27,27,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan, 4U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan, 0x19U))) {
            vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros 
                = (0x3fU & ((IData)(2U) + (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros)));
            vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan 
                = (0x7ffffffU & VL_SHIFTL_III(27,27,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan, 2U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan, 0x1aU))) {
            vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros 
                = (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros)));
            vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan 
                = (0x7ffffffU & VL_SHIFTL_III(27,27,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan, 1U));
        }
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__norm_val 
        = (0x7ffffffU & VL_SHIFTL_III(27,27,6, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sum_mag, (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros)));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__final_mant 
        = (0x7fffffU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__norm_val 
                        >> 3U));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__final_exp_calc 
        = (0x7ffU & ((IData)(0x70U) + (((IData)(2U) 
                                        + VL_EXTENDS_II(11,7, (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_exp_base))) 
                                       - VL_EXTENDS_II(11,8, (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros)))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__result_out 
        = ((((0U == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sum_mag) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_exp_base)))
            ? 0U : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__final_exp_calc)))
                     ? (0x7f800000U | ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_res_sign) 
                                       << 0x1fU)) : 
                    (((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_res_sign) 
                      << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__final_exp_calc) 
                                                   << 0x17U)) 
                                   | vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__final_mant))));
    if (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_special) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__result_out 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_spec_res;
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__is_nan_any = 0U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_pos_inf = 0U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_neg_inf = 0U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[0U] 
        = (0xffffU & ((0U == (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U] 
                                       >> 0xaU))) ? 
                      (0x8000U & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U])
                       : vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[0U] 
        = (1U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
                 [0U] >> 0xfU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[0U] 
        = (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
                    [0U] >> 0xaU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[0U] 
        = (0x3ffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
           [0U]);
    if (((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
          [0U]) & (0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                   [0U]))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__is_nan_any = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
           [0U]) & (~ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
                    [0U])) & (~ (IData)((0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                                         [0U]))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_pos_inf = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
           [0U]) & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
          [0U]) & (~ (IData)((0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                              [0U]))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_neg_inf = 1U;
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[1U] 
        = (0xffffU & ((0U == (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U] 
                                       >> 0x1aU))) ? 
                      (0x8000U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U] 
                                  >> 0x10U)) : ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U] 
                                                   >> 0x10U))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[1U] 
        = (1U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
                 [1U] >> 0xfU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[1U] 
        = (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
                    [1U] >> 0xaU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[1U] 
        = (0x3ffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
           [1U]);
    if (((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
          [1U]) & (0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                   [1U]))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__is_nan_any = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
           [1U]) & (~ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
                    [1U])) & (~ (IData)((0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                                         [1U]))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_pos_inf = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
           [1U]) & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
          [1U]) & (~ (IData)((0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                              [1U]))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_neg_inf = 1U;
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[2U] 
        = (0xffffU & ((0U == (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U] 
                                       >> 0xaU))) ? 
                      (0x8000U & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U])
                       : vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[2U] 
        = (1U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
                 [2U] >> 0xfU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[2U] 
        = (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
                    [2U] >> 0xaU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[2U] 
        = (0x3ffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
           [2U]);
    if (((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
          [2U]) & (0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                   [2U]))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__is_nan_any = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
           [2U]) & (~ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
                    [2U])) & (~ (IData)((0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                                         [2U]))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_pos_inf = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
           [2U]) & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
          [2U]) & (~ (IData)((0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                              [2U]))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_neg_inf = 1U;
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[3U] 
        = (0xffffU & ((0U == (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U] 
                                       >> 0x1aU))) ? 
                      (0x8000U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U] 
                                  >> 0x10U)) : ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U] 
                                                   >> 0x10U))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[3U] 
        = (1U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
                 [3U] >> 0xfU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[3U] 
        = (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
                    [3U] >> 0xaU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[3U] 
        = (0x3ffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
           [3U]);
    if (((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
          [3U]) & (0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                   [3U]))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__is_nan_any = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
           [3U]) & (~ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
                    [3U])) & (~ (IData)((0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                                         [3U]))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_pos_inf = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
           [3U]) & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
          [3U]) & (~ (IData)((0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                              [3U]))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_neg_inf = 1U;
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[4U] 
        = (0xffffU & ((0U == (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U] 
                                       >> 0xaU))) ? 
                      (0x8000U & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U])
                       : vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[4U] 
        = (1U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
                 [4U] >> 0xfU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[4U] 
        = (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
                    [4U] >> 0xaU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[4U] 
        = (0x3ffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
           [4U]);
    if (((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
          [4U]) & (0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                   [4U]))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__is_nan_any = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
           [4U]) & (~ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
                    [4U])) & (~ (IData)((0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                                         [4U]))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_pos_inf = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
           [4U]) & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
          [4U]) & (~ (IData)((0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                              [4U]))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_neg_inf = 1U;
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[5U] 
        = (0xffffU & ((0U == (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U] 
                                       >> 0x1aU))) ? 
                      (0x8000U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U] 
                                  >> 0x10U)) : ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U] 
                                                   >> 0x10U))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[5U] 
        = (1U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
                 [5U] >> 0xfU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[5U] 
        = (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
                    [5U] >> 0xaU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[5U] 
        = (0x3ffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
           [5U]);
    if (((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
          [5U]) & (0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                   [5U]))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__is_nan_any = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
           [5U]) & (~ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
                    [5U])) & (~ (IData)((0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                                         [5U]))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_pos_inf = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
           [5U]) & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
          [5U]) & (~ (IData)((0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                              [5U]))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_neg_inf = 1U;
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[6U] 
        = (0xffffU & ((0U == (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U] 
                                       >> 0xaU))) ? 
                      (0x8000U & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U])
                       : vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[6U] 
        = (1U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
                 [6U] >> 0xfU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[6U] 
        = (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
                    [6U] >> 0xaU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[6U] 
        = (0x3ffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
           [6U]);
    if (((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
          [6U]) & (0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                   [6U]))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__is_nan_any = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
           [6U]) & (~ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
                    [6U])) & (~ (IData)((0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                                         [6U]))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_pos_inf = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
           [6U]) & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
          [6U]) & (~ (IData)((0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                              [6U]))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_neg_inf = 1U;
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[7U] 
        = (0xffffU & ((0U == (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U] 
                                       >> 0x1aU))) ? 
                      (0x8000U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U] 
                                  >> 0x10U)) : ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U] 
                                                   >> 0x10U))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[7U] 
        = (1U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
                 [7U] >> 0xfU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[7U] 
        = (0x1fU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
                    [7U] >> 0xaU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[7U] 
        = (0x3ffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
           [7U]);
    if (((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
          [7U]) & (0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                   [7U]))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__is_nan_any = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
           [7U]) & (~ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
                    [7U])) & (~ (IData)((0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                                         [7U]))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_pos_inf = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
           [7U]) & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
          [7U]) & (~ (IData)((0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                              [7U]))))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_neg_inf = 1U;
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[0U][0U] 
        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
        [0U];
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[0U][0U] = 0U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[0U][1U] 
        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
        [1U];
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[0U][1U] = 1U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[0U][2U] 
        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
        [2U];
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[0U][2U] = 2U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[0U][3U] 
        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
        [3U];
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[0U][3U] = 3U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[0U][4U] 
        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
        [4U];
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[0U][4U] = 4U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[0U][5U] 
        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
        [5U];
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[0U][5U] = 5U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[0U][6U] 
        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
        [6U];
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[0U][6U] = 6U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[0U][7U] 
        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
        [7U];
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[0U][7U] = 7U;
    if ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
         [0U][0U] >= vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
         [0U][1U])) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[1U][0U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
            [0U][0U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[1U][0U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
            [0U][0U];
    } else {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[1U][0U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
            [0U][1U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[1U][0U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
            [0U][1U];
    }
    if ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
         [0U][2U] >= vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
         [0U][3U])) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[1U][1U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
            [0U][2U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[1U][1U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
            [0U][2U];
    } else {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[1U][1U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
            [0U][3U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[1U][1U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
            [0U][3U];
    }
    if ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
         [0U][4U] >= vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
         [0U][5U])) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[1U][2U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
            [0U][4U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[1U][2U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
            [0U][4U];
    } else {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[1U][2U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
            [0U][5U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[1U][2U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
            [0U][5U];
    }
    if ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
         [0U][6U] >= vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
         [0U][7U])) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[1U][3U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
            [0U][6U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[1U][3U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
            [0U][6U];
    } else {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[1U][3U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
            [0U][7U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[1U][3U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
            [0U][7U];
    }
    if ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
         [1U][0U] >= vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
         [1U][1U])) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[2U][0U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
            [1U][0U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[2U][0U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
            [1U][0U];
    } else {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[2U][0U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
            [1U][1U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[2U][0U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
            [1U][1U];
    }
    if ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
         [1U][2U] >= vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
         [1U][3U])) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[2U][1U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
            [1U][2U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[2U][1U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
            [1U][2U];
    } else {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[2U][1U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
            [1U][3U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[2U][1U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
            [1U][3U];
    }
    if ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
         [2U][0U] >= vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
         [2U][1U])) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[3U][0U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
            [2U][0U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[3U][0U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
            [2U][0U];
    } else {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[3U][0U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
            [2U][1U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[3U][0U] 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
            [2U][1U];
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp 
        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
        [3U][0U];
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx 
        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
        [3U][0U];
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_max 
        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
        [vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx];
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_case = 0U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_neg_inf)))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_case = 1U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_pos_inf) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_case = 1U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_neg_inf) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_case = 1U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_result = 0xff800000U;
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp_eff 
        = ((0U == (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp))
            ? 1U : (0x1fU & (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp)));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[0U] 
        = (((IData)((0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                     [0U])) << 0x18U) | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                                         [0U] << 0xeU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[0U] 
        = (0x3fU & ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp_eff) 
                    - ((0U == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                        [0U]) ? 1U : vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                       [0U])));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[0U] 
        = (0U != (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base
                  [0U] & (~ VL_SHIFTL_III(25,25,6, (IData)(0x1ffffffU), 
                                          vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
                                          [0U]))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[0U] 
        = ((0x19U <= vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
            [0U]) ? 0U : (0x1ffffffU & VL_SHIFTR_III(32,32,6, 
                                                     vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base
                                                     [0U], 
                                                     vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
                                                     [0U])));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[0U] 
        = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_max) 
           ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
           [0U]);
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[0U] 
        = (0xfffffffU & ((0U == (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx))
                          ? vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                         [0U] : (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff
                                 [0U] ? (~ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                                         [0U]) : vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                                 [0U])));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[1U] 
        = (((IData)((0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                     [1U])) << 0x18U) | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                                         [1U] << 0xeU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[1U] 
        = (0x3fU & ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp_eff) 
                    - ((0U == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                        [1U]) ? 1U : vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                       [1U])));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[1U] 
        = (0U != (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base
                  [1U] & (~ VL_SHIFTL_III(25,25,6, (IData)(0x1ffffffU), 
                                          vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
                                          [1U]))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[1U] 
        = ((0x19U <= vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
            [1U]) ? 0U : (0x1ffffffU & VL_SHIFTR_III(32,32,6, 
                                                     vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base
                                                     [1U], 
                                                     vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
                                                     [1U])));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[1U] 
        = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_max) 
           ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
           [1U]);
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[1U] 
        = (0xfffffffU & ((1U == (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx))
                          ? vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                         [1U] : (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff
                                 [1U] ? (~ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                                         [1U]) : vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                                 [1U])));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[2U] 
        = (((IData)((0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                     [2U])) << 0x18U) | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                                         [2U] << 0xeU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[2U] 
        = (0x3fU & ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp_eff) 
                    - ((0U == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                        [2U]) ? 1U : vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                       [2U])));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[2U] 
        = (0U != (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base
                  [2U] & (~ VL_SHIFTL_III(25,25,6, (IData)(0x1ffffffU), 
                                          vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
                                          [2U]))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[2U] 
        = ((0x19U <= vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
            [2U]) ? 0U : (0x1ffffffU & VL_SHIFTR_III(32,32,6, 
                                                     vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base
                                                     [2U], 
                                                     vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
                                                     [2U])));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[2U] 
        = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_max) 
           ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
           [2U]);
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[2U] 
        = (0xfffffffU & ((2U == (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx))
                          ? vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                         [2U] : (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff
                                 [2U] ? (~ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                                         [2U]) : vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                                 [2U])));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[3U] 
        = (((IData)((0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                     [3U])) << 0x18U) | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                                         [3U] << 0xeU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[3U] 
        = (0x3fU & ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp_eff) 
                    - ((0U == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                        [3U]) ? 1U : vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                       [3U])));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[3U] 
        = (0U != (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base
                  [3U] & (~ VL_SHIFTL_III(25,25,6, (IData)(0x1ffffffU), 
                                          vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
                                          [3U]))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[3U] 
        = ((0x19U <= vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
            [3U]) ? 0U : (0x1ffffffU & VL_SHIFTR_III(32,32,6, 
                                                     vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base
                                                     [3U], 
                                                     vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
                                                     [3U])));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[3U] 
        = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_max) 
           ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
           [3U]);
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[3U] 
        = (0xfffffffU & ((3U == (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx))
                          ? vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                         [3U] : (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff
                                 [3U] ? (~ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                                         [3U]) : vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                                 [3U])));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[4U] 
        = (((IData)((0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                     [4U])) << 0x18U) | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                                         [4U] << 0xeU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[4U] 
        = (0x3fU & ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp_eff) 
                    - ((0U == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                        [4U]) ? 1U : vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                       [4U])));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[4U] 
        = (0U != (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base
                  [4U] & (~ VL_SHIFTL_III(25,25,6, (IData)(0x1ffffffU), 
                                          vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
                                          [4U]))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[4U] 
        = ((0x19U <= vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
            [4U]) ? 0U : (0x1ffffffU & VL_SHIFTR_III(32,32,6, 
                                                     vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base
                                                     [4U], 
                                                     vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
                                                     [4U])));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[4U] 
        = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_max) 
           ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
           [4U]);
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[4U] 
        = (0xfffffffU & ((4U == (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx))
                          ? vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                         [4U] : (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff
                                 [4U] ? (~ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                                         [4U]) : vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                                 [4U])));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[5U] 
        = (((IData)((0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                     [5U])) << 0x18U) | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                                         [5U] << 0xeU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[5U] 
        = (0x3fU & ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp_eff) 
                    - ((0U == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                        [5U]) ? 1U : vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                       [5U])));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[5U] 
        = (0U != (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base
                  [5U] & (~ VL_SHIFTL_III(25,25,6, (IData)(0x1ffffffU), 
                                          vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
                                          [5U]))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[5U] 
        = ((0x19U <= vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
            [5U]) ? 0U : (0x1ffffffU & VL_SHIFTR_III(32,32,6, 
                                                     vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base
                                                     [5U], 
                                                     vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
                                                     [5U])));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[5U] 
        = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_max) 
           ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
           [5U]);
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[5U] 
        = (0xfffffffU & ((5U == (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx))
                          ? vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                         [5U] : (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff
                                 [5U] ? (~ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                                         [5U]) : vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                                 [5U])));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[6U] 
        = (((IData)((0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                     [6U])) << 0x18U) | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                                         [6U] << 0xeU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[6U] 
        = (0x3fU & ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp_eff) 
                    - ((0U == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                        [6U]) ? 1U : vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                       [6U])));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[6U] 
        = (0U != (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base
                  [6U] & (~ VL_SHIFTL_III(25,25,6, (IData)(0x1ffffffU), 
                                          vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
                                          [6U]))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[6U] 
        = ((0x19U <= vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
            [6U]) ? 0U : (0x1ffffffU & VL_SHIFTR_III(32,32,6, 
                                                     vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base
                                                     [6U], 
                                                     vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
                                                     [6U])));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[6U] 
        = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_max) 
           ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
           [6U]);
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[6U] 
        = (0xfffffffU & ((6U == (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx))
                          ? vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                         [6U] : (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff
                                 [6U] ? (~ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                                         [6U]) : vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                                 [6U])));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[7U] 
        = (((IData)((0U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                     [7U])) << 0x18U) | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                                         [7U] << 0xeU));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[7U] 
        = (0x3fU & ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp_eff) 
                    - ((0U == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                        [7U]) ? 1U : vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                       [7U])));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[7U] 
        = (0U != (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base
                  [7U] & (~ VL_SHIFTL_III(25,25,6, (IData)(0x1ffffffU), 
                                          vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
                                          [7U]))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[7U] 
        = ((0x19U <= vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
            [7U]) ? 0U : (0x1ffffffU & VL_SHIFTR_III(32,32,6, 
                                                     vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base
                                                     [7U], 
                                                     vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
                                                     [7U])));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[7U] 
        = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_max) 
           ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
           [7U]);
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[7U] 
        = (0xfffffffU & ((7U == (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx))
                          ? vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                         [7U] : (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff
                                 [7U] ? (~ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                                         [7U]) : vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                                 [7U])));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[0U] 
        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
        [0U];
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[0U] = 0U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[1U] 
        = (0xfffffffU & ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
                          [0U] ^ VL_SHIFTL_III(28,28,32, 
                                               vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                               [0U], 1U)) 
                         ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                         [1U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[1U] 
        = (((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
             [0U] & VL_SHIFTL_III(28,28,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                  [0U], 1U)) | (VL_SHIFTL_III(28,28,32, 
                                                              vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                                              [0U], 1U) 
                                                & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                                                [1U])) 
           | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
              [1U] & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
              [0U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[2U] 
        = (0xfffffffU & ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
                          [1U] ^ VL_SHIFTL_III(28,28,32, 
                                               vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                               [1U], 1U)) 
                         ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                         [2U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[2U] 
        = (((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
             [1U] & VL_SHIFTL_III(28,28,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                  [1U], 1U)) | (VL_SHIFTL_III(28,28,32, 
                                                              vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                                              [1U], 1U) 
                                                & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                                                [2U])) 
           | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
              [2U] & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
              [1U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[3U] 
        = (0xfffffffU & ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
                          [2U] ^ VL_SHIFTL_III(28,28,32, 
                                               vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                               [2U], 1U)) 
                         ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                         [3U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[3U] 
        = (((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
             [2U] & VL_SHIFTL_III(28,28,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                  [2U], 1U)) | (VL_SHIFTL_III(28,28,32, 
                                                              vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                                              [2U], 1U) 
                                                & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                                                [3U])) 
           | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
              [3U] & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
              [2U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[4U] 
        = (0xfffffffU & ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
                          [3U] ^ VL_SHIFTL_III(28,28,32, 
                                               vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                               [3U], 1U)) 
                         ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                         [4U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[4U] 
        = (((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
             [3U] & VL_SHIFTL_III(28,28,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                  [3U], 1U)) | (VL_SHIFTL_III(28,28,32, 
                                                              vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                                              [3U], 1U) 
                                                & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                                                [4U])) 
           | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
              [4U] & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
              [3U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[5U] 
        = (0xfffffffU & ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
                          [4U] ^ VL_SHIFTL_III(28,28,32, 
                                               vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                               [4U], 1U)) 
                         ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                         [5U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[5U] 
        = (((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
             [4U] & VL_SHIFTL_III(28,28,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                  [4U], 1U)) | (VL_SHIFTL_III(28,28,32, 
                                                              vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                                              [4U], 1U) 
                                                & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                                                [5U])) 
           | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
              [5U] & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
              [4U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[6U] 
        = (0xfffffffU & ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
                          [5U] ^ VL_SHIFTL_III(28,28,32, 
                                               vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                               [5U], 1U)) 
                         ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                         [6U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[6U] 
        = (((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
             [5U] & VL_SHIFTL_III(28,28,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                  [5U], 1U)) | (VL_SHIFTL_III(28,28,32, 
                                                              vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                                              [5U], 1U) 
                                                & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                                                [6U])) 
           | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
              [6U] & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
              [5U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[7U] 
        = (0xfffffffU & ((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
                          [6U] ^ VL_SHIFTL_III(28,28,32, 
                                               vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                               [6U], 1U)) 
                         ^ vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                         [7U]));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[7U] 
        = (((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
             [6U] & VL_SHIFTL_III(28,28,32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                  [6U], 1U)) | (VL_SHIFTL_III(28,28,32, 
                                                              vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                                              [6U], 1U) 
                                                & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                                                [7U])) 
           | (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
              [7U] & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
              [6U]));
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
    vlSelfRef.__Vm_traceActivity[6U] = 1U;
    vlSelfRef.__Vm_traceActivity[7U] = 1U;
}

VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___ctor_var_reset(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___ctor_var_reset\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_clk = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data);
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
        vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[__Vi0] = VL_RAND_RESET_I(5);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[__Vi0] = VL_RAND_RESET_I(10);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[__Vi0][__Vi1] = VL_RAND_RESET_I(5);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[__Vi0][__Vi1] = VL_RAND_RESET_I(3);
        }
    }
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp = VL_RAND_RESET_I(5);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp_eff = VL_RAND_RESET_I(5);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx = VL_RAND_RESET_I(3);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_max = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[__Vi0] = VL_RAND_RESET_I(6);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[__Vi0] = VL_RAND_RESET_I(25);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[__Vi0] = VL_RAND_RESET_I(25);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[__Vi0] = VL_RAND_RESET_I(28);
    }
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__is_nan_any = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_pos_inf = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_neg_inf = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_case = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_result = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[__Vi0] = VL_RAND_RESET_I(28);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[__Vi0] = VL_RAND_RESET_I(28);
    }
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_a_e = VL_RAND_RESET_I(5);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_a_s = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_align_sticky = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_special_case = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_special_result = VL_RAND_RESET_I(32);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_sum_vec = VL_RAND_RESET_I(28);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_carry_vec = VL_RAND_RESET_I(28);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_hot_ones = VL_RAND_RESET_I(4);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__raw_sum = VL_RAND_RESET_I(29);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mag_sum = VL_RAND_RESET_I(27);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__res_sign = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_exp_base = VL_RAND_RESET_I(5);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sum_mag = VL_RAND_RESET_I(27);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_spec_res = VL_RAND_RESET_I(32);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_res_sign = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sticky = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_special = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan = VL_RAND_RESET_I(27);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros = VL_RAND_RESET_I(6);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__norm_val = VL_RAND_RESET_I(27);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__final_mant = VL_RAND_RESET_I(23);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__final_exp_calc = VL_RAND_RESET_I(11);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__result_out = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__unnamedblk7__DOT__i = 0;
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__unnamedblk8__DOT__i = 0;
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__stage3_logic__DOT__unnamedblk9__DOT__i = 0;
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__unnamedblk10__DOT__i = 0;
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp = VL_RAND_RESET_I(10);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded = VL_RAND_RESET_I(11);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__guard = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rnd = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__sticky = VL_RAND_RESET_I(1);
    vlSelf->addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__round_up = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
