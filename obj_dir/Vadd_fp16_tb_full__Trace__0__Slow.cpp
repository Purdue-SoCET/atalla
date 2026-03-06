// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadd_fp16_tb_full__Syms.h"


VL_ATTR_COLD void Vadd_fp16_tb_full___024root__trace_init_sub__TOP__0(Vadd_fp16_tb_full___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root__trace_init_sub__TOP__0\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("add_fp16_tb_full", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+80,0,"PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+79,0,"tb_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"tb_nrst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"tb_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+3,0,"tb_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+4,0,"tb_start",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"tb_sub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+47,0,"tb_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+48,0,"tb_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+7,0,"pass_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+8,0,"fail_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+81,0,"P_INF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+82,0,"N_INF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+83,0,"NAN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+84,0,"P_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+85,0,"N_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+86,0,"ONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+87,0,"TWO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+88,0,"MIN_SUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+89,0,"MAX_FINITE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+9,0,"fd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+10,0,"a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+11,0,"b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+12,0,"expected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+79,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"nRST",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"stall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"sub",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"fp1_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+3,0,"fp2_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+47,0,"fp_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+48,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+16,0,"a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+17,0,"b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+18,0,"is_nan_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"is_nan_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"is_inf_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"is_inf_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"special_case",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+23,0,"special_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+24,0,"op_swap",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+25,0,"high_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+26,0,"low_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+27,0,"high_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+28,0,"low_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+29,0,"mant_hi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+30,0,"mant_lo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+31,0,"mant_lo_aligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+32,0,"mask_align",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBit(c+33,0,"sticky_align_local",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"sticky_lost",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+35,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+36,0,"exp_max",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+37,0,"frac_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+38,0,"frac_not_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBit(c+39,0,"sign_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"sign_not_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+41,0,"smaller_mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+42,0,"larger_mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+49,0,"mantissa_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBit(c+43,0,"larger_mantissa_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"result_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+44,0,"signs_differ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+51,0,"mantissa_overflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"sub_has_lost_sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"sub_has_added_sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+52,0,"smaller_mantissa_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+53,0,"larger_mantissa_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBit(c+54,0,"larger_mantissa_sign_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"sign_shifted_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"sign_not_shifted_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"signs_differ_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+58,0,"exp_max_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+59,0,"special_case_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+60,0,"special_result_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+61,0,"sub_has_lost_sticky_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"sub_has_added_sticky_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+63,0,"normalized_mantissa_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+64,0,"norm_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+65,0,"exp_norm_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+66,0,"round_this",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+67,0,"exp_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+68,0,"ftz_under",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"round_inc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+70,0,"frac_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBit(c+71,0,"frac_carry",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+72,0,"exp_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+73,0,"rounded_fraction",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+74,0,"overflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+75,0,"exp_out_final",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+76,0,"rounded_fraction_final",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->pushPrefix("normalizer", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+77,0,"fraction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+63,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+78,0,"shifted_amount",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+13,0,"ret",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+14,0,"sub_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+15,0,"is_zero_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vadd_fp16_tb_full___024root__trace_init_top(Vadd_fp16_tb_full___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root__trace_init_top\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vadd_fp16_tb_full___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vadd_fp16_tb_full___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vadd_fp16_tb_full___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadd_fp16_tb_full___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadd_fp16_tb_full___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vadd_fp16_tb_full___024root__trace_register(Vadd_fp16_tb_full___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root__trace_register\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vadd_fp16_tb_full___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vadd_fp16_tb_full___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vadd_fp16_tb_full___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vadd_fp16_tb_full___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vadd_fp16_tb_full___024root__trace_const_0_sub_0(Vadd_fp16_tb_full___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vadd_fp16_tb_full___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root__trace_const_0\n"); );
    // Init
    Vadd_fp16_tb_full___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd_fp16_tb_full___024root*>(voidSelf);
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vadd_fp16_tb_full___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vadd_fp16_tb_full___024root__trace_const_0_sub_0(Vadd_fp16_tb_full___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root__trace_const_0_sub_0\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+80,(2U),32);
    bufp->fullSData(oldp+81,(0x7c00U),16);
    bufp->fullSData(oldp+82,(0xfc00U),16);
    bufp->fullSData(oldp+83,(0x7d00U),16);
    bufp->fullSData(oldp+84,(0U),16);
    bufp->fullSData(oldp+85,(0x8000U),16);
    bufp->fullSData(oldp+86,(0x3c00U),16);
    bufp->fullSData(oldp+87,(0x4000U),16);
    bufp->fullSData(oldp+88,(1U),16);
    bufp->fullSData(oldp+89,(0x7bffU),16);
    bufp->fullBit(oldp+90,(0U));
}

VL_ATTR_COLD void Vadd_fp16_tb_full___024root__trace_full_0_sub_0(Vadd_fp16_tb_full___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vadd_fp16_tb_full___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root__trace_full_0\n"); );
    // Init
    Vadd_fp16_tb_full___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd_fp16_tb_full___024root*>(voidSelf);
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vadd_fp16_tb_full___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vadd_fp16_tb_full___024root__trace_full_0_sub_0(Vadd_fp16_tb_full___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root__trace_full_0_sub_0\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.add_fp16_tb_full__DOT__tb_nrst));
    bufp->fullSData(oldp+2,(vlSelfRef.add_fp16_tb_full__DOT__tb_a),16);
    bufp->fullSData(oldp+3,(vlSelfRef.add_fp16_tb_full__DOT__tb_b),16);
    bufp->fullBit(oldp+4,(vlSelfRef.add_fp16_tb_full__DOT__tb_start));
    bufp->fullBit(oldp+5,(vlSelfRef.add_fp16_tb_full__DOT__tb_sub));
    bufp->fullSData(oldp+6,(vlSelfRef.add_fp16_tb_full__DOT__exp),16);
    bufp->fullIData(oldp+7,(vlSelfRef.add_fp16_tb_full__DOT__pass_count),32);
    bufp->fullIData(oldp+8,(vlSelfRef.add_fp16_tb_full__DOT__fail_count),32);
    bufp->fullIData(oldp+9,(vlSelfRef.add_fp16_tb_full__DOT__fd),32);
    bufp->fullSData(oldp+10,(vlSelfRef.add_fp16_tb_full__DOT__a),16);
    bufp->fullSData(oldp+11,(vlSelfRef.add_fp16_tb_full__DOT__b),16);
    bufp->fullSData(oldp+12,(vlSelfRef.add_fp16_tb_full__DOT__expected),16);
    bufp->fullIData(oldp+13,(vlSelfRef.add_fp16_tb_full__DOT__unnamedblk1__DOT__ret),32);
    bufp->fullIData(oldp+14,(vlSelfRef.add_fp16_tb_full__DOT__unnamedblk1__DOT__sub_flag),32);
    bufp->fullBit(oldp+15,(vlSelfRef.add_fp16_tb_full__DOT__unnamedblk1__DOT__is_zero_result));
    bufp->fullSData(oldp+16,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a),16);
    bufp->fullSData(oldp+17,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b),16);
    bufp->fullBit(oldp+18,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_nan_a));
    bufp->fullBit(oldp+19,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_nan_b));
    bufp->fullBit(oldp+20,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_inf_a));
    bufp->fullBit(oldp+21,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_inf_b));
    bufp->fullBit(oldp+22,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case));
    bufp->fullSData(oldp+23,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result),16);
    bufp->fullBit(oldp+24,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__op_swap));
    bufp->fullSData(oldp+25,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__high_op),16);
    bufp->fullSData(oldp+26,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__low_op),16);
    bufp->fullCData(oldp+27,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__high_exp),5);
    bufp->fullCData(oldp+28,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__low_exp),5);
    bufp->fullSData(oldp+29,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_hi),13);
    bufp->fullSData(oldp+30,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo),13);
    bufp->fullSData(oldp+31,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo_aligned),13);
    bufp->fullSData(oldp+32,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mask_align),13);
    bufp->fullBit(oldp+33,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sticky_align_local));
    bufp->fullBit(oldp+34,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sticky_lost));
    bufp->fullCData(oldp+35,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_diff),5);
    bufp->fullCData(oldp+36,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_max),5);
    bufp->fullSData(oldp+37,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_shifted),13);
    bufp->fullSData(oldp+38,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_not_shifted),13);
    bufp->fullBit(oldp+39,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_shifted));
    bufp->fullBit(oldp+40,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_not_shifted));
    bufp->fullSData(oldp+41,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__smaller_mantissa),13);
    bufp->fullSData(oldp+42,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa),13);
    bufp->fullBit(oldp+43,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa_sign));
    bufp->fullBit(oldp+44,(((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_shifted) 
                            ^ (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_not_shifted))));
    bufp->fullBit(oldp+45,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sub_has_lost_sticky));
    bufp->fullBit(oldp+46,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sub_has_added_sticky));
    bufp->fullSData(oldp+47,(((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                               ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                               : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                   ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                   ? 
                                                  ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                   : 
                                                  (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))))),16);
    bufp->fullBit(oldp+48,(vlSelfRef.add_fp16_tb_full__DOT__tb_done));
    bufp->fullSData(oldp+49,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum),14);
    bufp->fullBit(oldp+50,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign));
    bufp->fullBit(oldp+51,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_overflow));
    bufp->fullSData(oldp+52,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__smaller_mantissa_l),13);
    bufp->fullSData(oldp+53,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa_l),13);
    bufp->fullBit(oldp+54,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa_sign_l));
    bufp->fullBit(oldp+55,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_shifted_l));
    bufp->fullBit(oldp+56,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_not_shifted_l));
    bufp->fullBit(oldp+57,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__signs_differ_l));
    bufp->fullCData(oldp+58,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_max_l),5);
    bufp->fullBit(oldp+59,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l));
    bufp->fullSData(oldp+60,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l),16);
    bufp->fullBit(oldp+61,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sub_has_lost_sticky_l));
    bufp->fullBit(oldp+62,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sub_has_added_sticky_l));
    bufp->fullSData(oldp+63,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum),13);
    bufp->fullCData(oldp+64,((0xfU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount))),4);
    bufp->fullCData(oldp+65,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_norm_s),7);
    bufp->fullSData(oldp+66,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_this),12);
    bufp->fullCData(oldp+67,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_base),6);
    bufp->fullBit(oldp+68,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under));
    bufp->fullBit(oldp+69,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_inc));
    bufp->fullSData(oldp+70,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_sum),11);
    bufp->fullBit(oldp+71,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_carry));
    bufp->fullCData(oldp+72,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out),6);
    bufp->fullSData(oldp+73,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction),10);
    bufp->fullBit(oldp+74,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__overflow));
    bufp->fullCData(oldp+75,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final),5);
    bufp->fullSData(oldp+76,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final),10);
    bufp->fullSData(oldp+77,((0x1fffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))),13);
    bufp->fullCData(oldp+78,(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount),5);
    bufp->fullBit(oldp+79,(vlSelfRef.add_fp16_tb_full__DOT__tb_clk));
}
