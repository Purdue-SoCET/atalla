// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VADD32_FP32ACCUM_BF16_TB_SOFTFLOAT__SYMS_H_
#define VERILATED_VADD32_FP32ACCUM_BF16_TB_SOFTFLOAT__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vadd32_fp32accum_bf16_tb_softfloat.h"

// INCLUDE MODULE CLASSES
#include "Vadd32_fp32accum_bf16_tb_softfloat___024root.h"
#include "Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1.h"
#include "Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi2.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vadd32_fp32accum_bf16_tb_softfloat__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vadd32_fp32accum_bf16_tb_softfloat* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vadd32_fp32accum_bf16_tb_softfloat___024root TOP;
    Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1 TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__0__KET__;
    Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1 TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__1__KET__;
    Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1 TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__2__KET__;
    Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1 TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__3__KET__;
    Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1 TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__4__KET__;
    Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1 TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__5__KET__;
    Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1 TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__6__KET__;
    Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1 TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__7__KET__;
    Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi2 TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage2_if__BRA__0__KET__;
    Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi2 TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage2_if__BRA__1__KET__;
    Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi2 TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if;

    // CONSTRUCTORS
    Vadd32_fp32accum_bf16_tb_softfloat__Syms(VerilatedContext* contextp, const char* namep, Vadd32_fp32accum_bf16_tb_softfloat* modelp);
    ~Vadd32_fp32accum_bf16_tb_softfloat__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
