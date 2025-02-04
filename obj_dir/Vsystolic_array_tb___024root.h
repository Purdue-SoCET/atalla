// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsystolic_array_tb.h for the primary calling header

#ifndef VERILATED_VSYSTOLIC_ARRAY_TB___024ROOT_H_
#define VERILATED_VSYSTOLIC_ARRAY_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vsystolic_array_tb_systolic_array_MAC_if;
class Vsystolic_array_tb_systolic_array_add_if;
class Vsystolic_array_tb_systolic_array_control_unit_if;
class Vsystolic_array_tb_systolic_array_if;


class Vsystolic_array_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsystolic_array_tb___024root final : public VerilatedModule {
  public:
    // CELLS
    Vsystolic_array_tb_systolic_array_if* __PVT__systolic_array_tb__DOT__memory_if;
    Vsystolic_array_tb_systolic_array_control_unit_if* __PVT__systolic_array_tb__DOT__DUT__DOT__control_unit_if;
    Vsystolic_array_tb_systolic_array_MAC_if* __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__15__KET__;
    Vsystolic_array_tb_systolic_array_MAC_if* __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__14__KET__;
    Vsystolic_array_tb_systolic_array_MAC_if* __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__13__KET__;
    Vsystolic_array_tb_systolic_array_MAC_if* __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__12__KET__;
    Vsystolic_array_tb_systolic_array_MAC_if* __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__11__KET__;
    Vsystolic_array_tb_systolic_array_MAC_if* __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__10__KET__;
    Vsystolic_array_tb_systolic_array_MAC_if* __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__9__KET__;
    Vsystolic_array_tb_systolic_array_MAC_if* __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__8__KET__;
    Vsystolic_array_tb_systolic_array_MAC_if* __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__7__KET__;
    Vsystolic_array_tb_systolic_array_MAC_if* __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__6__KET__;
    Vsystolic_array_tb_systolic_array_MAC_if* __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__5__KET__;
    Vsystolic_array_tb_systolic_array_MAC_if* __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__4__KET__;
    Vsystolic_array_tb_systolic_array_MAC_if* __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__3__KET__;
    Vsystolic_array_tb_systolic_array_MAC_if* __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__2__KET__;
    Vsystolic_array_tb_systolic_array_MAC_if* __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__1__KET__;
    Vsystolic_array_tb_systolic_array_MAC_if* __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__0__KET__;
    Vsystolic_array_tb_systolic_array_add_if* __PVT__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__3__KET__;
    Vsystolic_array_tb_systolic_array_add_if* __PVT__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__2__KET__;
    Vsystolic_array_tb_systolic_array_add_if* __PVT__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__1__KET__;
    Vsystolic_array_tb_systolic_array_add_if* __PVT__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__0__KET__;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ systolic_array_tb__DOT__tb_nRST;
        CData/*0:0*/ systolic_array_tb__DOT__tb_clk;
        CData/*3:0*/ systolic_array_tb__DOT__DUT__DOT__loadi;
        CData/*3:0*/ systolic_array_tb__DOT__DUT__DOT__loadw;
        CData/*3:0*/ systolic_array_tb__DOT__DUT__DOT__loadps;
        CData/*1:0*/ systolic_array_tb__DOT__DUT__DOT__row_out;
        CData/*2:0*/ systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_count;
        CData/*0:0*/ systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_start;
        CData/*1:0*/ systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_add_count;
        CData/*0:0*/ systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_add_start;
        CData/*2:0*/ systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration_full;
        CData/*2:0*/ systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full;
        CData/*1:0*/ systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__input_tracker;
        CData/*1:0*/ systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__data_loaded;
        CData/*1:0*/ systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_data_loaded;
        CData/*0:0*/ systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__MAC_done;
        CData/*0:0*/ systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_done;
        CData/*0:0*/ systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT____Vlvbound_hd9ef4104__0;
        CData/*3:0*/ systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT____Vlvbound_haaf93ebe__0;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__systolic_array_tb__DOT__tb_clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__systolic_array_tb__DOT__tb_nRST__0;
        CData/*0:0*/ __VactContinue;
        SData/*15:0*/ systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0;
        SData/*15:0*/ systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0;
        SData/*15:0*/ systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0;
        SData/*15:0*/ systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT____Vlvbound_h574c72a0__0;
        IData/*31:0*/ systolic_array_tb__DOT__DUT__DOT__z;
        IData/*31:0*/ systolic_array_tb__DOT__DUT__DOT__y;
        IData/*31:0*/ systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__i;
        IData/*31:0*/ systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__j;
        IData/*31:0*/ systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__k;
        IData/*31:0*/ systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__q;
        VlWide<4>/*127:0*/ systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem;
        VlWide<4>/*127:0*/ systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next;
        IData/*31:0*/ systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__i;
        VlWide<4>/*127:0*/ systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem;
        VlWide<4>/*127:0*/ systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next;
        IData/*31:0*/ systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__i;
        VlWide<4>/*127:0*/ systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem;
        VlWide<4>/*127:0*/ systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next;
        IData/*31:0*/ systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__i;
        VlWide<4>/*127:0*/ systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem;
        VlWide<4>/*127:0*/ systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next;
        IData/*31:0*/ systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__i;
        VlWide<5>/*143:0*/ systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem;
        VlWide<5>/*143:0*/ systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next;
        IData/*31:0*/ systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__i;
        VlWide<5>/*143:0*/ systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem;
        VlWide<5>/*143:0*/ systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next;
        IData/*31:0*/ systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__i;
        VlWide<5>/*143:0*/ systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem;
        VlWide<5>/*143:0*/ systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next;
        IData/*31:0*/ systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__i;
        VlWide<5>/*143:0*/ systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem;
        VlWide<5>/*143:0*/ systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next;
        IData/*31:0*/ systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__i;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ systolic_array_tb__DOT__DUT__DOT__top_input;
        QData/*63:0*/ systolic_array_tb__DOT__DUT__DOT__weights_input;
        VlWide<8>/*255:0*/ systolic_array_tb__DOT__DUT__DOT__current_out;
        QData/*63:0*/ systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__0__KET____DOT__o_fifo__DOT__fifo_mem;
        QData/*63:0*/ systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__0__KET____DOT__o_fifo__DOT__fifo_mem_next;
        QData/*63:0*/ systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__1__KET____DOT__o_fifo__DOT__fifo_mem;
    };
    struct {
        QData/*63:0*/ systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__1__KET____DOT__o_fifo__DOT__fifo_mem_next;
        QData/*63:0*/ systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__2__KET____DOT__o_fifo__DOT__fifo_mem;
        QData/*63:0*/ systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__2__KET____DOT__o_fifo__DOT__fifo_mem_next;
        QData/*63:0*/ systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__3__KET____DOT__o_fifo__DOT__fifo_mem;
        QData/*63:0*/ systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__3__KET____DOT__o_fifo__DOT__fifo_mem_next;
        VlUnpacked<VlUnpacked<SData/*15:0*/, 4>, 4> systolic_array_tb__DOT__DUT__DOT__MAC_inputs;
        VlUnpacked<VlUnpacked<SData/*15:0*/, 4>, 4> systolic_array_tb__DOT__DUT__DOT__MAC_outputs;
        VlUnpacked<VlUnpacked<SData/*15:0*/, 4>, 4> systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs;
        VlUnpacked<SData/*15:0*/, 4> systolic_array_tb__DOT__DUT__DOT__ps_add_inputs;
        VlUnpacked<QData/*63:0*/, 4> systolic_array_tb__DOT__DUT__DOT__weights;
        VlUnpacked<CData/*3:0*/, 3> systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration;
        VlUnpacked<CData/*3:0*/, 3> systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration;
        VlUnpacked<CData/*0:0*/, 7> __Vm_traceActivity;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h8059f569__0;
    VlTriggerScheduler __VtrigSched_h8059f538__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vsystolic_array_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsystolic_array_tb___024root(Vsystolic_array_tb__Syms* symsp, const char* v__name);
    ~Vsystolic_array_tb___024root();
    VL_UNCOPYABLE(Vsystolic_array_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
