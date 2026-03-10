// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vadd4_fp32accum_bf16_tb_softfloat.h for the primary calling header

#ifndef VERILATED_VADD4_FP32ACCUM_BF16_TB_SOFTFLOAT_SYSTOLIC_ARRAY_4_INPUT_ADDER_IF__PI1_H_
#define VERILATED_VADD4_FP32ACCUM_BF16_TB_SOFTFLOAT_SYSTOLIC_ARRAY_4_INPUT_ADDER_IF__PI1_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vadd4_fp32accum_bf16_tb_softfloat__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vadd4_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    IData/*31:0*/ out;

    // INTERNAL VARIABLES
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vadd4_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1(Vadd4_fp32accum_bf16_tb_softfloat__Syms* symsp, const char* v__name);
    ~Vadd4_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1();
    VL_UNCOPYABLE(Vadd4_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vadd4_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1* obj);

#endif  // guard
