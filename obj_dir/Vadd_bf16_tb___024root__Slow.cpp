// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd_bf16_tb.h for the primary calling header

#include "Vadd_bf16_tb__pch.h"
#include "Vadd_bf16_tb__Syms.h"
#include "Vadd_bf16_tb___024root.h"

void Vadd_bf16_tb___024root___ctor_var_reset(Vadd_bf16_tb___024root* vlSelf);

Vadd_bf16_tb___024root::Vadd_bf16_tb___024root(Vadd_bf16_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vadd_bf16_tb___024root___ctor_var_reset(this);
}

void Vadd_bf16_tb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vadd_bf16_tb___024root::~Vadd_bf16_tb___024root() {
}
