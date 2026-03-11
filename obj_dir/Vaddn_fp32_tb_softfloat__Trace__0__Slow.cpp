// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vaddn_fp32_tb_softfloat__Syms.h"


VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root__trace_init_sub__TOP__0(Vaddn_fp32_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root__trace_init_sub__TOP__0\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("addn_fp32_tb_softfloat", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+187,0,"NUM_INPUTS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+188,0,"PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+187,0,"LATENCY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+189,0,"PRECISION_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+190,0,"EXPONENT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+191,0,"MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+191,0,"IN_MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+190,0,"IN_EXPONENT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+186,0,"tb_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"tb_nrst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+2,0,"tb_in_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBus(c+145,0,"tb_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+6,0,"exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"pass_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+8,0,"fail_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+9,0,"off_by_one",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+10,0,"off_by_two",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+11,0,"off_by_five_plus",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+12,0,"diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+192,0,"P_INF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+193,0,"N_INF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+194,0,"NAN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+195,0,"P_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+196,0,"N_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+197,0,"ONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+198,0,"TWO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+199,0,"THREE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+200,0,"FOUR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+201,0,"MIN_SUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+202,0,"MAX_FINITE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"fd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+14,0,"fail_fd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+15,0,"a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,0,"b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+17,0,"c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"expected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+20,0,"total_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+187,0,"NUM_INPUTS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+191,0,"MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+190,0,"EXPONENT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+191,0,"IN_MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+190,0,"IN_EXPONENT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+189,0,"PRECISION_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+186,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"nRST",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+2,0,"in_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBus(c+145,0,"out_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+203,0,"NEW_MANT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+204,0,"SUM_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+205,0,"MAX_EXP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+206,0,"RES_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+207,0,"BIAS_DIFF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+206,0,"IN_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+208,0,"HOT_ONES_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+188,0,"LEVELS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+187,0,"P",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+188,0,"IDX_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("daz_in", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+24+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("exp", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+28+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("frac", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+32+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 22,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("sign", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBit(c+36+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("tree_exp", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->pushPrefix("[0]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+40,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+41,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+42,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+43,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("[1]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+44,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+45,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+46,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+47,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("[2]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+48,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+49,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+50,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+51,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("tree_idx", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->pushPrefix("[0]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+52,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+53,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+54,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+55,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("[1]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+56,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+57,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+58,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+59,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("[2]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+60,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+61,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+62,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+63,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->declBus(c+64,0,"max_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+65,0,"max_exp_eff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+66,0,"max_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+67,0,"sign_max",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("shift", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+68+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 8,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("mant_base", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declArray(c+72+i*3,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 73,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("shifted_mant", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declArray(c+84+i*3,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 73,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("sticky", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBit(c+96+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("op_sign_diff", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBit(c+100+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("op", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declArray(c+104+i*3,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 76,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+116,0,"is_nan_any",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+117,0,"any_pos_inf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+118,0,"any_neg_inf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+119,0,"special_case",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+120,0,"special_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("csa_s", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declArray(c+121+i*3,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 76,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("csa_c", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declArray(c+133+i*3,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 76,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+146,0,"st1_a_e",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+147,0,"st1_a_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+148,0,"st1_align_sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+149,0,"st1_special_case",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+150,0,"st1_special_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+151,0,"st1_sum_vec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 76,0);
    tracep->declArray(c+154,0,"st1_carry_vec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 76,0);
    tracep->declBus(c+157,0,"st1_hot_ones",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declArray(c+158,0,"raw_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 77,0);
    tracep->declArray(c+161,0,"mag_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 75,0);
    tracep->declBit(c+164,0,"res_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+165,0,"st2_exp_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+166,0,"st2_sum_mag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 75,0);
    tracep->declBus(c+169,0,"st2_spec_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+170,0,"st2_res_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+171,0,"st2_sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+172,0,"st2_special",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+173,0,"lzd_scan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 75,0);
    tracep->declBus(c+176,0,"lead_zeros",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+177,0,"norm_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 75,0);
    tracep->declBus(c+180,0,"final_mant",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+181,0,"final_exp_calc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+182,0,"result_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("stage1_logic", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+209,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+209,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+210,0,"lvl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+201,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk5", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+209,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk6", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+209,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("stage3_logic", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("unnamedblk9", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+183,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk7", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+184,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk8", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+185,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+21,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+22,0,"ret",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+23,0,"is_zero_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root__trace_init_top(Vaddn_fp32_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root__trace_init_top\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vaddn_fp32_tb_softfloat___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vaddn_fp32_tb_softfloat___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vaddn_fp32_tb_softfloat___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root__trace_register(Vaddn_fp32_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root__trace_register\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vaddn_fp32_tb_softfloat___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vaddn_fp32_tb_softfloat___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vaddn_fp32_tb_softfloat___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vaddn_fp32_tb_softfloat___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root__trace_const_0_sub_0(Vaddn_fp32_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root__trace_const_0\n"); );
    // Init
    Vaddn_fp32_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaddn_fp32_tb_softfloat___024root*>(voidSelf);
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vaddn_fp32_tb_softfloat___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root__trace_const_0_sub_0(Vaddn_fp32_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root__trace_const_0_sub_0\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+187,(4U),32);
    bufp->fullIData(oldp+188,(2U),32);
    bufp->fullIData(oldp+189,(0x32U),32);
    bufp->fullIData(oldp+190,(8U),32);
    bufp->fullIData(oldp+191,(0x17U),32);
    bufp->fullIData(oldp+192,(0x7f800000U),32);
    bufp->fullIData(oldp+193,(0xff800000U),32);
    bufp->fullIData(oldp+194,(0x7fc00000U),32);
    bufp->fullIData(oldp+195,(0U),32);
    bufp->fullIData(oldp+196,(0x80000000U),32);
    bufp->fullIData(oldp+197,(0x3f800000U),32);
    bufp->fullIData(oldp+198,(0x40000000U),32);
    bufp->fullIData(oldp+199,(0x40400000U),32);
    bufp->fullIData(oldp+200,(0x40800000U),32);
    bufp->fullIData(oldp+201,(1U),32);
    bufp->fullIData(oldp+202,(0x7f7fffffU),32);
    bufp->fullIData(oldp+203,(0x4aU),32);
    bufp->fullIData(oldp+204,(0x4cU),32);
    bufp->fullIData(oldp+205,(0xffU),32);
    bufp->fullIData(oldp+206,(0x20U),32);
    bufp->fullIData(oldp+207,(0U),32);
    bufp->fullIData(oldp+208,(3U),32);
    bufp->fullIData(oldp+209,(4U),32);
    bufp->fullIData(oldp+210,(2U),32);
}

VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root__trace_full_0_sub_0(Vaddn_fp32_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root__trace_full_0\n"); );
    // Init
    Vaddn_fp32_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaddn_fp32_tb_softfloat___024root*>(voidSelf);
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vaddn_fp32_tb_softfloat___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root__trace_full_0_sub_0(Vaddn_fp32_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root__trace_full_0_sub_0\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_nrst));
    bufp->fullWData(oldp+2,(vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data),128);
    bufp->fullIData(oldp+6,(vlSelfRef.addn_fp32_tb_softfloat__DOT__exp),32);
    bufp->fullIData(oldp+7,(vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count),32);
    bufp->fullIData(oldp+8,(vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count),32);
    bufp->fullIData(oldp+9,(vlSelfRef.addn_fp32_tb_softfloat__DOT__off_by_one),32);
    bufp->fullIData(oldp+10,(vlSelfRef.addn_fp32_tb_softfloat__DOT__off_by_two),32);
    bufp->fullIData(oldp+11,(vlSelfRef.addn_fp32_tb_softfloat__DOT__off_by_five_plus),32);
    bufp->fullIData(oldp+12,(vlSelfRef.addn_fp32_tb_softfloat__DOT__diff),32);
    bufp->fullIData(oldp+13,(vlSelfRef.addn_fp32_tb_softfloat__DOT__fd),32);
    bufp->fullIData(oldp+14,(vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_fd),32);
    bufp->fullIData(oldp+15,(vlSelfRef.addn_fp32_tb_softfloat__DOT__a),32);
    bufp->fullIData(oldp+16,(vlSelfRef.addn_fp32_tb_softfloat__DOT__b),32);
    bufp->fullIData(oldp+17,(vlSelfRef.addn_fp32_tb_softfloat__DOT__c),32);
    bufp->fullIData(oldp+18,(vlSelfRef.addn_fp32_tb_softfloat__DOT__d),32);
    bufp->fullIData(oldp+19,(vlSelfRef.addn_fp32_tb_softfloat__DOT__expected),32);
    bufp->fullIData(oldp+20,(vlSelfRef.addn_fp32_tb_softfloat__DOT__total_count),32);
    bufp->fullIData(oldp+21,(vlSelfRef.addn_fp32_tb_softfloat__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+22,(vlSelfRef.addn_fp32_tb_softfloat__DOT__unnamedblk2__DOT__ret),32);
    bufp->fullBit(oldp+23,(vlSelfRef.addn_fp32_tb_softfloat__DOT__unnamedblk2__DOT__is_zero_result));
    bufp->fullIData(oldp+24,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in[0]),32);
    bufp->fullIData(oldp+25,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in[1]),32);
    bufp->fullIData(oldp+26,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in[2]),32);
    bufp->fullIData(oldp+27,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__daz_in[3]),32);
    bufp->fullCData(oldp+28,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp[0]),8);
    bufp->fullCData(oldp+29,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp[1]),8);
    bufp->fullCData(oldp+30,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp[2]),8);
    bufp->fullCData(oldp+31,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__exp[3]),8);
    bufp->fullIData(oldp+32,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac[0]),23);
    bufp->fullIData(oldp+33,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac[1]),23);
    bufp->fullIData(oldp+34,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac[2]),23);
    bufp->fullIData(oldp+35,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__frac[3]),23);
    bufp->fullBit(oldp+36,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign[0]));
    bufp->fullBit(oldp+37,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign[1]));
    bufp->fullBit(oldp+38,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign[2]));
    bufp->fullBit(oldp+39,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign[3]));
    bufp->fullCData(oldp+40,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
                             [0U][0U]),8);
    bufp->fullCData(oldp+41,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
                             [0U][1U]),8);
    bufp->fullCData(oldp+42,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
                             [0U][2U]),8);
    bufp->fullCData(oldp+43,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
                             [0U][3U]),8);
    bufp->fullCData(oldp+44,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
                             [1U][0U]),8);
    bufp->fullCData(oldp+45,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
                             [1U][1U]),8);
    bufp->fullCData(oldp+46,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
                             [1U][2U]),8);
    bufp->fullCData(oldp+47,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
                             [1U][3U]),8);
    bufp->fullCData(oldp+48,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
                             [2U][0U]),8);
    bufp->fullCData(oldp+49,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
                             [2U][1U]),8);
    bufp->fullCData(oldp+50,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
                             [2U][2U]),8);
    bufp->fullCData(oldp+51,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_exp
                             [2U][3U]),8);
    bufp->fullCData(oldp+52,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
                             [0U][0U]),2);
    bufp->fullCData(oldp+53,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
                             [0U][1U]),2);
    bufp->fullCData(oldp+54,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
                             [0U][2U]),2);
    bufp->fullCData(oldp+55,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
                             [0U][3U]),2);
    bufp->fullCData(oldp+56,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
                             [1U][0U]),2);
    bufp->fullCData(oldp+57,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
                             [1U][1U]),2);
    bufp->fullCData(oldp+58,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
                             [1U][2U]),2);
    bufp->fullCData(oldp+59,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
                             [1U][3U]),2);
    bufp->fullCData(oldp+60,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
                             [2U][0U]),2);
    bufp->fullCData(oldp+61,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
                             [2U][1U]),2);
    bufp->fullCData(oldp+62,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
                             [2U][2U]),2);
    bufp->fullCData(oldp+63,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__tree_idx
                             [2U][3U]),2);
    bufp->fullCData(oldp+64,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_exp),8);
    bufp->fullCData(oldp+65,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_exp_eff),8);
    bufp->fullCData(oldp+66,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__max_idx),2);
    bufp->fullBit(oldp+67,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sign_max));
    bufp->fullSData(oldp+68,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift[0]),9);
    bufp->fullSData(oldp+69,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift[1]),9);
    bufp->fullSData(oldp+70,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift[2]),9);
    bufp->fullSData(oldp+71,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shift[3]),9);
    bufp->fullWData(oldp+72,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[0]),74);
    bufp->fullWData(oldp+75,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[1]),74);
    bufp->fullWData(oldp+78,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[2]),74);
    bufp->fullWData(oldp+81,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mant_base[3]),74);
    bufp->fullWData(oldp+84,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[0]),74);
    bufp->fullWData(oldp+87,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[1]),74);
    bufp->fullWData(oldp+90,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[2]),74);
    bufp->fullWData(oldp+93,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__shifted_mant[3]),74);
    bufp->fullBit(oldp+96,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sticky[0]));
    bufp->fullBit(oldp+97,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sticky[1]));
    bufp->fullBit(oldp+98,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sticky[2]));
    bufp->fullBit(oldp+99,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__sticky[3]));
    bufp->fullBit(oldp+100,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff[0]));
    bufp->fullBit(oldp+101,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff[1]));
    bufp->fullBit(oldp+102,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff[2]));
    bufp->fullBit(oldp+103,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op_sign_diff[3]));
    bufp->fullWData(oldp+104,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[0]),77);
    bufp->fullWData(oldp+107,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[1]),77);
    bufp->fullWData(oldp+110,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[2]),77);
    bufp->fullWData(oldp+113,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__op[3]),77);
    bufp->fullBit(oldp+116,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__is_nan_any));
    bufp->fullBit(oldp+117,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_pos_inf));
    bufp->fullBit(oldp+118,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__any_neg_inf));
    bufp->fullBit(oldp+119,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__special_case));
    bufp->fullIData(oldp+120,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__special_result),32);
    bufp->fullWData(oldp+121,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[0]),77);
    bufp->fullWData(oldp+124,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[1]),77);
    bufp->fullWData(oldp+127,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[2]),77);
    bufp->fullWData(oldp+130,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_s[3]),77);
    bufp->fullWData(oldp+133,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[0]),77);
    bufp->fullWData(oldp+136,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[1]),77);
    bufp->fullWData(oldp+139,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[2]),77);
    bufp->fullWData(oldp+142,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__csa_c[3]),77);
    bufp->fullIData(oldp+145,(vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result),32);
    bufp->fullCData(oldp+146,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_a_e),8);
    bufp->fullBit(oldp+147,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_a_s));
    bufp->fullBit(oldp+148,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_align_sticky));
    bufp->fullBit(oldp+149,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_special_case));
    bufp->fullIData(oldp+150,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_special_result),32);
    bufp->fullWData(oldp+151,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_sum_vec),77);
    bufp->fullWData(oldp+154,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_carry_vec),77);
    bufp->fullCData(oldp+157,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st1_hot_ones),3);
    bufp->fullWData(oldp+158,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__raw_sum),78);
    bufp->fullWData(oldp+161,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__mag_sum),76);
    bufp->fullBit(oldp+164,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__res_sign));
    bufp->fullCData(oldp+165,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_exp_base),8);
    bufp->fullWData(oldp+166,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sum_mag),76);
    bufp->fullIData(oldp+169,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_spec_res),32);
    bufp->fullBit(oldp+170,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_res_sign));
    bufp->fullBit(oldp+171,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_sticky));
    bufp->fullBit(oldp+172,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__st2_special));
    bufp->fullWData(oldp+173,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lzd_scan),76);
    bufp->fullCData(oldp+176,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__lead_zeros),8);
    bufp->fullWData(oldp+177,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__norm_val),76);
    bufp->fullIData(oldp+180,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__final_mant),23);
    bufp->fullSData(oldp+181,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__final_exp_calc),11);
    bufp->fullIData(oldp+182,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__result_out),32);
    bufp->fullIData(oldp+183,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__stage3_logic__DOT__unnamedblk9__DOT__i),32);
    bufp->fullIData(oldp+184,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__unnamedblk7__DOT__i),32);
    bufp->fullIData(oldp+185,(vlSelfRef.addn_fp32_tb_softfloat__DOT__dut__DOT__unnamedblk8__DOT__i),32);
    bufp->fullBit(oldp+186,(vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_clk));
}
