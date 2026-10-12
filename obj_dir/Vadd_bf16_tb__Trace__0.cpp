// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadd_bf16_tb__Syms.h"


void Vadd_bf16_tb___024root__trace_chg_0_sub_0(Vadd_bf16_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vadd_bf16_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root__trace_chg_0\n"); );
    // Init
    Vadd_bf16_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd_bf16_tb___024root*>(voidSelf);
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vadd_bf16_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vadd_bf16_tb___024root__trace_chg_0_sub_0(Vadd_bf16_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root__trace_chg_0_sub_0\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.add_bf16_tb__DOT__tb_nrst));
        bufp->chgSData(oldp+1,(vlSelfRef.add_bf16_tb__DOT__tb_a),16);
        bufp->chgSData(oldp+2,(vlSelfRef.add_bf16_tb__DOT__tb_b),16);
        bufp->chgBit(oldp+3,(vlSelfRef.add_bf16_tb__DOT__tb_sub));
        bufp->chgSData(oldp+4,(vlSelfRef.add_bf16_tb__DOT__A[0]),16);
        bufp->chgSData(oldp+5,(vlSelfRef.add_bf16_tb__DOT__A[1]),16);
        bufp->chgSData(oldp+6,(vlSelfRef.add_bf16_tb__DOT__A[2]),16);
        bufp->chgSData(oldp+7,(vlSelfRef.add_bf16_tb__DOT__A[3]),16);
        bufp->chgSData(oldp+8,(vlSelfRef.add_bf16_tb__DOT__A[4]),16);
        bufp->chgSData(oldp+9,(vlSelfRef.add_bf16_tb__DOT__A[5]),16);
        bufp->chgSData(oldp+10,(vlSelfRef.add_bf16_tb__DOT__A[6]),16);
        bufp->chgSData(oldp+11,(vlSelfRef.add_bf16_tb__DOT__A[7]),16);
        bufp->chgSData(oldp+12,(vlSelfRef.add_bf16_tb__DOT__A[8]),16);
        bufp->chgSData(oldp+13,(vlSelfRef.add_bf16_tb__DOT__A[9]),16);
        bufp->chgSData(oldp+14,(vlSelfRef.add_bf16_tb__DOT__A[10]),16);
        bufp->chgSData(oldp+15,(vlSelfRef.add_bf16_tb__DOT__A[11]),16);
        bufp->chgSData(oldp+16,(vlSelfRef.add_bf16_tb__DOT__A[12]),16);
        bufp->chgSData(oldp+17,(vlSelfRef.add_bf16_tb__DOT__A[13]),16);
        bufp->chgSData(oldp+18,(vlSelfRef.add_bf16_tb__DOT__A[14]),16);
        bufp->chgSData(oldp+19,(vlSelfRef.add_bf16_tb__DOT__A[15]),16);
        bufp->chgSData(oldp+20,(vlSelfRef.add_bf16_tb__DOT__A[16]),16);
        bufp->chgSData(oldp+21,(vlSelfRef.add_bf16_tb__DOT__A[17]),16);
        bufp->chgSData(oldp+22,(vlSelfRef.add_bf16_tb__DOT__A[18]),16);
        bufp->chgSData(oldp+23,(vlSelfRef.add_bf16_tb__DOT__A[19]),16);
        bufp->chgSData(oldp+24,(vlSelfRef.add_bf16_tb__DOT__A[20]),16);
        bufp->chgSData(oldp+25,(vlSelfRef.add_bf16_tb__DOT__A[21]),16);
        bufp->chgSData(oldp+26,(vlSelfRef.add_bf16_tb__DOT__A[22]),16);
        bufp->chgSData(oldp+27,(vlSelfRef.add_bf16_tb__DOT__A[23]),16);
        bufp->chgSData(oldp+28,(vlSelfRef.add_bf16_tb__DOT__A[24]),16);
        bufp->chgSData(oldp+29,(vlSelfRef.add_bf16_tb__DOT__B[0]),16);
        bufp->chgSData(oldp+30,(vlSelfRef.add_bf16_tb__DOT__B[1]),16);
        bufp->chgSData(oldp+31,(vlSelfRef.add_bf16_tb__DOT__B[2]),16);
        bufp->chgSData(oldp+32,(vlSelfRef.add_bf16_tb__DOT__B[3]),16);
        bufp->chgSData(oldp+33,(vlSelfRef.add_bf16_tb__DOT__B[4]),16);
        bufp->chgSData(oldp+34,(vlSelfRef.add_bf16_tb__DOT__B[5]),16);
        bufp->chgSData(oldp+35,(vlSelfRef.add_bf16_tb__DOT__B[6]),16);
        bufp->chgSData(oldp+36,(vlSelfRef.add_bf16_tb__DOT__B[7]),16);
        bufp->chgSData(oldp+37,(vlSelfRef.add_bf16_tb__DOT__B[8]),16);
        bufp->chgSData(oldp+38,(vlSelfRef.add_bf16_tb__DOT__B[9]),16);
        bufp->chgSData(oldp+39,(vlSelfRef.add_bf16_tb__DOT__B[10]),16);
        bufp->chgSData(oldp+40,(vlSelfRef.add_bf16_tb__DOT__B[11]),16);
        bufp->chgSData(oldp+41,(vlSelfRef.add_bf16_tb__DOT__B[12]),16);
        bufp->chgSData(oldp+42,(vlSelfRef.add_bf16_tb__DOT__B[13]),16);
        bufp->chgSData(oldp+43,(vlSelfRef.add_bf16_tb__DOT__B[14]),16);
        bufp->chgSData(oldp+44,(vlSelfRef.add_bf16_tb__DOT__B[15]),16);
        bufp->chgSData(oldp+45,(vlSelfRef.add_bf16_tb__DOT__B[16]),16);
        bufp->chgSData(oldp+46,(vlSelfRef.add_bf16_tb__DOT__B[17]),16);
        bufp->chgSData(oldp+47,(vlSelfRef.add_bf16_tb__DOT__B[18]),16);
        bufp->chgSData(oldp+48,(vlSelfRef.add_bf16_tb__DOT__B[19]),16);
        bufp->chgSData(oldp+49,(vlSelfRef.add_bf16_tb__DOT__B[20]),16);
        bufp->chgSData(oldp+50,(vlSelfRef.add_bf16_tb__DOT__B[21]),16);
        bufp->chgSData(oldp+51,(vlSelfRef.add_bf16_tb__DOT__B[22]),16);
        bufp->chgSData(oldp+52,(vlSelfRef.add_bf16_tb__DOT__B[23]),16);
        bufp->chgSData(oldp+53,(vlSelfRef.add_bf16_tb__DOT__B[24]),16);
        bufp->chgSData(oldp+54,(vlSelfRef.add_bf16_tb__DOT__EXP[0]),16);
        bufp->chgSData(oldp+55,(vlSelfRef.add_bf16_tb__DOT__EXP[1]),16);
        bufp->chgSData(oldp+56,(vlSelfRef.add_bf16_tb__DOT__EXP[2]),16);
        bufp->chgSData(oldp+57,(vlSelfRef.add_bf16_tb__DOT__EXP[3]),16);
        bufp->chgSData(oldp+58,(vlSelfRef.add_bf16_tb__DOT__EXP[4]),16);
        bufp->chgSData(oldp+59,(vlSelfRef.add_bf16_tb__DOT__EXP[5]),16);
        bufp->chgSData(oldp+60,(vlSelfRef.add_bf16_tb__DOT__EXP[6]),16);
        bufp->chgSData(oldp+61,(vlSelfRef.add_bf16_tb__DOT__EXP[7]),16);
        bufp->chgSData(oldp+62,(vlSelfRef.add_bf16_tb__DOT__EXP[8]),16);
        bufp->chgSData(oldp+63,(vlSelfRef.add_bf16_tb__DOT__EXP[9]),16);
        bufp->chgSData(oldp+64,(vlSelfRef.add_bf16_tb__DOT__EXP[10]),16);
        bufp->chgSData(oldp+65,(vlSelfRef.add_bf16_tb__DOT__EXP[11]),16);
        bufp->chgSData(oldp+66,(vlSelfRef.add_bf16_tb__DOT__EXP[12]),16);
        bufp->chgSData(oldp+67,(vlSelfRef.add_bf16_tb__DOT__EXP[13]),16);
        bufp->chgSData(oldp+68,(vlSelfRef.add_bf16_tb__DOT__EXP[14]),16);
        bufp->chgSData(oldp+69,(vlSelfRef.add_bf16_tb__DOT__EXP[15]),16);
        bufp->chgSData(oldp+70,(vlSelfRef.add_bf16_tb__DOT__EXP[16]),16);
        bufp->chgSData(oldp+71,(vlSelfRef.add_bf16_tb__DOT__EXP[17]),16);
        bufp->chgSData(oldp+72,(vlSelfRef.add_bf16_tb__DOT__EXP[18]),16);
        bufp->chgSData(oldp+73,(vlSelfRef.add_bf16_tb__DOT__EXP[19]),16);
        bufp->chgSData(oldp+74,(vlSelfRef.add_bf16_tb__DOT__EXP[20]),16);
        bufp->chgSData(oldp+75,(vlSelfRef.add_bf16_tb__DOT__EXP[21]),16);
        bufp->chgSData(oldp+76,(vlSelfRef.add_bf16_tb__DOT__EXP[22]),16);
        bufp->chgSData(oldp+77,(vlSelfRef.add_bf16_tb__DOT__EXP[23]),16);
        bufp->chgSData(oldp+78,(vlSelfRef.add_bf16_tb__DOT__EXP[24]),16);
        bufp->chgIData(oldp+79,(vlSelfRef.add_bf16_tb__DOT__idx),32);
        bufp->chgIData(oldp+80,(vlSelfRef.add_bf16_tb__DOT__i),32);
        bufp->chgIData(oldp+81,(vlSelfRef.add_bf16_tb__DOT__fd),32);
        bufp->chgSData(oldp+82,(vlSelfRef.add_bf16_tb__DOT__csv_a),16);
        bufp->chgSData(oldp+83,(vlSelfRef.add_bf16_tb__DOT__csv_b),16);
        bufp->chgSData(oldp+84,(vlSelfRef.add_bf16_tb__DOT__csv_exp),16);
        bufp->chgIData(oldp+85,(vlSelfRef.add_bf16_tb__DOT__csv_sub_i),32);
        bufp->chgBit(oldp+86,(vlSelfRef.add_bf16_tb__DOT__csv_sub));
        bufp->chgIData(oldp+87,(vlSelfRef.add_bf16_tb__DOT__pass_cnt),32);
        bufp->chgIData(oldp+88,(vlSelfRef.add_bf16_tb__DOT__fail_cnt),32);
        bufp->chgBit(oldp+89,((0U != (0xffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                                               >> 7U)))));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [5U])))) {
        bufp->chgBit(oldp+90,(vlSelfRef.add_bf16_tb__DOT__tb_invalid));
        bufp->chgSData(oldp+91,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff),16);
        bufp->chgBit(oldp+92,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_nan1));
        bufp->chgBit(oldp+93,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_nan2));
        bufp->chgBit(oldp+94,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_inf1));
        bufp->chgBit(oldp+95,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_inf2));
        bufp->chgCData(oldp+96,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__smaller_exponent),8);
        bufp->chgCData(oldp+97,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_exponent),8);
        bufp->chgBit(oldp+98,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_select));
        bufp->chgBit(oldp+99,((0U != (0xffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff) 
                                               >> 7U)))));
        bufp->chgCData(oldp+100,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_diff),8);
        bufp->chgCData(oldp+101,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_max),8);
        bufp->chgSData(oldp+102,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__frac_shifted),10);
        bufp->chgSData(oldp+103,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__frac_not_shifted),10);
        bufp->chgBit(oldp+104,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_shifted));
        bufp->chgBit(oldp+105,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_not_shifted));
        bufp->chgSData(oldp+106,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__smaller_mantissa),10);
        bufp->chgSData(oldp+107,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa),10);
        bufp->chgBit(oldp+108,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa_sign));
        bufp->chgBit(oldp+109,(((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_shifted) 
                                ^ (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_not_shifted))));
        bufp->chgSData(oldp+110,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__xor_out),9);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgBit(oldp+111,(((0xffU == (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_max_l)) 
                                | ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__mantissa_overflow) 
                                   & (0xfeU == (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_max_l))))));
        bufp->chgBit(oldp+112,(((0U == (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__u_result)) 
                                | ((~ ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__u_result) 
                                       >> 7U)) & (0U 
                                                  != 
                                                  (3U 
                                                   & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__u_result) 
                                                      >> 6U)))))));
        bufp->chgSData(oldp+113,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__mantissa_sum),11);
        bufp->chgBit(oldp+114,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__mantissa_overflow));
        bufp->chgSData(oldp+115,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__smaller_mantissa_l),10);
        bufp->chgSData(oldp+116,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa_l),10);
        bufp->chgBit(oldp+117,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa_sign_l));
        bufp->chgBit(oldp+118,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_shifted_l));
        bufp->chgBit(oldp+119,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_not_shifted_l));
        bufp->chgBit(oldp+120,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__signs_differ_l));
        bufp->chgCData(oldp+121,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_max_l),8);
        bufp->chgCData(oldp+122,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__u_result),8);
        bufp->chgSData(oldp+123,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__normalized_mantissa_sum),9);
        bufp->chgCData(oldp+124,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__norm_shift),4);
        bufp->chgCData(oldp+125,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__u_exp1),8);
        bufp->chgCData(oldp+126,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__u_shifted_amount),8);
        bufp->chgSData(oldp+127,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__round_this),9);
        bufp->chgCData(oldp+128,((0xffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__mantissa_overflow)
                                            ? ((IData)(1U) 
                                               + (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_max_l))
                                            : (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__u_result)))),8);
        bufp->chgBit(oldp+129,((1U & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__round_this) 
                                      >> 1U))));
        bufp->chgBit(oldp+130,((1U & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__round_this))));
        bufp->chgSData(oldp+131,((0x3ffU & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__mantissa_sum))),10);
    }
    bufp->chgBit(oldp+132,(vlSelfRef.add_bf16_tb__DOT__tb_clk));
    bufp->chgSData(oldp+133,(((((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_inf1) 
                                & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_inf2)) 
                               & (((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                                   ^ (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff)) 
                                  >> 0xfU)) ? 0x7fc0U
                               : ((((IData)((0x7f7fU 
                                             == (0x7fffU 
                                                 & (IData)(vlSelfRef.add_bf16_tb__DOT__tb_a)))) 
                                    & (0U != (0x7fffU 
                                              & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff)))) 
                                   | (((IData)((0x7f7fU 
                                                == 
                                                (0x7fffU 
                                                 & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff)))) 
                                       & (0U != (0x7fffU 
                                                 & (IData)(vlSelfRef.add_bf16_tb__DOT__tb_a)))) 
                                      & (~ (((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                                             ^ (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff)) 
                                            >> 0xfU))))
                                   ? ((0x8000U & (IData)(vlSelfRef.add_bf16_tb__DOT__tb_a))
                                       ? 0xff80U : 0x7f80U)
                                   : (((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_inf1) 
                                       | (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_nan1))
                                       ? (IData)(vlSelfRef.add_bf16_tb__DOT__tb_a)
                                       : (((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_inf2) 
                                           | (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_nan2))
                                           ? (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff)
                                           : ((IData)(
                                                      (((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__xor_out) 
                                                        >> 8U) 
                                                       & (~ (IData)(
                                                                    (0U 
                                                                     != 
                                                                     (0xffU 
                                                                      & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__xor_out)))))))
                                               ? 0U
                                               : (((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__result_sign) 
                                                   << 0xfU) 
                                                  | (((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_out_adj) 
                                                      << 7U) 
                                                     | (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__rounded_fraction))))))))),16);
    bufp->chgBit(oldp+134,(((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_select)
                             ? (0U != ((((0U != (0xffU 
                                                 & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff) 
                                                    >> 7U))) 
                                         << 9U) | (0x1fcU 
                                                   & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff) 
                                                      << 2U))) 
                                       & (VL_SHIFTL_III(32,32,8, (IData)(1U), (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_diff)) 
                                          - (IData)(1U))))
                             : (0U != ((((0U != (0xffU 
                                                 & ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                                                    >> 7U))) 
                                         << 9U) | (0x1fcU 
                                                   & ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                                                      << 2U))) 
                                       & (VL_SHIFTL_III(32,32,8, (IData)(1U), (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_diff)) 
                                          - (IData)(1U)))))));
    bufp->chgBit(oldp+135,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__result_sign));
    bufp->chgCData(oldp+136,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__rounded_fraction),7);
    bufp->chgCData(oldp+137,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_out_adj),8);
    bufp->chgCData(oldp+138,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__round_sum),8);
}

void Vadd_bf16_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root__trace_cleanup\n"); );
    // Init
    Vadd_bf16_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd_bf16_tb___024root*>(voidSelf);
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
}
