// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd4_fp32accum_bf16_tb_softfloat.h for the primary calling header

#include "Vadd4_fp32accum_bf16_tb_softfloat__pch.h"
#include "Vadd4_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if.h"

VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if___ctor_var_reset(Vadd4_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vadd4_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if___ctor_var_reset\n"); );
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->out = VL_RAND_RESET_I(32);
}
