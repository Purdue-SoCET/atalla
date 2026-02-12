// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd4_fp16_tb_softfloat.h for the primary calling header

#include "Vadd4_fp16_tb_softfloat__pch.h"
#include "Vadd4_fp16_tb_softfloat___024root.h"

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___eval_static(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___eval_static\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__add4_fp16_tb_softfloat__DOT__tb_clk__0 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__add4_fp16_tb_softfloat__DOT__tb_nrst__0 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_nrst;
}

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___eval_final(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___eval_final\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___dump_triggers__stl(Vadd4_fp16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vadd4_fp16_tb_softfloat___024root___eval_phase__stl(Vadd4_fp16_tb_softfloat___024root* vlSelf);

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___eval_settle(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___eval_settle\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vadd4_fp16_tb_softfloat___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 21, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vadd4_fp16_tb_softfloat___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___dump_triggers__stl(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___dump_triggers__stl\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___stl_sequent__TOP__0(Vadd4_fp16_tb_softfloat___024root* vlSelf);
VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root____Vm_traceActivitySetAll(Vadd4_fp16_tb_softfloat___024root* vlSelf);

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___eval_stl(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___eval_stl\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vadd4_fp16_tb_softfloat___024root___stl_sequent__TOP__0(vlSelf);
        Vadd4_fp16_tb_softfloat___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___stl_sequent__TOP__0(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___stl_sequent__TOP__0\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0 = 0;
    CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0 = 0;
    CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0 = 0;
    CData/*0:0*/ add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0 = 0;
    // Body
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_reg_st3 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_i;
    if ((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_right_shift_radix))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shifted_sum 
            = (0xfffffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_reg_st3) 
                           >> (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_right_shift_radix)));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_shifted_out 
            = (0U != ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_reg_st3) 
                      & (((IData)(1U) << (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_right_shift_radix)) 
                         - (IData)(1U))));
    } else {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shifted_sum 
            = (0xfffffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_reg_st3) 
                           << (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_num_leading_zeros)));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_shifted_out = 0U;
    }
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__unrounded_mantissa 
        = (0x3ffU & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shifted_sum 
                     >> 3U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__guard 
        = (1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shifted_sum 
                 >> 2U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round 
        = (1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shifted_sum 
                 >> 1U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky 
        = (1U & ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shifted_sum 
                  | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_shifted_out)) 
                 | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_alignment_sticky)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round_up 
        = ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__guard) 
           & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round) 
               | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky)) 
              | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__unrounded_mantissa)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mantissa_internal 
        = (0x7ffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__unrounded_mantissa) 
                     + (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round_up)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__overflow 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mantissa_internal) 
                 >> 0xaU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_mantissa 
        = ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__overflow)
            ? 0U : (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mantissa_internal)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__new_exponent_internal 
        = (0x7fU & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_a_e_out) 
                     + (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__overflow)) 
                    + VL_EXTENDS_II(7,4, (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_right_shift_radix))));
    if ((0U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_right_shift_radix))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__new_exponent_internal 
            = (0x7fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__new_exponent_internal) 
                        - VL_EXTENDS_II(7,6, (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_num_leading_zeros))));
    }
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__inf = 0U;
    if (VL_LTES_III(7, 0x1fU, (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__new_exponent_internal))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__inf = 1U;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__new_exponent = 0x1fU;
    } else {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__new_exponent 
            = (VL_GTES_III(32, 0U, VL_EXTENDS_II(32,7, (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__new_exponent_internal)))
                ? 0U : (0x1fU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__new_exponent_internal)));
    }
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_sum_next 
        = ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special_case)
            ? (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special_result)
            : ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__inf)
                ? (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_result_s) 
                    << 0xfU) | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__new_exponent) 
                                << 0xaU)) : (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_result_s) 
                                              << 0xfU) 
                                             | (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__new_exponent) 
                                                 << 0xaU) 
                                                | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_mantissa)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
        = (0x3fffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                      >> 1U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_raw 
        = (0x3fffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_y_f) 
                      >> 1U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_raw 
        = (0x3fffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_m_f) 
                      >> 1U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_raw 
        = (0x3fffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_n_f) 
                      >> 1U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext 
        = (0x3ffffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_b_op)
                        ? ((IData)(1U) + (0x38000U 
                                          | (0x7fffU 
                                             & (~ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_raw)))))
                        : (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_raw)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext 
        = (0x3ffffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_c_op)
                        ? ((IData)(1U) + (0x38000U 
                                          | (0x7fffU 
                                             & (~ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_raw)))))
                        : (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_raw)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext 
        = (0x3ffffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_d_op)
                        ? ((IData)(1U) + (0x38000U 
                                          | (0x7fffU 
                                             & (~ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_raw)))))
                        : (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_raw)));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0 
        = (1U & ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                  ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                 ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
        = ((0x3fffeU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1) 
           | (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                   & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                  | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                 | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
        = ((0x3fffeU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1) 
           | (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                  ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext) 
                 >> 1U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
        = ((0x3fffdU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0) 
              << 1U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                   | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext 
                      & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                  | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                 >> 1U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
        = ((0x3fffdU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0) 
              << 1U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                  ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext) 
                 >> 2U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
        = ((0x3fffbU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0) 
              << 2U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                   | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext 
                      & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                  | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                 >> 2U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
        = ((0x3fffbU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0) 
              << 2U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                  ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext) 
                 >> 3U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
        = ((0x3fff7U & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0) 
              << 3U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                   | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext 
                      & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                  | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                 >> 3U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
        = ((0x3fff7U & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0) 
              << 3U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                  ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext) 
                 >> 4U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
        = ((0x3ffefU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0) 
              << 4U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                   | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext 
                      & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                  | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                 >> 4U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
        = ((0x3ffefU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0) 
              << 4U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                  ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext) 
                 >> 5U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
        = ((0x3ffdfU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0) 
              << 5U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                   | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext 
                      & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                  | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                 >> 5U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
        = ((0x3ffdfU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0) 
              << 5U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                  ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext) 
                 >> 6U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
        = ((0x3ffbfU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0) 
              << 6U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                   | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext 
                      & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                  | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                 >> 6U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
        = ((0x3ffbfU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0) 
              << 6U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                  ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext) 
                 >> 7U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
        = ((0x3ff7fU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0) 
              << 7U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                   | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext 
                      & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                  | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                 >> 7U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
        = ((0x3ff7fU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0) 
              << 7U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                  ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext) 
                 >> 8U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
        = ((0x3feffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0) 
              << 8U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                   | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext 
                      & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                  | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                 >> 8U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
        = ((0x3feffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0) 
              << 8U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                  ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext) 
                 >> 9U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
        = ((0x3fdffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0) 
              << 9U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                   | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext 
                      & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                  | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                 >> 9U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
        = ((0x3fdffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0) 
              << 9U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                  ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext) 
                 >> 0xaU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
        = ((0x3fbffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0) 
              << 0xaU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                   | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext 
                      & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                  | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                 >> 0xaU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
        = ((0x3fbffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0) 
              << 0xaU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                  ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext) 
                 >> 0xbU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
        = ((0x3f7ffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0) 
              << 0xbU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                   | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext 
                      & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                  | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                 >> 0xbU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
        = ((0x3f7ffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0) 
              << 0xbU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                  ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext) 
                 >> 0xcU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
        = ((0x3efffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0) 
              << 0xcU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                   | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext 
                      & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                  | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                 >> 0xcU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
        = ((0x3efffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0) 
              << 0xcU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                  ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext) 
                 >> 0xdU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
        = ((0x3dfffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0) 
              << 0xdU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                   | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext 
                      & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                  | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                 >> 0xdU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
        = ((0x3dfffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0) 
              << 0xdU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                  ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext) 
                 >> 0xeU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
        = ((0x3bfffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0) 
              << 0xeU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                   | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext 
                      & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                  | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                 >> 0xeU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
        = ((0x3bfffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0) 
              << 0xeU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                  ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext) 
                 >> 0xfU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
        = ((0x37fffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0) 
              << 0xfU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                   | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext 
                      & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                  | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                 >> 0xfU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
        = ((0x37fffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0) 
              << 0xfU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                  ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext) 
                 >> 0x10U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
        = ((0x2ffffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0) 
              << 0x10U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                   | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext 
                      & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                  | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                 >> 0x10U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
        = ((0x2ffffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0) 
              << 0x10U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                  ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext) 
                 >> 0x11U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
        = ((0x1ffffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hae4cc29c__0) 
              << 0x11U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext) 
                   | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext 
                      & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                  | (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext)) 
                 >> 0x11U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
        = ((0x1ffffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_h5cd32dfc__0) 
              << 0x11U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk2__DOT__i = 0x12U;
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0 
        = (1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                 ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2 
        = ((0x3fffeU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2) 
           | (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0 
        = (1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                 & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2 
        = ((0x3fffeU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2) 
           | (IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val 
        = (1U & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1);
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                  >> 1U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2 
        = ((0x3fffdU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0) 
              << 1U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                   >> 1U) | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext 
                              >> 1U) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))) 
                 | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                     >> 1U) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2 
        = ((0x3fffdU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0) 
              << 1U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val 
        = (1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
                 >> 1U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                  >> 2U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2 
        = ((0x3fffbU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0) 
              << 2U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                   >> 2U) | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext 
                              >> 2U) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))) 
                 | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                     >> 2U) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2 
        = ((0x3fffbU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0) 
              << 2U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val 
        = (1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
                 >> 2U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                  >> 3U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2 
        = ((0x3fff7U & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0) 
              << 3U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                   >> 3U) | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext 
                              >> 3U) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))) 
                 | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                     >> 3U) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2 
        = ((0x3fff7U & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0) 
              << 3U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val 
        = (1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
                 >> 3U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                  >> 4U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2 
        = ((0x3ffefU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0) 
              << 4U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                   >> 4U) | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext 
                              >> 4U) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))) 
                 | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                     >> 4U) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2 
        = ((0x3ffefU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0) 
              << 4U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val 
        = (1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
                 >> 4U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                  >> 5U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2 
        = ((0x3ffdfU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0) 
              << 5U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                   >> 5U) | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext 
                              >> 5U) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))) 
                 | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                     >> 5U) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2 
        = ((0x3ffdfU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0) 
              << 5U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val 
        = (1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
                 >> 5U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                  >> 6U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2 
        = ((0x3ffbfU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0) 
              << 6U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                   >> 6U) | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext 
                              >> 6U) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))) 
                 | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                     >> 6U) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2 
        = ((0x3ffbfU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0) 
              << 6U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val 
        = (1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
                 >> 6U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                  >> 7U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2 
        = ((0x3ff7fU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0) 
              << 7U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                   >> 7U) | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext 
                              >> 7U) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))) 
                 | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                     >> 7U) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2 
        = ((0x3ff7fU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0) 
              << 7U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val 
        = (1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
                 >> 7U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                  >> 8U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2 
        = ((0x3feffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0) 
              << 8U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                   >> 8U) | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext 
                              >> 8U) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))) 
                 | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                     >> 8U) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2 
        = ((0x3feffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0) 
              << 8U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val 
        = (1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
                 >> 8U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                  >> 9U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2 
        = ((0x3fdffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0) 
              << 9U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                   >> 9U) | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext 
                              >> 9U) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))) 
                 | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                     >> 9U) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2 
        = ((0x3fdffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0) 
              << 9U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val 
        = (1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
                 >> 9U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                  >> 0xaU) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2 
        = ((0x3fbffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0) 
              << 0xaU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                   >> 0xaU) | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext 
                                >> 0xaU) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))) 
                 | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                     >> 0xaU) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2 
        = ((0x3fbffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0) 
              << 0xaU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val 
        = (1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
                 >> 0xaU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                  >> 0xbU) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2 
        = ((0x3f7ffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0) 
              << 0xbU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                   >> 0xbU) | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext 
                                >> 0xbU) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))) 
                 | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                     >> 0xbU) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2 
        = ((0x3f7ffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0) 
              << 0xbU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val 
        = (1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
                 >> 0xbU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                  >> 0xcU) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2 
        = ((0x3efffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0) 
              << 0xcU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                   >> 0xcU) | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext 
                                >> 0xcU) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))) 
                 | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                     >> 0xcU) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2 
        = ((0x3efffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0) 
              << 0xcU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val 
        = (1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
                 >> 0xcU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                  >> 0xdU) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2 
        = ((0x3dfffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0) 
              << 0xdU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                   >> 0xdU) | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext 
                                >> 0xdU) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))) 
                 | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                     >> 0xdU) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2 
        = ((0x3dfffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0) 
              << 0xdU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val 
        = (1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
                 >> 0xdU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                  >> 0xeU) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2 
        = ((0x3bfffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0) 
              << 0xeU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                   >> 0xeU) | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext 
                                >> 0xeU) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))) 
                 | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                     >> 0xeU) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2 
        = ((0x3bfffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0) 
              << 0xeU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val 
        = (1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
                 >> 0xeU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                  >> 0xfU) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2 
        = ((0x37fffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0) 
              << 0xfU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                   >> 0xfU) | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext 
                                >> 0xfU) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))) 
                 | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                     >> 0xfU) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2 
        = ((0x37fffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0) 
              << 0xfU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val 
        = (1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
                 >> 0xfU));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                  >> 0x10U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2 
        = ((0x2ffffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0) 
              << 0x10U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                   >> 0x10U) | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext 
                                 >> 0x10U) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))) 
                 | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                     >> 0x10U) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2 
        = ((0x2ffffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0) 
              << 0x10U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val 
        = (1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 
                 >> 0x10U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0 
        = (1U & (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                  >> 0x11U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2 
        = ((0x1ffffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hd6702ffa__0) 
              << 0x11U));
    add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0 
        = (1U & ((((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext) 
                   >> 0x11U) | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext 
                                 >> 0x11U) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))) 
                 | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 
                     >> 0x11U) & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2 
        = ((0x1ffffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2) 
           | ((IData)(add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vlvbound_hf7287d8e__0) 
              << 0x11U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__i = 0x12U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__magnitude_sum 
        = (0x3ffffU & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2 
                       + (0x3fffeU & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2 
                                      << 1U))));
    if ((0x20000U & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__magnitude_sum)) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__next_result_s 
            = (1U & (~ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s)));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__corrected_sum 
            = (0xffffU & ((IData)(1U) + (~ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__magnitude_sum)));
    } else {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__next_result_s 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__corrected_sum 
            = (0xffffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__magnitude_sum);
    }
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__next_right_shift_radix 
        = ((0x8000U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__corrected_sum))
            ? 2U : ((0x4000U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__corrected_sum))
                     ? 1U : 0U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__next_num_leading_zeros = 0xfU;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk5__DOT__k = 0xfU;
    {
        while (VL_LTES_III(32, 0U, vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk5__DOT__k)) {
            if ((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__corrected_sum) 
                       >> (0xfU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk5__DOT__k)))) {
                vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__next_num_leading_zeros 
                    = (VL_GTES_III(32, 0xdU, vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk5__DOT__k)
                        ? (0xfU & ((IData)(0xdU) - vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk5__DOT__k))
                        : 0U);
                goto __Vlabel1;
            }
            vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk5__DOT__k 
                = (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk5__DOT__k 
                   - (IData)(1U));
        }
        __Vlabel1: ;
    }
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
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y))) 
            << 0xeU) | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y) 
                        << 4U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx))) 
            << 0xeU) | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx) 
                        << 4U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx))) 
            << 0xeU) | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx) 
                        << 4U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted 
        = ((0xfU <= (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift))
            ? 0U : (0x7fffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base) 
                               >> (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted 
        = ((0xfU <= (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift))
            ? 0U : (0x7fffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base) 
                               >> (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted 
        = ((0xfU <= (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift))
            ? 0U : (0x7fffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base) 
                               >> (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_y 
        = ((0xfU <= (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift))
            ? (0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base))
            : (0U != ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base) 
                      & ([&]() {
                        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__get_sticky_mask__50__shift_amt 
                            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift;
                        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__get_sticky_mask__50__Vfuncout 
                            = (0x7fffU & (~ ((IData)(0x7fffU) 
                                             << (IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__get_sticky_mask__50__shift_amt))));
                    }(), (IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__get_sticky_mask__50__Vfuncout)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_m 
        = ((0xfU <= (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift))
            ? (0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base))
            : (0U != ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base) 
                      & ([&]() {
                        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__get_sticky_mask__51__shift_amt 
                            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift;
                        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__get_sticky_mask__51__Vfuncout 
                            = (0x7fffU & (~ ((IData)(0x7fffU) 
                                             << (IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__get_sticky_mask__51__shift_amt))));
                    }(), (IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__get_sticky_mask__51__Vfuncout)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_n 
        = ((0xfU <= (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift))
            ? (0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base))
            : (0U != ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base) 
                      & ([&]() {
                        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__get_sticky_mask__52__shift_amt 
                            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift;
                        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__get_sticky_mask__52__Vfuncout 
                            = (0x7fffU & (~ ((IData)(0x7fffU) 
                                             << (IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__get_sticky_mask__52__shift_amt))));
                    }(), (IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__get_sticky_mask__52__Vfuncout)))));
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

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___eval_triggers__stl(Vadd4_fp16_tb_softfloat___024root* vlSelf);

VL_ATTR_COLD bool Vadd4_fp16_tb_softfloat___024root___eval_phase__stl(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___eval_phase__stl\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vadd4_fp16_tb_softfloat___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vadd4_fp16_tb_softfloat___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___dump_triggers__act(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___dump_triggers__act\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge add4_fp16_tb_softfloat.tb_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge add4_fp16_tb_softfloat.tb_nrst)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(negedge add4_fp16_tb_softfloat.tb_clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___dump_triggers__nba(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___dump_triggers__nba\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge add4_fp16_tb_softfloat.tb_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge add4_fp16_tb_softfloat.tb_nrst)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(negedge add4_fp16_tb_softfloat.tb_clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root____Vm_traceActivitySetAll(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root____Vm_traceActivitySetAll\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
}

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___ctor_var_reset(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___ctor_var_reset\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->add4_fp16_tb_softfloat__DOT__tb_clk = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__tb_nrst = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__tb_a = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__tb_b = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__tb_c = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__tb_d = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__exp = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__pass_count = 0;
    vlSelf->add4_fp16_tb_softfloat__DOT__fail_count = 0;
    vlSelf->add4_fp16_tb_softfloat__DOT__fd = 0;
    vlSelf->add4_fp16_tb_softfloat__DOT__fail_fd = 0;
    vlSelf->add4_fp16_tb_softfloat__DOT__a = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__b = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__c = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__d = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__expected = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__ret = 0;
    vlSelf->add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__is_zero_result = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__total_count = 0;
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_y = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_mx = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_nx = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y_eff = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx_eff = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx_eff = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant = VL_RAND_RESET_I(15);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base = VL_RAND_RESET_I(15);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base = VL_RAND_RESET_I(15);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base = VL_RAND_RESET_I(15);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted = VL_RAND_RESET_I(15);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted = VL_RAND_RESET_I(15);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted = VL_RAND_RESET_I(15);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_y = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_m = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_n = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_a = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_b = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_c = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_d = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_inf_a = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_inf_b = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_inf_c = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__is_inf_d = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_b_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_c_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_d_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_e = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f = VL_RAND_RESET_I(15);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_y_f = VL_RAND_RESET_I(15);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_m_f = VL_RAND_RESET_I(15);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_n_f = VL_RAND_RESET_I(15);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_alignment_sticky = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_case = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_result = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_ext = VL_RAND_RESET_I(18);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_ext = VL_RAND_RESET_I(18);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_ext = VL_RAND_RESET_I(18);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_ext = VL_RAND_RESET_I(18);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s1 = VL_RAND_RESET_I(18);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c1 = VL_RAND_RESET_I(18);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__s2 = VL_RAND_RESET_I(18);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c2 = VL_RAND_RESET_I(18);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__magnitude_sum = VL_RAND_RESET_I(18);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__corrected_sum = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__next_result_s = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__next_num_leading_zeros = VL_RAND_RESET_I(4);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__next_right_shift_radix = VL_RAND_RESET_I(2);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_i = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_alignment_sticky = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_result_s = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_a_e_out = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_num_leading_zeros = VL_RAND_RESET_I(4);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_right_shift_radix = VL_RAND_RESET_I(2);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special_case = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special_result = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__b_raw = VL_RAND_RESET_I(15);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__c_raw = VL_RAND_RESET_I(15);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__d_raw = VL_RAND_RESET_I(15);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_reg_st3 = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__shifted_sum = VL_RAND_RESET_I(20);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__unrounded_mantissa = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mantissa_internal = VL_RAND_RESET_I(11);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__guard = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_shifted_out = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round_up = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__overflow = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_mantissa = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__new_exponent_internal = VL_RAND_RESET_I(7);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__new_exponent = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__inf = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_sum_next = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage1_combinational__DOT__unnamedblk1__DOT__has_pos_inf = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage1_combinational__DOT__unnamedblk1__DOT__has_neg_inf = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__i = 0;
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk3__DOT__unnamedblk4__DOT__c_val = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_combinational__DOT__unnamedblk5__DOT__k = 0;
    vlSelf->__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__get_sticky_mask__50__Vfuncout = VL_RAND_RESET_I(15);
    vlSelf->__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__get_sticky_mask__50__shift_amt = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__get_sticky_mask__51__Vfuncout = VL_RAND_RESET_I(15);
    vlSelf->__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__get_sticky_mask__51__shift_amt = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__get_sticky_mask__52__Vfuncout = VL_RAND_RESET_I(15);
    vlSelf->__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__get_sticky_mask__52__shift_amt = VL_RAND_RESET_I(5);
    vlSelf->__Vtrigprevexpr___TOP__add4_fp16_tb_softfloat__DOT__tb_clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__add4_fp16_tb_softfloat__DOT__tb_nrst__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
