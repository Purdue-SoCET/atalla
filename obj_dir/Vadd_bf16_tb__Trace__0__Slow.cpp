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
    tracep->declBus(c+140,0,"CLK_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+133,0,"tb_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"tb_nrst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"tb_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+3,0,"tb_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+4,0,"tb_sub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+134,0,"tb_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+112,0,"tb_overflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+113,0,"tb_underflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+91,0,"tb_invalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("A", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 25; ++i) {
        tracep->declBus(c+5+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("B", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 25; ++i) {
        tracep->declBus(c+30+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("EXP", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 25; ++i) {
        tracep->declBus(c+55+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+80,0,"idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+81,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+141,0,"QNAN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+142,0,"POS_INF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+143,0,"NEG_INF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+144,0,"POS_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+145,0,"NEG_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+146,0,"MAX_POS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+147,0,"MAX_NEG",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+82,0,"fd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+83,0,"csv_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+84,0,"csv_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+85,0,"csv_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+86,0,"csv_sub_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+87,0,"csv_sub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+88,0,"pass_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+89,0,"fail_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+133,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"nRST",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"sub",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"bf1_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+3,0,"bf2_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+134,0,"bf_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+112,0,"overflow",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+113,0,"underflow",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+91,0,"invalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+92,0,"bf2_eff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("u_add_bf16", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+133,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"nRST",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"bf1_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+92,0,"bf2_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+134,0,"bf_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+112,0,"overflow",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+113,0,"underflow",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+91,0,"invalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,0,"is_nan1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+94,0,"is_nan2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+95,0,"is_inf1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"is_inf2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+135,0,"sticky_bit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+97,0,"smaller_exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+98,0,"larger_exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+99,0,"exp_select",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"frac_leading_bit_bf1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"frac_leading_bit_bf2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+101,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+102,0,"exp_max",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+103,0,"frac_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+104,0,"frac_not_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+105,0,"sign_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+106,0,"sign_not_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+107,0,"smaller_mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+108,0,"larger_mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+114,0,"mantissa_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBit(c+109,0,"larger_mantissa_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+136,0,"result_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+110,0,"signs_differ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+115,0,"mantissa_overflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+116,0,"smaller_mantissa_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+117,0,"larger_mantissa_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+118,0,"larger_mantissa_sign_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+119,0,"sign_shifted_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+120,0,"sign_not_shifted_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+121,0,"signs_differ_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+122,0,"exp_max_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+123,0,"exp_minus_shift_amount",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+124,0,"normalized_mantissa_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+125,0,"norm_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+126,0,"u_exp1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+127,0,"u_shifted_amount",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+123,0,"u_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+128,0,"round_this",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+129,0,"exp_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+137,0,"rounded_fraction",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+138,0,"exp_out_adj",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+130,0,"G",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+131,0,"R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+139,0,"round_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+111,0,"xor_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,7);
    tracep->pushPrefix("normalizer", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+132,0,"fraction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+124,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+125,0,"shifted_amount",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
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
    bufp->fullIData(oldp+140,(1U),32);
    bufp->fullSData(oldp+141,(0x7fc0U),16);
    bufp->fullSData(oldp+142,(0x7f80U),16);
    bufp->fullSData(oldp+143,(0xff80U),16);
    bufp->fullSData(oldp+144,(0U),16);
    bufp->fullSData(oldp+145,(0x8000U),16);
    bufp->fullSData(oldp+146,(0x7f7fU),16);
    bufp->fullSData(oldp+147,(0xff7fU),16);
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
    bufp->fullSData(oldp+2,(vlSelfRef.add_bf16_tb__DOT__tb_a),16);
    bufp->fullSData(oldp+3,(vlSelfRef.add_bf16_tb__DOT__tb_b),16);
    bufp->fullBit(oldp+4,(vlSelfRef.add_bf16_tb__DOT__tb_sub));
    bufp->fullSData(oldp+5,(vlSelfRef.add_bf16_tb__DOT__A[0]),16);
    bufp->fullSData(oldp+6,(vlSelfRef.add_bf16_tb__DOT__A[1]),16);
    bufp->fullSData(oldp+7,(vlSelfRef.add_bf16_tb__DOT__A[2]),16);
    bufp->fullSData(oldp+8,(vlSelfRef.add_bf16_tb__DOT__A[3]),16);
    bufp->fullSData(oldp+9,(vlSelfRef.add_bf16_tb__DOT__A[4]),16);
    bufp->fullSData(oldp+10,(vlSelfRef.add_bf16_tb__DOT__A[5]),16);
    bufp->fullSData(oldp+11,(vlSelfRef.add_bf16_tb__DOT__A[6]),16);
    bufp->fullSData(oldp+12,(vlSelfRef.add_bf16_tb__DOT__A[7]),16);
    bufp->fullSData(oldp+13,(vlSelfRef.add_bf16_tb__DOT__A[8]),16);
    bufp->fullSData(oldp+14,(vlSelfRef.add_bf16_tb__DOT__A[9]),16);
    bufp->fullSData(oldp+15,(vlSelfRef.add_bf16_tb__DOT__A[10]),16);
    bufp->fullSData(oldp+16,(vlSelfRef.add_bf16_tb__DOT__A[11]),16);
    bufp->fullSData(oldp+17,(vlSelfRef.add_bf16_tb__DOT__A[12]),16);
    bufp->fullSData(oldp+18,(vlSelfRef.add_bf16_tb__DOT__A[13]),16);
    bufp->fullSData(oldp+19,(vlSelfRef.add_bf16_tb__DOT__A[14]),16);
    bufp->fullSData(oldp+20,(vlSelfRef.add_bf16_tb__DOT__A[15]),16);
    bufp->fullSData(oldp+21,(vlSelfRef.add_bf16_tb__DOT__A[16]),16);
    bufp->fullSData(oldp+22,(vlSelfRef.add_bf16_tb__DOT__A[17]),16);
    bufp->fullSData(oldp+23,(vlSelfRef.add_bf16_tb__DOT__A[18]),16);
    bufp->fullSData(oldp+24,(vlSelfRef.add_bf16_tb__DOT__A[19]),16);
    bufp->fullSData(oldp+25,(vlSelfRef.add_bf16_tb__DOT__A[20]),16);
    bufp->fullSData(oldp+26,(vlSelfRef.add_bf16_tb__DOT__A[21]),16);
    bufp->fullSData(oldp+27,(vlSelfRef.add_bf16_tb__DOT__A[22]),16);
    bufp->fullSData(oldp+28,(vlSelfRef.add_bf16_tb__DOT__A[23]),16);
    bufp->fullSData(oldp+29,(vlSelfRef.add_bf16_tb__DOT__A[24]),16);
    bufp->fullSData(oldp+30,(vlSelfRef.add_bf16_tb__DOT__B[0]),16);
    bufp->fullSData(oldp+31,(vlSelfRef.add_bf16_tb__DOT__B[1]),16);
    bufp->fullSData(oldp+32,(vlSelfRef.add_bf16_tb__DOT__B[2]),16);
    bufp->fullSData(oldp+33,(vlSelfRef.add_bf16_tb__DOT__B[3]),16);
    bufp->fullSData(oldp+34,(vlSelfRef.add_bf16_tb__DOT__B[4]),16);
    bufp->fullSData(oldp+35,(vlSelfRef.add_bf16_tb__DOT__B[5]),16);
    bufp->fullSData(oldp+36,(vlSelfRef.add_bf16_tb__DOT__B[6]),16);
    bufp->fullSData(oldp+37,(vlSelfRef.add_bf16_tb__DOT__B[7]),16);
    bufp->fullSData(oldp+38,(vlSelfRef.add_bf16_tb__DOT__B[8]),16);
    bufp->fullSData(oldp+39,(vlSelfRef.add_bf16_tb__DOT__B[9]),16);
    bufp->fullSData(oldp+40,(vlSelfRef.add_bf16_tb__DOT__B[10]),16);
    bufp->fullSData(oldp+41,(vlSelfRef.add_bf16_tb__DOT__B[11]),16);
    bufp->fullSData(oldp+42,(vlSelfRef.add_bf16_tb__DOT__B[12]),16);
    bufp->fullSData(oldp+43,(vlSelfRef.add_bf16_tb__DOT__B[13]),16);
    bufp->fullSData(oldp+44,(vlSelfRef.add_bf16_tb__DOT__B[14]),16);
    bufp->fullSData(oldp+45,(vlSelfRef.add_bf16_tb__DOT__B[15]),16);
    bufp->fullSData(oldp+46,(vlSelfRef.add_bf16_tb__DOT__B[16]),16);
    bufp->fullSData(oldp+47,(vlSelfRef.add_bf16_tb__DOT__B[17]),16);
    bufp->fullSData(oldp+48,(vlSelfRef.add_bf16_tb__DOT__B[18]),16);
    bufp->fullSData(oldp+49,(vlSelfRef.add_bf16_tb__DOT__B[19]),16);
    bufp->fullSData(oldp+50,(vlSelfRef.add_bf16_tb__DOT__B[20]),16);
    bufp->fullSData(oldp+51,(vlSelfRef.add_bf16_tb__DOT__B[21]),16);
    bufp->fullSData(oldp+52,(vlSelfRef.add_bf16_tb__DOT__B[22]),16);
    bufp->fullSData(oldp+53,(vlSelfRef.add_bf16_tb__DOT__B[23]),16);
    bufp->fullSData(oldp+54,(vlSelfRef.add_bf16_tb__DOT__B[24]),16);
    bufp->fullSData(oldp+55,(vlSelfRef.add_bf16_tb__DOT__EXP[0]),16);
    bufp->fullSData(oldp+56,(vlSelfRef.add_bf16_tb__DOT__EXP[1]),16);
    bufp->fullSData(oldp+57,(vlSelfRef.add_bf16_tb__DOT__EXP[2]),16);
    bufp->fullSData(oldp+58,(vlSelfRef.add_bf16_tb__DOT__EXP[3]),16);
    bufp->fullSData(oldp+59,(vlSelfRef.add_bf16_tb__DOT__EXP[4]),16);
    bufp->fullSData(oldp+60,(vlSelfRef.add_bf16_tb__DOT__EXP[5]),16);
    bufp->fullSData(oldp+61,(vlSelfRef.add_bf16_tb__DOT__EXP[6]),16);
    bufp->fullSData(oldp+62,(vlSelfRef.add_bf16_tb__DOT__EXP[7]),16);
    bufp->fullSData(oldp+63,(vlSelfRef.add_bf16_tb__DOT__EXP[8]),16);
    bufp->fullSData(oldp+64,(vlSelfRef.add_bf16_tb__DOT__EXP[9]),16);
    bufp->fullSData(oldp+65,(vlSelfRef.add_bf16_tb__DOT__EXP[10]),16);
    bufp->fullSData(oldp+66,(vlSelfRef.add_bf16_tb__DOT__EXP[11]),16);
    bufp->fullSData(oldp+67,(vlSelfRef.add_bf16_tb__DOT__EXP[12]),16);
    bufp->fullSData(oldp+68,(vlSelfRef.add_bf16_tb__DOT__EXP[13]),16);
    bufp->fullSData(oldp+69,(vlSelfRef.add_bf16_tb__DOT__EXP[14]),16);
    bufp->fullSData(oldp+70,(vlSelfRef.add_bf16_tb__DOT__EXP[15]),16);
    bufp->fullSData(oldp+71,(vlSelfRef.add_bf16_tb__DOT__EXP[16]),16);
    bufp->fullSData(oldp+72,(vlSelfRef.add_bf16_tb__DOT__EXP[17]),16);
    bufp->fullSData(oldp+73,(vlSelfRef.add_bf16_tb__DOT__EXP[18]),16);
    bufp->fullSData(oldp+74,(vlSelfRef.add_bf16_tb__DOT__EXP[19]),16);
    bufp->fullSData(oldp+75,(vlSelfRef.add_bf16_tb__DOT__EXP[20]),16);
    bufp->fullSData(oldp+76,(vlSelfRef.add_bf16_tb__DOT__EXP[21]),16);
    bufp->fullSData(oldp+77,(vlSelfRef.add_bf16_tb__DOT__EXP[22]),16);
    bufp->fullSData(oldp+78,(vlSelfRef.add_bf16_tb__DOT__EXP[23]),16);
    bufp->fullSData(oldp+79,(vlSelfRef.add_bf16_tb__DOT__EXP[24]),16);
    bufp->fullIData(oldp+80,(vlSelfRef.add_bf16_tb__DOT__idx),32);
    bufp->fullIData(oldp+81,(vlSelfRef.add_bf16_tb__DOT__i),32);
    bufp->fullIData(oldp+82,(vlSelfRef.add_bf16_tb__DOT__fd),32);
    bufp->fullSData(oldp+83,(vlSelfRef.add_bf16_tb__DOT__csv_a),16);
    bufp->fullSData(oldp+84,(vlSelfRef.add_bf16_tb__DOT__csv_b),16);
    bufp->fullSData(oldp+85,(vlSelfRef.add_bf16_tb__DOT__csv_exp),16);
    bufp->fullIData(oldp+86,(vlSelfRef.add_bf16_tb__DOT__csv_sub_i),32);
    bufp->fullBit(oldp+87,(vlSelfRef.add_bf16_tb__DOT__csv_sub));
    bufp->fullIData(oldp+88,(vlSelfRef.add_bf16_tb__DOT__pass_cnt),32);
    bufp->fullIData(oldp+89,(vlSelfRef.add_bf16_tb__DOT__fail_cnt),32);
    bufp->fullBit(oldp+90,((0U != (0xffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                                            >> 7U)))));
    bufp->fullBit(oldp+91,(vlSelfRef.add_bf16_tb__DOT__tb_invalid));
    bufp->fullSData(oldp+92,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff),16);
    bufp->fullBit(oldp+93,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_nan1));
    bufp->fullBit(oldp+94,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_nan2));
    bufp->fullBit(oldp+95,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_inf1));
    bufp->fullBit(oldp+96,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_inf2));
    bufp->fullCData(oldp+97,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__smaller_exponent),8);
    bufp->fullCData(oldp+98,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_exponent),8);
    bufp->fullBit(oldp+99,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_select));
    bufp->fullBit(oldp+100,((0U != (0xffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff) 
                                             >> 7U)))));
    bufp->fullCData(oldp+101,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_diff),8);
    bufp->fullCData(oldp+102,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_max),8);
    bufp->fullSData(oldp+103,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__frac_shifted),10);
    bufp->fullSData(oldp+104,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__frac_not_shifted),10);
    bufp->fullBit(oldp+105,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_shifted));
    bufp->fullBit(oldp+106,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_not_shifted));
    bufp->fullSData(oldp+107,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__smaller_mantissa),10);
    bufp->fullSData(oldp+108,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa),10);
    bufp->fullBit(oldp+109,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa_sign));
    bufp->fullBit(oldp+110,(((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_shifted) 
                             ^ (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_not_shifted))));
    bufp->fullSData(oldp+111,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__xor_out),9);
    bufp->fullBit(oldp+112,(((0xffU == (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_max_l)) 
                             | ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__mantissa_overflow) 
                                & (0xfeU == (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_max_l))))));
    bufp->fullBit(oldp+113,(((0U == (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__u_result)) 
                             | ((~ ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__u_result) 
                                    >> 7U)) & (0U != 
                                               (3U 
                                                & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__u_result) 
                                                   >> 6U)))))));
    bufp->fullSData(oldp+114,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__mantissa_sum),11);
    bufp->fullBit(oldp+115,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__mantissa_overflow));
    bufp->fullSData(oldp+116,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__smaller_mantissa_l),10);
    bufp->fullSData(oldp+117,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa_l),10);
    bufp->fullBit(oldp+118,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__larger_mantissa_sign_l));
    bufp->fullBit(oldp+119,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_shifted_l));
    bufp->fullBit(oldp+120,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__sign_not_shifted_l));
    bufp->fullBit(oldp+121,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__signs_differ_l));
    bufp->fullCData(oldp+122,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_max_l),8);
    bufp->fullCData(oldp+123,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__u_result),8);
    bufp->fullSData(oldp+124,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__normalized_mantissa_sum),9);
    bufp->fullCData(oldp+125,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__norm_shift),4);
    bufp->fullCData(oldp+126,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__u_exp1),8);
    bufp->fullCData(oldp+127,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__u_shifted_amount),8);
    bufp->fullSData(oldp+128,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__round_this),9);
    bufp->fullCData(oldp+129,((0xffU & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__mantissa_overflow)
                                         ? ((IData)(1U) 
                                            + (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_max_l))
                                         : (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__u_result)))),8);
    bufp->fullBit(oldp+130,((1U & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__round_this) 
                                   >> 1U))));
    bufp->fullBit(oldp+131,((1U & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__round_this))));
    bufp->fullSData(oldp+132,((0x3ffU & (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__mantissa_sum))),10);
    bufp->fullBit(oldp+133,(vlSelfRef.add_bf16_tb__DOT__tb_clk));
    bufp->fullSData(oldp+134,(((((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__is_inf1) 
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
                                                : (
                                                   ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_out_adj) 
                                                       << 7U) 
                                                      | (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__rounded_fraction))))))))),16);
    bufp->fullBit(oldp+135,(((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_select)
                              ? (0U != ((((0U != (0xffU 
                                                  & ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff) 
                                                     >> 7U))) 
                                          << 9U) | 
                                         (0x1fcU & 
                                          ((IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__bf2_eff) 
                                           << 2U))) 
                                        & (VL_SHIFTL_III(32,32,8, (IData)(1U), (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_diff)) 
                                           - (IData)(1U))))
                              : (0U != ((((0U != (0xffU 
                                                  & ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                                                     >> 7U))) 
                                          << 9U) | 
                                         (0x1fcU & 
                                          ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_a) 
                                           << 2U))) 
                                        & (VL_SHIFTL_III(32,32,8, (IData)(1U), (IData)(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_diff)) 
                                           - (IData)(1U)))))));
    bufp->fullBit(oldp+136,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__result_sign));
    bufp->fullCData(oldp+137,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__rounded_fraction),7);
    bufp->fullCData(oldp+138,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__exp_out_adj),8);
    bufp->fullCData(oldp+139,(vlSelfRef.add_bf16_tb__DOT__dut__DOT__u_add_bf16__DOT__round_sum),8);
}
