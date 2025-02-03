// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsystolic_array_tb.h for the primary calling header

#ifndef VERILATED_VSYSTOLIC_ARRAY_TB_SYSTOLIC_ARRAY_IF_H_
#define VERILATED_VSYSTOLIC_ARRAY_TB_SYSTOLIC_ARRAY_IF_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vsystolic_array_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsystolic_array_tb_systolic_array_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ weight_en;
    CData/*0:0*/ input_en;
    CData/*0:0*/ partial_en;
    CData/*0:0*/ out_en;
    CData/*0:0*/ drained;
    CData/*1:0*/ row_en;
    CData/*1:0*/ row_out;
    QData/*63:0*/ array_in;
    QData/*63:0*/ array_in_partials;
    QData/*63:0*/ array_output;

    // INTERNAL VARIABLES
    Vsystolic_array_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsystolic_array_tb_systolic_array_if(Vsystolic_array_tb__Syms* symsp, const char* v__name);
    ~Vsystolic_array_tb_systolic_array_if();
    VL_UNCOPYABLE(Vsystolic_array_tb_systolic_array_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vsystolic_array_tb_systolic_array_if* obj);

#endif  // guard
