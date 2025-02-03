// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsysarr_PS_FIFO.h for the primary calling header

#include "Vsysarr_PS_FIFO__pch.h"
#include "Vsysarr_PS_FIFO__Syms.h"
#include "Vsysarr_PS_FIFO___024root.h"

VL_INLINE_OPT VlCoroutine Vsysarr_PS_FIFO___024root___eval_initial__TOP__Vtiming__0(Vsysarr_PS_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_PS_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_PS_FIFO___024root___eval_initial__TOP__Vtiming__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i;
    sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i = 0;
    IData/*31:0*/ __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__1__num_cycles;
    __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__1__num_cycles = 0;
    IData/*31:0*/ __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__2__num_cycles;
    __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__2__num_cycles = 0;
    IData/*31:0*/ __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__3__num_cycles;
    __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__3__num_cycles = 0;
    // Body
    vlSelfRef.sysarr_PS_FIFO_tb__DOT__tb_clk = 0U;
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.load = 0U;
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 0U;
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.load_values = 0ULL;
    vlSelfRef.sysarr_PS_FIFO_tb__DOT__tb_nrst = 0U;
    co_await vlSelfRef.__VtrigSched_hb54afee6__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge sysarr_PS_FIFO_tb.tb_clk)", 
                                                         "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                                         33);
    co_await vlSelfRef.__VtrigSched_hb54afee6__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge sysarr_PS_FIFO_tb.tb_clk)", 
                                                         "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                                         34);
    co_await vlSelfRef.__VtrigSched_hb54afea7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge sysarr_PS_FIFO_tb.tb_clk)", 
                                                         "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                                         35);
    vlSelfRef.sysarr_PS_FIFO_tb__DOT__tb_nrst = 1U;
    co_await vlSelfRef.__VtrigSched_hb54afee6__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge sysarr_PS_FIFO_tb.tb_clk)", 
                                                         "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                                         37);
    co_await vlSelfRef.__VtrigSched_hb54afee6__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge sysarr_PS_FIFO_tb.tb_clk)", 
                                                         "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                                         38);
    VL_WRITEF_NX("ps fifo output before load = %x\n",0,
                 16,(0xffffU & vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem[0U]));
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.load_values = 0x123456789abcdefULL;
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.load = 1U;
    __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__1__num_cycles = 1U;
    sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i = 0U;
    while (VL_LTS_III(32, sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i, __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__1__num_cycles)) {
        co_await vlSelfRef.__VtrigSched_hb54afee6__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge sysarr_PS_FIFO_tb.tb_clk)", 
                                                             "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                                             27);
        sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i 
            = ((IData)(1U) + sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i);
    }
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.load = 0U;
    VL_WRITEF_NX("ps fifo output after load = %x\n",0,
                 16,(0xffffU & vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem[0U]));
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 1U;
    __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__2__num_cycles = 1U;
    sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i = 0U;
    while (VL_LTS_III(32, sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i, __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__2__num_cycles)) {
        co_await vlSelfRef.__VtrigSched_hb54afee6__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge sysarr_PS_FIFO_tb.tb_clk)", 
                                                             "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                                             27);
        sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i 
            = ((IData)(1U) + sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i);
    }
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 0U;
    VL_WRITEF_NX("ps_fifo_if.out = %x\n",0,16,(0xffffU 
                                               & vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem[0U]));
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 1U;
    __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__2__num_cycles = 1U;
    sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i = 0U;
    while (VL_LTS_III(32, sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i, __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__2__num_cycles)) {
        co_await vlSelfRef.__VtrigSched_hb54afee6__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge sysarr_PS_FIFO_tb.tb_clk)", 
                                                             "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                                             27);
        sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i 
            = ((IData)(1U) + sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i);
    }
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 0U;
    VL_WRITEF_NX("ps_fifo_if.out = %x\n",0,16,(0xffffU 
                                               & vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem[0U]));
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 1U;
    __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__2__num_cycles = 1U;
    sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i = 0U;
    while (VL_LTS_III(32, sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i, __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__2__num_cycles)) {
        co_await vlSelfRef.__VtrigSched_hb54afee6__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge sysarr_PS_FIFO_tb.tb_clk)", 
                                                             "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                                             27);
        sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i 
            = ((IData)(1U) + sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i);
    }
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 0U;
    VL_WRITEF_NX("ps_fifo_if.out = %x\n",0,16,(0xffffU 
                                               & vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem[0U]));
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 1U;
    __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__2__num_cycles = 1U;
    sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i = 0U;
    while (VL_LTS_III(32, sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i, __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__2__num_cycles)) {
        co_await vlSelfRef.__VtrigSched_hb54afee6__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge sysarr_PS_FIFO_tb.tb_clk)", 
                                                             "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                                             27);
        sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i 
            = ((IData)(1U) + sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i);
    }
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 0U;
    VL_WRITEF_NX("ps_fifo_if.out = %x\n",0,16,(0xffffU 
                                               & vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem[0U]));
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 1U;
    __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__2__num_cycles = 1U;
    sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i = 0U;
    while (VL_LTS_III(32, sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i, __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__2__num_cycles)) {
        co_await vlSelfRef.__VtrigSched_hb54afee6__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge sysarr_PS_FIFO_tb.tb_clk)", 
                                                             "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                                             27);
        sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i 
            = ((IData)(1U) + sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i);
    }
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 0U;
    VL_WRITEF_NX("ps_fifo_if.out = %x\n",0,16,(0xffffU 
                                               & vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem[0U]));
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 1U;
    __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__2__num_cycles = 1U;
    sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i = 0U;
    while (VL_LTS_III(32, sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i, __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__2__num_cycles)) {
        co_await vlSelfRef.__VtrigSched_hb54afee6__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge sysarr_PS_FIFO_tb.tb_clk)", 
                                                             "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                                             27);
        sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i 
            = ((IData)(1U) + sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i);
    }
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 0U;
    VL_WRITEF_NX("ps_fifo_if.out = %x\n",0,16,(0xffffU 
                                               & vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem[0U]));
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 1U;
    __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__2__num_cycles = 1U;
    sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i = 0U;
    while (VL_LTS_III(32, sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i, __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__2__num_cycles)) {
        co_await vlSelfRef.__VtrigSched_hb54afee6__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge sysarr_PS_FIFO_tb.tb_clk)", 
                                                             "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                                             27);
        sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i 
            = ((IData)(1U) + sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i);
    }
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 0U;
    VL_WRITEF_NX("ps_fifo_if.out = %x\n",0,16,(0xffffU 
                                               & vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem[0U]));
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 1U;
    __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__2__num_cycles = 1U;
    sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i = 0U;
    while (VL_LTS_III(32, sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i, __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__2__num_cycles)) {
        co_await vlSelfRef.__VtrigSched_hb54afee6__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge sysarr_PS_FIFO_tb.tb_clk)", 
                                                             "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                                             27);
        sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i 
            = ((IData)(1U) + sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i);
    }
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 0U;
    VL_WRITEF_NX("ps_fifo_if.out = %x\n",0,16,(0xffffU 
                                               & vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem[0U]));
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.load_values = 0xa5a5a5a5a5a5a5a5ULL;
    co_await vlSelfRef.__VdlySched.delay(0xaULL, nullptr, 
                                         "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                         70);
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.load = 1U;
    co_await vlSelfRef.__VdlySched.delay(0xaULL, nullptr, 
                                         "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                         72);
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.load = 0U;
    VL_WRITEF_NX("ps_fifo_if.out = %x\n",0,16,(0xffffU 
                                               & vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem[0U]));
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 1U;
    __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__3__num_cycles = 1U;
    sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i = 0U;
    while (VL_LTS_III(32, sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i, __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__3__num_cycles)) {
        co_await vlSelfRef.__VtrigSched_hb54afee6__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge sysarr_PS_FIFO_tb.tb_clk)", 
                                                             "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                                             27);
        sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i 
            = ((IData)(1U) + sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i);
    }
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 0U;
    VL_WRITEF_NX("ps_fifo_if.out = %x\n",0,16,(0xffffU 
                                               & vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem[0U]));
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 1U;
    __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__3__num_cycles = 1U;
    sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i = 0U;
    while (VL_LTS_III(32, sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i, __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__3__num_cycles)) {
        co_await vlSelfRef.__VtrigSched_hb54afee6__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge sysarr_PS_FIFO_tb.tb_clk)", 
                                                             "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                                             27);
        sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i 
            = ((IData)(1U) + sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i);
    }
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 0U;
    VL_WRITEF_NX("ps_fifo_if.out = %x\n",0,16,(0xffffU 
                                               & vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem[0U]));
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 1U;
    __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__3__num_cycles = 1U;
    sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i = 0U;
    while (VL_LTS_III(32, sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i, __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__3__num_cycles)) {
        co_await vlSelfRef.__VtrigSched_hb54afee6__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge sysarr_PS_FIFO_tb.tb_clk)", 
                                                             "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                                             27);
        sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i 
            = ((IData)(1U) + sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i);
    }
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 0U;
    VL_WRITEF_NX("ps_fifo_if.out = %x\n",0,16,(0xffffU 
                                               & vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem[0U]));
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 1U;
    __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__3__num_cycles = 1U;
    sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i = 0U;
    while (VL_LTS_III(32, sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i, __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__3__num_cycles)) {
        co_await vlSelfRef.__VtrigSched_hb54afee6__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge sysarr_PS_FIFO_tb.tb_clk)", 
                                                             "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                                             27);
        sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i 
            = ((IData)(1U) + sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i);
    }
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 0U;
    VL_WRITEF_NX("ps_fifo_if.out = %x\n",0,16,(0xffffU 
                                               & vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem[0U]));
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 1U;
    __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__3__num_cycles = 1U;
    sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i = 0U;
    while (VL_LTS_III(32, sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i, __Vtask_sysarr_PS_FIFO_tb__DOT__wait_n_clocks__3__num_cycles)) {
        co_await vlSelfRef.__VtrigSched_hb54afee6__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge sysarr_PS_FIFO_tb.tb_clk)", 
                                                             "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                                             27);
        sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i 
            = ((IData)(1U) + sysarr_PS_FIFO_tb__DOT__wait_n_clocks__Vstatic__i);
    }
    vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift = 0U;
    VL_WRITEF_NX("ps_fifo_if.out = %x\nps_fifo_if.out = %x\n",0,
                 16,(0xffffU & vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem[0U]),
                 16,(0xffffU & vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem[0U]));
    vlSelfRef.sysarr_PS_FIFO_tb__DOT__tb_nrst = 0U;
    co_await vlSelfRef.__VtrigSched_hb54afee6__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge sysarr_PS_FIFO_tb.tb_clk)", 
                                                         "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                                         33);
    co_await vlSelfRef.__VtrigSched_hb54afee6__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge sysarr_PS_FIFO_tb.tb_clk)", 
                                                         "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                                         34);
    co_await vlSelfRef.__VtrigSched_hb54afea7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge sysarr_PS_FIFO_tb.tb_clk)", 
                                                         "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                                         35);
    vlSelfRef.sysarr_PS_FIFO_tb__DOT__tb_nrst = 1U;
    co_await vlSelfRef.__VtrigSched_hb54afee6__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge sysarr_PS_FIFO_tb.tb_clk)", 
                                                         "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                                         37);
    co_await vlSelfRef.__VtrigSched_hb54afee6__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge sysarr_PS_FIFO_tb.tb_clk)", 
                                                         "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                                         38);
    VL_WRITEF_NX("ps_fifo_if.out = %x\n",0,16,(0xffffU 
                                               & vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem[0U]));
    co_await vlSelfRef.__VdlySched.delay(0xaULL, nullptr, 
                                         "src/testbench/sysarr_PS_FIFO_tb.sv", 
                                         86);
    VL_STOP_MT("src/testbench/sysarr_PS_FIFO_tb.sv", 87, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsysarr_PS_FIFO___024root___dump_triggers__act(Vsysarr_PS_FIFO___024root* vlSelf);
#endif  // VL_DEBUG

void Vsysarr_PS_FIFO___024root___eval_triggers__act(Vsysarr_PS_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_PS_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_PS_FIFO___024root___eval_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.sysarr_PS_FIFO_tb__DOT__tb_clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sysarr_PS_FIFO_tb__DOT__tb_clk__0))));
    vlSelfRef.__VactTriggered.set(1U, ((~ (IData)(vlSelfRef.sysarr_PS_FIFO_tb__DOT__tb_nrst)) 
                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sysarr_PS_FIFO_tb__DOT__tb_nrst__0)));
    vlSelfRef.__VactTriggered.set(2U, ((~ (IData)(vlSelfRef.sysarr_PS_FIFO_tb__DOT__tb_clk)) 
                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sysarr_PS_FIFO_tb__DOT__tb_clk__0)));
    vlSelfRef.__VactTriggered.set(3U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__sysarr_PS_FIFO_tb__DOT__tb_clk__0 
        = vlSelfRef.sysarr_PS_FIFO_tb__DOT__tb_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__sysarr_PS_FIFO_tb__DOT__tb_nrst__0 
        = vlSelfRef.sysarr_PS_FIFO_tb__DOT__tb_nrst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsysarr_PS_FIFO___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vsysarr_PS_FIFO___024root___act_comb__TOP__0(Vsysarr_PS_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_PS_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_PS_FIFO___024root___act_comb__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem_next[0U] 
        = vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem[0U];
    vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem_next[1U] 
        = vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem[1U];
    vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem_next[2U] 
        = vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem[2U];
    vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem_next[3U] 
        = vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem[3U];
    if (vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.load) {
        vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem_next[2U] 
            = ((0xffffU & vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem_next[2U]) 
               | ((IData)((((QData)((IData)((((IData)(vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.load_values) 
                                              << 0x10U) 
                                             | (0xffffU 
                                                & (IData)(
                                                          (vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.load_values 
                                                           >> 0x10U)))))) 
                            << 0x10U) | (QData)((IData)(
                                                        (0xffffU 
                                                         & (IData)(
                                                                   (vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.load_values 
                                                                    >> 0x20U))))))) 
                  << 0x10U));
        vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem_next[3U] 
            = (((IData)((((QData)((IData)((((IData)(vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.load_values) 
                                            << 0x10U) 
                                           | (0xffffU 
                                              & (IData)(
                                                        (vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.load_values 
                                                         >> 0x10U)))))) 
                          << 0x10U) | (QData)((IData)(
                                                      (0xffffU 
                                                       & (IData)(
                                                                 (vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.load_values 
                                                                  >> 0x20U))))))) 
                >> 0x10U) | ((IData)(((((QData)((IData)(
                                                        (((IData)(vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.load_values) 
                                                          << 0x10U) 
                                                         | (0xffffU 
                                                            & (IData)(
                                                                      (vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.load_values 
                                                                       >> 0x10U)))))) 
                                        << 0x10U) | (QData)((IData)(
                                                                    (0xffffU 
                                                                     & (IData)(
                                                                               (vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.load_values 
                                                                                >> 0x20U)))))) 
                                      >> 0x20U)) << 0x10U));
        vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem_next[2U] 
            = ((0xffff0000U & vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem_next[2U]) 
               | (0xffffU & (IData)((vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.load_values 
                                     >> 0x30U))));
    } else if (vlSymsp->TOP__sysarr_PS_FIFO_tb__DOT__ps_fifo_if.shift) {
        VL_SHIFTR_WWI(128,128,32, vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem_next, vlSelfRef.sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem, 0x10U);
    }
}
