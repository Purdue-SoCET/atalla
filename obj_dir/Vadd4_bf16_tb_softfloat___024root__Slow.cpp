// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd4_bf16_tb_softfloat.h for the primary calling header

#include "Vadd4_bf16_tb_softfloat__pch.h"
#include "Vadd4_bf16_tb_softfloat__Syms.h"
#include "Vadd4_bf16_tb_softfloat___024root.h"

void Vadd4_bf16_tb_softfloat___024root___ctor_var_reset(Vadd4_bf16_tb_softfloat___024root* vlSelf);

Vadd4_bf16_tb_softfloat___024root::Vadd4_bf16_tb_softfloat___024root(Vadd4_bf16_tb_softfloat__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vadd4_bf16_tb_softfloat___024root___ctor_var_reset(this);
}

void Vadd4_bf16_tb_softfloat___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vadd4_bf16_tb_softfloat___024root::~Vadd4_bf16_tb_softfloat___024root() {
}
