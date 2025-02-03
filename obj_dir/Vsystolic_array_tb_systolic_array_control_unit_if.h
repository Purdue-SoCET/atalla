// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsystolic_array_tb.h for the primary calling header

#ifndef VERILATED_VSYSTOLIC_ARRAY_TB_SYSTOLIC_ARRAY_CONTROL_UNIT_IF_H_
#define VERILATED_VSYSTOLIC_ARRAY_TB_SYSTOLIC_ARRAY_CONTROL_UNIT_IF_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vsystolic_array_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsystolic_array_tb_systolic_array_control_unit_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ input_type;
    CData/*0:0*/ input_load;
    CData/*0:0*/ weight_load;
    CData/*0:0*/ partials_load;
    CData/*0:0*/ MAC_start;
    CData/*2:0*/ MAC_count;
    CData/*0:0*/ add_start;
    CData/*1:0*/ add_count;
    CData/*0:0*/ fifo_shift;
    CData/*0:0*/ out_fifo_shift;
    CData/*1:0*/ input_row;
    CData/*1:0*/ weight_row;
    CData/*1:0*/ partials_row;
    VlUnpacked<CData/*3:0*/, 3> iteration;

    // INTERNAL VARIABLES
    Vsystolic_array_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsystolic_array_tb_systolic_array_control_unit_if(Vsystolic_array_tb__Syms* symsp, const char* v__name);
    ~Vsystolic_array_tb_systolic_array_control_unit_if();
    VL_UNCOPYABLE(Vsystolic_array_tb_systolic_array_control_unit_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vsystolic_array_tb_systolic_array_control_unit_if* obj);

#endif  // guard
