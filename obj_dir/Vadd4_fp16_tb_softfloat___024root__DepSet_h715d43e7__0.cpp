// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd4_fp16_tb_softfloat.h for the primary calling header

#include "Vadd4_fp16_tb_softfloat__pch.h"
#include "Vadd4_fp16_tb_softfloat___024root.h"

VlCoroutine Vadd4_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__0(Vadd4_fp16_tb_softfloat___024root* vlSelf);
VlCoroutine Vadd4_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__1(Vadd4_fp16_tb_softfloat___024root* vlSelf);

void Vadd4_fp16_tb_softfloat___024root___eval_initial(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___eval_initial\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vadd4_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vadd4_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vadd4_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__1(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_clk = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                             nullptr, 
                                             "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                             29);
        vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_clk = 1U;
        co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                             nullptr, 
                                             "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                             31);
    }
}

void Vadd4_fp16_tb_softfloat___024root___act_comb__TOP__0(Vadd4_fp16_tb_softfloat___024root* vlSelf);

void Vadd4_fp16_tb_softfloat___024root___eval_act(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___eval_act\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0xcULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadd4_fp16_tb_softfloat___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void Vadd4_fp16_tb_softfloat___024root___act_comb__TOP__0(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___act_comb__TOP__0\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*14:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__Vfuncout = 0;
    SData/*14:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__mant;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__mant = 0;
    CData/*4:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__shift_amt;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__shift_amt = 0;
    SData/*14:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__Vfuncout = 0;
    SData/*14:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__mant;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__mant = 0;
    CData/*4:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__shift_amt;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__shift_amt = 0;
    SData/*14:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__Vfuncout = 0;
    SData/*14:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__mant;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__mant = 0;
    CData/*4:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__shift_amt;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__shift_amt = 0;
    // Body
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a;
    if ((IData)(((0U == (0x7c00U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a))) 
                 & (0U != (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a)))))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz 
            = (0x8000U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a));
    }
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b;
    if ((IData)(((0U == (0x7c00U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b))) 
                 & (0U != (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b)))))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz 
            = (0x8000U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b));
    }
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c;
    if ((IData)(((0U == (0x7c00U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c))) 
                 & (0U != (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c)))))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz 
            = (0x8000U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c));
    }
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d;
    if ((IData)(((0U == (0x7c00U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d))) 
                 & (0U != (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d)))))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz 
            = (0x8000U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d));
    }
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz) 
                    >> 0xaU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a 
        = (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz) 
                    >> 0xaU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b 
        = (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz) 
                    >> 0xaU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c 
        = (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz) 
                    >> 0xaU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d 
        = (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = 0U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = 0U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_a 
        = ((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a)) 
           & (0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_b 
        = ((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b)) 
           & (0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_c 
        = ((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c)) 
           & (0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_d 
        = ((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d)) 
           & (0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_inf_a 
        = ((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a)) 
           & (0U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_inf_b 
        = ((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b)) 
           & (0U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_inf_c 
        = ((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c)) 
           & (0U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_inf_d 
        = ((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d)) 
           & (0U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d)));
    if (((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_a) 
           | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_b)) 
          | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_c)) 
         | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_d))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = 1U;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = 0x7e00U;
    } else if (((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_inf_a) 
                  | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_inf_b)) 
                 | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_inf_c)) 
                | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_inf_d))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage1_combinational__DOT__unnamedblk1__DOT__has_pos_inf 
            = (((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_inf_a) 
                  & (~ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a))) 
                 | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_inf_b) 
                    & (~ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b)))) 
                | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_inf_c) 
                   & (~ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c)))) 
               | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_inf_d) 
                  & (~ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d))));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage1_combinational__DOT__unnamedblk1__DOT__has_neg_inf 
            = (((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_inf_a) 
                  & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a)) 
                 | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_inf_b) 
                    & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b))) 
                | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_inf_c) 
                   & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c))) 
               | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_inf_d) 
                  & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d)));
        if (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage1_combinational__DOT__unnamedblk1__DOT__has_pos_inf) 
             & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage1_combinational__DOT__unnamedblk1__DOT__has_neg_inf))) {
            vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = 1U;
            vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = 0x7e00U;
        } else if (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage1_combinational__DOT__unnamedblk1__DOT__has_pos_inf) {
            vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = 1U;
            vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = 0x7c00U;
        } else {
            vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = 1U;
            vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = 0xfc00U;
        }
    }
    if (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a) 
         >= (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b;
    } else {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c) 
         >= (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d;
    } else {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p) 
         >= (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_y 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_mx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_nx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n;
    } else {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_y 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_mx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_nx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m;
    }
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x))
            ? 1U : (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y))
            ? 1U : (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx))
            ? 1U : (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx))
            ? 1U : (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff) 
                    - (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y_eff)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff) 
                    - (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx_eff)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff) 
                    - (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx_eff)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x))) 
            << 0xeU) | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x) 
                        << 4U));
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__shift_amt 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__mant 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y))) 
            << 0xeU) | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y) 
                        << 4U));
    vlSelf->__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__result = VL_RAND_RESET_I(15);
    vlSelf->__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__sticky = VL_RAND_RESET_I(1);
    if ((0U == (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__shift_amt))) {
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__result 
            = __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__mant;
    } else if ((0xfU <= (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__shift_amt))) {
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__result = 0U;
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__result 
            = ((0x7ffeU & (IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__result)) 
               | (0U != (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__mant)));
    } else {
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__result 
            = (0x7fffU & ((IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__mant) 
                          >> (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__shift_amt)));
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__sticky 
            = (0U != ((IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__mant) 
                      & (((IData)(1U) << (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__shift_amt)) 
                         - (IData)(1U))));
        if ((1U & ((IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__sticky) 
                   | (IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__result)))) {
            vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__result 
                = (1U | (IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__result));
        }
    }
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__Vfuncout 
        = vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__result;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted 
        = __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__50__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__shift_amt 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__mant 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx))) 
            << 0xeU) | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx) 
                        << 4U));
    vlSelf->__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__result = VL_RAND_RESET_I(15);
    vlSelf->__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__sticky = VL_RAND_RESET_I(1);
    if ((0U == (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__shift_amt))) {
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__result 
            = __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__mant;
    } else if ((0xfU <= (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__shift_amt))) {
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__result = 0U;
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__result 
            = ((0x7ffeU & (IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__result)) 
               | (0U != (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__mant)));
    } else {
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__result 
            = (0x7fffU & ((IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__mant) 
                          >> (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__shift_amt)));
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__sticky 
            = (0U != ((IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__mant) 
                      & (((IData)(1U) << (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__shift_amt)) 
                         - (IData)(1U))));
        if ((1U & ((IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__sticky) 
                   | (IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__result)))) {
            vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__result 
                = (1U | (IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__result));
        }
    }
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__Vfuncout 
        = vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__result;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted 
        = __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__51__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__shift_amt 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__mant 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx))) 
            << 0xeU) | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx) 
                        << 4U));
    vlSelf->__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__result = VL_RAND_RESET_I(15);
    vlSelf->__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__sticky = VL_RAND_RESET_I(1);
    if ((0U == (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__shift_amt))) {
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__result 
            = __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__mant;
    } else if ((0xfU <= (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__shift_amt))) {
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__result = 0U;
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__result 
            = ((0x7ffeU & (IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__result)) 
               | (0U != (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__mant)));
    } else {
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__result 
            = (0x7fffU & ((IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__mant) 
                          >> (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__shift_amt)));
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__sticky 
            = (0U != ((IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__mant) 
                      & (((IData)(1U) << (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__shift_amt)) 
                         - (IData)(1U))));
        if ((1U & ((IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__sticky) 
                   | (IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__result)))) {
            vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__result 
                = (1U | (IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__result));
        }
    }
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__Vfuncout 
        = vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__result;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted 
        = __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shift_right_sticky__52__Vfuncout;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_op 
        = ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_y));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_op 
        = ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_mx));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_op 
        = ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_nx));
}

void Vadd4_fp16_tb_softfloat___024root___nba_sequent__TOP__0(Vadd4_fp16_tb_softfloat___024root* vlSelf);

void Vadd4_fp16_tb_softfloat___024root___eval_nba(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___eval_nba\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
        Vadd4_fp16_tb_softfloat___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0xcULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadd4_fp16_tb_softfloat___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
}

void Vadd4_fp16_tb_softfloat___024root___timing_resume(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___timing_resume\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h88600c86__0.resume(
                                                   "@(negedge add4_fp16_tb_softfloat.tb_clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vadd4_fp16_tb_softfloat___024root___timing_commit(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___timing_commit\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (8ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h88600c86__0.commit(
                                                   "@(negedge add4_fp16_tb_softfloat.tb_clk)");
    }
}

void Vadd4_fp16_tb_softfloat___024root___eval_triggers__act(Vadd4_fp16_tb_softfloat___024root* vlSelf);

bool Vadd4_fp16_tb_softfloat___024root___eval_phase__act(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___eval_phase__act\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vadd4_fp16_tb_softfloat___024root___eval_triggers__act(vlSelf);
    Vadd4_fp16_tb_softfloat___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vadd4_fp16_tb_softfloat___024root___timing_resume(vlSelf);
        Vadd4_fp16_tb_softfloat___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vadd4_fp16_tb_softfloat___024root___eval_phase__nba(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___eval_phase__nba\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vadd4_fp16_tb_softfloat___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___dump_triggers__nba(Vadd4_fp16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___dump_triggers__act(Vadd4_fp16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG

void Vadd4_fp16_tb_softfloat___024root___eval(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___eval\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vadd4_fp16_tb_softfloat___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 19, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vadd4_fp16_tb_softfloat___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 19, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vadd4_fp16_tb_softfloat___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vadd4_fp16_tb_softfloat___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vadd4_fp16_tb_softfloat___024root___eval_debug_assertions(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___eval_debug_assertions\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
