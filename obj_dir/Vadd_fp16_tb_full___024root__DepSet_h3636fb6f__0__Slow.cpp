// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd_fp16_tb_full.h for the primary calling header

#include "Vadd_fp16_tb_full__pch.h"
#include "Vadd_fp16_tb_full__Syms.h"
#include "Vadd_fp16_tb_full___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_fp16_tb_full___024root___dump_triggers__stl(Vadd_fp16_tb_full___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vadd_fp16_tb_full___024root___eval_triggers__stl(Vadd_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root___eval_triggers__stl\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vadd_fp16_tb_full___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
