// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsysarr_OUT_FIFO.h for the primary calling header

#include "Vsysarr_OUT_FIFO__pch.h"
#include "Vsysarr_OUT_FIFO__Syms.h"
#include "Vsysarr_OUT_FIFO___024root.h"

void Vsysarr_OUT_FIFO___024root___ctor_var_reset(Vsysarr_OUT_FIFO___024root* vlSelf);

Vsysarr_OUT_FIFO___024root::Vsysarr_OUT_FIFO___024root(Vsysarr_OUT_FIFO__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vsysarr_OUT_FIFO___024root___ctor_var_reset(this);
}

void Vsysarr_OUT_FIFO___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vsysarr_OUT_FIFO___024root::~Vsysarr_OUT_FIFO___024root() {
}
