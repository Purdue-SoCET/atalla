// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaddn_fp32accum_fp16_tb_softfloat.h for the primary calling header

#include "Vaddn_fp32accum_fp16_tb_softfloat__pch.h"
#include "Vaddn_fp32accum_fp16_tb_softfloat__Syms.h"
#include "Vaddn_fp32accum_fp16_tb_softfloat___024root.h"

void Vaddn_fp32accum_fp16_tb_softfloat___024root___ctor_var_reset(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf);

Vaddn_fp32accum_fp16_tb_softfloat___024root::Vaddn_fp32accum_fp16_tb_softfloat___024root(Vaddn_fp32accum_fp16_tb_softfloat__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vaddn_fp32accum_fp16_tb_softfloat___024root___ctor_var_reset(this);
}

void Vaddn_fp32accum_fp16_tb_softfloat___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vaddn_fp32accum_fp16_tb_softfloat___024root::~Vaddn_fp32accum_fp16_tb_softfloat___024root() {
}
