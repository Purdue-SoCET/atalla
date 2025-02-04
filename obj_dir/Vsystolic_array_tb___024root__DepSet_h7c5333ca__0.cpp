// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsystolic_array_tb.h for the primary calling header

#include "Vsystolic_array_tb__pch.h"
#include "Vsystolic_array_tb___024root.h"

VlCoroutine Vsystolic_array_tb___024root___eval_initial__TOP__Vtiming__0(Vsystolic_array_tb___024root* vlSelf);
VlCoroutine Vsystolic_array_tb___024root___eval_initial__TOP__Vtiming__1(Vsystolic_array_tb___024root* vlSelf);

void Vsystolic_array_tb___024root___eval_initial(Vsystolic_array_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array_tb___024root___eval_initial\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vsystolic_array_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vsystolic_array_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__systolic_array_tb__DOT__tb_clk__0 
        = vlSelfRef.systolic_array_tb__DOT__tb_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__systolic_array_tb__DOT__tb_nRST__0 
        = vlSelfRef.systolic_array_tb__DOT__tb_nRST;
}

VL_INLINE_OPT VlCoroutine Vsystolic_array_tb___024root___eval_initial__TOP__Vtiming__1(Vsystolic_array_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "src/testbench/systolic_array_tb.sv", 
                                             24);
        vlSelfRef.systolic_array_tb__DOT__tb_clk = 
            (1U & ((IData)(1U) + (IData)(vlSelfRef.systolic_array_tb__DOT__tb_clk)));
    }
}

void Vsystolic_array_tb___024root___act_comb__TOP__0(Vsystolic_array_tb___024root* vlSelf);

void Vsystolic_array_tb___024root___eval_act(Vsystolic_array_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array_tb___024root___eval_act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0xdULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vsystolic_array_tb___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

void Vsystolic_array_tb___024root___nba_sequent__TOP__0(Vsystolic_array_tb___024root* vlSelf);
void Vsystolic_array_tb___024root___nba_sequent__TOP__1(Vsystolic_array_tb___024root* vlSelf);
void Vsystolic_array_tb___024root___nba_sequent__TOP__2(Vsystolic_array_tb___024root* vlSelf);
void Vsystolic_array_tb___024root___nba_sequent__TOP__3(Vsystolic_array_tb___024root* vlSelf);
void Vsystolic_array_tb___024root___nba_comb__TOP__0(Vsystolic_array_tb___024root* vlSelf);
void Vsystolic_array_tb___024root___nba_comb__TOP__1(Vsystolic_array_tb___024root* vlSelf);

void Vsystolic_array_tb___024root___eval_nba(Vsystolic_array_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array_tb___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vsystolic_array_tb___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vsystolic_array_tb___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
        Vsystolic_array_tb___024root___nba_sequent__TOP__2(vlSelf);
        Vsystolic_array_tb___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((0xdULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vsystolic_array_tb___024root___nba_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
    if ((0xfULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vsystolic_array_tb___024root___nba_comb__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[6U] = 1U;
    }
}

void Vsystolic_array_tb___024root___timing_resume(Vsystolic_array_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array_tb___024root___timing_resume\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h8059f569__0.resume(
                                                   "@(posedge systolic_array_tb.tb_clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h8059f538__0.resume(
                                                   "@(negedge systolic_array_tb.tb_clk)");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vsystolic_array_tb___024root___timing_commit(Vsystolic_array_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array_tb___024root___timing_commit\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h8059f569__0.commit(
                                                   "@(posedge systolic_array_tb.tb_clk)");
    }
    if ((! (4ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h8059f538__0.commit(
                                                   "@(negedge systolic_array_tb.tb_clk)");
    }
}

void Vsystolic_array_tb___024root___eval_triggers__act(Vsystolic_array_tb___024root* vlSelf);

bool Vsystolic_array_tb___024root___eval_phase__act(Vsystolic_array_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array_tb___024root___eval_phase__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vsystolic_array_tb___024root___eval_triggers__act(vlSelf);
    Vsystolic_array_tb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vsystolic_array_tb___024root___timing_resume(vlSelf);
        Vsystolic_array_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vsystolic_array_tb___024root___eval_phase__nba(Vsystolic_array_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array_tb___024root___eval_phase__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vsystolic_array_tb___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsystolic_array_tb___024root___dump_triggers__nba(Vsystolic_array_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsystolic_array_tb___024root___dump_triggers__act(Vsystolic_array_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vsystolic_array_tb___024root___eval(Vsystolic_array_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array_tb___024root___eval\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vsystolic_array_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("src/testbench/systolic_array_tb.sv", 10, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vsystolic_array_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("src/testbench/systolic_array_tb.sv", 10, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vsystolic_array_tb___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vsystolic_array_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vsystolic_array_tb___024root___eval_debug_assertions(Vsystolic_array_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array_tb___024root___eval_debug_assertions\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
