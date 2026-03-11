// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaddn_fp32_tb_softfloat.h for the primary calling header

#include "Vaddn_fp32_tb_softfloat__pch.h"
#include "Vaddn_fp32_tb_softfloat__Syms.h"
#include "Vaddn_fp32_tb_softfloat___024root.h"

extern const VlWide<14>/*447:0*/ Vaddn_fp32_tb_softfloat__ConstPool__CONST_hb39bc3cc_0;

VL_INLINE_OPT VlCoroutine Vaddn_fp32_tb_softfloat___024root___eval_initial__TOP__Vtiming__0(Vaddn_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    std::string addn_fp32_tb_softfloat__DOT__header;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__0__a;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__0__a = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__0__b;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__0__b = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__0__c;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__0__c = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__0__d;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__0__d = 0;
    std::string __Vtask_addn_fp32_tb_softfloat__DOT__check_case__1__casename;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__check_case__1__expected;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__1__expected = 0;
    CData/*0:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__check_case__1__match;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__1__match = 0;
    CData/*0:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__2__Vfuncout;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__2__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__2__val;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__2__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__3__Vfuncout;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__3__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__3__val;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__3__val = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__4__a;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__4__a = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__4__b;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__4__b = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__4__c;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__4__c = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__4__d;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__4__d = 0;
    std::string __Vtask_addn_fp32_tb_softfloat__DOT__check_case__5__casename;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__check_case__5__expected;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__5__expected = 0;
    CData/*0:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__check_case__5__match;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__5__match = 0;
    CData/*0:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__6__Vfuncout;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__6__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__6__val;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__6__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__7__Vfuncout;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__7__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__7__val;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__7__val = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__8__a;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__8__a = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__8__b;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__8__b = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__8__c;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__8__c = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__8__d;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__8__d = 0;
    std::string __Vtask_addn_fp32_tb_softfloat__DOT__check_case__9__casename;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__check_case__9__expected;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__9__expected = 0;
    CData/*0:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__check_case__9__match;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__9__match = 0;
    CData/*0:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__10__Vfuncout;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__10__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__10__val;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__10__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__11__Vfuncout;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__11__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__11__val;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__11__val = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__12__a;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__12__a = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__12__b;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__12__b = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__12__c;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__12__c = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__12__d;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__12__d = 0;
    std::string __Vtask_addn_fp32_tb_softfloat__DOT__check_case__13__casename;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__check_case__13__expected;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__13__expected = 0;
    CData/*0:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__check_case__13__match;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__13__match = 0;
    CData/*0:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__14__Vfuncout;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__14__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__14__val;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__14__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__15__Vfuncout;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__15__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__15__val;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__15__val = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__16__a;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__16__a = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__16__b;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__16__b = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__16__c;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__16__c = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__16__d;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__16__d = 0;
    std::string __Vtask_addn_fp32_tb_softfloat__DOT__check_case__17__casename;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__check_case__17__expected;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__17__expected = 0;
    CData/*0:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__check_case__17__match;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__17__match = 0;
    CData/*0:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__18__Vfuncout;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__18__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__18__val;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__18__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__19__Vfuncout;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__19__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__19__val;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__19__val = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__20__a;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__20__a = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__20__b;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__20__b = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__20__c;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__20__c = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__20__d;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__20__d = 0;
    std::string __Vtask_addn_fp32_tb_softfloat__DOT__check_case__21__casename;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__check_case__21__expected;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__21__expected = 0;
    CData/*0:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__check_case__21__match;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__21__match = 0;
    CData/*0:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__22__Vfuncout;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__22__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__22__val;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__22__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__23__Vfuncout;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__23__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__23__val;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__23__val = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__24__a;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__24__a = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__24__b;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__24__b = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__24__c;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__24__c = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__24__d;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__24__d = 0;
    std::string __Vtask_addn_fp32_tb_softfloat__DOT__check_case__25__casename;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__check_case__25__expected;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__25__expected = 0;
    CData/*0:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__check_case__25__match;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__25__match = 0;
    CData/*0:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__26__Vfuncout;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__26__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__26__val;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__26__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__27__Vfuncout;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__27__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__27__val;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__27__val = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__28__a;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__28__a = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__28__b;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__28__b = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__28__c;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__28__c = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__28__d;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__28__d = 0;
    std::string __Vtask_addn_fp32_tb_softfloat__DOT__check_case__29__casename;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__check_case__29__expected;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__29__expected = 0;
    CData/*0:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__check_case__29__match;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__29__match = 0;
    CData/*0:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__30__Vfuncout;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__30__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__30__val;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__30__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__31__Vfuncout;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__31__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__31__val;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__31__val = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__32__a;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__32__a = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__32__b;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__32__b = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__32__c;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__32__c = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__32__d;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__32__d = 0;
    std::string __Vtask_addn_fp32_tb_softfloat__DOT__check_case__33__casename;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__check_case__33__expected;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__33__expected = 0;
    CData/*0:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__check_case__33__match;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__33__match = 0;
    CData/*0:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__34__Vfuncout;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__34__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__34__val;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__34__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__35__Vfuncout;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__35__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__35__val;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__35__val = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__36__a;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__36__a = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__36__b;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__36__b = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__36__c;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__36__c = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__36__d;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__36__d = 0;
    std::string __Vtask_addn_fp32_tb_softfloat__DOT__check_case__37__casename;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__check_case__37__expected;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__37__expected = 0;
    CData/*0:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__check_case__37__match;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__37__match = 0;
    CData/*0:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__38__Vfuncout;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__38__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__38__val;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__38__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__39__Vfuncout;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__39__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__39__val;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__39__val = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__40__a;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__40__a = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__40__b;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__40__b = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__40__c;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__40__c = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__40__d;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__40__d = 0;
    std::string __Vtask_addn_fp32_tb_softfloat__DOT__check_case__41__casename;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__check_case__41__expected;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__41__expected = 0;
    CData/*0:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__check_case__41__match;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__41__match = 0;
    CData/*0:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__42__Vfuncout;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__42__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__42__val;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__42__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__43__Vfuncout;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__43__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__43__val;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__43__val = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__44__a;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__44__a = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__44__b;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__44__b = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__44__c;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__44__c = 0;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__test_case__44__d;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__44__d = 0;
    std::string __Vtask_addn_fp32_tb_softfloat__DOT__check_case__45__casename;
    IData/*31:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__check_case__45__expected;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__45__expected = 0;
    CData/*0:0*/ __Vtask_addn_fp32_tb_softfloat__DOT__check_case__45__match;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__45__match = 0;
    CData/*0:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__46__Vfuncout;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__46__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__46__val;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__46__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__47__Vfuncout;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__47__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__47__val;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__47__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__48__Vfuncout;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__48__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__48__val;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__48__val = 0;
    CData/*0:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__49__Vfuncout;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__49__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__49__val;
    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__49__val = 0;
    VlWide<7>/*223:0*/ __Vtemp_1;
    VlWide<7>/*223:0*/ __Vtemp_2;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x61766573U;
    __Vtemp_1[2U] = 0x33325f77U;
    __Vtemp_1[3U] = 0x4e5f6670U;
    __Vtemp_1[4U] = 0x2f616464U;
    __Vtemp_1[5U] = 0x61766573U;
    __Vtemp_1[6U] = 0x77U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(7, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    __Vtemp_2[0U] = 0x2e637376U;
    __Vtemp_2[1U] = 0x66703332U;
    __Vtemp_2[2U] = 0x7572655fU;
    __Vtemp_2[3U] = 0x65735f70U;
    __Vtemp_2[4U] = 0x696c7572U;
    __Vtemp_2[5U] = 0x745f6661U;
    __Vtemp_2[6U] = 0x746573U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_fd 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(7, __Vtemp_2)
                      , std::string{"w"});
    ;
    VL_FWRITEF_NX(vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_fd,"a,b,c,d,expected,got\n",0);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__off_by_one = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__off_by_two = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__off_by_five_plus = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__total_count = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_nrst = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U] = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U] = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U] = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U] = 0U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__unnamedblk1__DOT__i = 4U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                         126);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_nrst = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                         128);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("--- Hardcoded 4-input Addition Cases ---\n",0);
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__0__d = 0x3f800000U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__0__c = 0x3f800000U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__0__b = 0x3f800000U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__0__a = 0x3f800000U;
    co_await vlSelfRef.__VtrigSched_hd66bd573__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_fp32_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                                         58);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U] 
        = __Vtask_addn_fp32_tb_softfloat__DOT__test_case__0__a;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U] 
        = __Vtask_addn_fp32_tb_softfloat__DOT__test_case__0__b;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U] 
        = (IData)((((QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__0__d)) 
                    << 0x20U) | (QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__0__c))));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U] 
        = (IData)(((((QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__0__d)) 
                     << 0x20U) | (QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__0__c))) 
                   >> 0x20U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__exp = 0x40800000U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                         135);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__1__expected 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__exp;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__1__casename = 
        std::string{"1+1+1+1 = 4"};
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__1__match = 0;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__1__match 
        = ((([&]() {
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__2__val 
                        = vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__2__Vfuncout 
                        = (IData)(((0x7f800000U == 
                                    (0x7f800000U & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__2__val)) 
                                   & (0U != (0x7fffffU 
                                             & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__2__val))));
                }(), (IData)(__Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__2__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__3__val 
                        = __Vtask_addn_fp32_tb_softfloat__DOT__check_case__1__expected;
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__3__Vfuncout 
                        = (IData)(((0x7f800000U == 
                                    (0x7f800000U & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__3__val)) 
                                   & (0U != (0x7fffffU 
                                             & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__3__val))));
                }(), (IData)(__Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__3__Vfuncout))) 
           || (vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result 
               == __Vtask_addn_fp32_tb_softfloat__DOT__check_case__1__expected));
    if (VL_LIKELY((__Vtask_addn_fp32_tb_softfloat__DOT__check_case__1__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_addn_fp32_tb_softfloat__DOT__check_case__1__casename),
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_fp32_tb_softfloat__DOT__check_case__1__casename),
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result,
                     32,__Vtask_addn_fp32_tb_softfloat__DOT__check_case__1__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                      32,__Vtask_addn_fp32_tb_softfloat__DOT__check_case__1__expected,
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                         137);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__4__d = 0x40000000U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__4__c = 0x40000000U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__4__b = 0x40000000U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__4__a = 0x40000000U;
    co_await vlSelfRef.__VtrigSched_hd66bd573__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_fp32_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                                         58);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U] 
        = __Vtask_addn_fp32_tb_softfloat__DOT__test_case__4__a;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U] 
        = __Vtask_addn_fp32_tb_softfloat__DOT__test_case__4__b;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U] 
        = (IData)((((QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__4__d)) 
                    << 0x20U) | (QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__4__c))));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U] 
        = (IData)(((((QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__4__d)) 
                     << 0x20U) | (QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__4__c))) 
                   >> 0x20U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__exp = 0x41000000U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                         142);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__5__expected 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__exp;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__5__casename = 
        std::string{"2+2+2+2 = 8"};
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__5__match = 0;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__5__match 
        = ((([&]() {
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__6__val 
                        = vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__6__Vfuncout 
                        = (IData)(((0x7f800000U == 
                                    (0x7f800000U & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__6__val)) 
                                   & (0U != (0x7fffffU 
                                             & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__6__val))));
                }(), (IData)(__Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__6__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__7__val 
                        = __Vtask_addn_fp32_tb_softfloat__DOT__check_case__5__expected;
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__7__Vfuncout 
                        = (IData)(((0x7f800000U == 
                                    (0x7f800000U & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__7__val)) 
                                   & (0U != (0x7fffffU 
                                             & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__7__val))));
                }(), (IData)(__Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__7__Vfuncout))) 
           || (vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result 
               == __Vtask_addn_fp32_tb_softfloat__DOT__check_case__5__expected));
    if (VL_LIKELY((__Vtask_addn_fp32_tb_softfloat__DOT__check_case__5__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_addn_fp32_tb_softfloat__DOT__check_case__5__casename),
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_fp32_tb_softfloat__DOT__check_case__5__casename),
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result,
                     32,__Vtask_addn_fp32_tb_softfloat__DOT__check_case__5__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                      32,__Vtask_addn_fp32_tb_softfloat__DOT__check_case__5__expected,
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                         144);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__8__d = 0U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__8__c = 0U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__8__b = 0U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__8__a = 0U;
    co_await vlSelfRef.__VtrigSched_hd66bd573__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_fp32_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                                         58);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U] 
        = __Vtask_addn_fp32_tb_softfloat__DOT__test_case__8__a;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U] 
        = __Vtask_addn_fp32_tb_softfloat__DOT__test_case__8__b;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U] 
        = (IData)((((QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__8__d)) 
                    << 0x20U) | (QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__8__c))));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U] 
        = (IData)(((((QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__8__d)) 
                     << 0x20U) | (QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__8__c))) 
                   >> 0x20U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__exp = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                         149);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__9__expected 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__exp;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__9__casename = 
        std::string{"0+0+0+0 = 0"};
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__9__match = 0;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__9__match 
        = ((([&]() {
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__10__val 
                        = vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__10__Vfuncout 
                        = (IData)(((0x7f800000U == 
                                    (0x7f800000U & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__10__val)) 
                                   & (0U != (0x7fffffU 
                                             & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__10__val))));
                }(), (IData)(__Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__10__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__11__val 
                        = __Vtask_addn_fp32_tb_softfloat__DOT__check_case__9__expected;
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__11__Vfuncout 
                        = (IData)(((0x7f800000U == 
                                    (0x7f800000U & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__11__val)) 
                                   & (0U != (0x7fffffU 
                                             & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__11__val))));
                }(), (IData)(__Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__11__Vfuncout))) 
           || (vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result 
               == __Vtask_addn_fp32_tb_softfloat__DOT__check_case__9__expected));
    if (VL_LIKELY((__Vtask_addn_fp32_tb_softfloat__DOT__check_case__9__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_addn_fp32_tb_softfloat__DOT__check_case__9__casename),
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_fp32_tb_softfloat__DOT__check_case__9__casename),
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result,
                     32,__Vtask_addn_fp32_tb_softfloat__DOT__check_case__9__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                      32,__Vtask_addn_fp32_tb_softfloat__DOT__check_case__9__expected,
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                         151);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__12__d = 0U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__12__c = 0U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__12__b = 0U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__12__a = 0x3f800000U;
    co_await vlSelfRef.__VtrigSched_hd66bd573__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_fp32_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                                         58);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U] 
        = __Vtask_addn_fp32_tb_softfloat__DOT__test_case__12__a;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U] 
        = __Vtask_addn_fp32_tb_softfloat__DOT__test_case__12__b;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U] 
        = (IData)((((QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__12__d)) 
                    << 0x20U) | (QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__12__c))));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U] 
        = (IData)(((((QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__12__d)) 
                     << 0x20U) | (QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__12__c))) 
                   >> 0x20U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__exp = 0x3f800000U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                         156);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__13__expected 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__exp;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__13__casename = 
        std::string{"1+0+0+0 = 1"};
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__13__match = 0;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__13__match 
        = ((([&]() {
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__14__val 
                        = vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__14__Vfuncout 
                        = (IData)(((0x7f800000U == 
                                    (0x7f800000U & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__14__val)) 
                                   & (0U != (0x7fffffU 
                                             & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__14__val))));
                }(), (IData)(__Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__14__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__15__val 
                        = __Vtask_addn_fp32_tb_softfloat__DOT__check_case__13__expected;
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__15__Vfuncout 
                        = (IData)(((0x7f800000U == 
                                    (0x7f800000U & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__15__val)) 
                                   & (0U != (0x7fffffU 
                                             & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__15__val))));
                }(), (IData)(__Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__15__Vfuncout))) 
           || (vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result 
               == __Vtask_addn_fp32_tb_softfloat__DOT__check_case__13__expected));
    if (VL_LIKELY((__Vtask_addn_fp32_tb_softfloat__DOT__check_case__13__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_addn_fp32_tb_softfloat__DOT__check_case__13__casename),
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_fp32_tb_softfloat__DOT__check_case__13__casename),
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result,
                     32,__Vtask_addn_fp32_tb_softfloat__DOT__check_case__13__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                      32,__Vtask_addn_fp32_tb_softfloat__DOT__check_case__13__expected,
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                         158);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__16__d = 0x3f800000U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__16__c = 0x3f800000U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__16__b = 0x3f800000U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__16__a = 0x7f800000U;
    co_await vlSelfRef.__VtrigSched_hd66bd573__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_fp32_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                                         58);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U] 
        = __Vtask_addn_fp32_tb_softfloat__DOT__test_case__16__a;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U] 
        = __Vtask_addn_fp32_tb_softfloat__DOT__test_case__16__b;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U] 
        = (IData)((((QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__16__d)) 
                    << 0x20U) | (QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__16__c))));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U] 
        = (IData)(((((QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__16__d)) 
                     << 0x20U) | (QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__16__c))) 
                   >> 0x20U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__exp = 0x7f800000U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                         163);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__17__expected 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__exp;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__17__casename = 
        std::string{"Inf+1+1+1 = Inf"};
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__17__match = 0;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__17__match 
        = ((([&]() {
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__18__val 
                        = vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__18__Vfuncout 
                        = (IData)(((0x7f800000U == 
                                    (0x7f800000U & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__18__val)) 
                                   & (0U != (0x7fffffU 
                                             & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__18__val))));
                }(), (IData)(__Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__18__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__19__val 
                        = __Vtask_addn_fp32_tb_softfloat__DOT__check_case__17__expected;
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__19__Vfuncout 
                        = (IData)(((0x7f800000U == 
                                    (0x7f800000U & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__19__val)) 
                                   & (0U != (0x7fffffU 
                                             & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__19__val))));
                }(), (IData)(__Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__19__Vfuncout))) 
           || (vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result 
               == __Vtask_addn_fp32_tb_softfloat__DOT__check_case__17__expected));
    if (VL_LIKELY((__Vtask_addn_fp32_tb_softfloat__DOT__check_case__17__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_addn_fp32_tb_softfloat__DOT__check_case__17__casename),
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_fp32_tb_softfloat__DOT__check_case__17__casename),
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result,
                     32,__Vtask_addn_fp32_tb_softfloat__DOT__check_case__17__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                      32,__Vtask_addn_fp32_tb_softfloat__DOT__check_case__17__expected,
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                         165);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__20__d = 0x3f800000U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__20__c = 0x3f800000U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__20__b = 0x7f800000U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__20__a = 0x7f800000U;
    co_await vlSelfRef.__VtrigSched_hd66bd573__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_fp32_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                                         58);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U] 
        = __Vtask_addn_fp32_tb_softfloat__DOT__test_case__20__a;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U] 
        = __Vtask_addn_fp32_tb_softfloat__DOT__test_case__20__b;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U] 
        = (IData)((((QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__20__d)) 
                    << 0x20U) | (QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__20__c))));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U] 
        = (IData)(((((QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__20__d)) 
                     << 0x20U) | (QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__20__c))) 
                   >> 0x20U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__exp = 0x7f800000U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                         170);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__21__expected 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__exp;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__21__casename = 
        std::string{"Inf+Inf+1+1 = Inf"};
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__21__match = 0;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__21__match 
        = ((([&]() {
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__22__val 
                        = vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__22__Vfuncout 
                        = (IData)(((0x7f800000U == 
                                    (0x7f800000U & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__22__val)) 
                                   & (0U != (0x7fffffU 
                                             & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__22__val))));
                }(), (IData)(__Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__22__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__23__val 
                        = __Vtask_addn_fp32_tb_softfloat__DOT__check_case__21__expected;
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__23__Vfuncout 
                        = (IData)(((0x7f800000U == 
                                    (0x7f800000U & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__23__val)) 
                                   & (0U != (0x7fffffU 
                                             & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__23__val))));
                }(), (IData)(__Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__23__Vfuncout))) 
           || (vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result 
               == __Vtask_addn_fp32_tb_softfloat__DOT__check_case__21__expected));
    if (VL_LIKELY((__Vtask_addn_fp32_tb_softfloat__DOT__check_case__21__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_addn_fp32_tb_softfloat__DOT__check_case__21__casename),
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_fp32_tb_softfloat__DOT__check_case__21__casename),
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result,
                     32,__Vtask_addn_fp32_tb_softfloat__DOT__check_case__21__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                      32,__Vtask_addn_fp32_tb_softfloat__DOT__check_case__21__expected,
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                         172);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__24__d = 0x3f800000U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__24__c = 0x3f800000U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__24__b = 0xff800000U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__24__a = 0x7f800000U;
    co_await vlSelfRef.__VtrigSched_hd66bd573__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_fp32_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                                         58);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U] 
        = __Vtask_addn_fp32_tb_softfloat__DOT__test_case__24__a;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U] 
        = __Vtask_addn_fp32_tb_softfloat__DOT__test_case__24__b;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U] 
        = (IData)((((QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__24__d)) 
                    << 0x20U) | (QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__24__c))));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U] 
        = (IData)(((((QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__24__d)) 
                     << 0x20U) | (QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__24__c))) 
                   >> 0x20U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__exp = 0x7fc00000U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                         177);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__25__expected 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__exp;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__25__casename = 
        std::string{"+Inf + -Inf + 1 + 1 = NaN"};
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__25__match = 0;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__25__match 
        = ((([&]() {
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__26__val 
                        = vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__26__Vfuncout 
                        = (IData)(((0x7f800000U == 
                                    (0x7f800000U & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__26__val)) 
                                   & (0U != (0x7fffffU 
                                             & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__26__val))));
                }(), (IData)(__Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__26__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__27__val 
                        = __Vtask_addn_fp32_tb_softfloat__DOT__check_case__25__expected;
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__27__Vfuncout 
                        = (IData)(((0x7f800000U == 
                                    (0x7f800000U & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__27__val)) 
                                   & (0U != (0x7fffffU 
                                             & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__27__val))));
                }(), (IData)(__Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__27__Vfuncout))) 
           || (vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result 
               == __Vtask_addn_fp32_tb_softfloat__DOT__check_case__25__expected));
    if (VL_LIKELY((__Vtask_addn_fp32_tb_softfloat__DOT__check_case__25__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_addn_fp32_tb_softfloat__DOT__check_case__25__casename),
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_fp32_tb_softfloat__DOT__check_case__25__casename),
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result,
                     32,__Vtask_addn_fp32_tb_softfloat__DOT__check_case__25__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                      32,__Vtask_addn_fp32_tb_softfloat__DOT__check_case__25__expected,
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                         179);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__28__d = 0x3f800000U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__28__c = 0x3f800000U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__28__b = 0x3f800000U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__28__a = 0x7fc00000U;
    co_await vlSelfRef.__VtrigSched_hd66bd573__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_fp32_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                                         58);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U] 
        = __Vtask_addn_fp32_tb_softfloat__DOT__test_case__28__a;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U] 
        = __Vtask_addn_fp32_tb_softfloat__DOT__test_case__28__b;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U] 
        = (IData)((((QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__28__d)) 
                    << 0x20U) | (QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__28__c))));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U] 
        = (IData)(((((QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__28__d)) 
                     << 0x20U) | (QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__28__c))) 
                   >> 0x20U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__exp = 0x7fc00000U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                         184);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__29__expected 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__exp;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__29__casename = 
        std::string{"NaN+1+1+1 = NaN"};
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__29__match = 0;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__29__match 
        = ((([&]() {
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__30__val 
                        = vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__30__Vfuncout 
                        = (IData)(((0x7f800000U == 
                                    (0x7f800000U & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__30__val)) 
                                   & (0U != (0x7fffffU 
                                             & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__30__val))));
                }(), (IData)(__Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__30__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__31__val 
                        = __Vtask_addn_fp32_tb_softfloat__DOT__check_case__29__expected;
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__31__Vfuncout 
                        = (IData)(((0x7f800000U == 
                                    (0x7f800000U & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__31__val)) 
                                   & (0U != (0x7fffffU 
                                             & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__31__val))));
                }(), (IData)(__Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__31__Vfuncout))) 
           || (vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result 
               == __Vtask_addn_fp32_tb_softfloat__DOT__check_case__29__expected));
    if (VL_LIKELY((__Vtask_addn_fp32_tb_softfloat__DOT__check_case__29__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_addn_fp32_tb_softfloat__DOT__check_case__29__casename),
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_fp32_tb_softfloat__DOT__check_case__29__casename),
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result,
                     32,__Vtask_addn_fp32_tb_softfloat__DOT__check_case__29__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                      32,__Vtask_addn_fp32_tb_softfloat__DOT__check_case__29__expected,
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                         186);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__32__d = 0x3f800000U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__32__c = 0x3f800000U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__32__b = 1U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__32__a = 1U;
    co_await vlSelfRef.__VtrigSched_hd66bd573__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_fp32_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                                         58);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U] 
        = __Vtask_addn_fp32_tb_softfloat__DOT__test_case__32__a;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U] 
        = __Vtask_addn_fp32_tb_softfloat__DOT__test_case__32__b;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U] 
        = (IData)((((QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__32__d)) 
                    << 0x20U) | (QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__32__c))));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U] 
        = (IData)(((((QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__32__d)) 
                     << 0x20U) | (QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__32__c))) 
                   >> 0x20U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__exp = 0x40000000U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                         191);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__33__expected 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__exp;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__33__casename = 
        std::string{"sub+sub+1+1 = 2 (DAZ)"};
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__33__match = 0;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__33__match 
        = ((([&]() {
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__34__val 
                        = vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__34__Vfuncout 
                        = (IData)(((0x7f800000U == 
                                    (0x7f800000U & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__34__val)) 
                                   & (0U != (0x7fffffU 
                                             & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__34__val))));
                }(), (IData)(__Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__34__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__35__val 
                        = __Vtask_addn_fp32_tb_softfloat__DOT__check_case__33__expected;
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__35__Vfuncout 
                        = (IData)(((0x7f800000U == 
                                    (0x7f800000U & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__35__val)) 
                                   & (0U != (0x7fffffU 
                                             & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__35__val))));
                }(), (IData)(__Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__35__Vfuncout))) 
           || (vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result 
               == __Vtask_addn_fp32_tb_softfloat__DOT__check_case__33__expected));
    if (VL_LIKELY((__Vtask_addn_fp32_tb_softfloat__DOT__check_case__33__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_addn_fp32_tb_softfloat__DOT__check_case__33__casename),
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_fp32_tb_softfloat__DOT__check_case__33__casename),
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result,
                     32,__Vtask_addn_fp32_tb_softfloat__DOT__check_case__33__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                      32,__Vtask_addn_fp32_tb_softfloat__DOT__check_case__33__expected,
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                         193);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__36__d = 0x7f7fffffU;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__36__c = 0x7f7fffffU;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__36__b = 0x7f7fffffU;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__36__a = 0x7f7fffffU;
    co_await vlSelfRef.__VtrigSched_hd66bd573__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_fp32_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                                         58);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U] 
        = __Vtask_addn_fp32_tb_softfloat__DOT__test_case__36__a;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U] 
        = __Vtask_addn_fp32_tb_softfloat__DOT__test_case__36__b;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U] 
        = (IData)((((QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__36__d)) 
                    << 0x20U) | (QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__36__c))));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U] 
        = (IData)(((((QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__36__d)) 
                     << 0x20U) | (QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__36__c))) 
                   >> 0x20U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__exp = 0x7f800000U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                         198);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__37__expected 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__exp;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__37__casename = 
        std::string{"max+max+max+max = Inf"};
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__37__match = 0;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__37__match 
        = ((([&]() {
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__38__val 
                        = vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__38__Vfuncout 
                        = (IData)(((0x7f800000U == 
                                    (0x7f800000U & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__38__val)) 
                                   & (0U != (0x7fffffU 
                                             & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__38__val))));
                }(), (IData)(__Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__38__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__39__val 
                        = __Vtask_addn_fp32_tb_softfloat__DOT__check_case__37__expected;
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__39__Vfuncout 
                        = (IData)(((0x7f800000U == 
                                    (0x7f800000U & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__39__val)) 
                                   & (0U != (0x7fffffU 
                                             & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__39__val))));
                }(), (IData)(__Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__39__Vfuncout))) 
           || (vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result 
               == __Vtask_addn_fp32_tb_softfloat__DOT__check_case__37__expected));
    if (VL_LIKELY((__Vtask_addn_fp32_tb_softfloat__DOT__check_case__37__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_addn_fp32_tb_softfloat__DOT__check_case__37__casename),
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_fp32_tb_softfloat__DOT__check_case__37__casename),
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result,
                     32,__Vtask_addn_fp32_tb_softfloat__DOT__check_case__37__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                      32,__Vtask_addn_fp32_tb_softfloat__DOT__check_case__37__expected,
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                         200);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__40__d = 0xbf800000U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__40__c = 0x3f800000U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__40__b = 0xbf800000U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__40__a = 0x3f800000U;
    co_await vlSelfRef.__VtrigSched_hd66bd573__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_fp32_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                                         58);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U] 
        = __Vtask_addn_fp32_tb_softfloat__DOT__test_case__40__a;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U] 
        = __Vtask_addn_fp32_tb_softfloat__DOT__test_case__40__b;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U] 
        = (IData)((((QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__40__d)) 
                    << 0x20U) | (QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__40__c))));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U] 
        = (IData)(((((QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__40__d)) 
                     << 0x20U) | (QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__40__c))) 
                   >> 0x20U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__exp = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                         205);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__41__expected 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__exp;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__41__casename = 
        std::string{"1+(-1)+1+(-1) = 0"};
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__41__match = 0;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__41__match 
        = ((([&]() {
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__42__val 
                        = vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__42__Vfuncout 
                        = (IData)(((0x7f800000U == 
                                    (0x7f800000U & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__42__val)) 
                                   & (0U != (0x7fffffU 
                                             & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__42__val))));
                }(), (IData)(__Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__42__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__43__val 
                        = __Vtask_addn_fp32_tb_softfloat__DOT__check_case__41__expected;
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__43__Vfuncout 
                        = (IData)(((0x7f800000U == 
                                    (0x7f800000U & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__43__val)) 
                                   & (0U != (0x7fffffU 
                                             & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__43__val))));
                }(), (IData)(__Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__43__Vfuncout))) 
           || (vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result 
               == __Vtask_addn_fp32_tb_softfloat__DOT__check_case__41__expected));
    if (VL_LIKELY((__Vtask_addn_fp32_tb_softfloat__DOT__check_case__41__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_addn_fp32_tb_softfloat__DOT__check_case__41__casename),
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_fp32_tb_softfloat__DOT__check_case__41__casename),
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result,
                     32,__Vtask_addn_fp32_tb_softfloat__DOT__check_case__41__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                      32,__Vtask_addn_fp32_tb_softfloat__DOT__check_case__41__expected,
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                         207);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__44__d = 0xc0000000U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__44__c = 0xc0000000U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__44__b = 0xc0000000U;
    __Vtask_addn_fp32_tb_softfloat__DOT__test_case__44__a = 0xc0000000U;
    co_await vlSelfRef.__VtrigSched_hd66bd573__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_fp32_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                                         58);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U] 
        = __Vtask_addn_fp32_tb_softfloat__DOT__test_case__44__a;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U] 
        = __Vtask_addn_fp32_tb_softfloat__DOT__test_case__44__b;
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U] 
        = (IData)((((QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__44__d)) 
                    << 0x20U) | (QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__44__c))));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U] 
        = (IData)(((((QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__44__d)) 
                     << 0x20U) | (QData)((IData)(__Vtask_addn_fp32_tb_softfloat__DOT__test_case__44__c))) 
                   >> 0x20U));
    vlSelfRef.addn_fp32_tb_softfloat__DOT__exp = 0xc1000000U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                         213);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__45__expected 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__exp;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__45__casename = 
        std::string{"-2+-2+-2+-2 = -8"};
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__45__match = 0;
    __Vtask_addn_fp32_tb_softfloat__DOT__check_case__45__match 
        = ((([&]() {
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__46__val 
                        = vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__46__Vfuncout 
                        = (IData)(((0x7f800000U == 
                                    (0x7f800000U & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__46__val)) 
                                   & (0U != (0x7fffffU 
                                             & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__46__val))));
                }(), (IData)(__Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__46__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__47__val 
                        = __Vtask_addn_fp32_tb_softfloat__DOT__check_case__45__expected;
                    __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__47__Vfuncout 
                        = (IData)(((0x7f800000U == 
                                    (0x7f800000U & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__47__val)) 
                                   & (0U != (0x7fffffU 
                                             & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__47__val))));
                }(), (IData)(__Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__47__Vfuncout))) 
           || (vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result 
               == __Vtask_addn_fp32_tb_softfloat__DOT__check_case__45__expected));
    if (VL_LIKELY((__Vtask_addn_fp32_tb_softfloat__DOT__check_case__45__match))) {
        VL_WRITEF_NX("passed %@ | A=%x B=%x C=%x D=%x -> %x\n",0,
                     -1,&(__Vtask_addn_fp32_tb_softfloat__DOT__check_case__45__casename),
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: A=%x B=%x C=%x D=%x Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_fp32_tb_softfloat__DOT__check_case__45__casename),
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                     32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result,
                     32,__Vtask_addn_fp32_tb_softfloat__DOT__check_case__45__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U],
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U],
                      32,__Vtask_addn_fp32_tb_softfloat__DOT__check_case__45__expected,
                      32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                         215);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("\n--- Berkeley SoftFloat Random Test Cases ---\n",0);
    vlSelfRef.addn_fp32_tb_softfloat__DOT__fd = VL_FOPEN_NN(
                                                            VL_CVT_PACK_STR_NW(14, Vaddn_fp32_tb_softfloat__ConstPool__CONST_hb39bc3cc_0)
                                                            , 
                                                            std::string{"r"});
    ;
    if (VL_UNLIKELY(((0U == vlSelfRef.addn_fp32_tb_softfloat__DOT__fd)))) {
        VL_WRITEF_NX("error: could not open testfloat_cases_4_pure_fp32.csv\nmake sure it is in the right directory! check tb for pathing\n",0);
        VL_FINISH_MT("tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 224, "");
    }
    (void)VL_FGETS_NI(addn_fp32_tb_softfloat__DOT__header, vlSelfRef.addn_fp32_tb_softfloat__DOT__fd);
    while ((! (vlSelfRef.addn_fp32_tb_softfloat__DOT__fd ? feof(VL_CVT_I_FP(vlSelfRef.addn_fp32_tb_softfloat__DOT__fd)) : true))) {
        {
            vlSelfRef.addn_fp32_tb_softfloat__DOT__unnamedblk2__DOT__ret 
                = VL_FSCANF_INX(vlSelfRef.addn_fp32_tb_softfloat__DOT__fd,"%x,%x,%x,%x,%x\n",0,
                                32,&(vlSelfRef.addn_fp32_tb_softfloat__DOT__a),
                                32,&(vlSelfRef.addn_fp32_tb_softfloat__DOT__b),
                                32,&(vlSelfRef.addn_fp32_tb_softfloat__DOT__c),
                                32,&(vlSelfRef.addn_fp32_tb_softfloat__DOT__d),
                                32,&(vlSelfRef.addn_fp32_tb_softfloat__DOT__expected)) ;
            if ((5U != vlSelfRef.addn_fp32_tb_softfloat__DOT__unnamedblk2__DOT__ret)) {
                goto __Vlabel1;
            }
            vlSelfRef.addn_fp32_tb_softfloat__DOT__total_count 
                = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__total_count);
            co_await vlSelfRef.__VtrigSched_hd66bd573__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge addn_fp32_tb_softfloat.tb_clk)", 
                                                                 "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                                                 238);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[0U] 
                = vlSelfRef.addn_fp32_tb_softfloat__DOT__a;
            vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[1U] 
                = vlSelfRef.addn_fp32_tb_softfloat__DOT__b;
            vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[2U] 
                = (IData)((((QData)((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__d)) 
                            << 0x20U) | (QData)((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__c))));
            vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_in_data[3U] 
                = (IData)(((((QData)((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__d)) 
                             << 0x20U) | (QData)((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__c))) 
                           >> 0x20U));
            co_await vlSelfRef.__VdlySched.delay(0x1f40ULL, 
                                                 nullptr, 
                                                 "tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 
                                                 244);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSelfRef.addn_fp32_tb_softfloat__DOT__unnamedblk2__DOT__is_zero_result 
                = (((0U == vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result) 
                    | (0x80000000U == vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result)) 
                   & ((0U == vlSelfRef.addn_fp32_tb_softfloat__DOT__expected) 
                      | (0x80000000U == vlSelfRef.addn_fp32_tb_softfloat__DOT__expected)));
            if ((([&]() {
                            __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__48__val 
                                = vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result;
                            __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__48__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__48__val)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__48__val))));
                        }(), (IData)(__Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__48__Vfuncout)) 
                 & ([&]() {
                            __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__49__val 
                                = vlSelfRef.addn_fp32_tb_softfloat__DOT__expected;
                            __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__49__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__49__val)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & __Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__49__val))));
                        }(), (IData)(__Vfunc_addn_fp32_tb_softfloat__DOT__is_nan__49__Vfuncout)))) {
                vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count 
                    = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count);
            } else if (vlSelfRef.addn_fp32_tb_softfloat__DOT__unnamedblk2__DOT__is_zero_result) {
                vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count 
                    = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count);
            } else if (VL_UNLIKELY(((vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result 
                                     != vlSelfRef.addn_fp32_tb_softfloat__DOT__expected)))) {
                VL_FWRITEF_NX(vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x\n",0,
                              32,vlSelfRef.addn_fp32_tb_softfloat__DOT__a,
                              32,vlSelfRef.addn_fp32_tb_softfloat__DOT__b,
                              32,vlSelfRef.addn_fp32_tb_softfloat__DOT__c,
                              32,vlSelfRef.addn_fp32_tb_softfloat__DOT__d,
                              32,vlSelfRef.addn_fp32_tb_softfloat__DOT__expected,
                              32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result);
                vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count 
                    = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count);
                if (VL_UNLIKELY((VL_GTES_III(32, 0xaU, vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count)))) {
                    VL_WRITEF_NX("FAIL: A=%x B=%x C=%x D=%x | Got=%x Exp=%x\n",0,
                                 32,vlSelfRef.addn_fp32_tb_softfloat__DOT__a,
                                 32,vlSelfRef.addn_fp32_tb_softfloat__DOT__b,
                                 32,vlSelfRef.addn_fp32_tb_softfloat__DOT__c,
                                 32,vlSelfRef.addn_fp32_tb_softfloat__DOT__d,
                                 32,vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result,
                                 32,vlSelfRef.addn_fp32_tb_softfloat__DOT__expected);
                } else if (VL_UNLIKELY(((0xbU == vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count)))) {
                    VL_WRITEF_NX("... (suppressing further terminal output, all failures logged to test_failures_pure_fp32.csv) ...\n",0);
                }
                vlSelfRef.addn_fp32_tb_softfloat__DOT__diff 
                    = (vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_result 
                       - vlSelfRef.addn_fp32_tb_softfloat__DOT__expected);
                if (((1U == vlSelfRef.addn_fp32_tb_softfloat__DOT__diff) 
                     | (0xffffffffU == vlSelfRef.addn_fp32_tb_softfloat__DOT__diff))) {
                    vlSelfRef.addn_fp32_tb_softfloat__DOT__off_by_one 
                        = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__off_by_one);
                } else if (((2U == vlSelfRef.addn_fp32_tb_softfloat__DOT__diff) 
                            | (0xfffffffeU == vlSelfRef.addn_fp32_tb_softfloat__DOT__diff))) {
                    vlSelfRef.addn_fp32_tb_softfloat__DOT__off_by_two 
                        = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__off_by_two);
                } else if ((VL_LTES_III(32, 2U, vlSelfRef.addn_fp32_tb_softfloat__DOT__diff) 
                            | VL_GTES_III(32, 0xfffffffeU, vlSelfRef.addn_fp32_tb_softfloat__DOT__diff))) {
                    vlSelfRef.addn_fp32_tb_softfloat__DOT__off_by_five_plus 
                        = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__off_by_five_plus);
                }
            } else {
                vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count 
                    = ((IData)(1U) + vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count);
            }
            if (VL_UNLIKELY(((0U == VL_MODDIVS_III(32, vlSelfRef.addn_fp32_tb_softfloat__DOT__total_count, (IData)(0x186a0U)))))) {
                VL_WRITEF_NX("progress: %0d tested (%0d pass, %0d fail)...\n",0,
                             32,vlSelfRef.addn_fp32_tb_softfloat__DOT__total_count,
                             32,vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count,
                             32,vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count);
            }
            __Vlabel1: ;
        }
    }
    VL_FCLOSE_I(vlSelfRef.addn_fp32_tb_softfloat__DOT__fd); VL_FCLOSE_I(vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_fd); VL_WRITEF_NX("\n=== test summary ===\nNUM_INPUTS: 4\nPRECISION BITS: 50\nPASSED: %0d\nFAILED: %0d\nOFF-BY-ONE: %0d\nOFF-BY-TWO: %0d\nOFF-BY-TWO-PLUS: %0d\nfailure cases logged to: test_failures_pure_fp32.csv\n",0,
                                                                                32,
                                                                                vlSelfRef.addn_fp32_tb_softfloat__DOT__pass_count,
                                                                                32,
                                                                                vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count,
                                                                                32,
                                                                                vlSelfRef.addn_fp32_tb_softfloat__DOT__off_by_one,
                                                                                32,
                                                                                vlSelfRef.addn_fp32_tb_softfloat__DOT__off_by_two,
                                                                                32,
                                                                                vlSelfRef.addn_fp32_tb_softfloat__DOT__off_by_five_plus);
    if ((0U == vlSelfRef.addn_fp32_tb_softfloat__DOT__fail_count)) {
        VL_WRITEF_NX("ALL TESTS PASSED!\n",0);
    } else {
        VL_WRITEF_NX("SOME TESTS FAILED!\n",0);
    }
    VL_FINISH_MT("tb/unit/systolic_array/addn_fp32_tb_softfloat.sv", 304, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddn_fp32_tb_softfloat___024root___dump_triggers__act(Vaddn_fp32_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG

void Vaddn_fp32_tb_softfloat___024root___eval_triggers__act(Vaddn_fp32_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_fp32_tb_softfloat___024root___eval_triggers__act\n"); );
    Vaddn_fp32_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__addn_fp32_tb_softfloat__DOT__tb_clk__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_nrst)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__addn_fp32_tb_softfloat__DOT__tb_nrst__0)));
    vlSelfRef.__VactTriggered.setBit(2U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__VactTriggered.setBit(3U, ((~ (IData)(vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_clk)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__addn_fp32_tb_softfloat__DOT__tb_clk__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__addn_fp32_tb_softfloat__DOT__tb_clk__0 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__addn_fp32_tb_softfloat__DOT__tb_nrst__0 
        = vlSelfRef.addn_fp32_tb_softfloat__DOT__tb_nrst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vaddn_fp32_tb_softfloat___024root___dump_triggers__act(vlSelf);
    }
#endif
}
