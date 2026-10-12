// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VADD_FP16_TB_FULL__SYMS_H_
#define VERILATED_VADD_FP16_TB_FULL__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vadd_fp16_tb_full.h"

// INCLUDE MODULE CLASSES
#include "Vadd_fp16_tb_full___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vadd_fp16_tb_full__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vadd_fp16_tb_full* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vadd_fp16_tb_full___024root    TOP;

    // CONSTRUCTORS
    Vadd_fp16_tb_full__Syms(VerilatedContext* contextp, const char* namep, Vadd_fp16_tb_full* modelp);
    ~Vadd_fp16_tb_full__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
