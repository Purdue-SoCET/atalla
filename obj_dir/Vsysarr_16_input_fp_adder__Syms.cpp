// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vsysarr_16_input_fp_adder__pch.h"
#include "Vsysarr_16_input_fp_adder.h"
#include "Vsysarr_16_input_fp_adder___024root.h"

// FUNCTIONS
Vsysarr_16_input_fp_adder__Syms::~Vsysarr_16_input_fp_adder__Syms()
{
}

Vsysarr_16_input_fp_adder__Syms::Vsysarr_16_input_fp_adder__Syms(VerilatedContext* contextp, const char* namep, Vsysarr_16_input_fp_adder* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(1292);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
