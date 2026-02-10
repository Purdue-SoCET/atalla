// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadd4_fp16_tb_full__Syms.h"


VL_ATTR_COLD void Vadd4_fp16_tb_full___024root__trace_init_sub__TOP__0(Vadd4_fp16_tb_full___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_full___024root__trace_init_sub__TOP__0\n"); );
    Vadd4_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("add4_fp16_tb_full", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+208,0,"PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+207,0,"tb_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"tb_nrst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"tb_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+3,0,"tb_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+4,0,"tb_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+5,0,"tb_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+6,0,"tb_start",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+80,0,"tb_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+81,0,"tb_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+8,0,"pass_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+9,0,"fail_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+209,0,"P_INF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+210,0,"N_INF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+211,0,"NAN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+212,0,"P_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+213,0,"N_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+214,0,"ONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+215,0,"TWO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+216,0,"THREE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+217,0,"FOUR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+218,0,"MIN_SUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+219,0,"MAX_FINITE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+10,0,"fd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+11,0,"a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+12,0,"b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+13,0,"c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+14,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+15,0,"expected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+207,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"nRST",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+220,0,"stall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+3,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+4,0,"c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+5,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+80,0,"fp_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+81,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+82,0,"ab",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+83,0,"cd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+84,0,"done_ab",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"done_cd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_ab", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+207,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"nRST",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+220,0,"stall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+220,0,"sub",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"fp1_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+3,0,"fp2_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+82,0,"fp_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+84,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+18,0,"a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+19,0,"b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+20,0,"is_nan_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"is_nan_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"is_inf_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"is_inf_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"special_case",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+25,0,"special_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+26,0,"op_swap",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+27,0,"high_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+28,0,"low_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+29,0,"high_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+30,0,"low_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+31,0,"mant_hi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+32,0,"mant_lo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+33,0,"mant_lo_aligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+34,0,"mask_align",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBit(c+35,0,"sticky_align_local",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"sticky_lost",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+37,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+38,0,"exp_max",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+39,0,"frac_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+40,0,"frac_not_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBit(c+41,0,"sign_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+42,0,"sign_not_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+43,0,"smaller_mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+44,0,"larger_mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+86,0,"mantissa_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBit(c+45,0,"larger_mantissa_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"result_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"signs_differ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"mantissa_overflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"sub_has_lost_sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"sub_has_added_sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+89,0,"smaller_mantissa_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+90,0,"larger_mantissa_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBit(c+91,0,"larger_mantissa_sign_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+92,0,"sign_shifted_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,0,"sign_not_shifted_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+94,0,"signs_differ_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+95,0,"exp_max_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+96,0,"special_case_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+97,0,"special_result_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+98,0,"sub_has_lost_sticky_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"sub_has_added_sticky_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"start_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+100,0,"normalized_mantissa_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+101,0,"norm_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+102,0,"exp_norm_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+103,0,"round_this",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+104,0,"exp_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+105,0,"ftz_under",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+106,0,"round_inc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+107,0,"frac_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBit(c+108,0,"frac_carry",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+109,0,"exp_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+110,0,"rounded_fraction",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+111,0,"overflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+112,0,"exp_out_final",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+113,0,"rounded_fraction_final",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->pushPrefix("normalizer", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+114,0,"fraction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+100,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+115,0,"shifted_amount",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_cd", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+207,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"nRST",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+220,0,"stall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+220,0,"sub",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+4,0,"fp1_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+5,0,"fp2_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+83,0,"fp_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+85,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+49,0,"a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+50,0,"b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+51,0,"is_nan_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"is_nan_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"is_inf_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"is_inf_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"special_case",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+56,0,"special_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+57,0,"op_swap",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+58,0,"high_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+59,0,"low_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+60,0,"high_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+61,0,"low_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+62,0,"mant_hi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+63,0,"mant_lo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+64,0,"mant_lo_aligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+65,0,"mask_align",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBit(c+66,0,"sticky_align_local",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"sticky_lost",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+68,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+69,0,"exp_max",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+70,0,"frac_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+71,0,"frac_not_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBit(c+72,0,"sign_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+73,0,"sign_not_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+74,0,"smaller_mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+75,0,"larger_mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+116,0,"mantissa_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBit(c+76,0,"larger_mantissa_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+117,0,"result_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"signs_differ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+118,0,"mantissa_overflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"sub_has_lost_sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+79,0,"sub_has_added_sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+119,0,"smaller_mantissa_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+120,0,"larger_mantissa_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBit(c+121,0,"larger_mantissa_sign_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+122,0,"sign_shifted_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"sign_not_shifted_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"signs_differ_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+125,0,"exp_max_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+126,0,"special_case_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+127,0,"special_result_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+128,0,"sub_has_lost_sticky_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+129,0,"sub_has_added_sticky_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"start_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+130,0,"normalized_mantissa_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+131,0,"norm_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+132,0,"exp_norm_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+133,0,"round_this",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+134,0,"exp_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+135,0,"ftz_under",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+136,0,"round_inc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+137,0,"frac_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBit(c+138,0,"frac_carry",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+139,0,"exp_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+140,0,"rounded_fraction",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+141,0,"overflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+142,0,"exp_out_final",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+143,0,"rounded_fraction_final",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->pushPrefix("normalizer", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+144,0,"fraction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+130,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+145,0,"shifted_amount",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_sum", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+207,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"nRST",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+220,0,"stall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+220,0,"sub",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+82,0,"fp1_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+83,0,"fp2_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+80,0,"fp_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+81,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+146,0,"a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+147,0,"b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+148,0,"is_nan_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+149,0,"is_nan_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+150,0,"is_inf_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+151,0,"is_inf_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+152,0,"special_case",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+153,0,"special_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+154,0,"op_swap",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+155,0,"high_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+156,0,"low_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+157,0,"high_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+158,0,"low_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+159,0,"mant_hi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+160,0,"mant_lo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+161,0,"mant_lo_aligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+162,0,"mask_align",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBit(c+163,0,"sticky_align_local",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+164,0,"sticky_lost",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+165,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+166,0,"exp_max",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+167,0,"frac_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+168,0,"frac_not_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBit(c+169,0,"sign_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+170,0,"sign_not_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+171,0,"smaller_mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+172,0,"larger_mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+173,0,"mantissa_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBit(c+174,0,"larger_mantissa_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+175,0,"result_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+176,0,"signs_differ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"mantissa_overflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+178,0,"sub_has_lost_sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+179,0,"sub_has_added_sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+180,0,"smaller_mantissa_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+181,0,"larger_mantissa_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBit(c+182,0,"larger_mantissa_sign_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+183,0,"sign_shifted_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+184,0,"sign_not_shifted_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+185,0,"signs_differ_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+186,0,"exp_max_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+187,0,"special_case_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+188,0,"special_result_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+189,0,"sub_has_lost_sticky_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+190,0,"sub_has_added_sticky_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"start_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+191,0,"normalized_mantissa_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+192,0,"norm_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+193,0,"exp_norm_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+194,0,"round_this",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+195,0,"exp_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+196,0,"ftz_under",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+197,0,"round_inc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+198,0,"frac_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBit(c+199,0,"frac_carry",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+200,0,"exp_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+201,0,"rounded_fraction",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+202,0,"overflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+203,0,"exp_out_final",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+204,0,"rounded_fraction_final",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->pushPrefix("normalizer", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+205,0,"fraction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+191,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+206,0,"shifted_amount",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+16,0,"ret",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+17,0,"is_zero_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vadd4_fp16_tb_full___024root__trace_init_top(Vadd4_fp16_tb_full___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_full___024root__trace_init_top\n"); );
    Vadd4_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vadd4_fp16_tb_full___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vadd4_fp16_tb_full___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vadd4_fp16_tb_full___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadd4_fp16_tb_full___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadd4_fp16_tb_full___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vadd4_fp16_tb_full___024root__trace_register(Vadd4_fp16_tb_full___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_full___024root__trace_register\n"); );
    Vadd4_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vadd4_fp16_tb_full___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vadd4_fp16_tb_full___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vadd4_fp16_tb_full___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vadd4_fp16_tb_full___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vadd4_fp16_tb_full___024root__trace_const_0_sub_0(Vadd4_fp16_tb_full___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vadd4_fp16_tb_full___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_full___024root__trace_const_0\n"); );
    // Init
    Vadd4_fp16_tb_full___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd4_fp16_tb_full___024root*>(voidSelf);
    Vadd4_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vadd4_fp16_tb_full___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vadd4_fp16_tb_full___024root__trace_const_0_sub_0(Vadd4_fp16_tb_full___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_full___024root__trace_const_0_sub_0\n"); );
    Vadd4_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+208,(2U),32);
    bufp->fullSData(oldp+209,(0x7c00U),16);
    bufp->fullSData(oldp+210,(0xfc00U),16);
    bufp->fullSData(oldp+211,(0x7d00U),16);
    bufp->fullSData(oldp+212,(0U),16);
    bufp->fullSData(oldp+213,(0x8000U),16);
    bufp->fullSData(oldp+214,(0x3c00U),16);
    bufp->fullSData(oldp+215,(0x4000U),16);
    bufp->fullSData(oldp+216,(0x4200U),16);
    bufp->fullSData(oldp+217,(0x4400U),16);
    bufp->fullSData(oldp+218,(1U),16);
    bufp->fullSData(oldp+219,(0x7bffU),16);
    bufp->fullBit(oldp+220,(0U));
}

VL_ATTR_COLD void Vadd4_fp16_tb_full___024root__trace_full_0_sub_0(Vadd4_fp16_tb_full___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vadd4_fp16_tb_full___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_full___024root__trace_full_0\n"); );
    // Init
    Vadd4_fp16_tb_full___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd4_fp16_tb_full___024root*>(voidSelf);
    Vadd4_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vadd4_fp16_tb_full___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vadd4_fp16_tb_full___024root__trace_full_0_sub_0(Vadd4_fp16_tb_full___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_full___024root__trace_full_0_sub_0\n"); );
    Vadd4_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst));
    bufp->fullSData(oldp+2,(vlSelfRef.add4_fp16_tb_full__DOT__tb_a),16);
    bufp->fullSData(oldp+3,(vlSelfRef.add4_fp16_tb_full__DOT__tb_b),16);
    bufp->fullSData(oldp+4,(vlSelfRef.add4_fp16_tb_full__DOT__tb_c),16);
    bufp->fullSData(oldp+5,(vlSelfRef.add4_fp16_tb_full__DOT__tb_d),16);
    bufp->fullBit(oldp+6,(vlSelfRef.add4_fp16_tb_full__DOT__tb_start));
    bufp->fullSData(oldp+7,(vlSelfRef.add4_fp16_tb_full__DOT__exp),16);
    bufp->fullIData(oldp+8,(vlSelfRef.add4_fp16_tb_full__DOT__pass_count),32);
    bufp->fullIData(oldp+9,(vlSelfRef.add4_fp16_tb_full__DOT__fail_count),32);
    bufp->fullIData(oldp+10,(vlSelfRef.add4_fp16_tb_full__DOT__fd),32);
    bufp->fullSData(oldp+11,(vlSelfRef.add4_fp16_tb_full__DOT__a),16);
    bufp->fullSData(oldp+12,(vlSelfRef.add4_fp16_tb_full__DOT__b),16);
    bufp->fullSData(oldp+13,(vlSelfRef.add4_fp16_tb_full__DOT__c),16);
    bufp->fullSData(oldp+14,(vlSelfRef.add4_fp16_tb_full__DOT__d),16);
    bufp->fullSData(oldp+15,(vlSelfRef.add4_fp16_tb_full__DOT__expected),16);
    bufp->fullIData(oldp+16,(vlSelfRef.add4_fp16_tb_full__DOT__unnamedblk1__DOT__ret),32);
    bufp->fullBit(oldp+17,(vlSelfRef.add4_fp16_tb_full__DOT__unnamedblk1__DOT__is_zero_result));
    bufp->fullSData(oldp+18,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__a),16);
    bufp->fullSData(oldp+19,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__b),16);
    bufp->fullBit(oldp+20,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__is_nan_a));
    bufp->fullBit(oldp+21,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__is_nan_b));
    bufp->fullBit(oldp+22,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__is_inf_a));
    bufp->fullBit(oldp+23,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__is_inf_b));
    bufp->fullBit(oldp+24,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_case));
    bufp->fullSData(oldp+25,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_result),16);
    bufp->fullBit(oldp+26,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__op_swap));
    bufp->fullSData(oldp+27,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__high_op),16);
    bufp->fullSData(oldp+28,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__low_op),16);
    bufp->fullCData(oldp+29,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__high_exp),5);
    bufp->fullCData(oldp+30,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__low_exp),5);
    bufp->fullSData(oldp+31,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_hi),13);
    bufp->fullSData(oldp+32,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_lo),13);
    bufp->fullSData(oldp+33,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_lo_aligned),13);
    bufp->fullSData(oldp+34,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mask_align),13);
    bufp->fullBit(oldp+35,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sticky_align_local));
    bufp->fullBit(oldp+36,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sticky_lost));
    bufp->fullCData(oldp+37,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_diff),5);
    bufp->fullCData(oldp+38,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_max),5);
    bufp->fullSData(oldp+39,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_shifted),13);
    bufp->fullSData(oldp+40,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_not_shifted),13);
    bufp->fullBit(oldp+41,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_shifted));
    bufp->fullBit(oldp+42,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_not_shifted));
    bufp->fullSData(oldp+43,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__smaller_mantissa),13);
    bufp->fullSData(oldp+44,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__larger_mantissa),13);
    bufp->fullBit(oldp+45,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__larger_mantissa_sign));
    bufp->fullBit(oldp+46,(((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_shifted) 
                            ^ (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_not_shifted))));
    bufp->fullBit(oldp+47,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sub_has_lost_sticky));
    bufp->fullBit(oldp+48,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sub_has_added_sticky));
    bufp->fullSData(oldp+49,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__a),16);
    bufp->fullSData(oldp+50,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__b),16);
    bufp->fullBit(oldp+51,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__is_nan_a));
    bufp->fullBit(oldp+52,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__is_nan_b));
    bufp->fullBit(oldp+53,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__is_inf_a));
    bufp->fullBit(oldp+54,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__is_inf_b));
    bufp->fullBit(oldp+55,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_case));
    bufp->fullSData(oldp+56,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_result),16);
    bufp->fullBit(oldp+57,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__op_swap));
    bufp->fullSData(oldp+58,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__high_op),16);
    bufp->fullSData(oldp+59,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__low_op),16);
    bufp->fullCData(oldp+60,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__high_exp),5);
    bufp->fullCData(oldp+61,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__low_exp),5);
    bufp->fullSData(oldp+62,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_hi),13);
    bufp->fullSData(oldp+63,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_lo),13);
    bufp->fullSData(oldp+64,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_lo_aligned),13);
    bufp->fullSData(oldp+65,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mask_align),13);
    bufp->fullBit(oldp+66,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sticky_align_local));
    bufp->fullBit(oldp+67,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sticky_lost));
    bufp->fullCData(oldp+68,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_diff),5);
    bufp->fullCData(oldp+69,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_max),5);
    bufp->fullSData(oldp+70,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_shifted),13);
    bufp->fullSData(oldp+71,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_not_shifted),13);
    bufp->fullBit(oldp+72,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_shifted));
    bufp->fullBit(oldp+73,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_not_shifted));
    bufp->fullSData(oldp+74,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__smaller_mantissa),13);
    bufp->fullSData(oldp+75,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__larger_mantissa),13);
    bufp->fullBit(oldp+76,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__larger_mantissa_sign));
    bufp->fullBit(oldp+77,(((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_shifted) 
                            ^ (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_not_shifted))));
    bufp->fullBit(oldp+78,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sub_has_lost_sticky));
    bufp->fullBit(oldp+79,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sub_has_added_sticky));
    bufp->fullSData(oldp+80,(((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                               ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                               : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                                   ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                      << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                                   ? 
                                                  ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                   << 0xfU)
                                                   : 
                                                  (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final))))))),16);
    bufp->fullBit(oldp+81,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__start_l));
    bufp->fullSData(oldp+82,(((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_case_l)
                               ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_result_l)
                               : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum))
                                   ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__result_sign) 
                                      << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__ftz_under)
                                                   ? 
                                                  ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__result_sign) 
                                                   << 0xfU)
                                                   : 
                                                  (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__rounded_fraction_final))))))),16);
    bufp->fullSData(oldp+83,(((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_case_l)
                               ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_result_l)
                               : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum))
                                   ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__result_sign) 
                                      << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__ftz_under)
                                                   ? 
                                                  ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__result_sign) 
                                                   << 0xfU)
                                                   : 
                                                  (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__rounded_fraction_final))))))),16);
    bufp->fullBit(oldp+84,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__start_l));
    bufp->fullBit(oldp+85,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__start_l));
    bufp->fullSData(oldp+86,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum),14);
    bufp->fullBit(oldp+87,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__result_sign));
    bufp->fullBit(oldp+88,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_overflow));
    bufp->fullSData(oldp+89,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__smaller_mantissa_l),13);
    bufp->fullSData(oldp+90,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__larger_mantissa_l),13);
    bufp->fullBit(oldp+91,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__larger_mantissa_sign_l));
    bufp->fullBit(oldp+92,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_shifted_l));
    bufp->fullBit(oldp+93,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_not_shifted_l));
    bufp->fullBit(oldp+94,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__signs_differ_l));
    bufp->fullCData(oldp+95,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_max_l),5);
    bufp->fullBit(oldp+96,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_case_l));
    bufp->fullSData(oldp+97,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_result_l),16);
    bufp->fullBit(oldp+98,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sub_has_lost_sticky_l));
    bufp->fullBit(oldp+99,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sub_has_added_sticky_l));
    bufp->fullSData(oldp+100,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__normalized_mantissa_sum),13);
    bufp->fullCData(oldp+101,((0xfU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT____Vcellout__normalizer__shifted_amount))),4);
    bufp->fullCData(oldp+102,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_norm_s),7);
    bufp->fullSData(oldp+103,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__round_this),12);
    bufp->fullCData(oldp+104,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_base),6);
    bufp->fullBit(oldp+105,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__ftz_under));
    bufp->fullBit(oldp+106,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__round_inc));
    bufp->fullSData(oldp+107,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_sum),11);
    bufp->fullBit(oldp+108,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_carry));
    bufp->fullCData(oldp+109,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_out),6);
    bufp->fullSData(oldp+110,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__rounded_fraction),10);
    bufp->fullBit(oldp+111,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__overflow));
    bufp->fullCData(oldp+112,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_out_final),5);
    bufp->fullSData(oldp+113,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__rounded_fraction_final),10);
    bufp->fullSData(oldp+114,((0x1fffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum))),13);
    bufp->fullCData(oldp+115,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT____Vcellout__normalizer__shifted_amount),5);
    bufp->fullSData(oldp+116,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum),14);
    bufp->fullBit(oldp+117,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__result_sign));
    bufp->fullBit(oldp+118,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_overflow));
    bufp->fullSData(oldp+119,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__smaller_mantissa_l),13);
    bufp->fullSData(oldp+120,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__larger_mantissa_l),13);
    bufp->fullBit(oldp+121,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__larger_mantissa_sign_l));
    bufp->fullBit(oldp+122,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_shifted_l));
    bufp->fullBit(oldp+123,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_not_shifted_l));
    bufp->fullBit(oldp+124,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__signs_differ_l));
    bufp->fullCData(oldp+125,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_max_l),5);
    bufp->fullBit(oldp+126,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_case_l));
    bufp->fullSData(oldp+127,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_result_l),16);
    bufp->fullBit(oldp+128,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sub_has_lost_sticky_l));
    bufp->fullBit(oldp+129,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sub_has_added_sticky_l));
    bufp->fullSData(oldp+130,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__normalized_mantissa_sum),13);
    bufp->fullCData(oldp+131,((0xfU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT____Vcellout__normalizer__shifted_amount))),4);
    bufp->fullCData(oldp+132,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_norm_s),7);
    bufp->fullSData(oldp+133,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__round_this),12);
    bufp->fullCData(oldp+134,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_base),6);
    bufp->fullBit(oldp+135,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__ftz_under));
    bufp->fullBit(oldp+136,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__round_inc));
    bufp->fullSData(oldp+137,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_sum),11);
    bufp->fullBit(oldp+138,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_carry));
    bufp->fullCData(oldp+139,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_out),6);
    bufp->fullSData(oldp+140,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__rounded_fraction),10);
    bufp->fullBit(oldp+141,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__overflow));
    bufp->fullCData(oldp+142,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_out_final),5);
    bufp->fullSData(oldp+143,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__rounded_fraction_final),10);
    bufp->fullSData(oldp+144,((0x1fffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum))),13);
    bufp->fullCData(oldp+145,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT____Vcellout__normalizer__shifted_amount),5);
    bufp->fullSData(oldp+146,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__a),16);
    bufp->fullSData(oldp+147,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__b),16);
    bufp->fullBit(oldp+148,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__is_nan_a));
    bufp->fullBit(oldp+149,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__is_nan_b));
    bufp->fullBit(oldp+150,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__is_inf_a));
    bufp->fullBit(oldp+151,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__is_inf_b));
    bufp->fullBit(oldp+152,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case));
    bufp->fullSData(oldp+153,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result),16);
    bufp->fullBit(oldp+154,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__op_swap));
    bufp->fullSData(oldp+155,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__high_op),16);
    bufp->fullSData(oldp+156,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__low_op),16);
    bufp->fullCData(oldp+157,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__high_exp),5);
    bufp->fullCData(oldp+158,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__low_exp),5);
    bufp->fullSData(oldp+159,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_hi),13);
    bufp->fullSData(oldp+160,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_lo),13);
    bufp->fullSData(oldp+161,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_lo_aligned),13);
    bufp->fullSData(oldp+162,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mask_align),13);
    bufp->fullBit(oldp+163,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sticky_align_local));
    bufp->fullBit(oldp+164,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sticky_lost));
    bufp->fullCData(oldp+165,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_diff),5);
    bufp->fullCData(oldp+166,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_max),5);
    bufp->fullSData(oldp+167,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_shifted),13);
    bufp->fullSData(oldp+168,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_not_shifted),13);
    bufp->fullBit(oldp+169,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_shifted));
    bufp->fullBit(oldp+170,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_not_shifted));
    bufp->fullSData(oldp+171,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__smaller_mantissa),13);
    bufp->fullSData(oldp+172,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__larger_mantissa),13);
    bufp->fullSData(oldp+173,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum),14);
    bufp->fullBit(oldp+174,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__larger_mantissa_sign));
    bufp->fullBit(oldp+175,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign));
    bufp->fullBit(oldp+176,(((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_shifted) 
                             ^ (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_not_shifted))));
    bufp->fullBit(oldp+177,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_overflow));
    bufp->fullBit(oldp+178,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sub_has_lost_sticky));
    bufp->fullBit(oldp+179,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sub_has_added_sticky));
    bufp->fullSData(oldp+180,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__smaller_mantissa_l),13);
    bufp->fullSData(oldp+181,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__larger_mantissa_l),13);
    bufp->fullBit(oldp+182,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__larger_mantissa_sign_l));
    bufp->fullBit(oldp+183,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_shifted_l));
    bufp->fullBit(oldp+184,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_not_shifted_l));
    bufp->fullBit(oldp+185,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__signs_differ_l));
    bufp->fullCData(oldp+186,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_max_l),5);
    bufp->fullBit(oldp+187,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l));
    bufp->fullSData(oldp+188,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l),16);
    bufp->fullBit(oldp+189,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sub_has_lost_sticky_l));
    bufp->fullBit(oldp+190,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sub_has_added_sticky_l));
    bufp->fullSData(oldp+191,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__normalized_mantissa_sum),13);
    bufp->fullCData(oldp+192,((0xfU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT____Vcellout__normalizer__shifted_amount))),4);
    bufp->fullCData(oldp+193,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_norm_s),7);
    bufp->fullSData(oldp+194,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__round_this),12);
    bufp->fullCData(oldp+195,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_base),6);
    bufp->fullBit(oldp+196,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under));
    bufp->fullBit(oldp+197,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__round_inc));
    bufp->fullSData(oldp+198,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_sum),11);
    bufp->fullBit(oldp+199,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_carry));
    bufp->fullCData(oldp+200,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out),6);
    bufp->fullSData(oldp+201,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction),10);
    bufp->fullBit(oldp+202,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__overflow));
    bufp->fullCData(oldp+203,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final),5);
    bufp->fullSData(oldp+204,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final),10);
    bufp->fullSData(oldp+205,((0x1fffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))),13);
    bufp->fullCData(oldp+206,(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT____Vcellout__normalizer__shifted_amount),5);
    bufp->fullBit(oldp+207,(vlSelfRef.add4_fp16_tb_full__DOT__tb_clk));
}
