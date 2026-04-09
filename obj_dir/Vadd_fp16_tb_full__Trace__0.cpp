// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadd_fp16_tb_full__Syms.h"


void Vadd_fp16_tb_full___024root__trace_chg_0_sub_0(Vadd_fp16_tb_full___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vadd_fp16_tb_full___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root__trace_chg_0\n"); );
    // Init
    Vadd_fp16_tb_full___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd_fp16_tb_full___024root*>(voidSelf);
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vadd_fp16_tb_full___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vadd_fp16_tb_full___024root__trace_chg_0_sub_0(Vadd_fp16_tb_full___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root__trace_chg_0_sub_0\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.add_fp16_tb_full__DOT__tb_nrst));
        bufp->chgSData(oldp+1,(vlSelfRef.add_fp16_tb_full__DOT__tb_a),16);
        bufp->chgSData(oldp+2,(vlSelfRef.add_fp16_tb_full__DOT__tb_b),16);
        bufp->chgBit(oldp+3,(vlSelfRef.add_fp16_tb_full__DOT__tb_start));
        bufp->chgBit(oldp+4,(vlSelfRef.add_fp16_tb_full__DOT__tb_sub));
        bufp->chgSData(oldp+5,(vlSelfRef.add_fp16_tb_full__DOT__exp),16);
        bufp->chgIData(oldp+6,(vlSelfRef.add_fp16_tb_full__DOT__pass_count),32);
        bufp->chgIData(oldp+7,(vlSelfRef.add_fp16_tb_full__DOT__fail_count),32);
        bufp->chgIData(oldp+8,(vlSelfRef.add_fp16_tb_full__DOT__fd),32);
        bufp->chgSData(oldp+9,(vlSelfRef.add_fp16_tb_full__DOT__a),16);
        bufp->chgSData(oldp+10,(vlSelfRef.add_fp16_tb_full__DOT__b),16);
        bufp->chgSData(oldp+11,(vlSelfRef.add_fp16_tb_full__DOT__expected),16);
        bufp->chgIData(oldp+12,(vlSelfRef.add_fp16_tb_full__DOT__unnamedblk1__DOT__ret),32);
        bufp->chgIData(oldp+13,(vlSelfRef.add_fp16_tb_full__DOT__unnamedblk1__DOT__sub_flag),32);
        bufp->chgBit(oldp+14,(vlSelfRef.add_fp16_tb_full__DOT__unnamedblk1__DOT__is_zero_result));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [5U])))) {
        bufp->chgSData(oldp+15,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a),16);
        bufp->chgSData(oldp+16,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b),16);
        bufp->chgBit(oldp+17,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_nan_a));
        bufp->chgBit(oldp+18,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_nan_b));
        bufp->chgBit(oldp+19,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_inf_a));
        bufp->chgBit(oldp+20,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_inf_b));
        bufp->chgBit(oldp+21,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case));
        bufp->chgSData(oldp+22,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result),16);
        bufp->chgBit(oldp+23,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__op_swap));
        bufp->chgSData(oldp+24,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__high_op),16);
        bufp->chgSData(oldp+25,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__low_op),16);
        bufp->chgCData(oldp+26,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__high_exp),5);
        bufp->chgCData(oldp+27,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__low_exp),5);
        bufp->chgSData(oldp+28,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_hi),13);
        bufp->chgSData(oldp+29,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo),13);
        bufp->chgSData(oldp+30,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo_aligned),13);
        bufp->chgSData(oldp+31,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mask_align),13);
        bufp->chgBit(oldp+32,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sticky_align_local));
        bufp->chgBit(oldp+33,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sticky_lost));
        bufp->chgCData(oldp+34,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_diff),5);
        bufp->chgCData(oldp+35,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_max),5);
        bufp->chgSData(oldp+36,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_shifted),13);
        bufp->chgSData(oldp+37,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_not_shifted),13);
        bufp->chgBit(oldp+38,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_shifted));
        bufp->chgBit(oldp+39,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_not_shifted));
        bufp->chgSData(oldp+40,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__smaller_mantissa),13);
        bufp->chgSData(oldp+41,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa),13);
        bufp->chgBit(oldp+42,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa_sign));
        bufp->chgBit(oldp+43,(((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_shifted) 
                               ^ (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_not_shifted))));
        bufp->chgBit(oldp+44,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sub_has_lost_sticky));
        bufp->chgBit(oldp+45,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sub_has_added_sticky));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgSData(oldp+46,(((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                                  ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                                  : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                      ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                         << 0xfU) : 
                                     ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                       ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                          << 0xfU) : 
                                      (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) | 
                                       (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                         << 0xaU) | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))))),16);
        bufp->chgBit(oldp+47,(vlSelfRef.add_fp16_tb_full__DOT__tb_done));
        bufp->chgSData(oldp+48,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum),14);
        bufp->chgBit(oldp+49,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign));
        bufp->chgBit(oldp+50,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_overflow));
        bufp->chgSData(oldp+51,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__smaller_mantissa_l),13);
        bufp->chgSData(oldp+52,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa_l),13);
        bufp->chgBit(oldp+53,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa_sign_l));
        bufp->chgBit(oldp+54,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_shifted_l));
        bufp->chgBit(oldp+55,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_not_shifted_l));
        bufp->chgBit(oldp+56,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__signs_differ_l));
        bufp->chgCData(oldp+57,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_max_l),5);
        bufp->chgBit(oldp+58,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l));
        bufp->chgSData(oldp+59,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l),16);
        bufp->chgBit(oldp+60,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sub_has_lost_sticky_l));
        bufp->chgBit(oldp+61,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sub_has_added_sticky_l));
        bufp->chgSData(oldp+62,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum),13);
        bufp->chgCData(oldp+63,((0xfU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount))),4);
        bufp->chgCData(oldp+64,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_norm_s),7);
        bufp->chgSData(oldp+65,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_this),12);
        bufp->chgCData(oldp+66,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_base),6);
        bufp->chgBit(oldp+67,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under));
        bufp->chgBit(oldp+68,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_inc));
        bufp->chgSData(oldp+69,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_sum),11);
        bufp->chgBit(oldp+70,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_carry));
        bufp->chgCData(oldp+71,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out),6);
        bufp->chgSData(oldp+72,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction),10);
        bufp->chgBit(oldp+73,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__overflow));
        bufp->chgCData(oldp+74,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final),5);
        bufp->chgSData(oldp+75,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final),10);
        bufp->chgSData(oldp+76,((0x1fffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))),13);
        bufp->chgCData(oldp+77,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount),5);
    }
    bufp->chgBit(oldp+78,(vlSelfRef.add_fp16_tb_full__DOT__tb_clk));
}

void Vadd_fp16_tb_full___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root__trace_cleanup\n"); );
    // Init
    Vadd_fp16_tb_full___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd_fp16_tb_full___024root*>(voidSelf);
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
}
