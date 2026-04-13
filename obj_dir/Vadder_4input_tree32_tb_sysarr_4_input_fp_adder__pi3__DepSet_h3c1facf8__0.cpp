// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadder_4input_tree32_tb.h for the primary calling header

#include "Vadder_4input_tree32_tb__pch.h"
#include "Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3.h"

VL_INLINE_OPT void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0ULL == vlSelfRef.__PVT__st2_sum_mag)) {
        vlSelfRef.__PVT__lzd_scan = 0ULL;
        vlSelfRef.__PVT__lead_zeros = 0x3eU;
    } else {
        vlSelfRef.__PVT__lzd_scan = vlSelfRef.__PVT__st2_sum_mag;
        vlSelfRef.__PVT__lead_zeros = 0U;
        if ((0ULL == (0x7fffffffffffffffULL & VL_SHIFTR_QQI(63,63,32, vlSelfRef.__PVT__lzd_scan, 0x1fU)))) {
            vlSelfRef.__PVT__lead_zeros = (0x3fU & 
                                           ((IData)(0x20U) 
                                            + (IData)(vlSelfRef.__PVT__lead_zeros)));
            vlSelfRef.__PVT__lzd_scan = (0x7fffffffffffffffULL 
                                         & VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__lzd_scan, 0x20U));
        }
        if ((0ULL == (0x7fffffffffffffffULL & VL_SHIFTR_QQI(63,63,32, vlSelfRef.__PVT__lzd_scan, 0x2fU)))) {
            vlSelfRef.__PVT__lead_zeros = (0x3fU & 
                                           ((IData)(0x10U) 
                                            + (IData)(vlSelfRef.__PVT__lead_zeros)));
            vlSelfRef.__PVT__lzd_scan = (0x7fffffffffffffffULL 
                                         & VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__lzd_scan, 0x10U));
        }
        if ((0ULL == (0x7fffffffffffffffULL & VL_SHIFTR_QQI(63,63,32, vlSelfRef.__PVT__lzd_scan, 0x37U)))) {
            vlSelfRef.__PVT__lead_zeros = (0x3fU & 
                                           ((IData)(8U) 
                                            + (IData)(vlSelfRef.__PVT__lead_zeros)));
            vlSelfRef.__PVT__lzd_scan = (0x7fffffffffffffffULL 
                                         & VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__lzd_scan, 8U));
        }
        if ((0ULL == (0x7fffffffffffffffULL & VL_SHIFTR_QQI(63,63,32, vlSelfRef.__PVT__lzd_scan, 0x3bU)))) {
            vlSelfRef.__PVT__lead_zeros = (0x3fU & 
                                           ((IData)(4U) 
                                            + (IData)(vlSelfRef.__PVT__lead_zeros)));
            vlSelfRef.__PVT__lzd_scan = (0x7fffffffffffffffULL 
                                         & VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__lzd_scan, 4U));
        }
        if ((0ULL == (0x7fffffffffffffffULL & VL_SHIFTR_QQI(63,63,32, vlSelfRef.__PVT__lzd_scan, 0x3dU)))) {
            vlSelfRef.__PVT__lead_zeros = (0x3fU & 
                                           ((IData)(2U) 
                                            + (IData)(vlSelfRef.__PVT__lead_zeros)));
            vlSelfRef.__PVT__lzd_scan = (0x7fffffffffffffffULL 
                                         & VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__lzd_scan, 2U));
        }
        if ((0ULL == (0x7fffffffffffffffULL & VL_SHIFTR_QQI(63,63,32, vlSelfRef.__PVT__lzd_scan, 0x3eU)))) {
            vlSelfRef.__PVT__lead_zeros = (0x3fU & 
                                           ((IData)(1U) 
                                            + (IData)(vlSelfRef.__PVT__lead_zeros)));
            vlSelfRef.__PVT__lzd_scan = (0x7fffffffffffffffULL 
                                         & VL_SHIFTL_QQI(63,63,32, vlSelfRef.__PVT__lzd_scan, 1U));
        }
    }
    vlSelfRef.__PVT__norm_val = (0x7fffffffffffffffULL 
                                 & (vlSelfRef.__PVT__st2_sum_mag 
                                    << (IData)(vlSelfRef.__PVT__lead_zeros)));
    vlSelfRef.__PVT__final_mant = (0x3ffffffU & vlSelfRef.__PVT__rounded_mant_int);
    vlSelfRef.__PVT__lead_zeros = (0x3fU & ((IData)(vlSelfRef.__PVT__lead_zeros) 
                                            - ((0x4000000U 
                                                & vlSelfRef.__PVT__rounded_mant_int)
                                                ? 1U
                                                : 0U)));
    vlSelfRef.__PVT__final_exp_calc = (0x7ffU & (((IData)(4U) 
                                                  + 
                                                  VL_EXTENDS_II(11,10, (IData)(vlSelfRef.__PVT__st2_exp_base))) 
                                                 - 
                                                 VL_EXTENDS_II(11,8, (IData)(vlSelfRef.__PVT__lead_zeros))));
    vlSelfRef.__PVT__result_out = ((((0ULL == vlSelfRef.__PVT__st2_sum_mag) 
                                     | VL_GTES_III(32, 0U, 
                                                   VL_EXTENDS_II(32,11, (IData)(vlSelfRef.__PVT__final_exp_calc)))) 
                                    | (0U == (IData)(vlSelfRef.__PVT__st2_exp_base)))
                                    ? 0ULL : (VL_LTES_III(32, 0xffU, 
                                                          VL_EXTENDS_II(32,11, (IData)(vlSelfRef.__PVT__final_exp_calc)))
                                               ? (0x3fc000000ULL 
                                                  | ((QData)((IData)(vlSelfRef.__PVT__st2_res_sign)) 
                                                     << 0x22U))
                                               : (((QData)((IData)(vlSelfRef.__PVT__st2_res_sign)) 
                                                   << 0x22U) 
                                                  | (((QData)((IData)(
                                                                      (0xffU 
                                                                       & (IData)(vlSelfRef.__PVT__final_exp_calc)))) 
                                                      << 0x1aU) 
                                                     | (QData)((IData)(vlSelfRef.__PVT__final_mant))))));
    if (vlSelfRef.__PVT__st2_special) {
        vlSelfRef.__PVT__result_out = vlSelfRef.__PVT__st2_spec_res;
    }
    vlSelfRef.__PVT__guard_bit = (1U & (IData)((vlSelfRef.__PVT__norm_val 
                                                >> 0x23U)));
    vlSelfRef.__PVT__round_bit = (1U & (IData)((vlSelfRef.__PVT__norm_val 
                                                >> 0x22U)));
    vlSelfRef.__PVT__sticky_bit = ((0U != (0x3ffffffffULL 
                                           & vlSelfRef.__PVT__norm_val)) 
                                   | (IData)(vlSelfRef.__PVT__st2_sticky));
    vlSelfRef.__PVT__l_bit = (1U & (IData)((vlSelfRef.__PVT__norm_val 
                                            >> 0x24U)));
    vlSelfRef.__PVT__round_up = ((IData)(vlSelfRef.__PVT__guard_bit) 
                                 & (((IData)(vlSelfRef.__PVT__round_bit) 
                                     | (IData)(vlSelfRef.__PVT__sticky_bit)) 
                                    | (IData)(vlSelfRef.__PVT__l_bit)));
    vlSelfRef.__PVT__rounded_mant_int = (0x7ffffffU 
                                         & ((0x3ffffffU 
                                             & (IData)(
                                                       (vlSelfRef.__PVT__norm_val 
                                                        >> 0x24U))) 
                                            + (IData)(vlSelfRef.__PVT__round_up)));
}
