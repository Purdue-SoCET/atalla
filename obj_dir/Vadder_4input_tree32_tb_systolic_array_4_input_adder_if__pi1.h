// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vadder_4input_tree32_tb.h for the primary calling header

#ifndef VERILATED_VADDER_4INPUT_TREE32_TB_SYSTOLIC_ARRAY_4_INPUT_ADDER_IF__PI1_H_
#define VERILATED_VADDER_4INPUT_TREE32_TB_SYSTOLIC_ARRAY_4_INPUT_ADDER_IF__PI1_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vadder_4input_tree32_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    QData/*34:0*/ out;

    // INTERNAL VARIABLES
    Vadder_4input_tree32_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1(Vadder_4input_tree32_tb__Syms* symsp, const char* v__name);
    ~Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1();
    VL_UNCOPYABLE(Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* obj);

#endif  // guard
