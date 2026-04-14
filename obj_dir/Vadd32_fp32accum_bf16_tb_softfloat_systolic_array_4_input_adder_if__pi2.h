// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vadd32_fp32accum_bf16_tb_softfloat.h for the primary calling header

#ifndef VERILATED_VADD32_FP32ACCUM_BF16_TB_SOFTFLOAT_SYSTOLIC_ARRAY_4_INPUT_ADDER_IF__PI2_H_
#define VERILATED_VADD32_FP32ACCUM_BF16_TB_SOFTFLOAT_SYSTOLIC_ARRAY_4_INPUT_ADDER_IF__PI2_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vadd32_fp32accum_bf16_tb_softfloat__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi2 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    QData/*34:0*/ out;

    // INTERNAL VARIABLES
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi2(Vadd32_fp32accum_bf16_tb_softfloat__Syms* symsp, const char* v__name);
    ~Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi2();
    VL_UNCOPYABLE(Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi2);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi2* obj);

#endif  // guard
