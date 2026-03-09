// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadd4_fp32_tb_softfloat__Syms.h"


VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root__trace_init_sub__TOP__add4_fp32_tb_softfloat__DOT__add_if__0(Vadd4_fp32_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root__trace_init_sub__TOP__0(Vadd4_fp32_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root__trace_init_sub__TOP__0\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("add4_fp32_tb_softfloat", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+172,0,"PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+173,0,"LATENCY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+174,0,"PRECISION_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+175,0,"EXPONENT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+176,0,"MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+171,0,"tb_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"tb_nrst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("add_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vadd4_fp32_tb_softfloat___024root__trace_init_sub__TOP__add4_fp32_tb_softfloat__DOT__add_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+2,0,"tb_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"tb_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"tb_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+5,0,"tb_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+126,0,"tb_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+6,0,"exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"pass_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+8,0,"fail_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+9,0,"off_by_one",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+10,0,"off_by_two",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+11,0,"off_by_five_plus",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+12,0,"diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+177,0,"P_INF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+178,0,"N_INF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+179,0,"NAN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+180,0,"P_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+181,0,"N_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+182,0,"ONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+183,0,"TWO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+184,0,"THREE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+185,0,"FOUR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+186,0,"MIN_SUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+187,0,"MAX_FINITE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"fd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+14,0,"fail_fd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+15,0,"a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,0,"b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+17,0,"c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"expected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("etchedfp4adder", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+176,0,"MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+175,0,"EXPONENT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+176,0,"OUT_MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+174,0,"PRECISION_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+171,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"nRST",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("add", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vadd4_fp32_tb_softfloat___024root__trace_init_sub__TOP__add4_fp32_tb_softfloat__DOT__add_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+176,0,"MAX_MANT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+188,0,"NEW_MANT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+189,0,"SUM_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+190,0,"MAX_EXP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+191,0,"RES_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+23,0,"a_daz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"b_daz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+25,0,"c_daz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,0,"d_daz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+27,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+28,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+29,0,"exp_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+30,0,"exp_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+31,0,"frac_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+32,0,"frac_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+33,0,"frac_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+34,0,"frac_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+35,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+37,0,"sign_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"sign_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+39,0,"exp_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+40,0,"exp_m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+41,0,"exp_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+42,0,"exp_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+43,0,"exp_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+44,0,"exp_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+45,0,"exp_mx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+46,0,"exp_nx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+47,0,"frac_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+48,0,"frac_m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+49,0,"frac_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+50,0,"frac_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+51,0,"frac_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+52,0,"frac_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+53,0,"frac_mx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+54,0,"frac_nx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+55,0,"sign_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"sign_m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"sign_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+58,0,"sign_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+59,0,"sign_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+60,0,"sign_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"sign_mx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"sign_nx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+63,0,"exp_x_eff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+64,0,"exp_y_eff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+65,0,"exp_mx_eff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+66,0,"exp_nx_eff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+67,0,"y_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+68,0,"m_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+69,0,"n_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declArray(c+70,0,"x_mant",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 74,0);
    tracep->declArray(c+73,0,"y_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 74,0);
    tracep->declArray(c+76,0,"m_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 74,0);
    tracep->declArray(c+79,0,"n_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 74,0);
    tracep->declArray(c+82,0,"y_mant_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 74,0);
    tracep->declArray(c+85,0,"m_mant_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 74,0);
    tracep->declArray(c+88,0,"n_mant_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 74,0);
    tracep->declBit(c+91,0,"sticky_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+92,0,"sticky_m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,0,"sticky_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+94,0,"y_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+95,0,"m_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"n_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+97,0,"is_nan_any",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"special_case",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"any_pos_inf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"any_neg_inf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+101,0,"special_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+127,0,"st1_a_e",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+128,0,"st1_a_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+129,0,"st1_align_sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+130,0,"st1_special_case",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+131,0,"st1_special_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+132,0,"st1_sum_vec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 77,0);
    tracep->declArray(c+135,0,"st1_carry_vec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 77,0);
    tracep->declBus(c+138,0,"st1_hot_ones",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declArray(c+139,0,"raw_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 78,0);
    tracep->declArray(c+142,0,"mag_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 76,0);
    tracep->declBit(c+145,0,"res_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+146,0,"st2_exp_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+147,0,"st2_sum_mag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 76,0);
    tracep->declBus(c+150,0,"st2_spec_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+151,0,"st2_res_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+152,0,"st2_sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+153,0,"st2_special",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+154,0,"lzd_scan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 76,0);
    tracep->declBus(c+157,0,"lead_zeros",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+158,0,"norm_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 76,0);
    tracep->declBus(c+161,0,"raw_mant",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+162,0,"final_mant",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+163,0,"rounded_mant_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+164,0,"final_exp_calc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBit(c+165,0,"guard_bit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+166,0,"round_bit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+167,0,"sticky_bit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+168,0,"round_up",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+169,0,"result_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+102,0,"op_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 77,0);
    tracep->declArray(c+105,0,"op_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 77,0);
    tracep->declArray(c+108,0,"op_m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 77,0);
    tracep->declArray(c+111,0,"op_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 77,0);
    tracep->declArray(c+114,0,"csa_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 77,0);
    tracep->declArray(c+117,0,"csa_c1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 77,0);
    tracep->declArray(c+120,0,"csa_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 77,0);
    tracep->declArray(c+123,0,"csa_c2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 77,0);
    tracep->pushPrefix("stage3_logic", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+170,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+20,0,"ret",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+21,0,"is_zero_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+22,0,"total_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root__trace_init_sub__TOP__add4_fp32_tb_softfloat__DOT__add_if__0(Vadd4_fp32_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root__trace_init_sub__TOP__add4_fp32_tb_softfloat__DOT__add_if__0\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+175,0,"EXPONENT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+176,0,"MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+176,0,"OUT_MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+174,0,"PRECISION_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+191,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+191,0,"OUTPUT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+5,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+126,0,"out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
}

VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root__trace_init_top(Vadd4_fp32_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root__trace_init_top\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vadd4_fp32_tb_softfloat___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadd4_fp32_tb_softfloat___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadd4_fp32_tb_softfloat___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root__trace_register(Vadd4_fp32_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root__trace_register\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vadd4_fp32_tb_softfloat___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vadd4_fp32_tb_softfloat___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vadd4_fp32_tb_softfloat___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vadd4_fp32_tb_softfloat___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root__trace_const_0_sub_0(Vadd4_fp32_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root__trace_const_0\n"); );
    // Init
    Vadd4_fp32_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd4_fp32_tb_softfloat___024root*>(voidSelf);
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vadd4_fp32_tb_softfloat___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root__trace_const_0_sub_0(Vadd4_fp32_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root__trace_const_0_sub_0\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+172,(2U),32);
    bufp->fullIData(oldp+173,(4U),32);
    bufp->fullIData(oldp+174,(0x32U),32);
    bufp->fullIData(oldp+175,(8U),32);
    bufp->fullIData(oldp+176,(0x17U),32);
    bufp->fullIData(oldp+177,(0x7f800000U),32);
    bufp->fullIData(oldp+178,(0xff800000U),32);
    bufp->fullIData(oldp+179,(0x7fc00000U),32);
    bufp->fullIData(oldp+180,(0U),32);
    bufp->fullIData(oldp+181,(0x80000000U),32);
    bufp->fullIData(oldp+182,(0x3f800000U),32);
    bufp->fullIData(oldp+183,(0x40000000U),32);
    bufp->fullIData(oldp+184,(0x40400000U),32);
    bufp->fullIData(oldp+185,(0x40800000U),32);
    bufp->fullIData(oldp+186,(1U),32);
    bufp->fullIData(oldp+187,(0x7f7fffffU),32);
    bufp->fullIData(oldp+188,(0x4bU),32);
    bufp->fullIData(oldp+189,(0x4dU),32);
    bufp->fullIData(oldp+190,(0xffU),32);
    bufp->fullIData(oldp+191,(0x20U),32);
}

VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root__trace_full_0_sub_0(Vadd4_fp32_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root__trace_full_0\n"); );
    // Init
    Vadd4_fp32_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd4_fp32_tb_softfloat___024root*>(voidSelf);
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vadd4_fp32_tb_softfloat___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root__trace_full_0_sub_0(Vadd4_fp32_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root__trace_full_0_sub_0\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_nrst));
    bufp->fullIData(oldp+2,(vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_a),32);
    bufp->fullIData(oldp+3,(vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_b),32);
    bufp->fullIData(oldp+4,(vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_c),32);
    bufp->fullIData(oldp+5,(vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_d),32);
    bufp->fullIData(oldp+6,(vlSelfRef.add4_fp32_tb_softfloat__DOT__exp),32);
    bufp->fullIData(oldp+7,(vlSelfRef.add4_fp32_tb_softfloat__DOT__pass_count),32);
    bufp->fullIData(oldp+8,(vlSelfRef.add4_fp32_tb_softfloat__DOT__fail_count),32);
    bufp->fullIData(oldp+9,(vlSelfRef.add4_fp32_tb_softfloat__DOT__off_by_one),32);
    bufp->fullIData(oldp+10,(vlSelfRef.add4_fp32_tb_softfloat__DOT__off_by_two),32);
    bufp->fullIData(oldp+11,(vlSelfRef.add4_fp32_tb_softfloat__DOT__off_by_five_plus),32);
    bufp->fullIData(oldp+12,(vlSelfRef.add4_fp32_tb_softfloat__DOT__diff),32);
    bufp->fullIData(oldp+13,(vlSelfRef.add4_fp32_tb_softfloat__DOT__fd),32);
    bufp->fullIData(oldp+14,(vlSelfRef.add4_fp32_tb_softfloat__DOT__fail_fd),32);
    bufp->fullIData(oldp+15,(vlSelfRef.add4_fp32_tb_softfloat__DOT__a),32);
    bufp->fullIData(oldp+16,(vlSelfRef.add4_fp32_tb_softfloat__DOT__b),32);
    bufp->fullIData(oldp+17,(vlSelfRef.add4_fp32_tb_softfloat__DOT__c),32);
    bufp->fullIData(oldp+18,(vlSelfRef.add4_fp32_tb_softfloat__DOT__d),32);
    bufp->fullIData(oldp+19,(vlSelfRef.add4_fp32_tb_softfloat__DOT__expected),32);
    bufp->fullIData(oldp+20,(vlSelfRef.add4_fp32_tb_softfloat__DOT__unnamedblk1__DOT__ret),32);
    bufp->fullBit(oldp+21,(vlSelfRef.add4_fp32_tb_softfloat__DOT__unnamedblk1__DOT__is_zero_result));
    bufp->fullIData(oldp+22,(vlSelfRef.add4_fp32_tb_softfloat__DOT__unnamedblk1__DOT__total_count),32);
    bufp->fullIData(oldp+23,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz),32);
    bufp->fullIData(oldp+24,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz),32);
    bufp->fullIData(oldp+25,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz),32);
    bufp->fullIData(oldp+26,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz),32);
    bufp->fullCData(oldp+27,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a),8);
    bufp->fullCData(oldp+28,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b),8);
    bufp->fullCData(oldp+29,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c),8);
    bufp->fullCData(oldp+30,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d),8);
    bufp->fullIData(oldp+31,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a),23);
    bufp->fullIData(oldp+32,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b),23);
    bufp->fullIData(oldp+33,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c),23);
    bufp->fullIData(oldp+34,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d),23);
    bufp->fullBit(oldp+35,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a));
    bufp->fullBit(oldp+36,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b));
    bufp->fullBit(oldp+37,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c));
    bufp->fullBit(oldp+38,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d));
    bufp->fullCData(oldp+39,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p),8);
    bufp->fullCData(oldp+40,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m),8);
    bufp->fullCData(oldp+41,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r),8);
    bufp->fullCData(oldp+42,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n),8);
    bufp->fullCData(oldp+43,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x),8);
    bufp->fullCData(oldp+44,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y),8);
    bufp->fullCData(oldp+45,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx),8);
    bufp->fullCData(oldp+46,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx),8);
    bufp->fullIData(oldp+47,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p),23);
    bufp->fullIData(oldp+48,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m),23);
    bufp->fullIData(oldp+49,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r),23);
    bufp->fullIData(oldp+50,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n),23);
    bufp->fullIData(oldp+51,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x),23);
    bufp->fullIData(oldp+52,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y),23);
    bufp->fullIData(oldp+53,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx),23);
    bufp->fullIData(oldp+54,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx),23);
    bufp->fullBit(oldp+55,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p));
    bufp->fullBit(oldp+56,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m));
    bufp->fullBit(oldp+57,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r));
    bufp->fullBit(oldp+58,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n));
    bufp->fullBit(oldp+59,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x));
    bufp->fullBit(oldp+60,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_y));
    bufp->fullBit(oldp+61,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_mx));
    bufp->fullBit(oldp+62,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_nx));
    bufp->fullCData(oldp+63,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff),8);
    bufp->fullCData(oldp+64,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y_eff),8);
    bufp->fullCData(oldp+65,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx_eff),8);
    bufp->fullCData(oldp+66,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx_eff),8);
    bufp->fullSData(oldp+67,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift),9);
    bufp->fullSData(oldp+68,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift),9);
    bufp->fullSData(oldp+69,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift),9);
    bufp->fullWData(oldp+70,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant),75);
    bufp->fullWData(oldp+73,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted),75);
    bufp->fullWData(oldp+76,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted),75);
    bufp->fullWData(oldp+79,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted),75);
    bufp->fullWData(oldp+82,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base),75);
    bufp->fullWData(oldp+85,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base),75);
    bufp->fullWData(oldp+88,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base),75);
    bufp->fullBit(oldp+91,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_y));
    bufp->fullBit(oldp+92,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_m));
    bufp->fullBit(oldp+93,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_n));
    bufp->fullBit(oldp+94,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_op));
    bufp->fullBit(oldp+95,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_op));
    bufp->fullBit(oldp+96,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_op));
    bufp->fullBit(oldp+97,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_any));
    bufp->fullBit(oldp+98,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__special_case));
    bufp->fullBit(oldp+99,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__any_pos_inf));
    bufp->fullBit(oldp+100,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__any_neg_inf));
    bufp->fullIData(oldp+101,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__special_result),32);
    bufp->fullWData(oldp+102,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x),78);
    bufp->fullWData(oldp+105,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y),78);
    bufp->fullWData(oldp+108,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m),78);
    bufp->fullWData(oldp+111,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n),78);
    bufp->fullWData(oldp+114,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1),78);
    bufp->fullWData(oldp+117,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c1),78);
    bufp->fullWData(oldp+120,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s2),78);
    bufp->fullWData(oldp+123,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c2),78);
    bufp->fullIData(oldp+126,(vlSymsp->TOP__add4_fp32_tb_softfloat__DOT__add_if.out),32);
    bufp->fullCData(oldp+127,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_e),8);
    bufp->fullBit(oldp+128,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s));
    bufp->fullBit(oldp+129,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_align_sticky));
    bufp->fullBit(oldp+130,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_case));
    bufp->fullIData(oldp+131,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_result),32);
    bufp->fullWData(oldp+132,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_sum_vec),78);
    bufp->fullWData(oldp+135,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_carry_vec),78);
    bufp->fullCData(oldp+138,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_hot_ones),2);
    bufp->fullWData(oldp+139,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum),79);
    bufp->fullWData(oldp+142,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum),77);
    bufp->fullBit(oldp+145,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__res_sign));
    bufp->fullCData(oldp+146,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_exp_base),8);
    bufp->fullWData(oldp+147,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag),77);
    bufp->fullIData(oldp+150,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_spec_res),32);
    bufp->fullBit(oldp+151,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign));
    bufp->fullBit(oldp+152,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sticky));
    bufp->fullBit(oldp+153,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special));
    bufp->fullWData(oldp+154,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan),77);
    bufp->fullCData(oldp+157,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros),8);
    bufp->fullWData(oldp+158,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val),77);
    bufp->fullIData(oldp+161,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__raw_mant),23);
    bufp->fullIData(oldp+162,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__final_mant),23);
    bufp->fullIData(oldp+163,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mant_int),24);
    bufp->fullSData(oldp+164,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc),11);
    bufp->fullBit(oldp+165,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__guard_bit));
    bufp->fullBit(oldp+166,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__round_bit));
    bufp->fullBit(oldp+167,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_bit));
    bufp->fullBit(oldp+168,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__round_up));
    bufp->fullIData(oldp+169,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__result_out),32);
    bufp->fullIData(oldp+170,(vlSelfRef.add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__stage3_logic__DOT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+171,(vlSelfRef.add4_fp32_tb_softfloat__DOT__tb_clk));
}
