// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadder_4input_tree32_tb.h for the primary calling header

#include "Vadder_4input_tree32_tb__pch.h"
#include "Vadder_4input_tree32_tb__Syms.h"
#include "Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3.h"

VL_INLINE_OPT void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__21__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__21__KET____DOT__stage_inst__1\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__21__KET__.out 
        = ((IData)(vlSymsp->TOP.adder_4input_tree32_tb__DOT__nrst)
            ? vlSelfRef.__PVT__result_out : 0ULL);
}

VL_INLINE_OPT void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__22__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__22__KET____DOT__stage_inst__0\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__safe_a = (QData)((IData)(vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__21__KET__.out));
    vlSelfRef.__PVT__safe_b = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x43U] 
                                               << 0x10U)));
    vlSelfRef.__PVT__safe_c = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x44U] 
                                               << 0x10U)));
    vlSelfRef.__PVT__safe_d = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x45U] 
                                               << 0x10U)));
    vlSelfRef.__PVT__a_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_a 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_a 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_a);
    vlSelfRef.__PVT__b_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_b 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_b 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_b);
    vlSelfRef.__PVT__c_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_c 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_c 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_c);
    vlSelfRef.__PVT__d_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_d 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_d 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_d);
    vlSelfRef.__PVT__sign_a = (1U & (IData)((vlSelfRef.__PVT__a_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_a = (0xffU & (IData)((vlSelfRef.__PVT__a_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_a = (0x3ffffffU & (IData)(vlSelfRef.__PVT__a_daz));
    vlSelfRef.__PVT__sign_b = (1U & (IData)((vlSelfRef.__PVT__b_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_b = (0xffU & (IData)((vlSelfRef.__PVT__b_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_b = (0x3ffffffU & (IData)(vlSelfRef.__PVT__b_daz));
    vlSelfRef.__PVT__sign_c = (1U & (IData)((vlSelfRef.__PVT__c_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_c = (0xffU & (IData)((vlSelfRef.__PVT__c_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_c = (0x3ffffffU & (IData)(vlSelfRef.__PVT__c_daz));
    vlSelfRef.__PVT__sign_d = (1U & (IData)((vlSelfRef.__PVT__d_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_d = (0xffU & (IData)((vlSelfRef.__PVT__d_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_d = (0x3ffffffU & (IData)(vlSelfRef.__PVT__d_daz));
    vlSelfRef.__PVT__is_nan_any = (((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                      & (0U != vlSelfRef.__PVT__frac_a)) 
                                     | ((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                        & (0U != vlSelfRef.__PVT__frac_b))) 
                                    | ((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                       & (0U != vlSelfRef.__PVT__frac_c))) 
                                   | ((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                      & (0U != vlSelfRef.__PVT__frac_d)));
    vlSelfRef.__PVT__any_pos_inf = ((((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                        & (~ (IData)(vlSelfRef.__PVT__sign_a))) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_a)))) 
                                      | (((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                          & (~ (IData)(vlSelfRef.__PVT__sign_b))) 
                                         & (~ (IData)(
                                                      (0U 
                                                       != vlSelfRef.__PVT__frac_b))))) 
                                     | (((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                         & (~ (IData)(vlSelfRef.__PVT__sign_c))) 
                                        & (~ (IData)(
                                                     (0U 
                                                      != vlSelfRef.__PVT__frac_c))))) 
                                    | (((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                        & (~ (IData)(vlSelfRef.__PVT__sign_d))) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_d)))));
    vlSelfRef.__PVT__any_neg_inf = ((((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                        & (IData)(vlSelfRef.__PVT__sign_a)) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_a)))) 
                                      | (((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                          & (IData)(vlSelfRef.__PVT__sign_b)) 
                                         & (~ (IData)(
                                                      (0U 
                                                       != vlSelfRef.__PVT__frac_b))))) 
                                     | (((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                         & (IData)(vlSelfRef.__PVT__sign_c)) 
                                        & (~ (IData)(
                                                     (0U 
                                                      != vlSelfRef.__PVT__frac_c))))) 
                                    | (((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                        & (IData)(vlSelfRef.__PVT__sign_d)) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_d)))));
    vlSelfRef.__PVT__special_case = 0U;
    vlSelfRef.__PVT__special_result = 0ULL;
    if (((IData)(vlSelfRef.__PVT__is_nan_any) | ((IData)(vlSelfRef.__PVT__any_pos_inf) 
                                                 & (IData)(vlSelfRef.__PVT__any_neg_inf)))) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x3fe000000ULL;
    } else if (vlSelfRef.__PVT__any_pos_inf) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x3fc000000ULL;
    } else if (vlSelfRef.__PVT__any_neg_inf) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x7fc000000ULL;
    }
    if (((IData)(vlSelfRef.__PVT__exp_a) >= (IData)(vlSelfRef.__PVT__exp_b))) {
        vlSelfRef.__PVT__exp_p = vlSelfRef.__PVT__exp_a;
        vlSelfRef.__PVT__frac_p = vlSelfRef.__PVT__frac_a;
        vlSelfRef.__PVT__sign_p = vlSelfRef.__PVT__sign_a;
        vlSelfRef.__PVT__exp_m = vlSelfRef.__PVT__exp_b;
        vlSelfRef.__PVT__frac_m = vlSelfRef.__PVT__frac_b;
        vlSelfRef.__PVT__sign_m = vlSelfRef.__PVT__sign_b;
    } else {
        vlSelfRef.__PVT__exp_p = vlSelfRef.__PVT__exp_b;
        vlSelfRef.__PVT__frac_p = vlSelfRef.__PVT__frac_b;
        vlSelfRef.__PVT__sign_p = vlSelfRef.__PVT__sign_b;
        vlSelfRef.__PVT__exp_m = vlSelfRef.__PVT__exp_a;
        vlSelfRef.__PVT__frac_m = vlSelfRef.__PVT__frac_a;
        vlSelfRef.__PVT__sign_m = vlSelfRef.__PVT__sign_a;
    }
    if (((IData)(vlSelfRef.__PVT__exp_c) >= (IData)(vlSelfRef.__PVT__exp_d))) {
        vlSelfRef.__PVT__exp_r = vlSelfRef.__PVT__exp_c;
        vlSelfRef.__PVT__frac_r = vlSelfRef.__PVT__frac_c;
        vlSelfRef.__PVT__sign_r = vlSelfRef.__PVT__sign_c;
        vlSelfRef.__PVT__exp_n = vlSelfRef.__PVT__exp_d;
        vlSelfRef.__PVT__frac_n = vlSelfRef.__PVT__frac_d;
        vlSelfRef.__PVT__sign_n = vlSelfRef.__PVT__sign_d;
    } else {
        vlSelfRef.__PVT__exp_r = vlSelfRef.__PVT__exp_d;
        vlSelfRef.__PVT__frac_r = vlSelfRef.__PVT__frac_d;
        vlSelfRef.__PVT__sign_r = vlSelfRef.__PVT__sign_d;
        vlSelfRef.__PVT__exp_n = vlSelfRef.__PVT__exp_c;
        vlSelfRef.__PVT__frac_n = vlSelfRef.__PVT__frac_c;
        vlSelfRef.__PVT__sign_n = vlSelfRef.__PVT__sign_c;
    }
    if (((IData)(vlSelfRef.__PVT__exp_p) >= (IData)(vlSelfRef.__PVT__exp_r))) {
        vlSelfRef.__PVT__exp_x = vlSelfRef.__PVT__exp_p;
        vlSelfRef.__PVT__frac_x = vlSelfRef.__PVT__frac_p;
        vlSelfRef.__PVT__sign_x = vlSelfRef.__PVT__sign_p;
        vlSelfRef.__PVT__exp_y = vlSelfRef.__PVT__exp_r;
        vlSelfRef.__PVT__frac_y = vlSelfRef.__PVT__frac_r;
        vlSelfRef.__PVT__sign_y = vlSelfRef.__PVT__sign_r;
        vlSelfRef.__PVT__exp_mx = vlSelfRef.__PVT__exp_m;
        vlSelfRef.__PVT__frac_mx = vlSelfRef.__PVT__frac_m;
        vlSelfRef.__PVT__sign_mx = vlSelfRef.__PVT__sign_m;
        vlSelfRef.__PVT__exp_nx = vlSelfRef.__PVT__exp_n;
        vlSelfRef.__PVT__frac_nx = vlSelfRef.__PVT__frac_n;
        vlSelfRef.__PVT__sign_nx = vlSelfRef.__PVT__sign_n;
    } else {
        vlSelfRef.__PVT__exp_x = vlSelfRef.__PVT__exp_r;
        vlSelfRef.__PVT__frac_x = vlSelfRef.__PVT__frac_r;
        vlSelfRef.__PVT__sign_x = vlSelfRef.__PVT__sign_r;
        vlSelfRef.__PVT__exp_y = vlSelfRef.__PVT__exp_p;
        vlSelfRef.__PVT__frac_y = vlSelfRef.__PVT__frac_p;
        vlSelfRef.__PVT__sign_y = vlSelfRef.__PVT__sign_p;
        vlSelfRef.__PVT__exp_mx = vlSelfRef.__PVT__exp_n;
        vlSelfRef.__PVT__frac_mx = vlSelfRef.__PVT__frac_n;
        vlSelfRef.__PVT__sign_mx = vlSelfRef.__PVT__sign_n;
        vlSelfRef.__PVT__exp_nx = vlSelfRef.__PVT__exp_m;
        vlSelfRef.__PVT__frac_nx = vlSelfRef.__PVT__frac_m;
        vlSelfRef.__PVT__sign_nx = vlSelfRef.__PVT__sign_m;
    }
    vlSelfRef.__PVT__exp_x_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_x))
                                   ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_x)));
    vlSelfRef.__PVT__exp_y_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_y))
                                   ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_y)));
    vlSelfRef.__PVT__exp_mx_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_mx))
                                    ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_mx)));
    vlSelfRef.__PVT__exp_nx_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_nx))
                                    ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_nx)));
    vlSelfRef.__PVT__y_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_y_eff)));
    vlSelfRef.__PVT__m_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_mx_eff)));
    vlSelfRef.__PVT__n_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_nx_eff)));
    vlSelfRef.__PVT__x_mant = (0x7ffffffffffffffULL 
                               & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                         (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_x))) 
                                                                           << 0x1aU) 
                                                                          | vlSelfRef.__PVT__frac_x))), 0x20U));
    vlSelfRef.__PVT__y_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_y))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_y))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__y_shift))) {
        vlSelfRef.__PVT__safe_y_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_y = (0U != vlSelfRef.__PVT__y_mant_base);
        vlSelfRef.__PVT__y_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_y_shift = (0x3fU & (IData)(vlSelfRef.__PVT__y_shift));
        vlSelfRef.__PVT__sticky_y = (0U != (vlSelfRef.__PVT__y_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_y_shift)))));
        vlSelfRef.__PVT__y_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__y_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_y_shift)));
    }
    vlSelfRef.__PVT__m_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_mx))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_mx))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__m_shift))) {
        vlSelfRef.__PVT__safe_m_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_m = (0U != vlSelfRef.__PVT__m_mant_base);
        vlSelfRef.__PVT__m_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_m_shift = (0x3fU & (IData)(vlSelfRef.__PVT__m_shift));
        vlSelfRef.__PVT__sticky_m = (0U != (vlSelfRef.__PVT__m_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_m_shift)))));
        vlSelfRef.__PVT__m_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__m_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_m_shift)));
    }
    vlSelfRef.__PVT__n_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_nx))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_nx))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__n_shift))) {
        vlSelfRef.__PVT__safe_n_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_n = (0U != vlSelfRef.__PVT__n_mant_base);
        vlSelfRef.__PVT__n_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_n_shift = (0x3fU & (IData)(vlSelfRef.__PVT__n_shift));
        vlSelfRef.__PVT__sticky_n = (0U != (vlSelfRef.__PVT__n_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_n_shift)))));
        vlSelfRef.__PVT__n_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__n_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_n_shift)));
    }
    vlSelfRef.__PVT__y_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_y));
    vlSelfRef.__PVT__m_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_mx));
    vlSelfRef.__PVT__n_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_nx));
    vlSelfRef.__PVT__op_x = vlSelfRef.__PVT__x_mant;
    vlSelfRef.__PVT__op_y = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__y_op)
                                 ? (~ vlSelfRef.__PVT__y_shifted)
                                 : vlSelfRef.__PVT__y_shifted));
    vlSelfRef.__PVT__op_m = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__m_op)
                                 ? (~ vlSelfRef.__PVT__m_shifted)
                                 : vlSelfRef.__PVT__m_shifted));
    vlSelfRef.__PVT__op_n = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__n_op)
                                 ? (~ vlSelfRef.__PVT__n_shifted)
                                 : vlSelfRef.__PVT__n_shifted));
    vlSelfRef.__PVT__csa_s1 = ((vlSelfRef.__PVT__op_x 
                                ^ vlSelfRef.__PVT__op_y) 
                               ^ vlSelfRef.__PVT__op_m);
    vlSelfRef.__PVT__csa_c1 = (((vlSelfRef.__PVT__op_x 
                                 & vlSelfRef.__PVT__op_y) 
                                | (vlSelfRef.__PVT__op_y 
                                   & vlSelfRef.__PVT__op_m)) 
                               | (vlSelfRef.__PVT__op_m 
                                  & vlSelfRef.__PVT__op_x));
    vlSelfRef.__PVT__csa_s2 = (0x7fffffffffffffffULL 
                               & ((vlSelfRef.__PVT__csa_s1 
                                   ^ VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U)) 
                                  ^ vlSelfRef.__PVT__op_n));
    vlSelfRef.__PVT__csa_c2 = (((vlSelfRef.__PVT__csa_s1 
                                 & VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U)) 
                                | (VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U) 
                                   & vlSelfRef.__PVT__op_n)) 
                               | (vlSelfRef.__PVT__op_n 
                                  & vlSelfRef.__PVT__csa_s1));
}

VL_INLINE_OPT void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__22__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__22__KET____DOT__stage_inst__1\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__22__KET__.out 
        = ((IData)(vlSymsp->TOP.adder_4input_tree32_tb__DOT__nrst)
            ? vlSelfRef.__PVT__result_out : 0ULL);
}

VL_INLINE_OPT void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__23__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__23__KET____DOT__stage_inst__0\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__safe_a = (QData)((IData)(vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__22__KET__.out));
    vlSelfRef.__PVT__safe_b = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x46U] 
                                               << 0x10U)));
    vlSelfRef.__PVT__safe_c = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x47U] 
                                               << 0x10U)));
    vlSelfRef.__PVT__safe_d = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x48U] 
                                               << 0x10U)));
    vlSelfRef.__PVT__a_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_a 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_a 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_a);
    vlSelfRef.__PVT__b_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_b 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_b 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_b);
    vlSelfRef.__PVT__c_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_c 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_c 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_c);
    vlSelfRef.__PVT__d_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_d 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_d 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_d);
    vlSelfRef.__PVT__sign_a = (1U & (IData)((vlSelfRef.__PVT__a_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_a = (0xffU & (IData)((vlSelfRef.__PVT__a_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_a = (0x3ffffffU & (IData)(vlSelfRef.__PVT__a_daz));
    vlSelfRef.__PVT__sign_b = (1U & (IData)((vlSelfRef.__PVT__b_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_b = (0xffU & (IData)((vlSelfRef.__PVT__b_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_b = (0x3ffffffU & (IData)(vlSelfRef.__PVT__b_daz));
    vlSelfRef.__PVT__sign_c = (1U & (IData)((vlSelfRef.__PVT__c_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_c = (0xffU & (IData)((vlSelfRef.__PVT__c_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_c = (0x3ffffffU & (IData)(vlSelfRef.__PVT__c_daz));
    vlSelfRef.__PVT__sign_d = (1U & (IData)((vlSelfRef.__PVT__d_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_d = (0xffU & (IData)((vlSelfRef.__PVT__d_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_d = (0x3ffffffU & (IData)(vlSelfRef.__PVT__d_daz));
    vlSelfRef.__PVT__is_nan_any = (((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                      & (0U != vlSelfRef.__PVT__frac_a)) 
                                     | ((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                        & (0U != vlSelfRef.__PVT__frac_b))) 
                                    | ((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                       & (0U != vlSelfRef.__PVT__frac_c))) 
                                   | ((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                      & (0U != vlSelfRef.__PVT__frac_d)));
    vlSelfRef.__PVT__any_pos_inf = ((((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                        & (~ (IData)(vlSelfRef.__PVT__sign_a))) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_a)))) 
                                      | (((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                          & (~ (IData)(vlSelfRef.__PVT__sign_b))) 
                                         & (~ (IData)(
                                                      (0U 
                                                       != vlSelfRef.__PVT__frac_b))))) 
                                     | (((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                         & (~ (IData)(vlSelfRef.__PVT__sign_c))) 
                                        & (~ (IData)(
                                                     (0U 
                                                      != vlSelfRef.__PVT__frac_c))))) 
                                    | (((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                        & (~ (IData)(vlSelfRef.__PVT__sign_d))) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_d)))));
    vlSelfRef.__PVT__any_neg_inf = ((((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                        & (IData)(vlSelfRef.__PVT__sign_a)) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_a)))) 
                                      | (((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                          & (IData)(vlSelfRef.__PVT__sign_b)) 
                                         & (~ (IData)(
                                                      (0U 
                                                       != vlSelfRef.__PVT__frac_b))))) 
                                     | (((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                         & (IData)(vlSelfRef.__PVT__sign_c)) 
                                        & (~ (IData)(
                                                     (0U 
                                                      != vlSelfRef.__PVT__frac_c))))) 
                                    | (((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                        & (IData)(vlSelfRef.__PVT__sign_d)) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_d)))));
    vlSelfRef.__PVT__special_case = 0U;
    vlSelfRef.__PVT__special_result = 0ULL;
    if (((IData)(vlSelfRef.__PVT__is_nan_any) | ((IData)(vlSelfRef.__PVT__any_pos_inf) 
                                                 & (IData)(vlSelfRef.__PVT__any_neg_inf)))) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x3fe000000ULL;
    } else if (vlSelfRef.__PVT__any_pos_inf) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x3fc000000ULL;
    } else if (vlSelfRef.__PVT__any_neg_inf) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x7fc000000ULL;
    }
    if (((IData)(vlSelfRef.__PVT__exp_a) >= (IData)(vlSelfRef.__PVT__exp_b))) {
        vlSelfRef.__PVT__exp_p = vlSelfRef.__PVT__exp_a;
        vlSelfRef.__PVT__frac_p = vlSelfRef.__PVT__frac_a;
        vlSelfRef.__PVT__sign_p = vlSelfRef.__PVT__sign_a;
        vlSelfRef.__PVT__exp_m = vlSelfRef.__PVT__exp_b;
        vlSelfRef.__PVT__frac_m = vlSelfRef.__PVT__frac_b;
        vlSelfRef.__PVT__sign_m = vlSelfRef.__PVT__sign_b;
    } else {
        vlSelfRef.__PVT__exp_p = vlSelfRef.__PVT__exp_b;
        vlSelfRef.__PVT__frac_p = vlSelfRef.__PVT__frac_b;
        vlSelfRef.__PVT__sign_p = vlSelfRef.__PVT__sign_b;
        vlSelfRef.__PVT__exp_m = vlSelfRef.__PVT__exp_a;
        vlSelfRef.__PVT__frac_m = vlSelfRef.__PVT__frac_a;
        vlSelfRef.__PVT__sign_m = vlSelfRef.__PVT__sign_a;
    }
    if (((IData)(vlSelfRef.__PVT__exp_c) >= (IData)(vlSelfRef.__PVT__exp_d))) {
        vlSelfRef.__PVT__exp_r = vlSelfRef.__PVT__exp_c;
        vlSelfRef.__PVT__frac_r = vlSelfRef.__PVT__frac_c;
        vlSelfRef.__PVT__sign_r = vlSelfRef.__PVT__sign_c;
        vlSelfRef.__PVT__exp_n = vlSelfRef.__PVT__exp_d;
        vlSelfRef.__PVT__frac_n = vlSelfRef.__PVT__frac_d;
        vlSelfRef.__PVT__sign_n = vlSelfRef.__PVT__sign_d;
    } else {
        vlSelfRef.__PVT__exp_r = vlSelfRef.__PVT__exp_d;
        vlSelfRef.__PVT__frac_r = vlSelfRef.__PVT__frac_d;
        vlSelfRef.__PVT__sign_r = vlSelfRef.__PVT__sign_d;
        vlSelfRef.__PVT__exp_n = vlSelfRef.__PVT__exp_c;
        vlSelfRef.__PVT__frac_n = vlSelfRef.__PVT__frac_c;
        vlSelfRef.__PVT__sign_n = vlSelfRef.__PVT__sign_c;
    }
    if (((IData)(vlSelfRef.__PVT__exp_p) >= (IData)(vlSelfRef.__PVT__exp_r))) {
        vlSelfRef.__PVT__exp_x = vlSelfRef.__PVT__exp_p;
        vlSelfRef.__PVT__frac_x = vlSelfRef.__PVT__frac_p;
        vlSelfRef.__PVT__sign_x = vlSelfRef.__PVT__sign_p;
        vlSelfRef.__PVT__exp_y = vlSelfRef.__PVT__exp_r;
        vlSelfRef.__PVT__frac_y = vlSelfRef.__PVT__frac_r;
        vlSelfRef.__PVT__sign_y = vlSelfRef.__PVT__sign_r;
        vlSelfRef.__PVT__exp_mx = vlSelfRef.__PVT__exp_m;
        vlSelfRef.__PVT__frac_mx = vlSelfRef.__PVT__frac_m;
        vlSelfRef.__PVT__sign_mx = vlSelfRef.__PVT__sign_m;
        vlSelfRef.__PVT__exp_nx = vlSelfRef.__PVT__exp_n;
        vlSelfRef.__PVT__frac_nx = vlSelfRef.__PVT__frac_n;
        vlSelfRef.__PVT__sign_nx = vlSelfRef.__PVT__sign_n;
    } else {
        vlSelfRef.__PVT__exp_x = vlSelfRef.__PVT__exp_r;
        vlSelfRef.__PVT__frac_x = vlSelfRef.__PVT__frac_r;
        vlSelfRef.__PVT__sign_x = vlSelfRef.__PVT__sign_r;
        vlSelfRef.__PVT__exp_y = vlSelfRef.__PVT__exp_p;
        vlSelfRef.__PVT__frac_y = vlSelfRef.__PVT__frac_p;
        vlSelfRef.__PVT__sign_y = vlSelfRef.__PVT__sign_p;
        vlSelfRef.__PVT__exp_mx = vlSelfRef.__PVT__exp_n;
        vlSelfRef.__PVT__frac_mx = vlSelfRef.__PVT__frac_n;
        vlSelfRef.__PVT__sign_mx = vlSelfRef.__PVT__sign_n;
        vlSelfRef.__PVT__exp_nx = vlSelfRef.__PVT__exp_m;
        vlSelfRef.__PVT__frac_nx = vlSelfRef.__PVT__frac_m;
        vlSelfRef.__PVT__sign_nx = vlSelfRef.__PVT__sign_m;
    }
    vlSelfRef.__PVT__exp_x_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_x))
                                   ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_x)));
    vlSelfRef.__PVT__exp_y_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_y))
                                   ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_y)));
    vlSelfRef.__PVT__exp_mx_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_mx))
                                    ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_mx)));
    vlSelfRef.__PVT__exp_nx_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_nx))
                                    ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_nx)));
    vlSelfRef.__PVT__y_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_y_eff)));
    vlSelfRef.__PVT__m_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_mx_eff)));
    vlSelfRef.__PVT__n_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_nx_eff)));
    vlSelfRef.__PVT__x_mant = (0x7ffffffffffffffULL 
                               & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                         (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_x))) 
                                                                           << 0x1aU) 
                                                                          | vlSelfRef.__PVT__frac_x))), 0x20U));
    vlSelfRef.__PVT__y_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_y))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_y))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__y_shift))) {
        vlSelfRef.__PVT__safe_y_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_y = (0U != vlSelfRef.__PVT__y_mant_base);
        vlSelfRef.__PVT__y_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_y_shift = (0x3fU & (IData)(vlSelfRef.__PVT__y_shift));
        vlSelfRef.__PVT__sticky_y = (0U != (vlSelfRef.__PVT__y_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_y_shift)))));
        vlSelfRef.__PVT__y_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__y_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_y_shift)));
    }
    vlSelfRef.__PVT__m_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_mx))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_mx))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__m_shift))) {
        vlSelfRef.__PVT__safe_m_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_m = (0U != vlSelfRef.__PVT__m_mant_base);
        vlSelfRef.__PVT__m_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_m_shift = (0x3fU & (IData)(vlSelfRef.__PVT__m_shift));
        vlSelfRef.__PVT__sticky_m = (0U != (vlSelfRef.__PVT__m_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_m_shift)))));
        vlSelfRef.__PVT__m_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__m_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_m_shift)));
    }
    vlSelfRef.__PVT__n_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_nx))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_nx))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__n_shift))) {
        vlSelfRef.__PVT__safe_n_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_n = (0U != vlSelfRef.__PVT__n_mant_base);
        vlSelfRef.__PVT__n_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_n_shift = (0x3fU & (IData)(vlSelfRef.__PVT__n_shift));
        vlSelfRef.__PVT__sticky_n = (0U != (vlSelfRef.__PVT__n_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_n_shift)))));
        vlSelfRef.__PVT__n_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__n_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_n_shift)));
    }
    vlSelfRef.__PVT__y_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_y));
    vlSelfRef.__PVT__m_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_mx));
    vlSelfRef.__PVT__n_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_nx));
    vlSelfRef.__PVT__op_x = vlSelfRef.__PVT__x_mant;
    vlSelfRef.__PVT__op_y = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__y_op)
                                 ? (~ vlSelfRef.__PVT__y_shifted)
                                 : vlSelfRef.__PVT__y_shifted));
    vlSelfRef.__PVT__op_m = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__m_op)
                                 ? (~ vlSelfRef.__PVT__m_shifted)
                                 : vlSelfRef.__PVT__m_shifted));
    vlSelfRef.__PVT__op_n = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__n_op)
                                 ? (~ vlSelfRef.__PVT__n_shifted)
                                 : vlSelfRef.__PVT__n_shifted));
    vlSelfRef.__PVT__csa_s1 = ((vlSelfRef.__PVT__op_x 
                                ^ vlSelfRef.__PVT__op_y) 
                               ^ vlSelfRef.__PVT__op_m);
    vlSelfRef.__PVT__csa_c1 = (((vlSelfRef.__PVT__op_x 
                                 & vlSelfRef.__PVT__op_y) 
                                | (vlSelfRef.__PVT__op_y 
                                   & vlSelfRef.__PVT__op_m)) 
                               | (vlSelfRef.__PVT__op_m 
                                  & vlSelfRef.__PVT__op_x));
    vlSelfRef.__PVT__csa_s2 = (0x7fffffffffffffffULL 
                               & ((vlSelfRef.__PVT__csa_s1 
                                   ^ VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U)) 
                                  ^ vlSelfRef.__PVT__op_n));
    vlSelfRef.__PVT__csa_c2 = (((vlSelfRef.__PVT__csa_s1 
                                 & VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U)) 
                                | (VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U) 
                                   & vlSelfRef.__PVT__op_n)) 
                               | (vlSelfRef.__PVT__op_n 
                                  & vlSelfRef.__PVT__csa_s1));
}

VL_INLINE_OPT void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__23__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__23__KET____DOT__stage_inst__1\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__23__KET__.out 
        = ((IData)(vlSymsp->TOP.adder_4input_tree32_tb__DOT__nrst)
            ? vlSelfRef.__PVT__result_out : 0ULL);
}

VL_INLINE_OPT void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__24__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__24__KET____DOT__stage_inst__0\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__safe_a = (QData)((IData)(vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__23__KET__.out));
    vlSelfRef.__PVT__safe_b = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x49U] 
                                               << 0x10U)));
    vlSelfRef.__PVT__safe_c = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x4aU] 
                                               << 0x10U)));
    vlSelfRef.__PVT__safe_d = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x4bU] 
                                               << 0x10U)));
    vlSelfRef.__PVT__a_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_a 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_a 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_a);
    vlSelfRef.__PVT__b_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_b 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_b 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_b);
    vlSelfRef.__PVT__c_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_c 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_c 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_c);
    vlSelfRef.__PVT__d_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_d 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_d 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_d);
    vlSelfRef.__PVT__sign_a = (1U & (IData)((vlSelfRef.__PVT__a_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_a = (0xffU & (IData)((vlSelfRef.__PVT__a_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_a = (0x3ffffffU & (IData)(vlSelfRef.__PVT__a_daz));
    vlSelfRef.__PVT__sign_b = (1U & (IData)((vlSelfRef.__PVT__b_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_b = (0xffU & (IData)((vlSelfRef.__PVT__b_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_b = (0x3ffffffU & (IData)(vlSelfRef.__PVT__b_daz));
    vlSelfRef.__PVT__sign_c = (1U & (IData)((vlSelfRef.__PVT__c_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_c = (0xffU & (IData)((vlSelfRef.__PVT__c_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_c = (0x3ffffffU & (IData)(vlSelfRef.__PVT__c_daz));
    vlSelfRef.__PVT__sign_d = (1U & (IData)((vlSelfRef.__PVT__d_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_d = (0xffU & (IData)((vlSelfRef.__PVT__d_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_d = (0x3ffffffU & (IData)(vlSelfRef.__PVT__d_daz));
    vlSelfRef.__PVT__is_nan_any = (((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                      & (0U != vlSelfRef.__PVT__frac_a)) 
                                     | ((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                        & (0U != vlSelfRef.__PVT__frac_b))) 
                                    | ((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                       & (0U != vlSelfRef.__PVT__frac_c))) 
                                   | ((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                      & (0U != vlSelfRef.__PVT__frac_d)));
    vlSelfRef.__PVT__any_pos_inf = ((((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                        & (~ (IData)(vlSelfRef.__PVT__sign_a))) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_a)))) 
                                      | (((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                          & (~ (IData)(vlSelfRef.__PVT__sign_b))) 
                                         & (~ (IData)(
                                                      (0U 
                                                       != vlSelfRef.__PVT__frac_b))))) 
                                     | (((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                         & (~ (IData)(vlSelfRef.__PVT__sign_c))) 
                                        & (~ (IData)(
                                                     (0U 
                                                      != vlSelfRef.__PVT__frac_c))))) 
                                    | (((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                        & (~ (IData)(vlSelfRef.__PVT__sign_d))) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_d)))));
    vlSelfRef.__PVT__any_neg_inf = ((((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                        & (IData)(vlSelfRef.__PVT__sign_a)) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_a)))) 
                                      | (((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                          & (IData)(vlSelfRef.__PVT__sign_b)) 
                                         & (~ (IData)(
                                                      (0U 
                                                       != vlSelfRef.__PVT__frac_b))))) 
                                     | (((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                         & (IData)(vlSelfRef.__PVT__sign_c)) 
                                        & (~ (IData)(
                                                     (0U 
                                                      != vlSelfRef.__PVT__frac_c))))) 
                                    | (((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                        & (IData)(vlSelfRef.__PVT__sign_d)) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_d)))));
    vlSelfRef.__PVT__special_case = 0U;
    vlSelfRef.__PVT__special_result = 0ULL;
    if (((IData)(vlSelfRef.__PVT__is_nan_any) | ((IData)(vlSelfRef.__PVT__any_pos_inf) 
                                                 & (IData)(vlSelfRef.__PVT__any_neg_inf)))) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x3fe000000ULL;
    } else if (vlSelfRef.__PVT__any_pos_inf) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x3fc000000ULL;
    } else if (vlSelfRef.__PVT__any_neg_inf) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x7fc000000ULL;
    }
    if (((IData)(vlSelfRef.__PVT__exp_a) >= (IData)(vlSelfRef.__PVT__exp_b))) {
        vlSelfRef.__PVT__exp_p = vlSelfRef.__PVT__exp_a;
        vlSelfRef.__PVT__frac_p = vlSelfRef.__PVT__frac_a;
        vlSelfRef.__PVT__sign_p = vlSelfRef.__PVT__sign_a;
        vlSelfRef.__PVT__exp_m = vlSelfRef.__PVT__exp_b;
        vlSelfRef.__PVT__frac_m = vlSelfRef.__PVT__frac_b;
        vlSelfRef.__PVT__sign_m = vlSelfRef.__PVT__sign_b;
    } else {
        vlSelfRef.__PVT__exp_p = vlSelfRef.__PVT__exp_b;
        vlSelfRef.__PVT__frac_p = vlSelfRef.__PVT__frac_b;
        vlSelfRef.__PVT__sign_p = vlSelfRef.__PVT__sign_b;
        vlSelfRef.__PVT__exp_m = vlSelfRef.__PVT__exp_a;
        vlSelfRef.__PVT__frac_m = vlSelfRef.__PVT__frac_a;
        vlSelfRef.__PVT__sign_m = vlSelfRef.__PVT__sign_a;
    }
    if (((IData)(vlSelfRef.__PVT__exp_c) >= (IData)(vlSelfRef.__PVT__exp_d))) {
        vlSelfRef.__PVT__exp_r = vlSelfRef.__PVT__exp_c;
        vlSelfRef.__PVT__frac_r = vlSelfRef.__PVT__frac_c;
        vlSelfRef.__PVT__sign_r = vlSelfRef.__PVT__sign_c;
        vlSelfRef.__PVT__exp_n = vlSelfRef.__PVT__exp_d;
        vlSelfRef.__PVT__frac_n = vlSelfRef.__PVT__frac_d;
        vlSelfRef.__PVT__sign_n = vlSelfRef.__PVT__sign_d;
    } else {
        vlSelfRef.__PVT__exp_r = vlSelfRef.__PVT__exp_d;
        vlSelfRef.__PVT__frac_r = vlSelfRef.__PVT__frac_d;
        vlSelfRef.__PVT__sign_r = vlSelfRef.__PVT__sign_d;
        vlSelfRef.__PVT__exp_n = vlSelfRef.__PVT__exp_c;
        vlSelfRef.__PVT__frac_n = vlSelfRef.__PVT__frac_c;
        vlSelfRef.__PVT__sign_n = vlSelfRef.__PVT__sign_c;
    }
    if (((IData)(vlSelfRef.__PVT__exp_p) >= (IData)(vlSelfRef.__PVT__exp_r))) {
        vlSelfRef.__PVT__exp_x = vlSelfRef.__PVT__exp_p;
        vlSelfRef.__PVT__frac_x = vlSelfRef.__PVT__frac_p;
        vlSelfRef.__PVT__sign_x = vlSelfRef.__PVT__sign_p;
        vlSelfRef.__PVT__exp_y = vlSelfRef.__PVT__exp_r;
        vlSelfRef.__PVT__frac_y = vlSelfRef.__PVT__frac_r;
        vlSelfRef.__PVT__sign_y = vlSelfRef.__PVT__sign_r;
        vlSelfRef.__PVT__exp_mx = vlSelfRef.__PVT__exp_m;
        vlSelfRef.__PVT__frac_mx = vlSelfRef.__PVT__frac_m;
        vlSelfRef.__PVT__sign_mx = vlSelfRef.__PVT__sign_m;
        vlSelfRef.__PVT__exp_nx = vlSelfRef.__PVT__exp_n;
        vlSelfRef.__PVT__frac_nx = vlSelfRef.__PVT__frac_n;
        vlSelfRef.__PVT__sign_nx = vlSelfRef.__PVT__sign_n;
    } else {
        vlSelfRef.__PVT__exp_x = vlSelfRef.__PVT__exp_r;
        vlSelfRef.__PVT__frac_x = vlSelfRef.__PVT__frac_r;
        vlSelfRef.__PVT__sign_x = vlSelfRef.__PVT__sign_r;
        vlSelfRef.__PVT__exp_y = vlSelfRef.__PVT__exp_p;
        vlSelfRef.__PVT__frac_y = vlSelfRef.__PVT__frac_p;
        vlSelfRef.__PVT__sign_y = vlSelfRef.__PVT__sign_p;
        vlSelfRef.__PVT__exp_mx = vlSelfRef.__PVT__exp_n;
        vlSelfRef.__PVT__frac_mx = vlSelfRef.__PVT__frac_n;
        vlSelfRef.__PVT__sign_mx = vlSelfRef.__PVT__sign_n;
        vlSelfRef.__PVT__exp_nx = vlSelfRef.__PVT__exp_m;
        vlSelfRef.__PVT__frac_nx = vlSelfRef.__PVT__frac_m;
        vlSelfRef.__PVT__sign_nx = vlSelfRef.__PVT__sign_m;
    }
    vlSelfRef.__PVT__exp_x_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_x))
                                   ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_x)));
    vlSelfRef.__PVT__exp_y_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_y))
                                   ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_y)));
    vlSelfRef.__PVT__exp_mx_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_mx))
                                    ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_mx)));
    vlSelfRef.__PVT__exp_nx_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_nx))
                                    ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_nx)));
    vlSelfRef.__PVT__y_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_y_eff)));
    vlSelfRef.__PVT__m_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_mx_eff)));
    vlSelfRef.__PVT__n_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_nx_eff)));
    vlSelfRef.__PVT__x_mant = (0x7ffffffffffffffULL 
                               & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                         (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_x))) 
                                                                           << 0x1aU) 
                                                                          | vlSelfRef.__PVT__frac_x))), 0x20U));
    vlSelfRef.__PVT__y_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_y))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_y))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__y_shift))) {
        vlSelfRef.__PVT__safe_y_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_y = (0U != vlSelfRef.__PVT__y_mant_base);
        vlSelfRef.__PVT__y_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_y_shift = (0x3fU & (IData)(vlSelfRef.__PVT__y_shift));
        vlSelfRef.__PVT__sticky_y = (0U != (vlSelfRef.__PVT__y_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_y_shift)))));
        vlSelfRef.__PVT__y_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__y_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_y_shift)));
    }
    vlSelfRef.__PVT__m_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_mx))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_mx))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__m_shift))) {
        vlSelfRef.__PVT__safe_m_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_m = (0U != vlSelfRef.__PVT__m_mant_base);
        vlSelfRef.__PVT__m_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_m_shift = (0x3fU & (IData)(vlSelfRef.__PVT__m_shift));
        vlSelfRef.__PVT__sticky_m = (0U != (vlSelfRef.__PVT__m_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_m_shift)))));
        vlSelfRef.__PVT__m_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__m_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_m_shift)));
    }
    vlSelfRef.__PVT__n_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_nx))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_nx))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__n_shift))) {
        vlSelfRef.__PVT__safe_n_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_n = (0U != vlSelfRef.__PVT__n_mant_base);
        vlSelfRef.__PVT__n_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_n_shift = (0x3fU & (IData)(vlSelfRef.__PVT__n_shift));
        vlSelfRef.__PVT__sticky_n = (0U != (vlSelfRef.__PVT__n_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_n_shift)))));
        vlSelfRef.__PVT__n_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__n_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_n_shift)));
    }
    vlSelfRef.__PVT__y_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_y));
    vlSelfRef.__PVT__m_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_mx));
    vlSelfRef.__PVT__n_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_nx));
    vlSelfRef.__PVT__op_x = vlSelfRef.__PVT__x_mant;
    vlSelfRef.__PVT__op_y = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__y_op)
                                 ? (~ vlSelfRef.__PVT__y_shifted)
                                 : vlSelfRef.__PVT__y_shifted));
    vlSelfRef.__PVT__op_m = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__m_op)
                                 ? (~ vlSelfRef.__PVT__m_shifted)
                                 : vlSelfRef.__PVT__m_shifted));
    vlSelfRef.__PVT__op_n = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__n_op)
                                 ? (~ vlSelfRef.__PVT__n_shifted)
                                 : vlSelfRef.__PVT__n_shifted));
    vlSelfRef.__PVT__csa_s1 = ((vlSelfRef.__PVT__op_x 
                                ^ vlSelfRef.__PVT__op_y) 
                               ^ vlSelfRef.__PVT__op_m);
    vlSelfRef.__PVT__csa_c1 = (((vlSelfRef.__PVT__op_x 
                                 & vlSelfRef.__PVT__op_y) 
                                | (vlSelfRef.__PVT__op_y 
                                   & vlSelfRef.__PVT__op_m)) 
                               | (vlSelfRef.__PVT__op_m 
                                  & vlSelfRef.__PVT__op_x));
    vlSelfRef.__PVT__csa_s2 = (0x7fffffffffffffffULL 
                               & ((vlSelfRef.__PVT__csa_s1 
                                   ^ VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U)) 
                                  ^ vlSelfRef.__PVT__op_n));
    vlSelfRef.__PVT__csa_c2 = (((vlSelfRef.__PVT__csa_s1 
                                 & VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U)) 
                                | (VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U) 
                                   & vlSelfRef.__PVT__op_n)) 
                               | (vlSelfRef.__PVT__op_n 
                                  & vlSelfRef.__PVT__csa_s1));
}

VL_INLINE_OPT void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__24__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__24__KET____DOT__stage_inst__1\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__24__KET__.out 
        = ((IData)(vlSymsp->TOP.adder_4input_tree32_tb__DOT__nrst)
            ? vlSelfRef.__PVT__result_out : 0ULL);
}

VL_INLINE_OPT void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__25__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__25__KET____DOT__stage_inst__0\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__safe_a = (QData)((IData)(vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__24__KET__.out));
    vlSelfRef.__PVT__safe_b = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x4cU] 
                                               << 0x10U)));
    vlSelfRef.__PVT__safe_c = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x4dU] 
                                               << 0x10U)));
    vlSelfRef.__PVT__safe_d = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x4eU] 
                                               << 0x10U)));
    vlSelfRef.__PVT__a_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_a 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_a 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_a);
    vlSelfRef.__PVT__b_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_b 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_b 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_b);
    vlSelfRef.__PVT__c_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_c 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_c 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_c);
    vlSelfRef.__PVT__d_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_d 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_d 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_d);
    vlSelfRef.__PVT__sign_a = (1U & (IData)((vlSelfRef.__PVT__a_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_a = (0xffU & (IData)((vlSelfRef.__PVT__a_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_a = (0x3ffffffU & (IData)(vlSelfRef.__PVT__a_daz));
    vlSelfRef.__PVT__sign_b = (1U & (IData)((vlSelfRef.__PVT__b_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_b = (0xffU & (IData)((vlSelfRef.__PVT__b_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_b = (0x3ffffffU & (IData)(vlSelfRef.__PVT__b_daz));
    vlSelfRef.__PVT__sign_c = (1U & (IData)((vlSelfRef.__PVT__c_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_c = (0xffU & (IData)((vlSelfRef.__PVT__c_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_c = (0x3ffffffU & (IData)(vlSelfRef.__PVT__c_daz));
    vlSelfRef.__PVT__sign_d = (1U & (IData)((vlSelfRef.__PVT__d_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_d = (0xffU & (IData)((vlSelfRef.__PVT__d_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_d = (0x3ffffffU & (IData)(vlSelfRef.__PVT__d_daz));
    vlSelfRef.__PVT__is_nan_any = (((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                      & (0U != vlSelfRef.__PVT__frac_a)) 
                                     | ((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                        & (0U != vlSelfRef.__PVT__frac_b))) 
                                    | ((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                       & (0U != vlSelfRef.__PVT__frac_c))) 
                                   | ((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                      & (0U != vlSelfRef.__PVT__frac_d)));
    vlSelfRef.__PVT__any_pos_inf = ((((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                        & (~ (IData)(vlSelfRef.__PVT__sign_a))) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_a)))) 
                                      | (((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                          & (~ (IData)(vlSelfRef.__PVT__sign_b))) 
                                         & (~ (IData)(
                                                      (0U 
                                                       != vlSelfRef.__PVT__frac_b))))) 
                                     | (((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                         & (~ (IData)(vlSelfRef.__PVT__sign_c))) 
                                        & (~ (IData)(
                                                     (0U 
                                                      != vlSelfRef.__PVT__frac_c))))) 
                                    | (((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                        & (~ (IData)(vlSelfRef.__PVT__sign_d))) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_d)))));
    vlSelfRef.__PVT__any_neg_inf = ((((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                        & (IData)(vlSelfRef.__PVT__sign_a)) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_a)))) 
                                      | (((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                          & (IData)(vlSelfRef.__PVT__sign_b)) 
                                         & (~ (IData)(
                                                      (0U 
                                                       != vlSelfRef.__PVT__frac_b))))) 
                                     | (((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                         & (IData)(vlSelfRef.__PVT__sign_c)) 
                                        & (~ (IData)(
                                                     (0U 
                                                      != vlSelfRef.__PVT__frac_c))))) 
                                    | (((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                        & (IData)(vlSelfRef.__PVT__sign_d)) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_d)))));
    vlSelfRef.__PVT__special_case = 0U;
    vlSelfRef.__PVT__special_result = 0ULL;
    if (((IData)(vlSelfRef.__PVT__is_nan_any) | ((IData)(vlSelfRef.__PVT__any_pos_inf) 
                                                 & (IData)(vlSelfRef.__PVT__any_neg_inf)))) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x3fe000000ULL;
    } else if (vlSelfRef.__PVT__any_pos_inf) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x3fc000000ULL;
    } else if (vlSelfRef.__PVT__any_neg_inf) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x7fc000000ULL;
    }
    if (((IData)(vlSelfRef.__PVT__exp_a) >= (IData)(vlSelfRef.__PVT__exp_b))) {
        vlSelfRef.__PVT__exp_p = vlSelfRef.__PVT__exp_a;
        vlSelfRef.__PVT__frac_p = vlSelfRef.__PVT__frac_a;
        vlSelfRef.__PVT__sign_p = vlSelfRef.__PVT__sign_a;
        vlSelfRef.__PVT__exp_m = vlSelfRef.__PVT__exp_b;
        vlSelfRef.__PVT__frac_m = vlSelfRef.__PVT__frac_b;
        vlSelfRef.__PVT__sign_m = vlSelfRef.__PVT__sign_b;
    } else {
        vlSelfRef.__PVT__exp_p = vlSelfRef.__PVT__exp_b;
        vlSelfRef.__PVT__frac_p = vlSelfRef.__PVT__frac_b;
        vlSelfRef.__PVT__sign_p = vlSelfRef.__PVT__sign_b;
        vlSelfRef.__PVT__exp_m = vlSelfRef.__PVT__exp_a;
        vlSelfRef.__PVT__frac_m = vlSelfRef.__PVT__frac_a;
        vlSelfRef.__PVT__sign_m = vlSelfRef.__PVT__sign_a;
    }
    if (((IData)(vlSelfRef.__PVT__exp_c) >= (IData)(vlSelfRef.__PVT__exp_d))) {
        vlSelfRef.__PVT__exp_r = vlSelfRef.__PVT__exp_c;
        vlSelfRef.__PVT__frac_r = vlSelfRef.__PVT__frac_c;
        vlSelfRef.__PVT__sign_r = vlSelfRef.__PVT__sign_c;
        vlSelfRef.__PVT__exp_n = vlSelfRef.__PVT__exp_d;
        vlSelfRef.__PVT__frac_n = vlSelfRef.__PVT__frac_d;
        vlSelfRef.__PVT__sign_n = vlSelfRef.__PVT__sign_d;
    } else {
        vlSelfRef.__PVT__exp_r = vlSelfRef.__PVT__exp_d;
        vlSelfRef.__PVT__frac_r = vlSelfRef.__PVT__frac_d;
        vlSelfRef.__PVT__sign_r = vlSelfRef.__PVT__sign_d;
        vlSelfRef.__PVT__exp_n = vlSelfRef.__PVT__exp_c;
        vlSelfRef.__PVT__frac_n = vlSelfRef.__PVT__frac_c;
        vlSelfRef.__PVT__sign_n = vlSelfRef.__PVT__sign_c;
    }
    if (((IData)(vlSelfRef.__PVT__exp_p) >= (IData)(vlSelfRef.__PVT__exp_r))) {
        vlSelfRef.__PVT__exp_x = vlSelfRef.__PVT__exp_p;
        vlSelfRef.__PVT__frac_x = vlSelfRef.__PVT__frac_p;
        vlSelfRef.__PVT__sign_x = vlSelfRef.__PVT__sign_p;
        vlSelfRef.__PVT__exp_y = vlSelfRef.__PVT__exp_r;
        vlSelfRef.__PVT__frac_y = vlSelfRef.__PVT__frac_r;
        vlSelfRef.__PVT__sign_y = vlSelfRef.__PVT__sign_r;
        vlSelfRef.__PVT__exp_mx = vlSelfRef.__PVT__exp_m;
        vlSelfRef.__PVT__frac_mx = vlSelfRef.__PVT__frac_m;
        vlSelfRef.__PVT__sign_mx = vlSelfRef.__PVT__sign_m;
        vlSelfRef.__PVT__exp_nx = vlSelfRef.__PVT__exp_n;
        vlSelfRef.__PVT__frac_nx = vlSelfRef.__PVT__frac_n;
        vlSelfRef.__PVT__sign_nx = vlSelfRef.__PVT__sign_n;
    } else {
        vlSelfRef.__PVT__exp_x = vlSelfRef.__PVT__exp_r;
        vlSelfRef.__PVT__frac_x = vlSelfRef.__PVT__frac_r;
        vlSelfRef.__PVT__sign_x = vlSelfRef.__PVT__sign_r;
        vlSelfRef.__PVT__exp_y = vlSelfRef.__PVT__exp_p;
        vlSelfRef.__PVT__frac_y = vlSelfRef.__PVT__frac_p;
        vlSelfRef.__PVT__sign_y = vlSelfRef.__PVT__sign_p;
        vlSelfRef.__PVT__exp_mx = vlSelfRef.__PVT__exp_n;
        vlSelfRef.__PVT__frac_mx = vlSelfRef.__PVT__frac_n;
        vlSelfRef.__PVT__sign_mx = vlSelfRef.__PVT__sign_n;
        vlSelfRef.__PVT__exp_nx = vlSelfRef.__PVT__exp_m;
        vlSelfRef.__PVT__frac_nx = vlSelfRef.__PVT__frac_m;
        vlSelfRef.__PVT__sign_nx = vlSelfRef.__PVT__sign_m;
    }
    vlSelfRef.__PVT__exp_x_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_x))
                                   ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_x)));
    vlSelfRef.__PVT__exp_y_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_y))
                                   ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_y)));
    vlSelfRef.__PVT__exp_mx_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_mx))
                                    ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_mx)));
    vlSelfRef.__PVT__exp_nx_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_nx))
                                    ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_nx)));
    vlSelfRef.__PVT__y_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_y_eff)));
    vlSelfRef.__PVT__m_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_mx_eff)));
    vlSelfRef.__PVT__n_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_nx_eff)));
    vlSelfRef.__PVT__x_mant = (0x7ffffffffffffffULL 
                               & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                         (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_x))) 
                                                                           << 0x1aU) 
                                                                          | vlSelfRef.__PVT__frac_x))), 0x20U));
    vlSelfRef.__PVT__y_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_y))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_y))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__y_shift))) {
        vlSelfRef.__PVT__safe_y_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_y = (0U != vlSelfRef.__PVT__y_mant_base);
        vlSelfRef.__PVT__y_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_y_shift = (0x3fU & (IData)(vlSelfRef.__PVT__y_shift));
        vlSelfRef.__PVT__sticky_y = (0U != (vlSelfRef.__PVT__y_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_y_shift)))));
        vlSelfRef.__PVT__y_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__y_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_y_shift)));
    }
    vlSelfRef.__PVT__m_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_mx))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_mx))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__m_shift))) {
        vlSelfRef.__PVT__safe_m_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_m = (0U != vlSelfRef.__PVT__m_mant_base);
        vlSelfRef.__PVT__m_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_m_shift = (0x3fU & (IData)(vlSelfRef.__PVT__m_shift));
        vlSelfRef.__PVT__sticky_m = (0U != (vlSelfRef.__PVT__m_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_m_shift)))));
        vlSelfRef.__PVT__m_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__m_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_m_shift)));
    }
    vlSelfRef.__PVT__n_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_nx))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_nx))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__n_shift))) {
        vlSelfRef.__PVT__safe_n_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_n = (0U != vlSelfRef.__PVT__n_mant_base);
        vlSelfRef.__PVT__n_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_n_shift = (0x3fU & (IData)(vlSelfRef.__PVT__n_shift));
        vlSelfRef.__PVT__sticky_n = (0U != (vlSelfRef.__PVT__n_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_n_shift)))));
        vlSelfRef.__PVT__n_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__n_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_n_shift)));
    }
    vlSelfRef.__PVT__y_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_y));
    vlSelfRef.__PVT__m_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_mx));
    vlSelfRef.__PVT__n_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_nx));
    vlSelfRef.__PVT__op_x = vlSelfRef.__PVT__x_mant;
    vlSelfRef.__PVT__op_y = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__y_op)
                                 ? (~ vlSelfRef.__PVT__y_shifted)
                                 : vlSelfRef.__PVT__y_shifted));
    vlSelfRef.__PVT__op_m = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__m_op)
                                 ? (~ vlSelfRef.__PVT__m_shifted)
                                 : vlSelfRef.__PVT__m_shifted));
    vlSelfRef.__PVT__op_n = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__n_op)
                                 ? (~ vlSelfRef.__PVT__n_shifted)
                                 : vlSelfRef.__PVT__n_shifted));
    vlSelfRef.__PVT__csa_s1 = ((vlSelfRef.__PVT__op_x 
                                ^ vlSelfRef.__PVT__op_y) 
                               ^ vlSelfRef.__PVT__op_m);
    vlSelfRef.__PVT__csa_c1 = (((vlSelfRef.__PVT__op_x 
                                 & vlSelfRef.__PVT__op_y) 
                                | (vlSelfRef.__PVT__op_y 
                                   & vlSelfRef.__PVT__op_m)) 
                               | (vlSelfRef.__PVT__op_m 
                                  & vlSelfRef.__PVT__op_x));
    vlSelfRef.__PVT__csa_s2 = (0x7fffffffffffffffULL 
                               & ((vlSelfRef.__PVT__csa_s1 
                                   ^ VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U)) 
                                  ^ vlSelfRef.__PVT__op_n));
    vlSelfRef.__PVT__csa_c2 = (((vlSelfRef.__PVT__csa_s1 
                                 & VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U)) 
                                | (VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U) 
                                   & vlSelfRef.__PVT__op_n)) 
                               | (vlSelfRef.__PVT__op_n 
                                  & vlSelfRef.__PVT__csa_s1));
}

VL_INLINE_OPT void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__25__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__25__KET____DOT__stage_inst__1\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__25__KET__.out 
        = ((IData)(vlSymsp->TOP.adder_4input_tree32_tb__DOT__nrst)
            ? vlSelfRef.__PVT__result_out : 0ULL);
}

VL_INLINE_OPT void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__26__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__26__KET____DOT__stage_inst__0\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__safe_a = (QData)((IData)(vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__25__KET__.out));
    vlSelfRef.__PVT__safe_b = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x4fU] 
                                               << 0x10U)));
    vlSelfRef.__PVT__safe_c = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x50U] 
                                               << 0x10U)));
    vlSelfRef.__PVT__safe_d = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x51U] 
                                               << 0x10U)));
    vlSelfRef.__PVT__a_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_a 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_a 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_a);
    vlSelfRef.__PVT__b_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_b 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_b 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_b);
    vlSelfRef.__PVT__c_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_c 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_c 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_c);
    vlSelfRef.__PVT__d_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_d 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_d 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_d);
    vlSelfRef.__PVT__sign_a = (1U & (IData)((vlSelfRef.__PVT__a_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_a = (0xffU & (IData)((vlSelfRef.__PVT__a_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_a = (0x3ffffffU & (IData)(vlSelfRef.__PVT__a_daz));
    vlSelfRef.__PVT__sign_b = (1U & (IData)((vlSelfRef.__PVT__b_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_b = (0xffU & (IData)((vlSelfRef.__PVT__b_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_b = (0x3ffffffU & (IData)(vlSelfRef.__PVT__b_daz));
    vlSelfRef.__PVT__sign_c = (1U & (IData)((vlSelfRef.__PVT__c_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_c = (0xffU & (IData)((vlSelfRef.__PVT__c_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_c = (0x3ffffffU & (IData)(vlSelfRef.__PVT__c_daz));
    vlSelfRef.__PVT__sign_d = (1U & (IData)((vlSelfRef.__PVT__d_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_d = (0xffU & (IData)((vlSelfRef.__PVT__d_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_d = (0x3ffffffU & (IData)(vlSelfRef.__PVT__d_daz));
    vlSelfRef.__PVT__is_nan_any = (((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                      & (0U != vlSelfRef.__PVT__frac_a)) 
                                     | ((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                        & (0U != vlSelfRef.__PVT__frac_b))) 
                                    | ((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                       & (0U != vlSelfRef.__PVT__frac_c))) 
                                   | ((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                      & (0U != vlSelfRef.__PVT__frac_d)));
    vlSelfRef.__PVT__any_pos_inf = ((((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                        & (~ (IData)(vlSelfRef.__PVT__sign_a))) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_a)))) 
                                      | (((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                          & (~ (IData)(vlSelfRef.__PVT__sign_b))) 
                                         & (~ (IData)(
                                                      (0U 
                                                       != vlSelfRef.__PVT__frac_b))))) 
                                     | (((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                         & (~ (IData)(vlSelfRef.__PVT__sign_c))) 
                                        & (~ (IData)(
                                                     (0U 
                                                      != vlSelfRef.__PVT__frac_c))))) 
                                    | (((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                        & (~ (IData)(vlSelfRef.__PVT__sign_d))) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_d)))));
    vlSelfRef.__PVT__any_neg_inf = ((((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                        & (IData)(vlSelfRef.__PVT__sign_a)) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_a)))) 
                                      | (((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                          & (IData)(vlSelfRef.__PVT__sign_b)) 
                                         & (~ (IData)(
                                                      (0U 
                                                       != vlSelfRef.__PVT__frac_b))))) 
                                     | (((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                         & (IData)(vlSelfRef.__PVT__sign_c)) 
                                        & (~ (IData)(
                                                     (0U 
                                                      != vlSelfRef.__PVT__frac_c))))) 
                                    | (((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                        & (IData)(vlSelfRef.__PVT__sign_d)) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_d)))));
    vlSelfRef.__PVT__special_case = 0U;
    vlSelfRef.__PVT__special_result = 0ULL;
    if (((IData)(vlSelfRef.__PVT__is_nan_any) | ((IData)(vlSelfRef.__PVT__any_pos_inf) 
                                                 & (IData)(vlSelfRef.__PVT__any_neg_inf)))) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x3fe000000ULL;
    } else if (vlSelfRef.__PVT__any_pos_inf) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x3fc000000ULL;
    } else if (vlSelfRef.__PVT__any_neg_inf) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x7fc000000ULL;
    }
    if (((IData)(vlSelfRef.__PVT__exp_a) >= (IData)(vlSelfRef.__PVT__exp_b))) {
        vlSelfRef.__PVT__exp_p = vlSelfRef.__PVT__exp_a;
        vlSelfRef.__PVT__frac_p = vlSelfRef.__PVT__frac_a;
        vlSelfRef.__PVT__sign_p = vlSelfRef.__PVT__sign_a;
        vlSelfRef.__PVT__exp_m = vlSelfRef.__PVT__exp_b;
        vlSelfRef.__PVT__frac_m = vlSelfRef.__PVT__frac_b;
        vlSelfRef.__PVT__sign_m = vlSelfRef.__PVT__sign_b;
    } else {
        vlSelfRef.__PVT__exp_p = vlSelfRef.__PVT__exp_b;
        vlSelfRef.__PVT__frac_p = vlSelfRef.__PVT__frac_b;
        vlSelfRef.__PVT__sign_p = vlSelfRef.__PVT__sign_b;
        vlSelfRef.__PVT__exp_m = vlSelfRef.__PVT__exp_a;
        vlSelfRef.__PVT__frac_m = vlSelfRef.__PVT__frac_a;
        vlSelfRef.__PVT__sign_m = vlSelfRef.__PVT__sign_a;
    }
    if (((IData)(vlSelfRef.__PVT__exp_c) >= (IData)(vlSelfRef.__PVT__exp_d))) {
        vlSelfRef.__PVT__exp_r = vlSelfRef.__PVT__exp_c;
        vlSelfRef.__PVT__frac_r = vlSelfRef.__PVT__frac_c;
        vlSelfRef.__PVT__sign_r = vlSelfRef.__PVT__sign_c;
        vlSelfRef.__PVT__exp_n = vlSelfRef.__PVT__exp_d;
        vlSelfRef.__PVT__frac_n = vlSelfRef.__PVT__frac_d;
        vlSelfRef.__PVT__sign_n = vlSelfRef.__PVT__sign_d;
    } else {
        vlSelfRef.__PVT__exp_r = vlSelfRef.__PVT__exp_d;
        vlSelfRef.__PVT__frac_r = vlSelfRef.__PVT__frac_d;
        vlSelfRef.__PVT__sign_r = vlSelfRef.__PVT__sign_d;
        vlSelfRef.__PVT__exp_n = vlSelfRef.__PVT__exp_c;
        vlSelfRef.__PVT__frac_n = vlSelfRef.__PVT__frac_c;
        vlSelfRef.__PVT__sign_n = vlSelfRef.__PVT__sign_c;
    }
    if (((IData)(vlSelfRef.__PVT__exp_p) >= (IData)(vlSelfRef.__PVT__exp_r))) {
        vlSelfRef.__PVT__exp_x = vlSelfRef.__PVT__exp_p;
        vlSelfRef.__PVT__frac_x = vlSelfRef.__PVT__frac_p;
        vlSelfRef.__PVT__sign_x = vlSelfRef.__PVT__sign_p;
        vlSelfRef.__PVT__exp_y = vlSelfRef.__PVT__exp_r;
        vlSelfRef.__PVT__frac_y = vlSelfRef.__PVT__frac_r;
        vlSelfRef.__PVT__sign_y = vlSelfRef.__PVT__sign_r;
        vlSelfRef.__PVT__exp_mx = vlSelfRef.__PVT__exp_m;
        vlSelfRef.__PVT__frac_mx = vlSelfRef.__PVT__frac_m;
        vlSelfRef.__PVT__sign_mx = vlSelfRef.__PVT__sign_m;
        vlSelfRef.__PVT__exp_nx = vlSelfRef.__PVT__exp_n;
        vlSelfRef.__PVT__frac_nx = vlSelfRef.__PVT__frac_n;
        vlSelfRef.__PVT__sign_nx = vlSelfRef.__PVT__sign_n;
    } else {
        vlSelfRef.__PVT__exp_x = vlSelfRef.__PVT__exp_r;
        vlSelfRef.__PVT__frac_x = vlSelfRef.__PVT__frac_r;
        vlSelfRef.__PVT__sign_x = vlSelfRef.__PVT__sign_r;
        vlSelfRef.__PVT__exp_y = vlSelfRef.__PVT__exp_p;
        vlSelfRef.__PVT__frac_y = vlSelfRef.__PVT__frac_p;
        vlSelfRef.__PVT__sign_y = vlSelfRef.__PVT__sign_p;
        vlSelfRef.__PVT__exp_mx = vlSelfRef.__PVT__exp_n;
        vlSelfRef.__PVT__frac_mx = vlSelfRef.__PVT__frac_n;
        vlSelfRef.__PVT__sign_mx = vlSelfRef.__PVT__sign_n;
        vlSelfRef.__PVT__exp_nx = vlSelfRef.__PVT__exp_m;
        vlSelfRef.__PVT__frac_nx = vlSelfRef.__PVT__frac_m;
        vlSelfRef.__PVT__sign_nx = vlSelfRef.__PVT__sign_m;
    }
    vlSelfRef.__PVT__exp_x_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_x))
                                   ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_x)));
    vlSelfRef.__PVT__exp_y_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_y))
                                   ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_y)));
    vlSelfRef.__PVT__exp_mx_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_mx))
                                    ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_mx)));
    vlSelfRef.__PVT__exp_nx_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_nx))
                                    ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_nx)));
    vlSelfRef.__PVT__y_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_y_eff)));
    vlSelfRef.__PVT__m_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_mx_eff)));
    vlSelfRef.__PVT__n_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_nx_eff)));
    vlSelfRef.__PVT__x_mant = (0x7ffffffffffffffULL 
                               & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                         (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_x))) 
                                                                           << 0x1aU) 
                                                                          | vlSelfRef.__PVT__frac_x))), 0x20U));
    vlSelfRef.__PVT__y_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_y))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_y))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__y_shift))) {
        vlSelfRef.__PVT__safe_y_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_y = (0U != vlSelfRef.__PVT__y_mant_base);
        vlSelfRef.__PVT__y_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_y_shift = (0x3fU & (IData)(vlSelfRef.__PVT__y_shift));
        vlSelfRef.__PVT__sticky_y = (0U != (vlSelfRef.__PVT__y_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_y_shift)))));
        vlSelfRef.__PVT__y_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__y_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_y_shift)));
    }
    vlSelfRef.__PVT__m_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_mx))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_mx))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__m_shift))) {
        vlSelfRef.__PVT__safe_m_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_m = (0U != vlSelfRef.__PVT__m_mant_base);
        vlSelfRef.__PVT__m_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_m_shift = (0x3fU & (IData)(vlSelfRef.__PVT__m_shift));
        vlSelfRef.__PVT__sticky_m = (0U != (vlSelfRef.__PVT__m_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_m_shift)))));
        vlSelfRef.__PVT__m_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__m_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_m_shift)));
    }
    vlSelfRef.__PVT__n_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_nx))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_nx))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__n_shift))) {
        vlSelfRef.__PVT__safe_n_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_n = (0U != vlSelfRef.__PVT__n_mant_base);
        vlSelfRef.__PVT__n_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_n_shift = (0x3fU & (IData)(vlSelfRef.__PVT__n_shift));
        vlSelfRef.__PVT__sticky_n = (0U != (vlSelfRef.__PVT__n_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_n_shift)))));
        vlSelfRef.__PVT__n_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__n_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_n_shift)));
    }
    vlSelfRef.__PVT__y_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_y));
    vlSelfRef.__PVT__m_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_mx));
    vlSelfRef.__PVT__n_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_nx));
    vlSelfRef.__PVT__op_x = vlSelfRef.__PVT__x_mant;
    vlSelfRef.__PVT__op_y = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__y_op)
                                 ? (~ vlSelfRef.__PVT__y_shifted)
                                 : vlSelfRef.__PVT__y_shifted));
    vlSelfRef.__PVT__op_m = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__m_op)
                                 ? (~ vlSelfRef.__PVT__m_shifted)
                                 : vlSelfRef.__PVT__m_shifted));
    vlSelfRef.__PVT__op_n = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__n_op)
                                 ? (~ vlSelfRef.__PVT__n_shifted)
                                 : vlSelfRef.__PVT__n_shifted));
    vlSelfRef.__PVT__csa_s1 = ((vlSelfRef.__PVT__op_x 
                                ^ vlSelfRef.__PVT__op_y) 
                               ^ vlSelfRef.__PVT__op_m);
    vlSelfRef.__PVT__csa_c1 = (((vlSelfRef.__PVT__op_x 
                                 & vlSelfRef.__PVT__op_y) 
                                | (vlSelfRef.__PVT__op_y 
                                   & vlSelfRef.__PVT__op_m)) 
                               | (vlSelfRef.__PVT__op_m 
                                  & vlSelfRef.__PVT__op_x));
    vlSelfRef.__PVT__csa_s2 = (0x7fffffffffffffffULL 
                               & ((vlSelfRef.__PVT__csa_s1 
                                   ^ VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U)) 
                                  ^ vlSelfRef.__PVT__op_n));
    vlSelfRef.__PVT__csa_c2 = (((vlSelfRef.__PVT__csa_s1 
                                 & VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U)) 
                                | (VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U) 
                                   & vlSelfRef.__PVT__op_n)) 
                               | (vlSelfRef.__PVT__op_n 
                                  & vlSelfRef.__PVT__csa_s1));
}

VL_INLINE_OPT void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__26__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__26__KET____DOT__stage_inst__1\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__26__KET__.out 
        = ((IData)(vlSymsp->TOP.adder_4input_tree32_tb__DOT__nrst)
            ? vlSelfRef.__PVT__result_out : 0ULL);
}

VL_INLINE_OPT void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__27__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__27__KET____DOT__stage_inst__0\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__safe_a = (QData)((IData)(vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__26__KET__.out));
    vlSelfRef.__PVT__safe_b = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x52U] 
                                               << 0x10U)));
    vlSelfRef.__PVT__safe_c = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x53U] 
                                               << 0x10U)));
    vlSelfRef.__PVT__safe_d = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x54U] 
                                               << 0x10U)));
    vlSelfRef.__PVT__a_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_a 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_a 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_a);
    vlSelfRef.__PVT__b_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_b 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_b 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_b);
    vlSelfRef.__PVT__c_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_c 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_c 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_c);
    vlSelfRef.__PVT__d_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_d 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_d 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_d);
    vlSelfRef.__PVT__sign_a = (1U & (IData)((vlSelfRef.__PVT__a_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_a = (0xffU & (IData)((vlSelfRef.__PVT__a_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_a = (0x3ffffffU & (IData)(vlSelfRef.__PVT__a_daz));
    vlSelfRef.__PVT__sign_b = (1U & (IData)((vlSelfRef.__PVT__b_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_b = (0xffU & (IData)((vlSelfRef.__PVT__b_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_b = (0x3ffffffU & (IData)(vlSelfRef.__PVT__b_daz));
    vlSelfRef.__PVT__sign_c = (1U & (IData)((vlSelfRef.__PVT__c_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_c = (0xffU & (IData)((vlSelfRef.__PVT__c_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_c = (0x3ffffffU & (IData)(vlSelfRef.__PVT__c_daz));
    vlSelfRef.__PVT__sign_d = (1U & (IData)((vlSelfRef.__PVT__d_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_d = (0xffU & (IData)((vlSelfRef.__PVT__d_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_d = (0x3ffffffU & (IData)(vlSelfRef.__PVT__d_daz));
    vlSelfRef.__PVT__is_nan_any = (((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                      & (0U != vlSelfRef.__PVT__frac_a)) 
                                     | ((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                        & (0U != vlSelfRef.__PVT__frac_b))) 
                                    | ((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                       & (0U != vlSelfRef.__PVT__frac_c))) 
                                   | ((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                      & (0U != vlSelfRef.__PVT__frac_d)));
    vlSelfRef.__PVT__any_pos_inf = ((((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                        & (~ (IData)(vlSelfRef.__PVT__sign_a))) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_a)))) 
                                      | (((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                          & (~ (IData)(vlSelfRef.__PVT__sign_b))) 
                                         & (~ (IData)(
                                                      (0U 
                                                       != vlSelfRef.__PVT__frac_b))))) 
                                     | (((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                         & (~ (IData)(vlSelfRef.__PVT__sign_c))) 
                                        & (~ (IData)(
                                                     (0U 
                                                      != vlSelfRef.__PVT__frac_c))))) 
                                    | (((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                        & (~ (IData)(vlSelfRef.__PVT__sign_d))) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_d)))));
    vlSelfRef.__PVT__any_neg_inf = ((((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                        & (IData)(vlSelfRef.__PVT__sign_a)) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_a)))) 
                                      | (((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                          & (IData)(vlSelfRef.__PVT__sign_b)) 
                                         & (~ (IData)(
                                                      (0U 
                                                       != vlSelfRef.__PVT__frac_b))))) 
                                     | (((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                         & (IData)(vlSelfRef.__PVT__sign_c)) 
                                        & (~ (IData)(
                                                     (0U 
                                                      != vlSelfRef.__PVT__frac_c))))) 
                                    | (((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                        & (IData)(vlSelfRef.__PVT__sign_d)) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_d)))));
    vlSelfRef.__PVT__special_case = 0U;
    vlSelfRef.__PVT__special_result = 0ULL;
    if (((IData)(vlSelfRef.__PVT__is_nan_any) | ((IData)(vlSelfRef.__PVT__any_pos_inf) 
                                                 & (IData)(vlSelfRef.__PVT__any_neg_inf)))) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x3fe000000ULL;
    } else if (vlSelfRef.__PVT__any_pos_inf) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x3fc000000ULL;
    } else if (vlSelfRef.__PVT__any_neg_inf) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x7fc000000ULL;
    }
    if (((IData)(vlSelfRef.__PVT__exp_a) >= (IData)(vlSelfRef.__PVT__exp_b))) {
        vlSelfRef.__PVT__exp_p = vlSelfRef.__PVT__exp_a;
        vlSelfRef.__PVT__frac_p = vlSelfRef.__PVT__frac_a;
        vlSelfRef.__PVT__sign_p = vlSelfRef.__PVT__sign_a;
        vlSelfRef.__PVT__exp_m = vlSelfRef.__PVT__exp_b;
        vlSelfRef.__PVT__frac_m = vlSelfRef.__PVT__frac_b;
        vlSelfRef.__PVT__sign_m = vlSelfRef.__PVT__sign_b;
    } else {
        vlSelfRef.__PVT__exp_p = vlSelfRef.__PVT__exp_b;
        vlSelfRef.__PVT__frac_p = vlSelfRef.__PVT__frac_b;
        vlSelfRef.__PVT__sign_p = vlSelfRef.__PVT__sign_b;
        vlSelfRef.__PVT__exp_m = vlSelfRef.__PVT__exp_a;
        vlSelfRef.__PVT__frac_m = vlSelfRef.__PVT__frac_a;
        vlSelfRef.__PVT__sign_m = vlSelfRef.__PVT__sign_a;
    }
    if (((IData)(vlSelfRef.__PVT__exp_c) >= (IData)(vlSelfRef.__PVT__exp_d))) {
        vlSelfRef.__PVT__exp_r = vlSelfRef.__PVT__exp_c;
        vlSelfRef.__PVT__frac_r = vlSelfRef.__PVT__frac_c;
        vlSelfRef.__PVT__sign_r = vlSelfRef.__PVT__sign_c;
        vlSelfRef.__PVT__exp_n = vlSelfRef.__PVT__exp_d;
        vlSelfRef.__PVT__frac_n = vlSelfRef.__PVT__frac_d;
        vlSelfRef.__PVT__sign_n = vlSelfRef.__PVT__sign_d;
    } else {
        vlSelfRef.__PVT__exp_r = vlSelfRef.__PVT__exp_d;
        vlSelfRef.__PVT__frac_r = vlSelfRef.__PVT__frac_d;
        vlSelfRef.__PVT__sign_r = vlSelfRef.__PVT__sign_d;
        vlSelfRef.__PVT__exp_n = vlSelfRef.__PVT__exp_c;
        vlSelfRef.__PVT__frac_n = vlSelfRef.__PVT__frac_c;
        vlSelfRef.__PVT__sign_n = vlSelfRef.__PVT__sign_c;
    }
    if (((IData)(vlSelfRef.__PVT__exp_p) >= (IData)(vlSelfRef.__PVT__exp_r))) {
        vlSelfRef.__PVT__exp_x = vlSelfRef.__PVT__exp_p;
        vlSelfRef.__PVT__frac_x = vlSelfRef.__PVT__frac_p;
        vlSelfRef.__PVT__sign_x = vlSelfRef.__PVT__sign_p;
        vlSelfRef.__PVT__exp_y = vlSelfRef.__PVT__exp_r;
        vlSelfRef.__PVT__frac_y = vlSelfRef.__PVT__frac_r;
        vlSelfRef.__PVT__sign_y = vlSelfRef.__PVT__sign_r;
        vlSelfRef.__PVT__exp_mx = vlSelfRef.__PVT__exp_m;
        vlSelfRef.__PVT__frac_mx = vlSelfRef.__PVT__frac_m;
        vlSelfRef.__PVT__sign_mx = vlSelfRef.__PVT__sign_m;
        vlSelfRef.__PVT__exp_nx = vlSelfRef.__PVT__exp_n;
        vlSelfRef.__PVT__frac_nx = vlSelfRef.__PVT__frac_n;
        vlSelfRef.__PVT__sign_nx = vlSelfRef.__PVT__sign_n;
    } else {
        vlSelfRef.__PVT__exp_x = vlSelfRef.__PVT__exp_r;
        vlSelfRef.__PVT__frac_x = vlSelfRef.__PVT__frac_r;
        vlSelfRef.__PVT__sign_x = vlSelfRef.__PVT__sign_r;
        vlSelfRef.__PVT__exp_y = vlSelfRef.__PVT__exp_p;
        vlSelfRef.__PVT__frac_y = vlSelfRef.__PVT__frac_p;
        vlSelfRef.__PVT__sign_y = vlSelfRef.__PVT__sign_p;
        vlSelfRef.__PVT__exp_mx = vlSelfRef.__PVT__exp_n;
        vlSelfRef.__PVT__frac_mx = vlSelfRef.__PVT__frac_n;
        vlSelfRef.__PVT__sign_mx = vlSelfRef.__PVT__sign_n;
        vlSelfRef.__PVT__exp_nx = vlSelfRef.__PVT__exp_m;
        vlSelfRef.__PVT__frac_nx = vlSelfRef.__PVT__frac_m;
        vlSelfRef.__PVT__sign_nx = vlSelfRef.__PVT__sign_m;
    }
    vlSelfRef.__PVT__exp_x_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_x))
                                   ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_x)));
    vlSelfRef.__PVT__exp_y_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_y))
                                   ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_y)));
    vlSelfRef.__PVT__exp_mx_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_mx))
                                    ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_mx)));
    vlSelfRef.__PVT__exp_nx_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_nx))
                                    ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_nx)));
    vlSelfRef.__PVT__y_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_y_eff)));
    vlSelfRef.__PVT__m_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_mx_eff)));
    vlSelfRef.__PVT__n_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_nx_eff)));
    vlSelfRef.__PVT__x_mant = (0x7ffffffffffffffULL 
                               & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                         (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_x))) 
                                                                           << 0x1aU) 
                                                                          | vlSelfRef.__PVT__frac_x))), 0x20U));
    vlSelfRef.__PVT__y_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_y))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_y))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__y_shift))) {
        vlSelfRef.__PVT__safe_y_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_y = (0U != vlSelfRef.__PVT__y_mant_base);
        vlSelfRef.__PVT__y_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_y_shift = (0x3fU & (IData)(vlSelfRef.__PVT__y_shift));
        vlSelfRef.__PVT__sticky_y = (0U != (vlSelfRef.__PVT__y_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_y_shift)))));
        vlSelfRef.__PVT__y_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__y_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_y_shift)));
    }
    vlSelfRef.__PVT__m_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_mx))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_mx))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__m_shift))) {
        vlSelfRef.__PVT__safe_m_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_m = (0U != vlSelfRef.__PVT__m_mant_base);
        vlSelfRef.__PVT__m_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_m_shift = (0x3fU & (IData)(vlSelfRef.__PVT__m_shift));
        vlSelfRef.__PVT__sticky_m = (0U != (vlSelfRef.__PVT__m_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_m_shift)))));
        vlSelfRef.__PVT__m_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__m_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_m_shift)));
    }
    vlSelfRef.__PVT__n_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_nx))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_nx))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__n_shift))) {
        vlSelfRef.__PVT__safe_n_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_n = (0U != vlSelfRef.__PVT__n_mant_base);
        vlSelfRef.__PVT__n_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_n_shift = (0x3fU & (IData)(vlSelfRef.__PVT__n_shift));
        vlSelfRef.__PVT__sticky_n = (0U != (vlSelfRef.__PVT__n_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_n_shift)))));
        vlSelfRef.__PVT__n_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__n_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_n_shift)));
    }
    vlSelfRef.__PVT__y_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_y));
    vlSelfRef.__PVT__m_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_mx));
    vlSelfRef.__PVT__n_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_nx));
    vlSelfRef.__PVT__op_x = vlSelfRef.__PVT__x_mant;
    vlSelfRef.__PVT__op_y = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__y_op)
                                 ? (~ vlSelfRef.__PVT__y_shifted)
                                 : vlSelfRef.__PVT__y_shifted));
    vlSelfRef.__PVT__op_m = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__m_op)
                                 ? (~ vlSelfRef.__PVT__m_shifted)
                                 : vlSelfRef.__PVT__m_shifted));
    vlSelfRef.__PVT__op_n = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__n_op)
                                 ? (~ vlSelfRef.__PVT__n_shifted)
                                 : vlSelfRef.__PVT__n_shifted));
    vlSelfRef.__PVT__csa_s1 = ((vlSelfRef.__PVT__op_x 
                                ^ vlSelfRef.__PVT__op_y) 
                               ^ vlSelfRef.__PVT__op_m);
    vlSelfRef.__PVT__csa_c1 = (((vlSelfRef.__PVT__op_x 
                                 & vlSelfRef.__PVT__op_y) 
                                | (vlSelfRef.__PVT__op_y 
                                   & vlSelfRef.__PVT__op_m)) 
                               | (vlSelfRef.__PVT__op_m 
                                  & vlSelfRef.__PVT__op_x));
    vlSelfRef.__PVT__csa_s2 = (0x7fffffffffffffffULL 
                               & ((vlSelfRef.__PVT__csa_s1 
                                   ^ VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U)) 
                                  ^ vlSelfRef.__PVT__op_n));
    vlSelfRef.__PVT__csa_c2 = (((vlSelfRef.__PVT__csa_s1 
                                 & VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U)) 
                                | (VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U) 
                                   & vlSelfRef.__PVT__op_n)) 
                               | (vlSelfRef.__PVT__op_n 
                                  & vlSelfRef.__PVT__csa_s1));
}

VL_INLINE_OPT void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__27__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__27__KET____DOT__stage_inst__1\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__27__KET__.out 
        = ((IData)(vlSymsp->TOP.adder_4input_tree32_tb__DOT__nrst)
            ? vlSelfRef.__PVT__result_out : 0ULL);
}

VL_INLINE_OPT void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__28__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__28__KET____DOT__stage_inst__0\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__safe_a = (QData)((IData)(vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__27__KET__.out));
    vlSelfRef.__PVT__safe_b = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x55U] 
                                               << 0x10U)));
    vlSelfRef.__PVT__safe_c = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x56U] 
                                               << 0x10U)));
    vlSelfRef.__PVT__safe_d = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x57U] 
                                               << 0x10U)));
    vlSelfRef.__PVT__a_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_a 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_a 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_a);
    vlSelfRef.__PVT__b_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_b 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_b 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_b);
    vlSelfRef.__PVT__c_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_c 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_c 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_c);
    vlSelfRef.__PVT__d_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_d 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_d 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_d);
    vlSelfRef.__PVT__sign_a = (1U & (IData)((vlSelfRef.__PVT__a_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_a = (0xffU & (IData)((vlSelfRef.__PVT__a_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_a = (0x3ffffffU & (IData)(vlSelfRef.__PVT__a_daz));
    vlSelfRef.__PVT__sign_b = (1U & (IData)((vlSelfRef.__PVT__b_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_b = (0xffU & (IData)((vlSelfRef.__PVT__b_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_b = (0x3ffffffU & (IData)(vlSelfRef.__PVT__b_daz));
    vlSelfRef.__PVT__sign_c = (1U & (IData)((vlSelfRef.__PVT__c_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_c = (0xffU & (IData)((vlSelfRef.__PVT__c_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_c = (0x3ffffffU & (IData)(vlSelfRef.__PVT__c_daz));
    vlSelfRef.__PVT__sign_d = (1U & (IData)((vlSelfRef.__PVT__d_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_d = (0xffU & (IData)((vlSelfRef.__PVT__d_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_d = (0x3ffffffU & (IData)(vlSelfRef.__PVT__d_daz));
    vlSelfRef.__PVT__is_nan_any = (((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                      & (0U != vlSelfRef.__PVT__frac_a)) 
                                     | ((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                        & (0U != vlSelfRef.__PVT__frac_b))) 
                                    | ((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                       & (0U != vlSelfRef.__PVT__frac_c))) 
                                   | ((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                      & (0U != vlSelfRef.__PVT__frac_d)));
    vlSelfRef.__PVT__any_pos_inf = ((((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                        & (~ (IData)(vlSelfRef.__PVT__sign_a))) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_a)))) 
                                      | (((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                          & (~ (IData)(vlSelfRef.__PVT__sign_b))) 
                                         & (~ (IData)(
                                                      (0U 
                                                       != vlSelfRef.__PVT__frac_b))))) 
                                     | (((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                         & (~ (IData)(vlSelfRef.__PVT__sign_c))) 
                                        & (~ (IData)(
                                                     (0U 
                                                      != vlSelfRef.__PVT__frac_c))))) 
                                    | (((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                        & (~ (IData)(vlSelfRef.__PVT__sign_d))) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_d)))));
    vlSelfRef.__PVT__any_neg_inf = ((((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                        & (IData)(vlSelfRef.__PVT__sign_a)) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_a)))) 
                                      | (((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                          & (IData)(vlSelfRef.__PVT__sign_b)) 
                                         & (~ (IData)(
                                                      (0U 
                                                       != vlSelfRef.__PVT__frac_b))))) 
                                     | (((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                         & (IData)(vlSelfRef.__PVT__sign_c)) 
                                        & (~ (IData)(
                                                     (0U 
                                                      != vlSelfRef.__PVT__frac_c))))) 
                                    | (((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                        & (IData)(vlSelfRef.__PVT__sign_d)) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_d)))));
    vlSelfRef.__PVT__special_case = 0U;
    vlSelfRef.__PVT__special_result = 0ULL;
    if (((IData)(vlSelfRef.__PVT__is_nan_any) | ((IData)(vlSelfRef.__PVT__any_pos_inf) 
                                                 & (IData)(vlSelfRef.__PVT__any_neg_inf)))) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x3fe000000ULL;
    } else if (vlSelfRef.__PVT__any_pos_inf) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x3fc000000ULL;
    } else if (vlSelfRef.__PVT__any_neg_inf) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x7fc000000ULL;
    }
    if (((IData)(vlSelfRef.__PVT__exp_a) >= (IData)(vlSelfRef.__PVT__exp_b))) {
        vlSelfRef.__PVT__exp_p = vlSelfRef.__PVT__exp_a;
        vlSelfRef.__PVT__frac_p = vlSelfRef.__PVT__frac_a;
        vlSelfRef.__PVT__sign_p = vlSelfRef.__PVT__sign_a;
        vlSelfRef.__PVT__exp_m = vlSelfRef.__PVT__exp_b;
        vlSelfRef.__PVT__frac_m = vlSelfRef.__PVT__frac_b;
        vlSelfRef.__PVT__sign_m = vlSelfRef.__PVT__sign_b;
    } else {
        vlSelfRef.__PVT__exp_p = vlSelfRef.__PVT__exp_b;
        vlSelfRef.__PVT__frac_p = vlSelfRef.__PVT__frac_b;
        vlSelfRef.__PVT__sign_p = vlSelfRef.__PVT__sign_b;
        vlSelfRef.__PVT__exp_m = vlSelfRef.__PVT__exp_a;
        vlSelfRef.__PVT__frac_m = vlSelfRef.__PVT__frac_a;
        vlSelfRef.__PVT__sign_m = vlSelfRef.__PVT__sign_a;
    }
    if (((IData)(vlSelfRef.__PVT__exp_c) >= (IData)(vlSelfRef.__PVT__exp_d))) {
        vlSelfRef.__PVT__exp_r = vlSelfRef.__PVT__exp_c;
        vlSelfRef.__PVT__frac_r = vlSelfRef.__PVT__frac_c;
        vlSelfRef.__PVT__sign_r = vlSelfRef.__PVT__sign_c;
        vlSelfRef.__PVT__exp_n = vlSelfRef.__PVT__exp_d;
        vlSelfRef.__PVT__frac_n = vlSelfRef.__PVT__frac_d;
        vlSelfRef.__PVT__sign_n = vlSelfRef.__PVT__sign_d;
    } else {
        vlSelfRef.__PVT__exp_r = vlSelfRef.__PVT__exp_d;
        vlSelfRef.__PVT__frac_r = vlSelfRef.__PVT__frac_d;
        vlSelfRef.__PVT__sign_r = vlSelfRef.__PVT__sign_d;
        vlSelfRef.__PVT__exp_n = vlSelfRef.__PVT__exp_c;
        vlSelfRef.__PVT__frac_n = vlSelfRef.__PVT__frac_c;
        vlSelfRef.__PVT__sign_n = vlSelfRef.__PVT__sign_c;
    }
    if (((IData)(vlSelfRef.__PVT__exp_p) >= (IData)(vlSelfRef.__PVT__exp_r))) {
        vlSelfRef.__PVT__exp_x = vlSelfRef.__PVT__exp_p;
        vlSelfRef.__PVT__frac_x = vlSelfRef.__PVT__frac_p;
        vlSelfRef.__PVT__sign_x = vlSelfRef.__PVT__sign_p;
        vlSelfRef.__PVT__exp_y = vlSelfRef.__PVT__exp_r;
        vlSelfRef.__PVT__frac_y = vlSelfRef.__PVT__frac_r;
        vlSelfRef.__PVT__sign_y = vlSelfRef.__PVT__sign_r;
        vlSelfRef.__PVT__exp_mx = vlSelfRef.__PVT__exp_m;
        vlSelfRef.__PVT__frac_mx = vlSelfRef.__PVT__frac_m;
        vlSelfRef.__PVT__sign_mx = vlSelfRef.__PVT__sign_m;
        vlSelfRef.__PVT__exp_nx = vlSelfRef.__PVT__exp_n;
        vlSelfRef.__PVT__frac_nx = vlSelfRef.__PVT__frac_n;
        vlSelfRef.__PVT__sign_nx = vlSelfRef.__PVT__sign_n;
    } else {
        vlSelfRef.__PVT__exp_x = vlSelfRef.__PVT__exp_r;
        vlSelfRef.__PVT__frac_x = vlSelfRef.__PVT__frac_r;
        vlSelfRef.__PVT__sign_x = vlSelfRef.__PVT__sign_r;
        vlSelfRef.__PVT__exp_y = vlSelfRef.__PVT__exp_p;
        vlSelfRef.__PVT__frac_y = vlSelfRef.__PVT__frac_p;
        vlSelfRef.__PVT__sign_y = vlSelfRef.__PVT__sign_p;
        vlSelfRef.__PVT__exp_mx = vlSelfRef.__PVT__exp_n;
        vlSelfRef.__PVT__frac_mx = vlSelfRef.__PVT__frac_n;
        vlSelfRef.__PVT__sign_mx = vlSelfRef.__PVT__sign_n;
        vlSelfRef.__PVT__exp_nx = vlSelfRef.__PVT__exp_m;
        vlSelfRef.__PVT__frac_nx = vlSelfRef.__PVT__frac_m;
        vlSelfRef.__PVT__sign_nx = vlSelfRef.__PVT__sign_m;
    }
    vlSelfRef.__PVT__exp_x_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_x))
                                   ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_x)));
    vlSelfRef.__PVT__exp_y_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_y))
                                   ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_y)));
    vlSelfRef.__PVT__exp_mx_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_mx))
                                    ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_mx)));
    vlSelfRef.__PVT__exp_nx_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_nx))
                                    ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_nx)));
    vlSelfRef.__PVT__y_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_y_eff)));
    vlSelfRef.__PVT__m_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_mx_eff)));
    vlSelfRef.__PVT__n_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_nx_eff)));
    vlSelfRef.__PVT__x_mant = (0x7ffffffffffffffULL 
                               & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                         (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_x))) 
                                                                           << 0x1aU) 
                                                                          | vlSelfRef.__PVT__frac_x))), 0x20U));
    vlSelfRef.__PVT__y_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_y))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_y))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__y_shift))) {
        vlSelfRef.__PVT__safe_y_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_y = (0U != vlSelfRef.__PVT__y_mant_base);
        vlSelfRef.__PVT__y_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_y_shift = (0x3fU & (IData)(vlSelfRef.__PVT__y_shift));
        vlSelfRef.__PVT__sticky_y = (0U != (vlSelfRef.__PVT__y_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_y_shift)))));
        vlSelfRef.__PVT__y_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__y_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_y_shift)));
    }
    vlSelfRef.__PVT__m_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_mx))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_mx))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__m_shift))) {
        vlSelfRef.__PVT__safe_m_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_m = (0U != vlSelfRef.__PVT__m_mant_base);
        vlSelfRef.__PVT__m_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_m_shift = (0x3fU & (IData)(vlSelfRef.__PVT__m_shift));
        vlSelfRef.__PVT__sticky_m = (0U != (vlSelfRef.__PVT__m_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_m_shift)))));
        vlSelfRef.__PVT__m_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__m_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_m_shift)));
    }
    vlSelfRef.__PVT__n_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_nx))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_nx))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__n_shift))) {
        vlSelfRef.__PVT__safe_n_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_n = (0U != vlSelfRef.__PVT__n_mant_base);
        vlSelfRef.__PVT__n_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_n_shift = (0x3fU & (IData)(vlSelfRef.__PVT__n_shift));
        vlSelfRef.__PVT__sticky_n = (0U != (vlSelfRef.__PVT__n_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_n_shift)))));
        vlSelfRef.__PVT__n_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__n_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_n_shift)));
    }
    vlSelfRef.__PVT__y_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_y));
    vlSelfRef.__PVT__m_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_mx));
    vlSelfRef.__PVT__n_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_nx));
    vlSelfRef.__PVT__op_x = vlSelfRef.__PVT__x_mant;
    vlSelfRef.__PVT__op_y = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__y_op)
                                 ? (~ vlSelfRef.__PVT__y_shifted)
                                 : vlSelfRef.__PVT__y_shifted));
    vlSelfRef.__PVT__op_m = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__m_op)
                                 ? (~ vlSelfRef.__PVT__m_shifted)
                                 : vlSelfRef.__PVT__m_shifted));
    vlSelfRef.__PVT__op_n = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__n_op)
                                 ? (~ vlSelfRef.__PVT__n_shifted)
                                 : vlSelfRef.__PVT__n_shifted));
    vlSelfRef.__PVT__csa_s1 = ((vlSelfRef.__PVT__op_x 
                                ^ vlSelfRef.__PVT__op_y) 
                               ^ vlSelfRef.__PVT__op_m);
    vlSelfRef.__PVT__csa_c1 = (((vlSelfRef.__PVT__op_x 
                                 & vlSelfRef.__PVT__op_y) 
                                | (vlSelfRef.__PVT__op_y 
                                   & vlSelfRef.__PVT__op_m)) 
                               | (vlSelfRef.__PVT__op_m 
                                  & vlSelfRef.__PVT__op_x));
    vlSelfRef.__PVT__csa_s2 = (0x7fffffffffffffffULL 
                               & ((vlSelfRef.__PVT__csa_s1 
                                   ^ VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U)) 
                                  ^ vlSelfRef.__PVT__op_n));
    vlSelfRef.__PVT__csa_c2 = (((vlSelfRef.__PVT__csa_s1 
                                 & VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U)) 
                                | (VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U) 
                                   & vlSelfRef.__PVT__op_n)) 
                               | (vlSelfRef.__PVT__op_n 
                                  & vlSelfRef.__PVT__csa_s1));
}

VL_INLINE_OPT void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__28__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__28__KET____DOT__stage_inst__1\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__28__KET__.out 
        = ((IData)(vlSymsp->TOP.adder_4input_tree32_tb__DOT__nrst)
            ? vlSelfRef.__PVT__result_out : 0ULL);
}

VL_INLINE_OPT void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__29__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__29__KET____DOT__stage_inst__0\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__safe_a = (QData)((IData)(vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__28__KET__.out));
    vlSelfRef.__PVT__safe_b = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x58U] 
                                               << 0x10U)));
    vlSelfRef.__PVT__safe_c = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x59U] 
                                               << 0x10U)));
    vlSelfRef.__PVT__safe_d = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x5aU] 
                                               << 0x10U)));
    vlSelfRef.__PVT__a_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_a 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_a 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_a);
    vlSelfRef.__PVT__b_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_b 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_b 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_b);
    vlSelfRef.__PVT__c_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_c 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_c 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_c);
    vlSelfRef.__PVT__d_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_d 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_d 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_d);
    vlSelfRef.__PVT__sign_a = (1U & (IData)((vlSelfRef.__PVT__a_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_a = (0xffU & (IData)((vlSelfRef.__PVT__a_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_a = (0x3ffffffU & (IData)(vlSelfRef.__PVT__a_daz));
    vlSelfRef.__PVT__sign_b = (1U & (IData)((vlSelfRef.__PVT__b_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_b = (0xffU & (IData)((vlSelfRef.__PVT__b_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_b = (0x3ffffffU & (IData)(vlSelfRef.__PVT__b_daz));
    vlSelfRef.__PVT__sign_c = (1U & (IData)((vlSelfRef.__PVT__c_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_c = (0xffU & (IData)((vlSelfRef.__PVT__c_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_c = (0x3ffffffU & (IData)(vlSelfRef.__PVT__c_daz));
    vlSelfRef.__PVT__sign_d = (1U & (IData)((vlSelfRef.__PVT__d_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_d = (0xffU & (IData)((vlSelfRef.__PVT__d_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_d = (0x3ffffffU & (IData)(vlSelfRef.__PVT__d_daz));
    vlSelfRef.__PVT__is_nan_any = (((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                      & (0U != vlSelfRef.__PVT__frac_a)) 
                                     | ((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                        & (0U != vlSelfRef.__PVT__frac_b))) 
                                    | ((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                       & (0U != vlSelfRef.__PVT__frac_c))) 
                                   | ((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                      & (0U != vlSelfRef.__PVT__frac_d)));
    vlSelfRef.__PVT__any_pos_inf = ((((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                        & (~ (IData)(vlSelfRef.__PVT__sign_a))) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_a)))) 
                                      | (((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                          & (~ (IData)(vlSelfRef.__PVT__sign_b))) 
                                         & (~ (IData)(
                                                      (0U 
                                                       != vlSelfRef.__PVT__frac_b))))) 
                                     | (((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                         & (~ (IData)(vlSelfRef.__PVT__sign_c))) 
                                        & (~ (IData)(
                                                     (0U 
                                                      != vlSelfRef.__PVT__frac_c))))) 
                                    | (((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                        & (~ (IData)(vlSelfRef.__PVT__sign_d))) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_d)))));
    vlSelfRef.__PVT__any_neg_inf = ((((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                        & (IData)(vlSelfRef.__PVT__sign_a)) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_a)))) 
                                      | (((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                          & (IData)(vlSelfRef.__PVT__sign_b)) 
                                         & (~ (IData)(
                                                      (0U 
                                                       != vlSelfRef.__PVT__frac_b))))) 
                                     | (((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                         & (IData)(vlSelfRef.__PVT__sign_c)) 
                                        & (~ (IData)(
                                                     (0U 
                                                      != vlSelfRef.__PVT__frac_c))))) 
                                    | (((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                        & (IData)(vlSelfRef.__PVT__sign_d)) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_d)))));
    vlSelfRef.__PVT__special_case = 0U;
    vlSelfRef.__PVT__special_result = 0ULL;
    if (((IData)(vlSelfRef.__PVT__is_nan_any) | ((IData)(vlSelfRef.__PVT__any_pos_inf) 
                                                 & (IData)(vlSelfRef.__PVT__any_neg_inf)))) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x3fe000000ULL;
    } else if (vlSelfRef.__PVT__any_pos_inf) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x3fc000000ULL;
    } else if (vlSelfRef.__PVT__any_neg_inf) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x7fc000000ULL;
    }
    if (((IData)(vlSelfRef.__PVT__exp_a) >= (IData)(vlSelfRef.__PVT__exp_b))) {
        vlSelfRef.__PVT__exp_p = vlSelfRef.__PVT__exp_a;
        vlSelfRef.__PVT__frac_p = vlSelfRef.__PVT__frac_a;
        vlSelfRef.__PVT__sign_p = vlSelfRef.__PVT__sign_a;
        vlSelfRef.__PVT__exp_m = vlSelfRef.__PVT__exp_b;
        vlSelfRef.__PVT__frac_m = vlSelfRef.__PVT__frac_b;
        vlSelfRef.__PVT__sign_m = vlSelfRef.__PVT__sign_b;
    } else {
        vlSelfRef.__PVT__exp_p = vlSelfRef.__PVT__exp_b;
        vlSelfRef.__PVT__frac_p = vlSelfRef.__PVT__frac_b;
        vlSelfRef.__PVT__sign_p = vlSelfRef.__PVT__sign_b;
        vlSelfRef.__PVT__exp_m = vlSelfRef.__PVT__exp_a;
        vlSelfRef.__PVT__frac_m = vlSelfRef.__PVT__frac_a;
        vlSelfRef.__PVT__sign_m = vlSelfRef.__PVT__sign_a;
    }
    if (((IData)(vlSelfRef.__PVT__exp_c) >= (IData)(vlSelfRef.__PVT__exp_d))) {
        vlSelfRef.__PVT__exp_r = vlSelfRef.__PVT__exp_c;
        vlSelfRef.__PVT__frac_r = vlSelfRef.__PVT__frac_c;
        vlSelfRef.__PVT__sign_r = vlSelfRef.__PVT__sign_c;
        vlSelfRef.__PVT__exp_n = vlSelfRef.__PVT__exp_d;
        vlSelfRef.__PVT__frac_n = vlSelfRef.__PVT__frac_d;
        vlSelfRef.__PVT__sign_n = vlSelfRef.__PVT__sign_d;
    } else {
        vlSelfRef.__PVT__exp_r = vlSelfRef.__PVT__exp_d;
        vlSelfRef.__PVT__frac_r = vlSelfRef.__PVT__frac_d;
        vlSelfRef.__PVT__sign_r = vlSelfRef.__PVT__sign_d;
        vlSelfRef.__PVT__exp_n = vlSelfRef.__PVT__exp_c;
        vlSelfRef.__PVT__frac_n = vlSelfRef.__PVT__frac_c;
        vlSelfRef.__PVT__sign_n = vlSelfRef.__PVT__sign_c;
    }
    if (((IData)(vlSelfRef.__PVT__exp_p) >= (IData)(vlSelfRef.__PVT__exp_r))) {
        vlSelfRef.__PVT__exp_x = vlSelfRef.__PVT__exp_p;
        vlSelfRef.__PVT__frac_x = vlSelfRef.__PVT__frac_p;
        vlSelfRef.__PVT__sign_x = vlSelfRef.__PVT__sign_p;
        vlSelfRef.__PVT__exp_y = vlSelfRef.__PVT__exp_r;
        vlSelfRef.__PVT__frac_y = vlSelfRef.__PVT__frac_r;
        vlSelfRef.__PVT__sign_y = vlSelfRef.__PVT__sign_r;
        vlSelfRef.__PVT__exp_mx = vlSelfRef.__PVT__exp_m;
        vlSelfRef.__PVT__frac_mx = vlSelfRef.__PVT__frac_m;
        vlSelfRef.__PVT__sign_mx = vlSelfRef.__PVT__sign_m;
        vlSelfRef.__PVT__exp_nx = vlSelfRef.__PVT__exp_n;
        vlSelfRef.__PVT__frac_nx = vlSelfRef.__PVT__frac_n;
        vlSelfRef.__PVT__sign_nx = vlSelfRef.__PVT__sign_n;
    } else {
        vlSelfRef.__PVT__exp_x = vlSelfRef.__PVT__exp_r;
        vlSelfRef.__PVT__frac_x = vlSelfRef.__PVT__frac_r;
        vlSelfRef.__PVT__sign_x = vlSelfRef.__PVT__sign_r;
        vlSelfRef.__PVT__exp_y = vlSelfRef.__PVT__exp_p;
        vlSelfRef.__PVT__frac_y = vlSelfRef.__PVT__frac_p;
        vlSelfRef.__PVT__sign_y = vlSelfRef.__PVT__sign_p;
        vlSelfRef.__PVT__exp_mx = vlSelfRef.__PVT__exp_n;
        vlSelfRef.__PVT__frac_mx = vlSelfRef.__PVT__frac_n;
        vlSelfRef.__PVT__sign_mx = vlSelfRef.__PVT__sign_n;
        vlSelfRef.__PVT__exp_nx = vlSelfRef.__PVT__exp_m;
        vlSelfRef.__PVT__frac_nx = vlSelfRef.__PVT__frac_m;
        vlSelfRef.__PVT__sign_nx = vlSelfRef.__PVT__sign_m;
    }
    vlSelfRef.__PVT__exp_x_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_x))
                                   ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_x)));
    vlSelfRef.__PVT__exp_y_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_y))
                                   ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_y)));
    vlSelfRef.__PVT__exp_mx_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_mx))
                                    ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_mx)));
    vlSelfRef.__PVT__exp_nx_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_nx))
                                    ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_nx)));
    vlSelfRef.__PVT__y_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_y_eff)));
    vlSelfRef.__PVT__m_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_mx_eff)));
    vlSelfRef.__PVT__n_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_nx_eff)));
    vlSelfRef.__PVT__x_mant = (0x7ffffffffffffffULL 
                               & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                         (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_x))) 
                                                                           << 0x1aU) 
                                                                          | vlSelfRef.__PVT__frac_x))), 0x20U));
    vlSelfRef.__PVT__y_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_y))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_y))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__y_shift))) {
        vlSelfRef.__PVT__safe_y_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_y = (0U != vlSelfRef.__PVT__y_mant_base);
        vlSelfRef.__PVT__y_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_y_shift = (0x3fU & (IData)(vlSelfRef.__PVT__y_shift));
        vlSelfRef.__PVT__sticky_y = (0U != (vlSelfRef.__PVT__y_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_y_shift)))));
        vlSelfRef.__PVT__y_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__y_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_y_shift)));
    }
    vlSelfRef.__PVT__m_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_mx))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_mx))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__m_shift))) {
        vlSelfRef.__PVT__safe_m_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_m = (0U != vlSelfRef.__PVT__m_mant_base);
        vlSelfRef.__PVT__m_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_m_shift = (0x3fU & (IData)(vlSelfRef.__PVT__m_shift));
        vlSelfRef.__PVT__sticky_m = (0U != (vlSelfRef.__PVT__m_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_m_shift)))));
        vlSelfRef.__PVT__m_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__m_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_m_shift)));
    }
    vlSelfRef.__PVT__n_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_nx))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_nx))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__n_shift))) {
        vlSelfRef.__PVT__safe_n_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_n = (0U != vlSelfRef.__PVT__n_mant_base);
        vlSelfRef.__PVT__n_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_n_shift = (0x3fU & (IData)(vlSelfRef.__PVT__n_shift));
        vlSelfRef.__PVT__sticky_n = (0U != (vlSelfRef.__PVT__n_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_n_shift)))));
        vlSelfRef.__PVT__n_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__n_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_n_shift)));
    }
    vlSelfRef.__PVT__y_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_y));
    vlSelfRef.__PVT__m_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_mx));
    vlSelfRef.__PVT__n_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_nx));
    vlSelfRef.__PVT__op_x = vlSelfRef.__PVT__x_mant;
    vlSelfRef.__PVT__op_y = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__y_op)
                                 ? (~ vlSelfRef.__PVT__y_shifted)
                                 : vlSelfRef.__PVT__y_shifted));
    vlSelfRef.__PVT__op_m = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__m_op)
                                 ? (~ vlSelfRef.__PVT__m_shifted)
                                 : vlSelfRef.__PVT__m_shifted));
    vlSelfRef.__PVT__op_n = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__n_op)
                                 ? (~ vlSelfRef.__PVT__n_shifted)
                                 : vlSelfRef.__PVT__n_shifted));
    vlSelfRef.__PVT__csa_s1 = ((vlSelfRef.__PVT__op_x 
                                ^ vlSelfRef.__PVT__op_y) 
                               ^ vlSelfRef.__PVT__op_m);
    vlSelfRef.__PVT__csa_c1 = (((vlSelfRef.__PVT__op_x 
                                 & vlSelfRef.__PVT__op_y) 
                                | (vlSelfRef.__PVT__op_y 
                                   & vlSelfRef.__PVT__op_m)) 
                               | (vlSelfRef.__PVT__op_m 
                                  & vlSelfRef.__PVT__op_x));
    vlSelfRef.__PVT__csa_s2 = (0x7fffffffffffffffULL 
                               & ((vlSelfRef.__PVT__csa_s1 
                                   ^ VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U)) 
                                  ^ vlSelfRef.__PVT__op_n));
    vlSelfRef.__PVT__csa_c2 = (((vlSelfRef.__PVT__csa_s1 
                                 & VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U)) 
                                | (VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U) 
                                   & vlSelfRef.__PVT__op_n)) 
                               | (vlSelfRef.__PVT__op_n 
                                  & vlSelfRef.__PVT__csa_s1));
}

VL_INLINE_OPT void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__29__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__29__KET____DOT__stage_inst__1\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__29__KET__.out 
        = ((IData)(vlSymsp->TOP.adder_4input_tree32_tb__DOT__nrst)
            ? vlSelfRef.__PVT__result_out : 0ULL);
}

VL_INLINE_OPT void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__30__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__30__KET____DOT__stage_inst__0\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__safe_a = (QData)((IData)(vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__29__KET__.out));
    vlSelfRef.__PVT__safe_b = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x5bU] 
                                               << 0x10U)));
    vlSelfRef.__PVT__safe_c = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x5cU] 
                                               << 0x10U)));
    vlSelfRef.__PVT__safe_d = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x5dU] 
                                               << 0x10U)));
    vlSelfRef.__PVT__a_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_a 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_a 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_a);
    vlSelfRef.__PVT__b_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_b 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_b 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_b);
    vlSelfRef.__PVT__c_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_c 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_c 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_c);
    vlSelfRef.__PVT__d_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_d 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_d 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_d);
    vlSelfRef.__PVT__sign_a = (1U & (IData)((vlSelfRef.__PVT__a_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_a = (0xffU & (IData)((vlSelfRef.__PVT__a_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_a = (0x3ffffffU & (IData)(vlSelfRef.__PVT__a_daz));
    vlSelfRef.__PVT__sign_b = (1U & (IData)((vlSelfRef.__PVT__b_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_b = (0xffU & (IData)((vlSelfRef.__PVT__b_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_b = (0x3ffffffU & (IData)(vlSelfRef.__PVT__b_daz));
    vlSelfRef.__PVT__sign_c = (1U & (IData)((vlSelfRef.__PVT__c_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_c = (0xffU & (IData)((vlSelfRef.__PVT__c_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_c = (0x3ffffffU & (IData)(vlSelfRef.__PVT__c_daz));
    vlSelfRef.__PVT__sign_d = (1U & (IData)((vlSelfRef.__PVT__d_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_d = (0xffU & (IData)((vlSelfRef.__PVT__d_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_d = (0x3ffffffU & (IData)(vlSelfRef.__PVT__d_daz));
    vlSelfRef.__PVT__is_nan_any = (((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                      & (0U != vlSelfRef.__PVT__frac_a)) 
                                     | ((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                        & (0U != vlSelfRef.__PVT__frac_b))) 
                                    | ((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                       & (0U != vlSelfRef.__PVT__frac_c))) 
                                   | ((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                      & (0U != vlSelfRef.__PVT__frac_d)));
    vlSelfRef.__PVT__any_pos_inf = ((((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                        & (~ (IData)(vlSelfRef.__PVT__sign_a))) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_a)))) 
                                      | (((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                          & (~ (IData)(vlSelfRef.__PVT__sign_b))) 
                                         & (~ (IData)(
                                                      (0U 
                                                       != vlSelfRef.__PVT__frac_b))))) 
                                     | (((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                         & (~ (IData)(vlSelfRef.__PVT__sign_c))) 
                                        & (~ (IData)(
                                                     (0U 
                                                      != vlSelfRef.__PVT__frac_c))))) 
                                    | (((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                        & (~ (IData)(vlSelfRef.__PVT__sign_d))) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_d)))));
    vlSelfRef.__PVT__any_neg_inf = ((((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                        & (IData)(vlSelfRef.__PVT__sign_a)) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_a)))) 
                                      | (((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                          & (IData)(vlSelfRef.__PVT__sign_b)) 
                                         & (~ (IData)(
                                                      (0U 
                                                       != vlSelfRef.__PVT__frac_b))))) 
                                     | (((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                         & (IData)(vlSelfRef.__PVT__sign_c)) 
                                        & (~ (IData)(
                                                     (0U 
                                                      != vlSelfRef.__PVT__frac_c))))) 
                                    | (((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                        & (IData)(vlSelfRef.__PVT__sign_d)) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_d)))));
    vlSelfRef.__PVT__special_case = 0U;
    vlSelfRef.__PVT__special_result = 0ULL;
    if (((IData)(vlSelfRef.__PVT__is_nan_any) | ((IData)(vlSelfRef.__PVT__any_pos_inf) 
                                                 & (IData)(vlSelfRef.__PVT__any_neg_inf)))) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x3fe000000ULL;
    } else if (vlSelfRef.__PVT__any_pos_inf) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x3fc000000ULL;
    } else if (vlSelfRef.__PVT__any_neg_inf) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x7fc000000ULL;
    }
    if (((IData)(vlSelfRef.__PVT__exp_a) >= (IData)(vlSelfRef.__PVT__exp_b))) {
        vlSelfRef.__PVT__exp_p = vlSelfRef.__PVT__exp_a;
        vlSelfRef.__PVT__frac_p = vlSelfRef.__PVT__frac_a;
        vlSelfRef.__PVT__sign_p = vlSelfRef.__PVT__sign_a;
        vlSelfRef.__PVT__exp_m = vlSelfRef.__PVT__exp_b;
        vlSelfRef.__PVT__frac_m = vlSelfRef.__PVT__frac_b;
        vlSelfRef.__PVT__sign_m = vlSelfRef.__PVT__sign_b;
    } else {
        vlSelfRef.__PVT__exp_p = vlSelfRef.__PVT__exp_b;
        vlSelfRef.__PVT__frac_p = vlSelfRef.__PVT__frac_b;
        vlSelfRef.__PVT__sign_p = vlSelfRef.__PVT__sign_b;
        vlSelfRef.__PVT__exp_m = vlSelfRef.__PVT__exp_a;
        vlSelfRef.__PVT__frac_m = vlSelfRef.__PVT__frac_a;
        vlSelfRef.__PVT__sign_m = vlSelfRef.__PVT__sign_a;
    }
    if (((IData)(vlSelfRef.__PVT__exp_c) >= (IData)(vlSelfRef.__PVT__exp_d))) {
        vlSelfRef.__PVT__exp_r = vlSelfRef.__PVT__exp_c;
        vlSelfRef.__PVT__frac_r = vlSelfRef.__PVT__frac_c;
        vlSelfRef.__PVT__sign_r = vlSelfRef.__PVT__sign_c;
        vlSelfRef.__PVT__exp_n = vlSelfRef.__PVT__exp_d;
        vlSelfRef.__PVT__frac_n = vlSelfRef.__PVT__frac_d;
        vlSelfRef.__PVT__sign_n = vlSelfRef.__PVT__sign_d;
    } else {
        vlSelfRef.__PVT__exp_r = vlSelfRef.__PVT__exp_d;
        vlSelfRef.__PVT__frac_r = vlSelfRef.__PVT__frac_d;
        vlSelfRef.__PVT__sign_r = vlSelfRef.__PVT__sign_d;
        vlSelfRef.__PVT__exp_n = vlSelfRef.__PVT__exp_c;
        vlSelfRef.__PVT__frac_n = vlSelfRef.__PVT__frac_c;
        vlSelfRef.__PVT__sign_n = vlSelfRef.__PVT__sign_c;
    }
    if (((IData)(vlSelfRef.__PVT__exp_p) >= (IData)(vlSelfRef.__PVT__exp_r))) {
        vlSelfRef.__PVT__exp_x = vlSelfRef.__PVT__exp_p;
        vlSelfRef.__PVT__frac_x = vlSelfRef.__PVT__frac_p;
        vlSelfRef.__PVT__sign_x = vlSelfRef.__PVT__sign_p;
        vlSelfRef.__PVT__exp_y = vlSelfRef.__PVT__exp_r;
        vlSelfRef.__PVT__frac_y = vlSelfRef.__PVT__frac_r;
        vlSelfRef.__PVT__sign_y = vlSelfRef.__PVT__sign_r;
        vlSelfRef.__PVT__exp_mx = vlSelfRef.__PVT__exp_m;
        vlSelfRef.__PVT__frac_mx = vlSelfRef.__PVT__frac_m;
        vlSelfRef.__PVT__sign_mx = vlSelfRef.__PVT__sign_m;
        vlSelfRef.__PVT__exp_nx = vlSelfRef.__PVT__exp_n;
        vlSelfRef.__PVT__frac_nx = vlSelfRef.__PVT__frac_n;
        vlSelfRef.__PVT__sign_nx = vlSelfRef.__PVT__sign_n;
    } else {
        vlSelfRef.__PVT__exp_x = vlSelfRef.__PVT__exp_r;
        vlSelfRef.__PVT__frac_x = vlSelfRef.__PVT__frac_r;
        vlSelfRef.__PVT__sign_x = vlSelfRef.__PVT__sign_r;
        vlSelfRef.__PVT__exp_y = vlSelfRef.__PVT__exp_p;
        vlSelfRef.__PVT__frac_y = vlSelfRef.__PVT__frac_p;
        vlSelfRef.__PVT__sign_y = vlSelfRef.__PVT__sign_p;
        vlSelfRef.__PVT__exp_mx = vlSelfRef.__PVT__exp_n;
        vlSelfRef.__PVT__frac_mx = vlSelfRef.__PVT__frac_n;
        vlSelfRef.__PVT__sign_mx = vlSelfRef.__PVT__sign_n;
        vlSelfRef.__PVT__exp_nx = vlSelfRef.__PVT__exp_m;
        vlSelfRef.__PVT__frac_nx = vlSelfRef.__PVT__frac_m;
        vlSelfRef.__PVT__sign_nx = vlSelfRef.__PVT__sign_m;
    }
    vlSelfRef.__PVT__exp_x_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_x))
                                   ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_x)));
    vlSelfRef.__PVT__exp_y_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_y))
                                   ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_y)));
    vlSelfRef.__PVT__exp_mx_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_mx))
                                    ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_mx)));
    vlSelfRef.__PVT__exp_nx_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_nx))
                                    ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_nx)));
    vlSelfRef.__PVT__y_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_y_eff)));
    vlSelfRef.__PVT__m_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_mx_eff)));
    vlSelfRef.__PVT__n_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_nx_eff)));
    vlSelfRef.__PVT__x_mant = (0x7ffffffffffffffULL 
                               & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                         (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_x))) 
                                                                           << 0x1aU) 
                                                                          | vlSelfRef.__PVT__frac_x))), 0x20U));
    vlSelfRef.__PVT__y_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_y))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_y))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__y_shift))) {
        vlSelfRef.__PVT__safe_y_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_y = (0U != vlSelfRef.__PVT__y_mant_base);
        vlSelfRef.__PVT__y_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_y_shift = (0x3fU & (IData)(vlSelfRef.__PVT__y_shift));
        vlSelfRef.__PVT__sticky_y = (0U != (vlSelfRef.__PVT__y_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_y_shift)))));
        vlSelfRef.__PVT__y_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__y_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_y_shift)));
    }
    vlSelfRef.__PVT__m_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_mx))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_mx))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__m_shift))) {
        vlSelfRef.__PVT__safe_m_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_m = (0U != vlSelfRef.__PVT__m_mant_base);
        vlSelfRef.__PVT__m_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_m_shift = (0x3fU & (IData)(vlSelfRef.__PVT__m_shift));
        vlSelfRef.__PVT__sticky_m = (0U != (vlSelfRef.__PVT__m_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_m_shift)))));
        vlSelfRef.__PVT__m_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__m_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_m_shift)));
    }
    vlSelfRef.__PVT__n_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_nx))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_nx))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__n_shift))) {
        vlSelfRef.__PVT__safe_n_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_n = (0U != vlSelfRef.__PVT__n_mant_base);
        vlSelfRef.__PVT__n_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_n_shift = (0x3fU & (IData)(vlSelfRef.__PVT__n_shift));
        vlSelfRef.__PVT__sticky_n = (0U != (vlSelfRef.__PVT__n_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_n_shift)))));
        vlSelfRef.__PVT__n_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__n_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_n_shift)));
    }
    vlSelfRef.__PVT__y_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_y));
    vlSelfRef.__PVT__m_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_mx));
    vlSelfRef.__PVT__n_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_nx));
    vlSelfRef.__PVT__op_x = vlSelfRef.__PVT__x_mant;
    vlSelfRef.__PVT__op_y = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__y_op)
                                 ? (~ vlSelfRef.__PVT__y_shifted)
                                 : vlSelfRef.__PVT__y_shifted));
    vlSelfRef.__PVT__op_m = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__m_op)
                                 ? (~ vlSelfRef.__PVT__m_shifted)
                                 : vlSelfRef.__PVT__m_shifted));
    vlSelfRef.__PVT__op_n = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__n_op)
                                 ? (~ vlSelfRef.__PVT__n_shifted)
                                 : vlSelfRef.__PVT__n_shifted));
    vlSelfRef.__PVT__csa_s1 = ((vlSelfRef.__PVT__op_x 
                                ^ vlSelfRef.__PVT__op_y) 
                               ^ vlSelfRef.__PVT__op_m);
    vlSelfRef.__PVT__csa_c1 = (((vlSelfRef.__PVT__op_x 
                                 & vlSelfRef.__PVT__op_y) 
                                | (vlSelfRef.__PVT__op_y 
                                   & vlSelfRef.__PVT__op_m)) 
                               | (vlSelfRef.__PVT__op_m 
                                  & vlSelfRef.__PVT__op_x));
    vlSelfRef.__PVT__csa_s2 = (0x7fffffffffffffffULL 
                               & ((vlSelfRef.__PVT__csa_s1 
                                   ^ VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U)) 
                                  ^ vlSelfRef.__PVT__op_n));
    vlSelfRef.__PVT__csa_c2 = (((vlSelfRef.__PVT__csa_s1 
                                 & VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U)) 
                                | (VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U) 
                                   & vlSelfRef.__PVT__op_n)) 
                               | (vlSelfRef.__PVT__op_n 
                                  & vlSelfRef.__PVT__csa_s1));
}

VL_INLINE_OPT void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__30__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__30__KET____DOT__stage_inst__1\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__30__KET__.out 
        = ((IData)(vlSymsp->TOP.adder_4input_tree32_tb__DOT__nrst)
            ? vlSelfRef.__PVT__result_out : 0ULL);
}

VL_INLINE_OPT void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__31__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__31__KET____DOT__stage_inst__0\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__safe_a = (QData)((IData)(vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__30__KET__.out));
    vlSelfRef.__PVT__safe_b = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x5eU] 
                                               << 0x10U)));
    vlSelfRef.__PVT__safe_c = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x5fU] 
                                               << 0x10U)));
    vlSelfRef.__PVT__safe_d = (QData)((IData)((vlSymsp->TOP.adder_4input_tree32_tb__DOT__inputs
                                               [0x60U] 
                                               << 0x10U)));
    vlSelfRef.__PVT__a_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_a 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_a 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_a);
    vlSelfRef.__PVT__b_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_b 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_b 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_b);
    vlSelfRef.__PVT__c_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_c 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_c 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_c);
    vlSelfRef.__PVT__d_daz = ((0U == (0xffU & (IData)(
                                                      (vlSelfRef.__PVT__safe_d 
                                                       >> 0x1aU))))
                               ? ((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelfRef.__PVT__safe_d 
                                                              >> 0x22U))))) 
                                  << 0x22U) : vlSelfRef.__PVT__safe_d);
    vlSelfRef.__PVT__sign_a = (1U & (IData)((vlSelfRef.__PVT__a_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_a = (0xffU & (IData)((vlSelfRef.__PVT__a_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_a = (0x3ffffffU & (IData)(vlSelfRef.__PVT__a_daz));
    vlSelfRef.__PVT__sign_b = (1U & (IData)((vlSelfRef.__PVT__b_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_b = (0xffU & (IData)((vlSelfRef.__PVT__b_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_b = (0x3ffffffU & (IData)(vlSelfRef.__PVT__b_daz));
    vlSelfRef.__PVT__sign_c = (1U & (IData)((vlSelfRef.__PVT__c_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_c = (0xffU & (IData)((vlSelfRef.__PVT__c_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_c = (0x3ffffffU & (IData)(vlSelfRef.__PVT__c_daz));
    vlSelfRef.__PVT__sign_d = (1U & (IData)((vlSelfRef.__PVT__d_daz 
                                             >> 0x22U)));
    vlSelfRef.__PVT__exp_d = (0xffU & (IData)((vlSelfRef.__PVT__d_daz 
                                               >> 0x1aU)));
    vlSelfRef.__PVT__frac_d = (0x3ffffffU & (IData)(vlSelfRef.__PVT__d_daz));
    vlSelfRef.__PVT__is_nan_any = (((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                      & (0U != vlSelfRef.__PVT__frac_a)) 
                                     | ((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                        & (0U != vlSelfRef.__PVT__frac_b))) 
                                    | ((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                       & (0U != vlSelfRef.__PVT__frac_c))) 
                                   | ((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                      & (0U != vlSelfRef.__PVT__frac_d)));
    vlSelfRef.__PVT__any_pos_inf = ((((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                        & (~ (IData)(vlSelfRef.__PVT__sign_a))) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_a)))) 
                                      | (((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                          & (~ (IData)(vlSelfRef.__PVT__sign_b))) 
                                         & (~ (IData)(
                                                      (0U 
                                                       != vlSelfRef.__PVT__frac_b))))) 
                                     | (((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                         & (~ (IData)(vlSelfRef.__PVT__sign_c))) 
                                        & (~ (IData)(
                                                     (0U 
                                                      != vlSelfRef.__PVT__frac_c))))) 
                                    | (((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                        & (~ (IData)(vlSelfRef.__PVT__sign_d))) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_d)))));
    vlSelfRef.__PVT__any_neg_inf = ((((((0xffU == (IData)(vlSelfRef.__PVT__exp_a)) 
                                        & (IData)(vlSelfRef.__PVT__sign_a)) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_a)))) 
                                      | (((0xffU == (IData)(vlSelfRef.__PVT__exp_b)) 
                                          & (IData)(vlSelfRef.__PVT__sign_b)) 
                                         & (~ (IData)(
                                                      (0U 
                                                       != vlSelfRef.__PVT__frac_b))))) 
                                     | (((0xffU == (IData)(vlSelfRef.__PVT__exp_c)) 
                                         & (IData)(vlSelfRef.__PVT__sign_c)) 
                                        & (~ (IData)(
                                                     (0U 
                                                      != vlSelfRef.__PVT__frac_c))))) 
                                    | (((0xffU == (IData)(vlSelfRef.__PVT__exp_d)) 
                                        & (IData)(vlSelfRef.__PVT__sign_d)) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlSelfRef.__PVT__frac_d)))));
    vlSelfRef.__PVT__special_case = 0U;
    vlSelfRef.__PVT__special_result = 0ULL;
    if (((IData)(vlSelfRef.__PVT__is_nan_any) | ((IData)(vlSelfRef.__PVT__any_pos_inf) 
                                                 & (IData)(vlSelfRef.__PVT__any_neg_inf)))) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x3fe000000ULL;
    } else if (vlSelfRef.__PVT__any_pos_inf) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x3fc000000ULL;
    } else if (vlSelfRef.__PVT__any_neg_inf) {
        vlSelfRef.__PVT__special_case = 1U;
        vlSelfRef.__PVT__special_result = 0x7fc000000ULL;
    }
    if (((IData)(vlSelfRef.__PVT__exp_a) >= (IData)(vlSelfRef.__PVT__exp_b))) {
        vlSelfRef.__PVT__exp_p = vlSelfRef.__PVT__exp_a;
        vlSelfRef.__PVT__frac_p = vlSelfRef.__PVT__frac_a;
        vlSelfRef.__PVT__sign_p = vlSelfRef.__PVT__sign_a;
        vlSelfRef.__PVT__exp_m = vlSelfRef.__PVT__exp_b;
        vlSelfRef.__PVT__frac_m = vlSelfRef.__PVT__frac_b;
        vlSelfRef.__PVT__sign_m = vlSelfRef.__PVT__sign_b;
    } else {
        vlSelfRef.__PVT__exp_p = vlSelfRef.__PVT__exp_b;
        vlSelfRef.__PVT__frac_p = vlSelfRef.__PVT__frac_b;
        vlSelfRef.__PVT__sign_p = vlSelfRef.__PVT__sign_b;
        vlSelfRef.__PVT__exp_m = vlSelfRef.__PVT__exp_a;
        vlSelfRef.__PVT__frac_m = vlSelfRef.__PVT__frac_a;
        vlSelfRef.__PVT__sign_m = vlSelfRef.__PVT__sign_a;
    }
    if (((IData)(vlSelfRef.__PVT__exp_c) >= (IData)(vlSelfRef.__PVT__exp_d))) {
        vlSelfRef.__PVT__exp_r = vlSelfRef.__PVT__exp_c;
        vlSelfRef.__PVT__frac_r = vlSelfRef.__PVT__frac_c;
        vlSelfRef.__PVT__sign_r = vlSelfRef.__PVT__sign_c;
        vlSelfRef.__PVT__exp_n = vlSelfRef.__PVT__exp_d;
        vlSelfRef.__PVT__frac_n = vlSelfRef.__PVT__frac_d;
        vlSelfRef.__PVT__sign_n = vlSelfRef.__PVT__sign_d;
    } else {
        vlSelfRef.__PVT__exp_r = vlSelfRef.__PVT__exp_d;
        vlSelfRef.__PVT__frac_r = vlSelfRef.__PVT__frac_d;
        vlSelfRef.__PVT__sign_r = vlSelfRef.__PVT__sign_d;
        vlSelfRef.__PVT__exp_n = vlSelfRef.__PVT__exp_c;
        vlSelfRef.__PVT__frac_n = vlSelfRef.__PVT__frac_c;
        vlSelfRef.__PVT__sign_n = vlSelfRef.__PVT__sign_c;
    }
    if (((IData)(vlSelfRef.__PVT__exp_p) >= (IData)(vlSelfRef.__PVT__exp_r))) {
        vlSelfRef.__PVT__exp_x = vlSelfRef.__PVT__exp_p;
        vlSelfRef.__PVT__frac_x = vlSelfRef.__PVT__frac_p;
        vlSelfRef.__PVT__sign_x = vlSelfRef.__PVT__sign_p;
        vlSelfRef.__PVT__exp_y = vlSelfRef.__PVT__exp_r;
        vlSelfRef.__PVT__frac_y = vlSelfRef.__PVT__frac_r;
        vlSelfRef.__PVT__sign_y = vlSelfRef.__PVT__sign_r;
        vlSelfRef.__PVT__exp_mx = vlSelfRef.__PVT__exp_m;
        vlSelfRef.__PVT__frac_mx = vlSelfRef.__PVT__frac_m;
        vlSelfRef.__PVT__sign_mx = vlSelfRef.__PVT__sign_m;
        vlSelfRef.__PVT__exp_nx = vlSelfRef.__PVT__exp_n;
        vlSelfRef.__PVT__frac_nx = vlSelfRef.__PVT__frac_n;
        vlSelfRef.__PVT__sign_nx = vlSelfRef.__PVT__sign_n;
    } else {
        vlSelfRef.__PVT__exp_x = vlSelfRef.__PVT__exp_r;
        vlSelfRef.__PVT__frac_x = vlSelfRef.__PVT__frac_r;
        vlSelfRef.__PVT__sign_x = vlSelfRef.__PVT__sign_r;
        vlSelfRef.__PVT__exp_y = vlSelfRef.__PVT__exp_p;
        vlSelfRef.__PVT__frac_y = vlSelfRef.__PVT__frac_p;
        vlSelfRef.__PVT__sign_y = vlSelfRef.__PVT__sign_p;
        vlSelfRef.__PVT__exp_mx = vlSelfRef.__PVT__exp_n;
        vlSelfRef.__PVT__frac_mx = vlSelfRef.__PVT__frac_n;
        vlSelfRef.__PVT__sign_mx = vlSelfRef.__PVT__sign_n;
        vlSelfRef.__PVT__exp_nx = vlSelfRef.__PVT__exp_m;
        vlSelfRef.__PVT__frac_nx = vlSelfRef.__PVT__frac_m;
        vlSelfRef.__PVT__sign_nx = vlSelfRef.__PVT__sign_m;
    }
    vlSelfRef.__PVT__exp_x_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_x))
                                   ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_x)));
    vlSelfRef.__PVT__exp_y_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_y))
                                   ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_y)));
    vlSelfRef.__PVT__exp_mx_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_mx))
                                    ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_mx)));
    vlSelfRef.__PVT__exp_nx_eff = ((0U == (IData)(vlSelfRef.__PVT__exp_nx))
                                    ? 1U : (0xffU & (IData)(vlSelfRef.__PVT__exp_nx)));
    vlSelfRef.__PVT__y_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_y_eff)));
    vlSelfRef.__PVT__m_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_mx_eff)));
    vlSelfRef.__PVT__n_shift = (0x1ffU & ((IData)(vlSelfRef.__PVT__exp_x_eff) 
                                          - (IData)(vlSelfRef.__PVT__exp_nx_eff)));
    vlSelfRef.__PVT__x_mant = (0x7ffffffffffffffULL 
                               & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                         (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_x))) 
                                                                           << 0x1aU) 
                                                                          | vlSelfRef.__PVT__frac_x))), 0x20U));
    vlSelfRef.__PVT__y_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_y))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_y))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__y_shift))) {
        vlSelfRef.__PVT__safe_y_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_y = (0U != vlSelfRef.__PVT__y_mant_base);
        vlSelfRef.__PVT__y_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_y_shift = (0x3fU & (IData)(vlSelfRef.__PVT__y_shift));
        vlSelfRef.__PVT__sticky_y = (0U != (vlSelfRef.__PVT__y_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_y_shift)))));
        vlSelfRef.__PVT__y_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__y_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_y_shift)));
    }
    vlSelfRef.__PVT__m_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_mx))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_mx))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__m_shift))) {
        vlSelfRef.__PVT__safe_m_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_m = (0U != vlSelfRef.__PVT__m_mant_base);
        vlSelfRef.__PVT__m_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_m_shift = (0x3fU & (IData)(vlSelfRef.__PVT__m_shift));
        vlSelfRef.__PVT__sticky_m = (0U != (vlSelfRef.__PVT__m_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_m_shift)))));
        vlSelfRef.__PVT__m_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__m_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_m_shift)));
    }
    vlSelfRef.__PVT__n_mant_base = (0x7ffffffffffffffULL 
                                    & VL_SHIFTL_QQI(59,59,32, (QData)((IData)(
                                                                              (((IData)(
                                                                                (0U 
                                                                                != (IData)(vlSelfRef.__PVT__exp_nx))) 
                                                                                << 0x1aU) 
                                                                               | vlSelfRef.__PVT__frac_nx))), 0x20U));
    if ((0x3bU <= (IData)(vlSelfRef.__PVT__n_shift))) {
        vlSelfRef.__PVT__safe_n_shift = 0x3aU;
        vlSelfRef.__PVT__sticky_n = (0U != vlSelfRef.__PVT__n_mant_base);
        vlSelfRef.__PVT__n_shifted = 0ULL;
    } else {
        vlSelfRef.__PVT__safe_n_shift = (0x3fU & (IData)(vlSelfRef.__PVT__n_shift));
        vlSelfRef.__PVT__sticky_n = (0U != (vlSelfRef.__PVT__n_mant_base 
                                            & (~ (0x7ffffffffffffffULL 
                                                  << (IData)(vlSelfRef.__PVT__safe_n_shift)))));
        vlSelfRef.__PVT__n_shifted = (0x7ffffffffffffffULL 
                                      & (vlSelfRef.__PVT__n_mant_base 
                                         >> (IData)(vlSelfRef.__PVT__safe_n_shift)));
    }
    vlSelfRef.__PVT__y_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_y));
    vlSelfRef.__PVT__m_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_mx));
    vlSelfRef.__PVT__n_op = ((IData)(vlSelfRef.__PVT__sign_x) 
                             ^ (IData)(vlSelfRef.__PVT__sign_nx));
    vlSelfRef.__PVT__op_x = vlSelfRef.__PVT__x_mant;
    vlSelfRef.__PVT__op_y = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__y_op)
                                 ? (~ vlSelfRef.__PVT__y_shifted)
                                 : vlSelfRef.__PVT__y_shifted));
    vlSelfRef.__PVT__op_m = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__m_op)
                                 ? (~ vlSelfRef.__PVT__m_shifted)
                                 : vlSelfRef.__PVT__m_shifted));
    vlSelfRef.__PVT__op_n = (0x7fffffffffffffffULL 
                             & ((IData)(vlSelfRef.__PVT__n_op)
                                 ? (~ vlSelfRef.__PVT__n_shifted)
                                 : vlSelfRef.__PVT__n_shifted));
    vlSelfRef.__PVT__csa_s1 = ((vlSelfRef.__PVT__op_x 
                                ^ vlSelfRef.__PVT__op_y) 
                               ^ vlSelfRef.__PVT__op_m);
    vlSelfRef.__PVT__csa_c1 = (((vlSelfRef.__PVT__op_x 
                                 & vlSelfRef.__PVT__op_y) 
                                | (vlSelfRef.__PVT__op_y 
                                   & vlSelfRef.__PVT__op_m)) 
                               | (vlSelfRef.__PVT__op_m 
                                  & vlSelfRef.__PVT__op_x));
    vlSelfRef.__PVT__csa_s2 = (0x7fffffffffffffffULL 
                               & ((vlSelfRef.__PVT__csa_s1 
                                   ^ VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U)) 
                                  ^ vlSelfRef.__PVT__op_n));
    vlSelfRef.__PVT__csa_c2 = (((vlSelfRef.__PVT__csa_s1 
                                 & VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U)) 
                                | (VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__csa_c1, 1U) 
                                   & vlSelfRef.__PVT__op_n)) 
                               | (vlSelfRef.__PVT__op_n 
                                  & vlSelfRef.__PVT__csa_s1));
}

VL_INLINE_OPT void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__31__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__31__KET____DOT__stage_inst__0\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_8;
    VlWide<3>/*95:0*/ __Vtemp_9;
    VlWide<3>/*95:0*/ __Vtemp_11;
    VlWide<3>/*95:0*/ __Vtemp_12;
    VlWide<3>/*95:0*/ __Vtemp_14;
    VlWide<3>/*95:0*/ __Vtemp_15;
    // Body
    if (vlSymsp->TOP.adder_4input_tree32_tb__DOT__nrst) {
        vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__31__KET__.out 
            = vlSelfRef.__PVT__result_out;
        vlSelfRef.__PVT__st2_sum_mag = vlSelfRef.__PVT__mag_sum;
        vlSelfRef.__PVT__st1_carry_vec = vlSelfRef.__PVT__csa_c2;
        vlSelfRef.__PVT__st1_sum_vec = vlSelfRef.__PVT__csa_s2;
        vlSelfRef.__PVT__st1_hot_ones = (3U & (((IData)(vlSelfRef.__PVT__y_op) 
                                                + (IData)(vlSelfRef.__PVT__m_op)) 
                                               + (IData)(vlSelfRef.__PVT__n_op)));
        vlSelfRef.__PVT__st2_exp_base = vlSelfRef.__PVT__st1_a_e;
        vlSelfRef.__PVT__st2_spec_res = vlSelfRef.__PVT__st1_special_result;
        vlSelfRef.__PVT__st1_a_e = vlSelfRef.__PVT__exp_x;
        vlSelfRef.__PVT__st1_special_result = vlSelfRef.__PVT__special_result;
    } else {
        vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__31__KET__.out = 0ULL;
        vlSelfRef.__PVT__st2_sum_mag = 0ULL;
        vlSelfRef.__PVT__st1_carry_vec = 0ULL;
        vlSelfRef.__PVT__st1_sum_vec = 0ULL;
        vlSelfRef.__PVT__st1_hot_ones = 0U;
        vlSelfRef.__PVT__st2_exp_base = 0U;
        vlSelfRef.__PVT__st2_spec_res = 0ULL;
        vlSelfRef.__PVT__st1_a_e = 0U;
        vlSelfRef.__PVT__st1_special_result = 0ULL;
    }
    vlSelfRef.__PVT__st2_res_sign = ((IData)(vlSymsp->TOP.adder_4input_tree32_tb__DOT__nrst) 
                                     && (IData)(vlSelfRef.__PVT__res_sign));
    vlSelfRef.__PVT__st1_a_s = ((IData)(vlSymsp->TOP.adder_4input_tree32_tb__DOT__nrst) 
                                && (IData)(vlSelfRef.__PVT__sign_x));
    vlSelfRef.__PVT__st2_special = ((IData)(vlSymsp->TOP.adder_4input_tree32_tb__DOT__nrst) 
                                    && (IData)(vlSelfRef.__PVT__st1_special_case));
    vlSelfRef.__PVT__st2_sticky = ((IData)(vlSymsp->TOP.adder_4input_tree32_tb__DOT__nrst) 
                                   && (IData)(vlSelfRef.__PVT__st1_align_sticky));
    if ((0ULL != vlSelfRef.__PVT__st2_sum_mag)) {
        vlSelfRef.__PVT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    __Vtemp_3[0U] = (IData)((((QData)((IData)((1U & (IData)(
                                                            (vlSelfRef.__PVT__st1_sum_vec 
                                                             >> 0x3eU))))) 
                              << 0x3fU) | vlSelfRef.__PVT__st1_sum_vec));
    __Vtemp_3[1U] = (IData)(((((QData)((IData)((1U 
                                                & (IData)(
                                                          (vlSelfRef.__PVT__st1_sum_vec 
                                                           >> 0x3eU))))) 
                               << 0x3fU) | vlSelfRef.__PVT__st1_sum_vec) 
                             >> 0x20U));
    __Vtemp_3[2U] = (1U & (IData)((vlSelfRef.__PVT__st1_sum_vec 
                                   >> 0x3eU)));
    VL_EXTENDS_WW(67,65, __Vtemp_4, __Vtemp_3);
    __Vtemp_6[0U] = __Vtemp_4[0U];
    __Vtemp_6[1U] = __Vtemp_4[1U];
    __Vtemp_6[2U] = (7U & __Vtemp_4[2U]);
    __Vtemp_8[0U] = ((IData)((((QData)((IData)((1U 
                                                & (IData)(
                                                          (vlSelfRef.__PVT__st1_carry_vec 
                                                           >> 0x3eU))))) 
                               << 0x3fU) | vlSelfRef.__PVT__st1_carry_vec)) 
                     << 1U);
    __Vtemp_8[1U] = (((IData)((((QData)((IData)((1U 
                                                 & (IData)(
                                                           (vlSelfRef.__PVT__st1_carry_vec 
                                                            >> 0x3eU))))) 
                                << 0x3fU) | vlSelfRef.__PVT__st1_carry_vec)) 
                      >> 0x1fU) | ((IData)(((((QData)((IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.__PVT__st1_carry_vec 
                                                                          >> 0x3eU))))) 
                                              << 0x3fU) 
                                             | vlSelfRef.__PVT__st1_carry_vec) 
                                            >> 0x20U)) 
                                   << 1U));
    __Vtemp_8[2U] = ((IData)(((((QData)((IData)((1U 
                                                 & (IData)(
                                                           (vlSelfRef.__PVT__st1_carry_vec 
                                                            >> 0x3eU))))) 
                                << 0x3fU) | vlSelfRef.__PVT__st1_carry_vec) 
                              >> 0x20U)) >> 0x1fU);
    VL_EXTENDS_WW(67,65, __Vtemp_9, __Vtemp_8);
    __Vtemp_11[0U] = __Vtemp_9[0U];
    __Vtemp_11[1U] = __Vtemp_9[1U];
    __Vtemp_11[2U] = (7U & __Vtemp_9[2U]);
    VL_ADD_W(3, __Vtemp_12, __Vtemp_6, __Vtemp_11);
    __Vtemp_14[0U] = vlSelfRef.__PVT__st1_hot_ones;
    __Vtemp_14[1U] = 0U;
    __Vtemp_14[2U] = 0U;
    VL_ADD_W(3, __Vtemp_15, __Vtemp_12, __Vtemp_14);
    vlSelfRef.__PVT__raw_sum[0U] = __Vtemp_15[0U];
    vlSelfRef.__PVT__raw_sum[1U] = __Vtemp_15[1U];
    vlSelfRef.__PVT__raw_sum[2U] = (1U & __Vtemp_15[2U]);
    if ((1U & vlSelfRef.__PVT__raw_sum[2U])) {
        vlSelfRef.__PVT__mag_sum = (0x7fffffffffffffffULL 
                                    & (1ULL + (~ (((QData)((IData)(
                                                                   vlSelfRef.__PVT__raw_sum[1U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.__PVT__raw_sum[0U]))))));
        vlSelfRef.__PVT__res_sign = (1U & (~ (IData)(vlSelfRef.__PVT__st1_a_s)));
    } else {
        vlSelfRef.__PVT__mag_sum = (0x7fffffffffffffffULL 
                                    & (((QData)((IData)(
                                                        vlSelfRef.__PVT__raw_sum[1U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelfRef.__PVT__raw_sum[0U]))));
        vlSelfRef.__PVT__res_sign = vlSelfRef.__PVT__st1_a_s;
    }
    vlSelfRef.__PVT__st1_special_case = ((IData)(vlSymsp->TOP.adder_4input_tree32_tb__DOT__nrst) 
                                         && (IData)(vlSelfRef.__PVT__special_case));
    vlSelfRef.__PVT__st1_align_sticky = ((IData)(vlSymsp->TOP.adder_4input_tree32_tb__DOT__nrst) 
                                         && (((IData)(vlSelfRef.__PVT__sticky_y) 
                                              | (IData)(vlSelfRef.__PVT__sticky_m)) 
                                             | (IData)(vlSelfRef.__PVT__sticky_n)));
}
