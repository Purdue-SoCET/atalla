// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd32_fp32accum_bf16_tb_softfloat.h for the primary calling header

#include "Vadd32_fp32accum_bf16_tb_softfloat__pch.h"

void Vadd32_fp32accum_bf16_tb_softfloat___024root___ctor_var_reset(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);

Vadd32_fp32accum_bf16_tb_softfloat___024root::Vadd32_fp32accum_bf16_tb_softfloat___024root(Vadd32_fp32accum_bf16_tb_softfloat__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
    , __Vm_mtaskstate_6(1U)
    , __Vm_mtaskstate_4(1U)
    , __Vm_mtaskstate_2(1U)
    , __Vm_mtaskstate_7(1U)
    , __Vm_mtaskstate_3(1U)
    , __Vm_mtaskstate_5(1U)
    , __Vm_mtaskstate_final__0nba(2U)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vadd32_fp32accum_bf16_tb_softfloat___024root___ctor_var_reset(this);
}

void Vadd32_fp32accum_bf16_tb_softfloat___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vadd32_fp32accum_bf16_tb_softfloat___024root::~Vadd32_fp32accum_bf16_tb_softfloat___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
