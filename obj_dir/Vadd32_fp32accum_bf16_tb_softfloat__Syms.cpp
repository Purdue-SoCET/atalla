// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vadd32_fp32accum_bf16_tb_softfloat__pch.h"
#include "Vadd32_fp32accum_bf16_tb_softfloat.h"
#include "Vadd32_fp32accum_bf16_tb_softfloat___024root.h"
#include "Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if.h"
#include "Vadd32_fp32accum_bf16_tb_softfloat_systolic_array_4_input_adder_if__pi1.h"

// FUNCTIONS
Vadd32_fp32accum_bf16_tb_softfloat__Syms::~Vadd32_fp32accum_bf16_tb_softfloat__Syms()
{
}

Vadd32_fp32accum_bf16_tb_softfloat__Syms::Vadd32_fp32accum_bf16_tb_softfloat__Syms(VerilatedContext* contextp, const char* namep, Vadd32_fp32accum_bf16_tb_softfloat* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__0__KET__{this, Verilated::catName(namep, "add32_fp32accum_bf16_tb_softfloat.dut.stage1_if[0]")}
    , TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__1__KET__{this, Verilated::catName(namep, "add32_fp32accum_bf16_tb_softfloat.dut.stage1_if[1]")}
    , TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__2__KET__{this, Verilated::catName(namep, "add32_fp32accum_bf16_tb_softfloat.dut.stage1_if[2]")}
    , TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__3__KET__{this, Verilated::catName(namep, "add32_fp32accum_bf16_tb_softfloat.dut.stage1_if[3]")}
    , TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__4__KET__{this, Verilated::catName(namep, "add32_fp32accum_bf16_tb_softfloat.dut.stage1_if[4]")}
    , TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__5__KET__{this, Verilated::catName(namep, "add32_fp32accum_bf16_tb_softfloat.dut.stage1_if[5]")}
    , TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__6__KET__{this, Verilated::catName(namep, "add32_fp32accum_bf16_tb_softfloat.dut.stage1_if[6]")}
    , TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__7__KET__{this, Verilated::catName(namep, "add32_fp32accum_bf16_tb_softfloat.dut.stage1_if[7]")}
    , TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage2_if__BRA__0__KET__{this, Verilated::catName(namep, "add32_fp32accum_bf16_tb_softfloat.dut.stage2_if[0]")}
    , TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage2_if__BRA__1__KET__{this, Verilated::catName(namep, "add32_fp32accum_bf16_tb_softfloat.dut.stage2_if[1]")}
    , TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if{this, Verilated::catName(namep, "add32_fp32accum_bf16_tb_softfloat.dut.stage3_if")}
{
        // Check resources
        Verilated::stackCheck(31664);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__0__KET__ = &TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__0__KET__;
    TOP.__PVT__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__1__KET__ = &TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__1__KET__;
    TOP.__PVT__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__2__KET__ = &TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__2__KET__;
    TOP.__PVT__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__3__KET__ = &TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__3__KET__;
    TOP.__PVT__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__4__KET__ = &TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__4__KET__;
    TOP.__PVT__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__5__KET__ = &TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__5__KET__;
    TOP.__PVT__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__6__KET__ = &TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__6__KET__;
    TOP.__PVT__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__7__KET__ = &TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__7__KET__;
    TOP.__PVT__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage2_if__BRA__0__KET__ = &TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage2_if__BRA__0__KET__;
    TOP.__PVT__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage2_if__BRA__1__KET__ = &TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage2_if__BRA__1__KET__;
    TOP.__PVT__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if = &TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__0__KET__.__Vconfigure(true);
    TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__1__KET__.__Vconfigure(false);
    TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__2__KET__.__Vconfigure(false);
    TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__3__KET__.__Vconfigure(false);
    TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__4__KET__.__Vconfigure(false);
    TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__5__KET__.__Vconfigure(false);
    TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__6__KET__.__Vconfigure(false);
    TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__7__KET__.__Vconfigure(false);
    TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage2_if__BRA__0__KET__.__Vconfigure(true);
    TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage2_if__BRA__1__KET__.__Vconfigure(false);
    TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.__Vconfigure(false);
}
