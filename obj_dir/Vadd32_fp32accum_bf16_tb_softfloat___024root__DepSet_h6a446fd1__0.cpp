// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd32_fp32accum_bf16_tb_softfloat.h for the primary calling header

#include "Vadd32_fp32accum_bf16_tb_softfloat__pch.h"
#include "Vadd32_fp32accum_bf16_tb_softfloat___024root.h"

VlCoroutine Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_initial__TOP__Vtiming__0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);
VlCoroutine Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_initial__TOP__Vtiming__1(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);
VlCoroutine Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_initial__TOP__Vtiming__2(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);

void Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_initial(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_initial\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_initial__TOP__Vtiming__2(vlSelf);
}

extern const VlWide<16>/*511:0*/ Vadd32_fp32accum_bf16_tb_softfloat__ConstPool__CONST_h93e1b771_0;
extern const VlWide<14>/*447:0*/ Vadd32_fp32accum_bf16_tb_softfloat__ConstPool__CONST_h4e1d0cf8_0;

VL_INLINE_OPT VlCoroutine Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_initial__TOP__Vtiming__0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    std::string add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__header;
    VlWide<5>/*159:0*/ __Vtemp_1;
    // Body
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0U] 
        = Vadd32_fp32accum_bf16_tb_softfloat__ConstPool__CONST_h93e1b771_0[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[1U] 
        = Vadd32_fp32accum_bf16_tb_softfloat__ConstPool__CONST_h93e1b771_0[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[2U] 
        = Vadd32_fp32accum_bf16_tb_softfloat__ConstPool__CONST_h93e1b771_0[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[3U] 
        = Vadd32_fp32accum_bf16_tb_softfloat__ConstPool__CONST_h93e1b771_0[3U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[4U] 
        = Vadd32_fp32accum_bf16_tb_softfloat__ConstPool__CONST_h93e1b771_0[4U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[5U] 
        = Vadd32_fp32accum_bf16_tb_softfloat__ConstPool__CONST_h93e1b771_0[5U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[6U] 
        = Vadd32_fp32accum_bf16_tb_softfloat__ConstPool__CONST_h93e1b771_0[6U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[7U] 
        = Vadd32_fp32accum_bf16_tb_softfloat__ConstPool__CONST_h93e1b771_0[7U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[8U] 
        = Vadd32_fp32accum_bf16_tb_softfloat__ConstPool__CONST_h93e1b771_0[8U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[9U] 
        = Vadd32_fp32accum_bf16_tb_softfloat__ConstPool__CONST_h93e1b771_0[9U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xaU] 
        = Vadd32_fp32accum_bf16_tb_softfloat__ConstPool__CONST_h93e1b771_0[0xaU];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xbU] 
        = Vadd32_fp32accum_bf16_tb_softfloat__ConstPool__CONST_h93e1b771_0[0xbU];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xcU] 
        = Vadd32_fp32accum_bf16_tb_softfloat__ConstPool__CONST_h93e1b771_0[0xcU];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xdU] 
        = Vadd32_fp32accum_bf16_tb_softfloat__ConstPool__CONST_h93e1b771_0[0xdU];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xeU] 
        = Vadd32_fp32accum_bf16_tb_softfloat__ConstPool__CONST_h93e1b771_0[0xeU];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xfU] 
        = Vadd32_fp32accum_bf16_tb_softfloat__ConstPool__CONST_h93e1b771_0[0xfU];
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                         77);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst = 1U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__fd 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(14, Vadd32_fp32accum_bf16_tb_softfloat__ConstPool__CONST_h4e1d0cf8_0)
                      , std::string{"r"});
    ;
    __Vtemp_1[0U] = 0x2e637376U;
    __Vtemp_1[1U] = 0x75726573U;
    __Vtemp_1[2U] = 0x6661696cU;
    __Vtemp_1[3U] = 0x7265655fU;
    __Vtemp_1[4U] = 0x74U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(5, __Vtemp_1)
                      , std::string{"w"});
    ;
    if (VL_UNLIKELY(((0U == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__fd)))) {
        VL_WRITEF_NX("FATAL: CSV not found\n",0);
        VL_FINISH_MT("tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 82, "");
    }
    (void)VL_FGETS_NI(add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__header, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__fd);
    VL_WRITEF_NX("Starting Continuous Simulation with Full Diagnostics...\n",0);
    while ((! (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__fd ? feof(VL_CVT_I_FP(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__fd)) : true))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__ret 
            = VL_FSCANF_INX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__fd,"%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x\n",0,
                            16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                 [0U]),16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                            [1U]),16,
                            &(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                              [2U]),16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                         [3U]),16,&(
                                                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                                    [4U]),
                            16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                 [5U]),16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                            [6U]),16,
                            &(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                              [7U]),16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                         [8U]),16,&(
                                                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                                    [9U]),
                            16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                 [0xaU]),16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                              [0xbU]),
                            16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                 [0xcU]),16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                              [0xdU]),
                            16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                 [0xeU]),16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                              [0xfU]),
                            16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                 [0x10U]),16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                               [0x11U]),
                            16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                 [0x12U]),16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                               [0x13U]),
                            16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                 [0x14U]),16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                               [0x15U]),
                            16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                 [0x16U]),16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                               [0x17U]),
                            16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                 [0x18U]),16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                               [0x19U]),
                            16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                 [0x1aU]),16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                               [0x1bU]),
                            16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                 [0x1cU]),16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                               [0x1dU]),
                            16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                 [0x1eU]),16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                               [0x1fU]),
                            16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_expected)) ;
        if ((0x21U == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__ret)) {
            co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                                 "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                                 102);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0U] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0U]) 
                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [0U]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[0U] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[0U]) | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [0U]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 1U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0U] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0U]) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                      [1U] << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[0U] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[0U]) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                           [1U] << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 2U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[1U] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[1U]) 
                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [2U]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[1U] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[1U]) | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [2U]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 3U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[1U] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[1U]) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                      [3U] << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[1U] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[1U]) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                           [3U] << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 4U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[2U] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[2U]) 
                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [4U]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[2U] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[2U]) | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [4U]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 5U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[2U] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[2U]) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                      [5U] << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[2U] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[2U]) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                           [5U] << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 6U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[3U] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[3U]) 
                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [6U]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[3U] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[3U]) | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [6U]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 7U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[3U] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[3U]) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                      [7U] << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[3U] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[3U]) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                           [7U] << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 8U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[4U] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[4U]) 
                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [8U]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[4U] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[4U]) | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [8U]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 9U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[4U] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[4U]) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                      [9U] << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[4U] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[4U]) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                           [9U] << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 0xaU;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[5U] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[5U]) 
                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [0xaU]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[5U] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[5U]) | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [0xaU]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 0xbU;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[5U] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[5U]) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                      [0xbU] << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[5U] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[5U]) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                           [0xbU] << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 0xcU;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[6U] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[6U]) 
                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [0xcU]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[6U] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[6U]) | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [0xcU]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 0xdU;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[6U] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[6U]) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                      [0xdU] << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[6U] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[6U]) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                           [0xdU] << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 0xeU;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[7U] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[7U]) 
                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [0xeU]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[7U] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[7U]) | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [0xeU]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 0xfU;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[7U] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[7U]) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                      [0xfU] << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[7U] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[7U]) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                           [0xfU] << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 0x10U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[8U] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[8U]) 
                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [0x10U]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[8U] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[8U]) | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [0x10U]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 0x11U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[8U] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[8U]) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                      [0x11U] << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[8U] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[8U]) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                           [0x11U] 
                                           << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 0x12U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[9U] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[9U]) 
                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [0x12U]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[9U] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[9U]) | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [0x12U]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 0x13U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[9U] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[9U]) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                      [0x13U] << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[9U] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[9U]) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                           [0x13U] 
                                           << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 0x14U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xaU] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xaU]) 
                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [0x14U]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[0xaU] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[0xaU]) | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [0x14U]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 0x15U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xaU] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xaU]) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                      [0x15U] << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[0xaU] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[0xaU]) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                             [0x15U] 
                                             << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 0x16U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xbU] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xbU]) 
                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [0x16U]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[0xbU] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[0xbU]) | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [0x16U]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 0x17U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xbU] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xbU]) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                      [0x17U] << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[0xbU] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[0xbU]) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                             [0x17U] 
                                             << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 0x18U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xcU] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xcU]) 
                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [0x18U]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[0xcU] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[0xcU]) | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [0x18U]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 0x19U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xcU] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xcU]) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                      [0x19U] << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[0xcU] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[0xcU]) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                             [0x19U] 
                                             << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 0x1aU;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xdU] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xdU]) 
                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [0x1aU]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[0xdU] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[0xdU]) | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [0x1aU]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 0x1bU;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xdU] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xdU]) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                      [0x1bU] << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[0xdU] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[0xdU]) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                             [0x1bU] 
                                             << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 0x1cU;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xeU] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xeU]) 
                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [0x1cU]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[0xeU] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[0xeU]) | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [0x1cU]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 0x1dU;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xeU] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xeU]) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                      [0x1dU] << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[0xeU] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[0xeU]) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                             [0x1dU] 
                                             << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 0x1eU;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xfU] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xfU]) 
                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [0x1eU]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[0xfU] 
                = ((0xffff0000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[0xfU]) | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                   [0x1eU]);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 0x1fU;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xfU] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xfU]) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                      [0x1fU] << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__inputs[0xfU] 
                = ((0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry
                    .__PVT__inputs[0xfU]) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_inputs
                                             [0x1fU] 
                                             << 0x10U));
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__unnamedblk2__DOT__k = 0x20U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__expected 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__temp_expected;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry.__PVT__id 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__total_processed;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__scoreboard_queue.push_back(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__entry);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__total_processed 
                = ((IData)(1U) + vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__total_processed);
        }
    }
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         116);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         116);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         116);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         116);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         116);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         116);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         116);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         116);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         116);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         116);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         116);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         116);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         116);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         116);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         116);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         116);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         116);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         116);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         116);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("\nSimulation Completed.\n",0);
    VL_WRITEF_NX("\n========================================\nFINAL REPORT\nTOTAL CASES: %0d\nPASSED:      %0d\nFAILED:      %0d\n",0,
                 32,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__total_processed,
                 32,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__pass_count,
                 32,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_count);
    if (VL_UNLIKELY((VL_LTS_III(32, 0U, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__total_processed)))) {
        VL_WRITEF_NX("AVG ULP ERR: %0f\n",0,64,((1.0 
                                                 * 
                                                 VL_ISTOR_D_Q(64, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff)) 
                                                / VL_ISTOR_D_I(32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__total_processed)));
    }
    VL_WRITEF_NX("MAX ULP ERR: %0d\nULP > 1:     %0d\n========================================\n\n",0,
                 32,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__largest_ulp,
                 32,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count);
    VL_FINISH_MT("tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 119, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

VL_INLINE_OPT VlCoroutine Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_initial__TOP__Vtiming__1(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__1__Vfuncout;
    __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__1__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__1__val;
    __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__1__val = 0;
    CData/*0:0*/ __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__Vfuncout;
    __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__val;
    __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__val = 0;
    QData/*63:0*/ __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__Vfuncout;
    __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__a;
    __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__a = 0;
    SData/*15:0*/ __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__b;
    __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__b = 0;
    QData/*63:0*/ __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_a;
    __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_a = 0;
    QData/*63:0*/ __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_b;
    __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_b = 0;
    // Body
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         128);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         128);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         128);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         128);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         128);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         128);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         128);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         128);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         128);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         128);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         128);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         128);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         128);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_he33aaeef__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                         128);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    while (1U) {
        co_await vlSelfRef.__VtrigSched_he33aaeae__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                             "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                             131);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        if (VL_LTS_III(32, 0U, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__scoreboard_queue.size())) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__scoreboard_queue.pop_front();
            if ((([&]() {
                            __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__1__val 
                                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_result;
                            __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__1__Vfuncout 
                                = (IData)(((0x7f80U 
                                            == (0x7f80U 
                                                & (IData)(__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__1__val))) 
                                           & (0U != 
                                              (0x7fU 
                                               & (IData)(__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__1__val)))));
                        }(), (IData)(__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__1__Vfuncout)) 
                 & ([&]() {
                            __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__val 
                                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                .__PVT__expected;
                            __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__Vfuncout 
                                = (IData)(((0x7f80U 
                                            == (0x7f80U 
                                                & (IData)(__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__val))) 
                                           & (0U != 
                                              (0x7fU 
                                               & (IData)(__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__val)))));
                        }(), (IData)(__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__Vfuncout)))) {
                vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__match = 1U;
                vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__ulp = 0ULL;
            } else {
                vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__match 
                    = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_result) 
                       == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                       .__PVT__expected);
                __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__b 
                    = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                    .__PVT__expected;
                __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__a 
                    = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_result;
                __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_a = 0;
                __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_b = 0;
                __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_a 
                    = ((0x8000U & (IData)(__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__a))
                        ? (0x7fffffffULL - (QData)((IData)(
                                                           (0x7fffU 
                                                            & (IData)(__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__a)))))
                        : (0x80000000ULL + (QData)((IData)(
                                                           (0x7fffU 
                                                            & (IData)(__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__a))))));
                __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_b 
                    = ((0x8000U & (IData)(__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__b))
                        ? (0x7fffffffULL - (QData)((IData)(
                                                           (0x7fffU 
                                                            & (IData)(__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__b)))))
                        : (0x80000000ULL + (QData)((IData)(
                                                           (0x7fffU 
                                                            & (IData)(__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__b))))));
                __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__Vfuncout 
                    = (VL_GTS_IQQ(64, __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_a, __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_b)
                        ? (__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_a 
                           - __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_b)
                        : (__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_b 
                           - __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_a));
                vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__ulp 
                    = __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__Vfuncout;
            }
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
                = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
                   + vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__ulp);
            if (VL_LTS_IQQ(64, 1ULL, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__ulp)) {
                vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count 
                    = ((IData)(1U) + vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count);
            }
            if (VL_GTS_IQQ(64, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__ulp, 
                           VL_EXTENDS_QI(64,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__largest_ulp))) {
                vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__largest_ulp 
                    = (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__ulp);
            }
            if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__match) {
                vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__pass_count 
                    = ((IData)(1U) + vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__pass_count);
            } else {
                if (VL_UNLIKELY((VL_GTS_III(32, 0x14U, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_count)))) {
                    VL_WRITEF_NX("FAIL: Row %0d | Got=%x Exp=%x | ULP=%0d\n",0,
                                 32,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                 .__PVT__id,16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_result,
                                 16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                 .__PVT__expected,64,
                                 vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__ulp);
                }
                if (VL_UNLIKELY(((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd)))) {
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[0U]));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 1U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[0U] 
                                      >> 0x10U));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 2U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[1U]));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 3U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[1U] 
                                      >> 0x10U));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 4U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[2U]));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 5U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[2U] 
                                      >> 0x10U));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 6U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[3U]));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 7U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[3U] 
                                      >> 0x10U));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 8U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[4U]));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 9U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[4U] 
                                      >> 0x10U));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 0xaU;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[5U]));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 0xbU;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[5U] 
                                      >> 0x10U));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 0xcU;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[6U]));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 0xdU;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[6U] 
                                      >> 0x10U));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 0xeU;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[7U]));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 0xfU;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[7U] 
                                      >> 0x10U));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 0x10U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[8U]));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 0x11U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[8U] 
                                      >> 0x10U));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 0x12U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[9U]));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 0x13U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[9U] 
                                      >> 0x10U));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 0x14U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[0xaU]));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 0x15U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[0xaU] 
                                      >> 0x10U));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 0x16U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[0xbU]));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 0x17U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[0xbU] 
                                      >> 0x10U));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 0x18U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[0xcU]));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 0x19U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[0xcU] 
                                      >> 0x10U));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 0x1aU;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[0xdU]));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 0x1bU;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[0xdU] 
                                      >> 0x10U));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 0x1cU;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[0xeU]));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 0x1dU;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[0xeU] 
                                      >> 0x10U));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 0x1eU;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(0xffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[0xfU]));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 0x1fU;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                      .__PVT__inputs[0xfU] 
                                      >> 0x10U));
                    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__unnamedblk4__DOT__k = 0x20U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,%x,%0d\n",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                  .__PVT__expected,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_result,
                                  64,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__ulp);
                }
                vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_count 
                    = ((IData)(1U) + vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_count);
            }
            if (VL_UNLIKELY((((0U == VL_MODDIVS_III(32, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                                                .__PVT__id), (IData)(0x186a0U))) 
                              & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                                 .__PVT__id))))) {
                VL_WRITEF_NX("Processed %0d cases...\n",0,
                             32,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__check_entry
                             .__PVT__id);
            }
        }
    }
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
}

VL_INLINE_OPT VlCoroutine Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_initial__TOP__Vtiming__2(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                             nullptr, 
                                             "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                             17);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_clk 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_clk)));
    }
}

void Vadd32_fp32accum_bf16_tb_softfloat___024root___act_comb__TOP__0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);

void Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_act(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_act\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((5ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
}

VL_INLINE_OPT void Vadd32_fp32accum_bf16_tb_softfloat___024root___act_comb__TOP__0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___act_comb__TOP__0\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*127:0*/ __Vtemp_9;
    VlWide<4>/*127:0*/ __Vtemp_10;
    VlWide<4>/*127:0*/ __Vtemp_15;
    VlWide<4>/*127:0*/ __Vtemp_18;
    VlWide<4>/*127:0*/ __Vtemp_19;
    VlWide<4>/*127:0*/ __Vtemp_24;
    VlWide<4>/*127:0*/ __Vtemp_27;
    VlWide<4>/*127:0*/ __Vtemp_28;
    VlWide<4>/*127:0*/ __Vtemp_33;
    VlWide<4>/*127:0*/ __Vtemp_57;
    VlWide<4>/*127:0*/ __Vtemp_60;
    VlWide<4>/*127:0*/ __Vtemp_62;
    VlWide<4>/*127:0*/ __Vtemp_74;
    VlWide<4>/*127:0*/ __Vtemp_75;
    VlWide<4>/*127:0*/ __Vtemp_80;
    VlWide<4>/*127:0*/ __Vtemp_83;
    VlWide<4>/*127:0*/ __Vtemp_84;
    VlWide<4>/*127:0*/ __Vtemp_89;
    VlWide<4>/*127:0*/ __Vtemp_92;
    VlWide<4>/*127:0*/ __Vtemp_93;
    VlWide<4>/*127:0*/ __Vtemp_98;
    VlWide<4>/*127:0*/ __Vtemp_122;
    VlWide<4>/*127:0*/ __Vtemp_125;
    VlWide<4>/*127:0*/ __Vtemp_127;
    VlWide<4>/*127:0*/ __Vtemp_139;
    VlWide<4>/*127:0*/ __Vtemp_140;
    VlWide<4>/*127:0*/ __Vtemp_145;
    VlWide<4>/*127:0*/ __Vtemp_148;
    VlWide<4>/*127:0*/ __Vtemp_149;
    VlWide<4>/*127:0*/ __Vtemp_154;
    VlWide<4>/*127:0*/ __Vtemp_157;
    VlWide<4>/*127:0*/ __Vtemp_158;
    VlWide<4>/*127:0*/ __Vtemp_163;
    VlWide<4>/*127:0*/ __Vtemp_187;
    VlWide<4>/*127:0*/ __Vtemp_190;
    VlWide<4>/*127:0*/ __Vtemp_192;
    VlWide<4>/*127:0*/ __Vtemp_204;
    VlWide<4>/*127:0*/ __Vtemp_205;
    VlWide<4>/*127:0*/ __Vtemp_210;
    VlWide<4>/*127:0*/ __Vtemp_213;
    VlWide<4>/*127:0*/ __Vtemp_214;
    VlWide<4>/*127:0*/ __Vtemp_219;
    VlWide<4>/*127:0*/ __Vtemp_222;
    VlWide<4>/*127:0*/ __Vtemp_223;
    VlWide<4>/*127:0*/ __Vtemp_228;
    VlWide<4>/*127:0*/ __Vtemp_252;
    VlWide<4>/*127:0*/ __Vtemp_255;
    VlWide<4>/*127:0*/ __Vtemp_257;
    VlWide<4>/*127:0*/ __Vtemp_269;
    VlWide<4>/*127:0*/ __Vtemp_270;
    VlWide<4>/*127:0*/ __Vtemp_275;
    VlWide<4>/*127:0*/ __Vtemp_278;
    VlWide<4>/*127:0*/ __Vtemp_279;
    VlWide<4>/*127:0*/ __Vtemp_284;
    VlWide<4>/*127:0*/ __Vtemp_287;
    VlWide<4>/*127:0*/ __Vtemp_288;
    VlWide<4>/*127:0*/ __Vtemp_293;
    VlWide<4>/*127:0*/ __Vtemp_317;
    VlWide<4>/*127:0*/ __Vtemp_320;
    VlWide<4>/*127:0*/ __Vtemp_322;
    VlWide<4>/*127:0*/ __Vtemp_334;
    VlWide<4>/*127:0*/ __Vtemp_335;
    VlWide<4>/*127:0*/ __Vtemp_340;
    VlWide<4>/*127:0*/ __Vtemp_343;
    VlWide<4>/*127:0*/ __Vtemp_344;
    VlWide<4>/*127:0*/ __Vtemp_349;
    VlWide<4>/*127:0*/ __Vtemp_352;
    VlWide<4>/*127:0*/ __Vtemp_353;
    VlWide<4>/*127:0*/ __Vtemp_358;
    VlWide<4>/*127:0*/ __Vtemp_382;
    VlWide<4>/*127:0*/ __Vtemp_385;
    VlWide<4>/*127:0*/ __Vtemp_387;
    VlWide<4>/*127:0*/ __Vtemp_399;
    VlWide<4>/*127:0*/ __Vtemp_400;
    VlWide<4>/*127:0*/ __Vtemp_405;
    VlWide<4>/*127:0*/ __Vtemp_408;
    VlWide<4>/*127:0*/ __Vtemp_409;
    VlWide<4>/*127:0*/ __Vtemp_414;
    VlWide<4>/*127:0*/ __Vtemp_417;
    VlWide<4>/*127:0*/ __Vtemp_418;
    VlWide<4>/*127:0*/ __Vtemp_423;
    VlWide<4>/*127:0*/ __Vtemp_447;
    VlWide<4>/*127:0*/ __Vtemp_450;
    VlWide<4>/*127:0*/ __Vtemp_452;
    VlWide<4>/*127:0*/ __Vtemp_464;
    VlWide<4>/*127:0*/ __Vtemp_465;
    VlWide<4>/*127:0*/ __Vtemp_470;
    VlWide<4>/*127:0*/ __Vtemp_473;
    VlWide<4>/*127:0*/ __Vtemp_474;
    VlWide<4>/*127:0*/ __Vtemp_479;
    VlWide<4>/*127:0*/ __Vtemp_482;
    VlWide<4>/*127:0*/ __Vtemp_483;
    VlWide<4>/*127:0*/ __Vtemp_488;
    VlWide<4>/*127:0*/ __Vtemp_512;
    VlWide<4>/*127:0*/ __Vtemp_515;
    VlWide<4>/*127:0*/ __Vtemp_517;
    // Body
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__a_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0U] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0U])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__b_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0U] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0U] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0U] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__c_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[1U] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[1U])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__d_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[1U] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[1U] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[1U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[1U] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__x_mant[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__x_mant[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__x_mant[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__x_mant[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x14U));
    __Vtemp_9[0U] = 0xffffffffU;
    __Vtemp_9[1U] = 0xffffffffU;
    __Vtemp_9[2U] = 0xffffffffU;
    __Vtemp_9[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_10, __Vtemp_9, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_mant_base[0U] 
                     & (~ __Vtemp_10[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_mant_base[1U] 
                                              & (~ 
                                                 __Vtemp_10[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_mant_base[2U] 
                      & (~ __Vtemp_10[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
                                                & (~ 
                                                   __Vtemp_10[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_15, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[0U] 
            = __Vtemp_15[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[1U] 
            = __Vtemp_15[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[2U] 
            = __Vtemp_15[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[3U] 
            = (0xfffffffU & __Vtemp_15[3U]);
    }
    __Vtemp_18[0U] = 0xffffffffU;
    __Vtemp_18[1U] = 0xffffffffU;
    __Vtemp_18[2U] = 0xffffffffU;
    __Vtemp_18[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_19, __Vtemp_18, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_mant_base[0U] 
                     & (~ __Vtemp_19[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_mant_base[1U] 
                                              & (~ 
                                                 __Vtemp_19[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_mant_base[2U] 
                      & (~ __Vtemp_19[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
                                                & (~ 
                                                   __Vtemp_19[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_24, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[0U] 
            = __Vtemp_24[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[1U] 
            = __Vtemp_24[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[2U] 
            = __Vtemp_24[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[3U] 
            = (0xfffffffU & __Vtemp_24[3U]);
    }
    __Vtemp_27[0U] = 0xffffffffU;
    __Vtemp_27[1U] = 0xffffffffU;
    __Vtemp_27[2U] = 0xffffffffU;
    __Vtemp_27[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_28, __Vtemp_27, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_mant_base[0U] 
                     & (~ __Vtemp_28[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_mant_base[1U] 
                                              & (~ 
                                                 __Vtemp_28[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_mant_base[2U] 
                      & (~ __Vtemp_28[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
                                                & (~ 
                                                   __Vtemp_28[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_33, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[0U] 
            = __Vtemp_33[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[1U] 
            = __Vtemp_33[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[2U] 
            = __Vtemp_33[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[3U] 
            = (0xfffffffU & __Vtemp_33[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[0U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__x_mant[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[1U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__x_mant[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[2U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__x_mant[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[3U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__x_mant[3U];
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[0U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[0U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[1U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[1U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[2U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[2U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[3U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[3U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[3U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c1[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[0U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[0U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[0U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c1[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[1U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[1U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[1U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c1[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[2U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[2U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[2U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c1[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[3U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[3U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[3U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_57, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s2[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[0U] 
            ^ __Vtemp_57[0U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s2[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[1U] 
            ^ __Vtemp_57[1U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s2[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[2U] 
            ^ __Vtemp_57[2U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s2[3U] 
        = (0x7fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[3U] 
                           ^ __Vtemp_57[3U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_60, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    VL_SHIFTL_WWI(127,127,32, __Vtemp_62, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c2[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[0U] 
             & __Vtemp_60[0U]) | (__Vtemp_62[0U] & 
                                  vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c2[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[1U] 
             & __Vtemp_60[1U]) | (__Vtemp_62[1U] & 
                                  vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c2[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[2U] 
             & __Vtemp_60[2U]) | (__Vtemp_62[2U] & 
                                  vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c2[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[3U] 
             & __Vtemp_60[3U]) | (__Vtemp_62[3U] & 
                                  vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[3U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__a_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[2U] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[2U])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__b_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[2U] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[2U] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[2U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[2U] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__c_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[3U] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[3U])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[3U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__d_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[3U] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[3U] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[3U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[3U] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__x_mant[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__x_mant[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__x_mant[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__x_mant[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x14U));
    __Vtemp_74[0U] = 0xffffffffU;
    __Vtemp_74[1U] = 0xffffffffU;
    __Vtemp_74[2U] = 0xffffffffU;
    __Vtemp_74[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_75, __Vtemp_74, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_mant_base[0U] 
                     & (~ __Vtemp_75[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_mant_base[1U] 
                                              & (~ 
                                                 __Vtemp_75[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_mant_base[2U] 
                      & (~ __Vtemp_75[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
                                                & (~ 
                                                   __Vtemp_75[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_80, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[0U] 
            = __Vtemp_80[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[1U] 
            = __Vtemp_80[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[2U] 
            = __Vtemp_80[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[3U] 
            = (0xfffffffU & __Vtemp_80[3U]);
    }
    __Vtemp_83[0U] = 0xffffffffU;
    __Vtemp_83[1U] = 0xffffffffU;
    __Vtemp_83[2U] = 0xffffffffU;
    __Vtemp_83[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_84, __Vtemp_83, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_mant_base[0U] 
                     & (~ __Vtemp_84[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_mant_base[1U] 
                                              & (~ 
                                                 __Vtemp_84[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_mant_base[2U] 
                      & (~ __Vtemp_84[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
                                                & (~ 
                                                   __Vtemp_84[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_89, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[0U] 
            = __Vtemp_89[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[1U] 
            = __Vtemp_89[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[2U] 
            = __Vtemp_89[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[3U] 
            = (0xfffffffU & __Vtemp_89[3U]);
    }
    __Vtemp_92[0U] = 0xffffffffU;
    __Vtemp_92[1U] = 0xffffffffU;
    __Vtemp_92[2U] = 0xffffffffU;
    __Vtemp_92[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_93, __Vtemp_92, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_mant_base[0U] 
                     & (~ __Vtemp_93[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_mant_base[1U] 
                                              & (~ 
                                                 __Vtemp_93[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_mant_base[2U] 
                      & (~ __Vtemp_93[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
                                                & (~ 
                                                   __Vtemp_93[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_98, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[0U] 
            = __Vtemp_98[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[1U] 
            = __Vtemp_98[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[2U] 
            = __Vtemp_98[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[3U] 
            = (0xfffffffU & __Vtemp_98[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[0U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__x_mant[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[1U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__x_mant[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[2U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__x_mant[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[3U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__x_mant[3U];
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[0U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[0U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[1U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[1U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[2U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[2U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[3U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[3U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[3U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c1[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[0U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[0U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[0U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c1[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[1U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[1U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[1U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c1[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[2U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[2U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[2U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c1[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[3U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[3U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[3U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_122, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s2[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[0U] 
            ^ __Vtemp_122[0U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s2[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[1U] 
            ^ __Vtemp_122[1U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s2[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[2U] 
            ^ __Vtemp_122[2U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s2[3U] 
        = (0x7fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[3U] 
                           ^ __Vtemp_122[3U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_125, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    VL_SHIFTL_WWI(127,127,32, __Vtemp_127, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c2[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[0U] 
             & __Vtemp_125[0U]) | (__Vtemp_127[0U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c2[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[1U] 
             & __Vtemp_125[1U]) | (__Vtemp_127[1U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c2[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[2U] 
             & __Vtemp_125[2U]) | (__Vtemp_127[2U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c2[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[3U] 
             & __Vtemp_125[3U]) | (__Vtemp_127[3U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[3U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__a_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[4U] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[4U])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[4U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__b_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[4U] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[4U] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[4U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[4U] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__c_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[5U] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[5U])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[5U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__d_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[5U] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[5U] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[5U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[5U] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__x_mant[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__x_mant[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__x_mant[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__x_mant[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x14U));
    __Vtemp_139[0U] = 0xffffffffU;
    __Vtemp_139[1U] = 0xffffffffU;
    __Vtemp_139[2U] = 0xffffffffU;
    __Vtemp_139[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_140, __Vtemp_139, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_mant_base[0U] 
                     & (~ __Vtemp_140[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_mant_base[1U] 
                                               & (~ 
                                                  __Vtemp_140[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_mant_base[2U] 
                      & (~ __Vtemp_140[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
                                                 & (~ 
                                                    __Vtemp_140[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_145, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[0U] 
            = __Vtemp_145[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[1U] 
            = __Vtemp_145[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[2U] 
            = __Vtemp_145[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[3U] 
            = (0xfffffffU & __Vtemp_145[3U]);
    }
    __Vtemp_148[0U] = 0xffffffffU;
    __Vtemp_148[1U] = 0xffffffffU;
    __Vtemp_148[2U] = 0xffffffffU;
    __Vtemp_148[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_149, __Vtemp_148, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_mant_base[0U] 
                     & (~ __Vtemp_149[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_mant_base[1U] 
                                               & (~ 
                                                  __Vtemp_149[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_mant_base[2U] 
                      & (~ __Vtemp_149[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
                                                 & (~ 
                                                    __Vtemp_149[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_154, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[0U] 
            = __Vtemp_154[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[1U] 
            = __Vtemp_154[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[2U] 
            = __Vtemp_154[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[3U] 
            = (0xfffffffU & __Vtemp_154[3U]);
    }
    __Vtemp_157[0U] = 0xffffffffU;
    __Vtemp_157[1U] = 0xffffffffU;
    __Vtemp_157[2U] = 0xffffffffU;
    __Vtemp_157[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_158, __Vtemp_157, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_mant_base[0U] 
                     & (~ __Vtemp_158[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_mant_base[1U] 
                                               & (~ 
                                                  __Vtemp_158[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_mant_base[2U] 
                      & (~ __Vtemp_158[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
                                                 & (~ 
                                                    __Vtemp_158[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_163, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[0U] 
            = __Vtemp_163[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[1U] 
            = __Vtemp_163[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[2U] 
            = __Vtemp_163[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[3U] 
            = (0xfffffffU & __Vtemp_163[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[0U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__x_mant[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[1U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__x_mant[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[2U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__x_mant[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[3U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__x_mant[3U];
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[0U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[0U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[1U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[1U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[2U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[2U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[3U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[3U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[3U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c1[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[0U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[0U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[0U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c1[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[1U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[1U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[1U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c1[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[2U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[2U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[2U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c1[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[3U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[3U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[3U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_187, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s2[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[0U] 
            ^ __Vtemp_187[0U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s2[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[1U] 
            ^ __Vtemp_187[1U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s2[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[2U] 
            ^ __Vtemp_187[2U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s2[3U] 
        = (0x7fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[3U] 
                           ^ __Vtemp_187[3U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_190, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    VL_SHIFTL_WWI(127,127,32, __Vtemp_192, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c2[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[0U] 
             & __Vtemp_190[0U]) | (__Vtemp_192[0U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c2[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[1U] 
             & __Vtemp_190[1U]) | (__Vtemp_192[1U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c2[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[2U] 
             & __Vtemp_190[2U]) | (__Vtemp_192[2U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c2[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[3U] 
             & __Vtemp_190[3U]) | (__Vtemp_192[3U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[3U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__a_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[6U] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[6U])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[6U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__b_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[6U] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[6U] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[6U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[6U] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__c_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[7U] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[7U])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[7U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__d_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[7U] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[7U] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[7U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[7U] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__x_mant[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__x_mant[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__x_mant[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__x_mant[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x14U));
    __Vtemp_204[0U] = 0xffffffffU;
    __Vtemp_204[1U] = 0xffffffffU;
    __Vtemp_204[2U] = 0xffffffffU;
    __Vtemp_204[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_205, __Vtemp_204, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_mant_base[0U] 
                     & (~ __Vtemp_205[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_mant_base[1U] 
                                               & (~ 
                                                  __Vtemp_205[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_mant_base[2U] 
                      & (~ __Vtemp_205[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
                                                 & (~ 
                                                    __Vtemp_205[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_210, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[0U] 
            = __Vtemp_210[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[1U] 
            = __Vtemp_210[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[2U] 
            = __Vtemp_210[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[3U] 
            = (0xfffffffU & __Vtemp_210[3U]);
    }
    __Vtemp_213[0U] = 0xffffffffU;
    __Vtemp_213[1U] = 0xffffffffU;
    __Vtemp_213[2U] = 0xffffffffU;
    __Vtemp_213[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_214, __Vtemp_213, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_mant_base[0U] 
                     & (~ __Vtemp_214[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_mant_base[1U] 
                                               & (~ 
                                                  __Vtemp_214[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_mant_base[2U] 
                      & (~ __Vtemp_214[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
                                                 & (~ 
                                                    __Vtemp_214[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_219, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[0U] 
            = __Vtemp_219[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[1U] 
            = __Vtemp_219[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[2U] 
            = __Vtemp_219[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[3U] 
            = (0xfffffffU & __Vtemp_219[3U]);
    }
    __Vtemp_222[0U] = 0xffffffffU;
    __Vtemp_222[1U] = 0xffffffffU;
    __Vtemp_222[2U] = 0xffffffffU;
    __Vtemp_222[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_223, __Vtemp_222, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_mant_base[0U] 
                     & (~ __Vtemp_223[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_mant_base[1U] 
                                               & (~ 
                                                  __Vtemp_223[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_mant_base[2U] 
                      & (~ __Vtemp_223[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
                                                 & (~ 
                                                    __Vtemp_223[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_228, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[0U] 
            = __Vtemp_228[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[1U] 
            = __Vtemp_228[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[2U] 
            = __Vtemp_228[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[3U] 
            = (0xfffffffU & __Vtemp_228[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[0U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__x_mant[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[1U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__x_mant[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[2U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__x_mant[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[3U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__x_mant[3U];
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[0U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[0U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[1U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[1U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[2U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[2U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[3U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[3U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[3U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c1[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[0U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[0U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[0U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c1[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[1U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[1U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[1U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c1[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[2U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[2U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[2U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c1[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[3U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[3U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[3U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_252, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s2[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[0U] 
            ^ __Vtemp_252[0U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s2[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[1U] 
            ^ __Vtemp_252[1U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s2[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[2U] 
            ^ __Vtemp_252[2U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s2[3U] 
        = (0x7fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[3U] 
                           ^ __Vtemp_252[3U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_255, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    VL_SHIFTL_WWI(127,127,32, __Vtemp_257, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c2[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[0U] 
             & __Vtemp_255[0U]) | (__Vtemp_257[0U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c2[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[1U] 
             & __Vtemp_255[1U]) | (__Vtemp_257[1U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c2[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[2U] 
             & __Vtemp_255[2U]) | (__Vtemp_257[2U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c2[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[3U] 
             & __Vtemp_255[3U]) | (__Vtemp_257[3U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[3U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__a_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[8U] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[8U])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[8U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__b_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[8U] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[8U] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[8U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[8U] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__c_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[9U] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[9U])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[9U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__d_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[9U] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[9U] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[9U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[9U] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__x_mant[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__x_mant[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__x_mant[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__x_mant[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x14U));
    __Vtemp_269[0U] = 0xffffffffU;
    __Vtemp_269[1U] = 0xffffffffU;
    __Vtemp_269[2U] = 0xffffffffU;
    __Vtemp_269[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_270, __Vtemp_269, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_mant_base[0U] 
                     & (~ __Vtemp_270[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_mant_base[1U] 
                                               & (~ 
                                                  __Vtemp_270[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_mant_base[2U] 
                      & (~ __Vtemp_270[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
                                                 & (~ 
                                                    __Vtemp_270[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_275, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[0U] 
            = __Vtemp_275[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[1U] 
            = __Vtemp_275[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[2U] 
            = __Vtemp_275[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[3U] 
            = (0xfffffffU & __Vtemp_275[3U]);
    }
    __Vtemp_278[0U] = 0xffffffffU;
    __Vtemp_278[1U] = 0xffffffffU;
    __Vtemp_278[2U] = 0xffffffffU;
    __Vtemp_278[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_279, __Vtemp_278, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_mant_base[0U] 
                     & (~ __Vtemp_279[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_mant_base[1U] 
                                               & (~ 
                                                  __Vtemp_279[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_mant_base[2U] 
                      & (~ __Vtemp_279[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
                                                 & (~ 
                                                    __Vtemp_279[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_284, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[0U] 
            = __Vtemp_284[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[1U] 
            = __Vtemp_284[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[2U] 
            = __Vtemp_284[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[3U] 
            = (0xfffffffU & __Vtemp_284[3U]);
    }
    __Vtemp_287[0U] = 0xffffffffU;
    __Vtemp_287[1U] = 0xffffffffU;
    __Vtemp_287[2U] = 0xffffffffU;
    __Vtemp_287[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_288, __Vtemp_287, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_mant_base[0U] 
                     & (~ __Vtemp_288[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_mant_base[1U] 
                                               & (~ 
                                                  __Vtemp_288[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_mant_base[2U] 
                      & (~ __Vtemp_288[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
                                                 & (~ 
                                                    __Vtemp_288[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_293, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[0U] 
            = __Vtemp_293[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[1U] 
            = __Vtemp_293[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[2U] 
            = __Vtemp_293[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[3U] 
            = (0xfffffffU & __Vtemp_293[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[0U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__x_mant[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[1U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__x_mant[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[2U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__x_mant[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[3U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__x_mant[3U];
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[0U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[0U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[1U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[1U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[2U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[2U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[3U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[3U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[3U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c1[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[0U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[0U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[0U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c1[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[1U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[1U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[1U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c1[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[2U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[2U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[2U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c1[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[3U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[3U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[3U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_317, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s2[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[0U] 
            ^ __Vtemp_317[0U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s2[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[1U] 
            ^ __Vtemp_317[1U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s2[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[2U] 
            ^ __Vtemp_317[2U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s2[3U] 
        = (0x7fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[3U] 
                           ^ __Vtemp_317[3U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_320, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    VL_SHIFTL_WWI(127,127,32, __Vtemp_322, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c2[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[0U] 
             & __Vtemp_320[0U]) | (__Vtemp_322[0U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c2[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[1U] 
             & __Vtemp_320[1U]) | (__Vtemp_322[1U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c2[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[2U] 
             & __Vtemp_320[2U]) | (__Vtemp_322[2U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c2[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[3U] 
             & __Vtemp_320[3U]) | (__Vtemp_322[3U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[3U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__a_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xaU] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xaU])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xaU]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__b_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xaU] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xaU] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xaU] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xaU] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__c_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xbU] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xbU])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xbU]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__d_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xbU] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xbU] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xbU] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xbU] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__x_mant[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__x_mant[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__x_mant[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__x_mant[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x14U));
    __Vtemp_334[0U] = 0xffffffffU;
    __Vtemp_334[1U] = 0xffffffffU;
    __Vtemp_334[2U] = 0xffffffffU;
    __Vtemp_334[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_335, __Vtemp_334, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_mant_base[0U] 
                     & (~ __Vtemp_335[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_mant_base[1U] 
                                               & (~ 
                                                  __Vtemp_335[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_mant_base[2U] 
                      & (~ __Vtemp_335[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
                                                 & (~ 
                                                    __Vtemp_335[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_340, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[0U] 
            = __Vtemp_340[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[1U] 
            = __Vtemp_340[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[2U] 
            = __Vtemp_340[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[3U] 
            = (0xfffffffU & __Vtemp_340[3U]);
    }
    __Vtemp_343[0U] = 0xffffffffU;
    __Vtemp_343[1U] = 0xffffffffU;
    __Vtemp_343[2U] = 0xffffffffU;
    __Vtemp_343[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_344, __Vtemp_343, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_mant_base[0U] 
                     & (~ __Vtemp_344[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_mant_base[1U] 
                                               & (~ 
                                                  __Vtemp_344[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_mant_base[2U] 
                      & (~ __Vtemp_344[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
                                                 & (~ 
                                                    __Vtemp_344[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_349, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[0U] 
            = __Vtemp_349[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[1U] 
            = __Vtemp_349[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[2U] 
            = __Vtemp_349[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[3U] 
            = (0xfffffffU & __Vtemp_349[3U]);
    }
    __Vtemp_352[0U] = 0xffffffffU;
    __Vtemp_352[1U] = 0xffffffffU;
    __Vtemp_352[2U] = 0xffffffffU;
    __Vtemp_352[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_353, __Vtemp_352, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_mant_base[0U] 
                     & (~ __Vtemp_353[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_mant_base[1U] 
                                               & (~ 
                                                  __Vtemp_353[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_mant_base[2U] 
                      & (~ __Vtemp_353[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
                                                 & (~ 
                                                    __Vtemp_353[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_358, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[0U] 
            = __Vtemp_358[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[1U] 
            = __Vtemp_358[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[2U] 
            = __Vtemp_358[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[3U] 
            = (0xfffffffU & __Vtemp_358[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[0U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__x_mant[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[1U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__x_mant[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[2U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__x_mant[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[3U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__x_mant[3U];
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[0U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[0U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[1U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[1U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[2U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[2U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[3U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[3U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[3U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c1[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[0U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[0U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[0U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c1[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[1U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[1U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[1U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c1[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[2U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[2U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[2U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c1[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[3U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[3U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[3U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_382, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s2[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[0U] 
            ^ __Vtemp_382[0U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s2[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[1U] 
            ^ __Vtemp_382[1U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s2[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[2U] 
            ^ __Vtemp_382[2U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s2[3U] 
        = (0x7fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[3U] 
                           ^ __Vtemp_382[3U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_385, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    VL_SHIFTL_WWI(127,127,32, __Vtemp_387, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c2[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[0U] 
             & __Vtemp_385[0U]) | (__Vtemp_387[0U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c2[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[1U] 
             & __Vtemp_385[1U]) | (__Vtemp_387[1U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c2[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[2U] 
             & __Vtemp_385[2U]) | (__Vtemp_387[2U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c2[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[3U] 
             & __Vtemp_385[3U]) | (__Vtemp_387[3U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[3U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__a_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xcU] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xcU])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xcU]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__b_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xcU] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xcU] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xcU] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xcU] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__c_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xdU] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xdU])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xdU]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__d_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xdU] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xdU] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xdU] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xdU] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__x_mant[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__x_mant[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__x_mant[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__x_mant[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x14U));
    __Vtemp_399[0U] = 0xffffffffU;
    __Vtemp_399[1U] = 0xffffffffU;
    __Vtemp_399[2U] = 0xffffffffU;
    __Vtemp_399[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_400, __Vtemp_399, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_mant_base[0U] 
                     & (~ __Vtemp_400[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_mant_base[1U] 
                                               & (~ 
                                                  __Vtemp_400[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_mant_base[2U] 
                      & (~ __Vtemp_400[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
                                                 & (~ 
                                                    __Vtemp_400[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_405, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[0U] 
            = __Vtemp_405[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[1U] 
            = __Vtemp_405[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[2U] 
            = __Vtemp_405[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[3U] 
            = (0xfffffffU & __Vtemp_405[3U]);
    }
    __Vtemp_408[0U] = 0xffffffffU;
    __Vtemp_408[1U] = 0xffffffffU;
    __Vtemp_408[2U] = 0xffffffffU;
    __Vtemp_408[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_409, __Vtemp_408, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_mant_base[0U] 
                     & (~ __Vtemp_409[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_mant_base[1U] 
                                               & (~ 
                                                  __Vtemp_409[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_mant_base[2U] 
                      & (~ __Vtemp_409[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
                                                 & (~ 
                                                    __Vtemp_409[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_414, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[0U] 
            = __Vtemp_414[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[1U] 
            = __Vtemp_414[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[2U] 
            = __Vtemp_414[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[3U] 
            = (0xfffffffU & __Vtemp_414[3U]);
    }
    __Vtemp_417[0U] = 0xffffffffU;
    __Vtemp_417[1U] = 0xffffffffU;
    __Vtemp_417[2U] = 0xffffffffU;
    __Vtemp_417[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_418, __Vtemp_417, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_mant_base[0U] 
                     & (~ __Vtemp_418[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_mant_base[1U] 
                                               & (~ 
                                                  __Vtemp_418[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_mant_base[2U] 
                      & (~ __Vtemp_418[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
                                                 & (~ 
                                                    __Vtemp_418[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_423, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[0U] 
            = __Vtemp_423[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[1U] 
            = __Vtemp_423[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[2U] 
            = __Vtemp_423[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[3U] 
            = (0xfffffffU & __Vtemp_423[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[0U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__x_mant[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[1U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__x_mant[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[2U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__x_mant[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[3U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__x_mant[3U];
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[0U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[0U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[1U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[1U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[2U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[2U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[3U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[3U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[3U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c1[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[0U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[0U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[0U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c1[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[1U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[1U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[1U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c1[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[2U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[2U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[2U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c1[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[3U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[3U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[3U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_447, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s2[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[0U] 
            ^ __Vtemp_447[0U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s2[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[1U] 
            ^ __Vtemp_447[1U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s2[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[2U] 
            ^ __Vtemp_447[2U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s2[3U] 
        = (0x7fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[3U] 
                           ^ __Vtemp_447[3U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_450, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    VL_SHIFTL_WWI(127,127,32, __Vtemp_452, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c2[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[0U] 
             & __Vtemp_450[0U]) | (__Vtemp_452[0U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c2[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[1U] 
             & __Vtemp_450[1U]) | (__Vtemp_452[1U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c2[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[2U] 
             & __Vtemp_450[2U]) | (__Vtemp_452[2U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c2[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[3U] 
             & __Vtemp_450[3U]) | (__Vtemp_452[3U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[3U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__a_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xeU] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xeU])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xeU]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__b_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xeU] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xeU] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xeU] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xeU] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__c_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xfU] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xfU])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xfU]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__d_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xfU] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xfU] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xfU] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xfU] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__x_mant[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__x_mant[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__x_mant[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__x_mant[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x14U));
    __Vtemp_464[0U] = 0xffffffffU;
    __Vtemp_464[1U] = 0xffffffffU;
    __Vtemp_464[2U] = 0xffffffffU;
    __Vtemp_464[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_465, __Vtemp_464, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_mant_base[0U] 
                     & (~ __Vtemp_465[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_mant_base[1U] 
                                               & (~ 
                                                  __Vtemp_465[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_mant_base[2U] 
                      & (~ __Vtemp_465[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
                                                 & (~ 
                                                    __Vtemp_465[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_470, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[0U] 
            = __Vtemp_470[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[1U] 
            = __Vtemp_470[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[2U] 
            = __Vtemp_470[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[3U] 
            = (0xfffffffU & __Vtemp_470[3U]);
    }
    __Vtemp_473[0U] = 0xffffffffU;
    __Vtemp_473[1U] = 0xffffffffU;
    __Vtemp_473[2U] = 0xffffffffU;
    __Vtemp_473[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_474, __Vtemp_473, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_mant_base[0U] 
                     & (~ __Vtemp_474[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_mant_base[1U] 
                                               & (~ 
                                                  __Vtemp_474[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_mant_base[2U] 
                      & (~ __Vtemp_474[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
                                                 & (~ 
                                                    __Vtemp_474[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_479, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[0U] 
            = __Vtemp_479[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[1U] 
            = __Vtemp_479[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[2U] 
            = __Vtemp_479[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[3U] 
            = (0xfffffffU & __Vtemp_479[3U]);
    }
    __Vtemp_482[0U] = 0xffffffffU;
    __Vtemp_482[1U] = 0xffffffffU;
    __Vtemp_482[2U] = 0xffffffffU;
    __Vtemp_482[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_483, __Vtemp_482, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_mant_base[0U] 
                     & (~ __Vtemp_483[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_mant_base[1U] 
                                               & (~ 
                                                  __Vtemp_483[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_mant_base[2U] 
                      & (~ __Vtemp_483[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
                                                 & (~ 
                                                    __Vtemp_483[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_488, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[0U] 
            = __Vtemp_488[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[1U] 
            = __Vtemp_488[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[2U] 
            = __Vtemp_488[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[3U] 
            = (0xfffffffU & __Vtemp_488[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[0U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__x_mant[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[1U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__x_mant[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[2U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__x_mant[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[3U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__x_mant[3U];
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[0U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[0U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[1U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[1U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[2U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[2U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[3U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[3U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[3U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c1[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[0U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[0U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[0U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c1[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[1U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[1U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[1U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c1[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[2U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[2U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[2U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c1[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[3U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[3U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[3U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_512, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s2[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[0U] 
            ^ __Vtemp_512[0U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s2[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[1U] 
            ^ __Vtemp_512[1U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s2[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[2U] 
            ^ __Vtemp_512[2U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s2[3U] 
        = (0x7fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[3U] 
                           ^ __Vtemp_512[3U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_515, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    VL_SHIFTL_WWI(127,127,32, __Vtemp_517, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c2[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[0U] 
             & __Vtemp_515[0U]) | (__Vtemp_517[0U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c2[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[1U] 
             & __Vtemp_515[1U]) | (__Vtemp_517[1U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c2[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[2U] 
             & __Vtemp_515[2U]) | (__Vtemp_517[2U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c2[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[3U] 
             & __Vtemp_515[3U]) | (__Vtemp_517[3U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[3U]));
}

void Vadd32_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);
void Vadd32_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__1(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);
void Vadd32_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__2(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);

void Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_nba(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_nba\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
        Vadd32_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__0(vlSelf);
        Vadd32_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__1(vlSelf);
        Vadd32_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((5ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[6U] = 1U;
    }
}

void Vadd32_fp32accum_bf16_tb_softfloat___024root___timing_resume(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___timing_resume\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_he33aaeef__0.resume(
                                                   "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_he33aaeae__0.resume(
                                                   "@(negedge add32_fp32accum_bf16_tb_softfloat.tb_clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vadd32_fp32accum_bf16_tb_softfloat___024root___timing_commit(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___timing_commit\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_he33aaeef__0.commit(
                                                   "@(posedge add32_fp32accum_bf16_tb_softfloat.tb_clk)");
    }
    if ((! (8ULL & vlSelfRef.__VactTriggered.word(0U)))) {
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
    VlTriggerVec<4> __VpreTriggered;
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
            VL_FATAL_MT("tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 4, "", "NBA region did not converge.");
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
                VL_FATAL_MT("tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 4, "", "Active region did not converge.");
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

std::string VL_TO_STRING(const Vadd32_fp32accum_bf16_tb_softfloat_add32_fp32accum_bf16_tb_softfloat__DOT__scoreboard_entry_t__struct__0& obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root::VL_TO_STRING\n"); );
    // Body
    std::string out;
    out += "'{inputs:" + VL_TO_STRING(obj.__PVT__inputs);
        out += ", expected:" + VL_TO_STRING(obj.__PVT__expected);
        out += ", id:" + VL_TO_STRING(obj.__PVT__id);
        out += "}";
    return out;
}
