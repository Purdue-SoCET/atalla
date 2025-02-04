// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsystolic_array_tb.h for the primary calling header

#include "Vsystolic_array_tb__pch.h"
#include "Vsystolic_array_tb__Syms.h"
#include "Vsystolic_array_tb_systolic_array_if.h"

void Vsystolic_array_tb_systolic_array_if___ctor_var_reset(Vsystolic_array_tb_systolic_array_if* vlSelf);

Vsystolic_array_tb_systolic_array_if::Vsystolic_array_tb_systolic_array_if(Vsystolic_array_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vsystolic_array_tb_systolic_array_if___ctor_var_reset(this);
}

void Vsystolic_array_tb_systolic_array_if::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vsystolic_array_tb_systolic_array_if::~Vsystolic_array_tb_systolic_array_if() {
}
