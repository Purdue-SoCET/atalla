// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadd4_bf16_tb_softfloat__Syms.h"


void Vadd4_bf16_tb_softfloat___024root__trace_chg_0_sub_0(Vadd4_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vadd4_bf16_tb_softfloat___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_bf16_tb_softfloat___024root__trace_chg_0\n"); );
    // Init
    Vadd4_bf16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd4_bf16_tb_softfloat___024root*>(voidSelf);
    Vadd4_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vadd4_bf16_tb_softfloat___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vadd4_bf16_tb_softfloat___024root__trace_chg_0_sub_0(Vadd4_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_bf16_tb_softfloat___024root__trace_chg_0_sub_0\n"); );
    Vadd4_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.add4_bf16_tb_softfloat__DOT__tb_nrst));
        bufp->chgSData(oldp+1,(vlSelfRef.add4_bf16_tb_softfloat__DOT__tb_a),16);
        bufp->chgSData(oldp+2,(vlSelfRef.add4_bf16_tb_softfloat__DOT__tb_b),16);
        bufp->chgSData(oldp+3,(vlSelfRef.add4_bf16_tb_softfloat__DOT__tb_c),16);
        bufp->chgSData(oldp+4,(vlSelfRef.add4_bf16_tb_softfloat__DOT__tb_d),16);
        bufp->chgSData(oldp+5,(vlSelfRef.add4_bf16_tb_softfloat__DOT__exp),16);
        bufp->chgIData(oldp+6,(vlSelfRef.add4_bf16_tb_softfloat__DOT__pass_count),32);
        bufp->chgIData(oldp+7,(vlSelfRef.add4_bf16_tb_softfloat__DOT__fail_count),32);
        bufp->chgIData(oldp+8,(vlSelfRef.add4_bf16_tb_softfloat__DOT__off_by_one),32);
        bufp->chgIData(oldp+9,(vlSelfRef.add4_bf16_tb_softfloat__DOT__off_by_two),32);
        bufp->chgIData(oldp+10,(vlSelfRef.add4_bf16_tb_softfloat__DOT__off_by_five_plus),32);
        bufp->chgIData(oldp+11,(vlSelfRef.add4_bf16_tb_softfloat__DOT__diff),32);
        bufp->chgIData(oldp+12,(vlSelfRef.add4_bf16_tb_softfloat__DOT__fd),32);
        bufp->chgIData(oldp+13,(vlSelfRef.add4_bf16_tb_softfloat__DOT__fail_fd),32);
        bufp->chgSData(oldp+14,(vlSelfRef.add4_bf16_tb_softfloat__DOT__a),16);
        bufp->chgSData(oldp+15,(vlSelfRef.add4_bf16_tb_softfloat__DOT__b),16);
        bufp->chgSData(oldp+16,(vlSelfRef.add4_bf16_tb_softfloat__DOT__c),16);
        bufp->chgSData(oldp+17,(vlSelfRef.add4_bf16_tb_softfloat__DOT__d),16);
        bufp->chgSData(oldp+18,(vlSelfRef.add4_bf16_tb_softfloat__DOT__expected),16);
        bufp->chgIData(oldp+19,(vlSelfRef.add4_bf16_tb_softfloat__DOT__unnamedblk1__DOT__ret),32);
        bufp->chgBit(oldp+20,(vlSelfRef.add4_bf16_tb_softfloat__DOT__unnamedblk1__DOT__is_zero_result));
        bufp->chgIData(oldp+21,(vlSelfRef.add4_bf16_tb_softfloat__DOT__unnamedblk1__DOT__total_count),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [5U])))) {
        bufp->chgSData(oldp+22,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz),16);
        bufp->chgSData(oldp+23,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz),16);
        bufp->chgSData(oldp+24,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz),16);
        bufp->chgSData(oldp+25,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz),16);
        bufp->chgCData(oldp+26,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a),8);
        bufp->chgCData(oldp+27,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b),8);
        bufp->chgCData(oldp+28,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c),8);
        bufp->chgCData(oldp+29,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d),8);
        bufp->chgCData(oldp+30,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a),7);
        bufp->chgCData(oldp+31,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b),7);
        bufp->chgCData(oldp+32,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c),7);
        bufp->chgCData(oldp+33,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d),7);
        bufp->chgBit(oldp+34,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a));
        bufp->chgBit(oldp+35,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b));
        bufp->chgBit(oldp+36,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c));
        bufp->chgBit(oldp+37,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d));
        bufp->chgCData(oldp+38,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p),8);
        bufp->chgCData(oldp+39,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m),8);
        bufp->chgCData(oldp+40,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r),8);
        bufp->chgCData(oldp+41,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n),8);
        bufp->chgCData(oldp+42,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x),8);
        bufp->chgCData(oldp+43,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y),8);
        bufp->chgCData(oldp+44,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx),8);
        bufp->chgCData(oldp+45,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx),8);
        bufp->chgCData(oldp+46,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p),7);
        bufp->chgCData(oldp+47,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m),7);
        bufp->chgCData(oldp+48,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r),7);
        bufp->chgCData(oldp+49,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n),7);
        bufp->chgCData(oldp+50,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x),7);
        bufp->chgCData(oldp+51,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y),7);
        bufp->chgCData(oldp+52,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx),7);
        bufp->chgCData(oldp+53,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx),7);
        bufp->chgBit(oldp+54,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p));
        bufp->chgBit(oldp+55,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m));
        bufp->chgBit(oldp+56,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r));
        bufp->chgBit(oldp+57,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n));
        bufp->chgBit(oldp+58,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x));
        bufp->chgBit(oldp+59,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_y));
        bufp->chgBit(oldp+60,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_mx));
        bufp->chgBit(oldp+61,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_nx));
        bufp->chgCData(oldp+62,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff),8);
        bufp->chgCData(oldp+63,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y_eff),8);
        bufp->chgCData(oldp+64,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx_eff),8);
        bufp->chgCData(oldp+65,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx_eff),8);
        bufp->chgSData(oldp+66,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift),9);
        bufp->chgSData(oldp+67,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift),9);
        bufp->chgSData(oldp+68,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift),9);
        bufp->chgIData(oldp+69,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant),19);
        bufp->chgIData(oldp+70,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted),19);
        bufp->chgIData(oldp+71,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted),19);
        bufp->chgIData(oldp+72,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted),19);
        bufp->chgIData(oldp+73,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base),19);
        bufp->chgIData(oldp+74,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base),19);
        bufp->chgIData(oldp+75,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base),19);
        bufp->chgBit(oldp+76,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_y));
        bufp->chgBit(oldp+77,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_m));
        bufp->chgBit(oldp+78,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_n));
        bufp->chgBit(oldp+79,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__y_op));
        bufp->chgBit(oldp+80,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__m_op));
        bufp->chgBit(oldp+81,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__n_op));
        bufp->chgBit(oldp+82,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_any));
        bufp->chgBit(oldp+83,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case));
        bufp->chgSData(oldp+84,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result),16);
        bufp->chgBit(oldp+85,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__any_pos_inf));
        bufp->chgBit(oldp+86,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__any_neg_inf));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgSData(oldp+87,(vlSymsp->TOP__add4_bf16_tb_softfloat__DOT__add_if.out),16);
        bufp->chgCData(oldp+88,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_e),8);
        bufp->chgIData(oldp+89,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f),19);
        bufp->chgIData(oldp+90,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_y_f),19);
        bufp->chgIData(oldp+91,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_m_f),19);
        bufp->chgIData(oldp+92,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_n_f),19);
        bufp->chgSData(oldp+93,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_result),16);
        bufp->chgBit(oldp+94,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s));
        bufp->chgBit(oldp+95,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_b_op));
        bufp->chgBit(oldp+96,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_c_op));
        bufp->chgBit(oldp+97,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_d_op));
        bufp->chgBit(oldp+98,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_align_sticky));
        bufp->chgBit(oldp+99,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_case));
        bufp->chgIData(oldp+100,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a),23);
        bufp->chgIData(oldp+101,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b),23);
        bufp->chgIData(oldp+102,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c),23);
        bufp->chgIData(oldp+103,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_d),23);
        bufp->chgIData(oldp+104,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum),21);
        bufp->chgIData(oldp+105,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum),22);
        bufp->chgCData(oldp+106,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros),5);
        bufp->chgBit(oldp+107,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__res_sign));
        bufp->chgCData(oldp+108,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_exp_base),8);
        bufp->chgIData(oldp+109,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag),21);
        bufp->chgCData(oldp+110,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_lzd),5);
        bufp->chgSData(oldp+111,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_spec_res),16);
        bufp->chgBit(oldp+112,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign));
        bufp->chgBit(oldp+113,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sticky));
        bufp->chgBit(oldp+114,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special));
        bufp->chgIData(oldp+115,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val),21);
        bufp->chgCData(oldp+116,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_mant),7);
        bufp->chgCData(oldp+117,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__final_mant),7);
        bufp->chgCData(oldp+118,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mant_int),8);
        bufp->chgSData(oldp+119,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc),11);
        bufp->chgBit(oldp+120,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__guard_bit));
        bufp->chgBit(oldp+121,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__round_bit));
        bufp->chgBit(oldp+122,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_bit));
        bufp->chgBit(oldp+123,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__round_up));
        bufp->chgSData(oldp+124,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__result_out),16);
        bufp->chgIData(oldp+125,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1),23);
        bufp->chgIData(oldp+126,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1),23);
        bufp->chgIData(oldp+127,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1_shifted),23);
        bufp->chgIData(oldp+128,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_logic__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+129,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_logic__DOT__unnamedblk2__DOT__i),32);
    }
    bufp->chgBit(oldp+130,(vlSelfRef.add4_bf16_tb_softfloat__DOT__tb_clk));
}

void Vadd4_bf16_tb_softfloat___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_bf16_tb_softfloat___024root__trace_cleanup\n"); );
    // Init
    Vadd4_bf16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd4_bf16_tb_softfloat___024root*>(voidSelf);
    Vadd4_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
}
