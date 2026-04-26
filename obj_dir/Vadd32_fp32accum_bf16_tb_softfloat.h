// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VADD32_FP32ACCUM_BF16_TB_SOFTFLOAT_H_
#define VERILATED_VADD32_FP32ACCUM_BF16_TB_SOFTFLOAT_H_  // guard

#include "verilated.h"
#include "verilated_threads.h"

class Vadd32_fp32accum_bf16_tb_softfloat__Syms;
class Vadd32_fp32accum_bf16_tb_softfloat___024root;
class VerilatedVcdC;
class Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1;
class Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi2;


// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vadd32_fp32accum_bf16_tb_softfloat VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const vlSymsp;

  public:

    // CONSTEXPR CAPABILITIES
    // Verilated with --trace?
    static constexpr bool traceCapable = true;

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.
    Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1* const __PVT__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__7__KET__;
    Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1* const __PVT__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__6__KET__;
    Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1* const __PVT__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__5__KET__;
    Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1* const __PVT__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__4__KET__;
    Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1* const __PVT__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__3__KET__;
    Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1* const __PVT__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__2__KET__;
    Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1* const __PVT__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__1__KET__;
    Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1* const __PVT__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__0__KET__;
    Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi2* const __PVT__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage2_if__BRA__1__KET__;
    Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi2* const __PVT__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage2_if__BRA__0__KET__;
    Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi2* const __PVT__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if;

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vadd32_fp32accum_bf16_tb_softfloat___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vadd32_fp32accum_bf16_tb_softfloat(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vadd32_fp32accum_bf16_tb_softfloat(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vadd32_fp32accum_bf16_tb_softfloat();
  private:
    VL_UNCOPYABLE(Vadd32_fp32accum_bf16_tb_softfloat);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedTraceBaseC* tfp, int levels, int options = 0) { contextp()->trace(tfp, levels, options); }
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
    std::unique_ptr<VerilatedTraceConfig> traceConfig() const override final;
  private:
    // Internal functions - trace registration
    void traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options);
};

#endif  // guard
