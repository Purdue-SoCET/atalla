// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaddn_fp32_tb_softfloat.h for the primary calling header

#include "Vaddn_fp32_tb_softfloat__pch.h"
#include "Vaddn_fp32_tb_softfloat___024root.h"

VlCoroutine Vaddn_fp32_tb_softfloat___024root___eval_initial__TOP__Vtiming__0(Vaddn_fp32_tb_softfloat___024root* vlSelf);
VlCoroutine Vaddn_fp32_tb_softfloat___024root___eval_initial__TOP__Vtiming__1(Vaddn_fp32_tb_softfloat___024root* vlSelf);

void Vaddn_fp32_tb_softfloat___024root___eval_initial(Vaddn_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root___eval_initial\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vaddn_fp32_tb_softfloat___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vaddn_fp32_tb_softfloat___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vaddn_fp32_tb_softfloat___024root___eval_initial__TOP__Vtiming__1(Vaddn_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_clk = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                             nullptr, 
                                             "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                             29);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_clk = 1U;
        co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                             nullptr, 
                                             "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                             31);
    }
}

void Vaddn_fp32_tb_softfloat___024root___act_comb__TOP__0(Vaddn_fp32_tb_softfloat___024root* vlSelf);

void Vaddn_fp32_tb_softfloat___024root___eval_act(Vaddn_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root___eval_act\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0xcULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vaddn_fp32_tb_softfloat___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void Vaddn_fp32_tb_softfloat___024root___act_comb__TOP__0(Vaddn_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root___act_comb__TOP__0\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_21;
    VlWide<3>/*95:0*/ __Vtemp_22;
    VlWide<3>/*95:0*/ __Vtemp_27;
    VlWide<3>/*95:0*/ __Vtemp_41;
    VlWide<3>/*95:0*/ __Vtemp_42;
    VlWide<3>/*95:0*/ __Vtemp_47;
    VlWide<3>/*95:0*/ __Vtemp_61;
    VlWide<3>/*95:0*/ __Vtemp_62;
    VlWide<3>/*95:0*/ __Vtemp_67;
    VlWide<3>/*95:0*/ __Vtemp_82;
    VlWide<3>/*95:0*/ __Vtemp_84;
    VlWide<3>/*95:0*/ __Vtemp_88;
    VlWide<3>/*95:0*/ __Vtemp_90;
    VlWide<3>/*95:0*/ __Vtemp_94;
    VlWide<3>/*95:0*/ __Vtemp_96;
    VlWide<3>/*95:0*/ __Vtemp_100;
    VlWide<3>/*95:0*/ __Vtemp_102;
    VlWide<3>/*95:0*/ __Vtemp_106;
    VlWide<3>/*95:0*/ __Vtemp_108;
    VlWide<3>/*95:0*/ __Vtemp_112;
    VlWide<3>/*95:0*/ __Vtemp_114;
    // Body
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__is_nan_any = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_pos_inf = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_neg_inf = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in[0U] 
        = ((0U == (0xffU & (vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U])
            : vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign[0U] 
        = (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in
           [0U] >> 0x1fU);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp[0U] 
        = (0xffU & (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in
                    [0U] >> 0x17U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac[0U] 
        = (0x7fffffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in
           [0U]);
    if (((0xffU == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
          [0U]) & (0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                   [0U]))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
           [0U]) & (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign
                    [0U])) & (~ (IData)((0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                                         [0U]))))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
           [0U]) & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign
          [0U]) & (~ (IData)((0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                              [0U]))))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_neg_inf = 1U;
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in[1U] 
        = ((0U == (0xffU & (vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U])
            : vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign[1U] 
        = (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in
           [1U] >> 0x1fU);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp[1U] 
        = (0xffU & (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in
                    [1U] >> 0x17U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac[1U] 
        = (0x7fffffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in
           [1U]);
    if (((0xffU == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
          [1U]) & (0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                   [1U]))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
           [1U]) & (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign
                    [1U])) & (~ (IData)((0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                                         [1U]))))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
           [1U]) & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign
          [1U]) & (~ (IData)((0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                              [1U]))))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_neg_inf = 1U;
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in[2U] 
        = ((0U == (0xffU & (vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U])
            : vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign[2U] 
        = (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in
           [2U] >> 0x1fU);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp[2U] 
        = (0xffU & (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in
                    [2U] >> 0x17U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac[2U] 
        = (0x7fffffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in
           [2U]);
    if (((0xffU == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
          [2U]) & (0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                   [2U]))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
           [2U]) & (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign
                    [2U])) & (~ (IData)((0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                                         [2U]))))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
           [2U]) & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign
          [2U]) & (~ (IData)((0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                              [2U]))))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_neg_inf = 1U;
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in[3U] 
        = ((0U == (0xffU & (vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U])
            : vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign[3U] 
        = (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in
           [3U] >> 0x1fU);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp[3U] 
        = (0xffU & (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in
                    [3U] >> 0x17U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac[3U] 
        = (0x7fffffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in
           [3U]);
    if (((0xffU == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
          [3U]) & (0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                   [3U]))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
           [3U]) & (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign
                    [3U])) & (~ (IData)((0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                                         [3U]))))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
           [3U]) & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign
          [3U]) & (~ (IData)((0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                              [3U]))))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_neg_inf = 1U;
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp[0U][0U] 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
        [0U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx[0U][0U] = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp[0U][1U] 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
        [1U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx[0U][1U] = 1U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp[0U][2U] 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
        [2U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx[0U][2U] = 2U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp[0U][3U] 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
        [3U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx[0U][3U] = 3U;
    if ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
         [0U][0U] >= vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
         [0U][1U])) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h3dde53fc__0 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
            [0U][0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h00fc99f2__0 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
            [0U][0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp[1U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h3dde53fc__0;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx[1U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h00fc99f2__0;
    } else {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h3dde53fc__1 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
            [0U][1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h00fc99f2__1 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
            [0U][1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp[1U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h3dde53fc__1;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx[1U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h00fc99f2__1;
    }
    if ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
         [0U][2U] >= vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
         [0U][3U])) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h3dde53fc__0 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
            [0U][2U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h00fc99f2__0 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
            [0U][2U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp[1U][1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h3dde53fc__0;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx[1U][1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h00fc99f2__0;
    } else {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h3dde53fc__1 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
            [0U][3U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h00fc99f2__1 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
            [0U][3U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp[1U][1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h3dde53fc__1;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx[1U][1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h00fc99f2__1;
    }
    if ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
         [1U][0U] >= vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
         [1U][1U])) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h3dde53fc__0 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
            [1U][0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h00fc99f2__0 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
            [1U][0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp[2U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h3dde53fc__0;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx[2U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h00fc99f2__0;
    } else {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h3dde53fc__1 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
            [1U][1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h00fc99f2__1 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
            [1U][1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp[2U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h3dde53fc__1;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx[2U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h00fc99f2__1;
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_exp 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
        [2U][0U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_idx 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
        [2U][0U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign_max 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign
        [vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_idx];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__special_case = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_neg_inf)))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__special_case = 1U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_pos_inf) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__special_case = 1U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_neg_inf) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__special_case = 1U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__special_result = 0xff800000U;
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_exp_eff 
        = ((0U == (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_exp))
            ? 1U : (0xffU & (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_exp)));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[0U][0U] = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[0U][1U] 
        = (0xfffc0000U & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
           [0U][1U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[0U][1U] 
        = ((0x3ffffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
            [0U][1U]) | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                         [0U] << 0x12U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[0U][2U] 
        = ((0x200U & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
            [0U][2U]) | (0x3ffU & (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                                   [0U] >> 0xeU)));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[0U][2U] 
        = ((0x1ffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
            [0U][2U]) | (0x3ffU & ((IData)((0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
                                            [0U])) 
                                   << 9U)));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift[0U] 
        = (0x1ffU & ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_exp_eff) 
                     - ((0U == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
                         [0U]) ? 1U : vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
                        [0U])));
    __Vtemp_1[0U] = 0xffffffffU;
    __Vtemp_1[1U] = 0xffffffffU;
    __Vtemp_1[2U] = 0x3ffU;
    VL_SHIFTL_WWI(74,74,9, __Vtemp_2, __Vtemp_1, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift
                  [0U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sticky[0U] 
        = (0U != (((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                    [0U][0U] & (~ __Vtemp_2[0U])) | 
                   (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                    [0U][1U] & (~ __Vtemp_2[1U]))) 
                  | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                     [0U][2U] & (~ __Vtemp_2[2U]))));
    VL_SHIFTR_WWI(74,74,9, __Vtemp_7, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                  [0U], vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift
                  [0U]);
    if ((0x4aU <= vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift
         [0U])) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[0U][0U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[0U][1U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[0U][2U] = 0U;
    } else {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[0U][0U] 
            = __Vtemp_7[0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[0U][1U] 
            = __Vtemp_7[1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[0U][2U] 
            = (0x3ffU & __Vtemp_7[2U]);
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff[0U] 
        = ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign_max) 
           ^ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign
           [0U]);
    if ((0U == (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_idx))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[0U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [0U][0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[0U][1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [0U][1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[0U][2U] 
            = (0x1fffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [0U][2U]);
    } else if (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff
               [0U]) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[0U][0U] 
            = (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [0U][0U]);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[0U][1U] 
            = (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [0U][1U]);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[0U][2U] 
            = (0x1fffU & (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
                          [0U][2U]));
    } else {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[0U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [0U][0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[0U][1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [0U][1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[0U][2U] 
            = (0x1fffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [0U][2U]);
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[1U][0U] = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[1U][1U] 
        = (0xfffc0000U & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
           [1U][1U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[1U][1U] 
        = ((0x3ffffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
            [1U][1U]) | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                         [1U] << 0x12U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[1U][2U] 
        = ((0x200U & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
            [1U][2U]) | (0x3ffU & (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                                   [1U] >> 0xeU)));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[1U][2U] 
        = ((0x1ffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
            [1U][2U]) | (0x3ffU & ((IData)((0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
                                            [1U])) 
                                   << 9U)));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift[1U] 
        = (0x1ffU & ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_exp_eff) 
                     - ((0U == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
                         [1U]) ? 1U : vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
                        [1U])));
    __Vtemp_21[0U] = 0xffffffffU;
    __Vtemp_21[1U] = 0xffffffffU;
    __Vtemp_21[2U] = 0x3ffU;
    VL_SHIFTL_WWI(74,74,9, __Vtemp_22, __Vtemp_21, 
                  vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift
                  [1U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sticky[1U] 
        = (0U != (((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                    [1U][0U] & (~ __Vtemp_22[0U])) 
                   | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                      [1U][1U] & (~ __Vtemp_22[1U]))) 
                  | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                     [1U][2U] & (~ __Vtemp_22[2U]))));
    VL_SHIFTR_WWI(74,74,9, __Vtemp_27, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                  [1U], vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift
                  [1U]);
    if ((0x4aU <= vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift
         [1U])) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[1U][0U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[1U][1U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[1U][2U] = 0U;
    } else {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[1U][0U] 
            = __Vtemp_27[0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[1U][1U] 
            = __Vtemp_27[1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[1U][2U] 
            = (0x3ffU & __Vtemp_27[2U]);
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff[1U] 
        = ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign_max) 
           ^ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign
           [1U]);
    if ((1U == (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_idx))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[1U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [1U][0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[1U][1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [1U][1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[1U][2U] 
            = (0x1fffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [1U][2U]);
    } else if (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff
               [1U]) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[1U][0U] 
            = (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [1U][0U]);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[1U][1U] 
            = (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [1U][1U]);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[1U][2U] 
            = (0x1fffU & (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
                          [1U][2U]));
    } else {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[1U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [1U][0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[1U][1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [1U][1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[1U][2U] 
            = (0x1fffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [1U][2U]);
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[2U][0U] = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[2U][1U] 
        = (0xfffc0000U & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
           [2U][1U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[2U][1U] 
        = ((0x3ffffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
            [2U][1U]) | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                         [2U] << 0x12U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[2U][2U] 
        = ((0x200U & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
            [2U][2U]) | (0x3ffU & (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                                   [2U] >> 0xeU)));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[2U][2U] 
        = ((0x1ffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
            [2U][2U]) | (0x3ffU & ((IData)((0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
                                            [2U])) 
                                   << 9U)));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift[2U] 
        = (0x1ffU & ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_exp_eff) 
                     - ((0U == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
                         [2U]) ? 1U : vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
                        [2U])));
    __Vtemp_41[0U] = 0xffffffffU;
    __Vtemp_41[1U] = 0xffffffffU;
    __Vtemp_41[2U] = 0x3ffU;
    VL_SHIFTL_WWI(74,74,9, __Vtemp_42, __Vtemp_41, 
                  vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift
                  [2U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sticky[2U] 
        = (0U != (((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                    [2U][0U] & (~ __Vtemp_42[0U])) 
                   | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                      [2U][1U] & (~ __Vtemp_42[1U]))) 
                  | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                     [2U][2U] & (~ __Vtemp_42[2U]))));
    VL_SHIFTR_WWI(74,74,9, __Vtemp_47, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                  [2U], vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift
                  [2U]);
    if ((0x4aU <= vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift
         [2U])) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[2U][0U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[2U][1U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[2U][2U] = 0U;
    } else {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[2U][0U] 
            = __Vtemp_47[0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[2U][1U] 
            = __Vtemp_47[1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[2U][2U] 
            = (0x3ffU & __Vtemp_47[2U]);
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff[2U] 
        = ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign_max) 
           ^ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign
           [2U]);
    if ((2U == (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_idx))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[2U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [2U][0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[2U][1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [2U][1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[2U][2U] 
            = (0x1fffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [2U][2U]);
    } else if (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff
               [2U]) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[2U][0U] 
            = (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [2U][0U]);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[2U][1U] 
            = (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [2U][1U]);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[2U][2U] 
            = (0x1fffU & (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
                          [2U][2U]));
    } else {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[2U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [2U][0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[2U][1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [2U][1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[2U][2U] 
            = (0x1fffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [2U][2U]);
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[3U][0U] = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[3U][1U] 
        = (0xfffc0000U & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
           [3U][1U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[3U][1U] 
        = ((0x3ffffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
            [3U][1U]) | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                         [3U] << 0x12U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[3U][2U] 
        = ((0x200U & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
            [3U][2U]) | (0x3ffU & (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                                   [3U] >> 0xeU)));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[3U][2U] 
        = ((0x1ffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
            [3U][2U]) | (0x3ffU & ((IData)((0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
                                            [3U])) 
                                   << 9U)));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift[3U] 
        = (0x1ffU & ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_exp_eff) 
                     - ((0U == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
                         [3U]) ? 1U : vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
                        [3U])));
    __Vtemp_61[0U] = 0xffffffffU;
    __Vtemp_61[1U] = 0xffffffffU;
    __Vtemp_61[2U] = 0x3ffU;
    VL_SHIFTL_WWI(74,74,9, __Vtemp_62, __Vtemp_61, 
                  vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift
                  [3U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sticky[3U] 
        = (0U != (((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                    [3U][0U] & (~ __Vtemp_62[0U])) 
                   | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                      [3U][1U] & (~ __Vtemp_62[1U]))) 
                  | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                     [3U][2U] & (~ __Vtemp_62[2U]))));
    VL_SHIFTR_WWI(74,74,9, __Vtemp_67, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                  [3U], vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift
                  [3U]);
    if ((0x4aU <= vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift
         [3U])) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[3U][0U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[3U][1U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[3U][2U] = 0U;
    } else {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[3U][0U] 
            = __Vtemp_67[0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[3U][1U] 
            = __Vtemp_67[1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[3U][2U] 
            = (0x3ffU & __Vtemp_67[2U]);
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff[3U] 
        = ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign_max) 
           ^ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign
           [3U]);
    if ((3U == (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_idx))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[3U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [3U][0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[3U][1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [3U][1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[3U][2U] 
            = (0x1fffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [3U][2U]);
    } else if (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff
               [3U]) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[3U][0U] 
            = (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [3U][0U]);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[3U][1U] 
            = (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [3U][1U]);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[3U][2U] 
            = (0x1fffU & (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
                          [3U][2U]));
    } else {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[3U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [3U][0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[3U][1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [3U][1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[3U][2U] 
            = (0x1fffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [3U][2U]);
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[0U][0U] 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
        [0U][0U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[0U][1U] 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
        [0U][1U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[0U][2U] 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
        [0U][2U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[0U][0U] = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[0U][1U] = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[0U][2U] = 0U;
    VL_SHIFTL_WWI(77,77,32, __Vtemp_84, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c
                  [0U], 1U);
    __Vtemp_82[1U] = ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
                       [0U][1U] ^ __Vtemp_84[1U]) ^ 
                      vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                      [1U][1U]);
    __Vtemp_82[2U] = (0x1fffU & ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
                                  [0U][2U] ^ __Vtemp_84[2U]) 
                                 ^ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                                 [1U][2U]));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[1U][0U] 
        = ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
            [0U][0U] ^ __Vtemp_84[0U]) ^ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
           [1U][0U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[1U][1U] 
        = __Vtemp_82[1U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[1U][2U] 
        = __Vtemp_82[2U];
    VL_SHIFTL_WWI(77,77,32, __Vtemp_88, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c
                  [0U], 1U);
    VL_SHIFTL_WWI(77,77,32, __Vtemp_90, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c
                  [0U], 1U);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[1U][0U] 
        = (((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
             [0U][0U] & __Vtemp_88[0U]) | (__Vtemp_90[0U] 
                                           & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                                           [1U][0U])) 
           | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
              [1U][0U] & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
              [0U][0U]));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[1U][1U] 
        = (((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
             [0U][1U] & __Vtemp_88[1U]) | (__Vtemp_90[1U] 
                                           & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                                           [1U][1U])) 
           | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
              [1U][1U] & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
              [0U][1U]));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[1U][2U] 
        = (((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
             [0U][2U] & __Vtemp_88[2U]) | (__Vtemp_90[2U] 
                                           & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                                           [1U][2U])) 
           | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
              [1U][2U] & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
              [0U][2U]));
    VL_SHIFTL_WWI(77,77,32, __Vtemp_96, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c
                  [1U], 1U);
    __Vtemp_94[1U] = ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
                       [1U][1U] ^ __Vtemp_96[1U]) ^ 
                      vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                      [2U][1U]);
    __Vtemp_94[2U] = (0x1fffU & ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
                                  [1U][2U] ^ __Vtemp_96[2U]) 
                                 ^ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                                 [2U][2U]));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[2U][0U] 
        = ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
            [1U][0U] ^ __Vtemp_96[0U]) ^ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
           [2U][0U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[2U][1U] 
        = __Vtemp_94[1U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[2U][2U] 
        = __Vtemp_94[2U];
    VL_SHIFTL_WWI(77,77,32, __Vtemp_100, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c
                  [1U], 1U);
    VL_SHIFTL_WWI(77,77,32, __Vtemp_102, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c
                  [1U], 1U);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[2U][0U] 
        = (((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
             [1U][0U] & __Vtemp_100[0U]) | (__Vtemp_102[0U] 
                                            & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                                            [2U][0U])) 
           | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
              [2U][0U] & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
              [1U][0U]));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[2U][1U] 
        = (((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
             [1U][1U] & __Vtemp_100[1U]) | (__Vtemp_102[1U] 
                                            & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                                            [2U][1U])) 
           | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
              [2U][1U] & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
              [1U][1U]));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[2U][2U] 
        = (((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
             [1U][2U] & __Vtemp_100[2U]) | (__Vtemp_102[2U] 
                                            & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                                            [2U][2U])) 
           | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
              [2U][2U] & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
              [1U][2U]));
    VL_SHIFTL_WWI(77,77,32, __Vtemp_108, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c
                  [2U], 1U);
    __Vtemp_106[1U] = ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
                        [2U][1U] ^ __Vtemp_108[1U]) 
                       ^ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                       [3U][1U]);
    __Vtemp_106[2U] = (0x1fffU & ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
                                   [2U][2U] ^ __Vtemp_108[2U]) 
                                  ^ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                                  [3U][2U]));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[3U][0U] 
        = ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
            [2U][0U] ^ __Vtemp_108[0U]) ^ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
           [3U][0U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[3U][1U] 
        = __Vtemp_106[1U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[3U][2U] 
        = __Vtemp_106[2U];
    VL_SHIFTL_WWI(77,77,32, __Vtemp_112, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c
                  [2U], 1U);
    VL_SHIFTL_WWI(77,77,32, __Vtemp_114, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c
                  [2U], 1U);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[3U][0U] 
        = (((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
             [2U][0U] & __Vtemp_112[0U]) | (__Vtemp_114[0U] 
                                            & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                                            [3U][0U])) 
           | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
              [3U][0U] & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
              [2U][0U]));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[3U][1U] 
        = (((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
             [2U][1U] & __Vtemp_112[1U]) | (__Vtemp_114[1U] 
                                            & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                                            [3U][1U])) 
           | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
              [3U][1U] & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
              [2U][1U]));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[3U][2U] 
        = (((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
             [2U][2U] & __Vtemp_112[2U]) | (__Vtemp_114[2U] 
                                            & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                                            [3U][2U])) 
           | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
              [3U][2U] & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
              [2U][2U]));
}

void Vaddn_fp32_tb_softfloat___024root___nba_sequent__TOP__0(Vaddn_fp32_tb_softfloat___024root* vlSelf);

void Vaddn_fp32_tb_softfloat___024root___eval_nba(Vaddn_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root___eval_nba\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vaddn_fp32_tb_softfloat___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((0xcULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vaddn_fp32_tb_softfloat___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
}

VL_INLINE_OPT void Vaddn_fp32_tb_softfloat___024root___nba_sequent__TOP__0(Vaddn_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root___nba_sequent__TOP__0\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vdly__addn_fp32_tb_softfloat__DOT__dut__DOT__st1_align_sticky;
    __Vdly__addn_fp32_tb_softfloat__DOT__dut__DOT__st1_align_sticky = 0;
    CData/*2:0*/ __Vdly__addn_fp32_tb_softfloat__DOT__dut__DOT__st1_hot_ones;
    __Vdly__addn_fp32_tb_softfloat__DOT__dut__DOT__st1_hot_ones = 0;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_8;
    VlWide<3>/*95:0*/ __Vtemp_10;
    VlWide<3>/*95:0*/ __Vtemp_13;
    VlWide<3>/*95:0*/ __Vtemp_14;
    VlWide<3>/*95:0*/ __Vtemp_15;
    VlWide<3>/*95:0*/ __Vtemp_17;
    VlWide<3>/*95:0*/ __Vtemp_18;
    VlWide<3>/*95:0*/ __Vtemp_20;
    VlWide<3>/*95:0*/ __Vtemp_21;
    VlWide<3>/*95:0*/ __Vtemp_23;
    VlWide<3>/*95:0*/ __Vtemp_25;
    VlWide<3>/*95:0*/ __Vtemp_26;
    VlWide<3>/*95:0*/ __Vtemp_32;
    VlWide<3>/*95:0*/ __Vtemp_37;
    VlWide<3>/*95:0*/ __Vtemp_40;
    VlWide<3>/*95:0*/ __Vtemp_45;
    VlWide<3>/*95:0*/ __Vtemp_48;
    VlWide<3>/*95:0*/ __Vtemp_53;
    VlWide<3>/*95:0*/ __Vtemp_56;
    VlWide<3>/*95:0*/ __Vtemp_61;
    VlWide<3>/*95:0*/ __Vtemp_64;
    VlWide<3>/*95:0*/ __Vtemp_69;
    VlWide<3>/*95:0*/ __Vtemp_72;
    VlWide<3>/*95:0*/ __Vtemp_77;
    VlWide<3>/*95:0*/ __Vtemp_80;
    VlWide<3>/*95:0*/ __Vtemp_85;
    VlWide<3>/*95:0*/ __Vtemp_87;
    // Body
    __Vdly__addn_fp32_tb_softfloat__DOT__dut__DOT__st1_align_sticky 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_align_sticky;
    __Vdly__addn_fp32_tb_softfloat__DOT__dut__DOT__st1_hot_ones 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_hot_ones;
    if (vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_nrst) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__unnamedblk7__DOT__i = 4U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__unnamedblk8__DOT__i = 4U;
        __Vdly__addn_fp32_tb_softfloat__DOT__dut__DOT__st1_align_sticky = 0U;
        if ((0U != (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_idx))) {
            __Vdly__addn_fp32_tb_softfloat__DOT__dut__DOT__st1_align_sticky 
                = ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_align_sticky) 
                   | vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sticky
                   [0U]);
        }
        if ((1U != (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_idx))) {
            __Vdly__addn_fp32_tb_softfloat__DOT__dut__DOT__st1_align_sticky 
                = ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_align_sticky) 
                   | vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sticky
                   [1U]);
        }
        if ((2U != (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_idx))) {
            __Vdly__addn_fp32_tb_softfloat__DOT__dut__DOT__st1_align_sticky 
                = ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_align_sticky) 
                   | vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sticky
                   [2U]);
        }
        if ((3U != (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_idx))) {
            __Vdly__addn_fp32_tb_softfloat__DOT__dut__DOT__st1_align_sticky 
                = ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_align_sticky) 
                   | vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sticky
                   [3U]);
        }
        __Vdly__addn_fp32_tb_softfloat__DOT__dut__DOT__st1_hot_ones = 0U;
        if (((0U != (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_idx)) 
             & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff
             [0U])) {
            __Vdly__addn_fp32_tb_softfloat__DOT__dut__DOT__st1_hot_ones 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_hot_ones)));
        }
        if (((1U != (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_idx)) 
             & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff
             [1U])) {
            __Vdly__addn_fp32_tb_softfloat__DOT__dut__DOT__st1_hot_ones 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_hot_ones)));
        }
        if (((2U != (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_idx)) 
             & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff
             [2U])) {
            __Vdly__addn_fp32_tb_softfloat__DOT__dut__DOT__st1_hot_ones 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_hot_ones)));
        }
        if (((3U != (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_idx)) 
             & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff
             [3U])) {
            __Vdly__addn_fp32_tb_softfloat__DOT__dut__DOT__st1_hot_ones 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_hot_ones)));
        }
        vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__result_out;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mag_sum[0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mag_sum[1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[2U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mag_sum[2U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_carry_vec[0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c
            [3U][0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_carry_vec[1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c
            [3U][1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_carry_vec[2U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c
            [3U][2U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_sum_vec[0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
            [3U][0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_sum_vec[1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
            [3U][1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_sum_vec[2U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
            [3U][2U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_exp_base 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_a_e;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_spec_res 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_special_result;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_a_e 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_exp;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_special_result 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__special_result;
    } else {
        __Vdly__addn_fp32_tb_softfloat__DOT__dut__DOT__st1_align_sticky = 0U;
        __Vdly__addn_fp32_tb_softfloat__DOT__dut__DOT__st1_hot_ones = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[0U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[1U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[2U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_carry_vec[0U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_carry_vec[1U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_carry_vec[2U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_sum_vec[0U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_sum_vec[1U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_sum_vec[2U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_exp_base = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_spec_res = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_a_e = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_special_result = 0U;
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sticky 
        = ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_align_sticky));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__res_sign));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_a_s 
        = ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign_max));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_special 
        = ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_special_case));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_hot_ones 
        = __Vdly__addn_fp32_tb_softfloat__DOT__dut__DOT__st1_hot_ones;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_align_sticky 
        = __Vdly__addn_fp32_tb_softfloat__DOT__dut__DOT__st1_align_sticky;
    if ((0U != ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[0U] 
                 | vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[1U]) 
                | vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[2U]))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__stage3_logic__DOT__unnamedblk9__DOT__i = 0xffffffffU;
    }
    __Vtemp_7[0U] = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_sum_vec[0U];
    __Vtemp_7[1U] = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_sum_vec[1U];
    __Vtemp_7[2U] = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_sum_vec[2U];
    VL_EXTENDS_WW(79,78, __Vtemp_8, __Vtemp_7);
    __Vtemp_10[0U] = __Vtemp_8[0U];
    __Vtemp_10[1U] = __Vtemp_8[1U];
    __Vtemp_10[2U] = (0x7fffU & __Vtemp_8[2U]);
    VL_SHIFTL_WWI(77,77,32, __Vtemp_13, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_carry_vec, 1U);
    __Vtemp_14[0U] = __Vtemp_13[0U];
    __Vtemp_14[1U] = __Vtemp_13[1U];
    __Vtemp_14[2U] = (0x1fffU & __Vtemp_13[2U]);
    VL_EXTENDS_WW(79,77, __Vtemp_15, __Vtemp_14);
    __Vtemp_17[0U] = __Vtemp_15[0U];
    __Vtemp_17[1U] = __Vtemp_15[1U];
    __Vtemp_17[2U] = (0x7fffU & __Vtemp_15[2U]);
    VL_ADD_W(3, __Vtemp_18, __Vtemp_10, __Vtemp_17);
    __Vtemp_20[0U] = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_hot_ones;
    __Vtemp_20[1U] = 0U;
    __Vtemp_20[2U] = 0U;
    VL_ADD_W(3, __Vtemp_21, __Vtemp_18, __Vtemp_20);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__raw_sum[0U] 
        = __Vtemp_21[0U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__raw_sum[1U] 
        = __Vtemp_21[1U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__raw_sum[2U] 
        = (0x3fffU & __Vtemp_21[2U]);
    if ((0x1000U & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__raw_sum[2U])) {
        __Vtemp_23[0U] = 1U;
        __Vtemp_23[1U] = 0U;
        __Vtemp_23[2U] = 0U;
        __Vtemp_25[0U] = (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__raw_sum[0U]);
        __Vtemp_25[1U] = (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__raw_sum[1U]);
        __Vtemp_25[2U] = (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__raw_sum[2U]);
        VL_ADD_W(3, __Vtemp_26, __Vtemp_23, __Vtemp_25);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mag_sum[0U] 
            = __Vtemp_26[0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mag_sum[1U] 
            = __Vtemp_26[1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mag_sum[2U] 
            = (0xfffU & __Vtemp_26[2U]);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_a_s)));
    } else {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mag_sum[0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__raw_sum[0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mag_sum[1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__raw_sum[1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mag_sum[2U] 
            = (0xfffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__raw_sum[2U]);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__res_sign 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_a_s;
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_special_case 
        = ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__special_case));
    if ((0U == ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[0U] 
                 | vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[1U]) 
                | vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[2U]))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[0U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[1U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[2U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros = 0x4bU;
    } else {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[2U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[2U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros = 0U;
        VL_SHIFTR_WWI(76,76,32, __Vtemp_32, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 0xcU);
        if ((0U == ((__Vtemp_32[0U] | __Vtemp_32[1U]) 
                    | (0xfffU & __Vtemp_32[2U])))) {
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros 
                = (0xffU & ((IData)(0x40U) + (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros)));
            VL_SHIFTL_WWI(76,76,32, __Vtemp_37, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 0x40U);
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[0U] 
                = __Vtemp_37[0U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[1U] 
                = __Vtemp_37[1U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[2U] 
                = (0xfffU & __Vtemp_37[2U]);
        }
        VL_SHIFTR_WWI(76,76,32, __Vtemp_40, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 0x2cU);
        if ((0U == ((__Vtemp_40[0U] | __Vtemp_40[1U]) 
                    | (0xfffU & __Vtemp_40[2U])))) {
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros 
                = (0xffU & ((IData)(0x20U) + (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros)));
            VL_SHIFTL_WWI(76,76,32, __Vtemp_45, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 0x20U);
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[0U] 
                = __Vtemp_45[0U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[1U] 
                = __Vtemp_45[1U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[2U] 
                = (0xfffU & __Vtemp_45[2U]);
        }
        VL_SHIFTR_WWI(76,76,32, __Vtemp_48, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 0x3cU);
        if ((0U == ((__Vtemp_48[0U] | __Vtemp_48[1U]) 
                    | (0xfffU & __Vtemp_48[2U])))) {
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros 
                = (0xffU & ((IData)(0x10U) + (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros)));
            VL_SHIFTL_WWI(76,76,32, __Vtemp_53, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 0x10U);
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[0U] 
                = __Vtemp_53[0U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[1U] 
                = __Vtemp_53[1U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[2U] 
                = (0xfffU & __Vtemp_53[2U]);
        }
        VL_SHIFTR_WWI(76,76,32, __Vtemp_56, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 0x44U);
        if ((0U == ((__Vtemp_56[0U] | __Vtemp_56[1U]) 
                    | (0xfffU & __Vtemp_56[2U])))) {
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros 
                = (0xffU & ((IData)(8U) + (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros)));
            VL_SHIFTL_WWI(76,76,32, __Vtemp_61, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 8U);
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[0U] 
                = __Vtemp_61[0U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[1U] 
                = __Vtemp_61[1U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[2U] 
                = (0xfffU & __Vtemp_61[2U]);
        }
        VL_SHIFTR_WWI(76,76,32, __Vtemp_64, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 0x48U);
        if ((0U == ((__Vtemp_64[0U] | __Vtemp_64[1U]) 
                    | (0xfffU & __Vtemp_64[2U])))) {
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros 
                = (0xffU & ((IData)(4U) + (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros)));
            VL_SHIFTL_WWI(76,76,32, __Vtemp_69, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 4U);
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[0U] 
                = __Vtemp_69[0U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[1U] 
                = __Vtemp_69[1U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[2U] 
                = (0xfffU & __Vtemp_69[2U]);
        }
        VL_SHIFTR_WWI(76,76,32, __Vtemp_72, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 0x4aU);
        if ((0U == ((__Vtemp_72[0U] | __Vtemp_72[1U]) 
                    | (0xfffU & __Vtemp_72[2U])))) {
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros 
                = (0xffU & ((IData)(2U) + (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros)));
            VL_SHIFTL_WWI(76,76,32, __Vtemp_77, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 2U);
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[0U] 
                = __Vtemp_77[0U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[1U] 
                = __Vtemp_77[1U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[2U] 
                = (0xfffU & __Vtemp_77[2U]);
        }
        VL_SHIFTR_WWI(76,76,32, __Vtemp_80, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 0x4bU);
        if ((0U == ((__Vtemp_80[0U] | __Vtemp_80[1U]) 
                    | (0xfffU & __Vtemp_80[2U])))) {
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros 
                = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros)));
            VL_SHIFTL_WWI(76,76,32, __Vtemp_85, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 1U);
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[0U] 
                = __Vtemp_85[0U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[1U] 
                = __Vtemp_85[1U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[2U] 
                = (0xfffU & __Vtemp_85[2U]);
        }
    }
    VL_SHIFTL_WWI(76,76,8, __Vtemp_87, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag, (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__norm_val[0U] 
        = __Vtemp_87[0U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__norm_val[1U] 
        = __Vtemp_87[1U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__norm_val[2U] 
        = (0xfffU & __Vtemp_87[2U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__final_mant 
        = (0x7fffffU & ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__norm_val[2U] 
                         << 0xcU) | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__norm_val[1U] 
                                     >> 0x14U)));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(2U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,10, (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros))));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__result_out 
        = ((((0U == ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[0U] 
                      | vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[1U]) 
                     | vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[2U])) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_exp_base)))
            ? 0U : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__final_exp_calc)))
                     ? (0x7f800000U | ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_res_sign) 
                                       << 0x1fU)) : 
                    (((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_res_sign) 
                      << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__final_exp_calc) 
                                                   << 0x17U)) 
                                   | vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__final_mant))));
    if (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_special) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__result_out 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_spec_res;
    }
}

void Vaddn_fp32_tb_softfloat___024root___timing_resume(Vaddn_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root___timing_resume\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hd66bd573__0.resume(
                                                   "@(negedge addn_fp32_tb_softfloat.tb_clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vaddn_fp32_tb_softfloat___024root___timing_commit(Vaddn_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root___timing_commit\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (8ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hd66bd573__0.commit(
                                                   "@(negedge addn_fp32_tb_softfloat.tb_clk)");
    }
}

void Vaddn_fp32_tb_softfloat___024root___eval_triggers__act(Vaddn_fp32_tb_softfloat___024root* vlSelf);

bool Vaddn_fp32_tb_softfloat___024root___eval_phase__act(Vaddn_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root___eval_phase__act\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vaddn_fp32_tb_softfloat___024root___eval_triggers__act(vlSelf);
    Vaddn_fp32_tb_softfloat___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vaddn_fp32_tb_softfloat___024root___timing_resume(vlSelf);
        Vaddn_fp32_tb_softfloat___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vaddn_fp32_tb_softfloat___024root___eval_phase__nba(Vaddn_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root___eval_phase__nba\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vaddn_fp32_tb_softfloat___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root___dump_triggers__nba(Vaddn_fp32_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root___dump_triggers__act(Vaddn_fp32_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG

void Vaddn_fp32_tb_softfloat___024root___eval(Vaddn_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root___eval\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vaddn_fp32_tb_softfloat___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 12, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vaddn_fp32_tb_softfloat___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 12, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vaddn_fp32_tb_softfloat___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vaddn_fp32_tb_softfloat___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vaddn_fp32_tb_softfloat___024root___eval_debug_assertions(Vaddn_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root___eval_debug_assertions\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
