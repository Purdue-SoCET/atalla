// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsystolic_array_tb.h for the primary calling header

#include "Vsystolic_array_tb__pch.h"
#include "Vsystolic_array_tb_systolic_array_if.h"

VL_ATTR_COLD void Vsystolic_array_tb_systolic_array_if___ctor_var_reset(Vsystolic_array_tb_systolic_array_if* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vsystolic_array_tb_systolic_array_if___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->weight_en = VL_RAND_RESET_I(1);
    vlSelf->input_en = VL_RAND_RESET_I(1);
    vlSelf->partial_en = VL_RAND_RESET_I(1);
    vlSelf->out_en = VL_RAND_RESET_I(1);
    vlSelf->drained = VL_RAND_RESET_I(1);
    vlSelf->row_en = VL_RAND_RESET_I(2);
    vlSelf->row_out = VL_RAND_RESET_I(2);
    vlSelf->array_in = VL_RAND_RESET_Q(64);
    vlSelf->array_in_partials = VL_RAND_RESET_Q(64);
    vlSelf->array_output = VL_RAND_RESET_Q(64);
}
