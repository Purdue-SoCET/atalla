// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vaddn_8_fp32accum_fp16_tb_softfloat__Syms.h"


void Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_chg_0_sub_0(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_chg_0\n"); );
    // Init
    Vaddn_8_fp32accum_fp16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaddn_8_fp32accum_fp16_tb_softfloat___024root*>(voidSelf);
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_chg_0_sub_0(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_chg_0_sub_0\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst));
        bufp->chgWData(oldp+1,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data),128);
        bufp->chgSData(oldp+5,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__exp),16);
        bufp->chgIData(oldp+6,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__pass_count),32);
        bufp->chgIData(oldp+7,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_count),32);
        bufp->chgIData(oldp+8,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__ulp_diff),32);
        bufp->chgIData(oldp+9,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__ulp_big_count),32);
        bufp->chgDouble(oldp+10,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__total_ulp_diff));
        bufp->chgQData(oldp+12,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a),64);
        bufp->chgQData(oldp+14,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b),64);
        bufp->chgIData(oldp+16,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fd),32);
        bufp->chgIData(oldp+17,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_fd),32);
        bufp->chgSData(oldp+18,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__a),16);
        bufp->chgSData(oldp+19,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__b),16);
        bufp->chgSData(oldp+20,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__c),16);
        bufp->chgSData(oldp+21,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__d),16);
        bufp->chgSData(oldp+22,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__e),16);
        bufp->chgSData(oldp+23,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__f),16);
        bufp->chgSData(oldp+24,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__g),16);
        bufp->chgSData(oldp+25,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__h),16);
        bufp->chgSData(oldp+26,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__expected),16);
        bufp->chgIData(oldp+27,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__total_count),32);
        bufp->chgIData(oldp+28,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+29,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__unnamedblk2__DOT__ret),32);
        bufp->chgBit(oldp+30,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__unnamedblk2__DOT__is_zero_result));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [6U])))) {
        bufp->chgSData(oldp+31,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[0]),16);
        bufp->chgSData(oldp+32,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[1]),16);
        bufp->chgSData(oldp+33,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[2]),16);
        bufp->chgSData(oldp+34,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[3]),16);
        bufp->chgSData(oldp+35,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[4]),16);
        bufp->chgSData(oldp+36,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[5]),16);
        bufp->chgSData(oldp+37,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[6]),16);
        bufp->chgSData(oldp+38,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[7]),16);
        bufp->chgCData(oldp+39,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[0]),5);
        bufp->chgCData(oldp+40,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[1]),5);
        bufp->chgCData(oldp+41,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[2]),5);
        bufp->chgCData(oldp+42,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[3]),5);
        bufp->chgCData(oldp+43,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[4]),5);
        bufp->chgCData(oldp+44,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[5]),5);
        bufp->chgCData(oldp+45,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[6]),5);
        bufp->chgCData(oldp+46,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[7]),5);
        bufp->chgSData(oldp+47,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[0]),10);
        bufp->chgSData(oldp+48,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[1]),10);
        bufp->chgSData(oldp+49,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[2]),10);
        bufp->chgSData(oldp+50,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[3]),10);
        bufp->chgSData(oldp+51,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[4]),10);
        bufp->chgSData(oldp+52,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[5]),10);
        bufp->chgSData(oldp+53,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[6]),10);
        bufp->chgSData(oldp+54,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[7]),10);
        bufp->chgBit(oldp+55,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[0]));
        bufp->chgBit(oldp+56,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[1]));
        bufp->chgBit(oldp+57,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[2]));
        bufp->chgBit(oldp+58,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[3]));
        bufp->chgBit(oldp+59,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[4]));
        bufp->chgBit(oldp+60,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[5]));
        bufp->chgBit(oldp+61,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[6]));
        bufp->chgBit(oldp+62,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[7]));
        bufp->chgCData(oldp+63,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [0U][0U]),5);
        bufp->chgCData(oldp+64,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [0U][1U]),5);
        bufp->chgCData(oldp+65,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [0U][2U]),5);
        bufp->chgCData(oldp+66,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [0U][3U]),5);
        bufp->chgCData(oldp+67,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [0U][4U]),5);
        bufp->chgCData(oldp+68,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [0U][5U]),5);
        bufp->chgCData(oldp+69,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [0U][6U]),5);
        bufp->chgCData(oldp+70,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [0U][7U]),5);
        bufp->chgCData(oldp+71,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [1U][0U]),5);
        bufp->chgCData(oldp+72,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [1U][1U]),5);
        bufp->chgCData(oldp+73,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [1U][2U]),5);
        bufp->chgCData(oldp+74,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [1U][3U]),5);
        bufp->chgCData(oldp+75,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [1U][4U]),5);
        bufp->chgCData(oldp+76,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [1U][5U]),5);
        bufp->chgCData(oldp+77,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [1U][6U]),5);
        bufp->chgCData(oldp+78,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [1U][7U]),5);
        bufp->chgCData(oldp+79,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [2U][0U]),5);
        bufp->chgCData(oldp+80,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [2U][1U]),5);
        bufp->chgCData(oldp+81,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [2U][2U]),5);
        bufp->chgCData(oldp+82,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [2U][3U]),5);
        bufp->chgCData(oldp+83,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [2U][4U]),5);
        bufp->chgCData(oldp+84,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [2U][5U]),5);
        bufp->chgCData(oldp+85,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [2U][6U]),5);
        bufp->chgCData(oldp+86,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [2U][7U]),5);
        bufp->chgCData(oldp+87,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [3U][0U]),5);
        bufp->chgCData(oldp+88,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [3U][1U]),5);
        bufp->chgCData(oldp+89,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [3U][2U]),5);
        bufp->chgCData(oldp+90,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [3U][3U]),5);
        bufp->chgCData(oldp+91,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [3U][4U]),5);
        bufp->chgCData(oldp+92,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [3U][5U]),5);
        bufp->chgCData(oldp+93,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [3U][6U]),5);
        bufp->chgCData(oldp+94,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [3U][7U]),5);
        bufp->chgCData(oldp+95,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                [0U][0U]),3);
        bufp->chgCData(oldp+96,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                [0U][1U]),3);
        bufp->chgCData(oldp+97,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                [0U][2U]),3);
        bufp->chgCData(oldp+98,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                [0U][3U]),3);
        bufp->chgCData(oldp+99,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                [0U][4U]),3);
        bufp->chgCData(oldp+100,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [0U][5U]),3);
        bufp->chgCData(oldp+101,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [0U][6U]),3);
        bufp->chgCData(oldp+102,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [0U][7U]),3);
        bufp->chgCData(oldp+103,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [1U][0U]),3);
        bufp->chgCData(oldp+104,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [1U][1U]),3);
        bufp->chgCData(oldp+105,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [1U][2U]),3);
        bufp->chgCData(oldp+106,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [1U][3U]),3);
        bufp->chgCData(oldp+107,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [1U][4U]),3);
        bufp->chgCData(oldp+108,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [1U][5U]),3);
        bufp->chgCData(oldp+109,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [1U][6U]),3);
        bufp->chgCData(oldp+110,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [1U][7U]),3);
        bufp->chgCData(oldp+111,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [2U][0U]),3);
        bufp->chgCData(oldp+112,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [2U][1U]),3);
        bufp->chgCData(oldp+113,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [2U][2U]),3);
        bufp->chgCData(oldp+114,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [2U][3U]),3);
        bufp->chgCData(oldp+115,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [2U][4U]),3);
        bufp->chgCData(oldp+116,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [2U][5U]),3);
        bufp->chgCData(oldp+117,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [2U][6U]),3);
        bufp->chgCData(oldp+118,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [2U][7U]),3);
        bufp->chgCData(oldp+119,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [3U][0U]),3);
        bufp->chgCData(oldp+120,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [3U][1U]),3);
        bufp->chgCData(oldp+121,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [3U][2U]),3);
        bufp->chgCData(oldp+122,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [3U][3U]),3);
        bufp->chgCData(oldp+123,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [3U][4U]),3);
        bufp->chgCData(oldp+124,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [3U][5U]),3);
        bufp->chgCData(oldp+125,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [3U][6U]),3);
        bufp->chgCData(oldp+126,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                 [3U][7U]),3);
        bufp->chgCData(oldp+127,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp),5);
        bufp->chgCData(oldp+128,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp_eff),5);
        bufp->chgCData(oldp+129,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx),3);
        bufp->chgBit(oldp+130,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_max));
        bufp->chgCData(oldp+131,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[0]),6);
        bufp->chgCData(oldp+132,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[1]),6);
        bufp->chgCData(oldp+133,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[2]),6);
        bufp->chgCData(oldp+134,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[3]),6);
        bufp->chgCData(oldp+135,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[4]),6);
        bufp->chgCData(oldp+136,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[5]),6);
        bufp->chgCData(oldp+137,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[6]),6);
        bufp->chgCData(oldp+138,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[7]),6);
        bufp->chgIData(oldp+139,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[0]),25);
        bufp->chgIData(oldp+140,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[1]),25);
        bufp->chgIData(oldp+141,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[2]),25);
        bufp->chgIData(oldp+142,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[3]),25);
        bufp->chgIData(oldp+143,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[4]),25);
        bufp->chgIData(oldp+144,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[5]),25);
        bufp->chgIData(oldp+145,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[6]),25);
        bufp->chgIData(oldp+146,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[7]),25);
        bufp->chgIData(oldp+147,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[0]),25);
        bufp->chgIData(oldp+148,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[1]),25);
        bufp->chgIData(oldp+149,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[2]),25);
        bufp->chgIData(oldp+150,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[3]),25);
        bufp->chgIData(oldp+151,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[4]),25);
        bufp->chgIData(oldp+152,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[5]),25);
        bufp->chgIData(oldp+153,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[6]),25);
        bufp->chgIData(oldp+154,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[7]),25);
        bufp->chgBit(oldp+155,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[0]));
        bufp->chgBit(oldp+156,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[1]));
        bufp->chgBit(oldp+157,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[2]));
        bufp->chgBit(oldp+158,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[3]));
        bufp->chgBit(oldp+159,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[4]));
        bufp->chgBit(oldp+160,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[5]));
        bufp->chgBit(oldp+161,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[6]));
        bufp->chgBit(oldp+162,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[7]));
        bufp->chgBit(oldp+163,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[0]));
        bufp->chgBit(oldp+164,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[1]));
        bufp->chgBit(oldp+165,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[2]));
        bufp->chgBit(oldp+166,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[3]));
        bufp->chgBit(oldp+167,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[4]));
        bufp->chgBit(oldp+168,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[5]));
        bufp->chgBit(oldp+169,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[6]));
        bufp->chgBit(oldp+170,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[7]));
        bufp->chgIData(oldp+171,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[0]),28);
        bufp->chgIData(oldp+172,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[1]),28);
        bufp->chgIData(oldp+173,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[2]),28);
        bufp->chgIData(oldp+174,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[3]),28);
        bufp->chgIData(oldp+175,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[4]),28);
        bufp->chgIData(oldp+176,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[5]),28);
        bufp->chgIData(oldp+177,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[6]),28);
        bufp->chgIData(oldp+178,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[7]),28);
        bufp->chgBit(oldp+179,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__is_nan_any));
        bufp->chgBit(oldp+180,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_pos_inf));
        bufp->chgBit(oldp+181,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_neg_inf));
        bufp->chgBit(oldp+182,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_case));
        bufp->chgIData(oldp+183,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_result),32);
        bufp->chgIData(oldp+184,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[0]),28);
        bufp->chgIData(oldp+185,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[1]),28);
        bufp->chgIData(oldp+186,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[2]),28);
        bufp->chgIData(oldp+187,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[3]),28);
        bufp->chgIData(oldp+188,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[4]),28);
        bufp->chgIData(oldp+189,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[5]),28);
        bufp->chgIData(oldp+190,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[6]),28);
        bufp->chgIData(oldp+191,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[7]),28);
        bufp->chgIData(oldp+192,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[0]),28);
        bufp->chgIData(oldp+193,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[1]),28);
        bufp->chgIData(oldp+194,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[2]),28);
        bufp->chgIData(oldp+195,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[3]),28);
        bufp->chgIData(oldp+196,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[4]),28);
        bufp->chgIData(oldp+197,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[5]),28);
        bufp->chgIData(oldp+198,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[6]),28);
        bufp->chgIData(oldp+199,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[7]),28);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgCData(oldp+200,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_a_e),5);
        bufp->chgBit(oldp+201,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_a_s));
        bufp->chgBit(oldp+202,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_align_sticky));
        bufp->chgBit(oldp+203,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_special_case));
        bufp->chgIData(oldp+204,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_special_result),32);
        bufp->chgIData(oldp+205,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_sum_vec),28);
        bufp->chgIData(oldp+206,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_carry_vec),28);
        bufp->chgCData(oldp+207,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_hot_ones),4);
        bufp->chgIData(oldp+208,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__raw_sum),29);
        bufp->chgIData(oldp+209,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mag_sum),27);
        bufp->chgBit(oldp+210,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__res_sign));
        bufp->chgCData(oldp+211,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_exp_base),5);
        bufp->chgIData(oldp+212,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sum_mag),27);
        bufp->chgIData(oldp+213,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_spec_res),32);
        bufp->chgBit(oldp+214,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_res_sign));
        bufp->chgBit(oldp+215,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sticky));
        bufp->chgBit(oldp+216,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_special));
        bufp->chgIData(oldp+217,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__stage3_logic__DOT__unnamedblk9__DOT__i),32);
        bufp->chgIData(oldp+218,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__unnamedblk7__DOT__i),32);
        bufp->chgIData(oldp+219,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__unnamedblk8__DOT__i),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[5U]))) {
        bufp->chgIData(oldp+220,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs
                                 [3U]),32);
        bufp->chgSData(oldp+221,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result),16);
        bufp->chgIData(oldp+222,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs[0]),32);
        bufp->chgIData(oldp+223,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs[1]),32);
        bufp->chgIData(oldp+224,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs[2]),32);
        bufp->chgIData(oldp+225,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs[3]),32);
        bufp->chgIData(oldp+226,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__unnamedblk10__DOT__i),32);
        bufp->chgBit(oldp+227,((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs
                                [3U] >> 0x1fU)));
        bufp->chgCData(oldp+228,((0xffU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs
                                           [3U] >> 0x17U))),8);
        bufp->chgIData(oldp+229,((0x7fffffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs
                                  [3U])),23);
        bufp->chgSData(oldp+230,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp),10);
        bufp->chgSData(oldp+231,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded),11);
        bufp->chgBit(oldp+232,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__guard));
        bufp->chgBit(oldp+233,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rnd));
        bufp->chgBit(oldp+234,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__sticky));
        bufp->chgBit(oldp+235,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__round_up));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[7U]))) {
        bufp->chgIData(oldp+236,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan),27);
        bufp->chgCData(oldp+237,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros),6);
        bufp->chgIData(oldp+238,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__norm_val),27);
        bufp->chgIData(oldp+239,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__final_mant),23);
        bufp->chgSData(oldp+240,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__final_exp_calc),11);
        bufp->chgIData(oldp+241,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__result_out),32);
    }
    bufp->chgBit(oldp+242,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_clk));
}

void Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_cleanup\n"); );
    // Init
    Vaddn_8_fp32accum_fp16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaddn_8_fp32accum_fp16_tb_softfloat___024root*>(voidSelf);
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[7U] = 0U;
}
