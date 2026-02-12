// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vadd4_fp16_tb_softfloat__pch.h"
#include "Vadd4_fp16_tb_softfloat.h"
#include "Vadd4_fp16_tb_softfloat___024root.h"
#include "Vadd4_fp16_tb_softfloat_systolic_array_4_input_adder_if.h"

// FUNCTIONS
Vadd4_fp16_tb_softfloat__Syms::~Vadd4_fp16_tb_softfloat__Syms()
{
}

Vadd4_fp16_tb_softfloat__Syms::Vadd4_fp16_tb_softfloat__Syms(VerilatedContext* contextp, const char* namep, Vadd4_fp16_tb_softfloat* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__add4_fp16_tb_softfloat__DOT__add_if{this, Verilated::catName(namep, "add4_fp16_tb_softfloat.add_if")}
{
        // Check resources
        Verilated::stackCheck(1026);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__add4_fp16_tb_softfloat__DOT__add_if = &TOP__add4_fp16_tb_softfloat__DOT__add_if;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__add4_fp16_tb_softfloat__DOT__add_if.__Vconfigure(true);
}
