// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadder_4input_tree32_tb.h for the primary calling header

#include "Vadder_4input_tree32_tb__pch.h"
#include "Vadder_4input_tree32_tb___024root.h"

VL_ATTR_COLD void Vadder_4input_tree32_tb___024root___eval_initial__TOP(Vadder_4input_tree32_tb___024root* vlSelf);
VlCoroutine Vadder_4input_tree32_tb___024root___eval_initial__TOP__Vtiming__0(Vadder_4input_tree32_tb___024root* vlSelf);
VlCoroutine Vadder_4input_tree32_tb___024root___eval_initial__TOP__Vtiming__1(Vadder_4input_tree32_tb___024root* vlSelf);

void Vadder_4input_tree32_tb___024root___eval_initial(Vadder_4input_tree32_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_4input_tree32_tb___024root___eval_initial\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vadder_4input_tree32_tb___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vadder_4input_tree32_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vadder_4input_tree32_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vadder_4input_tree32_tb___024root___eval_initial__TOP__Vtiming__1(Vadder_4input_tree32_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_4input_tree32_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        vlSelfRef.adder_4input_tree32_tb__DOT__clk = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                             nullptr, 
                                             "tb/unit/systolic_array/adder_4input_tree32_tb.sv", 
                                             40);
        vlSelfRef.adder_4input_tree32_tb__DOT__clk = 1U;
        co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                             nullptr, 
                                             "tb/unit/systolic_array/adder_4input_tree32_tb.sv", 
                                             41);
    }
}

VL_INLINE_OPT void Vadder_4input_tree32_tb___024root___act_sequent__TOP__0(Vadder_4input_tree32_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_4input_tree32_tb___024root___act_sequent__TOP__0\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0ULL == vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_sum_mag)) {
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lzd_scan = 0ULL;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lead_zeros = 0x3eU;
    } else {
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lzd_scan 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_sum_mag;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lead_zeros = 0U;
        if ((0ULL == (0x7fffffffffffffffULL & VL_SHIFTR_QQI(63,63,32, vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lzd_scan, 0x1fU)))) {
            vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lead_zeros 
                = (0x3fU & ((IData)(0x20U) + (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lead_zeros)));
            vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lzd_scan 
                = (0x7fffffffffffffffULL & VL_SHIFTL_QQI(63,63,32, vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lzd_scan, 0x20U));
        }
        if ((0ULL == (0x7fffffffffffffffULL & VL_SHIFTR_QQI(63,63,32, vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lzd_scan, 0x2fU)))) {
            vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lead_zeros 
                = (0x3fU & ((IData)(0x10U) + (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lead_zeros)));
            vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lzd_scan 
                = (0x7fffffffffffffffULL & VL_SHIFTL_QQI(63,63,32, vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lzd_scan, 0x10U));
        }
        if ((0ULL == (0x7fffffffffffffffULL & VL_SHIFTR_QQI(63,63,32, vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lzd_scan, 0x37U)))) {
            vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lead_zeros 
                = (0x3fU & ((IData)(8U) + (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lead_zeros)));
            vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lzd_scan 
                = (0x7fffffffffffffffULL & VL_SHIFTL_QQI(63,63,32, vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lzd_scan, 8U));
        }
        if ((0ULL == (0x7fffffffffffffffULL & VL_SHIFTR_QQI(63,63,32, vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lzd_scan, 0x3bU)))) {
            vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lead_zeros 
                = (0x3fU & ((IData)(4U) + (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lead_zeros)));
            vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lzd_scan 
                = (0x7fffffffffffffffULL & VL_SHIFTL_QQI(63,63,32, vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lzd_scan, 4U));
        }
        if ((0ULL == (0x7fffffffffffffffULL & VL_SHIFTR_QQI(63,63,32, vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lzd_scan, 0x3dU)))) {
            vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lead_zeros 
                = (0x3fU & ((IData)(2U) + (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lead_zeros)));
            vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lzd_scan 
                = (0x7fffffffffffffffULL & VL_SHIFTL_QQI(63,63,32, vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lzd_scan, 2U));
        }
        if ((0ULL == (0x7fffffffffffffffULL & VL_SHIFTR_QQI(63,63,32, vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lzd_scan, 0x3eU)))) {
            vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lead_zeros 
                = (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lead_zeros)));
            vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lzd_scan 
                = (0x7fffffffffffffffULL & VL_SHIFTL_QQI(63,63,32, vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lzd_scan, 1U));
        }
    }
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__norm_val 
        = (0x7fffffffffffffffULL & (vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_sum_mag 
                                    << (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lead_zeros)));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__final_mant 
        = (0x3ffffffU & vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__rounded_mant_int);
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lead_zeros 
        = (0x3fU & ((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lead_zeros) 
                    - ((0x4000000U & vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__rounded_mant_int)
                        ? 1U : 0U)));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(4U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,8, (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__lead_zeros))));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__result_out 
        = ((((0ULL == vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_sum_mag) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_exp_base)))
            ? 0ULL : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__final_exp_calc)))
                       ? (0x3fc000000ULL | ((QData)((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_res_sign)) 
                                            << 0x22U))
                       : (((QData)((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_res_sign)) 
                           << 0x22U) | (((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__final_exp_calc)))) 
                                         << 0x1aU) 
                                        | (QData)((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__final_mant))))));
    if (vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_special) {
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__result_out 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_spec_res;
    }
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__guard_bit 
        = (1U & (IData)((vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__norm_val 
                         >> 0x23U)));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__round_bit 
        = (1U & (IData)((vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__norm_val 
                         >> 0x22U)));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sticky_bit 
        = ((0U != (0x3ffffffffULL & vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__norm_val)) 
           | (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_sticky));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__l_bit 
        = (1U & (IData)((vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__norm_val 
                         >> 0x24U)));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__round_up 
        = ((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__guard_bit) 
           & (((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__round_bit) 
               | (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sticky_bit)) 
              | (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__l_bit)));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__rounded_mant_int 
        = (0x7ffffffU & ((0x3ffffffU & (IData)((vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__norm_val 
                                                >> 0x24U))) 
                         + (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__round_up)));
}

VL_INLINE_OPT void Vadder_4input_tree32_tb___024root___nba_sequent__TOP__0(Vadder_4input_tree32_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_4input_tree32_tb___024root___nba_sequent__TOP__0\n"); );
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
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_a_s 
        = ((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__nrst) 
           && (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sign_x));
    if (vlSelfRef.adder_4input_tree32_tb__DOT__nrst) {
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_carry_vec 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__csa_c2;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_sum_vec 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__csa_s2;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_hot_ones 
            = (3U & (((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__y_op) 
                      + (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__m_op)) 
                     + (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__n_op)));
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_sum_mag 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__mag_sum;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_exp_base 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_a_e;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_spec_res 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_special_result;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_a_e 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__exp_x;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_special_result 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__special_result;
    } else {
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_carry_vec = 0ULL;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_sum_vec = 0ULL;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_hot_ones = 0U;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_sum_mag = 0ULL;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_exp_base = 0U;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_spec_res = 0ULL;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_a_e = 0U;
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_special_result = 0ULL;
    }
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__nrst) 
           && (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__res_sign));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_sticky 
        = ((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__nrst) 
           && (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_align_sticky));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_special 
        = ((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__nrst) 
           && (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_special_case));
    __Vtemp_3[0U] = (IData)((((QData)((IData)((1U & (IData)(
                                                            (vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_sum_vec 
                                                             >> 0x3eU))))) 
                              << 0x3fU) | vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_sum_vec));
    __Vtemp_3[1U] = (IData)(((((QData)((IData)((1U 
                                                & (IData)(
                                                          (vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_sum_vec 
                                                           >> 0x3eU))))) 
                               << 0x3fU) | vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_sum_vec) 
                             >> 0x20U));
    __Vtemp_3[2U] = (1U & (IData)((vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_sum_vec 
                                   >> 0x3eU)));
    VL_EXTENDS_WW(67,65, __Vtemp_4, __Vtemp_3);
    __Vtemp_6[0U] = __Vtemp_4[0U];
    __Vtemp_6[1U] = __Vtemp_4[1U];
    __Vtemp_6[2U] = (7U & __Vtemp_4[2U]);
    __Vtemp_8[0U] = ((IData)((((QData)((IData)((1U 
                                                & (IData)(
                                                          (vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_carry_vec 
                                                           >> 0x3eU))))) 
                               << 0x3fU) | vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_carry_vec)) 
                     << 1U);
    __Vtemp_8[1U] = (((IData)((((QData)((IData)((1U 
                                                 & (IData)(
                                                           (vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_carry_vec 
                                                            >> 0x3eU))))) 
                                << 0x3fU) | vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_carry_vec)) 
                      >> 0x1fU) | ((IData)(((((QData)((IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_carry_vec 
                                                                          >> 0x3eU))))) 
                                              << 0x3fU) 
                                             | vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_carry_vec) 
                                            >> 0x20U)) 
                                   << 1U));
    __Vtemp_8[2U] = ((IData)(((((QData)((IData)((1U 
                                                 & (IData)(
                                                           (vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_carry_vec 
                                                            >> 0x3eU))))) 
                                << 0x3fU) | vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_carry_vec) 
                              >> 0x20U)) >> 0x1fU);
    VL_EXTENDS_WW(67,65, __Vtemp_9, __Vtemp_8);
    __Vtemp_11[0U] = __Vtemp_9[0U];
    __Vtemp_11[1U] = __Vtemp_9[1U];
    __Vtemp_11[2U] = (7U & __Vtemp_9[2U]);
    VL_ADD_W(3, __Vtemp_12, __Vtemp_6, __Vtemp_11);
    __Vtemp_14[0U] = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_hot_ones;
    __Vtemp_14[1U] = 0U;
    __Vtemp_14[2U] = 0U;
    VL_ADD_W(3, __Vtemp_15, __Vtemp_12, __Vtemp_14);
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__raw_sum[0U] 
        = __Vtemp_15[0U];
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__raw_sum[1U] 
        = __Vtemp_15[1U];
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__raw_sum[2U] 
        = (1U & __Vtemp_15[2U]);
    if ((1U & vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__raw_sum[2U])) {
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__mag_sum 
            = (0x7fffffffffffffffULL & (1ULL + (~ (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__raw_sum[1U])) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(
                                                                     vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__raw_sum[0U]))))));
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_a_s)));
    } else {
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__mag_sum 
            = (0x7fffffffffffffffULL & (((QData)((IData)(
                                                         vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__raw_sum[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__raw_sum[0U]))));
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__res_sign 
            = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_a_s;
    }
    if ((0ULL != vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st2_sum_mag)) {
        vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_align_sticky 
        = ((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__nrst) 
           && (((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sticky_y) 
                | (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sticky_m)) 
               | (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__sticky_n)));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__st1_special_case 
        = ((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__nrst) 
           && (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__special_case));
}

void Vadder_4input_tree32_tb___024root___timing_resume(Vadder_4input_tree32_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_4input_tree32_tb___024root___timing_resume\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x100000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h2af12165__0.resume(
                                                   "@(posedge adder_4input_tree32_tb.clk)");
    }
    if ((0x400000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vadder_4input_tree32_tb___024root___timing_commit(Vadder_4input_tree32_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_4input_tree32_tb___024root___timing_commit\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (0x100000000ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h2af12165__0.commit(
                                                   "@(posedge adder_4input_tree32_tb.clk)");
    }
}

void Vadder_4input_tree32_tb___024root___eval_triggers__act(Vadder_4input_tree32_tb___024root* vlSelf);
void Vadder_4input_tree32_tb___024root___eval_act(Vadder_4input_tree32_tb___024root* vlSelf);

bool Vadder_4input_tree32_tb___024root___eval_phase__act(Vadder_4input_tree32_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_4input_tree32_tb___024root___eval_phase__act\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<35> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vadder_4input_tree32_tb___024root___eval_triggers__act(vlSelf);
    Vadder_4input_tree32_tb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vadder_4input_tree32_tb___024root___timing_resume(vlSelf);
        Vadder_4input_tree32_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vadder_4input_tree32_tb___024root___eval_nba(Vadder_4input_tree32_tb___024root* vlSelf);

bool Vadder_4input_tree32_tb___024root___eval_phase__nba(Vadder_4input_tree32_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_4input_tree32_tb___024root___eval_phase__nba\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vadder_4input_tree32_tb___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadder_4input_tree32_tb___024root___dump_triggers__nba(Vadder_4input_tree32_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadder_4input_tree32_tb___024root___dump_triggers__act(Vadder_4input_tree32_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vadder_4input_tree32_tb___024root___eval(Vadder_4input_tree32_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_4input_tree32_tb___024root___eval\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vadder_4input_tree32_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/unit/systolic_array/adder_4input_tree32_tb.sv", 18, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vadder_4input_tree32_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/unit/systolic_array/adder_4input_tree32_tb.sv", 18, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vadder_4input_tree32_tb___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vadder_4input_tree32_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vadder_4input_tree32_tb___024root___eval_debug_assertions(Vadder_4input_tree32_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_4input_tree32_tb___024root___eval_debug_assertions\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
