// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadd4_fp16_tb_softfloat__Syms.h"


VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root__trace_init_sub__TOP__add4_fp16_tb_softfloat__DOT__add_if__0(Vadd4_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root__trace_init_sub__TOP__0(Vadd4_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root__trace_init_sub__TOP__0\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("add4_fp16_tb_softfloat", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+261,0,"PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+262,0,"LATENCY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+260,0,"tb_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"tb_nrst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("add_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vadd4_fp16_tb_softfloat___024root__trace_init_sub__TOP__add4_fp16_tb_softfloat__DOT__add_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+2,0,"tb_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+3,0,"tb_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+4,0,"tb_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+5,0,"tb_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+81,0,"tb_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+6,0,"exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+7,0,"pass_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+8,0,"fail_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+263,0,"P_INF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+264,0,"N_INF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+265,0,"NAN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+266,0,"P_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+267,0,"N_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+268,0,"ONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+269,0,"TWO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+270,0,"THREE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+271,0,"FOUR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+272,0,"MIN_SUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+273,0,"MAX_FINITE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+9,0,"fd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+10,0,"fail_fd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+11,0,"a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+12,0,"b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+13,0,"c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+14,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+15,0,"expected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("etchedfp4adder", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+274,0,"MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+275,0,"EXPONENT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+276,0,"PRECISION_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+260,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"nRST",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("add", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vadd4_fp16_tb_softfloat___024root__trace_init_sub__TOP__add4_fp16_tb_softfloat__DOT__add_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+277,0,"NEW_MANT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+82,0,"st1_a_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"st1_b_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"st1_c_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"st1_d_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+86,0,"st1_a_e",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+87,0,"st1_x_f",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+88,0,"st1_y_f",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+89,0,"st1_m_f",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+90,0,"st1_n_f",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBit(c+91,0,"st1_special_case",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+92,0,"st1_special_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+93,0,"st2_special_case",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+94,0,"st2_special_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+95,0,"sum_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+96,0,"result_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+97,0,"a_e_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+98,0,"num_leading_zeros",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+99,0,"sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+100,0,"right_shift_radix",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("first_stage", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+275,0,"EXP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+274,0,"MANTISSA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+276,0,"PRECISION",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+260,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"n_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+3,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+4,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+5,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+86,0,"x_e_f",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+82,0,"x_s_f",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+87,0,"x_f",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+88,0,"y_shifted_f",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+89,0,"m_shifted_f",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+90,0,"n_shifted_f",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBit(c+83,0,"y_op_f",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"m_op_f",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"n_op_f",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+91,0,"special_case_f",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+92,0,"special_result_f",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+277,0,"MANT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"a_daz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+20,0,"b_daz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+21,0,"c_daz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+22,0,"d_daz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+23,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+24,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+25,0,"exp_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+26,0,"exp_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+27,0,"frac_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+28,0,"frac_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+29,0,"frac_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+30,0,"frac_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+31,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"sign_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"sign_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+35,0,"exp_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+36,0,"exp_m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+37,0,"exp_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+38,0,"exp_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+39,0,"exp_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+40,0,"exp_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+41,0,"exp_mx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+42,0,"exp_nx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+43,0,"frac_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+44,0,"frac_m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+45,0,"frac_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+46,0,"frac_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+47,0,"frac_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+48,0,"frac_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+49,0,"frac_mx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+50,0,"frac_nx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+51,0,"sign_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"sign_m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"sign_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"sign_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"sign_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"sign_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"sign_mx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+58,0,"sign_nx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+59,0,"y_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+60,0,"m_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+61,0,"n_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+62,0,"x_mant",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+63,0,"y_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+64,0,"m_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+65,0,"n_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBit(c+66,0,"y_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"m_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"n_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"is_nan_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"is_nan_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"is_nan_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+72,0,"is_nan_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+73,0,"is_inf_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+74,0,"is_inf_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+75,0,"is_inf_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,0,"is_inf_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"special_case",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+78,0,"special_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+79,0,"has_pos_inf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+80,0,"has_neg_inf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("second_stage", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+274,0,"MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+275,0,"EXPONENT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+276,0,"PRECISION_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+260,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"nRST",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"a_s",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"b_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"c_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"d_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,0,"b_sb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+102,0,"c_sb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+103,0,"d_sb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+86,0,"a_e",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+104,0,"a_f",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBus(c+105,0,"b_f",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBus(c+106,0,"c_f",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBus(c+107,0,"d_f",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBus(c+95,0,"sum_i",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+96,0,"result_s",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+97,0,"a_e_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+98,0,"num_leading_zeros",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+100,0,"right_shift_radix",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+277,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+108,0,"b_inv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+109,0,"c_inv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+110,0,"d_inv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+111,0,"s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+112,0,"c1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+113,0,"s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+114,0,"c2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+115,0,"signed_sb_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+116,0,"next_result_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+117,0,"next_num_leading_zeros",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+118,0,"magnitude_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBus(c+119,0,"corrected_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("loop_s1[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+120,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+121,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+122,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s1[10]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+125,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+127,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+128,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+129,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s1[11]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+130,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+131,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+132,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s1[12]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+135,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+136,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+137,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+138,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+139,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s1[13]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+140,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+141,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+142,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+143,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+144,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s1[14]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+278,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+145,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+146,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+147,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+148,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s1[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+149,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+150,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+151,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+152,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+153,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s1[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+154,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+155,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+156,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+157,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+158,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s1[3]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+159,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+160,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+161,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+162,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+163,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s1[4]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+164,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+165,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+166,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+167,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+168,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s1[5]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+169,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+170,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+171,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+172,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+173,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s1[6]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+174,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+175,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+176,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+178,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s1[7]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+179,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+180,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+181,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+182,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+183,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s1[8]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+184,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+185,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+186,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+187,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+188,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s1[9]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+189,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+190,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+191,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+192,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+193,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s2[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+123,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+194,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+278,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+195,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+196,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s2[10]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+128,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+197,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+193,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+198,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+199,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s2[11]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+133,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+200,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+129,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+201,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+202,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s2[12]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+138,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+203,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+204,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+205,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s2[13]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+143,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+206,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+139,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+207,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+208,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s2[14]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+147,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+209,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+144,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+210,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+211,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s2[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+152,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+212,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+214,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s2[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+157,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+215,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+153,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+216,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+217,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s2[3]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+162,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+218,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+158,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+219,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+220,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s2[4]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+167,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+221,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+163,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+222,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+223,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s2[5]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+172,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+224,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+168,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+225,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+226,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s2[6]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+177,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+173,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+229,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s2[7]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+182,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+230,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+178,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+231,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+232,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s2[8]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+187,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+233,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+183,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+234,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+235,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("loop_s2[9]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("fa_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+192,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+236,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+188,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+237,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+238,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+239,0,"k",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("third_stage", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+275,0,"EXPONENT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+274,0,"MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+276,0,"PRECISION_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+260,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"nRST",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+98,0,"leading_zeros",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+100,0,"right_shifts",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+95,0,"sum",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+96,0,"sign",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+97,0,"exponent",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+93,0,"special_case",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+94,0,"special_result",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+99,0,"final_sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+240,0,"shifted_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBus(c+241,0,"sum_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBus(c+242,0,"leading_zeros_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+243,0,"sign_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+244,0,"exponent_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+245,0,"special_case_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+246,0,"special_result_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+247,0,"final_sum_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+248,0,"right_shift_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+249,0,"overflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+250,0,"unrounded_mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+251,0,"rounded_mantissa_internal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBit(c+252,0,"guard",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+253,0,"round",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+254,0,"sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+255,0,"round_up",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+256,0,"final_mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+257,0,"new_exponent_internal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+258,0,"new_exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+259,0,"inf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+16,0,"ret",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+17,0,"is_zero_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+18,0,"total_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root__trace_init_sub__TOP__add4_fp16_tb_softfloat__DOT__add_if__0(Vadd4_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root__trace_init_sub__TOP__add4_fp16_tb_softfloat__DOT__add_if__0\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+275,0,"EXPONENT_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+274,0,"MANTISSA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+276,0,"PRECISION_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+279,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+3,0,"b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+4,0,"c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+5,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+81,0,"out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
}

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root__trace_init_top(Vadd4_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root__trace_init_top\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vadd4_fp16_tb_softfloat___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadd4_fp16_tb_softfloat___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadd4_fp16_tb_softfloat___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root__trace_register(Vadd4_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root__trace_register\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vadd4_fp16_tb_softfloat___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vadd4_fp16_tb_softfloat___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vadd4_fp16_tb_softfloat___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vadd4_fp16_tb_softfloat___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root__trace_const_0_sub_0(Vadd4_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root__trace_const_0\n"); );
    // Init
    Vadd4_fp16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd4_fp16_tb_softfloat___024root*>(voidSelf);
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vadd4_fp16_tb_softfloat___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root__trace_const_0_sub_0(Vadd4_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root__trace_const_0_sub_0\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+261,(2U),32);
    bufp->fullIData(oldp+262,(4U),32);
    bufp->fullSData(oldp+263,(0x7c00U),16);
    bufp->fullSData(oldp+264,(0xfc00U),16);
    bufp->fullSData(oldp+265,(0x7d00U),16);
    bufp->fullSData(oldp+266,(0U),16);
    bufp->fullSData(oldp+267,(0x8000U),16);
    bufp->fullSData(oldp+268,(0x3c00U),16);
    bufp->fullSData(oldp+269,(0x4000U),16);
    bufp->fullSData(oldp+270,(0x4200U),16);
    bufp->fullSData(oldp+271,(0x4400U),16);
    bufp->fullSData(oldp+272,(1U),16);
    bufp->fullSData(oldp+273,(0x7bffU),16);
    bufp->fullIData(oldp+274,(0xaU),32);
    bufp->fullIData(oldp+275,(5U),32);
    bufp->fullIData(oldp+276,(3U),32);
    bufp->fullIData(oldp+277,(0xfU),32);
    bufp->fullBit(oldp+278,(0U));
    bufp->fullIData(oldp+279,(0x10U),32);
}

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root__trace_full_0_sub_0(Vadd4_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root__trace_full_0\n"); );
    // Init
    Vadd4_fp16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd4_fp16_tb_softfloat___024root*>(voidSelf);
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vadd4_fp16_tb_softfloat___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root__trace_full_0_sub_0(Vadd4_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root__trace_full_0_sub_0\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_nrst));
    bufp->fullSData(oldp+2,(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a),16);
    bufp->fullSData(oldp+3,(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b),16);
    bufp->fullSData(oldp+4,(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c),16);
    bufp->fullSData(oldp+5,(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d),16);
    bufp->fullSData(oldp+6,(vlSelfRef.add4_fp16_tb_softfloat__DOT__exp),16);
    bufp->fullIData(oldp+7,(vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count),32);
    bufp->fullIData(oldp+8,(vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count),32);
    bufp->fullIData(oldp+9,(vlSelfRef.add4_fp16_tb_softfloat__DOT__fd),32);
    bufp->fullIData(oldp+10,(vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_fd),32);
    bufp->fullSData(oldp+11,(vlSelfRef.add4_fp16_tb_softfloat__DOT__a),16);
    bufp->fullSData(oldp+12,(vlSelfRef.add4_fp16_tb_softfloat__DOT__b),16);
    bufp->fullSData(oldp+13,(vlSelfRef.add4_fp16_tb_softfloat__DOT__c),16);
    bufp->fullSData(oldp+14,(vlSelfRef.add4_fp16_tb_softfloat__DOT__d),16);
    bufp->fullSData(oldp+15,(vlSelfRef.add4_fp16_tb_softfloat__DOT__expected),16);
    bufp->fullIData(oldp+16,(vlSelfRef.add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__ret),32);
    bufp->fullBit(oldp+17,(vlSelfRef.add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__is_zero_result));
    bufp->fullIData(oldp+18,(vlSelfRef.add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__total_count),32);
    bufp->fullSData(oldp+19,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__a_daz),16);
    bufp->fullSData(oldp+20,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__b_daz),16);
    bufp->fullSData(oldp+21,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__c_daz),16);
    bufp->fullSData(oldp+22,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__d_daz),16);
    bufp->fullCData(oldp+23,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_a),5);
    bufp->fullCData(oldp+24,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_b),5);
    bufp->fullCData(oldp+25,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_c),5);
    bufp->fullCData(oldp+26,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_d),5);
    bufp->fullSData(oldp+27,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_a),10);
    bufp->fullSData(oldp+28,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_b),10);
    bufp->fullSData(oldp+29,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_c),10);
    bufp->fullSData(oldp+30,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_d),10);
    bufp->fullBit(oldp+31,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_a));
    bufp->fullBit(oldp+32,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_b));
    bufp->fullBit(oldp+33,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_c));
    bufp->fullBit(oldp+34,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_d));
    bufp->fullCData(oldp+35,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_p),5);
    bufp->fullCData(oldp+36,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_m),5);
    bufp->fullCData(oldp+37,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_r),5);
    bufp->fullCData(oldp+38,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_n),5);
    bufp->fullCData(oldp+39,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_x),5);
    bufp->fullCData(oldp+40,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_y),5);
    bufp->fullCData(oldp+41,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_mx),5);
    bufp->fullCData(oldp+42,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__exp_nx),5);
    bufp->fullSData(oldp+43,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_p),10);
    bufp->fullSData(oldp+44,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_m),10);
    bufp->fullSData(oldp+45,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_r),10);
    bufp->fullSData(oldp+46,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_n),10);
    bufp->fullSData(oldp+47,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_x),10);
    bufp->fullSData(oldp+48,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_y),10);
    bufp->fullSData(oldp+49,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_mx),10);
    bufp->fullSData(oldp+50,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__frac_nx),10);
    bufp->fullBit(oldp+51,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_p));
    bufp->fullBit(oldp+52,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_m));
    bufp->fullBit(oldp+53,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_r));
    bufp->fullBit(oldp+54,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_n));
    bufp->fullBit(oldp+55,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_x));
    bufp->fullBit(oldp+56,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_y));
    bufp->fullBit(oldp+57,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_mx));
    bufp->fullBit(oldp+58,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__sign_nx));
    bufp->fullCData(oldp+59,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__y_shift),5);
    bufp->fullCData(oldp+60,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__m_shift),5);
    bufp->fullCData(oldp+61,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__n_shift),5);
    bufp->fullSData(oldp+62,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__x_mant),15);
    bufp->fullSData(oldp+63,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__y_shifted),15);
    bufp->fullSData(oldp+64,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__m_shifted),15);
    bufp->fullSData(oldp+65,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__n_shifted),15);
    bufp->fullBit(oldp+66,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__y_op));
    bufp->fullBit(oldp+67,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__m_op));
    bufp->fullBit(oldp+68,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__n_op));
    bufp->fullBit(oldp+69,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_nan_a));
    bufp->fullBit(oldp+70,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_nan_b));
    bufp->fullBit(oldp+71,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_nan_c));
    bufp->fullBit(oldp+72,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_nan_d));
    bufp->fullBit(oldp+73,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_a));
    bufp->fullBit(oldp+74,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_b));
    bufp->fullBit(oldp+75,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_c));
    bufp->fullBit(oldp+76,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__is_inf_d));
    bufp->fullBit(oldp+77,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__special_case));
    bufp->fullSData(oldp+78,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__special_result),16);
    bufp->fullBit(oldp+79,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__unnamedblk1__DOT__has_pos_inf));
    bufp->fullBit(oldp+80,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__first_stage__DOT__unnamedblk1__DOT__has_neg_inf));
    bufp->fullSData(oldp+81,(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out),16);
    bufp->fullBit(oldp+82,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s));
    bufp->fullBit(oldp+83,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_b_op));
    bufp->fullBit(oldp+84,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_c_op));
    bufp->fullBit(oldp+85,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_d_op));
    bufp->fullCData(oldp+86,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_e),5);
    bufp->fullSData(oldp+87,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f),15);
    bufp->fullSData(oldp+88,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_y_f),15);
    bufp->fullSData(oldp+89,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_m_f),15);
    bufp->fullSData(oldp+90,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_n_f),15);
    bufp->fullBit(oldp+91,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_case));
    bufp->fullSData(oldp+92,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_result),16);
    bufp->fullBit(oldp+93,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special_case));
    bufp->fullSData(oldp+94,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special_result),16);
    bufp->fullSData(oldp+95,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum_i),16);
    bufp->fullBit(oldp+96,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__result_s));
    bufp->fullCData(oldp+97,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__a_e_out),5);
    bufp->fullCData(oldp+98,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__num_leading_zeros),4);
    bufp->fullSData(oldp+99,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sum),16);
    bufp->fullCData(oldp+100,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__right_shift_radix),2);
    bufp->fullBit(oldp+101,((1U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_y_f))));
    bufp->fullBit(oldp+102,((1U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_m_f))));
    bufp->fullBit(oldp+103,((1U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_n_f))));
    bufp->fullSData(oldp+104,((0x3fffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                          >> 1U))),14);
    bufp->fullSData(oldp+105,((0x3fffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_y_f) 
                                          >> 1U))),14);
    bufp->fullSData(oldp+106,((0x3fffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_m_f) 
                                          >> 1U))),14);
    bufp->fullSData(oldp+107,((0x3fffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_n_f) 
                                          >> 1U))),14);
    bufp->fullSData(oldp+108,((0x7fffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_1_0)),15);
    bufp->fullSData(oldp+109,((0x7fffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_2_0)),15);
    bufp->fullSData(oldp+110,((0x7fffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0)),15);
    bufp->fullSData(oldp+111,(((((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__14__KET____DOT__fa_1__sum) 
                                   << 0xeU) | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__13__KET____DOT__fa_1__sum) 
                                               << 0xdU)) 
                                 | (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__sum) 
                                     << 0xcU) | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__sum) 
                                                 << 0xbU))) 
                                | ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__sum) 
                                     << 0xaU) | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__sum) 
                                                 << 9U)) 
                                   | (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__sum) 
                                       << 8U) | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__sum) 
                                                 << 7U)))) 
                               | (((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__sum) 
                                     << 6U) | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__sum) 
                                               << 5U)) 
                                   | (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__sum) 
                                       << 4U) | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__sum) 
                                                 << 3U))) 
                                  | (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__sum) 
                                      << 2U) | (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__sum) 
                                                 << 1U) 
                                                | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__s1__BRA__0__KET__)))))),15);
    bufp->fullSData(oldp+112,((((((0x4000U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_1_0 
                                              & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_2_0)) 
                                  | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__13__KET____DOT__fa_1__co) 
                                     << 0xdU)) | (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__co) 
                                                   << 0xcU) 
                                                  | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__co) 
                                                     << 0xbU))) 
                                | ((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__co) 
                                     << 0xaU) | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__co) 
                                                 << 9U)) 
                                   | (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__co) 
                                       << 8U) | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__co) 
                                                 << 7U)))) 
                               | (((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__co) 
                                     << 6U) | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__co) 
                                               << 5U)) 
                                   | (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__co) 
                                       << 4U) | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__co) 
                                                 << 3U))) 
                                  | (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__co) 
                                      << 2U) | (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__co) 
                                                 << 1U) 
                                                | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c1__BRA__0__KET__)))))),15);
    bufp->fullSData(oldp+113,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__s2),15);
    bufp->fullSData(oldp+114,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c2),15);
    bufp->fullCData(oldp+115,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__signed_sb_sum),3);
    bufp->fullBit(oldp+116,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__next_result_s));
    bufp->fullCData(oldp+117,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__next_num_leading_zeros),4);
    bufp->fullIData(oldp+118,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__magnitude_sum),17);
    bufp->fullSData(oldp+119,((0xffffU & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_0_0)),16);
    bufp->fullBit(oldp+120,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                   >> 1U))));
    bufp->fullBit(oldp+121,((1U & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_1_0)));
    bufp->fullBit(oldp+122,((1U & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_2_0)));
    bufp->fullBit(oldp+123,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__s1__BRA__0__KET__));
    bufp->fullBit(oldp+124,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c1__BRA__0__KET__));
    bufp->fullBit(oldp+125,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                   >> 0xbU))));
    bufp->fullBit(oldp+126,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_1_0 
                                   >> 0xaU))));
    bufp->fullBit(oldp+127,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_2_0 
                                   >> 0xaU))));
    bufp->fullBit(oldp+128,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__sum));
    bufp->fullBit(oldp+129,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__co));
    bufp->fullBit(oldp+130,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                   >> 0xcU))));
    bufp->fullBit(oldp+131,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_1_0 
                                   >> 0xbU))));
    bufp->fullBit(oldp+132,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_2_0 
                                   >> 0xbU))));
    bufp->fullBit(oldp+133,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__sum));
    bufp->fullBit(oldp+134,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__co));
    bufp->fullBit(oldp+135,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                   >> 0xdU))));
    bufp->fullBit(oldp+136,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_1_0 
                                   >> 0xcU))));
    bufp->fullBit(oldp+137,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_2_0 
                                   >> 0xcU))));
    bufp->fullBit(oldp+138,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__sum));
    bufp->fullBit(oldp+139,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__co));
    bufp->fullBit(oldp+140,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                   >> 0xeU))));
    bufp->fullBit(oldp+141,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_1_0 
                                   >> 0xdU))));
    bufp->fullBit(oldp+142,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_2_0 
                                   >> 0xdU))));
    bufp->fullBit(oldp+143,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__13__KET____DOT__fa_1__sum));
    bufp->fullBit(oldp+144,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__13__KET____DOT__fa_1__co));
    bufp->fullBit(oldp+145,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_1_0 
                                   >> 0xeU))));
    bufp->fullBit(oldp+146,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_2_0 
                                   >> 0xeU))));
    bufp->fullBit(oldp+147,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__14__KET____DOT__fa_1__sum));
    bufp->fullBit(oldp+148,((1U & ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_1_0 
                                    & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_2_0) 
                                   >> 0xeU))));
    bufp->fullBit(oldp+149,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                   >> 2U))));
    bufp->fullBit(oldp+150,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_1_0 
                                   >> 1U))));
    bufp->fullBit(oldp+151,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_2_0 
                                   >> 1U))));
    bufp->fullBit(oldp+152,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__sum));
    bufp->fullBit(oldp+153,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__co));
    bufp->fullBit(oldp+154,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                   >> 3U))));
    bufp->fullBit(oldp+155,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_1_0 
                                   >> 2U))));
    bufp->fullBit(oldp+156,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_2_0 
                                   >> 2U))));
    bufp->fullBit(oldp+157,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__sum));
    bufp->fullBit(oldp+158,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__co));
    bufp->fullBit(oldp+159,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                   >> 4U))));
    bufp->fullBit(oldp+160,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_1_0 
                                   >> 3U))));
    bufp->fullBit(oldp+161,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_2_0 
                                   >> 3U))));
    bufp->fullBit(oldp+162,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__sum));
    bufp->fullBit(oldp+163,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__co));
    bufp->fullBit(oldp+164,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                   >> 5U))));
    bufp->fullBit(oldp+165,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_1_0 
                                   >> 4U))));
    bufp->fullBit(oldp+166,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_2_0 
                                   >> 4U))));
    bufp->fullBit(oldp+167,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__sum));
    bufp->fullBit(oldp+168,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__co));
    bufp->fullBit(oldp+169,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                   >> 6U))));
    bufp->fullBit(oldp+170,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_1_0 
                                   >> 5U))));
    bufp->fullBit(oldp+171,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_2_0 
                                   >> 5U))));
    bufp->fullBit(oldp+172,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__sum));
    bufp->fullBit(oldp+173,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__co));
    bufp->fullBit(oldp+174,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                   >> 7U))));
    bufp->fullBit(oldp+175,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_1_0 
                                   >> 6U))));
    bufp->fullBit(oldp+176,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_2_0 
                                   >> 6U))));
    bufp->fullBit(oldp+177,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__sum));
    bufp->fullBit(oldp+178,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__co));
    bufp->fullBit(oldp+179,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                   >> 8U))));
    bufp->fullBit(oldp+180,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_1_0 
                                   >> 7U))));
    bufp->fullBit(oldp+181,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_2_0 
                                   >> 7U))));
    bufp->fullBit(oldp+182,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__sum));
    bufp->fullBit(oldp+183,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__co));
    bufp->fullBit(oldp+184,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                   >> 9U))));
    bufp->fullBit(oldp+185,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_1_0 
                                   >> 8U))));
    bufp->fullBit(oldp+186,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_2_0 
                                   >> 8U))));
    bufp->fullBit(oldp+187,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__sum));
    bufp->fullBit(oldp+188,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__co));
    bufp->fullBit(oldp+189,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_x_f) 
                                   >> 0xaU))));
    bufp->fullBit(oldp+190,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_1_0 
                                   >> 9U))));
    bufp->fullBit(oldp+191,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_2_0 
                                   >> 9U))));
    bufp->fullBit(oldp+192,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__sum));
    bufp->fullBit(oldp+193,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__co));
    bufp->fullBit(oldp+194,((1U & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0)));
    bufp->fullBit(oldp+195,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__s1__BRA__0__KET__) 
                                   ^ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0))));
    bufp->fullBit(oldp+196,(((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__s1__BRA__0__KET__) 
                             & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0)));
    bufp->fullBit(oldp+197,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                   >> 0xaU))));
    bufp->fullBit(oldp+198,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__sum) 
                                   ^ ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                       >> 0xaU) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__co))))));
    bufp->fullBit(oldp+199,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__sum) 
                              & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                 >> 0xaU)) | (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                                >> 0xaU) 
                                               | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__sum)) 
                                              & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__co)))));
    bufp->fullBit(oldp+200,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                   >> 0xbU))));
    bufp->fullBit(oldp+201,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__sum) 
                                   ^ ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                       >> 0xbU) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__co))))));
    bufp->fullBit(oldp+202,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__sum) 
                              & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                 >> 0xbU)) | (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                                >> 0xbU) 
                                               | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__sum)) 
                                              & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__10__KET____DOT__fa_1__co)))));
    bufp->fullBit(oldp+203,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                   >> 0xcU))));
    bufp->fullBit(oldp+204,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__sum) 
                                   ^ ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                       >> 0xcU) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__co))))));
    bufp->fullBit(oldp+205,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__sum) 
                              & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                 >> 0xcU)) | (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                                >> 0xcU) 
                                               | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__sum)) 
                                              & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__11__KET____DOT__fa_1__co)))));
    bufp->fullBit(oldp+206,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                   >> 0xdU))));
    bufp->fullBit(oldp+207,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__13__KET____DOT__fa_1__sum) 
                                   ^ ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                       >> 0xdU) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__co))))));
    bufp->fullBit(oldp+208,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__13__KET____DOT__fa_1__sum) 
                              & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                 >> 0xdU)) | (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                                >> 0xdU) 
                                               | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__13__KET____DOT__fa_1__sum)) 
                                              & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__12__KET____DOT__fa_1__co)))));
    bufp->fullBit(oldp+209,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                   >> 0xeU))));
    bufp->fullBit(oldp+210,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__14__KET____DOT__fa_1__sum) 
                                   ^ ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                       >> 0xeU) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__13__KET____DOT__fa_1__co))))));
    bufp->fullBit(oldp+211,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__14__KET____DOT__fa_1__sum) 
                              & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                 >> 0xeU)) | (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                                >> 0xeU) 
                                               | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__14__KET____DOT__fa_1__sum)) 
                                              & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__13__KET____DOT__fa_1__co)))));
    bufp->fullBit(oldp+212,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                   >> 1U))));
    bufp->fullBit(oldp+213,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__sum) 
                                   ^ ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                       >> 1U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c1__BRA__0__KET__))))));
    bufp->fullBit(oldp+214,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__sum) 
                              & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                 >> 1U)) | (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                              >> 1U) 
                                             | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__sum)) 
                                            & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__c1__BRA__0__KET__)))));
    bufp->fullBit(oldp+215,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                   >> 2U))));
    bufp->fullBit(oldp+216,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__sum) 
                                   ^ ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                       >> 2U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__co))))));
    bufp->fullBit(oldp+217,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__sum) 
                              & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                 >> 2U)) | (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                              >> 2U) 
                                             | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__sum)) 
                                            & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__1__KET____DOT__fa_1__co)))));
    bufp->fullBit(oldp+218,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                   >> 3U))));
    bufp->fullBit(oldp+219,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__sum) 
                                   ^ ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                       >> 3U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__co))))));
    bufp->fullBit(oldp+220,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__sum) 
                              & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                 >> 3U)) | (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                              >> 3U) 
                                             | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__sum)) 
                                            & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__2__KET____DOT__fa_1__co)))));
    bufp->fullBit(oldp+221,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                   >> 4U))));
    bufp->fullBit(oldp+222,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__sum) 
                                   ^ ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                       >> 4U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__co))))));
    bufp->fullBit(oldp+223,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__sum) 
                              & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                 >> 4U)) | (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                              >> 4U) 
                                             | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__sum)) 
                                            & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__3__KET____DOT__fa_1__co)))));
    bufp->fullBit(oldp+224,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                   >> 5U))));
    bufp->fullBit(oldp+225,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__sum) 
                                   ^ ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                       >> 5U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__co))))));
    bufp->fullBit(oldp+226,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__sum) 
                              & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                 >> 5U)) | (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                              >> 5U) 
                                             | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__sum)) 
                                            & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__4__KET____DOT__fa_1__co)))));
    bufp->fullBit(oldp+227,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                   >> 6U))));
    bufp->fullBit(oldp+228,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__sum) 
                                   ^ ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                       >> 6U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__co))))));
    bufp->fullBit(oldp+229,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__sum) 
                              & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                 >> 6U)) | (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                              >> 6U) 
                                             | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__sum)) 
                                            & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__5__KET____DOT__fa_1__co)))));
    bufp->fullBit(oldp+230,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                   >> 7U))));
    bufp->fullBit(oldp+231,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__sum) 
                                   ^ ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                       >> 7U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__co))))));
    bufp->fullBit(oldp+232,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__sum) 
                              & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                 >> 7U)) | (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                              >> 7U) 
                                             | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__sum)) 
                                            & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__6__KET____DOT__fa_1__co)))));
    bufp->fullBit(oldp+233,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                   >> 8U))));
    bufp->fullBit(oldp+234,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__sum) 
                                   ^ ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                       >> 8U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__co))))));
    bufp->fullBit(oldp+235,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__sum) 
                              & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                 >> 8U)) | (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                              >> 8U) 
                                             | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__sum)) 
                                            & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__7__KET____DOT__fa_1__co)))));
    bufp->fullBit(oldp+236,((1U & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                   >> 9U))));
    bufp->fullBit(oldp+237,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__sum) 
                                   ^ ((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                       >> 9U) ^ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__co))))));
    bufp->fullBit(oldp+238,((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__sum) 
                              & (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                 >> 9U)) | (((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____VdfgRegularize_hc819fdcb_3_0 
                                              >> 9U) 
                                             | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__9__KET____DOT__fa_1__sum)) 
                                            & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT____Vcellout__loop_s1__BRA__8__KET____DOT__fa_1__co)))));
    bufp->fullIData(oldp+239,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__second_stage__DOT__unnamedblk1__DOT__k),32);
    bufp->fullSData(oldp+240,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__shifted_sum),14);
    bufp->fullSData(oldp+241,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__sum_reg),14);
    bufp->fullCData(oldp+242,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__leading_zeros_reg),4);
    bufp->fullBit(oldp+243,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__sign_reg));
    bufp->fullCData(oldp+244,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__exponent_reg),5);
    bufp->fullBit(oldp+245,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__special_case_reg));
    bufp->fullSData(oldp+246,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__special_result_reg),16);
    bufp->fullSData(oldp+247,(((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__special_case_reg)
                                ? (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__special_result_reg)
                                : ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__inf)
                                    ? (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__sign_reg) 
                                        << 0xfU) | 
                                       ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__new_exponent) 
                                        << 0xaU)) : 
                                   ((0U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__new_exponent))
                                     ? (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__sign_reg) 
                                         << 0xfU) | 
                                        ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__new_exponent) 
                                         << 0xaU)) : 
                                    (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__sign_reg) 
                                      << 0xfU) | (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__new_exponent) 
                                                   << 0xaU) 
                                                  | ((0x400U 
                                                      & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__rounded_mantissa_internal))
                                                      ? 0U
                                                      : 
                                                     (0x3ffU 
                                                      & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__rounded_mantissa_internal))))))))),16);
    bufp->fullCData(oldp+248,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__right_shift_reg),2);
    bufp->fullBit(oldp+249,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__rounded_mantissa_internal) 
                                   >> 0xaU))));
    bufp->fullSData(oldp+250,((0x3ffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__shifted_sum) 
                                         >> 3U))),10);
    bufp->fullSData(oldp+251,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__rounded_mantissa_internal),11);
    bufp->fullBit(oldp+252,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__shifted_sum) 
                                   >> 3U))));
    bufp->fullBit(oldp+253,((1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__shifted_sum) 
                                   >> 2U))));
    bufp->fullBit(oldp+254,((0U != (3U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__shifted_sum)))));
    bufp->fullBit(oldp+255,((IData)((((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__shifted_sum) 
                                      >> 3U) & (0U 
                                                != 
                                                (0xfU 
                                                 & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__shifted_sum)))))));
    bufp->fullSData(oldp+256,(((0x400U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__rounded_mantissa_internal))
                                ? 0U : (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__rounded_mantissa_internal)))),10);
    bufp->fullCData(oldp+257,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__new_exponent_internal),7);
    bufp->fullCData(oldp+258,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__new_exponent),5);
    bufp->fullBit(oldp+259,(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__third_stage__DOT__inf));
    bufp->fullBit(oldp+260,(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_clk));
}
