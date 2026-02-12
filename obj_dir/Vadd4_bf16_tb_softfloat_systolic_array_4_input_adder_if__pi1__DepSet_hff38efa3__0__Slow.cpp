// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd4_bf16_tb_softfloat.h for the primary calling header

#include "Vadd4_bf16_tb_softfloat__pch.h"
#include "Vadd4_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1.h"

VL_ATTR_COLD void Vadd4_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1___ctor_var_reset(Vadd4_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vadd4_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1___ctor_var_reset\n"); );
    Vadd4_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->out = VL_RAND_RESET_I(16);
}
