// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vsysarr_FIFO__pch.h"
#include "Vsysarr_FIFO.h"
#include "Vsysarr_FIFO___024root.h"
#include "Vsysarr_FIFO_systolic_array_FIFO_if.h"

// FUNCTIONS
Vsysarr_FIFO__Syms::~Vsysarr_FIFO__Syms()
{
}

Vsysarr_FIFO__Syms::Vsysarr_FIFO__Syms(VerilatedContext* contextp, const char* namep, Vsysarr_FIFO* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__sysarr_FIFO_tb__DOT__fifo_if{this, Verilated::catName(namep, "sysarr_FIFO_tb.fifo_if")}
{
        // Check resources
        Verilated::stackCheck(34);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-9);
    // Setup each module's pointers to their submodules
    TOP.__PVT__sysarr_FIFO_tb__DOT__fifo_if = &TOP__sysarr_FIFO_tb__DOT__fifo_if;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__sysarr_FIFO_tb__DOT__fifo_if.__Vconfigure(true);
}
