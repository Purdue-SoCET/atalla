// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaddn_fp32accum_fp16_tb_softfloat.h for the primary calling header

#include "Vaddn_fp32accum_fp16_tb_softfloat__pch.h"
#include "Vaddn_fp32accum_fp16_tb_softfloat__Syms.h"
#include "Vaddn_fp32accum_fp16_tb_softfloat___024root.h"

extern const VlWide<9>/*287:0*/ Vaddn_fp32accum_fp16_tb_softfloat__ConstPool__CONST_hcb3e5208_0;
extern const VlWide<10>/*319:0*/ Vaddn_fp32accum_fp16_tb_softfloat__ConstPool__CONST_h49757150_0;
extern const VlWide<16>/*511:0*/ Vaddn_fp32accum_fp16_tb_softfloat__ConstPool__CONST_h36bfebb1_0;

VL_INLINE_OPT VlCoroutine Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__0(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vaddn_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    std::string addn_fp32accum_fp16_tb_softfloat__DOT__header;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__0__a;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__0__a = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__0__b;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__0__b = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__0__c;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__0__c = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__0__d;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__0__d = 0;
    std::string __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__1__casename;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__1__expected;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__1__expected = 0;
    CData/*0:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__1__match;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__1__match = 0;
    CData/*0:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__val;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__val;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__val = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__4__a;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__4__a = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__4__b;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__4__b = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__4__c;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__4__c = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__4__d;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__4__d = 0;
    std::string __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__5__casename;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__5__expected;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__5__expected = 0;
    CData/*0:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__5__match;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__5__match = 0;
    CData/*0:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__val;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__val;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__val = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__8__a;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__8__a = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__8__b;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__8__b = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__8__c;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__8__c = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__8__d;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__8__d = 0;
    std::string __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__9__casename;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__9__expected;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__9__expected = 0;
    CData/*0:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__9__match;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__9__match = 0;
    CData/*0:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__val;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__val;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__val = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__12__a;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__12__a = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__12__b;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__12__b = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__12__c;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__12__c = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__12__d;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__12__d = 0;
    std::string __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__13__casename;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__13__expected;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__13__expected = 0;
    CData/*0:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__13__match;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__13__match = 0;
    CData/*0:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__val;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__val;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__val = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__16__a;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__16__a = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__16__b;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__16__b = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__16__c;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__16__c = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__16__d;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__16__d = 0;
    std::string __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__17__casename;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__17__expected;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__17__expected = 0;
    CData/*0:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__17__match;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__17__match = 0;
    CData/*0:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__val;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__val;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__val = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__20__a;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__20__a = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__20__b;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__20__b = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__20__c;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__20__c = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__20__d;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__20__d = 0;
    std::string __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__21__casename;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__21__expected;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__21__expected = 0;
    CData/*0:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__21__match;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__21__match = 0;
    CData/*0:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__22__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__22__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__22__val;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__22__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__23__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__23__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__23__val;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__23__val = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__24__a;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__24__a = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__24__b;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__24__b = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__24__c;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__24__c = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__24__d;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__24__d = 0;
    std::string __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__25__casename;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__25__expected;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__25__expected = 0;
    CData/*0:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__25__match;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__25__match = 0;
    CData/*0:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__26__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__26__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__26__val;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__26__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__27__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__27__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__27__val;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__27__val = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__28__a;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__28__a = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__28__b;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__28__b = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__28__c;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__28__c = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__28__d;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__28__d = 0;
    std::string __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__29__casename;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__29__expected;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__29__expected = 0;
    CData/*0:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__29__match;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__29__match = 0;
    CData/*0:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__30__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__30__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__30__val;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__30__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__31__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__31__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__31__val;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__31__val = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__32__a;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__32__a = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__32__b;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__32__b = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__32__c;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__32__c = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__32__d;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__32__d = 0;
    std::string __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__33__casename;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__33__expected;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__33__expected = 0;
    CData/*0:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__33__match;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__33__match = 0;
    CData/*0:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__34__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__34__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__34__val;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__34__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__35__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__35__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__35__val;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__35__val = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__36__a;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__36__a = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__36__b;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__36__b = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__36__c;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__36__c = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__36__d;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__36__d = 0;
    std::string __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__37__casename;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__37__expected;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__37__expected = 0;
    CData/*0:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__37__match;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__37__match = 0;
    CData/*0:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__38__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__38__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__38__val;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__38__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__39__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__39__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__39__val;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__39__val = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__40__a;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__40__a = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__40__b;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__40__b = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__40__c;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__40__c = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__40__d;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__40__d = 0;
    std::string __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__41__casename;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__41__expected;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__41__expected = 0;
    CData/*0:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__41__match;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__41__match = 0;
    CData/*0:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__42__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__42__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__42__val;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__42__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__43__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__43__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__43__val;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__43__val = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__44__a;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__44__a = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__44__b;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__44__b = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__44__c;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__44__c = 0;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__44__d;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__44__d = 0;
    std::string __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__45__casename;
    SData/*15:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__45__expected;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__45__expected = 0;
    CData/*0:0*/ __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__45__match;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__45__match = 0;
    CData/*0:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__46__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__46__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__46__val;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__46__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__47__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__47__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__47__val;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__47__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__48__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__48__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__48__val;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__48__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__49__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__49__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__49__val;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__49__val = 0;
    QData/*63:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__Vfuncout;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__a;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__a = 0;
    SData/*15:0*/ __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__b;
    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__b = 0;
    // Body
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(9, Vaddn_fp32accum_fp16_tb_softfloat__ConstPool__CONST_hcb3e5208_0));
    vlSymsp->_traceDumpOpen();
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_fd 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(10, Vaddn_fp32accum_fp16_tb_softfloat__ConstPool__CONST_h49757150_0)
                      , std::string{"w"});
    ;
    VL_FWRITEF_NX(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"a,b,c,d,expected,got\n",0);
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count = 0U;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count = 0U;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__ulp_big_count = 0U;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__total_ulp_diff = 0.0;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__total_count = 0U;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_nrst = 0U;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data = 0ULL;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__unnamedblk1__DOT__i = 4U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                         142);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_nrst = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                         144);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("--- Hardcoded 4-input Addition Cases ---\n",0);
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__0__d = 0x3c00U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__0__c = 0x3c00U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__0__b = 0x3c00U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__0__a = 0x3c00U;
    co_await vlSelfRef.__VtrigSched_h3cf440f3__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                                         64);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
        = (((QData)((IData)((((IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__0__d) 
                              << 0x10U) | (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__0__c)))) 
            << 0x20U) | (QData)((IData)((((IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__0__b) 
                                          << 0x10U) 
                                         | (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__0__a)))));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__exp = 0x4400U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                         148);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__1__expected 
        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__1__casename = 
        std::string{"1+1+1+1 = 4"};
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__1__match = 0;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__1__match 
        = ((([&]() {
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__val 
                        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__val)))));
                }(), (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__val 
                        = __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__1__expected;
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__val)))));
                }(), (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__Vfuncout))) 
           || ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__1__expected)));
    if (VL_LIKELY((__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__1__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__1__casename),
                     16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x10U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x20U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x30U))),
                     16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__1__casename),
                     16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x10U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x20U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x30U))),
                     16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__1__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x10U))),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x20U))),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x30U))),
                      16,(IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__1__expected),
                      16,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                         148);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__4__d = 0x4000U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__4__c = 0x4000U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__4__b = 0x4000U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__4__a = 0x4000U;
    co_await vlSelfRef.__VtrigSched_h3cf440f3__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                                         64);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
        = (((QData)((IData)((((IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__4__d) 
                              << 0x10U) | (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__4__c)))) 
            << 0x20U) | (QData)((IData)((((IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__4__b) 
                                          << 0x10U) 
                                         | (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__4__a)))));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__exp = 0x4800U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                         149);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__5__expected 
        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__5__casename = 
        std::string{"2+2+2+2 = 8"};
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__5__match = 0;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__5__match 
        = ((([&]() {
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__val 
                        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__val)))));
                }(), (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__val 
                        = __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__5__expected;
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__val)))));
                }(), (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__Vfuncout))) 
           || ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__5__expected)));
    if (VL_LIKELY((__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__5__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__5__casename),
                     16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x10U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x20U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x30U))),
                     16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__5__casename),
                     16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x10U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x20U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x30U))),
                     16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__5__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x10U))),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x20U))),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x30U))),
                      16,(IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__5__expected),
                      16,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                         149);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__8__d = 0U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__8__c = 0U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__8__b = 0U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__8__a = 0U;
    co_await vlSelfRef.__VtrigSched_h3cf440f3__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                                         64);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
        = (((QData)((IData)((((IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__8__d) 
                              << 0x10U) | (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__8__c)))) 
            << 0x20U) | (QData)((IData)((((IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__8__b) 
                                          << 0x10U) 
                                         | (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__8__a)))));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__exp = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                         150);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__9__expected 
        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__9__casename = 
        std::string{"0+0+0+0 = 0"};
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__9__match = 0;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__9__match 
        = ((([&]() {
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__val 
                        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__val)))));
                }(), (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__val 
                        = __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__9__expected;
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__val)))));
                }(), (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__Vfuncout))) 
           || ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__9__expected)));
    if (VL_LIKELY((__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__9__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__9__casename),
                     16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x10U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x20U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x30U))),
                     16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__9__casename),
                     16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x10U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x20U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x30U))),
                     16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__9__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x10U))),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x20U))),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x30U))),
                      16,(IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__9__expected),
                      16,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                         150);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__12__d = 0U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__12__c = 0U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__12__b = 0U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__12__a = 0x3c00U;
    co_await vlSelfRef.__VtrigSched_h3cf440f3__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                                         64);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
        = (((QData)((IData)((((IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__12__d) 
                              << 0x10U) | (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__12__c)))) 
            << 0x20U) | (QData)((IData)((((IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__12__b) 
                                          << 0x10U) 
                                         | (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__12__a)))));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__exp = 0x3c00U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                         151);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__13__expected 
        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__13__casename = 
        std::string{"1+0+0+0 = 1"};
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__13__match = 0;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__13__match 
        = ((([&]() {
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__val 
                        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__val)))));
                }(), (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__val 
                        = __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__13__expected;
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__val)))));
                }(), (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__Vfuncout))) 
           || ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__13__expected)));
    if (VL_LIKELY((__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__13__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__13__casename),
                     16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x10U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x20U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x30U))),
                     16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__13__casename),
                     16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x10U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x20U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x30U))),
                     16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__13__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x10U))),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x20U))),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x30U))),
                      16,(IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__13__expected),
                      16,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                         151);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__16__d = 0x3c00U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__16__c = 0x3c00U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__16__b = 0x3c00U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__16__a = 0x7c00U;
    co_await vlSelfRef.__VtrigSched_h3cf440f3__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                                         64);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
        = (((QData)((IData)((((IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__16__d) 
                              << 0x10U) | (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__16__c)))) 
            << 0x20U) | (QData)((IData)((((IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__16__b) 
                                          << 0x10U) 
                                         | (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__16__a)))));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__exp = 0x7c00U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                         152);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__17__expected 
        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__17__casename = 
        std::string{"Inf+1+1+1 = Inf"};
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__17__match = 0;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__17__match 
        = ((([&]() {
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__val 
                        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__val)))));
                }(), (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__val 
                        = __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__17__expected;
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__val)))));
                }(), (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__Vfuncout))) 
           || ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__17__expected)));
    if (VL_LIKELY((__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__17__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__17__casename),
                     16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x10U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x20U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x30U))),
                     16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__17__casename),
                     16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x10U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x20U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x30U))),
                     16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__17__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x10U))),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x20U))),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x30U))),
                      16,(IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__17__expected),
                      16,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                         152);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__20__d = 0x3c00U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__20__c = 0x3c00U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__20__b = 0x7c00U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__20__a = 0x7c00U;
    co_await vlSelfRef.__VtrigSched_h3cf440f3__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                                         64);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
        = (((QData)((IData)((((IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__20__d) 
                              << 0x10U) | (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__20__c)))) 
            << 0x20U) | (QData)((IData)((((IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__20__b) 
                                          << 0x10U) 
                                         | (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__20__a)))));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__exp = 0x7c00U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                         153);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__21__expected 
        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__21__casename = 
        std::string{"Inf+Inf+1+1 = Inf"};
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__21__match = 0;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__21__match 
        = ((([&]() {
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__22__val 
                        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__22__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__22__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__22__val)))));
                }(), (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__22__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__23__val 
                        = __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__21__expected;
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__23__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__23__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__23__val)))));
                }(), (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__23__Vfuncout))) 
           || ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__21__expected)));
    if (VL_LIKELY((__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__21__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__21__casename),
                     16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x10U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x20U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x30U))),
                     16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__21__casename),
                     16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x10U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x20U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x30U))),
                     16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__21__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x10U))),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x20U))),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x30U))),
                      16,(IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__21__expected),
                      16,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                         153);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__24__d = 0x3c00U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__24__c = 0x3c00U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__24__b = 0xfc00U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__24__a = 0x7c00U;
    co_await vlSelfRef.__VtrigSched_h3cf440f3__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                                         64);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
        = (((QData)((IData)((((IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__24__d) 
                              << 0x10U) | (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__24__c)))) 
            << 0x20U) | (QData)((IData)((((IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__24__b) 
                                          << 0x10U) 
                                         | (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__24__a)))));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__exp = 0x7d00U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                         154);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__25__expected 
        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__25__casename = 
        std::string{"+Inf + -Inf + 1 + 1 = NaN"};
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__25__match = 0;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__25__match 
        = ((([&]() {
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__26__val 
                        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__26__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__26__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__26__val)))));
                }(), (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__26__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__27__val 
                        = __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__25__expected;
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__27__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__27__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__27__val)))));
                }(), (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__27__Vfuncout))) 
           || ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__25__expected)));
    if (VL_LIKELY((__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__25__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__25__casename),
                     16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x10U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x20U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x30U))),
                     16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__25__casename),
                     16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x10U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x20U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x30U))),
                     16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__25__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x10U))),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x20U))),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x30U))),
                      16,(IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__25__expected),
                      16,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                         154);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__28__d = 0x3c00U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__28__c = 0x3c00U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__28__b = 0x3c00U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__28__a = 0x7d00U;
    co_await vlSelfRef.__VtrigSched_h3cf440f3__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                                         64);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
        = (((QData)((IData)((((IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__28__d) 
                              << 0x10U) | (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__28__c)))) 
            << 0x20U) | (QData)((IData)((((IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__28__b) 
                                          << 0x10U) 
                                         | (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__28__a)))));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__exp = 0x7d00U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                         155);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__29__expected 
        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__29__casename = 
        std::string{"NaN+1+1+1 = NaN"};
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__29__match = 0;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__29__match 
        = ((([&]() {
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__30__val 
                        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__30__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__30__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__30__val)))));
                }(), (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__30__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__31__val 
                        = __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__29__expected;
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__31__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__31__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__31__val)))));
                }(), (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__31__Vfuncout))) 
           || ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__29__expected)));
    if (VL_LIKELY((__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__29__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__29__casename),
                     16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x10U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x20U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x30U))),
                     16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__29__casename),
                     16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x10U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x20U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x30U))),
                     16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__29__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x10U))),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x20U))),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x30U))),
                      16,(IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__29__expected),
                      16,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                         155);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__32__d = 0x3c00U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__32__c = 0x3c00U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__32__b = 1U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__32__a = 1U;
    co_await vlSelfRef.__VtrigSched_h3cf440f3__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                                         64);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
        = (((QData)((IData)((((IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__32__d) 
                              << 0x10U) | (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__32__c)))) 
            << 0x20U) | (QData)((IData)((((IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__32__b) 
                                          << 0x10U) 
                                         | (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__32__a)))));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__exp = 0x4000U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                         156);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__33__expected 
        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__33__casename = 
        std::string{"sub+sub+1+1 = 2 (DAZ)"};
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__33__match = 0;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__33__match 
        = ((([&]() {
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__34__val 
                        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__34__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__34__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__34__val)))));
                }(), (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__34__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__35__val 
                        = __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__33__expected;
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__35__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__35__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__35__val)))));
                }(), (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__35__Vfuncout))) 
           || ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__33__expected)));
    if (VL_LIKELY((__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__33__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__33__casename),
                     16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x10U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x20U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x30U))),
                     16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__33__casename),
                     16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x10U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x20U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x30U))),
                     16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__33__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x10U))),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x20U))),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x30U))),
                      16,(IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__33__expected),
                      16,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                         156);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__36__d = 0x7bffU;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__36__c = 0x7bffU;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__36__b = 0x7bffU;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__36__a = 0x7bffU;
    co_await vlSelfRef.__VtrigSched_h3cf440f3__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                                         64);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
        = (((QData)((IData)((((IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__36__d) 
                              << 0x10U) | (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__36__c)))) 
            << 0x20U) | (QData)((IData)((((IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__36__b) 
                                          << 0x10U) 
                                         | (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__36__a)))));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__exp = 0x7c00U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                         157);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__37__expected 
        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__37__casename = 
        std::string{"max+max+max+max = Inf"};
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__37__match = 0;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__37__match 
        = ((([&]() {
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__38__val 
                        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__38__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__38__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__38__val)))));
                }(), (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__38__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__39__val 
                        = __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__37__expected;
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__39__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__39__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__39__val)))));
                }(), (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__39__Vfuncout))) 
           || ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__37__expected)));
    if (VL_LIKELY((__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__37__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__37__casename),
                     16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x10U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x20U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x30U))),
                     16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__37__casename),
                     16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x10U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x20U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x30U))),
                     16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__37__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x10U))),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x20U))),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x30U))),
                      16,(IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__37__expected),
                      16,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                         157);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__40__d = 0xbc00U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__40__c = 0x3c00U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__40__b = 0xbc00U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__40__a = 0x3c00U;
    co_await vlSelfRef.__VtrigSched_h3cf440f3__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                                         64);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
        = (((QData)((IData)((((IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__40__d) 
                              << 0x10U) | (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__40__c)))) 
            << 0x20U) | (QData)((IData)((((IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__40__b) 
                                          << 0x10U) 
                                         | (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__40__a)))));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__exp = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                         158);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__41__expected 
        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__41__casename = 
        std::string{"1+(-1)+1+(-1) = 0"};
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__41__match = 0;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__41__match 
        = ((([&]() {
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__42__val 
                        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__42__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__42__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__42__val)))));
                }(), (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__42__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__43__val 
                        = __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__41__expected;
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__43__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__43__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__43__val)))));
                }(), (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__43__Vfuncout))) 
           || ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__41__expected)));
    if (VL_LIKELY((__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__41__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__41__casename),
                     16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x10U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x20U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x30U))),
                     16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__41__casename),
                     16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x10U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x20U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x30U))),
                     16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__41__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x10U))),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x20U))),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x30U))),
                      16,(IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__41__expected),
                      16,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                         158);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__44__d = 0xc000U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__44__c = 0xc000U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__44__b = 0xc000U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__44__a = 0xc000U;
    co_await vlSelfRef.__VtrigSched_h3cf440f3__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                                         64);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
        = (((QData)((IData)((((IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__44__d) 
                              << 0x10U) | (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__44__c)))) 
            << 0x20U) | (QData)((IData)((((IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__44__b) 
                                          << 0x10U) 
                                         | (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__test_case__44__a)))));
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__exp = 0xc800U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                         159);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__45__expected 
        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__45__casename = 
        std::string{"-2+-2+-2+-2 = -8"};
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__45__match = 0;
    __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__45__match 
        = ((([&]() {
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__46__val 
                        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__46__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__46__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__46__val)))));
                }(), (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__46__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__47__val 
                        = __Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__45__expected;
                    __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__47__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__47__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__47__val)))));
                }(), (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__47__Vfuncout))) 
           || ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__45__expected)));
    if (VL_LIKELY((__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__45__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__45__casename),
                     16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x10U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x20U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x30U))),
                     16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__45__casename),
                     16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x10U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x20U))),
                     16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                            >> 0x30U))),
                     16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__45__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      16,(0xffffU & (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data)),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x10U))),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x20U))),
                      16,(0xffffU & (IData)((vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                                             >> 0x30U))),
                      16,(IData)(__Vtask_addn_fp32accum_fp16_tb_softfloat__DOT__check_case__45__expected),
                      16,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                         159);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("\n--- Berkeley SoftFloat Random Test Cases ---\n",0);
    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fd 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(16, Vaddn_fp32accum_fp16_tb_softfloat__ConstPool__CONST_h36bfebb1_0)
                      , std::string{"r"});
    ;
    if (VL_UNLIKELY(((0U == vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fd)))) {
        VL_WRITEF_NX("error: could not open testfloat_cases_4_pure_fp32accum_fp16.csv\nmake sure it is in the right directory! check tb for pathing\n",0);
        VL_FINISH_MT("tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 168, "");
    }
    (void)VL_FGETS_NI(addn_fp32accum_fp16_tb_softfloat__DOT__header, vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fd);
    while ((! (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fd ? feof(VL_CVT_I_FP(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fd)) : true))) {
        {
            vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__unnamedblk2__DOT__ret 
                = VL_FSCANF_INX(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fd,"%x,%x,%x,%x,%x\n",0,
                                16,&(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__a),
                                16,&(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__b),
                                16,&(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__c),
                                16,&(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__d),
                                16,&(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__expected)) ;
            if ((5U != vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__unnamedblk2__DOT__ret)) {
                goto __Vlabel1;
            }
            vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__total_count 
                = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__total_count);
            co_await vlSelfRef.__VtrigSched_h3cf440f3__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge addn_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                                 "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                                                 181);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_in_data 
                = (((QData)((IData)((((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__d) 
                                      << 0x10U) | (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__c)))) 
                    << 0x20U) | (QData)((IData)((((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__b) 
                                                  << 0x10U) 
                                                 | (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__a)))));
            co_await vlSelfRef.__VdlySched.delay(0x1f40ULL, 
                                                 nullptr, 
                                                 "tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 
                                                 187);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__unnamedblk2__DOT__is_zero_result 
                = (((0U == (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result)) 
                    | (0x8000U == (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result))) 
                   & ((0U == (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__expected)) 
                      | (0x8000U == (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__expected))));
            if ((([&]() {
                            __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__48__val 
                                = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                            __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__48__Vfuncout 
                                = (IData)(((0x7c00U 
                                            == (0x7c00U 
                                                & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__48__val))) 
                                           & (0U != 
                                              (0x3ffU 
                                               & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__48__val)))));
                        }(), (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__48__Vfuncout)) 
                 & ([&]() {
                            __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__49__val 
                                = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__expected;
                            __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__49__Vfuncout 
                                = (IData)(((0x7c00U 
                                            == (0x7c00U 
                                                & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__49__val))) 
                                           & (0U != 
                                              (0x3ffU 
                                               & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__49__val)))));
                        }(), (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__is_nan__49__Vfuncout)))) {
                vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count 
                    = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count);
            } else if (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__unnamedblk2__DOT__is_zero_result) {
                vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count 
                    = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count);
            } else if (VL_UNLIKELY((((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
                                     != (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__expected))))) {
                VL_FWRITEF_NX(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                              16,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__a,
                              16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__b),
                              16,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__c,
                              16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__d),
                              16,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__expected,
                              16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result));
                vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count 
                    = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count);
                if (VL_UNLIKELY((VL_GTES_III(32, 0xaU, vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count)))) {
                    VL_WRITEF_NX("FAIL: A=%x B=%x C=%x D=%x | Got_fp16=%x, Got_fp32=%x, Exp=%x\n",0,
                                 16,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__a,
                                 16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__b),
                                 16,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__c,
                                 16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__d),
                                 16,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result,
                                 32,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out,
                                 16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__expected));
                } else if (VL_UNLIKELY(((0xbU == vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count)))) {
                    VL_WRITEF_NX("... (suppressing further terminal output, all failures logged to test_failures.csv) ...\n",0);
                }
                vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__ulp_diff 
                    = (IData)(([&]() {
                            __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__b 
                                = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__expected;
                            __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__a 
                                = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                            vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
                                = ((0x8000U & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__a))
                                    ? (0x7fffffffULL 
                                       - (QData)((IData)(
                                                         (0x7fffU 
                                                          & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__a)))))
                                    : (0x80000000ULL 
                                       + (QData)((IData)(
                                                         (0x7fffU 
                                                          & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__a))))));
                            vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
                                = ((0x8000U & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__b))
                                    ? (0x7fffffffULL 
                                       - (QData)((IData)(
                                                         (0x7fffU 
                                                          & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__b)))))
                                    : (0x80000000ULL 
                                       + (QData)((IData)(
                                                         (0x7fffU 
                                                          & (IData)(__Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__b))))));
                            __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__Vfuncout 
                                = (VL_GTS_IQQ(64, vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a, vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                                    ? (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
                                       - vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                                    : (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
                                       - vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a));
                        }(), __Vfunc_addn_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__50__Vfuncout));
                vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__total_ulp_diff 
                    = (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__total_ulp_diff 
                       + VL_ISTOR_D_I(32, vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__ulp_diff));
                if (VL_UNLIKELY(((VL_LTES_III(32, 0xaU, vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__ulp_diff) 
                                  & VL_GTS_III(32, 0xaU, vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__ulp_big_count))))) {
                    VL_WRITEF_NX("FAIL: A=%x B=%x C=%x D=%x | Got_fp16=%x, Got_fp32=%x, Exp=%x\nULP difference: %0d\n",0,
                                 16,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__a,
                                 16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__b),
                                 16,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__c,
                                 16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__d),
                                 16,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_result,
                                 32,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out,
                                 16,(IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__expected),
                                 32,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__ulp_diff);
                    vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__ulp_big_count 
                        = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__ulp_big_count);
                }
            } else {
                vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count 
                    = ((IData)(1U) + vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count);
            }
            if (VL_UNLIKELY(((0U == VL_MODDIVS_III(32, vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__total_count, (IData)(0x186a0U)))))) {
                VL_WRITEF_NX("progress: %0d tested (%0d pass, %0d fail)...\n",0,
                             32,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__total_count,
                             32,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count,
                             32,vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count);
            }
            __Vlabel1: ;
        }
    }
    VL_FCLOSE_I(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fd); VL_FCLOSE_I(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_fd); VL_WRITEF_NX("\n=== test summary ===\nNUM_INPUTS: 4\nPRECISION_BITS: 1\nPASSED: %0d\nFAILED: %0d\nAverage ULP difference: %f\nfailure cases logged to: test_failures_pure_fp32accum_fp16.csv\n",0,
                                                                                32,
                                                                                vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__pass_count,
                                                                                32,
                                                                                vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count,
                                                                                64,
                                                                                (vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__total_ulp_diff 
                                                                                / 
                                                                                VL_ISTOR_D_I(32, vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count)));
    if ((0U == vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__fail_count)) {
        VL_WRITEF_NX("ALL TESTS PASSED!\n",0);
    } else {
        VL_WRITEF_NX("SOME TESTS FAILED!\n",0);
    }
    VL_FINISH_MT("tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv", 242, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddn_fp32accum_fp16_tb_softfloat___024root___dump_triggers__act(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG

void Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_triggers__act(Vaddn_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32accum_fp16_tb_softfloat___024root___eval_triggers__act\n"); );
    Vaddn_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__addn_fp32accum_fp16_tb_softfloat__DOT__tb_clk__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_nrst)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__addn_fp32accum_fp16_tb_softfloat__DOT__tb_nrst__0)));
    vlSelfRef.__VactTriggered.setBit(2U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__VactTriggered.setBit(3U, ((~ (IData)(vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_clk)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__addn_fp32accum_fp16_tb_softfloat__DOT__tb_clk__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__addn_fp32accum_fp16_tb_softfloat__DOT__tb_clk__0 
        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__addn_fp32accum_fp16_tb_softfloat__DOT__tb_nrst__0 
        = vlSelfRef.addn_fp32accum_fp16_tb_softfloat__DOT__tb_nrst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vaddn_fp32accum_fp16_tb_softfloat___024root___dump_triggers__act(vlSelf);
    }
#endif
}
