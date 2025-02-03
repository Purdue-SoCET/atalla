// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsysarr_PS_FIFO.h for the primary calling header

#include "Vsysarr_PS_FIFO__pch.h"
#include "Vsysarr_PS_FIFO__Syms.h"
#include "Vsysarr_PS_FIFO_systolic_array_PS_FIFO_if.h"

void Vsysarr_PS_FIFO_systolic_array_PS_FIFO_if___ctor_var_reset(Vsysarr_PS_FIFO_systolic_array_PS_FIFO_if* vlSelf);

Vsysarr_PS_FIFO_systolic_array_PS_FIFO_if::Vsysarr_PS_FIFO_systolic_array_PS_FIFO_if(Vsysarr_PS_FIFO__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vsysarr_PS_FIFO_systolic_array_PS_FIFO_if___ctor_var_reset(this);
}

void Vsysarr_PS_FIFO_systolic_array_PS_FIFO_if::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vsysarr_PS_FIFO_systolic_array_PS_FIFO_if::~Vsysarr_PS_FIFO_systolic_array_PS_FIFO_if() {
}
