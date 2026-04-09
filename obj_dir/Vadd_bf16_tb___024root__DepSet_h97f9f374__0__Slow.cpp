// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd_bf16_tb.h for the primary calling header

#include "Vadd_bf16_tb__pch.h"
#include "Vadd_bf16_tb___024root.h"

VL_ATTR_COLD void Vadd_bf16_tb___024root___eval_static(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___eval_static\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__add_bf16_tb__DOT__tb_clk__0 
        = vlSelfRef.add_bf16_tb__DOT__tb_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__add_bf16_tb__DOT__tb_nrst__0 
        = vlSelfRef.add_bf16_tb__DOT__tb_nrst;
}

VL_ATTR_COLD void Vadd_bf16_tb___024root___eval_final(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___eval_final\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_bf16_tb___024root___dump_triggers__stl(Vadd_bf16_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vadd_bf16_tb___024root___eval_phase__stl(Vadd_bf16_tb___024root* vlSelf);

VL_ATTR_COLD void Vadd_bf16_tb___024root___eval_settle(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___eval_settle\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vadd_bf16_tb___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("systolic_array_utils/add_bf16_tb.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vadd_bf16_tb___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_bf16_tb___024root___dump_triggers__stl(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___dump_triggers__stl\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void Vadd_bf16_tb___024root___stl_sequent__TOP__0(Vadd_bf16_tb___024root* vlSelf);
VL_ATTR_COLD void Vadd_bf16_tb___024root____Vm_traceActivitySetAll(Vadd_bf16_tb___024root* vlSelf);

VL_ATTR_COLD void Vadd_bf16_tb___024root___eval_stl(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___eval_stl\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vadd_bf16_tb___024root___stl_sequent__TOP__0(vlSelf);
        Vadd_bf16_tb___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

extern const VlUnpacked<SData/*8:0*/, 1024> Vadd_bf16_tb__ConstPool__TABLE_h5713a960_0;
extern const VlUnpacked<CData/*3:0*/, 1024> Vadd_bf16_tb__ConstPool__TABLE_hb30919e0_0;

VL_ATTR_COLD void Vadd_bf16_tb___024root___stl_sequent__TOP__0(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___stl_sequent__TOP__0\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*9:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    if (vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__signs_differ_l) {
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__mantissa_sum 
            = (0x7ffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa_l) 
                         - (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__smaller_mantissa_l)));
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__result_sign 
            = vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa_sign_l;
    } else {
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__mantissa_sum 
            = (0x7ffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__smaller_mantissa_l) 
                         + (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa_l)));
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__result_sign 
            = ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_shifted_l) 
               & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_not_shifted_l));
    }
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__mantissa_overflow 
        = (1U & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__mantissa_sum) 
                 >> 0xaU));
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff = 
        ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_sub)
          ? ((0x8000U & ((~ ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_b) 
                             >> 0xfU)) << 0xfU)) | 
             (0x7fffU & (IData)(vlSelfRef.add_bf16_tb__DOT__tb_b)))
          : (IData)(vlSelfRef.add_bf16_tb__DOT__tb_b));
    __Vtableidx1 = (0x3ffU & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__mantissa_sum));
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__normalized_mantissa_sum 
        = Vadd_bf16_tb__ConstPool__TABLE_h5713a960_0
        [__Vtableidx1];
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__norm_shift 
        = Vadd_bf16_tb__ConstPool__TABLE_hb30919e0_0
        [__Vtableidx1];
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__xor_out 
        = (0x1ffU & (((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                      ^ (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff)) 
                     >> 7U));
    if ((1U & ((~ (IData)((0U != (0x7fffU & (IData)(vlSelfRef.add_bf16_tb__DOT__tb_a))))) 
               & (~ (IData)((0U != (3U & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff)))))))) {
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__result_sign 
            = (1U & (((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                      & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff)) 
                     >> 0xfU));
    }
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_nan1 
        = (IData)(((0x7f80U == (0x7f80U & (IData)(vlSelfRef.add_bf16_tb__DOT__tb_a))) 
                   & (0U != (0x7fU & (IData)(vlSelfRef.add_bf16_tb__DOT__tb_a)))));
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_nan2 
        = (IData)(((0x7f80U == (0x7f80U & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff))) 
                   & (0U != (0x7fU & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff)))));
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_inf1 
        = (IData)(((0x7f80U == (0x7f80U & (IData)(vlSelfRef.add_bf16_tb__DOT__tb_a))) 
                   & (~ (IData)((0U != (0x7fU & (IData)(vlSelfRef.add_bf16_tb__DOT__tb_a)))))));
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_inf2 
        = (IData)(((0x7f80U == (0x7f80U & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff))) 
                   & (~ (IData)((0U != (0x7fU & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff)))))));
    vlSelfRef.add_bf16_tb__DOT__tb_invalid = (((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_nan1) 
                                               | (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_nan2)) 
                                              | (((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_inf1) 
                                                  & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_inf2)) 
                                                 & ((1U 
                                                     & ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                                                        >> 0xfU)) 
                                                    == 
                                                    (1U 
                                                     & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff) 
                                                        >> 0xfU)))));
    if (((0xffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                   >> 7U)) < (0xffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff) 
                                       >> 7U)))) {
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__smaller_exponent 
            = (0xffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                        >> 7U));
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_exponent 
            = (0xffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff) 
                        >> 7U));
    } else {
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__smaller_exponent 
            = (0xffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff) 
                        >> 7U));
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_exponent 
            = (0xffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                        >> 7U));
    }
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_select 
        = ((0xffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                     >> 7U)) >= (0xffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff) 
                                          >> 7U)));
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__round_this 
        = (0x1ffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__mantissa_overflow)
                      ? ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__mantissa_sum) 
                         >> 1U) : (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__normalized_mantissa_sum)));
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__u_exp1 
        = vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_max_l;
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__u_shifted_amount 
        = vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__norm_shift;
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__u_result 
        = (0xffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__u_exp1) 
                    - (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__u_shifted_amount)));
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_diff 
        = (0xffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_exponent) 
                    - (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__smaller_exponent)));
    if (vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_select) {
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_max 
            = (0xffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                        >> 7U));
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_shifted 
            = (1U & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff) 
                     >> 0xfU));
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_not_shifted 
            = (1U & ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                     >> 0xfU));
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__frac_not_shifted 
            = ((0U != (0xffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                                >> 7U))) ? (((0U != 
                                              (0xffU 
                                               & ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                                                  >> 7U))) 
                                             << 9U) 
                                            | (0x1fcU 
                                               & ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                                                  << 2U)))
                : 0U);
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__frac_shifted 
            = (0x3ffU & ((1U & (((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_diff) 
                                 >> 7U) | (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0xffU 
                                                       & ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                                                          >> 7U)))))))
                          ? 0U : ((((0U != (0xffU & 
                                            ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff) 
                                             >> 7U))) 
                                    << 9U) | (0x1fcU 
                                              & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff) 
                                                 << 2U))) 
                                  >> (0xfU & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_diff)))));
    } else {
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_max 
            = (0xffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff) 
                        >> 7U));
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_shifted 
            = (1U & ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                     >> 0xfU));
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_not_shifted 
            = (1U & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff) 
                     >> 0xfU));
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__frac_not_shifted 
            = ((0U != (0xffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff) 
                                >> 7U))) ? (((0U != 
                                              (0xffU 
                                               & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff) 
                                                  >> 7U))) 
                                             << 9U) 
                                            | (0x1fcU 
                                               & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff) 
                                                  << 2U)))
                : 0U);
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__frac_shifted 
            = (0x3ffU & ((1U & (((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_diff) 
                                 >> 7U) | (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0xffU 
                                                       & ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                                                          >> 7U)))))))
                          ? 0U : ((((0U != (0xffU & 
                                            ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                                             >> 7U))) 
                                    << 9U) | (0x1fcU 
                                              & ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                                                 << 2U))) 
                                  >> (0xfU & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_diff)))));
    }
    if (((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__frac_shifted) 
         > (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__frac_not_shifted))) {
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__smaller_mantissa 
            = vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__frac_not_shifted;
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa 
            = vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__frac_shifted;
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa_sign 
            = vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_shifted;
    } else {
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__smaller_mantissa 
            = vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__frac_shifted;
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa 
            = vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__frac_not_shifted;
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa_sign 
            = vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_not_shifted;
    }
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__round_sum 
        = (0x7fU & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__round_this) 
                    >> 2U));
    if ((1U & (((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__round_this) 
                >> 1U) & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__round_this) 
                          | ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_select)
                              ? (0U != ((((0U != (0xffU 
                                                  & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff) 
                                                     >> 7U))) 
                                          << 9U) | 
                                         (0x1fcU & 
                                          ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff) 
                                           << 2U))) 
                                        & (VL_SHIFTL_III(32,32,8, (IData)(1U), (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_diff)) 
                                           - (IData)(1U))))
                              : (0U != ((((0U != (0xffU 
                                                  & ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                                                     >> 7U))) 
                                          << 9U) | 
                                         (0x1fcU & 
                                          ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                                           << 2U))) 
                                        & (VL_SHIFTL_III(32,32,8, (IData)(1U), (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_diff)) 
                                           - (IData)(1U))))))))) {
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__round_sum 
            = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__round_sum)));
    }
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__rounded_fraction 
        = (0x7fU & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__round_sum));
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_out_adj 
        = (0xffU & (((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__mantissa_overflow)
                      ? ((IData)(1U) + (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_max_l))
                      : (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__u_result)) 
                    + (1U & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__round_sum) 
                             >> 7U))));
    vlSelfRef.add_bf16_tb__DOT__tb_result = ((((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_inf1) 
                                               & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_inf2)) 
                                              & (((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                                                  ^ (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff)) 
                                                 >> 0xfU))
                                              ? 0x7fc0U
                                              : ((((IData)(
                                                           (0x7f7fU 
                                                            == 
                                                            (0x7fffU 
                                                             & (IData)(vlSelfRef.add_bf16_tb__DOT__tb_a)))) 
                                                   & (0U 
                                                      != 
                                                      (0x7fffU 
                                                       & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff)))) 
                                                  | (((IData)(
                                                              (0x7f7fU 
                                                               == 
                                                               (0x7fffU 
                                                                & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff)))) 
                                                      & (0U 
                                                         != 
                                                         (0x7fffU 
                                                          & (IData)(vlSelfRef.add_bf16_tb__DOT__tb_a)))) 
                                                     & (~ 
                                                        (((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                                                          ^ (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff)) 
                                                         >> 0xfU))))
                                                  ? 
                                                 ((0x8000U 
                                                   & (IData)(vlSelfRef.add_bf16_tb__DOT__tb_a))
                                                   ? 0xff80U
                                                   : 0x7f80U)
                                                  : 
                                                 (((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_inf1) 
                                                   | (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_nan1))
                                                   ? (IData)(vlSelfRef.add_bf16_tb__DOT__tb_a)
                                                   : 
                                                  (((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_inf2) 
                                                    | (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_nan2))
                                                    ? (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff)
                                                    : 
                                                   ((IData)(
                                                            (((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__xor_out) 
                                                              >> 8U) 
                                                             & (~ (IData)(
                                                                          (0U 
                                                                           != 
                                                                           (0xffU 
                                                                            & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__xor_out)))))))
                                                     ? 0U
                                                     : 
                                                    (((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__result_sign) 
                                                      << 0xfU) 
                                                     | (((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_out_adj) 
                                                         << 7U) 
                                                        | (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__rounded_fraction))))))));
}

VL_ATTR_COLD void Vadd_bf16_tb___024root___eval_triggers__stl(Vadd_bf16_tb___024root* vlSelf);

VL_ATTR_COLD bool Vadd_bf16_tb___024root___eval_phase__stl(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___eval_phase__stl\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vadd_bf16_tb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vadd_bf16_tb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_bf16_tb___024root___dump_triggers__act(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___dump_triggers__act\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge add_bf16_tb.tb_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge add_bf16_tb.tb_nrst)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(negedge add_bf16_tb.tb_clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_bf16_tb___024root___dump_triggers__nba(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___dump_triggers__nba\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge add_bf16_tb.tb_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge add_bf16_tb.tb_nrst)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(negedge add_bf16_tb.tb_clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vadd_bf16_tb___024root____Vm_traceActivitySetAll(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root____Vm_traceActivitySetAll\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
}

VL_ATTR_COLD void Vadd_bf16_tb___024root___ctor_var_reset(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___ctor_var_reset\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->add_bf16_tb__DOT__tb_clk = VL_RAND_RESET_I(1);
    vlSelf->add_bf16_tb__DOT__tb_nrst = VL_RAND_RESET_I(1);
    vlSelf->add_bf16_tb__DOT__tb_a = VL_RAND_RESET_I(16);
    vlSelf->add_bf16_tb__DOT__tb_b = VL_RAND_RESET_I(16);
    vlSelf->add_bf16_tb__DOT__tb_sub = VL_RAND_RESET_I(1);
    vlSelf->add_bf16_tb__DOT__tb_result = VL_RAND_RESET_I(16);
    vlSelf->add_bf16_tb__DOT__tb_invalid = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 25; ++__Vi0) {
        vlSelf->add_bf16_tb__DOT__A[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 25; ++__Vi0) {
        vlSelf->add_bf16_tb__DOT__B[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 25; ++__Vi0) {
        vlSelf->add_bf16_tb__DOT__EXP[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->add_bf16_tb__DOT__idx = VL_RAND_RESET_I(32);
    vlSelf->add_bf16_tb__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->add_bf16_tb__DOT__fd = 0;
    vlSelf->add_bf16_tb__DOT__csv_a = VL_RAND_RESET_I(16);
    vlSelf->add_bf16_tb__DOT__csv_b = VL_RAND_RESET_I(16);
    vlSelf->add_bf16_tb__DOT__csv_exp = VL_RAND_RESET_I(16);
    vlSelf->add_bf16_tb__DOT__csv_sub_i = 0;
    vlSelf->add_bf16_tb__DOT__csv_sub = VL_RAND_RESET_I(1);
    vlSelf->add_bf16_tb__DOT__pass_cnt = VL_RAND_RESET_I(32);
    vlSelf->add_bf16_tb__DOT__fail_cnt = VL_RAND_RESET_I(32);
    vlSelf->add_bf16_tb__DOT__dut__DOT__bf2_eff = VL_RAND_RESET_I(16);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_nan1 = VL_RAND_RESET_I(1);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_nan2 = VL_RAND_RESET_I(1);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_inf1 = VL_RAND_RESET_I(1);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_inf2 = VL_RAND_RESET_I(1);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__smaller_exponent = VL_RAND_RESET_I(8);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_exponent = VL_RAND_RESET_I(8);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_select = VL_RAND_RESET_I(1);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_diff = VL_RAND_RESET_I(8);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_max = VL_RAND_RESET_I(8);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__frac_shifted = VL_RAND_RESET_I(10);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__frac_not_shifted = VL_RAND_RESET_I(10);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_shifted = VL_RAND_RESET_I(1);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_not_shifted = VL_RAND_RESET_I(1);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__smaller_mantissa = VL_RAND_RESET_I(10);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa = VL_RAND_RESET_I(10);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__mantissa_sum = VL_RAND_RESET_I(11);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa_sign = VL_RAND_RESET_I(1);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__result_sign = VL_RAND_RESET_I(1);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__mantissa_overflow = VL_RAND_RESET_I(1);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__smaller_mantissa_l = VL_RAND_RESET_I(10);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa_l = VL_RAND_RESET_I(10);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa_sign_l = VL_RAND_RESET_I(1);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_shifted_l = VL_RAND_RESET_I(1);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_not_shifted_l = VL_RAND_RESET_I(1);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__signs_differ_l = VL_RAND_RESET_I(1);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_max_l = VL_RAND_RESET_I(8);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__normalized_mantissa_sum = VL_RAND_RESET_I(9);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__norm_shift = VL_RAND_RESET_I(4);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__u_exp1 = VL_RAND_RESET_I(8);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__u_shifted_amount = VL_RAND_RESET_I(8);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__u_result = VL_RAND_RESET_I(8);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__round_this = VL_RAND_RESET_I(9);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__rounded_fraction = VL_RAND_RESET_I(7);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_out_adj = VL_RAND_RESET_I(8);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__round_sum = VL_RAND_RESET_I(8);
    vlSelf->add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__xor_out = VL_RAND_RESET_I(9);
    vlSelf->__Vtrigprevexpr___TOP__add_bf16_tb__DOT__tb_clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__add_bf16_tb__DOT__tb_nrst__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
