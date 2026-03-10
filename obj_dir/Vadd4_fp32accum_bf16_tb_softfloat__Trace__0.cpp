// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadd4_fp32accum_bf16_tb_softfloat__Syms.h"


void Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_chg_0_sub_0(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_chg_0\n"); );
    // Init
    Vadd4_fp32accum_bf16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd4_fp32accum_bf16_tb_softfloat___024root*>(voidSelf);
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_chg_0_sub_0(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_chg_0_sub_0\n"); );
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_nrst));
        bufp->chgSData(oldp+1,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a),16);
        bufp->chgSData(oldp+2,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b),16);
        bufp->chgSData(oldp+3,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c),16);
        bufp->chgSData(oldp+4,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d),16);
        bufp->chgSData(oldp+5,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__exp),16);
        bufp->chgIData(oldp+6,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count),32);
        bufp->chgIData(oldp+7,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count),32);
        bufp->chgQData(oldp+8,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff),64);
        bufp->chgIData(oldp+10,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count),32);
        bufp->chgSData(oldp+11,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__a),16);
        bufp->chgSData(oldp+12,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__b),16);
        bufp->chgSData(oldp+13,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__c),16);
        bufp->chgSData(oldp+14,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__d),16);
        bufp->chgSData(oldp+15,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__expected),16);
        bufp->chgIData(oldp+16,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fd),32);
        bufp->chgIData(oldp+17,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_count),32);
        bufp->chgQData(oldp+18,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a),64);
        bufp->chgQData(oldp+20,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b),64);
        bufp->chgIData(oldp+22,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__ret),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [5U])))) {
        bufp->chgSData(oldp+23,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__a_daz),16);
        bufp->chgSData(oldp+24,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__b_daz),16);
        bufp->chgSData(oldp+25,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__c_daz),16);
        bufp->chgSData(oldp+26,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__d_daz),16);
        bufp->chgCData(oldp+27,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_a),8);
        bufp->chgCData(oldp+28,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_b),8);
        bufp->chgCData(oldp+29,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_c),8);
        bufp->chgCData(oldp+30,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_d),8);
        bufp->chgCData(oldp+31,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_a),7);
        bufp->chgCData(oldp+32,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_b),7);
        bufp->chgCData(oldp+33,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_c),7);
        bufp->chgCData(oldp+34,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_d),7);
        bufp->chgBit(oldp+35,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_a));
        bufp->chgBit(oldp+36,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_b));
        bufp->chgBit(oldp+37,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_c));
        bufp->chgBit(oldp+38,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_d));
        bufp->chgCData(oldp+39,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_p),8);
        bufp->chgCData(oldp+40,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_m),8);
        bufp->chgCData(oldp+41,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_r),8);
        bufp->chgCData(oldp+42,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_n),8);
        bufp->chgCData(oldp+43,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_x),8);
        bufp->chgCData(oldp+44,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_y),8);
        bufp->chgCData(oldp+45,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_mx),8);
        bufp->chgCData(oldp+46,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_nx),8);
        bufp->chgCData(oldp+47,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_p),7);
        bufp->chgCData(oldp+48,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_m),7);
        bufp->chgCData(oldp+49,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_r),7);
        bufp->chgCData(oldp+50,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_n),7);
        bufp->chgCData(oldp+51,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_x),7);
        bufp->chgCData(oldp+52,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_y),7);
        bufp->chgCData(oldp+53,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_mx),7);
        bufp->chgCData(oldp+54,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_nx),7);
        bufp->chgBit(oldp+55,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_p));
        bufp->chgBit(oldp+56,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_m));
        bufp->chgBit(oldp+57,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_r));
        bufp->chgBit(oldp+58,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_n));
        bufp->chgBit(oldp+59,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_x));
        bufp->chgBit(oldp+60,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_y));
        bufp->chgBit(oldp+61,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_mx));
        bufp->chgBit(oldp+62,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_nx));
        bufp->chgCData(oldp+63,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_x_eff),8);
        bufp->chgCData(oldp+64,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_y_eff),8);
        bufp->chgCData(oldp+65,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_mx_eff),8);
        bufp->chgCData(oldp+66,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_nx_eff),8);
        bufp->chgSData(oldp+67,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__y_shift),9);
        bufp->chgSData(oldp+68,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__m_shift),9);
        bufp->chgSData(oldp+69,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__n_shift),9);
        bufp->chgIData(oldp+70,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__x_mant),24);
        bufp->chgIData(oldp+71,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__y_shifted),24);
        bufp->chgIData(oldp+72,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__m_shifted),24);
        bufp->chgIData(oldp+73,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__n_shifted),24);
        bufp->chgIData(oldp+74,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__y_mant_base),24);
        bufp->chgIData(oldp+75,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__m_mant_base),24);
        bufp->chgIData(oldp+76,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__n_mant_base),24);
        bufp->chgBit(oldp+77,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sticky_y));
        bufp->chgBit(oldp+78,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sticky_m));
        bufp->chgBit(oldp+79,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sticky_n));
        bufp->chgBit(oldp+80,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__y_op));
        bufp->chgBit(oldp+81,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__m_op));
        bufp->chgBit(oldp+82,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__n_op));
        bufp->chgBit(oldp+83,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__is_nan_any));
        bufp->chgBit(oldp+84,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__special_case));
        bufp->chgBit(oldp+85,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__any_pos_inf));
        bufp->chgBit(oldp+86,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__any_neg_inf));
        bufp->chgIData(oldp+87,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__special_result),32);
        bufp->chgIData(oldp+88,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__op_x),27);
        bufp->chgIData(oldp+89,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__op_y),27);
        bufp->chgIData(oldp+90,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__op_m),27);
        bufp->chgIData(oldp+91,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__op_n),27);
        bufp->chgIData(oldp+92,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__csa_s1),27);
        bufp->chgIData(oldp+93,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__csa_c1),27);
        bufp->chgIData(oldp+94,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__csa_s2),27);
        bufp->chgIData(oldp+95,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__csa_c2),27);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgSData(oldp+96,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result),16);
        bufp->chgCData(oldp+97,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st1_a_e),8);
        bufp->chgBit(oldp+98,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st1_a_s));
        bufp->chgBit(oldp+99,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st1_align_sticky));
        bufp->chgBit(oldp+100,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st1_special_case));
        bufp->chgIData(oldp+101,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st1_special_result),32);
        bufp->chgIData(oldp+102,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st1_sum_vec),27);
        bufp->chgIData(oldp+103,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st1_carry_vec),27);
        bufp->chgCData(oldp+104,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st1_hot_ones),2);
        bufp->chgIData(oldp+105,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__raw_sum),28);
        bufp->chgIData(oldp+106,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__mag_sum),26);
        bufp->chgBit(oldp+107,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__res_sign));
        bufp->chgCData(oldp+108,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_exp_base),8);
        bufp->chgIData(oldp+109,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_sum_mag),26);
        bufp->chgIData(oldp+110,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_spec_res),32);
        bufp->chgBit(oldp+111,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_res_sign));
        bufp->chgBit(oldp+112,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_sticky));
        bufp->chgBit(oldp+113,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_special));
        bufp->chgIData(oldp+114,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan),26);
        bufp->chgCData(oldp+115,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros),6);
        bufp->chgIData(oldp+116,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__norm_val),26);
        bufp->chgIData(oldp+117,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__final_mant),23);
        bufp->chgSData(oldp+118,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__final_exp_calc),11);
        bufp->chgIData(oldp+119,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__result_out),32);
        bufp->chgIData(oldp+120,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__stage3_logic__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+121,(vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out),32);
        bufp->chgBit(oldp+122,((vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out 
                                >> 0x1fU)));
        bufp->chgCData(oldp+123,((0xffU & (vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out 
                                           >> 0x17U))),8);
        bufp->chgIData(oldp+124,((0x7fffffU & vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out)),23);
        bufp->chgSData(oldp+125,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__new_exp),10);
        bufp->chgCData(oldp+126,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__rounded),8);
        bufp->chgBit(oldp+127,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__guard));
        bufp->chgBit(oldp+128,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__rnd));
        bufp->chgBit(oldp+129,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__sticky));
        bufp->chgBit(oldp+130,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__round_up));
    }
    bufp->chgBit(oldp+131,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_clk));
}

void Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_cleanup\n"); );
    // Init
    Vadd4_fp32accum_bf16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd4_fp32accum_bf16_tb_softfloat___024root*>(voidSelf);
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
}
