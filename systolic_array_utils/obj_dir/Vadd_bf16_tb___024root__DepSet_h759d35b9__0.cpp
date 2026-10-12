// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd_bf16_tb.h for the primary calling header

#include "Vadd_bf16_tb__pch.h"
#include "Vadd_bf16_tb__Syms.h"
#include "Vadd_bf16_tb___024root.h"

extern const VlWide<12>/*383:0*/ Vadd_bf16_tb__ConstPool__CONST_hfc1f2f8f_0;

VL_INLINE_OPT VlCoroutine Vadd_bf16_tb___024root___eval_initial__TOP__Vtiming__0(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h707c10c3__0;
    add_bf16_tb__DOT____Vlvbound_h707c10c3__0 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_ha6d72a1a__0;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__0 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h6b815d42__0;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__0 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h707c10c3__1;
    add_bf16_tb__DOT____Vlvbound_h707c10c3__1 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_ha6d72a1a__1;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__1 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h6b815d42__1;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__1 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h707c10c3__2;
    add_bf16_tb__DOT____Vlvbound_h707c10c3__2 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_ha6d72a1a__2;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__2 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h6b815d42__2;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__2 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h707c10c3__3;
    add_bf16_tb__DOT____Vlvbound_h707c10c3__3 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_ha6d72a1a__3;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__3 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h6b815d42__3;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__3 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h707c10c3__4;
    add_bf16_tb__DOT____Vlvbound_h707c10c3__4 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_ha6d72a1a__4;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__4 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h6b815d42__4;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__4 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h707c10c3__5;
    add_bf16_tb__DOT____Vlvbound_h707c10c3__5 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_ha6d72a1a__5;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__5 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h6b815d42__5;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__5 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h707c10c3__6;
    add_bf16_tb__DOT____Vlvbound_h707c10c3__6 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_ha6d72a1a__6;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__6 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h6b815d42__6;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__6 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h707c10c3__7;
    add_bf16_tb__DOT____Vlvbound_h707c10c3__7 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_ha6d72a1a__7;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__7 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h6b815d42__7;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__7 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h707c10c3__8;
    add_bf16_tb__DOT____Vlvbound_h707c10c3__8 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_ha6d72a1a__8;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__8 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h6b815d42__8;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__8 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h707c10c3__9;
    add_bf16_tb__DOT____Vlvbound_h707c10c3__9 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_ha6d72a1a__9;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__9 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h6b815d42__9;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__9 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h707c10c3__10;
    add_bf16_tb__DOT____Vlvbound_h707c10c3__10 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_ha6d72a1a__10;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__10 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h6b815d42__10;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__10 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h707c10c3__11;
    add_bf16_tb__DOT____Vlvbound_h707c10c3__11 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_ha6d72a1a__11;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__11 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h6b815d42__11;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__11 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h707c10c3__12;
    add_bf16_tb__DOT____Vlvbound_h707c10c3__12 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_ha6d72a1a__12;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__12 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h6b815d42__12;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__12 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h707c10c3__13;
    add_bf16_tb__DOT____Vlvbound_h707c10c3__13 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_ha6d72a1a__13;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__13 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h6b815d42__13;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__13 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h707c10c3__14;
    add_bf16_tb__DOT____Vlvbound_h707c10c3__14 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_ha6d72a1a__14;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__14 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h6b815d42__14;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__14 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h707c10c3__15;
    add_bf16_tb__DOT____Vlvbound_h707c10c3__15 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_ha6d72a1a__15;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__15 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h6b815d42__15;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__15 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h707c10c3__16;
    add_bf16_tb__DOT____Vlvbound_h707c10c3__16 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_ha6d72a1a__16;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__16 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h6b815d42__16;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__16 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h707c10c3__17;
    add_bf16_tb__DOT____Vlvbound_h707c10c3__17 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_ha6d72a1a__17;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__17 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h6b815d42__17;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__17 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h707c10c3__18;
    add_bf16_tb__DOT____Vlvbound_h707c10c3__18 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_ha6d72a1a__18;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__18 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h6b815d42__18;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__18 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h707c10c3__19;
    add_bf16_tb__DOT____Vlvbound_h707c10c3__19 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_ha6d72a1a__19;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__19 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h6b815d42__19;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__19 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h707c10c3__20;
    add_bf16_tb__DOT____Vlvbound_h707c10c3__20 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_ha6d72a1a__20;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__20 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h6b815d42__20;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__20 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h707c10c3__21;
    add_bf16_tb__DOT____Vlvbound_h707c10c3__21 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_ha6d72a1a__21;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__21 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h6b815d42__21;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__21 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h707c10c3__22;
    add_bf16_tb__DOT____Vlvbound_h707c10c3__22 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_ha6d72a1a__22;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__22 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h6b815d42__22;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__22 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h707c10c3__23;
    add_bf16_tb__DOT____Vlvbound_h707c10c3__23 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_ha6d72a1a__23;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__23 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h6b815d42__23;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__23 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h707c10c3__24;
    add_bf16_tb__DOT____Vlvbound_h707c10c3__24 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_ha6d72a1a__24;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__24 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h6b815d42__24;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__24 = 0;
    // Body
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(12, Vadd_bf16_tb__ConstPool__CONST_hfc1f2f8f_0));
    vlSymsp->_traceDumpOpen();
    vlSelfRef.add_bf16_tb__DOT__tb_nrst = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "add_bf16_tb.sv", 
                                         69);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_bf16_tb__DOT__tb_nrst = 1U;
    add_bf16_tb__DOT____Vlvbound_h707c10c3__0 = 0x3fc0U;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__0 = 0x4020U;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__0 = 0x4080U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__test_set1[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h707c10c3__0;
        vlSelfRef.add_bf16_tb__DOT__test_set2[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_ha6d72a1a__0;
        vlSelfRef.add_bf16_tb__DOT__expected_out[(0x1fU 
                                                  & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h6b815d42__0;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_h707c10c3__1 = 0x4200U;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__1 = 0x3f00U;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__1 = 0x4202U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__test_set1[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h707c10c3__1;
        vlSelfRef.add_bf16_tb__DOT__test_set2[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_ha6d72a1a__1;
        vlSelfRef.add_bf16_tb__DOT__expected_out[(0x1fU 
                                                  & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h6b815d42__1;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_h707c10c3__2 = 0x4100U;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__2 = 0x4100U;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__2 = 0x4180U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__test_set1[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h707c10c3__2;
        vlSelfRef.add_bf16_tb__DOT__test_set2[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_ha6d72a1a__2;
        vlSelfRef.add_bf16_tb__DOT__expected_out[(0x1fU 
                                                  & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h6b815d42__2;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_h707c10c3__3 = 0x4480U;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__3 = 0x4100U;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__3 = 0x4481U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__test_set1[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h707c10c3__3;
        vlSelfRef.add_bf16_tb__DOT__test_set2[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_ha6d72a1a__3;
        vlSelfRef.add_bf16_tb__DOT__expected_out[(0x1fU 
                                                  & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h6b815d42__3;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_h707c10c3__4 = 0U;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__4 = 0U;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__4 = 0U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__test_set1[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h707c10c3__4;
        vlSelfRef.add_bf16_tb__DOT__test_set2[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_ha6d72a1a__4;
        vlSelfRef.add_bf16_tb__DOT__expected_out[(0x1fU 
                                                  & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h6b815d42__4;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_h707c10c3__5 = 0x8000U;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__5 = 0U;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__5 = 0U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__test_set1[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h707c10c3__5;
        vlSelfRef.add_bf16_tb__DOT__test_set2[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_ha6d72a1a__5;
        vlSelfRef.add_bf16_tb__DOT__expected_out[(0x1fU 
                                                  & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h6b815d42__5;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_h707c10c3__6 = 0x8000U;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__6 = 0x8000U;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__6 = 0x8000U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__test_set1[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h707c10c3__6;
        vlSelfRef.add_bf16_tb__DOT__test_set2[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_ha6d72a1a__6;
        vlSelfRef.add_bf16_tb__DOT__expected_out[(0x1fU 
                                                  & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h6b815d42__6;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_h707c10c3__7 = 0U;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__7 = 0x4100U;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__7 = 0x4100U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__test_set1[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h707c10c3__7;
        vlSelfRef.add_bf16_tb__DOT__test_set2[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_ha6d72a1a__7;
        vlSelfRef.add_bf16_tb__DOT__expected_out[(0x1fU 
                                                  & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h6b815d42__7;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_h707c10c3__8 = 0x7f80U;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__8 = 0x4080U;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__8 = 0x7f80U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__test_set1[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h707c10c3__8;
        vlSelfRef.add_bf16_tb__DOT__test_set2[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_ha6d72a1a__8;
        vlSelfRef.add_bf16_tb__DOT__expected_out[(0x1fU 
                                                  & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h6b815d42__8;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_h707c10c3__9 = 0x7f80U;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__9 = 0xff80U;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__9 = 0x7fc0U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__test_set1[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h707c10c3__9;
        vlSelfRef.add_bf16_tb__DOT__test_set2[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_ha6d72a1a__9;
        vlSelfRef.add_bf16_tb__DOT__expected_out[(0x1fU 
                                                  & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h6b815d42__9;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_h707c10c3__10 = 0xff80U;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__10 = 0x4080U;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__10 = 0xff80U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__test_set1[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h707c10c3__10;
        vlSelfRef.add_bf16_tb__DOT__test_set2[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_ha6d72a1a__10;
        vlSelfRef.add_bf16_tb__DOT__expected_out[(0x1fU 
                                                  & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h6b815d42__10;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_h707c10c3__11 = 0xff80U;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__11 = 0xff80U;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__11 = 0xff80U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__test_set1[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h707c10c3__11;
        vlSelfRef.add_bf16_tb__DOT__test_set2[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_ha6d72a1a__11;
        vlSelfRef.add_bf16_tb__DOT__expected_out[(0x1fU 
                                                  & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h6b815d42__11;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_h707c10c3__12 = 0x7f80U;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__12 = 0x7f80U;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__12 = 0x7f80U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__test_set1[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h707c10c3__12;
        vlSelfRef.add_bf16_tb__DOT__test_set2[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_ha6d72a1a__12;
        vlSelfRef.add_bf16_tb__DOT__expected_out[(0x1fU 
                                                  & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h6b815d42__12;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_h707c10c3__13 = 0x7fc0U;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__13 = 0x3f80U;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__13 = 0x7fc0U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__test_set1[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h707c10c3__13;
        vlSelfRef.add_bf16_tb__DOT__test_set2[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_ha6d72a1a__13;
        vlSelfRef.add_bf16_tb__DOT__expected_out[(0x1fU 
                                                  & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h6b815d42__13;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_h707c10c3__14 = 0x7fc0U;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__14 = 0x7fc0U;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__14 = 0x7fc0U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__test_set1[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h707c10c3__14;
        vlSelfRef.add_bf16_tb__DOT__test_set2[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_ha6d72a1a__14;
        vlSelfRef.add_bf16_tb__DOT__expected_out[(0x1fU 
                                                  & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h6b815d42__14;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_h707c10c3__15 = 0x7f7fU;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__15 = 0x7f00U;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__15 = 0x7f80U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__test_set1[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h707c10c3__15;
        vlSelfRef.add_bf16_tb__DOT__test_set2[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_ha6d72a1a__15;
        vlSelfRef.add_bf16_tb__DOT__expected_out[(0x1fU 
                                                  & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h6b815d42__15;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_h707c10c3__16 = 0xff7fU;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__16 = 0xff7fU;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__16 = 0xff80U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__test_set1[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h707c10c3__16;
        vlSelfRef.add_bf16_tb__DOT__test_set2[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_ha6d72a1a__16;
        vlSelfRef.add_bf16_tb__DOT__expected_out[(0x1fU 
                                                  & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h6b815d42__16;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_h707c10c3__17 = 0x80U;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__17 = 0x80U;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__17 = 0x100U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__test_set1[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h707c10c3__17;
        vlSelfRef.add_bf16_tb__DOT__test_set2[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_ha6d72a1a__17;
        vlSelfRef.add_bf16_tb__DOT__expected_out[(0x1fU 
                                                  & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h6b815d42__17;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_h707c10c3__18 = 1U;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__18 = 1U;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__18 = 0U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__test_set1[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h707c10c3__18;
        vlSelfRef.add_bf16_tb__DOT__test_set2[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_ha6d72a1a__18;
        vlSelfRef.add_bf16_tb__DOT__expected_out[(0x1fU 
                                                  & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h6b815d42__18;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_h707c10c3__19 = 0x81U;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__19 = 0x8080U;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__19 = 0U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__test_set1[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h707c10c3__19;
        vlSelfRef.add_bf16_tb__DOT__test_set2[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_ha6d72a1a__19;
        vlSelfRef.add_bf16_tb__DOT__expected_out[(0x1fU 
                                                  & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h6b815d42__19;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_h707c10c3__20 = 0x7000U;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__20 = 0x3000U;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__20 = 0x7000U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__test_set1[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h707c10c3__20;
        vlSelfRef.add_bf16_tb__DOT__test_set2[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_ha6d72a1a__20;
        vlSelfRef.add_bf16_tb__DOT__expected_out[(0x1fU 
                                                  & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h6b815d42__20;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_h707c10c3__21 = 0x5a00U;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__21 = 1U;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__21 = 0x5a00U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__test_set1[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h707c10c3__21;
        vlSelfRef.add_bf16_tb__DOT__test_set2[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_ha6d72a1a__21;
        vlSelfRef.add_bf16_tb__DOT__expected_out[(0x1fU 
                                                  & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h6b815d42__21;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_h707c10c3__22 = 0x4000U;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__22 = 0xc000U;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__22 = 0U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__test_set1[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h707c10c3__22;
        vlSelfRef.add_bf16_tb__DOT__test_set2[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_ha6d72a1a__22;
        vlSelfRef.add_bf16_tb__DOT__expected_out[(0x1fU 
                                                  & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h6b815d42__22;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_h707c10c3__23 = 0x4200U;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__23 = 0xc1fcU;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__23 = 0x3f00U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__test_set1[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h707c10c3__23;
        vlSelfRef.add_bf16_tb__DOT__test_set2[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_ha6d72a1a__23;
        vlSelfRef.add_bf16_tb__DOT__expected_out[(0x1fU 
                                                  & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h6b815d42__23;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_h707c10c3__24 = 0xc000U;
    add_bf16_tb__DOT____Vlvbound_ha6d72a1a__24 = 0x3f80U;
    add_bf16_tb__DOT____Vlvbound_h6b815d42__24 = 0xbf80U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__test_set1[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h707c10c3__24;
        vlSelfRef.add_bf16_tb__DOT__test_set2[(0x1fU 
                                               & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_ha6d72a1a__24;
        vlSelfRef.add_bf16_tb__DOT__expected_out[(0x1fU 
                                                  & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h6b815d42__24;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    co_await vlSelfRef.__VtrigSched_hf547eadd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add_bf16_tb.tb_clk)", 
                                                         "add_bf16_tb.sv", 
                                                         374);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_bf16_tb__DOT__tb_start = 0U;
    vlSelfRef.add_bf16_tb__DOT__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.add_bf16_tb__DOT__i, vlSelfRef.add_bf16_tb__DOT__idx)) {
        co_await vlSelfRef.__VtrigSched_hf547eadd__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge add_bf16_tb.tb_clk)", 
                                                             "add_bf16_tb.sv", 
                                                             379);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSelfRef.add_bf16_tb__DOT__tb_start = 0U;
        if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__i))) {
            vlSelfRef.add_bf16_tb__DOT__tb_a = vlSelfRef.add_bf16_tb__DOT__test_set1
                [(0x1fU & vlSelfRef.add_bf16_tb__DOT__i)];
            vlSelfRef.add_bf16_tb__DOT__tb_b = vlSelfRef.add_bf16_tb__DOT__test_set2
                [(0x1fU & vlSelfRef.add_bf16_tb__DOT__i)];
        } else {
            vlSelfRef.add_bf16_tb__DOT__tb_a = 0U;
            vlSelfRef.add_bf16_tb__DOT__tb_b = 0U;
        }
        vlSelfRef.add_bf16_tb__DOT__tb_start = 1U;
        co_await vlSelfRef.__VtrigSched_hf547eadd__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge add_bf16_tb.tb_clk)", 
                                                             "add_bf16_tb.sv", 
                                                             384);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSelfRef.add_bf16_tb__DOT__tb_start = 0U;
        co_await vlSelfRef.__VtrigSched_hf547eadd__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge add_bf16_tb.tb_clk)", 
                                                             "add_bf16_tb.sv", 
                                                             386);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        VL_WRITEF_NX("========================================\nTest Case %0d:\nInput A:       %x\nInput B:       %x\nExpected Out:  %x\nActual Result: %x\nMatch: %s\nFlags - Overflow: %b, Underflow: %b, Invalid: %b\n========================================\n",0,
                     32,vlSelfRef.add_bf16_tb__DOT__i,
                     16,(IData)(vlSelfRef.add_bf16_tb__DOT__tb_a),
                     16,vlSelfRef.add_bf16_tb__DOT__tb_b,
                     16,((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__i))
                          ? vlSelfRef.add_bf16_tb__DOT__expected_out
                         [(0x1fU & vlSelfRef.add_bf16_tb__DOT__i)]
                          : 0U),16,(((IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__result_sign) 
                                     << 0xfU) | (((IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__exp_out_adj) 
                                                  << 7U) 
                                                 | (IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__rounded_fraction))),
                     32,(((((IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__result_sign) 
                            << 0xfU) | (((IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__exp_out_adj) 
                                         << 7U) | (IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__rounded_fraction))) 
                          == ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__i))
                               ? vlSelfRef.add_bf16_tb__DOT__expected_out
                              [(0x1fU & vlSelfRef.add_bf16_tb__DOT__i)]
                               : 0U)) ? 0x50415353U
                          : 0x4641494cU),1,((0xffU 
                                             == (IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__exp_max_l)) 
                                            | ((IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__mantissa_overflow) 
                                               & (0xfeU 
                                                  == (IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__exp_max_l)))),
                     1,((0U == (0xffU & (IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__u_result))) 
                        | ((~ ((IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__u_result) 
                               >> 7U)) & (0U != (3U 
                                                 & ((IData)(vlSelfRef.add_bf16_tb__DOT__bob__DOT__u_result) 
                                                    >> 6U))))),
                     1,(IData)(vlSelfRef.add_bf16_tb__DOT__tb_invalid));
        vlSelfRef.add_bf16_tb__DOT__i = ((IData)(1U) 
                                         + vlSelfRef.add_bf16_tb__DOT__i);
    }
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "add_bf16_tb.sv", 
                                         406);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_FINISH_MT("add_bf16_tb.sv", 407, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_bf16_tb___024root___dump_triggers__act(Vadd_bf16_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vadd_bf16_tb___024root___eval_triggers__act(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___eval_triggers__act\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.add_bf16_tb__DOT__tb_clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__add_bf16_tb__DOT__tb_clk__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.add_bf16_tb__DOT__tb_nrst)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__add_bf16_tb__DOT__tb_nrst__0)));
    vlSelfRef.__VactTriggered.setBit(2U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__add_bf16_tb__DOT__tb_clk__0 
        = vlSelfRef.add_bf16_tb__DOT__tb_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__add_bf16_tb__DOT__tb_nrst__0 
        = vlSelfRef.add_bf16_tb__DOT__tb_nrst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vadd_bf16_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}
