// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadd4_fp32accum_bf16_tb_softfloat__Syms.h"


VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_init_sub__TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if__0(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_init_sub__TOP__0(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_init_sub__TOP__0\n"); );
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("add4_fp32accum_bf16_tb_softfloat", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+133,0,"PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+134,0,"LATENCY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+132,0,"tb_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"tb_nrst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("add_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_init_sub__TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+2,0,"tb_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+3,0,"tb_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+4,0,"tb_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+5,0,"tb_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+97,0,"tb_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+6,0,"exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+7,0,"pass_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+8,0,"fail_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declQuad(c+9,0,"total_ulp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LONGINT, false,-1, 63,0);
    tracep->declBus(c+11,0,"ulp_big_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+12,0,"a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+13,0,"b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+14,0,"c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+15,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+16,0,"expected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+17,0,"fd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+18,0,"total_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declQuad(c+19,0,"get_ulp_distance__Vstatic__int_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LONGINT, false,-1, 63,0);
    tracep->declQuad(c+21,0,"get_ulp_distance__Vstatic__int_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LONGINT, false,-1, 63,0);
    tracep->declBus(c+135,0,"P_INF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+136,0,"N_INF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+137,0,"NAN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+138,0,"P_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+139,0,"N_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+140,0,"ONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+141,0,"TWO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+142,0,"FOUR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+143,0,"MIN_SUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+144,0,"MAX_FINITE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("bf16adder", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+145,0,"MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+146,0,"EXPONENT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+147,0,"IN_MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+146,0,"IN_EXPONENT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+148,0,"PRECISION_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+132,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"nRST",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("add", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_init_sub__TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+149,0,"NEW_MANT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+150,0,"SUM_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+151,0,"MAX_EXP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+152,0,"RES_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+148,0,"BIAS_DIFF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+153,0,"IN_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"a_daz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+25,0,"b_daz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+26,0,"c_daz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+27,0,"d_daz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+28,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+29,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+30,0,"exp_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+31,0,"exp_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+32,0,"frac_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+33,0,"frac_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+34,0,"frac_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+35,0,"frac_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+36,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+37,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"sign_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"sign_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+40,0,"exp_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+41,0,"exp_m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+42,0,"exp_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+43,0,"exp_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+44,0,"exp_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+45,0,"exp_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+46,0,"exp_mx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+47,0,"exp_nx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+48,0,"frac_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+49,0,"frac_m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+50,0,"frac_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+51,0,"frac_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+52,0,"frac_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+53,0,"frac_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+54,0,"frac_mx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+55,0,"frac_nx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+56,0,"sign_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"sign_m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+58,0,"sign_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+59,0,"sign_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+60,0,"sign_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"sign_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"sign_mx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"sign_nx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+64,0,"exp_x_eff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+65,0,"exp_y_eff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+66,0,"exp_mx_eff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+67,0,"exp_nx_eff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+68,0,"y_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+69,0,"m_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+70,0,"n_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+71,0,"x_mant",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+72,0,"y_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+73,0,"m_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+74,0,"n_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+75,0,"y_mant_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+76,0,"m_mant_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+77,0,"n_mant_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+78,0,"sticky_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+79,0,"sticky_m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+80,0,"sticky_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"y_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"m_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"n_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"is_nan_any",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"special_case",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"any_pos_inf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"any_neg_inf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+88,0,"special_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+98,0,"st1_a_e",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+99,0,"st1_a_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"st1_align_sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,0,"st1_special_case",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+102,0,"st1_special_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+103,0,"st1_sum_vec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 26,0);
    tracep->declBus(c+104,0,"st1_carry_vec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 26,0);
    tracep->declBus(c+105,0,"st1_hot_ones",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+106,0,"raw_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+107,0,"mag_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+108,0,"res_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+109,0,"st2_exp_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+110,0,"st2_sum_mag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+111,0,"st2_spec_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+112,0,"st2_res_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+113,0,"st2_sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+114,0,"st2_special",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+115,0,"lzd_scan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+116,0,"lead_zeros",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+117,0,"norm_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+154,0,"raw_mant",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+118,0,"final_mant",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+155,0,"rounded_mant_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+119,0,"final_exp_calc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBit(c+156,0,"guard_bit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+157,0,"round_bit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+158,0,"sticky_bit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+159,0,"round_up",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+120,0,"result_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+89,0,"op_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 26,0);
    tracep->declBus(c+90,0,"op_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 26,0);
    tracep->declBus(c+91,0,"op_m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 26,0);
    tracep->declBus(c+92,0,"op_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 26,0);
    tracep->declBus(c+93,0,"csa_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 26,0);
    tracep->declBus(c+94,0,"csa_c1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 26,0);
    tracep->declBus(c+95,0,"csa_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 26,0);
    tracep->declBus(c+96,0,"csa_c2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 26,0);
    tracep->pushPrefix("stage3_logic", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+121,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("reduce", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+146,0,"IN_EXP_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+145,0,"IN_MANT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+146,0,"OUT_EXP_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+147,0,"OUT_MANT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+152,0,"IN_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+153,0,"OUT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+148,0,"BIAS_DIFF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+153,0,"DROP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+122,0,"fp_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+97,0,"fp_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+123,0,"sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+124,0,"in_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+125,0,"in_mant",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+126,0,"new_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+127,0,"rounded",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+128,0,"guard",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+129,0,"rnd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+130,0,"sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+131,0,"round_up",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+23,0,"ret",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_init_sub__TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if__0(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_init_sub__TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if__0\n"); );
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+145,0,"MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+146,0,"EXPONENT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+147,0,"IN_MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+146,0,"IN_EXPONENT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+148,0,"PRECISION_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+153,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+152,0,"OUTPUT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+3,0,"b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+4,0,"c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+5,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+122,0,"out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
}

VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_init_top(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_init_top\n"); );
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_register(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_register\n"); );
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_const_0_sub_0(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_const_0\n"); );
    // Init
    Vadd4_fp32accum_bf16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd4_fp32accum_bf16_tb_softfloat___024root*>(voidSelf);
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_const_0_sub_0(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_const_0_sub_0\n"); );
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+133,(2U),32);
    bufp->fullIData(oldp+134,(4U),32);
    bufp->fullSData(oldp+135,(0x7f80U),16);
    bufp->fullSData(oldp+136,(0xff80U),16);
    bufp->fullSData(oldp+137,(0x7fc0U),16);
    bufp->fullSData(oldp+138,(0U),16);
    bufp->fullSData(oldp+139,(0x8000U),16);
    bufp->fullSData(oldp+140,(0x3f80U),16);
    bufp->fullSData(oldp+141,(0x4000U),16);
    bufp->fullSData(oldp+142,(0x4080U),16);
    bufp->fullSData(oldp+143,(1U),16);
    bufp->fullSData(oldp+144,(0x7f7fU),16);
    bufp->fullIData(oldp+145,(0x17U),32);
    bufp->fullIData(oldp+146,(8U),32);
    bufp->fullIData(oldp+147,(7U),32);
    bufp->fullIData(oldp+148,(0U),32);
    bufp->fullIData(oldp+149,(0x18U),32);
    bufp->fullIData(oldp+150,(0x1aU),32);
    bufp->fullIData(oldp+151,(0xffU),32);
    bufp->fullIData(oldp+152,(0x20U),32);
    bufp->fullIData(oldp+153,(0x10U),32);
    bufp->fullIData(oldp+154,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__raw_mant),23);
    bufp->fullIData(oldp+155,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__rounded_mant_int),24);
    bufp->fullBit(oldp+156,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__guard_bit));
    bufp->fullBit(oldp+157,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__round_bit));
    bufp->fullBit(oldp+158,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sticky_bit));
    bufp->fullBit(oldp+159,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__round_up));
}

VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_full_0_sub_0(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_full_0\n"); );
    // Init
    Vadd4_fp32accum_bf16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd4_fp32accum_bf16_tb_softfloat___024root*>(voidSelf);
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_full_0_sub_0(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root__trace_full_0_sub_0\n"); );
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_nrst));
    bufp->fullSData(oldp+2,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a),16);
    bufp->fullSData(oldp+3,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b),16);
    bufp->fullSData(oldp+4,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c),16);
    bufp->fullSData(oldp+5,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d),16);
    bufp->fullSData(oldp+6,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__exp),16);
    bufp->fullIData(oldp+7,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count),32);
    bufp->fullIData(oldp+8,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count),32);
    bufp->fullQData(oldp+9,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff),64);
    bufp->fullIData(oldp+11,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count),32);
    bufp->fullSData(oldp+12,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__a),16);
    bufp->fullSData(oldp+13,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__b),16);
    bufp->fullSData(oldp+14,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__c),16);
    bufp->fullSData(oldp+15,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__d),16);
    bufp->fullSData(oldp+16,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__expected),16);
    bufp->fullIData(oldp+17,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fd),32);
    bufp->fullIData(oldp+18,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_count),32);
    bufp->fullQData(oldp+19,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a),64);
    bufp->fullQData(oldp+21,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b),64);
    bufp->fullIData(oldp+23,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__ret),32);
    bufp->fullSData(oldp+24,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__a_daz),16);
    bufp->fullSData(oldp+25,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__b_daz),16);
    bufp->fullSData(oldp+26,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__c_daz),16);
    bufp->fullSData(oldp+27,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__d_daz),16);
    bufp->fullCData(oldp+28,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_a),8);
    bufp->fullCData(oldp+29,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_b),8);
    bufp->fullCData(oldp+30,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_c),8);
    bufp->fullCData(oldp+31,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_d),8);
    bufp->fullCData(oldp+32,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_a),7);
    bufp->fullCData(oldp+33,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_b),7);
    bufp->fullCData(oldp+34,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_c),7);
    bufp->fullCData(oldp+35,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_d),7);
    bufp->fullBit(oldp+36,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_a));
    bufp->fullBit(oldp+37,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_b));
    bufp->fullBit(oldp+38,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_c));
    bufp->fullBit(oldp+39,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_d));
    bufp->fullCData(oldp+40,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_p),8);
    bufp->fullCData(oldp+41,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_m),8);
    bufp->fullCData(oldp+42,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_r),8);
    bufp->fullCData(oldp+43,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_n),8);
    bufp->fullCData(oldp+44,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_x),8);
    bufp->fullCData(oldp+45,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_y),8);
    bufp->fullCData(oldp+46,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_mx),8);
    bufp->fullCData(oldp+47,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_nx),8);
    bufp->fullCData(oldp+48,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_p),7);
    bufp->fullCData(oldp+49,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_m),7);
    bufp->fullCData(oldp+50,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_r),7);
    bufp->fullCData(oldp+51,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_n),7);
    bufp->fullCData(oldp+52,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_x),7);
    bufp->fullCData(oldp+53,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_y),7);
    bufp->fullCData(oldp+54,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_mx),7);
    bufp->fullCData(oldp+55,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__frac_nx),7);
    bufp->fullBit(oldp+56,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_p));
    bufp->fullBit(oldp+57,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_m));
    bufp->fullBit(oldp+58,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_r));
    bufp->fullBit(oldp+59,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_n));
    bufp->fullBit(oldp+60,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_x));
    bufp->fullBit(oldp+61,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_y));
    bufp->fullBit(oldp+62,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_mx));
    bufp->fullBit(oldp+63,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sign_nx));
    bufp->fullCData(oldp+64,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_x_eff),8);
    bufp->fullCData(oldp+65,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_y_eff),8);
    bufp->fullCData(oldp+66,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_mx_eff),8);
    bufp->fullCData(oldp+67,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__exp_nx_eff),8);
    bufp->fullSData(oldp+68,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__y_shift),9);
    bufp->fullSData(oldp+69,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__m_shift),9);
    bufp->fullSData(oldp+70,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__n_shift),9);
    bufp->fullIData(oldp+71,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__x_mant),24);
    bufp->fullIData(oldp+72,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__y_shifted),24);
    bufp->fullIData(oldp+73,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__m_shifted),24);
    bufp->fullIData(oldp+74,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__n_shifted),24);
    bufp->fullIData(oldp+75,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__y_mant_base),24);
    bufp->fullIData(oldp+76,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__m_mant_base),24);
    bufp->fullIData(oldp+77,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__n_mant_base),24);
    bufp->fullBit(oldp+78,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sticky_y));
    bufp->fullBit(oldp+79,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sticky_m));
    bufp->fullBit(oldp+80,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__sticky_n));
    bufp->fullBit(oldp+81,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__y_op));
    bufp->fullBit(oldp+82,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__m_op));
    bufp->fullBit(oldp+83,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__n_op));
    bufp->fullBit(oldp+84,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__is_nan_any));
    bufp->fullBit(oldp+85,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__special_case));
    bufp->fullBit(oldp+86,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__any_pos_inf));
    bufp->fullBit(oldp+87,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__any_neg_inf));
    bufp->fullIData(oldp+88,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__special_result),32);
    bufp->fullIData(oldp+89,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__op_x),27);
    bufp->fullIData(oldp+90,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__op_y),27);
    bufp->fullIData(oldp+91,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__op_m),27);
    bufp->fullIData(oldp+92,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__op_n),27);
    bufp->fullIData(oldp+93,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__csa_s1),27);
    bufp->fullIData(oldp+94,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__csa_c1),27);
    bufp->fullIData(oldp+95,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__csa_s2),27);
    bufp->fullIData(oldp+96,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__csa_c2),27);
    bufp->fullSData(oldp+97,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result),16);
    bufp->fullCData(oldp+98,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st1_a_e),8);
    bufp->fullBit(oldp+99,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st1_a_s));
    bufp->fullBit(oldp+100,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st1_align_sticky));
    bufp->fullBit(oldp+101,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st1_special_case));
    bufp->fullIData(oldp+102,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st1_special_result),32);
    bufp->fullIData(oldp+103,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st1_sum_vec),27);
    bufp->fullIData(oldp+104,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st1_carry_vec),27);
    bufp->fullCData(oldp+105,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st1_hot_ones),2);
    bufp->fullIData(oldp+106,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__raw_sum),28);
    bufp->fullIData(oldp+107,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__mag_sum),26);
    bufp->fullBit(oldp+108,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__res_sign));
    bufp->fullCData(oldp+109,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_exp_base),8);
    bufp->fullIData(oldp+110,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_sum_mag),26);
    bufp->fullIData(oldp+111,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_spec_res),32);
    bufp->fullBit(oldp+112,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_res_sign));
    bufp->fullBit(oldp+113,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_sticky));
    bufp->fullBit(oldp+114,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_special));
    bufp->fullIData(oldp+115,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan),26);
    bufp->fullCData(oldp+116,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros),6);
    bufp->fullIData(oldp+117,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__norm_val),26);
    bufp->fullIData(oldp+118,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__final_mant),23);
    bufp->fullSData(oldp+119,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__final_exp_calc),11);
    bufp->fullIData(oldp+120,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__result_out),32);
    bufp->fullIData(oldp+121,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__stage3_logic__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+122,(vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out),32);
    bufp->fullBit(oldp+123,((vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out 
                             >> 0x1fU)));
    bufp->fullCData(oldp+124,((0xffU & (vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out 
                                        >> 0x17U))),8);
    bufp->fullIData(oldp+125,((0x7fffffU & vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out)),23);
    bufp->fullSData(oldp+126,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__new_exp),10);
    bufp->fullCData(oldp+127,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__rounded),8);
    bufp->fullBit(oldp+128,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__guard));
    bufp->fullBit(oldp+129,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__rnd));
    bufp->fullBit(oldp+130,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__sticky));
    bufp->fullBit(oldp+131,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__round_up));
    bufp->fullBit(oldp+132,(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_clk));
}
