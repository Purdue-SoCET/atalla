// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd_fp16_tb_full.h for the primary calling header

#include "Vadd_fp16_tb_full__pch.h"
#include "Vadd_fp16_tb_full__Syms.h"
#include "Vadd_fp16_tb_full___024root.h"

void Vadd_fp16_tb_full___024root___ctor_var_reset(Vadd_fp16_tb_full___024root* vlSelf);

Vadd_fp16_tb_full___024root::Vadd_fp16_tb_full___024root(Vadd_fp16_tb_full__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vadd_fp16_tb_full___024root___ctor_var_reset(this);
}

void Vadd_fp16_tb_full___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vadd_fp16_tb_full___024root::~Vadd_fp16_tb_full___024root() {
}
