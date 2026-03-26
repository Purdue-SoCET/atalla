// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsysarr_16_input_fp_adder.h for the primary calling header

#include "Vsysarr_16_input_fp_adder__pch.h"
#include "Vsysarr_16_input_fp_adder__Syms.h"
#include "Vsysarr_16_input_fp_adder___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsysarr_16_input_fp_adder___024root___dump_triggers__stl(Vsysarr_16_input_fp_adder___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsysarr_16_input_fp_adder___024root___eval_triggers__stl(Vsysarr_16_input_fp_adder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_16_input_fp_adder___024root___eval_triggers__stl\n"); );
    Vsysarr_16_input_fp_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsysarr_16_input_fp_adder___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
