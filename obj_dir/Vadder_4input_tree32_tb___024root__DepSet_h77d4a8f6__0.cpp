// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadder_4input_tree32_tb.h for the primary calling header

#include "Vadder_4input_tree32_tb__pch.h"
#include "Vadder_4input_tree32_tb__Syms.h"
#include "Vadder_4input_tree32_tb___024root.h"

extern const VlWide<21>/*671:0*/ Vadder_4input_tree32_tb__ConstPool__CONST_h25bd285d_0;

VL_INLINE_OPT VlCoroutine Vadder_4input_tree32_tb___024root___eval_initial__TOP__Vtiming__0(Vadder_4input_tree32_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_4input_tree32_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    std::string adder_4input_tree32_tb__DOT__header;
    IData/*31:0*/ adder_4input_tree32_tb__DOT__unnamedblk1__DOT__unnamedblk1_1__DOT____Vrepeat0;
    adder_4input_tree32_tb__DOT__unnamedblk1__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vfunc_adder_4input_tree32_tb__DOT__get_ulp_bf16__0__Vfuncout;
    __Vfunc_adder_4input_tree32_tb__DOT__get_ulp_bf16__0__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_adder_4input_tree32_tb__DOT__get_ulp_bf16__0__hw;
    __Vfunc_adder_4input_tree32_tb__DOT__get_ulp_bf16__0__hw = 0;
    SData/*15:0*/ __Vfunc_adder_4input_tree32_tb__DOT__get_ulp_bf16__0__ref_v;
    __Vfunc_adder_4input_tree32_tb__DOT__get_ulp_bf16__0__ref_v = 0;
    VlWide<5>/*159:0*/ __Vtemp_1;
    VlWide<5>/*159:0*/ __Vtemp_2;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x72696674U;
    __Vtemp_1[2U] = 0x65655f64U;
    __Vtemp_1[3U] = 0x732f7472U;
    __Vtemp_1[4U] = 0x77617665U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(5, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    __Vtemp_2[0U] = 0x2e637376U;
    __Vtemp_2[1U] = 0x75726573U;
    __Vtemp_2[2U] = 0x6661696cU;
    __Vtemp_2[3U] = 0x63756d5fU;
    __Vtemp_2[4U] = 0x6163U;
    vlSelfRef.adder_4input_tree32_tb__DOT__fail_fd 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(5, __Vtemp_2)
                      , std::string{"w"});
    ;
    VL_FWRITEF_NX(vlSelfRef.adder_4input_tree32_tb__DOT__fail_fd,"expected,got,ulp_diff\n",0);
    vlSelfRef.adder_4input_tree32_tb__DOT__nrst = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/adder_4input_tree32_tb.sv", 
                                         65);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.adder_4input_tree32_tb__DOT__nrst = 1U;
    vlSelfRef.adder_4input_tree32_tb__DOT__fd = VL_FOPEN_NN(
                                                            VL_CVT_PACK_STR_NW(21, Vadder_4input_tree32_tb__ConstPool__CONST_h25bd285d_0)
                                                            , 
                                                            std::string{"r"});
    ;
    if (VL_UNLIKELY(((0U == vlSelfRef.adder_4input_tree32_tb__DOT__fd)))) {
        VL_WRITEF_NX("ERROR: CSV not found!\n",0);
        VL_FINISH_MT("tb/unit/systolic_array/adder_4input_tree32_tb.sv", 70, "");
    }
    (void)VL_FGETS_NI(adder_4input_tree32_tb__DOT__header, vlSelfRef.adder_4input_tree32_tb__DOT__fd);
    while ((! (vlSelfRef.adder_4input_tree32_tb__DOT__fd ? feof(VL_CVT_I_FP(vlSelfRef.adder_4input_tree32_tb__DOT__fd)) : true))) {
        {
            vlSelfRef.adder_4input_tree32_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 0U;
            while (VL_GTS_III(32, 0x61U, vlSelfRef.adder_4input_tree32_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i)) {
                vlSelfRef.adder_4input_tree32_tb__DOT__unnamedblk1__DOT__ret 
                    = VL_FSCANF_INX(vlSelfRef.adder_4input_tree32_tb__DOT__fd,"%x,",0,
                                    16,&(vlSelfRef.adder_4input_tree32_tb__DOT____Vlvbound_hb2b269bb__0)) ;
                if (VL_LIKELY(((0x60U >= (0x7fU & vlSelfRef.adder_4input_tree32_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i))))) {
                    vlSelfRef.adder_4input_tree32_tb__DOT__inputs[(0x7fU 
                                                                   & vlSelfRef.adder_4input_tree32_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i)] 
                        = vlSelfRef.adder_4input_tree32_tb__DOT____Vlvbound_hb2b269bb__0;
                }
                vlSelfRef.adder_4input_tree32_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i 
                    = ((IData)(1U) + vlSelfRef.adder_4input_tree32_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i);
            }
            vlSelfRef.adder_4input_tree32_tb__DOT__unnamedblk1__DOT__ret 
                = VL_FSCANF_INX(vlSelfRef.adder_4input_tree32_tb__DOT__fd,"%x\n",0,
                                16,&(vlSelfRef.adder_4input_tree32_tb__DOT__expected)) ;
            if ((0U == vlSelfRef.adder_4input_tree32_tb__DOT__unnamedblk1__DOT__ret)) {
                goto __Vlabel1;
            }
            adder_4input_tree32_tb__DOT__unnamedblk1__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0x80U;
            while (VL_LTS_III(32, 0U, adder_4input_tree32_tb__DOT__unnamedblk1__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
                co_await vlSelfRef.__VtrigSched_h2af12165__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge adder_4input_tree32_tb.clk)", 
                                                                     "tb/unit/systolic_array/adder_4input_tree32_tb.sv", 
                                                                     87);
                vlSelfRef.__Vm_traceActivity[2U] = 1U;
                adder_4input_tree32_tb__DOT__unnamedblk1__DOT__unnamedblk1_1__DOT____Vrepeat0 
                    = (adder_4input_tree32_tb__DOT__unnamedblk1__DOT__unnamedblk1_1__DOT____Vrepeat0 
                       - (IData)(1U));
            }
            vlSelfRef.adder_4input_tree32_tb__DOT__total_count 
                = ((IData)(1U) + vlSelfRef.adder_4input_tree32_tb__DOT__total_count);
            VL_WRITEF_NX("Test Case %0d: Expected=%x | Got=%x\n",0,
                         32,vlSelfRef.adder_4input_tree32_tb__DOT__total_count,
                         16,(IData)(vlSelfRef.adder_4input_tree32_tb__DOT__expected),
                         16,vlSelfRef.adder_4input_tree32_tb__DOT__hw_out);
            if (VL_UNLIKELY((((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__hw_out) 
                              != (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__expected))))) {
                __Vfunc_adder_4input_tree32_tb__DOT__get_ulp_bf16__0__ref_v 
                    = vlSelfRef.adder_4input_tree32_tb__DOT__expected;
                __Vfunc_adder_4input_tree32_tb__DOT__get_ulp_bf16__0__hw 
                    = vlSelfRef.adder_4input_tree32_tb__DOT__hw_out;
                {
                    if (((IData)(__Vfunc_adder_4input_tree32_tb__DOT__get_ulp_bf16__0__hw) 
                         == (IData)(__Vfunc_adder_4input_tree32_tb__DOT__get_ulp_bf16__0__ref_v))) {
                        __Vfunc_adder_4input_tree32_tb__DOT__get_ulp_bf16__0__Vfuncout = 0U;
                        goto __Vlabel2;
                    }
                    if (((0xffU == (0xffU & ((IData)(__Vfunc_adder_4input_tree32_tb__DOT__get_ulp_bf16__0__hw) 
                                             >> 7U))) 
                         | (0xffU == (0xffU & ((IData)(__Vfunc_adder_4input_tree32_tb__DOT__get_ulp_bf16__0__ref_v) 
                                               >> 7U))))) {
                        __Vfunc_adder_4input_tree32_tb__DOT__get_ulp_bf16__0__Vfuncout = 0xffffffffU;
                        goto __Vlabel2;
                    }
                    if (((1U & ((IData)(__Vfunc_adder_4input_tree32_tb__DOT__get_ulp_bf16__0__hw) 
                                >> 0xfU)) != (1U & 
                                              ((IData)(__Vfunc_adder_4input_tree32_tb__DOT__get_ulp_bf16__0__ref_v) 
                                               >> 0xfU)))) {
                        __Vfunc_adder_4input_tree32_tb__DOT__get_ulp_bf16__0__Vfuncout = 0x7fffU;
                        goto __Vlabel2;
                    }
                    __Vfunc_adder_4input_tree32_tb__DOT__get_ulp_bf16__0__Vfuncout 
                        = (((IData)(__Vfunc_adder_4input_tree32_tb__DOT__get_ulp_bf16__0__hw) 
                            > (IData)(__Vfunc_adder_4input_tree32_tb__DOT__get_ulp_bf16__0__ref_v))
                            ? ((IData)(__Vfunc_adder_4input_tree32_tb__DOT__get_ulp_bf16__0__hw) 
                               - (IData)(__Vfunc_adder_4input_tree32_tb__DOT__get_ulp_bf16__0__ref_v))
                            : ((IData)(__Vfunc_adder_4input_tree32_tb__DOT__get_ulp_bf16__0__ref_v) 
                               - (IData)(__Vfunc_adder_4input_tree32_tb__DOT__get_ulp_bf16__0__hw)));
                    __Vlabel2: ;
                }
                vlSelfRef.adder_4input_tree32_tb__DOT__unnamedblk1__DOT__unnamedblk3__DOT__ulp 
                    = __Vfunc_adder_4input_tree32_tb__DOT__get_ulp_bf16__0__Vfuncout;
                vlSelfRef.adder_4input_tree32_tb__DOT__fail_count 
                    = ((IData)(1U) + vlSelfRef.adder_4input_tree32_tb__DOT__fail_count);
                vlSelfRef.adder_4input_tree32_tb__DOT__total_ulp_error 
                    = (vlSelfRef.adder_4input_tree32_tb__DOT__total_ulp_error 
                       + VL_ISTOR_D_I(32, vlSelfRef.adder_4input_tree32_tb__DOT__unnamedblk1__DOT__unnamedblk3__DOT__ulp));
                if (VL_GTS_III(32, vlSelfRef.adder_4input_tree32_tb__DOT__unnamedblk1__DOT__unnamedblk3__DOT__ulp, vlSelfRef.adder_4input_tree32_tb__DOT__largest_ulp)) {
                    vlSelfRef.adder_4input_tree32_tb__DOT__largest_ulp 
                        = vlSelfRef.adder_4input_tree32_tb__DOT__unnamedblk1__DOT__unnamedblk3__DOT__ulp;
                }
                VL_FWRITEF_NX(vlSelfRef.adder_4input_tree32_tb__DOT__fail_fd,"%x,%x,%11d\n",0,
                              16,vlSelfRef.adder_4input_tree32_tb__DOT__expected,
                              16,(IData)(vlSelfRef.adder_4input_tree32_tb__DOT__hw_out),
                              32,vlSelfRef.adder_4input_tree32_tb__DOT__unnamedblk1__DOT__unnamedblk3__DOT__ulp);
                if (VL_UNLIKELY(((VL_GTES_III(32, 0xfU, vlSelfRef.adder_4input_tree32_tb__DOT__fail_count) 
                                  | VL_LTS_III(32, 0x64U, vlSelfRef.adder_4input_tree32_tb__DOT__unnamedblk1__DOT__unnamedblk3__DOT__ulp))))) {
                    VL_WRITEF_NX("FAIL Case %0d: Exp=%x Got=%x | ULP Diff: %0d\n",0,
                                 32,vlSelfRef.adder_4input_tree32_tb__DOT__total_count,
                                 16,(IData)(vlSelfRef.adder_4input_tree32_tb__DOT__expected),
                                 16,vlSelfRef.adder_4input_tree32_tb__DOT__hw_out,
                                 32,vlSelfRef.adder_4input_tree32_tb__DOT__unnamedblk1__DOT__unnamedblk3__DOT__ulp);
                } else if (VL_UNLIKELY(((0x10U == vlSelfRef.adder_4input_tree32_tb__DOT__fail_count)))) {
                    VL_WRITEF_NX("... (Further failures silenced, check accum_failures.csv) ...\n",0);
                }
            } else {
                vlSelfRef.adder_4input_tree32_tb__DOT__pass_count 
                    = ((IData)(1U) + vlSelfRef.adder_4input_tree32_tb__DOT__pass_count);
            }
            if (VL_UNLIKELY(((0U == VL_MODDIVS_III(32, vlSelfRef.adder_4input_tree32_tb__DOT__total_count, (IData)(0x64U)))))) {
                VL_WRITEF_NX("Progress: %0d cases processed...\n",0,
                             32,vlSelfRef.adder_4input_tree32_tb__DOT__total_count);
            }
            __Vlabel1: ;
        }
    }
    VL_WRITEF_NX("\n=== ACCUMULATION DRIFT SUMMARY ===\nSTAGES: 32 (97 inputs)\nPASSED: %0d\nFAILED: %0d\n",0,
                 32,vlSelfRef.adder_4input_tree32_tb__DOT__pass_count,
                 32,vlSelfRef.adder_4input_tree32_tb__DOT__fail_count);
    if (VL_UNLIKELY((VL_LTS_III(32, 0U, vlSelfRef.adder_4input_tree32_tb__DOT__total_count)))) {
        VL_WRITEF_NX("AVG ULP DRIFT: %f\n",0,64,(vlSelfRef.adder_4input_tree32_tb__DOT__total_ulp_error 
                                                 / 
                                                 VL_ISTOR_D_I(32, vlSelfRef.adder_4input_tree32_tb__DOT__total_count)));
    }
    VL_WRITEF_NX("MAX ULP DRIFT: %0d\n==================================\n\n",0,
                 32,vlSelfRef.adder_4input_tree32_tb__DOT__largest_ulp);
    VL_FCLOSE_I(vlSelfRef.adder_4input_tree32_tb__DOT__fd); VL_FCLOSE_I(vlSelfRef.adder_4input_tree32_tb__DOT__fail_fd); VL_FINISH_MT("tb/unit/systolic_array/adder_4input_tree32_tb.sv", 127, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadder_4input_tree32_tb___024root___dump_triggers__act(Vadder_4input_tree32_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vadder_4input_tree32_tb___024root___eval_triggers__act(Vadder_4input_tree32_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_4input_tree32_tb___024root___eval_triggers__act\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, (vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__rounded_mant_int 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(1U, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(2U, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__2__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__2__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(3U, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__3__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__3__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(4U, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__4__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__4__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(5U, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__5__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__5__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(6U, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__6__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__6__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(7U, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__7__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__7__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(8U, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__8__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__8__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(9U, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__9__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__9__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(0xaU, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__10__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                            != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__10__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(0xbU, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__11__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                            != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__11__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(0xcU, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__12__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                            != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__12__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(0xdU, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__13__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                            != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__13__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(0xeU, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__14__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                            != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__14__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(0xfU, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__15__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                            != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__15__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(0x10U, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__16__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                             != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__16__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(0x11U, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__17__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                             != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__17__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(0x12U, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__18__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                             != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__18__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(0x13U, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__19__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                             != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__19__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(0x14U, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__20__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                             != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__20__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(0x15U, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__21__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                             != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__21__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(0x16U, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__22__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                             != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__22__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(0x17U, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__23__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                             != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__23__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(0x18U, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__24__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                             != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__24__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(0x19U, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__25__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                             != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__25__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(0x1aU, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__26__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                             != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__26__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(0x1bU, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__27__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                             != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__27__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(0x1cU, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__28__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                             != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__28__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(0x1dU, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__29__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                             != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__29__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(0x1eU, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__30__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                             != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__30__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(0x1fU, (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__31__KET____DOT__stage_inst.__PVT__rounded_mant_int 
                                             != vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__31__KET____DOT__stage_inst____PVT__rounded_mant_int__1));
    vlSelfRef.__VactTriggered.setBit(0x20U, ((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__clk) 
                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__clk__0))));
    vlSelfRef.__VactTriggered.setBit(0x21U, ((~ (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__nrst)) 
                                             & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__nrst__0)));
    vlSelfRef.__VactTriggered.setBit(0x22U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__rounded_mant_int__1 
        = vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__2__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__2__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__3__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__3__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__4__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__4__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__5__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__5__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__6__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__6__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__7__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__7__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__8__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__8__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__9__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__9__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__10__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__10__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__11__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__11__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__12__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__12__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__13__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__13__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__14__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__14__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__15__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__15__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__16__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__16__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__17__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__17__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__18__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__18__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__19__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__19__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__20__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__20__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__21__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__21__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__22__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__22__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__23__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__23__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__24__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__24__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__25__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__25__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__26__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__26__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__27__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__27__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__28__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__28__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__29__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__29__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__30__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__30__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__31__KET____DOT__stage_inst____PVT__rounded_mant_int__1 
        = vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__31__KET____DOT__stage_inst.__PVT__rounded_mant_int;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__clk__0 
        = vlSelfRef.adder_4input_tree32_tb__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__adder_4input_tree32_tb__DOT__nrst__0 
        = vlSelfRef.adder_4input_tree32_tb__DOT__nrst;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VactDidInit)))))) {
        vlSelfRef.__VactDidInit = 1U;
        vlSelfRef.__VactTriggered.setBit(0U, 1U);
        vlSelfRef.__VactTriggered.setBit(1U, 1U);
        vlSelfRef.__VactTriggered.setBit(2U, 1U);
        vlSelfRef.__VactTriggered.setBit(3U, 1U);
        vlSelfRef.__VactTriggered.setBit(4U, 1U);
        vlSelfRef.__VactTriggered.setBit(5U, 1U);
        vlSelfRef.__VactTriggered.setBit(6U, 1U);
        vlSelfRef.__VactTriggered.setBit(7U, 1U);
        vlSelfRef.__VactTriggered.setBit(8U, 1U);
        vlSelfRef.__VactTriggered.setBit(9U, 1U);
        vlSelfRef.__VactTriggered.setBit(0xaU, 1U);
        vlSelfRef.__VactTriggered.setBit(0xbU, 1U);
        vlSelfRef.__VactTriggered.setBit(0xcU, 1U);
        vlSelfRef.__VactTriggered.setBit(0xdU, 1U);
        vlSelfRef.__VactTriggered.setBit(0xeU, 1U);
        vlSelfRef.__VactTriggered.setBit(0xfU, 1U);
        vlSelfRef.__VactTriggered.setBit(0x10U, 1U);
        vlSelfRef.__VactTriggered.setBit(0x11U, 1U);
        vlSelfRef.__VactTriggered.setBit(0x12U, 1U);
        vlSelfRef.__VactTriggered.setBit(0x13U, 1U);
        vlSelfRef.__VactTriggered.setBit(0x14U, 1U);
        vlSelfRef.__VactTriggered.setBit(0x15U, 1U);
        vlSelfRef.__VactTriggered.setBit(0x16U, 1U);
        vlSelfRef.__VactTriggered.setBit(0x17U, 1U);
        vlSelfRef.__VactTriggered.setBit(0x18U, 1U);
        vlSelfRef.__VactTriggered.setBit(0x19U, 1U);
        vlSelfRef.__VactTriggered.setBit(0x1aU, 1U);
        vlSelfRef.__VactTriggered.setBit(0x1bU, 1U);
        vlSelfRef.__VactTriggered.setBit(0x1cU, 1U);
        vlSelfRef.__VactTriggered.setBit(0x1dU, 1U);
        vlSelfRef.__VactTriggered.setBit(0x1eU, 1U);
        vlSelfRef.__VactTriggered.setBit(0x1fU, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vadder_4input_tree32_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void Vadder_4input_tree32_tb___024root___act_sequent__TOP__0(Vadder_4input_tree32_tb___024root* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__2__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__3__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__4__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__5__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__6__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__7__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__8__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__9__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__10__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__11__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__12__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__13__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__14__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__15__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__16__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__17__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__18__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__19__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__20__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__21__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__22__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__23__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__24__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__25__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__26__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__27__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__28__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__29__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__30__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__31__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);

void Vadder_4input_tree32_tb___024root___eval_act(Vadder_4input_tree32_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_4input_tree32_tb___024root___eval_act\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb___024root___act_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__2__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__3__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[6U] = 1U;
    }
    if ((0x10ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__4__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[7U] = 1U;
    }
    if ((0x20ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__5__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[8U] = 1U;
    }
    if ((0x40ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__6__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[9U] = 1U;
    }
    if ((0x80ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__7__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0xaU] = 1U;
    }
    if ((0x100ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__8__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0xbU] = 1U;
    }
    if ((0x200ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__9__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0xcU] = 1U;
    }
    if ((0x400ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__10__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0xdU] = 1U;
    }
    if ((0x800ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__11__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0xeU] = 1U;
    }
    if ((0x1000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__12__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0xfU] = 1U;
    }
    if ((0x2000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__13__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x10U] = 1U;
    }
    if ((0x4000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__14__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x11U] = 1U;
    }
    if ((0x8000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__15__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x12U] = 1U;
    }
    if ((0x10000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__16__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x13U] = 1U;
    }
    if ((0x20000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__17__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x14U] = 1U;
    }
    if ((0x40000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__18__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x15U] = 1U;
    }
    if ((0x80000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__19__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x16U] = 1U;
    }
    if ((0x100000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__20__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x17U] = 1U;
    }
    if ((0x200000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__21__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x18U] = 1U;
    }
    if ((0x400000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__22__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x19U] = 1U;
    }
    if ((0x800000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__23__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x1aU] = 1U;
    }
    if ((0x1000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__24__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x1bU] = 1U;
    }
    if ((0x2000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__25__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x1cU] = 1U;
    }
    if ((0x4000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__26__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x1dU] = 1U;
    }
    if ((0x8000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__27__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x1eU] = 1U;
    }
    if ((0x10000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__28__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x1fU] = 1U;
    }
    if ((0x20000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__29__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x20U] = 1U;
    }
    if ((0x40000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__30__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x21U] = 1U;
    }
    if ((0x80000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__31__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x22U] = 1U;
    }
    if ((0x500000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x23U] = 1U;
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__2__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__2__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__3__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__3__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__4__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__4__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__5__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__5__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__6__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__6__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__7__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__7__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__8__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__8__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__9__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__9__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__10__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__10__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__11__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__11__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__12__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__12__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__13__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__13__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__14__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__14__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__15__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__15__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__16__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__16__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__17__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__17__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__18__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__18__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__19__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__19__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__20__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__20__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__21__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__21__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__22__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__22__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__23__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__23__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__24__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__24__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__25__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__25__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__26__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__26__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__27__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__27__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__28__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__28__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__29__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__29__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__30__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__30__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__31__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__31__KET____DOT__stage_inst));
    }
}

void Vadder_4input_tree32_tb___024root___nba_sequent__TOP__0(Vadder_4input_tree32_tb___024root* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__31__KET____DOT__stage_inst__0(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__30__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__29__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__28__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__27__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__26__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__25__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__24__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__23__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__22__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__21__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__20__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__19__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__18__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__17__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__16__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__15__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__14__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__13__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__12__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__11__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__10__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__9__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__8__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__7__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__6__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__5__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__4__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__3__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__2__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__1(Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3* vlSelf);
void Vadder_4input_tree32_tb___024root___nba_sequent__TOP__1(Vadder_4input_tree32_tb___024root* vlSelf);

void Vadder_4input_tree32_tb___024root___eval_nba(Vadder_4input_tree32_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_4input_tree32_tb___024root___eval_nba\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x300000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x24U] = 1U;
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__2__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__3__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__4__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__5__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__6__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__7__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__8__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__9__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__10__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__11__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__12__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__13__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__14__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__15__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__16__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__17__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__18__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__19__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__20__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__21__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__22__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__23__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__24__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__25__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__26__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__27__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__28__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__29__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__30__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__31__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__31__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__30__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__30__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__29__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__29__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__28__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__28__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__27__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__27__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__26__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__26__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__25__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__25__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__24__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__24__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__23__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__23__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__22__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__22__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__21__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__21__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__20__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__20__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__19__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__19__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__18__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__18__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__17__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__17__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__16__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__16__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__15__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__15__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__14__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__14__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__13__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__13__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__12__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__12__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__11__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__11__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__10__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__10__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__9__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__9__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__8__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__8__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__7__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__7__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__6__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__6__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__5__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__5__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__4__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__4__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__3__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__3__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__2__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__2__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___nba_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__1((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((0x380000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__31__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x25U] = 1U;
    }
    if ((0x340000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__30__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x26U] = 1U;
    }
    if ((0x320000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__29__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x27U] = 1U;
    }
    if ((0x310000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__28__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x28U] = 1U;
    }
    if ((0x308000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__27__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x29U] = 1U;
    }
    if ((0x304000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__26__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x2aU] = 1U;
    }
    if ((0x302000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__25__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x2bU] = 1U;
    }
    if ((0x301000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__24__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x2cU] = 1U;
    }
    if ((0x300800000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__23__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x2dU] = 1U;
    }
    if ((0x300400000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__22__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x2eU] = 1U;
    }
    if ((0x300200000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__21__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x2fU] = 1U;
    }
    if ((0x300100000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__20__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x30U] = 1U;
    }
    if ((0x300080000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__19__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x31U] = 1U;
    }
    if ((0x300040000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__18__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x32U] = 1U;
    }
    if ((0x300020000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__17__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x33U] = 1U;
    }
    if ((0x300010000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__16__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x34U] = 1U;
    }
    if ((0x300008000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__15__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x35U] = 1U;
    }
    if ((0x300004000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__14__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x36U] = 1U;
    }
    if ((0x300002000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__13__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x37U] = 1U;
    }
    if ((0x300001000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__12__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x38U] = 1U;
    }
    if ((0x300000800ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__11__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x39U] = 1U;
    }
    if ((0x300000400ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__10__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x3aU] = 1U;
    }
    if ((0x300000200ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__9__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x3bU] = 1U;
    }
    if ((0x300000100ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__8__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x3cU] = 1U;
    }
    if ((0x300000080ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__7__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x3dU] = 1U;
    }
    if ((0x300000040ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__6__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x3eU] = 1U;
    }
    if ((0x300000020ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__5__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x3fU] = 1U;
    }
    if ((0x300000010ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__4__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x40U] = 1U;
    }
    if ((0x300000008ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__3__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x41U] = 1U;
    }
    if ((0x300000004ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__2__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x42U] = 1U;
    }
    if ((0x300000002ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_sequent__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x43U] = 1U;
    }
    if ((0x300000001ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb___024root___act_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x44U] = 1U;
    }
    if ((0x700000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__31__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__31__KET____DOT__stage_inst));
        vlSelfRef.__Vm_traceActivity[0x45U] = 1U;
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__30__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__30__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__29__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__29__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__28__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__28__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__27__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__27__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__26__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__26__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__25__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__25__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__24__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__24__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__23__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__23__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__22__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__22__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__21__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__21__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__20__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__20__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__19__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__19__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__18__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__18__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__17__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__17__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__16__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__16__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__15__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__15__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__14__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__14__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__13__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__13__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__12__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__12__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__11__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__11__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__10__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__10__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__9__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__9__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__8__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__8__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__7__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__7__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__6__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__6__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__5__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__5__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__4__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__4__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__3__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__3__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__2__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__2__KET____DOT__stage_inst));
        Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3___act_comb__TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst__0((&vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst));
    }
}

VL_INLINE_OPT void Vadder_4input_tree32_tb___024root___nba_sequent__TOP__1(Vadder_4input_tree32_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder_4input_tree32_tb___024root___nba_sequent__TOP__1\n"); );
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__0__KET__.out 
        = ((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__nrst)
            ? vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__stage_0__DOT__result_out
            : 0ULL);
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__final_reduce__DOT__guard 
        = (1U & (IData)((vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__31__KET__.out 
                         >> 0x12U)));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__final_reduce__DOT__rnd 
        = (1U & (IData)((vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__31__KET__.out 
                         >> 0x11U)));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__final_reduce__DOT__sticky 
        = (0U != (0x1ffffU & (IData)(vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__31__KET__.out)));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__final_reduce__DOT__round_up 
        = ((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__final_reduce__DOT__guard) 
           & (((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__final_reduce__DOT__rnd) 
               | (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__final_reduce__DOT__sticky)) 
              | (IData)((vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__31__KET__.out 
                         >> 0x13U))));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__final_reduce__DOT__rounded 
        = (0xffU & ((0x7fU & (IData)((vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__31__KET__.out 
                                      >> 0x13U))) + (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__final_reduce__DOT__round_up)));
    vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__final_reduce__DOT__new_exp 
        = (0x3ffU & (VL_EXTENDS_II(10,10, (0xffU & (IData)(
                                                           (vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__31__KET__.out 
                                                            >> 0x1aU)))) 
                     + VL_EXTENDS_II(10,10, (1U & ((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__final_reduce__DOT__rounded) 
                                                   >> 7U)))));
    vlSelfRef.adder_4input_tree32_tb__DOT__hw_out = 
        ((0xffU == (0xffU & (IData)((vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__31__KET__.out 
                                     >> 0x1aU)))) ? 
         (0x7f80U | ((0x8000U & ((IData)((vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__31__KET__.out 
                                          >> 0x22U)) 
                                 << 0xfU)) | ((0U != 
                                               (0x3ffffffU 
                                                & (IData)(vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__31__KET__.out)))
                                               ? 0x40U
                                               : 0U)))
          : (VL_LTES_III(10, 0xffU, (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__final_reduce__DOT__new_exp))
              ? (0x7f80U | (0x8000U & ((IData)((vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__31__KET__.out 
                                                >> 0x22U)) 
                                       << 0xfU))) : 
             (VL_GTES_III(32, 0U, VL_EXTENDS_II(32,10, (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__final_reduce__DOT__new_exp)))
               ? (0x8000U & ((IData)((vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__31__KET__.out 
                                      >> 0x22U)) << 0xfU))
               : ((0x8000U & ((IData)((vlSymsp->TOP__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__31__KET__.out 
                                       >> 0x22U)) << 0xfU)) 
                  | ((0x7f80U & ((IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__final_reduce__DOT__new_exp) 
                                 << 7U)) | ((0x80U 
                                             & (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__final_reduce__DOT__rounded))
                                             ? 0U : 
                                            (0x7fU 
                                             & (IData)(vlSelfRef.adder_4input_tree32_tb__DOT__dut__DOT__final_reduce__DOT__rounded))))))));
}
