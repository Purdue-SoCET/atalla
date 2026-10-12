// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd_bf16_tb.h for the primary calling header

#include "Vadd_bf16_tb__pch.h"
#include "Vadd_bf16_tb___024root.h"

VlCoroutine Vadd_bf16_tb___024root___eval_initial__TOP__Vtiming__0(Vadd_bf16_tb___024root* vlSelf);
VlCoroutine Vadd_bf16_tb___024root___eval_initial__TOP__Vtiming__1(Vadd_bf16_tb___024root* vlSelf);

void Vadd_bf16_tb___024root___eval_initial(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___eval_initial\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vadd_bf16_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vadd_bf16_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vadd_bf16_tb___024root___eval_initial__TOP__Vtiming__1(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        vlSelfRef.add_bf16_tb__DOT__tb_clk = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x1f4ULL, 
                                             nullptr, 
                                             "systolic_array_utils/add_bf16_tb.sv", 
                                             9);
        vlSelfRef.add_bf16_tb__DOT__tb_clk = 1U;
        co_await vlSelfRef.__VdlySched.delay(0x1f4ULL, 
                                             nullptr, 
                                             "systolic_array_utils/add_bf16_tb.sv", 
                                             10);
    }
}

void Vadd_bf16_tb___024root___act_comb__TOP__0(Vadd_bf16_tb___024root* vlSelf);

void Vadd_bf16_tb___024root___eval_act(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___eval_act\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0xdULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadd_bf16_tb___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void Vadd_bf16_tb___024root___act_comb__TOP__0(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___act_comb__TOP__0\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff = 
        ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_sub)
          ? ((0x8000U & ((~ ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_b) 
                             >> 0xfU)) << 0xfU)) | 
             (0x7fffU & (IData)(vlSelfRef.add_bf16_tb__DOT__tb_b)))
          : (IData)(vlSelfRef.add_bf16_tb__DOT__tb_b));
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__xor_out 
        = (0x1ffU & (((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                      ^ (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff)) 
                     >> 7U));
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__result_sign 
        = ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__signs_differ_l)
            ? (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa_sign_l)
            : ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_shifted_l) 
               & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_not_shifted_l)));
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

void Vadd_bf16_tb___024root___nba_sequent__TOP__0(Vadd_bf16_tb___024root* vlSelf);
void Vadd_bf16_tb___024root___nba_comb__TOP__0(Vadd_bf16_tb___024root* vlSelf);
void Vadd_bf16_tb___024root___nba_comb__TOP__1(Vadd_bf16_tb___024root* vlSelf);

void Vadd_bf16_tb___024root___eval_nba(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___eval_nba\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadd_bf16_tb___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((0xdULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadd_bf16_tb___024root___nba_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
    if ((0xfULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadd_bf16_tb___024root___nba_comb__TOP__1(vlSelf);
    }
}

extern const VlUnpacked<SData/*8:0*/, 1024> Vadd_bf16_tb__ConstPool__TABLE_h5713a960_0;
extern const VlUnpacked<CData/*3:0*/, 1024> Vadd_bf16_tb__ConstPool__TABLE_hb30919e0_0;

VL_INLINE_OPT void Vadd_bf16_tb___024root___nba_sequent__TOP__0(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___nba_sequent__TOP__0\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*9:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa_sign_l 
        = ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa_sign));
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_not_shifted_l 
        = ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_not_shifted));
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_shifted_l 
        = ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_shifted));
    if (vlSelfRef.add_bf16_tb__DOT__tb_nrst) {
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_max_l 
            = vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_max;
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__smaller_mantissa_l 
            = vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__smaller_mantissa;
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa_l 
            = vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa;
    } else {
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_max_l = 0U;
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__smaller_mantissa_l = 0U;
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa_l = 0U;
    }
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__signs_differ_l 
        = ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_nrst) 
           && ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_shifted) 
               ^ (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_not_shifted)));
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__mantissa_sum 
        = (0x7ffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__signs_differ_l)
                      ? ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa_l) 
                         - (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__smaller_mantissa_l))
                      : ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__smaller_mantissa_l) 
                         + (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa_l))));
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__mantissa_overflow 
        = (1U & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__mantissa_sum) 
                 >> 0xaU));
    __Vtableidx1 = (0x3ffU & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__mantissa_sum));
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__normalized_mantissa_sum 
        = Vadd_bf16_tb__ConstPool__TABLE_h5713a960_0
        [__Vtableidx1];
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__norm_shift 
        = Vadd_bf16_tb__ConstPool__TABLE_hb30919e0_0
        [__Vtableidx1];
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
}

VL_INLINE_OPT void Vadd_bf16_tb___024root___nba_comb__TOP__0(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___nba_comb__TOP__0\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff = 
        ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_sub)
          ? ((0x8000U & ((~ ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_b) 
                             >> 0xfU)) << 0xfU)) | 
             (0x7fffU & (IData)(vlSelfRef.add_bf16_tb__DOT__tb_b)))
          : (IData)(vlSelfRef.add_bf16_tb__DOT__tb_b));
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__xor_out 
        = (0x1ffU & (((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                      ^ (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff)) 
                     >> 7U));
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
}

VL_INLINE_OPT void Vadd_bf16_tb___024root___nba_comb__TOP__1(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___nba_comb__TOP__1\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__result_sign 
        = ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__signs_differ_l)
            ? (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa_sign_l)
            : ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_shifted_l) 
               & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_not_shifted_l)));
    if ((1U & ((~ (IData)((0U != (0x7fffU & (IData)(vlSelfRef.add_bf16_tb__DOT__tb_a))))) 
               & (~ (IData)((0U != (3U & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff)))))))) {
        vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__result_sign 
            = (1U & (((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                      & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff)) 
                     >> 0xfU));
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

void Vadd_bf16_tb___024root___timing_resume(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___timing_resume\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hf547ea9c__0.resume(
                                                   "@(negedge add_bf16_tb.tb_clk)");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hf547eadd__0.resume(
                                                   "@(posedge add_bf16_tb.tb_clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vadd_bf16_tb___024root___timing_commit(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___timing_commit\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (8ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hf547ea9c__0.commit(
                                                   "@(negedge add_bf16_tb.tb_clk)");
    }
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hf547eadd__0.commit(
                                                   "@(posedge add_bf16_tb.tb_clk)");
    }
}

void Vadd_bf16_tb___024root___eval_triggers__act(Vadd_bf16_tb___024root* vlSelf);

bool Vadd_bf16_tb___024root___eval_phase__act(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___eval_phase__act\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vadd_bf16_tb___024root___eval_triggers__act(vlSelf);
    Vadd_bf16_tb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vadd_bf16_tb___024root___timing_resume(vlSelf);
        Vadd_bf16_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vadd_bf16_tb___024root___eval_phase__nba(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___eval_phase__nba\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vadd_bf16_tb___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_bf16_tb___024root___dump_triggers__nba(Vadd_bf16_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_bf16_tb___024root___dump_triggers__act(Vadd_bf16_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vadd_bf16_tb___024root___eval(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___eval\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vadd_bf16_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("systolic_array_utils/add_bf16_tb.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vadd_bf16_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("systolic_array_utils/add_bf16_tb.sv", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vadd_bf16_tb___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vadd_bf16_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vadd_bf16_tb___024root___eval_debug_assertions(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___eval_debug_assertions\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
