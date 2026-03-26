// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSYSARR_16_INPUT_FP_ADDER__SYMS_H_
#define VERILATED_VSYSARR_16_INPUT_FP_ADDER__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vsysarr_16_input_fp_adder.h"

// INCLUDE MODULE CLASSES
#include "Vsysarr_16_input_fp_adder___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vsysarr_16_input_fp_adder__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vsysarr_16_input_fp_adder* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vsysarr_16_input_fp_adder___024root TOP;

    // CONSTRUCTORS
    Vsysarr_16_input_fp_adder__Syms(VerilatedContext* contextp, const char* namep, Vsysarr_16_input_fp_adder* modelp);
    ~Vsysarr_16_input_fp_adder__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
