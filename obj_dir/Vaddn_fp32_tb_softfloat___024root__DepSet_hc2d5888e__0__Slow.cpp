// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaddn_fp32_tb_softfloat.h for the primary calling header

#include "Vaddn_fp32_tb_softfloat__pch.h"
#include "Vaddn_fp32_tb_softfloat___024root.h"

VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root___eval_static(Vaddn_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root___eval_static\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__addn_fp32_tb_softfloat__DOT__tb_clk__0 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__addn_fp32_tb_softfloat__DOT__tb_nrst__0 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_nrst;
}

VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root___eval_final(Vaddn_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root___eval_final\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root___dump_triggers__stl(Vaddn_fp32_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vaddn_fp32_tb_softfloat___024root___eval_phase__stl(Vaddn_fp32_tb_softfloat___024root* vlSelf);

VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root___eval_settle(Vaddn_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root___eval_settle\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vaddn_fp32_tb_softfloat___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 12, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vaddn_fp32_tb_softfloat___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root___dump_triggers__stl(Vaddn_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root___dump_triggers__stl\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root___stl_sequent__TOP__0(Vaddn_fp32_tb_softfloat___024root* vlSelf);
VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root____Vm_traceActivitySetAll(Vaddn_fp32_tb_softfloat___024root* vlSelf);

VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root___eval_stl(Vaddn_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root___eval_stl\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vaddn_fp32_tb_softfloat___024root___stl_sequent__TOP__0(vlSelf);
        Vaddn_fp32_tb_softfloat___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root___stl_sequent__TOP__0(Vaddn_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root___stl_sequent__TOP__0\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_5;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_10;
    VlWide<3>/*95:0*/ __Vtemp_11;
    VlWide<3>/*95:0*/ __Vtemp_12;
    VlWide<3>/*95:0*/ __Vtemp_14;
    VlWide<3>/*95:0*/ __Vtemp_15;
    VlWide<3>/*95:0*/ __Vtemp_17;
    VlWide<3>/*95:0*/ __Vtemp_18;
    VlWide<3>/*95:0*/ __Vtemp_20;
    VlWide<3>/*95:0*/ __Vtemp_22;
    VlWide<3>/*95:0*/ __Vtemp_23;
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
    VlWide<3>/*95:0*/ __Vtemp_77;
    VlWide<3>/*95:0*/ __Vtemp_82;
    VlWide<3>/*95:0*/ __Vtemp_84;
    VlWide<3>/*95:0*/ __Vtemp_86;
    VlWide<3>/*95:0*/ __Vtemp_87;
    VlWide<3>/*95:0*/ __Vtemp_92;
    VlWide<3>/*95:0*/ __Vtemp_106;
    VlWide<3>/*95:0*/ __Vtemp_107;
    VlWide<3>/*95:0*/ __Vtemp_112;
    VlWide<3>/*95:0*/ __Vtemp_126;
    VlWide<3>/*95:0*/ __Vtemp_127;
    VlWide<3>/*95:0*/ __Vtemp_132;
    VlWide<3>/*95:0*/ __Vtemp_146;
    VlWide<3>/*95:0*/ __Vtemp_147;
    VlWide<3>/*95:0*/ __Vtemp_152;
    VlWide<3>/*95:0*/ __Vtemp_167;
    VlWide<3>/*95:0*/ __Vtemp_169;
    VlWide<3>/*95:0*/ __Vtemp_173;
    VlWide<3>/*95:0*/ __Vtemp_175;
    VlWide<3>/*95:0*/ __Vtemp_179;
    VlWide<3>/*95:0*/ __Vtemp_181;
    VlWide<3>/*95:0*/ __Vtemp_185;
    VlWide<3>/*95:0*/ __Vtemp_187;
    VlWide<3>/*95:0*/ __Vtemp_191;
    VlWide<3>/*95:0*/ __Vtemp_193;
    VlWide<3>/*95:0*/ __Vtemp_197;
    VlWide<3>/*95:0*/ __Vtemp_199;
    // Body
    if ((0U != ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[0U] 
                 | vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[1U]) 
                | vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[2U]))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__stage3_logic__DOT__unnamedblk9__DOT__i = 0xffffffffU;
    }
    __Vtemp_4[0U] = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_sum_vec[0U];
    __Vtemp_4[1U] = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_sum_vec[1U];
    __Vtemp_4[2U] = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_sum_vec[2U];
    VL_EXTENDS_WW(79,78, __Vtemp_5, __Vtemp_4);
    __Vtemp_7[0U] = __Vtemp_5[0U];
    __Vtemp_7[1U] = __Vtemp_5[1U];
    __Vtemp_7[2U] = (0x7fffU & __Vtemp_5[2U]);
    VL_SHIFTL_WWI(77,77,32, __Vtemp_10, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_carry_vec, 1U);
    __Vtemp_11[0U] = __Vtemp_10[0U];
    __Vtemp_11[1U] = __Vtemp_10[1U];
    __Vtemp_11[2U] = (0x1fffU & __Vtemp_10[2U]);
    VL_EXTENDS_WW(79,77, __Vtemp_12, __Vtemp_11);
    __Vtemp_14[0U] = __Vtemp_12[0U];
    __Vtemp_14[1U] = __Vtemp_12[1U];
    __Vtemp_14[2U] = (0x7fffU & __Vtemp_12[2U]);
    VL_ADD_W(3, __Vtemp_15, __Vtemp_7, __Vtemp_14);
    __Vtemp_17[0U] = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_hot_ones;
    __Vtemp_17[1U] = 0U;
    __Vtemp_17[2U] = 0U;
    VL_ADD_W(3, __Vtemp_18, __Vtemp_15, __Vtemp_17);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__raw_sum[0U] 
        = __Vtemp_18[0U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__raw_sum[1U] 
        = __Vtemp_18[1U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__raw_sum[2U] 
        = (0x3fffU & __Vtemp_18[2U]);
    if ((0x1000U & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__raw_sum[2U])) {
        __Vtemp_20[0U] = 1U;
        __Vtemp_20[1U] = 0U;
        __Vtemp_20[2U] = 0U;
        __Vtemp_22[0U] = (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__raw_sum[0U]);
        __Vtemp_22[1U] = (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__raw_sum[1U]);
        __Vtemp_22[2U] = (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__raw_sum[2U]);
        VL_ADD_W(3, __Vtemp_23, __Vtemp_20, __Vtemp_22);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mag_sum[0U] 
            = __Vtemp_23[0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mag_sum[1U] 
            = __Vtemp_23[1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mag_sum[2U] 
            = (0xfffU & __Vtemp_23[2U]);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_a_s)));
    } else {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mag_sum[0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__raw_sum[0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mag_sum[1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__raw_sum[1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mag_sum[2U] 
            = (0xfffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__raw_sum[2U]);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__res_sign 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_a_s;
    }
    if ((0U == ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[0U] 
                 | vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[1U]) 
                | vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[2U]))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[0U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[1U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[2U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros = 0x4bU;
    } else {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[2U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[2U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros = 0U;
        VL_SHIFTR_WWI(76,76,32, __Vtemp_29, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 0xcU);
        if ((0U == ((__Vtemp_29[0U] | __Vtemp_29[1U]) 
                    | (0xfffU & __Vtemp_29[2U])))) {
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros 
                = (0xffU & ((IData)(0x40U) + (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros)));
            VL_SHIFTL_WWI(76,76,32, __Vtemp_34, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 0x40U);
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[0U] 
                = __Vtemp_34[0U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[1U] 
                = __Vtemp_34[1U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[2U] 
                = (0xfffU & __Vtemp_34[2U]);
        }
        VL_SHIFTR_WWI(76,76,32, __Vtemp_37, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 0x2cU);
        if ((0U == ((__Vtemp_37[0U] | __Vtemp_37[1U]) 
                    | (0xfffU & __Vtemp_37[2U])))) {
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros 
                = (0xffU & ((IData)(0x20U) + (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros)));
            VL_SHIFTL_WWI(76,76,32, __Vtemp_42, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 0x20U);
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[0U] 
                = __Vtemp_42[0U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[1U] 
                = __Vtemp_42[1U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[2U] 
                = (0xfffU & __Vtemp_42[2U]);
        }
        VL_SHIFTR_WWI(76,76,32, __Vtemp_45, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 0x3cU);
        if ((0U == ((__Vtemp_45[0U] | __Vtemp_45[1U]) 
                    | (0xfffU & __Vtemp_45[2U])))) {
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros 
                = (0xffU & ((IData)(0x10U) + (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros)));
            VL_SHIFTL_WWI(76,76,32, __Vtemp_50, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 0x10U);
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[0U] 
                = __Vtemp_50[0U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[1U] 
                = __Vtemp_50[1U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[2U] 
                = (0xfffU & __Vtemp_50[2U]);
        }
        VL_SHIFTR_WWI(76,76,32, __Vtemp_53, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 0x44U);
        if ((0U == ((__Vtemp_53[0U] | __Vtemp_53[1U]) 
                    | (0xfffU & __Vtemp_53[2U])))) {
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros 
                = (0xffU & ((IData)(8U) + (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros)));
            VL_SHIFTL_WWI(76,76,32, __Vtemp_58, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 8U);
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[0U] 
                = __Vtemp_58[0U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[1U] 
                = __Vtemp_58[1U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[2U] 
                = (0xfffU & __Vtemp_58[2U]);
        }
        VL_SHIFTR_WWI(76,76,32, __Vtemp_61, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 0x48U);
        if ((0U == ((__Vtemp_61[0U] | __Vtemp_61[1U]) 
                    | (0xfffU & __Vtemp_61[2U])))) {
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros 
                = (0xffU & ((IData)(4U) + (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros)));
            VL_SHIFTL_WWI(76,76,32, __Vtemp_66, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 4U);
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[0U] 
                = __Vtemp_66[0U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[1U] 
                = __Vtemp_66[1U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[2U] 
                = (0xfffU & __Vtemp_66[2U]);
        }
        VL_SHIFTR_WWI(76,76,32, __Vtemp_69, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 0x4aU);
        if ((0U == ((__Vtemp_69[0U] | __Vtemp_69[1U]) 
                    | (0xfffU & __Vtemp_69[2U])))) {
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros 
                = (0xffU & ((IData)(2U) + (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros)));
            VL_SHIFTL_WWI(76,76,32, __Vtemp_74, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 2U);
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[0U] 
                = __Vtemp_74[0U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[1U] 
                = __Vtemp_74[1U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[2U] 
                = (0xfffU & __Vtemp_74[2U]);
        }
        VL_SHIFTR_WWI(76,76,32, __Vtemp_77, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 0x4bU);
        if ((0U == ((__Vtemp_77[0U] | __Vtemp_77[1U]) 
                    | (0xfffU & __Vtemp_77[2U])))) {
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros 
                = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros)));
            VL_SHIFTL_WWI(76,76,32, __Vtemp_82, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan, 1U);
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[0U] 
                = __Vtemp_82[0U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[1U] 
                = __Vtemp_82[1U];
            vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan[2U] 
                = (0xfffU & __Vtemp_82[2U]);
        }
    }
    VL_SHIFTL_WWI(76,76,8, __Vtemp_84, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag, (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__norm_val[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__norm_val[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__norm_val[2U] 
        = (0xfffU & __Vtemp_84[2U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__final_mant 
        = (0x7fffffU & ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__norm_val[2U] 
                         << 0xcU) | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__norm_val[1U] 
                                     >> 0x14U)));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(2U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,10, (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros))));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__result_out 
        = ((((0U == ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[0U] 
                      | vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[1U]) 
                     | vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag[2U])) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_exp_base)))
            ? 0U : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__final_exp_calc)))
                     ? (0x7f800000U | ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_res_sign) 
                                       << 0x1fU)) : 
                    (((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_res_sign) 
                      << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__final_exp_calc) 
                                                   << 0x17U)) 
                                   | vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__final_mant))));
    if (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_special) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__result_out 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_spec_res;
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__is_nan_any = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_pos_inf = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_neg_inf = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in[0U] 
        = ((0U == (0xffU & (vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U])
            : vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign[0U] 
        = (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in
           [0U] >> 0x1fU);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp[0U] 
        = (0xffU & (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in
                    [0U] >> 0x17U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac[0U] 
        = (0x7fffffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in
           [0U]);
    if (((0xffU == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
          [0U]) & (0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                   [0U]))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
           [0U]) & (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign
                    [0U])) & (~ (IData)((0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                                         [0U]))))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
           [0U]) & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign
          [0U]) & (~ (IData)((0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                              [0U]))))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_neg_inf = 1U;
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in[1U] 
        = ((0U == (0xffU & (vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U])
            : vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign[1U] 
        = (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in
           [1U] >> 0x1fU);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp[1U] 
        = (0xffU & (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in
                    [1U] >> 0x17U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac[1U] 
        = (0x7fffffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in
           [1U]);
    if (((0xffU == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
          [1U]) & (0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                   [1U]))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
           [1U]) & (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign
                    [1U])) & (~ (IData)((0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                                         [1U]))))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
           [1U]) & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign
          [1U]) & (~ (IData)((0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                              [1U]))))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_neg_inf = 1U;
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in[2U] 
        = ((0U == (0xffU & (vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U])
            : vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign[2U] 
        = (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in
           [2U] >> 0x1fU);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp[2U] 
        = (0xffU & (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in
                    [2U] >> 0x17U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac[2U] 
        = (0x7fffffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in
           [2U]);
    if (((0xffU == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
          [2U]) & (0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                   [2U]))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
           [2U]) & (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign
                    [2U])) & (~ (IData)((0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                                         [2U]))))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
           [2U]) & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign
          [2U]) & (~ (IData)((0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                              [2U]))))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_neg_inf = 1U;
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in[3U] 
        = ((0U == (0xffU & (vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U] 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U])
            : vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign[3U] 
        = (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in
           [3U] >> 0x1fU);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp[3U] 
        = (0xffU & (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in
                    [3U] >> 0x17U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac[3U] 
        = (0x7fffffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in
           [3U]);
    if (((0xffU == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
          [3U]) & (0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                   [3U]))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__is_nan_any = 1U;
    }
    if ((((0xffU == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
           [3U]) & (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign
                    [3U])) & (~ (IData)((0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                                         [3U]))))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_pos_inf = 1U;
    }
    if ((((0xffU == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
           [3U]) & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign
          [3U]) & (~ (IData)((0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                              [3U]))))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_neg_inf = 1U;
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp[0U][0U] 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
        [0U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx[0U][0U] = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp[0U][1U] 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
        [1U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx[0U][1U] = 1U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp[0U][2U] 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
        [2U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx[0U][2U] = 2U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp[0U][3U] 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
        [3U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx[0U][3U] = 3U;
    if ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
         [0U][0U] >= vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
         [0U][1U])) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h3dde53fc__0 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
            [0U][0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h00fc99f2__0 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
            [0U][0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp[1U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h3dde53fc__0;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx[1U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h00fc99f2__0;
    } else {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h3dde53fc__1 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
            [0U][1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h00fc99f2__1 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
            [0U][1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp[1U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h3dde53fc__1;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx[1U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h00fc99f2__1;
    }
    if ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
         [0U][2U] >= vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
         [0U][3U])) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h3dde53fc__0 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
            [0U][2U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h00fc99f2__0 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
            [0U][2U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp[1U][1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h3dde53fc__0;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx[1U][1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h00fc99f2__0;
    } else {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h3dde53fc__1 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
            [0U][3U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h00fc99f2__1 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
            [0U][3U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp[1U][1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h3dde53fc__1;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx[1U][1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h00fc99f2__1;
    }
    if ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
         [1U][0U] >= vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
         [1U][1U])) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h3dde53fc__0 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
            [1U][0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h00fc99f2__0 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
            [1U][0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp[2U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h3dde53fc__0;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx[2U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h00fc99f2__0;
    } else {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h3dde53fc__1 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
            [1U][1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h00fc99f2__1 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
            [1U][1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp[2U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h3dde53fc__1;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx[2U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h00fc99f2__1;
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_exp 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
        [2U][0U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_idx 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
        [2U][0U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign_max 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign
        [vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_idx];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__special_case = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_neg_inf)))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__special_case = 1U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_pos_inf) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__special_case = 1U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_neg_inf) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__special_case = 1U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__special_result = 0xff800000U;
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_exp_eff 
        = ((0U == (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_exp))
            ? 1U : (0xffU & (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_exp)));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[0U][0U] = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[0U][1U] 
        = (0xfffc0000U & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
           [0U][1U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[0U][1U] 
        = ((0x3ffffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
            [0U][1U]) | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                         [0U] << 0x12U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[0U][2U] 
        = ((0x200U & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
            [0U][2U]) | (0x3ffU & (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                                   [0U] >> 0xeU)));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[0U][2U] 
        = ((0x1ffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
            [0U][2U]) | (0x3ffU & ((IData)((0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
                                            [0U])) 
                                   << 9U)));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift[0U] 
        = (0x1ffU & ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_exp_eff) 
                     - ((0U == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
                         [0U]) ? 1U : vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
                        [0U])));
    __Vtemp_86[0U] = 0xffffffffU;
    __Vtemp_86[1U] = 0xffffffffU;
    __Vtemp_86[2U] = 0x3ffU;
    VL_SHIFTL_WWI(74,74,9, __Vtemp_87, __Vtemp_86, 
                  vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift
                  [0U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sticky[0U] 
        = (0U != (((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                    [0U][0U] & (~ __Vtemp_87[0U])) 
                   | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                      [0U][1U] & (~ __Vtemp_87[1U]))) 
                  | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                     [0U][2U] & (~ __Vtemp_87[2U]))));
    VL_SHIFTR_WWI(74,74,9, __Vtemp_92, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                  [0U], vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift
                  [0U]);
    if ((0x4aU <= vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift
         [0U])) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[0U][0U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[0U][1U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[0U][2U] = 0U;
    } else {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[0U][0U] 
            = __Vtemp_92[0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[0U][1U] 
            = __Vtemp_92[1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[0U][2U] 
            = (0x3ffU & __Vtemp_92[2U]);
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff[0U] 
        = ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign_max) 
           ^ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign
           [0U]);
    if ((0U == (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_idx))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[0U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [0U][0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[0U][1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [0U][1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[0U][2U] 
            = (0x1fffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [0U][2U]);
    } else if (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff
               [0U]) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[0U][0U] 
            = (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [0U][0U]);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[0U][1U] 
            = (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [0U][1U]);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[0U][2U] 
            = (0x1fffU & (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
                          [0U][2U]));
    } else {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[0U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [0U][0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[0U][1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [0U][1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[0U][2U] 
            = (0x1fffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [0U][2U]);
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[1U][0U] = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[1U][1U] 
        = (0xfffc0000U & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
           [1U][1U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[1U][1U] 
        = ((0x3ffffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
            [1U][1U]) | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                         [1U] << 0x12U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[1U][2U] 
        = ((0x200U & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
            [1U][2U]) | (0x3ffU & (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                                   [1U] >> 0xeU)));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[1U][2U] 
        = ((0x1ffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
            [1U][2U]) | (0x3ffU & ((IData)((0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
                                            [1U])) 
                                   << 9U)));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift[1U] 
        = (0x1ffU & ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_exp_eff) 
                     - ((0U == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
                         [1U]) ? 1U : vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
                        [1U])));
    __Vtemp_106[0U] = 0xffffffffU;
    __Vtemp_106[1U] = 0xffffffffU;
    __Vtemp_106[2U] = 0x3ffU;
    VL_SHIFTL_WWI(74,74,9, __Vtemp_107, __Vtemp_106, 
                  vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift
                  [1U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sticky[1U] 
        = (0U != (((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                    [1U][0U] & (~ __Vtemp_107[0U])) 
                   | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                      [1U][1U] & (~ __Vtemp_107[1U]))) 
                  | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                     [1U][2U] & (~ __Vtemp_107[2U]))));
    VL_SHIFTR_WWI(74,74,9, __Vtemp_112, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                  [1U], vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift
                  [1U]);
    if ((0x4aU <= vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift
         [1U])) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[1U][0U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[1U][1U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[1U][2U] = 0U;
    } else {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[1U][0U] 
            = __Vtemp_112[0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[1U][1U] 
            = __Vtemp_112[1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[1U][2U] 
            = (0x3ffU & __Vtemp_112[2U]);
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff[1U] 
        = ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign_max) 
           ^ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign
           [1U]);
    if ((1U == (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_idx))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[1U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [1U][0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[1U][1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [1U][1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[1U][2U] 
            = (0x1fffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [1U][2U]);
    } else if (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff
               [1U]) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[1U][0U] 
            = (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [1U][0U]);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[1U][1U] 
            = (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [1U][1U]);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[1U][2U] 
            = (0x1fffU & (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
                          [1U][2U]));
    } else {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[1U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [1U][0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[1U][1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [1U][1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[1U][2U] 
            = (0x1fffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [1U][2U]);
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[2U][0U] = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[2U][1U] 
        = (0xfffc0000U & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
           [2U][1U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[2U][1U] 
        = ((0x3ffffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
            [2U][1U]) | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                         [2U] << 0x12U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[2U][2U] 
        = ((0x200U & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
            [2U][2U]) | (0x3ffU & (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                                   [2U] >> 0xeU)));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[2U][2U] 
        = ((0x1ffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
            [2U][2U]) | (0x3ffU & ((IData)((0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
                                            [2U])) 
                                   << 9U)));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift[2U] 
        = (0x1ffU & ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_exp_eff) 
                     - ((0U == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
                         [2U]) ? 1U : vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
                        [2U])));
    __Vtemp_126[0U] = 0xffffffffU;
    __Vtemp_126[1U] = 0xffffffffU;
    __Vtemp_126[2U] = 0x3ffU;
    VL_SHIFTL_WWI(74,74,9, __Vtemp_127, __Vtemp_126, 
                  vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift
                  [2U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sticky[2U] 
        = (0U != (((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                    [2U][0U] & (~ __Vtemp_127[0U])) 
                   | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                      [2U][1U] & (~ __Vtemp_127[1U]))) 
                  | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                     [2U][2U] & (~ __Vtemp_127[2U]))));
    VL_SHIFTR_WWI(74,74,9, __Vtemp_132, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                  [2U], vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift
                  [2U]);
    if ((0x4aU <= vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift
         [2U])) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[2U][0U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[2U][1U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[2U][2U] = 0U;
    } else {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[2U][0U] 
            = __Vtemp_132[0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[2U][1U] 
            = __Vtemp_132[1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[2U][2U] 
            = (0x3ffU & __Vtemp_132[2U]);
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff[2U] 
        = ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign_max) 
           ^ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign
           [2U]);
    if ((2U == (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_idx))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[2U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [2U][0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[2U][1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [2U][1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[2U][2U] 
            = (0x1fffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [2U][2U]);
    } else if (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff
               [2U]) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[2U][0U] 
            = (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [2U][0U]);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[2U][1U] 
            = (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [2U][1U]);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[2U][2U] 
            = (0x1fffU & (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
                          [2U][2U]));
    } else {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[2U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [2U][0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[2U][1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [2U][1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[2U][2U] 
            = (0x1fffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [2U][2U]);
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[3U][0U] = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[3U][1U] 
        = (0xfffc0000U & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
           [3U][1U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[3U][1U] 
        = ((0x3ffffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
            [3U][1U]) | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                         [3U] << 0x12U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[3U][2U] 
        = ((0x200U & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
            [3U][2U]) | (0x3ffU & (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac
                                   [3U] >> 0xeU)));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[3U][2U] 
        = ((0x1ffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
            [3U][2U]) | (0x3ffU & ((IData)((0U != vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
                                            [3U])) 
                                   << 9U)));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift[3U] 
        = (0x1ffU & ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_exp_eff) 
                     - ((0U == vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
                         [3U]) ? 1U : vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp
                        [3U])));
    __Vtemp_146[0U] = 0xffffffffU;
    __Vtemp_146[1U] = 0xffffffffU;
    __Vtemp_146[2U] = 0x3ffU;
    VL_SHIFTL_WWI(74,74,9, __Vtemp_147, __Vtemp_146, 
                  vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift
                  [3U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sticky[3U] 
        = (0U != (((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                    [3U][0U] & (~ __Vtemp_147[0U])) 
                   | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                      [3U][1U] & (~ __Vtemp_147[1U]))) 
                  | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                     [3U][2U] & (~ __Vtemp_147[2U]))));
    VL_SHIFTR_WWI(74,74,9, __Vtemp_152, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base
                  [3U], vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift
                  [3U]);
    if ((0x4aU <= vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift
         [3U])) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[3U][0U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[3U][1U] = 0U;
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[3U][2U] = 0U;
    } else {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[3U][0U] 
            = __Vtemp_152[0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[3U][1U] 
            = __Vtemp_152[1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[3U][2U] 
            = (0x3ffU & __Vtemp_152[2U]);
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff[3U] 
        = ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign_max) 
           ^ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign
           [3U]);
    if ((3U == (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_idx))) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[3U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [3U][0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[3U][1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [3U][1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[3U][2U] 
            = (0x1fffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [3U][2U]);
    } else if (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff
               [3U]) {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[3U][0U] 
            = (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [3U][0U]);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[3U][1U] 
            = (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [3U][1U]);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[3U][2U] 
            = (0x1fffU & (~ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
                          [3U][2U]));
    } else {
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[3U][0U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [3U][0U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[3U][1U] 
            = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
            [3U][1U];
        vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[3U][2U] 
            = (0x1fffU & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant
               [3U][2U]);
    }
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[0U][0U] 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
        [0U][0U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[0U][1U] 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
        [0U][1U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[0U][2U] 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
        [0U][2U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[0U][0U] = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[0U][1U] = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[0U][2U] = 0U;
    VL_SHIFTL_WWI(77,77,32, __Vtemp_169, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c
                  [0U], 1U);
    __Vtemp_167[1U] = ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
                        [0U][1U] ^ __Vtemp_169[1U]) 
                       ^ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                       [1U][1U]);
    __Vtemp_167[2U] = (0x1fffU & ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
                                   [0U][2U] ^ __Vtemp_169[2U]) 
                                  ^ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                                  [1U][2U]));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[1U][0U] 
        = ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
            [0U][0U] ^ __Vtemp_169[0U]) ^ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
           [1U][0U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[1U][1U] 
        = __Vtemp_167[1U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[1U][2U] 
        = __Vtemp_167[2U];
    VL_SHIFTL_WWI(77,77,32, __Vtemp_173, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c
                  [0U], 1U);
    VL_SHIFTL_WWI(77,77,32, __Vtemp_175, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c
                  [0U], 1U);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[1U][0U] 
        = (((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
             [0U][0U] & __Vtemp_173[0U]) | (__Vtemp_175[0U] 
                                            & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                                            [1U][0U])) 
           | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
              [1U][0U] & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
              [0U][0U]));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[1U][1U] 
        = (((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
             [0U][1U] & __Vtemp_173[1U]) | (__Vtemp_175[1U] 
                                            & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                                            [1U][1U])) 
           | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
              [1U][1U] & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
              [0U][1U]));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[1U][2U] 
        = (((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
             [0U][2U] & __Vtemp_173[2U]) | (__Vtemp_175[2U] 
                                            & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                                            [1U][2U])) 
           | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
              [1U][2U] & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
              [0U][2U]));
    VL_SHIFTL_WWI(77,77,32, __Vtemp_181, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c
                  [1U], 1U);
    __Vtemp_179[1U] = ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
                        [1U][1U] ^ __Vtemp_181[1U]) 
                       ^ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                       [2U][1U]);
    __Vtemp_179[2U] = (0x1fffU & ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
                                   [1U][2U] ^ __Vtemp_181[2U]) 
                                  ^ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                                  [2U][2U]));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[2U][0U] 
        = ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
            [1U][0U] ^ __Vtemp_181[0U]) ^ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
           [2U][0U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[2U][1U] 
        = __Vtemp_179[1U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[2U][2U] 
        = __Vtemp_179[2U];
    VL_SHIFTL_WWI(77,77,32, __Vtemp_185, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c
                  [1U], 1U);
    VL_SHIFTL_WWI(77,77,32, __Vtemp_187, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c
                  [1U], 1U);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[2U][0U] 
        = (((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
             [1U][0U] & __Vtemp_185[0U]) | (__Vtemp_187[0U] 
                                            & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                                            [2U][0U])) 
           | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
              [2U][0U] & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
              [1U][0U]));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[2U][1U] 
        = (((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
             [1U][1U] & __Vtemp_185[1U]) | (__Vtemp_187[1U] 
                                            & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                                            [2U][1U])) 
           | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
              [2U][1U] & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
              [1U][1U]));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[2U][2U] 
        = (((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
             [1U][2U] & __Vtemp_185[2U]) | (__Vtemp_187[2U] 
                                            & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                                            [2U][2U])) 
           | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
              [2U][2U] & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
              [1U][2U]));
    VL_SHIFTL_WWI(77,77,32, __Vtemp_193, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c
                  [2U], 1U);
    __Vtemp_191[1U] = ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
                        [2U][1U] ^ __Vtemp_193[1U]) 
                       ^ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                       [3U][1U]);
    __Vtemp_191[2U] = (0x1fffU & ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
                                   [2U][2U] ^ __Vtemp_193[2U]) 
                                  ^ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                                  [3U][2U]));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[3U][0U] 
        = ((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
            [2U][0U] ^ __Vtemp_193[0U]) ^ vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
           [3U][0U]);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[3U][1U] 
        = __Vtemp_191[1U];
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[3U][2U] 
        = __Vtemp_191[2U];
    VL_SHIFTL_WWI(77,77,32, __Vtemp_197, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c
                  [2U], 1U);
    VL_SHIFTL_WWI(77,77,32, __Vtemp_199, vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c
                  [2U], 1U);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[3U][0U] 
        = (((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
             [2U][0U] & __Vtemp_197[0U]) | (__Vtemp_199[0U] 
                                            & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                                            [3U][0U])) 
           | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
              [3U][0U] & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
              [2U][0U]));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[3U][1U] 
        = (((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
             [2U][1U] & __Vtemp_197[1U]) | (__Vtemp_199[1U] 
                                            & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                                            [3U][1U])) 
           | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
              [3U][1U] & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
              [2U][1U]));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[3U][2U] 
        = (((vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
             [2U][2U] & __Vtemp_197[2U]) | (__Vtemp_199[2U] 
                                            & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
                                            [3U][2U])) 
           | (vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op
              [3U][2U] & vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s
              [2U][2U]));
}

VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root___eval_triggers__stl(Vaddn_fp32_tb_softfloat___024root* vlSelf);

VL_ATTR_COLD bool Vaddn_fp32_tb_softfloat___024root___eval_phase__stl(Vaddn_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root___eval_phase__stl\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vaddn_fp32_tb_softfloat___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vaddn_fp32_tb_softfloat___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root___dump_triggers__act(Vaddn_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root___dump_triggers__act\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge addn_fp32_tb_softfloat.tb_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge addn_fp32_tb_softfloat.tb_nrst)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(negedge addn_fp32_tb_softfloat.tb_clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root___dump_triggers__nba(Vaddn_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root___dump_triggers__nba\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge addn_fp32_tb_softfloat.tb_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge addn_fp32_tb_softfloat.tb_nrst)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(negedge addn_fp32_tb_softfloat.tb_clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root____Vm_traceActivitySetAll(Vaddn_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root____Vm_traceActivitySetAll\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
}

VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root___ctor_var_reset(Vaddn_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root___ctor_var_reset\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->addn_fp32_tb_softfloat__DOT__tb_clk = VL_RAND_RESET_I(1);
    vlSelf->addn_fp32_tb_softfloat__DOT__tb_nrst = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, vlSelf->addn_fp32_tb_softfloat__DOT__tb_in_data);
    vlSelf->addn_fp32_tb_softfloat__DOT__tb_result = VL_RAND_RESET_I(32);
    vlSelf->addn_fp32_tb_softfloat__DOT__exp = VL_RAND_RESET_I(32);
    vlSelf->addn_fp32_tb_softfloat__DOT__pass_count = 0;
    vlSelf->addn_fp32_tb_softfloat__DOT__fail_count = 0;
    vlSelf->addn_fp32_tb_softfloat__DOT__off_by_one = 0;
    vlSelf->addn_fp32_tb_softfloat__DOT__off_by_two = 0;
    vlSelf->addn_fp32_tb_softfloat__DOT__off_by_five_plus = 0;
    vlSelf->addn_fp32_tb_softfloat__DOT__diff = 0;
    vlSelf->addn_fp32_tb_softfloat__DOT__fd = 0;
    vlSelf->addn_fp32_tb_softfloat__DOT__fail_fd = 0;
    vlSelf->addn_fp32_tb_softfloat__DOT__a = VL_RAND_RESET_I(32);
    vlSelf->addn_fp32_tb_softfloat__DOT__b = VL_RAND_RESET_I(32);
    vlSelf->addn_fp32_tb_softfloat__DOT__c = VL_RAND_RESET_I(32);
    vlSelf->addn_fp32_tb_softfloat__DOT__d = VL_RAND_RESET_I(32);
    vlSelf->addn_fp32_tb_softfloat__DOT__expected = VL_RAND_RESET_I(32);
    vlSelf->addn_fp32_tb_softfloat__DOT__total_count = 0;
    vlSelf->addn_fp32_tb_softfloat__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->addn_fp32_tb_softfloat__DOT__unnamedblk2__DOT__ret = 0;
    vlSelf->addn_fp32_tb_softfloat__DOT__unnamedblk2__DOT__is_zero_result = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__exp[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__frac[__Vi0] = VL_RAND_RESET_I(23);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__sign[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp[__Vi0][__Vi1] = VL_RAND_RESET_I(8);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx[__Vi0][__Vi1] = VL_RAND_RESET_I(2);
        }
    }
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__max_exp = VL_RAND_RESET_I(8);
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__max_exp_eff = VL_RAND_RESET_I(8);
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__max_idx = VL_RAND_RESET_I(2);
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__sign_max = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__shift[__Vi0] = VL_RAND_RESET_I(9);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        VL_RAND_RESET_W(74, vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[__Vi0]);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        VL_RAND_RESET_W(74, vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[__Vi0]);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__sticky[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        VL_RAND_RESET_W(77, vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__op[__Vi0]);
    }
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__is_nan_any = VL_RAND_RESET_I(1);
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__any_pos_inf = VL_RAND_RESET_I(1);
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__any_neg_inf = VL_RAND_RESET_I(1);
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__special_case = VL_RAND_RESET_I(1);
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__special_result = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        VL_RAND_RESET_W(77, vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[__Vi0]);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        VL_RAND_RESET_W(77, vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[__Vi0]);
    }
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__st1_a_e = VL_RAND_RESET_I(8);
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__st1_a_s = VL_RAND_RESET_I(1);
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__st1_align_sticky = VL_RAND_RESET_I(1);
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__st1_special_case = VL_RAND_RESET_I(1);
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__st1_special_result = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(77, vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__st1_sum_vec);
    VL_RAND_RESET_W(77, vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__st1_carry_vec);
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__st1_hot_ones = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(78, vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__raw_sum);
    VL_RAND_RESET_W(76, vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__mag_sum);
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__res_sign = VL_RAND_RESET_I(1);
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__st2_exp_base = VL_RAND_RESET_I(8);
    VL_RAND_RESET_W(76, vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag);
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__st2_spec_res = VL_RAND_RESET_I(32);
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__st2_res_sign = VL_RAND_RESET_I(1);
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sticky = VL_RAND_RESET_I(1);
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__st2_special = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(76, vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan);
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros = VL_RAND_RESET_I(8);
    VL_RAND_RESET_W(76, vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__norm_val);
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__final_mant = VL_RAND_RESET_I(23);
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__final_exp_calc = VL_RAND_RESET_I(11);
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__result_out = VL_RAND_RESET_I(32);
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__unnamedblk7__DOT__i = 0;
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__unnamedblk8__DOT__i = 0;
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT__stage3_logic__DOT__unnamedblk9__DOT__i = 0;
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h3dde53fc__0 = VL_RAND_RESET_I(8);
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h00fc99f2__0 = VL_RAND_RESET_I(2);
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h3dde53fc__1 = VL_RAND_RESET_I(8);
    vlSelf->addn_fp32_tb_softfloat__DOT__dut__DOT____Vlvbound_h00fc99f2__1 = VL_RAND_RESET_I(2);
    vlSelf->__Vtrigprevexpr___TOP__addn_fp32_tb_softfloat__DOT__tb_clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__addn_fp32_tb_softfloat__DOT__tb_nrst__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
