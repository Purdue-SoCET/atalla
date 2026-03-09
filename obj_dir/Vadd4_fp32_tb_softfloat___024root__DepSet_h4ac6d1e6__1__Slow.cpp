// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd4_fp32_tb_softfloat.h for the primary calling header

#include "Vadd4_fp32_tb_softfloat__pch.h"
#include "Vadd4_fp32_tb_softfloat___024root.h"

VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root___eval_triggers__stl(Vadd4_fp32_tb_softfloat___024root* vlSelf);
VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root___eval_stl(Vadd4_fp32_tb_softfloat___024root* vlSelf);

VL_ATTR_COLD bool Vadd4_fp32_tb_softfloat___024root___eval_phase__stl(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root___eval_phase__stl\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vadd4_fp32_tb_softfloat___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vadd4_fp32_tb_softfloat___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root___dump_triggers__act(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root___dump_triggers__act\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge add4_fp32_tb_softfloat.tb_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge add4_fp32_tb_softfloat.tb_nrst)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(negedge add4_fp32_tb_softfloat.tb_clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root___dump_triggers__nba(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root___dump_triggers__nba\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge add4_fp32_tb_softfloat.tb_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge add4_fp32_tb_softfloat.tb_nrst)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(negedge add4_fp32_tb_softfloat.tb_clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root____Vm_traceActivitySetAll(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root____Vm_traceActivitySetAll\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
}

VL_ATTR_COLD void Vadd4_fp32_tb_softfloat___024root___ctor_var_reset(Vadd4_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32_tb_softfloat___024root___ctor_var_reset\n"); );
    Vadd4_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->add4_fp32_tb_softfloat__DOT__tb_clk = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__tb_nrst = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__tb_a = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__tb_b = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__tb_c = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__tb_d = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__exp = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__pass_count = 0;
    vlSelf->add4_fp32_tb_softfloat__DOT__fail_count = 0;
    vlSelf->add4_fp32_tb_softfloat__DOT__off_by_one = 0;
    vlSelf->add4_fp32_tb_softfloat__DOT__off_by_two = 0;
    vlSelf->add4_fp32_tb_softfloat__DOT__off_by_five_plus = 0;
    vlSelf->add4_fp32_tb_softfloat__DOT__diff = 0;
    vlSelf->add4_fp32_tb_softfloat__DOT__fd = 0;
    vlSelf->add4_fp32_tb_softfloat__DOT__fail_fd = 0;
    vlSelf->add4_fp32_tb_softfloat__DOT__a = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__b = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__c = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__d = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__expected = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__unnamedblk1__DOT__ret = 0;
    vlSelf->add4_fp32_tb_softfloat__DOT__unnamedblk1__DOT__is_zero_result = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__unnamedblk1__DOT__total_count = 0;
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__a_daz = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__b_daz = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__c_daz = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__d_daz = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_a = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_b = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_c = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_d = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_a = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_b = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_c = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_d = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_a = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_b = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_c = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_d = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_p = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_m = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_r = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_n = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_p = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_m = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_r = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_n = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_x = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_y = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_mx = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__frac_nx = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_p = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_m = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_r = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_n = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_y = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_mx = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sign_nx = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x_eff = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_y_eff = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_mx_eff = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__exp_nx_eff = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shift = VL_RAND_RESET_I(9);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shift = VL_RAND_RESET_I(9);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shift = VL_RAND_RESET_I(9);
    VL_RAND_RESET_W(5025, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__x_mant);
    VL_RAND_RESET_W(5025, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_shifted);
    VL_RAND_RESET_W(5025, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_shifted);
    VL_RAND_RESET_W(5025, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_shifted);
    VL_RAND_RESET_W(5025, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_mant_base);
    VL_RAND_RESET_W(5025, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_mant_base);
    VL_RAND_RESET_W(5025, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_mant_base);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_y = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_m = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_n = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__y_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__m_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__n_op = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__is_nan_any = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__special_case = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__any_pos_inf = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__any_neg_inf = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__special_result = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_e = VL_RAND_RESET_I(8);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_align_sticky = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_case = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_result = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(5028, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_sum_vec);
    VL_RAND_RESET_W(5028, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_carry_vec);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st1_hot_ones = VL_RAND_RESET_I(2);
    VL_RAND_RESET_W(5029, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum);
    VL_RAND_RESET_W(5027, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__res_sign = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_exp_base = VL_RAND_RESET_I(8);
    VL_RAND_RESET_W(5027, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_spec_res = VL_RAND_RESET_I(32);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sticky = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(5027, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros = VL_RAND_RESET_I(14);
    VL_RAND_RESET_W(5027, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__raw_mant = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__final_mant = VL_RAND_RESET_I(23);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mant_int = VL_RAND_RESET_I(24);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc = VL_RAND_RESET_I(11);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__guard_bit = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__round_bit = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_bit = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__round_up = VL_RAND_RESET_I(1);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__result_out = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(5028, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_x);
    VL_RAND_RESET_W(5028, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_y);
    VL_RAND_RESET_W(5028, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_m);
    VL_RAND_RESET_W(5028, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__op_n);
    VL_RAND_RESET_W(5028, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s1);
    VL_RAND_RESET_W(5028, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c1);
    VL_RAND_RESET_W(5028, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s2);
    VL_RAND_RESET_W(5028, vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c2);
    vlSelf->add4_fp32_tb_softfloat__DOT__etchedfp4adder__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->__Vtrigprevexpr___TOP__add4_fp32_tb_softfloat__DOT__tb_clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__add4_fp32_tb_softfloat__DOT__tb_nrst__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
