// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd32_fp32accum_bf16_tb_softfloat.h for the primary calling header

#include "Vadd32_fp32accum_bf16_tb_softfloat__pch.h"

void Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if___ctor_var_reset(Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if* vlSelf);

Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if::Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if() = default;
Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if::~Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if() = default;

void Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if::ctor(Vadd32_fp32accum_bf16_tb_softfloat__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if___ctor_var_reset(this);
}

void Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
