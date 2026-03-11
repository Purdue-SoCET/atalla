// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vaddn_fp32accum_fp16_tb_softfloat__Syms.h"


void Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_chg_0_sub_0(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_chg_0\n"); );
    // Init
    Vaddn_fp32accum_fp16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaddn_fp32accum_fp16_tb_softfloat___024root*>(voidSelf);
    Vaddn_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_chg_0_sub_0(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_chg_0_sub_0\n"); );
    Vaddn_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_nrst));
        bufp->chgQData(oldp+1,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data),64);
        bufp->chgSData(oldp+3,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__exp),16);
        bufp->chgIData(oldp+4,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count),32);
        bufp->chgIData(oldp+5,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count),32);
        bufp->chgIData(oldp+6,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__ulp_diff),32);
        bufp->chgIData(oldp+7,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__ulp_big_count),32);
        bufp->chgDouble(oldp+8,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__total_ulp_diff));
        bufp->chgQData(oldp+10,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a),64);
        bufp->chgQData(oldp+12,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b),64);
        bufp->chgIData(oldp+14,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fd),32);
        bufp->chgIData(oldp+15,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_fd),32);
        bufp->chgSData(oldp+16,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__a),16);
        bufp->chgSData(oldp+17,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__b),16);
        bufp->chgSData(oldp+18,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__c),16);
        bufp->chgSData(oldp+19,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__d),16);
        bufp->chgSData(oldp+20,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__expected),16);
        bufp->chgIData(oldp+21,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__total_count),32);
        bufp->chgIData(oldp+22,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+23,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__unnamedblk2__DOT__ret),32);
        bufp->chgBit(oldp+24,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__unnamedblk2__DOT__is_zero_result));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [5U])))) {
        bufp->chgSData(oldp+25,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[0]),16);
        bufp->chgSData(oldp+26,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[1]),16);
        bufp->chgSData(oldp+27,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[2]),16);
        bufp->chgSData(oldp+28,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[3]),16);
        bufp->chgCData(oldp+29,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[0]),5);
        bufp->chgCData(oldp+30,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[1]),5);
        bufp->chgCData(oldp+31,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[2]),5);
        bufp->chgCData(oldp+32,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[3]),5);
        bufp->chgSData(oldp+33,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[0]),10);
        bufp->chgSData(oldp+34,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[1]),10);
        bufp->chgSData(oldp+35,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[2]),10);
        bufp->chgSData(oldp+36,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[3]),10);
        bufp->chgBit(oldp+37,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[0]));
        bufp->chgBit(oldp+38,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[1]));
        bufp->chgBit(oldp+39,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[2]));
        bufp->chgBit(oldp+40,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[3]));
        bufp->chgCData(oldp+41,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [0U][0U]),5);
        bufp->chgCData(oldp+42,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [0U][1U]),5);
        bufp->chgCData(oldp+43,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [0U][2U]),5);
        bufp->chgCData(oldp+44,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [0U][3U]),5);
        bufp->chgCData(oldp+45,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [1U][0U]),5);
        bufp->chgCData(oldp+46,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [1U][1U]),5);
        bufp->chgCData(oldp+47,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [1U][2U]),5);
        bufp->chgCData(oldp+48,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [1U][3U]),5);
        bufp->chgCData(oldp+49,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [2U][0U]),5);
        bufp->chgCData(oldp+50,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [2U][1U]),5);
        bufp->chgCData(oldp+51,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [2U][2U]),5);
        bufp->chgCData(oldp+52,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                                [2U][3U]),5);
        bufp->chgCData(oldp+53,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                [0U][0U]),2);
        bufp->chgCData(oldp+54,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                [0U][1U]),2);
        bufp->chgCData(oldp+55,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                [0U][2U]),2);
        bufp->chgCData(oldp+56,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                [0U][3U]),2);
        bufp->chgCData(oldp+57,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                [1U][0U]),2);
        bufp->chgCData(oldp+58,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                [1U][1U]),2);
        bufp->chgCData(oldp+59,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                [1U][2U]),2);
        bufp->chgCData(oldp+60,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                [1U][3U]),2);
        bufp->chgCData(oldp+61,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                [2U][0U]),2);
        bufp->chgCData(oldp+62,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                [2U][1U]),2);
        bufp->chgCData(oldp+63,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                [2U][2U]),2);
        bufp->chgCData(oldp+64,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                                [2U][3U]),2);
        bufp->chgCData(oldp+65,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp),5);
        bufp->chgCData(oldp+66,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp_eff),5);
        bufp->chgCData(oldp+67,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx),2);
        bufp->chgBit(oldp+68,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_max));
        bufp->chgCData(oldp+69,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[0]),6);
        bufp->chgCData(oldp+70,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[1]),6);
        bufp->chgCData(oldp+71,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[2]),6);
        bufp->chgCData(oldp+72,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[3]),6);
        bufp->chgIData(oldp+73,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[0]),25);
        bufp->chgIData(oldp+74,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[1]),25);
        bufp->chgIData(oldp+75,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[2]),25);
        bufp->chgIData(oldp+76,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[3]),25);
        bufp->chgIData(oldp+77,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[0]),25);
        bufp->chgIData(oldp+78,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[1]),25);
        bufp->chgIData(oldp+79,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[2]),25);
        bufp->chgIData(oldp+80,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[3]),25);
        bufp->chgBit(oldp+81,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[0]));
        bufp->chgBit(oldp+82,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[1]));
        bufp->chgBit(oldp+83,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[2]));
        bufp->chgBit(oldp+84,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[3]));
        bufp->chgBit(oldp+85,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[0]));
        bufp->chgBit(oldp+86,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[1]));
        bufp->chgBit(oldp+87,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[2]));
        bufp->chgBit(oldp+88,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[3]));
        bufp->chgIData(oldp+89,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[0]),28);
        bufp->chgIData(oldp+90,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[1]),28);
        bufp->chgIData(oldp+91,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[2]),28);
        bufp->chgIData(oldp+92,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[3]),28);
        bufp->chgBit(oldp+93,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__is_nan_any));
        bufp->chgBit(oldp+94,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_pos_inf));
        bufp->chgBit(oldp+95,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_neg_inf));
        bufp->chgBit(oldp+96,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_case));
        bufp->chgIData(oldp+97,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_result),32);
        bufp->chgIData(oldp+98,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[0]),28);
        bufp->chgIData(oldp+99,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[1]),28);
        bufp->chgIData(oldp+100,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[2]),28);
        bufp->chgIData(oldp+101,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[3]),28);
        bufp->chgIData(oldp+102,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[0]),28);
        bufp->chgIData(oldp+103,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[1]),28);
        bufp->chgIData(oldp+104,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[2]),28);
        bufp->chgIData(oldp+105,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[3]),28);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgIData(oldp+106,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out),32);
        bufp->chgSData(oldp+107,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result),16);
        bufp->chgCData(oldp+108,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_a_e),5);
        bufp->chgBit(oldp+109,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_a_s));
        bufp->chgBit(oldp+110,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_align_sticky));
        bufp->chgBit(oldp+111,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_special_case));
        bufp->chgIData(oldp+112,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_special_result),32);
        bufp->chgIData(oldp+113,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_sum_vec),28);
        bufp->chgIData(oldp+114,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_carry_vec),28);
        bufp->chgCData(oldp+115,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_hot_ones),3);
        bufp->chgIData(oldp+116,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__raw_sum),29);
        bufp->chgIData(oldp+117,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mag_sum),27);
        bufp->chgBit(oldp+118,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__res_sign));
        bufp->chgCData(oldp+119,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_exp_base),5);
        bufp->chgIData(oldp+120,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sum_mag),27);
        bufp->chgIData(oldp+121,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_spec_res),32);
        bufp->chgBit(oldp+122,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_res_sign));
        bufp->chgBit(oldp+123,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sticky));
        bufp->chgBit(oldp+124,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_special));
        bufp->chgIData(oldp+125,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan),27);
        bufp->chgCData(oldp+126,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros),6);
        bufp->chgIData(oldp+127,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__norm_val),27);
        bufp->chgIData(oldp+128,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__final_mant),23);
        bufp->chgSData(oldp+129,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__final_exp_calc),11);
        bufp->chgIData(oldp+130,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__result_out),32);
        bufp->chgIData(oldp+131,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__stage3_logic__DOT__unnamedblk9__DOT__i),32);
        bufp->chgIData(oldp+132,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__unnamedblk7__DOT__i),32);
        bufp->chgIData(oldp+133,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__unnamedblk8__DOT__i),32);
        bufp->chgBit(oldp+134,((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
                                >> 0x1fU)));
        bufp->chgCData(oldp+135,((0xffU & (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+136,((0x7fffffU & vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out)),23);
        bufp->chgSData(oldp+137,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp),10);
        bufp->chgSData(oldp+138,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded),11);
        bufp->chgBit(oldp+139,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__guard));
        bufp->chgBit(oldp+140,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rnd));
        bufp->chgBit(oldp+141,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__sticky));
        bufp->chgBit(oldp+142,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__round_up));
    }
    bufp->chgBit(oldp+143,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_clk));
}

void Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_cleanup\n"); );
    // Init
    Vaddn_fp32accum_fp16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaddn_fp32accum_fp16_tb_softfloat___024root*>(voidSelf);
    Vaddn_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
}
