// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsysarr_OUT_FIFO.h for the primary calling header

#include "Vsysarr_OUT_FIFO__pch.h"
#include "Vsysarr_OUT_FIFO__Syms.h"
#include "Vsysarr_OUT_FIFO___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsysarr_OUT_FIFO___024root___dump_triggers__stl(Vsysarr_OUT_FIFO___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsysarr_OUT_FIFO___024root___eval_triggers__stl(Vsysarr_OUT_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_OUT_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_OUT_FIFO___024root___eval_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsysarr_OUT_FIFO___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
