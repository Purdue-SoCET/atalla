// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsysarr_PS_FIFO.h for the primary calling header

#ifndef VERILATED_VSYSARR_PS_FIFO_SYSTOLIC_ARRAY_PS_FIFO_IF_H_
#define VERILATED_VSYSARR_PS_FIFO_SYSTOLIC_ARRAY_PS_FIFO_IF_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vsysarr_PS_FIFO__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsysarr_PS_FIFO_systolic_array_PS_FIFO_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ load;
    CData/*0:0*/ shift;
    QData/*63:0*/ load_values;

    // INTERNAL VARIABLES
    Vsysarr_PS_FIFO__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsysarr_PS_FIFO_systolic_array_PS_FIFO_if(Vsysarr_PS_FIFO__Syms* symsp, const char* v__name);
    ~Vsysarr_PS_FIFO_systolic_array_PS_FIFO_if();
    VL_UNCOPYABLE(Vsysarr_PS_FIFO_systolic_array_PS_FIFO_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vsysarr_PS_FIFO_systolic_array_PS_FIFO_if* obj);

#endif  // guard
