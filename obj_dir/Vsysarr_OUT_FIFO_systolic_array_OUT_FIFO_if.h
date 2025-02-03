// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsysarr_OUT_FIFO.h for the primary calling header

#ifndef VERILATED_VSYSARR_OUT_FIFO_SYSTOLIC_ARRAY_OUT_FIFO_IF_H_
#define VERILATED_VSYSARR_OUT_FIFO_SYSTOLIC_ARRAY_OUT_FIFO_IF_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vsysarr_OUT_FIFO__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsysarr_OUT_FIFO_systolic_array_OUT_FIFO_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ shift;
    SData/*15:0*/ shift_value;

    // INTERNAL VARIABLES
    Vsysarr_OUT_FIFO__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsysarr_OUT_FIFO_systolic_array_OUT_FIFO_if(Vsysarr_OUT_FIFO__Syms* symsp, const char* v__name);
    ~Vsysarr_OUT_FIFO_systolic_array_OUT_FIFO_if();
    VL_UNCOPYABLE(Vsysarr_OUT_FIFO_systolic_array_OUT_FIFO_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vsysarr_OUT_FIFO_systolic_array_OUT_FIFO_if* obj);

#endif  // guard
