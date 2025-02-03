// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsysarr_FIFO.h for the primary calling header

#include "Vsysarr_FIFO__pch.h"
#include "Vsysarr_FIFO___024root.h"

VlCoroutine Vsysarr_FIFO___024root___eval_initial__TOP__Vtiming__0(Vsysarr_FIFO___024root* vlSelf);
VlCoroutine Vsysarr_FIFO___024root___eval_initial__TOP__Vtiming__1(Vsysarr_FIFO___024root* vlSelf);

void Vsysarr_FIFO___024root___eval_initial(Vsysarr_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_FIFO___024root___eval_initial\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vsysarr_FIFO___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vsysarr_FIFO___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__sysarr_FIFO_tb__DOT__tb_clk__0 
        = vlSelfRef.sysarr_FIFO_tb__DOT__tb_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__sysarr_FIFO_tb__DOT__tb_nrst__0 
        = vlSelfRef.sysarr_FIFO_tb__DOT__tb_nrst;
}

VL_INLINE_OPT VlCoroutine Vsysarr_FIFO___024root___eval_initial__TOP__Vtiming__1(Vsysarr_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_FIFO___024root___eval_initial__TOP__Vtiming__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "src/testbench/sysarr_FIFO_tb.sv", 
                                             16);
        vlSelfRef.sysarr_FIFO_tb__DOT__tb_clk = (1U 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelfRef.sysarr_FIFO_tb__DOT__tb_clk)));
    }
}

void Vsysarr_FIFO___024root___act_comb__TOP__0(Vsysarr_FIFO___024root* vlSelf);

void Vsysarr_FIFO___024root___eval_act(Vsysarr_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_FIFO___024root___eval_act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0xdULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vsysarr_FIFO___024root___act_comb__TOP__0(vlSelf);
    }
}

void Vsysarr_FIFO___024root___nba_sequent__TOP__0(Vsysarr_FIFO___024root* vlSelf);

void Vsysarr_FIFO___024root___eval_nba(Vsysarr_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_FIFO___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vsysarr_FIFO___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0xfULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vsysarr_FIFO___024root___act_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vsysarr_FIFO___024root___nba_sequent__TOP__0(Vsysarr_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_FIFO___024root___nba_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.sysarr_FIFO_tb__DOT__tb_nrst) {
        vlSelfRef.sysarr_FIFO_tb__DOT__DUT__DOT__fifo_mem[0U] 
            = vlSelfRef.sysarr_FIFO_tb__DOT__DUT__DOT__fifo_mem_next[0U];
        vlSelfRef.sysarr_FIFO_tb__DOT__DUT__DOT__fifo_mem[1U] 
            = vlSelfRef.sysarr_FIFO_tb__DOT__DUT__DOT__fifo_mem_next[1U];
        vlSelfRef.sysarr_FIFO_tb__DOT__DUT__DOT__fifo_mem[2U] 
            = vlSelfRef.sysarr_FIFO_tb__DOT__DUT__DOT__fifo_mem_next[2U];
        vlSelfRef.sysarr_FIFO_tb__DOT__DUT__DOT__fifo_mem[3U] 
            = vlSelfRef.sysarr_FIFO_tb__DOT__DUT__DOT__fifo_mem_next[3U];
    } else {
        vlSelfRef.sysarr_FIFO_tb__DOT__DUT__DOT__fifo_mem[0U] = 0U;
        vlSelfRef.sysarr_FIFO_tb__DOT__DUT__DOT__fifo_mem[1U] = 0U;
        vlSelfRef.sysarr_FIFO_tb__DOT__DUT__DOT__fifo_mem[2U] = 0U;
        vlSelfRef.sysarr_FIFO_tb__DOT__DUT__DOT__fifo_mem[3U] = 0U;
    }
}

void Vsysarr_FIFO___024root___timing_resume(Vsysarr_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_FIFO___024root___timing_resume\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h4f401444__0.resume(
                                                   "@(posedge sysarr_FIFO_tb.tb_clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h4f401405__0.resume(
                                                   "@(negedge sysarr_FIFO_tb.tb_clk)");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vsysarr_FIFO___024root___timing_commit(Vsysarr_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_FIFO___024root___timing_commit\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h4f401444__0.commit(
                                                   "@(posedge sysarr_FIFO_tb.tb_clk)");
    }
    if ((! (4ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h4f401405__0.commit(
                                                   "@(negedge sysarr_FIFO_tb.tb_clk)");
    }
}

void Vsysarr_FIFO___024root___eval_triggers__act(Vsysarr_FIFO___024root* vlSelf);

bool Vsysarr_FIFO___024root___eval_phase__act(Vsysarr_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_FIFO___024root___eval_phase__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vsysarr_FIFO___024root___eval_triggers__act(vlSelf);
    Vsysarr_FIFO___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vsysarr_FIFO___024root___timing_resume(vlSelf);
        Vsysarr_FIFO___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vsysarr_FIFO___024root___eval_phase__nba(Vsysarr_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_FIFO___024root___eval_phase__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vsysarr_FIFO___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsysarr_FIFO___024root___dump_triggers__nba(Vsysarr_FIFO___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsysarr_FIFO___024root___dump_triggers__act(Vsysarr_FIFO___024root* vlSelf);
#endif  // VL_DEBUG

void Vsysarr_FIFO___024root___eval(Vsysarr_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_FIFO___024root___eval\n"); );
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
            Vsysarr_FIFO___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("src/testbench/sysarr_FIFO_tb.sv", 5, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vsysarr_FIFO___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("src/testbench/sysarr_FIFO_tb.sv", 5, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vsysarr_FIFO___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vsysarr_FIFO___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vsysarr_FIFO___024root___eval_debug_assertions(Vsysarr_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_FIFO___024root___eval_debug_assertions\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
