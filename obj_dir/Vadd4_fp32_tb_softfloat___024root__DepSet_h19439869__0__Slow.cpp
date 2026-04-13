// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd4_fp32_tb_softfloat.h for the primary calling header

#include "Vadd4_fp32_tb_softfloat__pch.h"
#include "Vadd4_fp32_tb_softfloat__Syms.h"
#include "Vadd4_fp32_tb_softfloat___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root___dump_triggers__stl(Vadd4_fp32_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root___eval_triggers__stl(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root___eval_triggers__stl\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
    vlSelfRef.__VstlTriggered.setBit(1U, (vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val__0));
    vlSelfRef.__Vtrigprevexpr___TOP__add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val__0 
        = vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VstlDidInit)))))) {
        vlSelfRef.__VstlDidInit = 1U;
        vlSelfRef.__VstlTriggered.setBit(1U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vadd4_fp32_tb_softfloat___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
