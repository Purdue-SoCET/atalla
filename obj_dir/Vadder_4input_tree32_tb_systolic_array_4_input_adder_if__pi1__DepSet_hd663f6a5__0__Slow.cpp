// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadder_4input_tree32_tb.h for the primary calling header

#include "Vadder_4input_tree32_tb__pch.h"
#include "Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1.h"

VL_ATTR_COLD void Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1___ctor_var_reset(Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1___ctor_var_reset\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->out = VL_RAND_RESET_Q(35);
}
