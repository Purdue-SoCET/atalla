// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd4_fp32accum_fp16_tb_softfloat.h for the primary calling header

#include "Vadd4_fp32accum_fp16_tb_softfloat__pch.h"
#include "Vadd4_fp32accum_fp16_tb_softfloat___024root.h"

VlCoroutine Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__0(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf);
VlCoroutine Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__1(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf);

void Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_initial(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_initial\n"); );
    Vadd4_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__1(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vadd4_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_clk = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                             nullptr, 
                                             "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                             36);
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_clk = 1U;
        co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                             nullptr, 
                                             "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                             38);
    }
}

void Vadd4_fp32accum_fp16_tb_softfloat___024root___act_comb__TOP__0(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf);

void Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_act(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_act\n"); );
    Vadd4_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0xcULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadd4_fp32accum_fp16_tb_softfloat___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void Vadd4_fp32accum_fp16_tb_softfloat___024root___act_comb__TOP__0(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_fp16_tb_softfloat___024root___act_comb__TOP__0\n"); );
    Vadd4_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz 
        = ((0U == (0x1fU & ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a) 
                            >> 0xaU))) ? (0x8000U & (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a))
            : (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz 
        = ((0U == (0x1fU & ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b) 
                            >> 0xaU))) ? (0x8000U & (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b))
            : (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz 
        = ((0U == (0x1fU & ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c) 
                            >> 0xaU))) ? (0x8000U & (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c))
            : (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz 
        = ((0U == (0x1fU & ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d) 
                            >> 0xaU))) ? (0x8000U & (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d))
            : (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz) 
                    >> 0xaU));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a 
        = (0x3ffU & (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz) 
                    >> 0xaU));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b 
        = (0x3ffU & (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz) 
                    >> 0xaU));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c 
        = (0x3ffU & (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz) 
                    >> 0xaU));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d 
        = (0x3ffU & (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_any 
        = (((((0x1fU == (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a))) 
             | ((0x1fU == (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b)))) 
            | ((0x1fU == (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c)))) 
           | ((0x1fU == (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d))));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__any_pos_inf 
        = ((((((0x1fU == (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a))))) 
             | (((0x1fU == (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b)))))) 
            | (((0x1fU == (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c)))))) 
           | (((0x1fU == (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d))))));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__any_neg_inf 
        = ((((((0x1fU == (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a)) 
               & (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a))))) 
             | (((0x1fU == (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b)))))) 
            | (((0x1fU == (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c)) 
                & (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c)))))) 
           | (((0x1fU == (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d)) 
               & (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d))))));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = 0U;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__any_neg_inf)))) {
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = 1U;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__any_pos_inf) {
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = 1U;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__any_neg_inf) {
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = 1U;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a) 
         >= (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b))) {
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b;
    } else {
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c) 
         >= (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d))) {
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d;
    } else {
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p) 
         >= (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r))) {
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_y 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_mx 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_nx 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n;
    } else {
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_y 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_mx 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_nx 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m;
    }
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x))
            ? 1U : (0x1fU & (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x)));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y))
            ? 1U : (0x1fU & (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y)));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx))
            ? 1U : (0x1fU & (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx)));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx))
            ? 1U : (0x1fU & (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx)));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift 
        = (0x3fU & ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff) 
                    - (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y_eff)));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift 
        = (0x3fU & ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff) 
                    - (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx_eff)));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift 
        = (0x3fU & ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff) 
                    - (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx_eff)));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x))) 
            << 0x18U) | ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x) 
                         << 0xeU));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y))) 
            << 0x18U) | ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y) 
                         << 0xeU));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx))) 
            << 0x18U) | ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx) 
                         << 0xeU));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx))) 
            << 0x18U) | ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx) 
                         << 0xeU));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_y 
        = (0U != (vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base 
                  & (~ VL_SHIFTL_III(25,25,6, (IData)(0x1ffffffU), (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift)))));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted 
        = ((0x19U <= (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift))
            ? 0U : (0x1ffffffU & VL_SHIFTR_III(32,32,6, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base, (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift))));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_m 
        = (0U != (vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base 
                  & (~ VL_SHIFTL_III(25,25,6, (IData)(0x1ffffffU), (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift)))));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted 
        = ((0x19U <= (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift))
            ? 0U : (0x1ffffffU & VL_SHIFTR_III(32,32,6, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base, (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift))));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_n 
        = (0U != (vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base 
                  & (~ VL_SHIFTL_III(25,25,6, (IData)(0x1ffffffU), (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift)))));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted 
        = ((0x19U <= (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift))
            ? 0U : (0x1ffffffU & VL_SHIFTR_III(32,32,6, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base, (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift))));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_op 
        = ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_y));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_op 
        = ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_mx));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_op 
        = ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_nx));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__op_x 
        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__op_y 
        = (0xfffffffU & ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_op)
                          ? (~ vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted)
                          : vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__op_m 
        = (0xfffffffU & ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_op)
                          ? (~ vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted)
                          : vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__op_n 
        = (0xfffffffU & ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_op)
                          ? (~ vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted)
                          : vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1 
        = ((vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__op_x 
            ^ vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__op_y) 
           ^ vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__op_m);
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c1 
        = (((vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__op_x 
             & vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__op_y) 
            | (vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__op_y 
               & vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__op_m)) 
           | (vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__op_m 
              & vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__op_x));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s2 
        = (0xfffffffU & ((vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1 
                          ^ VL_SHIFTL_III(28,28,32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c1, 1U)) 
                         ^ vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__op_n));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c2 
        = (((vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1 
             & VL_SHIFTL_III(28,28,32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c1, 1U)) 
            | (VL_SHIFTL_III(28,28,32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c1, 1U) 
               & vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__op_n)) 
           | (vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__op_n 
              & vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1));
}

void Vadd4_fp32accum_fp16_tb_softfloat___024root___nba_sequent__TOP__0(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf);
void Vadd4_fp32accum_fp16_tb_softfloat___024root___nba_sequent__TOP__1(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf);
void Vadd4_fp32accum_fp16_tb_softfloat___024root___nba_sequent__TOP__2(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf);

void Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_nba(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_nba\n"); );
    Vadd4_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadd4_fp32accum_fp16_tb_softfloat___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
        Vadd4_fp32accum_fp16_tb_softfloat___024root___nba_sequent__TOP__1(vlSelf);
        Vadd4_fp32accum_fp16_tb_softfloat___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((0xcULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadd4_fp32accum_fp16_tb_softfloat___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
}

VL_INLINE_OPT void Vadd4_fp32accum_fp16_tb_softfloat___024root___nba_sequent__TOP__0(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_fp16_tb_softfloat___024root___nba_sequent__TOP__0\n"); );
    Vadd4_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__res_sign));
    if (vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_nrst) {
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_carry_vec 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c2;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_sum_vec 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s2;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_exp_base 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_e;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_spec_res 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_result;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_hot_ones 
            = (3U & (((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_op) 
                      + (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_op)) 
                     + (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_op)));
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_e 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_result 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result;
    } else {
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag = 0U;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_carry_vec = 0U;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_sum_vec = 0U;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_exp_base = 0U;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_spec_res = 0U;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_hot_ones = 0U;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_e = 0U;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_result = 0U;
    }
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s 
        = ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special 
        = ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_case));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sticky 
        = ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_align_sticky));
    if ((0U != vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag)) {
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_case 
        = ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum 
        = (0x1fffffffU & ((vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_sum_vec 
                           + VL_EXTENDS_II(29,28, (0xfffffffU 
                                                   & VL_SHIFTL_III(28,28,32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_carry_vec, 1U)))) 
                          + (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_hot_ones)));
    if ((0x8000000U & vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum)) {
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum 
            = (0x7ffffffU & ((IData)(1U) + (~ vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum)));
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s)));
    } else {
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum 
            = (0x7ffffffU & vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum);
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__res_sign 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s;
    }
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_align_sticky 
        = ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_nrst) 
           && (((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_y) 
                | (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_m)) 
               | (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_n)));
}

void Vadd4_fp32accum_fp16_tb_softfloat___024root___timing_resume(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_fp16_tb_softfloat___024root___timing_resume\n"); );
    Vadd4_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h8c095862__0.resume(
                                                   "@(negedge add4_fp32accum_fp16_tb_softfloat.tb_clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vadd4_fp32accum_fp16_tb_softfloat___024root___timing_commit(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_fp16_tb_softfloat___024root___timing_commit\n"); );
    Vadd4_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (8ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h8c095862__0.commit(
                                                   "@(negedge add4_fp32accum_fp16_tb_softfloat.tb_clk)");
    }
}

void Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_triggers__act(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf);

bool Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_phase__act(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_phase__act\n"); );
    Vadd4_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_triggers__act(vlSelf);
    Vadd4_fp32accum_fp16_tb_softfloat___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vadd4_fp32accum_fp16_tb_softfloat___024root___timing_resume(vlSelf);
        Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_phase__nba(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_phase__nba\n"); );
    Vadd4_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp32accum_fp16_tb_softfloat___024root___dump_triggers__nba(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp32accum_fp16_tb_softfloat___024root___dump_triggers__act(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG

void Vadd4_fp32accum_fp16_tb_softfloat___024root___eval(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_fp16_tb_softfloat___024root___eval\n"); );
    Vadd4_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vadd4_fp32accum_fp16_tb_softfloat___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 21, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vadd4_fp32accum_fp16_tb_softfloat___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 21, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_debug_assertions(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_debug_assertions\n"); );
    Vadd4_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
