// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vaddn_fp32accum_fp16_tb_softfloat__Syms.h"


VL_ATTR_COLD void Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_init_sub__TOP__0(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_init_sub__TOP__0\n"); );
    Vaddn_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("addn_fp32accum_fp16_tb_softfloat", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+145,0,"NUM_INPUTS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+146,0,"PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+145,0,"LATENCY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+147,0,"MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+148,0,"EXPONENT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+149,0,"IN_MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+150,0,"IN_EXPONENT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+151,0,"PRECISION_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+144,0,"tb_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"tb_nrst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+2,0,"tb_in_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+107,0,"tb_raw_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+108,0,"tb_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+4,0,"exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+5,0,"pass_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+6,0,"fail_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+152,0,"off_by_one",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+153,0,"off_by_two",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+154,0,"off_by_five_plus",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+7,0,"ulp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+8,0,"ulp_big_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declDouble(c+9,0,"total_ulp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declQuad(c+11,0,"get_ulp_distance__Vstatic__int_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LONGINT, false,-1, 63,0);
    tracep->declQuad(c+13,0,"get_ulp_distance__Vstatic__int_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LONGINT, false,-1, 63,0);
    tracep->declBus(c+155,0,"P_INF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+156,0,"N_INF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+157,0,"NAN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+158,0,"P_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+159,0,"N_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+160,0,"ONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+161,0,"TWO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+162,0,"THREE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+163,0,"FOUR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+164,0,"MIN_SUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+165,0,"MAX_FINITE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+15,0,"fd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+16,0,"fail_fd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+17,0,"a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+18,0,"b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+19,0,"c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+20,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+21,0,"expected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+22,0,"total_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("etchedfpNadder", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+145,0,"NUM_INPUTS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+147,0,"MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+148,0,"EXPONENT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+149,0,"IN_MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+150,0,"IN_EXPONENT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+151,0,"PRECISION_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+144,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"nRST",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+2,0,"in_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+107,0,"out_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"NEW_MANT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+167,0,"SUM_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+168,0,"MAX_EXP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+169,0,"RES_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+170,0,"BIAS_DIFF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"IN_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+172,0,"HOT_ONES_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+146,0,"LEVELS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+145,0,"P",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+146,0,"IDX_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("daz_in", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+26+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("exp", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+30+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 4,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("frac", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+34+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 9,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("sign", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBit(c+38+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("tree_exp", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->pushPrefix("[0]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+42,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+43,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+44,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+45,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("[1]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+46,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+47,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+48,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+49,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("[2]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+50,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+51,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+52,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+53,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("tree_idx", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->pushPrefix("[0]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+54,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+55,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+56,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+57,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("[1]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+58,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+59,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+60,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+61,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("[2]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+62,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+63,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+64,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+65,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->declBus(c+66,0,"max_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+67,0,"max_exp_eff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+68,0,"max_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+69,0,"sign_max",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("shift", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+70+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 5,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("mant_base", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+74+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 24,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("shifted_mant", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+78+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 24,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("sticky", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBit(c+82+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("op_sign_diff", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBit(c+86+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("op", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+90+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 27,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+94,0,"is_nan_any",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+95,0,"any_pos_inf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"any_neg_inf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+97,0,"special_case",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+98,0,"special_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("csa_s", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+99+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 27,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("csa_c", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+103+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 27,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+109,0,"st1_a_e",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+110,0,"st1_a_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+111,0,"st1_align_sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+112,0,"st1_special_case",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+113,0,"st1_special_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+114,0,"st1_sum_vec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+115,0,"st1_carry_vec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+116,0,"st1_hot_ones",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+117,0,"raw_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 28,0);
    tracep->declBus(c+118,0,"mag_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 26,0);
    tracep->declBit(c+119,0,"res_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+120,0,"st2_exp_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+121,0,"st2_sum_mag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 26,0);
    tracep->declBus(c+122,0,"st2_spec_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+123,0,"st2_res_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"st2_sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+125,0,"st2_special",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+126,0,"lzd_scan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 26,0);
    tracep->declBus(c+127,0,"lead_zeros",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+128,0,"norm_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 26,0);
    tracep->declBus(c+129,0,"final_mant",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+130,0,"final_exp_calc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+131,0,"result_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("stage1_logic", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+173,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+173,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+174,0,"lvl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+175,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk5", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+173,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk6", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+173,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("stage3_logic", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("unnamedblk9", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+132,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk7", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+133,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk8", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+134,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("reduce", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+148,0,"IN_EXP_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+147,0,"IN_MANT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+150,0,"OUT_EXP_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+149,0,"OUT_MANT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+169,0,"IN_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"OUT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+170,0,"BIAS_DIFF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+176,0,"DROP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+107,0,"fp_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+108,0,"fp_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+135,0,"sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+136,0,"in_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+137,0,"in_mant",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+138,0,"new_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+139,0,"rounded",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBit(c+140,0,"guard",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+141,0,"rnd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+142,0,"sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+143,0,"round_up",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+23,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+24,0,"ret",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+25,0,"is_zero_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_init_top(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_init_top\n"); );
    Vaddn_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_register(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_register\n"); );
    Vaddn_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_const_0_sub_0(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_const_0\n"); );
    // Init
    Vaddn_fp32accum_fp16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaddn_fp32accum_fp16_tb_softfloat___024root*>(voidSelf);
    Vaddn_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_const_0_sub_0(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_const_0_sub_0\n"); );
    Vaddn_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+145,(4U),32);
    bufp->fullIData(oldp+146,(2U),32);
    bufp->fullIData(oldp+147,(0x17U),32);
    bufp->fullIData(oldp+148,(8U),32);
    bufp->fullIData(oldp+149,(0xaU),32);
    bufp->fullIData(oldp+150,(5U),32);
    bufp->fullIData(oldp+151,(1U),32);
    bufp->fullIData(oldp+152,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__off_by_one),32);
    bufp->fullIData(oldp+153,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__off_by_two),32);
    bufp->fullIData(oldp+154,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__off_by_five_plus),32);
    bufp->fullSData(oldp+155,(0x7c00U),16);
    bufp->fullSData(oldp+156,(0xfc00U),16);
    bufp->fullSData(oldp+157,(0x7d00U),16);
    bufp->fullSData(oldp+158,(0U),16);
    bufp->fullSData(oldp+159,(0x8000U),16);
    bufp->fullSData(oldp+160,(0x3c00U),16);
    bufp->fullSData(oldp+161,(0x4000U),16);
    bufp->fullSData(oldp+162,(0x4200U),16);
    bufp->fullSData(oldp+163,(0x4400U),16);
    bufp->fullSData(oldp+164,(1U),16);
    bufp->fullSData(oldp+165,(0x7bffU),16);
    bufp->fullIData(oldp+166,(0x19U),32);
    bufp->fullIData(oldp+167,(0x1bU),32);
    bufp->fullIData(oldp+168,(0xffU),32);
    bufp->fullIData(oldp+169,(0x20U),32);
    bufp->fullIData(oldp+170,(0x70U),32);
    bufp->fullIData(oldp+171,(0x10U),32);
    bufp->fullIData(oldp+172,(3U),32);
    bufp->fullIData(oldp+173,(4U),32);
    bufp->fullIData(oldp+174,(2U),32);
    bufp->fullIData(oldp+175,(1U),32);
    bufp->fullIData(oldp+176,(0xdU),32);
}

VL_ATTR_COLD void Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_full_0_sub_0(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_full_0\n"); );
    // Init
    Vaddn_fp32accum_fp16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaddn_fp32accum_fp16_tb_softfloat___024root*>(voidSelf);
    Vaddn_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_full_0_sub_0(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32accum_fp16_tb_softfloat___024root__trace_full_0_sub_0\n"); );
    Vaddn_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_nrst));
    bufp->fullQData(oldp+2,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data),64);
    bufp->fullSData(oldp+4,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__exp),16);
    bufp->fullIData(oldp+5,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count),32);
    bufp->fullIData(oldp+6,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count),32);
    bufp->fullIData(oldp+7,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__ulp_diff),32);
    bufp->fullIData(oldp+8,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__ulp_big_count),32);
    bufp->fullDouble(oldp+9,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__total_ulp_diff));
    bufp->fullQData(oldp+11,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a),64);
    bufp->fullQData(oldp+13,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b),64);
    bufp->fullIData(oldp+15,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fd),32);
    bufp->fullIData(oldp+16,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_fd),32);
    bufp->fullSData(oldp+17,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__a),16);
    bufp->fullSData(oldp+18,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__b),16);
    bufp->fullSData(oldp+19,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__c),16);
    bufp->fullSData(oldp+20,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__d),16);
    bufp->fullSData(oldp+21,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__expected),16);
    bufp->fullIData(oldp+22,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__total_count),32);
    bufp->fullIData(oldp+23,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+24,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__unnamedblk2__DOT__ret),32);
    bufp->fullBit(oldp+25,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__unnamedblk2__DOT__is_zero_result));
    bufp->fullSData(oldp+26,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[0]),16);
    bufp->fullSData(oldp+27,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[1]),16);
    bufp->fullSData(oldp+28,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[2]),16);
    bufp->fullSData(oldp+29,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[3]),16);
    bufp->fullCData(oldp+30,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[0]),5);
    bufp->fullCData(oldp+31,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[1]),5);
    bufp->fullCData(oldp+32,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[2]),5);
    bufp->fullCData(oldp+33,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[3]),5);
    bufp->fullSData(oldp+34,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[0]),10);
    bufp->fullSData(oldp+35,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[1]),10);
    bufp->fullSData(oldp+36,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[2]),10);
    bufp->fullSData(oldp+37,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[3]),10);
    bufp->fullBit(oldp+38,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[0]));
    bufp->fullBit(oldp+39,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[1]));
    bufp->fullBit(oldp+40,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[2]));
    bufp->fullBit(oldp+41,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[3]));
    bufp->fullCData(oldp+42,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [0U][0U]),5);
    bufp->fullCData(oldp+43,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [0U][1U]),5);
    bufp->fullCData(oldp+44,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [0U][2U]),5);
    bufp->fullCData(oldp+45,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [0U][3U]),5);
    bufp->fullCData(oldp+46,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [1U][0U]),5);
    bufp->fullCData(oldp+47,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [1U][1U]),5);
    bufp->fullCData(oldp+48,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [1U][2U]),5);
    bufp->fullCData(oldp+49,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [1U][3U]),5);
    bufp->fullCData(oldp+50,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [2U][0U]),5);
    bufp->fullCData(oldp+51,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [2U][1U]),5);
    bufp->fullCData(oldp+52,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [2U][2U]),5);
    bufp->fullCData(oldp+53,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [2U][3U]),5);
    bufp->fullCData(oldp+54,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                             [0U][0U]),2);
    bufp->fullCData(oldp+55,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                             [0U][1U]),2);
    bufp->fullCData(oldp+56,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                             [0U][2U]),2);
    bufp->fullCData(oldp+57,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                             [0U][3U]),2);
    bufp->fullCData(oldp+58,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                             [1U][0U]),2);
    bufp->fullCData(oldp+59,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                             [1U][1U]),2);
    bufp->fullCData(oldp+60,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                             [1U][2U]),2);
    bufp->fullCData(oldp+61,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                             [1U][3U]),2);
    bufp->fullCData(oldp+62,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                             [2U][0U]),2);
    bufp->fullCData(oldp+63,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                             [2U][1U]),2);
    bufp->fullCData(oldp+64,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                             [2U][2U]),2);
    bufp->fullCData(oldp+65,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                             [2U][3U]),2);
    bufp->fullCData(oldp+66,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp),5);
    bufp->fullCData(oldp+67,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp_eff),5);
    bufp->fullCData(oldp+68,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx),2);
    bufp->fullBit(oldp+69,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_max));
    bufp->fullCData(oldp+70,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[0]),6);
    bufp->fullCData(oldp+71,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[1]),6);
    bufp->fullCData(oldp+72,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[2]),6);
    bufp->fullCData(oldp+73,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[3]),6);
    bufp->fullIData(oldp+74,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[0]),25);
    bufp->fullIData(oldp+75,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[1]),25);
    bufp->fullIData(oldp+76,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[2]),25);
    bufp->fullIData(oldp+77,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[3]),25);
    bufp->fullIData(oldp+78,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[0]),25);
    bufp->fullIData(oldp+79,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[1]),25);
    bufp->fullIData(oldp+80,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[2]),25);
    bufp->fullIData(oldp+81,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[3]),25);
    bufp->fullBit(oldp+82,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[0]));
    bufp->fullBit(oldp+83,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[1]));
    bufp->fullBit(oldp+84,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[2]));
    bufp->fullBit(oldp+85,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[3]));
    bufp->fullBit(oldp+86,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[0]));
    bufp->fullBit(oldp+87,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[1]));
    bufp->fullBit(oldp+88,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[2]));
    bufp->fullBit(oldp+89,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[3]));
    bufp->fullIData(oldp+90,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[0]),28);
    bufp->fullIData(oldp+91,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[1]),28);
    bufp->fullIData(oldp+92,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[2]),28);
    bufp->fullIData(oldp+93,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[3]),28);
    bufp->fullBit(oldp+94,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__is_nan_any));
    bufp->fullBit(oldp+95,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_pos_inf));
    bufp->fullBit(oldp+96,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_neg_inf));
    bufp->fullBit(oldp+97,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_case));
    bufp->fullIData(oldp+98,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_result),32);
    bufp->fullIData(oldp+99,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[0]),28);
    bufp->fullIData(oldp+100,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[1]),28);
    bufp->fullIData(oldp+101,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[2]),28);
    bufp->fullIData(oldp+102,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[3]),28);
    bufp->fullIData(oldp+103,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[0]),28);
    bufp->fullIData(oldp+104,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[1]),28);
    bufp->fullIData(oldp+105,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[2]),28);
    bufp->fullIData(oldp+106,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[3]),28);
    bufp->fullIData(oldp+107,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out),32);
    bufp->fullSData(oldp+108,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result),16);
    bufp->fullCData(oldp+109,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_a_e),5);
    bufp->fullBit(oldp+110,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_a_s));
    bufp->fullBit(oldp+111,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_align_sticky));
    bufp->fullBit(oldp+112,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_special_case));
    bufp->fullIData(oldp+113,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_special_result),32);
    bufp->fullIData(oldp+114,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_sum_vec),28);
    bufp->fullIData(oldp+115,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_carry_vec),28);
    bufp->fullCData(oldp+116,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_hot_ones),3);
    bufp->fullIData(oldp+117,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__raw_sum),29);
    bufp->fullIData(oldp+118,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mag_sum),27);
    bufp->fullBit(oldp+119,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__res_sign));
    bufp->fullCData(oldp+120,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_exp_base),5);
    bufp->fullIData(oldp+121,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sum_mag),27);
    bufp->fullIData(oldp+122,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_spec_res),32);
    bufp->fullBit(oldp+123,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_res_sign));
    bufp->fullBit(oldp+124,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sticky));
    bufp->fullBit(oldp+125,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_special));
    bufp->fullIData(oldp+126,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan),27);
    bufp->fullCData(oldp+127,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros),6);
    bufp->fullIData(oldp+128,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__norm_val),27);
    bufp->fullIData(oldp+129,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__final_mant),23);
    bufp->fullSData(oldp+130,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__final_exp_calc),11);
    bufp->fullIData(oldp+131,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__result_out),32);
    bufp->fullIData(oldp+132,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__stage3_logic__DOT__unnamedblk9__DOT__i),32);
    bufp->fullIData(oldp+133,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__unnamedblk7__DOT__i),32);
    bufp->fullIData(oldp+134,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__unnamedblk8__DOT__i),32);
    bufp->fullBit(oldp+135,((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
                             >> 0x1fU)));
    bufp->fullCData(oldp+136,((0xffU & (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out 
                                        >> 0x17U))),8);
    bufp->fullIData(oldp+137,((0x7fffffU & vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out)),23);
    bufp->fullSData(oldp+138,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp),10);
    bufp->fullSData(oldp+139,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded),11);
    bufp->fullBit(oldp+140,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__guard));
    bufp->fullBit(oldp+141,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rnd));
    bufp->fullBit(oldp+142,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__sticky));
    bufp->fullBit(oldp+143,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__round_up));
    bufp->fullBit(oldp+144,(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_clk));
}
