// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsystolic_array_tb.h for the primary calling header

#include "Vsystolic_array_tb__pch.h"
#include "Vsystolic_array_tb__Syms.h"
#include "Vsystolic_array_tb___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsystolic_array_tb___024root___dump_triggers__stl(Vsystolic_array_tb___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsystolic_array_tb___024root___eval_triggers__stl(Vsystolic_array_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array_tb___024root___eval_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsystolic_array_tb___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

extern const VlUnpacked<CData/*0:0*/, 32> Vsystolic_array_tb__ConstPool__TABLE_h2d70b61b_0;
extern const VlUnpacked<CData/*1:0*/, 32> Vsystolic_array_tb__ConstPool__TABLE_h5bec8395_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vsystolic_array_tb__ConstPool__TABLE_hc6a7dea8_0;
extern const VlUnpacked<CData/*1:0*/, 32> Vsystolic_array_tb__ConstPool__TABLE_hd2e7befa_0;
extern const VlUnpacked<CData/*1:0*/, 32> Vsystolic_array_tb__ConstPool__TABLE_h3c738066_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vsystolic_array_tb__ConstPool__TABLE_haf0b274b_0;

VL_ATTR_COLD void Vsystolic_array_tb___024root___stl_sequent__TOP__0(Vsystolic_array_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array_tb___024root___stl_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    VlWide<4>/*127:0*/ __Vtemp_6;
    VlWide<4>/*127:0*/ __Vtemp_7;
    VlWide<4>/*127:0*/ __Vtemp_8;
    VlWide<4>/*127:0*/ __Vtemp_9;
    VlWide<5>/*159:0*/ __Vtemp_11;
    VlWide<5>/*159:0*/ __Vtemp_13;
    VlWide<5>/*159:0*/ __Vtemp_15;
    VlWide<5>/*159:0*/ __Vtemp_17;
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
                goto __Vlabel1;
            }
            vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__q 
                = ((IData)(1U) + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__q);
        }
        __Vlabel1: ;
    }
    if (((IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.add_start) 
         | (0U < (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.add_count)))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_add_count 
            = (3U & ((IData)(1U) + (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.add_count)));
        if ((3U == (IData)(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.add_count))) {
            vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_add_count = 0U;
        }
    }
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
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.iteration[2U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
        [2U];
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.iteration[1U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
        [1U];
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.iteration[0U] 
        = vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration
        [0U];
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.out_fifo_shift = 0U;
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
    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_start = 0U;
    if ((((3U == (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__data_loaded)) 
          | (1U == (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__input_tracker))) 
         & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__MAC_done))) {
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_count = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_done = 0U;
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_start = 1U;
    }
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
                    goto __Vlabel3;
                }
            }
            vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__i 
                = ((IData)(1U) + vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__i);
        }
        __Vlabel3: ;
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
    vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.fifo_shift = 0U;
    if (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_start) {
        vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.fifo_shift = 1U;
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
        VL_SHIFTR_WWI(128,128,32, __Vtemp_6, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next, 0x10U);
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[0U] 
            = __Vtemp_6[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[1U] 
            = __Vtemp_6[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = __Vtemp_6[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
            = __Vtemp_6[3U];
        VL_SHIFTR_WWI(128,128,32, __Vtemp_7, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next, 0x10U);
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[0U] 
            = __Vtemp_7[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[1U] 
            = __Vtemp_7[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = __Vtemp_7[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
            = __Vtemp_7[3U];
        VL_SHIFTR_WWI(128,128,32, __Vtemp_8, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next, 0x10U);
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[0U] 
            = __Vtemp_8[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[1U] 
            = __Vtemp_8[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = __Vtemp_8[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
            = __Vtemp_8[3U];
        VL_SHIFTR_WWI(128,128,32, __Vtemp_9, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next, 0x10U);
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[0U] 
            = __Vtemp_9[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[1U] 
            = __Vtemp_9[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[2U] 
            = __Vtemp_9[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next[3U] 
            = __Vtemp_9[3U];
        VL_SHIFTR_WWI(144,144,32, __Vtemp_11, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem, 0x10U);
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[0U] 
            = __Vtemp_11[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[1U] 
            = __Vtemp_11[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
            = __Vtemp_11[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = __Vtemp_11[3U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
            = (0xffffU & __Vtemp_11[4U]);
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
        VL_SHIFTR_WWI(144,144,32, __Vtemp_13, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem, 0x10U);
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[0U] 
            = __Vtemp_13[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[1U] 
            = __Vtemp_13[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
            = __Vtemp_13[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = __Vtemp_13[3U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
            = (0xffffU & __Vtemp_13[4U]);
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
        VL_SHIFTR_WWI(144,144,32, __Vtemp_15, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem, 0x10U);
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[0U] 
            = __Vtemp_15[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[1U] 
            = __Vtemp_15[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
            = __Vtemp_15[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = __Vtemp_15[3U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
            = (0xffffU & __Vtemp_15[4U]);
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
        VL_SHIFTR_WWI(144,144,32, __Vtemp_17, vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem, 0x10U);
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[0U] 
            = __Vtemp_17[0U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[1U] 
            = __Vtemp_17[1U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[2U] 
            = __Vtemp_17[2U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[3U] 
            = __Vtemp_17[3U];
        vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next[4U] 
            = (0xffffU & __Vtemp_17[4U]);
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
