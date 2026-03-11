// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaddn_fp32accum_fp16_tb_softfloat.h for the primary calling header

#include "Vaddn_fp32accum_fp16_tb_softfloat__pch.h"
#include "Vaddn_fp32accum_fp16_tb_softfloat___024root.h"

VlCoroutine Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__0(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf);
VlCoroutine Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__1(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf);

void Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_initial(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_initial\n"); );
    Vaddn_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__1(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vaddn_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_clk = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                             nullptr, 
                                             "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                             30);
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_clk = 1U;
        co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                             nullptr, 
                                             "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                             32);
    }
}

void Vaddn_fp32accum_fp16_tb_softfloat___024root___act_comb__TOP__0(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf);

void Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_act(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_act\n"); );
    Vaddn_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0xcULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vaddn_fp32accum_fp16_tb_softfloat___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void Vaddn_fp32accum_fp16_tb_softfloat___024root___act_comb__TOP__0(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32accum_fp16_tb_softfloat___024root___act_comb__TOP__0\n"); );
    Vaddn_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__is_nan_any = 0U;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_pos_inf = 0U;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_neg_inf = 0U;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[0U] 
        = (0xffffU & ((0U == (0x1fU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                               >> 0xaU))))
                       ? (0x8000U & ((IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                              >> 0xfU)) 
                                     << 0xfU)) : (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[0U] 
        = (1U & (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
                 [0U] >> 0xfU));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[0U] 
        = (0x1fU & (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
                    [0U] >> 0xaU));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[0U] 
        = (0x3ffU & vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
           [0U]);
    if (((0x1fU == vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
          [0U]) & (0U != vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                   [0U]))) {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__is_nan_any = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
           [0U]) & (~ vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
                    [0U])) & (~ (IData)((0U != vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                                         [0U]))))) {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_pos_inf = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
           [0U]) & vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
          [0U]) & (~ (IData)((0U != vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                              [0U]))))) {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_neg_inf = 1U;
    }
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[1U] 
        = (0xffffU & ((0U == (0x1fU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                               >> 0x1aU))))
                       ? (0x8000U & ((IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                              >> 0x1fU)) 
                                     << 0xfU)) : (IData)(
                                                         (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                                          >> 0x10U))));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[1U] 
        = (1U & (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
                 [1U] >> 0xfU));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[1U] 
        = (0x1fU & (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
                    [1U] >> 0xaU));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[1U] 
        = (0x3ffU & vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
           [1U]);
    if (((0x1fU == vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
          [1U]) & (0U != vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                   [1U]))) {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__is_nan_any = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
           [1U]) & (~ vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
                    [1U])) & (~ (IData)((0U != vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                                         [1U]))))) {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_pos_inf = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
           [1U]) & vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
          [1U]) & (~ (IData)((0U != vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                              [1U]))))) {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_neg_inf = 1U;
    }
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[2U] 
        = (0xffffU & ((0U == (0x1fU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                               >> 0x2aU))))
                       ? (0x8000U & ((IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                              >> 0x2fU)) 
                                     << 0xfU)) : (IData)(
                                                         (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                                          >> 0x20U))));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[2U] 
        = (1U & (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
                 [2U] >> 0xfU));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[2U] 
        = (0x1fU & (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
                    [2U] >> 0xaU));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[2U] 
        = (0x3ffU & vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
           [2U]);
    if (((0x1fU == vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
          [2U]) & (0U != vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                   [2U]))) {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__is_nan_any = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
           [2U]) & (~ vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
                    [2U])) & (~ (IData)((0U != vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                                         [2U]))))) {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_pos_inf = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
           [2U]) & vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
          [2U]) & (~ (IData)((0U != vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                              [2U]))))) {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_neg_inf = 1U;
    }
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[3U] 
        = (0xffffU & ((0U == (0x1fU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                               >> 0x3aU))))
                       ? (0x8000U & ((IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                              >> 0x3fU)) 
                                     << 0xfU)) : (IData)(
                                                         (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                                          >> 0x30U))));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[3U] 
        = (1U & (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
                 [3U] >> 0xfU));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[3U] 
        = (0x1fU & (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
                    [3U] >> 0xaU));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[3U] 
        = (0x3ffU & vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in
           [3U]);
    if (((0x1fU == vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
          [3U]) & (0U != vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                   [3U]))) {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__is_nan_any = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
           [3U]) & (~ vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
                    [3U])) & (~ (IData)((0U != vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                                         [3U]))))) {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_pos_inf = 1U;
    }
    if ((((0x1fU == vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
           [3U]) & vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
          [3U]) & (~ (IData)((0U != vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                              [3U]))))) {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_neg_inf = 1U;
    }
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[0U][0U] 
        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
        [0U];
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[0U][0U] = 0U;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[0U][1U] 
        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
        [1U];
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[0U][1U] = 1U;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[0U][2U] 
        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
        [2U];
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[0U][2U] = 2U;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[0U][3U] 
        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
        [3U];
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[0U][3U] = 3U;
    if ((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
         [0U][0U] >= vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
         [0U][1U])) {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h0bb7bd8f__0 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
            [0U][0U];
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h00fc99f2__0 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
            [0U][0U];
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[1U][0U] 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h0bb7bd8f__0;
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[1U][0U] 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h00fc99f2__0;
    } else {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h0bb7bd8f__1 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
            [0U][1U];
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h00fc99f2__1 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
            [0U][1U];
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[1U][0U] 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h0bb7bd8f__1;
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[1U][0U] 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h00fc99f2__1;
    }
    if ((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
         [0U][2U] >= vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
         [0U][3U])) {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h0bb7bd8f__0 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
            [0U][2U];
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h00fc99f2__0 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
            [0U][2U];
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[1U][1U] 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h0bb7bd8f__0;
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[1U][1U] 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h00fc99f2__0;
    } else {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h0bb7bd8f__1 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
            [0U][3U];
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h00fc99f2__1 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
            [0U][3U];
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[1U][1U] 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h0bb7bd8f__1;
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[1U][1U] 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h00fc99f2__1;
    }
    if ((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
         [1U][0U] >= vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
         [1U][1U])) {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h0bb7bd8f__0 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
            [1U][0U];
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h00fc99f2__0 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
            [1U][0U];
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[2U][0U] 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h0bb7bd8f__0;
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[2U][0U] 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h00fc99f2__0;
    } else {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h0bb7bd8f__1 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
            [1U][1U];
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h00fc99f2__1 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
            [1U][1U];
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp[2U][0U] 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h0bb7bd8f__1;
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx[2U][0U] 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT____Vlvbound_h00fc99f2__1;
    }
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp 
        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
        [2U][0U];
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx 
        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
        [2U][0U];
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_max 
        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
        [vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx];
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_case = 0U;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_neg_inf)))) {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_case = 1U;
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_pos_inf) {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_case = 1U;
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_neg_inf) {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_case = 1U;
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_result = 0xff800000U;
    }
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp_eff 
        = ((0U == (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp))
            ? 1U : (0x1fU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp)));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[0U] 
        = (((IData)((0U != vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                     [0U])) << 0x18U) | (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                                         [0U] << 0xeU));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[0U] 
        = (0x3fU & ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp_eff) 
                    - ((0U == vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                        [0U]) ? 1U : vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                       [0U])));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[0U] 
        = (0U != (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base
                  [0U] & (~ VL_SHIFTL_III(25,25,6, (IData)(0x1ffffffU), 
                                          vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
                                          [0U]))));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[0U] 
        = ((0x19U <= vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
            [0U]) ? 0U : (0x1ffffffU & VL_SHIFTR_III(32,32,6, 
                                                     vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base
                                                     [0U], 
                                                     vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
                                                     [0U])));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[0U] 
        = ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_max) 
           ^ vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
           [0U]);
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[0U] 
        = (0xfffffffU & ((0U == (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx))
                          ? vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                         [0U] : (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff
                                 [0U] ? (~ vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                                         [0U]) : vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                                 [0U])));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[1U] 
        = (((IData)((0U != vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                     [1U])) << 0x18U) | (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                                         [1U] << 0xeU));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[1U] 
        = (0x3fU & ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp_eff) 
                    - ((0U == vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                        [1U]) ? 1U : vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                       [1U])));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[1U] 
        = (0U != (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base
                  [1U] & (~ VL_SHIFTL_III(25,25,6, (IData)(0x1ffffffU), 
                                          vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
                                          [1U]))));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[1U] 
        = ((0x19U <= vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
            [1U]) ? 0U : (0x1ffffffU & VL_SHIFTR_III(32,32,6, 
                                                     vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base
                                                     [1U], 
                                                     vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
                                                     [1U])));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[1U] 
        = ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_max) 
           ^ vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
           [1U]);
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[1U] 
        = (0xfffffffU & ((1U == (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx))
                          ? vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                         [1U] : (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff
                                 [1U] ? (~ vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                                         [1U]) : vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                                 [1U])));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[2U] 
        = (((IData)((0U != vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                     [2U])) << 0x18U) | (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                                         [2U] << 0xeU));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[2U] 
        = (0x3fU & ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp_eff) 
                    - ((0U == vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                        [2U]) ? 1U : vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                       [2U])));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[2U] 
        = (0U != (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base
                  [2U] & (~ VL_SHIFTL_III(25,25,6, (IData)(0x1ffffffU), 
                                          vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
                                          [2U]))));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[2U] 
        = ((0x19U <= vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
            [2U]) ? 0U : (0x1ffffffU & VL_SHIFTR_III(32,32,6, 
                                                     vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base
                                                     [2U], 
                                                     vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
                                                     [2U])));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[2U] 
        = ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_max) 
           ^ vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
           [2U]);
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[2U] 
        = (0xfffffffU & ((2U == (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx))
                          ? vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                         [2U] : (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff
                                 [2U] ? (~ vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                                         [2U]) : vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                                 [2U])));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[3U] 
        = (((IData)((0U != vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                     [3U])) << 0x18U) | (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac
                                         [3U] << 0xeU));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[3U] 
        = (0x3fU & ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp_eff) 
                    - ((0U == vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                        [3U]) ? 1U : vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp
                       [3U])));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[3U] 
        = (0U != (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base
                  [3U] & (~ VL_SHIFTL_III(25,25,6, (IData)(0x1ffffffU), 
                                          vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
                                          [3U]))));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[3U] 
        = ((0x19U <= vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
            [3U]) ? 0U : (0x1ffffffU & VL_SHIFTR_III(32,32,6, 
                                                     vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base
                                                     [3U], 
                                                     vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift
                                                     [3U])));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[3U] 
        = ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_max) 
           ^ vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign
           [3U]);
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[3U] 
        = (0xfffffffU & ((3U == (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx))
                          ? vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                         [3U] : (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff
                                 [3U] ? (~ vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                                         [3U]) : vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant
                                 [3U])));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[0U] 
        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
        [0U];
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[0U] = 0U;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[1U] 
        = (0xfffffffU & ((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
                          [0U] ^ VL_SHIFTL_III(28,28,32, 
                                               vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                               [0U], 1U)) 
                         ^ vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                         [1U]));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[1U] 
        = (((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
             [0U] & VL_SHIFTL_III(28,28,32, vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                  [0U], 1U)) | (VL_SHIFTL_III(28,28,32, 
                                                              vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                                              [0U], 1U) 
                                                & vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                                                [1U])) 
           | (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
              [1U] & vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
              [0U]));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[2U] 
        = (0xfffffffU & ((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
                          [1U] ^ VL_SHIFTL_III(28,28,32, 
                                               vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                               [1U], 1U)) 
                         ^ vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                         [2U]));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[2U] 
        = (((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
             [1U] & VL_SHIFTL_III(28,28,32, vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                  [1U], 1U)) | (VL_SHIFTL_III(28,28,32, 
                                                              vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                                              [1U], 1U) 
                                                & vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                                                [2U])) 
           | (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
              [2U] & vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
              [1U]));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[3U] 
        = (0xfffffffU & ((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
                          [2U] ^ VL_SHIFTL_III(28,28,32, 
                                               vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                               [2U], 1U)) 
                         ^ vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                         [3U]));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[3U] 
        = (((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
             [2U] & VL_SHIFTL_III(28,28,32, vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                  [2U], 1U)) | (VL_SHIFTL_III(28,28,32, 
                                                              vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
                                                              [2U], 1U) 
                                                & vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
                                                [3U])) 
           | (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op
              [3U] & vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
              [2U]));
}

void Vaddn_fp32accum_fp16_tb_softfloat___024root___nba_sequent__TOP__0(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf);

void Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_nba(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_nba\n"); );
    Vaddn_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vaddn_fp32accum_fp16_tb_softfloat___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((0xcULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vaddn_fp32accum_fp16_tb_softfloat___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
}

VL_INLINE_OPT void Vaddn_fp32accum_fp16_tb_softfloat___024root___nba_sequent__TOP__0(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32accum_fp16_tb_softfloat___024root___nba_sequent__TOP__0\n"); );
    Vaddn_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vdly__addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_align_sticky;
    __Vdly__addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_align_sticky = 0;
    CData/*2:0*/ __Vdly__addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_hot_ones;
    __Vdly__addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_hot_ones = 0;
    // Body
    __Vdly__addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_align_sticky 
        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_align_sticky;
    __Vdly__addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_hot_ones 
        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_hot_ones;
    if (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_nrst) {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__unnamedblk7__DOT__i = 4U;
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__unnamedblk8__DOT__i = 4U;
        __Vdly__addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_align_sticky = 0U;
        if ((0U != (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx))) {
            __Vdly__addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_align_sticky 
                = ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_align_sticky) 
                   | vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky
                   [0U]);
        }
        if ((1U != (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx))) {
            __Vdly__addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_align_sticky 
                = ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_align_sticky) 
                   | vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky
                   [1U]);
        }
        if ((2U != (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx))) {
            __Vdly__addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_align_sticky 
                = ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_align_sticky) 
                   | vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky
                   [2U]);
        }
        if ((3U != (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx))) {
            __Vdly__addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_align_sticky 
                = ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_align_sticky) 
                   | vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky
                   [3U]);
        }
        __Vdly__addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_hot_ones = 0U;
        if (((0U != (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx)) 
             & vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff
             [0U])) {
            __Vdly__addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_hot_ones 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_hot_ones)));
        }
        if (((1U != (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx)) 
             & vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff
             [1U])) {
            __Vdly__addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_hot_ones 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_hot_ones)));
        }
        if (((2U != (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx)) 
             & vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff
             [2U])) {
            __Vdly__addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_hot_ones 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_hot_ones)));
        }
        if (((3U != (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx)) 
             & vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff
             [3U])) {
            __Vdly__addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_hot_ones 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_hot_ones)));
        }
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__result_out;
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sum_mag 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mag_sum;
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_carry_vec 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c
            [3U];
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_sum_vec 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s
            [3U];
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_exp_base 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_a_e;
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_spec_res 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_special_result;
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_a_e 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp;
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_special_result 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_result;
    } else {
        __Vdly__addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_align_sticky = 0U;
        __Vdly__addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_hot_ones = 0U;
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out = 0U;
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sum_mag = 0U;
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_carry_vec = 0U;
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_sum_vec = 0U;
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_exp_base = 0U;
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_spec_res = 0U;
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_a_e = 0U;
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_special_result = 0U;
    }
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sticky 
        = ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_align_sticky));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__res_sign));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_a_s 
        = ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_max));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_special 
        = ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_special_case));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_hot_ones 
        = __Vdly__addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_hot_ones;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_align_sticky 
        = __Vdly__addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_align_sticky;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__guard 
        = (1U & (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
                 >> 0xcU));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rnd 
        = (1U & (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
                 >> 0xbU));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__sticky 
        = (0U != (0x7ffU & vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__round_up 
        = ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__guard) 
           & (((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rnd) 
               | (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__sticky)) 
              | (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
                 >> 0xdU)));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded 
        = (0x7ffU & ((0x3ffU & (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
                                >> 0xdU)) + (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__round_up)));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp 
        = (0x3ffU & ((VL_EXTENDS_II(10,10, (0xffU & 
                                            (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
                                             >> 0x17U))) 
                      - (IData)(0x70U)) + VL_EXTENDS_II(10,10, 
                                                        (1U 
                                                         & ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded) 
                                                            >> 0xaU)))));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result 
        = ((0xffU == (0xffU & (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
                               >> 0x17U))) ? (0x7c00U 
                                              | ((0x8000U 
                                                  & (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
                                                     >> 0x10U)) 
                                                 | ((0U 
                                                     != 
                                                     (0x7fffffU 
                                                      & vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out))
                                                     ? 0x200U
                                                     : 0U)))
            : (VL_LTES_III(10, 0x1fU, (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp))
                ? (0x7c00U | (0x8000U & (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
                                         >> 0x10U)))
                : (VL_GTES_III(32, 0U, VL_EXTENDS_II(32,10, (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp)))
                    ? (0x8000U & (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
                                  >> 0x10U)) : ((0x8000U 
                                                 & (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
                                                    >> 0x10U)) 
                                                | ((0x7c00U 
                                                    & ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp) 
                                                       << 0xaU)) 
                                                   | ((0x400U 
                                                       & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded))
                                                       ? 0U
                                                       : 
                                                      (0x3ffU 
                                                       & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded))))))));
    if ((0U != vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sum_mag)) {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__stage3_logic__DOT__unnamedblk9__DOT__i = 0xffffffffU;
    }
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__raw_sum 
        = (0x1fffffffU & (((0x3fffffffU & VL_EXTENDS_II(30,29, vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_sum_vec)) 
                           + (0x3fffffffU & VL_EXTENDS_II(30,28, 
                                                          (0xfffffffU 
                                                           & VL_SHIFTL_III(28,28,32, vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_carry_vec, 1U))))) 
                          + (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_hot_ones)));
    if ((0x8000000U & vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__raw_sum)) {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mag_sum 
            = (0x7ffffffU & ((IData)(1U) + (~ vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__raw_sum)));
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_a_s)));
    } else {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mag_sum 
            = (0x7ffffffU & vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__raw_sum);
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__res_sign 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_a_s;
    }
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_special_case 
        = ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_case));
    if ((0U == vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sum_mag)) {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan = 0U;
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros = 0x1aU;
    } else {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sum_mag;
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros = 0U;
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan, 0xbU))) {
            vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros 
                = (0x3fU & ((IData)(0x10U) + (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros)));
            vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan 
                = (0x7ffffffU & VL_SHIFTL_III(27,27,32, vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan, 0x10U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan, 0x13U))) {
            vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros 
                = (0x3fU & ((IData)(8U) + (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros)));
            vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan 
                = (0x7ffffffU & VL_SHIFTL_III(27,27,32, vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan, 8U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan, 0x17U))) {
            vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros 
                = (0x3fU & ((IData)(4U) + (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros)));
            vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan 
                = (0x7ffffffU & VL_SHIFTL_III(27,27,32, vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan, 4U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan, 0x19U))) {
            vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros 
                = (0x3fU & ((IData)(2U) + (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros)));
            vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan 
                = (0x7ffffffU & VL_SHIFTL_III(27,27,32, vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan, 2U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan, 0x1aU))) {
            vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros 
                = (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros)));
            vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan 
                = (0x7ffffffU & VL_SHIFTL_III(27,27,32, vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan, 1U));
        }
    }
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__norm_val 
        = (0x7ffffffU & VL_SHIFTL_III(27,27,6, vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sum_mag, (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros)));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__final_mant 
        = (0x7fffffU & (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__norm_val 
                        >> 3U));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__final_exp_calc 
        = (0x7ffU & ((IData)(0x70U) + (((IData)(2U) 
                                        + VL_EXTENDS_II(11,7, (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_exp_base))) 
                                       - VL_EXTENDS_II(11,8, (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros)))));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__result_out 
        = ((((0U == vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sum_mag) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_exp_base)))
            ? 0U : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__final_exp_calc)))
                     ? (0x7f800000U | ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_res_sign) 
                                       << 0x1fU)) : 
                    (((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_res_sign) 
                      << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__final_exp_calc) 
                                                   << 0x17U)) 
                                   | vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__final_mant))));
    if (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_special) {
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__result_out 
            = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_spec_res;
    }
}

void Vaddn_fp32accum_fp16_tb_softfloat___024root___timing_resume(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32accum_fp16_tb_softfloat___024root___timing_resume\n"); );
    Vaddn_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h3cf440f3__0.resume(
                                                   "@(negedge addn_fp32accum_fp16_tb_softfloat.tb_clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vaddn_fp32accum_fp16_tb_softfloat___024root___timing_commit(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32accum_fp16_tb_softfloat___024root___timing_commit\n"); );
    Vaddn_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (8ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h3cf440f3__0.commit(
                                                   "@(negedge addn_fp32accum_fp16_tb_softfloat.tb_clk)");
    }
}

void Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_triggers__act(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf);

bool Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_phase__act(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_phase__act\n"); );
    Vaddn_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_triggers__act(vlSelf);
    Vaddn_fp32accum_fp16_tb_softfloat___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vaddn_fp32accum_fp16_tb_softfloat___024root___timing_resume(vlSelf);
        Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_phase__nba(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_phase__nba\n"); );
    Vaddn_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddn_fp32accum_fp16_tb_softfloat___024root___dump_triggers__nba(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddn_fp32accum_fp16_tb_softfloat___024root___dump_triggers__act(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG

void Vaddn_fp32accum_fp16_tb_softfloat___024root___eval(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32accum_fp16_tb_softfloat___024root___eval\n"); );
    Vaddn_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vaddn_fp32accum_fp16_tb_softfloat___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 14, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vaddn_fp32accum_fp16_tb_softfloat___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 14, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_debug_assertions(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_debug_assertions\n"); );
    Vaddn_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
