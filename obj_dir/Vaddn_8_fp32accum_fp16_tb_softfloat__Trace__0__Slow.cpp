// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vaddn_8_fp32accum_fp16_tb_softfloat__Syms.h"


VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_init_sub__TOP__0(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_init_sub__TOP__0\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("addn_8_fp32accum_fp16_tb_softfloat", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+252,0,"NUM_INPUTS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+253,0,"PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+254,0,"LATENCY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+255,0,"MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+252,0,"EXPONENT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+255,0,"IN_MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+252,0,"IN_EXPONENT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+256,0,"PRECISION_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+251,0,"tb_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"tb_nrst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+2,0,"tb_in_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBus(c+229,0,"tb_raw_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+230,0,"tb_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+6,0,"exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+7,0,"pass_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+8,0,"fail_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+257,0,"off_by_one",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+258,0,"off_by_two",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+259,0,"off_by_five_plus",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+9,0,"ulp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+10,0,"ulp_big_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declDouble(c+11,0,"total_ulp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declQuad(c+13,0,"get_ulp_distance__Vstatic__int_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LONGINT, false,-1, 63,0);
    tracep->declQuad(c+15,0,"get_ulp_distance__Vstatic__int_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LONGINT, false,-1, 63,0);
    tracep->declBus(c+260,0,"P_INF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+261,0,"N_INF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+262,0,"NAN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+263,0,"P_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+264,0,"N_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+265,0,"ONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+266,0,"TWO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+267,0,"MIN_SUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+268,0,"MAX_FINITE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+17,0,"fd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+18,0,"fail_fd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+19,0,"a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+20,0,"b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+21,0,"c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+22,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+23,0,"e",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+24,0,"f",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+25,0,"g",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+26,0,"h",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+27,0,"expected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+28,0,"total_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("etchedfpNadder", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+252,0,"NUM_INPUTS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+255,0,"MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+252,0,"EXPONENT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+255,0,"IN_MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+252,0,"IN_EXPONENT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+256,0,"PRECISION_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+269,0,"EXTRA_STAGES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+251,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"nRST",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+29,0,"in_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBus(c+229,0,"out_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+270,0,"NEW_MANT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+271,0,"SUM_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+272,0,"MAX_EXP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+273,0,"RES_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+274,0,"BIAS_DIFF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+273,0,"IN_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+275,0,"HOT_ONES_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+269,0,"LEVELS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+252,0,"P",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+269,0,"IDX_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("daz_in", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+40+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("exp", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+48+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("frac", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+56+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 22,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("sign", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBit(c+64+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("tree_exp", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->pushPrefix("[0]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+72,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+73,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+74,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+75,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+76,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+77,0,"[5]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+78,0,"[6]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+79,0,"[7]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("[1]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+80,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+81,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+82,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+83,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+84,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+85,0,"[5]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+86,0,"[6]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+87,0,"[7]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("[2]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+88,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+89,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+90,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+91,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+92,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+93,0,"[5]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+94,0,"[6]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+95,0,"[7]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("[3]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+96,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+97,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+98,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+99,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+100,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+101,0,"[5]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+102,0,"[6]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+103,0,"[7]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("tree_idx", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->pushPrefix("[0]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+104,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+105,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+106,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+107,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+108,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+109,0,"[5]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+110,0,"[6]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+111,0,"[7]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("[1]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+112,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+113,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+114,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+115,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+116,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+117,0,"[5]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+118,0,"[6]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+119,0,"[7]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("[2]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+120,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+121,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+122,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+123,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+124,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+125,0,"[5]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+126,0,"[6]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+127,0,"[7]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("[3]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+128,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+129,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+130,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+131,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+132,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+133,0,"[5]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+134,0,"[6]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+135,0,"[7]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->declBus(c+136,0,"max_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+137,0,"max_exp_eff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+138,0,"max_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+139,0,"sign_max",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("shift", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+140+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 8,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("mant_base", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+148+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 24,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("shifted_mant", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+156+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 24,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("sticky", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBit(c+164+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("op_sign_diff", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBit(c+172+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("op", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+180+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 27,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+188,0,"is_nan_any",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+189,0,"any_pos_inf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+190,0,"any_neg_inf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+191,0,"special_case",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+192,0,"special_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("csa_s", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+193+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 27,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("csa_c", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+201+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 27,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+209,0,"st1_a_e",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+210,0,"st1_a_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+211,0,"st1_align_sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+212,0,"st1_special_case",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+213,0,"st1_special_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+214,0,"st1_sum_vec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+215,0,"st1_carry_vec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+216,0,"st1_hot_ones",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+217,0,"raw_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 28,0);
    tracep->declBus(c+218,0,"mag_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 26,0);
    tracep->declBit(c+219,0,"res_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+220,0,"st2_exp_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+221,0,"st2_sum_mag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 26,0);
    tracep->declBus(c+222,0,"st2_spec_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+223,0,"st2_res_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+224,0,"st2_sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+225,0,"st2_special",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+245,0,"lzd_scan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 26,0);
    tracep->declBus(c+246,0,"lead_zeros",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+247,0,"norm_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 26,0);
    tracep->declBus(c+248,0,"final_mant",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+249,0,"final_exp_calc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+250,0,"result_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("pipe_regs", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+231+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("stage1_logic", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+276,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+276,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+277,0,"lvl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+278,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk5", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+276,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk6", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+276,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("stage3_logic", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("unnamedblk9", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+226,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk10", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+235,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk7", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+227,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk8", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+228,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("reduce", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+252,0,"IN_EXP_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+255,0,"IN_MANT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+279,0,"OUT_EXP_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+280,0,"OUT_MANT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+273,0,"IN_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+281,0,"OUT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+282,0,"BIAS_DIFF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+283,0,"DROP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+229,0,"fp_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+230,0,"fp_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+236,0,"sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+237,0,"in_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+238,0,"in_mant",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+239,0,"new_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+240,0,"rounded",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBit(c+241,0,"guard",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+242,0,"rnd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+243,0,"sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+244,0,"round_up",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+37,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+38,0,"ret",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+39,0,"is_zero_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_init_top(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_init_top\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_register(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_register\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_const_0_sub_0(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_const_0\n"); );
    // Init
    Vaddn_8_fp32accum_fp16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaddn_8_fp32accum_fp16_tb_softfloat___024root*>(voidSelf);
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_const_0_sub_0(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_const_0_sub_0\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+252,(8U),32);
    bufp->fullIData(oldp+253,(2U),32);
    bufp->fullIData(oldp+254,(7U),32);
    bufp->fullIData(oldp+255,(0x17U),32);
    bufp->fullIData(oldp+256,(1U),32);
    bufp->fullIData(oldp+257,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__off_by_one),32);
    bufp->fullIData(oldp+258,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__off_by_two),32);
    bufp->fullIData(oldp+259,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__off_by_five_plus),32);
    bufp->fullSData(oldp+260,(0x7c00U),16);
    bufp->fullSData(oldp+261,(0xfc00U),16);
    bufp->fullSData(oldp+262,(0x7d00U),16);
    bufp->fullSData(oldp+263,(0U),16);
    bufp->fullSData(oldp+264,(0x8000U),16);
    bufp->fullSData(oldp+265,(0x3c00U),16);
    bufp->fullSData(oldp+266,(0x4000U),16);
    bufp->fullSData(oldp+267,(1U),16);
    bufp->fullSData(oldp+268,(0x7bffU),16);
    bufp->fullIData(oldp+269,(3U),32);
    bufp->fullIData(oldp+270,(0x19U),32);
    bufp->fullIData(oldp+271,(0x1bU),32);
    bufp->fullIData(oldp+272,(0xffU),32);
    bufp->fullIData(oldp+273,(0x20U),32);
    bufp->fullIData(oldp+274,(0U),32);
    bufp->fullIData(oldp+275,(4U),32);
    bufp->fullIData(oldp+276,(8U),32);
    bufp->fullIData(oldp+277,(3U),32);
    bufp->fullIData(oldp+278,(1U),32);
    bufp->fullIData(oldp+279,(5U),32);
    bufp->fullIData(oldp+280,(0xaU),32);
    bufp->fullIData(oldp+281,(0x10U),32);
    bufp->fullIData(oldp+282,(0x70U),32);
    bufp->fullIData(oldp+283,(0xdU),32);
}

VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_full_0_sub_0(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_full_0\n"); );
    // Init
    Vaddn_8_fp32accum_fp16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaddn_8_fp32accum_fp16_tb_softfloat___024root*>(voidSelf);
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_full_0_sub_0(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_full_0_sub_0\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<8>/*255:0*/ __Vtemp_1;
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst));
    bufp->fullWData(oldp+2,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data),128);
    bufp->fullSData(oldp+6,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__exp),16);
    bufp->fullIData(oldp+7,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__pass_count),32);
    bufp->fullIData(oldp+8,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_count),32);
    bufp->fullIData(oldp+9,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__ulp_diff),32);
    bufp->fullIData(oldp+10,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__ulp_big_count),32);
    bufp->fullDouble(oldp+11,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__total_ulp_diff));
    bufp->fullQData(oldp+13,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a),64);
    bufp->fullQData(oldp+15,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b),64);
    bufp->fullIData(oldp+17,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fd),32);
    bufp->fullIData(oldp+18,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_fd),32);
    bufp->fullSData(oldp+19,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__a),16);
    bufp->fullSData(oldp+20,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__b),16);
    bufp->fullSData(oldp+21,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__c),16);
    bufp->fullSData(oldp+22,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__d),16);
    bufp->fullSData(oldp+23,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__e),16);
    bufp->fullSData(oldp+24,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__f),16);
    bufp->fullSData(oldp+25,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__g),16);
    bufp->fullSData(oldp+26,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__h),16);
    bufp->fullSData(oldp+27,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__expected),16);
    bufp->fullIData(oldp+28,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__total_count),32);
    __Vtemp_1[0U] = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U];
    __Vtemp_1[1U] = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U];
    __Vtemp_1[2U] = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U];
    __Vtemp_1[3U] = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U];
    __Vtemp_1[4U] = 0U;
    __Vtemp_1[5U] = 0U;
    __Vtemp_1[6U] = 0U;
    __Vtemp_1[7U] = 0U;
    bufp->fullWData(oldp+29,(__Vtemp_1),256);
    bufp->fullIData(oldp+37,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+38,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__unnamedblk2__DOT__ret),32);
    bufp->fullBit(oldp+39,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__unnamedblk2__DOT__is_zero_result));
    bufp->fullIData(oldp+40,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[0]),32);
    bufp->fullIData(oldp+41,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[1]),32);
    bufp->fullIData(oldp+42,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[2]),32);
    bufp->fullIData(oldp+43,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[3]),32);
    bufp->fullIData(oldp+44,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[4]),32);
    bufp->fullIData(oldp+45,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[5]),32);
    bufp->fullIData(oldp+46,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[6]),32);
    bufp->fullIData(oldp+47,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__daz_in[7]),32);
    bufp->fullCData(oldp+48,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[0]),8);
    bufp->fullCData(oldp+49,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[1]),8);
    bufp->fullCData(oldp+50,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[2]),8);
    bufp->fullCData(oldp+51,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[3]),8);
    bufp->fullCData(oldp+52,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[4]),8);
    bufp->fullCData(oldp+53,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[5]),8);
    bufp->fullCData(oldp+54,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[6]),8);
    bufp->fullCData(oldp+55,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__exp[7]),8);
    bufp->fullIData(oldp+56,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[0]),23);
    bufp->fullIData(oldp+57,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[1]),23);
    bufp->fullIData(oldp+58,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[2]),23);
    bufp->fullIData(oldp+59,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[3]),23);
    bufp->fullIData(oldp+60,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[4]),23);
    bufp->fullIData(oldp+61,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[5]),23);
    bufp->fullIData(oldp+62,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[6]),23);
    bufp->fullIData(oldp+63,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__frac[7]),23);
    bufp->fullBit(oldp+64,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[0]));
    bufp->fullBit(oldp+65,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[1]));
    bufp->fullBit(oldp+66,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[2]));
    bufp->fullBit(oldp+67,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[3]));
    bufp->fullBit(oldp+68,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[4]));
    bufp->fullBit(oldp+69,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[5]));
    bufp->fullBit(oldp+70,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[6]));
    bufp->fullBit(oldp+71,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign[7]));
    bufp->fullCData(oldp+72,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [0U][0U]),8);
    bufp->fullCData(oldp+73,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [0U][1U]),8);
    bufp->fullCData(oldp+74,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [0U][2U]),8);
    bufp->fullCData(oldp+75,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [0U][3U]),8);
    bufp->fullCData(oldp+76,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [0U][4U]),8);
    bufp->fullCData(oldp+77,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [0U][5U]),8);
    bufp->fullCData(oldp+78,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [0U][6U]),8);
    bufp->fullCData(oldp+79,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [0U][7U]),8);
    bufp->fullCData(oldp+80,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [1U][0U]),8);
    bufp->fullCData(oldp+81,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [1U][1U]),8);
    bufp->fullCData(oldp+82,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [1U][2U]),8);
    bufp->fullCData(oldp+83,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [1U][3U]),8);
    bufp->fullCData(oldp+84,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [1U][4U]),8);
    bufp->fullCData(oldp+85,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [1U][5U]),8);
    bufp->fullCData(oldp+86,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [1U][6U]),8);
    bufp->fullCData(oldp+87,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [1U][7U]),8);
    bufp->fullCData(oldp+88,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [2U][0U]),8);
    bufp->fullCData(oldp+89,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [2U][1U]),8);
    bufp->fullCData(oldp+90,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [2U][2U]),8);
    bufp->fullCData(oldp+91,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [2U][3U]),8);
    bufp->fullCData(oldp+92,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [2U][4U]),8);
    bufp->fullCData(oldp+93,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [2U][5U]),8);
    bufp->fullCData(oldp+94,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [2U][6U]),8);
    bufp->fullCData(oldp+95,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [2U][7U]),8);
    bufp->fullCData(oldp+96,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [3U][0U]),8);
    bufp->fullCData(oldp+97,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [3U][1U]),8);
    bufp->fullCData(oldp+98,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [3U][2U]),8);
    bufp->fullCData(oldp+99,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                             [3U][3U]),8);
    bufp->fullCData(oldp+100,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                              [3U][4U]),8);
    bufp->fullCData(oldp+101,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                              [3U][5U]),8);
    bufp->fullCData(oldp+102,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                              [3U][6U]),8);
    bufp->fullCData(oldp+103,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_exp
                              [3U][7U]),8);
    bufp->fullCData(oldp+104,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [0U][0U]),3);
    bufp->fullCData(oldp+105,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [0U][1U]),3);
    bufp->fullCData(oldp+106,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [0U][2U]),3);
    bufp->fullCData(oldp+107,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [0U][3U]),3);
    bufp->fullCData(oldp+108,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [0U][4U]),3);
    bufp->fullCData(oldp+109,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [0U][5U]),3);
    bufp->fullCData(oldp+110,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [0U][6U]),3);
    bufp->fullCData(oldp+111,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [0U][7U]),3);
    bufp->fullCData(oldp+112,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [1U][0U]),3);
    bufp->fullCData(oldp+113,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [1U][1U]),3);
    bufp->fullCData(oldp+114,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [1U][2U]),3);
    bufp->fullCData(oldp+115,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [1U][3U]),3);
    bufp->fullCData(oldp+116,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [1U][4U]),3);
    bufp->fullCData(oldp+117,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [1U][5U]),3);
    bufp->fullCData(oldp+118,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [1U][6U]),3);
    bufp->fullCData(oldp+119,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [1U][7U]),3);
    bufp->fullCData(oldp+120,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [2U][0U]),3);
    bufp->fullCData(oldp+121,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [2U][1U]),3);
    bufp->fullCData(oldp+122,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [2U][2U]),3);
    bufp->fullCData(oldp+123,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [2U][3U]),3);
    bufp->fullCData(oldp+124,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [2U][4U]),3);
    bufp->fullCData(oldp+125,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [2U][5U]),3);
    bufp->fullCData(oldp+126,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [2U][6U]),3);
    bufp->fullCData(oldp+127,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [2U][7U]),3);
    bufp->fullCData(oldp+128,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [3U][0U]),3);
    bufp->fullCData(oldp+129,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [3U][1U]),3);
    bufp->fullCData(oldp+130,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [3U][2U]),3);
    bufp->fullCData(oldp+131,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [3U][3U]),3);
    bufp->fullCData(oldp+132,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [3U][4U]),3);
    bufp->fullCData(oldp+133,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [3U][5U]),3);
    bufp->fullCData(oldp+134,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [3U][6U]),3);
    bufp->fullCData(oldp+135,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__tree_idx
                              [3U][7U]),3);
    bufp->fullCData(oldp+136,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp),8);
    bufp->fullCData(oldp+137,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_exp_eff),8);
    bufp->fullCData(oldp+138,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__max_idx),3);
    bufp->fullBit(oldp+139,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sign_max));
    bufp->fullSData(oldp+140,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[0]),9);
    bufp->fullSData(oldp+141,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[1]),9);
    bufp->fullSData(oldp+142,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[2]),9);
    bufp->fullSData(oldp+143,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[3]),9);
    bufp->fullSData(oldp+144,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[4]),9);
    bufp->fullSData(oldp+145,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[5]),9);
    bufp->fullSData(oldp+146,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[6]),9);
    bufp->fullSData(oldp+147,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shift[7]),9);
    bufp->fullIData(oldp+148,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[0]),25);
    bufp->fullIData(oldp+149,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[1]),25);
    bufp->fullIData(oldp+150,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[2]),25);
    bufp->fullIData(oldp+151,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[3]),25);
    bufp->fullIData(oldp+152,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[4]),25);
    bufp->fullIData(oldp+153,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[5]),25);
    bufp->fullIData(oldp+154,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[6]),25);
    bufp->fullIData(oldp+155,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mant_base[7]),25);
    bufp->fullIData(oldp+156,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[0]),25);
    bufp->fullIData(oldp+157,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[1]),25);
    bufp->fullIData(oldp+158,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[2]),25);
    bufp->fullIData(oldp+159,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[3]),25);
    bufp->fullIData(oldp+160,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[4]),25);
    bufp->fullIData(oldp+161,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[5]),25);
    bufp->fullIData(oldp+162,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[6]),25);
    bufp->fullIData(oldp+163,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__shifted_mant[7]),25);
    bufp->fullBit(oldp+164,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[0]));
    bufp->fullBit(oldp+165,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[1]));
    bufp->fullBit(oldp+166,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[2]));
    bufp->fullBit(oldp+167,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[3]));
    bufp->fullBit(oldp+168,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[4]));
    bufp->fullBit(oldp+169,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[5]));
    bufp->fullBit(oldp+170,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[6]));
    bufp->fullBit(oldp+171,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__sticky[7]));
    bufp->fullBit(oldp+172,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[0]));
    bufp->fullBit(oldp+173,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[1]));
    bufp->fullBit(oldp+174,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[2]));
    bufp->fullBit(oldp+175,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[3]));
    bufp->fullBit(oldp+176,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[4]));
    bufp->fullBit(oldp+177,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[5]));
    bufp->fullBit(oldp+178,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[6]));
    bufp->fullBit(oldp+179,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op_sign_diff[7]));
    bufp->fullIData(oldp+180,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[0]),28);
    bufp->fullIData(oldp+181,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[1]),28);
    bufp->fullIData(oldp+182,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[2]),28);
    bufp->fullIData(oldp+183,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[3]),28);
    bufp->fullIData(oldp+184,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[4]),28);
    bufp->fullIData(oldp+185,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[5]),28);
    bufp->fullIData(oldp+186,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[6]),28);
    bufp->fullIData(oldp+187,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__op[7]),28);
    bufp->fullBit(oldp+188,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__is_nan_any));
    bufp->fullBit(oldp+189,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_pos_inf));
    bufp->fullBit(oldp+190,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__any_neg_inf));
    bufp->fullBit(oldp+191,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_case));
    bufp->fullIData(oldp+192,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__special_result),32);
    bufp->fullIData(oldp+193,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[0]),28);
    bufp->fullIData(oldp+194,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[1]),28);
    bufp->fullIData(oldp+195,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[2]),28);
    bufp->fullIData(oldp+196,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[3]),28);
    bufp->fullIData(oldp+197,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[4]),28);
    bufp->fullIData(oldp+198,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[5]),28);
    bufp->fullIData(oldp+199,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[6]),28);
    bufp->fullIData(oldp+200,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_s[7]),28);
    bufp->fullIData(oldp+201,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[0]),28);
    bufp->fullIData(oldp+202,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[1]),28);
    bufp->fullIData(oldp+203,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[2]),28);
    bufp->fullIData(oldp+204,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[3]),28);
    bufp->fullIData(oldp+205,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[4]),28);
    bufp->fullIData(oldp+206,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[5]),28);
    bufp->fullIData(oldp+207,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[6]),28);
    bufp->fullIData(oldp+208,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__csa_c[7]),28);
    bufp->fullCData(oldp+209,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_a_e),8);
    bufp->fullBit(oldp+210,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_a_s));
    bufp->fullBit(oldp+211,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_align_sticky));
    bufp->fullBit(oldp+212,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_special_case));
    bufp->fullIData(oldp+213,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_special_result),32);
    bufp->fullIData(oldp+214,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_sum_vec),28);
    bufp->fullIData(oldp+215,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_carry_vec),28);
    bufp->fullCData(oldp+216,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st1_hot_ones),4);
    bufp->fullIData(oldp+217,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__raw_sum),29);
    bufp->fullIData(oldp+218,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__mag_sum),27);
    bufp->fullBit(oldp+219,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__res_sign));
    bufp->fullCData(oldp+220,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_exp_base),8);
    bufp->fullIData(oldp+221,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sum_mag),27);
    bufp->fullIData(oldp+222,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_spec_res),32);
    bufp->fullBit(oldp+223,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_res_sign));
    bufp->fullBit(oldp+224,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_sticky));
    bufp->fullBit(oldp+225,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__st2_special));
    bufp->fullIData(oldp+226,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__stage3_logic__DOT__unnamedblk9__DOT__i),32);
    bufp->fullIData(oldp+227,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__unnamedblk7__DOT__i),32);
    bufp->fullIData(oldp+228,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__unnamedblk8__DOT__i),32);
    bufp->fullIData(oldp+229,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs
                              [3U]),32);
    bufp->fullSData(oldp+230,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result),16);
    bufp->fullIData(oldp+231,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs[0]),32);
    bufp->fullIData(oldp+232,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs[1]),32);
    bufp->fullIData(oldp+233,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs[2]),32);
    bufp->fullIData(oldp+234,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs[3]),32);
    bufp->fullIData(oldp+235,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__unnamedblk10__DOT__i),32);
    bufp->fullBit(oldp+236,((vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs
                             [3U] >> 0x1fU)));
    bufp->fullCData(oldp+237,((0xffU & (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs
                                        [3U] >> 0x17U))),8);
    bufp->fullIData(oldp+238,((0x7fffffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__pipe_regs
                               [3U])),23);
    bufp->fullSData(oldp+239,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp),10);
    bufp->fullSData(oldp+240,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded),11);
    bufp->fullBit(oldp+241,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__guard));
    bufp->fullBit(oldp+242,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rnd));
    bufp->fullBit(oldp+243,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__sticky));
    bufp->fullBit(oldp+244,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__round_up));
    bufp->fullIData(oldp+245,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lzd_scan),27);
    bufp->fullCData(oldp+246,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__lead_zeros),6);
    bufp->fullIData(oldp+247,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__norm_val),27);
    bufp->fullIData(oldp+248,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__final_mant),23);
    bufp->fullSData(oldp+249,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__final_exp_calc),11);
    bufp->fullIData(oldp+250,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__etchedfpNadder__DOT__result_out),32);
    bufp->fullBit(oldp+251,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_clk));
}
