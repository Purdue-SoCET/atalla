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
                      [5U])))) {
        bufp->chgSData(oldp+31,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data[0]),16);
        bufp->chgSData(oldp+32,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data[1]),16);
        bufp->chgSData(oldp+33,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data[2]),16);
        bufp->chgSData(oldp+34,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data[3]),16);
        bufp->chgSData(oldp+35,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data[4]),16);
        bufp->chgSData(oldp+36,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data[5]),16);
        bufp->chgSData(oldp+37,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data[6]),16);
        bufp->chgSData(oldp+38,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_data[7]),16);
        bufp->chgCData(oldp+39,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr[0]),5);
        bufp->chgCData(oldp+40,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr[1]),5);
        bufp->chgCData(oldp+41,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr[2]),5);
        bufp->chgCData(oldp+42,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr[3]),5);
        bufp->chgCData(oldp+43,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr[4]),5);
        bufp->chgCData(oldp+44,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr[5]),5);
        bufp->chgCData(oldp+45,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr[6]),5);
        bufp->chgCData(oldp+46,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp_arr[7]),5);
        bufp->chgCData(oldp+47,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__idx_arr[0]),3);
        bufp->chgCData(oldp+48,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__idx_arr[1]),3);
        bufp->chgCData(oldp+49,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__idx_arr[2]),3);
        bufp->chgCData(oldp+50,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__idx_arr[3]),3);
        bufp->chgCData(oldp+51,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__idx_arr[4]),3);
        bufp->chgCData(oldp+52,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__idx_arr[5]),3);
        bufp->chgCData(oldp+53,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__idx_arr[6]),3);
        bufp->chgCData(oldp+54,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__idx_arr[7]),3);
        bufp->chgBit(oldp+55,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_is_nan_any));
        bufp->chgBit(oldp+56,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_pos_inf));
        bufp->chgBit(oldp+57,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_any_neg_inf));
        bufp->chgBit(oldp+58,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_spec_case));
        bufp->chgIData(oldp+59,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_spec_res),32);
        bufp->chgCData(oldp+60,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e1[0]),5);
        bufp->chgCData(oldp+61,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e1[1]),5);
        bufp->chgCData(oldp+62,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e1[2]),5);
        bufp->chgCData(oldp+63,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e1[3]),5);
        bufp->chgCData(oldp+64,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e2[0]),5);
        bufp->chgCData(oldp+65,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__e2[1]),5);
        bufp->chgCData(oldp+66,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_max_exp),5);
        bufp->chgCData(oldp+67,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i1[0]),3);
        bufp->chgCData(oldp+68,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i1[1]),3);
        bufp->chgCData(oldp+69,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i1[2]),3);
        bufp->chgCData(oldp+70,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i1[3]),3);
        bufp->chgCData(oldp+71,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i2[0]),3);
        bufp->chgCData(oldp+72,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__i2[1]),3);
        bufp->chgCData(oldp+73,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_max_idx),3);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgIData(oldp+74,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out),32);
        bufp->chgSData(oldp+75,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result),16);
        bufp->chgCData(oldp+76,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_exp),5);
        bufp->chgCData(oldp+77,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_max_idx),3);
        bufp->chgSData(oldp+78,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data[0]),16);
        bufp->chgSData(oldp+79,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data[1]),16);
        bufp->chgSData(oldp+80,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data[2]),16);
        bufp->chgSData(oldp+81,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data[3]),16);
        bufp->chgSData(oldp+82,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data[4]),16);
        bufp->chgSData(oldp+83,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data[5]),16);
        bufp->chgSData(oldp+84,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data[6]),16);
        bufp->chgSData(oldp+85,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_data[7]),16);
        bufp->chgBit(oldp+86,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_spec_case));
        bufp->chgIData(oldp+87,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_spec_res),32);
        bufp->chgIData(oldp+88,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[0]),30);
        bufp->chgIData(oldp+89,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[1]),30);
        bufp->chgIData(oldp+90,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[2]),30);
        bufp->chgIData(oldp+91,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[3]),30);
        bufp->chgIData(oldp+92,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[4]),30);
        bufp->chgIData(oldp+93,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[5]),30);
        bufp->chgIData(oldp+94,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[6]),30);
        bufp->chgIData(oldp+95,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[7]),30);
        bufp->chgCData(oldp+96,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh[0]),6);
        bufp->chgCData(oldp+97,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh[1]),6);
        bufp->chgCData(oldp+98,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh[2]),6);
        bufp->chgCData(oldp+99,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh[3]),6);
        bufp->chgCData(oldp+100,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh[4]),6);
        bufp->chgCData(oldp+101,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh[5]),6);
        bufp->chgCData(oldp+102,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh[6]),6);
        bufp->chgCData(oldp+103,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sh[7]),6);
        bufp->chgIData(oldp+104,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base[0]),25);
        bufp->chgIData(oldp+105,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base[1]),25);
        bufp->chgIData(oldp+106,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base[2]),25);
        bufp->chgIData(oldp+107,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base[3]),25);
        bufp->chgIData(oldp+108,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base[4]),25);
        bufp->chgIData(oldp+109,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base[5]),25);
        bufp->chgIData(oldp+110,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base[6]),25);
        bufp->chgIData(oldp+111,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__m_base[7]),25);
        bufp->chgBit(oldp+112,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff[0]));
        bufp->chgBit(oldp+113,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff[1]));
        bufp->chgBit(oldp+114,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff[2]));
        bufp->chgBit(oldp+115,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff[3]));
        bufp->chgBit(oldp+116,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff[4]));
        bufp->chgBit(oldp+117,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff[5]));
        bufp->chgBit(oldp+118,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff[6]));
        bufp->chgBit(oldp+119,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_diff[7]));
        bufp->chgBit(oldp+120,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_sticky));
        bufp->chgCData(oldp+121,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_hot_ones),4);
        bufp->chgIData(oldp+122,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s1_0),30);
        bufp->chgIData(oldp+123,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c1_0),30);
        bufp->chgIData(oldp+124,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s1_1),30);
        bufp->chgIData(oldp+125,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c1_1),30);
        bufp->chgIData(oldp+126,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s2_0),30);
        bufp->chgIData(oldp+127,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c2_0),30);
        bufp->chgIData(oldp+128,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s2_1),30);
        bufp->chgIData(oldp+129,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c2_1),30);
        bufp->chgIData(oldp+130,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s3_0),30);
        bufp->chgIData(oldp+131,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c3_0),30);
        bufp->chgIData(oldp+132,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__s4_0),30);
        bufp->chgIData(oldp+133,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c4_0),30);
        bufp->chgIData(oldp+134,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sum_vec),30);
        bufp->chgIData(oldp+135,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_carry_vec),30);
        bufp->chgCData(oldp+136,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_exp),5);
        bufp->chgBit(oldp+137,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sign_max));
        bufp->chgBit(oldp+138,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sticky));
        bufp->chgCData(oldp+139,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_hot_ones),4);
        bufp->chgBit(oldp+140,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_spec_case));
        bufp->chgIData(oldp+141,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_spec_res),32);
        bufp->chgIData(oldp+142,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_raw_sum),31);
        bufp->chgIData(oldp+143,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_mag_sum),29);
        bufp->chgBit(oldp+144,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_res_sign));
        bufp->chgIData(oldp+145,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_mag_sum),29);
        bufp->chgBit(oldp+146,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_res_sign));
        bufp->chgBit(oldp+147,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_sticky));
        bufp->chgCData(oldp+148,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_exp),5);
        bufp->chgBit(oldp+149,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_spec_case));
        bufp->chgIData(oldp+150,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st3_spec_res),32);
        bufp->chgIData(oldp+151,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_scan),29);
        bufp->chgCData(oldp+152,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_lzd),6);
        bufp->chgCData(oldp+153,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_lzd),6);
        bufp->chgIData(oldp+154,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_mag),29);
        bufp->chgBit(oldp+155,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_sign));
        bufp->chgBit(oldp+156,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_sticky));
        bufp->chgCData(oldp+157,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_exp),5);
        bufp->chgBit(oldp+158,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_spec_case));
        bufp->chgIData(oldp+159,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_spec_res),32);
        bufp->chgIData(oldp+160,((0x1fffffffU & VL_SHIFTL_III(29,29,6, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_mag, (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st4_lzd)))),29);
        bufp->chgSData(oldp+161,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__c_e_final),11);
        bufp->chgIData(oldp+162,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__unnamedblk4__DOT__i),32);
        bufp->chgIData(oldp+163,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__unnamedblk5__DOT__i),32);
        bufp->chgBit(oldp+164,((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
                                >> 0x1fU)));
        bufp->chgCData(oldp+165,((0xffU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+166,((0x7fffffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out)),23);
        bufp->chgSData(oldp+167,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp),10);
        bufp->chgSData(oldp+168,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded),11);
        bufp->chgBit(oldp+169,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__guard));
        bufp->chgBit(oldp+170,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rnd));
        bufp->chgBit(oldp+171,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__sticky));
        bufp->chgBit(oldp+172,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__round_up));
    }
    bufp->chgBit(oldp+173,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_clk));
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
}
