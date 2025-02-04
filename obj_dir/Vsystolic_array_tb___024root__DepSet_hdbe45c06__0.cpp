// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsystolic_array_tb.h for the primary calling header

#include "Vsystolic_array_tb__pch.h"
#include "Vsystolic_array_tb__Syms.h"
#include "Vsystolic_array_tb___024root.h"

VL_INLINE_OPT VlCoroutine Vsystolic_array_tb___024root___eval_initial__TOP__Vtiming__0(Vsystolic_array_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile(std::string{"dump.vcd"});
    vlSymsp->_traceDumpOpen();
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.weight_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0ULL;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials = 0ULL;
    vlSelfRef.systolic_array_tb__DOT__tb_nRST = 0U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         30);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         31);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f538__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         32);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.systolic_array_tb__DOT__tb_nRST = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         34);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         35);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("BASIC 2X2 Example with Simple Partials\n",0);
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.weight_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0x1000200000000ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         71);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.weight_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0x3000400000000ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         75);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.weight_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 2U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         79);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.weight_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 3U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         83);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.weight_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0x5000600000000ULL;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials = 0x10001ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         92);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 0U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         95);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         95);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0x7000800000000ULL;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials = 0x10001ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         101);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 0U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         104);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         104);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         104);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         104);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         104);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 2U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0ULL;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials = 0x1000100010001ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         110);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 0U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         113);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         113);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         113);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         113);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         113);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 3U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0ULL;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials = 0x1000100010001ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         119);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 0U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         122);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         122);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         122);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         122);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         122);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         122);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         123);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         123);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         123);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         123);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         123);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         123);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         124);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         124);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         124);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         124);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         124);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         124);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         125);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         125);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         125);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         125);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         125);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         125);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         126);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         126);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         126);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         126);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         126);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         126);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         127);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         127);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         127);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         127);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         127);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         127);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         128);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         128);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         128);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         128);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         128);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         128);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         129);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         129);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         129);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         129);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         129);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         129);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         130);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         130);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         130);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         130);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         130);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         130);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         131);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         131);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         131);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         131);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         131);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         131);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("array should be drained %1#\nfifos should have space  %1#\nFull 4X4 Example\n",0,
                 1,vlSymsp->TOP__systolic_array_tb__DOT__memory_if.drained,
                 1,((1U == (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__input_tracker)) 
                    | (0U == (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__input_tracker))));
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.weight_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0x7000400080005ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         140);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.weight_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0x7000300070008ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         144);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.weight_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 2U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0x5000400080008ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         148);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.weight_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 3U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0x3000600050002ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         152);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.weight_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0x8000600020005ULL;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials = 0x2000500080009ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         161);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 0U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         164);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         164);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         164);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         164);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         164);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0x1000600090001ULL;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials = 0x9000100090007ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         170);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 0U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         173);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         173);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         173);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         173);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         173);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 2U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0x3000700040009ULL;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials = 0x9000800010008ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         179);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 0U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         182);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         182);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         182);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         182);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         182);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 3U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0x3000500030007ULL;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials = 0x8000300010008ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         188);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 0U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         191);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         191);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         191);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         191);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         191);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         191);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         192);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         192);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         192);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         192);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         192);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         192);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         193);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         193);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         193);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         193);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         193);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         193);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         194);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         194);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         194);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         194);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         194);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         194);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         195);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         195);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         195);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         195);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         195);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         195);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         196);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         196);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         196);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         196);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         196);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         196);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         197);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         197);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         197);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         197);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         197);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         197);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         198);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         198);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         198);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         198);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         198);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         198);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         199);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         199);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         199);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         199);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         199);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         199);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         200);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         200);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         200);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         200);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         200);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         200);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("array should be drained %1#\nfifos should have space  %1#\n",0,
                 1,vlSymsp->TOP__systolic_array_tb__DOT__memory_if.drained,
                 1,((1U == (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__input_tracker)) 
                    | (0U == (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__input_tracker))));
    vlSelfRef.systolic_array_tb__DOT__tb_nRST = 0U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         30);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         31);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f538__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         32);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.systolic_array_tb__DOT__tb_nRST = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         34);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         35);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("Pipelined Example\n",0);
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.weight_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0x7000400080005ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         210);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.weight_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0x7000300070008ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         214);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.weight_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 2U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0x5000400080008ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         218);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.weight_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 3U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0x3000600050002ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         222);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.weight_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0x8000600020005ULL;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials = 0x2000500080009ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         231);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 0U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         234);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         234);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0x1000600090001ULL;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials = 0x9000100090007ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         240);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 0U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         243);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         243);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         243);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         243);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 2U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0x3000700040009ULL;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials = 0x9000800010008ULL;
    VL_WRITEF_NX("after iteration 1 of the first gemm, not all input rows have been loaded\nfifos should not have space  %1#\n",0,
                 1,((1U == (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__input_tracker)) 
                    | (0U == (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__input_tracker))));
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         251);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 0U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         254);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         254);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         254);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         254);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 3U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0x3000500030007ULL;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials = 0x8000300010008ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         260);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 0U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         263);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         263);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         263);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         263);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("after first array is fully loaded into array\narray should not be drained %1#\nfifos should have space  %1#\n",0,
                 1,vlSymsp->TOP__systolic_array_tb__DOT__memory_if.drained,
                 1,((1U == (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__input_tracker)) 
                    | (0U == (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__input_tracker))));
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0x5000900070002ULL;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials = 0x3000300010005ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         273);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 0U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         276);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         276);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         276);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         276);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0x4000900020009ULL;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials = 0x7000900070009ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         282);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 0U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         285);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         285);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         285);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         285);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 2U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0x5000200040007ULL;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials = 0x8000200010007ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         291);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 0U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         294);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         294);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         294);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         294);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en = 3U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in = 0x8000300010004ULL;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials = 0x7000800050002ULL;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         300);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en = 0U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         303);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         303);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         303);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         303);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         303);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         304);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         304);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         304);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         304);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         304);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         305);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         305);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         305);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         305);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         305);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         306);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         306);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         306);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         306);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         306);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         307);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         307);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         307);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         307);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         307);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         308);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         308);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         308);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         308);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         308);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         309);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         309);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         309);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         309);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         309);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         310);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         310);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         310);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         310);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         310);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         311);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         311);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         311);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         311);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         311);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         312);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         312);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         312);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         312);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h8059f569__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge systolic_array_tb.tb_clk)", 
                                                         "src/testbench/systolic_array_tb.sv", 
                                                         312);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("array should be drained %1#\nfifos should have space  %1#\n",0,
                 1,vlSymsp->TOP__systolic_array_tb__DOT__memory_if.drained,
                 1,((1U == (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__input_tracker)) 
                    | (0U == (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__input_tracker))));
    co_await vlSelfRef.__VdlySched.delay(0x32ULL, nullptr, 
                                         "src/testbench/systolic_array_tb.sv", 
                                         315);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_STOP_MT("src/testbench/systolic_array_tb.sv", 316, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsystolic_array_tb___024root___dump_triggers__act(Vsystolic_array_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vsystolic_array_tb___024root___eval_triggers__act(Vsystolic_array_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array_tb___024root___eval_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.systolic_array_tb__DOT__tb_clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__systolic_array_tb__DOT__tb_clk__0))));
    vlSelfRef.__VactTriggered.set(1U, ((~ (IData)(vlSelfRef.systolic_array_tb__DOT__tb_nRST)) 
                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__systolic_array_tb__DOT__tb_nRST__0)));
    vlSelfRef.__VactTriggered.set(2U, ((~ (IData)(vlSelfRef.systolic_array_tb__DOT__tb_clk)) 
                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__systolic_array_tb__DOT__tb_clk__0)));
    vlSelfRef.__VactTriggered.set(3U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__systolic_array_tb__DOT__tb_clk__0 
        = vlSelfRef.systolic_array_tb__DOT__tb_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__systolic_array_tb__DOT__tb_nRST__0 
        = vlSelfRef.systolic_array_tb__DOT__tb_nRST;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsystolic_array_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}

extern const VlUnpacked<CData/*0:0*/, 32> Vsystolic_array_tb__ConstPool__TABLE_h2d70b61b_0;
extern const VlUnpacked<CData/*1:0*/, 32> Vsystolic_array_tb__ConstPool__TABLE_h5bec8395_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vsystolic_array_tb__ConstPool__TABLE_hc6a7dea8_0;
extern const VlUnpacked<CData/*1:0*/, 32> Vsystolic_array_tb__ConstPool__TABLE_hd2e7befa_0;
extern const VlUnpacked<CData/*1:0*/, 32> Vsystolic_array_tb__ConstPool__TABLE_h3c738066_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vsystolic_array_tb__ConstPool__TABLE_haf0b274b_0;

VL_INLINE_OPT void Vsystolic_array_tb___024root___act_comb__TOP__0(Vsystolic_array_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array_tb___024root___act_comb__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    VlWide<4>/*127:0*/ __Vtemp_2;
    VlWide<4>/*127:0*/ __Vtemp_3;
    VlWide<4>/*127:0*/ __Vtemp_4;
    VlWide<4>/*127:0*/ __Vtemp_5;
    VlWide<5>/*159:0*/ __Vtemp_7;
    VlWide<5>/*159:0*/ __Vtemp_9;
    VlWide<5>/*159:0*/ __Vtemp_11;
    VlWide<5>/*159:0*/ __Vtemp_13;
    // Body
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_data_loaded 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__data_loaded;
    if (vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_data_loaded 
            = (1U | (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_data_loaded));
    }
    if (vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_data_loaded 
            = (2U | (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_data_loaded));
    }
    if (vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.MAC_start) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_data_loaded = 0U;
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration[2U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
        [2U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration[1U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
        [1U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration[0U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
        [0U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration_full;
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__i = 0U;
    {
        while (VL_GTS_III(32, 3U, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__i)) {
            if (((IData)(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en) 
                 & (0U == (IData)(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en)))) {
                if ((1U & (~ ((2U >= (3U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__i)) 
                              && (1U & ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration_full) 
                                        >> (3U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__i))))))) {
                    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT____Vlvbound_hd9ef4104__0 = 1U;
                    if (VL_LIKELY((2U >= (3U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__i)))) {
                        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full 
                            = (((~ ((IData)(1U) << 
                                    (3U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__i))) 
                                & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full)) 
                               | (7U & ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT____Vlvbound_hd9ef4104__0) 
                                        << (3U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__i))));
                    }
                    goto __Vlabel1;
                }
            }
            vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__i 
                = ((IData)(1U) + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__i);
        }
        __Vlabel1: ;
    }
    if (((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full) 
         & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_start))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT____Vlvbound_haaf93ebe__0 
            = (0xfU & ((IData)(1U) + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
                       [0U]));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration[0U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT____Vlvbound_haaf93ebe__0;
        if ((0xbU == vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
             [0U])) {
            vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration[0U] = 0U;
            vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full 
                = (6U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full));
        }
    }
    if ((((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full) 
          >> 1U) & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_start))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT____Vlvbound_haaf93ebe__0 
            = (0xfU & ((IData)(1U) + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
                       [1U]));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration[1U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT____Vlvbound_haaf93ebe__0;
        if ((0xbU == vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
             [1U])) {
            vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration[1U] = 0U;
            vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full 
                = (5U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full));
        }
    }
    if ((((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full) 
          >> 2U) & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_start))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT____Vlvbound_haaf93ebe__0 
            = (0xfU & ((IData)(1U) + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
                       [2U]));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration[2U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT____Vlvbound_haaf93ebe__0;
        if ((0xbU == vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
             [2U])) {
            vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration[2U] = 0U;
            vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full 
                = (3U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full));
        }
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__j = 3U;
    __Vtableidx1 = ((((IData)(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en) 
                      << 4U) | ((IData)(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.weight_en) 
                                << 3U)) | (((IData)(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en)));
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.input_type 
        = Vsystolic_array_tb__ConstPool__TABLE_h2d70b61b_0
        [__Vtableidx1];
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.input_row 
        = Vsystolic_array_tb__ConstPool__TABLE_h5bec8395_0
        [__Vtableidx1];
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.input_load 
        = Vsystolic_array_tb__ConstPool__TABLE_hc6a7dea8_0
        [__Vtableidx1];
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.weight_row 
        = Vsystolic_array_tb__ConstPool__TABLE_hd2e7befa_0
        [__Vtableidx1];
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.weight_load 
        = Vsystolic_array_tb__ConstPool__TABLE_h2d70b61b_0
        [__Vtableidx1];
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.partials_row 
        = Vsystolic_array_tb__ConstPool__TABLE_h3c738066_0
        [__Vtableidx1];
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.partials_load 
        = Vsystolic_array_tb__ConstPool__TABLE_haf0b274b_0
        [__Vtableidx1];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadw = 0U;
    if (vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.weight_load) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadw 
            = ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadw) 
               | (0xfU & ((IData)(1U) << (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.weight_row))));
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights_input = 0ULL;
    if (vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.input_type) {
        if (vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.input_type) {
            vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights_input 
                = vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in;
        }
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input = 0ULL;
    if ((1U & (~ (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.input_type)))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
            = vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in;
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadi = 0U;
    if (vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.input_load) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadi 
            = ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadi) 
               | (0xfU & ((IData)(1U) << (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.input_row))));
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadps = 0U;
    if (vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.partials_load) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadps 
            = ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadps) 
               | (0xfU & ((IData)(1U) << (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.partials_row))));
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[0U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem[0U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[1U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem[1U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem[2U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem[3U];
    if ((1U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadi))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__i = 4U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = ((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[2U]) 
               | ((IData)((((QData)((IData)((((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input) 
                                              << 0x10U) 
                                             | (0xffffU 
                                                & (IData)(
                                                          (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                           >> 0x10U)))))) 
                            << 0x10U) | (QData)((IData)(
                                                        (0xffffU 
                                                         & (IData)(
                                                                   (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                    >> 0x20U))))))) 
                  << 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
            = (((IData)((((QData)((IData)((((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input) 
                                            << 0x10U) 
                                           | (0xffffU 
                                              & (IData)(
                                                        (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                         >> 0x10U)))))) 
                          << 0x10U) | (QData)((IData)(
                                                      (0xffffU 
                                                       & (IData)(
                                                                 (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                  >> 0x20U))))))) 
                >> 0x10U) | ((IData)(((((QData)((IData)(
                                                        (((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input) 
                                                          << 0x10U) 
                                                         | (0xffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                       >> 0x10U)))))) 
                                        << 0x10U) | (QData)((IData)(
                                                                    (0xffffU 
                                                                     & (IData)(
                                                                               (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                                >> 0x20U)))))) 
                                      >> 0x20U)) << 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = ((0xffff0000U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[2U]) 
               | (0xffffU & (IData)((vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                     >> 0x30U))));
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[0U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem[0U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[1U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem[1U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem[2U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem[3U];
    if ((2U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadi))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__i = 4U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = ((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[2U]) 
               | ((IData)((((QData)((IData)((((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input) 
                                              << 0x10U) 
                                             | (0xffffU 
                                                & (IData)(
                                                          (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                           >> 0x10U)))))) 
                            << 0x10U) | (QData)((IData)(
                                                        (0xffffU 
                                                         & (IData)(
                                                                   (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                    >> 0x20U))))))) 
                  << 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
            = (((IData)((((QData)((IData)((((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input) 
                                            << 0x10U) 
                                           | (0xffffU 
                                              & (IData)(
                                                        (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                         >> 0x10U)))))) 
                          << 0x10U) | (QData)((IData)(
                                                      (0xffffU 
                                                       & (IData)(
                                                                 (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                  >> 0x20U))))))) 
                >> 0x10U) | ((IData)(((((QData)((IData)(
                                                        (((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input) 
                                                          << 0x10U) 
                                                         | (0xffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                       >> 0x10U)))))) 
                                        << 0x10U) | (QData)((IData)(
                                                                    (0xffffU 
                                                                     & (IData)(
                                                                               (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                                >> 0x20U)))))) 
                                      >> 0x20U)) << 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = ((0xffff0000U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[2U]) 
               | (0xffffU & (IData)((vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                     >> 0x30U))));
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[0U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem[0U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[1U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem[1U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem[2U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem[3U];
    if ((4U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadi))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__i = 4U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = ((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[2U]) 
               | ((IData)((((QData)((IData)((((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input) 
                                              << 0x10U) 
                                             | (0xffffU 
                                                & (IData)(
                                                          (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                           >> 0x10U)))))) 
                            << 0x10U) | (QData)((IData)(
                                                        (0xffffU 
                                                         & (IData)(
                                                                   (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                    >> 0x20U))))))) 
                  << 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
            = (((IData)((((QData)((IData)((((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input) 
                                            << 0x10U) 
                                           | (0xffffU 
                                              & (IData)(
                                                        (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                         >> 0x10U)))))) 
                          << 0x10U) | (QData)((IData)(
                                                      (0xffffU 
                                                       & (IData)(
                                                                 (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                  >> 0x20U))))))) 
                >> 0x10U) | ((IData)(((((QData)((IData)(
                                                        (((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input) 
                                                          << 0x10U) 
                                                         | (0xffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                       >> 0x10U)))))) 
                                        << 0x10U) | (QData)((IData)(
                                                                    (0xffffU 
                                                                     & (IData)(
                                                                               (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                                >> 0x20U)))))) 
                                      >> 0x20U)) << 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = ((0xffff0000U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[2U]) 
               | (0xffffU & (IData)((vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                     >> 0x30U))));
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[0U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem[0U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[1U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem[1U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem[2U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem[3U];
    if ((8U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadi))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__i = 4U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = ((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[2U]) 
               | ((IData)((((QData)((IData)((((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input) 
                                              << 0x10U) 
                                             | (0xffffU 
                                                & (IData)(
                                                          (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                           >> 0x10U)))))) 
                            << 0x10U) | (QData)((IData)(
                                                        (0xffffU 
                                                         & (IData)(
                                                                   (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                    >> 0x20U))))))) 
                  << 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
            = (((IData)((((QData)((IData)((((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input) 
                                            << 0x10U) 
                                           | (0xffffU 
                                              & (IData)(
                                                        (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                         >> 0x10U)))))) 
                          << 0x10U) | (QData)((IData)(
                                                      (0xffffU 
                                                       & (IData)(
                                                                 (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                  >> 0x20U))))))) 
                >> 0x10U) | ((IData)(((((QData)((IData)(
                                                        (((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input) 
                                                          << 0x10U) 
                                                         | (0xffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                       >> 0x10U)))))) 
                                        << 0x10U) | (QData)((IData)(
                                                                    (0xffffU 
                                                                     & (IData)(
                                                                               (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                                >> 0x20U)))))) 
                                      >> 0x20U)) << 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = ((0xffff0000U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[2U]) 
               | (0xffffU & (IData)((vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                     >> 0x30U))));
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[0U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem[0U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[1U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem[1U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem[2U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem[3U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem[4U];
    if ((1U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadps))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__i = 4U;
    }
    if (vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.fifo_shift) {
        VL_SHIFTR_WWI(128,128,32, __Vtemp_2, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next, 0x10U);
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[0U] 
            = __Vtemp_2[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[1U] 
            = __Vtemp_2[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = __Vtemp_2[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
            = __Vtemp_2[3U];
        VL_SHIFTR_WWI(128,128,32, __Vtemp_3, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next, 0x10U);
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[0U] 
            = __Vtemp_3[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[1U] 
            = __Vtemp_3[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = __Vtemp_3[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
            = __Vtemp_3[3U];
        VL_SHIFTR_WWI(128,128,32, __Vtemp_4, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next, 0x10U);
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[0U] 
            = __Vtemp_4[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[1U] 
            = __Vtemp_4[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = __Vtemp_4[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
            = __Vtemp_4[3U];
        VL_SHIFTR_WWI(128,128,32, __Vtemp_5, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next, 0x10U);
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[0U] 
            = __Vtemp_5[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[1U] 
            = __Vtemp_5[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = __Vtemp_5[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
            = __Vtemp_5[3U];
        VL_SHIFTR_WWI(144,144,32, __Vtemp_7, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem, 0x10U);
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[0U] 
            = __Vtemp_7[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[1U] 
            = __Vtemp_7[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
            = __Vtemp_7[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = __Vtemp_7[3U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
            = (0xffffU & __Vtemp_7[4U]);
    }
    if ((1U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadps))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
            = (0xffffU & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials 
                                  >> 0x10U)));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = ((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U]) 
               | ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0) 
                  << 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials 
                                  >> 0x20U)));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = ((0xffff0000U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U]) 
               | (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials 
                                  >> 0x30U)));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
            = ((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U]) 
               | ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0) 
                  << 0x10U));
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[0U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem[0U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[1U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem[1U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem[2U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem[3U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem[4U];
    if ((2U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadps))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__i = 4U;
    }
    if (vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.fifo_shift) {
        VL_SHIFTR_WWI(144,144,32, __Vtemp_9, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem, 0x10U);
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[0U] 
            = __Vtemp_9[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[1U] 
            = __Vtemp_9[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
            = __Vtemp_9[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = __Vtemp_9[3U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
            = (0xffffU & __Vtemp_9[4U]);
    }
    if ((2U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadps))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
            = (0xffffU & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials 
                                  >> 0x10U)));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = ((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U]) 
               | ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0) 
                  << 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials 
                                  >> 0x20U)));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = ((0xffff0000U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U]) 
               | (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials 
                                  >> 0x30U)));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
            = ((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U]) 
               | ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0) 
                  << 0x10U));
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[0U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem[0U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[1U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem[1U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem[2U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem[3U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem[4U];
    if ((4U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadps))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__i = 4U;
    }
    if (vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.fifo_shift) {
        VL_SHIFTR_WWI(144,144,32, __Vtemp_11, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem, 0x10U);
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[0U] 
            = __Vtemp_11[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[1U] 
            = __Vtemp_11[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
            = __Vtemp_11[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = __Vtemp_11[3U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
            = (0xffffU & __Vtemp_11[4U]);
    }
    if ((4U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadps))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
            = (0xffffU & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials 
                                  >> 0x10U)));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = ((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U]) 
               | ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0) 
                  << 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials 
                                  >> 0x20U)));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = ((0xffff0000U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U]) 
               | (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials 
                                  >> 0x30U)));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
            = ((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U]) 
               | ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0) 
                  << 0x10U));
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[0U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem[0U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[1U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem[1U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem[2U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem[3U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem[4U];
    if (vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.fifo_shift) {
        VL_SHIFTR_WWI(144,144,32, __Vtemp_13, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem, 0x10U);
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[0U] 
            = __Vtemp_13[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[1U] 
            = __Vtemp_13[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
            = __Vtemp_13[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = __Vtemp_13[3U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
            = (0xffffU & __Vtemp_13[4U]);
    }
    if ((8U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadps))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__i = 4U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
            = (0xffffU & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials 
                                  >> 0x10U)));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = ((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U]) 
               | ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0) 
                  << 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials 
                                  >> 0x20U)));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = ((0xffff0000U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U]) 
               | (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials 
                                  >> 0x30U)));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
            = ((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U]) 
               | ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0) 
                  << 0x10U));
    }
}

VL_INLINE_OPT void Vsystolic_array_tb___024root___nba_sequent__TOP__0(Vsystolic_array_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array_tb___024root___nba_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.out_en)) {
        VL_WRITEF_NX("output row is %1#\noutput is %5#, %5#, %5#, %5#\n",0,
                     2,vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_out,
                     16,(0xffffU & (IData)(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_output)),
                     16,(0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_output 
                                            >> 0x10U))),
                     16,(0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_output 
                                            >> 0x20U))),
                     16,(0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_output 
                                            >> 0x30U))));
    }
}

VL_INLINE_OPT void Vsystolic_array_tb___024root___nba_sequent__TOP__1(Vsystolic_array_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array_tb___024root___nba_sequent__TOP__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    QData/*63:0*/ __VdlyVal__systolic_array_tb__DOT__DUT__DOT__weights__v0;
    __VdlyVal__systolic_array_tb__DOT__DUT__DOT__weights__v0 = 0;
    CData/*0:0*/ __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v0;
    __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v0 = 0;
    CData/*0:0*/ __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v1;
    __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v1 = 0;
    QData/*63:0*/ __VdlyVal__systolic_array_tb__DOT__DUT__DOT__weights__v2;
    __VdlyVal__systolic_array_tb__DOT__DUT__DOT__weights__v2 = 0;
    CData/*0:0*/ __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v2;
    __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v2 = 0;
    CData/*0:0*/ __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v3;
    __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v3 = 0;
    QData/*63:0*/ __VdlyVal__systolic_array_tb__DOT__DUT__DOT__weights__v4;
    __VdlyVal__systolic_array_tb__DOT__DUT__DOT__weights__v4 = 0;
    CData/*0:0*/ __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v4;
    __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v4 = 0;
    CData/*0:0*/ __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v5;
    __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v5 = 0;
    QData/*63:0*/ __VdlyVal__systolic_array_tb__DOT__DUT__DOT__weights__v6;
    __VdlyVal__systolic_array_tb__DOT__DUT__DOT__weights__v6 = 0;
    CData/*0:0*/ __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v6;
    __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v6 = 0;
    CData/*0:0*/ __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v7;
    __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v7 = 0;
    SData/*15:0*/ __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v0;
    __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v0 = 0;
    CData/*0:0*/ __VdlySet__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v0;
    __VdlySet__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v0 = 0;
    SData/*15:0*/ __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v1;
    __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v1 = 0;
    SData/*15:0*/ __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v2;
    __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v2 = 0;
    SData/*15:0*/ __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v3;
    __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v3 = 0;
    SData/*15:0*/ __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v4;
    __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v4 = 0;
    SData/*15:0*/ __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v5;
    __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v5 = 0;
    SData/*15:0*/ __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v6;
    __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v6 = 0;
    SData/*15:0*/ __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v7;
    __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v7 = 0;
    SData/*15:0*/ __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v8;
    __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v8 = 0;
    SData/*15:0*/ __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v9;
    __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v9 = 0;
    SData/*15:0*/ __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v10;
    __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v10 = 0;
    SData/*15:0*/ __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v11;
    __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v11 = 0;
    SData/*15:0*/ __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v12;
    __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v12 = 0;
    SData/*15:0*/ __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v13;
    __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v13 = 0;
    SData/*15:0*/ __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v14;
    __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v14 = 0;
    SData/*15:0*/ __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v15;
    __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v15 = 0;
    CData/*0:0*/ __VdlySet__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v16;
    __VdlySet__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v16 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration__v0;
    __VdlyVal__systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration__v0 = 0;
    CData/*0:0*/ __VdlySet__systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration__v0;
    __VdlySet__systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration__v0 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration__v1;
    __VdlyVal__systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration__v1 = 0;
    CData/*3:0*/ __VdlyVal__systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration__v2;
    __VdlyVal__systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration__v2 = 0;
    CData/*0:0*/ __VdlySet__systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration__v3;
    __VdlySet__systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration__v3 = 0;
    // Body
    __VdlySet__systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration__v0 = 0U;
    __VdlySet__systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration__v3 = 0U;
    __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v0 = 0U;
    __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v1 = 0U;
    __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v2 = 0U;
    __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v3 = 0U;
    __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v4 = 0U;
    __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v5 = 0U;
    __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v6 = 0U;
    __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v7 = 0U;
    __VdlySet__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v0 = 0U;
    __VdlySet__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v16 = 0U;
    if ((1U & (~ (IData)(vlSelfRef.systolic_array_tb__DOT__tb_nRST)))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__y = 4U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__z = 4U;
    }
    if (vlSelfRef.systolic_array_tb__DOT__tb_nRST) {
        __VdlyVal__systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration__v0 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration
            [2U];
        __VdlySet__systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration__v0 = 1U;
        __VdlyVal__systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration__v1 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration
            [1U];
        __VdlyVal__systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration__v2 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration
            [0U];
        if ((1U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadw))) {
            __VdlyVal__systolic_array_tb__DOT__DUT__DOT__weights__v0 
                = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights_input;
            __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v0 = 1U;
        }
        if ((2U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadw))) {
            __VdlyVal__systolic_array_tb__DOT__DUT__DOT__weights__v2 
                = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights_input;
            __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v2 = 1U;
        }
        if ((4U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadw))) {
            __VdlyVal__systolic_array_tb__DOT__DUT__DOT__weights__v4 
                = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights_input;
            __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v4 = 1U;
        }
        if ((8U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadw))) {
            __VdlyVal__systolic_array_tb__DOT__DUT__DOT__weights__v6 
                = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights_input;
            __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v6 = 1U;
        }
        if ((4U == (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.MAC_count))) {
            __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v0 
                = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                [3U][3U];
            __VdlySet__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v0 = 1U;
            __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v1 
                = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                [3U][2U];
            __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v2 
                = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                [3U][1U];
            __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v3 
                = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                [3U][0U];
            __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v4 
                = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                [2U][3U];
            __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v5 
                = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                [2U][2U];
            __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v6 
                = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                [2U][1U];
            __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v7 
                = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                [2U][0U];
            __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v8 
                = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                [1U][3U];
            __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v9 
                = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                [1U][2U];
            __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v10 
                = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                [1U][1U];
            __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v11 
                = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                [1U][0U];
            __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v12 
                = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                [0U][3U];
            __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v13 
                = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                [0U][2U];
            __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v14 
                = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                [0U][1U];
            __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v15 
                = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                [0U][0U];
        }
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__0__KET____DOT__o_fifo__DOT__fifo_mem 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__0__KET____DOT__o_fifo__DOT__fifo_mem_next;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__1__KET____DOT__o_fifo__DOT__fifo_mem 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__1__KET____DOT__o_fifo__DOT__fifo_mem_next;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__2__KET____DOT__o_fifo__DOT__fifo_mem 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__2__KET____DOT__o_fifo__DOT__fifo_mem_next;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__3__KET____DOT__o_fifo__DOT__fifo_mem 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__3__KET____DOT__o_fifo__DOT__fifo_mem_next;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem[0U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem[1U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem[2U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem[3U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem[4U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem[0U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem[1U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem[2U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem[3U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem[4U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem[0U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem[1U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem[2U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem[3U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem[4U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem[0U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem[1U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem[2U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem[3U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem[4U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__data_loaded 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_data_loaded;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration_full 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem[0U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem[1U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem[2U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem[3U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[3U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem[0U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem[1U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem[2U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem[3U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[3U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem[0U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem[1U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem[2U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem[3U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[3U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem[0U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem[1U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem[2U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem[3U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[3U];
    } else {
        __VdlySet__systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration__v3 = 1U;
        __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v1 = 1U;
        __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v3 = 1U;
        __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v5 = 1U;
        __VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v7 = 1U;
        __VdlySet__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v16 = 1U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__0__KET____DOT__o_fifo__DOT__fifo_mem = 0ULL;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__1__KET____DOT__o_fifo__DOT__fifo_mem = 0ULL;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__2__KET____DOT__o_fifo__DOT__fifo_mem = 0ULL;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__3__KET____DOT__o_fifo__DOT__fifo_mem = 0ULL;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem[0U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem[1U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem[2U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem[3U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem[4U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem[0U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem[1U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem[2U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem[3U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem[4U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem[0U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem[1U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem[2U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem[3U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem[4U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem[0U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem[1U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem[2U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem[3U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem[4U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__data_loaded = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration_full = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem[0U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem[1U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem[2U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem[3U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem[0U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem[1U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem[2U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem[3U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem[0U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem[1U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem[2U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem[3U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem[0U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem[1U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem[2U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem[3U] = 0U;
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__MAC_done 
        = ((1U & (~ (IData)(vlSelfRef.systolic_array_tb__DOT__tb_nRST))) 
           || (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_done));
    if (__VdlySet__systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration__v0) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration[2U] 
            = __VdlyVal__systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration__v0;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration[1U] 
            = __VdlyVal__systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration__v1;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration[0U] 
            = __VdlyVal__systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration__v2;
    }
    if (__VdlySet__systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration__v3) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration[2U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration[1U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration[0U] = 0U;
    }
    if (__VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v0) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights[0U] 
            = __VdlyVal__systolic_array_tb__DOT__DUT__DOT__weights__v0;
    }
    if (__VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v1) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights[0U] = 0ULL;
    }
    if (__VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v2) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights[1U] 
            = __VdlyVal__systolic_array_tb__DOT__DUT__DOT__weights__v2;
    }
    if (__VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v3) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights[1U] = 0ULL;
    }
    if (__VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v4) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights[2U] 
            = __VdlyVal__systolic_array_tb__DOT__DUT__DOT__weights__v4;
    }
    if (__VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v5) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights[2U] = 0ULL;
    }
    if (__VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v6) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights[3U] 
            = __VdlyVal__systolic_array_tb__DOT__DUT__DOT__weights__v6;
    }
    if (__VdlySet__systolic_array_tb__DOT__DUT__DOT__weights__v7) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights[3U] = 0ULL;
    }
    if (__VdlySet__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v0) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[3U][3U] 
            = __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v0;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[3U][2U] 
            = __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v1;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[3U][1U] 
            = __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v2;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[3U][0U] 
            = __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v3;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[2U][3U] 
            = __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v4;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[2U][2U] 
            = __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v5;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[2U][1U] 
            = __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v6;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[2U][0U] 
            = __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v7;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[1U][3U] 
            = __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v8;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[1U][2U] 
            = __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v9;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[1U][1U] 
            = __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v10;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[1U][0U] 
            = __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v11;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[0U][3U] 
            = __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v12;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[0U][2U] 
            = __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v13;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[0U][1U] 
            = __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v14;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[0U][0U] 
            = __VdlyVal__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v15;
    }
    if (__VdlySet__systolic_array_tb__DOT__DUT__DOT__MAC_outputs__v16) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[0U][0U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[0U][1U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[0U][2U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[0U][3U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[1U][0U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[1U][1U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[1U][2U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[1U][3U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[2U][0U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[2U][1U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[2U][2U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[2U][3U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[3U][0U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[3U][1U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[3U][2U] = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs[3U][3U] = 0U;
    }
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.iteration[2U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
        [2U];
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.iteration[1U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
        [1U];
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.iteration[0U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
        [0U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__current_out[0U] 
        = (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__0__KET____DOT__o_fifo__DOT__fifo_mem);
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__current_out[1U] 
        = (IData)((vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__0__KET____DOT__o_fifo__DOT__fifo_mem 
                   >> 0x20U));
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__current_out[2U] 
        = (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__1__KET____DOT__o_fifo__DOT__fifo_mem);
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__current_out[3U] 
        = (IData)((vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__1__KET____DOT__o_fifo__DOT__fifo_mem 
                   >> 0x20U));
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__current_out[4U] 
        = (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__2__KET____DOT__o_fifo__DOT__fifo_mem);
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__current_out[5U] 
        = (IData)((vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__2__KET____DOT__o_fifo__DOT__fifo_mem 
                   >> 0x20U));
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__current_out[6U] 
        = (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__3__KET____DOT__o_fifo__DOT__fifo_mem);
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__current_out[7U] 
        = (IData)((vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__3__KET____DOT__o_fifo__DOT__fifo_mem 
                   >> 0x20U));
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__ps_add_inputs[0U] 
        = (0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem[0U]);
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__ps_add_inputs[1U] 
        = (0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem[0U]);
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__ps_add_inputs[2U] 
        = (0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem[0U]);
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__ps_add_inputs[3U] 
        = (0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem[0U]);
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__input_tracker = 0U;
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__k = 0U;
    {
        while (VL_GTS_III(32, 3U, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__k)) {
            if ((((2U >= (3U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__k)) 
                  && (1U & ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration_full) 
                            >> (3U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__k)))) 
                 & (0xcU != ((2U >= (3U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__k))
                              ? vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
                             [(3U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__k)]
                              : 0U)))) {
                vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__input_tracker = 1U;
                if ((4U > ((2U >= (3U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__k))
                            ? vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
                           [(3U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__k)]
                            : 0U))) {
                    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__input_tracker = 3U;
                    goto __Vlabel2;
                }
            }
            vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__k 
                = ((IData)(1U) + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__k);
        }
        __Vlabel2: ;
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs[0U][0U] 
        = (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem[1U] 
           >> 0x10U);
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs[0U][1U] 
        = (0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem[1U]);
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs[0U][2U] 
        = (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem[0U] 
           >> 0x10U);
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs[0U][3U] 
        = (0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem[0U]);
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs[1U][0U] 
        = (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem[1U] 
           >> 0x10U);
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs[1U][1U] 
        = (0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem[1U]);
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs[1U][2U] 
        = (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem[0U] 
           >> 0x10U);
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs[1U][3U] 
        = (0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem[0U]);
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs[2U][0U] 
        = (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem[1U] 
           >> 0x10U);
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs[2U][1U] 
        = (0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem[1U]);
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs[2U][2U] 
        = (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem[0U] 
           >> 0x10U);
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs[2U][3U] 
        = (0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem[0U]);
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs[3U][0U] 
        = (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem[1U] 
           >> 0x10U);
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs[3U][1U] 
        = (0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem[1U]);
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs[3U][2U] 
        = (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem[0U] 
           >> 0x10U);
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs[3U][3U] 
        = (0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem[0U]);
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.drained = 1U;
    if ((0U < vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.iteration
         [0U])) {
        vlSymsp->TOP__systolic_array_tb__DOT__memory_if.drained = 0U;
    }
    if ((0U < vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.iteration
         [1U])) {
        vlSymsp->TOP__systolic_array_tb__DOT__memory_if.drained = 0U;
    }
    if ((0U < vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.iteration
         [2U])) {
        vlSymsp->TOP__systolic_array_tb__DOT__memory_if.drained = 0U;
    }
}

VL_INLINE_OPT void Vsystolic_array_tb___024root___nba_sequent__TOP__2(Vsystolic_array_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array_tb___024root___nba_sequent__TOP__2\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.add_start 
        = ((IData)(vlSelfRef.systolic_array_tb__DOT__tb_nRST) 
           && (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_add_start));
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.MAC_start 
        = ((IData)(vlSelfRef.systolic_array_tb__DOT__tb_nRST) 
           && (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_start));
    if (vlSelfRef.systolic_array_tb__DOT__tb_nRST) {
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.add_count 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_add_count;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.MAC_count 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_count;
    } else {
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.add_count = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.MAC_count = 0U;
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_start = 0U;
    if ((((3U == (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__data_loaded)) 
          | (1U == (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__input_tracker))) 
         & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__MAC_done))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_start = 1U;
    }
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.fifo_shift = 0U;
    if (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_start) {
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.fifo_shift = 1U;
    }
}

VL_INLINE_OPT void Vsystolic_array_tb___024root___nba_sequent__TOP__3(Vsystolic_array_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array_tb___024root___nba_sequent__TOP__3\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_add_start = 0U;
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_add_count 
        = vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.add_count;
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__q = 0U;
    {
        while (VL_GTS_III(32, 3U, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__q)) {
            if (((4U < ((2U >= (3U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__q))
                         ? vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
                        [(3U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__q)]
                         : 0U)) & (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.MAC_start))) {
                vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_add_start = 1U;
                goto __Vlabel3;
            }
            vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__q 
                = ((IData)(1U) + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__q);
        }
        __Vlabel3: ;
    }
    if (((IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.add_start) 
         | (0U < (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.add_count)))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_add_count 
            = (3U & ((IData)(1U) + (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.add_count)));
        if ((3U == (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.add_count))) {
            vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_add_count = 0U;
        }
    }
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.out_fifo_shift = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.out_en = 0U;
    if (((8U <= vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.iteration
          [0U]) & (3U == (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.add_count)))) {
        vlSymsp->TOP__systolic_array_tb__DOT__memory_if.out_en = 1U;
    }
    if (((8U <= vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.iteration
          [1U]) & (3U == (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.add_count)))) {
        vlSymsp->TOP__systolic_array_tb__DOT__memory_if.out_en = 1U;
    }
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_out = 0U;
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out = 0U;
    vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_output = 0ULL;
    if (((8U <= vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.iteration
          [0U]) & (3U == (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.add_count)))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out 
            = (3U & vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.iteration
               [0U]);
        vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_out 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out;
        vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_output 
            = (((QData)((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__current_out[
                                (((IData)(0x3fU) + 
                                  (0xffU & VL_SHIFTL_III(8,32,32, (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out), 6U))) 
                                 >> 5U)])) << ((0U 
                                                == 
                                                (0x1fU 
                                                 & VL_SHIFTL_III(8,32,32, (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out), 6U)))
                                                ? 0x20U
                                                : ((IData)(0x40U) 
                                                   - 
                                                   (0x1fU 
                                                    & VL_SHIFTL_III(8,32,32, (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out), 6U))))) 
               | (((0U == (0x1fU & VL_SHIFTL_III(8,32,32, (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out), 6U)))
                    ? 0ULL : ((QData)((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__current_out[
                                              (((IData)(0x1fU) 
                                                + (0xffU 
                                                   & VL_SHIFTL_III(8,32,32, (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out), 6U))) 
                                               >> 5U)])) 
                              << ((IData)(0x20U) - 
                                  (0x1fU & VL_SHIFTL_III(8,32,32, (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out), 6U))))) 
                  | ((QData)((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__current_out[
                                     (7U & (VL_SHIFTL_III(8,32,32, (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out), 6U) 
                                            >> 5U))])) 
                     >> (0x1fU & VL_SHIFTL_III(8,32,32, (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out), 6U)))));
    }
    if (((8U <= vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.iteration
          [1U]) & (3U == (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.add_count)))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out 
            = (3U & vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.iteration
               [1U]);
        vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_out 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out;
        vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_output 
            = (((QData)((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__current_out[
                                (((IData)(0x3fU) + 
                                  (0xffU & VL_SHIFTL_III(8,32,32, (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out), 6U))) 
                                 >> 5U)])) << ((0U 
                                                == 
                                                (0x1fU 
                                                 & VL_SHIFTL_III(8,32,32, (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out), 6U)))
                                                ? 0x20U
                                                : ((IData)(0x40U) 
                                                   - 
                                                   (0x1fU 
                                                    & VL_SHIFTL_III(8,32,32, (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out), 6U))))) 
               | (((0U == (0x1fU & VL_SHIFTL_III(8,32,32, (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out), 6U)))
                    ? 0ULL : ((QData)((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__current_out[
                                              (((IData)(0x1fU) 
                                                + (0xffU 
                                                   & VL_SHIFTL_III(8,32,32, (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out), 6U))) 
                                               >> 5U)])) 
                              << ((IData)(0x20U) - 
                                  (0x1fU & VL_SHIFTL_III(8,32,32, (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out), 6U))))) 
                  | ((QData)((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__current_out[
                                     (7U & (VL_SHIFTL_III(8,32,32, (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out), 6U) 
                                            >> 5U))])) 
                     >> (0x1fU & VL_SHIFTL_III(8,32,32, (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out), 6U)))));
    }
    if (((8U <= vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.iteration
          [2U]) & (3U == (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.add_count)))) {
        vlSymsp->TOP__systolic_array_tb__DOT__memory_if.out_en = 1U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out 
            = (3U & vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.iteration
               [2U]);
        vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_out 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out;
        vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_output 
            = (((QData)((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__current_out[
                                (((IData)(0x3fU) + 
                                  (0xffU & VL_SHIFTL_III(8,32,32, (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out), 6U))) 
                                 >> 5U)])) << ((0U 
                                                == 
                                                (0x1fU 
                                                 & VL_SHIFTL_III(8,32,32, (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out), 6U)))
                                                ? 0x20U
                                                : ((IData)(0x40U) 
                                                   - 
                                                   (0x1fU 
                                                    & VL_SHIFTL_III(8,32,32, (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out), 6U))))) 
               | (((0U == (0x1fU & VL_SHIFTL_III(8,32,32, (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out), 6U)))
                    ? 0ULL : ((QData)((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__current_out[
                                              (((IData)(0x1fU) 
                                                + (0xffU 
                                                   & VL_SHIFTL_III(8,32,32, (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out), 6U))) 
                                               >> 5U)])) 
                              << ((IData)(0x20U) - 
                                  (0x1fU & VL_SHIFTL_III(8,32,32, (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out), 6U))))) 
                  | ((QData)((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__current_out[
                                     (7U & (VL_SHIFTL_III(8,32,32, (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out), 6U) 
                                            >> 5U))])) 
                     >> (0x1fU & VL_SHIFTL_III(8,32,32, (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out), 6U)))));
    }
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__0__KET__.add_ouput = 0U;
    if ((2U == (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.add_count))) {
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.out_fifo_shift = 1U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__0__KET__.add_ouput 
            = (0xffffU & (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__ps_add_inputs
                          [0U] + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                          [3U][0U]));
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__1__KET__.add_ouput = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__1__KET__.add_ouput 
            = (0xffffU & (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__ps_add_inputs
                          [1U] + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                          [3U][1U]));
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__2__KET__.add_ouput = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__2__KET__.add_ouput 
            = (0xffffU & (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__ps_add_inputs
                          [2U] + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                          [3U][2U]));
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__3__KET__.add_ouput = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__3__KET__.add_ouput 
            = (0xffffU & (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__ps_add_inputs
                          [3U] + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                          [3U][3U]));
    } else {
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__1__KET__.add_ouput = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__2__KET__.add_ouput = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__3__KET__.add_ouput = 0U;
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_count 
        = vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.MAC_count;
    if (((0U < (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.MAC_count)) 
         | (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.MAC_start))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_count 
            = (7U & ((IData)(1U) + (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.MAC_count)));
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_done 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__MAC_done;
    if ((1U & ((3U <= (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.MAC_count)) 
               | (~ (IData)((0U != (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration_full))))))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_done = 1U;
    }
    if ((((3U == (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__data_loaded)) 
          | (1U == (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__input_tracker))) 
         & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__MAC_done))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_count = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_done = 0U;
    }
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__0__KET__.out_accumulate = 0U;
    if ((4U == (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.MAC_count))) {
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__0__KET__.out_accumulate 
            = (0xffffU & (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                          [0U][0U] * (0xffffU & (IData)(
                                                        (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                         [0U] 
                                                         >> 0x30U)))));
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__1__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__1__KET__.out_accumulate 
            = (0xffffU & (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                          [0U][1U] * (0xffffU & (IData)(
                                                        (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                         [1U] 
                                                         >> 0x30U)))));
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__2__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__2__KET__.out_accumulate 
            = (0xffffU & (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                          [0U][2U] * (0xffffU & (IData)(
                                                        (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                         [2U] 
                                                         >> 0x30U)))));
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__3__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__3__KET__.out_accumulate 
            = (0xffffU & (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                          [0U][3U] * (0xffffU & (IData)(
                                                        (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                         [3U] 
                                                         >> 0x30U)))));
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__4__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__4__KET__.out_accumulate 
            = (0xffffU & ((vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                           [1U][0U] * (0xffffU & (IData)(
                                                         (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                          [0U] 
                                                          >> 0x20U)))) 
                          + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                          [0U][0U]));
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__5__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__5__KET__.out_accumulate 
            = (0xffffU & ((vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                           [1U][1U] * (0xffffU & (IData)(
                                                         (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                          [1U] 
                                                          >> 0x20U)))) 
                          + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                          [0U][1U]));
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__6__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__6__KET__.out_accumulate 
            = (0xffffU & ((vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                           [1U][2U] * (0xffffU & (IData)(
                                                         (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                          [2U] 
                                                          >> 0x20U)))) 
                          + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                          [0U][2U]));
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__7__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__7__KET__.out_accumulate 
            = (0xffffU & ((vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                           [1U][3U] * (0xffffU & (IData)(
                                                         (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                          [3U] 
                                                          >> 0x20U)))) 
                          + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                          [0U][3U]));
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__8__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__8__KET__.out_accumulate 
            = (0xffffU & ((vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                           [2U][0U] * (0xffffU & (IData)(
                                                         (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                          [0U] 
                                                          >> 0x10U)))) 
                          + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                          [1U][0U]));
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__9__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__9__KET__.out_accumulate 
            = (0xffffU & ((vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                           [2U][1U] * (0xffffU & (IData)(
                                                         (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                          [1U] 
                                                          >> 0x10U)))) 
                          + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                          [1U][1U]));
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__10__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__10__KET__.out_accumulate 
            = (0xffffU & ((vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                           [2U][2U] * (0xffffU & (IData)(
                                                         (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                          [2U] 
                                                          >> 0x10U)))) 
                          + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                          [1U][2U]));
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__11__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__11__KET__.out_accumulate 
            = (0xffffU & ((vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                           [2U][3U] * (0xffffU & (IData)(
                                                         (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                          [3U] 
                                                          >> 0x10U)))) 
                          + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                          [1U][3U]));
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__12__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__12__KET__.out_accumulate 
            = (0xffffU & ((vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                           [3U][0U] * (0xffffU & (IData)(
                                                         vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                         [0U]))) 
                          + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                          [2U][0U]));
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__13__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__13__KET__.out_accumulate 
            = (0xffffU & ((vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                           [3U][1U] * (0xffffU & (IData)(
                                                         vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                         [1U]))) 
                          + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                          [2U][1U]));
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__14__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__14__KET__.out_accumulate 
            = (0xffffU & ((vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                           [3U][2U] * (0xffffU & (IData)(
                                                         vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                         [2U]))) 
                          + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                          [2U][2U]));
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__15__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__15__KET__.out_accumulate 
            = (0xffffU & ((vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                           [3U][3U] * (0xffffU & (IData)(
                                                         vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                         [3U]))) 
                          + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                          [2U][3U]));
    } else {
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__1__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__2__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__3__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__4__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__5__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__6__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__7__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__8__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__9__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__10__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__11__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__12__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__13__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__14__KET__.out_accumulate = 0U;
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__15__KET__.out_accumulate = 0U;
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__0__KET____DOT__o_fifo__DOT__fifo_mem_next 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__0__KET____DOT__o_fifo__DOT__fifo_mem;
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__1__KET____DOT__o_fifo__DOT__fifo_mem_next 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__1__KET____DOT__o_fifo__DOT__fifo_mem;
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__2__KET____DOT__o_fifo__DOT__fifo_mem_next 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__2__KET____DOT__o_fifo__DOT__fifo_mem;
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__3__KET____DOT__o_fifo__DOT__fifo_mem_next 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__3__KET____DOT__o_fifo__DOT__fifo_mem;
    if (vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.out_fifo_shift) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__0__KET____DOT__o_fifo__DOT__fifo_mem_next 
            = (((QData)((IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__0__KET__.add_ouput)) 
                << 0x30U) | (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__0__KET____DOT__o_fifo__DOT__fifo_mem 
                             >> 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__1__KET____DOT__o_fifo__DOT__fifo_mem_next 
            = (((QData)((IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__1__KET__.add_ouput)) 
                << 0x30U) | (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__1__KET____DOT__o_fifo__DOT__fifo_mem 
                             >> 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__2__KET____DOT__o_fifo__DOT__fifo_mem_next 
            = (((QData)((IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__2__KET__.add_ouput)) 
                << 0x30U) | (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__2__KET____DOT__o_fifo__DOT__fifo_mem 
                             >> 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__3__KET____DOT__o_fifo__DOT__fifo_mem_next 
            = (((QData)((IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__3__KET__.add_ouput)) 
                << 0x30U) | (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__3__KET____DOT__o_fifo__DOT__fifo_mem 
                             >> 0x10U));
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs[0U][0U] 
        = vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__0__KET__.out_accumulate;
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs[0U][1U] 
        = vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__1__KET__.out_accumulate;
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs[0U][2U] 
        = vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__2__KET__.out_accumulate;
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs[0U][3U] 
        = vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__3__KET__.out_accumulate;
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs[1U][0U] 
        = vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__4__KET__.out_accumulate;
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs[1U][1U] 
        = vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__5__KET__.out_accumulate;
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs[1U][2U] 
        = vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__6__KET__.out_accumulate;
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs[1U][3U] 
        = vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__7__KET__.out_accumulate;
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs[2U][0U] 
        = vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__8__KET__.out_accumulate;
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs[2U][1U] 
        = vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__9__KET__.out_accumulate;
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs[2U][2U] 
        = vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__10__KET__.out_accumulate;
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs[2U][3U] 
        = vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__11__KET__.out_accumulate;
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs[3U][0U] 
        = vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__12__KET__.out_accumulate;
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs[3U][1U] 
        = vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__13__KET__.out_accumulate;
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs[3U][2U] 
        = vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__14__KET__.out_accumulate;
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs[3U][3U] 
        = vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__15__KET__.out_accumulate;
}

VL_INLINE_OPT void Vsystolic_array_tb___024root___nba_comb__TOP__0(Vsystolic_array_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array_tb___024root___nba_comb__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = ((((IData)(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en) 
                      << 4U) | ((IData)(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.weight_en) 
                                << 3U)) | (((IData)(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en)));
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.input_type 
        = Vsystolic_array_tb__ConstPool__TABLE_h2d70b61b_0
        [__Vtableidx1];
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.input_row 
        = Vsystolic_array_tb__ConstPool__TABLE_h5bec8395_0
        [__Vtableidx1];
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.input_load 
        = Vsystolic_array_tb__ConstPool__TABLE_hc6a7dea8_0
        [__Vtableidx1];
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.weight_row 
        = Vsystolic_array_tb__ConstPool__TABLE_hd2e7befa_0
        [__Vtableidx1];
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.weight_load 
        = Vsystolic_array_tb__ConstPool__TABLE_h2d70b61b_0
        [__Vtableidx1];
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.partials_row 
        = Vsystolic_array_tb__ConstPool__TABLE_h3c738066_0
        [__Vtableidx1];
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.partials_load 
        = Vsystolic_array_tb__ConstPool__TABLE_haf0b274b_0
        [__Vtableidx1];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadw = 0U;
    if (vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.weight_load) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadw 
            = ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadw) 
               | (0xfU & ((IData)(1U) << (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.weight_row))));
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input = 0ULL;
    if ((1U & (~ (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.input_type)))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
            = vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in;
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights_input = 0ULL;
    if (vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.input_type) {
        if (vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.input_type) {
            vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights_input 
                = vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in;
        }
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadi = 0U;
    if (vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.input_load) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadi 
            = ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadi) 
               | (0xfU & ((IData)(1U) << (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.input_row))));
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadps = 0U;
    if (vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.partials_load) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadps 
            = ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadps) 
               | (0xfU & ((IData)(1U) << (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.partials_row))));
    }
    if ((1U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadi))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__i = 4U;
    }
    if ((2U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadi))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__i = 4U;
    }
    if ((4U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadi))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__i = 4U;
    }
    if ((8U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadi))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__i = 4U;
    }
    if ((1U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadps))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__i = 4U;
    }
    if ((2U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadps))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__i = 4U;
    }
    if ((4U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadps))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__i = 4U;
    }
    if ((8U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadps))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__i = 4U;
    }
}

VL_INLINE_OPT void Vsystolic_array_tb___024root___nba_comb__TOP__1(Vsystolic_array_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array_tb___024root___nba_comb__TOP__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*127:0*/ __Vtemp_2;
    VlWide<4>/*127:0*/ __Vtemp_3;
    VlWide<4>/*127:0*/ __Vtemp_4;
    VlWide<4>/*127:0*/ __Vtemp_5;
    VlWide<5>/*159:0*/ __Vtemp_7;
    VlWide<5>/*159:0*/ __Vtemp_9;
    VlWide<5>/*159:0*/ __Vtemp_11;
    VlWide<5>/*159:0*/ __Vtemp_13;
    // Body
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration[2U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
        [2U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration[1U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
        [1U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration[0U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
        [0U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration_full;
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__i = 0U;
    {
        while (VL_GTS_III(32, 3U, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__i)) {
            if (((IData)(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en) 
                 & (0U == (IData)(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en)))) {
                if ((1U & (~ ((2U >= (3U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__i)) 
                              && (1U & ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration_full) 
                                        >> (3U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__i))))))) {
                    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT____Vlvbound_hd9ef4104__0 = 1U;
                    if (VL_LIKELY((2U >= (3U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__i)))) {
                        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full 
                            = (((~ ((IData)(1U) << 
                                    (3U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__i))) 
                                & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full)) 
                               | (7U & ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT____Vlvbound_hd9ef4104__0) 
                                        << (3U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__i))));
                    }
                    goto __Vlabel4;
                }
            }
            vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__i 
                = ((IData)(1U) + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__i);
        }
        __Vlabel4: ;
    }
    if (((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full) 
         & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_start))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT____Vlvbound_haaf93ebe__0 
            = (0xfU & ((IData)(1U) + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
                       [0U]));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration[0U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT____Vlvbound_haaf93ebe__0;
        if ((0xbU == vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
             [0U])) {
            vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration[0U] = 0U;
            vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full 
                = (6U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full));
        }
    }
    if ((((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full) 
          >> 1U) & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_start))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT____Vlvbound_haaf93ebe__0 
            = (0xfU & ((IData)(1U) + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
                       [1U]));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration[1U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT____Vlvbound_haaf93ebe__0;
        if ((0xbU == vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
             [1U])) {
            vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration[1U] = 0U;
            vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full 
                = (5U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full));
        }
    }
    if ((((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full) 
          >> 2U) & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_start))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT____Vlvbound_haaf93ebe__0 
            = (0xfU & ((IData)(1U) + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
                       [2U]));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration[2U] 
            = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT____Vlvbound_haaf93ebe__0;
        if ((0xbU == vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
             [2U])) {
            vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration[2U] = 0U;
            vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full 
                = (3U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full));
        }
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__j = 3U;
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_data_loaded 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__data_loaded;
    if (vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_data_loaded 
            = (1U | (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_data_loaded));
    }
    if (vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_data_loaded 
            = (2U | (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_data_loaded));
    }
    if (vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.MAC_start) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_data_loaded = 0U;
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[0U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem[0U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[1U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem[1U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem[2U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem[3U];
    if ((1U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadi))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = ((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[2U]) 
               | ((IData)((((QData)((IData)((((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input) 
                                              << 0x10U) 
                                             | (0xffffU 
                                                & (IData)(
                                                          (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                           >> 0x10U)))))) 
                            << 0x10U) | (QData)((IData)(
                                                        (0xffffU 
                                                         & (IData)(
                                                                   (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                    >> 0x20U))))))) 
                  << 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
            = (((IData)((((QData)((IData)((((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input) 
                                            << 0x10U) 
                                           | (0xffffU 
                                              & (IData)(
                                                        (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                         >> 0x10U)))))) 
                          << 0x10U) | (QData)((IData)(
                                                      (0xffffU 
                                                       & (IData)(
                                                                 (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                  >> 0x20U))))))) 
                >> 0x10U) | ((IData)(((((QData)((IData)(
                                                        (((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input) 
                                                          << 0x10U) 
                                                         | (0xffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                       >> 0x10U)))))) 
                                        << 0x10U) | (QData)((IData)(
                                                                    (0xffffU 
                                                                     & (IData)(
                                                                               (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                                >> 0x20U)))))) 
                                      >> 0x20U)) << 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = ((0xffff0000U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[2U]) 
               | (0xffffU & (IData)((vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                     >> 0x30U))));
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[0U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem[0U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[1U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem[1U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem[2U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem[3U];
    if ((2U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadi))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = ((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[2U]) 
               | ((IData)((((QData)((IData)((((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input) 
                                              << 0x10U) 
                                             | (0xffffU 
                                                & (IData)(
                                                          (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                           >> 0x10U)))))) 
                            << 0x10U) | (QData)((IData)(
                                                        (0xffffU 
                                                         & (IData)(
                                                                   (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                    >> 0x20U))))))) 
                  << 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
            = (((IData)((((QData)((IData)((((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input) 
                                            << 0x10U) 
                                           | (0xffffU 
                                              & (IData)(
                                                        (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                         >> 0x10U)))))) 
                          << 0x10U) | (QData)((IData)(
                                                      (0xffffU 
                                                       & (IData)(
                                                                 (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                  >> 0x20U))))))) 
                >> 0x10U) | ((IData)(((((QData)((IData)(
                                                        (((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input) 
                                                          << 0x10U) 
                                                         | (0xffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                       >> 0x10U)))))) 
                                        << 0x10U) | (QData)((IData)(
                                                                    (0xffffU 
                                                                     & (IData)(
                                                                               (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                                >> 0x20U)))))) 
                                      >> 0x20U)) << 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = ((0xffff0000U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[2U]) 
               | (0xffffU & (IData)((vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                     >> 0x30U))));
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[0U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem[0U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[1U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem[1U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem[2U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem[3U];
    if ((4U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadi))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = ((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[2U]) 
               | ((IData)((((QData)((IData)((((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input) 
                                              << 0x10U) 
                                             | (0xffffU 
                                                & (IData)(
                                                          (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                           >> 0x10U)))))) 
                            << 0x10U) | (QData)((IData)(
                                                        (0xffffU 
                                                         & (IData)(
                                                                   (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                    >> 0x20U))))))) 
                  << 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
            = (((IData)((((QData)((IData)((((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input) 
                                            << 0x10U) 
                                           | (0xffffU 
                                              & (IData)(
                                                        (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                         >> 0x10U)))))) 
                          << 0x10U) | (QData)((IData)(
                                                      (0xffffU 
                                                       & (IData)(
                                                                 (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                  >> 0x20U))))))) 
                >> 0x10U) | ((IData)(((((QData)((IData)(
                                                        (((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input) 
                                                          << 0x10U) 
                                                         | (0xffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                       >> 0x10U)))))) 
                                        << 0x10U) | (QData)((IData)(
                                                                    (0xffffU 
                                                                     & (IData)(
                                                                               (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                                >> 0x20U)))))) 
                                      >> 0x20U)) << 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = ((0xffff0000U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[2U]) 
               | (0xffffU & (IData)((vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                     >> 0x30U))));
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[0U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem[0U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[1U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem[1U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem[2U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem[3U];
    if ((8U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadi))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = ((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[2U]) 
               | ((IData)((((QData)((IData)((((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input) 
                                              << 0x10U) 
                                             | (0xffffU 
                                                & (IData)(
                                                          (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                           >> 0x10U)))))) 
                            << 0x10U) | (QData)((IData)(
                                                        (0xffffU 
                                                         & (IData)(
                                                                   (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                    >> 0x20U))))))) 
                  << 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
            = (((IData)((((QData)((IData)((((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input) 
                                            << 0x10U) 
                                           | (0xffffU 
                                              & (IData)(
                                                        (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                         >> 0x10U)))))) 
                          << 0x10U) | (QData)((IData)(
                                                      (0xffffU 
                                                       & (IData)(
                                                                 (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                  >> 0x20U))))))) 
                >> 0x10U) | ((IData)(((((QData)((IData)(
                                                        (((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input) 
                                                          << 0x10U) 
                                                         | (0xffffU 
                                                            & (IData)(
                                                                      (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                       >> 0x10U)))))) 
                                        << 0x10U) | (QData)((IData)(
                                                                    (0xffffU 
                                                                     & (IData)(
                                                                               (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                                                                >> 0x20U)))))) 
                                      >> 0x20U)) << 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = ((0xffff0000U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[2U]) 
               | (0xffffU & (IData)((vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input 
                                     >> 0x30U))));
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[0U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem[0U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[1U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem[1U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem[2U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem[3U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem[4U];
    if (vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.fifo_shift) {
        VL_SHIFTR_WWI(128,128,32, __Vtemp_2, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next, 0x10U);
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[0U] 
            = __Vtemp_2[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[1U] 
            = __Vtemp_2[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = __Vtemp_2[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
            = __Vtemp_2[3U];
        VL_SHIFTR_WWI(128,128,32, __Vtemp_3, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next, 0x10U);
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[0U] 
            = __Vtemp_3[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[1U] 
            = __Vtemp_3[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = __Vtemp_3[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
            = __Vtemp_3[3U];
        VL_SHIFTR_WWI(128,128,32, __Vtemp_4, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next, 0x10U);
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[0U] 
            = __Vtemp_4[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[1U] 
            = __Vtemp_4[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = __Vtemp_4[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
            = __Vtemp_4[3U];
        VL_SHIFTR_WWI(128,128,32, __Vtemp_5, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next, 0x10U);
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[0U] 
            = __Vtemp_5[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[1U] 
            = __Vtemp_5[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = __Vtemp_5[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
            = __Vtemp_5[3U];
        VL_SHIFTR_WWI(144,144,32, __Vtemp_7, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem, 0x10U);
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[0U] 
            = __Vtemp_7[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[1U] 
            = __Vtemp_7[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
            = __Vtemp_7[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = __Vtemp_7[3U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
            = (0xffffU & __Vtemp_7[4U]);
    }
    if ((1U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadps))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
            = (0xffffU & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials 
                                  >> 0x10U)));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = ((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U]) 
               | ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0) 
                  << 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials 
                                  >> 0x20U)));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = ((0xffff0000U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U]) 
               | (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials 
                                  >> 0x30U)));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
            = ((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U]) 
               | ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0) 
                  << 0x10U));
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[0U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem[0U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[1U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem[1U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem[2U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem[3U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem[4U];
    if (vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.fifo_shift) {
        VL_SHIFTR_WWI(144,144,32, __Vtemp_9, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem, 0x10U);
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[0U] 
            = __Vtemp_9[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[1U] 
            = __Vtemp_9[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
            = __Vtemp_9[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = __Vtemp_9[3U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
            = (0xffffU & __Vtemp_9[4U]);
    }
    if ((2U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadps))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
            = (0xffffU & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials 
                                  >> 0x10U)));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = ((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U]) 
               | ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0) 
                  << 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials 
                                  >> 0x20U)));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = ((0xffff0000U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U]) 
               | (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials 
                                  >> 0x30U)));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
            = ((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U]) 
               | ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0) 
                  << 0x10U));
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[0U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem[0U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[1U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem[1U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem[2U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem[3U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem[4U];
    if (vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.fifo_shift) {
        VL_SHIFTR_WWI(144,144,32, __Vtemp_11, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem, 0x10U);
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[0U] 
            = __Vtemp_11[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[1U] 
            = __Vtemp_11[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
            = __Vtemp_11[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = __Vtemp_11[3U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
            = (0xffffU & __Vtemp_11[4U]);
    }
    if ((4U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadps))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
            = (0xffffU & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials 
                                  >> 0x10U)));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = ((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U]) 
               | ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0) 
                  << 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials 
                                  >> 0x20U)));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = ((0xffff0000U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U]) 
               | (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials 
                                  >> 0x30U)));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
            = ((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U]) 
               | ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0) 
                  << 0x10U));
    }
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[0U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem[0U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[1U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem[1U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem[2U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem[3U];
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem[4U];
    if (vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.fifo_shift) {
        VL_SHIFTR_WWI(144,144,32, __Vtemp_13, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem, 0x10U);
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[0U] 
            = __Vtemp_13[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[1U] 
            = __Vtemp_13[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
            = __Vtemp_13[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = __Vtemp_13[3U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
            = (0xffffU & __Vtemp_13[4U]);
    }
    if ((8U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadps))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
            = (0xffffU & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials 
                                  >> 0x10U)));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = ((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U]) 
               | ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0) 
                  << 0x10U));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials 
                                  >> 0x20U)));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = ((0xffff0000U & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U]) 
               | (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0 
            = (0xffffU & (IData)((vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials 
                                  >> 0x30U)));
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
            = ((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U]) 
               | ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0) 
                  << 0x10U));
    }
}
