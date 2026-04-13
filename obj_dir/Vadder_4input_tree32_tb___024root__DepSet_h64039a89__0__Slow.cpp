// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadder_4input_tree32_tb.h for the primary calling header

#include "Vadder_4input_tree32_tb__pch.h"
#include "Vadder_4input_tree32_tb___024root.h"

VL_ATTR_COLD void Vadder_4input_tree32_tb___024root___eval_static__TOP(Vadder_4input_tree32_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_4input_tree32_tb___024root___eval_static__TOP\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.adder_4input_tree32_tb__DOT__pass_count = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__fail_count = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__total_count = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__largest_ulp = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__total_ulp_error = 0.0;
}

VL_ATTR_COLD void Vadder_4input_tree32_tb___024root___eval_initial__TOP(Vadder_4input_tree32_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_4input_tree32_tb___024root___eval_initial__TOP\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__safe_a = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__safe_b = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__safe_c = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__safe_d = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__a_daz = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__b_daz = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__c_daz = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__d_daz = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_a = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_a = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_a = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_b = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_b = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_b = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_c = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_c = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_c = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_d = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_d = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_d = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__is_nan_any = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__any_pos_inf = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__any_neg_inf = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__special_case = 0U;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__special_result = 0ULL;
    if (vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__any_pos_inf) {
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__special_case = 1U;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__special_result = 0x3fc000000ULL;
    } else if (vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__any_neg_inf) {
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__special_case = 1U;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__special_result = 0x7fc000000ULL;
    }
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_p 
        = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_a;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_p 
        = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_a;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_p 
        = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_a;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_m 
        = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_b;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_m 
        = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_b;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_m 
        = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_b;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_r 
        = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_c;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_r 
        = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_c;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_r 
        = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_c;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_n 
        = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_d;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_n 
        = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_d;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_n 
        = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_d;
    if (((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_p) 
         >= (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_r))) {
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_x 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_p;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_x 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_p;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_x 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_p;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_y 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_r;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_y 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_r;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_y 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_r;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_mx 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_m;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_mx 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_m;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_mx 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_m;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_nx 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_n;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_nx 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_n;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_nx 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_n;
    } else {
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_x 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_r;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_x 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_r;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_x 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_r;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_y 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_p;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_y 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_p;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_y 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_p;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_mx 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_n;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_mx 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_n;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_mx 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_n;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_nx 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_m;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_nx 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_m;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_nx 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_m;
    }
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_x)));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_y)));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_mx)));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_nx)));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_y_eff)));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_mx_eff)));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_nx_eff)));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__x_mant 
        = (0x7ffffffffffffffULL & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                          (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_x))) 
                                                                            << 7U) 
                                                                           | (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_x)))), 0x33U));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__y_mant_base 
        = (0x7ffffffffffffffULL & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                          (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_y))) 
                                                                            << 7U) 
                                                                           | (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_y)))), 0x33U));
    if ((0x3bU <= (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__y_shift))) {
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__safe_y_shift = 0x3aU;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sticky_y 
            = (0U != vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__y_mant_base);
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__y_shifted = 0ULL;
    } else {
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__safe_y_shift 
            = (0x3fU & (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__y_shift));
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sticky_y 
            = (0U != (vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__y_mant_base 
                      & (~ (0x7ffffffffffffffULL << (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__safe_y_shift)))));
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__y_shifted 
            = (0x7ffffffffffffffULL & (vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__y_mant_base 
                                       >> (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__safe_y_shift)));
    }
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__m_mant_base 
        = (0x7ffffffffffffffULL & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                          (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_mx))) 
                                                                            << 7U) 
                                                                           | (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_mx)))), 0x33U));
    if ((0x3bU <= (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__m_shift))) {
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__safe_m_shift = 0x3aU;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sticky_m 
            = (0U != vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__m_mant_base);
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__m_shifted = 0ULL;
    } else {
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__safe_m_shift 
            = (0x3fU & (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__m_shift));
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sticky_m 
            = (0U != (vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__m_mant_base 
                      & (~ (0x7ffffffffffffffULL << (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__safe_m_shift)))));
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__m_shifted 
            = (0x7ffffffffffffffULL & (vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__m_mant_base 
                                       >> (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__safe_m_shift)));
    }
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__n_mant_base 
        = (0x7ffffffffffffffULL & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                          (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_nx))) 
                                                                            << 7U) 
                                                                           | (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_nx)))), 0x33U));
    if ((0x3bU <= (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__n_shift))) {
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__safe_n_shift = 0x3aU;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sticky_n 
            = (0U != vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__n_mant_base);
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__n_shifted = 0ULL;
    } else {
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__safe_n_shift 
            = (0x3fU & (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__n_shift));
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sticky_n 
            = (0U != (vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__n_mant_base 
                      & (~ (0x7ffffffffffffffULL << (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__safe_n_shift)))));
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__n_shifted 
            = (0x7ffffffffffffffULL & (vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__n_mant_base 
                                       >> (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__safe_n_shift)));
    }
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__y_op 
        = ((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_x) 
           ^ (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_y));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__m_op 
        = ((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_x) 
           ^ (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_mx));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__n_op 
        = ((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_x) 
           ^ (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_nx));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__op_x 
        = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__x_mant;
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__op_y 
        = (0x7fffffffffffffffULL & ((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__y_op)
                                     ? (~ vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__y_shifted)
                                     : vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__y_shifted));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__op_m 
        = (0x7fffffffffffffffULL & ((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__m_op)
                                     ? (~ vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__m_shifted)
                                     : vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__m_shifted));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__op_n 
        = (0x7fffffffffffffffULL & ((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__n_op)
                                     ? (~ vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__n_shifted)
                                     : vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__n_shifted));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__csa_s1 
        = ((vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__op_x 
            ^ vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__op_y) 
           ^ vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__op_m);
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__csa_c1 
        = (((vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__op_x 
             & vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__op_y) 
            | (vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__op_y 
               & vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__op_m)) 
           | (vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__op_m 
              & vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__op_x));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__csa_s2 
        = (0x7fffffffffffffffULL & ((vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__csa_s1 
                                     ^ VL_SHIFTL_QQI(63,63,32, vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__csa_c1, 1U)) 
                                    ^ vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__op_n));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__csa_c2 
        = (((vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__csa_s1 
             & VL_SHIFTL_QQI(63,63,32, vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__csa_c1, 1U)) 
            | (VL_SHIFTL_QQI(63,63,32, vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__csa_c1, 1U) 
               & vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__op_n)) 
           | (vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__op_n 
              & vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__csa_s1));
}

VL_ATTR_COLD void Vadder_4input_tree32_tb___024root___eval_final(Vadder_4input_tree32_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_4input_tree32_tb___024root___eval_final\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadder_4input_tree32_tb___024root___dump_triggers__stl(Vadder_4input_tree32_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vadder_4input_tree32_tb___024root___eval_phase__stl(Vadder_4input_tree32_tb___024root* vlSelf);

VL_ATTR_COLD void Vadder_4input_tree32_tb___024root___eval_settle(Vadder_4input_tree32_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_4input_tree32_tb___024root___eval_settle\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vadder_4input_tree32_tb___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb/unit/systolic_array/adder_4input_tree32_tb.sv", 18, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vadder_4input_tree32_tb___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadder_4input_tree32_tb___024root___dump_triggers__stl(Vadder_4input_tree32_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_4input_tree32_tb___024root___dump_triggers__stl\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
    if ((2ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 1 is active: @([hybrid] adder_4input_tree32_tb.dut.stage_0.rounded_mant_int)\n");
    }
    if ((4ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 2 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[1].stage_inst.rounded_mant_int)\n");
    }
    if ((8ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 3 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[2].stage_inst.rounded_mant_int)\n");
    }
    if ((0x10ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 4 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[3].stage_inst.rounded_mant_int)\n");
    }
    if ((0x20ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 5 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[4].stage_inst.rounded_mant_int)\n");
    }
    if ((0x40ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 6 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[5].stage_inst.rounded_mant_int)\n");
    }
    if ((0x80ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 7 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[6].stage_inst.rounded_mant_int)\n");
    }
    if ((0x100ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 8 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[7].stage_inst.rounded_mant_int)\n");
    }
    if ((0x200ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 9 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[8].stage_inst.rounded_mant_int)\n");
    }
    if ((0x400ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 10 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[9].stage_inst.rounded_mant_int)\n");
    }
    if ((0x800ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 11 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[10].stage_inst.rounded_mant_int)\n");
    }
    if ((0x1000ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 12 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[11].stage_inst.rounded_mant_int)\n");
    }
    if ((0x2000ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 13 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[12].stage_inst.rounded_mant_int)\n");
    }
    if ((0x4000ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 14 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[13].stage_inst.rounded_mant_int)\n");
    }
    if ((0x8000ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 15 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[14].stage_inst.rounded_mant_int)\n");
    }
    if ((0x10000ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 16 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[15].stage_inst.rounded_mant_int)\n");
    }
    if ((0x20000ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 17 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[16].stage_inst.rounded_mant_int)\n");
    }
    if ((0x40000ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 18 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[17].stage_inst.rounded_mant_int)\n");
    }
    if ((0x80000ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 19 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[18].stage_inst.rounded_mant_int)\n");
    }
    if ((0x100000ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 20 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[19].stage_inst.rounded_mant_int)\n");
    }
    if ((0x200000ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 21 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[20].stage_inst.rounded_mant_int)\n");
    }
    if ((0x400000ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 22 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[21].stage_inst.rounded_mant_int)\n");
    }
    if ((0x800000ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 23 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[22].stage_inst.rounded_mant_int)\n");
    }
    if ((0x1000000ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 24 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[23].stage_inst.rounded_mant_int)\n");
    }
    if ((0x2000000ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 25 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[24].stage_inst.rounded_mant_int)\n");
    }
    if ((0x4000000ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 26 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[25].stage_inst.rounded_mant_int)\n");
    }
    if ((0x8000000ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 27 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[26].stage_inst.rounded_mant_int)\n");
    }
    if ((0x10000000ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 28 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[27].stage_inst.rounded_mant_int)\n");
    }
    if ((0x20000000ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 29 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[28].stage_inst.rounded_mant_int)\n");
    }
    if ((0x40000000ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 30 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[29].stage_inst.rounded_mant_int)\n");
    }
    if ((0x80000000ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 31 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[30].stage_inst.rounded_mant_int)\n");
    }
    if ((0x100000000ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 32 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[31].stage_inst.rounded_mant_int)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vadder_4input_tree32_tb___024root___eval_triggers__stl(Vadder_4input_tree32_tb___024root* vlSelf);
VL_ATTR_COLD void Vadder_4input_tree32_tb___024root___eval_stl(Vadder_4input_tree32_tb___024root* vlSelf);

VL_ATTR_COLD bool Vadder_4input_tree32_tb___024root___eval_phase__stl(Vadder_4input_tree32_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_4input_tree32_tb___024root___eval_phase__stl\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vadder_4input_tree32_tb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vadder_4input_tree32_tb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadder_4input_tree32_tb___024root___dump_triggers__act(Vadder_4input_tree32_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_4input_tree32_tb___024root___dump_triggers__act\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @([hybrid] adder_4input_tree32_tb.dut.stage_0.rounded_mant_int)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[1].stage_inst.rounded_mant_int)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[2].stage_inst.rounded_mant_int)\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[3].stage_inst.rounded_mant_int)\n");
    }
    if ((0x10ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[4].stage_inst.rounded_mant_int)\n");
    }
    if ((0x20ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 5 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[5].stage_inst.rounded_mant_int)\n");
    }
    if ((0x40ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 6 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[6].stage_inst.rounded_mant_int)\n");
    }
    if ((0x80ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 7 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[7].stage_inst.rounded_mant_int)\n");
    }
    if ((0x100ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 8 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[8].stage_inst.rounded_mant_int)\n");
    }
    if ((0x200ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 9 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[9].stage_inst.rounded_mant_int)\n");
    }
    if ((0x400ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 10 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[10].stage_inst.rounded_mant_int)\n");
    }
    if ((0x800ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 11 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[11].stage_inst.rounded_mant_int)\n");
    }
    if ((0x1000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 12 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[12].stage_inst.rounded_mant_int)\n");
    }
    if ((0x2000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 13 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[13].stage_inst.rounded_mant_int)\n");
    }
    if ((0x4000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 14 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[14].stage_inst.rounded_mant_int)\n");
    }
    if ((0x8000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 15 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[15].stage_inst.rounded_mant_int)\n");
    }
    if ((0x10000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 16 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[16].stage_inst.rounded_mant_int)\n");
    }
    if ((0x20000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 17 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[17].stage_inst.rounded_mant_int)\n");
    }
    if ((0x40000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 18 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[18].stage_inst.rounded_mant_int)\n");
    }
    if ((0x80000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 19 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[19].stage_inst.rounded_mant_int)\n");
    }
    if ((0x100000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 20 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[20].stage_inst.rounded_mant_int)\n");
    }
    if ((0x200000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 21 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[21].stage_inst.rounded_mant_int)\n");
    }
    if ((0x400000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 22 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[22].stage_inst.rounded_mant_int)\n");
    }
    if ((0x800000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 23 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[23].stage_inst.rounded_mant_int)\n");
    }
    if ((0x1000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 24 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[24].stage_inst.rounded_mant_int)\n");
    }
    if ((0x2000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 25 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[25].stage_inst.rounded_mant_int)\n");
    }
    if ((0x4000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 26 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[26].stage_inst.rounded_mant_int)\n");
    }
    if ((0x8000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 27 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[27].stage_inst.rounded_mant_int)\n");
    }
    if ((0x10000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 28 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[28].stage_inst.rounded_mant_int)\n");
    }
    if ((0x20000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 29 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[29].stage_inst.rounded_mant_int)\n");
    }
    if ((0x40000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 30 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[30].stage_inst.rounded_mant_int)\n");
    }
    if ((0x80000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 31 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[31].stage_inst.rounded_mant_int)\n");
    }
    if ((0x100000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 32 is active: @(posedge adder_4input_tree32_tb.clk)\n");
    }
    if ((0x200000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 33 is active: @(negedge adder_4input_tree32_tb.nrst)\n");
    }
    if ((0x400000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 34 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadder_4input_tree32_tb___024root___dump_triggers__nba(Vadder_4input_tree32_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_4input_tree32_tb___024root___dump_triggers__nba\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @([hybrid] adder_4input_tree32_tb.dut.stage_0.rounded_mant_int)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[1].stage_inst.rounded_mant_int)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[2].stage_inst.rounded_mant_int)\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[3].stage_inst.rounded_mant_int)\n");
    }
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[4].stage_inst.rounded_mant_int)\n");
    }
    if ((0x20ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 5 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[5].stage_inst.rounded_mant_int)\n");
    }
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 6 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[6].stage_inst.rounded_mant_int)\n");
    }
    if ((0x80ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 7 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[7].stage_inst.rounded_mant_int)\n");
    }
    if ((0x100ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 8 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[8].stage_inst.rounded_mant_int)\n");
    }
    if ((0x200ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 9 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[9].stage_inst.rounded_mant_int)\n");
    }
    if ((0x400ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 10 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[10].stage_inst.rounded_mant_int)\n");
    }
    if ((0x800ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 11 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[11].stage_inst.rounded_mant_int)\n");
    }
    if ((0x1000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 12 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[12].stage_inst.rounded_mant_int)\n");
    }
    if ((0x2000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 13 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[13].stage_inst.rounded_mant_int)\n");
    }
    if ((0x4000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 14 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[14].stage_inst.rounded_mant_int)\n");
    }
    if ((0x8000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 15 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[15].stage_inst.rounded_mant_int)\n");
    }
    if ((0x10000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 16 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[16].stage_inst.rounded_mant_int)\n");
    }
    if ((0x20000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 17 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[17].stage_inst.rounded_mant_int)\n");
    }
    if ((0x40000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 18 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[18].stage_inst.rounded_mant_int)\n");
    }
    if ((0x80000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 19 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[19].stage_inst.rounded_mant_int)\n");
    }
    if ((0x100000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 20 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[20].stage_inst.rounded_mant_int)\n");
    }
    if ((0x200000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 21 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[21].stage_inst.rounded_mant_int)\n");
    }
    if ((0x400000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 22 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[22].stage_inst.rounded_mant_int)\n");
    }
    if ((0x800000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 23 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[23].stage_inst.rounded_mant_int)\n");
    }
    if ((0x1000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 24 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[24].stage_inst.rounded_mant_int)\n");
    }
    if ((0x2000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 25 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[25].stage_inst.rounded_mant_int)\n");
    }
    if ((0x4000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 26 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[26].stage_inst.rounded_mant_int)\n");
    }
    if ((0x8000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 27 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[27].stage_inst.rounded_mant_int)\n");
    }
    if ((0x10000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 28 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[28].stage_inst.rounded_mant_int)\n");
    }
    if ((0x20000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 29 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[29].stage_inst.rounded_mant_int)\n");
    }
    if ((0x40000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 30 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[30].stage_inst.rounded_mant_int)\n");
    }
    if ((0x80000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 31 is active: @([hybrid] adder_4input_tree32_tb.dut.gen_accum_stages[31].stage_inst.rounded_mant_int)\n");
    }
    if ((0x100000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 32 is active: @(posedge adder_4input_tree32_tb.clk)\n");
    }
    if ((0x200000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 33 is active: @(negedge adder_4input_tree32_tb.nrst)\n");
    }
    if ((0x400000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 34 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vadder_4input_tree32_tb___024root____Vm_traceActivitySetAll(Vadder_4input_tree32_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_4input_tree32_tb___024root____Vm_traceActivitySetAll\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    IData/*31:0*/ __Vilp1;
    __Vilp1 = 0U;
    while ((__Vilp1 <= 0x45U)) {
        vlSelfRef.__Vm_traceActivity[__Vilp1] = 1U;
        __Vilp1 = ((IData)(1U) + __Vilp1);
    }
}

VL_ATTR_COLD void Vadder_4input_tree32_tb___024root___ctor_var_reset(Vadder_4input_tree32_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_4input_tree32_tb___024root___ctor_var_reset\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->adder_4input_tree32_tb__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__nrst = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 97; ++__Vi0) {
        vlSelf->adder_4input_tree32_tb__DOT__inputs[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->adder_4input_tree32_tb__DOT__hw_out = VL_RAND_RESET_I(16);
    vlSelf->adder_4input_tree32_tb__DOT__expected = VL_RAND_RESET_I(16);
    vlSelf->adder_4input_tree32_tb__DOT__pass_count = 0;
    vlSelf->adder_4input_tree32_tb__DOT__fail_count = 0;
    vlSelf->adder_4input_tree32_tb__DOT__total_count = 0;
    vlSelf->adder_4input_tree32_tb__DOT__largest_ulp = 0;
    vlSelf->adder_4input_tree32_tb__DOT__total_ulp_error = 0;
    vlSelf->adder_4input_tree32_tb__DOT__fd = 0;
    vlSelf->adder_4input_tree32_tb__DOT__fail_fd = 0;
    vlSelf->adder_4input_tree32_tb__DOT__unnamedblk1__DOT__ret = 0;
    vlSelf->adder_4input_tree32_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->adder_4input_tree32_tb__DOT__unnamedblk1__DOT__unnamedblk3__DOT__ulp = 0;
    vlSelf->adder_4input_tree32_tb__DOT____Vlvbound_hb2b269bb__0 = VL_RAND_RESET_I(16);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__safe_a = VL_RAND_RESET_I(16);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__safe_b = VL_RAND_RESET_I(16);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__safe_c = VL_RAND_RESET_I(16);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__safe_d = VL_RAND_RESET_I(16);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__a_daz = VL_RAND_RESET_I(16);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__b_daz = VL_RAND_RESET_I(16);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__c_daz = VL_RAND_RESET_I(16);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__d_daz = VL_RAND_RESET_I(16);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_a = VL_RAND_RESET_I(8);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_b = VL_RAND_RESET_I(8);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_c = VL_RAND_RESET_I(8);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_d = VL_RAND_RESET_I(8);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_a = VL_RAND_RESET_I(7);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_b = VL_RAND_RESET_I(7);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_c = VL_RAND_RESET_I(7);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_d = VL_RAND_RESET_I(7);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_a = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_b = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_c = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_d = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_p = VL_RAND_RESET_I(8);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_m = VL_RAND_RESET_I(8);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_r = VL_RAND_RESET_I(8);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_n = VL_RAND_RESET_I(8);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_x = VL_RAND_RESET_I(8);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_y = VL_RAND_RESET_I(8);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_mx = VL_RAND_RESET_I(8);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_nx = VL_RAND_RESET_I(8);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_p = VL_RAND_RESET_I(7);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_m = VL_RAND_RESET_I(7);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_r = VL_RAND_RESET_I(7);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_n = VL_RAND_RESET_I(7);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_x = VL_RAND_RESET_I(7);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_y = VL_RAND_RESET_I(7);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_mx = VL_RAND_RESET_I(7);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__frac_nx = VL_RAND_RESET_I(7);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_p = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_m = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_r = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_n = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_x = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_y = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_mx = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_nx = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_x_eff = VL_RAND_RESET_I(8);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_y_eff = VL_RAND_RESET_I(8);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_mx_eff = VL_RAND_RESET_I(8);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_nx_eff = VL_RAND_RESET_I(8);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__y_shift = VL_RAND_RESET_I(9);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__m_shift = VL_RAND_RESET_I(9);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__n_shift = VL_RAND_RESET_I(9);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__safe_y_shift = VL_RAND_RESET_I(6);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__safe_m_shift = VL_RAND_RESET_I(6);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__safe_n_shift = VL_RAND_RESET_I(6);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__x_mant = VL_RAND_RESET_Q(59);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__y_shifted = VL_RAND_RESET_Q(59);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__m_shifted = VL_RAND_RESET_Q(59);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__n_shifted = VL_RAND_RESET_Q(59);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__y_mant_base = VL_RAND_RESET_Q(59);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__m_mant_base = VL_RAND_RESET_Q(59);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__n_mant_base = VL_RAND_RESET_Q(59);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sticky_y = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sticky_m = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sticky_n = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__y_op = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__m_op = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__n_op = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__is_nan_any = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__special_case = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__any_pos_inf = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__any_neg_inf = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__special_result = VL_RAND_RESET_Q(35);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_a_e = VL_RAND_RESET_I(8);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_a_s = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_align_sticky = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_special_case = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_special_result = VL_RAND_RESET_Q(35);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_sum_vec = VL_RAND_RESET_Q(63);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_carry_vec = VL_RAND_RESET_Q(63);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_hot_ones = VL_RAND_RESET_I(2);
    VL_RAND_RESET_W(65, vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__raw_sum);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__mag_sum = VL_RAND_RESET_Q(63);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__res_sign = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_exp_base = VL_RAND_RESET_I(8);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_sum_mag = VL_RAND_RESET_Q(63);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_spec_res = VL_RAND_RESET_Q(35);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_res_sign = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_sticky = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_special = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lzd_scan = VL_RAND_RESET_Q(63);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lead_zeros = VL_RAND_RESET_I(6);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__norm_val = VL_RAND_RESET_Q(63);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__raw_mant = VL_RAND_RESET_I(26);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__final_mant = VL_RAND_RESET_I(26);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__rounded_mant_int = VL_RAND_RESET_I(27);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__final_exp_calc = VL_RAND_RESET_I(11);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__guard_bit = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__round_bit = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sticky_bit = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__round_up = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__l_bit = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__result_out = VL_RAND_RESET_Q(35);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__op_x = VL_RAND_RESET_Q(63);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__op_y = VL_RAND_RESET_Q(63);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__op_m = VL_RAND_RESET_Q(63);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__op_n = VL_RAND_RESET_Q(63);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__csa_s1 = VL_RAND_RESET_Q(63);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__csa_c1 = VL_RAND_RESET_Q(63);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__csa_s2 = VL_RAND_RESET_Q(63);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__csa_c2 = VL_RAND_RESET_Q(63);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__final_reduce__DOT__new_exp = VL_RAND_RESET_I(10);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__final_reduce__DOT__rounded = VL_RAND_RESET_I(8);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__final_reduce__DOT__guard = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__final_reduce__DOT__rnd = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__final_reduce__DOT__sticky = VL_RAND_RESET_I(1);
    vlSelf->adder_4input_tree32_tb__DOT__dut__DOT__final_reduce__DOT__round_up = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__2__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__3__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__4__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__5__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__6__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__7__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__8__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__9__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__10__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__11__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__12__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__13__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__14__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__15__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__16__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__17__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__18__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__19__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__20__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__21__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__22__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__23__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__24__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__25__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__26__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__27__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__28__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__29__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__30__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__31__KET____DOT__stage_inst____PVT__rounded_mant_int__0 = VL_RAND_RESET_I(27);
    vlSelf->__VstlDidInit = 0;
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__2__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__3__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__4__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__5__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__6__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__7__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__8__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__9__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__10__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__11__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__12__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__13__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__14__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__15__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__16__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__17__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__18__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__19__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__20__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__21__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__22__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__23__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__24__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__25__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__26__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__27__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__28__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__29__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__30__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__31__KET____DOT__stage_inst____PVT__rounded_mant_int__1 = VL_RAND_RESET_I(27);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__nrst__0 = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 70; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
