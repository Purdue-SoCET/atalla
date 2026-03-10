// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd4_fp32accum_fp16_tb_softfloat.h for the primary calling header

#include "Vadd4_fp32accum_fp16_tb_softfloat__pch.h"
#include "Vadd4_fp32accum_fp16_tb_softfloat__Syms.h"
#include "Vadd4_fp32accum_fp16_tb_softfloat___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp32accum_fp16_tb_softfloat___024root___dump_triggers__stl(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_triggers__stl(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_triggers__stl\n"); );
    Vadd4_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vadd4_fp32accum_fp16_tb_softfloat___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void Vadd4_fp32accum_fp16_tb_softfloat___024root___stl_sequent__TOP__0(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_fp16_tb_softfloat___024root___stl_sequent__TOP__0\n"); );
    Vadd4_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0U != vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag)) {
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
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
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__guard 
        = (1U & (vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out 
                 >> 0xcU));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rnd 
        = (1U & (vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out 
                 >> 0xbU));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__sticky 
        = (0U != (0x7ffU & vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__round_up 
        = ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__guard) 
           & (((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rnd) 
               | (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__sticky)) 
              | (vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out 
                 >> 0xdU)));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded 
        = (0x7ffU & ((0x3ffU & (vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out 
                                >> 0xdU)) + (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__round_up)));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp 
        = (0x3ffU & ((VL_EXTENDS_II(10,10, (0xffU & 
                                            (vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out 
                                             >> 0x17U))) 
                      - (IData)(0x70U)) + VL_EXTENDS_II(10,10, 
                                                        (1U 
                                                         & ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded) 
                                                            >> 0xaU)))));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result 
        = ((0xffU == (0xffU & (vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out 
                               >> 0x17U))) ? (0x7c00U 
                                              | ((0x8000U 
                                                  & (vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out 
                                                     >> 0x10U)) 
                                                 | ((0U 
                                                     != 
                                                     (0x7fffffU 
                                                      & vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out))
                                                     ? 0x200U
                                                     : 0U)))
            : (VL_LTES_III(10, 0x1fU, (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp))
                ? (0x7c00U | (0x8000U & (vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out 
                                         >> 0x10U)))
                : (VL_GTES_III(32, 0U, VL_EXTENDS_II(32,10, (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp)))
                    ? (0x8000U & (vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out 
                                  >> 0x10U)) : ((0x8000U 
                                                 & (vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out 
                                                    >> 0x10U)) 
                                                | ((0x7c00U 
                                                    & ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp) 
                                                       << 0xaU)) 
                                                   | ((0x400U 
                                                       & (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded))
                                                       ? 0U
                                                       : 
                                                      (0x3ffU 
                                                       & (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded))))))));
    if ((0U == vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag)) {
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan = 0U;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros = 0x1aU;
    } else {
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros = 0U;
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0xbU))) {
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros 
                = (0x3fU & ((IData)(0x10U) + (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)));
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan 
                = (0x7ffffffU & VL_SHIFTL_III(27,27,32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0x10U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0x13U))) {
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros 
                = (0x3fU & ((IData)(8U) + (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)));
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan 
                = (0x7ffffffU & VL_SHIFTL_III(27,27,32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 8U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0x17U))) {
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros 
                = (0x3fU & ((IData)(4U) + (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)));
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan 
                = (0x7ffffffU & VL_SHIFTL_III(27,27,32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 4U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0x19U))) {
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros 
                = (0x3fU & ((IData)(2U) + (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)));
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan 
                = (0x7ffffffU & VL_SHIFTL_III(27,27,32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 2U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0x1aU))) {
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros 
                = (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)));
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan 
                = (0x7ffffffU & VL_SHIFTL_III(27,27,32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 1U));
        }
    }
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val 
        = (0x7ffffffU & VL_SHIFTL_III(27,27,6, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag, (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_mant 
        = (0x7fffffU & (vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val 
                        >> 3U));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc 
        = (0x7ffU & ((IData)(0x70U) + (((IData)(2U) 
                                        + VL_EXTENDS_II(11,7, (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_exp_base))) 
                                       - VL_EXTENDS_II(11,8, (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)))));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__result_out 
        = ((((0U == vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_exp_base)))
            ? ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign) 
               << 0x1fU) : (VL_LTES_III(32, 0xffU, 
                                        VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc)))
                             ? (0x7f800000U | ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign) 
                                               << 0x1fU))
                             : (((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign) 
                                 << 0x1fU) | ((0x7f800000U 
                                               & ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc) 
                                                  << 0x17U)) 
                                              | vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_mant))));
    if (vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special) {
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__result_out 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_spec_res;
    }
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
