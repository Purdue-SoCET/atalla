// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd32_fp32accum_bf16_tb_softfloat.h for the primary calling header

#include "Vadd32_fp32accum_bf16_tb_softfloat__pch.h"
#include "Vadd32_fp32accum_bf16_tb_softfloat__Syms.h"
#include "Vadd32_fp32accum_bf16_tb_softfloat___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd32_fp32accum_bf16_tb_softfloat___024root___dump_triggers__stl(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_triggers__stl(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_triggers__stl\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
    vlSelfRef.__VstlTriggered.setBit(1U, (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__norm_val 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__norm_val__0));
    vlSelfRef.__VstlTriggered.setBit(2U, (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val__0));
    vlSelfRef.__VstlTriggered.setBit(3U, (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val__0));
    vlSelfRef.__VstlTriggered.setBit(4U, (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val__0));
    vlSelfRef.__VstlTriggered.setBit(5U, (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val__0));
    vlSelfRef.__VstlTriggered.setBit(6U, (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val__0));
    vlSelfRef.__VstlTriggered.setBit(7U, (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val__0));
    vlSelfRef.__VstlTriggered.setBit(8U, (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val__0));
    vlSelfRef.__VstlTriggered.setBit(9U, (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val__0));
    vlSelfRef.__VstlTriggered.setBit(0xaU, (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val 
                                            != vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val__0));
    vlSelfRef.__VstlTriggered.setBit(0xbU, (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val 
                                            != vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val__0));
    vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__norm_val__0 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__norm_val;
    vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val__0 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val;
    vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val__0 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val;
    vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val__0 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val;
    vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val__0 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val;
    vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val__0 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val;
    vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val__0 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val;
    vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val__0 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val;
    vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val__0 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val;
    vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val__0 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val;
    vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val__0 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VstlDidInit)))))) {
        vlSelfRef.__VstlDidInit = 1U;
        vlSelfRef.__VstlTriggered.setBit(1U, 1U);
        vlSelfRef.__VstlTriggered.setBit(2U, 1U);
        vlSelfRef.__VstlTriggered.setBit(3U, 1U);
        vlSelfRef.__VstlTriggered.setBit(4U, 1U);
        vlSelfRef.__VstlTriggered.setBit(5U, 1U);
        vlSelfRef.__VstlTriggered.setBit(6U, 1U);
        vlSelfRef.__VstlTriggered.setBit(7U, 1U);
        vlSelfRef.__VstlTriggered.setBit(8U, 1U);
        vlSelfRef.__VstlTriggered.setBit(9U, 1U);
        vlSelfRef.__VstlTriggered.setBit(0xaU, 1U);
        vlSelfRef.__VstlTriggered.setBit(0xbU, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void Vadd32_fp32accum_bf16_tb_softfloat___024root___stl_sequent__TOP__0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___stl_sequent__TOP__0\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__raw_sum 
        = (0x3fffffffU & ((VL_EXTENDS_II(30,31, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_sum_vec) 
                           + VL_EXTENDS_II(30,30, (0x3fffffffU 
                                                   & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_carry_vec, 1U)))) 
                          + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_hot_ones)));
    if ((0x20000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__raw_sum)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__mag_sum 
            = (0x3fffffffU & ((IData)(1U) + (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__raw_sum)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__mag_sum 
            = (0x1fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__raw_sum);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_a_s;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum 
        = (0x3fffffffU & ((VL_EXTENDS_II(30,31, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_sum_vec) 
                           + VL_EXTENDS_II(30,30, (0x3fffffffU 
                                                   & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U)))) 
                          + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_hot_ones)));
    if ((0x20000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x3fffffffU & ((IData)(1U) + (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x1fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_a_s;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum 
        = (0x3fffffffU & ((VL_EXTENDS_II(30,31, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_sum_vec) 
                           + VL_EXTENDS_II(30,30, (0x3fffffffU 
                                                   & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U)))) 
                          + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_hot_ones)));
    if ((0x20000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x3fffffffU & ((IData)(1U) + (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x1fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_a_s;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum 
        = (0x3fffffffU & ((VL_EXTENDS_II(30,31, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_sum_vec) 
                           + VL_EXTENDS_II(30,30, (0x3fffffffU 
                                                   & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U)))) 
                          + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_hot_ones)));
    if ((0x20000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x3fffffffU & ((IData)(1U) + (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x1fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_a_s;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum 
        = (0x3fffffffU & ((VL_EXTENDS_II(30,31, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_sum_vec) 
                           + VL_EXTENDS_II(30,30, (0x3fffffffU 
                                                   & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U)))) 
                          + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_hot_ones)));
    if ((0x20000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x3fffffffU & ((IData)(1U) + (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x1fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_a_s;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum 
        = (0x3fffffffU & ((VL_EXTENDS_II(30,31, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_sum_vec) 
                           + VL_EXTENDS_II(30,30, (0x3fffffffU 
                                                   & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U)))) 
                          + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_hot_ones)));
    if ((0x20000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x3fffffffU & ((IData)(1U) + (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x1fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_a_s;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum 
        = (0x3fffffffU & ((VL_EXTENDS_II(30,31, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_sum_vec) 
                           + VL_EXTENDS_II(30,30, (0x3fffffffU 
                                                   & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U)))) 
                          + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_hot_ones)));
    if ((0x20000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x3fffffffU & ((IData)(1U) + (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x1fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_a_s;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum 
        = (0x3fffffffU & ((VL_EXTENDS_II(30,31, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_sum_vec) 
                           + VL_EXTENDS_II(30,30, (0x3fffffffU 
                                                   & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U)))) 
                          + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_hot_ones)));
    if ((0x20000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x3fffffffU & ((IData)(1U) + (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x1fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_a_s;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum 
        = (0x3fffffffU & ((VL_EXTENDS_II(30,31, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_sum_vec) 
                           + VL_EXTENDS_II(30,30, (0x3fffffffU 
                                                   & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U)))) 
                          + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_hot_ones)));
    if ((0x20000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x3fffffffU & ((IData)(1U) + (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x1fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_a_s;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum 
        = (0x3fffffffU & ((VL_EXTENDS_II(30,31, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_sum_vec) 
                           + VL_EXTENDS_II(30,30, (0x3fffffffU 
                                                   & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_carry_vec, 1U)))) 
                          + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_hot_ones)));
    if ((0x20000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__mag_sum 
            = (0x3fffffffU & ((IData)(1U) + (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__mag_sum 
            = (0x1fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_a_s;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum 
        = (0x3fffffffU & ((VL_EXTENDS_II(30,31, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_sum_vec) 
                           + VL_EXTENDS_II(30,30, (0x3fffffffU 
                                                   & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_carry_vec, 1U)))) 
                          + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_hot_ones)));
    if ((0x20000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__mag_sum 
            = (0x3fffffffU & ((IData)(1U) + (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__mag_sum 
            = (0x1fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_a_s;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__guard 
        = (1U & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage3_if.out 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__rnd 
        = (1U & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage3_if.out 
                 >> 0xeU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__sticky 
        = (0U != (0x3fffU & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage3_if.out));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__round_up 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__guard) 
           & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__rnd) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__sticky)) 
              | (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage3_if.out 
                 >> 0x10U)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__rounded 
        = (0xffU & ((0x7fU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage3_if.out 
                              >> 0x10U)) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__round_up)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__new_exp 
        = (0x3ffU & (VL_EXTENDS_II(10,10, (0xffU & 
                                           (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage3_if.out 
                                            >> 0x17U))) 
                     + VL_EXTENDS_II(10,10, (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__rounded) 
                                                   >> 7U)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_result 
        = ((0xffU == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage3_if.out 
                               >> 0x17U))) ? (0x7f80U 
                                              | ((0x8000U 
                                                  & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage3_if.out 
                                                     >> 0x10U)) 
                                                 | ((0U 
                                                     != 
                                                     (0x7fffffU 
                                                      & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage3_if.out))
                                                     ? 0x40U
                                                     : 0U)))
            : (VL_LTES_III(10, 0xffU, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__new_exp))
                ? (0x7f80U | (0x8000U & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage3_if.out 
                                         >> 0x10U)))
                : (VL_GTES_III(32, 0U, VL_EXTENDS_II(32,10, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__new_exp)))
                    ? (0x8000U & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage3_if.out 
                                  >> 0x10U)) : ((0x8000U 
                                                 & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage3_if.out 
                                                    >> 0x10U)) 
                                                | ((0x7f80U 
                                                    & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__new_exp) 
                                                       << 7U)) 
                                                   | ((0x80U 
                                                       & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__rounded))
                                                       ? 0U
                                                       : 
                                                      (0x7fU 
                                                       & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__rounded))))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__a_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0U] >> 7U))) ? (0x8000U 
                                             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                             [0U]) : 
           vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__b_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [1U] >> 7U))) ? (0x8000U 
                                             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                             [1U]) : 
           vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__c_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [2U] >> 7U))) ? (0x8000U 
                                             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                             [2U]) : 
           vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__d_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [3U] >> 7U))) ? (0x8000U 
                                             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                             [3U]) : 
           vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__x_mant 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_y))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_m))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_n))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__x_mant;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c1 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s2 
        = (0x3fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1 
                           ^ VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
                          ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c2 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1 
             & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
            | (VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c1, 1U) 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__a_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [4U] >> 7U))) ? (0x8000U 
                                             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                             [4U]) : 
           vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [4U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__b_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [5U] >> 7U))) ? (0x8000U 
                                             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                             [5U]) : 
           vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [5U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__c_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [6U] >> 7U))) ? (0x8000U 
                                             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                             [6U]) : 
           vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [6U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__d_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [7U] >> 7U))) ? (0x8000U 
                                             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                             [7U]) : 
           vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [7U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__x_mant 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_y))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_m))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_n))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__x_mant;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c1 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s2 
        = (0x3fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1 
                           ^ VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
                          ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c2 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1 
             & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
            | (VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c1, 1U) 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__a_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [8U] >> 7U))) ? (0x8000U 
                                             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                             [8U]) : 
           vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [8U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__b_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [9U] >> 7U))) ? (0x8000U 
                                             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                             [9U]) : 
           vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [9U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__c_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0xaU] >> 7U))) ? (0x8000U 
                                               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                               [0xaU])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0xaU]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__d_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0xbU] >> 7U))) ? (0x8000U 
                                               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                               [0xbU])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0xbU]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__x_mant 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_y))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_m))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_n))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__x_mant;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c1 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s2 
        = (0x3fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1 
                           ^ VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
                          ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c2 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1 
             & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
            | (VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c1, 1U) 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__a_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0xcU] >> 7U))) ? (0x8000U 
                                               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                               [0xcU])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0xcU]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__b_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0xdU] >> 7U))) ? (0x8000U 
                                               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                               [0xdU])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0xdU]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__c_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0xeU] >> 7U))) ? (0x8000U 
                                               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                               [0xeU])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0xeU]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__d_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0xfU] >> 7U))) ? (0x8000U 
                                               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                               [0xfU])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0xfU]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__x_mant 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_y))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_m))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_n))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__x_mant;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c1 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s2 
        = (0x3fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1 
                           ^ VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
                          ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c2 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1 
             & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
            | (VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c1, 1U) 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__a_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x10U] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x10U])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x10U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__b_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x11U] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x11U])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x11U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__c_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x12U] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x12U])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x12U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__d_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x13U] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x13U])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x13U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__x_mant 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_y))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_m))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_n))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__x_mant;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c1 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s2 
        = (0x3fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1 
                           ^ VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
                          ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c2 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1 
             & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
            | (VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c1, 1U) 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__a_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x14U] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x14U])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x14U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__b_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x15U] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x15U])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x15U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__c_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x16U] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x16U])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x16U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__d_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x17U] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x17U])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x17U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__x_mant 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_y))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_m))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_n))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__x_mant;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c1 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s2 
        = (0x3fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1 
                           ^ VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
                          ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c2 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1 
             & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
            | (VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c1, 1U) 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__a_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x18U] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x18U])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x18U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__b_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x19U] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x19U])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x19U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__c_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x1aU] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x1aU])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x1aU]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__d_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x1bU] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x1bU])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x1bU]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__x_mant 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_y))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_m))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_n))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__x_mant;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c1 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s2 
        = (0x3fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1 
                           ^ VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
                          ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c2 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1 
             & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
            | (VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c1, 1U) 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__a_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x1cU] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x1cU])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x1cU]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__b_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x1dU] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x1dU])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x1dU]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__c_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x1eU] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x1eU])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x1eU]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__d_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x1fU] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x1fU])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x1fU]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__x_mant 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_y))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_m))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_n))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__x_mant;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c1 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s2 
        = (0x3fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1 
                           ^ VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
                          ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c2 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1 
             & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
            | (VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c1, 1U) 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__a_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage2_if__BRA__0__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage2_if__BRA__0__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage2_if__BRA__0__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__b_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage2_if__BRA__1__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage2_if__BRA__1__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage2_if__BRA__1__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__c_daz = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__d_daz = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_a 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__a_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_a 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__a_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_a 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__a_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_b 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__b_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_b 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__b_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_b 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__b_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_c = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_c = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_c = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_d = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_d = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_d = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__is_nan_any 
        = (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_a)) 
            & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_a)) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_b)) 
              & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_b)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__any_pos_inf 
        = ((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_a)) 
             & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_a))) 
            & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_a)))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_b)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_b))) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_b)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__any_neg_inf 
        = ((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_a)) 
             & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_a)) 
            & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_a)))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_b)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_b)) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_b)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_a;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_r 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_c;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_r 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_c;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_r 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_c;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_n 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_d;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_n 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_d;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_n 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_d;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__x_mant 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_x))) 
            << 0x1aU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_x 
                         << 3U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_y))) 
            << 0x1aU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_y 
                         << 3U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_mx))) 
            << 0x1aU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_mx 
                         << 3U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_nx))) 
            << 0x1aU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_nx 
                         << 3U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sticky_y 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sticky_y))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sticky_m 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sticky_m))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sticky_n 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sticky_n))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_x 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__x_mant;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_y 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_m 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_n 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__csa_s1 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_x 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_y) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_m);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__csa_c1 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_x 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_y) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_y 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_m)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_m 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__csa_s2 
        = (0x3fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__csa_s1 
                           ^ VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__csa_c1, 1U)) 
                          ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_n));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__csa_c2 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__csa_s1 
             & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__csa_c1, 1U)) 
            | (VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__csa_c1, 1U) 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_n)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_n 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__csa_s1));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__a_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__0__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__0__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__0__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__b_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__1__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__1__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__1__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__c_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__2__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__2__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__2__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__d_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__3__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__3__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__3__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_a 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__a_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_a 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__a_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_a 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__a_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_b 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__b_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_b 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__b_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_b 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__b_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_c 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__c_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_c 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__c_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_c 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__c_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_d 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__d_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_d 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__d_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_d 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__d_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_a)) 
              & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_a)) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_b)) 
                & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_b))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_c)) 
               & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_c))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_d)) 
              & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_d)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_a))) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_a)))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_b))) 
                & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_b))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_c))) 
               & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_c))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_d))) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_d)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_a)) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_a)))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_b)) 
                & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_b))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_c)) 
               & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_c))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_d)) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_d)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__x_mant 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x))) 
            << 0x1aU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_x 
                         << 3U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_y))) 
            << 0x1aU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_y 
                         << 3U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_mx))) 
            << 0x1aU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_mx 
                         << 3U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_nx))) 
            << 0x1aU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_nx 
                         << 3U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_y 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_y))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_m 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_m))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_n 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_n))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_x 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__x_mant;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_x 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c1 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_x 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s2 
        = (0x3fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1 
                           ^ VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c1, 1U)) 
                          ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c2 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1 
             & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c1, 1U)) 
            | (VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c1, 1U) 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__a_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__4__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__4__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__4__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__b_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__5__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__5__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__5__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__c_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__6__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__6__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__6__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__d_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__7__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__7__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__7__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_a 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__a_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_a 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__a_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_a 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__a_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_b 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__b_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_b 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__b_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_b 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__b_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_c 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__c_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_c 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__c_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_c 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__c_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_d 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__d_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_d 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__d_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_d 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__d_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_a)) 
              & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_a)) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_b)) 
                & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_b))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_c)) 
               & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_c))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_d)) 
              & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_d)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_a))) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_a)))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_b))) 
                & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_b))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_c))) 
               & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_c))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_d))) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_d)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_a)) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_a)))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_b)) 
                & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_b))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_c)) 
               & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_c))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_d)) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_d)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__x_mant 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x))) 
            << 0x1aU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_x 
                         << 3U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_y))) 
            << 0x1aU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_y 
                         << 3U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_mx))) 
            << 0x1aU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_mx 
                         << 3U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_nx))) 
            << 0x1aU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_nx 
                         << 3U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_y 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_y))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_m 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_m))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_n 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_n))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_x 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__x_mant;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_x 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c1 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_x 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s2 
        = (0x3fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1 
                           ^ VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c1, 1U)) 
                          ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c2 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1 
             & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c1, 1U)) 
            | (VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c1, 1U) 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1));
}
