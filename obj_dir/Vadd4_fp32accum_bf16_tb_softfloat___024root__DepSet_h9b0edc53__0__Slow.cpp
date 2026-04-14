// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd4_fp32accum_bf16_tb_softfloat.h for the primary calling header

#include "Vadd4_fp32accum_bf16_tb_softfloat__pch.h"
#include "Vadd4_fp32accum_bf16_tb_softfloat___024root.h"

VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root___eval_static(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root___eval_static\n"); );
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__norm_val__0 
        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__norm_val;
    vlSelfRef.__Vtrigprevexpr___TOP__add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__norm_val__1 
        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__norm_val;
    vlSelfRef.__Vtrigprevexpr___TOP__add4_fp32accum_bf16_tb_softfloat__DOT__tb_clk__0 
        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__add4_fp32accum_bf16_tb_softfloat__DOT__tb_nrst__0 
        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_nrst;
}

VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root___eval_final(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root___eval_final\n"); );
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root___dump_triggers__stl(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vadd4_fp32accum_bf16_tb_softfloat___024root___eval_phase__stl(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf);

VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root___eval_settle(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root___eval_settle\n"); );
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vadd4_fp32accum_bf16_tb_softfloat___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 20, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vadd4_fp32accum_bf16_tb_softfloat___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root___dump_triggers__stl(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root___dump_triggers__stl\n"); );
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
    if ((2ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 1 is active: @([hybrid] add4_fp32accum_bf16_tb_softfloat.bf16adder.norm_val)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root___stl_sequent__TOP__0(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf);
VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root____Vm_traceActivitySetAll(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf);
VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root___stl_sequent__TOP__1(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf);
VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root___stl_comb__TOP__0(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf);

VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root___eval_stl(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root___eval_stl\n"); );
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vadd4_fp32accum_bf16_tb_softfloat___024root___stl_sequent__TOP__0(vlSelf);
        Vadd4_fp32accum_bf16_tb_softfloat___024root____Vm_traceActivitySetAll(vlSelf);
    }
    if ((2ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vadd4_fp32accum_bf16_tb_softfloat___024root___stl_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vadd4_fp32accum_bf16_tb_softfloat___024root___stl_comb__TOP__0(vlSelf);
        Vadd4_fp32accum_bf16_tb_softfloat___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root___stl_sequent__TOP__1(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root___stl_sequent__TOP__1\n"); );
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__rounded_mant_int 
        = (0x3ffffffU & (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__norm_val 
                         >> 3U));
}

VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root___stl_comb__TOP__0(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root___stl_comb__TOP__0\n"); );
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0U == vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_sum_mag)) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan = 0U;
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros = 0x1dU;
    } else {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan 
            = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_sum_mag;
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros = 0U;
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan, 0xeU))) {
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros 
                = (0x1fU & ((IData)(0x10U) + (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros)));
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan, 0x10U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan, 0x16U))) {
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros 
                = (0x1fU & ((IData)(8U) + (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros)));
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan, 8U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan, 0x1aU))) {
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros 
                = (0x1fU & ((IData)(4U) + (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros)));
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan, 4U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan, 0x1cU))) {
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros 
                = (0x1fU & ((IData)(2U) + (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros)));
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan, 2U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan, 0x1dU))) {
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros)));
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan, 1U));
        }
    }
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__norm_val 
        = (0x3fffffffU & (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_sum_mag 
                          << (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros)));
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__final_mant 
        = (0x3ffffffU & vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__rounded_mant_int);
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros) 
                    - ((0x4000000U & vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__rounded_mant_int)
                        ? 1U : 0U)));
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(3U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,7, (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros))));
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__result_out 
        = ((((0U == vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_sum_mag) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_exp_base)))
            ? 0ULL : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__final_exp_calc)))
                       ? (0x3fc000000ULL | ((QData)((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_res_sign)) 
                                            << 0x22U))
                       : (((QData)((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_res_sign)) 
                           << 0x22U) | (((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__final_exp_calc)))) 
                                         << 0x1aU) 
                                        | (QData)((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__final_mant))))));
    if (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_special) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__result_out 
            = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_spec_res;
    }
}

VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root___eval_triggers__stl(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf);

VL_ATTR_COLD bool Vadd4_fp32accum_bf16_tb_softfloat___024root___eval_phase__stl(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root___eval_phase__stl\n"); );
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vadd4_fp32accum_bf16_tb_softfloat___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vadd4_fp32accum_bf16_tb_softfloat___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root___dump_triggers__act(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root___dump_triggers__act\n"); );
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @([hybrid] add4_fp32accum_bf16_tb_softfloat.bf16adder.norm_val)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge add4_fp32accum_bf16_tb_softfloat.tb_clk)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(negedge add4_fp32accum_bf16_tb_softfloat.tb_nrst)\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((0x10ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @(negedge add4_fp32accum_bf16_tb_softfloat.tb_clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root___dump_triggers__nba(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root___dump_triggers__nba\n"); );
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @([hybrid] add4_fp32accum_bf16_tb_softfloat.bf16adder.norm_val)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge add4_fp32accum_bf16_tb_softfloat.tb_clk)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(negedge add4_fp32accum_bf16_tb_softfloat.tb_nrst)\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @(negedge add4_fp32accum_bf16_tb_softfloat.tb_clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root____Vm_traceActivitySetAll(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root____Vm_traceActivitySetAll\n"); );
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
    vlSelfRef.__Vm_traceActivity[6U] = 1U;
}

VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root___ctor_var_reset(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root___ctor_var_reset\n"); );
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__tb_clk = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__tb_nrst = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__tb_a = VL_RAND_RESET_I(16);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__tb_b = VL_RAND_RESET_I(16);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__tb_c = VL_RAND_RESET_I(16);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__tb_d = VL_RAND_RESET_I(16);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__tb_result = VL_RAND_RESET_I(16);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__exp = VL_RAND_RESET_I(16);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__pass_count = 0;
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__fail_count = 0;
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff = 0;
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count = 0;
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp = 0;
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__a = VL_RAND_RESET_I(16);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__b = VL_RAND_RESET_I(16);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__c = VL_RAND_RESET_I(16);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__d = VL_RAND_RESET_I(16);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__expected = VL_RAND_RESET_I(16);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__fd = 0;
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__total_count = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a = 0;
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b = 0;
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__ret = 0;
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__a_daz = VL_RAND_RESET_I(16);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__b_daz = VL_RAND_RESET_I(16);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__c_daz = VL_RAND_RESET_I(16);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__d_daz = VL_RAND_RESET_I(16);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_a = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_b = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_c = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_d = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_a = VL_RAND_RESET_I(7);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_b = VL_RAND_RESET_I(7);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_c = VL_RAND_RESET_I(7);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_d = VL_RAND_RESET_I(7);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_a = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_b = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_c = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_d = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_p = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_m = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_r = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_n = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_x = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_y = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_mx = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_nx = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_p = VL_RAND_RESET_I(7);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_m = VL_RAND_RESET_I(7);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_r = VL_RAND_RESET_I(7);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_n = VL_RAND_RESET_I(7);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_x = VL_RAND_RESET_I(7);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_y = VL_RAND_RESET_I(7);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_mx = VL_RAND_RESET_I(7);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_nx = VL_RAND_RESET_I(7);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_p = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_m = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_r = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_n = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_x = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_y = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_mx = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_nx = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_x_eff = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_y_eff = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_mx_eff = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_nx_eff = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__y_shift = VL_RAND_RESET_I(9);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__m_shift = VL_RAND_RESET_I(9);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__n_shift = VL_RAND_RESET_I(9);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__x_mant = VL_RAND_RESET_I(27);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__y_shifted = VL_RAND_RESET_I(27);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__m_shifted = VL_RAND_RESET_I(27);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__n_shifted = VL_RAND_RESET_I(27);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__y_mant_base = VL_RAND_RESET_I(27);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__m_mant_base = VL_RAND_RESET_I(27);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__n_mant_base = VL_RAND_RESET_I(27);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sticky_y = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sticky_m = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sticky_n = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__y_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__m_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__n_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__is_nan_any = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__special_case = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__any_pos_inf = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__any_neg_inf = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__special_result = VL_RAND_RESET_Q(35);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st1_a_e = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st1_a_s = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st1_align_sticky = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st1_special_case = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st1_special_result = VL_RAND_RESET_Q(35);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st1_sum_vec = VL_RAND_RESET_I(30);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st1_carry_vec = VL_RAND_RESET_I(30);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st1_hot_ones = VL_RAND_RESET_I(2);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__raw_sum = VL_RAND_RESET_I(30);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__mag_sum = VL_RAND_RESET_I(30);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__res_sign = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_exp_base = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_sum_mag = VL_RAND_RESET_I(30);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_spec_res = VL_RAND_RESET_Q(35);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_res_sign = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_sticky = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_special = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan = VL_RAND_RESET_I(30);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros = VL_RAND_RESET_I(5);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__norm_val = VL_RAND_RESET_I(30);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__raw_mant = VL_RAND_RESET_I(26);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__final_mant = VL_RAND_RESET_I(26);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__rounded_mant_int = VL_RAND_RESET_I(27);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__final_exp_calc = VL_RAND_RESET_I(11);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__result_out = VL_RAND_RESET_Q(35);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__op_x = VL_RAND_RESET_I(30);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__op_y = VL_RAND_RESET_I(30);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__op_m = VL_RAND_RESET_I(30);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__op_n = VL_RAND_RESET_I(30);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__csa_s1 = VL_RAND_RESET_I(30);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__csa_c1 = VL_RAND_RESET_I(30);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__csa_s2 = VL_RAND_RESET_I(30);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__csa_c2 = VL_RAND_RESET_I(30);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__new_exp = VL_RAND_RESET_I(10);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__rounded = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__guard = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__rnd = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__sticky = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__round_up = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__norm_val__0 = VL_RAND_RESET_I(30);
    vlSelf->__VstlDidInit = 0;
    vlSelf->__Vtrigprevexpr___TOP__add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__norm_val__1 = VL_RAND_RESET_I(30);
    vlSelf->__Vtrigprevexpr___TOP__add4_fp32accum_bf16_tb_softfloat__DOT__tb_clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__add4_fp32accum_bf16_tb_softfloat__DOT__tb_nrst__0 = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
