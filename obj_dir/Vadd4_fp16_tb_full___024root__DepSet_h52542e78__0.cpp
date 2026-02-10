// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd4_fp16_tb_full.h for the primary calling header

#include "Vadd4_fp16_tb_full__pch.h"
#include "Vadd4_fp16_tb_full__Syms.h"
#include "Vadd4_fp16_tb_full___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp16_tb_full___024root___dump_triggers__act(Vadd4_fp16_tb_full___024root* vlSelf);
#endif  // VL_DEBUG

void Vadd4_fp16_tb_full___024root___eval_triggers__act(Vadd4_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_full___024root___eval_triggers__act\n"); );
    Vadd4_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__add4_fp16_tb_full__DOT__tb_clk__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__add4_fp16_tb_full__DOT__tb_nrst__0)));
    vlSelfRef.__VactTriggered.setBit(2U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__VactTriggered.setBit(3U, ((~ (IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_clk)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__add4_fp16_tb_full__DOT__tb_clk__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__add4_fp16_tb_full__DOT__tb_clk__0 
        = vlSelfRef.add4_fp16_tb_full__DOT__tb_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__add4_fp16_tb_full__DOT__tb_nrst__0 
        = vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vadd4_fp16_tb_full___024root___dump_triggers__act(vlSelf);
    }
#endif
}
