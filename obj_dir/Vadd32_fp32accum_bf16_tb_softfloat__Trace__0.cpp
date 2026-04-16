// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vadd32_fp32accum_bf16_tb_softfloat__Syms.h"


void Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_0_sub_0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_0\n"); );
    // Body
    Vadd32_fp32accum_bf16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd32_fp32accum_bf16_tb_softfloat___024root*>(voidSelf);
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_0_sub_0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_0_sub_0\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity[1U] 
                       | vlSelfRef.__Vm_traceActivity[2U]) 
                      | vlSelfRef.__Vm_traceActivity[3U])))) {
        bufp->chgIData(oldp+0,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__total_processed),32);
        bufp->chgIData(oldp+1,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__fd),32);
        bufp->chgIData(oldp+2,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__ret),32);
        bufp->chgWData(oldp+3,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                               .__PVT__inputs),512);
        bufp->chgSData(oldp+19,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                                .__PVT__expected),16);
        bufp->chgIData(oldp+20,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                                .__PVT__id),32);
        bufp->chgSData(oldp+21,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[0]),16);
        bufp->chgSData(oldp+22,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[1]),16);
        bufp->chgSData(oldp+23,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[2]),16);
        bufp->chgSData(oldp+24,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[3]),16);
        bufp->chgSData(oldp+25,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[4]),16);
        bufp->chgSData(oldp+26,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[5]),16);
        bufp->chgSData(oldp+27,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[6]),16);
        bufp->chgSData(oldp+28,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[7]),16);
        bufp->chgSData(oldp+29,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[8]),16);
        bufp->chgSData(oldp+30,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[9]),16);
        bufp->chgSData(oldp+31,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[10]),16);
        bufp->chgSData(oldp+32,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[11]),16);
        bufp->chgSData(oldp+33,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[12]),16);
        bufp->chgSData(oldp+34,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[13]),16);
        bufp->chgSData(oldp+35,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[14]),16);
        bufp->chgSData(oldp+36,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[15]),16);
        bufp->chgSData(oldp+37,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[16]),16);
        bufp->chgSData(oldp+38,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[17]),16);
        bufp->chgSData(oldp+39,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[18]),16);
        bufp->chgSData(oldp+40,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[19]),16);
        bufp->chgSData(oldp+41,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[20]),16);
        bufp->chgSData(oldp+42,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[21]),16);
        bufp->chgSData(oldp+43,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[22]),16);
        bufp->chgSData(oldp+44,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[23]),16);
        bufp->chgSData(oldp+45,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[24]),16);
        bufp->chgSData(oldp+46,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[25]),16);
        bufp->chgSData(oldp+47,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[26]),16);
        bufp->chgSData(oldp+48,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[27]),16);
        bufp->chgSData(oldp+49,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[28]),16);
        bufp->chgSData(oldp+50,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[29]),16);
        bufp->chgSData(oldp+51,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[30]),16);
        bufp->chgSData(oldp+52,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs[31]),16);
        bufp->chgSData(oldp+53,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_expected),16);
    }
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity[1U] 
                       | vlSelfRef.__Vm_traceActivity[2U]) 
                      | vlSelfRef.__Vm_traceActivity[4U])))) {
        bufp->chgWData(oldp+54,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                .__PVT__inputs),512);
        bufp->chgSData(oldp+70,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                .__PVT__expected),16);
        bufp->chgIData(oldp+71,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                .__PVT__id),32);
        bufp->chgQData(oldp+72,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__ulp),64);
        bufp->chgBit(oldp+74,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__match));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[2U] 
                      | vlSelfRef.__Vm_traceActivity[3U])))) {
        bufp->chgBit(oldp+75,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst));
        bufp->chgIData(oldp+76,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd),32);
        bufp->chgWData(oldp+77,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs),512);
        bufp->chgSData(oldp+93,((0x0000ffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[14U])),16);
        bufp->chgSData(oldp+94,((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[14U] 
                                 >> 0x00000010U)),16);
        bufp->chgSData(oldp+95,((0x0000ffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[15U])),16);
        bufp->chgSData(oldp+96,((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[15U] 
                                 >> 0x00000010U)),16);
        bufp->chgSData(oldp+97,((0x0000ffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[12U])),16);
        bufp->chgSData(oldp+98,((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[12U] 
                                 >> 0x00000010U)),16);
        bufp->chgSData(oldp+99,((0x0000ffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[13U])),16);
        bufp->chgSData(oldp+100,((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[13U] 
                                  >> 0x00000010U)),16);
        bufp->chgSData(oldp+101,((0x0000ffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[10U])),16);
        bufp->chgSData(oldp+102,((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[10U] 
                                  >> 0x00000010U)),16);
        bufp->chgSData(oldp+103,((0x0000ffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[11U])),16);
        bufp->chgSData(oldp+104,((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[11U] 
                                  >> 0x00000010U)),16);
        bufp->chgSData(oldp+105,((0x0000ffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[8U])),16);
        bufp->chgSData(oldp+106,((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[8U] 
                                  >> 0x00000010U)),16);
        bufp->chgSData(oldp+107,((0x0000ffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[9U])),16);
        bufp->chgSData(oldp+108,((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[9U] 
                                  >> 0x00000010U)),16);
        bufp->chgSData(oldp+109,((0x0000ffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[6U])),16);
        bufp->chgSData(oldp+110,((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[6U] 
                                  >> 0x00000010U)),16);
        bufp->chgSData(oldp+111,((0x0000ffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[7U])),16);
        bufp->chgSData(oldp+112,((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[7U] 
                                  >> 0x00000010U)),16);
        bufp->chgSData(oldp+113,((0x0000ffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[4U])),16);
        bufp->chgSData(oldp+114,((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[4U] 
                                  >> 0x00000010U)),16);
        bufp->chgSData(oldp+115,((0x0000ffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[5U])),16);
        bufp->chgSData(oldp+116,((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[5U] 
                                  >> 0x00000010U)),16);
        bufp->chgSData(oldp+117,((0x0000ffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[2U])),16);
        bufp->chgSData(oldp+118,((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[2U] 
                                  >> 0x00000010U)),16);
        bufp->chgSData(oldp+119,((0x0000ffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[3U])),16);
        bufp->chgSData(oldp+120,((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[3U] 
                                  >> 0x00000010U)),16);
        bufp->chgSData(oldp+121,((0x0000ffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0U])),16);
        bufp->chgSData(oldp+122,((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0U] 
                                  >> 0x00000010U)),16);
        bufp->chgSData(oldp+123,((0x0000ffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[1U])),16);
        bufp->chgSData(oldp+124,((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[1U] 
                                  >> 0x00000010U)),16);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[2U] 
                      | vlSelfRef.__Vm_traceActivity[4U])))) {
        bufp->chgIData(oldp+125,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__pass_count),32);
        bufp->chgIData(oldp+126,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_count),32);
        bufp->chgQData(oldp+127,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff),64);
        bufp->chgIData(oldp+129,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count),32);
        bufp->chgIData(oldp+130,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__largest_ulp),32);
        bufp->chgDouble(oldp+131,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__total_num_diff));
        bufp->chgDouble(oldp+133,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__largest_num_diff));
        bufp->chgDouble(oldp+135,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__num_diff));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[5U] 
                      | vlSelfRef.__Vm_traceActivity[21U])))) {
        bufp->chgSData(oldp+137,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__a_daz),16);
        bufp->chgSData(oldp+138,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__b_daz),16);
        bufp->chgSData(oldp+139,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__c_daz),16);
        bufp->chgSData(oldp+140,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__d_daz),16);
        bufp->chgCData(oldp+141,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a),8);
        bufp->chgCData(oldp+142,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b),8);
        bufp->chgCData(oldp+143,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c),8);
        bufp->chgCData(oldp+144,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d),8);
        bufp->chgCData(oldp+145,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_a),7);
        bufp->chgCData(oldp+146,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_b),7);
        bufp->chgCData(oldp+147,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_c),7);
        bufp->chgCData(oldp+148,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_d),7);
        bufp->chgBit(oldp+149,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_a));
        bufp->chgBit(oldp+150,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_b));
        bufp->chgBit(oldp+151,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_c));
        bufp->chgBit(oldp+152,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_d));
        bufp->chgCData(oldp+153,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_p),8);
        bufp->chgCData(oldp+154,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_m),8);
        bufp->chgCData(oldp+155,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_r),8);
        bufp->chgCData(oldp+156,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_n),8);
        bufp->chgCData(oldp+157,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x),8);
        bufp->chgCData(oldp+158,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y),8);
        bufp->chgCData(oldp+159,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx),8);
        bufp->chgCData(oldp+160,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx),8);
        bufp->chgCData(oldp+161,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_p),7);
        bufp->chgCData(oldp+162,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_m),7);
        bufp->chgCData(oldp+163,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_r),7);
        bufp->chgCData(oldp+164,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_n),7);
        bufp->chgCData(oldp+165,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_x),7);
        bufp->chgCData(oldp+166,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_y),7);
        bufp->chgCData(oldp+167,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_mx),7);
        bufp->chgCData(oldp+168,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_nx),7);
        bufp->chgBit(oldp+169,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_p));
        bufp->chgBit(oldp+170,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_m));
        bufp->chgBit(oldp+171,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_r));
        bufp->chgBit(oldp+172,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_n));
        bufp->chgBit(oldp+173,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_x));
        bufp->chgBit(oldp+174,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_y));
        bufp->chgBit(oldp+175,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_mx));
        bufp->chgBit(oldp+176,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_nx));
        bufp->chgCData(oldp+177,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x_eff),8);
        bufp->chgCData(oldp+178,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y_eff),8);
        bufp->chgCData(oldp+179,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx_eff),8);
        bufp->chgCData(oldp+180,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx_eff),8);
        bufp->chgSData(oldp+181,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shift),9);
        bufp->chgSData(oldp+182,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shift),9);
        bufp->chgSData(oldp+183,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shift),9);
        bufp->chgQData(oldp+184,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__x_mant),34);
        bufp->chgQData(oldp+186,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted),34);
        bufp->chgQData(oldp+188,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted),34);
        bufp->chgQData(oldp+190,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted),34);
        bufp->chgQData(oldp+192,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_mant_base),34);
        bufp->chgQData(oldp+194,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_mant_base),34);
        bufp->chgQData(oldp+196,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_mant_base),34);
        bufp->chgCData(oldp+198,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_y),2);
        bufp->chgCData(oldp+199,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_m),2);
        bufp->chgCData(oldp+200,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_n),2);
        bufp->chgBit(oldp+201,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_sticky_nonzero));
        bufp->chgBit(oldp+202,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_sticky_nonzero));
    }
}

void Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_1_sub_0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_1(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_1\n"); );
    // Body
    Vadd32_fp32accum_bf16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd32_fp32accum_bf16_tb_softfloat___024root*>(voidSelf);
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_1_sub_0((&vlSymsp->TOP), bufp);
}

void Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_1_sub_0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_1_sub_0\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 203);
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[5U] 
                      | vlSelfRef.__Vm_traceActivity[21U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_sticky_nonzero));
        bufp->chgBit(oldp+1,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__ym_mismatch));
        bufp->chgBit(oldp+2,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__yn_mismatch));
        bufp->chgBit(oldp+3,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__mn_mismatch));
        bufp->chgBit(oldp+4,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_mismatch));
        bufp->chgBit(oldp+5,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_nonzero));
        bufp->chgBit(oldp+6,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_op));
        bufp->chgBit(oldp+7,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_op));
        bufp->chgBit(oldp+8,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_op));
        bufp->chgBit(oldp+9,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__is_nan_any));
        bufp->chgBit(oldp+10,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_case));
        bufp->chgBit(oldp+11,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_pos_inf));
        bufp->chgBit(oldp+12,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_neg_inf));
        bufp->chgIData(oldp+13,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_result),32);
        bufp->chgCData(oldp+14,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_align_sticky_n),2);
        bufp->chgQData(oldp+15,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x),37);
        bufp->chgQData(oldp+17,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y),37);
        bufp->chgQData(oldp+19,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m),37);
        bufp->chgQData(oldp+21,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n),37);
        bufp->chgQData(oldp+23,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1),37);
        bufp->chgQData(oldp+25,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c1),37);
        bufp->chgQData(oldp+27,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s2),37);
        bufp->chgQData(oldp+29,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c2),37);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[5U] 
                      | vlSelfRef.__Vm_traceActivity[22U])))) {
        bufp->chgSData(oldp+31,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__a_daz),16);
        bufp->chgSData(oldp+32,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__b_daz),16);
        bufp->chgSData(oldp+33,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__c_daz),16);
        bufp->chgSData(oldp+34,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__d_daz),16);
        bufp->chgCData(oldp+35,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a),8);
        bufp->chgCData(oldp+36,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b),8);
        bufp->chgCData(oldp+37,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c),8);
        bufp->chgCData(oldp+38,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d),8);
        bufp->chgCData(oldp+39,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_a),7);
        bufp->chgCData(oldp+40,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_b),7);
        bufp->chgCData(oldp+41,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_c),7);
        bufp->chgCData(oldp+42,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_d),7);
        bufp->chgBit(oldp+43,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_a));
        bufp->chgBit(oldp+44,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_b));
        bufp->chgBit(oldp+45,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_c));
        bufp->chgBit(oldp+46,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_d));
        bufp->chgCData(oldp+47,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_p),8);
        bufp->chgCData(oldp+48,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_m),8);
        bufp->chgCData(oldp+49,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_r),8);
        bufp->chgCData(oldp+50,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_n),8);
        bufp->chgCData(oldp+51,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x),8);
        bufp->chgCData(oldp+52,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y),8);
        bufp->chgCData(oldp+53,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx),8);
        bufp->chgCData(oldp+54,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx),8);
        bufp->chgCData(oldp+55,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_p),7);
        bufp->chgCData(oldp+56,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_m),7);
        bufp->chgCData(oldp+57,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_r),7);
        bufp->chgCData(oldp+58,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_n),7);
        bufp->chgCData(oldp+59,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_x),7);
        bufp->chgCData(oldp+60,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_y),7);
        bufp->chgCData(oldp+61,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_mx),7);
        bufp->chgCData(oldp+62,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_nx),7);
        bufp->chgBit(oldp+63,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_p));
        bufp->chgBit(oldp+64,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_m));
        bufp->chgBit(oldp+65,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_r));
        bufp->chgBit(oldp+66,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_n));
        bufp->chgBit(oldp+67,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_x));
        bufp->chgBit(oldp+68,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_y));
        bufp->chgBit(oldp+69,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_mx));
        bufp->chgBit(oldp+70,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_nx));
        bufp->chgCData(oldp+71,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x_eff),8);
        bufp->chgCData(oldp+72,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y_eff),8);
        bufp->chgCData(oldp+73,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx_eff),8);
        bufp->chgCData(oldp+74,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx_eff),8);
        bufp->chgSData(oldp+75,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shift),9);
        bufp->chgSData(oldp+76,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shift),9);
        bufp->chgSData(oldp+77,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shift),9);
        bufp->chgQData(oldp+78,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__x_mant),34);
        bufp->chgQData(oldp+80,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted),34);
        bufp->chgQData(oldp+82,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted),34);
        bufp->chgQData(oldp+84,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted),34);
        bufp->chgQData(oldp+86,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_mant_base),34);
        bufp->chgQData(oldp+88,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_mant_base),34);
        bufp->chgQData(oldp+90,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_mant_base),34);
        bufp->chgCData(oldp+92,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_y),2);
        bufp->chgCData(oldp+93,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_m),2);
        bufp->chgCData(oldp+94,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_n),2);
        bufp->chgBit(oldp+95,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_sticky_nonzero));
        bufp->chgBit(oldp+96,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_sticky_nonzero));
        bufp->chgBit(oldp+97,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_sticky_nonzero));
        bufp->chgBit(oldp+98,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__ym_mismatch));
        bufp->chgBit(oldp+99,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__yn_mismatch));
        bufp->chgBit(oldp+100,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__mn_mismatch));
        bufp->chgBit(oldp+101,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_mismatch));
        bufp->chgBit(oldp+102,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_nonzero));
        bufp->chgBit(oldp+103,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_op));
        bufp->chgBit(oldp+104,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_op));
        bufp->chgBit(oldp+105,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_op));
        bufp->chgBit(oldp+106,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__is_nan_any));
        bufp->chgBit(oldp+107,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_case));
        bufp->chgBit(oldp+108,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_pos_inf));
        bufp->chgBit(oldp+109,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_neg_inf));
        bufp->chgIData(oldp+110,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_result),32);
        bufp->chgCData(oldp+111,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_align_sticky_n),2);
        bufp->chgQData(oldp+112,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x),37);
        bufp->chgQData(oldp+114,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y),37);
        bufp->chgQData(oldp+116,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m),37);
        bufp->chgQData(oldp+118,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n),37);
        bufp->chgQData(oldp+120,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1),37);
        bufp->chgQData(oldp+122,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c1),37);
        bufp->chgQData(oldp+124,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s2),37);
        bufp->chgQData(oldp+126,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c2),37);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[5U] 
                      | vlSelfRef.__Vm_traceActivity[23U])))) {
        bufp->chgSData(oldp+128,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__a_daz),16);
        bufp->chgSData(oldp+129,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__b_daz),16);
        bufp->chgSData(oldp+130,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__c_daz),16);
        bufp->chgSData(oldp+131,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__d_daz),16);
        bufp->chgCData(oldp+132,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a),8);
        bufp->chgCData(oldp+133,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b),8);
        bufp->chgCData(oldp+134,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c),8);
        bufp->chgCData(oldp+135,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d),8);
        bufp->chgCData(oldp+136,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_a),7);
        bufp->chgCData(oldp+137,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_b),7);
        bufp->chgCData(oldp+138,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_c),7);
        bufp->chgCData(oldp+139,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_d),7);
        bufp->chgBit(oldp+140,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_a));
        bufp->chgBit(oldp+141,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_b));
        bufp->chgBit(oldp+142,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_c));
        bufp->chgBit(oldp+143,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_d));
        bufp->chgCData(oldp+144,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_p),8);
        bufp->chgCData(oldp+145,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_m),8);
        bufp->chgCData(oldp+146,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_r),8);
        bufp->chgCData(oldp+147,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_n),8);
        bufp->chgCData(oldp+148,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x),8);
        bufp->chgCData(oldp+149,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y),8);
        bufp->chgCData(oldp+150,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx),8);
        bufp->chgCData(oldp+151,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx),8);
        bufp->chgCData(oldp+152,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_p),7);
        bufp->chgCData(oldp+153,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_m),7);
        bufp->chgCData(oldp+154,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_r),7);
        bufp->chgCData(oldp+155,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_n),7);
        bufp->chgCData(oldp+156,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_x),7);
        bufp->chgCData(oldp+157,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_y),7);
        bufp->chgCData(oldp+158,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_mx),7);
        bufp->chgCData(oldp+159,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_nx),7);
        bufp->chgBit(oldp+160,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_p));
        bufp->chgBit(oldp+161,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_m));
        bufp->chgBit(oldp+162,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_r));
        bufp->chgBit(oldp+163,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_n));
        bufp->chgBit(oldp+164,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_x));
        bufp->chgBit(oldp+165,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_y));
        bufp->chgBit(oldp+166,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_mx));
        bufp->chgBit(oldp+167,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_nx));
        bufp->chgCData(oldp+168,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x_eff),8);
        bufp->chgCData(oldp+169,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y_eff),8);
        bufp->chgCData(oldp+170,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx_eff),8);
        bufp->chgCData(oldp+171,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx_eff),8);
        bufp->chgSData(oldp+172,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shift),9);
        bufp->chgSData(oldp+173,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shift),9);
        bufp->chgSData(oldp+174,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shift),9);
        bufp->chgQData(oldp+175,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__x_mant),34);
        bufp->chgQData(oldp+177,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted),34);
        bufp->chgQData(oldp+179,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted),34);
        bufp->chgQData(oldp+181,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted),34);
        bufp->chgQData(oldp+183,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_mant_base),34);
        bufp->chgQData(oldp+185,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_mant_base),34);
        bufp->chgQData(oldp+187,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_mant_base),34);
        bufp->chgCData(oldp+189,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_y),2);
        bufp->chgCData(oldp+190,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_m),2);
        bufp->chgCData(oldp+191,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_n),2);
        bufp->chgBit(oldp+192,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_sticky_nonzero));
        bufp->chgBit(oldp+193,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_sticky_nonzero));
        bufp->chgBit(oldp+194,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_sticky_nonzero));
        bufp->chgBit(oldp+195,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__ym_mismatch));
        bufp->chgBit(oldp+196,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__yn_mismatch));
        bufp->chgBit(oldp+197,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__mn_mismatch));
        bufp->chgBit(oldp+198,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_mismatch));
        bufp->chgBit(oldp+199,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_nonzero));
        bufp->chgBit(oldp+200,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_op));
        bufp->chgBit(oldp+201,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_op));
        bufp->chgBit(oldp+202,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_op));
    }
}

void Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_2_sub_0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_2(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_2\n"); );
    // Body
    Vadd32_fp32accum_bf16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd32_fp32accum_bf16_tb_softfloat___024root*>(voidSelf);
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_2_sub_0((&vlSymsp->TOP), bufp);
}

void Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_2_sub_0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_2_sub_0\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 406);
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[5U] 
                      | vlSelfRef.__Vm_traceActivity[23U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__is_nan_any));
        bufp->chgBit(oldp+1,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_case));
        bufp->chgBit(oldp+2,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_pos_inf));
        bufp->chgBit(oldp+3,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_neg_inf));
        bufp->chgIData(oldp+4,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_result),32);
        bufp->chgCData(oldp+5,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_align_sticky_n),2);
        bufp->chgQData(oldp+6,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x),37);
        bufp->chgQData(oldp+8,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y),37);
        bufp->chgQData(oldp+10,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m),37);
        bufp->chgQData(oldp+12,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n),37);
        bufp->chgQData(oldp+14,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1),37);
        bufp->chgQData(oldp+16,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c1),37);
        bufp->chgQData(oldp+18,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s2),37);
        bufp->chgQData(oldp+20,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c2),37);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[5U] 
                      | vlSelfRef.__Vm_traceActivity[24U])))) {
        bufp->chgSData(oldp+22,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__a_daz),16);
        bufp->chgSData(oldp+23,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__b_daz),16);
        bufp->chgSData(oldp+24,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__c_daz),16);
        bufp->chgSData(oldp+25,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__d_daz),16);
        bufp->chgCData(oldp+26,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a),8);
        bufp->chgCData(oldp+27,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b),8);
        bufp->chgCData(oldp+28,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c),8);
        bufp->chgCData(oldp+29,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d),8);
        bufp->chgCData(oldp+30,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_a),7);
        bufp->chgCData(oldp+31,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_b),7);
        bufp->chgCData(oldp+32,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_c),7);
        bufp->chgCData(oldp+33,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_d),7);
        bufp->chgBit(oldp+34,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_a));
        bufp->chgBit(oldp+35,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_b));
        bufp->chgBit(oldp+36,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_c));
        bufp->chgBit(oldp+37,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_d));
        bufp->chgCData(oldp+38,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_p),8);
        bufp->chgCData(oldp+39,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_m),8);
        bufp->chgCData(oldp+40,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_r),8);
        bufp->chgCData(oldp+41,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_n),8);
        bufp->chgCData(oldp+42,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x),8);
        bufp->chgCData(oldp+43,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y),8);
        bufp->chgCData(oldp+44,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx),8);
        bufp->chgCData(oldp+45,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx),8);
        bufp->chgCData(oldp+46,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_p),7);
        bufp->chgCData(oldp+47,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_m),7);
        bufp->chgCData(oldp+48,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_r),7);
        bufp->chgCData(oldp+49,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_n),7);
        bufp->chgCData(oldp+50,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_x),7);
        bufp->chgCData(oldp+51,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_y),7);
        bufp->chgCData(oldp+52,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_mx),7);
        bufp->chgCData(oldp+53,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_nx),7);
        bufp->chgBit(oldp+54,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_p));
        bufp->chgBit(oldp+55,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_m));
        bufp->chgBit(oldp+56,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_r));
        bufp->chgBit(oldp+57,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_n));
        bufp->chgBit(oldp+58,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_x));
        bufp->chgBit(oldp+59,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_y));
        bufp->chgBit(oldp+60,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_mx));
        bufp->chgBit(oldp+61,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_nx));
        bufp->chgCData(oldp+62,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x_eff),8);
        bufp->chgCData(oldp+63,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y_eff),8);
        bufp->chgCData(oldp+64,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx_eff),8);
        bufp->chgCData(oldp+65,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx_eff),8);
        bufp->chgSData(oldp+66,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shift),9);
        bufp->chgSData(oldp+67,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shift),9);
        bufp->chgSData(oldp+68,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shift),9);
        bufp->chgQData(oldp+69,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__x_mant),34);
        bufp->chgQData(oldp+71,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted),34);
        bufp->chgQData(oldp+73,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted),34);
        bufp->chgQData(oldp+75,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted),34);
        bufp->chgQData(oldp+77,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_mant_base),34);
        bufp->chgQData(oldp+79,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_mant_base),34);
        bufp->chgQData(oldp+81,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_mant_base),34);
        bufp->chgCData(oldp+83,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_y),2);
        bufp->chgCData(oldp+84,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_m),2);
        bufp->chgCData(oldp+85,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_n),2);
        bufp->chgBit(oldp+86,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_sticky_nonzero));
        bufp->chgBit(oldp+87,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_sticky_nonzero));
        bufp->chgBit(oldp+88,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_sticky_nonzero));
        bufp->chgBit(oldp+89,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__ym_mismatch));
        bufp->chgBit(oldp+90,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__yn_mismatch));
        bufp->chgBit(oldp+91,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__mn_mismatch));
        bufp->chgBit(oldp+92,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_mismatch));
        bufp->chgBit(oldp+93,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_nonzero));
        bufp->chgBit(oldp+94,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_op));
        bufp->chgBit(oldp+95,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_op));
        bufp->chgBit(oldp+96,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_op));
        bufp->chgBit(oldp+97,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__is_nan_any));
        bufp->chgBit(oldp+98,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_case));
        bufp->chgBit(oldp+99,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_pos_inf));
        bufp->chgBit(oldp+100,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_neg_inf));
        bufp->chgIData(oldp+101,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_result),32);
        bufp->chgCData(oldp+102,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_align_sticky_n),2);
        bufp->chgQData(oldp+103,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x),37);
        bufp->chgQData(oldp+105,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y),37);
        bufp->chgQData(oldp+107,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m),37);
        bufp->chgQData(oldp+109,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n),37);
        bufp->chgQData(oldp+111,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1),37);
        bufp->chgQData(oldp+113,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c1),37);
        bufp->chgQData(oldp+115,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s2),37);
        bufp->chgQData(oldp+117,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c2),37);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[5U] 
                      | vlSelfRef.__Vm_traceActivity[25U])))) {
        bufp->chgSData(oldp+119,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__a_daz),16);
        bufp->chgSData(oldp+120,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__b_daz),16);
        bufp->chgSData(oldp+121,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__c_daz),16);
        bufp->chgSData(oldp+122,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__d_daz),16);
        bufp->chgCData(oldp+123,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a),8);
        bufp->chgCData(oldp+124,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b),8);
        bufp->chgCData(oldp+125,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c),8);
        bufp->chgCData(oldp+126,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d),8);
        bufp->chgCData(oldp+127,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_a),7);
        bufp->chgCData(oldp+128,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_b),7);
        bufp->chgCData(oldp+129,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_c),7);
        bufp->chgCData(oldp+130,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_d),7);
        bufp->chgBit(oldp+131,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_a));
        bufp->chgBit(oldp+132,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_b));
        bufp->chgBit(oldp+133,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_c));
        bufp->chgBit(oldp+134,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_d));
        bufp->chgCData(oldp+135,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_p),8);
        bufp->chgCData(oldp+136,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_m),8);
        bufp->chgCData(oldp+137,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_r),8);
        bufp->chgCData(oldp+138,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_n),8);
        bufp->chgCData(oldp+139,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x),8);
        bufp->chgCData(oldp+140,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y),8);
        bufp->chgCData(oldp+141,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx),8);
        bufp->chgCData(oldp+142,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx),8);
        bufp->chgCData(oldp+143,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_p),7);
        bufp->chgCData(oldp+144,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_m),7);
        bufp->chgCData(oldp+145,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_r),7);
        bufp->chgCData(oldp+146,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_n),7);
        bufp->chgCData(oldp+147,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_x),7);
        bufp->chgCData(oldp+148,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_y),7);
        bufp->chgCData(oldp+149,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_mx),7);
        bufp->chgCData(oldp+150,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_nx),7);
        bufp->chgBit(oldp+151,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_p));
        bufp->chgBit(oldp+152,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_m));
        bufp->chgBit(oldp+153,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_r));
        bufp->chgBit(oldp+154,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_n));
        bufp->chgBit(oldp+155,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_x));
        bufp->chgBit(oldp+156,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_y));
        bufp->chgBit(oldp+157,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_mx));
        bufp->chgBit(oldp+158,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_nx));
        bufp->chgCData(oldp+159,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x_eff),8);
        bufp->chgCData(oldp+160,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y_eff),8);
        bufp->chgCData(oldp+161,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx_eff),8);
        bufp->chgCData(oldp+162,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx_eff),8);
        bufp->chgSData(oldp+163,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shift),9);
        bufp->chgSData(oldp+164,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shift),9);
        bufp->chgSData(oldp+165,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shift),9);
        bufp->chgQData(oldp+166,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__x_mant),34);
        bufp->chgQData(oldp+168,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted),34);
        bufp->chgQData(oldp+170,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted),34);
        bufp->chgQData(oldp+172,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted),34);
        bufp->chgQData(oldp+174,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_mant_base),34);
        bufp->chgQData(oldp+176,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_mant_base),34);
        bufp->chgQData(oldp+178,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_mant_base),34);
        bufp->chgCData(oldp+180,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_y),2);
        bufp->chgCData(oldp+181,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_m),2);
        bufp->chgCData(oldp+182,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_n),2);
        bufp->chgBit(oldp+183,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_sticky_nonzero));
        bufp->chgBit(oldp+184,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_sticky_nonzero));
        bufp->chgBit(oldp+185,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_sticky_nonzero));
        bufp->chgBit(oldp+186,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__ym_mismatch));
        bufp->chgBit(oldp+187,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__yn_mismatch));
        bufp->chgBit(oldp+188,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__mn_mismatch));
        bufp->chgBit(oldp+189,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_mismatch));
        bufp->chgBit(oldp+190,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_nonzero));
        bufp->chgBit(oldp+191,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_op));
        bufp->chgBit(oldp+192,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_op));
        bufp->chgBit(oldp+193,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_op));
        bufp->chgBit(oldp+194,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__is_nan_any));
        bufp->chgBit(oldp+195,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_case));
        bufp->chgBit(oldp+196,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_pos_inf));
        bufp->chgBit(oldp+197,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_neg_inf));
        bufp->chgIData(oldp+198,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_result),32);
        bufp->chgCData(oldp+199,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_align_sticky_n),2);
        bufp->chgQData(oldp+200,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x),37);
        bufp->chgQData(oldp+202,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y),37);
    }
}

void Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_3_sub_0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_3(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_3\n"); );
    // Body
    Vadd32_fp32accum_bf16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd32_fp32accum_bf16_tb_softfloat___024root*>(voidSelf);
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_3_sub_0((&vlSymsp->TOP), bufp);
}

void Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_3_sub_0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_3_sub_0\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 610);
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[5U] 
                      | vlSelfRef.__Vm_traceActivity[25U])))) {
        bufp->chgQData(oldp+0,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m),37);
        bufp->chgQData(oldp+2,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n),37);
        bufp->chgQData(oldp+4,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1),37);
        bufp->chgQData(oldp+6,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c1),37);
        bufp->chgQData(oldp+8,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s2),37);
        bufp->chgQData(oldp+10,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c2),37);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[5U] 
                      | vlSelfRef.__Vm_traceActivity[26U])))) {
        bufp->chgSData(oldp+12,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__a_daz),16);
        bufp->chgSData(oldp+13,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__b_daz),16);
        bufp->chgSData(oldp+14,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__c_daz),16);
        bufp->chgSData(oldp+15,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__d_daz),16);
        bufp->chgCData(oldp+16,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a),8);
        bufp->chgCData(oldp+17,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b),8);
        bufp->chgCData(oldp+18,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c),8);
        bufp->chgCData(oldp+19,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d),8);
        bufp->chgCData(oldp+20,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_a),7);
        bufp->chgCData(oldp+21,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_b),7);
        bufp->chgCData(oldp+22,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_c),7);
        bufp->chgCData(oldp+23,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_d),7);
        bufp->chgBit(oldp+24,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_a));
        bufp->chgBit(oldp+25,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_b));
        bufp->chgBit(oldp+26,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_c));
        bufp->chgBit(oldp+27,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_d));
        bufp->chgCData(oldp+28,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_p),8);
        bufp->chgCData(oldp+29,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_m),8);
        bufp->chgCData(oldp+30,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_r),8);
        bufp->chgCData(oldp+31,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_n),8);
        bufp->chgCData(oldp+32,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x),8);
        bufp->chgCData(oldp+33,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y),8);
        bufp->chgCData(oldp+34,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx),8);
        bufp->chgCData(oldp+35,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx),8);
        bufp->chgCData(oldp+36,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_p),7);
        bufp->chgCData(oldp+37,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_m),7);
        bufp->chgCData(oldp+38,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_r),7);
        bufp->chgCData(oldp+39,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_n),7);
        bufp->chgCData(oldp+40,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_x),7);
        bufp->chgCData(oldp+41,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_y),7);
        bufp->chgCData(oldp+42,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_mx),7);
        bufp->chgCData(oldp+43,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_nx),7);
        bufp->chgBit(oldp+44,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_p));
        bufp->chgBit(oldp+45,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_m));
        bufp->chgBit(oldp+46,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_r));
        bufp->chgBit(oldp+47,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_n));
        bufp->chgBit(oldp+48,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_x));
        bufp->chgBit(oldp+49,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_y));
        bufp->chgBit(oldp+50,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_mx));
        bufp->chgBit(oldp+51,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_nx));
        bufp->chgCData(oldp+52,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x_eff),8);
        bufp->chgCData(oldp+53,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y_eff),8);
        bufp->chgCData(oldp+54,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx_eff),8);
        bufp->chgCData(oldp+55,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx_eff),8);
        bufp->chgSData(oldp+56,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shift),9);
        bufp->chgSData(oldp+57,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shift),9);
        bufp->chgSData(oldp+58,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shift),9);
        bufp->chgQData(oldp+59,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__x_mant),34);
        bufp->chgQData(oldp+61,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted),34);
        bufp->chgQData(oldp+63,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted),34);
        bufp->chgQData(oldp+65,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted),34);
        bufp->chgQData(oldp+67,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_mant_base),34);
        bufp->chgQData(oldp+69,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_mant_base),34);
        bufp->chgQData(oldp+71,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_mant_base),34);
        bufp->chgCData(oldp+73,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_y),2);
        bufp->chgCData(oldp+74,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_m),2);
        bufp->chgCData(oldp+75,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_n),2);
        bufp->chgBit(oldp+76,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_sticky_nonzero));
        bufp->chgBit(oldp+77,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_sticky_nonzero));
        bufp->chgBit(oldp+78,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_sticky_nonzero));
        bufp->chgBit(oldp+79,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__ym_mismatch));
        bufp->chgBit(oldp+80,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__yn_mismatch));
        bufp->chgBit(oldp+81,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__mn_mismatch));
        bufp->chgBit(oldp+82,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_mismatch));
        bufp->chgBit(oldp+83,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_nonzero));
        bufp->chgBit(oldp+84,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_op));
        bufp->chgBit(oldp+85,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_op));
        bufp->chgBit(oldp+86,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_op));
        bufp->chgBit(oldp+87,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__is_nan_any));
        bufp->chgBit(oldp+88,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_case));
        bufp->chgBit(oldp+89,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_pos_inf));
        bufp->chgBit(oldp+90,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_neg_inf));
        bufp->chgIData(oldp+91,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_result),32);
        bufp->chgCData(oldp+92,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_align_sticky_n),2);
        bufp->chgQData(oldp+93,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x),37);
        bufp->chgQData(oldp+95,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y),37);
        bufp->chgQData(oldp+97,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m),37);
        bufp->chgQData(oldp+99,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n),37);
        bufp->chgQData(oldp+101,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1),37);
        bufp->chgQData(oldp+103,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c1),37);
        bufp->chgQData(oldp+105,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s2),37);
        bufp->chgQData(oldp+107,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c2),37);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[5U] 
                      | vlSelfRef.__Vm_traceActivity[27U])))) {
        bufp->chgSData(oldp+109,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__a_daz),16);
        bufp->chgSData(oldp+110,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__b_daz),16);
        bufp->chgSData(oldp+111,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__c_daz),16);
        bufp->chgSData(oldp+112,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__d_daz),16);
        bufp->chgCData(oldp+113,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a),8);
        bufp->chgCData(oldp+114,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b),8);
        bufp->chgCData(oldp+115,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c),8);
        bufp->chgCData(oldp+116,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d),8);
        bufp->chgCData(oldp+117,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_a),7);
        bufp->chgCData(oldp+118,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_b),7);
        bufp->chgCData(oldp+119,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_c),7);
        bufp->chgCData(oldp+120,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_d),7);
        bufp->chgBit(oldp+121,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_a));
        bufp->chgBit(oldp+122,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_b));
        bufp->chgBit(oldp+123,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_c));
        bufp->chgBit(oldp+124,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_d));
        bufp->chgCData(oldp+125,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_p),8);
        bufp->chgCData(oldp+126,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_m),8);
        bufp->chgCData(oldp+127,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_r),8);
        bufp->chgCData(oldp+128,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_n),8);
        bufp->chgCData(oldp+129,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x),8);
        bufp->chgCData(oldp+130,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y),8);
        bufp->chgCData(oldp+131,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx),8);
        bufp->chgCData(oldp+132,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx),8);
        bufp->chgCData(oldp+133,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_p),7);
        bufp->chgCData(oldp+134,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_m),7);
        bufp->chgCData(oldp+135,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_r),7);
        bufp->chgCData(oldp+136,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_n),7);
        bufp->chgCData(oldp+137,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_x),7);
        bufp->chgCData(oldp+138,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_y),7);
        bufp->chgCData(oldp+139,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_mx),7);
        bufp->chgCData(oldp+140,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_nx),7);
        bufp->chgBit(oldp+141,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_p));
        bufp->chgBit(oldp+142,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_m));
        bufp->chgBit(oldp+143,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_r));
        bufp->chgBit(oldp+144,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_n));
        bufp->chgBit(oldp+145,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_x));
        bufp->chgBit(oldp+146,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_y));
        bufp->chgBit(oldp+147,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_mx));
        bufp->chgBit(oldp+148,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_nx));
        bufp->chgCData(oldp+149,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x_eff),8);
        bufp->chgCData(oldp+150,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y_eff),8);
        bufp->chgCData(oldp+151,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx_eff),8);
        bufp->chgCData(oldp+152,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx_eff),8);
        bufp->chgSData(oldp+153,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shift),9);
        bufp->chgSData(oldp+154,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shift),9);
        bufp->chgSData(oldp+155,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shift),9);
        bufp->chgQData(oldp+156,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__x_mant),34);
        bufp->chgQData(oldp+158,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted),34);
        bufp->chgQData(oldp+160,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted),34);
        bufp->chgQData(oldp+162,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted),34);
        bufp->chgQData(oldp+164,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_mant_base),34);
        bufp->chgQData(oldp+166,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_mant_base),34);
        bufp->chgQData(oldp+168,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_mant_base),34);
        bufp->chgCData(oldp+170,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_y),2);
        bufp->chgCData(oldp+171,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_m),2);
        bufp->chgCData(oldp+172,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_n),2);
        bufp->chgBit(oldp+173,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_sticky_nonzero));
        bufp->chgBit(oldp+174,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_sticky_nonzero));
        bufp->chgBit(oldp+175,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_sticky_nonzero));
        bufp->chgBit(oldp+176,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__ym_mismatch));
        bufp->chgBit(oldp+177,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__yn_mismatch));
        bufp->chgBit(oldp+178,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__mn_mismatch));
        bufp->chgBit(oldp+179,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_mismatch));
        bufp->chgBit(oldp+180,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_nonzero));
        bufp->chgBit(oldp+181,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_op));
        bufp->chgBit(oldp+182,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_op));
        bufp->chgBit(oldp+183,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_op));
        bufp->chgBit(oldp+184,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__is_nan_any));
        bufp->chgBit(oldp+185,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_case));
        bufp->chgBit(oldp+186,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_pos_inf));
        bufp->chgBit(oldp+187,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_neg_inf));
        bufp->chgIData(oldp+188,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_result),32);
        bufp->chgCData(oldp+189,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_align_sticky_n),2);
        bufp->chgQData(oldp+190,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x),37);
        bufp->chgQData(oldp+192,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y),37);
        bufp->chgQData(oldp+194,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m),37);
        bufp->chgQData(oldp+196,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n),37);
        bufp->chgQData(oldp+198,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1),37);
        bufp->chgQData(oldp+200,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c1),37);
        bufp->chgQData(oldp+202,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s2),37);
    }
}

void Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_4_sub_0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_4(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_4\n"); );
    // Body
    Vadd32_fp32accum_bf16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd32_fp32accum_bf16_tb_softfloat___024root*>(voidSelf);
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_4_sub_0((&vlSymsp->TOP), bufp);
}

void Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_4_sub_0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_4_sub_0\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 814);
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[5U] 
                      | vlSelfRef.__Vm_traceActivity[27U])))) {
        bufp->chgQData(oldp+0,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c2),37);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[5U] 
                      | vlSelfRef.__Vm_traceActivity[28U])))) {
        bufp->chgSData(oldp+2,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__a_daz),16);
        bufp->chgSData(oldp+3,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__b_daz),16);
        bufp->chgSData(oldp+4,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__c_daz),16);
        bufp->chgSData(oldp+5,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__d_daz),16);
        bufp->chgCData(oldp+6,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a),8);
        bufp->chgCData(oldp+7,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b),8);
        bufp->chgCData(oldp+8,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c),8);
        bufp->chgCData(oldp+9,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d),8);
        bufp->chgCData(oldp+10,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_a),7);
        bufp->chgCData(oldp+11,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_b),7);
        bufp->chgCData(oldp+12,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_c),7);
        bufp->chgCData(oldp+13,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_d),7);
        bufp->chgBit(oldp+14,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_a));
        bufp->chgBit(oldp+15,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_b));
        bufp->chgBit(oldp+16,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_c));
        bufp->chgBit(oldp+17,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_d));
        bufp->chgCData(oldp+18,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_p),8);
        bufp->chgCData(oldp+19,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_m),8);
        bufp->chgCData(oldp+20,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_r),8);
        bufp->chgCData(oldp+21,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_n),8);
        bufp->chgCData(oldp+22,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x),8);
        bufp->chgCData(oldp+23,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y),8);
        bufp->chgCData(oldp+24,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx),8);
        bufp->chgCData(oldp+25,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx),8);
        bufp->chgCData(oldp+26,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_p),7);
        bufp->chgCData(oldp+27,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_m),7);
        bufp->chgCData(oldp+28,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_r),7);
        bufp->chgCData(oldp+29,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_n),7);
        bufp->chgCData(oldp+30,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_x),7);
        bufp->chgCData(oldp+31,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_y),7);
        bufp->chgCData(oldp+32,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_mx),7);
        bufp->chgCData(oldp+33,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_nx),7);
        bufp->chgBit(oldp+34,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_p));
        bufp->chgBit(oldp+35,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_m));
        bufp->chgBit(oldp+36,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_r));
        bufp->chgBit(oldp+37,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_n));
        bufp->chgBit(oldp+38,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_x));
        bufp->chgBit(oldp+39,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_y));
        bufp->chgBit(oldp+40,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_mx));
        bufp->chgBit(oldp+41,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_nx));
        bufp->chgCData(oldp+42,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x_eff),8);
        bufp->chgCData(oldp+43,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y_eff),8);
        bufp->chgCData(oldp+44,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx_eff),8);
        bufp->chgCData(oldp+45,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx_eff),8);
        bufp->chgSData(oldp+46,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shift),9);
        bufp->chgSData(oldp+47,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shift),9);
        bufp->chgSData(oldp+48,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shift),9);
        bufp->chgQData(oldp+49,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__x_mant),34);
        bufp->chgQData(oldp+51,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted),34);
        bufp->chgQData(oldp+53,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted),34);
        bufp->chgQData(oldp+55,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted),34);
        bufp->chgQData(oldp+57,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_mant_base),34);
        bufp->chgQData(oldp+59,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_mant_base),34);
        bufp->chgQData(oldp+61,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_mant_base),34);
        bufp->chgCData(oldp+63,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_y),2);
        bufp->chgCData(oldp+64,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_m),2);
        bufp->chgCData(oldp+65,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_n),2);
        bufp->chgBit(oldp+66,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_sticky_nonzero));
        bufp->chgBit(oldp+67,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_sticky_nonzero));
        bufp->chgBit(oldp+68,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_sticky_nonzero));
        bufp->chgBit(oldp+69,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__ym_mismatch));
        bufp->chgBit(oldp+70,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__yn_mismatch));
        bufp->chgBit(oldp+71,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__mn_mismatch));
        bufp->chgBit(oldp+72,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_mismatch));
        bufp->chgBit(oldp+73,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_nonzero));
        bufp->chgBit(oldp+74,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_op));
        bufp->chgBit(oldp+75,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_op));
        bufp->chgBit(oldp+76,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_op));
        bufp->chgBit(oldp+77,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__is_nan_any));
        bufp->chgBit(oldp+78,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_case));
        bufp->chgBit(oldp+79,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_pos_inf));
        bufp->chgBit(oldp+80,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_neg_inf));
        bufp->chgIData(oldp+81,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_result),32);
        bufp->chgCData(oldp+82,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_align_sticky_n),2);
        bufp->chgQData(oldp+83,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x),37);
        bufp->chgQData(oldp+85,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y),37);
        bufp->chgQData(oldp+87,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m),37);
        bufp->chgQData(oldp+89,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n),37);
        bufp->chgQData(oldp+91,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1),37);
        bufp->chgQData(oldp+93,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c1),37);
        bufp->chgQData(oldp+95,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s2),37);
        bufp->chgQData(oldp+97,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c2),37);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[6U]))) {
        bufp->chgQData(oldp+99,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag),37);
        bufp->chgBit(oldp+101,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_res_sign));
        bufp->chgQData(oldp+102,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag),37);
        bufp->chgBit(oldp+104,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_res_sign));
        bufp->chgQData(oldp+105,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag),37);
        bufp->chgBit(oldp+107,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_res_sign));
        bufp->chgQData(oldp+108,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag),37);
        bufp->chgBit(oldp+110,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_res_sign));
        bufp->chgQData(oldp+111,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag),37);
        bufp->chgBit(oldp+113,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_res_sign));
        bufp->chgQData(oldp+114,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag),37);
        bufp->chgBit(oldp+116,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_res_sign));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[7U]))) {
        bufp->chgBit(oldp+117,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_a_s));
        bufp->chgBit(oldp+118,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_a_s));
        bufp->chgIData(oldp+119,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_special_result),32);
        bufp->chgIData(oldp+120,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_spec_res),32);
        bufp->chgCData(oldp+121,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_a_e),8);
        bufp->chgIData(oldp+122,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_special_result),32);
        bufp->chgQData(oldp+123,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_sum_vec),37);
        bufp->chgQData(oldp+125,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_carry_vec),37);
        bufp->chgCData(oldp+127,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_exp_base),8);
        bufp->chgIData(oldp+128,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_spec_res),32);
        bufp->chgCData(oldp+129,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_a_e),8);
        bufp->chgIData(oldp+130,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_special_result),32);
        bufp->chgQData(oldp+131,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_sum_vec),37);
        bufp->chgQData(oldp+133,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_carry_vec),37);
        bufp->chgCData(oldp+135,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_exp_base),8);
        bufp->chgIData(oldp+136,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_spec_res),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[8U]))) {
        bufp->chgCData(oldp+137,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_align_sticky),2);
        bufp->chgBit(oldp+138,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sticky));
        bufp->chgBit(oldp+139,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_a_s));
        bufp->chgCData(oldp+140,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_align_sticky),2);
        bufp->chgIData(oldp+141,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_special_result),32);
        bufp->chgIData(oldp+142,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_spec_res),32);
        bufp->chgBit(oldp+143,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sticky));
        bufp->chgBit(oldp+144,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_a_s));
        bufp->chgBit(oldp+145,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_special_case));
        bufp->chgBit(oldp+146,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_special));
        bufp->chgBit(oldp+147,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_a_s));
        bufp->chgCData(oldp+148,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_a_e),8);
        bufp->chgBit(oldp+149,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_special_case));
        bufp->chgCData(oldp+150,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_exp_base),8);
        bufp->chgBit(oldp+151,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_special));
        bufp->chgIData(oldp+152,(vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__5__KET__.out),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[9U]))) {
        bufp->chgCData(oldp+153,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_a_e),8);
        bufp->chgIData(oldp+154,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_special_result),32);
        bufp->chgQData(oldp+155,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_sum_vec),37);
        bufp->chgQData(oldp+157,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_carry_vec),37);
        bufp->chgCData(oldp+159,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_exp_base),8);
        bufp->chgIData(oldp+160,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_spec_res),32);
        bufp->chgCData(oldp+161,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_a_e),8);
        bufp->chgQData(oldp+162,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_sum_vec),37);
        bufp->chgQData(oldp+164,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_carry_vec),37);
        bufp->chgCData(oldp+166,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_exp_base),8);
        bufp->chgCData(oldp+167,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_a_e),8);
        bufp->chgIData(oldp+168,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_special_result),32);
        bufp->chgQData(oldp+169,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_sum_vec),37);
        bufp->chgQData(oldp+171,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_carry_vec),37);
        bufp->chgCData(oldp+173,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_exp_base),8);
        bufp->chgIData(oldp+174,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_spec_res),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[10U]))) {
        bufp->chgBit(oldp+175,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_special_case));
        bufp->chgCData(oldp+176,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_align_sticky),2);
        bufp->chgBit(oldp+177,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sticky));
        bufp->chgBit(oldp+178,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_special));
        bufp->chgCData(oldp+179,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_align_sticky),2);
        bufp->chgBit(oldp+180,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sticky));
        bufp->chgCData(oldp+181,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_align_sticky),2);
        bufp->chgBit(oldp+182,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sticky));
        bufp->chgCData(oldp+183,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_a_e),8);
        bufp->chgBit(oldp+184,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_special_case));
        bufp->chgCData(oldp+185,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_align_sticky),2);
        bufp->chgQData(oldp+186,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_sum_vec),37);
        bufp->chgQData(oldp+188,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_carry_vec),37);
        bufp->chgCData(oldp+190,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_exp_base),8);
        bufp->chgBit(oldp+191,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sticky));
        bufp->chgBit(oldp+192,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_special));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[11U]))) {
        bufp->chgCData(oldp+193,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_a_e),8);
        bufp->chgBit(oldp+194,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_a_s));
        bufp->chgBit(oldp+195,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_special_case));
        bufp->chgQData(oldp+196,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_sum_vec),37);
        bufp->chgQData(oldp+198,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_carry_vec),37);
        bufp->chgCData(oldp+200,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_exp_base),8);
        bufp->chgBit(oldp+201,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_special));
        bufp->chgBit(oldp+202,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_a_s));
    }
}

void Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_5_sub_0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_5(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_5\n"); );
    // Body
    Vadd32_fp32accum_bf16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd32_fp32accum_bf16_tb_softfloat___024root*>(voidSelf);
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_5_sub_0((&vlSymsp->TOP), bufp);
}

void Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_5_sub_0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_5_sub_0\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1017);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[11U]))) {
        bufp->chgBit(oldp+0,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_special_case));
        bufp->chgBit(oldp+1,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_special));
        bufp->chgCData(oldp+2,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_a_e),8);
        bufp->chgBit(oldp+3,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_special_case));
        bufp->chgQData(oldp+4,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_sum_vec),37);
        bufp->chgQData(oldp+6,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_carry_vec),37);
        bufp->chgCData(oldp+8,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_exp_base),8);
        bufp->chgBit(oldp+9,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_special));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[12U]))) {
        bufp->chgBit(oldp+10,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_a_s));
        bufp->chgBit(oldp+11,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_special_case));
        bufp->chgIData(oldp+12,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_special_result),32);
        bufp->chgIData(oldp+13,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_spec_res),32);
        bufp->chgBit(oldp+14,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_special));
        bufp->chgCData(oldp+15,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_a_e),8);
        bufp->chgBit(oldp+16,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_a_s));
        bufp->chgBit(oldp+17,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_special_case));
        bufp->chgIData(oldp+18,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_special_result),32);
        bufp->chgQData(oldp+19,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_sum_vec),37);
        bufp->chgQData(oldp+21,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_carry_vec),37);
        bufp->chgCData(oldp+23,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_exp_base),8);
        bufp->chgIData(oldp+24,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_spec_res),32);
        bufp->chgBit(oldp+25,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_special));
        bufp->chgBit(oldp+26,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_special_case));
        bufp->chgBit(oldp+27,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_special));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[13U]))) {
        bufp->chgIData(oldp+28,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_special_result),32);
        bufp->chgQData(oldp+29,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_sum_vec),37);
        bufp->chgQData(oldp+31,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_carry_vec),37);
        bufp->chgIData(oldp+33,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_spec_res),32);
        bufp->chgIData(oldp+34,(vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__6__KET__.out),32);
        bufp->chgIData(oldp+35,(vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__7__KET__.out),32);
        bufp->chgIData(oldp+36,(vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__0__KET__.out),32);
        bufp->chgIData(oldp+37,(vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__1__KET__.out),32);
        bufp->chgIData(oldp+38,(vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__2__KET__.out),32);
        bufp->chgIData(oldp+39,(vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__3__KET__.out),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[14U]))) {
        bufp->chgCData(oldp+40,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_hot_ones),2);
        bufp->chgCData(oldp+41,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_align_sticky),2);
        bufp->chgCData(oldp+42,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_hot_ones),2);
        bufp->chgBit(oldp+43,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sticky));
        bufp->chgCData(oldp+44,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_hot_ones),2);
        bufp->chgCData(oldp+45,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_hot_ones),2);
        bufp->chgCData(oldp+46,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_hot_ones),2);
        bufp->chgBit(oldp+47,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_a_s));
        bufp->chgCData(oldp+48,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_align_sticky),2);
        bufp->chgBit(oldp+49,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sticky));
        bufp->chgIData(oldp+50,(vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__4__KET__.out),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[15U]))) {
        bufp->chgCData(oldp+51,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_a_e),8);
        bufp->chgBit(oldp+52,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_a_s));
        bufp->chgBit(oldp+53,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_special_case));
        bufp->chgCData(oldp+54,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_align_sticky),2);
        bufp->chgIData(oldp+55,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_special_result),32);
        bufp->chgQData(oldp+56,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_sum_vec),37);
        bufp->chgQData(oldp+58,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_carry_vec),37);
        bufp->chgCData(oldp+60,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_hot_ones),2);
        bufp->chgCData(oldp+61,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_exp_base),8);
        bufp->chgIData(oldp+62,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_spec_res),32);
        bufp->chgBit(oldp+63,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sticky));
        bufp->chgBit(oldp+64,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_special));
        bufp->chgIData(oldp+65,(vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage2_if__BRA__1__KET__.out),32);
        bufp->chgIData(oldp+66,(vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage2_if__BRA__0__KET__.out),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[16U]))) {
        bufp->chgIData(oldp+67,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_special_result),32);
        bufp->chgCData(oldp+68,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_hot_ones),2);
        bufp->chgIData(oldp+69,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_spec_res),32);
        bufp->chgCData(oldp+70,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_hot_ones),2);
        bufp->chgCData(oldp+71,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_align_sticky),2);
        bufp->chgCData(oldp+72,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_hot_ones),2);
        bufp->chgBit(oldp+73,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sticky));
        bufp->chgCData(oldp+74,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_align_sticky),2);
        bufp->chgCData(oldp+75,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_hot_ones),2);
        bufp->chgBit(oldp+76,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sticky));
        bufp->chgCData(oldp+77,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_hot_ones),2);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[17U]))) {
        bufp->chgQData(oldp+78,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan),37);
        bufp->chgCData(oldp+80,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros),6);
        bufp->chgQData(oldp+81,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val),37);
        bufp->chgIData(oldp+83,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__final_mant),23);
        bufp->chgIData(oldp+84,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__rounded_mant_int),24);
        bufp->chgSData(oldp+85,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__final_exp_calc),11);
        bufp->chgBit(oldp+86,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__guard_bit));
        bufp->chgBit(oldp+87,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__round_bit));
        bufp->chgBit(oldp+88,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_bit));
        bufp->chgBit(oldp+89,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__round_up));
        bufp->chgBit(oldp+90,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__l_bit));
        bufp->chgIData(oldp+91,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__result_out),32);
        bufp->chgQData(oldp+92,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan),37);
        bufp->chgCData(oldp+94,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros),6);
        bufp->chgQData(oldp+95,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val),37);
        bufp->chgIData(oldp+97,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__final_mant),23);
        bufp->chgIData(oldp+98,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__rounded_mant_int),24);
        bufp->chgSData(oldp+99,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__final_exp_calc),11);
        bufp->chgBit(oldp+100,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__guard_bit));
        bufp->chgBit(oldp+101,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__round_bit));
        bufp->chgBit(oldp+102,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_bit));
        bufp->chgBit(oldp+103,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__round_up));
        bufp->chgBit(oldp+104,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__l_bit));
        bufp->chgIData(oldp+105,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__result_out),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[18U]))) {
        bufp->chgQData(oldp+106,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum),37);
        bufp->chgQData(oldp+108,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__mag_sum),37);
        bufp->chgBit(oldp+110,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__res_sign));
        bufp->chgQData(oldp+111,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag),37);
        bufp->chgBit(oldp+113,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_res_sign));
        bufp->chgQData(oldp+114,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan),37);
        bufp->chgCData(oldp+116,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros),6);
        bufp->chgQData(oldp+117,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val),37);
        bufp->chgIData(oldp+119,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__final_mant),23);
        bufp->chgIData(oldp+120,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__rounded_mant_int),24);
        bufp->chgSData(oldp+121,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__final_exp_calc),11);
        bufp->chgBit(oldp+122,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__guard_bit));
        bufp->chgBit(oldp+123,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__round_bit));
        bufp->chgBit(oldp+124,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_bit));
        bufp->chgBit(oldp+125,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__round_up));
        bufp->chgBit(oldp+126,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__l_bit));
        bufp->chgIData(oldp+127,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__result_out),32);
        bufp->chgQData(oldp+128,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum),37);
        bufp->chgQData(oldp+130,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__mag_sum),37);
        bufp->chgBit(oldp+132,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__res_sign));
        bufp->chgQData(oldp+133,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum),37);
        bufp->chgQData(oldp+135,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__mag_sum),37);
        bufp->chgBit(oldp+137,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__res_sign));
        bufp->chgQData(oldp+138,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum),37);
        bufp->chgQData(oldp+140,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__mag_sum),37);
        bufp->chgBit(oldp+142,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__res_sign));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[19U]))) {
        bufp->chgQData(oldp+143,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan),37);
        bufp->chgCData(oldp+145,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros),6);
        bufp->chgQData(oldp+146,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val),37);
        bufp->chgIData(oldp+148,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__final_mant),23);
        bufp->chgIData(oldp+149,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__rounded_mant_int),24);
        bufp->chgSData(oldp+150,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__final_exp_calc),11);
        bufp->chgBit(oldp+151,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__guard_bit));
        bufp->chgBit(oldp+152,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__round_bit));
        bufp->chgBit(oldp+153,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_bit));
        bufp->chgBit(oldp+154,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__round_up));
        bufp->chgBit(oldp+155,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__l_bit));
        bufp->chgIData(oldp+156,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__result_out),32);
        bufp->chgQData(oldp+157,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan),37);
        bufp->chgCData(oldp+159,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros),6);
        bufp->chgQData(oldp+160,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val),37);
        bufp->chgIData(oldp+162,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__final_mant),23);
        bufp->chgIData(oldp+163,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__rounded_mant_int),24);
        bufp->chgSData(oldp+164,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__final_exp_calc),11);
        bufp->chgBit(oldp+165,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__guard_bit));
        bufp->chgBit(oldp+166,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__round_bit));
        bufp->chgBit(oldp+167,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_bit));
        bufp->chgBit(oldp+168,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__round_up));
        bufp->chgBit(oldp+169,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__l_bit));
        bufp->chgIData(oldp+170,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__result_out),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[20U]))) {
        bufp->chgQData(oldp+171,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan),37);
        bufp->chgCData(oldp+173,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros),6);
        bufp->chgQData(oldp+174,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val),37);
        bufp->chgIData(oldp+176,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__final_mant),23);
        bufp->chgIData(oldp+177,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__rounded_mant_int),24);
        bufp->chgSData(oldp+178,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__final_exp_calc),11);
        bufp->chgBit(oldp+179,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__guard_bit));
        bufp->chgBit(oldp+180,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__round_bit));
        bufp->chgBit(oldp+181,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_bit));
        bufp->chgBit(oldp+182,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__round_up));
        bufp->chgBit(oldp+183,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__l_bit));
        bufp->chgIData(oldp+184,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__result_out),32);
        bufp->chgQData(oldp+185,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan),37);
        bufp->chgCData(oldp+187,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros),6);
        bufp->chgQData(oldp+188,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val),37);
        bufp->chgIData(oldp+190,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__final_mant),23);
        bufp->chgIData(oldp+191,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__rounded_mant_int),24);
        bufp->chgSData(oldp+192,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__final_exp_calc),11);
        bufp->chgBit(oldp+193,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__guard_bit));
        bufp->chgBit(oldp+194,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__round_bit));
        bufp->chgBit(oldp+195,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_bit));
        bufp->chgBit(oldp+196,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__round_up));
        bufp->chgBit(oldp+197,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__l_bit));
        bufp->chgIData(oldp+198,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__result_out),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[29U]))) {
        bufp->chgIData(oldp+199,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__a_daz),32);
        bufp->chgIData(oldp+200,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__b_daz),32);
        bufp->chgIData(oldp+201,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__c_daz),32);
        bufp->chgIData(oldp+202,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__d_daz),32);
    }
}

void Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_6_sub_0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_6(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_6\n"); );
    // Body
    Vadd32_fp32accum_bf16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd32_fp32accum_bf16_tb_softfloat___024root*>(voidSelf);
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_6_sub_0((&vlSymsp->TOP), bufp);
}

void Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_6_sub_0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_6_sub_0\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1220);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[29U]))) {
        bufp->chgCData(oldp+0,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_a),8);
        bufp->chgCData(oldp+1,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_b),8);
        bufp->chgCData(oldp+2,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_c),8);
        bufp->chgCData(oldp+3,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_d),8);
        bufp->chgIData(oldp+4,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_a),23);
        bufp->chgIData(oldp+5,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_b),23);
        bufp->chgIData(oldp+6,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_c),23);
        bufp->chgIData(oldp+7,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_d),23);
        bufp->chgBit(oldp+8,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_a));
        bufp->chgBit(oldp+9,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_b));
        bufp->chgBit(oldp+10,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_c));
        bufp->chgBit(oldp+11,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_d));
        bufp->chgCData(oldp+12,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_p),8);
        bufp->chgCData(oldp+13,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_m),8);
        bufp->chgCData(oldp+14,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_r),8);
        bufp->chgCData(oldp+15,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_n),8);
        bufp->chgCData(oldp+16,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_x),8);
        bufp->chgCData(oldp+17,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_y),8);
        bufp->chgCData(oldp+18,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_mx),8);
        bufp->chgCData(oldp+19,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_nx),8);
        bufp->chgIData(oldp+20,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_p),23);
        bufp->chgIData(oldp+21,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_m),23);
        bufp->chgIData(oldp+22,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_r),23);
        bufp->chgIData(oldp+23,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_n),23);
        bufp->chgIData(oldp+24,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_x),23);
        bufp->chgIData(oldp+25,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_y),23);
        bufp->chgIData(oldp+26,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_mx),23);
        bufp->chgIData(oldp+27,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_nx),23);
        bufp->chgBit(oldp+28,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_p));
        bufp->chgBit(oldp+29,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_m));
        bufp->chgBit(oldp+30,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_r));
        bufp->chgBit(oldp+31,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_n));
        bufp->chgBit(oldp+32,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_x));
        bufp->chgBit(oldp+33,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_y));
        bufp->chgBit(oldp+34,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_mx));
        bufp->chgBit(oldp+35,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_nx));
        bufp->chgCData(oldp+36,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_x_eff),8);
        bufp->chgCData(oldp+37,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_y_eff),8);
        bufp->chgCData(oldp+38,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_mx_eff),8);
        bufp->chgCData(oldp+39,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_nx_eff),8);
        bufp->chgSData(oldp+40,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shift),9);
        bufp->chgSData(oldp+41,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shift),9);
        bufp->chgSData(oldp+42,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shift),9);
        bufp->chgQData(oldp+43,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__x_mant),34);
        bufp->chgQData(oldp+45,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shifted),34);
        bufp->chgQData(oldp+47,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shifted),34);
        bufp->chgQData(oldp+49,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shifted),34);
        bufp->chgQData(oldp+51,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_mant_base),34);
        bufp->chgQData(oldp+53,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_mant_base),34);
        bufp->chgQData(oldp+55,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_mant_base),34);
        bufp->chgCData(oldp+57,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sticky_y),2);
        bufp->chgCData(oldp+58,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sticky_m),2);
        bufp->chgCData(oldp+59,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sticky_n),2);
        bufp->chgBit(oldp+60,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_sticky_nonzero));
        bufp->chgBit(oldp+61,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_sticky_nonzero));
        bufp->chgBit(oldp+62,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_sticky_nonzero));
        bufp->chgBit(oldp+63,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__ym_mismatch));
        bufp->chgBit(oldp+64,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__yn_mismatch));
        bufp->chgBit(oldp+65,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__mn_mismatch));
        bufp->chgBit(oldp+66,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__any_mismatch));
        bufp->chgBit(oldp+67,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__any_nonzero));
        bufp->chgBit(oldp+68,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_op));
        bufp->chgBit(oldp+69,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_op));
        bufp->chgBit(oldp+70,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_op));
        bufp->chgBit(oldp+71,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__is_nan_any));
        bufp->chgBit(oldp+72,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__special_case));
        bufp->chgBit(oldp+73,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__any_pos_inf));
        bufp->chgBit(oldp+74,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__any_neg_inf));
        bufp->chgIData(oldp+75,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__special_result),32);
        bufp->chgCData(oldp+76,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_align_sticky_n),2);
        bufp->chgQData(oldp+77,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_x),37);
        bufp->chgQData(oldp+79,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_y),37);
        bufp->chgQData(oldp+81,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_m),37);
        bufp->chgQData(oldp+83,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n),37);
        bufp->chgQData(oldp+85,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1),37);
        bufp->chgQData(oldp+87,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_c1),37);
        bufp->chgQData(oldp+89,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s2),37);
        bufp->chgQData(oldp+91,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_c2),37);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[30U]))) {
        bufp->chgIData(oldp+93,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__a_daz),32);
        bufp->chgIData(oldp+94,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__b_daz),32);
        bufp->chgIData(oldp+95,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__c_daz),32);
        bufp->chgIData(oldp+96,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__d_daz),32);
        bufp->chgCData(oldp+97,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_a),8);
        bufp->chgCData(oldp+98,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_b),8);
        bufp->chgCData(oldp+99,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_c),8);
        bufp->chgCData(oldp+100,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_d),8);
        bufp->chgIData(oldp+101,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_a),23);
        bufp->chgIData(oldp+102,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_b),23);
        bufp->chgIData(oldp+103,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_c),23);
        bufp->chgIData(oldp+104,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_d),23);
        bufp->chgBit(oldp+105,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_a));
        bufp->chgBit(oldp+106,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_b));
        bufp->chgBit(oldp+107,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_c));
        bufp->chgBit(oldp+108,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_d));
        bufp->chgCData(oldp+109,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_p),8);
        bufp->chgCData(oldp+110,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_m),8);
        bufp->chgCData(oldp+111,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_r),8);
        bufp->chgCData(oldp+112,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_n),8);
        bufp->chgCData(oldp+113,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x),8);
        bufp->chgCData(oldp+114,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_y),8);
        bufp->chgCData(oldp+115,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_mx),8);
        bufp->chgCData(oldp+116,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_nx),8);
        bufp->chgIData(oldp+117,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_p),23);
        bufp->chgIData(oldp+118,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_m),23);
        bufp->chgIData(oldp+119,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_r),23);
        bufp->chgIData(oldp+120,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_n),23);
        bufp->chgIData(oldp+121,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_x),23);
        bufp->chgIData(oldp+122,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_y),23);
        bufp->chgIData(oldp+123,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_mx),23);
        bufp->chgIData(oldp+124,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_nx),23);
        bufp->chgBit(oldp+125,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_p));
        bufp->chgBit(oldp+126,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_m));
        bufp->chgBit(oldp+127,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_r));
        bufp->chgBit(oldp+128,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_n));
        bufp->chgBit(oldp+129,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_x));
        bufp->chgBit(oldp+130,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_y));
        bufp->chgBit(oldp+131,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_mx));
        bufp->chgBit(oldp+132,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_nx));
        bufp->chgCData(oldp+133,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x_eff),8);
        bufp->chgCData(oldp+134,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_y_eff),8);
        bufp->chgCData(oldp+135,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_mx_eff),8);
        bufp->chgCData(oldp+136,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_nx_eff),8);
        bufp->chgSData(oldp+137,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shift),9);
        bufp->chgSData(oldp+138,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shift),9);
        bufp->chgSData(oldp+139,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shift),9);
        bufp->chgQData(oldp+140,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__x_mant),34);
        bufp->chgQData(oldp+142,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted),34);
        bufp->chgQData(oldp+144,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted),34);
        bufp->chgQData(oldp+146,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted),34);
        bufp->chgQData(oldp+148,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_mant_base),34);
        bufp->chgQData(oldp+150,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_mant_base),34);
        bufp->chgQData(oldp+152,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_mant_base),34);
        bufp->chgCData(oldp+154,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_y),2);
        bufp->chgCData(oldp+155,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_m),2);
        bufp->chgCData(oldp+156,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_n),2);
        bufp->chgBit(oldp+157,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_sticky_nonzero));
        bufp->chgBit(oldp+158,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_sticky_nonzero));
        bufp->chgBit(oldp+159,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_sticky_nonzero));
        bufp->chgBit(oldp+160,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__ym_mismatch));
        bufp->chgBit(oldp+161,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__yn_mismatch));
        bufp->chgBit(oldp+162,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__mn_mismatch));
        bufp->chgBit(oldp+163,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__any_mismatch));
        bufp->chgBit(oldp+164,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__any_nonzero));
        bufp->chgBit(oldp+165,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_op));
        bufp->chgBit(oldp+166,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_op));
        bufp->chgBit(oldp+167,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_op));
        bufp->chgBit(oldp+168,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__is_nan_any));
        bufp->chgBit(oldp+169,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_case));
        bufp->chgBit(oldp+170,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__any_pos_inf));
        bufp->chgBit(oldp+171,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__any_neg_inf));
        bufp->chgIData(oldp+172,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_result),32);
        bufp->chgCData(oldp+173,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_align_sticky_n),2);
        bufp->chgQData(oldp+174,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_x),37);
        bufp->chgQData(oldp+176,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y),37);
        bufp->chgQData(oldp+178,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m),37);
        bufp->chgQData(oldp+180,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n),37);
        bufp->chgQData(oldp+182,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1),37);
        bufp->chgQData(oldp+184,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c1),37);
        bufp->chgQData(oldp+186,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s2),37);
        bufp->chgQData(oldp+188,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c2),37);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[31U]))) {
        bufp->chgIData(oldp+190,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__a_daz),32);
        bufp->chgIData(oldp+191,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__b_daz),32);
        bufp->chgIData(oldp+192,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__c_daz),32);
        bufp->chgIData(oldp+193,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__d_daz),32);
        bufp->chgCData(oldp+194,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_a),8);
        bufp->chgCData(oldp+195,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_b),8);
        bufp->chgCData(oldp+196,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_c),8);
        bufp->chgCData(oldp+197,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_d),8);
        bufp->chgIData(oldp+198,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_a),23);
        bufp->chgIData(oldp+199,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_b),23);
        bufp->chgIData(oldp+200,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_c),23);
        bufp->chgIData(oldp+201,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_d),23);
        bufp->chgBit(oldp+202,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_a));
    }
}

void Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_7_sub_0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_7(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_7\n"); );
    // Body
    Vadd32_fp32accum_bf16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd32_fp32accum_bf16_tb_softfloat___024root*>(voidSelf);
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_7_sub_0((&vlSymsp->TOP), bufp);
}

void Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_7_sub_0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_chg_7_sub_0\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1423);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[31U]))) {
        bufp->chgBit(oldp+0,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_b));
        bufp->chgBit(oldp+1,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_c));
        bufp->chgBit(oldp+2,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_d));
        bufp->chgCData(oldp+3,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_p),8);
        bufp->chgCData(oldp+4,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_m),8);
        bufp->chgCData(oldp+5,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_r),8);
        bufp->chgCData(oldp+6,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_n),8);
        bufp->chgCData(oldp+7,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x),8);
        bufp->chgCData(oldp+8,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_y),8);
        bufp->chgCData(oldp+9,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_mx),8);
        bufp->chgCData(oldp+10,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_nx),8);
        bufp->chgIData(oldp+11,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_p),23);
        bufp->chgIData(oldp+12,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_m),23);
        bufp->chgIData(oldp+13,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_r),23);
        bufp->chgIData(oldp+14,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_n),23);
        bufp->chgIData(oldp+15,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_x),23);
        bufp->chgIData(oldp+16,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_y),23);
        bufp->chgIData(oldp+17,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_mx),23);
        bufp->chgIData(oldp+18,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_nx),23);
        bufp->chgBit(oldp+19,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_p));
        bufp->chgBit(oldp+20,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_m));
        bufp->chgBit(oldp+21,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_r));
        bufp->chgBit(oldp+22,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_n));
        bufp->chgBit(oldp+23,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_x));
        bufp->chgBit(oldp+24,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_y));
        bufp->chgBit(oldp+25,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_mx));
        bufp->chgBit(oldp+26,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_nx));
        bufp->chgCData(oldp+27,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x_eff),8);
        bufp->chgCData(oldp+28,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_y_eff),8);
        bufp->chgCData(oldp+29,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_mx_eff),8);
        bufp->chgCData(oldp+30,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_nx_eff),8);
        bufp->chgSData(oldp+31,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shift),9);
        bufp->chgSData(oldp+32,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shift),9);
        bufp->chgSData(oldp+33,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shift),9);
        bufp->chgQData(oldp+34,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__x_mant),34);
        bufp->chgQData(oldp+36,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted),34);
        bufp->chgQData(oldp+38,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted),34);
        bufp->chgQData(oldp+40,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted),34);
        bufp->chgQData(oldp+42,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_mant_base),34);
        bufp->chgQData(oldp+44,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_mant_base),34);
        bufp->chgQData(oldp+46,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_mant_base),34);
        bufp->chgCData(oldp+48,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_y),2);
        bufp->chgCData(oldp+49,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_m),2);
        bufp->chgCData(oldp+50,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_n),2);
        bufp->chgBit(oldp+51,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_sticky_nonzero));
        bufp->chgBit(oldp+52,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_sticky_nonzero));
        bufp->chgBit(oldp+53,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_sticky_nonzero));
        bufp->chgBit(oldp+54,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__ym_mismatch));
        bufp->chgBit(oldp+55,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__yn_mismatch));
        bufp->chgBit(oldp+56,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__mn_mismatch));
        bufp->chgBit(oldp+57,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__any_mismatch));
        bufp->chgBit(oldp+58,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__any_nonzero));
        bufp->chgBit(oldp+59,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_op));
        bufp->chgBit(oldp+60,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_op));
        bufp->chgBit(oldp+61,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_op));
        bufp->chgBit(oldp+62,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__is_nan_any));
        bufp->chgBit(oldp+63,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_case));
        bufp->chgBit(oldp+64,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__any_pos_inf));
        bufp->chgBit(oldp+65,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__any_neg_inf));
        bufp->chgIData(oldp+66,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_result),32);
        bufp->chgCData(oldp+67,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_align_sticky_n),2);
        bufp->chgQData(oldp+68,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_x),37);
        bufp->chgQData(oldp+70,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y),37);
        bufp->chgQData(oldp+72,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m),37);
        bufp->chgQData(oldp+74,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n),37);
        bufp->chgQData(oldp+76,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1),37);
        bufp->chgQData(oldp+78,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c1),37);
        bufp->chgQData(oldp+80,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s2),37);
        bufp->chgQData(oldp+82,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c2),37);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[32U]))) {
        bufp->chgQData(oldp+84,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag),37);
        bufp->chgBit(oldp+86,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_res_sign));
        bufp->chgIData(oldp+87,(vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out),32);
        bufp->chgBit(oldp+88,((vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out 
                               >> 0x0000001fU)));
        bufp->chgCData(oldp+89,((0x000000ffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out 
                                                >> 0x00000017U))),8);
        bufp->chgIData(oldp+90,((0x007fffffU & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out)),23);
        bufp->chgBit(oldp+91,((1U & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out 
                                     >> 0x0000000fU))));
        bufp->chgBit(oldp+92,((1U & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out 
                                     >> 0x0000000eU))));
        bufp->chgBit(oldp+93,((0U != (0x00003fffU & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out))));
        bufp->chgBit(oldp+94,(((vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out 
                                >> 0x0000000fU) & (0U 
                                                   != 
                                                   (0x00017fffU 
                                                    & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out)))));
        bufp->chgQData(oldp+95,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag),37);
        bufp->chgBit(oldp+97,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_res_sign));
        bufp->chgQData(oldp+98,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag),37);
        bufp->chgBit(oldp+100,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_res_sign));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[33U]))) {
        bufp->chgQData(oldp+101,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan),37);
        bufp->chgCData(oldp+103,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros),6);
        bufp->chgQData(oldp+104,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__norm_val),37);
        bufp->chgIData(oldp+106,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__final_mant),23);
        bufp->chgIData(oldp+107,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__rounded_mant_int),24);
        bufp->chgSData(oldp+108,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__final_exp_calc),11);
        bufp->chgBit(oldp+109,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__guard_bit));
        bufp->chgBit(oldp+110,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__round_bit));
        bufp->chgBit(oldp+111,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sticky_bit));
        bufp->chgBit(oldp+112,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__round_up));
        bufp->chgBit(oldp+113,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__l_bit));
        bufp->chgIData(oldp+114,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__result_out),32);
        bufp->chgQData(oldp+115,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan),37);
        bufp->chgCData(oldp+117,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros),6);
        bufp->chgQData(oldp+118,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val),37);
        bufp->chgIData(oldp+120,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__final_mant),23);
        bufp->chgIData(oldp+121,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__rounded_mant_int),24);
        bufp->chgSData(oldp+122,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__final_exp_calc),11);
        bufp->chgBit(oldp+123,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__guard_bit));
        bufp->chgBit(oldp+124,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__round_bit));
        bufp->chgBit(oldp+125,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_bit));
        bufp->chgBit(oldp+126,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__round_up));
        bufp->chgBit(oldp+127,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__l_bit));
        bufp->chgIData(oldp+128,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__result_out),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[34U]))) {
        bufp->chgQData(oldp+129,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum),37);
        bufp->chgQData(oldp+131,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__mag_sum),37);
        bufp->chgBit(oldp+133,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__res_sign));
        bufp->chgQData(oldp+134,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan),37);
        bufp->chgCData(oldp+136,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros),6);
        bufp->chgQData(oldp+137,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val),37);
        bufp->chgIData(oldp+139,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__final_mant),23);
        bufp->chgIData(oldp+140,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__rounded_mant_int),24);
        bufp->chgSData(oldp+141,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__final_exp_calc),11);
        bufp->chgBit(oldp+142,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__guard_bit));
        bufp->chgBit(oldp+143,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__round_bit));
        bufp->chgBit(oldp+144,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_bit));
        bufp->chgBit(oldp+145,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__round_up));
        bufp->chgBit(oldp+146,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__l_bit));
        bufp->chgIData(oldp+147,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__result_out),32);
        bufp->chgQData(oldp+148,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum),37);
        bufp->chgQData(oldp+150,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__mag_sum),37);
        bufp->chgBit(oldp+152,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__res_sign));
        bufp->chgQData(oldp+153,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum),37);
        bufp->chgQData(oldp+155,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__mag_sum),37);
        bufp->chgBit(oldp+157,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__res_sign));
        bufp->chgQData(oldp+158,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum),37);
        bufp->chgQData(oldp+160,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__mag_sum),37);
        bufp->chgBit(oldp+162,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__res_sign));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[35U]))) {
        bufp->chgQData(oldp+163,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__raw_sum),37);
        bufp->chgQData(oldp+165,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__mag_sum),37);
        bufp->chgBit(oldp+167,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__res_sign));
        bufp->chgSData(oldp+168,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__final_reduce__DOT__new_exp),10);
        bufp->chgCData(oldp+169,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__final_reduce__DOT__rounded),8);
        bufp->chgQData(oldp+170,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum),37);
        bufp->chgQData(oldp+172,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__mag_sum),37);
        bufp->chgBit(oldp+174,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__res_sign));
        bufp->chgQData(oldp+175,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum),37);
        bufp->chgQData(oldp+177,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__mag_sum),37);
        bufp->chgBit(oldp+179,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__res_sign));
        bufp->chgQData(oldp+180,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag),37);
        bufp->chgBit(oldp+182,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_res_sign));
        bufp->chgQData(oldp+183,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan),37);
        bufp->chgCData(oldp+185,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros),6);
        bufp->chgQData(oldp+186,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val),37);
        bufp->chgIData(oldp+188,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__final_mant),23);
        bufp->chgIData(oldp+189,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__rounded_mant_int),24);
        bufp->chgSData(oldp+190,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__final_exp_calc),11);
        bufp->chgBit(oldp+191,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__guard_bit));
        bufp->chgBit(oldp+192,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__round_bit));
        bufp->chgBit(oldp+193,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_bit));
        bufp->chgBit(oldp+194,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__round_up));
        bufp->chgBit(oldp+195,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__l_bit));
        bufp->chgIData(oldp+196,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__result_out),32);
    }
    bufp->chgBit(oldp+197,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_clk));
    bufp->chgSData(oldp+198,(((0x000000ffU == (0x000000ffU 
                                               & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out 
                                                  >> 0x00000017U)))
                               ? ((0x00008000U & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out 
                                                  >> 0x00000010U)) 
                                  | ((0U != (0x007fffffU 
                                             & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out))
                                      ? 0x7fc0U : 0x7f80U))
                               : (VL_LTES_III(10, 0x00ffU, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__final_reduce__DOT__new_exp))
                                   ? (0x7f80U | (0x00008000U 
                                                 & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out 
                                                    >> 0x00000010U)))
                                   : (VL_GTES_III(32, 0U, 
                                                  VL_EXTENDS_II(32,10, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__final_reduce__DOT__new_exp)))
                                       ? (0x00008000U 
                                          & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out 
                                             >> 0x00000010U))
                                       : ((0x00008000U 
                                           & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out 
                                              >> 0x00000010U)) 
                                          | ((0x00007f80U 
                                              & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__final_reduce__DOT__new_exp) 
                                                 << 7U)) 
                                             | ((0x00000080U 
                                                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__final_reduce__DOT__rounded))
                                                 ? 0U
                                                 : 
                                                (0x0000007fU 
                                                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__final_reduce__DOT__rounded))))))))),16);
}

void Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root__trace_cleanup\n"); );
    // Body
    Vadd32_fp32accum_bf16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd32_fp32accum_bf16_tb_softfloat___024root*>(voidSelf);
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[7U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[8U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[9U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[10U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[11U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[12U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[13U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[14U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[15U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[16U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[17U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[18U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[19U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[20U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[21U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[22U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[23U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[24U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[25U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[26U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[27U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[28U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[29U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[30U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[31U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[32U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[33U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[34U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[35U] = 0U;
}
