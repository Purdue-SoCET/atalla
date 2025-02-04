// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsysarr_FIFO.h for the primary calling header

#ifndef VERILATED_VSYSARR_FIFO___024ROOT_H_
#define VERILATED_VSYSARR_FIFO___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vsysarr_FIFO_systolic_array_FIFO_if;


class Vsysarr_FIFO__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsysarr_FIFO___024root final : public VerilatedModule {
  public:
    // CELLS
    Vsysarr_FIFO_systolic_array_FIFO_if* __PVT__sysarr_FIFO_tb__DOT__fifo_if;

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ sysarr_FIFO_tb__DOT__tb_clk;
    CData/*0:0*/ sysarr_FIFO_tb__DOT__tb_nrst;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__sysarr_FIFO_tb__DOT__tb_clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__sysarr_FIFO_tb__DOT__tb_nrst__0;
    CData/*0:0*/ __VactContinue;
    VlWide<4>/*127:0*/ sysarr_FIFO_tb__DOT__DUT__DOT__fifo_mem;
    VlWide<4>/*127:0*/ sysarr_FIFO_tb__DOT__DUT__DOT__fifo_mem_next;
    IData/*31:0*/ __VactIterCount;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h4f401444__0;
    VlTriggerScheduler __VtrigSched_h4f401405__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vsysarr_FIFO__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsysarr_FIFO___024root(Vsysarr_FIFO__Syms* symsp, const char* v__name);
    ~Vsysarr_FIFO___024root();
    VL_UNCOPYABLE(Vsysarr_FIFO___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
