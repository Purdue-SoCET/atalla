// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd4_fp32accum_fp16_tb_softfloat.h for the primary calling header

#include "Vadd4_fp32accum_fp16_tb_softfloat__pch.h"
#include "Vadd4_fp32accum_fp16_tb_softfloat__Syms.h"
#include "Vadd4_fp32accum_fp16_tb_softfloat___024root.h"

extern const VlWide<9>/*287:0*/ Vadd4_fp32accum_fp16_tb_softfloat__ConstPool__CONST_h35596da8_0;
extern const VlWide<10>/*319:0*/ Vadd4_fp32accum_fp16_tb_softfloat__ConstPool__CONST_h49757150_0;
extern const VlWide<16>/*511:0*/ Vadd4_fp32accum_fp16_tb_softfloat__ConstPool__CONST_h36bfebb1_0;

VL_INLINE_OPT VlCoroutine Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__0(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vadd4_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    std::string add4_fp32accum_fp16_tb_softfloat__DOT__header;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__0__a;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__0__a = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__0__b;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__0__b = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__0__c;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__0__c = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__0__d;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__0__d = 0;
    std::string __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__1__casename;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__1__expected;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__1__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__1__match;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__1__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__val;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__val;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__val = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__4__a;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__4__a = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__4__b;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__4__b = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__4__c;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__4__c = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__4__d;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__4__d = 0;
    std::string __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__5__casename;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__5__expected;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__5__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__5__match;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__5__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__val;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__val;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__val = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__8__a;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__8__a = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__8__b;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__8__b = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__8__c;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__8__c = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__8__d;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__8__d = 0;
    std::string __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__9__casename;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__9__expected;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__9__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__9__match;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__9__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__val;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__val;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__val = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__12__a;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__12__a = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__12__b;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__12__b = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__12__c;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__12__c = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__12__d;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__12__d = 0;
    std::string __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__13__casename;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__13__expected;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__13__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__13__match;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__13__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__val;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__val;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__val = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__16__a;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__16__a = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__16__b;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__16__b = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__16__c;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__16__c = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__16__d;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__16__d = 0;
    std::string __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__17__casename;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__17__expected;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__17__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__17__match;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__17__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__val;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__val;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__val = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__20__a;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__20__a = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__20__b;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__20__b = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__20__c;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__20__c = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__20__d;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__20__d = 0;
    std::string __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__21__casename;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__21__expected;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__21__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__21__match;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__21__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__22__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__22__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__22__val;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__22__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__23__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__23__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__23__val;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__23__val = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__24__a;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__24__a = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__24__b;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__24__b = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__24__c;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__24__c = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__24__d;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__24__d = 0;
    std::string __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__25__casename;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__25__expected;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__25__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__25__match;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__25__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__26__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__26__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__26__val;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__26__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__27__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__27__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__27__val;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__27__val = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__28__a;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__28__a = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__28__b;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__28__b = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__28__c;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__28__c = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__28__d;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__28__d = 0;
    std::string __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__29__casename;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__29__expected;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__29__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__29__match;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__29__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__30__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__30__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__30__val;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__30__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__31__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__31__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__31__val;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__31__val = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__32__a;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__32__a = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__32__b;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__32__b = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__32__c;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__32__c = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__32__d;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__32__d = 0;
    std::string __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__33__casename;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__33__expected;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__33__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__33__match;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__33__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__34__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__34__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__34__val;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__34__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__35__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__35__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__35__val;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__35__val = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__36__a;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__36__a = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__36__b;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__36__b = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__36__c;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__36__c = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__36__d;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__36__d = 0;
    std::string __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__37__casename;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__37__expected;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__37__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__37__match;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__37__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__38__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__38__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__38__val;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__38__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__39__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__39__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__39__val;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__39__val = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__40__a;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__40__a = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__40__b;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__40__b = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__40__c;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__40__c = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__40__d;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__40__d = 0;
    std::string __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__41__casename;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__41__expected;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__41__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__41__match;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__41__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__42__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__42__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__42__val;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__42__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__43__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__43__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__43__val;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__43__val = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__44__a;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__44__a = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__44__b;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__44__b = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__44__c;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__44__c = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__44__d;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__44__d = 0;
    std::string __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__45__casename;
    SData/*15:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__45__expected;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__45__expected = 0;
    CData/*0:0*/ __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__45__match;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__45__match = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__46__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__46__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__46__val;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__46__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__47__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__47__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__47__val;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__47__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__48__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__48__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__48__val;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__48__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__49__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__49__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__49__val;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__49__val = 0;
    QData/*63:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__Vfuncout;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__a;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__a = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__b;
    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__b = 0;
    // Body
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(9, Vadd4_fp32accum_fp16_tb_softfloat__ConstPool__CONST_h35596da8_0));
    vlSymsp->_traceDumpOpen();
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_fd 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(10, Vadd4_fp32accum_fp16_tb_softfloat__ConstPool__CONST_h49757150_0)
                      , std::string{"w"});
    ;
    VL_FWRITEF_NX(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"a,b,c,d,expected,got\n",0);
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count = 0U;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count = 0U;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__off_by_one = 0U;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__off_by_two = 0U;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_nrst = 0U;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a = 0U;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b = 0U;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c = 0U;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                         181);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_nrst = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                         183);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("--- Hardcoded 4-input Addition Cases ---\n",0);
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__0__d = 0x3c00U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__0__c = 0x3c00U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__0__b = 0x3c00U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__0__a = 0x3c00U;
    co_await vlSelfRef.__VtrigSched_h8c095862__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                                         82);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__0__a;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__0__b;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__0__c;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__0__d;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__exp = 0x4400U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                         190);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__1__expected 
        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__1__casename = 
        std::string{"1+1+1+1 = 4"};
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__1__match = 0;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__1__match 
        = ((([&]() {
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__val 
                        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__val 
                        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__1__expected;
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__Vfuncout))) 
           || ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__1__expected)));
    if (VL_LIKELY((__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__1__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__1__casename),
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__1__casename),
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__1__expected);
        VL_FWRITEF_NX(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b),
                      16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d),
                      16,__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__1__expected,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                         192);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__4__d = 0x4000U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__4__c = 0x4000U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__4__b = 0x4000U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__4__a = 0x4000U;
    co_await vlSelfRef.__VtrigSched_h8c095862__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                                         82);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__4__a;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__4__b;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__4__c;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__4__d;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__exp = 0x4800U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                         197);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__5__expected 
        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__5__casename = 
        std::string{"2+2+2+2 = 8"};
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__5__match = 0;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__5__match 
        = ((([&]() {
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__val 
                        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__val 
                        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__5__expected;
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__Vfuncout))) 
           || ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__5__expected)));
    if (VL_LIKELY((__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__5__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__5__casename),
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__5__casename),
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__5__expected);
        VL_FWRITEF_NX(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b),
                      16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d),
                      16,__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__5__expected,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                         199);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__8__d = 0U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__8__c = 0U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__8__b = 0U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__8__a = 0U;
    co_await vlSelfRef.__VtrigSched_h8c095862__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                                         82);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__8__a;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__8__b;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__8__c;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__8__d;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__exp = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                         204);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__9__expected 
        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__9__casename = 
        std::string{"0+0+0+0 = 0"};
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__9__match = 0;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__9__match 
        = ((([&]() {
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__val 
                        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__val 
                        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__9__expected;
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__Vfuncout))) 
           || ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__9__expected)));
    if (VL_LIKELY((__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__9__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__9__casename),
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__9__casename),
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__9__expected);
        VL_FWRITEF_NX(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b),
                      16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d),
                      16,__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__9__expected,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                         206);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__12__d = 0U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__12__c = 0U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__12__b = 0U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__12__a = 0x3c00U;
    co_await vlSelfRef.__VtrigSched_h8c095862__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                                         82);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__12__a;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__12__b;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__12__c;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__12__d;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__exp = 0x3c00U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                         211);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__13__expected 
        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__13__casename = 
        std::string{"1+0+0+0 = 1"};
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__13__match = 0;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__13__match 
        = ((([&]() {
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__val 
                        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__val 
                        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__13__expected;
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__Vfuncout))) 
           || ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__13__expected)));
    if (VL_LIKELY((__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__13__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__13__casename),
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__13__casename),
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__13__expected);
        VL_FWRITEF_NX(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b),
                      16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d),
                      16,__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__13__expected,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                         213);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__16__d = 0x3c00U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__16__c = 0x3c00U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__16__b = 0x3c00U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__16__a = 0x7c00U;
    co_await vlSelfRef.__VtrigSched_h8c095862__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                                         82);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__16__a;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__16__b;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__16__c;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__16__d;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__exp = 0x7c00U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                         218);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__17__expected 
        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__17__casename = 
        std::string{"Inf+1+1+1 = Inf"};
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__17__match = 0;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__17__match 
        = ((([&]() {
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__val 
                        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__val 
                        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__17__expected;
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__Vfuncout))) 
           || ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__17__expected)));
    if (VL_LIKELY((__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__17__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__17__casename),
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__17__casename),
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__17__expected);
        VL_FWRITEF_NX(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b),
                      16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d),
                      16,__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__17__expected,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                         220);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__20__d = 0x3c00U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__20__c = 0x3c00U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__20__b = 0x7c00U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__20__a = 0x7c00U;
    co_await vlSelfRef.__VtrigSched_h8c095862__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                                         82);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__20__a;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__20__b;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__20__c;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__20__d;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__exp = 0x7c00U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                         225);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__21__expected 
        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__21__casename = 
        std::string{"Inf+Inf+1+1 = Inf"};
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__21__match = 0;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__21__match 
        = ((([&]() {
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__22__val 
                        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__22__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__22__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__22__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__22__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__23__val 
                        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__21__expected;
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__23__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__23__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__23__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__23__Vfuncout))) 
           || ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__21__expected)));
    if (VL_LIKELY((__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__21__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__21__casename),
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__21__casename),
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__21__expected);
        VL_FWRITEF_NX(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b),
                      16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d),
                      16,__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__21__expected,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                         227);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__24__d = 0x3c00U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__24__c = 0x3c00U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__24__b = 0xfc00U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__24__a = 0x7c00U;
    co_await vlSelfRef.__VtrigSched_h8c095862__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                                         82);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__24__a;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__24__b;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__24__c;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__24__d;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__exp = 0x7d00U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                         232);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__25__expected 
        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__25__casename = 
        std::string{"+Inf + -Inf + 1 + 1 = NaN"};
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__25__match = 0;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__25__match 
        = ((([&]() {
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__26__val 
                        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__26__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__26__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__26__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__26__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__27__val 
                        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__25__expected;
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__27__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__27__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__27__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__27__Vfuncout))) 
           || ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__25__expected)));
    if (VL_LIKELY((__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__25__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__25__casename),
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__25__casename),
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__25__expected);
        VL_FWRITEF_NX(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b),
                      16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d),
                      16,__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__25__expected,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                         234);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__28__d = 0x3c00U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__28__c = 0x3c00U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__28__b = 0x3c00U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__28__a = 0x7d00U;
    co_await vlSelfRef.__VtrigSched_h8c095862__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                                         82);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__28__a;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__28__b;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__28__c;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__28__d;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__exp = 0x7d00U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                         239);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__29__expected 
        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__29__casename = 
        std::string{"NaN+1+1+1 = NaN"};
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__29__match = 0;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__29__match 
        = ((([&]() {
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__30__val 
                        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__30__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__30__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__30__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__30__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__31__val 
                        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__29__expected;
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__31__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__31__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__31__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__31__Vfuncout))) 
           || ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__29__expected)));
    if (VL_LIKELY((__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__29__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__29__casename),
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__29__casename),
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__29__expected);
        VL_FWRITEF_NX(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b),
                      16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d),
                      16,__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__29__expected,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                         241);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__32__d = 0x3c00U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__32__c = 0x3c00U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__32__b = 1U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__32__a = 1U;
    co_await vlSelfRef.__VtrigSched_h8c095862__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                                         82);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__32__a;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__32__b;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__32__c;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__32__d;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__exp = 0x4000U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                         246);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__33__expected 
        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__33__casename = 
        std::string{"sub+sub+1+1 = 2 (DAZ)"};
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__33__match = 0;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__33__match 
        = ((([&]() {
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__34__val 
                        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__34__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__34__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__34__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__34__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__35__val 
                        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__33__expected;
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__35__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__35__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__35__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__35__Vfuncout))) 
           || ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__33__expected)));
    if (VL_LIKELY((__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__33__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__33__casename),
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__33__casename),
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__33__expected);
        VL_FWRITEF_NX(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b),
                      16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d),
                      16,__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__33__expected,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                         248);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__36__d = 0x7bffU;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__36__c = 0x7bffU;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__36__b = 0x7bffU;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__36__a = 0x7bffU;
    co_await vlSelfRef.__VtrigSched_h8c095862__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                                         82);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__36__a;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__36__b;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__36__c;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__36__d;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__exp = 0x7c00U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                         253);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__37__expected 
        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__37__casename = 
        std::string{"max+max+max+max = Inf"};
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__37__match = 0;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__37__match 
        = ((([&]() {
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__38__val 
                        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__38__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__38__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__38__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__38__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__39__val 
                        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__37__expected;
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__39__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__39__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__39__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__39__Vfuncout))) 
           || ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__37__expected)));
    if (VL_LIKELY((__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__37__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__37__casename),
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__37__casename),
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__37__expected);
        VL_FWRITEF_NX(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b),
                      16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d),
                      16,__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__37__expected,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                         255);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__40__d = 0xbc00U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__40__c = 0x3c00U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__40__b = 0xbc00U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__40__a = 0x3c00U;
    co_await vlSelfRef.__VtrigSched_h8c095862__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                                         82);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__40__a;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__40__b;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__40__c;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__40__d;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__exp = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                         260);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__41__expected 
        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__41__casename = 
        std::string{"1+(-1)+1+(-1) = 0"};
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__41__match = 0;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__41__match 
        = ((([&]() {
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__42__val 
                        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__42__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__42__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__42__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__42__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__43__val 
                        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__41__expected;
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__43__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__43__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__43__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__43__Vfuncout))) 
           || ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__41__expected)));
    if (VL_LIKELY((__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__41__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__41__casename),
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__41__casename),
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__41__expected);
        VL_FWRITEF_NX(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b),
                      16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d),
                      16,__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__41__expected,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                         262);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__44__d = 0xc000U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__44__c = 0xc000U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__44__b = 0xc000U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__44__a = 0xc000U;
    co_await vlSelfRef.__VtrigSched_h8c095862__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                                         82);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__44__a;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__44__b;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__44__c;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d 
        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__test_case__44__d;
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__exp = 0xc800U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                         268);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__45__expected 
        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__45__casename = 
        std::string{"-2+-2+-2+-2 = -8"};
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__45__match = 0;
    __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__45__match 
        = ((([&]() {
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__46__val 
                        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__46__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__46__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__46__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__46__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__47__val 
                        = __Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__45__expected;
                    __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__47__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__47__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__47__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__47__Vfuncout))) 
           || ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__45__expected)));
    if (VL_LIKELY((__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__45__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__45__casename),
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__45__casename),
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c),
                     16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d,
                     16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__45__expected);
        VL_FWRITEF_NX(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b),
                      16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d),
                      16,__Vtask_add4_fp32accum_fp16_tb_softfloat__DOT__check_case__45__expected,
                      16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                         270);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("\n--- Berkeley SoftFloat Random Test Cases ---\n",0);
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fd 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(16, Vadd4_fp32accum_fp16_tb_softfloat__ConstPool__CONST_h36bfebb1_0)
                      , std::string{"r"});
    ;
    if (VL_UNLIKELY(((0U == vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fd)))) {
        VL_WRITEF_NX("error: could not open testfloat_cases_4_pure_fp32accum_fp16.csv\nmake sure it is in the right directory! check tb for pathing\n",0);
        VL_FINISH_MT("tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 286, "");
    }
    (void)VL_FGETS_NI(add4_fp32accum_fp16_tb_softfloat__DOT__header, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fd);
    while ((! (vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fd ? feof(VL_CVT_I_FP(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fd)) : true))) {
        {
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__unnamedblk1__DOT__ret 
                = VL_FSCANF_INX(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fd,"%x,%x,%x,%x,%x\n",0,
                                16,&(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__a),
                                16,&(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__b),
                                16,&(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__c),
                                16,&(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__d),
                                16,&(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__expected)) ;
            if ((5U != vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__unnamedblk1__DOT__ret)) {
                goto __Vlabel1;
            }
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__unnamedblk1__DOT__total_count 
                = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__unnamedblk1__DOT__total_count);
            co_await vlSelfRef.__VtrigSched_h8c095862__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge add4_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                                 "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                                                 301);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_a 
                = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__a;
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_b 
                = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__b;
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_c 
                = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__c;
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_d 
                = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__d;
            co_await vlSelfRef.__VdlySched.delay(0x1f40ULL, 
                                                 nullptr, 
                                                 "tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 
                                                 307);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__unnamedblk1__DOT__is_zero_result 
                = (((0U == (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result)) 
                    | (0x8000U == (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result))) 
                   & (0U == (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__expected)));
            if ((([&]() {
                            __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__48__val 
                                = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                            __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__48__Vfuncout 
                                = (IData)(((0x7c00U 
                                            == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__48__val))) 
                                           & (0U != 
                                              (0x3ffU 
                                               & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__48__val)))));
                        }(), (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__48__Vfuncout)) 
                 & ([&]() {
                            __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__49__val 
                                = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__expected;
                            __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__49__Vfuncout 
                                = (IData)(((0x7c00U 
                                            == (0x7c00U 
                                                & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__49__val))) 
                                           & (0U != 
                                              (0x3ffU 
                                               & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__49__val)))));
                        }(), (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__is_nan__49__Vfuncout)))) {
                vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count 
                    = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count);
            } else if (vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__unnamedblk1__DOT__is_zero_result) {
                vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count 
                    = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count);
            } else if (VL_UNLIKELY((((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
                                     != (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__expected))))) {
                VL_FWRITEF_NX(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                              16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__a,
                              16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__b),
                              16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__c,
                              16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__d),
                              16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__expected,
                              16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result));
                vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count 
                    = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count);
                if (VL_UNLIKELY((VL_GTES_III(32, 0xaU, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count)))) {
                    VL_WRITEF_NX("FAIL: A=%x B=%x C=%x D=%x | Got_fp16=%x, Got_fp32=%x, Exp=%x\n",0,
                                 16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__a,
                                 16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__b),
                                 16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__c,
                                 16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__d),
                                 16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result,
                                 32,vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out,
                                 16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__expected));
                } else if (VL_UNLIKELY(((0xbU == vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count)))) {
                    VL_WRITEF_NX("... (suppressing further terminal output, all failures logged to test_failures.csv) ...\n",0);
                }
                vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__ulp_diff 
                    = (IData)(([&]() {
                            __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__b 
                                = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__expected;
                            __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__a 
                                = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
                                = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__a))
                                    ? (0x7fffffffULL 
                                       - (QData)((IData)(
                                                         (0x7fffU 
                                                          & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__a)))))
                                    : (0x80000000ULL 
                                       + (QData)((IData)(
                                                         (0x7fffU 
                                                          & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__a))))));
                            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
                                = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__b))
                                    ? (0x7fffffffULL 
                                       - (QData)((IData)(
                                                         (0x7fffU 
                                                          & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__b)))))
                                    : (0x80000000ULL 
                                       + (QData)((IData)(
                                                         (0x7fffU 
                                                          & (IData)(__Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__b))))));
                            __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__Vfuncout 
                                = (VL_GTS_IQQ(64, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                                    ? (vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
                                       - vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                                    : (vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
                                       - vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a));
                        }(), __Vfunc_add4_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__Vfuncout));
                vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__total_ulp_diff 
                    = (vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__total_ulp_diff 
                       + VL_ISTOR_D_I(32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__ulp_diff));
                if (VL_UNLIKELY(((VL_LTES_III(32, 0xaU, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__ulp_diff) 
                                  & VL_GTS_III(32, 0xaU, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__ulp_big_count))))) {
                    VL_WRITEF_NX("FAIL: A=%x B=%x C=%x D=%x | Got_fp16=%x, Got_fp32=%x, Exp=%x\nULP difference: %0d\n",0,
                                 16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__a,
                                 16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__b),
                                 16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__c,
                                 16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__d),
                                 16,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result,
                                 32,vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out,
                                 16,(IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__expected),
                                 32,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__ulp_diff);
                    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__ulp_big_count 
                        = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__ulp_big_count);
                }
            } else {
                vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count 
                    = ((IData)(1U) + vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count);
            }
            if (VL_UNLIKELY(((0U == VL_MODDIVS_III(32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__unnamedblk1__DOT__total_count, (IData)(0x186a0U)))))) {
                VL_WRITEF_NX("progress: %0d tested (%0d pass, %0d fail)...\n",0,
                             32,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__unnamedblk1__DOT__total_count,
                             32,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count,
                             32,vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count);
            }
            __Vlabel1: ;
        }
    }
    VL_FCLOSE_I(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fd); VL_FCLOSE_I(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_fd); VL_WRITEF_NX("\n=== test summary ===\nPRECISION_BITS: 1\nPASSED: %0d\nFAILED: %0d\nAverage ULP difference: %f\nfailure cases logged to: test_failures_pure.csv\n",0,
                                                                                32,
                                                                                vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__pass_count,
                                                                                32,
                                                                                vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count,
                                                                                64,
                                                                                (vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__total_ulp_diff 
                                                                                / 
                                                                                VL_ISTOR_D_I(32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count)));
    if ((0U == vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__fail_count)) {
        VL_WRITEF_NX("ALL TESTS PASSED!\n",0);
    } else {
        VL_WRITEF_NX("SOME TESTS FAILED!\n",0);
    }
    VL_FINISH_MT("tb/unit/systolic_array/add4_fp32accum_fp16_tb_softfloat.sv", 368, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp32accum_fp16_tb_softfloat___024root___dump_triggers__act(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG

void Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_triggers__act(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_triggers__act\n"); );
    Vadd4_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__add4_fp32accum_fp16_tb_softfloat__DOT__tb_clk__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_nrst)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__add4_fp32accum_fp16_tb_softfloat__DOT__tb_nrst__0)));
    vlSelfRef.__VactTriggered.setBit(2U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__VactTriggered.setBit(3U, ((~ (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_clk)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__add4_fp32accum_fp16_tb_softfloat__DOT__tb_clk__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__add4_fp32accum_fp16_tb_softfloat__DOT__tb_clk__0 
        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__add4_fp32accum_fp16_tb_softfloat__DOT__tb_nrst__0 
        = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_nrst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vadd4_fp32accum_fp16_tb_softfloat___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vadd4_fp32accum_fp16_tb_softfloat___024root___nba_sequent__TOP__1(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_fp16_tb_softfloat___024root___nba_sequent__TOP__1\n"); );
    Vadd4_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out 
        = ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_nrst)
            ? vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__result_out
            : 0U);
    if ((0U == vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag)) {
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan = 0U;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros = 0x1aU;
    } else {
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag;
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros = 0U;
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0xbU))) {
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros 
                = (0x3fU & ((IData)(0x10U) + (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)));
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan 
                = (0x7ffffffU & VL_SHIFTL_III(27,27,32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0x10U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0x13U))) {
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros 
                = (0x3fU & ((IData)(8U) + (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)));
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan 
                = (0x7ffffffU & VL_SHIFTL_III(27,27,32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 8U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0x17U))) {
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros 
                = (0x3fU & ((IData)(4U) + (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)));
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan 
                = (0x7ffffffU & VL_SHIFTL_III(27,27,32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 4U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0x19U))) {
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros 
                = (0x3fU & ((IData)(2U) + (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)));
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan 
                = (0x7ffffffU & VL_SHIFTL_III(27,27,32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 2U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 0x1aU))) {
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros 
                = (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)));
            vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan 
                = (0x7ffffffU & VL_SHIFTL_III(27,27,32, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lzd_scan, 1U));
        }
    }
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val 
        = (0x7ffffffU & VL_SHIFTL_III(27,27,6, vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag, (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_mant 
        = (0x7fffffU & (vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__norm_val 
                        >> 3U));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc 
        = (0x7ffU & ((IData)(0x70U) + (((IData)(2U) 
                                        + VL_EXTENDS_II(11,7, (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_exp_base))) 
                                       - VL_EXTENDS_II(11,8, (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__lead_zeros)))));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__result_out 
        = ((((0U == vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_sum_mag) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_exp_base)))
            ? ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign) 
               << 0x1fU) : (VL_LTES_III(32, 0xffU, 
                                        VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc)))
                             ? (0x7f800000U | ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign) 
                                               << 0x1fU))
                             : (((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_res_sign) 
                                 << 0x1fU) | ((0x7f800000U 
                                               & ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_exp_calc) 
                                                  << 0x17U)) 
                                              | vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__final_mant))));
    if (vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_special) {
        vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__result_out 
            = vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__etchedfp4adder__DOT__st2_spec_res;
    }
}

VL_INLINE_OPT void Vadd4_fp32accum_fp16_tb_softfloat___024root___nba_sequent__TOP__2(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_fp16_tb_softfloat___024root___nba_sequent__TOP__2\n"); );
    Vadd4_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__guard 
        = (1U & (vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out 
                 >> 0xcU));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rnd 
        = (1U & (vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out 
                 >> 0xbU));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__sticky 
        = (0U != (0x7ffU & vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__round_up 
        = ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__guard) 
           & (((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rnd) 
               | (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__sticky)) 
              | (vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out 
                 >> 0xdU)));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded 
        = (0x7ffU & ((0x3ffU & (vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out 
                                >> 0xdU)) + (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__round_up)));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp 
        = (0x3ffU & ((VL_EXTENDS_II(10,10, (0xffU & 
                                            (vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out 
                                             >> 0x17U))) 
                      - (IData)(0x70U)) + VL_EXTENDS_II(10,10, 
                                                        (1U 
                                                         & ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded) 
                                                            >> 0xaU)))));
    vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__tb_result 
        = ((0xffU == (0xffU & (vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out 
                               >> 0x17U))) ? (0x7c00U 
                                              | ((0x8000U 
                                                  & (vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out 
                                                     >> 0x10U)) 
                                                 | ((0U 
                                                     != 
                                                     (0x7fffffU 
                                                      & vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out))
                                                     ? 0x200U
                                                     : 0U)))
            : (VL_LTES_III(10, 0x1fU, (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp))
                ? (0x7c00U | (0x8000U & (vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out 
                                         >> 0x10U)))
                : (VL_GTES_III(32, 0U, VL_EXTENDS_II(32,10, (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp)))
                    ? (0x8000U & (vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out 
                                  >> 0x10U)) : ((0x8000U 
                                                 & (vlSymsp->TOP__add4_fp32accum_fp16_tb_softfloat__DOT__add_if.out 
                                                    >> 0x10U)) 
                                                | ((0x7c00U 
                                                    & ((IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__new_exp) 
                                                       << 0xaU)) 
                                                   | ((0x400U 
                                                       & (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded))
                                                       ? 0U
                                                       : 
                                                      (0x3ffU 
                                                       & (IData)(vlSelfRef.add4_fp32accum_fp16_tb_softfloat__DOT__reduce__DOT__rounded))))))));
}
