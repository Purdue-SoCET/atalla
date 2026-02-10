// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd4_fp16_tb_full.h for the primary calling header

#include "Vadd4_fp16_tb_full__pch.h"
#include "Vadd4_fp16_tb_full___024root.h"

VlCoroutine Vadd4_fp16_tb_full___024root___eval_initial__TOP__Vtiming__0(Vadd4_fp16_tb_full___024root* vlSelf);
VlCoroutine Vadd4_fp16_tb_full___024root___eval_initial__TOP__Vtiming__1(Vadd4_fp16_tb_full___024root* vlSelf);

void Vadd4_fp16_tb_full___024root___eval_initial(Vadd4_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_full___024root___eval_initial\n"); );
    Vadd4_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vadd4_fp16_tb_full___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vadd4_fp16_tb_full___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

extern const VlWide<11>/*351:0*/ Vadd4_fp16_tb_full__ConstPool__CONST_hee9515d5_0;

VL_INLINE_OPT VlCoroutine Vadd4_fp16_tb_full___024root___eval_initial__TOP__Vtiming__0(Vadd4_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_full___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vadd4_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    std::string add4_fp16_tb_full__DOT__header;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__0__a;
    __Vtask_add4_fp16_tb_full__DOT__test_case__0__a = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__0__b;
    __Vtask_add4_fp16_tb_full__DOT__test_case__0__b = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__0__c;
    __Vtask_add4_fp16_tb_full__DOT__test_case__0__c = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__0__d;
    __Vtask_add4_fp16_tb_full__DOT__test_case__0__d = 0;
    std::string __Vtask_add4_fp16_tb_full__DOT__check_case__1__casename;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__check_case__1__expected;
    __Vtask_add4_fp16_tb_full__DOT__check_case__1__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp16_tb_full__DOT__check_case__1__match;
    __Vtask_add4_fp16_tb_full__DOT__check_case__1__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__2__Vfuncout;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__2__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__2__val;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__2__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__3__Vfuncout;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__3__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__3__val;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__3__val = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__4__a;
    __Vtask_add4_fp16_tb_full__DOT__test_case__4__a = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__4__b;
    __Vtask_add4_fp16_tb_full__DOT__test_case__4__b = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__4__c;
    __Vtask_add4_fp16_tb_full__DOT__test_case__4__c = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__4__d;
    __Vtask_add4_fp16_tb_full__DOT__test_case__4__d = 0;
    std::string __Vtask_add4_fp16_tb_full__DOT__check_case__5__casename;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__check_case__5__expected;
    __Vtask_add4_fp16_tb_full__DOT__check_case__5__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp16_tb_full__DOT__check_case__5__match;
    __Vtask_add4_fp16_tb_full__DOT__check_case__5__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__6__Vfuncout;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__6__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__6__val;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__6__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__7__Vfuncout;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__7__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__7__val;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__7__val = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__8__a;
    __Vtask_add4_fp16_tb_full__DOT__test_case__8__a = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__8__b;
    __Vtask_add4_fp16_tb_full__DOT__test_case__8__b = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__8__c;
    __Vtask_add4_fp16_tb_full__DOT__test_case__8__c = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__8__d;
    __Vtask_add4_fp16_tb_full__DOT__test_case__8__d = 0;
    std::string __Vtask_add4_fp16_tb_full__DOT__check_case__9__casename;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__check_case__9__expected;
    __Vtask_add4_fp16_tb_full__DOT__check_case__9__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp16_tb_full__DOT__check_case__9__match;
    __Vtask_add4_fp16_tb_full__DOT__check_case__9__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__10__Vfuncout;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__10__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__10__val;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__10__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__11__Vfuncout;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__11__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__11__val;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__11__val = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__12__a;
    __Vtask_add4_fp16_tb_full__DOT__test_case__12__a = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__12__b;
    __Vtask_add4_fp16_tb_full__DOT__test_case__12__b = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__12__c;
    __Vtask_add4_fp16_tb_full__DOT__test_case__12__c = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__12__d;
    __Vtask_add4_fp16_tb_full__DOT__test_case__12__d = 0;
    std::string __Vtask_add4_fp16_tb_full__DOT__check_case__13__casename;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__check_case__13__expected;
    __Vtask_add4_fp16_tb_full__DOT__check_case__13__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp16_tb_full__DOT__check_case__13__match;
    __Vtask_add4_fp16_tb_full__DOT__check_case__13__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__14__Vfuncout;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__14__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__14__val;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__14__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__15__Vfuncout;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__15__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__15__val;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__15__val = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__16__a;
    __Vtask_add4_fp16_tb_full__DOT__test_case__16__a = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__16__b;
    __Vtask_add4_fp16_tb_full__DOT__test_case__16__b = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__16__c;
    __Vtask_add4_fp16_tb_full__DOT__test_case__16__c = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__16__d;
    __Vtask_add4_fp16_tb_full__DOT__test_case__16__d = 0;
    std::string __Vtask_add4_fp16_tb_full__DOT__check_case__17__casename;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__check_case__17__expected;
    __Vtask_add4_fp16_tb_full__DOT__check_case__17__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp16_tb_full__DOT__check_case__17__match;
    __Vtask_add4_fp16_tb_full__DOT__check_case__17__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__18__Vfuncout;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__18__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__18__val;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__18__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__19__Vfuncout;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__19__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__19__val;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__19__val = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__20__a;
    __Vtask_add4_fp16_tb_full__DOT__test_case__20__a = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__20__b;
    __Vtask_add4_fp16_tb_full__DOT__test_case__20__b = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__20__c;
    __Vtask_add4_fp16_tb_full__DOT__test_case__20__c = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__20__d;
    __Vtask_add4_fp16_tb_full__DOT__test_case__20__d = 0;
    std::string __Vtask_add4_fp16_tb_full__DOT__check_case__21__casename;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__check_case__21__expected;
    __Vtask_add4_fp16_tb_full__DOT__check_case__21__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp16_tb_full__DOT__check_case__21__match;
    __Vtask_add4_fp16_tb_full__DOT__check_case__21__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__22__Vfuncout;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__22__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__22__val;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__22__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__23__Vfuncout;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__23__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__23__val;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__23__val = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__24__a;
    __Vtask_add4_fp16_tb_full__DOT__test_case__24__a = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__24__b;
    __Vtask_add4_fp16_tb_full__DOT__test_case__24__b = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__24__c;
    __Vtask_add4_fp16_tb_full__DOT__test_case__24__c = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__24__d;
    __Vtask_add4_fp16_tb_full__DOT__test_case__24__d = 0;
    std::string __Vtask_add4_fp16_tb_full__DOT__check_case__25__casename;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__check_case__25__expected;
    __Vtask_add4_fp16_tb_full__DOT__check_case__25__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp16_tb_full__DOT__check_case__25__match;
    __Vtask_add4_fp16_tb_full__DOT__check_case__25__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__26__Vfuncout;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__26__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__26__val;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__26__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__27__Vfuncout;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__27__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__27__val;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__27__val = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__28__a;
    __Vtask_add4_fp16_tb_full__DOT__test_case__28__a = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__28__b;
    __Vtask_add4_fp16_tb_full__DOT__test_case__28__b = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__28__c;
    __Vtask_add4_fp16_tb_full__DOT__test_case__28__c = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__28__d;
    __Vtask_add4_fp16_tb_full__DOT__test_case__28__d = 0;
    std::string __Vtask_add4_fp16_tb_full__DOT__check_case__29__casename;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__check_case__29__expected;
    __Vtask_add4_fp16_tb_full__DOT__check_case__29__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp16_tb_full__DOT__check_case__29__match;
    __Vtask_add4_fp16_tb_full__DOT__check_case__29__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__30__Vfuncout;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__30__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__30__val;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__30__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__31__Vfuncout;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__31__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__31__val;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__31__val = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__32__a;
    __Vtask_add4_fp16_tb_full__DOT__test_case__32__a = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__32__b;
    __Vtask_add4_fp16_tb_full__DOT__test_case__32__b = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__32__c;
    __Vtask_add4_fp16_tb_full__DOT__test_case__32__c = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__32__d;
    __Vtask_add4_fp16_tb_full__DOT__test_case__32__d = 0;
    std::string __Vtask_add4_fp16_tb_full__DOT__check_case__33__casename;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__check_case__33__expected;
    __Vtask_add4_fp16_tb_full__DOT__check_case__33__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp16_tb_full__DOT__check_case__33__match;
    __Vtask_add4_fp16_tb_full__DOT__check_case__33__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__34__Vfuncout;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__34__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__34__val;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__34__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__35__Vfuncout;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__35__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__35__val;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__35__val = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__36__a;
    __Vtask_add4_fp16_tb_full__DOT__test_case__36__a = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__36__b;
    __Vtask_add4_fp16_tb_full__DOT__test_case__36__b = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__36__c;
    __Vtask_add4_fp16_tb_full__DOT__test_case__36__c = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__36__d;
    __Vtask_add4_fp16_tb_full__DOT__test_case__36__d = 0;
    std::string __Vtask_add4_fp16_tb_full__DOT__check_case__37__casename;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__check_case__37__expected;
    __Vtask_add4_fp16_tb_full__DOT__check_case__37__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp16_tb_full__DOT__check_case__37__match;
    __Vtask_add4_fp16_tb_full__DOT__check_case__37__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__38__Vfuncout;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__38__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__38__val;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__38__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__39__Vfuncout;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__39__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__39__val;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__39__val = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__40__a;
    __Vtask_add4_fp16_tb_full__DOT__test_case__40__a = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__40__b;
    __Vtask_add4_fp16_tb_full__DOT__test_case__40__b = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__40__c;
    __Vtask_add4_fp16_tb_full__DOT__test_case__40__c = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__40__d;
    __Vtask_add4_fp16_tb_full__DOT__test_case__40__d = 0;
    std::string __Vtask_add4_fp16_tb_full__DOT__check_case__41__casename;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__check_case__41__expected;
    __Vtask_add4_fp16_tb_full__DOT__check_case__41__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp16_tb_full__DOT__check_case__41__match;
    __Vtask_add4_fp16_tb_full__DOT__check_case__41__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__42__Vfuncout;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__42__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__42__val;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__42__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__43__Vfuncout;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__43__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__43__val;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__43__val = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__44__a;
    __Vtask_add4_fp16_tb_full__DOT__test_case__44__a = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__44__b;
    __Vtask_add4_fp16_tb_full__DOT__test_case__44__b = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__44__c;
    __Vtask_add4_fp16_tb_full__DOT__test_case__44__c = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__test_case__44__d;
    __Vtask_add4_fp16_tb_full__DOT__test_case__44__d = 0;
    std::string __Vtask_add4_fp16_tb_full__DOT__check_case__45__casename;
    SData/*15:0*/ __Vtask_add4_fp16_tb_full__DOT__check_case__45__expected;
    __Vtask_add4_fp16_tb_full__DOT__check_case__45__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp16_tb_full__DOT__check_case__45__match;
    __Vtask_add4_fp16_tb_full__DOT__check_case__45__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__46__Vfuncout;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__46__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__46__val;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__46__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__47__Vfuncout;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__47__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__47__val;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__47__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__48__Vfuncout;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__48__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__48__val;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__48__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__49__Vfuncout;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__49__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_full__DOT__is_nan__49__val;
    __Vfunc_add4_fp16_tb_full__DOT__is_nan__49__val = 0;
    // Body
    vlSelfRef.add4_fp16_tb_full__DOT__pass_count = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__fail_count = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_a = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_b = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_c = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_d = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                         104);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                         106);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("--- Hardcoded 4-input Addition Cases ---\n",0);
    __Vtask_add4_fp16_tb_full__DOT__test_case__0__d = 0x3c00U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__0__c = 0x3c00U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__0__b = 0x3c00U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__0__a = 0x3c00U;
    co_await vlSelfRef.__VtrigSched_h91ae8b3f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                         45);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_a = __Vtask_add4_fp16_tb_full__DOT__test_case__0__a;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_b = __Vtask_add4_fp16_tb_full__DOT__test_case__0__b;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_c = __Vtask_add4_fp16_tb_full__DOT__test_case__0__c;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_d = __Vtask_add4_fp16_tb_full__DOT__test_case__0__d;
    co_await vlSelfRef.__VtrigSched_h91ae8b3f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                         51);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__exp = 0x4400U;
    co_await vlSelfRef.__VdlySched.delay(0x1770ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                         113);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_full__DOT__check_case__1__expected 
        = vlSelfRef.add4_fp16_tb_full__DOT__exp;
    __Vtask_add4_fp16_tb_full__DOT__check_case__1__casename = 
        std::string{"1+1+1+1 = 4"};
    __Vtask_add4_fp16_tb_full__DOT__check_case__1__match = 0;
    __Vtask_add4_fp16_tb_full__DOT__check_case__1__match 
        = ((([&]() {
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__2__val 
                        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final))))));
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__2__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__2__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__2__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__2__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__3__val 
                        = __Vtask_add4_fp16_tb_full__DOT__check_case__1__expected;
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__3__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__3__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__3__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__3__Vfuncout))) 
           || (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add4_fp16_tb_full__DOT__check_case__1__expected)));
    if (__Vtask_add4_fp16_tb_full__DOT__check_case__1__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_full__DOT__check_case__1__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_d,
                     16,((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))));
        vlSelfRef.add4_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_full__DOT__check_case__1__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_d,
                     16,((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add4_fp16_tb_full__DOT__check_case__1__expected));
        vlSelfRef.add4_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                         115);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__4__d = 0x4000U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__4__c = 0x4000U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__4__b = 0x4000U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__4__a = 0x4000U;
    co_await vlSelfRef.__VtrigSched_h91ae8b3f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                         45);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_a = __Vtask_add4_fp16_tb_full__DOT__test_case__4__a;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_b = __Vtask_add4_fp16_tb_full__DOT__test_case__4__b;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_c = __Vtask_add4_fp16_tb_full__DOT__test_case__4__c;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_d = __Vtask_add4_fp16_tb_full__DOT__test_case__4__d;
    co_await vlSelfRef.__VtrigSched_h91ae8b3f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                         51);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__exp = 0x4800U;
    co_await vlSelfRef.__VdlySched.delay(0x1770ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                         120);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_full__DOT__check_case__5__expected 
        = vlSelfRef.add4_fp16_tb_full__DOT__exp;
    __Vtask_add4_fp16_tb_full__DOT__check_case__5__casename = 
        std::string{"2+2+2+2 = 8"};
    __Vtask_add4_fp16_tb_full__DOT__check_case__5__match = 0;
    __Vtask_add4_fp16_tb_full__DOT__check_case__5__match 
        = ((([&]() {
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__6__val 
                        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final))))));
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__6__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__6__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__6__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__6__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__7__val 
                        = __Vtask_add4_fp16_tb_full__DOT__check_case__5__expected;
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__7__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__7__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__7__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__7__Vfuncout))) 
           || (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add4_fp16_tb_full__DOT__check_case__5__expected)));
    if (__Vtask_add4_fp16_tb_full__DOT__check_case__5__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_full__DOT__check_case__5__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_d,
                     16,((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))));
        vlSelfRef.add4_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_full__DOT__check_case__5__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_d,
                     16,((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add4_fp16_tb_full__DOT__check_case__5__expected));
        vlSelfRef.add4_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                         122);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__8__d = 0U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__8__c = 0U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__8__b = 0U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__8__a = 0U;
    co_await vlSelfRef.__VtrigSched_h91ae8b3f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                         45);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_a = __Vtask_add4_fp16_tb_full__DOT__test_case__8__a;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_b = __Vtask_add4_fp16_tb_full__DOT__test_case__8__b;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_c = __Vtask_add4_fp16_tb_full__DOT__test_case__8__c;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_d = __Vtask_add4_fp16_tb_full__DOT__test_case__8__d;
    co_await vlSelfRef.__VtrigSched_h91ae8b3f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                         51);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__exp = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x1770ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                         127);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_full__DOT__check_case__9__expected 
        = vlSelfRef.add4_fp16_tb_full__DOT__exp;
    __Vtask_add4_fp16_tb_full__DOT__check_case__9__casename = 
        std::string{"0+0+0+0 = 0"};
    __Vtask_add4_fp16_tb_full__DOT__check_case__9__match = 0;
    __Vtask_add4_fp16_tb_full__DOT__check_case__9__match 
        = ((([&]() {
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__10__val 
                        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final))))));
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__10__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__10__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__10__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__10__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__11__val 
                        = __Vtask_add4_fp16_tb_full__DOT__check_case__9__expected;
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__11__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__11__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__11__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__11__Vfuncout))) 
           || (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add4_fp16_tb_full__DOT__check_case__9__expected)));
    if (__Vtask_add4_fp16_tb_full__DOT__check_case__9__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_full__DOT__check_case__9__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_d,
                     16,((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))));
        vlSelfRef.add4_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_full__DOT__check_case__9__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_d,
                     16,((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add4_fp16_tb_full__DOT__check_case__9__expected));
        vlSelfRef.add4_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                         129);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__12__d = 0U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__12__c = 0U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__12__b = 0U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__12__a = 0x3c00U;
    co_await vlSelfRef.__VtrigSched_h91ae8b3f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                         45);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_a = __Vtask_add4_fp16_tb_full__DOT__test_case__12__a;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_b = __Vtask_add4_fp16_tb_full__DOT__test_case__12__b;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_c = __Vtask_add4_fp16_tb_full__DOT__test_case__12__c;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_d = __Vtask_add4_fp16_tb_full__DOT__test_case__12__d;
    co_await vlSelfRef.__VtrigSched_h91ae8b3f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                         51);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__exp = 0x3c00U;
    co_await vlSelfRef.__VdlySched.delay(0x1770ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                         134);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_full__DOT__check_case__13__expected 
        = vlSelfRef.add4_fp16_tb_full__DOT__exp;
    __Vtask_add4_fp16_tb_full__DOT__check_case__13__casename = 
        std::string{"1+0+0+0 = 1"};
    __Vtask_add4_fp16_tb_full__DOT__check_case__13__match = 0;
    __Vtask_add4_fp16_tb_full__DOT__check_case__13__match 
        = ((([&]() {
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__14__val 
                        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final))))));
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__14__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__14__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__14__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__14__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__15__val 
                        = __Vtask_add4_fp16_tb_full__DOT__check_case__13__expected;
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__15__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__15__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__15__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__15__Vfuncout))) 
           || (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add4_fp16_tb_full__DOT__check_case__13__expected)));
    if (__Vtask_add4_fp16_tb_full__DOT__check_case__13__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_full__DOT__check_case__13__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_d,
                     16,((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))));
        vlSelfRef.add4_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_full__DOT__check_case__13__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_d,
                     16,((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add4_fp16_tb_full__DOT__check_case__13__expected));
        vlSelfRef.add4_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                         136);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__16__d = 0x3c00U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__16__c = 0x3c00U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__16__b = 0x3c00U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__16__a = 0x7c00U;
    co_await vlSelfRef.__VtrigSched_h91ae8b3f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                         45);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_a = __Vtask_add4_fp16_tb_full__DOT__test_case__16__a;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_b = __Vtask_add4_fp16_tb_full__DOT__test_case__16__b;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_c = __Vtask_add4_fp16_tb_full__DOT__test_case__16__c;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_d = __Vtask_add4_fp16_tb_full__DOT__test_case__16__d;
    co_await vlSelfRef.__VtrigSched_h91ae8b3f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                         51);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__exp = 0x7c00U;
    co_await vlSelfRef.__VdlySched.delay(0x1770ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                         141);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_full__DOT__check_case__17__expected 
        = vlSelfRef.add4_fp16_tb_full__DOT__exp;
    __Vtask_add4_fp16_tb_full__DOT__check_case__17__casename = 
        std::string{"Inf+1+1+1 = Inf"};
    __Vtask_add4_fp16_tb_full__DOT__check_case__17__match = 0;
    __Vtask_add4_fp16_tb_full__DOT__check_case__17__match 
        = ((([&]() {
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__18__val 
                        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final))))));
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__18__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__18__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__18__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__18__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__19__val 
                        = __Vtask_add4_fp16_tb_full__DOT__check_case__17__expected;
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__19__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__19__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__19__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__19__Vfuncout))) 
           || (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add4_fp16_tb_full__DOT__check_case__17__expected)));
    if (__Vtask_add4_fp16_tb_full__DOT__check_case__17__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_full__DOT__check_case__17__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_d,
                     16,((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))));
        vlSelfRef.add4_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_full__DOT__check_case__17__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_d,
                     16,((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add4_fp16_tb_full__DOT__check_case__17__expected));
        vlSelfRef.add4_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                         143);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__20__d = 0x3c00U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__20__c = 0x3c00U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__20__b = 0x7c00U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__20__a = 0x7c00U;
    co_await vlSelfRef.__VtrigSched_h91ae8b3f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                         45);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_a = __Vtask_add4_fp16_tb_full__DOT__test_case__20__a;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_b = __Vtask_add4_fp16_tb_full__DOT__test_case__20__b;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_c = __Vtask_add4_fp16_tb_full__DOT__test_case__20__c;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_d = __Vtask_add4_fp16_tb_full__DOT__test_case__20__d;
    co_await vlSelfRef.__VtrigSched_h91ae8b3f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                         51);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__exp = 0x7c00U;
    co_await vlSelfRef.__VdlySched.delay(0x1770ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                         148);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_full__DOT__check_case__21__expected 
        = vlSelfRef.add4_fp16_tb_full__DOT__exp;
    __Vtask_add4_fp16_tb_full__DOT__check_case__21__casename = 
        std::string{"Inf+Inf+1+1 = Inf"};
    __Vtask_add4_fp16_tb_full__DOT__check_case__21__match = 0;
    __Vtask_add4_fp16_tb_full__DOT__check_case__21__match 
        = ((([&]() {
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__22__val 
                        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final))))));
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__22__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__22__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__22__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__22__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__23__val 
                        = __Vtask_add4_fp16_tb_full__DOT__check_case__21__expected;
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__23__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__23__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__23__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__23__Vfuncout))) 
           || (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add4_fp16_tb_full__DOT__check_case__21__expected)));
    if (__Vtask_add4_fp16_tb_full__DOT__check_case__21__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_full__DOT__check_case__21__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_d,
                     16,((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))));
        vlSelfRef.add4_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_full__DOT__check_case__21__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_d,
                     16,((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add4_fp16_tb_full__DOT__check_case__21__expected));
        vlSelfRef.add4_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                         150);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__24__d = 0x3c00U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__24__c = 0x3c00U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__24__b = 0xfc00U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__24__a = 0x7c00U;
    co_await vlSelfRef.__VtrigSched_h91ae8b3f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                         45);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_a = __Vtask_add4_fp16_tb_full__DOT__test_case__24__a;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_b = __Vtask_add4_fp16_tb_full__DOT__test_case__24__b;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_c = __Vtask_add4_fp16_tb_full__DOT__test_case__24__c;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_d = __Vtask_add4_fp16_tb_full__DOT__test_case__24__d;
    co_await vlSelfRef.__VtrigSched_h91ae8b3f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                         51);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__exp = 0x7d00U;
    co_await vlSelfRef.__VdlySched.delay(0x1770ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                         155);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_full__DOT__check_case__25__expected 
        = vlSelfRef.add4_fp16_tb_full__DOT__exp;
    __Vtask_add4_fp16_tb_full__DOT__check_case__25__casename = 
        std::string{"+Inf + -Inf + 1 + 1 = NaN"};
    __Vtask_add4_fp16_tb_full__DOT__check_case__25__match = 0;
    __Vtask_add4_fp16_tb_full__DOT__check_case__25__match 
        = ((([&]() {
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__26__val 
                        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final))))));
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__26__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__26__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__26__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__26__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__27__val 
                        = __Vtask_add4_fp16_tb_full__DOT__check_case__25__expected;
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__27__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__27__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__27__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__27__Vfuncout))) 
           || (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add4_fp16_tb_full__DOT__check_case__25__expected)));
    if (__Vtask_add4_fp16_tb_full__DOT__check_case__25__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_full__DOT__check_case__25__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_d,
                     16,((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))));
        vlSelfRef.add4_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_full__DOT__check_case__25__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_d,
                     16,((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add4_fp16_tb_full__DOT__check_case__25__expected));
        vlSelfRef.add4_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                         157);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__28__d = 0x3c00U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__28__c = 0x3c00U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__28__b = 0x3c00U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__28__a = 0x7d00U;
    co_await vlSelfRef.__VtrigSched_h91ae8b3f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                         45);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_a = __Vtask_add4_fp16_tb_full__DOT__test_case__28__a;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_b = __Vtask_add4_fp16_tb_full__DOT__test_case__28__b;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_c = __Vtask_add4_fp16_tb_full__DOT__test_case__28__c;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_d = __Vtask_add4_fp16_tb_full__DOT__test_case__28__d;
    co_await vlSelfRef.__VtrigSched_h91ae8b3f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                         51);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__exp = 0x7d00U;
    co_await vlSelfRef.__VdlySched.delay(0x1770ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                         162);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_full__DOT__check_case__29__expected 
        = vlSelfRef.add4_fp16_tb_full__DOT__exp;
    __Vtask_add4_fp16_tb_full__DOT__check_case__29__casename = 
        std::string{"NaN+1+1+1 = NaN"};
    __Vtask_add4_fp16_tb_full__DOT__check_case__29__match = 0;
    __Vtask_add4_fp16_tb_full__DOT__check_case__29__match 
        = ((([&]() {
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__30__val 
                        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final))))));
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__30__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__30__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__30__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__30__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__31__val 
                        = __Vtask_add4_fp16_tb_full__DOT__check_case__29__expected;
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__31__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__31__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__31__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__31__Vfuncout))) 
           || (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add4_fp16_tb_full__DOT__check_case__29__expected)));
    if (__Vtask_add4_fp16_tb_full__DOT__check_case__29__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_full__DOT__check_case__29__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_d,
                     16,((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))));
        vlSelfRef.add4_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_full__DOT__check_case__29__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_d,
                     16,((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add4_fp16_tb_full__DOT__check_case__29__expected));
        vlSelfRef.add4_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                         164);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__32__d = 0x3c00U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__32__c = 0x3c00U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__32__b = 1U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__32__a = 1U;
    co_await vlSelfRef.__VtrigSched_h91ae8b3f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                         45);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_a = __Vtask_add4_fp16_tb_full__DOT__test_case__32__a;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_b = __Vtask_add4_fp16_tb_full__DOT__test_case__32__b;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_c = __Vtask_add4_fp16_tb_full__DOT__test_case__32__c;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_d = __Vtask_add4_fp16_tb_full__DOT__test_case__32__d;
    co_await vlSelfRef.__VtrigSched_h91ae8b3f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                         51);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__exp = 0x4000U;
    co_await vlSelfRef.__VdlySched.delay(0x1770ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                         169);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_full__DOT__check_case__33__expected 
        = vlSelfRef.add4_fp16_tb_full__DOT__exp;
    __Vtask_add4_fp16_tb_full__DOT__check_case__33__casename = 
        std::string{"sub+sub+1+1 = 2 (DAZ)"};
    __Vtask_add4_fp16_tb_full__DOT__check_case__33__match = 0;
    __Vtask_add4_fp16_tb_full__DOT__check_case__33__match 
        = ((([&]() {
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__34__val 
                        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final))))));
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__34__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__34__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__34__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__34__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__35__val 
                        = __Vtask_add4_fp16_tb_full__DOT__check_case__33__expected;
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__35__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__35__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__35__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__35__Vfuncout))) 
           || (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add4_fp16_tb_full__DOT__check_case__33__expected)));
    if (__Vtask_add4_fp16_tb_full__DOT__check_case__33__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_full__DOT__check_case__33__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_d,
                     16,((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))));
        vlSelfRef.add4_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_full__DOT__check_case__33__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_d,
                     16,((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add4_fp16_tb_full__DOT__check_case__33__expected));
        vlSelfRef.add4_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                         171);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__36__d = 0x7bffU;
    __Vtask_add4_fp16_tb_full__DOT__test_case__36__c = 0x7bffU;
    __Vtask_add4_fp16_tb_full__DOT__test_case__36__b = 0x7bffU;
    __Vtask_add4_fp16_tb_full__DOT__test_case__36__a = 0x7bffU;
    co_await vlSelfRef.__VtrigSched_h91ae8b3f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                         45);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_a = __Vtask_add4_fp16_tb_full__DOT__test_case__36__a;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_b = __Vtask_add4_fp16_tb_full__DOT__test_case__36__b;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_c = __Vtask_add4_fp16_tb_full__DOT__test_case__36__c;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_d = __Vtask_add4_fp16_tb_full__DOT__test_case__36__d;
    co_await vlSelfRef.__VtrigSched_h91ae8b3f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                         51);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__exp = 0x7c00U;
    co_await vlSelfRef.__VdlySched.delay(0x1770ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                         176);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_full__DOT__check_case__37__expected 
        = vlSelfRef.add4_fp16_tb_full__DOT__exp;
    __Vtask_add4_fp16_tb_full__DOT__check_case__37__casename = 
        std::string{"max+max+max+max = Inf"};
    __Vtask_add4_fp16_tb_full__DOT__check_case__37__match = 0;
    __Vtask_add4_fp16_tb_full__DOT__check_case__37__match 
        = ((([&]() {
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__38__val 
                        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final))))));
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__38__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__38__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__38__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__38__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__39__val 
                        = __Vtask_add4_fp16_tb_full__DOT__check_case__37__expected;
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__39__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__39__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__39__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__39__Vfuncout))) 
           || (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add4_fp16_tb_full__DOT__check_case__37__expected)));
    if (__Vtask_add4_fp16_tb_full__DOT__check_case__37__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_full__DOT__check_case__37__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_d,
                     16,((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))));
        vlSelfRef.add4_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_full__DOT__check_case__37__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_d,
                     16,((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add4_fp16_tb_full__DOT__check_case__37__expected));
        vlSelfRef.add4_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                         178);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__40__d = 0xbc00U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__40__c = 0x3c00U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__40__b = 0xbc00U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__40__a = 0x3c00U;
    co_await vlSelfRef.__VtrigSched_h91ae8b3f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                         45);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_a = __Vtask_add4_fp16_tb_full__DOT__test_case__40__a;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_b = __Vtask_add4_fp16_tb_full__DOT__test_case__40__b;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_c = __Vtask_add4_fp16_tb_full__DOT__test_case__40__c;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_d = __Vtask_add4_fp16_tb_full__DOT__test_case__40__d;
    co_await vlSelfRef.__VtrigSched_h91ae8b3f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                         51);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__exp = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x1770ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                         183);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_full__DOT__check_case__41__expected 
        = vlSelfRef.add4_fp16_tb_full__DOT__exp;
    __Vtask_add4_fp16_tb_full__DOT__check_case__41__casename = 
        std::string{"1+(-1)+1+(-1) = 0"};
    __Vtask_add4_fp16_tb_full__DOT__check_case__41__match = 0;
    __Vtask_add4_fp16_tb_full__DOT__check_case__41__match 
        = ((([&]() {
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__42__val 
                        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final))))));
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__42__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__42__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__42__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__42__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__43__val 
                        = __Vtask_add4_fp16_tb_full__DOT__check_case__41__expected;
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__43__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__43__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__43__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__43__Vfuncout))) 
           || (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add4_fp16_tb_full__DOT__check_case__41__expected)));
    if (__Vtask_add4_fp16_tb_full__DOT__check_case__41__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_full__DOT__check_case__41__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_d,
                     16,((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))));
        vlSelfRef.add4_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_full__DOT__check_case__41__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_d,
                     16,((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add4_fp16_tb_full__DOT__check_case__41__expected));
        vlSelfRef.add4_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                         185);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__44__d = 0xc000U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__44__c = 0xc000U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__44__b = 0xc000U;
    __Vtask_add4_fp16_tb_full__DOT__test_case__44__a = 0xc000U;
    co_await vlSelfRef.__VtrigSched_h91ae8b3f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                         45);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_a = __Vtask_add4_fp16_tb_full__DOT__test_case__44__a;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_b = __Vtask_add4_fp16_tb_full__DOT__test_case__44__b;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_c = __Vtask_add4_fp16_tb_full__DOT__test_case__44__c;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_d = __Vtask_add4_fp16_tb_full__DOT__test_case__44__d;
    co_await vlSelfRef.__VtrigSched_h91ae8b3f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                         51);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add4_fp16_tb_full__DOT__exp = 0xc800U;
    co_await vlSelfRef.__VdlySched.delay(0x1770ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                         191);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_full__DOT__check_case__45__expected 
        = vlSelfRef.add4_fp16_tb_full__DOT__exp;
    __Vtask_add4_fp16_tb_full__DOT__check_case__45__casename = 
        std::string{"-2+-2+-2+-2 = -8"};
    __Vtask_add4_fp16_tb_full__DOT__check_case__45__match = 0;
    __Vtask_add4_fp16_tb_full__DOT__check_case__45__match 
        = ((([&]() {
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__46__val 
                        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final))))));
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__46__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__46__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__46__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__46__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__47__val 
                        = __Vtask_add4_fp16_tb_full__DOT__check_case__45__expected;
                    __Vfunc_add4_fp16_tb_full__DOT__is_nan__47__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__47__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__47__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__47__Vfuncout))) 
           || (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add4_fp16_tb_full__DOT__check_case__45__expected)));
    if (__Vtask_add4_fp16_tb_full__DOT__check_case__45__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_full__DOT__check_case__45__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_d,
                     16,((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))));
        vlSelfRef.add4_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_full__DOT__check_case__45__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_full__DOT__tb_d,
                     16,((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add4_fp16_tb_full__DOT__check_case__45__expected));
        vlSelfRef.add4_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                         193);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("\n--- Random Test Cases from CSV ---\n",0);
    vlSelfRef.add4_fp16_tb_full__DOT__fd = VL_FOPEN_NN(
                                                       VL_CVT_PACK_STR_NW(11, Vadd4_fp16_tb_full__ConstPool__CONST_hee9515d5_0)
                                                       , 
                                                       std::string{"r"});
    ;
    if (VL_UNLIKELY(((0U == vlSelfRef.add4_fp16_tb_full__DOT__fd)))) {
        VL_WRITEF_NX("ERROR: Could not open random_cases_4.csv - run: python3 random_fp16gen4.py\n",0);
        VL_FINISH_MT("tb/unit/systolic_array/add4_fp16_tb_full.sv", 201, "");
    }
    (void)VL_FGETS_NI(add4_fp16_tb_full__DOT__header, vlSelfRef.add4_fp16_tb_full__DOT__fd);
    while ((! (vlSelfRef.add4_fp16_tb_full__DOT__fd ? feof(VL_CVT_I_FP(vlSelfRef.add4_fp16_tb_full__DOT__fd)) : true))) {
        {
            vlSelfRef.add4_fp16_tb_full__DOT__unnamedblk1__DOT__ret 
                = VL_FSCANF_INX(vlSelfRef.add4_fp16_tb_full__DOT__fd,"%x,%x,%x,%x,%x\n",0,
                                16,&(vlSelfRef.add4_fp16_tb_full__DOT__a),
                                16,&(vlSelfRef.add4_fp16_tb_full__DOT__b),
                                16,&(vlSelfRef.add4_fp16_tb_full__DOT__c),
                                16,&(vlSelfRef.add4_fp16_tb_full__DOT__d),
                                16,&(vlSelfRef.add4_fp16_tb_full__DOT__expected)) ;
            if ((5U != vlSelfRef.add4_fp16_tb_full__DOT__unnamedblk1__DOT__ret)) {
                goto __Vlabel1;
            }
            co_await vlSelfRef.__VtrigSched_h91ae8b3f__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge add4_fp16_tb_full.tb_clk)", 
                                                                 "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                                 213);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 1U;
            vlSelfRef.add4_fp16_tb_full__DOT__tb_a 
                = vlSelfRef.add4_fp16_tb_full__DOT__a;
            vlSelfRef.add4_fp16_tb_full__DOT__tb_b 
                = vlSelfRef.add4_fp16_tb_full__DOT__b;
            vlSelfRef.add4_fp16_tb_full__DOT__tb_c 
                = vlSelfRef.add4_fp16_tb_full__DOT__c;
            vlSelfRef.add4_fp16_tb_full__DOT__tb_d 
                = vlSelfRef.add4_fp16_tb_full__DOT__d;
            co_await vlSelfRef.__VtrigSched_h91ae8b3f__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge add4_fp16_tb_full.tb_clk)", 
                                                                 "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                                 220);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSelfRef.add4_fp16_tb_full__DOT__tb_start = 0U;
            co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                                 nullptr, 
                                                 "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                                 223);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSelfRef.add4_fp16_tb_full__DOT__unnamedblk1__DOT__is_zero_result 
                = (((0U == ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
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
                                                    | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final))))))) 
                    | (0x8000U == ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                                    ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                                    : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                                        ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                           << 0xfU)
                                        : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                            ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                               << 0xfU)
                                            : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                << 0xfU) 
                                               | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))))) 
                   & ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__expected)) 
                      | (0x8000U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__expected))));
            if ((([&]() {
                            __Vfunc_add4_fp16_tb_full__DOT__is_nan__48__val 
                                = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                                    ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                                    : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                                        ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                           << 0xfU)
                                        : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                            ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                               << 0xfU)
                                            : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                << 0xfU) 
                                               | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final))))));
                            __Vfunc_add4_fp16_tb_full__DOT__is_nan__48__Vfuncout 
                                = (IData)(((0x7c00U 
                                            == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__48__val))) 
                                           & (0U != 
                                              (0x3ffU 
                                               & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__48__val)))));
                        }(), (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__48__Vfuncout)) 
                 & ([&]() {
                            __Vfunc_add4_fp16_tb_full__DOT__is_nan__49__val 
                                = vlSelfRef.add4_fp16_tb_full__DOT__expected;
                            __Vfunc_add4_fp16_tb_full__DOT__is_nan__49__Vfuncout 
                                = (IData)(((0x7c00U 
                                            == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__49__val))) 
                                           & (0U != 
                                              (0x3ffU 
                                               & (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__49__val)))));
                        }(), (IData)(__Vfunc_add4_fp16_tb_full__DOT__is_nan__49__Vfuncout)))) {
                vlSelfRef.add4_fp16_tb_full__DOT__pass_count 
                    = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__pass_count);
            } else if (vlSelfRef.add4_fp16_tb_full__DOT__unnamedblk1__DOT__is_zero_result) {
                vlSelfRef.add4_fp16_tb_full__DOT__pass_count 
                    = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__pass_count);
            } else if (VL_UNLIKELY(((((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                                       ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                                       : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                                           ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                              << 0xfU)
                                           : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                               ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                  << 0xfU)
                                               : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                                   << 0xfU) 
                                                  | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                                      << 0xaU) 
                                                     | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))) 
                                     != (IData)(vlSelfRef.add4_fp16_tb_full__DOT__expected))))) {
                VL_WRITEF_NX("FAIL: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                             16,vlSelfRef.add4_fp16_tb_full__DOT__a,
                             16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__b),
                             16,vlSelfRef.add4_fp16_tb_full__DOT__c,
                             16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__d),
                             16,((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l)
                                  ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l)
                                  : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))
                                      ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                         << 0xfU) : 
                                     ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under)
                                       ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                          << 0xfU) : 
                                      (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign) 
                                        << 0xfU) | 
                                       (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final) 
                                         << 0xaU) | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final)))))),
                             16,(IData)(vlSelfRef.add4_fp16_tb_full__DOT__expected));
                vlSelfRef.add4_fp16_tb_full__DOT__fail_count 
                    = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__fail_count);
            } else {
                vlSelfRef.add4_fp16_tb_full__DOT__pass_count 
                    = ((IData)(1U) + vlSelfRef.add4_fp16_tb_full__DOT__pass_count);
            }
            __Vlabel1: ;
        }
    }
    VL_FCLOSE_I(vlSelfRef.add4_fp16_tb_full__DOT__fd); VL_WRITEF_NX("\n=== Test Summary ===\nPASSED: %0d\nFAILED: %0d\n",0,
                                                                    32,
                                                                    vlSelfRef.add4_fp16_tb_full__DOT__pass_count,
                                                                    32,
                                                                    vlSelfRef.add4_fp16_tb_full__DOT__fail_count);
    if ((0U == vlSelfRef.add4_fp16_tb_full__DOT__fail_count)) {
        VL_WRITEF_NX("ALL TESTS PASSED!\n",0);
    } else {
        VL_WRITEF_NX("SOME TESTS FAILED!\n",0);
    }
    VL_FINISH_MT("tb/unit/systolic_array/add4_fp16_tb_full.sv", 252, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

VL_INLINE_OPT VlCoroutine Vadd4_fp16_tb_full___024root___eval_initial__TOP__Vtiming__1(Vadd4_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_full___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vadd4_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        vlSelfRef.add4_fp16_tb_full__DOT__tb_clk = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                             nullptr, 
                                             "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                             17);
        vlSelfRef.add4_fp16_tb_full__DOT__tb_clk = 1U;
        co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                             nullptr, 
                                             "tb/unit/systolic_array/add4_fp16_tb_full.sv", 
                                             19);
    }
}

void Vadd4_fp16_tb_full___024root___act_comb__TOP__0(Vadd4_fp16_tb_full___024root* vlSelf);

void Vadd4_fp16_tb_full___024root___eval_act(Vadd4_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_full___024root___eval_act\n"); );
    Vadd4_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0xcULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadd4_fp16_tb_full___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void Vadd4_fp16_tb_full___024root___act_comb__TOP__0(Vadd4_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_full___024root___act_comb__TOP__0\n"); );
    Vadd4_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__a 
        = vlSelfRef.add4_fp16_tb_full__DOT__tb_a;
    if ((IData)(((0U == (0x7c00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__a))) 
                 & (0U != (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__a)))))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__a 
            = (0x8000U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__a));
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__b 
        = vlSelfRef.add4_fp16_tb_full__DOT__tb_b;
    if ((IData)(((0U == (0x7c00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__b))) 
                 & (0U != (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__b)))))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__b 
            = (0x8000U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__b));
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__a 
        = vlSelfRef.add4_fp16_tb_full__DOT__tb_c;
    if ((IData)(((0U == (0x7c00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__a))) 
                 & (0U != (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__a)))))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__a 
            = (0x8000U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__a));
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__b 
        = vlSelfRef.add4_fp16_tb_full__DOT__tb_d;
    if ((IData)(((0U == (0x7c00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__b))) 
                 & (0U != (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__b)))))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__b 
            = (0x8000U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__b));
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_case = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_result = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__is_nan_a 
        = (IData)(((0x7c00U == (0x7c00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__a))) 
                   & (0U != (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__a)))));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__is_nan_b 
        = (IData)(((0x7c00U == (0x7c00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__b))) 
                   & (0U != (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__b)))));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__is_inf_a 
        = (IData)((0x7c00U == (0x7fffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__a))));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__is_inf_b 
        = (IData)((0x7c00U == (0x7fffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__b))));
    if (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__is_nan_a) 
         | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__is_nan_b))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_case = 1U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_result = 0x7e00U;
    } else if (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__is_inf_a) 
                & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__is_inf_b))) {
        if (((1U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__a) 
                    >> 0xfU)) == (1U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__b) 
                                        >> 0xfU)))) {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_case = 1U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_result 
                = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__a;
        } else {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_case = 1U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_result = 0x7e00U;
        }
    } else if (vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__is_inf_a) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_case = 1U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_result 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__a;
    } else if (vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__is_inf_b) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_case = 1U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_result 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__b;
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__op_swap 
        = ((0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__a) 
                     >> 0xaU)) < (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__b) 
                                           >> 0xaU)));
    if (vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__op_swap) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__high_op 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__b;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__low_op 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__a;
    } else {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__high_op 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__a;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__low_op 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__b;
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__high_exp 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__high_op) 
                    >> 0xaU));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__low_exp 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__low_op) 
                    >> 0xaU));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_diff 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__high_exp) 
                    - (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__low_exp)));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_max 
        = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__high_exp;
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_hi 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__high_exp))) 
            << 0xcU) | (0xffcU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__high_op) 
                                  << 2U)));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_lo 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__low_exp))) 
            << 0xcU) | (0xffcU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__low_op) 
                                  << 2U)));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_lo_aligned = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sticky_align_local = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sticky_lost = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mask_align = 0U;
    if ((0xdU <= (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_diff))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_lo_aligned = 0U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sticky_lost = 0U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_lo_aligned 
            = ((0x1ffeU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_lo_aligned)) 
               | (0U != (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_lo)));
    } else if ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_diff))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_lo_aligned 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_lo;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sticky_lost = 0U;
    } else {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_lo_aligned 
            = (0x1fffU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_lo) 
                          >> (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_diff)));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mask_align 
            = (0x1fffU & (((IData)(1U) << (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_diff)) 
                          - (IData)(1U)));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sticky_align_local 
            = (0U != ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_lo) 
                      & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mask_align)));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sticky_lost 
            = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sticky_align_local) 
               & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_lo_aligned));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_lo_aligned 
            = ((0x1ffeU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_lo_aligned)) 
               | (1U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_lo_aligned) 
                        | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sticky_align_local))));
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_not_shifted 
        = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_hi;
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_shifted 
        = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mant_lo_aligned;
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_not_shifted 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__high_op) 
                 >> 0xfU));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_shifted 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__low_op) 
                 >> 0xfU));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_case = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_result = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__is_nan_a 
        = (IData)(((0x7c00U == (0x7c00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__a))) 
                   & (0U != (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__a)))));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__is_nan_b 
        = (IData)(((0x7c00U == (0x7c00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__b))) 
                   & (0U != (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__b)))));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__is_inf_a 
        = (IData)((0x7c00U == (0x7fffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__a))));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__is_inf_b 
        = (IData)((0x7c00U == (0x7fffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__b))));
    if (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__is_nan_a) 
         | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__is_nan_b))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_case = 1U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_result = 0x7e00U;
    } else if (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__is_inf_a) 
                & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__is_inf_b))) {
        if (((1U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__a) 
                    >> 0xfU)) == (1U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__b) 
                                        >> 0xfU)))) {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_case = 1U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_result 
                = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__a;
        } else {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_case = 1U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_result = 0x7e00U;
        }
    } else if (vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__is_inf_a) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_case = 1U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_result 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__a;
    } else if (vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__is_inf_b) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_case = 1U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_result 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__b;
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__op_swap 
        = ((0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__a) 
                     >> 0xaU)) < (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__b) 
                                           >> 0xaU)));
    if (vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__op_swap) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__high_op 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__b;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__low_op 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__a;
    } else {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__high_op 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__a;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__low_op 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__b;
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__high_exp 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__high_op) 
                    >> 0xaU));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__low_exp 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__low_op) 
                    >> 0xaU));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_diff 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__high_exp) 
                    - (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__low_exp)));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_max 
        = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__high_exp;
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_hi 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__high_exp))) 
            << 0xcU) | (0xffcU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__high_op) 
                                  << 2U)));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_lo 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__low_exp))) 
            << 0xcU) | (0xffcU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__low_op) 
                                  << 2U)));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_lo_aligned = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sticky_align_local = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sticky_lost = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mask_align = 0U;
    if ((0xdU <= (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_diff))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_lo_aligned = 0U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sticky_lost = 0U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_lo_aligned 
            = ((0x1ffeU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_lo_aligned)) 
               | (0U != (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_lo)));
    } else if ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_diff))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_lo_aligned 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_lo;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sticky_lost = 0U;
    } else {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_lo_aligned 
            = (0x1fffU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_lo) 
                          >> (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_diff)));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mask_align 
            = (0x1fffU & (((IData)(1U) << (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_diff)) 
                          - (IData)(1U)));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sticky_align_local 
            = (0U != ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_lo) 
                      & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mask_align)));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sticky_lost 
            = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sticky_align_local) 
               & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_lo_aligned));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_lo_aligned 
            = ((0x1ffeU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_lo_aligned)) 
               | (1U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_lo_aligned) 
                        | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sticky_align_local))));
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_not_shifted 
        = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_hi;
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_shifted 
        = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mant_lo_aligned;
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_not_shifted 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__high_op) 
                 >> 0xfU));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_shifted 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__low_op) 
                 >> 0xfU));
    if (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_shifted) 
         > (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_not_shifted))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__smaller_mantissa 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_not_shifted;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__larger_mantissa 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_shifted;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__larger_mantissa_sign 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_shifted;
    } else {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__smaller_mantissa 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_shifted;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__larger_mantissa 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_not_shifted;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__larger_mantissa_sign 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_not_shifted;
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sub_has_lost_sticky 
        = (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_shifted) 
            <= (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_not_shifted)) 
           && (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sticky_lost));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sub_has_added_sticky 
        = (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_shifted) 
            <= (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_not_shifted)) 
           && ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sticky_align_local) 
               & (~ (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sticky_lost))));
    if (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_shifted) 
         > (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_not_shifted))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__smaller_mantissa 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_not_shifted;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__larger_mantissa 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_shifted;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__larger_mantissa_sign 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_shifted;
    } else {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__smaller_mantissa 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_shifted;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__larger_mantissa 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_not_shifted;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__larger_mantissa_sign 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_not_shifted;
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sub_has_lost_sticky 
        = (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_shifted) 
            <= (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_not_shifted)) 
           && (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sticky_lost));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sub_has_added_sticky 
        = (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_shifted) 
            <= (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_not_shifted)) 
           && ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sticky_align_local) 
               & (~ (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sticky_lost))));
}

void Vadd4_fp16_tb_full___024root___nba_sequent__TOP__0(Vadd4_fp16_tb_full___024root* vlSelf);

void Vadd4_fp16_tb_full___024root___eval_nba(Vadd4_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_full___024root___eval_nba\n"); );
    Vadd4_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadd4_fp16_tb_full___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((0xcULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadd4_fp16_tb_full___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
}

VL_INLINE_OPT void Vadd4_fp16_tb_full___024root___nba_sequent__TOP__0(Vadd4_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_full___024root___nba_sequent__TOP__0\n"); );
    Vadd4_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__start_l 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_start));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case_l 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case));
    if (vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_max_l 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_max;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_result_l 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_result;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_result_l 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_result;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__smaller_mantissa_l 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__smaller_mantissa;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__larger_mantissa_l 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__larger_mantissa;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_max_l 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_max;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_max_l 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_max;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__smaller_mantissa_l 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__smaller_mantissa;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__larger_mantissa_l 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__larger_mantissa;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__smaller_mantissa_l 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__smaller_mantissa;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__larger_mantissa_l 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__larger_mantissa;
    } else {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result_l = 0U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_max_l = 0U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_result_l = 0U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_result_l = 0U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__smaller_mantissa_l = 0U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__larger_mantissa_l = 0U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_max_l = 0U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_max_l = 0U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__smaller_mantissa_l = 0U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__larger_mantissa_l = 0U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__smaller_mantissa_l = 0U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__larger_mantissa_l = 0U;
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__larger_mantissa_sign_l 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__larger_mantissa_sign));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sub_has_lost_sticky_l 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sub_has_lost_sticky));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sub_has_added_sticky_l 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sub_has_added_sticky));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__start_l 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__start_l));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_not_shifted_l 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_not_shifted));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_shifted_l 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_shifted));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_case_l 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_case));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_case_l 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_case));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__larger_mantissa_sign_l 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__larger_mantissa_sign));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__larger_mantissa_sign_l 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__larger_mantissa_sign));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_not_shifted_l 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_not_shifted));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_shifted_l 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_shifted));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_not_shifted_l 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_not_shifted));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_shifted_l 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_shifted));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__signs_differ_l 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst) 
           && ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_shifted) 
               ^ (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_not_shifted)));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sub_has_lost_sticky_l 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sub_has_lost_sticky));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sub_has_lost_sticky_l 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sub_has_lost_sticky));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sub_has_added_sticky_l 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sub_has_added_sticky));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sub_has_added_sticky_l 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sub_has_added_sticky));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__signs_differ_l 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst) 
           && ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_shifted) 
               ^ (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_not_shifted)));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__signs_differ_l 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst) 
           && ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_shifted) 
               ^ (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_not_shifted)));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__start_l 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp16_tb_full__DOT__tb_start));
    if (vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__signs_differ_l) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__larger_mantissa_sign_l;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum 
            = (0x3fffU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__larger_mantissa_l) 
                          - (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__smaller_mantissa_l)));
    } else {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__result_sign 
            = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_shifted_l) 
               & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_not_shifted_l));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum 
            = (0x3fffU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__smaller_mantissa_l) 
                          + (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__larger_mantissa_l)));
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_overflow 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum) 
                 >> 0xdU));
    if (vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__signs_differ_l) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__result_sign 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__larger_mantissa_sign_l;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum 
            = (0x3fffU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__larger_mantissa_l) 
                          - (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__smaller_mantissa_l)));
    } else {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__result_sign 
            = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_shifted_l) 
               & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sign_not_shifted_l));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum 
            = (0x3fffU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__smaller_mantissa_l) 
                          + (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__larger_mantissa_l)));
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_overflow 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum) 
                 >> 0xdU));
    if (vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__signs_differ_l) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__result_sign 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__larger_mantissa_sign_l;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum 
            = (0x3fffU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__larger_mantissa_l) 
                          - (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__smaller_mantissa_l)));
    } else {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__result_sign 
            = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_shifted_l) 
               & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sign_not_shifted_l));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum 
            = (0x3fffU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__smaller_mantissa_l) 
                          + (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__larger_mantissa_l)));
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_overflow 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum) 
                 >> 0xdU));
    if (((((((((0x800U == (0x1800U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))) 
               | (0x400U == (0x1c00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum)))) 
              | (0x200U == (0x1e00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum)))) 
             | (0x100U == (0x1f00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum)))) 
            | (0x80U == (0x1f80U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum)))) 
           | (0x40U == (0x1fc0U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum)))) 
          | (0x20U == (0x1fe0U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum)))) 
         | (0x10U == (0x1ff0U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))))) {
        if ((0x800U == (0x1800U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum)))) {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT____Vcellout__normalizer__shifted_amount = 1U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1ffeU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum) 
                                         << 1U)));
        } else if ((0x400U == (0x1c00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum)))) {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT____Vcellout__normalizer__shifted_amount = 2U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1ffcU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum) 
                                         << 2U)));
        } else if ((0x200U == (0x1e00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum)))) {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT____Vcellout__normalizer__shifted_amount = 3U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1ff8U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum) 
                                         << 3U)));
        } else if ((0x100U == (0x1f00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum)))) {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT____Vcellout__normalizer__shifted_amount = 4U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1ff0U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum) 
                                         << 4U)));
        } else if ((0x80U == (0x1f80U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum)))) {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT____Vcellout__normalizer__shifted_amount = 5U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1fe0U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum) 
                                         << 5U)));
        } else if ((0x40U == (0x1fc0U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum)))) {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT____Vcellout__normalizer__shifted_amount = 6U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1fc0U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum) 
                                         << 6U)));
        } else if ((0x20U == (0x1fe0U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum)))) {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT____Vcellout__normalizer__shifted_amount = 7U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1f80U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum) 
                                         << 7U)));
        } else {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT____Vcellout__normalizer__shifted_amount = 8U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1f00U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum) 
                                         << 8U)));
        }
    } else if ((8U == (0x1ff8U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum)))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT____Vcellout__normalizer__shifted_amount = 9U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__normalized_mantissa_sum 
            = (0x1fffU & (0x1e00U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum) 
                                     << 9U)));
    } else if ((4U == (0x1ffcU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum)))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT____Vcellout__normalizer__shifted_amount = 0xaU;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__normalized_mantissa_sum 
            = (0x1fffU & (0x1c00U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum) 
                                     << 0xaU)));
    } else if ((2U == (0x1ffeU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum)))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT____Vcellout__normalizer__shifted_amount = 0xbU;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__normalized_mantissa_sum 
            = (0x1fffU & (0x1800U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum) 
                                     << 0xbU)));
    } else if ((1U == (0x1fffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum)))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT____Vcellout__normalizer__shifted_amount = 0xcU;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__normalized_mantissa_sum 
            = (0x1fffU & (0x1000U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum) 
                                     << 0xcU)));
    } else {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT____Vcellout__normalizer__shifted_amount = 0U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__normalized_mantissa_sum 
            = (0x1fffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum));
    }
    if (((((((((0x800U == (0x1800U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum))) 
               | (0x400U == (0x1c00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum)))) 
              | (0x200U == (0x1e00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum)))) 
             | (0x100U == (0x1f00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum)))) 
            | (0x80U == (0x1f80U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum)))) 
           | (0x40U == (0x1fc0U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum)))) 
          | (0x20U == (0x1fe0U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum)))) 
         | (0x10U == (0x1ff0U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum))))) {
        if ((0x800U == (0x1800U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum)))) {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT____Vcellout__normalizer__shifted_amount = 1U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1ffeU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum) 
                                         << 1U)));
        } else if ((0x400U == (0x1c00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum)))) {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT____Vcellout__normalizer__shifted_amount = 2U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1ffcU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum) 
                                         << 2U)));
        } else if ((0x200U == (0x1e00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum)))) {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT____Vcellout__normalizer__shifted_amount = 3U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1ff8U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum) 
                                         << 3U)));
        } else if ((0x100U == (0x1f00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum)))) {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT____Vcellout__normalizer__shifted_amount = 4U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1ff0U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum) 
                                         << 4U)));
        } else if ((0x80U == (0x1f80U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum)))) {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT____Vcellout__normalizer__shifted_amount = 5U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1fe0U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum) 
                                         << 5U)));
        } else if ((0x40U == (0x1fc0U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum)))) {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT____Vcellout__normalizer__shifted_amount = 6U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1fc0U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum) 
                                         << 6U)));
        } else if ((0x20U == (0x1fe0U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum)))) {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT____Vcellout__normalizer__shifted_amount = 7U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1f80U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum) 
                                         << 7U)));
        } else {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT____Vcellout__normalizer__shifted_amount = 8U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1f00U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum) 
                                         << 8U)));
        }
    } else if ((8U == (0x1ff8U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum)))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT____Vcellout__normalizer__shifted_amount = 9U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__normalized_mantissa_sum 
            = (0x1fffU & (0x1e00U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum) 
                                     << 9U)));
    } else if ((4U == (0x1ffcU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum)))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT____Vcellout__normalizer__shifted_amount = 0xaU;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__normalized_mantissa_sum 
            = (0x1fffU & (0x1c00U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum) 
                                     << 0xaU)));
    } else if ((2U == (0x1ffeU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum)))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT____Vcellout__normalizer__shifted_amount = 0xbU;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__normalized_mantissa_sum 
            = (0x1fffU & (0x1800U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum) 
                                     << 0xbU)));
    } else if ((1U == (0x1fffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum)))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT____Vcellout__normalizer__shifted_amount = 0xcU;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__normalized_mantissa_sum 
            = (0x1fffU & (0x1000U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum) 
                                     << 0xcU)));
    } else {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT____Vcellout__normalizer__shifted_amount = 0U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__normalized_mantissa_sum 
            = (0x1fffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum));
    }
    if (((((((((0x800U == (0x1800U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum))) 
               | (0x400U == (0x1c00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum)))) 
              | (0x200U == (0x1e00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum)))) 
             | (0x100U == (0x1f00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum)))) 
            | (0x80U == (0x1f80U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum)))) 
           | (0x40U == (0x1fc0U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum)))) 
          | (0x20U == (0x1fe0U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum)))) 
         | (0x10U == (0x1ff0U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum))))) {
        if ((0x800U == (0x1800U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum)))) {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT____Vcellout__normalizer__shifted_amount = 1U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1ffeU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum) 
                                         << 1U)));
        } else if ((0x400U == (0x1c00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum)))) {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT____Vcellout__normalizer__shifted_amount = 2U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1ffcU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum) 
                                         << 2U)));
        } else if ((0x200U == (0x1e00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum)))) {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT____Vcellout__normalizer__shifted_amount = 3U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1ff8U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum) 
                                         << 3U)));
        } else if ((0x100U == (0x1f00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum)))) {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT____Vcellout__normalizer__shifted_amount = 4U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1ff0U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum) 
                                         << 4U)));
        } else if ((0x80U == (0x1f80U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum)))) {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT____Vcellout__normalizer__shifted_amount = 5U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1fe0U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum) 
                                         << 5U)));
        } else if ((0x40U == (0x1fc0U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum)))) {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT____Vcellout__normalizer__shifted_amount = 6U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1fc0U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum) 
                                         << 6U)));
        } else if ((0x20U == (0x1fe0U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum)))) {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT____Vcellout__normalizer__shifted_amount = 7U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1f80U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum) 
                                         << 7U)));
        } else {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT____Vcellout__normalizer__shifted_amount = 8U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1f00U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum) 
                                         << 8U)));
        }
    } else if ((8U == (0x1ff8U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum)))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT____Vcellout__normalizer__shifted_amount = 9U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__normalized_mantissa_sum 
            = (0x1fffU & (0x1e00U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum) 
                                     << 9U)));
    } else if ((4U == (0x1ffcU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum)))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT____Vcellout__normalizer__shifted_amount = 0xaU;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__normalized_mantissa_sum 
            = (0x1fffU & (0x1c00U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum) 
                                     << 0xaU)));
    } else if ((2U == (0x1ffeU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum)))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT____Vcellout__normalizer__shifted_amount = 0xbU;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__normalized_mantissa_sum 
            = (0x1fffU & (0x1800U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum) 
                                     << 0xbU)));
    } else if ((1U == (0x1fffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum)))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT____Vcellout__normalizer__shifted_amount = 0xcU;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__normalized_mantissa_sum 
            = (0x1fffU & (0x1000U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum) 
                                     << 0xcU)));
    } else {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT____Vcellout__normalizer__shifted_amount = 0U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__normalized_mantissa_sum 
            = (0x1fffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum));
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_norm_s 
        = ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__normalized_mantissa_sum))
            ? 0U : (0x7fU & (VL_EXTENDS_II(7,6, (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_max_l)) 
                             - (0xfU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT____Vcellout__normalizer__shifted_amount)))));
    if (vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_overflow) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__round_this 
            = (0xfffU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum) 
                         >> 1U));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__round_this 
            = ((0xffeU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__round_this)) 
               | (1U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__round_this) 
                        | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_sum))));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_base 
            = (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_max_l)));
    } else {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__round_this 
            = (0xfffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__normalized_mantissa_sum));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_base 
            = (0x3fU & (VL_GTES_III(7, 0U, (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_norm_s))
                         ? 0U : (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_norm_s)));
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_norm_s 
        = ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__normalized_mantissa_sum))
            ? 0U : (0x7fU & (VL_EXTENDS_II(7,6, (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_max_l)) 
                             - (0xfU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT____Vcellout__normalizer__shifted_amount)))));
    if (vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_overflow) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__round_this 
            = (0xfffU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum) 
                         >> 1U));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__round_this 
            = ((0xffeU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__round_this)) 
               | (1U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__round_this) 
                        | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum))));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_base 
            = (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_max_l)));
    } else {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__round_this 
            = (0xfffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__normalized_mantissa_sum));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_base 
            = (0x3fU & (VL_GTES_III(7, 0U, (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_norm_s))
                         ? 0U : (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_norm_s)));
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_norm_s 
        = ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__normalized_mantissa_sum))
            ? 0U : (0x7fU & (VL_EXTENDS_II(7,6, (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_max_l)) 
                             - (0xfU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT____Vcellout__normalizer__shifted_amount)))));
    if (vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_overflow) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__round_this 
            = (0xfffU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum) 
                         >> 1U));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__round_this 
            = ((0xffeU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__round_this)) 
               | (1U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__round_this) 
                        | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum))));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_base 
            = (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_max_l)));
    } else {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__round_this 
            = (0xfffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__normalized_mantissa_sum));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_base 
            = (0x3fU & (VL_GTES_III(7, 0U, (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_norm_s))
                         ? 0U : (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_norm_s)));
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__ftz_under 
        = ((1U & (~ (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mantissa_overflow))) 
           && VL_GTES_III(7, 0U, (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_norm_s)));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__ftz_under 
        = ((1U & (~ (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_overflow))) 
           && VL_GTES_III(7, 0U, (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_norm_s)));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__ftz_under 
        = ((1U & (~ (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_overflow))) 
           && VL_GTES_III(7, 0U, (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_norm_s)));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__round_inc 
        = ((1U & (~ (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__signs_differ_l) 
                      & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sub_has_lost_sticky_l)) 
                     & (2U == (3U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__round_this)))))) 
           && ((((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__signs_differ_l) 
                 & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sub_has_added_sticky_l)) 
                & (2U == (3U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__round_this)))) 
               || (1U & (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__round_this) 
                          >> 1U) & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__round_this) 
                                    | ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__round_this) 
                                       >> 2U))))));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_sum 
        = (0x7ffU & ((0x3ffU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__round_this) 
                                >> 2U)) + (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__round_inc)));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_carry 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_sum) 
                 >> 0xaU));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out 
        = (0x3fU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_base) 
                    + (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_carry)));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_carry)
            ? 0U : (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_sum)));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__round_inc 
        = ((1U & (~ (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__signs_differ_l) 
                      & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sub_has_lost_sticky_l)) 
                     & (2U == (3U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__round_this)))))) 
           && ((((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__signs_differ_l) 
                 & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__sub_has_added_sticky_l)) 
                & (2U == (3U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__round_this)))) 
               || (1U & (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__round_this) 
                          >> 1U) & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__round_this) 
                                    | ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__round_this) 
                                       >> 2U))))));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_sum 
        = (0x7ffU & ((0x3ffU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__round_this) 
                                >> 2U)) + (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__round_inc)));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_carry 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_sum) 
                 >> 0xaU));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_out 
        = (0x3fU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_base) 
                    + (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_carry)));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__rounded_fraction 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_carry)
            ? 0U : (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__frac_sum)));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__round_inc 
        = ((1U & (~ (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__signs_differ_l) 
                      & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sub_has_lost_sticky_l)) 
                     & (2U == (3U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__round_this)))))) 
           && ((((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__signs_differ_l) 
                 & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__sub_has_added_sticky_l)) 
                & (2U == (3U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__round_this)))) 
               || (1U & (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__round_this) 
                          >> 1U) & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__round_this) 
                                    | ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__round_this) 
                                       >> 2U))))));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_sum 
        = (0x7ffU & ((0x3ffU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__round_this) 
                                >> 2U)) + (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__round_inc)));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_carry 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_sum) 
                 >> 0xaU));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_out 
        = (0x3fU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_base) 
                    + (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_carry)));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__rounded_fraction 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_carry)
            ? 0U : (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__frac_sum)));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__overflow 
        = (0x1eU < (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out));
    if (vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__overflow) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final = 0x1fU;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final = 0U;
    } else {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out_final 
            = (0x1fU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_out));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction_final 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__rounded_fraction;
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__overflow 
        = (0x1eU < (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_out));
    if (vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__overflow) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_out_final = 0x1fU;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__rounded_fraction_final = 0U;
    } else {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_out_final 
            = (0x1fU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_out));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__rounded_fraction_final 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__rounded_fraction;
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__overflow 
        = (0x1eU < (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_out));
    if (vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__overflow) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_out_final = 0x1fU;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__rounded_fraction_final = 0U;
    } else {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_out_final 
            = (0x1fU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_out));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__rounded_fraction_final 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__rounded_fraction;
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__a 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_case_l)
            ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__special_result_l)
            : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__mantissa_sum))
                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__result_sign) 
                   << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__ftz_under)
                                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__result_sign) 
                                   << 0xfU) : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__result_sign) 
                                                << 0xfU) 
                                               | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_ab__DOT__rounded_fraction_final))))));
    if ((IData)(((0U == (0x7c00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__a))) 
                 & (0U != (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__a)))))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__a 
            = (0x8000U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__a));
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__b 
        = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_case_l)
            ? (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__special_result_l)
            : ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__mantissa_sum))
                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__result_sign) 
                   << 0xfU) : ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__ftz_under)
                                ? ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__result_sign) 
                                   << 0xfU) : (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__result_sign) 
                                                << 0xfU) 
                                               | (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_cd__DOT__rounded_fraction_final))))));
    if ((IData)(((0U == (0x7c00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__b))) 
                 & (0U != (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__b)))))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__b 
            = (0x8000U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__b));
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__is_nan_a 
        = (IData)(((0x7c00U == (0x7c00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__a))) 
                   & (0U != (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__a)))));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__is_nan_b 
        = (IData)(((0x7c00U == (0x7c00U & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__b))) 
                   & (0U != (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__b)))));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__is_inf_a 
        = (IData)((0x7c00U == (0x7fffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__a))));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__is_inf_b 
        = (IData)((0x7c00U == (0x7fffU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__b))));
    if (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__is_nan_a) 
         | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__is_nan_b))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case = 1U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result = 0x7e00U;
    } else if (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__is_inf_a) 
                & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__is_inf_b))) {
        if (((1U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__a) 
                    >> 0xfU)) == (1U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__b) 
                                        >> 0xfU)))) {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case = 1U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result 
                = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__a;
        } else {
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case = 1U;
            vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result = 0x7e00U;
        }
    } else if (vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__is_inf_a) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case = 1U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__a;
    } else if (vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__is_inf_b) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_case = 1U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__special_result 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__b;
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__op_swap 
        = ((0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__a) 
                     >> 0xaU)) < (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__b) 
                                           >> 0xaU)));
    if (vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__op_swap) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__high_op 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__b;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__low_op 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__a;
    } else {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__high_op 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__a;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__low_op 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__b;
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__high_exp 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__high_op) 
                    >> 0xaU));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__low_exp 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__low_op) 
                    >> 0xaU));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_diff 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__high_exp) 
                    - (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__low_exp)));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_max 
        = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__high_exp;
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_hi 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__high_exp))) 
            << 0xcU) | (0xffcU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__high_op) 
                                  << 2U)));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_lo 
        = (((IData)((0U != (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__low_exp))) 
            << 0xcU) | (0xffcU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__low_op) 
                                  << 2U)));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_lo_aligned = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sticky_align_local = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sticky_lost = 0U;
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mask_align = 0U;
    if ((0xdU <= (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_diff))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_lo_aligned = 0U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sticky_lost = 0U;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_lo_aligned 
            = ((0x1ffeU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_lo_aligned)) 
               | (0U != (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_lo)));
    } else if ((0U == (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_diff))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_lo_aligned 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_lo;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sticky_lost = 0U;
    } else {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_lo_aligned 
            = (0x1fffU & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_lo) 
                          >> (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_diff)));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mask_align 
            = (0x1fffU & (((IData)(1U) << (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__exp_diff)) 
                          - (IData)(1U)));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sticky_align_local 
            = (0U != ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_lo) 
                      & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mask_align)));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sticky_lost 
            = ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sticky_align_local) 
               & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_lo_aligned));
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_lo_aligned 
            = ((0x1ffeU & (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_lo_aligned)) 
               | (1U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_lo_aligned) 
                        | (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sticky_align_local))));
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_not_shifted 
        = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_hi;
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_shifted 
        = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__mant_lo_aligned;
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_not_shifted 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__high_op) 
                 >> 0xfU));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_shifted 
        = (1U & ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__low_op) 
                 >> 0xfU));
    if (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_shifted) 
         > (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_not_shifted))) {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__smaller_mantissa 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_not_shifted;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__larger_mantissa 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_shifted;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__larger_mantissa_sign 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_shifted;
    } else {
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__smaller_mantissa 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_shifted;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__larger_mantissa 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_not_shifted;
        vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__larger_mantissa_sign 
            = vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sign_not_shifted;
    }
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sub_has_lost_sticky 
        = (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_shifted) 
            <= (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_not_shifted)) 
           && (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sticky_lost));
    vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sub_has_added_sticky 
        = (((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_shifted) 
            <= (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__frac_not_shifted)) 
           && ((IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sticky_align_local) 
               & (~ (IData)(vlSelfRef.add4_fp16_tb_full__DOT__dut__DOT__u_sum__DOT__sticky_lost))));
}

void Vadd4_fp16_tb_full___024root___timing_resume(Vadd4_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_full___024root___timing_resume\n"); );
    Vadd4_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h91ae8b3f__0.resume(
                                                   "@(negedge add4_fp16_tb_full.tb_clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vadd4_fp16_tb_full___024root___timing_commit(Vadd4_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_full___024root___timing_commit\n"); );
    Vadd4_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (8ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h91ae8b3f__0.commit(
                                                   "@(negedge add4_fp16_tb_full.tb_clk)");
    }
}

void Vadd4_fp16_tb_full___024root___eval_triggers__act(Vadd4_fp16_tb_full___024root* vlSelf);

bool Vadd4_fp16_tb_full___024root___eval_phase__act(Vadd4_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_full___024root___eval_phase__act\n"); );
    Vadd4_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vadd4_fp16_tb_full___024root___eval_triggers__act(vlSelf);
    Vadd4_fp16_tb_full___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vadd4_fp16_tb_full___024root___timing_resume(vlSelf);
        Vadd4_fp16_tb_full___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vadd4_fp16_tb_full___024root___eval_phase__nba(Vadd4_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_full___024root___eval_phase__nba\n"); );
    Vadd4_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vadd4_fp16_tb_full___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp16_tb_full___024root___dump_triggers__nba(Vadd4_fp16_tb_full___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp16_tb_full___024root___dump_triggers__act(Vadd4_fp16_tb_full___024root* vlSelf);
#endif  // VL_DEBUG

void Vadd4_fp16_tb_full___024root___eval(Vadd4_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_full___024root___eval\n"); );
    Vadd4_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vadd4_fp16_tb_full___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/unit/systolic_array/add4_fp16_tb_full.sv", 8, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vadd4_fp16_tb_full___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/unit/systolic_array/add4_fp16_tb_full.sv", 8, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vadd4_fp16_tb_full___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vadd4_fp16_tb_full___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vadd4_fp16_tb_full___024root___eval_debug_assertions(Vadd4_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_full___024root___eval_debug_assertions\n"); );
    Vadd4_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
