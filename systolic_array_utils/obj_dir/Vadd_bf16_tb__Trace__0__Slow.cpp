// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadd_bf16_tb__Syms.h"


VL_ATTR_COLD void Vadd_bf16_tb___024root__trace_init_sub__TOP__0(Vadd_bf16_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root__trace_init_sub__TOP__0\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("add_bf16_tb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+132,0,"CLK_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+126,0,"tb_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"tb_nrst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+3,0,"tb_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+4,0,"tb_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+5,0,"tb_start",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+127,0,"tb_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+133,0,"tb_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+103,0,"tb_overflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+104,0,"tb_underflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"tb_invalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("test_set1", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 25; ++i) {
        tracep->declBus(c+6+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("test_set2", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 25; ++i) {
        tracep->declBus(c+31+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("expected_out", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 25; ++i) {
        tracep->declBus(c+56+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+134,0,"QNAN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+135,0,"POS_INF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+136,0,"NEG_INF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+137,0,"POS_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+138,0,"NEG_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+139,0,"MAX_POS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+140,0,"MAX_NEG",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+81,0,"idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("bob", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+126,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"nRST",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"bf1_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+4,0,"bf2_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+127,0,"bf_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+103,0,"overflow",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+104,0,"underflow",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"invalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"is_nan1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"is_nan2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"is_inf1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"is_inf2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"sticky_bit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+90,0,"smaller_exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+91,0,"larger_exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+92,0,"exp_select",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"frac_leading_bit_bf1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"frac_leading_bit_bf2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+93,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+96,0,"exp_max",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+94,0,"frac_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+95,0,"frac_not_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+97,0,"sign_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"sign_not_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+99,0,"smaller_mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+100,0,"larger_mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+105,0,"mantissa_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBit(c+101,0,"larger_mantissa_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+106,0,"result_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+102,0,"signs_differ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+107,0,"mantissa_overflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+108,0,"smaller_mantissa_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+109,0,"larger_mantissa_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+110,0,"larger_mantissa_sign_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+111,0,"sign_shifted_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+112,0,"sign_not_shifted_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+113,0,"signs_differ_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+114,0,"exp_max_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+115,0,"exp_minus_shift_amount",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+116,0,"normalized_mantissa_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+117,0,"norm_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+118,0,"u_exp1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+141,0,"u_exp2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+119,0,"u_shifted_amount",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+120,0,"u_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+121,0,"round_this",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+122,0,"exp_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+142,0,"round_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+128,0,"round_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+129,0,"rounded_fraction",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+130,0,"exp_out_adj",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+123,0,"G",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+131,0,"round_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("normalizer", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+125,0,"fraction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+116,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+117,0,"shifted_amount",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vadd_bf16_tb___024root__trace_init_top(Vadd_bf16_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root__trace_init_top\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vadd_bf16_tb___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vadd_bf16_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vadd_bf16_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadd_bf16_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadd_bf16_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vadd_bf16_tb___024root__trace_register(Vadd_bf16_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root__trace_register\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vadd_bf16_tb___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vadd_bf16_tb___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vadd_bf16_tb___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vadd_bf16_tb___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vadd_bf16_tb___024root__trace_const_0_sub_0(Vadd_bf16_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vadd_bf16_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root__trace_const_0\n"); );
    // Init
    Vadd_bf16_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd_bf16_tb___024root*>(voidSelf);
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vadd_bf16_tb___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vadd_bf16_tb___024root__trace_const_0_sub_0(Vadd_bf16_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root__trace_const_0_sub_0\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+132,(1U),32);
    bufp->fullBit(oldp+133,(vlSelfRef.add_bf16_tb__DOT__tb_done));
    bufp->fullSData(oldp+134,(0x7fc0U),16);
    bufp->fullSData(oldp+135,(0x7f80U),16);
    bufp->fullSData(oldp+136,(0xff80U),16);
    bufp->fullSData(oldp+137,(0U),16);
    bufp->fullSData(oldp+138,(0x8000U),16);
    bufp->fullSData(oldp+139,(0x7f7fU),16);
    bufp->fullSData(oldp+140,(0xff7fU),16);
    bufp->fullSData(oldp+141,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__u_exp2),9);
    bufp->fullSData(oldp+142,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__round_out),16);
}

VL_ATTR_COLD void Vadd_bf16_tb___024root__trace_full_0_sub_0(Vadd_bf16_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vadd_bf16_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root__trace_full_0\n"); );
    // Init
    Vadd_bf16_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd_bf16_tb___024root*>(voidSelf);
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vadd_bf16_tb___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vadd_bf16_tb___024root__trace_full_0_sub_0(Vadd_bf16_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root__trace_full_0_sub_0\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.add_bf16_tb__DOT__tb_nrst));
    bufp->fullIData(oldp+2,(vlSelfRef.add_bf16_tb__DOT__i),32);
    bufp->fullSData(oldp+3,(vlSelfRef.add_bf16_tb__DOT__tb_a),16);
    bufp->fullSData(oldp+4,(vlSelfRef.add_bf16_tb__DOT__tb_b),16);
    bufp->fullBit(oldp+5,(vlSelfRef.add_bf16_tb__DOT__tb_start));
    bufp->fullSData(oldp+6,(vlSelfRef.add_bf16_tb__DOT__test_set1[0]),16);
    bufp->fullSData(oldp+7,(vlSelfRef.add_bf16_tb__DOT__test_set1[1]),16);
    bufp->fullSData(oldp+8,(vlSelfRef.add_bf16_tb__DOT__test_set1[2]),16);
    bufp->fullSData(oldp+9,(vlSelfRef.add_bf16_tb__DOT__test_set1[3]),16);
    bufp->fullSData(oldp+10,(vlSelfRef.add_bf16_tb__DOT__test_set1[4]),16);
    bufp->fullSData(oldp+11,(vlSelfRef.add_bf16_tb__DOT__test_set1[5]),16);
    bufp->fullSData(oldp+12,(vlSelfRef.add_bf16_tb__DOT__test_set1[6]),16);
    bufp->fullSData(oldp+13,(vlSelfRef.add_bf16_tb__DOT__test_set1[7]),16);
    bufp->fullSData(oldp+14,(vlSelfRef.add_bf16_tb__DOT__test_set1[8]),16);
    bufp->fullSData(oldp+15,(vlSelfRef.add_bf16_tb__DOT__test_set1[9]),16);
    bufp->fullSData(oldp+16,(vlSelfRef.add_bf16_tb__DOT__test_set1[10]),16);
    bufp->fullSData(oldp+17,(vlSelfRef.add_bf16_tb__DOT__test_set1[11]),16);
    bufp->fullSData(oldp+18,(vlSelfRef.add_bf16_tb__DOT__test_set1[12]),16);
    bufp->fullSData(oldp+19,(vlSelfRef.add_bf16_tb__DOT__test_set1[13]),16);
    bufp->fullSData(oldp+20,(vlSelfRef.add_bf16_tb__DOT__test_set1[14]),16);
    bufp->fullSData(oldp+21,(vlSelfRef.add_bf16_tb__DOT__test_set1[15]),16);
    bufp->fullSData(oldp+22,(vlSelfRef.add_bf16_tb__DOT__test_set1[16]),16);
    bufp->fullSData(oldp+23,(vlSelfRef.add_bf16_tb__DOT__test_set1[17]),16);
    bufp->fullSData(oldp+24,(vlSelfRef.add_bf16_tb__DOT__test_set1[18]),16);
    bufp->fullSData(oldp+25,(vlSelfRef.add_bf16_tb__DOT__test_set1[19]),16);
    bufp->fullSData(oldp+26,(vlSelfRef.add_bf16_tb__DOT__test_set1[20]),16);
    bufp->fullSData(oldp+27,(vlSelfRef.add_bf16_tb__DOT__test_set1[21]),16);
    bufp->fullSData(oldp+28,(vlSelfRef.add_bf16_tb__DOT__test_set1[22]),16);
    bufp->fullSData(oldp+29,(vlSelfRef.add_bf16_tb__DOT__test_set1[23]),16);
    bufp->fullSData(oldp+30,(vlSelfRef.add_bf16_tb__DOT__test_set1[24]),16);
    bufp->fullSData(oldp+31,(vlSelfRef.add_bf16_tb__DOT__test_set2[0]),16);
    bufp->fullSData(oldp+32,(vlSelfRef.add_bf16_tb__DOT__test_set2[1]),16);
    bufp->fullSData(oldp+33,(vlSelfRef.add_bf16_tb__DOT__test_set2[2]),16);
    bufp->fullSData(oldp+34,(vlSelfRef.add_bf16_tb__DOT__test_set2[3]),16);
    bufp->fullSData(oldp+35,(vlSelfRef.add_bf16_tb__DOT__test_set2[4]),16);
    bufp->fullSData(oldp+36,(vlSelfRef.add_bf16_tb__DOT__test_set2[5]),16);
    bufp->fullSData(oldp+37,(vlSelfRef.add_bf16_tb__DOT__test_set2[6]),16);
    bufp->fullSData(oldp+38,(vlSelfRef.add_bf16_tb__DOT__test_set2[7]),16);
    bufp->fullSData(oldp+39,(vlSelfRef.add_bf16_tb__DOT__test_set2[8]),16);
    bufp->fullSData(oldp+40,(vlSelfRef.add_bf16_tb__DOT__test_set2[9]),16);
    bufp->fullSData(oldp+41,(vlSelfRef.add_bf16_tb__DOT__test_set2[10]),16);
    bufp->fullSData(oldp+42,(vlSelfRef.add_bf16_tb__DOT__test_set2[11]),16);
    bufp->fullSData(oldp+43,(vlSelfRef.add_bf16_tb__DOT__test_set2[12]),16);
    bufp->fullSData(oldp+44,(vlSelfRef.add_bf16_tb__DOT__test_set2[13]),16);
    bufp->fullSData(oldp+45,(vlSelfRef.add_bf16_tb__DOT__test_set2[14]),16);
    bufp->fullSData(oldp+46,(vlSelfRef.add_bf16_tb__DOT__test_set2[15]),16);
    bufp->fullSData(oldp+47,(vlSelfRef.add_bf16_tb__DOT__test_set2[16]),16);
    bufp->fullSData(oldp+48,(vlSelfRef.add_bf16_tb__DOT__test_set2[17]),16);
    bufp->fullSData(oldp+49,(vlSelfRef.add_bf16_tb__DOT__test_set2[18]),16);
    bufp->fullSData(oldp+50,(vlSelfRef.add_bf16_tb__DOT__test_set2[19]),16);
    bufp->fullSData(oldp+51,(vlSelfRef.add_bf16_tb__DOT__test_set2[20]),16);
    bufp->fullSData(oldp+52,(vlSelfRef.add_bf16_tb__DOT__test_set2[21]),16);
    bufp->fullSData(oldp+53,(vlSelfRef.add_bf16_tb__DOT__test_set2[22]),16);
    bufp->fullSData(oldp+54,(vlSelfRef.add_bf16_tb__DOT__test_set2[23]),16);
    bufp->fullSData(oldp+55,(vlSelfRef.add_bf16_tb__DOT__test_set2[24]),16);
    bufp->fullSData(oldp+56,(vlSelfRef.add_bf16_tb__DOT__expected_out[0]),16);
    bufp->fullSData(oldp+57,(vlSelfRef.add_bf16_tb__DOT__expected_out[1]),16);
    bufp->fullSData(oldp+58,(vlSelfRef.add_bf16_tb__DOT__expected_out[2]),16);
    bufp->fullSData(oldp+59,(vlSelfRef.add_bf16_tb__DOT__expected_out[3]),16);
    bufp->fullSData(oldp+60,(vlSelfRef.add_bf16_tb__DOT__expected_out[4]),16);
    bufp->fullSData(oldp+61,(vlSelfRef.add_bf16_tb__DOT__expected_out[5]),16);
    bufp->fullSData(oldp+62,(vlSelfRef.add_bf16_tb__DOT__expected_out[6]),16);
    bufp->fullSData(oldp+63,(vlSelfRef.add_bf16_tb__DOT__expected_out[7]),16);
    bufp->fullSData(oldp+64,(vlSelfRef.add_bf16_tb__DOT__expected_out[8]),16);
    bufp->fullSData(oldp+65,(vlSelfRef.add_bf16_tb__DOT__expected_out[9]),16);
    bufp->fullSData(oldp+66,(vlSelfRef.add_bf16_tb__DOT__expected_out[10]),16);
    bufp->fullSData(oldp+67,(vlSelfRef.add_bf16_tb__DOT__expected_out[11]),16);
    bufp->fullSData(oldp+68,(vlSelfRef.add_bf16_tb__DOT__expected_out[12]),16);
    bufp->fullSData(oldp+69,(vlSelfRef.add_bf16_tb__DOT__expected_out[13]),16);
    bufp->fullSData(oldp+70,(vlSelfRef.add_bf16_tb__DOT__expected_out[14]),16);
    bufp->fullSData(oldp+71,(vlSelfRef.add_bf16_tb__DOT__expected_out[15]),16);
    bufp->fullSData(oldp+72,(vlSelfRef.add_bf16_tb__DOT__expected_out[16]),16);
    bufp->fullSData(oldp+73,(vlSelfRef.add_bf16_tb__DOT__expected_out[17]),16);
    bufp->fullSData(oldp+74,(vlSelfRef.add_bf16_tb__DOT__expected_out[18]),16);
    bufp->fullSData(oldp+75,(vlSelfRef.add_bf16_tb__DOT__expected_out[19]),16);
    bufp->fullSData(oldp+76,(vlSelfRef.add_bf16_tb__DOT__expected_out[20]),16);
    bufp->fullSData(oldp+77,(vlSelfRef.add_bf16_tb__DOT__expected_out[21]),16);
    bufp->fullSData(oldp+78,(vlSelfRef.add_bf16_tb__DOT__expected_out[22]),16);
    bufp->fullSData(oldp+79,(vlSelfRef.add_bf16_tb__DOT__expected_out[23]),16);
    bufp->fullSData(oldp+80,(vlSelfRef.add_bf16_tb__DOT__expected_out[24]),16);
    bufp->fullIData(oldp+81,(vlSelfRef.add_bf16_tb__DOT__idx),32);
    bufp->fullBit(oldp+82,((0U != (0xffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                                            >> 7U)))));
    bufp->fullBit(oldp+83,((0U != (0xffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_b) 
                                            >> 7U)))));
    bufp->fullBit(oldp+84,(vlSelfRef.add_bf16_tb__DOT__tb_invalid));
    bufp->fullBit(oldp+85,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__is_nan1));
    bufp->fullBit(oldp+86,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__is_nan2));
    bufp->fullBit(oldp+87,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__is_inf1));
    bufp->fullBit(oldp+88,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__is_inf2));
    bufp->fullBit(oldp+89,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__sticky_bit));
    bufp->fullCData(oldp+90,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__smaller_exponent),8);
    bufp->fullCData(oldp+91,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__larger_exponent),8);
    bufp->fullBit(oldp+92,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__exp_select));
    bufp->fullCData(oldp+93,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__exp_diff),8);
    bufp->fullSData(oldp+94,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__frac_shifted),10);
    bufp->fullSData(oldp+95,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__frac_not_shifted),10);
    bufp->fullCData(oldp+96,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__exp_max),8);
    bufp->fullBit(oldp+97,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__sign_shifted));
    bufp->fullBit(oldp+98,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__sign_not_shifted));
    bufp->fullSData(oldp+99,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__smaller_mantissa),10);
    bufp->fullSData(oldp+100,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__larger_mantissa),10);
    bufp->fullBit(oldp+101,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__larger_mantissa_sign));
    bufp->fullBit(oldp+102,(((IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__sign_shifted) 
                             ^ (IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__sign_not_shifted))));
    bufp->fullBit(oldp+103,(((0xffU == (IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__exp_max_l)) 
                             | ((IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__mantissa_overflow) 
                                & (0xfeU == (IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__exp_max_l))))));
    bufp->fullBit(oldp+104,(((0U == (0xffU & (IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__u_result))) 
                             | ((~ ((IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__u_result) 
                                    >> 7U)) & (0U != 
                                               (3U 
                                                & ((IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__u_result) 
                                                   >> 6U)))))));
    bufp->fullSData(oldp+105,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__mantissa_sum),11);
    bufp->fullBit(oldp+106,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__result_sign));
    bufp->fullBit(oldp+107,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__mantissa_overflow));
    bufp->fullSData(oldp+108,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__smaller_mantissa_l),10);
    bufp->fullSData(oldp+109,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__larger_mantissa_l),10);
    bufp->fullBit(oldp+110,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__larger_mantissa_sign_l));
    bufp->fullBit(oldp+111,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__sign_shifted_l));
    bufp->fullBit(oldp+112,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__sign_not_shifted_l));
    bufp->fullBit(oldp+113,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__signs_differ_l));
    bufp->fullCData(oldp+114,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__exp_max_l),8);
    bufp->fullCData(oldp+115,((0xffU & (IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__u_result))),8);
    bufp->fullSData(oldp+116,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__normalized_mantissa_sum),10);
    bufp->fullCData(oldp+117,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__norm_shift),4);
    bufp->fullSData(oldp+118,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__u_exp1),9);
    bufp->fullCData(oldp+119,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__u_shifted_amount),8);
    bufp->fullSData(oldp+120,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__u_result),9);
    bufp->fullSData(oldp+121,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__round_this),9);
    bufp->fullCData(oldp+122,((0xffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__mantissa_overflow)
                                         ? ((IData)(1U) 
                                            + (IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__exp_max_l))
                                         : (IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__u_result)))),8);
    bufp->fullBit(oldp+123,((1U & ((IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__round_this) 
                                   >> 1U))));
    bufp->fullBit(oldp+124,((1U & (IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__round_this))));
    bufp->fullSData(oldp+125,((0x3ffU & (IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__mantissa_sum))),10);
    bufp->fullBit(oldp+126,(vlSelfRef.add_bf16_tb__DOT__tb_clk));
    bufp->fullSData(oldp+127,((((IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__result_sign) 
                                << 0xfU) | (((IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__exp_out_adj) 
                                             << 7U) 
                                            | (IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__rounded_fraction)))),16);
    bufp->fullBit(oldp+128,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__round_flag));
    bufp->fullCData(oldp+129,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__rounded_fraction),7);
    bufp->fullCData(oldp+130,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__exp_out_adj),8);
    bufp->fullCData(oldp+131,(vlSelfRef.add_bf16_tb__DOT__bob__DOT__round_sum),8);
}
