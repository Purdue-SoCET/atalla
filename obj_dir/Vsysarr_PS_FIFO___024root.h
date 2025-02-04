// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsysarr_PS_FIFO.h for the primary calling header

#ifndef VERILATED_VSYSARR_PS_FIFO___024ROOT_H_
#define VERILATED_VSYSARR_PS_FIFO___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vsysarr_PS_FIFO_systolic_array_PS_FIFO_if;


class Vsysarr_PS_FIFO__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsysarr_PS_FIFO___024root final : public VerilatedModule {
  public:
    // CELLS
    Vsysarr_PS_FIFO_systolic_array_PS_FIFO_if* __PVT__sysarr_PS_FIFO_tb__DOT__ps_fifo_if;

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ sysarr_PS_FIFO_tb__DOT__tb_clk;
    CData/*0:0*/ sysarr_PS_FIFO_tb__DOT__tb_nrst;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__sysarr_PS_FIFO_tb__DOT__tb_clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__sysarr_PS_FIFO_tb__DOT__tb_nrst__0;
    CData/*0:0*/ __VactContinue;
    VlWide<4>/*127:0*/ sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem;
    VlWide<4>/*127:0*/ sysarr_PS_FIFO_tb__DOT__DUT__DOT__ps_fifo_mem_next;
    IData/*31:0*/ __VactIterCount;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hb54afee6__0;
    VlTriggerScheduler __VtrigSched_hb54afea7__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vsysarr_PS_FIFO__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsysarr_PS_FIFO___024root(Vsysarr_PS_FIFO__Syms* symsp, const char* v__name);
    ~Vsysarr_PS_FIFO___024root();
    VL_UNCOPYABLE(Vsysarr_PS_FIFO___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
