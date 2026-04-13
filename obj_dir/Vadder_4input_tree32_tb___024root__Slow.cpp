// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadder_4input_tree32_tb.h for the primary calling header

#include "Vadder_4input_tree32_tb__pch.h"
#include "Vadder_4input_tree32_tb__Syms.h"
#include "Vadder_4input_tree32_tb___024root.h"

void Vadder_4input_tree32_tb___024root___ctor_var_reset(Vadder_4input_tree32_tb___024root* vlSelf);

Vadder_4input_tree32_tb___024root::Vadder_4input_tree32_tb___024root(Vadder_4input_tree32_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vadder_4input_tree32_tb___024root___ctor_var_reset(this);
}

void Vadder_4input_tree32_tb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vadder_4input_tree32_tb___024root::~Vadder_4input_tree32_tb___024root() {
}
