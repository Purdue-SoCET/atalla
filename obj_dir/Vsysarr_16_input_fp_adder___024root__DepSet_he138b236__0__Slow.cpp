// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsysarr_16_input_fp_adder.h for the primary calling header

#include "Vsysarr_16_input_fp_adder__pch.h"
#include "Vsysarr_16_input_fp_adder___024root.h"

VL_ATTR_COLD void Vsysarr_16_input_fp_adder___024root___eval_static(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___eval_static\n"); );
    Vsysarr_16_input_fp_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__tb_sysarr_16_input_adder__DOT__clk__0 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_sysarr_16_input_adder__DOT__nRST__0 
        = vlSelfRef.tb_sysarr_16_input_adder__DOT__nRST;
}

VL_ATTR_COLD void Vsysarr_16_input_fp_adder___024root___eval_final(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___eval_final\n"); );
    Vsysarr_16_input_fp_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsysarr_16_input_fp_adder___024root___dump_triggers__stl(Vsysarr_16_input_fp_adder___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vsysarr_16_input_fp_adder___024root___eval_phase__stl(Vsysarr_16_input_fp_adder___024root* vlSelf);

VL_ATTR_COLD void Vsysarr_16_input_fp_adder___024root___eval_settle(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___eval_settle\n"); );
    Vsysarr_16_input_fp_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vsysarr_16_input_fp_adder___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/home/asicfab/a/tpeddi/atalla/tb/unit/systolic_array/tb_sysarr_16_input_adder.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vsysarr_16_input_fp_adder___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsysarr_16_input_fp_adder___024root___dump_triggers__stl(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___dump_triggers__stl\n"); );
    Vsysarr_16_input_fp_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void Vsysarr_16_input_fp_adder___024root___stl_sequent__TOP__0(Vsysarr_16_input_fp_adder___024root* vlSelf);

VL_ATTR_COLD void Vsysarr_16_input_fp_adder___024root___eval_stl(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___eval_stl\n"); );
    Vsysarr_16_input_fp_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vsysarr_16_input_fp_adder___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vsysarr_16_input_fp_adder___024root___stl_sequent__TOP__0(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___stl_sequent__TOP__0\n"); );
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

VL_ATTR_COLD void Vsysarr_16_input_fp_adder___024root___eval_triggers__stl(Vsysarr_16_input_fp_adder___024root* vlSelf);

VL_ATTR_COLD bool Vsysarr_16_input_fp_adder___024root___eval_phase__stl(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___eval_phase__stl\n"); );
    Vsysarr_16_input_fp_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vsysarr_16_input_fp_adder___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vsysarr_16_input_fp_adder___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsysarr_16_input_fp_adder___024root___dump_triggers__act(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___dump_triggers__act\n"); );
    Vsysarr_16_input_fp_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_sysarr_16_input_adder.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge tb_sysarr_16_input_adder.nRST)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsysarr_16_input_fp_adder___024root___dump_triggers__nba(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___dump_triggers__nba\n"); );
    Vsysarr_16_input_fp_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_sysarr_16_input_adder.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge tb_sysarr_16_input_adder.nRST)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsysarr_16_input_fp_adder___024root___ctor_var_reset(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___ctor_var_reset\n"); );
    Vsysarr_16_input_fp_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->tb_sysarr_16_input_adder__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_sysarr_16_input_adder__DOT__nRST = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_sysarr_16_input_adder__DOT__in_data[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb_sysarr_16_input_adder__DOT__out_data = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(512, vlSelf->tb_sysarr_16_input_adder__DOT__flat_in_data);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_sysarr_16_input_adder__DOT__test_stimulus[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__daz_data[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__exp_arr[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__idx_arr[__Vi0] = VL_RAND_RESET_I(4);
    }
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__c_spec_case = VL_RAND_RESET_I(1);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__c_spec_res = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__e1[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__e2[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__i1[__Vi0] = VL_RAND_RESET_I(4);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__i2[__Vi0] = VL_RAND_RESET_I(4);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st1_e2[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st1_i2[__Vi0] = VL_RAND_RESET_I(4);
    }
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st1_spec_case = VL_RAND_RESET_I(1);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st1_spec_res = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__e3[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__c_max_exp = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__i3[__Vi0] = VL_RAND_RESET_I(4);
    }
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__c_max_idx = VL_RAND_RESET_I(4);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st2_data[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_exp = VL_RAND_RESET_I(8);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st2_max_idx = VL_RAND_RESET_I(4);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st2_spec_case = VL_RAND_RESET_I(1);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st2_spec_res = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st3_op[__Vi0] = VL_RAND_RESET_I(30);
    }
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st3_hot_ones = VL_RAND_RESET_I(5);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st3_exp = VL_RAND_RESET_I(8);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st3_sign_max = VL_RAND_RESET_I(1);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st3_spec_case = VL_RAND_RESET_I(1);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st3_spec_res = VL_RAND_RESET_I(32);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st4_sum = VL_RAND_RESET_I(30);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st4_carry = VL_RAND_RESET_I(30);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st4_hot_ones = VL_RAND_RESET_I(5);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st4_exp = VL_RAND_RESET_I(8);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st4_sign_max = VL_RAND_RESET_I(1);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st4_spec_case = VL_RAND_RESET_I(1);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st4_spec_res = VL_RAND_RESET_I(32);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st5_mag = VL_RAND_RESET_I(29);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st5_sign = VL_RAND_RESET_I(1);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st5_spec_case = VL_RAND_RESET_I(1);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st5_exp = VL_RAND_RESET_I(8);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st5_spec_res = VL_RAND_RESET_I(32);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st6_lzd = VL_RAND_RESET_I(6);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st6_mag = VL_RAND_RESET_I(29);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st6_sign = VL_RAND_RESET_I(1);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st6_spec_case = VL_RAND_RESET_I(1);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st6_exp = VL_RAND_RESET_I(8);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st6_spec_res = VL_RAND_RESET_I(32);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st7_norm = VL_RAND_RESET_I(29);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st7_e_final = VL_RAND_RESET_I(11);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st7_sign = VL_RAND_RESET_I(1);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st7_spec_case = VL_RAND_RESET_I(1);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st7_is_zero = VL_RAND_RESET_I(1);
    vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__st7_spec_res = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_sysarr_16_input_adder__DOT__dut__DOT__unnamedblk10__DOT__sign_diff[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v0 = VL_RAND_RESET_I(32);
    vlSelf->__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v0 = 0;
    vlSelf->__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v1 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v2 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v3 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v4 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v5 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v6 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v7 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v8 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v9 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v10 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v11 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v12 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v13 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v14 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v15 = VL_RAND_RESET_I(32);
    vlSelf->__VdlySet__tb_sysarr_16_input_adder__DOT__dut__DOT__st1_data__v16 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_sysarr_16_input_adder__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_sysarr_16_input_adder__DOT__nRST__0 = VL_RAND_RESET_I(1);
}
