// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaddn_fp32_tb_softfloat.h for the primary calling header

#include "Vaddn_fp32_tb_softfloat__pch.h"
#include "Vaddn_fp32_tb_softfloat__Syms.h"
#include "Vaddn_fp32_tb_softfloat___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root___dump_triggers__stl(Vaddn_fp32_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root___eval_triggers__stl(Vaddn_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root___eval_triggers__stl\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vaddn_fp32_tb_softfloat___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
