// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd4_fp32_tb_softfloat.h for the primary calling header

#include "Vadd4_fp32_tb_softfloat__pch.h"
#include "Vadd4_fp32_tb_softfloat___024root.h"

VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root___eval_static(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root___eval_static\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__add4_fp32_tb_softfloat__DOT__tb_clk__0 
        = vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__add4_fp32_tb_softfloat__DOT__tb_nrst__0 
        = vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_nrst;
}

VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root___eval_final(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root___eval_final\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root___dump_triggers__stl(Vadd4_fp32_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vadd4_fp32_tb_softfloat___024root___eval_phase__stl(Vadd4_fp32_tb_softfloat___024root* vlSelf);

VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root___eval_settle(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root___eval_settle\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vadd4_fp32_tb_softfloat___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb/unit/systolic_array/add4_fp32_tb_softfloat.sv", 21, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vadd4_fp32_tb_softfloat___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root___dump_triggers__stl(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root___dump_triggers__stl\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root___stl_sequent__TOP__0(Vadd4_fp32_tb_softfloat___024root* vlSelf);
VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root____Vm_traceActivitySetAll(Vadd4_fp32_tb_softfloat___024root* vlSelf);

VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root___eval_stl(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root___eval_stl\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vadd4_fp32_tb_softfloat___024root___stl_sequent__TOP__0(vlSelf);
        Vadd4_fp32_tb_softfloat___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root___stl_sequent__TOP__0(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root___stl_sequent__TOP__0\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_5;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_8;
    VlWide<3>/*95:0*/ __Vtemp_9;
    VlWide<3>/*95:0*/ __Vtemp_10;
    VlWide<3>/*95:0*/ __Vtemp_12;
    VlWide<3>/*95:0*/ __Vtemp_14;
    VlWide<3>/*95:0*/ __Vtemp_15;
    VlWide<3>/*95:0*/ __Vtemp_21;
    VlWide<3>/*95:0*/ __Vtemp_26;
    VlWide<3>/*95:0*/ __Vtemp_29;
    VlWide<3>/*95:0*/ __Vtemp_34;
    VlWide<3>/*95:0*/ __Vtemp_37;
    VlWide<3>/*95:0*/ __Vtemp_42;
    VlWide<3>/*95:0*/ __Vtemp_45;
    VlWide<3>/*95:0*/ __Vtemp_50;
    VlWide<3>/*95:0*/ __Vtemp_53;
    VlWide<3>/*95:0*/ __Vtemp_58;
    VlWide<3>/*95:0*/ __Vtemp_61;
    VlWide<3>/*95:0*/ __Vtemp_66;
    VlWide<3>/*95:0*/ __Vtemp_69;
    VlWide<3>/*95:0*/ __Vtemp_74;
    VlWide<3>/*95:0*/ __Vtemp_76;
    VlWide<3>/*95:0*/ __Vtemp_84;
    VlWide<3>/*95:0*/ __Vtemp_87;
    VlWide<3>/*95:0*/ __Vtemp_88;
    VlWide<3>/*95:0*/ __Vtemp_93;
    VlWide<3>/*95:0*/ __Vtemp_96;
    VlWide<3>/*95:0*/ __Vtemp_97;
    VlWide<3>/*95:0*/ __Vtemp_102;
    VlWide<3>/*95:0*/ __Vtemp_105;
    VlWide<3>/*95:0*/ __Vtemp_106;
    VlWide<3>/*95:0*/ __Vtemp_130;
    VlWide<3>/*95:0*/ __Vtemp_133;
    VlWide<3>/*95:0*/ __Vtemp_135;
    // Body
    if ((0U != ((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag[0U] 
                 | vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag[1U]) 
                | vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag[2U]))) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    VL_EXTENDS_WW(79,78, __Vtemp_3, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_sum_vec);
    VL_SHIFTL_WWI(78,78,32, __Vtemp_5, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_carry_vec, 1U);
    __Vtemp_6[0U] = __Vtemp_5[0U];
    __Vtemp_6[1U] = __Vtemp_5[1U];
    __Vtemp_6[2U] = (0x3fffU & __Vtemp_5[2U]);
    VL_EXTENDS_WW(79,78, __Vtemp_7, __Vtemp_6);
    VL_ADD_W(3, __Vtemp_8, __Vtemp_3, __Vtemp_7);
    __Vtemp_9[0U] = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_hot_ones;
    __Vtemp_9[1U] = 0U;
    __Vtemp_9[2U] = 0U;
    VL_ADD_W(3, __Vtemp_10, __Vtemp_8, __Vtemp_9);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum[0U] 
        = __Vtemp_10[0U];
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum[1U] 
        = __Vtemp_10[1U];
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum[2U] 
        = (0x7fffU & __Vtemp_10[2U]);
    if ((0x2000U & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum[2U])) {
        __Vtemp_12[0U] = 1U;
        __Vtemp_12[1U] = 0U;
        __Vtemp_12[2U] = 0U;
        __Vtemp_14[0U] = (~ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum[0U]);
        __Vtemp_14[1U] = (~ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum[1U]);
        __Vtemp_14[2U] = (~ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum[2U]);
        VL_ADD_W(3, __Vtemp_15, __Vtemp_12, __Vtemp_14);
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum[0U] 
            = __Vtemp_15[0U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum[1U] 
            = __Vtemp_15[1U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum[2U] 
            = (0x1fffU & __Vtemp_15[2U]);
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s)));
    } else {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum[0U] 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum[0U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum[1U] 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum[1U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum[2U] 
            = (0x1fffU & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum[2U]);
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__res_sign 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s;
    }
    if ((0U == ((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag[0U] 
                 | vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag[1U]) 
                | vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag[2U]))) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[0U] = 0U;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[1U] = 0U;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[2U] = 0U;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros = 0x4cU;
    } else {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[0U] 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag[0U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[1U] 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag[1U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[2U] 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag[2U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros = 0U;
        VL_SHIFTR_WWI(77,77,32, __Vtemp_21, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0xdU);
        if ((0U == ((__Vtemp_21[0U] | __Vtemp_21[1U]) 
                    | (0x1fffU & __Vtemp_21[2U])))) {
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros 
                = (0xffU & ((IData)(0x40U) + (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)));
            VL_SHIFTL_WWI(77,77,32, __Vtemp_26, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0x40U);
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[0U] 
                = __Vtemp_26[0U];
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[1U] 
                = __Vtemp_26[1U];
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[2U] 
                = (0x1fffU & __Vtemp_26[2U]);
        }
        VL_SHIFTR_WWI(77,77,32, __Vtemp_29, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0x2dU);
        if ((0U == ((__Vtemp_29[0U] | __Vtemp_29[1U]) 
                    | (0x1fffU & __Vtemp_29[2U])))) {
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros 
                = (0xffU & ((IData)(0x20U) + (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)));
            VL_SHIFTL_WWI(77,77,32, __Vtemp_34, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0x20U);
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[0U] 
                = __Vtemp_34[0U];
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[1U] 
                = __Vtemp_34[1U];
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[2U] 
                = (0x1fffU & __Vtemp_34[2U]);
        }
        VL_SHIFTR_WWI(77,77,32, __Vtemp_37, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0x3dU);
        if ((0U == ((__Vtemp_37[0U] | __Vtemp_37[1U]) 
                    | (0x1fffU & __Vtemp_37[2U])))) {
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros 
                = (0xffU & ((IData)(0x10U) + (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)));
            VL_SHIFTL_WWI(77,77,32, __Vtemp_42, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0x10U);
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[0U] 
                = __Vtemp_42[0U];
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[1U] 
                = __Vtemp_42[1U];
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[2U] 
                = (0x1fffU & __Vtemp_42[2U]);
        }
        VL_SHIFTR_WWI(77,77,32, __Vtemp_45, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0x45U);
        if ((0U == ((__Vtemp_45[0U] | __Vtemp_45[1U]) 
                    | (0x1fffU & __Vtemp_45[2U])))) {
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros 
                = (0xffU & ((IData)(8U) + (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)));
            VL_SHIFTL_WWI(77,77,32, __Vtemp_50, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 8U);
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[0U] 
                = __Vtemp_50[0U];
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[1U] 
                = __Vtemp_50[1U];
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[2U] 
                = (0x1fffU & __Vtemp_50[2U]);
        }
        VL_SHIFTR_WWI(77,77,32, __Vtemp_53, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0x49U);
        if ((0U == ((__Vtemp_53[0U] | __Vtemp_53[1U]) 
                    | (0x1fffU & __Vtemp_53[2U])))) {
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros 
                = (0xffU & ((IData)(4U) + (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)));
            VL_SHIFTL_WWI(77,77,32, __Vtemp_58, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 4U);
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[0U] 
                = __Vtemp_58[0U];
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[1U] 
                = __Vtemp_58[1U];
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[2U] 
                = (0x1fffU & __Vtemp_58[2U]);
        }
        VL_SHIFTR_WWI(77,77,32, __Vtemp_61, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0x4bU);
        if ((0U == ((__Vtemp_61[0U] | __Vtemp_61[1U]) 
                    | (0x1fffU & __Vtemp_61[2U])))) {
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros 
                = (0xffU & ((IData)(2U) + (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)));
            VL_SHIFTL_WWI(77,77,32, __Vtemp_66, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 2U);
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[0U] 
                = __Vtemp_66[0U];
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[1U] 
                = __Vtemp_66[1U];
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[2U] 
                = (0x1fffU & __Vtemp_66[2U]);
        }
        VL_SHIFTR_WWI(77,77,32, __Vtemp_69, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0x4cU);
        if ((0U == ((__Vtemp_69[0U] | __Vtemp_69[1U]) 
                    | (0x1fffU & __Vtemp_69[2U])))) {
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros 
                = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)));
            VL_SHIFTL_WWI(77,77,32, __Vtemp_74, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 1U);
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[0U] 
                = __Vtemp_74[0U];
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[1U] 
                = __Vtemp_74[1U];
            vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan[2U] 
                = (0x1fffU & __Vtemp_74[2U]);
        }
    }
    VL_SHIFTL_WWI(77,77,8, __Vtemp_76, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag, (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val[2U] 
        = (0x1fffU & __Vtemp_76[2U]);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__raw_mant 
        = (0x7fffffU & ((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val[2U] 
                         << 0xbU) | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val[1U] 
                                     >> 0x15U)));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__guard_bit 
        = (1U & (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val[1U] 
                 >> 0x14U));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__round_bit 
        = (1U & (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val[1U] 
                 >> 0x13U));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_bit 
        = ((0U != (0x7ffffffffffffULL & (((QData)((IData)(
                                                          vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val[1U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val[0U]))))) 
           | (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sticky));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__round_up 
        = ((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__guard_bit) 
           & (((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__round_bit) 
               | (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_bit)) 
              | vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__raw_mant));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mant_int 
        = (0xffffffU & (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__raw_mant 
                        + (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__round_up)));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__final_mant 
        = ((0x800000U & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mant_int)
            ? 0U : (0x7fffffU & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mant_int));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc 
        = (0x7ffU & ((((IData)(2U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_exp_base))) 
                      - VL_EXTENDS_II(11,10, (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros))) 
                     + VL_EXTENDS_II(11,10, (1U & (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mant_int 
                                                   >> 0x17U)))));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__result_out 
        = ((0U == ((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag[0U] 
                    | vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag[1U]) 
                   | vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag[2U]))
            ? ((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign) 
               << 0x1fU) : (VL_LTES_III(32, 0xffU, 
                                        VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc)))
                             ? (0x7f800000U | ((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign) 
                                               << 0x1fU))
                             : (VL_GTES_III(32, 0U, 
                                            VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc)))
                                 ? ((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign) 
                                    << 0x1fU) : (((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign) 
                                                  << 0x1fU) 
                                                 | ((0x7f800000U 
                                                     & ((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc) 
                                                        << 0x17U)) 
                                                    | vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__final_mant)))));
    if (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__result_out 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_spec_res;
    }
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz 
        = ((0U == (0xffU & (vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_a 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_a)
            : vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_a);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz 
        = ((0U == (0xffU & (vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_b 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_b)
            : vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_b);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz 
        = ((0U == (0xffU & (vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_c 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_c)
            : vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_c);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz 
        = ((0U == (0xffU & (vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_d 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_d)
            : vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_d);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a 
        = (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz 
           >> 0x1fU);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a 
        = (0xffU & (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz 
                    >> 0x17U));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a 
        = (0x7fffffU & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b 
        = (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz 
           >> 0x1fU);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b 
        = (0xffU & (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz 
                    >> 0x17U));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b 
        = (0x7fffffU & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c 
        = (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz 
           >> 0x1fU);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c 
        = (0xffU & (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz 
                    >> 0x17U));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c 
        = (0x7fffffU & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d 
        = (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz 
           >> 0x1fU);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d 
        = (0xffU & (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz 
                    >> 0x17U));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d 
        = (0x7fffffU & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a)) 
              & (0U != vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a)) 
             | ((0xffU == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b)) 
                & (0U != vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b))) 
            | ((0xffU == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c)) 
               & (0U != vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c))) 
           | ((0xffU == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d)) 
              & (0U != vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d)));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a))) 
              & (~ (IData)((0U != vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a)))) 
             | (((0xffU == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b))) 
                & (~ (IData)((0U != vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b))))) 
            | (((0xffU == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c))) 
               & (~ (IData)((0U != vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c))))) 
           | (((0xffU == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d))) 
              & (~ (IData)((0U != vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d)))));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a)) 
               & (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a)) 
              & (~ (IData)((0U != vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a)))) 
             | (((0xffU == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b)) 
                & (~ (IData)((0U != vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b))))) 
            | (((0xffU == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c)) 
                & (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c)) 
               & (~ (IData)((0U != vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c))))) 
           | (((0xffU == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d)) 
               & (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d)) 
              & (~ (IData)((0U != vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d)))));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = 0U;
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__any_neg_inf)))) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = 1U;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = 0xffc00000U;
    } else if (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__any_pos_inf) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = 1U;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__any_neg_inf) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = 1U;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a) 
         >= (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b))) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b;
    } else {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c) 
         >= (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d))) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d;
    } else {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p) 
         >= (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r))) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_y 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_mx 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_nx 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n;
    } else {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_y 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_mx 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_nx 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m;
    }
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x)));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y)));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx)));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx)));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y_eff)));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx_eff)));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx_eff)));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant[0U] = 0U;
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant[1U] 
        = (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x 
           << 0x13U);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant[2U] 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x))) 
            << 0xaU) | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x 
                        >> 0xdU));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base[0U] = 0U;
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base[1U] 
        = (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y 
           << 0x13U);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base[2U] 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y))) 
            << 0xaU) | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y 
                        >> 0xdU));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base[0U] = 0U;
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base[1U] 
        = (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx 
           << 0x13U);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base[2U] 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx))) 
            << 0xaU) | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx 
                        >> 0xdU));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base[0U] = 0U;
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base[1U] 
        = (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx 
           << 0x13U);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base[2U] 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx))) 
            << 0xaU) | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx 
                        >> 0xdU));
    VL_SHIFTR_WWI(75,75,9, __Vtemp_84, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base, (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift));
    if ((0x4bU <= (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift))) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted[0U] = 0U;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted[1U] = 0U;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted[2U] = 0U;
    } else {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted[0U] 
            = __Vtemp_84[0U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted[1U] 
            = __Vtemp_84[1U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted[2U] 
            = (0x7ffU & __Vtemp_84[2U]);
    }
    __Vtemp_87[0U] = 0xffffffffU;
    __Vtemp_87[1U] = 0xffffffffU;
    __Vtemp_87[2U] = 0x7ffU;
    VL_SHIFTL_WWI(75,75,9, __Vtemp_88, __Vtemp_87, (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_y 
        = (0U != (((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base[0U] 
                    & (~ __Vtemp_88[0U])) | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base[1U] 
                                             & (~ __Vtemp_88[1U]))) 
                  | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base[2U] 
                     & (~ __Vtemp_88[2U]))));
    VL_SHIFTR_WWI(75,75,9, __Vtemp_93, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base, (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift));
    if ((0x4bU <= (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift))) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted[0U] = 0U;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted[1U] = 0U;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted[2U] = 0U;
    } else {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted[0U] 
            = __Vtemp_93[0U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted[1U] 
            = __Vtemp_93[1U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted[2U] 
            = (0x7ffU & __Vtemp_93[2U]);
    }
    __Vtemp_96[0U] = 0xffffffffU;
    __Vtemp_96[1U] = 0xffffffffU;
    __Vtemp_96[2U] = 0x7ffU;
    VL_SHIFTL_WWI(75,75,9, __Vtemp_97, __Vtemp_96, (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_m 
        = (0U != (((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base[0U] 
                    & (~ __Vtemp_97[0U])) | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base[1U] 
                                             & (~ __Vtemp_97[1U]))) 
                  | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base[2U] 
                     & (~ __Vtemp_97[2U]))));
    VL_SHIFTR_WWI(75,75,9, __Vtemp_102, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base, (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift));
    if ((0x4bU <= (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift))) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted[0U] = 0U;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted[1U] = 0U;
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted[2U] = 0U;
    } else {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted[0U] 
            = __Vtemp_102[0U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted[1U] 
            = __Vtemp_102[1U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted[2U] 
            = (0x7ffU & __Vtemp_102[2U]);
    }
    __Vtemp_105[0U] = 0xffffffffU;
    __Vtemp_105[1U] = 0xffffffffU;
    __Vtemp_105[2U] = 0x7ffU;
    VL_SHIFTL_WWI(75,75,9, __Vtemp_106, __Vtemp_105, (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_n 
        = (0U != (((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base[0U] 
                    & (~ __Vtemp_106[0U])) | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base[1U] 
                                              & (~ 
                                                 __Vtemp_106[1U]))) 
                  | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base[2U] 
                     & (~ __Vtemp_106[2U]))));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_op 
        = ((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_y));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_op 
        = ((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_mx));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_op 
        = ((IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_nx));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x[0U] 
        = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant[0U];
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x[1U] 
        = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant[1U];
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x[2U] 
        = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant[2U];
    if (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_op) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[0U] 
            = (~ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted[0U]);
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[1U] 
            = (~ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted[1U]);
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[2U] 
            = (0x3fffU & (~ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted[2U]));
    } else {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[0U] 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted[0U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[1U] 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted[1U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[2U] 
            = (0x3fffU & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted[2U]);
    }
    if (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_op) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[0U] 
            = (~ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted[0U]);
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[1U] 
            = (~ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted[1U]);
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[2U] 
            = (0x3fffU & (~ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted[2U]));
    } else {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[0U] 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted[0U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[1U] 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted[1U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[2U] 
            = (0x3fffU & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted[2U]);
    }
    if (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_op) {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[0U] 
            = (~ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted[0U]);
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[1U] 
            = (~ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted[1U]);
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[2U] 
            = (0x3fffU & (~ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted[2U]));
    } else {
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[0U] 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted[0U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[1U] 
            = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted[1U];
        vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[2U] 
            = (0x3fffU & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted[2U]);
    }
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1[0U] 
        = ((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x[0U] 
            ^ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[0U]) 
           ^ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[0U]);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1[1U] 
        = ((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x[1U] 
            ^ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[1U]) 
           ^ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[1U]);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1[2U] 
        = ((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x[2U] 
            ^ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[2U]) 
           ^ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[2U]);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c1[0U] 
        = (((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x[0U] 
             & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[0U]) 
            | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[0U] 
               & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[0U])) 
           | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[0U] 
              & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x[0U]));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c1[1U] 
        = (((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x[1U] 
             & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[1U]) 
            | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[1U] 
               & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[1U])) 
           | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[1U] 
              & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x[1U]));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c1[2U] 
        = (((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x[2U] 
             & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[2U]) 
            | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y[2U] 
               & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[2U])) 
           | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m[2U] 
              & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x[2U]));
    VL_SHIFTL_WWI(78,78,32, __Vtemp_130, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c1, 1U);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s2[0U] 
        = ((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1[0U] 
            ^ __Vtemp_130[0U]) ^ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[0U]);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s2[1U] 
        = ((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1[1U] 
            ^ __Vtemp_130[1U]) ^ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[1U]);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s2[2U] 
        = (0x3fffU & ((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1[2U] 
                       ^ __Vtemp_130[2U]) ^ vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[2U]));
    VL_SHIFTL_WWI(78,78,32, __Vtemp_133, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c1, 1U);
    VL_SHIFTL_WWI(78,78,32, __Vtemp_135, vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c1, 1U);
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c2[0U] 
        = (((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1[0U] 
             & __Vtemp_133[0U]) | (__Vtemp_135[0U] 
                                   & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[0U])) 
           | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[0U] 
              & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1[0U]));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c2[1U] 
        = (((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1[1U] 
             & __Vtemp_133[1U]) | (__Vtemp_135[1U] 
                                   & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[1U])) 
           | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[1U] 
              & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1[1U]));
    vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c2[2U] 
        = (((vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1[2U] 
             & __Vtemp_133[2U]) | (__Vtemp_135[2U] 
                                   & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[2U])) 
           | (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n[2U] 
              & vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1[2U]));
}

VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root___eval_triggers__stl(Vadd4_fp32_tb_softfloat___024root* vlSelf);

VL_ATTR_COLD bool Vadd4_fp32_tb_softfloat___024root___eval_phase__stl(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root___eval_phase__stl\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vadd4_fp32_tb_softfloat___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vadd4_fp32_tb_softfloat___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root___dump_triggers__act(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root___dump_triggers__act\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge add4_fp32_tb_softfloat.tb_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge add4_fp32_tb_softfloat.tb_nrst)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(negedge add4_fp32_tb_softfloat.tb_clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root___dump_triggers__nba(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root___dump_triggers__nba\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge add4_fp32_tb_softfloat.tb_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge add4_fp32_tb_softfloat.tb_nrst)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(negedge add4_fp32_tb_softfloat.tb_clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root____Vm_traceActivitySetAll(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root____Vm_traceActivitySetAll\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
}

VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root___ctor_var_reset(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root___ctor_var_reset\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->add4_fp32_tb_softfloat__DOT__tb_clk = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__tb_nrst = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__tb_a = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__tb_b = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__tb_c = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__tb_d = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__exp = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__pass_count = 0;
    vlSelf->add4_fp32_tb_softfloat__DOT__fail_count = 0;
    vlSelf->add4_fp32_tb_softfloat__DOT__off_by_one = 0;
    vlSelf->add4_fp32_tb_softfloat__DOT__off_by_two = 0;
    vlSelf->add4_fp32_tb_softfloat__DOT__off_by_five_plus = 0;
    vlSelf->add4_fp32_tb_softfloat__DOT__diff = 0;
    vlSelf->add4_fp32_tb_softfloat__DOT__fd = 0;
    vlSelf->add4_fp32_tb_softfloat__DOT__fail_fd = 0;
    vlSelf->add4_fp32_tb_softfloat__DOT__a = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__b = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__c = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__d = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__expected = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__unnamedblk1__DOT__ret = 0;
    vlSelf->add4_fp32_tb_softfloat__DOT__unnamedblk1__DOT__is_zero_result = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__unnamedblk1__DOT__total_count = 0;
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_y = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_mx = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_nx = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y_eff = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx_eff = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx_eff = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift = VL_RAND_RESET_I(9);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift = VL_RAND_RESET_I(9);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift = VL_RAND_RESET_I(9);
    VL_RAND_RESET_W(75, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant);
    VL_RAND_RESET_W(75, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted);
    VL_RAND_RESET_W(75, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted);
    VL_RAND_RESET_W(75, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted);
    VL_RAND_RESET_W(75, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base);
    VL_RAND_RESET_W(75, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base);
    VL_RAND_RESET_W(75, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_y = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_m = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_n = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_any = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__any_pos_inf = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__any_neg_inf = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_e = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_align_sticky = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_case = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_result = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(78, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_sum_vec);
    VL_RAND_RESET_W(78, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_carry_vec);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_hot_ones = VL_RAND_RESET_I(2);
    VL_RAND_RESET_W(79, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum);
    VL_RAND_RESET_W(77, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__res_sign = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_exp_base = VL_RAND_RESET_I(8);
    VL_RAND_RESET_W(77, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_spec_res = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sticky = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(77, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros = VL_RAND_RESET_I(8);
    VL_RAND_RESET_W(77, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__raw_mant = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__final_mant = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mant_int = VL_RAND_RESET_I(24);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc = VL_RAND_RESET_I(11);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__guard_bit = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__round_bit = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_bit = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__round_up = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__result_out = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(78, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x);
    VL_RAND_RESET_W(78, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y);
    VL_RAND_RESET_W(78, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m);
    VL_RAND_RESET_W(78, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n);
    VL_RAND_RESET_W(78, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1);
    VL_RAND_RESET_W(78, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c1);
    VL_RAND_RESET_W(78, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s2);
    VL_RAND_RESET_W(78, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c2);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->__Vtrigprevexpr___TOP__add4_fp32_tb_softfloat__DOT__tb_clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__add4_fp32_tb_softfloat__DOT__tb_nrst__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
