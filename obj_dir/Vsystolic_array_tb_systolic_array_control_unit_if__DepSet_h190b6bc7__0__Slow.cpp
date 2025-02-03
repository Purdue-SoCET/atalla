// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsystolic_array_tb.h for the primary calling header

#include "Vsystolic_array_tb__pch.h"
#include "Vsystolic_array_tb_systolic_array_control_unit_if.h"

VL_ATTR_COLD void Vsystolic_array_tb_systolic_array_control_unit_if___ctor_var_reset(Vsystolic_array_tb_systolic_array_control_unit_if* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vsystolic_array_tb_systolic_array_control_unit_if___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->input_type = VL_RAND_RESET_I(1);
    vlSelf->input_load = VL_RAND_RESET_I(1);
    vlSelf->weight_load = VL_RAND_RESET_I(1);
    vlSelf->partials_load = VL_RAND_RESET_I(1);
    vlSelf->MAC_start = VL_RAND_RESET_I(1);
    vlSelf->MAC_count = VL_RAND_RESET_I(3);
    vlSelf->add_start = VL_RAND_RESET_I(1);
    vlSelf->add_count = VL_RAND_RESET_I(2);
    vlSelf->fifo_shift = VL_RAND_RESET_I(1);
    vlSelf->out_fifo_shift = VL_RAND_RESET_I(1);
    vlSelf->input_row = VL_RAND_RESET_I(2);
    vlSelf->weight_row = VL_RAND_RESET_I(2);
    vlSelf->partials_row = VL_RAND_RESET_I(2);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->iteration[__Vi0] = VL_RAND_RESET_I(4);
    }
}
