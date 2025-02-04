// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsysarr_OUT_FIFO.h for the primary calling header

#include "Vsysarr_OUT_FIFO__pch.h"
#include "Vsysarr_OUT_FIFO__Syms.h"
#include "Vsysarr_OUT_FIFO_systolic_array_OUT_FIFO_if.h"

void Vsysarr_OUT_FIFO_systolic_array_OUT_FIFO_if___ctor_var_reset(Vsysarr_OUT_FIFO_systolic_array_OUT_FIFO_if* vlSelf);

Vsysarr_OUT_FIFO_systolic_array_OUT_FIFO_if::Vsysarr_OUT_FIFO_systolic_array_OUT_FIFO_if(Vsysarr_OUT_FIFO__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vsysarr_OUT_FIFO_systolic_array_OUT_FIFO_if___ctor_var_reset(this);
}

void Vsysarr_OUT_FIFO_systolic_array_OUT_FIFO_if::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vsysarr_OUT_FIFO_systolic_array_OUT_FIFO_if::~Vsysarr_OUT_FIFO_systolic_array_OUT_FIFO_if() {
}
