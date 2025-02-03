// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsysarr_FIFO.h for the primary calling header

#include "Vsysarr_FIFO__pch.h"
#include "Vsysarr_FIFO_systolic_array_FIFO_if.h"

VL_ATTR_COLD void Vsysarr_FIFO_systolic_array_FIFO_if___ctor_var_reset(Vsysarr_FIFO_systolic_array_FIFO_if* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vsysarr_FIFO_systolic_array_FIFO_if___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->load = VL_RAND_RESET_I(1);
    vlSelf->shift = VL_RAND_RESET_I(1);
    vlSelf->load_values = VL_RAND_RESET_Q(64);
}
