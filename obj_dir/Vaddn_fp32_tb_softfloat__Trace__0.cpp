// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vaddn_fp32_tb_softfloat__Syms.h"


void Vaddn_fp32_tb_softfloat___024root__trace_chg_0_sub_0(Vaddn_fp32_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vaddn_fp32_tb_softfloat___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root__trace_chg_0\n"); );
    // Init
    Vaddn_fp32_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaddn_fp32_tb_softfloat___024root*>(voidSelf);
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vaddn_fp32_tb_softfloat___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vaddn_fp32_tb_softfloat___024root__trace_chg_0_sub_0(Vaddn_fp32_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root__trace_chg_0_sub_0\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_nrst));
        bufp->chgWData(oldp+1,(vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data),128);
        bufp->chgIData(oldp+5,(vlSelfRef.addn_fp32_tb_softfloat__DOT__exp),32);
        bufp->chgIData(oldp+6,(vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count),32);
        bufp->chgIData(oldp+7,(vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count),32);
        bufp->chgIData(oldp+8,(vlSelfRef.addn_fp32_tb_softfloat__DOT__off_by_one),32);
        bufp->chgIData(oldp+9,(vlSelfRef.addn_fp32_tb_softfloat__DOT__off_by_two),32);
        bufp->chgIData(oldp+10,(vlSelfRef.addn_fp32_tb_softfloat__DOT__off_by_five_plus),32);
        bufp->chgIData(oldp+11,(vlSelfRef.addn_fp32_tb_softfloat__DOT__diff),32);
        bufp->chgIData(oldp+12,(vlSelfRef.addn_fp32_tb_softfloat__DOT__fd),32);
        bufp->chgIData(oldp+13,(vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_fd),32);
        bufp->chgIData(oldp+14,(vlSelfRef.addn_fp32_tb_softfloat__DOT__a),32);
        bufp->chgIData(oldp+15,(vlSelfRef.addn_fp32_tb_softfloat__DOT__b),32);
        bufp->chgIData(oldp+16,(vlSelfRef.addn_fp32_tb_softfloat__DOT__c),32);
        bufp->chgIData(oldp+17,(vlSelfRef.addn_fp32_tb_softfloat__DOT__d),32);
        bufp->chgIData(oldp+18,(vlSelfRef.addn_fp32_tb_softfloat__DOT__expected),32);
        bufp->chgIData(oldp+19,(vlSelfRef.addn_fp32_tb_softfloat__DOT__total_count),32);
        bufp->chgIData(oldp+20,(vlSelfRef.addn_fp32_tb_softfloat__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+21,(vlSelfRef.addn_fp32_tb_softfloat__DOT__unnamedblk2__DOT__ret),32);
        bufp->chgBit(oldp+22,(vlSelfRef.addn_fp32_tb_softfloat__DOT__unnamedblk2__DOT__is_zero_result));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [5U])))) {
        bufp->chgIData(oldp+23,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in[0]),32);
        bufp->chgIData(oldp+24,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in[1]),32);
        bufp->chgIData(oldp+25,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in[2]),32);
        bufp->chgIData(oldp+26,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in[3]),32);
        bufp->chgCData(oldp+27,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp[0]),8);
        bufp->chgCData(oldp+28,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp[1]),8);
        bufp->chgCData(oldp+29,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp[2]),8);
        bufp->chgCData(oldp+30,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp[3]),8);
        bufp->chgIData(oldp+31,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac[0]),23);
        bufp->chgIData(oldp+32,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac[1]),23);
        bufp->chgIData(oldp+33,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac[2]),23);
        bufp->chgIData(oldp+34,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac[3]),23);
        bufp->chgBit(oldp+35,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign[0]));
        bufp->chgBit(oldp+36,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign[1]));
        bufp->chgBit(oldp+37,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign[2]));
        bufp->chgBit(oldp+38,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign[3]));
        bufp->chgCData(oldp+39,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
                                [0U][0U]),8);
        bufp->chgCData(oldp+40,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
                                [0U][1U]),8);
        bufp->chgCData(oldp+41,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
                                [0U][2U]),8);
        bufp->chgCData(oldp+42,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
                                [0U][3U]),8);
        bufp->chgCData(oldp+43,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
                                [1U][0U]),8);
        bufp->chgCData(oldp+44,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
                                [1U][1U]),8);
        bufp->chgCData(oldp+45,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
                                [1U][2U]),8);
        bufp->chgCData(oldp+46,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
                                [1U][3U]),8);
        bufp->chgCData(oldp+47,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
                                [2U][0U]),8);
        bufp->chgCData(oldp+48,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
                                [2U][1U]),8);
        bufp->chgCData(oldp+49,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
                                [2U][2U]),8);
        bufp->chgCData(oldp+50,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
                                [2U][3U]),8);
        bufp->chgCData(oldp+51,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
                                [0U][0U]),2);
        bufp->chgCData(oldp+52,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
                                [0U][1U]),2);
        bufp->chgCData(oldp+53,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
                                [0U][2U]),2);
        bufp->chgCData(oldp+54,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
                                [0U][3U]),2);
        bufp->chgCData(oldp+55,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
                                [1U][0U]),2);
        bufp->chgCData(oldp+56,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
                                [1U][1U]),2);
        bufp->chgCData(oldp+57,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
                                [1U][2U]),2);
        bufp->chgCData(oldp+58,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
                                [1U][3U]),2);
        bufp->chgCData(oldp+59,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
                                [2U][0U]),2);
        bufp->chgCData(oldp+60,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
                                [2U][1U]),2);
        bufp->chgCData(oldp+61,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
                                [2U][2U]),2);
        bufp->chgCData(oldp+62,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
                                [2U][3U]),2);
        bufp->chgCData(oldp+63,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_exp),8);
        bufp->chgCData(oldp+64,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_exp_eff),8);
        bufp->chgCData(oldp+65,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_idx),2);
        bufp->chgBit(oldp+66,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign_max));
        bufp->chgSData(oldp+67,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift[0]),9);
        bufp->chgSData(oldp+68,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift[1]),9);
        bufp->chgSData(oldp+69,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift[2]),9);
        bufp->chgSData(oldp+70,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift[3]),9);
        bufp->chgWData(oldp+71,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[0]),74);
        bufp->chgWData(oldp+74,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[1]),74);
        bufp->chgWData(oldp+77,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[2]),74);
        bufp->chgWData(oldp+80,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[3]),74);
        bufp->chgWData(oldp+83,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[0]),74);
        bufp->chgWData(oldp+86,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[1]),74);
        bufp->chgWData(oldp+89,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[2]),74);
        bufp->chgWData(oldp+92,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[3]),74);
        bufp->chgBit(oldp+95,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sticky[0]));
        bufp->chgBit(oldp+96,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sticky[1]));
        bufp->chgBit(oldp+97,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sticky[2]));
        bufp->chgBit(oldp+98,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sticky[3]));
        bufp->chgBit(oldp+99,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff[0]));
        bufp->chgBit(oldp+100,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff[1]));
        bufp->chgBit(oldp+101,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff[2]));
        bufp->chgBit(oldp+102,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff[3]));
        bufp->chgWData(oldp+103,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[0]),77);
        bufp->chgWData(oldp+106,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[1]),77);
        bufp->chgWData(oldp+109,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[2]),77);
        bufp->chgWData(oldp+112,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[3]),77);
        bufp->chgBit(oldp+115,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__is_nan_any));
        bufp->chgBit(oldp+116,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_pos_inf));
        bufp->chgBit(oldp+117,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_neg_inf));
        bufp->chgBit(oldp+118,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__special_case));
        bufp->chgIData(oldp+119,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__special_result),32);
        bufp->chgWData(oldp+120,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[0]),77);
        bufp->chgWData(oldp+123,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[1]),77);
        bufp->chgWData(oldp+126,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[2]),77);
        bufp->chgWData(oldp+129,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[3]),77);
        bufp->chgWData(oldp+132,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[0]),77);
        bufp->chgWData(oldp+135,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[1]),77);
        bufp->chgWData(oldp+138,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[2]),77);
        bufp->chgWData(oldp+141,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[3]),77);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgIData(oldp+144,(vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result),32);
        bufp->chgCData(oldp+145,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_a_e),8);
        bufp->chgBit(oldp+146,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_a_s));
        bufp->chgBit(oldp+147,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_align_sticky));
        bufp->chgBit(oldp+148,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_special_case));
        bufp->chgIData(oldp+149,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_special_result),32);
        bufp->chgWData(oldp+150,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_sum_vec),77);
        bufp->chgWData(oldp+153,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_carry_vec),77);
        bufp->chgCData(oldp+156,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_hot_ones),3);
        bufp->chgWData(oldp+157,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__raw_sum),78);
        bufp->chgWData(oldp+160,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mag_sum),76);
        bufp->chgBit(oldp+163,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__res_sign));
        bufp->chgCData(oldp+164,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_exp_base),8);
        bufp->chgWData(oldp+165,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag),76);
        bufp->chgIData(oldp+168,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_spec_res),32);
        bufp->chgBit(oldp+169,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_res_sign));
        bufp->chgBit(oldp+170,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sticky));
        bufp->chgBit(oldp+171,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_special));
        bufp->chgWData(oldp+172,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan),76);
        bufp->chgCData(oldp+175,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros),8);
        bufp->chgWData(oldp+176,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__norm_val),76);
        bufp->chgIData(oldp+179,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__final_mant),23);
        bufp->chgSData(oldp+180,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__final_exp_calc),11);
        bufp->chgIData(oldp+181,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__result_out),32);
        bufp->chgIData(oldp+182,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__stage3_logic__DOT__unnamedblk9__DOT__i),32);
        bufp->chgIData(oldp+183,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__unnamedblk7__DOT__i),32);
        bufp->chgIData(oldp+184,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__unnamedblk8__DOT__i),32);
    }
    bufp->chgBit(oldp+185,(vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_clk));
}

void Vaddn_fp32_tb_softfloat___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root__trace_cleanup\n"); );
    // Init
    Vaddn_fp32_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaddn_fp32_tb_softfloat___024root*>(voidSelf);
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
}
