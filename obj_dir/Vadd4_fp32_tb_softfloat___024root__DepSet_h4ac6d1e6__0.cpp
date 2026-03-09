// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd4_fp32_tb_softfloat.h for the primary calling header

#include "Vadd4_fp32_tb_softfloat__pch.h"
#include "Vadd4_fp32_tb_softfloat___024root.h"

VlCoroutine Vadd4_fp32_tb_softfloat___024root___eval_initial__TOP__Vtiming__0(Vadd4_fp32_tb_softfloat___024root* vlSelf);
VlCoroutine Vadd4_fp32_tb_softfloat___024root___eval_initial__TOP__Vtiming__1(Vadd4_fp32_tb_softfloat___024root* vlSelf);

void Vadd4_fp32_tb_softfloat___024root___eval_initial(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root___eval_initial\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vadd4_fp32_tb_softfloat___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vadd4_fp32_tb_softfloat___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vadd4_fp32_tb_softfloat___024root___eval_initial__TOP__Vtiming__1(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_clk = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                             nullptr, 
                                             "tb/unit/systolic_array/add4_fp32_tb_softfloat.sv", 
                                             34);
        vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_clk = 1U;
        co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                             nullptr, 
                                             "tb/unit/systolic_array/add4_fp32_tb_softfloat.sv", 
                                             36);
    }
}

void Vadd4_fp32_tb_softfloat___024root___act_comb__TOP__0(Vadd4_fp32_tb_softfloat___024root* vlSelf);

void Vadd4_fp32_tb_softfloat___024root___eval_act(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root___eval_act\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0xcULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadd4_fp32_tb_softfloat___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void Vadd4_fp32_tb_softfloat___024root___act_comb__TOP__0(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root___act_comb__TOP__0\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_10;
    VlWide<3>/*95:0*/ __Vtemp_11;
    VlWide<3>/*95:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_19;
    VlWide<3>/*95:0*/ __Vtemp_20;
    VlWide<3>/*95:0*/ __Vtemp_25;
    VlWide<3>/*95:0*/ __Vtemp_28;
    VlWide<3>/*95:0*/ __Vtemp_29;
    VlWide<3>/*95:0*/ __Vtemp_53;
    VlWide<3>/*95:0*/ __Vtemp_56;
    VlWide<3>/*95:0*/ __Vtemp_58;
    // Body
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz 
        = ((0U == (0xffU & (vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_a 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_a)
            : vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_a);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz 
        = ((0U == (0xffU & (vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_b 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_b)
            : vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_b);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz 
        = ((0U == (0xffU & (vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_c 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_c)
            : vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_c);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz 
        = ((0U == (0xffU & (vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_d 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_d)
            : vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_d);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a 
        = (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz 
           >> 0x1fU);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a 
        = (0xffU & (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz 
                    >> 0x17U));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a 
        = (0x7fffffU & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b 
        = (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz 
           >> 0x1fU);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b 
        = (0xffU & (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz 
                    >> 0x17U));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b 
        = (0x7fffffU & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c 
        = (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz 
           >> 0x1fU);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c 
        = (0xffU & (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz 
                    >> 0x17U));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c 
        = (0x7fffffU & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d 
        = (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz 
           >> 0x1fU);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d 
        = (0xffU & (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz 
                    >> 0x17U));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d 
        = (0x7fffffU & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a)) 
              & (0U != vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a)) 
             | ((0xffU == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b)) 
                & (0U != vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b))) 
            | ((0xffU == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c)) 
               & (0U != vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c))) 
           | ((0xffU == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d)) 
              & (0U != vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d)));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a))) 
              & (~ (IData)((0U != vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a)))) 
             | (((0xffU == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b))) 
                & (~ (IData)((0U != vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b))))) 
            | (((0xffU == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c))) 
               & (~ (IData)((0U != vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c))))) 
           | (((0xffU == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d))) 
              & (~ (IData)((0U != vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d)))));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a)) 
               & (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a)) 
              & (~ (IData)((0U != vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a)))) 
             | (((0xffU == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b)) 
                & (~ (IData)((0U != vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b))))) 
            | (((0xffU == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c)) 
                & (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c)) 
               & (~ (IData)((0U != vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c))))) 
           | (((0xffU == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d)) 
               & (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d)) 
              & (~ (IData)((0U != vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d)))));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = 0U;
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__any_neg_inf)))) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = 1U;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = 0xffc00000U;
    } else if (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__any_pos_inf) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = 1U;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__any_neg_inf) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = 1U;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a) 
         >= (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b))) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b;
    } else {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c) 
         >= (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d))) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d;
    } else {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p) 
         >= (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r))) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_y 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_mx 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_nx 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n;
    } else {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_y 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_mx 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_nx 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m;
    }
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x)));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y)));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx)));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx)));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y_eff)));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx_eff)));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx_eff)));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant[0U] = 0U;
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant[1U] 
        = (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x 
           << 0x13U);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant[2U] 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x))) 
            << 0xaU) | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x 
                        >> 0xdU));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base[0U] = 0U;
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base[1U] 
        = (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y 
           << 0x13U);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base[2U] 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y))) 
            << 0xaU) | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y 
                        >> 0xdU));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base[0U] = 0U;
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base[1U] 
        = (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx 
           << 0x13U);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base[2U] 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx))) 
            << 0xaU) | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx 
                        >> 0xdU));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base[0U] = 0U;
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base[1U] 
        = (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx 
           << 0x13U);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base[2U] 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx))) 
            << 0xaU) | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx 
                        >> 0xdU));
    VL_SHIFTR_WWI(75,75,9, __Vtemp_7, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base, (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift));
    if ((0x4bU <= (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift))) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted[0U] = 0U;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted[1U] = 0U;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted[2U] = 0U;
    } else {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted[0U] 
            = __Vtemp_7[0U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted[1U] 
            = __Vtemp_7[1U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted[2U] 
            = (0x7ffU & __Vtemp_7[2U]);
    }
    __Vtemp_10[0U] = 0xffffffffU;
    __Vtemp_10[1U] = 0xffffffffU;
    __Vtemp_10[2U] = 0x7ffU;
    VL_SHIFTL_WWI(75,75,9, __Vtemp_11, __Vtemp_10, (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_y 
        = (0U != (((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base[0U] 
                    & (~ __Vtemp_11[0U])) | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base[1U] 
                                             & (~ __Vtemp_11[1U]))) 
                  | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base[2U] 
                     & (~ __Vtemp_11[2U]))));
    VL_SHIFTR_WWI(75,75,9, __Vtemp_16, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base, (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift));
    if ((0x4bU <= (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift))) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted[0U] = 0U;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted[1U] = 0U;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted[2U] = 0U;
    } else {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted[0U] 
            = __Vtemp_16[0U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted[1U] 
            = __Vtemp_16[1U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted[2U] 
            = (0x7ffU & __Vtemp_16[2U]);
    }
    __Vtemp_19[0U] = 0xffffffffU;
    __Vtemp_19[1U] = 0xffffffffU;
    __Vtemp_19[2U] = 0x7ffU;
    VL_SHIFTL_WWI(75,75,9, __Vtemp_20, __Vtemp_19, (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_m 
        = (0U != (((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base[0U] 
                    & (~ __Vtemp_20[0U])) | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base[1U] 
                                             & (~ __Vtemp_20[1U]))) 
                  | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base[2U] 
                     & (~ __Vtemp_20[2U]))));
    VL_SHIFTR_WWI(75,75,9, __Vtemp_25, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base, (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift));
    if ((0x4bU <= (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift))) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted[0U] = 0U;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted[1U] = 0U;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted[2U] = 0U;
    } else {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted[0U] 
            = __Vtemp_25[0U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted[1U] 
            = __Vtemp_25[1U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted[2U] 
            = (0x7ffU & __Vtemp_25[2U]);
    }
    __Vtemp_28[0U] = 0xffffffffU;
    __Vtemp_28[1U] = 0xffffffffU;
    __Vtemp_28[2U] = 0x7ffU;
    VL_SHIFTL_WWI(75,75,9, __Vtemp_29, __Vtemp_28, (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_n 
        = (0U != (((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base[0U] 
                    & (~ __Vtemp_29[0U])) | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base[1U] 
                                             & (~ __Vtemp_29[1U]))) 
                  | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base[2U] 
                     & (~ __Vtemp_29[2U]))));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_op 
        = ((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_y));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_op 
        = ((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_mx));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_op 
        = ((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_nx));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x[0U] 
        = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant[0U];
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x[1U] 
        = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant[1U];
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x[2U] 
        = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant[2U];
    if (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_op) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[0U] 
            = (~ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted[0U]);
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[1U] 
            = (~ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted[1U]);
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[2U] 
            = (0x3fffU & (~ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted[2U]));
    } else {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[0U] 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted[0U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[1U] 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted[1U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[2U] 
            = (0x3fffU & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted[2U]);
    }
    if (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_op) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[0U] 
            = (~ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted[0U]);
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[1U] 
            = (~ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted[1U]);
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[2U] 
            = (0x3fffU & (~ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted[2U]));
    } else {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[0U] 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted[0U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[1U] 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted[1U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[2U] 
            = (0x3fffU & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted[2U]);
    }
    if (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_op) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[0U] 
            = (~ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted[0U]);
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[1U] 
            = (~ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted[1U]);
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[2U] 
            = (0x3fffU & (~ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted[2U]));
    } else {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[0U] 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted[0U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[1U] 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted[1U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[2U] 
            = (0x3fffU & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted[2U]);
    }
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1[0U] 
        = ((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x[0U] 
            ^ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[0U]) 
           ^ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[0U]);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1[1U] 
        = ((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x[1U] 
            ^ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[1U]) 
           ^ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[1U]);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1[2U] 
        = ((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x[2U] 
            ^ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[2U]) 
           ^ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[2U]);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c1[0U] 
        = (((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x[0U] 
             & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[0U]) 
            | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[0U] 
               & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[0U])) 
           | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[0U] 
              & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x[0U]));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c1[1U] 
        = (((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x[1U] 
             & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[1U]) 
            | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[1U] 
               & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[1U])) 
           | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[1U] 
              & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x[1U]));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c1[2U] 
        = (((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x[2U] 
             & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[2U]) 
            | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[2U] 
               & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[2U])) 
           | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[2U] 
              & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x[2U]));
    VL_SHIFTL_WWI(78,78,32, __Vtemp_53, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c1, 1U);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s2[0U] 
        = ((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1[0U] 
            ^ __Vtemp_53[0U]) ^ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[0U]);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s2[1U] 
        = ((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1[1U] 
            ^ __Vtemp_53[1U]) ^ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[1U]);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s2[2U] 
        = (0x3fffU & ((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1[2U] 
                       ^ __Vtemp_53[2U]) ^ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[2U]));
    VL_SHIFTL_WWI(78,78,32, __Vtemp_56, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c1, 1U);
    VL_SHIFTL_WWI(78,78,32, __Vtemp_58, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c1, 1U);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c2[0U] 
        = (((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1[0U] 
             & __Vtemp_56[0U]) | (__Vtemp_58[0U] & 
                                  vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[0U])) 
           | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[0U] 
              & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1[0U]));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c2[1U] 
        = (((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1[1U] 
             & __Vtemp_56[1U]) | (__Vtemp_58[1U] & 
                                  vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[1U])) 
           | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[1U] 
              & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1[1U]));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c2[2U] 
        = (((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1[2U] 
             & __Vtemp_56[2U]) | (__Vtemp_58[2U] & 
                                  vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[2U])) 
           | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[2U] 
              & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1[2U]));
}

void Vadd4_fp32_tb_softfloat___024root___nba_sequent__TOP__0(Vadd4_fp32_tb_softfloat___024root* vlSelf);

void Vadd4_fp32_tb_softfloat___024root___eval_nba(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root___eval_nba\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
        Vadd4_fp32_tb_softfloat___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0xcULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadd4_fp32_tb_softfloat___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
}

void Vadd4_fp32_tb_softfloat___024root___timing_resume(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root___timing_resume\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hdf4deb7b__0.resume(
                                                   "@(negedge add4_fp32_tb_softfloat.tb_clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vadd4_fp32_tb_softfloat___024root___timing_commit(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root___timing_commit\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (8ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hdf4deb7b__0.commit(
                                                   "@(negedge add4_fp32_tb_softfloat.tb_clk)");
    }
}

void Vadd4_fp32_tb_softfloat___024root___eval_triggers__act(Vadd4_fp32_tb_softfloat___024root* vlSelf);

bool Vadd4_fp32_tb_softfloat___024root___eval_phase__act(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root___eval_phase__act\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vadd4_fp32_tb_softfloat___024root___eval_triggers__act(vlSelf);
    Vadd4_fp32_tb_softfloat___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vadd4_fp32_tb_softfloat___024root___timing_resume(vlSelf);
        Vadd4_fp32_tb_softfloat___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vadd4_fp32_tb_softfloat___024root___eval_phase__nba(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root___eval_phase__nba\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vadd4_fp32_tb_softfloat___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root___dump_triggers__nba(Vadd4_fp32_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root___dump_triggers__act(Vadd4_fp32_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG

void Vadd4_fp32_tb_softfloat___024root___eval(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root___eval\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vadd4_fp32_tb_softfloat___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/unit/systolic_array/add4_fp32_tb_softfloat.sv", 21, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vadd4_fp32_tb_softfloat___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/unit/systolic_array/add4_fp32_tb_softfloat.sv", 21, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vadd4_fp32_tb_softfloat___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vadd4_fp32_tb_softfloat___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vadd4_fp32_tb_softfloat___024root___eval_debug_assertions(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root___eval_debug_assertions\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
