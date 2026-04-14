// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vadd4_fp32_tb_softfloat__pch.h"
#include "Vadd4_fp32_tb_softfloat.h"
#include "Vadd4_fp32_tb_softfloat___024root.h"
#include "Vadd4_fp32_tb_softfloat_systolic_array_4_input_adder_if__pi1.h"

// FUNCTIONS
Vadd4_fp32_tb_softfloat__Syms::~Vadd4_fp32_tb_softfloat__Syms()
{
#ifdef VM_TRACE
    if (__Vm_dumping) _traceDumpClose();
#endif  // VM_TRACE
}

void Vadd4_fp32_tb_softfloat__Syms::_traceDump() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    __Vm_dumperp->dump(VL_TIME_Q());
}

void Vadd4_fp32_tb_softfloat__Syms::_traceDumpOpen() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    if (VL_UNLIKELY(!__Vm_dumperp)) {
        __Vm_dumperp = new VerilatedVcdC();
        __Vm_modelp->trace(__Vm_dumperp, 0, 0);
        std::string dumpfile = _vm_contextp__->dumpfileCheck();
        __Vm_dumperp->open(dumpfile.c_str());
        __Vm_dumping = true;
    }
}

void Vadd4_fp32_tb_softfloat__Syms::_traceDumpClose() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    __Vm_dumping = false;
    VL_DO_CLEAR(delete __Vm_dumperp, __Vm_dumperp = nullptr);
}

Vadd4_fp32_tb_softfloat__Syms::Vadd4_fp32_tb_softfloat__Syms(VerilatedContext* contextp, const char* namep, Vadd4_fp32_tb_softfloat* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__add4_fp32_tb_softfloat__DOT__add_if{this, Verilated::catName(namep, "add4_fp32_tb_softfloat.add_if")}
{
        // Check resources
        Verilated::stackCheck(628);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__add4_fp32_tb_softfloat__DOT__add_if = &TOP__add4_fp32_tb_softfloat__DOT__add_if;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__add4_fp32_tb_softfloat__DOT__add_if.__Vconfigure(true);
}
