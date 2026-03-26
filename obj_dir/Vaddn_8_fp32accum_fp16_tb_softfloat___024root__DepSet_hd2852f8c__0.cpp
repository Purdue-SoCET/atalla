// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaddn_8_fp32accum_fp16_tb_softfloat.h for the primary calling header

#include "Vaddn_8_fp32accum_fp16_tb_softfloat__pch.h"
#include "Vaddn_8_fp32accum_fp16_tb_softfloat___024root.h"

VlCoroutine Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__0(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf);
VlCoroutine Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__1(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf);

void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_initial(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_initial\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__1(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_clk = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                             nullptr, 
                                             "tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv", 
                                             28);
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_clk = 1U;
        co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                             nullptr, 
                                             "tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv", 
                                             30);
    }
}

void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___act_comb__TOP__0(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf);

void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_act(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_act\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0xcULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vaddn_8_fp32accum_fp16_tb_softfloat___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___act_comb__TOP__0(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___act_comb__TOP__0\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
}

void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___nba_sequent__TOP__0(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf);

void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_nba(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_nba\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vaddn_8_fp32accum_fp16_tb_softfloat___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((0xcULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vaddn_8_fp32accum_fp16_tb_softfloat___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
}

VL_INLINE_OPT void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___nba_sequent__TOP__0(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___nba_sequent__TOP__0\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v0;
    __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v0 = 0;
    CData/*0:0*/ __VdlySet__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v0;
    __VdlySet__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v0 = 0;
    SData/*15:0*/ __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v1;
    __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v1 = 0;
    SData/*15:0*/ __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v2;
    __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v2 = 0;
    SData/*15:0*/ __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v3;
    __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v3 = 0;
    SData/*15:0*/ __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v4;
    __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v4 = 0;
    SData/*15:0*/ __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v5;
    __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v5 = 0;
    SData/*15:0*/ __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v6;
    __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v6 = 0;
    SData/*15:0*/ __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v7;
    __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v7 = 0;
    CData/*0:0*/ __VdlySet__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v8;
    __VdlySet__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v8 = 0;
    // Body
    __VdlySet__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v0 = 0U;
    __VdlySet__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v8 = 0U;
    if ((1U & (~ (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst)))) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__unnamedblk4__DOT__i = 8U;
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_sticky 
        = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_sticky));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sign_max 
        = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst) 
           && (1U & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data
                     [vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_idx] 
                     >> 0xfU)));
    if (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__unnamedblk5__DOT__i = 8U;
        __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v0 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
            [0U];
        __VdlySet__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v0 = 1U;
        __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v1 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
            [1U];
        __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v2 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
            [2U];
        __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v3 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
            [3U];
        __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v4 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
            [4U];
        __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v5 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
            [5U];
        __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v6 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
            [6U];
        __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v7 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data
            [7U];
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sum_vec 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s4_0;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_carry_vec 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c4_0;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_hot_ones 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_hot_ones;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_exp 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_exp;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
            = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_spec_case)
                ? vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_spec_res
                : (((0U == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_mag) 
                    | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_e_final))))
                    ? 0U : (VL_LTES_III(32, 0xffU, 
                                        VL_EXTENDS_II(32,11, (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_e_final)))
                             ? (0x7f800000U | ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_sign) 
                                               << 0x1fU))
                             : (((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_sign) 
                                 << 0x1fU) | ((0x7f800000U 
                                               & ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_e_final) 
                                                  << 0x17U)) 
                                              | (0x7fffffU 
                                                 & (VL_SHIFTL_III(29,29,6, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_mag, (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_lzd)) 
                                                    >> 5U)))))));
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_idx 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_max_idx;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_exp 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_exp;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_lzd 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_lzd;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_mag 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_mag_sum;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_spec_res 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_spec_res;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_exp 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_exp;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_mag_sum 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_mag_sum;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_spec_res 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_spec_res;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_exp 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_max_exp;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_spec_res 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_spec_res;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_spec_res 
            = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_spec_res;
    } else {
        __VdlySet__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v8 = 1U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sum_vec = 0U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_carry_vec = 0U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_hot_ones = 0U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_exp = 0U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out = 0U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_idx = 0U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_exp = 0U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_lzd = 0U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_mag = 0U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_spec_res = 0U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_exp = 0U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_mag_sum = 0U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_spec_res = 0U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_exp = 0U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_spec_res = 0U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_spec_res = 0U;
    }
    if (__VdlySet__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v0) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data[0U] 
            = __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v0;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data[1U] 
            = __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v1;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data[2U] 
            = __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v2;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data[3U] 
            = __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v3;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data[4U] 
            = __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v4;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data[5U] 
            = __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v5;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data[6U] 
            = __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v6;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data[7U] 
            = __VdlyVal__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v7;
    }
    if (__VdlySet__addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data__v8) {
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data[0U] = 0U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data[1U] = 0U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data[2U] = 0U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data[3U] = 0U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data[4U] = 0U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data[5U] = 0U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data[6U] = 0U;
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data[7U] = 0U;
    }
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_sticky 
        = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sticky));
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
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_sign 
        = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_res_sign));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_spec_case 
        = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_spec_case));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sticky 
        = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_sticky));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_e_final 
        = (0x7ffU & ((IData)(0x70U) + (((IData)(4U) 
                                        + VL_EXTENDS_II(11,7, (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_exp))) 
                                       - VL_EXTENDS_II(11,8, (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_lzd)))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_res_sign 
        = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_res_sign));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_spec_case 
        = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_spec_case));
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
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_spec_case 
        = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_spec_case));
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
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_spec_case 
        = ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_spec_case));
}

void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___timing_resume(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___timing_resume\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h1382584b__0.resume(
                                                   "@(negedge addn_8_fp32accum_fp16_tb_softfloat.tb_clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___timing_commit(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___timing_commit\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (8ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h1382584b__0.commit(
                                                   "@(negedge addn_8_fp32accum_fp16_tb_softfloat.tb_clk)");
    }
}

void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_triggers__act(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf);

bool Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_phase__act(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_phase__act\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_triggers__act(vlSelf);
    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vaddn_8_fp32accum_fp16_tb_softfloat___024root___timing_resume(vlSelf);
        Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_phase__nba(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_phase__nba\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___dump_triggers__nba(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___dump_triggers__act(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG

void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vaddn_8_fp32accum_fp16_tb_softfloat___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv", 12, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vaddn_8_fp32accum_fp16_tb_softfloat___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv", 12, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_debug_assertions(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_debug_assertions\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
