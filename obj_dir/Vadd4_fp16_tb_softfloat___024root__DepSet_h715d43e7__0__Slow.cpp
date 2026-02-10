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
            VL_FATAL_MT("tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 17, "", "Settle region did not converge.");
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
    SData/*14:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__Vfuncout = 0;
    SData/*14:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__mant;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__mant = 0;
    CData/*4:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__shift_amt;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__shift_amt = 0;
    SData/*14:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__Vfuncout = 0;
    SData/*14:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__mant;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__mant = 0;
    CData/*4:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__shift_amt;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__shift_amt = 0;
    SData/*14:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__Vfuncout = 0;
    SData/*14:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__mant;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__mant = 0;
    CData/*4:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__shift_amt;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__shift_amt = 0;
    // Body
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__signed_sb_sum = 0U;
    if ((1U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_y_f))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__signed_sb_sum 
            = (7U & (VL_EXTENDS_II(3,3, (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__signed_sb_sum)) 
                     + ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_b_op)
                         ? 0xffffffffU : 1U)));
    }
    if ((1U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_m_f))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__signed_sb_sum 
            = (7U & (VL_EXTENDS_II(3,3, (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__signed_sb_sum)) 
                     + ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_c_op)
                         ? 0xffffffffU : 1U)));
    }
    if ((1U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_n_f))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__signed_sb_sum 
            = (7U & (VL_EXTENDS_II(3,3, (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__signed_sb_sum)) 
                     + ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_d_op)
                         ? 0xffffffffU : 1U)));
    }
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__shifted_sum 
        = (0x3fffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__sum_reg));
    if ((2U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__right_shift_reg))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__shifted_sum 
            = (0x3fffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__sum_reg) 
                          >> 2U));
    } else if ((1U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__right_shift_reg))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__shifted_sum 
            = (0x3fffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__sum_reg) 
                          >> 1U));
    } else {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__shifted_sum 
            = (0x3fffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__sum_reg) 
                          << (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__leading_zeros_reg)));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__shifted_sum 
            = ((0x3ffeU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__shifted_sum)) 
               | ((3U > (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__leading_zeros_reg)) 
                  & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__sum_reg)));
    }
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2 
        = ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_d_op)
            ? ((IData)(1U) + (~ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_n_f)))
            : (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_n_f));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__a_daz 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a;
    if ((IData)(((0U == (0x7c00U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a))) 
                 & (0U != (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a)))))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__a_daz 
            = (0x8000U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__a_daz));
    }
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__b_daz 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b;
    if ((IData)(((0U == (0x7c00U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b))) 
                 & (0U != (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b)))))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__b_daz 
            = (0x8000U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__b_daz));
    }
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__c_daz 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c;
    if ((IData)(((0U == (0x7c00U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c))) 
                 & (0U != (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c)))))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__c_daz 
            = (0x8000U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__c_daz));
    }
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__d_daz 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d;
    if ((IData)(((0U == (0x7c00U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d))) 
                 & (0U != (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d)))))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__d_daz 
            = (0x8000U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__d_daz));
    }
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_a 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__a_daz) 
                    >> 0xaU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_a 
        = (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__a_daz));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_b 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__b_daz) 
                    >> 0xaU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_b 
        = (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__b_daz));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_c 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__c_daz) 
                    >> 0xaU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_c 
        = (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__c_daz));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_d 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__d_daz) 
                    >> 0xaU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_d 
        = (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__d_daz));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__special_case = 0U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__special_result = 0U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_nan_a 
        = ((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_a)) 
           & (0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_a)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_nan_b 
        = ((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_b)) 
           & (0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_b)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_nan_c 
        = ((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_c)) 
           & (0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_c)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_nan_d 
        = ((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_d)) 
           & (0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_d)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_a 
        = ((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_a)) 
           & (0U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_a)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_b 
        = ((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_b)) 
           & (0U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_b)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_c 
        = ((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_c)) 
           & (0U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_c)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_d 
        = ((0x1fU == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_d)) 
           & (0U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_d)));
    if (((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_nan_a) 
           | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_nan_b)) 
          | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_nan_c)) 
         | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_nan_d))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__special_case = 1U;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__special_result = 0x7e00U;
    } else if (((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_a) 
                  | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_b)) 
                 | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_c)) 
                | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_d))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__unnamedblk1__DOT__has_pos_inf 
            = (((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_a) 
                  & (~ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_a))) 
                 | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_b) 
                    & (~ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_b)))) 
                | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_c) 
                   & (~ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_c)))) 
               | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_d) 
                  & (~ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_d))));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__unnamedblk1__DOT__has_neg_inf 
            = (((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_a) 
                  & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_a)) 
                 | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_b) 
                    & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_b))) 
                | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_c) 
                   & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_c))) 
               | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_d) 
                  & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_d)));
        if (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__unnamedblk1__DOT__has_pos_inf) 
             & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__unnamedblk1__DOT__has_neg_inf))) {
            vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__special_case = 1U;
            vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__special_result = 0x7e00U;
        } else if (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__unnamedblk1__DOT__has_pos_inf) {
            vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__special_case = 1U;
            vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__special_result = 0x7c00U;
        } else {
            vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__special_case = 1U;
            vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__special_result = 0xfc00U;
        }
    }
    if (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_a) 
         >= (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_b))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_p 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_a;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_p 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_a;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_p 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_a;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_m 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_b;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_m 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_b;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_m 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_b;
    } else {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_p 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_b;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_p 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_b;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_p 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_b;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_m 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_a;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_m 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_a;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_m 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_c) 
         >= (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_d))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_r 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_c;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_r 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_c;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_r 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_c;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_n 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_d;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_n 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_d;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_n 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_d;
    } else {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_r 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_d;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_r 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_d;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_r 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_d;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_n 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_c;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_n 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_c;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_n 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_p) 
         >= (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_r))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_x 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_p;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_x 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_p;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_x 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_p;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_y 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_r;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_y 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_r;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_y 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_r;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_mx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_m;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_mx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_m;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_mx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_m;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_nx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_n;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_nx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_n;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_nx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_n;
    } else {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_x 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_r;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_x 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_r;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_x 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_r;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_y 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_p;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_y 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_p;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_y 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_p;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_mx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_n;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_mx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_n;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_mx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_n;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_nx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_m;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_nx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_m;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_nx 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_m;
    }
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__y_shift 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_x) 
                    - (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_y)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__m_shift 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_x) 
                    - (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_mx)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__n_shift 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_x) 
                    - (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_nx)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__x_mant 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_x))) 
            << 0xeU) | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_x) 
                        << 4U));
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__shift_amt 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__y_shift;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__mant 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_y))) 
            << 0xeU) | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_y) 
                        << 4U));
    vlSelf->__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__result = VL_RAND_RESET_I(15);
    vlSelf->__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__sticky = VL_RAND_RESET_I(1);
    if ((0U == (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__shift_amt))) {
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__result 
            = __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__mant;
    } else if ((0xfU <= (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__shift_amt))) {
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__result = 0U;
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__result 
            = ((0x7ffeU & (IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__result)) 
               | (0U != (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__mant)));
    } else {
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__result 
            = (0x7fffU & ((IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__mant) 
                          >> (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__shift_amt)));
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__sticky 
            = (0U != ((IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__mant) 
                      & (((IData)(1U) << (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__shift_amt)) 
                         - (IData)(1U))));
        if ((1U & ((IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__sticky) 
                   | (IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__result)))) {
            vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__result 
                = (1U | (IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__result));
        }
    }
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__Vfuncout 
        = vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__result;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__y_shifted 
        = __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__shift_amt 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__m_shift;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__mant 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_mx))) 
            << 0xeU) | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_mx) 
                        << 4U));
    vlSelf->__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__result = VL_RAND_RESET_I(15);
    vlSelf->__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__sticky = VL_RAND_RESET_I(1);
    if ((0U == (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__shift_amt))) {
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__result 
            = __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__mant;
    } else if ((0xfU <= (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__shift_amt))) {
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__result = 0U;
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__result 
            = ((0x7ffeU & (IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__result)) 
               | (0U != (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__mant)));
    } else {
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__result 
            = (0x7fffU & ((IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__mant) 
                          >> (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__shift_amt)));
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__sticky 
            = (0U != ((IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__mant) 
                      & (((IData)(1U) << (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__shift_amt)) 
                         - (IData)(1U))));
        if ((1U & ((IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__sticky) 
                   | (IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__result)))) {
            vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__result 
                = (1U | (IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__result));
        }
    }
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__Vfuncout 
        = vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__result;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__m_shifted 
        = __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__shift_amt 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__n_shift;
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__mant 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_nx))) 
            << 0xeU) | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_nx) 
                        << 4U));
    vlSelf->__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__result = VL_RAND_RESET_I(15);
    vlSelf->__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__sticky = VL_RAND_RESET_I(1);
    if ((0U == (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__shift_amt))) {
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__result 
            = __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__mant;
    } else if ((0xfU <= (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__shift_amt))) {
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__result = 0U;
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__result 
            = ((0x7ffeU & (IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__result)) 
               | (0U != (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__mant)));
    } else {
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__result 
            = (0x7fffU & ((IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__mant) 
                          >> (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__shift_amt)));
        vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__sticky 
            = (0U != ((IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__mant) 
                      & (((IData)(1U) << (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__shift_amt)) 
                         - (IData)(1U))));
        if ((1U & ((IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__sticky) 
                   | (IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__result)))) {
            vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__result 
                = (1U | (IData)(vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__result));
        }
    }
    __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__Vfuncout 
        = vlSelfRef.__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__result;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__n_shifted 
        = __Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__Vfuncout;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__y_op 
        = ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_y));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__m_op 
        = ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_mx));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__n_op 
        = ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_nx));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
        = ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_b_op)
            ? ((IData)(1U) + (~ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_y_f)))
            : (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_y_f));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1 
        = ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_c_op)
            ? ((IData)(1U) + (~ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_m_f)))
            : (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_m_f));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__rounded_mantissa_internal 
        = (0x3fffU & ((0x1ffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__shifted_sum) 
                                 >> 4U)) + (1U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__shifted_sum) 
                                                   >> 3U) 
                                                  & (IData)(
                                                            (0U 
                                                             != 
                                                             (0x17U 
                                                              & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__shifted_sum))))))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__15__KET____DOT__fa_1__sum 
        = (1U & ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                  ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1) 
                 >> 0xfU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__14__KET____DOT__fa_1__sum 
        = (1U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                  ^ (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                     ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 0xeU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__13__KET____DOT__fa_1__sum 
        = (1U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                  ^ (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                     ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 0xdU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__sum 
        = (1U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                  ^ (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                     ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 0xcU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__sum 
        = (1U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                  ^ (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                     ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 0xbU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__sum 
        = (1U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                  ^ (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                     ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 0xaU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__sum 
        = (1U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                  ^ (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                     ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 9U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__sum 
        = (1U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                  ^ (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                     ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 8U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__sum 
        = (1U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                  ^ (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                     ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 7U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__sum 
        = (1U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                  ^ (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                     ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 6U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__sum 
        = (1U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                  ^ (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                     ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 5U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__sum 
        = (1U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                  ^ (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                     ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 4U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__sum 
        = (1U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                  ^ (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                     ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 3U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__sum 
        = (1U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                  ^ (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                     ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 2U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__sum 
        = (1U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                  ^ (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                     ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 1U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__s1__BRA__0__KET__ 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                 ^ (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                    ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__14__KET____DOT__fa_1__co 
        = (1U & ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                   & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0) 
                  | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                      | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f)) 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 0xeU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__13__KET____DOT__fa_1__co 
        = (1U & ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                   & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0) 
                  | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                      | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f)) 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 0xdU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__co 
        = (1U & ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                   & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0) 
                  | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                      | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f)) 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 0xcU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__co 
        = (1U & ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                   & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0) 
                  | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                      | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f)) 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 0xbU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__co 
        = (1U & ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                   & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0) 
                  | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                      | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f)) 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 0xaU));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__co 
        = (1U & ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                   & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0) 
                  | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                      | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f)) 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 9U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__co 
        = (1U & ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                   & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0) 
                  | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                      | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f)) 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 8U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__co 
        = (1U & ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                   & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0) 
                  | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                      | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f)) 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 7U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__co 
        = (1U & ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                   & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0) 
                  | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                      | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f)) 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 6U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__co 
        = (1U & ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                   & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0) 
                  | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                      | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f)) 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 5U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__co 
        = (1U & ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                   & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0) 
                  | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                      | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f)) 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 4U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__co 
        = (1U & ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                   & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0) 
                  | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                      | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f)) 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 3U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__co 
        = (1U & ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                   & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0) 
                  | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                      | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f)) 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 2U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__co 
        = (1U & ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                   & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0) 
                  | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                      | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f)) 
                     & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)) 
                 >> 1U));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c1__BRA__0__KET__ 
        = (1U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                  & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0) 
                 | ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 
                     | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f)) 
                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__new_exponent_internal 
        = (0x7fU & ((((0xffU & VL_EXTENDS_II(8,7, (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__exponent_reg))) 
                      + (0xffU & VL_EXTENDS_II(8,7, 
                                               (1U 
                                                & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__rounded_mantissa_internal) 
                                                   >> 0xdU))))) 
                     - (0xffU & VL_EXTENDS_II(8,6, (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__leading_zeros_reg)))) 
                    + (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__right_shift_reg)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__s2 
        = ((0x10000U & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__s2) 
           | (((((0x8000U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__15__KET____DOT__fa_1__sum) 
                              << 0xfU) ^ ((0xffff8000U 
                                           & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                                          ^ ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__14__KET____DOT__fa_1__co) 
                                             << 0xfU)))) 
                 | (0x4000U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__14__KET____DOT__fa_1__sum) 
                                << 0xeU) ^ ((0xffffc000U 
                                             & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                                            ^ ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__13__KET____DOT__fa_1__co) 
                                               << 0xeU))))) 
                | ((0x2000U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__13__KET____DOT__fa_1__sum) 
                                << 0xdU) ^ ((0xffffe000U 
                                             & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                                            ^ ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__co) 
                                               << 0xdU)))) 
                   | (0x1000U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__sum) 
                                  << 0xcU) ^ ((0xfffff000U 
                                               & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                                              ^ ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__co) 
                                                 << 0xcU)))))) 
               | (((0x800U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__sum) 
                               << 0xbU) ^ ((0xfffff800U 
                                            & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                                           ^ ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__co) 
                                              << 0xbU)))) 
                   | (0x400U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__sum) 
                                 << 0xaU) ^ ((0xfffffc00U 
                                              & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                                             ^ ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__co) 
                                                << 0xaU))))) 
                  | ((0x200U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__sum) 
                                 << 9U) ^ ((0xfffffe00U 
                                            & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                                           ^ ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__co) 
                                              << 9U)))) 
                     | (0x100U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__sum) 
                                   << 8U) ^ ((0xffffff00U 
                                              & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                                             ^ ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__co) 
                                                << 8U))))))) 
              | ((((0x80U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__sum) 
                              << 7U) ^ ((0xffffff80U 
                                         & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                                        ^ ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__co) 
                                           << 7U)))) 
                   | (0x40U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__sum) 
                                << 6U) ^ ((0xffffffc0U 
                                           & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                                          ^ ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__co) 
                                             << 6U))))) 
                  | ((0x20U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__sum) 
                                << 5U) ^ ((0xffffffe0U 
                                           & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                                          ^ ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__co) 
                                             << 5U)))) 
                     | (0x10U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__sum) 
                                  << 4U) ^ ((0xfffffff0U 
                                             & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                                            ^ ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__co) 
                                               << 4U)))))) 
                 | (((8U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__sum) 
                             << 3U) ^ ((0xfffffff8U 
                                        & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                                       ^ ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__co) 
                                          << 3U)))) 
                     | (4U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__sum) 
                               << 2U) ^ ((0xfffffffcU 
                                          & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                                         ^ ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__co) 
                                            << 2U))))) 
                    | ((2U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__sum) 
                               << 1U) ^ ((0xfffffffeU 
                                          & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                                         ^ ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c1__BRA__0__KET__) 
                                            << 1U)))) 
                       | (1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__s1__BRA__0__KET__) 
                                ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2)))))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c2 
        = ((0x10000U & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c2) 
           | ((((((0xffff8000U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__15__KET____DOT__fa_1__sum) 
                                   << 0xfU) & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2)) 
                  | (((0xffff8000U & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                      | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__15__KET____DOT__fa_1__sum) 
                         << 0xfU)) & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__14__KET____DOT__fa_1__co) 
                                      << 0xfU))) | 
                 ((0xffffc000U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__14__KET____DOT__fa_1__sum) 
                                   << 0xeU) & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2)) 
                  | (((0xffffc000U & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                      | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__14__KET____DOT__fa_1__sum) 
                         << 0xeU)) & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__13__KET____DOT__fa_1__co) 
                                      << 0xeU)))) | 
                (((0xffffe000U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__13__KET____DOT__fa_1__sum) 
                                   << 0xdU) & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2)) 
                  | (((0xffffe000U & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                      | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__13__KET____DOT__fa_1__sum) 
                         << 0xdU)) & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__co) 
                                      << 0xdU))) | 
                 ((0xfffff000U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__sum) 
                                   << 0xcU) & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2)) 
                  | (((0xfffff000U & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                      | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__sum) 
                         << 0xcU)) & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__co) 
                                      << 0xcU))))) 
               | ((((0xfffff800U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__sum) 
                                     << 0xbU) & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2)) 
                    | (((0xfffff800U & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                        | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__sum) 
                           << 0xbU)) & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__co) 
                                        << 0xbU))) 
                   | ((0xfffffc00U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__sum) 
                                       << 0xaU) & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2)) 
                      | (((0xfffffc00U & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                          | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__sum) 
                             << 0xaU)) & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__co) 
                                          << 0xaU)))) 
                  | (((0xfffffe00U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__sum) 
                                       << 9U) & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2)) 
                      | (((0xfffffe00U & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                          | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__sum) 
                             << 9U)) & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__co) 
                                        << 9U))) | 
                     ((0xffffff00U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__sum) 
                                       << 8U) & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2)) 
                      | (((0xffffff00U & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                          | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__sum) 
                             << 8U)) & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__co) 
                                        << 8U)))))) 
              | (((((0xffffff80U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__sum) 
                                     << 7U) & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2)) 
                    | (((0xffffff80U & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                        | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__sum) 
                           << 7U)) & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__co) 
                                      << 7U))) | ((0xffffffc0U 
                                                   & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__sum) 
                                                       << 6U) 
                                                      & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2)) 
                                                  | (((0xffffffc0U 
                                                       & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                                                      | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__sum) 
                                                         << 6U)) 
                                                     & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__co) 
                                                        << 6U)))) 
                  | (((0xffffffe0U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__sum) 
                                       << 5U) & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2)) 
                      | (((0xffffffe0U & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                          | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__sum) 
                             << 5U)) & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__co) 
                                        << 5U))) | 
                     ((0xfffffff0U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__sum) 
                                       << 4U) & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2)) 
                      | (((0xfffffff0U & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                          | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__sum) 
                             << 4U)) & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__co) 
                                        << 4U))))) 
                 | ((((0xfffffff8U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__sum) 
                                       << 3U) & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2)) 
                      | (((0xfffffff8U & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                          | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__sum) 
                             << 3U)) & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__co) 
                                        << 3U))) | 
                     ((0xfffffffcU & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__sum) 
                                       << 2U) & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2)) 
                      | (((0xfffffffcU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                          | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__sum) 
                             << 2U)) & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__co) 
                                        << 2U)))) | 
                    (((0xfffffffeU & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__sum) 
                                       << 1U) & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2)) 
                      | (((0xfffffffeU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2) 
                          | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__sum) 
                             << 1U)) & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c1__BRA__0__KET__) 
                                        << 1U))) | 
                     ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__s1__BRA__0__KET__) 
                      & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2))))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__inf = 0U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__new_exponent 
        = (0x1fU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__new_exponent_internal));
    if (VL_LTES_III(7, 0x1fU, (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__new_exponent_internal))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__inf = 1U;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__new_exponent = 0x1fU;
    } else if (VL_GTES_III(32, 0U, VL_EXTENDS_II(32,7, (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__new_exponent_internal)))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__new_exponent = 0U;
    }
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__magnitude_sum 
        = (0x1ffffU & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__s2 
                       + (VL_SHIFTL_III(17,17,32, vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c2, 1U) 
                          + (0x3ffffU & VL_EXTENDS_II(18,15, 
                                                      (1U 
                                                       & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_b_op) 
                                                          + 
                                                          ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_c_op) 
                                                           + (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_d_op)))))))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__next_result_s 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s) 
                 ^ (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__magnitude_sum 
                    >> 0x10U)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_3 
        = (0x1ffffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__next_result_s)
                        ? (- vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__magnitude_sum)
                        : vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__magnitude_sum));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__right_shifts = 0U;
    if ((0x8000U & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_3)) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__right_shifts = 2U;
    } else if ((0x4000U & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_3)) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__right_shifts = 1U;
    }
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__next_num_leading_zeros = 0xfU;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__unnamedblk1__DOT__k = 0xfU;
    {
        while (VL_LTES_III(32, 0U, vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__unnamedblk1__DOT__k)) {
            if ((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_3 
                       >> (0xfU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__unnamedblk1__DOT__k)))) {
                vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__next_num_leading_zeros 
                    = (VL_LTS_III(32, 0xfU, ((IData)(0xfU) 
                                             - vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__unnamedblk1__DOT__k))
                        ? 0xfU : (0xfU & ((IData)(0xfU) 
                                          - vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__unnamedblk1__DOT__k)));
                goto __Vlabel1;
            }
            vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__unnamedblk1__DOT__k 
                = (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__unnamedblk1__DOT__k 
                   - (IData)(1U));
        }
        __Vlabel1: ;
    }
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
    vlSelf->add4_fp16_tb_softfloat__DOT__a = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__b = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__c = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__d = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__expected = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__ret = 0;
    vlSelf->add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__is_zero_result = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__total_count = 0;
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_b_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_c_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_d_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_e = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f = VL_RAND_RESET_I(15);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_y_f = VL_RAND_RESET_I(15);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_m_f = VL_RAND_RESET_I(15);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_n_f = VL_RAND_RESET_I(15);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_case = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_result = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special_case = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special_result = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__right_shifts = VL_RAND_RESET_I(2);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_i = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__result_s = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_e_out = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__num_leading_zeros = VL_RAND_RESET_I(4);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__a_daz = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__b_daz = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__c_daz = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__d_daz = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_a = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_b = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_c = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_d = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_a = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_b = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_c = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_d = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_a = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_b = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_c = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_d = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_p = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_m = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_r = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_n = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_x = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_y = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_mx = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_nx = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_p = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_m = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_r = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_n = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_x = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_y = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_mx = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_nx = VL_RAND_RESET_I(10);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_p = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_m = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_r = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_n = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_x = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_y = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_mx = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_nx = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__y_shift = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__m_shift = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__n_shift = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__x_mant = VL_RAND_RESET_I(15);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__y_shifted = VL_RAND_RESET_I(15);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__m_shifted = VL_RAND_RESET_I(15);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__n_shifted = VL_RAND_RESET_I(15);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__y_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__m_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__n_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_nan_a = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_nan_b = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_nan_c = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_nan_d = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_a = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_b = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_c = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_d = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__special_case = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__special_result = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__unnamedblk1__DOT__has_pos_inf = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__unnamedblk1__DOT__has_neg_inf = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__s1__BRA__16__KET__ = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__s1__BRA__0__KET__ = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c1__BRA__16__KET__ = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c1__BRA__0__KET__ = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__s2 = VL_RAND_RESET_I(17);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c2 = VL_RAND_RESET_I(17);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__signed_sb_sum = VL_RAND_RESET_I(3);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__next_result_s = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__next_num_leading_zeros = VL_RAND_RESET_I(4);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__magnitude_sum = VL_RAND_RESET_I(17);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__co = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__sum = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__co = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__sum = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__co = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__sum = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__co = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__sum = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__co = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__sum = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__co = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__sum = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__co = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__sum = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__co = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__sum = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__co = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__sum = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__co = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__sum = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__co = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__sum = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__co = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__sum = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__13__KET____DOT__fa_1__co = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__13__KET____DOT__fa_1__sum = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__14__KET____DOT__fa_1__co = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__14__KET____DOT__fa_1__sum = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__15__KET____DOT__fa_1__sum = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__unnamedblk1__DOT__k = 0;
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0 = VL_RAND_RESET_I(32);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_1 = VL_RAND_RESET_I(32);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_2 = VL_RAND_RESET_I(32);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_3 = VL_RAND_RESET_I(17);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__shifted_sum = VL_RAND_RESET_I(14);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__sum_reg = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__leading_zeros_reg = VL_RAND_RESET_I(4);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__sign_reg = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__exponent_reg = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__special_case_reg = VL_RAND_RESET_I(1);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__special_result_reg = VL_RAND_RESET_I(16);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__right_shift_reg = VL_RAND_RESET_I(2);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__rounded_mantissa_internal = VL_RAND_RESET_I(14);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__new_exponent_internal = VL_RAND_RESET_I(7);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__new_exponent = VL_RAND_RESET_I(5);
    vlSelf->add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__inf = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__result = VL_RAND_RESET_I(15);
    vlSelf->__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__50__sticky = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__result = VL_RAND_RESET_I(15);
    vlSelf->__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__51__sticky = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__result = VL_RAND_RESET_I(15);
    vlSelf->__Vfunc_add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__shift_right_sticky__52__sticky = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__add4_fp16_tb_softfloat__DOT__tb_clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__add4_fp16_tb_softfloat__DOT__tb_nrst__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
