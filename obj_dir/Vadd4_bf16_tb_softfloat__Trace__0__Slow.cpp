// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadd4_bf16_tb_softfloat__Syms.h"


VL_ATTR_COLD void Vadd4_bf16_tb_softfloat___024root__trace_init_sub__TOP__add4_bf16_tb_softfloat__DOT__add_if__0(Vadd4_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vadd4_bf16_tb_softfloat___024root__trace_init_sub__TOP__0(Vadd4_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_bf16_tb_softfloat___024root__trace_init_sub__TOP__0\n"); );
    Vadd4_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("add4_bf16_tb_softfloat", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+150,0,"PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+151,0,"LATENCY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+149,0,"tb_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"tb_nrst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("add_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vadd4_bf16_tb_softfloat___024root__trace_init_sub__TOP__add4_bf16_tb_softfloat__DOT__add_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+2,0,"tb_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+3,0,"tb_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+4,0,"tb_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+5,0,"tb_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+91,0,"tb_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+6,0,"exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+7,0,"pass_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+8,0,"fail_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+152,0,"P_INF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+153,0,"N_INF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+154,0,"NAN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+155,0,"P_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+156,0,"N_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+157,0,"ONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+158,0,"TWO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+159,0,"THREE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+160,0,"FOUR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+161,0,"MIN_SUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+162,0,"MAX_FINITE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+9,0,"fd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+10,0,"fail_fd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+11,0,"a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+12,0,"b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+13,0,"c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+14,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+15,0,"expected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("etchedfp4adder", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+163,0,"MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+164,0,"EXPONENT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+165,0,"PRECISION_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+149,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"nRST",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("add", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vadd4_bf16_tb_softfloat___024root__trace_init_sub__TOP__add4_bf16_tb_softfloat__DOT__add_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+166,0,"NEW_MANT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+167,0,"SUM_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+168,0,"LZD_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+169,0,"MAX_EXP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"a_daz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+20,0,"b_daz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+21,0,"c_daz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+22,0,"d_daz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+23,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+24,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+25,0,"exp_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+26,0,"exp_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+27,0,"frac_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+28,0,"frac_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+29,0,"frac_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+30,0,"frac_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+31,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"sign_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"sign_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+35,0,"exp_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+36,0,"exp_m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+37,0,"exp_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+38,0,"exp_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+39,0,"exp_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+40,0,"exp_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+41,0,"exp_mx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+42,0,"exp_nx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+43,0,"frac_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+44,0,"frac_m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+45,0,"frac_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+46,0,"frac_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+47,0,"frac_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+48,0,"frac_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+49,0,"frac_mx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+50,0,"frac_nx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+51,0,"sign_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"sign_m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"sign_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"sign_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"sign_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"sign_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"sign_mx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+58,0,"sign_nx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+59,0,"exp_x_eff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+60,0,"exp_y_eff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+61,0,"exp_mx_eff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+62,0,"exp_nx_eff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+63,0,"y_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+64,0,"m_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+65,0,"n_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declQuad(c+66,0,"x_mant",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declQuad(c+68,0,"y_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declQuad(c+70,0,"m_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declQuad(c+72,0,"n_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declQuad(c+74,0,"y_mant_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declQuad(c+76,0,"m_mant_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declQuad(c+78,0,"n_mant_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declBit(c+80,0,"sticky_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"sticky_m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"sticky_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"y_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"m_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"n_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"is_nan_any",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"special_case",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+88,0,"special_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+92,0,"st1_a_e",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declQuad(c+93,0,"st1_x_f",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declQuad(c+95,0,"st1_y_f",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declQuad(c+97,0,"st1_m_f",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declQuad(c+99,0,"st1_n_f",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declBus(c+101,0,"st1_special_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+102,0,"st1_a_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+103,0,"st1_b_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+104,0,"st1_c_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+105,0,"st1_d_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+106,0,"st1_align_sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+107,0,"st1_special_case",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+108,0,"sum_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 37,0);
    tracep->declQuad(c+110,0,"neg_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 37,0);
    tracep->declQuad(c+112,0,"neg_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 37,0);
    tracep->declQuad(c+114,0,"neg_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 37,0);
    tracep->declQuad(c+116,0,"mag_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 35,0);
    tracep->declQuad(c+118,0,"raw_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 36,0);
    tracep->declBus(c+120,0,"lead_zeros",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+121,0,"res_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+122,0,"st2_exp_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declQuad(c+123,0,"st2_sum_mag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 35,0);
    tracep->declBus(c+125,0,"st2_lzd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+126,0,"st2_spec_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+127,0,"st2_res_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+128,0,"st2_sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+129,0,"st2_special",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+130,0,"norm_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 35,0);
    tracep->declBus(c+132,0,"raw_mant",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+133,0,"final_mant",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+134,0,"rounded_mant_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+135,0,"final_exp_calc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBit(c+136,0,"guard_bit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+137,0,"round_bit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+138,0,"sticky_bit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+139,0,"round_up",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+140,0,"result_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+89,0,"any_pos_inf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"any_neg_inf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+141,0,"sum1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 37,0);
    tracep->declQuad(c+143,0,"carry1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 37,0);
    tracep->declQuad(c+145,0,"carry1_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 37,0);
    tracep->pushPrefix("stage2_logic", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+147,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+148,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+16,0,"ret",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+17,0,"is_zero_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+18,0,"total_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vadd4_bf16_tb_softfloat___024root__trace_init_sub__TOP__add4_bf16_tb_softfloat__DOT__add_if__0(Vadd4_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_bf16_tb_softfloat___024root__trace_init_sub__TOP__add4_bf16_tb_softfloat__DOT__add_if__0\n"); );
    Vadd4_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+164,0,"EXPONENT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+163,0,"MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+170,0,"PRECISION_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+3,0,"b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+4,0,"c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+5,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+91,0,"out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
}

VL_ATTR_COLD void Vadd4_bf16_tb_softfloat___024root__trace_init_top(Vadd4_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_bf16_tb_softfloat___024root__trace_init_top\n"); );
    Vadd4_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vadd4_bf16_tb_softfloat___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vadd4_bf16_tb_softfloat___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vadd4_bf16_tb_softfloat___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadd4_bf16_tb_softfloat___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadd4_bf16_tb_softfloat___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vadd4_bf16_tb_softfloat___024root__trace_register(Vadd4_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_bf16_tb_softfloat___024root__trace_register\n"); );
    Vadd4_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vadd4_bf16_tb_softfloat___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vadd4_bf16_tb_softfloat___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vadd4_bf16_tb_softfloat___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vadd4_bf16_tb_softfloat___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vadd4_bf16_tb_softfloat___024root__trace_const_0_sub_0(Vadd4_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vadd4_bf16_tb_softfloat___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_bf16_tb_softfloat___024root__trace_const_0\n"); );
    // Init
    Vadd4_bf16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd4_bf16_tb_softfloat___024root*>(voidSelf);
    Vadd4_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vadd4_bf16_tb_softfloat___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vadd4_bf16_tb_softfloat___024root__trace_const_0_sub_0(Vadd4_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_bf16_tb_softfloat___024root__trace_const_0_sub_0\n"); );
    Vadd4_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+150,(2U),32);
    bufp->fullIData(oldp+151,(4U),32);
    bufp->fullSData(oldp+152,(0x7f80U),16);
    bufp->fullSData(oldp+153,(0xff80U),16);
    bufp->fullSData(oldp+154,(0x7fc0U),16);
    bufp->fullSData(oldp+155,(0U),16);
    bufp->fullSData(oldp+156,(0x8000U),16);
    bufp->fullSData(oldp+157,(0x3f80U),16);
    bufp->fullSData(oldp+158,(0x4000U),16);
    bufp->fullSData(oldp+159,(0x4040U),16);
    bufp->fullSData(oldp+160,(0x4080U),16);
    bufp->fullSData(oldp+161,(1U),16);
    bufp->fullSData(oldp+162,(0x7f7fU),16);
    bufp->fullIData(oldp+163,(7U),32);
    bufp->fullIData(oldp+164,(8U),32);
    bufp->fullIData(oldp+165,(0x19U),32);
    bufp->fullIData(oldp+166,(0x22U),32);
    bufp->fullIData(oldp+167,(0x24U),32);
    bufp->fullIData(oldp+168,(6U),32);
    bufp->fullIData(oldp+169,(0xffU),32);
    bufp->fullIData(oldp+170,(3U),32);
    bufp->fullIData(oldp+171,(0x10U),32);
}

VL_ATTR_COLD void Vadd4_bf16_tb_softfloat___024root__trace_full_0_sub_0(Vadd4_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vadd4_bf16_tb_softfloat___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_bf16_tb_softfloat___024root__trace_full_0\n"); );
    // Init
    Vadd4_bf16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd4_bf16_tb_softfloat___024root*>(voidSelf);
    Vadd4_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vadd4_bf16_tb_softfloat___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vadd4_bf16_tb_softfloat___024root__trace_full_0_sub_0(Vadd4_bf16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_bf16_tb_softfloat___024root__trace_full_0_sub_0\n"); );
    Vadd4_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.add4_bf16_tb_softfloat__DOT__tb_nrst));
    bufp->fullSData(oldp+2,(vlSelfRef.add4_bf16_tb_softfloat__DOT__tb_a),16);
    bufp->fullSData(oldp+3,(vlSelfRef.add4_bf16_tb_softfloat__DOT__tb_b),16);
    bufp->fullSData(oldp+4,(vlSelfRef.add4_bf16_tb_softfloat__DOT__tb_c),16);
    bufp->fullSData(oldp+5,(vlSelfRef.add4_bf16_tb_softfloat__DOT__tb_d),16);
    bufp->fullSData(oldp+6,(vlSelfRef.add4_bf16_tb_softfloat__DOT__exp),16);
    bufp->fullIData(oldp+7,(vlSelfRef.add4_bf16_tb_softfloat__DOT__pass_count),32);
    bufp->fullIData(oldp+8,(vlSelfRef.add4_bf16_tb_softfloat__DOT__fail_count),32);
    bufp->fullIData(oldp+9,(vlSelfRef.add4_bf16_tb_softfloat__DOT__fd),32);
    bufp->fullIData(oldp+10,(vlSelfRef.add4_bf16_tb_softfloat__DOT__fail_fd),32);
    bufp->fullSData(oldp+11,(vlSelfRef.add4_bf16_tb_softfloat__DOT__a),16);
    bufp->fullSData(oldp+12,(vlSelfRef.add4_bf16_tb_softfloat__DOT__b),16);
    bufp->fullSData(oldp+13,(vlSelfRef.add4_bf16_tb_softfloat__DOT__c),16);
    bufp->fullSData(oldp+14,(vlSelfRef.add4_bf16_tb_softfloat__DOT__d),16);
    bufp->fullSData(oldp+15,(vlSelfRef.add4_bf16_tb_softfloat__DOT__expected),16);
    bufp->fullIData(oldp+16,(vlSelfRef.add4_bf16_tb_softfloat__DOT__unnamedblk1__DOT__ret),32);
    bufp->fullBit(oldp+17,(vlSelfRef.add4_bf16_tb_softfloat__DOT__unnamedblk1__DOT__is_zero_result));
    bufp->fullIData(oldp+18,(vlSelfRef.add4_bf16_tb_softfloat__DOT__unnamedblk1__DOT__total_count),32);
    bufp->fullSData(oldp+19,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz),16);
    bufp->fullSData(oldp+20,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz),16);
    bufp->fullSData(oldp+21,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz),16);
    bufp->fullSData(oldp+22,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz),16);
    bufp->fullCData(oldp+23,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a),8);
    bufp->fullCData(oldp+24,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b),8);
    bufp->fullCData(oldp+25,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c),8);
    bufp->fullCData(oldp+26,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d),8);
    bufp->fullCData(oldp+27,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a),7);
    bufp->fullCData(oldp+28,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b),7);
    bufp->fullCData(oldp+29,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c),7);
    bufp->fullCData(oldp+30,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d),7);
    bufp->fullBit(oldp+31,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a));
    bufp->fullBit(oldp+32,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b));
    bufp->fullBit(oldp+33,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c));
    bufp->fullBit(oldp+34,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d));
    bufp->fullCData(oldp+35,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p),8);
    bufp->fullCData(oldp+36,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m),8);
    bufp->fullCData(oldp+37,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r),8);
    bufp->fullCData(oldp+38,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n),8);
    bufp->fullCData(oldp+39,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x),8);
    bufp->fullCData(oldp+40,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y),8);
    bufp->fullCData(oldp+41,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx),8);
    bufp->fullCData(oldp+42,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx),8);
    bufp->fullCData(oldp+43,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p),7);
    bufp->fullCData(oldp+44,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m),7);
    bufp->fullCData(oldp+45,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r),7);
    bufp->fullCData(oldp+46,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n),7);
    bufp->fullCData(oldp+47,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x),7);
    bufp->fullCData(oldp+48,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y),7);
    bufp->fullCData(oldp+49,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx),7);
    bufp->fullCData(oldp+50,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx),7);
    bufp->fullBit(oldp+51,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p));
    bufp->fullBit(oldp+52,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m));
    bufp->fullBit(oldp+53,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r));
    bufp->fullBit(oldp+54,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n));
    bufp->fullBit(oldp+55,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x));
    bufp->fullBit(oldp+56,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_y));
    bufp->fullBit(oldp+57,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_mx));
    bufp->fullBit(oldp+58,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_nx));
    bufp->fullCData(oldp+59,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff),8);
    bufp->fullCData(oldp+60,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y_eff),8);
    bufp->fullCData(oldp+61,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx_eff),8);
    bufp->fullCData(oldp+62,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx_eff),8);
    bufp->fullSData(oldp+63,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift),9);
    bufp->fullSData(oldp+64,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift),9);
    bufp->fullSData(oldp+65,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift),9);
    bufp->fullQData(oldp+66,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant),34);
    bufp->fullQData(oldp+68,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted),34);
    bufp->fullQData(oldp+70,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted),34);
    bufp->fullQData(oldp+72,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted),34);
    bufp->fullQData(oldp+74,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base),34);
    bufp->fullQData(oldp+76,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base),34);
    bufp->fullQData(oldp+78,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base),34);
    bufp->fullBit(oldp+80,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_y));
    bufp->fullBit(oldp+81,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_m));
    bufp->fullBit(oldp+82,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_n));
    bufp->fullBit(oldp+83,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__y_op));
    bufp->fullBit(oldp+84,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__m_op));
    bufp->fullBit(oldp+85,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__n_op));
    bufp->fullBit(oldp+86,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_any));
    bufp->fullBit(oldp+87,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case));
    bufp->fullSData(oldp+88,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result),16);
    bufp->fullBit(oldp+89,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__any_pos_inf));
    bufp->fullBit(oldp+90,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__any_neg_inf));
    bufp->fullSData(oldp+91,(vlSymsp->TOP__add4_bf16_tb_softfloat__DOT__add_if.out),16);
    bufp->fullCData(oldp+92,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_e),8);
    bufp->fullQData(oldp+93,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f),34);
    bufp->fullQData(oldp+95,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_y_f),34);
    bufp->fullQData(oldp+97,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_m_f),34);
    bufp->fullQData(oldp+99,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_n_f),34);
    bufp->fullSData(oldp+101,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_result),16);
    bufp->fullBit(oldp+102,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s));
    bufp->fullBit(oldp+103,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_b_op));
    bufp->fullBit(oldp+104,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_c_op));
    bufp->fullBit(oldp+105,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_d_op));
    bufp->fullBit(oldp+106,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_align_sticky));
    bufp->fullBit(oldp+107,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_case));
    bufp->fullQData(oldp+108,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_a),38);
    bufp->fullQData(oldp+110,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_b),38);
    bufp->fullQData(oldp+112,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_c),38);
    bufp->fullQData(oldp+114,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__neg_d),38);
    bufp->fullQData(oldp+116,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum),36);
    bufp->fullQData(oldp+118,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum),37);
    bufp->fullCData(oldp+120,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros),6);
    bufp->fullBit(oldp+121,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__res_sign));
    bufp->fullCData(oldp+122,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_exp_base),8);
    bufp->fullQData(oldp+123,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag),36);
    bufp->fullCData(oldp+125,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_lzd),6);
    bufp->fullSData(oldp+126,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_spec_res),16);
    bufp->fullBit(oldp+127,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign));
    bufp->fullBit(oldp+128,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sticky));
    bufp->fullBit(oldp+129,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special));
    bufp->fullQData(oldp+130,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val),36);
    bufp->fullCData(oldp+132,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_mant),7);
    bufp->fullCData(oldp+133,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__final_mant),7);
    bufp->fullCData(oldp+134,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mant_int),8);
    bufp->fullSData(oldp+135,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc),11);
    bufp->fullBit(oldp+136,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__guard_bit));
    bufp->fullBit(oldp+137,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__round_bit));
    bufp->fullBit(oldp+138,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_bit));
    bufp->fullBit(oldp+139,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__round_up));
    bufp->fullSData(oldp+140,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__result_out),16);
    bufp->fullQData(oldp+141,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__sum1),38);
    bufp->fullQData(oldp+143,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1),38);
    bufp->fullQData(oldp+145,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__carry1_shifted),38);
    bufp->fullIData(oldp+147,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_logic__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+148,(vlSelfRef.add4_bf16_tb_softfloat__DOT__etchedfp4adder__DOT__stage2_logic__DOT__unnamedblk2__DOT__i),32);
    bufp->fullBit(oldp+149,(vlSelfRef.add4_bf16_tb_softfloat__DOT__tb_clk));
}
