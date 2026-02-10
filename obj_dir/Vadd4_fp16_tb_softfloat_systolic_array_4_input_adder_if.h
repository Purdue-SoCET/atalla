// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vadd4_fp16_tb_softfloat.h for the primary calling header

#ifndef VERILATED_VADD4_FP16_TB_SOFTFLOAT_SYSTOLIC_ARRAY_4_INPUT_ADDER_IF_H_
#define VERILATED_VADD4_FP16_TB_SOFTFLOAT_SYSTOLIC_ARRAY_4_INPUT_ADDER_IF_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vadd4_fp16_tb_softfloat__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vadd4_fp16_tb_softfloat_systolic_array_4_input_adder_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    SData/*15:0*/ out;

    // INTERNAL VARIABLES
    Vadd4_fp16_tb_softfloat__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vadd4_fp16_tb_softfloat_systolic_array_4_input_adder_if(Vadd4_fp16_tb_softfloat__Syms* symsp, const char* v__name);
    ~Vadd4_fp16_tb_softfloat_systolic_array_4_input_adder_if();
    VL_UNCOPYABLE(Vadd4_fp16_tb_softfloat_systolic_array_4_input_adder_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vadd4_fp16_tb_softfloat_systolic_array_4_input_adder_if* obj);

#endif  // guard
