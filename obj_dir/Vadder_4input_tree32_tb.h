// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VADDER_4INPUT_TREE32_TB_H_
#define VERILATED_VADDER_4INPUT_TREE32_TB_H_  // guard

#include "verilated.h"

class Vadder_4input_tree32_tb__Syms;
class Vadder_4input_tree32_tb___024root;
class VerilatedVcdC;
class Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3;
class Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1;


// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vadder_4input_tree32_tb VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vadder_4input_tree32_tb__Syms* const vlSymsp;

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
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__31__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__30__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__29__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__28__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__27__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__26__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__25__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__24__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__23__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__22__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__21__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__20__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__19__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__18__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__17__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__16__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__15__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__14__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__13__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__12__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__11__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__10__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__9__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__8__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__7__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__6__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__5__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__4__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__3__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__2__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__1__KET__;
    Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__0__KET__;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__2__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__3__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__4__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__5__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__6__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__7__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__8__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__9__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__10__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__11__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__12__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__13__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__14__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__15__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__16__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__17__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__18__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__19__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__20__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__21__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__22__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__23__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__24__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__25__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__26__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__27__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__28__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__29__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__30__KET____DOT__stage_inst;
    Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* const __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__31__KET____DOT__stage_inst;

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vadder_4input_tree32_tb___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vadder_4input_tree32_tb(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vadder_4input_tree32_tb(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vadder_4input_tree32_tb();
  private:
    VL_UNCOPYABLE(Vadder_4input_tree32_tb);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); eval_end_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step();
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
