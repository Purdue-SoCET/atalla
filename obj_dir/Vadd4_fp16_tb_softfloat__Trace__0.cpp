// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadd4_fp16_tb_softfloat__Syms.h"


void Vadd4_fp16_tb_softfloat___024root__trace_chg_0_sub_0(Vadd4_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vadd4_fp16_tb_softfloat___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root__trace_chg_0\n"); );
    // Init
    Vadd4_fp16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd4_fp16_tb_softfloat___024root*>(voidSelf);
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vadd4_fp16_tb_softfloat___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vadd4_fp16_tb_softfloat___024root__trace_chg_0_sub_0(Vadd4_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root__trace_chg_0_sub_0\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_nrst));
        bufp->chgSData(oldp+1,(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a),16);
        bufp->chgSData(oldp+2,(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b),16);
        bufp->chgSData(oldp+3,(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c),16);
        bufp->chgSData(oldp+4,(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d),16);
        bufp->chgSData(oldp+5,(vlSelfRef.add4_fp16_tb_softfloat__DOT__exp),16);
        bufp->chgIData(oldp+6,(vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count),32);
        bufp->chgIData(oldp+7,(vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count),32);
        bufp->chgIData(oldp+8,(vlSelfRef.add4_fp16_tb_softfloat__DOT__fd),32);
        bufp->chgSData(oldp+9,(vlSelfRef.add4_fp16_tb_softfloat__DOT__a),16);
        bufp->chgSData(oldp+10,(vlSelfRef.add4_fp16_tb_softfloat__DOT__b),16);
        bufp->chgSData(oldp+11,(vlSelfRef.add4_fp16_tb_softfloat__DOT__c),16);
        bufp->chgSData(oldp+12,(vlSelfRef.add4_fp16_tb_softfloat__DOT__d),16);
        bufp->chgSData(oldp+13,(vlSelfRef.add4_fp16_tb_softfloat__DOT__expected),16);
        bufp->chgIData(oldp+14,(vlSelfRef.add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__ret),32);
        bufp->chgBit(oldp+15,(vlSelfRef.add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__is_zero_result));
        bufp->chgIData(oldp+16,(vlSelfRef.add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__total_count),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [5U])))) {
        bufp->chgSData(oldp+17,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__a_daz),16);
        bufp->chgSData(oldp+18,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__b_daz),16);
        bufp->chgSData(oldp+19,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__c_daz),16);
        bufp->chgSData(oldp+20,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__d_daz),16);
        bufp->chgCData(oldp+21,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_a),5);
        bufp->chgCData(oldp+22,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_b),5);
        bufp->chgCData(oldp+23,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_c),5);
        bufp->chgCData(oldp+24,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_d),5);
        bufp->chgSData(oldp+25,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_a),10);
        bufp->chgSData(oldp+26,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_b),10);
        bufp->chgSData(oldp+27,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_c),10);
        bufp->chgSData(oldp+28,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_d),10);
        bufp->chgBit(oldp+29,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_a));
        bufp->chgBit(oldp+30,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_b));
        bufp->chgBit(oldp+31,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_c));
        bufp->chgBit(oldp+32,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_d));
        bufp->chgCData(oldp+33,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_p),5);
        bufp->chgCData(oldp+34,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_m),5);
        bufp->chgCData(oldp+35,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_r),5);
        bufp->chgCData(oldp+36,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_n),5);
        bufp->chgCData(oldp+37,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_x),5);
        bufp->chgCData(oldp+38,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_y),5);
        bufp->chgCData(oldp+39,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_mx),5);
        bufp->chgCData(oldp+40,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_nx),5);
        bufp->chgSData(oldp+41,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_p),10);
        bufp->chgSData(oldp+42,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_m),10);
        bufp->chgSData(oldp+43,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_r),10);
        bufp->chgSData(oldp+44,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_n),10);
        bufp->chgSData(oldp+45,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_x),10);
        bufp->chgSData(oldp+46,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_y),10);
        bufp->chgSData(oldp+47,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_mx),10);
        bufp->chgSData(oldp+48,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_nx),10);
        bufp->chgBit(oldp+49,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_p));
        bufp->chgBit(oldp+50,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_m));
        bufp->chgBit(oldp+51,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_r));
        bufp->chgBit(oldp+52,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_n));
        bufp->chgBit(oldp+53,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_x));
        bufp->chgBit(oldp+54,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_y));
        bufp->chgBit(oldp+55,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_mx));
        bufp->chgBit(oldp+56,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_nx));
        bufp->chgCData(oldp+57,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__y_shift),5);
        bufp->chgCData(oldp+58,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__m_shift),5);
        bufp->chgCData(oldp+59,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__n_shift),5);
        bufp->chgSData(oldp+60,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__x_mant),15);
        bufp->chgSData(oldp+61,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__y_shifted),15);
        bufp->chgSData(oldp+62,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__m_shifted),15);
        bufp->chgSData(oldp+63,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__n_shifted),15);
        bufp->chgBit(oldp+64,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__y_op));
        bufp->chgBit(oldp+65,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__m_op));
        bufp->chgBit(oldp+66,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__n_op));
        bufp->chgBit(oldp+67,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_nan_a));
        bufp->chgBit(oldp+68,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_nan_b));
        bufp->chgBit(oldp+69,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_nan_c));
        bufp->chgBit(oldp+70,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_nan_d));
        bufp->chgBit(oldp+71,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_a));
        bufp->chgBit(oldp+72,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_b));
        bufp->chgBit(oldp+73,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_c));
        bufp->chgBit(oldp+74,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_d));
        bufp->chgBit(oldp+75,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__special_case));
        bufp->chgSData(oldp+76,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__special_result),16);
        bufp->chgBit(oldp+77,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__unnamedblk1__DOT__has_pos_inf));
        bufp->chgBit(oldp+78,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__unnamedblk1__DOT__has_neg_inf));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgSData(oldp+79,(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out),16);
        bufp->chgBit(oldp+80,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s));
        bufp->chgBit(oldp+81,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_b_op));
        bufp->chgBit(oldp+82,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_c_op));
        bufp->chgBit(oldp+83,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_d_op));
        bufp->chgCData(oldp+84,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_e),5);
        bufp->chgSData(oldp+85,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f),15);
        bufp->chgSData(oldp+86,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_y_f),15);
        bufp->chgSData(oldp+87,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_m_f),15);
        bufp->chgSData(oldp+88,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_n_f),15);
        bufp->chgBit(oldp+89,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_case));
        bufp->chgSData(oldp+90,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_result),16);
        bufp->chgBit(oldp+91,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special_case));
        bufp->chgSData(oldp+92,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special_result),16);
        bufp->chgSData(oldp+93,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vcellout__second_stage__sum_i),14);
        bufp->chgBit(oldp+94,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__result_s));
        bufp->chgCData(oldp+95,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_e_out),5);
        bufp->chgCData(oldp+96,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__num_leading_zeros),4);
        bufp->chgSData(oldp+97,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum),16);
        bufp->chgBit(oldp+98,((1U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_y_f))));
        bufp->chgBit(oldp+99,((1U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_m_f))));
        bufp->chgBit(oldp+100,((1U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_n_f))));
        bufp->chgSData(oldp+101,((0x1fffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                             >> 1U))),13);
        bufp->chgSData(oldp+102,((0x1fffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_y_f) 
                                             >> 1U))),13);
        bufp->chgSData(oldp+103,((0x1fffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_m_f) 
                                             >> 1U))),13);
        bufp->chgSData(oldp+104,((0x1fffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_n_f) 
                                             >> 1U))),13);
        bufp->chgSData(oldp+105,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT____Vcellout__second_stage__sum_i),13);
        bufp->chgSData(oldp+106,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__b_inv),13);
        bufp->chgSData(oldp+107,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c_inv),13);
        bufp->chgSData(oldp+108,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv),13);
        bufp->chgSData(oldp+109,(((((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__sum) 
                                      << 0xcU) | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__sum) 
                                                  << 0xbU)) 
                                    | (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__sum) 
                                        << 0xaU) | 
                                       ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__sum) 
                                        << 9U))) | 
                                   (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__sum) 
                                     << 8U) | (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__sum) 
                                                << 7U) 
                                               | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__sum) 
                                                  << 6U)))) 
                                  | ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__sum) 
                                       << 5U) | (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__sum) 
                                                  << 4U) 
                                                 | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__sum) 
                                                    << 3U))) 
                                     | (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__sum) 
                                         << 2U) | (
                                                   ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__sum) 
                                                    << 1U) 
                                                   | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__s1__BRA__0__KET__)))))),13);
        bufp->chgSData(oldp+110,(((((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__co) 
                                      << 0xcU) | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__co) 
                                                  << 0xbU)) 
                                    | (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__co) 
                                        << 0xaU) | 
                                       ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__co) 
                                        << 9U))) | 
                                   (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__co) 
                                     << 8U) | (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__co) 
                                                << 7U) 
                                               | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__co) 
                                                  << 6U)))) 
                                  | ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__co) 
                                       << 5U) | (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__co) 
                                                  << 4U) 
                                                 | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__co) 
                                                    << 3U))) 
                                     | (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__co) 
                                         << 2U) | (
                                                   ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__co) 
                                                    << 1U) 
                                                   | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c1__BRA__0__KET__)))))),13);
        bufp->chgSData(oldp+111,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__s2),13);
        bufp->chgSData(oldp+112,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c2),13);
        bufp->chgCData(oldp+113,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__signed_sb_sum),3);
        bufp->chgBit(oldp+114,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__next_result_s));
        bufp->chgCData(oldp+115,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__next_num_leading_zeros),4);
        bufp->chgSData(oldp+116,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__magnitude_sum),15);
        bufp->chgSData(oldp+117,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__corrected_sum),15);
        bufp->chgBit(oldp+118,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                      >> 1U))));
        bufp->chgBit(oldp+119,((1U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__b_inv))));
        bufp->chgBit(oldp+120,((1U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c_inv))));
        bufp->chgBit(oldp+121,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__s1__BRA__0__KET__));
        bufp->chgBit(oldp+122,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c1__BRA__0__KET__));
        bufp->chgBit(oldp+123,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                      >> 0xbU))));
        bufp->chgBit(oldp+124,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__b_inv) 
                                      >> 0xaU))));
        bufp->chgBit(oldp+125,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c_inv) 
                                      >> 0xaU))));
        bufp->chgBit(oldp+126,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__sum));
        bufp->chgBit(oldp+127,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__co));
        bufp->chgBit(oldp+128,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                      >> 0xcU))));
        bufp->chgBit(oldp+129,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__b_inv) 
                                      >> 0xbU))));
        bufp->chgBit(oldp+130,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c_inv) 
                                      >> 0xbU))));
        bufp->chgBit(oldp+131,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__sum));
        bufp->chgBit(oldp+132,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__co));
        bufp->chgBit(oldp+133,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+134,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__b_inv) 
                                      >> 0xcU))));
        bufp->chgBit(oldp+135,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c_inv) 
                                      >> 0xcU))));
        bufp->chgBit(oldp+136,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__sum));
        bufp->chgBit(oldp+137,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__co));
        bufp->chgBit(oldp+138,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                      >> 2U))));
        bufp->chgBit(oldp+139,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__b_inv) 
                                      >> 1U))));
        bufp->chgBit(oldp+140,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c_inv) 
                                      >> 1U))));
        bufp->chgBit(oldp+141,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__sum));
        bufp->chgBit(oldp+142,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__co));
        bufp->chgBit(oldp+143,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                      >> 3U))));
        bufp->chgBit(oldp+144,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__b_inv) 
                                      >> 2U))));
        bufp->chgBit(oldp+145,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c_inv) 
                                      >> 2U))));
        bufp->chgBit(oldp+146,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__sum));
        bufp->chgBit(oldp+147,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__co));
        bufp->chgBit(oldp+148,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                      >> 4U))));
        bufp->chgBit(oldp+149,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__b_inv) 
                                      >> 3U))));
        bufp->chgBit(oldp+150,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c_inv) 
                                      >> 3U))));
        bufp->chgBit(oldp+151,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__sum));
        bufp->chgBit(oldp+152,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__co));
        bufp->chgBit(oldp+153,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                      >> 5U))));
        bufp->chgBit(oldp+154,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__b_inv) 
                                      >> 4U))));
        bufp->chgBit(oldp+155,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c_inv) 
                                      >> 4U))));
        bufp->chgBit(oldp+156,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__sum));
        bufp->chgBit(oldp+157,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__co));
        bufp->chgBit(oldp+158,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                      >> 6U))));
        bufp->chgBit(oldp+159,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__b_inv) 
                                      >> 5U))));
        bufp->chgBit(oldp+160,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c_inv) 
                                      >> 5U))));
        bufp->chgBit(oldp+161,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__sum));
        bufp->chgBit(oldp+162,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__co));
        bufp->chgBit(oldp+163,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                      >> 7U))));
        bufp->chgBit(oldp+164,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__b_inv) 
                                      >> 6U))));
        bufp->chgBit(oldp+165,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c_inv) 
                                      >> 6U))));
        bufp->chgBit(oldp+166,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__sum));
        bufp->chgBit(oldp+167,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__co));
        bufp->chgBit(oldp+168,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                      >> 8U))));
        bufp->chgBit(oldp+169,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__b_inv) 
                                      >> 7U))));
        bufp->chgBit(oldp+170,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c_inv) 
                                      >> 7U))));
        bufp->chgBit(oldp+171,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__sum));
        bufp->chgBit(oldp+172,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__co));
        bufp->chgBit(oldp+173,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                      >> 9U))));
        bufp->chgBit(oldp+174,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__b_inv) 
                                      >> 8U))));
        bufp->chgBit(oldp+175,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c_inv) 
                                      >> 8U))));
        bufp->chgBit(oldp+176,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__sum));
        bufp->chgBit(oldp+177,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__co));
        bufp->chgBit(oldp+178,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                      >> 0xaU))));
        bufp->chgBit(oldp+179,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__b_inv) 
                                      >> 9U))));
        bufp->chgBit(oldp+180,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c_inv) 
                                      >> 9U))));
        bufp->chgBit(oldp+181,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__sum));
        bufp->chgBit(oldp+182,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__co));
        bufp->chgBit(oldp+183,((1U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv))));
        bufp->chgBit(oldp+184,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__s1__BRA__0__KET__) 
                                      ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv)))));
        bufp->chgBit(oldp+185,(((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__s1__BRA__0__KET__) 
                                & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv))));
        bufp->chgBit(oldp+186,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                      >> 0xaU))));
        bufp->chgBit(oldp+187,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__sum) 
                                      ^ (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                          >> 0xaU) 
                                         ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__co))))));
        bufp->chgBit(oldp+188,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__sum) 
                                 & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                    >> 0xaU)) | ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                                   >> 0xaU) 
                                                  | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__sum)) 
                                                 & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__co)))));
        bufp->chgBit(oldp+189,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                      >> 0xbU))));
        bufp->chgBit(oldp+190,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__sum) 
                                      ^ (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                          >> 0xbU) 
                                         ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__co))))));
        bufp->chgBit(oldp+191,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__sum) 
                                 & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                    >> 0xbU)) | ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                                   >> 0xbU) 
                                                  | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__sum)) 
                                                 & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__co)))));
        bufp->chgBit(oldp+192,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                      >> 0xcU))));
        bufp->chgBit(oldp+193,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__sum) 
                                 ^ ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                    >> 0xcU)) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__co))));
        bufp->chgBit(oldp+194,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__sum) 
                                 & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                    >> 0xcU)) | ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                                   >> 0xcU) 
                                                  | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__sum)) 
                                                 & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__co)))));
        bufp->chgBit(oldp+195,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                      >> 1U))));
        bufp->chgBit(oldp+196,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__sum) 
                                      ^ (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                          >> 1U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c1__BRA__0__KET__))))));
        bufp->chgBit(oldp+197,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__sum) 
                                 & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                    >> 1U)) | ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                                 >> 1U) 
                                                | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__sum)) 
                                               & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c1__BRA__0__KET__)))));
        bufp->chgBit(oldp+198,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                      >> 2U))));
        bufp->chgBit(oldp+199,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__sum) 
                                      ^ (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                          >> 2U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__co))))));
        bufp->chgBit(oldp+200,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__sum) 
                                 & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                    >> 2U)) | ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                                 >> 2U) 
                                                | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__sum)) 
                                               & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__co)))));
        bufp->chgBit(oldp+201,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                      >> 3U))));
        bufp->chgBit(oldp+202,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__sum) 
                                      ^ (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                          >> 3U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__co))))));
        bufp->chgBit(oldp+203,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__sum) 
                                 & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                    >> 3U)) | ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                                 >> 3U) 
                                                | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__sum)) 
                                               & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__co)))));
        bufp->chgBit(oldp+204,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                      >> 4U))));
        bufp->chgBit(oldp+205,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__sum) 
                                      ^ (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                          >> 4U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__co))))));
        bufp->chgBit(oldp+206,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__sum) 
                                 & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                    >> 4U)) | ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                                 >> 4U) 
                                                | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__sum)) 
                                               & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__co)))));
        bufp->chgBit(oldp+207,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                      >> 5U))));
        bufp->chgBit(oldp+208,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__sum) 
                                      ^ (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                          >> 5U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__co))))));
        bufp->chgBit(oldp+209,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__sum) 
                                 & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                    >> 5U)) | ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                                 >> 5U) 
                                                | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__sum)) 
                                               & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__co)))));
        bufp->chgBit(oldp+210,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                      >> 6U))));
        bufp->chgBit(oldp+211,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__sum) 
                                      ^ (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                          >> 6U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__co))))));
        bufp->chgBit(oldp+212,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__sum) 
                                 & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                    >> 6U)) | ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                                 >> 6U) 
                                                | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__sum)) 
                                               & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__co)))));
        bufp->chgBit(oldp+213,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                      >> 7U))));
        bufp->chgBit(oldp+214,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__sum) 
                                      ^ (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                          >> 7U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__co))))));
        bufp->chgBit(oldp+215,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__sum) 
                                 & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                    >> 7U)) | ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                                 >> 7U) 
                                                | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__sum)) 
                                               & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__co)))));
        bufp->chgBit(oldp+216,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                      >> 8U))));
        bufp->chgBit(oldp+217,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__sum) 
                                      ^ (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                          >> 8U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__co))))));
        bufp->chgBit(oldp+218,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__sum) 
                                 & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                    >> 8U)) | ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                                 >> 8U) 
                                                | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__sum)) 
                                               & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__co)))));
        bufp->chgBit(oldp+219,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                      >> 9U))));
        bufp->chgBit(oldp+220,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__sum) 
                                      ^ (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                          >> 9U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__co))))));
        bufp->chgBit(oldp+221,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__sum) 
                                 & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                    >> 9U)) | ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__d_inv) 
                                                 >> 9U) 
                                                | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__sum)) 
                                               & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__co)))));
        bufp->chgIData(oldp+222,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__unnamedblk1__DOT__k),32);
        bufp->chgSData(oldp+223,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__shifted_sum),14);
        bufp->chgSData(oldp+224,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__sum_reg),14);
        bufp->chgCData(oldp+225,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__leading_zeros_reg),4);
        bufp->chgBit(oldp+226,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__sign_reg));
        bufp->chgCData(oldp+227,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__exponent_reg),5);
        bufp->chgBit(oldp+228,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__special_case_reg));
        bufp->chgSData(oldp+229,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__special_result_reg),16);
        bufp->chgSData(oldp+230,(((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__special_case_reg)
                                   ? (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__special_result_reg)
                                   : ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__inf)
                                       ? (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__sign_reg) 
                                           << 0xfU) 
                                          | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__new_exponent) 
                                             << 0xaU))
                                       : ((0U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__new_exponent))
                                           ? (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__sign_reg) 
                                               << 0xfU) 
                                              | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__new_exponent) 
                                                 << 0xaU))
                                           : (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__sign_reg) 
                                               << 0xfU) 
                                              | (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__new_exponent) 
                                                  << 0xaU) 
                                                 | ((0x400U 
                                                     & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__rounded_mantissa_internal))
                                                     ? 0U
                                                     : 
                                                    (0x3ffU 
                                                     & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__rounded_mantissa_internal))))))))),16);
        bufp->chgBit(oldp+231,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__rounded_mantissa_internal) 
                                      >> 0xaU))));
        bufp->chgSData(oldp+232,((0x3ffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__shifted_sum) 
                                            >> 4U))),10);
        bufp->chgSData(oldp+233,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__rounded_mantissa_internal),11);
        bufp->chgBit(oldp+234,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__shifted_sum) 
                                      >> 3U))));
        bufp->chgBit(oldp+235,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__shifted_sum) 
                                      >> 2U))));
        bufp->chgBit(oldp+236,((0U != (3U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__shifted_sum)))));
        bufp->chgBit(oldp+237,((IData)((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__shifted_sum) 
                                         >> 3U) & (0U 
                                                   != 
                                                   (0x17U 
                                                    & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__shifted_sum)))))));
        bufp->chgSData(oldp+238,(((0x400U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__rounded_mantissa_internal))
                                   ? 0U : (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__rounded_mantissa_internal)))),10);
        bufp->chgCData(oldp+239,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__new_exponent_internal),7);
        bufp->chgCData(oldp+240,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__new_exponent),5);
        bufp->chgBit(oldp+241,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__inf));
    }
    bufp->chgBit(oldp+242,(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_clk));
}

void Vadd4_fp16_tb_softfloat___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root__trace_cleanup\n"); );
    // Init
    Vadd4_fp16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd4_fp16_tb_softfloat___024root*>(voidSelf);
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
}
