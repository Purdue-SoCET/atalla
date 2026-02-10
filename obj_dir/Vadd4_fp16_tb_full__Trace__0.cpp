// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadd4_fp16_tb_full__Syms.h"


void Vadd4_fp16_tb_full___024root__trace_chg_0_sub_0(Vadd4_fp16_tb_full___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vadd4_fp16_tb_full___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_full___024root__trace_chg_0\n"); );
    // Init
    Vadd4_fp16_tb_full___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd4_fp16_tb_full___024root*>(voidSelf);
    Vadd4_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vadd4_fp16_tb_full___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vadd4_fp16_tb_full___024root__trace_chg_0_sub_0(Vadd4_fp16_tb_full___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_full___024root__trace_chg_0_sub_0\n"); );
    Vadd4_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst));
        bufp->chgSData(oldp+1,(vlSelfRef.add4_fp16_tb_full__DOT__tb_a),16);
        bufp->chgSData(oldp+2,(vlSelfRef.add4_fp16_tb_full__DOT__tb_b),16);
        bufp->chgSData(oldp+3,(vlSelfRef.add4_fp16_tb_full__DOT__tb_c),16);
        bufp->chgSData(oldp+4,(vlSelfRef.add4_fp16_tb_full__DOT__tb_d),16);
        bufp->chgBit(oldp+5,(vlSelfRef.add4_fp16_tb_full__DOT__tb_start));
        bufp->chgSData(oldp+6,(vlSelfRef.add4_fp16_tb_full__DOT__exp),16);
        bufp->chgIData(oldp+7,(vlSelfRef.add4_fp16_tb_full__DOT__pass_count),32);
        bufp->chgIData(oldp+8,(vlSelfRef.add4_fp16_tb_full__DOT__fail_count),32);
        bufp->chgIData(oldp+9,(vlSelfRef.add4_fp16_tb_full__DOT__fd),32);
        bufp->chgSData(oldp+10,(vlSelfRef.add4_fp16_tb_full__DOT__a),16);
        bufp->chgSData(oldp+11,(vlSelfRef.add4_fp16_tb_full__DOT__b),16);
        bufp->chgSData(oldp+12,(vlSelfRef.add4_fp16_tb_full__DOT__c),16);
        bufp->chgSData(oldp+13,(vlSelfRef.add4_fp16_tb_full__DOT__d),16);
        bufp->chgSData(oldp+14,(vlSelfRef.add4_fp16_tb_full__DOT__expected),16);
        bufp->chgIData(oldp+15,(vlSelfRef.add4_fp16_tb_full__DOT__unnamedblk1__DOT__ret),32);
        bufp->chgBit(oldp+16,(vlSelfRef.add4_fp16_tb_full__DOT__unnamedblk1__DOT__is_zero_result));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [5U])))) {
        bufp->chgSData(oldp+17,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__a),16);
        bufp->chgSData(oldp+18,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__b),16);
        bufp->chgBit(oldp+19,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__is_nan_a));
        bufp->chgBit(oldp+20,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__is_nan_b));
        bufp->chgBit(oldp+21,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__is_inf_a));
        bufp->chgBit(oldp+22,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__is_inf_b));
        bufp->chgBit(oldp+23,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_case));
        bufp->chgSData(oldp+24,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_result),16);
        bufp->chgBit(oldp+25,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__op_swap));
        bufp->chgSData(oldp+26,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__high_op),16);
        bufp->chgSData(oldp+27,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__low_op),16);
        bufp->chgCData(oldp+28,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__high_exp),5);
        bufp->chgCData(oldp+29,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__low_exp),5);
        bufp->chgSData(oldp+30,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_hi),13);
        bufp->chgSData(oldp+31,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_lo),13);
        bufp->chgSData(oldp+32,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_lo_aligned),13);
        bufp->chgSData(oldp+33,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mask_align),13);
        bufp->chgBit(oldp+34,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sticky_align_local));
        bufp->chgBit(oldp+35,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sticky_lost));
        bufp->chgCData(oldp+36,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_diff),5);
        bufp->chgCData(oldp+37,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_max),5);
        bufp->chgSData(oldp+38,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_shifted),13);
        bufp->chgSData(oldp+39,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_not_shifted),13);
        bufp->chgBit(oldp+40,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_shifted));
        bufp->chgBit(oldp+41,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_not_shifted));
        bufp->chgSData(oldp+42,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__smaller_mantissa),13);
        bufp->chgSData(oldp+43,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__larger_mantissa),13);
        bufp->chgBit(oldp+44,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__larger_mantissa_sign));
        bufp->chgBit(oldp+45,(((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_shifted) 
                               ^ (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_not_shifted))));
        bufp->chgBit(oldp+46,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sub_has_lost_sticky));
        bufp->chgBit(oldp+47,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sub_has_added_sticky));
        bufp->chgSData(oldp+48,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__a),16);
        bufp->chgSData(oldp+49,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__b),16);
        bufp->chgBit(oldp+50,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__is_nan_a));
        bufp->chgBit(oldp+51,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__is_nan_b));
        bufp->chgBit(oldp+52,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__is_inf_a));
        bufp->chgBit(oldp+53,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__is_inf_b));
        bufp->chgBit(oldp+54,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_case));
        bufp->chgSData(oldp+55,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_result),16);
        bufp->chgBit(oldp+56,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__op_swap));
        bufp->chgSData(oldp+57,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__high_op),16);
        bufp->chgSData(oldp+58,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__low_op),16);
        bufp->chgCData(oldp+59,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__high_exp),5);
        bufp->chgCData(oldp+60,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__low_exp),5);
        bufp->chgSData(oldp+61,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_hi),13);
        bufp->chgSData(oldp+62,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_lo),13);
        bufp->chgSData(oldp+63,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_lo_aligned),13);
        bufp->chgSData(oldp+64,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mask_align),13);
        bufp->chgBit(oldp+65,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sticky_align_local));
        bufp->chgBit(oldp+66,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sticky_lost));
        bufp->chgCData(oldp+67,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_diff),5);
        bufp->chgCData(oldp+68,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_max),5);
        bufp->chgSData(oldp+69,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_shifted),13);
        bufp->chgSData(oldp+70,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_not_shifted),13);
        bufp->chgBit(oldp+71,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_shifted));
        bufp->chgBit(oldp+72,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_not_shifted));
        bufp->chgSData(oldp+73,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__smaller_mantissa),13);
        bufp->chgSData(oldp+74,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__larger_mantissa),13);
        bufp->chgBit(oldp+75,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__larger_mantissa_sign));
        bufp->chgBit(oldp+76,(((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_shifted) 
                               ^ (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_not_shifted))));
        bufp->chgBit(oldp+77,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sub_has_lost_sticky));
        bufp->chgBit(oldp+78,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sub_has_added_sticky));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgSData(oldp+79,(((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                                  ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                                  : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                                      ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                         << 0xfU) : 
                                     ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                       ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                          << 0xfU) : 
                                      (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                        << 0xfU) | 
                                       (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                         << 0xaU) | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final))))))),16);
        bufp->chgBit(oldp+80,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__start_l));
        bufp->chgSData(oldp+81,(((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_case_l)
                                  ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_result_l)
                                  : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum))
                                      ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__result_sign) 
                                         << 0xfU) : 
                                     ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__ftz_under)
                                       ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__result_sign) 
                                          << 0xfU) : 
                                      (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__result_sign) 
                                        << 0xfU) | 
                                       (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_out_final) 
                                         << 0xaU) | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__rounded_fraction_final))))))),16);
        bufp->chgSData(oldp+82,(((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_case_l)
                                  ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_result_l)
                                  : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum))
                                      ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__result_sign) 
                                         << 0xfU) : 
                                     ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__ftz_under)
                                       ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__result_sign) 
                                          << 0xfU) : 
                                      (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__result_sign) 
                                        << 0xfU) | 
                                       (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_out_final) 
                                         << 0xaU) | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__rounded_fraction_final))))))),16);
        bufp->chgBit(oldp+83,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__start_l));
        bufp->chgBit(oldp+84,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__start_l));
        bufp->chgSData(oldp+85,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum),14);
        bufp->chgBit(oldp+86,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__result_sign));
        bufp->chgBit(oldp+87,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_overflow));
        bufp->chgSData(oldp+88,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__smaller_mantissa_l),13);
        bufp->chgSData(oldp+89,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__larger_mantissa_l),13);
        bufp->chgBit(oldp+90,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__larger_mantissa_sign_l));
        bufp->chgBit(oldp+91,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_shifted_l));
        bufp->chgBit(oldp+92,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_not_shifted_l));
        bufp->chgBit(oldp+93,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__signs_differ_l));
        bufp->chgCData(oldp+94,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_max_l),5);
        bufp->chgBit(oldp+95,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_case_l));
        bufp->chgSData(oldp+96,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_result_l),16);
        bufp->chgBit(oldp+97,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sub_has_lost_sticky_l));
        bufp->chgBit(oldp+98,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sub_has_added_sticky_l));
        bufp->chgSData(oldp+99,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__normalized_mantissa_sum),13);
        bufp->chgCData(oldp+100,((0xfU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT____Vcellout__normalizer__shifted_amount))),4);
        bufp->chgCData(oldp+101,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_norm_s),7);
        bufp->chgSData(oldp+102,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__round_this),12);
        bufp->chgCData(oldp+103,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_base),6);
        bufp->chgBit(oldp+104,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__ftz_under));
        bufp->chgBit(oldp+105,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__round_inc));
        bufp->chgSData(oldp+106,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_sum),11);
        bufp->chgBit(oldp+107,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_carry));
        bufp->chgCData(oldp+108,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_out),6);
        bufp->chgSData(oldp+109,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__rounded_fraction),10);
        bufp->chgBit(oldp+110,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__overflow));
        bufp->chgCData(oldp+111,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_out_final),5);
        bufp->chgSData(oldp+112,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__rounded_fraction_final),10);
        bufp->chgSData(oldp+113,((0x1fffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum))),13);
        bufp->chgCData(oldp+114,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT____Vcellout__normalizer__shifted_amount),5);
        bufp->chgSData(oldp+115,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum),14);
        bufp->chgBit(oldp+116,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__result_sign));
        bufp->chgBit(oldp+117,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_overflow));
        bufp->chgSData(oldp+118,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__smaller_mantissa_l),13);
        bufp->chgSData(oldp+119,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__larger_mantissa_l),13);
        bufp->chgBit(oldp+120,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__larger_mantissa_sign_l));
        bufp->chgBit(oldp+121,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_shifted_l));
        bufp->chgBit(oldp+122,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_not_shifted_l));
        bufp->chgBit(oldp+123,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__signs_differ_l));
        bufp->chgCData(oldp+124,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_max_l),5);
        bufp->chgBit(oldp+125,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_case_l));
        bufp->chgSData(oldp+126,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_result_l),16);
        bufp->chgBit(oldp+127,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sub_has_lost_sticky_l));
        bufp->chgBit(oldp+128,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sub_has_added_sticky_l));
        bufp->chgSData(oldp+129,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__normalized_mantissa_sum),13);
        bufp->chgCData(oldp+130,((0xfU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT____Vcellout__normalizer__shifted_amount))),4);
        bufp->chgCData(oldp+131,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_norm_s),7);
        bufp->chgSData(oldp+132,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__round_this),12);
        bufp->chgCData(oldp+133,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_base),6);
        bufp->chgBit(oldp+134,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__ftz_under));
        bufp->chgBit(oldp+135,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__round_inc));
        bufp->chgSData(oldp+136,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_sum),11);
        bufp->chgBit(oldp+137,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_carry));
        bufp->chgCData(oldp+138,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_out),6);
        bufp->chgSData(oldp+139,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__rounded_fraction),10);
        bufp->chgBit(oldp+140,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__overflow));
        bufp->chgCData(oldp+141,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_out_final),5);
        bufp->chgSData(oldp+142,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__rounded_fraction_final),10);
        bufp->chgSData(oldp+143,((0x1fffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum))),13);
        bufp->chgCData(oldp+144,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT____Vcellout__normalizer__shifted_amount),5);
        bufp->chgSData(oldp+145,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__a),16);
        bufp->chgSData(oldp+146,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__b),16);
        bufp->chgBit(oldp+147,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__is_nan_a));
        bufp->chgBit(oldp+148,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__is_nan_b));
        bufp->chgBit(oldp+149,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__is_inf_a));
        bufp->chgBit(oldp+150,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__is_inf_b));
        bufp->chgBit(oldp+151,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case));
        bufp->chgSData(oldp+152,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result),16);
        bufp->chgBit(oldp+153,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__op_swap));
        bufp->chgSData(oldp+154,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__high_op),16);
        bufp->chgSData(oldp+155,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__low_op),16);
        bufp->chgCData(oldp+156,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__high_exp),5);
        bufp->chgCData(oldp+157,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__low_exp),5);
        bufp->chgSData(oldp+158,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_hi),13);
        bufp->chgSData(oldp+159,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_lo),13);
        bufp->chgSData(oldp+160,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_lo_aligned),13);
        bufp->chgSData(oldp+161,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mask_align),13);
        bufp->chgBit(oldp+162,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sticky_align_local));
        bufp->chgBit(oldp+163,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sticky_lost));
        bufp->chgCData(oldp+164,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_diff),5);
        bufp->chgCData(oldp+165,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_max),5);
        bufp->chgSData(oldp+166,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_shifted),13);
        bufp->chgSData(oldp+167,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_not_shifted),13);
        bufp->chgBit(oldp+168,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_shifted));
        bufp->chgBit(oldp+169,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_not_shifted));
        bufp->chgSData(oldp+170,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__smaller_mantissa),13);
        bufp->chgSData(oldp+171,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__larger_mantissa),13);
        bufp->chgSData(oldp+172,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum),14);
        bufp->chgBit(oldp+173,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__larger_mantissa_sign));
        bufp->chgBit(oldp+174,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign));
        bufp->chgBit(oldp+175,(((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_shifted) 
                                ^ (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_not_shifted))));
        bufp->chgBit(oldp+176,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_overflow));
        bufp->chgBit(oldp+177,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sub_has_lost_sticky));
        bufp->chgBit(oldp+178,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sub_has_added_sticky));
        bufp->chgSData(oldp+179,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__smaller_mantissa_l),13);
        bufp->chgSData(oldp+180,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__larger_mantissa_l),13);
        bufp->chgBit(oldp+181,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__larger_mantissa_sign_l));
        bufp->chgBit(oldp+182,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_shifted_l));
        bufp->chgBit(oldp+183,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_not_shifted_l));
        bufp->chgBit(oldp+184,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__signs_differ_l));
        bufp->chgCData(oldp+185,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_max_l),5);
        bufp->chgBit(oldp+186,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l));
        bufp->chgSData(oldp+187,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l),16);
        bufp->chgBit(oldp+188,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sub_has_lost_sticky_l));
        bufp->chgBit(oldp+189,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sub_has_added_sticky_l));
        bufp->chgSData(oldp+190,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__normalized_mantissa_sum),13);
        bufp->chgCData(oldp+191,((0xfU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT____Vcellout__normalizer__shifted_amount))),4);
        bufp->chgCData(oldp+192,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_norm_s),7);
        bufp->chgSData(oldp+193,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__round_this),12);
        bufp->chgCData(oldp+194,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_base),6);
        bufp->chgBit(oldp+195,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under));
        bufp->chgBit(oldp+196,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__round_inc));
        bufp->chgSData(oldp+197,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_sum),11);
        bufp->chgBit(oldp+198,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_carry));
        bufp->chgCData(oldp+199,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out),6);
        bufp->chgSData(oldp+200,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction),10);
        bufp->chgBit(oldp+201,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__overflow));
        bufp->chgCData(oldp+202,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final),5);
        bufp->chgSData(oldp+203,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final),10);
        bufp->chgSData(oldp+204,((0x1fffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))),13);
        bufp->chgCData(oldp+205,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT____Vcellout__normalizer__shifted_amount),5);
    }
    bufp->chgBit(oldp+206,(vlSelfRef.add4_fp16_tb_full__DOT__tb_clk));
}

void Vadd4_fp16_tb_full___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_full___024root__trace_cleanup\n"); );
    // Init
    Vadd4_fp16_tb_full___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd4_fp16_tb_full___024root*>(voidSelf);
    Vadd4_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
}
