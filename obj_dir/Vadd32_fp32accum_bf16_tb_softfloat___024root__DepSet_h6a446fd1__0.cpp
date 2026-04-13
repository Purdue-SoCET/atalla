// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd32_fp32accum_bf16_tb_softfloat.h for the primary calling header

#include "Vadd32_fp32accum_bf16_tb_softfloat__pch.h"
#include "Vadd32_fp32accum_bf16_tb_softfloat___024root.h"

VlCoroutine Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_initial__TOP__Vtiming__0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);
VlCoroutine Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_initial__TOP__Vtiming__1(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);

void Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_initial(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_initial\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_initial__TOP__Vtiming__1(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_clk = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                             nullptr, 
                                             "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                             33);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_clk = 1U;
        co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                             nullptr, 
                                             "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                             35);
    }
}

void Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);
void Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__1(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);
void Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__2(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);
void Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__3(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);
void Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__4(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);
void Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__5(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);
void Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__6(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);
void Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__7(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);
void Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__8(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);
void Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__9(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);
void Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__10(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);
void Vadd32_fp32accum_bf16_tb_softfloat___024root___act_comb__TOP__0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);

void Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_act(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_act\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__2(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__3(vlSelf);
        vlSelfRef.__Vm_traceActivity[6U] = 1U;
    }
    if ((0x10ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__4(vlSelf);
        vlSelfRef.__Vm_traceActivity[7U] = 1U;
    }
    if ((0x20ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__5(vlSelf);
        vlSelfRef.__Vm_traceActivity[8U] = 1U;
    }
    if ((0x40ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__6(vlSelf);
        vlSelfRef.__Vm_traceActivity[9U] = 1U;
    }
    if ((0x80ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__7(vlSelf);
        vlSelfRef.__Vm_traceActivity[0xaU] = 1U;
    }
    if ((0x100ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__8(vlSelf);
        vlSelfRef.__Vm_traceActivity[0xbU] = 1U;
    }
    if ((0x200ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__9(vlSelf);
        vlSelfRef.__Vm_traceActivity[0xcU] = 1U;
    }
    if ((0x400ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__10(vlSelf);
        vlSelfRef.__Vm_traceActivity[0xdU] = 1U;
    }
    if ((0x6000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[0xeU] = 1U;
    }
}

VL_INLINE_OPT void Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__0\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__guard_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__norm_val 
                 >> 5U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__round_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__norm_val 
                 >> 4U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sticky_bit 
        = ((0U != (0xfU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__norm_val)) 
           | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st2_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__l_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__norm_val 
                 >> 6U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__round_up 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__guard_bit) 
           & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__round_bit) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sticky_bit)) 
              | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__l_bit)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__rounded_mant_int 
        = (0xffffffU & ((0x7fffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__norm_val 
                                      >> 6U)) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__round_up)));
    if ((0U == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lzd_scan = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lead_zeros = 0x1dU;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lzd_scan 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st2_sum_mag;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lead_zeros = 0U;
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lzd_scan, 0xeU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lead_zeros 
                = (0x1fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lzd_scan, 0x10U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lzd_scan, 0x16U))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lead_zeros 
                = (0x1fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lzd_scan, 8U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lzd_scan, 0x1aU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lead_zeros 
                = (0x1fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lzd_scan, 4U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lzd_scan, 0x1cU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lead_zeros 
                = (0x1fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lzd_scan, 2U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lzd_scan, 0x1dU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lead_zeros 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lzd_scan, 1U));
        }
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__norm_val 
        = (0x3fffffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st2_sum_mag 
                          << (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lead_zeros)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__final_mant 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__rounded_mant_int);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lead_zeros 
        = (0x1fU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lead_zeros) 
                    - ((0x800000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__rounded_mant_int)
                        ? 1U : 0U)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(3U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,7, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__lead_zeros))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__result_out 
        = ((((0U == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st2_sum_mag) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st2_exp_base)))
            ? 0U : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__final_exp_calc)))
                     ? (0x7f800000U | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st2_res_sign) 
                                       << 0x1fU)) : 
                    (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st2_res_sign) 
                      << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__final_exp_calc) 
                                                   << 0x17U)) 
                                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__final_mant))));
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st2_special) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__result_out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st2_spec_res;
    }
}

VL_INLINE_OPT void Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__1(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__1\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__guard_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val 
                 >> 5U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__round_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val 
                 >> 4U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_bit 
        = ((0U != (0xfU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val)) 
           | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__l_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val 
                 >> 6U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__round_up 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__guard_bit) 
           & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__round_bit) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_bit)) 
              | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__l_bit)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__rounded_mant_int 
        = (0xffffffU & ((0x7fffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val 
                                      >> 6U)) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__round_up)));
    if ((0U == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros = 0x1dU;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros = 0U;
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 0xeU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 0x10U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 0x16U))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 8U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 0x1aU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 4U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 0x1cU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 2U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 0x1dU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 1U));
        }
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val 
        = (0x3fffffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag 
                          << (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__final_mant 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__rounded_mant_int);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros 
        = (0x1fU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros) 
                    - ((0x800000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__rounded_mant_int)
                        ? 1U : 0U)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(3U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,7, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__result_out 
        = ((((0U == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_exp_base)))
            ? 0U : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__final_exp_calc)))
                     ? (0x7f800000U | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_res_sign) 
                                       << 0x1fU)) : 
                    (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_res_sign) 
                      << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__final_exp_calc) 
                                                   << 0x17U)) 
                                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__final_mant))));
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_special) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__result_out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_spec_res;
    }
}

VL_INLINE_OPT void Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__2(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__2\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__guard_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val 
                 >> 5U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__round_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val 
                 >> 4U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_bit 
        = ((0U != (0xfU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val)) 
           | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__l_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val 
                 >> 6U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__round_up 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__guard_bit) 
           & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__round_bit) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_bit)) 
              | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__l_bit)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__rounded_mant_int 
        = (0xffffffU & ((0x7fffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val 
                                      >> 6U)) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__round_up)));
    if ((0U == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros = 0x1dU;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros = 0U;
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 0xeU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 0x10U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 0x16U))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 8U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 0x1aU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 4U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 0x1cU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 2U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 0x1dU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 1U));
        }
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val 
        = (0x3fffffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag 
                          << (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__final_mant 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__rounded_mant_int);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros 
        = (0x1fU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros) 
                    - ((0x800000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__rounded_mant_int)
                        ? 1U : 0U)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(3U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,7, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__result_out 
        = ((((0U == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_exp_base)))
            ? 0U : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__final_exp_calc)))
                     ? (0x7f800000U | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_res_sign) 
                                       << 0x1fU)) : 
                    (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_res_sign) 
                      << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__final_exp_calc) 
                                                   << 0x17U)) 
                                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__final_mant))));
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_special) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__result_out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_spec_res;
    }
}

VL_INLINE_OPT void Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__3(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__3\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__guard_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val 
                 >> 5U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__round_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val 
                 >> 4U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_bit 
        = ((0U != (0xfU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val)) 
           | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__l_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val 
                 >> 6U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__round_up 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__guard_bit) 
           & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__round_bit) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_bit)) 
              | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__l_bit)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__rounded_mant_int 
        = (0xffffffU & ((0x7fffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val 
                                      >> 6U)) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__round_up)));
    if ((0U == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros = 0x1dU;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros = 0U;
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 0xeU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 0x10U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 0x16U))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 8U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 0x1aU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 4U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 0x1cU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 2U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 0x1dU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 1U));
        }
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val 
        = (0x3fffffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag 
                          << (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__final_mant 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__rounded_mant_int);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros 
        = (0x1fU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros) 
                    - ((0x800000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__rounded_mant_int)
                        ? 1U : 0U)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(3U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,7, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__result_out 
        = ((((0U == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_exp_base)))
            ? 0U : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__final_exp_calc)))
                     ? (0x7f800000U | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_res_sign) 
                                       << 0x1fU)) : 
                    (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_res_sign) 
                      << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__final_exp_calc) 
                                                   << 0x17U)) 
                                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__final_mant))));
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_special) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__result_out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_spec_res;
    }
}

VL_INLINE_OPT void Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__4(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__4\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__guard_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val 
                 >> 5U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__round_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val 
                 >> 4U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_bit 
        = ((0U != (0xfU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val)) 
           | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__l_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val 
                 >> 6U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__round_up 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__guard_bit) 
           & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__round_bit) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_bit)) 
              | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__l_bit)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__rounded_mant_int 
        = (0xffffffU & ((0x7fffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val 
                                      >> 6U)) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__round_up)));
    if ((0U == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros = 0x1dU;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros = 0U;
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 0xeU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 0x10U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 0x16U))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 8U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 0x1aU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 4U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 0x1cU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 2U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 0x1dU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 1U));
        }
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val 
        = (0x3fffffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag 
                          << (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__final_mant 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__rounded_mant_int);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros 
        = (0x1fU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros) 
                    - ((0x800000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__rounded_mant_int)
                        ? 1U : 0U)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(3U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,7, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__result_out 
        = ((((0U == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_exp_base)))
            ? 0U : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__final_exp_calc)))
                     ? (0x7f800000U | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_res_sign) 
                                       << 0x1fU)) : 
                    (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_res_sign) 
                      << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__final_exp_calc) 
                                                   << 0x17U)) 
                                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__final_mant))));
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_special) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__result_out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_spec_res;
    }
}

VL_INLINE_OPT void Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__5(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__5\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__guard_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val 
                 >> 5U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__round_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val 
                 >> 4U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_bit 
        = ((0U != (0xfU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val)) 
           | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__l_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val 
                 >> 6U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__round_up 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__guard_bit) 
           & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__round_bit) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_bit)) 
              | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__l_bit)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__rounded_mant_int 
        = (0xffffffU & ((0x7fffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val 
                                      >> 6U)) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__round_up)));
    if ((0U == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros = 0x1dU;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros = 0U;
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 0xeU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 0x10U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 0x16U))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 8U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 0x1aU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 4U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 0x1cU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 2U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 0x1dU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 1U));
        }
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val 
        = (0x3fffffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag 
                          << (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__final_mant 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__rounded_mant_int);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros 
        = (0x1fU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros) 
                    - ((0x800000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__rounded_mant_int)
                        ? 1U : 0U)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(3U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,7, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__result_out 
        = ((((0U == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_exp_base)))
            ? 0U : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__final_exp_calc)))
                     ? (0x7f800000U | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_res_sign) 
                                       << 0x1fU)) : 
                    (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_res_sign) 
                      << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__final_exp_calc) 
                                                   << 0x17U)) 
                                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__final_mant))));
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_special) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__result_out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_spec_res;
    }
}

VL_INLINE_OPT void Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__6(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__6\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__guard_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val 
                 >> 5U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__round_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val 
                 >> 4U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_bit 
        = ((0U != (0xfU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val)) 
           | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__l_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val 
                 >> 6U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__round_up 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__guard_bit) 
           & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__round_bit) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_bit)) 
              | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__l_bit)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__rounded_mant_int 
        = (0xffffffU & ((0x7fffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val 
                                      >> 6U)) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__round_up)));
    if ((0U == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros = 0x1dU;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros = 0U;
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 0xeU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 0x10U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 0x16U))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 8U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 0x1aU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 4U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 0x1cU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 2U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 0x1dU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 1U));
        }
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val 
        = (0x3fffffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag 
                          << (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__final_mant 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__rounded_mant_int);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros 
        = (0x1fU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros) 
                    - ((0x800000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__rounded_mant_int)
                        ? 1U : 0U)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(3U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,7, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__result_out 
        = ((((0U == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_exp_base)))
            ? 0U : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__final_exp_calc)))
                     ? (0x7f800000U | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_res_sign) 
                                       << 0x1fU)) : 
                    (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_res_sign) 
                      << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__final_exp_calc) 
                                                   << 0x17U)) 
                                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__final_mant))));
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_special) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__result_out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_spec_res;
    }
}

VL_INLINE_OPT void Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__7(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__7\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__guard_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val 
                 >> 5U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__round_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val 
                 >> 4U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_bit 
        = ((0U != (0xfU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val)) 
           | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__l_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val 
                 >> 6U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__round_up 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__guard_bit) 
           & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__round_bit) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_bit)) 
              | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__l_bit)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__rounded_mant_int 
        = (0xffffffU & ((0x7fffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val 
                                      >> 6U)) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__round_up)));
    if ((0U == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros = 0x1dU;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros = 0U;
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 0xeU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 0x10U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 0x16U))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 8U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 0x1aU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 4U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 0x1cU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 2U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 0x1dU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 1U));
        }
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val 
        = (0x3fffffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag 
                          << (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__final_mant 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__rounded_mant_int);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros 
        = (0x1fU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros) 
                    - ((0x800000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__rounded_mant_int)
                        ? 1U : 0U)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(3U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,7, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__result_out 
        = ((((0U == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_exp_base)))
            ? 0U : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__final_exp_calc)))
                     ? (0x7f800000U | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_res_sign) 
                                       << 0x1fU)) : 
                    (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_res_sign) 
                      << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__final_exp_calc) 
                                                   << 0x17U)) 
                                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__final_mant))));
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_special) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__result_out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_spec_res;
    }
}

VL_INLINE_OPT void Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__8(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__8\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__guard_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val 
                 >> 5U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__round_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val 
                 >> 4U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_bit 
        = ((0U != (0xfU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val)) 
           | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__l_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val 
                 >> 6U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__round_up 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__guard_bit) 
           & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__round_bit) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_bit)) 
              | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__l_bit)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__rounded_mant_int 
        = (0xffffffU & ((0x7fffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val 
                                      >> 6U)) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__round_up)));
    if ((0U == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros = 0x1dU;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros = 0U;
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 0xeU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 0x10U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 0x16U))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 8U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 0x1aU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 4U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 0x1cU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 2U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 0x1dU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 1U));
        }
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val 
        = (0x3fffffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag 
                          << (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__final_mant 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__rounded_mant_int);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros 
        = (0x1fU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros) 
                    - ((0x800000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__rounded_mant_int)
                        ? 1U : 0U)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(3U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,7, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__result_out 
        = ((((0U == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_exp_base)))
            ? 0U : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__final_exp_calc)))
                     ? (0x7f800000U | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_res_sign) 
                                       << 0x1fU)) : 
                    (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_res_sign) 
                      << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__final_exp_calc) 
                                                   << 0x17U)) 
                                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__final_mant))));
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_special) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__result_out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_spec_res;
    }
}

VL_INLINE_OPT void Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__9(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__9\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__guard_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val 
                 >> 5U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__round_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val 
                 >> 4U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_bit 
        = ((0U != (0xfU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val)) 
           | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__l_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val 
                 >> 6U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__round_up 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__guard_bit) 
           & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__round_bit) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_bit)) 
              | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__l_bit)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__rounded_mant_int 
        = (0xffffffU & ((0x7fffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val 
                                      >> 6U)) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__round_up)));
    if ((0U == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros = 0x1dU;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros = 0U;
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 0xeU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x1fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 0x10U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 0x16U))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x1fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 8U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 0x1aU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x1fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 4U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 0x1cU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x1fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 2U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 0x1dU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 1U));
        }
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val 
        = (0x3fffffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag 
                          << (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__final_mant 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__rounded_mant_int);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros 
        = (0x1fU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros) 
                    - ((0x800000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__rounded_mant_int)
                        ? 1U : 0U)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(3U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,7, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__result_out 
        = ((((0U == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_exp_base)))
            ? 0U : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__final_exp_calc)))
                     ? (0x7f800000U | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_res_sign) 
                                       << 0x1fU)) : 
                    (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_res_sign) 
                      << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__final_exp_calc) 
                                                   << 0x17U)) 
                                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__final_mant))));
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_special) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__result_out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_spec_res;
    }
}

VL_INLINE_OPT void Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__10(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__10\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__guard_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val 
                 >> 5U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__round_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val 
                 >> 4U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_bit 
        = ((0U != (0xfU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val)) 
           | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__l_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val 
                 >> 6U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__round_up 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__guard_bit) 
           & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__round_bit) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_bit)) 
              | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__l_bit)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__rounded_mant_int 
        = (0xffffffU & ((0x7fffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val 
                                      >> 6U)) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__round_up)));
    if ((0U == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros = 0x1dU;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros = 0U;
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 0xeU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x1fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 0x10U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 0x16U))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x1fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 8U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 0x1aU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x1fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 4U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 0x1cU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x1fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 2U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 0x1dU))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros)));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 1U));
        }
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val 
        = (0x3fffffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag 
                          << (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__final_mant 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__rounded_mant_int);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros 
        = (0x1fU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros) 
                    - ((0x800000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__rounded_mant_int)
                        ? 1U : 0U)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(3U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,7, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__result_out 
        = ((((0U == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_exp_base)))
            ? 0U : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__final_exp_calc)))
                     ? (0x7f800000U | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_res_sign) 
                                       << 0x1fU)) : 
                    (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_res_sign) 
                      << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__final_exp_calc) 
                                                   << 0x17U)) 
                                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__final_mant))));
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_special) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__result_out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_spec_res;
    }
}

VL_INLINE_OPT void Vadd32_fp32accum_bf16_tb_softfloat___024root___act_comb__TOP__0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___act_comb__TOP__0\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__a_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0U] >> 7U))) ? (0x8000U 
                                             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                             [0U]) : 
           vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__b_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [1U] >> 7U))) ? (0x8000U 
                                             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                             [1U]) : 
           vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__c_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [2U] >> 7U))) ? (0x8000U 
                                             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                             [2U]) : 
           vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__d_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [3U] >> 7U))) ? (0x8000U 
                                             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                             [3U]) : 
           vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__x_mant 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_y))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_m))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_n))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__x_mant;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c1 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s2 
        = (0x3fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1 
                           ^ VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
                          ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c2 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1 
             & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
            | (VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c1, 1U) 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__a_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [4U] >> 7U))) ? (0x8000U 
                                             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                             [4U]) : 
           vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [4U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__b_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [5U] >> 7U))) ? (0x8000U 
                                             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                             [5U]) : 
           vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [5U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__c_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [6U] >> 7U))) ? (0x8000U 
                                             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                             [6U]) : 
           vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [6U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__d_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [7U] >> 7U))) ? (0x8000U 
                                             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                             [7U]) : 
           vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [7U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__x_mant 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_y))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_m))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_n))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__x_mant;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c1 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s2 
        = (0x3fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1 
                           ^ VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
                          ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c2 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1 
             & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
            | (VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c1, 1U) 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__a_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [8U] >> 7U))) ? (0x8000U 
                                             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                             [8U]) : 
           vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [8U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__b_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [9U] >> 7U))) ? (0x8000U 
                                             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                             [9U]) : 
           vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [9U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__c_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0xaU] >> 7U))) ? (0x8000U 
                                               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                               [0xaU])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0xaU]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__d_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0xbU] >> 7U))) ? (0x8000U 
                                               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                               [0xbU])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0xbU]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__x_mant 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_y))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_m))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_n))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__x_mant;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c1 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s2 
        = (0x3fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1 
                           ^ VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
                          ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c2 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1 
             & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
            | (VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c1, 1U) 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__a_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0xcU] >> 7U))) ? (0x8000U 
                                               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                               [0xcU])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0xcU]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__b_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0xdU] >> 7U))) ? (0x8000U 
                                               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                               [0xdU])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0xdU]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__c_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0xeU] >> 7U))) ? (0x8000U 
                                               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                               [0xeU])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0xeU]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__d_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0xfU] >> 7U))) ? (0x8000U 
                                               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                               [0xfU])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0xfU]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__x_mant 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_y))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_m))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_n))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__x_mant;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c1 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s2 
        = (0x3fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1 
                           ^ VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
                          ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c2 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1 
             & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
            | (VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c1, 1U) 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__a_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x10U] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x10U])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x10U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__b_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x11U] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x11U])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x11U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__c_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x12U] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x12U])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x12U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__d_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x13U] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x13U])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x13U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__x_mant 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_y))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_m))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_n))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__x_mant;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c1 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s2 
        = (0x3fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1 
                           ^ VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
                          ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c2 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1 
             & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
            | (VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c1, 1U) 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__a_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x14U] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x14U])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x14U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__b_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x15U] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x15U])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x15U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__c_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x16U] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x16U])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x16U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__d_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x17U] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x17U])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x17U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__x_mant 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_y))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_m))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_n))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__x_mant;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c1 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s2 
        = (0x3fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1 
                           ^ VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
                          ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c2 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1 
             & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
            | (VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c1, 1U) 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__a_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x18U] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x18U])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x18U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__b_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x19U] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x19U])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x19U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__c_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x1aU] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x1aU])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x1aU]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__d_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x1bU] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x1bU])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x1bU]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__x_mant 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_y))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_m))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_n))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__x_mant;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c1 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s2 
        = (0x3fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1 
                           ^ VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
                          ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c2 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1 
             & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
            | (VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c1, 1U) 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__a_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x1cU] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x1cU])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x1cU]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__b_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x1dU] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x1dU])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x1dU]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__c_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x1eU] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x1eU])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x1eU]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__d_daz 
        = ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                            [0x1fU] >> 7U))) ? (0x8000U 
                                                & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                                [0x1fU])
            : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
           [0x1fU]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__x_mant 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1aU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x13U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_y))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_m))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_n))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__x_mant;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c1 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s2 
        = (0x3fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1 
                           ^ VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
                          ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c2 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1 
             & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c1, 1U)) 
            | (VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c1, 1U) 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1));
}

void Vadd32_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);
void Vadd32_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__1(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);
void Vadd32_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__2(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);

void Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_nba(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_nba\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x1800ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[0xfU] = 1U;
        Vadd32_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__1(vlSelf);
        Vadd32_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((0x1802ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x10U] = 1U;
    }
    if ((0x1804ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__2(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x11U] = 1U;
    }
    if ((0x1808ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__3(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x12U] = 1U;
    }
    if ((0x1810ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__4(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x13U] = 1U;
    }
    if ((0x1820ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__5(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x14U] = 1U;
    }
    if ((0x1840ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__6(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x15U] = 1U;
    }
    if ((0x1880ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__7(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x16U] = 1U;
    }
    if ((0x1900ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__8(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x17U] = 1U;
    }
    if ((0x1801ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x18U] = 1U;
    }
    if ((0x1a00ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__9(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x19U] = 1U;
    }
    if ((0x1c00ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___act_sequent__TOP__10(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x1aU] = 1U;
    }
    if ((0x6000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x1bU] = 1U;
    }
}

VL_INLINE_OPT void Vadd32_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__0\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__res_sign));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__res_sign));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__res_sign));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__res_sign));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__res_sign));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__res_sign));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__res_sign));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__res_sign));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__res_sign));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__res_sign));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__res_sign));
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st2_sum_mag 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__mag_sum;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__mag_sum;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__mag_sum;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__mag_sum;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__mag_sum;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__mag_sum;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__mag_sum;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__mag_sum;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__mag_sum;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__mag_sum;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__mag_sum;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_carry_vec 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c2;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_sum_vec 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s2;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_carry_vec 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c2;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_sum_vec 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s2;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_carry_vec 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c2;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_sum_vec 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s2;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_carry_vec 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c2;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_sum_vec 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s2;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_carry_vec 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c2;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_sum_vec 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s2;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_carry_vec 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c2;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_sum_vec 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s2;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_carry_vec 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c2;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_sum_vec 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s2;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_carry_vec 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c2;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_sum_vec 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s2;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_carry_vec 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__csa_c2;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_sum_vec 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__csa_s2;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_carry_vec 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c2;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_sum_vec 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s2;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_carry_vec 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c2;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_sum_vec 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s2;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_hot_ones 
            = (3U & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_op) 
                      + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_op)) 
                     + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_op)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_hot_ones 
            = (3U & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_op) 
                      + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_op)) 
                     + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_op)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_hot_ones 
            = (3U & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_op) 
                      + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_op)) 
                     + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_op)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_hot_ones 
            = (3U & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_op) 
                      + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_op)) 
                     + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_op)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_hot_ones 
            = (3U & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_op) 
                      + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_op)) 
                     + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_op)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_hot_ones 
            = (3U & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_op) 
                      + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_op)) 
                     + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_op)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_hot_ones 
            = (3U & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_op) 
                      + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_op)) 
                     + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_op)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_hot_ones 
            = (3U & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_op) 
                      + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_op)) 
                     + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_op)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_hot_ones 
            = (3U & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_op) 
                      + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_op)) 
                     + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_op)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_hot_ones 
            = (3U & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_op) 
                      + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_op)) 
                     + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_op)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_hot_ones 
            = (3U & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_op) 
                      + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_op)) 
                     + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_op)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_exp_base 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_a_e;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_spec_res 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_exp_base 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_a_e;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_spec_res 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_exp_base 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_a_e;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_spec_res 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_exp_base 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_a_e;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_spec_res 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_exp_base 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_a_e;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_spec_res 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_exp_base 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_a_e;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_spec_res 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_exp_base 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_a_e;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_spec_res 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_exp_base 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_a_e;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_spec_res 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st2_exp_base 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_a_e;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st2_spec_res 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_exp_base 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_a_e;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_spec_res 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_exp_base 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_a_e;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_spec_res 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_a_e 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_special_result 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_a_e 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_special_result 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_a_e 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_special_result 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_a_e 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_special_result 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_a_e 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_special_result 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_a_e 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_special_result 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_a_e 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_special_result 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_a_e 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_special_result 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_a_e 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_x;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_special_result 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_a_e 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_special_result 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_a_e 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_special_result 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_result;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st2_sum_mag = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_carry_vec = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_sum_vec = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_carry_vec = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_sum_vec = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_carry_vec = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_sum_vec = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_carry_vec = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_sum_vec = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_carry_vec = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_sum_vec = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_carry_vec = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_sum_vec = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_carry_vec = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_sum_vec = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_carry_vec = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_sum_vec = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_carry_vec = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_sum_vec = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_carry_vec = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_sum_vec = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_carry_vec = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_sum_vec = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_hot_ones = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_hot_ones = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_hot_ones = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_hot_ones = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_hot_ones = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_hot_ones = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_hot_ones = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_hot_ones = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_hot_ones = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_hot_ones = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_hot_ones = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_exp_base = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_spec_res = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_exp_base = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_spec_res = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_exp_base = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_spec_res = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_exp_base = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_spec_res = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_exp_base = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_spec_res = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_exp_base = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_spec_res = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_exp_base = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_spec_res = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_exp_base = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_spec_res = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st2_exp_base = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st2_spec_res = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_exp_base = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_spec_res = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_exp_base = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_spec_res = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_a_e = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_special_result = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_a_e = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_special_result = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_a_e = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_special_result = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_a_e = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_special_result = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_a_e = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_special_result = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_a_e = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_special_result = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_a_e = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_special_result = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_a_e = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_special_result = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_a_e = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_special_result = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_a_e = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_special_result = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_a_e = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_special_result = 0U;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_a_s 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_a_s 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_a_s 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_a_s 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_a_s 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_a_s 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_a_s 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_a_s 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_a_s 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_a_s 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_a_s 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_special 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_special 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_special 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_special 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_special 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_special 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_special 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_special 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st2_special 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_special 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_special 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_align_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_align_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_align_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_align_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_align_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_align_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_align_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_align_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st2_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_align_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_align_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_align_sticky));
    if ((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum 
        = (0x3fffffffU & ((VL_EXTENDS_II(30,31, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_sum_vec) 
                           + VL_EXTENDS_II(30,30, (0x3fffffffU 
                                                   & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U)))) 
                          + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_hot_ones)));
    if ((0x20000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x3fffffffU & ((IData)(1U) + (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x1fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_a_s;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum 
        = (0x3fffffffU & ((VL_EXTENDS_II(30,31, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_sum_vec) 
                           + VL_EXTENDS_II(30,30, (0x3fffffffU 
                                                   & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U)))) 
                          + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_hot_ones)));
    if ((0x20000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x3fffffffU & ((IData)(1U) + (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x1fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_a_s;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum 
        = (0x3fffffffU & ((VL_EXTENDS_II(30,31, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_sum_vec) 
                           + VL_EXTENDS_II(30,30, (0x3fffffffU 
                                                   & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U)))) 
                          + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_hot_ones)));
    if ((0x20000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x3fffffffU & ((IData)(1U) + (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x1fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_a_s;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum 
        = (0x3fffffffU & ((VL_EXTENDS_II(30,31, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_sum_vec) 
                           + VL_EXTENDS_II(30,30, (0x3fffffffU 
                                                   & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U)))) 
                          + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_hot_ones)));
    if ((0x20000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x3fffffffU & ((IData)(1U) + (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x1fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_a_s;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum 
        = (0x3fffffffU & ((VL_EXTENDS_II(30,31, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_sum_vec) 
                           + VL_EXTENDS_II(30,30, (0x3fffffffU 
                                                   & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U)))) 
                          + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_hot_ones)));
    if ((0x20000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x3fffffffU & ((IData)(1U) + (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x1fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_a_s;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum 
        = (0x3fffffffU & ((VL_EXTENDS_II(30,31, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_sum_vec) 
                           + VL_EXTENDS_II(30,30, (0x3fffffffU 
                                                   & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U)))) 
                          + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_hot_ones)));
    if ((0x20000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x3fffffffU & ((IData)(1U) + (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x1fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_a_s;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum 
        = (0x3fffffffU & ((VL_EXTENDS_II(30,31, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_sum_vec) 
                           + VL_EXTENDS_II(30,30, (0x3fffffffU 
                                                   & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U)))) 
                          + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_hot_ones)));
    if ((0x20000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x3fffffffU & ((IData)(1U) + (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x1fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_a_s;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum 
        = (0x3fffffffU & ((VL_EXTENDS_II(30,31, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_sum_vec) 
                           + VL_EXTENDS_II(30,30, (0x3fffffffU 
                                                   & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U)))) 
                          + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_hot_ones)));
    if ((0x20000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x3fffffffU & ((IData)(1U) + (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__mag_sum 
            = (0x1fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_a_s;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__raw_sum 
        = (0x3fffffffU & ((VL_EXTENDS_II(30,31, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_sum_vec) 
                           + VL_EXTENDS_II(30,30, (0x3fffffffU 
                                                   & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_carry_vec, 1U)))) 
                          + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_hot_ones)));
    if ((0x20000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__raw_sum)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__mag_sum 
            = (0x3fffffffU & ((IData)(1U) + (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__raw_sum)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__mag_sum 
            = (0x1fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__raw_sum);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_a_s;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum 
        = (0x3fffffffU & ((VL_EXTENDS_II(30,31, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_sum_vec) 
                           + VL_EXTENDS_II(30,30, (0x3fffffffU 
                                                   & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_carry_vec, 1U)))) 
                          + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_hot_ones)));
    if ((0x20000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__mag_sum 
            = (0x3fffffffU & ((IData)(1U) + (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__mag_sum 
            = (0x1fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_a_s;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum 
        = (0x3fffffffU & ((VL_EXTENDS_II(30,31, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_sum_vec) 
                           + VL_EXTENDS_II(30,30, (0x3fffffffU 
                                                   & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_carry_vec, 1U)))) 
                          + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_hot_ones)));
    if ((0x20000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum)) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__mag_sum 
            = (0x3fffffffU & ((IData)(1U) + (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__mag_sum 
            = (0x1fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_a_s;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_special_case 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_special_case 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_special_case 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_special_case 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_special_case 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_special_case 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_special_case 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_special_case 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_special_case 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_special_case 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_special_case 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_align_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_y) 
                | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_m)) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_n)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_align_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_y) 
                | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_m)) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_n)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_align_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_y) 
                | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_m)) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_n)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_align_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_y) 
                | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_m)) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_n)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_align_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_y) 
                | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_m)) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_n)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_align_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_y) 
                | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_m)) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_n)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_align_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_y) 
                | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_m)) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_n)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_align_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_y) 
                | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_m)) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_n)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__st1_align_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sticky_y) 
                | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sticky_m)) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sticky_n)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_align_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_y) 
                | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_m)) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_n)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_align_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_y) 
                | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_m)) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_n)));
}

void Vadd32_fp32accum_bf16_tb_softfloat___024root___timing_resume(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___timing_resume\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x4000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_he33aaeae__0.resume(
                                                   "@(negedge add32_fp32accum_bf16_tb_softfloat.tb_clk)");
    }
    if ((0x2000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vadd32_fp32accum_bf16_tb_softfloat___024root___timing_commit(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___timing_commit\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (0x4000ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_he33aaeae__0.commit(
                                                   "@(negedge add32_fp32accum_bf16_tb_softfloat.tb_clk)");
    }
}

void Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_triggers__act(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);

bool Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_phase__act(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_phase__act\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<15> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_triggers__act(vlSelf);
    Vadd32_fp32accum_bf16_tb_softfloat___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vadd32_fp32accum_bf16_tb_softfloat___024root___timing_resume(vlSelf);
        Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_phase__nba(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_phase__nba\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd32_fp32accum_bf16_tb_softfloat___024root___dump_triggers__nba(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd32_fp32accum_bf16_tb_softfloat___024root___dump_triggers__act(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG

void Vadd32_fp32accum_bf16_tb_softfloat___024root___eval(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___eval\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vadd32_fp32accum_bf16_tb_softfloat___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 16, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vadd32_fp32accum_bf16_tb_softfloat___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 16, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_debug_assertions(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_debug_assertions\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
