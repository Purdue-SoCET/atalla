// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd_fp16_tb_full.h for the primary calling header

#include "Vadd_fp16_tb_full__pch.h"
#include "Vadd_fp16_tb_full___024root.h"

VL_ATTR_COLD void Vadd_fp16_tb_full___024root___eval_static(Vadd_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root___eval_static\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__add_fp16_tb_full__DOT__tb_clk__0 
        = vlSelfRef.add_fp16_tb_full__DOT__tb_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__add_fp16_tb_full__DOT__tb_nrst__0 
        = vlSelfRef.add_fp16_tb_full__DOT__tb_nrst;
}

VL_ATTR_COLD void Vadd_fp16_tb_full___024root___eval_final(Vadd_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root___eval_final\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_fp16_tb_full___024root___dump_triggers__stl(Vadd_fp16_tb_full___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vadd_fp16_tb_full___024root___eval_phase__stl(Vadd_fp16_tb_full___024root* vlSelf);

VL_ATTR_COLD void Vadd_fp16_tb_full___024root___eval_settle(Vadd_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root___eval_settle\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vadd_fp16_tb_full___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb/unit/systolic_array/add_fp16_tb_full.sv", 9, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vadd_fp16_tb_full___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_fp16_tb_full___024root___dump_triggers__stl(Vadd_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root___dump_triggers__stl\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void Vadd_fp16_tb_full___024root___stl_sequent__TOP__0(Vadd_fp16_tb_full___024root* vlSelf);
VL_ATTR_COLD void Vadd_fp16_tb_full___024root____Vm_traceActivitySetAll(Vadd_fp16_tb_full___024root* vlSelf);

VL_ATTR_COLD void Vadd_fp16_tb_full___024root___eval_stl(Vadd_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root___eval_stl\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vadd_fp16_tb_full___024root___stl_sequent__TOP__0(vlSelf);
        Vadd_fp16_tb_full___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vadd_fp16_tb_full___024root___stl_sequent__TOP__0(Vadd_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root___stl_sequent__TOP__0\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__signs_differ_l) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa_sign_l;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum 
            = (0x3fffU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa_l) 
                          - (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__smaller_mantissa_l)));
    } else {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign 
            = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_shifted_l) 
               & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_not_shifted_l));
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum 
            = (0x3fffU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__smaller_mantissa_l) 
                          + (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa_l)));
    }
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a = vlSelfRef.add_fp16_tb_full__DOT__tb_a;
    if ((IData)(((0U == (0x7c00U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a))) 
                 & (0U != (0x3ffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a)))))) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a 
            = (0x8000U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a));
    }
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b = 
        ((IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub)
          ? ((0x8000U & ((~ ((IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_b) 
                             >> 0xfU)) << 0xfU)) | 
             (0x7fffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_b)))
          : (IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_b));
    if ((IData)(((0U == (0x7c00U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b))) 
                 & (0U != (0x3ffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b)))))) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b 
            = (0x8000U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b));
    }
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_overflow 
        = (1U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                 >> 0xdU));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_nan_a 
        = (IData)(((0x7c00U == (0x7c00U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a))) 
                   & (0U != (0x3ffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a)))));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_nan_b 
        = (IData)(((0x7c00U == (0x7c00U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b))) 
                   & (0U != (0x3ffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b)))));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_inf_a 
        = (IData)((0x7c00U == (0x7fffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a))));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_inf_b 
        = (IData)((0x7c00U == (0x7fffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b))));
    if (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_nan_a) 
         | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_nan_b))) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case = 1U;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result 
            = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_nan_a)
                ? (0x200U | (0xfdffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a)))
                : (0x200U | (0xfdffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b))));
    } else if (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_inf_a) 
                & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_inf_b))) {
        if (((1U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a) 
                    >> 0xfU)) == (1U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b) 
                                        >> 0xfU)))) {
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case = 1U;
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result 
                = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a;
        } else {
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case = 1U;
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result = 0x7e00U;
        }
    } else if (vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_inf_a) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case = 1U;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a;
    } else if (vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_inf_b) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case = 1U;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b;
    }
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__op_swap 
        = ((0x1fU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a) 
                     >> 0xaU)) < (0x1fU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b) 
                                           >> 0xaU)));
    if (vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__op_swap) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__high_op 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__low_op 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a;
    } else {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__high_op 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__low_op 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b;
    }
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__high_exp 
        = (0x1fU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__high_op) 
                    >> 0xaU));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__low_exp 
        = (0x1fU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__low_op) 
                    >> 0xaU));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_diff 
        = (0x1fU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__high_exp) 
                    - (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__low_exp)));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_max 
        = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__high_exp;
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_hi 
        = (((IData)((0U != (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__high_exp))) 
            << 0xcU) | (0xffcU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__high_op) 
                                  << 2U)));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo 
        = (((IData)((0U != (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__low_exp))) 
            << 0xcU) | (0xffcU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__low_op) 
                                  << 2U)));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo_aligned = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sticky_align_local = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sticky_lost = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mask_align = 0U;
    if ((0xdU <= (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_diff))) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo_aligned = 0U;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sticky_lost = 0U;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo_aligned 
            = ((0x1ffeU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo_aligned)) 
               | (0U != (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo)));
    } else if ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_diff))) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo_aligned 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sticky_lost = 0U;
    } else {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo_aligned 
            = (0x1fffU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo) 
                          >> (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_diff)));
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mask_align 
            = (0x1fffU & (((IData)(1U) << (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_diff)) 
                          - (IData)(1U)));
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sticky_align_local 
            = (0U != ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo) 
                      & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mask_align)));
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sticky_lost 
            = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sticky_align_local) 
               & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo_aligned));
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo_aligned 
            = ((0x1ffeU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo_aligned)) 
               | (1U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo_aligned) 
                        | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sticky_align_local))));
    }
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_not_shifted 
        = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_hi;
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_shifted 
        = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo_aligned;
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_not_shifted 
        = (1U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__high_op) 
                 >> 0xfU));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_shifted 
        = (1U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__low_op) 
                 >> 0xfU));
    if (((((((((0x800U == (0x1800U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))) 
               | (0x400U == (0x1c00U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) 
              | (0x200U == (0x1e00U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) 
             | (0x100U == (0x1f00U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) 
            | (0x80U == (0x1f80U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) 
           | (0x40U == (0x1fc0U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) 
          | (0x20U == (0x1fe0U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) 
         | (0x10U == (0x1ff0U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))))) {
        if ((0x800U == (0x1800U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) {
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = 1U;
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1ffeU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                                         << 1U)));
        } else if ((0x400U == (0x1c00U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) {
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = 2U;
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1ffcU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                                         << 2U)));
        } else if ((0x200U == (0x1e00U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) {
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = 3U;
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1ff8U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                                         << 3U)));
        } else if ((0x100U == (0x1f00U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) {
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = 4U;
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1ff0U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                                         << 4U)));
        } else if ((0x80U == (0x1f80U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) {
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = 5U;
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1fe0U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                                         << 5U)));
        } else if ((0x40U == (0x1fc0U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) {
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = 6U;
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1fc0U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                                         << 6U)));
        } else if ((0x20U == (0x1fe0U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) {
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = 7U;
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1f80U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                                         << 7U)));
        } else {
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = 8U;
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1f00U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                                         << 8U)));
        }
    } else if ((8U == (0x1ff8U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = 9U;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum 
            = (0x1fffU & (0x1e00U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                                     << 9U)));
    } else if ((4U == (0x1ffcU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = 0xaU;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum 
            = (0x1fffU & (0x1c00U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                                     << 0xaU)));
    } else if ((2U == (0x1ffeU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = 0xbU;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum 
            = (0x1fffU & (0x1800U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                                     << 0xbU)));
    } else if ((1U == (0x1fffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = 0xcU;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum 
            = (0x1fffU & (0x1000U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                                     << 0xcU)));
    } else {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = 0U;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum 
            = (0x1fffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum));
    }
    if (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_shifted) 
         > (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_not_shifted))) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__smaller_mantissa 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_not_shifted;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_shifted;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa_sign 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_shifted;
    } else {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__smaller_mantissa 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_shifted;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_not_shifted;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa_sign 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_not_shifted;
    }
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sub_has_lost_sticky 
        = (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_shifted) 
            <= (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_not_shifted)) 
           && (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sticky_lost));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sub_has_added_sticky 
        = (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_shifted) 
            <= (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_not_shifted)) 
           && ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sticky_align_local) 
               & (~ (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sticky_lost))));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_norm_s 
        = ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum))
            ? 0U : (0x7fU & (VL_EXTENDS_II(7,6, (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_max_l)) 
                             - (0xfU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount)))));
    if (vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_overflow) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_this 
            = (0xfffU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                         >> 1U));
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_this 
            = ((0xffeU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_this)) 
               | (1U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_this) 
                        | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))));
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_base 
            = (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_max_l)));
    } else {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_this 
            = (0xfffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum));
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_base 
            = (0x3fU & (VL_GTES_III(7, 0U, (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_norm_s))
                         ? 0U : (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_norm_s)));
    }
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under 
        = ((1U & (~ (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_overflow))) 
           && VL_GTES_III(7, 0U, (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_norm_s)));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_inc 
        = ((1U & (~ (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__signs_differ_l) 
                      & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sub_has_lost_sticky_l)) 
                     & (2U == (3U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_this)))))) 
           && ((((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__signs_differ_l) 
                 & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sub_has_added_sticky_l)) 
                & (2U == (3U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_this)))) 
               || (1U & (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_this) 
                          >> 1U) & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_this) 
                                    | ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_this) 
                                       >> 2U))))));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_sum 
        = (0x7ffU & ((0x3ffU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_this) 
                                >> 2U)) + (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_inc)));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_carry 
        = (1U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_sum) 
                 >> 0xaU));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out 
        = (0x3fU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_base) 
                    + (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_carry)));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction 
        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_carry)
            ? 0U : (0x3ffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_sum)));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__overflow 
        = (0x1eU < (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out));
    if (vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__overflow) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final = 0x1fU;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final = 0U;
    } else {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final 
            = (0x1fU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out));
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction;
    }
}

VL_ATTR_COLD void Vadd_fp16_tb_full___024root___eval_triggers__stl(Vadd_fp16_tb_full___024root* vlSelf);

VL_ATTR_COLD bool Vadd_fp16_tb_full___024root___eval_phase__stl(Vadd_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root___eval_phase__stl\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vadd_fp16_tb_full___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vadd_fp16_tb_full___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_fp16_tb_full___024root___dump_triggers__act(Vadd_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root___dump_triggers__act\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge add_fp16_tb_full.tb_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge add_fp16_tb_full.tb_nrst)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(negedge add_fp16_tb_full.tb_clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_fp16_tb_full___024root___dump_triggers__nba(Vadd_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root___dump_triggers__nba\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge add_fp16_tb_full.tb_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge add_fp16_tb_full.tb_nrst)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(negedge add_fp16_tb_full.tb_clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vadd_fp16_tb_full___024root____Vm_traceActivitySetAll(Vadd_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root____Vm_traceActivitySetAll\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
}

VL_ATTR_COLD void Vadd_fp16_tb_full___024root___ctor_var_reset(Vadd_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root___ctor_var_reset\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->add_fp16_tb_full__DOT__tb_clk = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__tb_nrst = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__tb_a = VL_RAND_RESET_I(16);
    vlSelf->add_fp16_tb_full__DOT__tb_b = VL_RAND_RESET_I(16);
    vlSelf->add_fp16_tb_full__DOT__tb_start = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__tb_sub = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__tb_done = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__exp = VL_RAND_RESET_I(16);
    vlSelf->add_fp16_tb_full__DOT__pass_count = 0;
    vlSelf->add_fp16_tb_full__DOT__fail_count = 0;
    vlSelf->add_fp16_tb_full__DOT__fd = 0;
    vlSelf->add_fp16_tb_full__DOT__a = VL_RAND_RESET_I(16);
    vlSelf->add_fp16_tb_full__DOT__b = VL_RAND_RESET_I(16);
    vlSelf->add_fp16_tb_full__DOT__expected = VL_RAND_RESET_I(16);
    vlSelf->add_fp16_tb_full__DOT__unnamedblk1__DOT__ret = 0;
    vlSelf->add_fp16_tb_full__DOT__unnamedblk1__DOT__sub_flag = 0;
    vlSelf->add_fp16_tb_full__DOT__unnamedblk1__DOT__is_zero_result = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__a = VL_RAND_RESET_I(16);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__b = VL_RAND_RESET_I(16);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__is_nan_a = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__is_nan_b = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__is_inf_a = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__is_inf_b = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__special_case = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__special_result = VL_RAND_RESET_I(16);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__op_swap = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__high_op = VL_RAND_RESET_I(16);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__low_op = VL_RAND_RESET_I(16);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__high_exp = VL_RAND_RESET_I(5);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__low_exp = VL_RAND_RESET_I(5);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__mant_hi = VL_RAND_RESET_I(13);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__mant_lo = VL_RAND_RESET_I(13);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__mant_lo_aligned = VL_RAND_RESET_I(13);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__mask_align = VL_RAND_RESET_I(13);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__sticky_align_local = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__sticky_lost = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__exp_diff = VL_RAND_RESET_I(5);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__exp_max = VL_RAND_RESET_I(5);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__frac_shifted = VL_RAND_RESET_I(13);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__frac_not_shifted = VL_RAND_RESET_I(13);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__sign_shifted = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__sign_not_shifted = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__smaller_mantissa = VL_RAND_RESET_I(13);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__larger_mantissa = VL_RAND_RESET_I(13);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__mantissa_sum = VL_RAND_RESET_I(14);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__larger_mantissa_sign = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__result_sign = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__mantissa_overflow = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__sub_has_lost_sticky = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__sub_has_added_sticky = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__smaller_mantissa_l = VL_RAND_RESET_I(13);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__larger_mantissa_l = VL_RAND_RESET_I(13);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__larger_mantissa_sign_l = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__sign_shifted_l = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__sign_not_shifted_l = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__signs_differ_l = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__exp_max_l = VL_RAND_RESET_I(5);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__special_case_l = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__special_result_l = VL_RAND_RESET_I(16);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__sub_has_lost_sticky_l = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__sub_has_added_sticky_l = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum = VL_RAND_RESET_I(13);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = VL_RAND_RESET_I(5);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__exp_norm_s = VL_RAND_RESET_I(7);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__round_this = VL_RAND_RESET_I(12);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__exp_base = VL_RAND_RESET_I(6);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__ftz_under = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__round_inc = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__frac_sum = VL_RAND_RESET_I(11);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__frac_carry = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__exp_out = VL_RAND_RESET_I(6);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__rounded_fraction = VL_RAND_RESET_I(10);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__overflow = VL_RAND_RESET_I(1);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__exp_out_final = VL_RAND_RESET_I(5);
    vlSelf->add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final = VL_RAND_RESET_I(10);
    vlSelf->__Vtrigprevexpr___TOP__add_fp16_tb_full__DOT__tb_clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__add_fp16_tb_full__DOT__tb_nrst__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
