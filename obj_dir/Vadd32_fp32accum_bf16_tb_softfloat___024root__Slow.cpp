// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd32_fp32accum_bf16_tb_softfloat.h for the primary calling header

#include "Vadd32_fp32accum_bf16_tb_softfloat__pch.h"

void Vadd32_fp32accum_bf16_tb_softfloat___024root___ctor_var_reset(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);

Vadd32_fp32accum_bf16_tb_softfloat___024root::Vadd32_fp32accum_bf16_tb_softfloat___024root(Vadd32_fp32accum_bf16_tb_softfloat__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
    , __Vm_mtaskstate_19(2U)
    , __Vm_mtaskstate_27(3U)
    , __Vm_mtaskstate_21(3U)
    , __Vm_mtaskstate_13(5U)
    , __Vm_mtaskstate_22(3U)
    , __Vm_mtaskstate_14(4U)
    , __Vm_mtaskstate_23(3U)
    , __Vm_mtaskstate_15(6U)
    , __Vm_mtaskstate_20(2U)
    , __Vm_mtaskstate_16(3U)
    , __Vm_mtaskstate_24(2U)
    , __Vm_mtaskstate_17(4U)
    , __Vm_mtaskstate_25(2U)
    , __Vm_mtaskstate_11(9U)
    , __Vm_mtaskstate_12(8U)
    , __Vm_mtaskstate_18(3U)
    , __Vm_mtaskstate_28(4U)
    , __Vm_mtaskstate_final__0nba(8U)
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
