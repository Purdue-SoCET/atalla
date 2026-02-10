// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vadd4_fp16_tb_full__pch.h"
#include "Vadd4_fp16_tb_full.h"
#include "Vadd4_fp16_tb_full___024root.h"

// FUNCTIONS
Vadd4_fp16_tb_full__Syms::~Vadd4_fp16_tb_full__Syms()
{
}

Vadd4_fp16_tb_full__Syms::Vadd4_fp16_tb_full__Syms(VerilatedContext* contextp, const char* namep, Vadd4_fp16_tb_full* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(332);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
