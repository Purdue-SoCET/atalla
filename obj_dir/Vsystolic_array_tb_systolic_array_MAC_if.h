// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsystolic_array_tb.h for the primary calling header

#ifndef VERILATED_VSYSTOLIC_ARRAY_TB_SYSTOLIC_ARRAY_MAC_IF_H_
#define VERILATED_VSYSTOLIC_ARRAY_TB_SYSTOLIC_ARRAY_MAC_IF_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vsystolic_array_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsystolic_array_tb_systolic_array_MAC_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    SData/*15:0*/ out_accumulate;

    // INTERNAL VARIABLES
    Vsystolic_array_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsystolic_array_tb_systolic_array_MAC_if(Vsystolic_array_tb__Syms* symsp, const char* v__name);
    ~Vsystolic_array_tb_systolic_array_MAC_if();
    VL_UNCOPYABLE(Vsystolic_array_tb_systolic_array_MAC_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vsystolic_array_tb_systolic_array_MAC_if* obj);

#endif  // guard
