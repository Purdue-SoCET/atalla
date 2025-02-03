// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vsystolic_array_tb__Syms.h"


void Vsystolic_array_tb___024root__trace_chg_0_sub_0(Vsystolic_array_tb___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vsystolic_array_tb___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array_tb___024root__trace_chg_0\n"); );
    // Init
    Vsystolic_array_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsystolic_array_tb___024root*>(voidSelf);
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vsystolic_array_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vsystolic_array_tb___024root__trace_chg_0_sub_0(Vsystolic_array_tb___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array_tb___024root__trace_chg_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U] 
                     | vlSelfRef.__Vm_traceActivity
                     [2U]))) {
        bufp->chgBit(oldp+0,(vlSelfRef.systolic_array_tb__DOT__tb_nRST));
        bufp->chgBit(oldp+1,(((IData)(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en) 
                              & (0U == (IData)(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en)))));
        bufp->chgBit(oldp+2,(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.weight_en));
        bufp->chgBit(oldp+3,(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.input_en));
        bufp->chgBit(oldp+4,(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.partial_en));
        bufp->chgCData(oldp+5,(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_en),2);
        bufp->chgQData(oldp+6,(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in),64);
        bufp->chgQData(oldp+8,(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_in_partials),64);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U] 
                     | vlSelfRef.__Vm_traceActivity
                     [5U]))) {
        bufp->chgQData(oldp+10,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__top_input),64);
        bufp->chgQData(oldp+12,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights_input),64);
        bufp->chgCData(oldp+14,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadi),4);
        bufp->chgCData(oldp+15,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadw),4);
        bufp->chgCData(oldp+16,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadps),4);
        bufp->chgIData(oldp+17,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__i),32);
        bufp->chgIData(oldp+18,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__i),32);
        bufp->chgIData(oldp+19,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__i),32);
        bufp->chgIData(oldp+20,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__i),32);
        bufp->chgIData(oldp+21,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__i),32);
        bufp->chgIData(oldp+22,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__i),32);
        bufp->chgIData(oldp+23,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__i),32);
        bufp->chgIData(oldp+24,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__i),32);
        bufp->chgBit(oldp+25,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.input_type));
        bufp->chgBit(oldp+26,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.input_load));
        bufp->chgBit(oldp+27,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.weight_load));
        bufp->chgBit(oldp+28,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.partials_load));
        bufp->chgCData(oldp+29,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.input_row),2);
        bufp->chgCData(oldp+30,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.weight_row),2);
        bufp->chgCData(oldp+31,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.partials_row),2);
        bufp->chgBit(oldp+32,((1U & ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadi) 
                                     >> 3U))));
        bufp->chgBit(oldp+33,((1U & ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadi) 
                                     >> 2U))));
        bufp->chgBit(oldp+34,((1U & ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadi) 
                                     >> 1U))));
        bufp->chgBit(oldp+35,((1U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadi))));
        bufp->chgBit(oldp+36,((1U & ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadps) 
                                     >> 3U))));
        bufp->chgBit(oldp+37,((1U & ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadps) 
                                     >> 2U))));
        bufp->chgBit(oldp+38,((1U & ((IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadps) 
                                     >> 1U))));
        bufp->chgBit(oldp+39,((1U & (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__loadps))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U] 
                     | vlSelfRef.__Vm_traceActivity
                     [6U]))) {
        bufp->chgCData(oldp+40,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration[0]),4);
        bufp->chgCData(oldp+41,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration[1]),4);
        bufp->chgCData(oldp+42,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration[2]),4);
        bufp->chgCData(oldp+43,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_iteration_full),3);
        bufp->chgCData(oldp+44,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_data_loaded),2);
        bufp->chgIData(oldp+45,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__i),32);
        bufp->chgIData(oldp+46,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__j),32);
        bufp->chgWData(oldp+47,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem_next),128);
        bufp->chgWData(oldp+51,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem_next),128);
        bufp->chgWData(oldp+55,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem_next),128);
        bufp->chgWData(oldp+59,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem_next),128);
        bufp->chgWData(oldp+63,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next),144);
        bufp->chgWData(oldp+68,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next),144);
        bufp->chgWData(oldp+73,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next),144);
        bufp->chgWData(oldp+78,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem_next),144);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[4U])) {
        bufp->chgSData(oldp+83,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                [0U][0U]),16);
        bufp->chgSData(oldp+84,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                [0U][1U]),16);
        bufp->chgSData(oldp+85,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                [0U][2U]),16);
        bufp->chgSData(oldp+86,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                [0U][3U]),16);
        bufp->chgSData(oldp+87,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                [1U][0U]),16);
        bufp->chgSData(oldp+88,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                [1U][1U]),16);
        bufp->chgSData(oldp+89,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                [1U][2U]),16);
        bufp->chgSData(oldp+90,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                [1U][3U]),16);
        bufp->chgSData(oldp+91,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                [2U][0U]),16);
        bufp->chgSData(oldp+92,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                [2U][1U]),16);
        bufp->chgSData(oldp+93,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                [2U][2U]),16);
        bufp->chgSData(oldp+94,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                [2U][3U]),16);
        bufp->chgSData(oldp+95,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                [3U][0U]),16);
        bufp->chgSData(oldp+96,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                [3U][1U]),16);
        bufp->chgSData(oldp+97,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                [3U][2U]),16);
        bufp->chgSData(oldp+98,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                [3U][3U]),16);
        bufp->chgSData(oldp+99,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                [0U][0U]),16);
        bufp->chgSData(oldp+100,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [0U][1U]),16);
        bufp->chgSData(oldp+101,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [0U][2U]),16);
        bufp->chgSData(oldp+102,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [0U][3U]),16);
        bufp->chgSData(oldp+103,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [1U][0U]),16);
        bufp->chgSData(oldp+104,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [1U][1U]),16);
        bufp->chgSData(oldp+105,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [1U][2U]),16);
        bufp->chgSData(oldp+106,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [1U][3U]),16);
        bufp->chgSData(oldp+107,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [2U][0U]),16);
        bufp->chgSData(oldp+108,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [2U][1U]),16);
        bufp->chgSData(oldp+109,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [2U][2U]),16);
        bufp->chgSData(oldp+110,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [2U][3U]),16);
        bufp->chgSData(oldp+111,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [3U][0U]),16);
        bufp->chgSData(oldp+112,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [3U][1U]),16);
        bufp->chgSData(oldp+113,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [3U][2U]),16);
        bufp->chgSData(oldp+114,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [3U][3U]),16);
        bufp->chgSData(oldp+115,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                                 [0U][0U]),16);
        bufp->chgSData(oldp+116,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                                 [0U][1U]),16);
        bufp->chgSData(oldp+117,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                                 [0U][2U]),16);
        bufp->chgSData(oldp+118,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                                 [0U][3U]),16);
        bufp->chgSData(oldp+119,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                                 [1U][0U]),16);
        bufp->chgSData(oldp+120,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                                 [1U][1U]),16);
        bufp->chgSData(oldp+121,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                                 [1U][2U]),16);
        bufp->chgSData(oldp+122,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                                 [1U][3U]),16);
        bufp->chgSData(oldp+123,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                                 [2U][0U]),16);
        bufp->chgSData(oldp+124,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                                 [2U][1U]),16);
        bufp->chgSData(oldp+125,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                                 [2U][2U]),16);
        bufp->chgSData(oldp+126,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                                 [2U][3U]),16);
        bufp->chgSData(oldp+127,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                                 [3U][0U]),16);
        bufp->chgSData(oldp+128,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                                 [3U][1U]),16);
        bufp->chgSData(oldp+129,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                                 [3U][2U]),16);
        bufp->chgSData(oldp+130,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__nxt_MAC_outputs
                                 [3U][3U]),16);
        bufp->chgSData(oldp+131,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__ps_add_inputs[0]),16);
        bufp->chgSData(oldp+132,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__ps_add_inputs[1]),16);
        bufp->chgSData(oldp+133,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__ps_add_inputs[2]),16);
        bufp->chgSData(oldp+134,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__ps_add_inputs[3]),16);
        bufp->chgQData(oldp+135,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights[0]),64);
        bufp->chgQData(oldp+137,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights[1]),64);
        bufp->chgQData(oldp+139,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights[2]),64);
        bufp->chgQData(oldp+141,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights[3]),64);
        bufp->chgIData(oldp+143,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__z),32);
        bufp->chgIData(oldp+144,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__y),32);
        bufp->chgCData(oldp+145,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__row_out),2);
        bufp->chgWData(oldp+146,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__current_out),256);
        bufp->chgCData(oldp+154,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_count),3);
        bufp->chgBit(oldp+155,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_start));
        bufp->chgCData(oldp+156,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_add_count),2);
        bufp->chgBit(oldp+157,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_add_start));
        bufp->chgCData(oldp+158,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration[0]),4);
        bufp->chgCData(oldp+159,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration[1]),4);
        bufp->chgCData(oldp+160,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration[2]),4);
        bufp->chgCData(oldp+161,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__iteration_full),3);
        bufp->chgCData(oldp+162,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__input_tracker),2);
        bufp->chgCData(oldp+163,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__data_loaded),2);
        bufp->chgBit(oldp+164,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__MAC_done));
        bufp->chgBit(oldp+165,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__nxt_MAC_done));
        bufp->chgIData(oldp+166,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__k),32);
        bufp->chgIData(oldp+167,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__q),32);
        bufp->chgWData(oldp+168,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem),128);
        bufp->chgWData(oldp+172,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem),128);
        bufp->chgWData(oldp+176,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem),128);
        bufp->chgWData(oldp+180,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem),128);
        bufp->chgWData(oldp+184,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem),144);
        bufp->chgWData(oldp+189,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem),144);
        bufp->chgWData(oldp+194,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem),144);
        bufp->chgWData(oldp+199,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem),144);
        bufp->chgQData(oldp+204,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__0__KET____DOT__o_fifo__DOT__fifo_mem),64);
        bufp->chgQData(oldp+206,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__0__KET____DOT__o_fifo__DOT__fifo_mem_next),64);
        bufp->chgQData(oldp+208,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__1__KET____DOT__o_fifo__DOT__fifo_mem),64);
        bufp->chgQData(oldp+210,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__1__KET____DOT__o_fifo__DOT__fifo_mem_next),64);
        bufp->chgQData(oldp+212,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__2__KET____DOT__o_fifo__DOT__fifo_mem),64);
        bufp->chgQData(oldp+214,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__2__KET____DOT__o_fifo__DOT__fifo_mem_next),64);
        bufp->chgQData(oldp+216,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__3__KET____DOT__o_fifo__DOT__fifo_mem),64);
        bufp->chgQData(oldp+218,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk6__BRA__3__KET____DOT__o_fifo__DOT__fifo_mem_next),64);
        bufp->chgBit(oldp+220,(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.out_en));
        bufp->chgBit(oldp+221,(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.drained));
        bufp->chgBit(oldp+222,(((1U == (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__input_tracker)) 
                                | (0U == (IData)(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__cu_inst__DOT__input_tracker)))));
        bufp->chgCData(oldp+223,(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.row_out),2);
        bufp->chgQData(oldp+224,(vlSymsp->TOP__systolic_array_tb__DOT__memory_if.array_output),64);
        bufp->chgBit(oldp+226,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.MAC_start));
        bufp->chgCData(oldp+227,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.MAC_count),3);
        bufp->chgBit(oldp+228,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.add_start));
        bufp->chgCData(oldp+229,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.add_count),2);
        bufp->chgBit(oldp+230,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.fifo_shift));
        bufp->chgBit(oldp+231,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.out_fifo_shift));
        bufp->chgCData(oldp+232,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.iteration[0]),4);
        bufp->chgCData(oldp+233,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.iteration[1]),4);
        bufp->chgCData(oldp+234,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__control_unit_if.iteration[2]),4);
        bufp->chgSData(oldp+235,((0xffffU & (IData)(
                                                    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                    [3U]))),16);
        bufp->chgSData(oldp+236,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                 [3U][3U]),16);
        bufp->chgSData(oldp+237,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [2U][3U]),16);
        bufp->chgSData(oldp+238,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__15__KET__.out_accumulate),16);
        bufp->chgSData(oldp+239,((0xffffU & (IData)(
                                                    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                    [2U]))),16);
        bufp->chgSData(oldp+240,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                 [3U][2U]),16);
        bufp->chgSData(oldp+241,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [2U][2U]),16);
        bufp->chgSData(oldp+242,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__14__KET__.out_accumulate),16);
        bufp->chgSData(oldp+243,((0xffffU & (IData)(
                                                    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                    [1U]))),16);
        bufp->chgSData(oldp+244,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                 [3U][1U]),16);
        bufp->chgSData(oldp+245,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [2U][1U]),16);
        bufp->chgSData(oldp+246,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__13__KET__.out_accumulate),16);
        bufp->chgSData(oldp+247,((0xffffU & (IData)(
                                                    vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                    [0U]))),16);
        bufp->chgSData(oldp+248,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                 [3U][0U]),16);
        bufp->chgSData(oldp+249,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [2U][0U]),16);
        bufp->chgSData(oldp+250,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__12__KET__.out_accumulate),16);
        bufp->chgSData(oldp+251,((0xffffU & (IData)(
                                                    (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                     [3U] 
                                                     >> 0x10U)))),16);
        bufp->chgSData(oldp+252,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                 [2U][3U]),16);
        bufp->chgSData(oldp+253,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [1U][3U]),16);
        bufp->chgSData(oldp+254,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__11__KET__.out_accumulate),16);
        bufp->chgSData(oldp+255,((0xffffU & (IData)(
                                                    (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                     [2U] 
                                                     >> 0x10U)))),16);
        bufp->chgSData(oldp+256,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                 [2U][2U]),16);
        bufp->chgSData(oldp+257,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [1U][2U]),16);
        bufp->chgSData(oldp+258,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__10__KET__.out_accumulate),16);
        bufp->chgSData(oldp+259,((0xffffU & (IData)(
                                                    (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                     [1U] 
                                                     >> 0x10U)))),16);
        bufp->chgSData(oldp+260,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                 [2U][1U]),16);
        bufp->chgSData(oldp+261,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [1U][1U]),16);
        bufp->chgSData(oldp+262,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__9__KET__.out_accumulate),16);
        bufp->chgSData(oldp+263,((0xffffU & (IData)(
                                                    (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                     [0U] 
                                                     >> 0x10U)))),16);
        bufp->chgSData(oldp+264,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                 [2U][0U]),16);
        bufp->chgSData(oldp+265,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [1U][0U]),16);
        bufp->chgSData(oldp+266,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__8__KET__.out_accumulate),16);
        bufp->chgSData(oldp+267,((0xffffU & (IData)(
                                                    (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                     [3U] 
                                                     >> 0x20U)))),16);
        bufp->chgSData(oldp+268,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                 [1U][3U]),16);
        bufp->chgSData(oldp+269,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [0U][3U]),16);
        bufp->chgSData(oldp+270,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__7__KET__.out_accumulate),16);
        bufp->chgSData(oldp+271,((0xffffU & (IData)(
                                                    (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                     [2U] 
                                                     >> 0x20U)))),16);
        bufp->chgSData(oldp+272,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                 [1U][2U]),16);
        bufp->chgSData(oldp+273,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [0U][2U]),16);
        bufp->chgSData(oldp+274,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__6__KET__.out_accumulate),16);
        bufp->chgSData(oldp+275,((0xffffU & (IData)(
                                                    (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                     [1U] 
                                                     >> 0x20U)))),16);
        bufp->chgSData(oldp+276,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                 [1U][1U]),16);
        bufp->chgSData(oldp+277,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [0U][1U]),16);
        bufp->chgSData(oldp+278,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__5__KET__.out_accumulate),16);
        bufp->chgSData(oldp+279,((0xffffU & (IData)(
                                                    (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                     [0U] 
                                                     >> 0x20U)))),16);
        bufp->chgSData(oldp+280,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                 [1U][0U]),16);
        bufp->chgSData(oldp+281,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [0U][0U]),16);
        bufp->chgSData(oldp+282,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__4__KET__.out_accumulate),16);
        bufp->chgSData(oldp+283,((0xffffU & (IData)(
                                                    (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                     [3U] 
                                                     >> 0x30U)))),16);
        bufp->chgSData(oldp+284,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                 [0U][3U]),16);
        bufp->chgSData(oldp+285,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__3__KET__.out_accumulate),16);
        bufp->chgSData(oldp+286,((0xffffU & (IData)(
                                                    (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                     [2U] 
                                                     >> 0x30U)))),16);
        bufp->chgSData(oldp+287,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                 [0U][2U]),16);
        bufp->chgSData(oldp+288,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__2__KET__.out_accumulate),16);
        bufp->chgSData(oldp+289,((0xffffU & (IData)(
                                                    (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                     [1U] 
                                                     >> 0x30U)))),16);
        bufp->chgSData(oldp+290,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                 [0U][1U]),16);
        bufp->chgSData(oldp+291,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__1__KET__.out_accumulate),16);
        bufp->chgSData(oldp+292,((0xffffU & (IData)(
                                                    (vlSelfRef.systolic_array_tb__DOT__DUT__DOT__weights
                                                     [0U] 
                                                     >> 0x30U)))),16);
        bufp->chgSData(oldp+293,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_inputs
                                 [0U][0U]),16);
        bufp->chgSData(oldp+294,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__0__KET__.out_accumulate),16);
        bufp->chgSData(oldp+295,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__ps_add_inputs
                                 [3U]),16);
        bufp->chgSData(oldp+296,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [3U][3U]),16);
        bufp->chgSData(oldp+297,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__3__KET__.add_ouput),16);
        bufp->chgSData(oldp+298,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__ps_add_inputs
                                 [2U]),16);
        bufp->chgSData(oldp+299,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [3U][2U]),16);
        bufp->chgSData(oldp+300,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__2__KET__.add_ouput),16);
        bufp->chgSData(oldp+301,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__ps_add_inputs
                                 [1U]),16);
        bufp->chgSData(oldp+302,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [3U][1U]),16);
        bufp->chgSData(oldp+303,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__1__KET__.add_ouput),16);
        bufp->chgSData(oldp+304,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__ps_add_inputs
                                 [0U]),16);
        bufp->chgSData(oldp+305,(vlSelfRef.systolic_array_tb__DOT__DUT__DOT__MAC_outputs
                                 [3U][0U]),16);
        bufp->chgSData(oldp+306,(vlSymsp->TOP__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__0__KET__.add_ouput),16);
        bufp->chgQData(oldp+307,((((QData)((IData)(
                                                   vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem[1U])) 
                                   << 0x20U) | (QData)((IData)(
                                                               vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__3__KET____DOT__i_fifo__DOT__fifo_mem[0U])))),64);
        bufp->chgQData(oldp+309,((((QData)((IData)(
                                                   vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem[1U])) 
                                   << 0x20U) | (QData)((IData)(
                                                               vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__2__KET____DOT__i_fifo__DOT__fifo_mem[0U])))),64);
        bufp->chgQData(oldp+311,((((QData)((IData)(
                                                   vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem[1U])) 
                                   << 0x20U) | (QData)((IData)(
                                                               vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__1__KET____DOT__i_fifo__DOT__fifo_mem[0U])))),64);
        bufp->chgQData(oldp+313,((((QData)((IData)(
                                                   vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem[1U])) 
                                   << 0x20U) | (QData)((IData)(
                                                               vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk2__BRA__0__KET____DOT__i_fifo__DOT__fifo_mem[0U])))),64);
        bufp->chgSData(oldp+315,((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__3__KET____DOT__ps_fifos__DOT__ps_fifo_mem[0U])),16);
        bufp->chgSData(oldp+316,((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__2__KET____DOT__ps_fifos__DOT__ps_fifo_mem[0U])),16);
        bufp->chgSData(oldp+317,((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__1__KET____DOT__ps_fifos__DOT__ps_fifo_mem[0U])),16);
        bufp->chgSData(oldp+318,((0xffffU & vlSelfRef.systolic_array_tb__DOT__DUT__DOT__genblk3__BRA__0__KET____DOT__ps_fifos__DOT__ps_fifo_mem[0U])),16);
    }
    bufp->chgBit(oldp+319,(vlSelfRef.systolic_array_tb__DOT__tb_clk));
}

void Vsystolic_array_tb___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic_array_tb___024root__trace_cleanup\n"); );
    // Init
    Vsystolic_array_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsystolic_array_tb___024root*>(voidSelf);
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
}
