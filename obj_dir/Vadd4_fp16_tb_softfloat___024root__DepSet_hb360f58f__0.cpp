// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd4_fp16_tb_softfloat.h for the primary calling header

#include "Vadd4_fp16_tb_softfloat__pch.h"
#include "Vadd4_fp16_tb_softfloat__Syms.h"
#include "Vadd4_fp16_tb_softfloat___024root.h"

extern const VlWide<13>/*415:0*/ Vadd4_fp16_tb_softfloat__ConstPool__CONST_h07642e36_0;

VL_INLINE_OPT VlCoroutine Vadd4_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__0(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    std::string add4_fp16_tb_softfloat__DOT__header;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__0__a;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__0__a = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__0__b;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__0__b = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__0__c;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__0__c = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__0__d;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__0__d = 0;
    std::string __Vtask_add4_fp16_tb_softfloat__DOT__check_case__1__casename;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__check_case__1__expected;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__1__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__check_case__1__match;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__1__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__2__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__2__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__2__val;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__2__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__3__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__3__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__3__val;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__3__val = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__4__a;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__4__a = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__4__b;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__4__b = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__4__c;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__4__c = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__4__d;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__4__d = 0;
    std::string __Vtask_add4_fp16_tb_softfloat__DOT__check_case__5__casename;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__check_case__5__expected;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__5__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__check_case__5__match;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__5__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__6__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__6__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__6__val;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__6__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__7__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__7__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__7__val;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__7__val = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__8__a;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__8__a = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__8__b;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__8__b = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__8__c;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__8__c = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__8__d;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__8__d = 0;
    std::string __Vtask_add4_fp16_tb_softfloat__DOT__check_case__9__casename;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__check_case__9__expected;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__9__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__check_case__9__match;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__9__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__10__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__10__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__10__val;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__10__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__11__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__11__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__11__val;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__11__val = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__12__a;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__12__a = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__12__b;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__12__b = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__12__c;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__12__c = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__12__d;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__12__d = 0;
    std::string __Vtask_add4_fp16_tb_softfloat__DOT__check_case__13__casename;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__check_case__13__expected;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__13__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__check_case__13__match;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__13__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__14__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__14__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__14__val;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__14__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__15__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__15__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__15__val;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__15__val = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__16__a;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__16__a = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__16__b;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__16__b = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__16__c;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__16__c = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__16__d;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__16__d = 0;
    std::string __Vtask_add4_fp16_tb_softfloat__DOT__check_case__17__casename;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__check_case__17__expected;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__17__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__check_case__17__match;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__17__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__18__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__18__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__18__val;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__18__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__19__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__19__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__19__val;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__19__val = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__20__a;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__20__a = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__20__b;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__20__b = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__20__c;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__20__c = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__20__d;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__20__d = 0;
    std::string __Vtask_add4_fp16_tb_softfloat__DOT__check_case__21__casename;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__check_case__21__expected;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__21__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__check_case__21__match;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__21__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__22__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__22__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__22__val;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__22__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__23__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__23__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__23__val;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__23__val = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__24__a;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__24__a = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__24__b;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__24__b = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__24__c;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__24__c = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__24__d;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__24__d = 0;
    std::string __Vtask_add4_fp16_tb_softfloat__DOT__check_case__25__casename;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__check_case__25__expected;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__25__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__check_case__25__match;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__25__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__26__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__26__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__26__val;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__26__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__27__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__27__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__27__val;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__27__val = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__28__a;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__28__a = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__28__b;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__28__b = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__28__c;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__28__c = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__28__d;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__28__d = 0;
    std::string __Vtask_add4_fp16_tb_softfloat__DOT__check_case__29__casename;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__check_case__29__expected;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__29__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__check_case__29__match;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__29__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__30__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__30__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__30__val;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__30__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__31__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__31__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__31__val;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__31__val = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__32__a;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__32__a = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__32__b;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__32__b = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__32__c;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__32__c = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__32__d;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__32__d = 0;
    std::string __Vtask_add4_fp16_tb_softfloat__DOT__check_case__33__casename;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__check_case__33__expected;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__33__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__check_case__33__match;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__33__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__34__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__34__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__34__val;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__34__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__35__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__35__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__35__val;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__35__val = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__36__a;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__36__a = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__36__b;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__36__b = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__36__c;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__36__c = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__36__d;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__36__d = 0;
    std::string __Vtask_add4_fp16_tb_softfloat__DOT__check_case__37__casename;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__check_case__37__expected;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__37__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__check_case__37__match;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__37__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__38__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__38__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__38__val;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__38__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__39__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__39__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__39__val;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__39__val = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__40__a;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__40__a = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__40__b;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__40__b = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__40__c;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__40__c = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__40__d;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__40__d = 0;
    std::string __Vtask_add4_fp16_tb_softfloat__DOT__check_case__41__casename;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__check_case__41__expected;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__41__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__check_case__41__match;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__41__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__42__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__42__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__42__val;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__42__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__43__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__43__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__43__val;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__43__val = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__44__a;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__44__a = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__44__b;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__44__b = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__44__c;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__44__c = 0;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__test_case__44__d;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__44__d = 0;
    std::string __Vtask_add4_fp16_tb_softfloat__DOT__check_case__45__casename;
    SData/*15:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__check_case__45__expected;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__45__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp16_tb_softfloat__DOT__check_case__45__match;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__45__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__46__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__46__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__46__val;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__46__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__47__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__47__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__47__val;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__47__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__48__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__48__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__48__val;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__48__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__49__Vfuncout;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__49__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__49__val;
    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__49__val = 0;
    VlWide<7>/*223:0*/ __Vtemp_1;
    VlWide<6>/*191:0*/ __Vtemp_2;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x61766573U;
    __Vtemp_1[2U] = 0x31365f77U;
    __Vtemp_1[3U] = 0x345f6670U;
    __Vtemp_1[4U] = 0x2f616464U;
    __Vtemp_1[5U] = 0x61766573U;
    __Vtemp_1[6U] = 0x77U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(7, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    __Vtemp_2[0U] = 0x2e637376U;
    __Vtemp_2[1U] = 0x70757265U;
    __Vtemp_2[2U] = 0x7265735fU;
    __Vtemp_2[3U] = 0x61696c75U;
    __Vtemp_2[4U] = 0x73745f66U;
    __Vtemp_2[5U] = 0x7465U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_fd 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(6, __Vtemp_2)
                      , std::string{"w"});
    ;
    VL_FWRITEF_NX(vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_fd,"a,b,c,d,expected,got\n",0);
    vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count = 0U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count = 0U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__off_by_one = 0U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__off_by_two = 0U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_nrst = 0U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a = 0U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b = 0U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c = 0U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                         139);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_nrst = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                         141);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("--- Hardcoded 4-input Addition Cases ---\n",0);
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__0__d = 0x3c00U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__0__c = 0x3c00U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__0__b = 0x3c00U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__0__a = 0x3c00U;
    co_await vlSelfRef.__VtrigSched_h88600c86__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                                         72);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__0__a;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__0__b;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__0__c;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__0__d;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__exp = 0x4400U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                         148);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__1__expected 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__1__casename = 
        std::string{"1+1+1+1 = 4"};
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__1__match = 0;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__1__match 
        = ((([&]() {
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__2__val 
                        = vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out;
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__2__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__2__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__2__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__2__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__3__val 
                        = __Vtask_add4_fp16_tb_softfloat__DOT__check_case__1__expected;
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__3__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__3__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__3__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__3__Vfuncout))) 
           || ((IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out) 
               == (IData)(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__1__expected)));
    if (VL_LIKELY((__Vtask_add4_fp16_tb_softfloat__DOT__check_case__1__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__1__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__1__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out),
                     16,__Vtask_add4_fp16_tb_softfloat__DOT__check_case__1__expected);
        VL_FWRITEF_NX(vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a,
                      16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b),
                      16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c,
                      16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d),
                      16,__Vtask_add4_fp16_tb_softfloat__DOT__check_case__1__expected,
                      16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                         150);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__4__d = 0x4000U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__4__c = 0x4000U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__4__b = 0x4000U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__4__a = 0x4000U;
    co_await vlSelfRef.__VtrigSched_h88600c86__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                                         72);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__4__a;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__4__b;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__4__c;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__4__d;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__exp = 0x4800U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                         155);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__5__expected 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__5__casename = 
        std::string{"2+2+2+2 = 8"};
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__5__match = 0;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__5__match 
        = ((([&]() {
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__6__val 
                        = vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out;
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__6__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__6__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__6__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__6__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__7__val 
                        = __Vtask_add4_fp16_tb_softfloat__DOT__check_case__5__expected;
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__7__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__7__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__7__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__7__Vfuncout))) 
           || ((IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out) 
               == (IData)(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__5__expected)));
    if (VL_LIKELY((__Vtask_add4_fp16_tb_softfloat__DOT__check_case__5__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__5__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__5__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out),
                     16,__Vtask_add4_fp16_tb_softfloat__DOT__check_case__5__expected);
        VL_FWRITEF_NX(vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a,
                      16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b),
                      16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c,
                      16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d),
                      16,__Vtask_add4_fp16_tb_softfloat__DOT__check_case__5__expected,
                      16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                         157);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__8__d = 0U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__8__c = 0U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__8__b = 0U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__8__a = 0U;
    co_await vlSelfRef.__VtrigSched_h88600c86__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                                         72);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__8__a;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__8__b;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__8__c;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__8__d;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__exp = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                         162);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__9__expected 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__9__casename = 
        std::string{"0+0+0+0 = 0"};
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__9__match = 0;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__9__match 
        = ((([&]() {
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__10__val 
                        = vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out;
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__10__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__10__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__10__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__10__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__11__val 
                        = __Vtask_add4_fp16_tb_softfloat__DOT__check_case__9__expected;
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__11__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__11__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__11__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__11__Vfuncout))) 
           || ((IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out) 
               == (IData)(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__9__expected)));
    if (VL_LIKELY((__Vtask_add4_fp16_tb_softfloat__DOT__check_case__9__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__9__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__9__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out),
                     16,__Vtask_add4_fp16_tb_softfloat__DOT__check_case__9__expected);
        VL_FWRITEF_NX(vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a,
                      16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b),
                      16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c,
                      16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d),
                      16,__Vtask_add4_fp16_tb_softfloat__DOT__check_case__9__expected,
                      16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                         164);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__12__d = 0U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__12__c = 0U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__12__b = 0U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__12__a = 0x3c00U;
    co_await vlSelfRef.__VtrigSched_h88600c86__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                                         72);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__12__a;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__12__b;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__12__c;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__12__d;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__exp = 0x3c00U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                         169);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__13__expected 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__13__casename = 
        std::string{"1+0+0+0 = 1"};
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__13__match = 0;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__13__match 
        = ((([&]() {
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__14__val 
                        = vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out;
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__14__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__14__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__14__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__14__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__15__val 
                        = __Vtask_add4_fp16_tb_softfloat__DOT__check_case__13__expected;
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__15__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__15__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__15__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__15__Vfuncout))) 
           || ((IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out) 
               == (IData)(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__13__expected)));
    if (VL_LIKELY((__Vtask_add4_fp16_tb_softfloat__DOT__check_case__13__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__13__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__13__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out),
                     16,__Vtask_add4_fp16_tb_softfloat__DOT__check_case__13__expected);
        VL_FWRITEF_NX(vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a,
                      16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b),
                      16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c,
                      16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d),
                      16,__Vtask_add4_fp16_tb_softfloat__DOT__check_case__13__expected,
                      16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                         171);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__16__d = 0x3c00U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__16__c = 0x3c00U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__16__b = 0x3c00U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__16__a = 0x7c00U;
    co_await vlSelfRef.__VtrigSched_h88600c86__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                                         72);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__16__a;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__16__b;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__16__c;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__16__d;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__exp = 0x7c00U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                         176);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__17__expected 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__17__casename = 
        std::string{"Inf+1+1+1 = Inf"};
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__17__match = 0;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__17__match 
        = ((([&]() {
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__18__val 
                        = vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out;
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__18__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__18__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__18__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__18__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__19__val 
                        = __Vtask_add4_fp16_tb_softfloat__DOT__check_case__17__expected;
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__19__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__19__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__19__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__19__Vfuncout))) 
           || ((IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out) 
               == (IData)(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__17__expected)));
    if (VL_LIKELY((__Vtask_add4_fp16_tb_softfloat__DOT__check_case__17__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__17__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__17__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out),
                     16,__Vtask_add4_fp16_tb_softfloat__DOT__check_case__17__expected);
        VL_FWRITEF_NX(vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a,
                      16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b),
                      16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c,
                      16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d),
                      16,__Vtask_add4_fp16_tb_softfloat__DOT__check_case__17__expected,
                      16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                         178);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__20__d = 0x3c00U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__20__c = 0x3c00U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__20__b = 0x7c00U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__20__a = 0x7c00U;
    co_await vlSelfRef.__VtrigSched_h88600c86__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                                         72);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__20__a;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__20__b;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__20__c;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__20__d;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__exp = 0x7c00U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                         183);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__21__expected 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__21__casename = 
        std::string{"Inf+Inf+1+1 = Inf"};
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__21__match = 0;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__21__match 
        = ((([&]() {
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__22__val 
                        = vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out;
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__22__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__22__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__22__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__22__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__23__val 
                        = __Vtask_add4_fp16_tb_softfloat__DOT__check_case__21__expected;
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__23__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__23__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__23__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__23__Vfuncout))) 
           || ((IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out) 
               == (IData)(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__21__expected)));
    if (VL_LIKELY((__Vtask_add4_fp16_tb_softfloat__DOT__check_case__21__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__21__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__21__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out),
                     16,__Vtask_add4_fp16_tb_softfloat__DOT__check_case__21__expected);
        VL_FWRITEF_NX(vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a,
                      16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b),
                      16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c,
                      16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d),
                      16,__Vtask_add4_fp16_tb_softfloat__DOT__check_case__21__expected,
                      16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                         185);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__24__d = 0x3c00U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__24__c = 0x3c00U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__24__b = 0xfc00U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__24__a = 0x7c00U;
    co_await vlSelfRef.__VtrigSched_h88600c86__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                                         72);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__24__a;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__24__b;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__24__c;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__24__d;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__exp = 0x7d00U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                         190);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__25__expected 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__25__casename = 
        std::string{"+Inf + -Inf + 1 + 1 = NaN"};
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__25__match = 0;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__25__match 
        = ((([&]() {
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__26__val 
                        = vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out;
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__26__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__26__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__26__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__26__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__27__val 
                        = __Vtask_add4_fp16_tb_softfloat__DOT__check_case__25__expected;
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__27__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__27__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__27__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__27__Vfuncout))) 
           || ((IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out) 
               == (IData)(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__25__expected)));
    if (VL_LIKELY((__Vtask_add4_fp16_tb_softfloat__DOT__check_case__25__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__25__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__25__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out),
                     16,__Vtask_add4_fp16_tb_softfloat__DOT__check_case__25__expected);
        VL_FWRITEF_NX(vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a,
                      16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b),
                      16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c,
                      16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d),
                      16,__Vtask_add4_fp16_tb_softfloat__DOT__check_case__25__expected,
                      16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                         192);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__28__d = 0x3c00U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__28__c = 0x3c00U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__28__b = 0x3c00U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__28__a = 0x7d00U;
    co_await vlSelfRef.__VtrigSched_h88600c86__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                                         72);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__28__a;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__28__b;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__28__c;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__28__d;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__exp = 0x7d00U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                         197);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__29__expected 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__29__casename = 
        std::string{"NaN+1+1+1 = NaN"};
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__29__match = 0;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__29__match 
        = ((([&]() {
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__30__val 
                        = vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out;
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__30__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__30__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__30__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__30__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__31__val 
                        = __Vtask_add4_fp16_tb_softfloat__DOT__check_case__29__expected;
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__31__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__31__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__31__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__31__Vfuncout))) 
           || ((IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out) 
               == (IData)(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__29__expected)));
    if (VL_LIKELY((__Vtask_add4_fp16_tb_softfloat__DOT__check_case__29__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__29__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__29__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out),
                     16,__Vtask_add4_fp16_tb_softfloat__DOT__check_case__29__expected);
        VL_FWRITEF_NX(vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a,
                      16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b),
                      16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c,
                      16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d),
                      16,__Vtask_add4_fp16_tb_softfloat__DOT__check_case__29__expected,
                      16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                         199);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__32__d = 0x3c00U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__32__c = 0x3c00U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__32__b = 1U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__32__a = 1U;
    co_await vlSelfRef.__VtrigSched_h88600c86__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                                         72);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__32__a;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__32__b;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__32__c;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__32__d;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__exp = 0x4000U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                         204);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__33__expected 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__33__casename = 
        std::string{"sub+sub+1+1 = 2 (DAZ)"};
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__33__match = 0;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__33__match 
        = ((([&]() {
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__34__val 
                        = vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out;
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__34__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__34__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__34__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__34__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__35__val 
                        = __Vtask_add4_fp16_tb_softfloat__DOT__check_case__33__expected;
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__35__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__35__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__35__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__35__Vfuncout))) 
           || ((IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out) 
               == (IData)(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__33__expected)));
    if (VL_LIKELY((__Vtask_add4_fp16_tb_softfloat__DOT__check_case__33__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__33__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__33__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out),
                     16,__Vtask_add4_fp16_tb_softfloat__DOT__check_case__33__expected);
        VL_FWRITEF_NX(vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a,
                      16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b),
                      16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c,
                      16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d),
                      16,__Vtask_add4_fp16_tb_softfloat__DOT__check_case__33__expected,
                      16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                         206);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__36__d = 0x7bffU;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__36__c = 0x7bffU;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__36__b = 0x7bffU;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__36__a = 0x7bffU;
    co_await vlSelfRef.__VtrigSched_h88600c86__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                                         72);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__36__a;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__36__b;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__36__c;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__36__d;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__exp = 0x7c00U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                         211);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__37__expected 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__37__casename = 
        std::string{"max+max+max+max = Inf"};
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__37__match = 0;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__37__match 
        = ((([&]() {
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__38__val 
                        = vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out;
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__38__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__38__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__38__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__38__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__39__val 
                        = __Vtask_add4_fp16_tb_softfloat__DOT__check_case__37__expected;
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__39__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__39__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__39__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__39__Vfuncout))) 
           || ((IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out) 
               == (IData)(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__37__expected)));
    if (VL_LIKELY((__Vtask_add4_fp16_tb_softfloat__DOT__check_case__37__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__37__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__37__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out),
                     16,__Vtask_add4_fp16_tb_softfloat__DOT__check_case__37__expected);
        VL_FWRITEF_NX(vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a,
                      16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b),
                      16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c,
                      16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d),
                      16,__Vtask_add4_fp16_tb_softfloat__DOT__check_case__37__expected,
                      16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                         213);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__40__d = 0xbc00U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__40__c = 0x3c00U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__40__b = 0xbc00U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__40__a = 0x3c00U;
    co_await vlSelfRef.__VtrigSched_h88600c86__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                                         72);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__40__a;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__40__b;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__40__c;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__40__d;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__exp = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                         218);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__41__expected 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__41__casename = 
        std::string{"1+(-1)+1+(-1) = 0"};
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__41__match = 0;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__41__match 
        = ((([&]() {
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__42__val 
                        = vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out;
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__42__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__42__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__42__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__42__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__43__val 
                        = __Vtask_add4_fp16_tb_softfloat__DOT__check_case__41__expected;
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__43__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__43__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__43__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__43__Vfuncout))) 
           || ((IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out) 
               == (IData)(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__41__expected)));
    if (VL_LIKELY((__Vtask_add4_fp16_tb_softfloat__DOT__check_case__41__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__41__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__41__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out),
                     16,__Vtask_add4_fp16_tb_softfloat__DOT__check_case__41__expected);
        VL_FWRITEF_NX(vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a,
                      16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b),
                      16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c,
                      16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d),
                      16,__Vtask_add4_fp16_tb_softfloat__DOT__check_case__41__expected,
                      16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                         220);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__44__d = 0xc000U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__44__c = 0xc000U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__44__b = 0xc000U;
    __Vtask_add4_fp16_tb_softfloat__DOT__test_case__44__a = 0xc000U;
    co_await vlSelfRef.__VtrigSched_h88600c86__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                                         72);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__44__a;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__44__b;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__44__c;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d = __Vtask_add4_fp16_tb_softfloat__DOT__test_case__44__d;
    vlSelfRef.add4_fp16_tb_softfloat__DOT__exp = 0xc800U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                         226);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__45__expected 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__45__casename = 
        std::string{"-2+-2+-2+-2 = -8"};
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__45__match = 0;
    __Vtask_add4_fp16_tb_softfloat__DOT__check_case__45__match 
        = ((([&]() {
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__46__val 
                        = vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out;
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__46__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__46__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__46__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__46__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__47__val 
                        = __Vtask_add4_fp16_tb_softfloat__DOT__check_case__45__expected;
                    __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__47__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__47__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__47__val)))));
                }(), (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__47__Vfuncout))) 
           || ((IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out) 
               == (IData)(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__45__expected)));
    if (VL_LIKELY((__Vtask_add4_fp16_tb_softfloat__DOT__check_case__45__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__45__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp16_tb_softfloat__DOT__check_case__45__casename),
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out),
                     16,__Vtask_add4_fp16_tb_softfloat__DOT__check_case__45__expected);
        VL_FWRITEF_NX(vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a,
                      16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b),
                      16,vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c,
                      16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d),
                      16,__Vtask_add4_fp16_tb_softfloat__DOT__check_case__45__expected,
                      16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                         228);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("\n--- Berkeley SoftFloat Random Test Cases ---\n",0);
    vlSelfRef.add4_fp16_tb_softfloat__DOT__fd = VL_FOPEN_NN(
                                                            VL_CVT_PACK_STR_NW(13, Vadd4_fp16_tb_softfloat__ConstPool__CONST_h07642e36_0)
                                                            , 
                                                            std::string{"r"});
    ;
    if (VL_UNLIKELY(((0U == vlSelfRef.add4_fp16_tb_softfloat__DOT__fd)))) {
        VL_WRITEF_NX("error: could not open testfloat_cases_4_pure.csv\nmake sure it is in the right directory! check tb for pathing\n",0);
        VL_FINISH_MT("tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 237, "");
    }
    (void)VL_FGETS_NI(add4_fp16_tb_softfloat__DOT__header, vlSelfRef.add4_fp16_tb_softfloat__DOT__fd);
    while ((! (vlSelfRef.add4_fp16_tb_softfloat__DOT__fd ? feof(VL_CVT_I_FP(vlSelfRef.add4_fp16_tb_softfloat__DOT__fd)) : true))) {
        {
            vlSelfRef.add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__ret 
                = VL_FSCANF_INX(vlSelfRef.add4_fp16_tb_softfloat__DOT__fd,"%x,%x,%x,%x,%x\n",0,
                                16,&(vlSelfRef.add4_fp16_tb_softfloat__DOT__a),
                                16,&(vlSelfRef.add4_fp16_tb_softfloat__DOT__b),
                                16,&(vlSelfRef.add4_fp16_tb_softfloat__DOT__c),
                                16,&(vlSelfRef.add4_fp16_tb_softfloat__DOT__d),
                                16,&(vlSelfRef.add4_fp16_tb_softfloat__DOT__expected)) ;
            if ((5U != vlSelfRef.add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__ret)) {
                goto __Vlabel1;
            }
            vlSelfRef.add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__total_count 
                = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__total_count);
            co_await vlSelfRef.__VtrigSched_h88600c86__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge add4_fp16_tb_softfloat.tb_clk)", 
                                                                 "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                                                 252);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_a 
                = vlSelfRef.add4_fp16_tb_softfloat__DOT__a;
            vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_b 
                = vlSelfRef.add4_fp16_tb_softfloat__DOT__b;
            vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_c 
                = vlSelfRef.add4_fp16_tb_softfloat__DOT__c;
            vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_d 
                = vlSelfRef.add4_fp16_tb_softfloat__DOT__d;
            co_await vlSelfRef.__VdlySched.delay(0x1f40ULL, 
                                                 nullptr, 
                                                 "tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 
                                                 258);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSelfRef.add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__is_zero_result 
                = (((0U == (IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out)) 
                    | (0x8000U == (IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out))) 
                   & ((0U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__expected)) 
                      | (0x8000U == (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__expected))));
            if ((([&]() {
                            __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__48__val 
                                = vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out;
                            __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__48__Vfuncout 
                                = (IData)(((0x7c00U 
                                            == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__48__val))) 
                                           & (0U != 
                                              (0x3ffU 
                                               & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__48__val)))));
                        }(), (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__48__Vfuncout)) 
                 & ([&]() {
                            __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__49__val 
                                = vlSelfRef.add4_fp16_tb_softfloat__DOT__expected;
                            __Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__49__Vfuncout 
                                = (IData)(((0x7c00U 
                                            == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__49__val))) 
                                           & (0U != 
                                              (0x3ffU 
                                               & (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__49__val)))));
                        }(), (IData)(__Vfunc_add4_fp16_tb_softfloat__DOT__is_nan__49__Vfuncout)))) {
                vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count 
                    = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count);
            } else if (vlSelfRef.add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__is_zero_result) {
                vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count 
                    = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count);
            } else if (VL_UNLIKELY((((IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out) 
                                     != (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__expected))))) {
                VL_FWRITEF_NX(vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                              16,vlSelfRef.add4_fp16_tb_softfloat__DOT__a,
                              16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__b),
                              16,vlSelfRef.add4_fp16_tb_softfloat__DOT__c,
                              16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__d),
                              16,vlSelfRef.add4_fp16_tb_softfloat__DOT__expected,
                              16,(IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out));
                vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count 
                    = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count);
                if (VL_UNLIKELY((VL_GTES_III(32, 0xaU, vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count)))) {
                    VL_WRITEF_NX("FAIL: A=%x B=%x C=%x D=%x | Got=%x Exp=%x\n",0,
                                 16,vlSelfRef.add4_fp16_tb_softfloat__DOT__a,
                                 16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__b),
                                 16,vlSelfRef.add4_fp16_tb_softfloat__DOT__c,
                                 16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__d),
                                 16,vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out,
                                 16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__expected));
                } else if (VL_UNLIKELY(((0xbU == vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count)))) {
                    VL_WRITEF_NX("... (suppressing further terminal output, all failures logged to test_failures.csv) ...\n",0);
                }
                vlSelfRef.add4_fp16_tb_softfloat__DOT__diff 
                    = ((IData)(vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out) 
                       - (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__expected));
                if (((1U == vlSelfRef.add4_fp16_tb_softfloat__DOT__diff) 
                     | (0xffffffffU == vlSelfRef.add4_fp16_tb_softfloat__DOT__diff))) {
                    vlSelfRef.add4_fp16_tb_softfloat__DOT__off_by_one 
                        = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__off_by_one);
                } else if (((2U == vlSelfRef.add4_fp16_tb_softfloat__DOT__diff) 
                            | (0xfffffffeU == vlSelfRef.add4_fp16_tb_softfloat__DOT__diff))) {
                    vlSelfRef.add4_fp16_tb_softfloat__DOT__off_by_two 
                        = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__off_by_two);
                } else if (VL_UNLIKELY(((VL_LTES_III(32, 2U, vlSelfRef.add4_fp16_tb_softfloat__DOT__diff) 
                                         | VL_GTES_III(32, 0xfffffffeU, vlSelfRef.add4_fp16_tb_softfloat__DOT__diff))))) {
                    VL_WRITEF_NX("NOTE: off-by-two-plus detected in test case A=%x B=%x C=%x D=%x | Got=%x Exp=%x (diff=%0d)\n",0,
                                 16,vlSelfRef.add4_fp16_tb_softfloat__DOT__a,
                                 16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__b),
                                 16,vlSelfRef.add4_fp16_tb_softfloat__DOT__c,
                                 16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__d),
                                 16,vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out,
                                 16,(IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__expected),
                                 32,vlSelfRef.add4_fp16_tb_softfloat__DOT__diff);
                    vlSelfRef.add4_fp16_tb_softfloat__DOT__off_by_five_plus 
                        = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__off_by_five_plus);
                }
            } else {
                vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count 
                    = ((IData)(1U) + vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count);
            }
            if (VL_UNLIKELY(((0U == VL_MODDIVS_III(32, vlSelfRef.add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__total_count, (IData)(0x186a0U)))))) {
                VL_WRITEF_NX("progress: %0d tested (%0d pass, %0d fail)...\n",0,
                             32,vlSelfRef.add4_fp16_tb_softfloat__DOT__unnamedblk1__DOT__total_count,
                             32,vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count,
                             32,vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count);
            }
            __Vlabel1: ;
        }
    }
    VL_FCLOSE_I(vlSelfRef.add4_fp16_tb_softfloat__DOT__fd); VL_FCLOSE_I(vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_fd); VL_WRITEF_NX("\n=== test summary ===\nPRECISION BITS: 22\nPASSED: %0d\nFAILED: %0d\nOFF-BY-ONE: %0d\nOFF-BY-TWO: %0d\nOFF-BY-TWO-PLUS: %0d\nfailure cases logged to: test_failures_pure.csv\n",0,
                                                                                32,
                                                                                vlSelfRef.add4_fp16_tb_softfloat__DOT__pass_count,
                                                                                32,
                                                                                vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count,
                                                                                32,
                                                                                vlSelfRef.add4_fp16_tb_softfloat__DOT__off_by_one,
                                                                                32,
                                                                                vlSelfRef.add4_fp16_tb_softfloat__DOT__off_by_two,
                                                                                32,
                                                                                vlSelfRef.add4_fp16_tb_softfloat__DOT__off_by_five_plus);
    if ((0U == vlSelfRef.add4_fp16_tb_softfloat__DOT__fail_count)) {
        VL_WRITEF_NX("ALL TESTS PASSED!\n",0);
    } else {
        VL_WRITEF_NX("SOME TESTS FAILED!\n",0);
    }
    VL_FINISH_MT("tb/unit/systolic_array/add4_fp16_tb_softfloat.sv", 321, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp16_tb_softfloat___024root___dump_triggers__act(Vadd4_fp16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG

void Vadd4_fp16_tb_softfloat___024root___eval_triggers__act(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___eval_triggers__act\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__add4_fp16_tb_softfloat__DOT__tb_clk__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_nrst)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__add4_fp16_tb_softfloat__DOT__tb_nrst__0)));
    vlSelfRef.__VactTriggered.setBit(2U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__VactTriggered.setBit(3U, ((~ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_clk)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__add4_fp16_tb_softfloat__DOT__tb_clk__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__add4_fp16_tb_softfloat__DOT__tb_clk__0 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__add4_fp16_tb_softfloat__DOT__tb_nrst__0 
        = vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_nrst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vadd4_fp16_tb_softfloat___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vadd4_fp16_tb_softfloat___024root___nba_sequent__TOP__0(Vadd4_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp16_tb_softfloat___024root___nba_sequent__TOP__0\n"); );
    Vadd4_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_nrst) {
        vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__result_out;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_carry_vec 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__csa_c2;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_sum_vec 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__csa_s2;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_exp_base 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_e;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_spec_res 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_result;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_hot_ones 
            = (3U & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__y_op) 
                      + (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__m_op)) 
                     + (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__n_op)));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_e 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__exp_x;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_result 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_result;
    } else {
        vlSymsp->TOP__add4_fp16_tb_softfloat__DOT__add_if.out = 0U;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag = 0ULL;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_carry_vec = 0ULL;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_sum_vec = 0ULL;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_exp_base = 0U;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_spec_res = 0U;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_hot_ones = 0U;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_e = 0U;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_result = 0U;
    }
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__res_sign));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s 
        = ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sign_x));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special 
        = ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_case));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sticky 
        = ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_align_sticky));
    if ((0ULL != vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag)) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_special_case 
        = ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__special_case));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum 
        = (0x3fffffffffULL & ((VL_EXTENDS_QQ(38,37, vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_sum_vec) 
                               + VL_EXTENDS_QQ(38,37, 
                                               (0x1fffffffffULL 
                                                & VL_SHIFTL_QQI(37,37,32, vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_carry_vec, 1U)))) 
                              + (QData)((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_hot_ones))));
    if ((1U & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum 
                       >> 0x24U)))) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum 
            = (0xfffffffffULL & (1ULL + (~ vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum)));
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s)));
    } else {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__mag_sum 
            = (0xfffffffffULL & vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_sum);
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__res_sign 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_a_s;
    }
    if ((0ULL == vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag)) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan = 0ULL;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros = 0x23U;
    } else {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag;
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros = 0U;
        if ((0ULL == (0xfffffffffULL & VL_SHIFTR_QQI(36,36,32, vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 4U)))) {
            vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x20U) + (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)));
            vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan 
                = (0xfffffffffULL & VL_SHIFTL_QQI(36,36,32, vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0x20U));
        }
        if ((0ULL == (0xfffffffffULL & VL_SHIFTR_QQI(36,36,32, vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0x14U)))) {
            vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x10U) + (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)));
            vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan 
                = (0xfffffffffULL & VL_SHIFTL_QQI(36,36,32, vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0x10U));
        }
        if ((0ULL == (0xfffffffffULL & VL_SHIFTR_QQI(36,36,32, vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0x1cU)))) {
            vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros 
                = (0x7fU & ((IData)(8U) + (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)));
            vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan 
                = (0xfffffffffULL & VL_SHIFTL_QQI(36,36,32, vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 8U));
        }
        if ((0ULL == (0xfffffffffULL & VL_SHIFTR_QQI(36,36,32, vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0x20U)))) {
            vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros 
                = (0x7fU & ((IData)(4U) + (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)));
            vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan 
                = (0xfffffffffULL & VL_SHIFTL_QQI(36,36,32, vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 4U));
        }
        if ((0ULL == (0xfffffffffULL & VL_SHIFTR_QQI(36,36,32, vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0x22U)))) {
            vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros 
                = (0x7fU & ((IData)(2U) + (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)));
            vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan 
                = (0xfffffffffULL & VL_SHIFTL_QQI(36,36,32, vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 2U));
        }
        if ((0ULL == (0xfffffffffULL & VL_SHIFTR_QQI(36,36,32, vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0x23U)))) {
            vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros 
                = (0x7fU & ((IData)(1U) + (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)));
            vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan 
                = (0xfffffffffULL & VL_SHIFTL_QQI(36,36,32, vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 1U));
        }
    }
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val 
        = (0xfffffffffULL & VL_SHIFTL_QQI(36,36,7, vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag, (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_mant 
        = (0x3ffU & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val 
                             >> 0x19U)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__guard_bit 
        = (1U & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val 
                         >> 0x18U)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round_bit 
        = (1U & (IData)((vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val 
                         >> 0x17U)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_bit 
        = ((0U != (0x7fffffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val))) 
           | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sticky));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round_up 
        = ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__guard_bit) 
           & (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round_bit) 
               | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_bit)) 
              | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_mant)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mant_int 
        = (0x7ffU & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__raw_mant) 
                     + (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__round_up)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_mant 
        = ((0x400U & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mant_int))
            ? 0U : (0x3ffU & (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mant_int)));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc 
        = (0xffU & ((((IData)(2U) + VL_EXTENDS_II(8,7, (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(8,9, (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros))) 
                    + VL_EXTENDS_II(8,7, (1U & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__rounded_mant_int) 
                                                >> 0xaU)))));
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__result_out 
        = ((0ULL == vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag)
            ? ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign) 
               << 0xfU) : (VL_LTES_III(32, 0x1fU, VL_EXTENDS_II(32,8, (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc)))
                            ? (0x7c00U | ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign) 
                                          << 0xfU))
                            : (VL_GTES_III(32, 0U, 
                                           VL_EXTENDS_II(32,8, (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc)))
                                ? ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign) 
                                   << 0xfU) : (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign) 
                                                << 0xfU) 
                                               | ((0x7c00U 
                                                   & ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc) 
                                                      << 0xaU)) 
                                                  | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_mant))))));
    if (vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special) {
        vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__result_out 
            = vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_spec_res;
    }
    vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st1_align_sticky 
        = ((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__tb_nrst) 
           && (((IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_y) 
                | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_m)) 
               | (IData)(vlSelfRef.add4_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__sticky_n)));
}
