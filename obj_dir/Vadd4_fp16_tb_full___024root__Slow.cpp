// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd4_fp16_tb_full.h for the primary calling header

#include "Vadd4_fp16_tb_full__pch.h"
#include "Vadd4_fp16_tb_full__Syms.h"
#include "Vadd4_fp16_tb_full___024root.h"

void Vadd4_fp16_tb_full___024root___ctor_var_reset(Vadd4_fp16_tb_full___024root* vlSelf);

Vadd4_fp16_tb_full___024root::Vadd4_fp16_tb_full___024root(Vadd4_fp16_tb_full__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vadd4_fp16_tb_full___024root___ctor_var_reset(this);
}

void Vadd4_fp16_tb_full___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vadd4_fp16_tb_full___024root::~Vadd4_fp16_tb_full___024root() {
}
