// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsysarr_16_input_fp_adder.h for the primary calling header

#include "Vsysarr_16_input_fp_adder__pch.h"
#include "Vsysarr_16_input_fp_adder___024root.h"

VlCoroutine Vsysarr_16_input_fp_adder___024root___eval_initial__TOP__Vtiming__0(Vsysarr_16_input_fp_adder___024root* vlSelf);
VlCoroutine Vsysarr_16_input_fp_adder___024root___eval_initial__TOP__Vtiming__1(Vsysarr_16_input_fp_adder___024root* vlSelf);

void Vsysarr_16_input_fp_adder___024root___eval_initial(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___eval_initial\n"); );
    Vsysarr_16_input_fp_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vsysarr_16_input_fp_adder___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vsysarr_16_input_fp_adder___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vsysarr_16_input_fp_adder___024root___eval_initial__TOP__Vtiming__0(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vsysarr_16_input_fp_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_sysarr_16_input_adder__DOT__clk = 0U;
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0x1f4ULL, 
                                             nullptr, 
                                             "/home/asicfab/a/tpeddi/atalla/tb/unit/systolic_array/tb_sysarr_16_input_adder.sv", 
                                             44);
        vlSelfRef.tb_sysarr_16_input_adder__DOT__clk 
            = (1U & (~ (IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__clk)));
    }
}

void Vsysarr_16_input_fp_adder___024root___act_comb__TOP__0(Vsysarr_16_input_fp_adder___024root* vlSelf);

void Vsysarr_16_input_fp_adder___024root___eval_act(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___eval_act\n"); );
    Vsysarr_16_input_fp_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((5ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vsysarr_16_input_fp_adder___024root___act_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vsysarr_16_input_fp_adder___024root___act_comb__TOP__0(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___act_comb__TOP__0\n"); );
    Vsysarr_16_input_fp_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any;
    tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 0;
    CData/*0:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf;
    tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 0;
    CData/*0:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf;
    tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 0;
    // Body
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0U] 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
        [0U];
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[1U] 
        = (IData)((((QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                    [2U])) << 0x20U) 
                   | (QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                     [1U]))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[2U] 
        = (IData)(((((QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                     [2U])) << 0x20U) 
                    | (QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                      [1U]))) >> 0x20U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[3U] 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
        [3U];
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[4U] 
        = (IData)((((QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                    [5U])) << 0x20U) 
                   | (QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                     [4U]))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[5U] 
        = (IData)(((((QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                     [5U])) << 0x20U) 
                    | (QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                      [4U]))) >> 0x20U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[6U] 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
        [6U];
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[7U] 
        = (IData)((((QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                    [8U])) << 0x20U) 
                   | (QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                     [7U]))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[8U] 
        = (IData)(((((QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                     [8U])) << 0x20U) 
                    | (QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                      [7U]))) >> 0x20U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[9U] 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
        [9U];
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xaU] 
        = (IData)((((QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                    [0xbU])) << 0x20U) 
                   | (QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                     [0xaU]))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xbU] 
        = (IData)(((((QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                     [0xbU])) << 0x20U) 
                    | (QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                      [0xaU]))) >> 0x20U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xcU] 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
        [0xcU];
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xdU] 
        = (IData)((((QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                    [0xeU])) << 0x20U) 
                   | (QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                     [0xdU]))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xeU] 
        = (IData)(((((QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                     [0xeU])) << 0x20U) 
                    | (QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                      [0xdU]))) >> 0x20U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xfU] 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
        [0xfU];
    tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 0U;
    tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 0U;
    tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 0U;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[0U] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0U])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0U]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[0U] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [0U] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[0U] = 0U;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [0U]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                          [0U])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0U]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                       [0U] >> 0x1fU))) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [0U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0U]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [0U] >> 0x1fU)) & (~ (IData)((0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                   [0U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[1U] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[1U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[1U])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[1U]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[1U] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [1U] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[1U] = 1U;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [1U]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                          [1U])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [1U]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                       [1U] >> 0x1fU))) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [1U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [1U]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [1U] >> 0x1fU)) & (~ (IData)((0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                   [1U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[2U] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[2U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[2U])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[2U]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[2U] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [2U] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[2U] = 2U;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [2U]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                          [2U])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [2U]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                       [2U] >> 0x1fU))) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [2U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [2U]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [2U] >> 0x1fU)) & (~ (IData)((0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                   [2U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[3U] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[3U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[3U])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[3U]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[3U] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [3U] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[3U] = 3U;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [3U]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                          [3U])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [3U]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                       [3U] >> 0x1fU))) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [3U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [3U]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [3U] >> 0x1fU)) & (~ (IData)((0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                   [3U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[4U] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[4U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[4U])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[4U]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[4U] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [4U] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[4U] = 4U;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [4U]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                          [4U])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [4U]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                       [4U] >> 0x1fU))) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [4U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [4U]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [4U] >> 0x1fU)) & (~ (IData)((0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                   [4U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[5U] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[5U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[5U])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[5U]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[5U] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [5U] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[5U] = 5U;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [5U]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                          [5U])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [5U]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                       [5U] >> 0x1fU))) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [5U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [5U]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [5U] >> 0x1fU)) & (~ (IData)((0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                   [5U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[6U] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[6U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[6U])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[6U]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[6U] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [6U] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[6U] = 6U;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [6U]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                          [6U])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [6U]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                       [6U] >> 0x1fU))) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [6U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [6U]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [6U] >> 0x1fU)) & (~ (IData)((0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                   [6U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[7U] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[7U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[7U])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[7U]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[7U] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [7U] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[7U] = 7U;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [7U]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                          [7U])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [7U]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                       [7U] >> 0x1fU))) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [7U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [7U]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [7U] >> 0x1fU)) & (~ (IData)((0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                   [7U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[8U] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[8U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[8U])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[8U]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[8U] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [8U] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[8U] = 8U;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [8U]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                          [8U])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [8U]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                       [8U] >> 0x1fU))) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [8U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [8U]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [8U] >> 0x1fU)) & (~ (IData)((0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                   [8U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[9U] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[9U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[9U])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[9U]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[9U] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [9U] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[9U] = 9U;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [9U]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                          [9U])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [9U]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                       [9U] >> 0x1fU))) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [9U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [9U]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [9U] >> 0x1fU)) & (~ (IData)((0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                   [9U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[0xaU] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xaU] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xaU])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xaU]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[0xaU] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [0xaU] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[0xaU] = 0xaU;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [0xaU]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                            [0xaU])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0xaU]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                         [0xaU] >> 0x1fU))) & (~ (IData)(
                                                         (0U 
                                                          != 
                                                          (0x7fffffU 
                                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                           [0xaU])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0xaU]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                      [0xaU] >> 0x1fU)) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [0xaU])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[0xbU] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xbU] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xbU])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xbU]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[0xbU] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [0xbU] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[0xbU] = 0xbU;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [0xbU]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                            [0xbU])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0xbU]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                         [0xbU] >> 0x1fU))) & (~ (IData)(
                                                         (0U 
                                                          != 
                                                          (0x7fffffU 
                                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                           [0xbU])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0xbU]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                      [0xbU] >> 0x1fU)) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [0xbU])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[0xcU] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xcU] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xcU])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xcU]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[0xcU] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [0xcU] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[0xcU] = 0xcU;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [0xcU]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                            [0xcU])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0xcU]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                         [0xcU] >> 0x1fU))) & (~ (IData)(
                                                         (0U 
                                                          != 
                                                          (0x7fffffU 
                                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                           [0xcU])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0xcU]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                      [0xcU] >> 0x1fU)) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [0xcU])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[0xdU] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xdU] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xdU])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xdU]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[0xdU] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [0xdU] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[0xdU] = 0xdU;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [0xdU]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                            [0xdU])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0xdU]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                         [0xdU] >> 0x1fU))) & (~ (IData)(
                                                         (0U 
                                                          != 
                                                          (0x7fffffU 
                                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                           [0xdU])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0xdU]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                      [0xdU] >> 0x1fU)) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [0xdU])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[0xeU] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xeU] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xeU])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xeU]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[0xeU] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [0xeU] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[0xeU] = 0xeU;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [0xeU]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                            [0xeU])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0xeU]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                         [0xeU] >> 0x1fU))) & (~ (IData)(
                                                         (0U 
                                                          != 
                                                          (0x7fffffU 
                                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                           [0xeU])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0xeU]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                      [0xeU] >> 0x1fU)) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [0xeU])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[0xfU] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xfU] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xfU])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xfU]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[0xfU] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [0xfU] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[0xfU] = 0xfU;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [0xfU]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                            [0xfU])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0xfU]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                         [0xfU] >> 0x1fU))) & (~ (IData)(
                                                         (0U 
                                                          != 
                                                          (0x7fffffU 
                                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                           [0xfU])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0xfU]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                      [0xfU] >> 0x1fU)) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [0xfU])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__c_spec_case = 0U;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__c_spec_res = 0U;
    if (((IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any) 
         | ((IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf) 
            & (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf)))) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__c_spec_case = 1U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__c_spec_res = 0x7fc00000U;
    } else if (tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__c_spec_case = 1U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__c_spec_res = 0x7f800000U;
    } else if (tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__c_spec_case = 1U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__c_spec_res = 0xff800000U;
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [0U] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [1U])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[0U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [0U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[0U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [0U];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[0U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [1U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[0U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [1U];
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [2U] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [3U])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[1U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [2U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[1U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [2U];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[1U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [3U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[1U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [3U];
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [4U] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [5U])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[2U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [4U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[2U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [4U];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[2U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [5U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[2U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [5U];
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [6U] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [7U])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[3U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [6U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[3U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [6U];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[3U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [7U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[3U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [7U];
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [8U] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [9U])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[4U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [8U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[4U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [8U];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[4U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [9U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[4U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [9U];
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [0xaU] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [0xbU])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[5U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [0xaU];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[5U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [0xaU];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[5U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [0xbU];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[5U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [0xbU];
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [0xcU] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [0xdU])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[6U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [0xcU];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[6U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [0xcU];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[6U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [0xdU];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[6U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [0xdU];
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [0xeU] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [0xfU])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[7U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [0xeU];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[7U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [0xeU];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[7U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [0xfU];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[7U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [0xfU];
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
         [0U] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
         [1U])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e2[0U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
            [0U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i2[0U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1
            [0U];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e2[0U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
            [1U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i2[0U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1
            [1U];
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
         [2U] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
         [3U])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e2[1U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
            [2U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i2[1U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1
            [2U];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e2[1U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
            [3U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i2[1U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1
            [3U];
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
         [4U] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
         [5U])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e2[2U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
            [4U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i2[2U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1
            [4U];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e2[2U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
            [5U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i2[2U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1
            [5U];
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
         [6U] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
         [7U])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e2[3U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
            [6U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i2[3U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1
            [6U];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e2[3U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
            [7U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i2[3U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1
            [7U];
    }
}

void Vsysarr_16_input_fp_adder___024root___nba_sequent__TOP__0(Vsysarr_16_input_fp_adder___024root* vlSelf);
void Vsysarr_16_input_fp_adder___024root___nba_sequent__TOP__1(Vsysarr_16_input_fp_adder___024root* vlSelf);
void Vsysarr_16_input_fp_adder___024root___nba_comb__TOP__0(Vsysarr_16_input_fp_adder___024root* vlSelf);
void Vsysarr_16_input_fp_adder___024root___nba_sequent__TOP__2(Vsysarr_16_input_fp_adder___024root* vlSelf);
void Vsysarr_16_input_fp_adder___024root___nba_comb__TOP__1(Vsysarr_16_input_fp_adder___024root* vlSelf);

void Vsysarr_16_input_fp_adder___024root___eval_nba(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___eval_nba\n"); );
    Vsysarr_16_input_fp_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vsysarr_16_input_fp_adder___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vsysarr_16_input_fp_adder___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((5ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vsysarr_16_input_fp_adder___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vsysarr_16_input_fp_adder___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((5ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vsysarr_16_input_fp_adder___024root___nba_comb__TOP__1(vlSelf);
    }
}

VL_INLINE_OPT void Vsysarr_16_input_fp_adder___024root___nba_sequent__TOP__0(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___nba_sequent__TOP__0\n"); );
    Vsysarr_16_input_fp_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2__v0;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2__v0;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2__v0 = 0;
    CData/*7:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2__v1;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2__v1 = 0;
    CData/*7:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2__v2;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2__v2 = 0;
    CData/*7:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2__v3;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2__v3 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2__v4;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2__v4 = 0;
    CData/*3:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2__v0;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2__v0;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2__v0 = 0;
    CData/*3:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2__v1;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2__v1 = 0;
    CData/*3:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2__v2;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2__v2 = 0;
    CData/*3:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2__v3;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2__v3 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2__v4;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2__v4 = 0;
    // Body
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2__v0 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2__v4 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2__v0 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2__v4 = 0U;
    vlSelfRef.__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v0 = 0U;
    vlSelfRef.__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v16 = 0U;
    if (vlSelfRef.tb_sysarr_16_input_adder__DOT__nRST) {
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2__v0 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e2
            [0U];
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2__v0 = 1U;
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2__v1 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e2
            [1U];
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2__v2 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e2
            [2U];
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2__v3 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e2
            [3U];
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2__v0 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i2
            [0U];
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2__v0 = 1U;
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2__v1 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i2
            [1U];
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2__v2 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i2
            [2U];
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2__v3 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i2
            [3U];
        vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v0 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
            [0U];
        vlSelfRef.__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v0 = 1U;
        vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v1 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
            [1U];
        vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v2 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
            [2U];
        vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v3 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
            [3U];
        vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v4 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
            [4U];
        vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v5 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
            [5U];
        vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v6 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
            [6U];
        vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v7 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
            [7U];
        vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v8 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
            [8U];
        vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v9 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
            [9U];
        vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v10 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
            [0xaU];
        vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v11 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
            [0xbU];
        vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v12 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
            [0xcU];
        vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v13 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
            [0xdU];
        vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v14 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
            [0xeU];
        vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v15 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
            [0xfU];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__out_data 
            = ((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st7_spec_case)
                ? vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st7_spec_res
                : (((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st7_is_zero) 
                    | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st7_e_final))))
                    ? 0U : (VL_LTES_III(32, 0xffU, 
                                        VL_EXTENDS_II(32,11, (IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st7_e_final)))
                             ? (0x7f800000U | ((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st7_sign) 
                                               << 0x1fU))
                             : (((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st7_sign) 
                                 << 0x1fU) | ((0x7f800000U 
                                               & ((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st7_e_final) 
                                                  << 0x17U)) 
                                              | (0x7fffffU 
                                                 & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st7_norm 
                                                    >> 5U)))))));
    } else {
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2__v4 = 1U;
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2__v4 = 1U;
        vlSelfRef.__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v16 = 1U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__out_data = 0U;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2__v0) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2[0U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2__v0;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2[1U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2__v1;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2[2U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2__v2;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2[3U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2__v3;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2__v4) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2[0U] = 0U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2[1U] = 0U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2[2U] = 0U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2[3U] = 0U;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2__v0) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2[0U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2__v0;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2[1U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2__v1;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2[2U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2__v2;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2[3U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2__v3;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2__v4) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2[0U] = 0U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2[1U] = 0U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2[2U] = 0U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2[3U] = 0U;
    }
}

VL_INLINE_OPT void Vsysarr_16_input_fp_adder___024root___nba_sequent__TOP__1(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___nba_sequent__TOP__1\n"); );
    Vsysarr_16_input_fp_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*8:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh = 0;
    IData/*23:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base = 0;
    CData/*4:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_0;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_0 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_0;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_0 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_1;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_1 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_1;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_1 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_2;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_2 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_2;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_2 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_3;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_3 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_3;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_3 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_4;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_4 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_4;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_4 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s2_0;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s2_0 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c2_0;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c2_0 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s2_1;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s2_1 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c2_1;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c2_1 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s2_2;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s2_2 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c2_2;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c2_2 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s3_0;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s3_0 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c3_0;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c3_0 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s3_1;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s3_1 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c3_1;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c3_1 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s4_0;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s4_0 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c4_0;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c4_0 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s4_1;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s4_1 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c4_1;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c4_1 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s5_0;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s5_0 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c5_0;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c5_0 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s6_0;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s6_0 = 0;
    IData/*29:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c6_0;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c6_0 = 0;
    IData/*30:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk13__DOT__raw_sum;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk13__DOT__raw_sum = 0;
    IData/*28:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__scan;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__scan = 0;
    CData/*5:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__lzd_cnt;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__lzd_cnt = 0;
    IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v0;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v1;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v1 = 0;
    IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v2;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v2 = 0;
    IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v3;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v3 = 0;
    IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v4;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v4 = 0;
    IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v5;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v5 = 0;
    IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v6;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v6 = 0;
    IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v7;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v7 = 0;
    IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v8;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v8 = 0;
    IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v9;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v9 = 0;
    IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v10;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v10 = 0;
    IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v11;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v11 = 0;
    IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v12;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v12 = 0;
    IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v13;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v13 = 0;
    IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v14;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v14 = 0;
    IData/*31:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v15;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v15 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v0;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v0;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v0 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v1;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v1 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v1;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v1 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v2;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v2 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v2;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v2 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v3;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v3 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v3;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v3 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v4;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v4 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v4;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v4 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v5;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v5 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v5;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v5 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v6;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v6 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v6;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v6 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v7;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v7 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v7;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v7 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v8;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v8 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v8;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v8 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v9;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v9 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v9;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v9 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v10;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v10 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v10;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v10 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v11;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v11 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v11;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v11 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v12;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v12 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v12;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v12 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v13;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v13 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v13;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v13 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v14;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v14 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v14;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v14 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v15;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v15 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v15;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v15 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v16;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v16 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v16;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v16 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v17;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v17 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v17;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v17 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v18;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v18 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v18;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v18 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v19;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v19 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v19;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v19 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v20;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v20 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v20;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v20 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v21;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v21 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v21;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v21 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v22;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v22 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v22;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v22 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v23;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v23 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v23;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v23 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v24;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v24 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v24;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v24 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v25;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v25 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v25;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v25 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v26;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v26 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v26;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v26 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v27;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v27 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v27;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v27 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v28;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v28 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v28;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v28 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v29;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v29 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v29;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v29 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v30;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v30 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v30;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v30 = 0;
    IData/*29:0*/ __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v31;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v31 = 0;
    CData/*0:0*/ __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v31;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v31 = 0;
    // Body
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v0 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v1 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v2 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v3 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v4 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v5 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v6 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v7 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v8 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v9 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v10 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v11 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v12 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v13 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v14 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v15 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v16 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v17 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v18 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v19 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v20 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v21 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v22 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v23 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v24 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v25 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v26 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v27 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v28 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v29 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v30 = 0U;
    __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v31 = 0U;
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v0 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data
        [0U];
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v1 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data
        [1U];
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v2 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data
        [2U];
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v3 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data
        [3U];
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v4 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data
        [4U];
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v5 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data
        [5U];
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v6 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data
        [6U];
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v7 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data
        [7U];
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v8 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data
        [8U];
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v9 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data
        [9U];
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v10 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data
        [0xaU];
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v11 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data
        [0xbU];
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v12 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data
        [0xcU];
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v13 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data
        [0xdU];
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v14 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data
        [0xeU];
    __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v15 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data
        [0xfU];
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st7_spec_case 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st6_spec_case;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st7_spec_res 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st6_spec_res;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st7_sign 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st6_sign;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st7_is_zero 
        = (0U == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st6_mag);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st7_e_final 
        = (0x7ffU & (((IData)(4U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st6_exp))) 
                     - VL_EXTENDS_II(11,8, (IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st6_lzd))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st7_norm 
        = (0x1fffffffU & VL_SHIFTL_III(29,29,6, vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st6_mag, (IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st6_lzd)));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st6_spec_case 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st5_spec_case;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st6_spec_res 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st5_spec_res;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st6_sign 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st5_sign;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st6_exp 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st5_exp;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st6_mag 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st5_mag;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__scan 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st5_mag;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__lzd_cnt = 0U;
    if ((0U == VL_SHIFTR_III(32,32,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__scan, 0xdU))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__lzd_cnt 
            = (0x3fU & ((IData)(0x10U) + (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__lzd_cnt)));
        tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__scan 
            = (0x1fffffffU & VL_SHIFTL_III(29,29,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__scan, 0x10U));
    }
    if ((0U == VL_SHIFTR_III(32,32,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__scan, 0x15U))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__lzd_cnt 
            = (0x3fU & ((IData)(8U) + (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__lzd_cnt)));
        tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__scan 
            = (0x1fffffffU & VL_SHIFTL_III(29,29,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__scan, 8U));
    }
    if ((0U == VL_SHIFTR_III(32,32,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__scan, 0x19U))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__lzd_cnt 
            = (0x3fU & ((IData)(4U) + (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__lzd_cnt)));
        tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__scan 
            = (0x1fffffffU & VL_SHIFTL_III(29,29,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__scan, 4U));
    }
    if ((0U == VL_SHIFTR_III(32,32,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__scan, 0x1bU))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__lzd_cnt 
            = (0x3fU & ((IData)(2U) + (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__lzd_cnt)));
        tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__scan 
            = (0x1fffffffU & VL_SHIFTL_III(29,29,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__scan, 2U));
    }
    if ((0U == VL_SHIFTR_III(32,32,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__scan, 0x1cU))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__lzd_cnt 
            = (0x3fU & ((IData)(1U) + (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__lzd_cnt)));
        tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__scan 
            = (0x1fffffffU & VL_SHIFTL_III(29,29,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__scan, 1U));
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st6_lzd 
        = tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk14__DOT__lzd_cnt;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st5_spec_case 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st4_spec_case;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st5_spec_res 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st4_spec_res;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st5_exp 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st4_exp;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk13__DOT__raw_sum 
        = (0x7fffffffU & ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st4_sum 
                           + VL_EXTENDS_II(31,30, (0x3fffffffU 
                                                   & VL_SHIFTL_III(30,30,32, vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st4_carry, 1U)))) 
                          + VL_EXTENDS_II(31,30, (IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st4_hot_ones))));
    if ((0x20000000U & tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk13__DOT__raw_sum)) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st5_mag 
            = (0x1fffffffU & ((IData)(1U) + (~ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk13__DOT__raw_sum)));
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st5_sign 
            = (1U & (~ (IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st4_sign_max)));
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st5_mag 
            = (0x1fffffffU & tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk13__DOT__raw_sum);
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st5_sign 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st4_sign_max;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st4_spec_case 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_spec_case;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st4_spec_res 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_spec_res;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st4_exp 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_exp;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st4_sign_max 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_sign_max;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_0 
        = ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
            [0U] ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
            [1U]) ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
           [2U]);
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_0 
        = (((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
             [0U] & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
             [1U]) | (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
                      [1U] & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
                      [2U])) | (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
                                [0U] & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
                                [2U]));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_1 
        = ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
            [3U] ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
            [4U]) ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
           [5U]);
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_1 
        = (((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
             [3U] & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
             [4U]) | (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
                      [4U] & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
                      [5U])) | (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
                                [3U] & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
                                [5U]));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_2 
        = ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
            [6U] ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
            [7U]) ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
           [8U]);
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_2 
        = (((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
             [6U] & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
             [7U]) | (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
                      [7U] & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
                      [8U])) | (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
                                [6U] & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
                                [8U]));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_3 
        = ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
            [9U] ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
            [0xaU]) ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
           [0xbU]);
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_3 
        = (((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
             [9U] & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
             [0xaU]) | (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
                        [0xaU] & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
                        [0xbU])) | (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
                                    [9U] & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
                                    [0xbU]));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_4 
        = ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
            [0xcU] ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
            [0xdU]) ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
           [0xeU]);
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_4 
        = (((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
             [0xcU] & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
             [0xdU]) | (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
                        [0xdU] & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
                        [0xeU])) | (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
                                    [0xcU] & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
                                    [0xeU]));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s2_0 
        = (0x3fffffffU & ((tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_0 
                           ^ VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_0, 1U)) 
                          ^ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_1));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c2_0 
        = (((tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_0 
             & VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_0, 1U)) 
            | (VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_0, 1U) 
               & tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_1)) 
           | (tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_0 
              & tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_1));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s2_1 
        = (0x3fffffffU & ((VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_1, 1U) 
                           ^ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_2) 
                          ^ VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_2, 1U)));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c2_1 
        = (0x3fffffffU & (((VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_1, 1U) 
                            & tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_2) 
                           | (tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_2 
                              & VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_2, 1U))) 
                          | VL_SHIFTL_III(30,30,32, 
                                          (tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_1 
                                           & tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_2), 1U)));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s2_2 
        = (0x3fffffffU & ((tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_3 
                           ^ VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_3, 1U)) 
                          ^ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_4));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c2_2 
        = (((tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_3 
             & VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_3, 1U)) 
            | (VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_3, 1U) 
               & tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_4)) 
           | (tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_3 
              & tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s1_4));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s3_0 
        = (0x3fffffffU & ((tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s2_0 
                           ^ VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c2_0, 1U)) 
                          ^ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s2_1));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c3_0 
        = (((tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s2_0 
             & VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c2_0, 1U)) 
            | (VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c2_0, 1U) 
               & tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s2_1)) 
           | (tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s2_0 
              & tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s2_1));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s3_1 
        = (0x3fffffffU & ((VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c2_1, 1U) 
                           ^ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s2_2) 
                          ^ VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c2_2, 1U)));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c3_1 
        = (0x3fffffffU & (((VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c2_1, 1U) 
                            & tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s2_2) 
                           | (tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s2_2 
                              & VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c2_2, 1U))) 
                          | VL_SHIFTL_III(30,30,32, 
                                          (tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c2_1 
                                           & tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c2_2), 1U)));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s4_0 
        = (0x3fffffffU & ((tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s3_0 
                           ^ VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c3_0, 1U)) 
                          ^ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s3_1));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c4_0 
        = (((tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s3_0 
             & VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c3_0, 1U)) 
            | (VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c3_0, 1U) 
               & tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s3_1)) 
           | (tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s3_0 
              & tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s3_1));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s4_1 
        = (0x3fffffffU & (VL_SHIFTL_III(30,30,32, (tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c3_1 
                                                   ^ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_4), 1U) 
                          ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
                          [0xfU]));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c4_1 
        = (0x3fffffffU & ((VL_SHIFTL_III(30,30,32, 
                                         (tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c3_1 
                                          & tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_4), 1U) 
                           | (VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c1_4, 1U) 
                              & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
                              [0xfU])) | (VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c3_1, 1U) 
                                          & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op
                                          [0xfU])));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s5_0 
        = (0x3fffffffU & ((tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s4_0 
                           ^ VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c4_0, 1U)) 
                          ^ tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s4_1));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c5_0 
        = (((tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s4_0 
             & VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c4_0, 1U)) 
            | (VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c4_0, 1U) 
               & tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s4_1)) 
           | (tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s4_0 
              & tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s4_1));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s6_0 
        = (0x3fffffffU & ((tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s5_0 
                           ^ VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c5_0, 1U)) 
                          ^ VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c4_1, 1U)));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c6_0 
        = (0x3fffffffU & (((tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s5_0 
                            & VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c5_0, 1U)) 
                           | VL_SHIFTL_III(30,30,32, 
                                           (tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c5_0 
                                            & tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c4_1), 1U)) 
                          | (tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s5_0 
                             & VL_SHIFTL_III(30,30,32, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c4_1, 1U))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st4_sum 
        = tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__s6_0;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st4_carry 
        = tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk12__DOT__c6_0;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st4_hot_ones 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_hot_ones;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_spec_case 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_spec_case;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_spec_res 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_spec_res;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_exp 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_exp;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_sign_max 
        = (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
           [vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx] 
           >> 0x1fU);
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt = 0U;
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base 
        = (((0U != (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                             [0U] >> 0x17U))) << 0x17U) 
           | (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
              [0U]));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh 
        = (0x1ffU & ((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_exp) 
                     - (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                                 [0U] >> 0x17U))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[0U] 
        = ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [0U] ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx]) 
           >> 0x1fU);
    if ((0U == (IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx))) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[0U] = 0U;
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v0 
            = tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base;
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v0 = 1U;
    } else {
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v1 
            = (0x3fffffffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                              [0U] ? (~ (0xffffffU 
                                         & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh))))
                               : (0xffffffU & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh)))));
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v1 = 1U;
        tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt 
            = (0x1fU & ((IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt) 
                        + vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                        [0U]));
    }
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base 
        = (((0U != (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                             [1U] >> 0x17U))) << 0x17U) 
           | (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
              [1U]));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh 
        = (0x1ffU & ((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_exp) 
                     - (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                                 [1U] >> 0x17U))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[1U] 
        = ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [1U] ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx]) 
           >> 0x1fU);
    if ((1U == (IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx))) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[1U] = 0U;
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v2 
            = tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base;
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v2 = 1U;
    } else {
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v3 
            = (0x3fffffffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                              [1U] ? (~ (0xffffffU 
                                         & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh))))
                               : (0xffffffU & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh)))));
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v3 = 1U;
        tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt 
            = (0x1fU & ((IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt) 
                        + vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                        [1U]));
    }
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base 
        = (((0U != (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                             [2U] >> 0x17U))) << 0x17U) 
           | (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
              [2U]));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh 
        = (0x1ffU & ((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_exp) 
                     - (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                                 [2U] >> 0x17U))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[2U] 
        = ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [2U] ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx]) 
           >> 0x1fU);
    if ((2U == (IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx))) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[2U] = 0U;
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v4 
            = tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base;
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v4 = 1U;
    } else {
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v5 
            = (0x3fffffffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                              [2U] ? (~ (0xffffffU 
                                         & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh))))
                               : (0xffffffU & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh)))));
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v5 = 1U;
        tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt 
            = (0x1fU & ((IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt) 
                        + vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                        [2U]));
    }
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base 
        = (((0U != (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                             [3U] >> 0x17U))) << 0x17U) 
           | (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
              [3U]));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh 
        = (0x1ffU & ((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_exp) 
                     - (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                                 [3U] >> 0x17U))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[3U] 
        = ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [3U] ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx]) 
           >> 0x1fU);
    if ((3U == (IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx))) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[3U] = 0U;
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v6 
            = tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base;
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v6 = 1U;
    } else {
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v7 
            = (0x3fffffffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                              [3U] ? (~ (0xffffffU 
                                         & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh))))
                               : (0xffffffU & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh)))));
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v7 = 1U;
        tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt 
            = (0x1fU & ((IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt) 
                        + vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                        [3U]));
    }
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base 
        = (((0U != (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                             [4U] >> 0x17U))) << 0x17U) 
           | (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
              [4U]));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh 
        = (0x1ffU & ((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_exp) 
                     - (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                                 [4U] >> 0x17U))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[4U] 
        = ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [4U] ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx]) 
           >> 0x1fU);
    if ((4U == (IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx))) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[4U] = 0U;
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v8 
            = tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base;
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v8 = 1U;
    } else {
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v9 
            = (0x3fffffffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                              [4U] ? (~ (0xffffffU 
                                         & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh))))
                               : (0xffffffU & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh)))));
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v9 = 1U;
        tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt 
            = (0x1fU & ((IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt) 
                        + vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                        [4U]));
    }
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base 
        = (((0U != (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                             [5U] >> 0x17U))) << 0x17U) 
           | (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
              [5U]));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh 
        = (0x1ffU & ((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_exp) 
                     - (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                                 [5U] >> 0x17U))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[5U] 
        = ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [5U] ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx]) 
           >> 0x1fU);
    if ((5U == (IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx))) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[5U] = 0U;
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v10 
            = tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base;
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v10 = 1U;
    } else {
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v11 
            = (0x3fffffffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                              [5U] ? (~ (0xffffffU 
                                         & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh))))
                               : (0xffffffU & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh)))));
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v11 = 1U;
        tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt 
            = (0x1fU & ((IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt) 
                        + vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                        [5U]));
    }
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base 
        = (((0U != (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                             [6U] >> 0x17U))) << 0x17U) 
           | (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
              [6U]));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh 
        = (0x1ffU & ((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_exp) 
                     - (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                                 [6U] >> 0x17U))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[6U] 
        = ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [6U] ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx]) 
           >> 0x1fU);
    if ((6U == (IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx))) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[6U] = 0U;
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v12 
            = tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base;
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v12 = 1U;
    } else {
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v13 
            = (0x3fffffffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                              [6U] ? (~ (0xffffffU 
                                         & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh))))
                               : (0xffffffU & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh)))));
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v13 = 1U;
        tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt 
            = (0x1fU & ((IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt) 
                        + vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                        [6U]));
    }
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base 
        = (((0U != (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                             [7U] >> 0x17U))) << 0x17U) 
           | (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
              [7U]));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh 
        = (0x1ffU & ((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_exp) 
                     - (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                                 [7U] >> 0x17U))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[7U] 
        = ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [7U] ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx]) 
           >> 0x1fU);
    if ((7U == (IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx))) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[7U] = 0U;
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v14 
            = tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base;
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v14 = 1U;
    } else {
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v15 
            = (0x3fffffffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                              [7U] ? (~ (0xffffffU 
                                         & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh))))
                               : (0xffffffU & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh)))));
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v15 = 1U;
        tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt 
            = (0x1fU & ((IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt) 
                        + vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                        [7U]));
    }
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base 
        = (((0U != (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                             [8U] >> 0x17U))) << 0x17U) 
           | (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
              [8U]));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh 
        = (0x1ffU & ((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_exp) 
                     - (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                                 [8U] >> 0x17U))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[8U] 
        = ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [8U] ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx]) 
           >> 0x1fU);
    if ((8U == (IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx))) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[8U] = 0U;
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v16 
            = tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base;
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v16 = 1U;
    } else {
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v17 
            = (0x3fffffffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                              [8U] ? (~ (0xffffffU 
                                         & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh))))
                               : (0xffffffU & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh)))));
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v17 = 1U;
        tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt 
            = (0x1fU & ((IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt) 
                        + vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                        [8U]));
    }
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base 
        = (((0U != (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                             [9U] >> 0x17U))) << 0x17U) 
           | (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
              [9U]));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh 
        = (0x1ffU & ((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_exp) 
                     - (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                                 [9U] >> 0x17U))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[9U] 
        = ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [9U] ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx]) 
           >> 0x1fU);
    if ((9U == (IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx))) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[9U] = 0U;
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v18 
            = tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base;
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v18 = 1U;
    } else {
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v19 
            = (0x3fffffffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                              [9U] ? (~ (0xffffffU 
                                         & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh))))
                               : (0xffffffU & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh)))));
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v19 = 1U;
        tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt 
            = (0x1fU & ((IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt) 
                        + vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                        [9U]));
    }
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base 
        = (((0U != (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                             [0xaU] >> 0x17U))) << 0x17U) 
           | (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
              [0xaU]));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh 
        = (0x1ffU & ((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_exp) 
                     - (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                                 [0xaU] >> 0x17U))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[0xaU] 
        = ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [0xaU] ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx]) 
           >> 0x1fU);
    if ((0xaU == (IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx))) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[0xaU] = 0U;
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v20 
            = tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base;
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v20 = 1U;
    } else {
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v21 
            = (0x3fffffffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                              [0xaU] ? (~ (0xffffffU 
                                           & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh))))
                               : (0xffffffU & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh)))));
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v21 = 1U;
        tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt 
            = (0x1fU & ((IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt) 
                        + vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                        [0xaU]));
    }
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base 
        = (((0U != (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                             [0xbU] >> 0x17U))) << 0x17U) 
           | (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
              [0xbU]));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh 
        = (0x1ffU & ((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_exp) 
                     - (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                                 [0xbU] >> 0x17U))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[0xbU] 
        = ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [0xbU] ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx]) 
           >> 0x1fU);
    if ((0xbU == (IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx))) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[0xbU] = 0U;
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v22 
            = tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base;
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v22 = 1U;
    } else {
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v23 
            = (0x3fffffffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                              [0xbU] ? (~ (0xffffffU 
                                           & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh))))
                               : (0xffffffU & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh)))));
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v23 = 1U;
        tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt 
            = (0x1fU & ((IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt) 
                        + vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                        [0xbU]));
    }
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base 
        = (((0U != (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                             [0xcU] >> 0x17U))) << 0x17U) 
           | (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
              [0xcU]));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh 
        = (0x1ffU & ((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_exp) 
                     - (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                                 [0xcU] >> 0x17U))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[0xcU] 
        = ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [0xcU] ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx]) 
           >> 0x1fU);
    if ((0xcU == (IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx))) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[0xcU] = 0U;
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v24 
            = tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base;
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v24 = 1U;
    } else {
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v25 
            = (0x3fffffffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                              [0xcU] ? (~ (0xffffffU 
                                           & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh))))
                               : (0xffffffU & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh)))));
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v25 = 1U;
        tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt 
            = (0x1fU & ((IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt) 
                        + vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                        [0xcU]));
    }
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base 
        = (((0U != (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                             [0xdU] >> 0x17U))) << 0x17U) 
           | (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
              [0xdU]));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh 
        = (0x1ffU & ((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_exp) 
                     - (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                                 [0xdU] >> 0x17U))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[0xdU] 
        = ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [0xdU] ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx]) 
           >> 0x1fU);
    if ((0xdU == (IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx))) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[0xdU] = 0U;
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v26 
            = tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base;
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v26 = 1U;
    } else {
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v27 
            = (0x3fffffffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                              [0xdU] ? (~ (0xffffffU 
                                           & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh))))
                               : (0xffffffU & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh)))));
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v27 = 1U;
        tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt 
            = (0x1fU & ((IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt) 
                        + vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                        [0xdU]));
    }
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base 
        = (((0U != (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                             [0xeU] >> 0x17U))) << 0x17U) 
           | (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
              [0xeU]));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh 
        = (0x1ffU & ((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_exp) 
                     - (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                                 [0xeU] >> 0x17U))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[0xeU] 
        = ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [0xeU] ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx]) 
           >> 0x1fU);
    if ((0xeU == (IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx))) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[0xeU] = 0U;
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v28 
            = tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base;
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v28 = 1U;
    } else {
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v29 
            = (0x3fffffffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                              [0xeU] ? (~ (0xffffffU 
                                           & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh))))
                               : (0xffffffU & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh)))));
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v29 = 1U;
        tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt 
            = (0x1fU & ((IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt) 
                        + vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                        [0xeU]));
    }
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base 
        = (((0U != (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                             [0xfU] >> 0x17U))) << 0x17U) 
           | (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
              [0xfU]));
    tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh 
        = (0x1ffU & ((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_exp) 
                     - (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
                                 [0xfU] >> 0x17U))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[0xfU] 
        = ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [0xfU] ^ vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data
            [vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx]) 
           >> 0x1fU);
    if ((0xfU == (IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx))) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[0xfU] = 0U;
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v30 
            = tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base;
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v30 = 1U;
    } else {
        __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v31 
            = (0x3fffffffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                              [0xfU] ? (~ (0xffffffU 
                                           & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh))))
                               : (0xffffffU & VL_SHIFTR_III(24,24,9, tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__m_base, (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sh)))));
        __VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v31 = 1U;
        tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt 
            = (0x1fU & ((IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt) 
                        + vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff
                        [0xfU]));
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_hot_ones 
        = tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__hot_cnt;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data[0U] 
        = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v0;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data[1U] 
        = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v1;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data[2U] 
        = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v2;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data[3U] 
        = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v3;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data[4U] 
        = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v4;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data[5U] 
        = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v5;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data[6U] 
        = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v6;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data[7U] 
        = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v7;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data[8U] 
        = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v8;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data[9U] 
        = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v9;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data[0xaU] 
        = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v10;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data[0xbU] 
        = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v11;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data[0xcU] 
        = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v12;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data[0xdU] 
        = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v13;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data[0xeU] 
        = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v14;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data[0xfU] 
        = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data__v15;
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v0) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[0U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v0;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v1) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[0U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v1;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v2) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[1U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v2;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v3) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[1U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v3;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v4) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[2U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v4;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v5) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[2U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v5;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v6) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[3U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v6;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v7) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[3U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v7;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v8) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[4U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v8;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v9) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[4U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v9;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v10) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[5U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v10;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v11) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[5U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v11;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v12) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[6U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v12;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v13) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[6U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v13;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v14) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[7U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v14;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v15) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[7U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v15;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v16) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[8U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v16;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v17) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[8U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v17;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v18) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[9U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v18;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v19) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[9U] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v19;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v20) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[0xaU] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v20;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v21) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[0xaU] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v21;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v22) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[0xbU] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v22;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v23) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[0xbU] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v23;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v24) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[0xcU] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v24;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v25) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[0xcU] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v25;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v26) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[0xdU] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v26;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v27) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[0xdU] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v27;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v28) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[0xeU] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v28;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v29) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[0xeU] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v29;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v30) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[0xfU] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v30;
    }
    if (__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v31) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[0xfU] 
            = __VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op__v31;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_spec_case 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_spec_case;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_spec_res 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_spec_res;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_exp 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__c_max_exp;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__c_max_idx;
}

VL_INLINE_OPT void Vsysarr_16_input_fp_adder___024root___nba_comb__TOP__0(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___nba_comb__TOP__0\n"); );
    Vsysarr_16_input_fp_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0U] 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
        [0U];
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[1U] 
        = (IData)((((QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                    [2U])) << 0x20U) 
                   | (QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                     [1U]))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[2U] 
        = (IData)(((((QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                     [2U])) << 0x20U) 
                    | (QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                      [1U]))) >> 0x20U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[3U] 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
        [3U];
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[4U] 
        = (IData)((((QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                    [5U])) << 0x20U) 
                   | (QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                     [4U]))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[5U] 
        = (IData)(((((QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                     [5U])) << 0x20U) 
                    | (QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                      [4U]))) >> 0x20U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[6U] 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
        [6U];
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[7U] 
        = (IData)((((QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                    [8U])) << 0x20U) 
                   | (QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                     [7U]))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[8U] 
        = (IData)(((((QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                     [8U])) << 0x20U) 
                    | (QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                      [7U]))) >> 0x20U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[9U] 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
        [9U];
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xaU] 
        = (IData)((((QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                    [0xbU])) << 0x20U) 
                   | (QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                     [0xaU]))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xbU] 
        = (IData)(((((QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                     [0xbU])) << 0x20U) 
                    | (QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                      [0xaU]))) >> 0x20U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xcU] 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
        [0xcU];
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xdU] 
        = (IData)((((QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                    [0xeU])) << 0x20U) 
                   | (QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                     [0xdU]))));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xeU] 
        = (IData)(((((QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                     [0xeU])) << 0x20U) 
                    | (QData)((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
                                      [0xdU]))) >> 0x20U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xfU] 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__in_data
        [0xfU];
}

VL_INLINE_OPT void Vsysarr_16_input_fp_adder___024root___nba_sequent__TOP__2(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___nba_sequent__TOP__2\n"); );
    Vsysarr_16_input_fp_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v0) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[0U] 
            = vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v0;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[1U] 
            = vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v1;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[2U] 
            = vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v2;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[3U] 
            = vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v3;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[4U] 
            = vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v4;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[5U] 
            = vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v5;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[6U] 
            = vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v6;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[7U] 
            = vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v7;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[8U] 
            = vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v8;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[9U] 
            = vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v9;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[0xaU] 
            = vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v10;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[0xbU] 
            = vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v11;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[0xcU] 
            = vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v12;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[0xdU] 
            = vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v13;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[0xeU] 
            = vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v14;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[0xfU] 
            = vlSelfRef.__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v15;
    }
    if (vlSelfRef.__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v16) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[0U] = 0U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[1U] = 0U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[2U] = 0U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[3U] = 0U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[4U] = 0U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[5U] = 0U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[6U] = 0U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[7U] = 0U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[8U] = 0U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[9U] = 0U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[0xaU] = 0U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[0xbU] = 0U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[0xcU] = 0U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[0xdU] = 0U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[0xeU] = 0U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[0xfU] = 0U;
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2
         [0U] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2
         [1U])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e3[0U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2
            [0U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i3[0U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2
            [0U];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e3[0U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2
            [1U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i3[0U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2
            [1U];
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2
         [2U] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2
         [3U])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e3[1U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2
            [2U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i3[1U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2
            [2U];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e3[1U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2
            [3U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i3[1U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2
            [3U];
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e3
         [0U] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e3
         [1U])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__c_max_exp 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e3
            [0U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__c_max_idx 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i3
            [0U];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__c_max_exp 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e3
            [1U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__c_max_idx 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i3
            [1U];
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_spec_case 
        = ((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__nRST) 
           && (IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__c_spec_case));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__st1_spec_res 
        = ((IData)(vlSelfRef.tb_sysarr_16_input_adder__DOT__nRST)
            ? vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__c_spec_res
            : 0U);
}

VL_INLINE_OPT void Vsysarr_16_input_fp_adder___024root___nba_comb__TOP__1(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___nba_comb__TOP__1\n"); );
    Vsysarr_16_input_fp_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any;
    tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 0;
    CData/*0:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf;
    tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 0;
    CData/*0:0*/ tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf;
    tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 0;
    // Body
    tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 0U;
    tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 0U;
    tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 0U;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[0U] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0U])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0U]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[0U] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [0U] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[0U] = 0U;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [0U]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                          [0U])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0U]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                       [0U] >> 0x1fU))) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [0U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0U]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [0U] >> 0x1fU)) & (~ (IData)((0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                   [0U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[1U] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[1U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[1U])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[1U]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[1U] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [1U] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[1U] = 1U;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [1U]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                          [1U])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [1U]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                       [1U] >> 0x1fU))) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [1U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [1U]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [1U] >> 0x1fU)) & (~ (IData)((0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                   [1U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[2U] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[2U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[2U])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[2U]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[2U] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [2U] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[2U] = 2U;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [2U]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                          [2U])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [2U]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                       [2U] >> 0x1fU))) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [2U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [2U]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [2U] >> 0x1fU)) & (~ (IData)((0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                   [2U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[3U] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[3U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[3U])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[3U]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[3U] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [3U] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[3U] = 3U;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [3U]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                          [3U])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [3U]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                       [3U] >> 0x1fU))) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [3U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [3U]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [3U] >> 0x1fU)) & (~ (IData)((0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                   [3U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[4U] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[4U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[4U])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[4U]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[4U] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [4U] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[4U] = 4U;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [4U]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                          [4U])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [4U]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                       [4U] >> 0x1fU))) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [4U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [4U]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [4U] >> 0x1fU)) & (~ (IData)((0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                   [4U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[5U] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[5U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[5U])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[5U]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[5U] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [5U] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[5U] = 5U;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [5U]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                          [5U])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [5U]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                       [5U] >> 0x1fU))) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [5U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [5U]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [5U] >> 0x1fU)) & (~ (IData)((0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                   [5U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[6U] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[6U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[6U])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[6U]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[6U] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [6U] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[6U] = 6U;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [6U]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                          [6U])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [6U]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                       [6U] >> 0x1fU))) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [6U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [6U]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [6U] >> 0x1fU)) & (~ (IData)((0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                   [6U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[7U] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[7U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[7U])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[7U]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[7U] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [7U] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[7U] = 7U;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [7U]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                          [7U])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [7U]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                       [7U] >> 0x1fU))) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [7U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [7U]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [7U] >> 0x1fU)) & (~ (IData)((0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                   [7U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[8U] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[8U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[8U])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[8U]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[8U] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [8U] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[8U] = 8U;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [8U]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                          [8U])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [8U]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                       [8U] >> 0x1fU))) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [8U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [8U]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [8U] >> 0x1fU)) & (~ (IData)((0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                   [8U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[9U] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[9U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[9U])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[9U]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[9U] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [9U] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[9U] = 9U;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [9U]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                          [9U])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [9U]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                       [9U] >> 0x1fU))) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [9U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [9U]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [9U] >> 0x1fU)) & (~ (IData)((0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                   [9U])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[0xaU] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xaU] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xaU])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xaU]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[0xaU] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [0xaU] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[0xaU] = 0xaU;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [0xaU]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                            [0xaU])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0xaU]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                         [0xaU] >> 0x1fU))) & (~ (IData)(
                                                         (0U 
                                                          != 
                                                          (0x7fffffU 
                                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                           [0xaU])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0xaU]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                      [0xaU] >> 0x1fU)) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [0xaU])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[0xbU] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xbU] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xbU])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xbU]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[0xbU] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [0xbU] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[0xbU] = 0xbU;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [0xbU]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                            [0xbU])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0xbU]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                         [0xbU] >> 0x1fU))) & (~ (IData)(
                                                         (0U 
                                                          != 
                                                          (0x7fffffU 
                                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                           [0xbU])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0xbU]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                      [0xbU] >> 0x1fU)) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [0xbU])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[0xcU] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xcU] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xcU])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xcU]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[0xcU] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [0xcU] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[0xcU] = 0xcU;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [0xcU]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                            [0xcU])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0xcU]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                         [0xcU] >> 0x1fU))) & (~ (IData)(
                                                         (0U 
                                                          != 
                                                          (0x7fffffU 
                                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                           [0xcU])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0xcU]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                      [0xcU] >> 0x1fU)) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [0xcU])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[0xdU] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xdU] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xdU])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xdU]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[0xdU] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [0xdU] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[0xdU] = 0xdU;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [0xdU]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                            [0xdU])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0xdU]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                         [0xdU] >> 0x1fU))) & (~ (IData)(
                                                         (0U 
                                                          != 
                                                          (0x7fffffU 
                                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                           [0xdU])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0xdU]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                      [0xdU] >> 0x1fU)) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [0xdU])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[0xeU] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xeU] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xeU])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xeU]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[0xeU] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [0xeU] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[0xeU] = 0xeU;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [0xeU]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                            [0xeU])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0xeU]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                         [0xeU] >> 0x1fU))) & (~ (IData)(
                                                         (0U 
                                                          != 
                                                          (0x7fffffU 
                                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                           [0xeU])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0xeU]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                      [0xeU] >> 0x1fU)) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [0xeU])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[0xfU] 
        = ((0U == (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xfU] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xfU])
            : vlSelfRef.tb_sysarr_16_input_adder__DOT__flat_in_data[0xfU]);
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[0xfU] 
        = (0xffU & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                    [0xfU] >> 0x17U));
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[0xfU] = 0xfU;
    if (((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
          [0xfU]) & (0U != (0x7fffffU & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                            [0xfU])))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0xfU]) & (~ (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                         [0xfU] >> 0x1fU))) & (~ (IData)(
                                                         (0U 
                                                          != 
                                                          (0x7fffffU 
                                                           & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                           [0xfU])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
           [0xfU]) & (vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                      [0xfU] >> 0x1fU)) & (~ (IData)(
                                                     (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data
                                                       [0xfU])))))) {
        tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf = 1U;
    }
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__c_spec_case = 0U;
    vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__c_spec_res = 0U;
    if (((IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__c_is_nan_any) 
         | ((IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf) 
            & (IData)(tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf)))) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__c_spec_case = 1U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__c_spec_res = 0x7fc00000U;
    } else if (tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_pos_inf) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__c_spec_case = 1U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__c_spec_res = 0x7f800000U;
    } else if (tb_sysarr_16_input_adder__DOT__dut__DOT__c_any_neg_inf) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__c_spec_case = 1U;
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__c_spec_res = 0xff800000U;
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [0U] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [1U])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[0U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [0U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[0U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [0U];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[0U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [1U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[0U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [1U];
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [2U] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [3U])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[1U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [2U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[1U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [2U];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[1U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [3U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[1U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [3U];
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [4U] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [5U])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[2U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [4U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[2U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [4U];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[2U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [5U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[2U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [5U];
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [6U] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [7U])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[3U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [6U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[3U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [6U];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[3U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [7U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[3U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [7U];
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [8U] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [9U])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[4U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [8U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[4U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [8U];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[4U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [9U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[4U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [9U];
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [0xaU] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [0xbU])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[5U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [0xaU];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[5U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [0xaU];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[5U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [0xbU];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[5U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [0xbU];
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [0xcU] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [0xdU])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[6U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [0xcU];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[6U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [0xcU];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[6U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [0xdU];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[6U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [0xdU];
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [0xeU] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
         [0xfU])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[7U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [0xeU];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[7U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [0xeU];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1[7U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr
            [0xfU];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1[7U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr
            [0xfU];
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
         [0U] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
         [1U])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e2[0U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
            [0U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i2[0U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1
            [0U];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e2[0U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
            [1U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i2[0U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1
            [1U];
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
         [2U] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
         [3U])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e2[1U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
            [2U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i2[1U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1
            [2U];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e2[1U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
            [3U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i2[1U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1
            [3U];
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
         [4U] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
         [5U])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e2[2U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
            [4U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i2[2U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1
            [4U];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e2[2U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
            [5U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i2[2U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1
            [5U];
    }
    if ((vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
         [6U] >= vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
         [7U])) {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e2[3U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
            [6U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i2[3U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1
            [6U];
    } else {
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e2[3U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__e1
            [7U];
        vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i2[3U] 
            = vlSelfRef.tb_sysarr_16_input_adder__DOT__dut__DOT__i1
            [7U];
    }
}

void Vsysarr_16_input_fp_adder___024root___timing_resume(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___timing_resume\n"); );
    Vsysarr_16_input_fp_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h21a46a7e__0.resume(
                                                   "@(posedge tb_sysarr_16_input_adder.clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vsysarr_16_input_fp_adder___024root___timing_commit(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___timing_commit\n"); );
    Vsysarr_16_input_fp_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h21a46a7e__0.commit(
                                                   "@(posedge tb_sysarr_16_input_adder.clk)");
    }
}

void Vsysarr_16_input_fp_adder___024root___eval_triggers__act(Vsysarr_16_input_fp_adder___024root* vlSelf);

bool Vsysarr_16_input_fp_adder___024root___eval_phase__act(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___eval_phase__act\n"); );
    Vsysarr_16_input_fp_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vsysarr_16_input_fp_adder___024root___eval_triggers__act(vlSelf);
    Vsysarr_16_input_fp_adder___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vsysarr_16_input_fp_adder___024root___timing_resume(vlSelf);
        Vsysarr_16_input_fp_adder___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vsysarr_16_input_fp_adder___024root___eval_phase__nba(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___eval_phase__nba\n"); );
    Vsysarr_16_input_fp_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vsysarr_16_input_fp_adder___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsysarr_16_input_fp_adder___024root___dump_triggers__nba(Vsysarr_16_input_fp_adder___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsysarr_16_input_fp_adder___024root___dump_triggers__act(Vsysarr_16_input_fp_adder___024root* vlSelf);
#endif  // VL_DEBUG

void Vsysarr_16_input_fp_adder___024root___eval(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___eval\n"); );
    Vsysarr_16_input_fp_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vsysarr_16_input_fp_adder___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/asicfab/a/tpeddi/atalla/tb/unit/systolic_array/tb_sysarr_16_input_adder.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vsysarr_16_input_fp_adder___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/asicfab/a/tpeddi/atalla/tb/unit/systolic_array/tb_sysarr_16_input_adder.sv", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vsysarr_16_input_fp_adder___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vsysarr_16_input_fp_adder___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vsysarr_16_input_fp_adder___024root___eval_debug_assertions(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___eval_debug_assertions\n"); );
    Vsysarr_16_input_fp_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
