// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsysarr_OUT_FIFO.h for the primary calling header

#include "Vsysarr_OUT_FIFO__pch.h"
#include "Vsysarr_OUT_FIFO__Syms.h"
#include "Vsysarr_OUT_FIFO___024root.h"

VL_INLINE_OPT VlCoroutine Vsysarr_OUT_FIFO___024root___eval_initial__TOP__Vtiming__0(Vsysarr_OUT_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_OUT_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_OUT_FIFO___024root___eval_initial__TOP__Vtiming__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__Vstatic__i;
    sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__Vstatic__i = 0;
    IData/*31:0*/ __Vtask_sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__1__num_cycles;
    __Vtask_sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__1__num_cycles = 0;
    IData/*31:0*/ __Vtask_sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__2__num_cycles;
    __Vtask_sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__2__num_cycles = 0;
    IData/*31:0*/ __Vtask_sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__3__num_cycles;
    __Vtask_sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__3__num_cycles = 0;
    IData/*31:0*/ __Vtask_sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__4__num_cycles;
    __Vtask_sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__4__num_cycles = 0;
    // Body
    vlSelfRef.sysarr_OUT_FIFO_tb__DOT__tb_clk = 0U;
    vlSymsp->TOP__sysarr_OUT_FIFO_tb__DOT__fifo_if.shift = 0U;
    vlSymsp->TOP__sysarr_OUT_FIFO_tb__DOT__fifo_if.shift_value = 0U;
    vlSelfRef.sysarr_OUT_FIFO_tb__DOT__tb_nrst = 0U;
    co_await vlSelfRef.__VtrigSched_h263db71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge sysarr_OUT_FIFO_tb.tb_clk)", 
                                                         "src/testbench/sysarr_OUT_FIFO_tb.sv", 
                                                         30);
    co_await vlSelfRef.__VtrigSched_h263db71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge sysarr_OUT_FIFO_tb.tb_clk)", 
                                                         "src/testbench/sysarr_OUT_FIFO_tb.sv", 
                                                         31);
    co_await vlSelfRef.__VtrigSched_h263db7df__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge sysarr_OUT_FIFO_tb.tb_clk)", 
                                                         "src/testbench/sysarr_OUT_FIFO_tb.sv", 
                                                         32);
    vlSelfRef.sysarr_OUT_FIFO_tb__DOT__tb_nrst = 1U;
    co_await vlSelfRef.__VtrigSched_h263db71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge sysarr_OUT_FIFO_tb.tb_clk)", 
                                                         "src/testbench/sysarr_OUT_FIFO_tb.sv", 
                                                         34);
    co_await vlSelfRef.__VtrigSched_h263db71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge sysarr_OUT_FIFO_tb.tb_clk)", 
                                                         "src/testbench/sysarr_OUT_FIFO_tb.sv", 
                                                         35);
    VL_WRITEF_NX("fifo output before shift = %x\n",0,
                 64,vlSelfRef.sysarr_OUT_FIFO_tb__DOT__DUT__DOT__fifo_mem);
    vlSymsp->TOP__sysarr_OUT_FIFO_tb__DOT__fifo_if.shift_value = 0x123U;
    vlSymsp->TOP__sysarr_OUT_FIFO_tb__DOT__fifo_if.shift = 1U;
    __Vtask_sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__1__num_cycles = 1U;
    sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__Vstatic__i = 0U;
    while (VL_LTS_III(32, sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__Vstatic__i, __Vtask_sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__1__num_cycles)) {
        co_await vlSelfRef.__VtrigSched_h263db71e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge sysarr_OUT_FIFO_tb.tb_clk)", 
                                                             "src/testbench/sysarr_OUT_FIFO_tb.sv", 
                                                             24);
        sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__Vstatic__i 
            = ((IData)(1U) + sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__Vstatic__i);
    }
    VL_WRITEF_NX("fifo output after 1 shift = %x\n",0,
                 64,vlSelfRef.sysarr_OUT_FIFO_tb__DOT__DUT__DOT__fifo_mem);
    vlSymsp->TOP__sysarr_OUT_FIFO_tb__DOT__fifo_if.shift_value = 0x4567U;
    vlSymsp->TOP__sysarr_OUT_FIFO_tb__DOT__fifo_if.shift = 1U;
    __Vtask_sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__2__num_cycles = 1U;
    sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__Vstatic__i = 0U;
    while (VL_LTS_III(32, sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__Vstatic__i, __Vtask_sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__2__num_cycles)) {
        co_await vlSelfRef.__VtrigSched_h263db71e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge sysarr_OUT_FIFO_tb.tb_clk)", 
                                                             "src/testbench/sysarr_OUT_FIFO_tb.sv", 
                                                             24);
        sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__Vstatic__i 
            = ((IData)(1U) + sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__Vstatic__i);
    }
    VL_WRITEF_NX("fifo output after 2 shift = %x\n",0,
                 64,vlSelfRef.sysarr_OUT_FIFO_tb__DOT__DUT__DOT__fifo_mem);
    vlSymsp->TOP__sysarr_OUT_FIFO_tb__DOT__fifo_if.shift_value = 0x89abU;
    vlSymsp->TOP__sysarr_OUT_FIFO_tb__DOT__fifo_if.shift = 1U;
    __Vtask_sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__3__num_cycles = 1U;
    sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__Vstatic__i = 0U;
    while (VL_LTS_III(32, sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__Vstatic__i, __Vtask_sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__3__num_cycles)) {
        co_await vlSelfRef.__VtrigSched_h263db71e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge sysarr_OUT_FIFO_tb.tb_clk)", 
                                                             "src/testbench/sysarr_OUT_FIFO_tb.sv", 
                                                             24);
        sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__Vstatic__i 
            = ((IData)(1U) + sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__Vstatic__i);
    }
    VL_WRITEF_NX("fifo output after 3 shift = %x\n",0,
                 64,vlSelfRef.sysarr_OUT_FIFO_tb__DOT__DUT__DOT__fifo_mem);
    vlSymsp->TOP__sysarr_OUT_FIFO_tb__DOT__fifo_if.shift_value = 0xcdefU;
    vlSymsp->TOP__sysarr_OUT_FIFO_tb__DOT__fifo_if.shift = 1U;
    __Vtask_sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__4__num_cycles = 1U;
    sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__Vstatic__i = 0U;
    while (VL_LTS_III(32, sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__Vstatic__i, __Vtask_sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__4__num_cycles)) {
        co_await vlSelfRef.__VtrigSched_h263db71e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge sysarr_OUT_FIFO_tb.tb_clk)", 
                                                             "src/testbench/sysarr_OUT_FIFO_tb.sv", 
                                                             24);
        sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__Vstatic__i 
            = ((IData)(1U) + sysarr_OUT_FIFO_tb__DOT__wait_n_clocks__Vstatic__i);
    }
    VL_WRITEF_NX("fifo output after 4 shift = %x\n",0,
                 64,vlSelfRef.sysarr_OUT_FIFO_tb__DOT__DUT__DOT__fifo_mem);
    vlSymsp->TOP__sysarr_OUT_FIFO_tb__DOT__fifo_if.shift = 0U;
    vlSelfRef.sysarr_OUT_FIFO_tb__DOT__tb_nrst = 0U;
    co_await vlSelfRef.__VtrigSched_h263db71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge sysarr_OUT_FIFO_tb.tb_clk)", 
                                                         "src/testbench/sysarr_OUT_FIFO_tb.sv", 
                                                         30);
    co_await vlSelfRef.__VtrigSched_h263db71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge sysarr_OUT_FIFO_tb.tb_clk)", 
                                                         "src/testbench/sysarr_OUT_FIFO_tb.sv", 
                                                         31);
    co_await vlSelfRef.__VtrigSched_h263db7df__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge sysarr_OUT_FIFO_tb.tb_clk)", 
                                                         "src/testbench/sysarr_OUT_FIFO_tb.sv", 
                                                         32);
    vlSelfRef.sysarr_OUT_FIFO_tb__DOT__tb_nrst = 1U;
    co_await vlSelfRef.__VtrigSched_h263db71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge sysarr_OUT_FIFO_tb.tb_clk)", 
                                                         "src/testbench/sysarr_OUT_FIFO_tb.sv", 
                                                         34);
    co_await vlSelfRef.__VtrigSched_h263db71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge sysarr_OUT_FIFO_tb.tb_clk)", 
                                                         "src/testbench/sysarr_OUT_FIFO_tb.sv", 
                                                         35);
    VL_WRITEF_NX("fifo output after reset = %x\n",0,
                 64,vlSelfRef.sysarr_OUT_FIFO_tb__DOT__DUT__DOT__fifo_mem);
    co_await vlSelfRef.__VdlySched.delay(0x32ULL, nullptr, 
                                         "src/testbench/sysarr_OUT_FIFO_tb.sv", 
                                         72);
    VL_STOP_MT("src/testbench/sysarr_OUT_FIFO_tb.sv", 73, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsysarr_OUT_FIFO___024root___dump_triggers__act(Vsysarr_OUT_FIFO___024root* vlSelf);
#endif  // VL_DEBUG

void Vsysarr_OUT_FIFO___024root___eval_triggers__act(Vsysarr_OUT_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_OUT_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_OUT_FIFO___024root___eval_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.sysarr_OUT_FIFO_tb__DOT__tb_clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sysarr_OUT_FIFO_tb__DOT__tb_clk__0))));
    vlSelfRef.__VactTriggered.set(1U, ((~ (IData)(vlSelfRef.sysarr_OUT_FIFO_tb__DOT__tb_nrst)) 
                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sysarr_OUT_FIFO_tb__DOT__tb_nrst__0)));
    vlSelfRef.__VactTriggered.set(2U, ((~ (IData)(vlSelfRef.sysarr_OUT_FIFO_tb__DOT__tb_clk)) 
                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sysarr_OUT_FIFO_tb__DOT__tb_clk__0)));
    vlSelfRef.__VactTriggered.set(3U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__sysarr_OUT_FIFO_tb__DOT__tb_clk__0 
        = vlSelfRef.sysarr_OUT_FIFO_tb__DOT__tb_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__sysarr_OUT_FIFO_tb__DOT__tb_nrst__0 
        = vlSelfRef.sysarr_OUT_FIFO_tb__DOT__tb_nrst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsysarr_OUT_FIFO___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vsysarr_OUT_FIFO___024root___act_comb__TOP__0(Vsysarr_OUT_FIFO___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsysarr_OUT_FIFO__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsysarr_OUT_FIFO___024root___act_comb__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.sysarr_OUT_FIFO_tb__DOT__DUT__DOT__fifo_mem_next 
        = vlSelfRef.sysarr_OUT_FIFO_tb__DOT__DUT__DOT__fifo_mem;
    if (vlSymsp->TOP__sysarr_OUT_FIFO_tb__DOT__fifo_if.shift) {
        vlSelfRef.sysarr_OUT_FIFO_tb__DOT__DUT__DOT__fifo_mem_next 
            = (((QData)((IData)(vlSymsp->TOP__sysarr_OUT_FIFO_tb__DOT__fifo_if.shift_value)) 
                << 0x30U) | (vlSelfRef.sysarr_OUT_FIFO_tb__DOT__DUT__DOT__fifo_mem 
                             >> 0x10U));
    }
}
