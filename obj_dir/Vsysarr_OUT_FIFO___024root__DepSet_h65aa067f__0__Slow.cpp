// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsysarr_OUT_FIFO.h for the primary calling header

#include "Vsysarr_OUT_FIFO__pch.h"
#include "Vsysarr_OUT_FIFO___024root.h"

VL_ATTR_COLD void Vsysarr_OUT_FIFO___024root___eval_static__TOP(Vsysarr_OUT_FIFO___024root* vlSelf);

VL_ATTR_COLD void Vsysarr_OUT_FIFO___024root___eval_static(Vsysarr_OUT_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_OUT_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_OUT_FIFO___024root___eval_static\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vsysarr_OUT_FIFO___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vsysarr_OUT_FIFO___024root___eval_static__TOP(Vsysarr_OUT_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_OUT_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_OUT_FIFO___024root___eval_static__TOP\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.sysarr_OUT_FIFO_tb__DOT__tb_clk = 0U;
}

VL_ATTR_COLD void Vsysarr_OUT_FIFO___024root___eval_final(Vsysarr_OUT_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_OUT_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_OUT_FIFO___024root___eval_final\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsysarr_OUT_FIFO___024root___dump_triggers__stl(Vsysarr_OUT_FIFO___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vsysarr_OUT_FIFO___024root___eval_phase__stl(Vsysarr_OUT_FIFO___024root* vlSelf);

VL_ATTR_COLD void Vsysarr_OUT_FIFO___024root___eval_settle(Vsysarr_OUT_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_OUT_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_OUT_FIFO___024root___eval_settle\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vsysarr_OUT_FIFO___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("src/testbench/sysarr_OUT_FIFO_tb.sv", 5, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vsysarr_OUT_FIFO___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsysarr_OUT_FIFO___024root___dump_triggers__stl(Vsysarr_OUT_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_OUT_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_OUT_FIFO___024root___dump_triggers__stl\n"); );
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

void Vsysarr_OUT_FIFO___024root___act_comb__TOP__0(Vsysarr_OUT_FIFO___024root* vlSelf);

VL_ATTR_COLD void Vsysarr_OUT_FIFO___024root___eval_stl(Vsysarr_OUT_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_OUT_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_OUT_FIFO___024root___eval_stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vsysarr_OUT_FIFO___024root___act_comb__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vsysarr_OUT_FIFO___024root___eval_triggers__stl(Vsysarr_OUT_FIFO___024root* vlSelf);

VL_ATTR_COLD bool Vsysarr_OUT_FIFO___024root___eval_phase__stl(Vsysarr_OUT_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_OUT_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_OUT_FIFO___024root___eval_phase__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vsysarr_OUT_FIFO___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vsysarr_OUT_FIFO___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsysarr_OUT_FIFO___024root___dump_triggers__act(Vsysarr_OUT_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_OUT_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_OUT_FIFO___024root___dump_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge sysarr_OUT_FIFO_tb.tb_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge sysarr_OUT_FIFO_tb.tb_nrst)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(negedge sysarr_OUT_FIFO_tb.tb_clk)\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsysarr_OUT_FIFO___024root___dump_triggers__nba(Vsysarr_OUT_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_OUT_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_OUT_FIFO___024root___dump_triggers__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge sysarr_OUT_FIFO_tb.tb_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge sysarr_OUT_FIFO_tb.tb_nrst)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(negedge sysarr_OUT_FIFO_tb.tb_clk)\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsysarr_OUT_FIFO___024root___ctor_var_reset(Vsysarr_OUT_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_OUT_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_OUT_FIFO___024root___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->sysarr_OUT_FIFO_tb__DOT__tb_clk = VL_RAND_RESET_I(1);
    vlSelf->sysarr_OUT_FIFO_tb__DOT__tb_nrst = VL_RAND_RESET_I(1);
    vlSelf->sysarr_OUT_FIFO_tb__DOT__DUT__DOT__fifo_mem = VL_RAND_RESET_Q(64);
    vlSelf->sysarr_OUT_FIFO_tb__DOT__DUT__DOT__fifo_mem_next = VL_RAND_RESET_Q(64);
    vlSelf->__Vtrigprevexpr___TOP__sysarr_OUT_FIFO_tb__DOT__tb_clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__sysarr_OUT_FIFO_tb__DOT__tb_nrst__0 = VL_RAND_RESET_I(1);
}
