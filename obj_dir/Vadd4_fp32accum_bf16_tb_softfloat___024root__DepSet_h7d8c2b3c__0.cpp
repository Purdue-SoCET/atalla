// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd4_fp32accum_bf16_tb_softfloat.h for the primary calling header

#include "Vadd4_fp32accum_bf16_tb_softfloat__pch.h"
#include "Vadd4_fp32accum_bf16_tb_softfloat__Syms.h"
#include "Vadd4_fp32accum_bf16_tb_softfloat___024root.h"

extern const VlWide<14>/*447:0*/ Vadd4_fp32accum_bf16_tb_softfloat__ConstPool__CONST_hc773bd16_0;

VL_INLINE_OPT VlCoroutine Vadd4_fp32accum_bf16_tb_softfloat___024root___eval_initial__TOP__Vtiming__0(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    std::string add4_fp32accum_bf16_tb_softfloat__DOT__header;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__0__a_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__0__a_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__0__b_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__0__b_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__0__c_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__0__c_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__0__d_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__0__d_in = 0;
    std::string __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__1__casename;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__1__expected_val;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__1__expected_val = 0;
    CData/*0:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__1__match;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__1__match = 0;
    QData/*63:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__1__ulp;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__1__ulp = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__val;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__3__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__3__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__3__val;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__3__val = 0;
    QData/*63:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__4__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__4__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__4__a;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__4__a = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__4__b;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__4__b = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__5__a_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__5__a_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__5__b_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__5__b_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__5__c_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__5__c_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__5__d_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__5__d_in = 0;
    std::string __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__6__casename;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__6__expected_val;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__6__expected_val = 0;
    CData/*0:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__6__match;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__6__match = 0;
    QData/*63:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__6__ulp;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__6__ulp = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__7__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__7__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__7__val;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__7__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__8__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__8__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__8__val;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__8__val = 0;
    QData/*63:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__9__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__9__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__9__a;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__9__a = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__9__b;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__9__b = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__10__a_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__10__a_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__10__b_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__10__b_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__10__c_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__10__c_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__10__d_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__10__d_in = 0;
    std::string __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__11__casename;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__11__expected_val;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__11__expected_val = 0;
    CData/*0:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__11__match;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__11__match = 0;
    QData/*63:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__11__ulp;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__11__ulp = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__12__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__12__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__12__val;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__12__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__13__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__13__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__13__val;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__13__val = 0;
    QData/*63:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__14__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__14__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__14__a;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__14__a = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__14__b;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__14__b = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__15__a_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__15__a_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__15__b_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__15__b_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__15__c_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__15__c_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__15__d_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__15__d_in = 0;
    std::string __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__16__casename;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__16__expected_val;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__16__expected_val = 0;
    CData/*0:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__16__match;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__16__match = 0;
    QData/*63:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__16__ulp;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__16__ulp = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__17__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__17__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__17__val;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__17__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__18__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__18__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__18__val;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__18__val = 0;
    QData/*63:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__19__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__19__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__19__a;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__19__a = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__19__b;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__19__b = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__20__a_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__20__a_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__20__b_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__20__b_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__20__c_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__20__c_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__20__d_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__20__d_in = 0;
    std::string __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__21__casename;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__21__expected_val;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__21__expected_val = 0;
    CData/*0:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__21__match;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__21__match = 0;
    QData/*63:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__21__ulp;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__21__ulp = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__22__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__22__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__22__val;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__22__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__23__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__23__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__23__val;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__23__val = 0;
    QData/*63:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__24__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__24__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__24__a;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__24__a = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__24__b;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__24__b = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__25__a_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__25__a_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__25__b_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__25__b_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__25__c_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__25__c_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__25__d_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__25__d_in = 0;
    std::string __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__26__casename;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__26__expected_val;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__26__expected_val = 0;
    CData/*0:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__26__match;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__26__match = 0;
    QData/*63:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__26__ulp;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__26__ulp = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__27__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__27__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__27__val;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__27__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__28__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__28__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__28__val;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__28__val = 0;
    QData/*63:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__29__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__29__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__29__a;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__29__a = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__29__b;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__29__b = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__30__a_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__30__a_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__30__b_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__30__b_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__30__c_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__30__c_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__30__d_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__30__d_in = 0;
    std::string __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__31__casename;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__31__expected_val;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__31__expected_val = 0;
    CData/*0:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__31__match;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__31__match = 0;
    QData/*63:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__31__ulp;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__31__ulp = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__32__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__32__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__32__val;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__32__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__33__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__33__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__33__val;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__33__val = 0;
    QData/*63:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__34__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__34__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__34__a;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__34__a = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__34__b;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__34__b = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__35__a_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__35__a_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__35__b_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__35__b_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__35__c_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__35__c_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__35__d_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__35__d_in = 0;
    std::string __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__36__casename;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__36__expected_val;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__36__expected_val = 0;
    CData/*0:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__36__match;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__36__match = 0;
    QData/*63:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__36__ulp;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__36__ulp = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__37__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__37__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__37__val;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__37__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__38__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__38__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__38__val;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__38__val = 0;
    QData/*63:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__39__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__39__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__39__a;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__39__a = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__39__b;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__39__b = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__40__a_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__40__a_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__40__b_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__40__b_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__40__c_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__40__c_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__40__d_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__40__d_in = 0;
    std::string __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__41__casename;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__41__expected_val;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__41__expected_val = 0;
    CData/*0:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__41__match;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__41__match = 0;
    QData/*63:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__41__ulp;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__41__ulp = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__42__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__42__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__42__val;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__42__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__43__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__43__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__43__val;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__43__val = 0;
    QData/*63:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__44__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__44__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__44__a;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__44__a = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__44__b;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__44__b = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__45__a_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__45__a_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__45__b_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__45__b_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__45__c_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__45__c_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__45__d_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__45__d_in = 0;
    std::string __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__46__casename;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__46__expected_val;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__46__expected_val = 0;
    CData/*0:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__46__match;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__46__match = 0;
    QData/*63:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__46__ulp;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__46__ulp = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__47__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__47__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__47__val;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__47__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__48__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__48__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__48__val;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__48__val = 0;
    QData/*63:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__49__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__49__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__49__a;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__49__a = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__49__b;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__49__b = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__50__a_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__50__a_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__50__b_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__50__b_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__50__c_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__50__c_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__50__d_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__50__d_in = 0;
    std::string __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__51__casename;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__51__expected_val;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__51__expected_val = 0;
    CData/*0:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__51__match;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__51__match = 0;
    QData/*63:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__51__ulp;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__51__ulp = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__52__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__52__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__52__val;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__52__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__53__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__53__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__53__val;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__53__val = 0;
    QData/*63:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__54__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__54__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__54__a;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__54__a = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__54__b;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__54__b = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__55__a_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__55__a_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__55__b_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__55__b_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__55__c_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__55__c_in = 0;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__55__d_in;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__55__d_in = 0;
    std::string __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__56__casename;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__56__expected_val;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__56__expected_val = 0;
    CData/*0:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__56__match;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__56__match = 0;
    QData/*63:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__56__ulp;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__56__ulp = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__57__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__57__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__57__val;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__57__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__58__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__58__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__58__val;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__58__val = 0;
    QData/*63:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__59__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__59__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__59__a;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__59__a = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__59__b;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__59__b = 0;
    std::string __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__60__casename;
    SData/*15:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__60__expected_val;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__60__expected_val = 0;
    CData/*0:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__60__match;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__60__match = 0;
    QData/*63:0*/ __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__60__ulp;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__60__ulp = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__61__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__61__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__61__val;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__61__val = 0;
    CData/*0:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__62__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__62__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__62__val;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__62__val = 0;
    QData/*63:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__63__Vfuncout;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__63__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__63__a;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__63__a = 0;
    SData/*15:0*/ __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__63__b;
    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__63__b = 0;
    VlWide<7>/*223:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x61766573U;
    __Vtemp_1[2U] = 0x31365f77U;
    __Vtemp_1[3U] = 0x345f6266U;
    __Vtemp_1[4U] = 0x2f616464U;
    __Vtemp_1[5U] = 0x61766573U;
    __Vtemp_1[6U] = 0x77U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(7, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count = 0U;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count = 0U;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff = 0ULL;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count = 0U;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp = 0U;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_nrst = 0U;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a = 0U;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b = 0U;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c = 0U;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                         152);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_nrst = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                         154);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__0__d_in = 0x3f80U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__0__c_in = 0x3f80U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__0__b_in = 0x3f80U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__0__a_in = 0x3f80U;
    co_await vlSelfRef.__VtrigSched_h44fc30c7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                                         83);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__0__a_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__0__b_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__0__c_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__0__d_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__exp = 0x4080U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                         158);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__1__expected_val 
        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__1__casename = 
        std::string{"1+1+1+1 = 4"};
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__1__match = 0;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__1__ulp = 0;
    if ((([&]() {
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__val 
                        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result;
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__Vfuncout 
                        = (IData)(((0x7f80U == (0x7f80U 
                                                & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__val))) 
                                   & (0U != (0x7fU 
                                             & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__Vfuncout)) 
         & ([&]() {
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__3__val 
                        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__1__expected_val;
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__3__Vfuncout 
                        = (IData)(((0x7f80U == (0x7f80U 
                                                & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__3__val))) 
                                   & (0U != (0x7fU 
                                             & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__3__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__3__Vfuncout)))) {
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__1__match = 1U;
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__1__ulp = 0ULL;
    } else {
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__1__match 
            = ((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__1__expected_val));
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__4__b 
            = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__1__expected_val;
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__4__a 
            = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result;
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
            = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__4__a))
                ? (0x7fffffffULL - (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__4__a)))))
                : (0x80000000ULL + (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__4__a))))));
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
            = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__4__b))
                ? (0x7fffffffULL - (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__4__b)))))
                : (0x80000000ULL + (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__4__b))))));
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__4__Vfuncout 
            = (VL_GTS_IQQ(64, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                ? (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
                   - vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                : (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
                   - vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a));
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__1__ulp 
            = __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__4__Vfuncout;
    }
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
        = (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
           + __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__1__ulp);
    if (VL_LTS_IQQ(64, 1ULL, __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__1__ulp)) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count);
    }
    if (VL_GTS_IQQ(64, __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__1__ulp, 
                   VL_EXTENDS_QI(64,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp))) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp 
            = (IData)(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__1__ulp);
    }
    if (__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__1__match) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count);
    } else {
        if (VL_UNLIKELY((VL_GTS_III(32, 0xaU, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count)))) {
            VL_WRITEF_NX("FAIL: %@ | A=%x B=%x C=%x D=%x Got=%x Exp=%x AdderGot=%x | ULP=%0d\n",0,
                         -1,&(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__1__casename),
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a),
                         16,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b,
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c),
                         16,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d,
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result),
                         16,__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__1__expected_val,
                         35,vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out,
                         64,__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__1__ulp);
        }
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count);
    }
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__5__d_in = 0x4000U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__5__c_in = 0x4000U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__5__b_in = 0x4000U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__5__a_in = 0x4000U;
    co_await vlSelfRef.__VtrigSched_h44fc30c7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                                         83);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__5__a_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__5__b_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__5__c_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__5__d_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__exp = 0x4100U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                         162);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__6__expected_val 
        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__6__casename = 
        std::string{"2+2+2+2 = 8"};
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__6__match = 0;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__6__ulp = 0;
    if ((([&]() {
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__7__val 
                        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result;
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__7__Vfuncout 
                        = (IData)(((0x7f80U == (0x7f80U 
                                                & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__7__val))) 
                                   & (0U != (0x7fU 
                                             & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__7__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__7__Vfuncout)) 
         & ([&]() {
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__8__val 
                        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__6__expected_val;
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__8__Vfuncout 
                        = (IData)(((0x7f80U == (0x7f80U 
                                                & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__8__val))) 
                                   & (0U != (0x7fU 
                                             & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__8__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__8__Vfuncout)))) {
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__6__match = 1U;
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__6__ulp = 0ULL;
    } else {
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__6__match 
            = ((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__6__expected_val));
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__9__b 
            = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__6__expected_val;
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__9__a 
            = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result;
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
            = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__9__a))
                ? (0x7fffffffULL - (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__9__a)))))
                : (0x80000000ULL + (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__9__a))))));
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
            = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__9__b))
                ? (0x7fffffffULL - (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__9__b)))))
                : (0x80000000ULL + (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__9__b))))));
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__9__Vfuncout 
            = (VL_GTS_IQQ(64, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                ? (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
                   - vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                : (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
                   - vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a));
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__6__ulp 
            = __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__9__Vfuncout;
    }
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
        = (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
           + __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__6__ulp);
    if (VL_LTS_IQQ(64, 1ULL, __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__6__ulp)) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count);
    }
    if (VL_GTS_IQQ(64, __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__6__ulp, 
                   VL_EXTENDS_QI(64,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp))) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp 
            = (IData)(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__6__ulp);
    }
    if (__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__6__match) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count);
    } else {
        if (VL_UNLIKELY((VL_GTS_III(32, 0xaU, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count)))) {
            VL_WRITEF_NX("FAIL: %@ | A=%x B=%x C=%x D=%x Got=%x Exp=%x AdderGot=%x | ULP=%0d\n",0,
                         -1,&(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__6__casename),
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a),
                         16,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b,
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c),
                         16,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d,
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result),
                         16,__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__6__expected_val,
                         35,vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out,
                         64,__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__6__ulp);
        }
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count);
    }
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__10__d_in = 0U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__10__c_in = 0U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__10__b_in = 0U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__10__a_in = 0U;
    co_await vlSelfRef.__VtrigSched_h44fc30c7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                                         83);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__10__a_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__10__b_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__10__c_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__10__d_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__exp = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                         166);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__11__expected_val 
        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__11__casename = 
        std::string{"0+0+0+0 = 0"};
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__11__match = 0;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__11__ulp = 0;
    if ((([&]() {
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__12__val 
                        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result;
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__12__Vfuncout 
                        = (IData)(((0x7f80U == (0x7f80U 
                                                & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__12__val))) 
                                   & (0U != (0x7fU 
                                             & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__12__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__12__Vfuncout)) 
         & ([&]() {
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__13__val 
                        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__11__expected_val;
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__13__Vfuncout 
                        = (IData)(((0x7f80U == (0x7f80U 
                                                & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__13__val))) 
                                   & (0U != (0x7fU 
                                             & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__13__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__13__Vfuncout)))) {
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__11__match = 1U;
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__11__ulp = 0ULL;
    } else {
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__11__match 
            = ((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__11__expected_val));
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__14__b 
            = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__11__expected_val;
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__14__a 
            = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result;
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
            = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__14__a))
                ? (0x7fffffffULL - (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__14__a)))))
                : (0x80000000ULL + (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__14__a))))));
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
            = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__14__b))
                ? (0x7fffffffULL - (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__14__b)))))
                : (0x80000000ULL + (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__14__b))))));
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__14__Vfuncout 
            = (VL_GTS_IQQ(64, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                ? (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
                   - vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                : (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
                   - vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a));
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__11__ulp 
            = __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__14__Vfuncout;
    }
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
        = (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
           + __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__11__ulp);
    if (VL_LTS_IQQ(64, 1ULL, __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__11__ulp)) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count);
    }
    if (VL_GTS_IQQ(64, __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__11__ulp, 
                   VL_EXTENDS_QI(64,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp))) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp 
            = (IData)(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__11__ulp);
    }
    if (__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__11__match) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count);
    } else {
        if (VL_UNLIKELY((VL_GTS_III(32, 0xaU, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count)))) {
            VL_WRITEF_NX("FAIL: %@ | A=%x B=%x C=%x D=%x Got=%x Exp=%x AdderGot=%x | ULP=%0d\n",0,
                         -1,&(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__11__casename),
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a),
                         16,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b,
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c),
                         16,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d,
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result),
                         16,__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__11__expected_val,
                         35,vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out,
                         64,__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__11__ulp);
        }
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count);
    }
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__15__d_in = 0x4080U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__15__c_in = 0x4000U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__15__b_in = 0x3f80U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__15__a_in = 0x7f80U;
    co_await vlSelfRef.__VtrigSched_h44fc30c7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                                         83);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__15__a_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__15__b_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__15__c_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__15__d_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__exp = 0x7f80U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                         171);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__16__expected_val 
        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__16__casename = 
        std::string{"inf + finite = inf"};
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__16__match = 0;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__16__ulp = 0;
    if ((([&]() {
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__17__val 
                        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result;
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__17__Vfuncout 
                        = (IData)(((0x7f80U == (0x7f80U 
                                                & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__17__val))) 
                                   & (0U != (0x7fU 
                                             & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__17__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__17__Vfuncout)) 
         & ([&]() {
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__18__val 
                        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__16__expected_val;
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__18__Vfuncout 
                        = (IData)(((0x7f80U == (0x7f80U 
                                                & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__18__val))) 
                                   & (0U != (0x7fU 
                                             & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__18__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__18__Vfuncout)))) {
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__16__match = 1U;
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__16__ulp = 0ULL;
    } else {
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__16__match 
            = ((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__16__expected_val));
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__19__b 
            = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__16__expected_val;
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__19__a 
            = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result;
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
            = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__19__a))
                ? (0x7fffffffULL - (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__19__a)))))
                : (0x80000000ULL + (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__19__a))))));
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
            = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__19__b))
                ? (0x7fffffffULL - (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__19__b)))))
                : (0x80000000ULL + (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__19__b))))));
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__19__Vfuncout 
            = (VL_GTS_IQQ(64, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                ? (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
                   - vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                : (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
                   - vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a));
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__16__ulp 
            = __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__19__Vfuncout;
    }
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
        = (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
           + __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__16__ulp);
    if (VL_LTS_IQQ(64, 1ULL, __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__16__ulp)) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count);
    }
    if (VL_GTS_IQQ(64, __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__16__ulp, 
                   VL_EXTENDS_QI(64,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp))) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp 
            = (IData)(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__16__ulp);
    }
    if (__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__16__match) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count);
    } else {
        if (VL_UNLIKELY((VL_GTS_III(32, 0xaU, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count)))) {
            VL_WRITEF_NX("FAIL: %@ | A=%x B=%x C=%x D=%x Got=%x Exp=%x AdderGot=%x | ULP=%0d\n",0,
                         -1,&(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__16__casename),
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a),
                         16,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b,
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c),
                         16,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d,
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result),
                         16,__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__16__expected_val,
                         35,vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out,
                         64,__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__16__ulp);
        }
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count);
    }
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__20__d_in = 0U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__20__c_in = 0x3f80U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__20__b_in = 0xff80U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__20__a_in = 0xff80U;
    co_await vlSelfRef.__VtrigSched_h44fc30c7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                                         83);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__20__a_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__20__b_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__20__c_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__20__d_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__exp = 0xff80U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                         175);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__21__expected_val 
        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__21__casename = 
        std::string{"-inf + -inf = -inf"};
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__21__match = 0;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__21__ulp = 0;
    if ((([&]() {
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__22__val 
                        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result;
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__22__Vfuncout 
                        = (IData)(((0x7f80U == (0x7f80U 
                                                & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__22__val))) 
                                   & (0U != (0x7fU 
                                             & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__22__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__22__Vfuncout)) 
         & ([&]() {
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__23__val 
                        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__21__expected_val;
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__23__Vfuncout 
                        = (IData)(((0x7f80U == (0x7f80U 
                                                & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__23__val))) 
                                   & (0U != (0x7fU 
                                             & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__23__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__23__Vfuncout)))) {
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__21__match = 1U;
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__21__ulp = 0ULL;
    } else {
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__21__match 
            = ((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__21__expected_val));
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__24__b 
            = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__21__expected_val;
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__24__a 
            = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result;
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
            = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__24__a))
                ? (0x7fffffffULL - (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__24__a)))))
                : (0x80000000ULL + (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__24__a))))));
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
            = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__24__b))
                ? (0x7fffffffULL - (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__24__b)))))
                : (0x80000000ULL + (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__24__b))))));
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__24__Vfuncout 
            = (VL_GTS_IQQ(64, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                ? (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
                   - vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                : (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
                   - vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a));
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__21__ulp 
            = __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__24__Vfuncout;
    }
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
        = (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
           + __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__21__ulp);
    if (VL_LTS_IQQ(64, 1ULL, __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__21__ulp)) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count);
    }
    if (VL_GTS_IQQ(64, __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__21__ulp, 
                   VL_EXTENDS_QI(64,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp))) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp 
            = (IData)(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__21__ulp);
    }
    if (__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__21__match) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count);
    } else {
        if (VL_UNLIKELY((VL_GTS_III(32, 0xaU, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count)))) {
            VL_WRITEF_NX("FAIL: %@ | A=%x B=%x C=%x D=%x Got=%x Exp=%x AdderGot=%x | ULP=%0d\n",0,
                         -1,&(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__21__casename),
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a),
                         16,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b,
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c),
                         16,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d,
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result),
                         16,__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__21__expected_val,
                         35,vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out,
                         64,__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__21__ulp);
        }
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count);
    }
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__25__d_in = 0x3f80U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__25__c_in = 0x3f80U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__25__b_in = 0xff80U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__25__a_in = 0x7f80U;
    co_await vlSelfRef.__VtrigSched_h44fc30c7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                                         83);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__25__a_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__25__b_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__25__c_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__25__d_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__exp = 0x7fc0U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                         179);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__26__expected_val 
        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__26__casename = 
        std::string{"inf - inf = NaN"};
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__26__match = 0;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__26__ulp = 0;
    if ((([&]() {
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__27__val 
                        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result;
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__27__Vfuncout 
                        = (IData)(((0x7f80U == (0x7f80U 
                                                & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__27__val))) 
                                   & (0U != (0x7fU 
                                             & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__27__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__27__Vfuncout)) 
         & ([&]() {
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__28__val 
                        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__26__expected_val;
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__28__Vfuncout 
                        = (IData)(((0x7f80U == (0x7f80U 
                                                & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__28__val))) 
                                   & (0U != (0x7fU 
                                             & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__28__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__28__Vfuncout)))) {
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__26__match = 1U;
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__26__ulp = 0ULL;
    } else {
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__26__match 
            = ((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__26__expected_val));
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__29__b 
            = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__26__expected_val;
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__29__a 
            = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result;
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
            = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__29__a))
                ? (0x7fffffffULL - (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__29__a)))))
                : (0x80000000ULL + (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__29__a))))));
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
            = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__29__b))
                ? (0x7fffffffULL - (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__29__b)))))
                : (0x80000000ULL + (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__29__b))))));
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__29__Vfuncout 
            = (VL_GTS_IQQ(64, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                ? (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
                   - vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                : (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
                   - vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a));
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__26__ulp 
            = __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__29__Vfuncout;
    }
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
        = (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
           + __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__26__ulp);
    if (VL_LTS_IQQ(64, 1ULL, __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__26__ulp)) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count);
    }
    if (VL_GTS_IQQ(64, __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__26__ulp, 
                   VL_EXTENDS_QI(64,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp))) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp 
            = (IData)(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__26__ulp);
    }
    if (__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__26__match) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count);
    } else {
        if (VL_UNLIKELY((VL_GTS_III(32, 0xaU, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count)))) {
            VL_WRITEF_NX("FAIL: %@ | A=%x B=%x C=%x D=%x Got=%x Exp=%x AdderGot=%x | ULP=%0d\n",0,
                         -1,&(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__26__casename),
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a),
                         16,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b,
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c),
                         16,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d,
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result),
                         16,__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__26__expected_val,
                         35,vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out,
                         64,__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__26__ulp);
        }
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count);
    }
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__30__d_in = 0x4080U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__30__c_in = 0x4000U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__30__b_in = 0x3f80U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__30__a_in = 0x7fc0U;
    co_await vlSelfRef.__VtrigSched_h44fc30c7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                                         83);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__30__a_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__30__b_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__30__c_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__30__d_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__exp = 0x7fc0U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                         183);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__31__expected_val 
        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__31__casename = 
        std::string{"NaN + finite = NaN"};
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__31__match = 0;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__31__ulp = 0;
    if ((([&]() {
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__32__val 
                        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result;
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__32__Vfuncout 
                        = (IData)(((0x7f80U == (0x7f80U 
                                                & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__32__val))) 
                                   & (0U != (0x7fU 
                                             & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__32__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__32__Vfuncout)) 
         & ([&]() {
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__33__val 
                        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__31__expected_val;
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__33__Vfuncout 
                        = (IData)(((0x7f80U == (0x7f80U 
                                                & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__33__val))) 
                                   & (0U != (0x7fU 
                                             & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__33__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__33__Vfuncout)))) {
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__31__match = 1U;
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__31__ulp = 0ULL;
    } else {
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__31__match 
            = ((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__31__expected_val));
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__34__b 
            = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__31__expected_val;
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__34__a 
            = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result;
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
            = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__34__a))
                ? (0x7fffffffULL - (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__34__a)))))
                : (0x80000000ULL + (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__34__a))))));
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
            = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__34__b))
                ? (0x7fffffffULL - (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__34__b)))))
                : (0x80000000ULL + (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__34__b))))));
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__34__Vfuncout 
            = (VL_GTS_IQQ(64, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                ? (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
                   - vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                : (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
                   - vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a));
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__31__ulp 
            = __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__34__Vfuncout;
    }
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
        = (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
           + __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__31__ulp);
    if (VL_LTS_IQQ(64, 1ULL, __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__31__ulp)) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count);
    }
    if (VL_GTS_IQQ(64, __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__31__ulp, 
                   VL_EXTENDS_QI(64,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp))) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp 
            = (IData)(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__31__ulp);
    }
    if (__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__31__match) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count);
    } else {
        if (VL_UNLIKELY((VL_GTS_III(32, 0xaU, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count)))) {
            VL_WRITEF_NX("FAIL: %@ | A=%x B=%x C=%x D=%x Got=%x Exp=%x AdderGot=%x | ULP=%0d\n",0,
                         -1,&(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__31__casename),
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a),
                         16,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b,
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c),
                         16,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d,
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result),
                         16,__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__31__expected_val,
                         35,vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out,
                         64,__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__31__ulp);
        }
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count);
    }
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__35__d_in = 0x8000U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__35__c_in = 0x8000U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__35__b_in = 0x8000U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__35__a_in = 0x8000U;
    co_await vlSelfRef.__VtrigSched_h44fc30c7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                                         83);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__35__a_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__35__b_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__35__c_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__35__d_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__exp = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                         188);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__36__expected_val 
        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__36__casename = 
        std::string{"-0 + -0 + -0 + -0 = 0"};
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__36__match = 0;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__36__ulp = 0;
    if ((([&]() {
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__37__val 
                        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result;
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__37__Vfuncout 
                        = (IData)(((0x7f80U == (0x7f80U 
                                                & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__37__val))) 
                                   & (0U != (0x7fU 
                                             & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__37__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__37__Vfuncout)) 
         & ([&]() {
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__38__val 
                        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__36__expected_val;
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__38__Vfuncout 
                        = (IData)(((0x7f80U == (0x7f80U 
                                                & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__38__val))) 
                                   & (0U != (0x7fU 
                                             & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__38__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__38__Vfuncout)))) {
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__36__match = 1U;
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__36__ulp = 0ULL;
    } else {
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__36__match 
            = ((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__36__expected_val));
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__39__b 
            = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__36__expected_val;
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__39__a 
            = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result;
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
            = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__39__a))
                ? (0x7fffffffULL - (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__39__a)))))
                : (0x80000000ULL + (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__39__a))))));
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
            = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__39__b))
                ? (0x7fffffffULL - (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__39__b)))))
                : (0x80000000ULL + (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__39__b))))));
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__39__Vfuncout 
            = (VL_GTS_IQQ(64, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                ? (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
                   - vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                : (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
                   - vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a));
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__36__ulp 
            = __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__39__Vfuncout;
    }
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
        = (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
           + __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__36__ulp);
    if (VL_LTS_IQQ(64, 1ULL, __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__36__ulp)) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count);
    }
    if (VL_GTS_IQQ(64, __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__36__ulp, 
                   VL_EXTENDS_QI(64,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp))) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp 
            = (IData)(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__36__ulp);
    }
    if (__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__36__match) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count);
    } else {
        if (VL_UNLIKELY((VL_GTS_III(32, 0xaU, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count)))) {
            VL_WRITEF_NX("FAIL: %@ | A=%x B=%x C=%x D=%x Got=%x Exp=%x AdderGot=%x | ULP=%0d\n",0,
                         -1,&(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__36__casename),
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a),
                         16,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b,
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c),
                         16,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d,
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result),
                         16,__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__36__expected_val,
                         35,vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out,
                         64,__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__36__ulp);
        }
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count);
    }
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__40__d_in = 0U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__40__c_in = 0U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__40__b_in = 0xbf80U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__40__a_in = 0x3f80U;
    co_await vlSelfRef.__VtrigSched_h44fc30c7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                                         83);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__40__a_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__40__b_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__40__c_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__40__d_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__exp = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                         192);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__41__expected_val 
        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__41__casename = 
        std::string{"1 + (-1) = 0"};
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__41__match = 0;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__41__ulp = 0;
    if ((([&]() {
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__42__val 
                        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result;
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__42__Vfuncout 
                        = (IData)(((0x7f80U == (0x7f80U 
                                                & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__42__val))) 
                                   & (0U != (0x7fU 
                                             & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__42__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__42__Vfuncout)) 
         & ([&]() {
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__43__val 
                        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__41__expected_val;
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__43__Vfuncout 
                        = (IData)(((0x7f80U == (0x7f80U 
                                                & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__43__val))) 
                                   & (0U != (0x7fU 
                                             & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__43__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__43__Vfuncout)))) {
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__41__match = 1U;
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__41__ulp = 0ULL;
    } else {
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__41__match 
            = ((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__41__expected_val));
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__44__b 
            = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__41__expected_val;
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__44__a 
            = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result;
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
            = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__44__a))
                ? (0x7fffffffULL - (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__44__a)))))
                : (0x80000000ULL + (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__44__a))))));
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
            = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__44__b))
                ? (0x7fffffffULL - (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__44__b)))))
                : (0x80000000ULL + (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__44__b))))));
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__44__Vfuncout 
            = (VL_GTS_IQQ(64, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                ? (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
                   - vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                : (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
                   - vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a));
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__41__ulp 
            = __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__44__Vfuncout;
    }
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
        = (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
           + __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__41__ulp);
    if (VL_LTS_IQQ(64, 1ULL, __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__41__ulp)) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count);
    }
    if (VL_GTS_IQQ(64, __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__41__ulp, 
                   VL_EXTENDS_QI(64,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp))) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp 
            = (IData)(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__41__ulp);
    }
    if (__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__41__match) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count);
    } else {
        if (VL_UNLIKELY((VL_GTS_III(32, 0xaU, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count)))) {
            VL_WRITEF_NX("FAIL: %@ | A=%x B=%x C=%x D=%x Got=%x Exp=%x AdderGot=%x | ULP=%0d\n",0,
                         -1,&(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__41__casename),
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a),
                         16,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b,
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c),
                         16,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d,
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result),
                         16,__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__41__expected_val,
                         35,vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out,
                         64,__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__41__ulp);
        }
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count);
    }
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__45__d_in = 0U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__45__c_in = 0U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__45__b_in = 0x7f7fU;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__45__a_in = 0x7f7fU;
    co_await vlSelfRef.__VtrigSched_h44fc30c7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                                         83);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__45__a_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__45__b_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__45__c_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__45__d_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__exp = 0x7f80U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                         198);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__46__expected_val 
        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__46__casename = 
        std::string{"MaxFinite + MaxFinite = Inf (Overflow)"};
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__46__match = 0;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__46__ulp = 0;
    if ((([&]() {
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__47__val 
                        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result;
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__47__Vfuncout 
                        = (IData)(((0x7f80U == (0x7f80U 
                                                & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__47__val))) 
                                   & (0U != (0x7fU 
                                             & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__47__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__47__Vfuncout)) 
         & ([&]() {
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__48__val 
                        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__46__expected_val;
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__48__Vfuncout 
                        = (IData)(((0x7f80U == (0x7f80U 
                                                & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__48__val))) 
                                   & (0U != (0x7fU 
                                             & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__48__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__48__Vfuncout)))) {
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__46__match = 1U;
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__46__ulp = 0ULL;
    } else {
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__46__match 
            = ((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__46__expected_val));
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__49__b 
            = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__46__expected_val;
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__49__a 
            = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result;
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
            = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__49__a))
                ? (0x7fffffffULL - (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__49__a)))))
                : (0x80000000ULL + (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__49__a))))));
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
            = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__49__b))
                ? (0x7fffffffULL - (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__49__b)))))
                : (0x80000000ULL + (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__49__b))))));
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__49__Vfuncout 
            = (VL_GTS_IQQ(64, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                ? (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
                   - vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                : (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
                   - vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a));
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__46__ulp 
            = __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__49__Vfuncout;
    }
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
        = (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
           + __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__46__ulp);
    if (VL_LTS_IQQ(64, 1ULL, __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__46__ulp)) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count);
    }
    if (VL_GTS_IQQ(64, __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__46__ulp, 
                   VL_EXTENDS_QI(64,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp))) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp 
            = (IData)(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__46__ulp);
    }
    if (__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__46__match) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count);
    } else {
        if (VL_UNLIKELY((VL_GTS_III(32, 0xaU, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count)))) {
            VL_WRITEF_NX("FAIL: %@ | A=%x B=%x C=%x D=%x Got=%x Exp=%x AdderGot=%x | ULP=%0d\n",0,
                         -1,&(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__46__casename),
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a),
                         16,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b,
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c),
                         16,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d,
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result),
                         16,__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__46__expected_val,
                         35,vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out,
                         64,__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__46__ulp);
        }
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count);
    }
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__50__d_in = 1U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__50__c_in = 1U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__50__b_in = 1U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__50__a_in = 1U;
    co_await vlSelfRef.__VtrigSched_h44fc30c7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                                         83);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__50__a_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__50__b_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__50__c_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__50__d_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__exp = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                         204);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__51__expected_val 
        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__51__casename = 
        std::string{"Subnormals + Subnormals = 0 (FTZ check)"};
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__51__match = 0;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__51__ulp = 0;
    if ((([&]() {
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__52__val 
                        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result;
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__52__Vfuncout 
                        = (IData)(((0x7f80U == (0x7f80U 
                                                & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__52__val))) 
                                   & (0U != (0x7fU 
                                             & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__52__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__52__Vfuncout)) 
         & ([&]() {
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__53__val 
                        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__51__expected_val;
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__53__Vfuncout 
                        = (IData)(((0x7f80U == (0x7f80U 
                                                & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__53__val))) 
                                   & (0U != (0x7fU 
                                             & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__53__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__53__Vfuncout)))) {
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__51__match = 1U;
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__51__ulp = 0ULL;
    } else {
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__51__match 
            = ((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__51__expected_val));
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__54__b 
            = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__51__expected_val;
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__54__a 
            = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result;
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
            = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__54__a))
                ? (0x7fffffffULL - (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__54__a)))))
                : (0x80000000ULL + (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__54__a))))));
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
            = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__54__b))
                ? (0x7fffffffULL - (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__54__b)))))
                : (0x80000000ULL + (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__54__b))))));
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__54__Vfuncout 
            = (VL_GTS_IQQ(64, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                ? (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
                   - vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                : (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
                   - vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a));
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__51__ulp 
            = __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__54__Vfuncout;
    }
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
        = (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
           + __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__51__ulp);
    if (VL_LTS_IQQ(64, 1ULL, __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__51__ulp)) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count);
    }
    if (VL_GTS_IQQ(64, __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__51__ulp, 
                   VL_EXTENDS_QI(64,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp))) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp 
            = (IData)(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__51__ulp);
    }
    if (__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__51__match) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count);
    } else {
        if (VL_UNLIKELY((VL_GTS_III(32, 0xaU, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count)))) {
            VL_WRITEF_NX("FAIL: %@ | A=%x B=%x C=%x D=%x Got=%x Exp=%x AdderGot=%x | ULP=%0d\n",0,
                         -1,&(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__51__casename),
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a),
                         16,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b,
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c),
                         16,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d,
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result),
                         16,__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__51__expected_val,
                         35,vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out,
                         64,__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__51__ulp);
        }
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count);
    }
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__55__d_in = 0U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__55__c_in = 0U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__55__b_in = 0x7f7fU;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__55__a_in = 0x7f7fU;
    co_await vlSelfRef.__VtrigSched_h44fc30c7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add4_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                                         83);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__55__a_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__55__b_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__55__c_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d 
        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__test_case__55__d_in;
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__exp = 0x7f80U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                         211);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__56__expected_val 
        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__exp;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__56__casename = 
        std::string{"Overflow to Infinity"};
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__56__match = 0;
    __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__56__ulp = 0;
    if ((([&]() {
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__57__val 
                        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result;
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__57__Vfuncout 
                        = (IData)(((0x7f80U == (0x7f80U 
                                                & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__57__val))) 
                                   & (0U != (0x7fU 
                                             & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__57__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__57__Vfuncout)) 
         & ([&]() {
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__58__val 
                        = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__56__expected_val;
                    __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__58__Vfuncout 
                        = (IData)(((0x7f80U == (0x7f80U 
                                                & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__58__val))) 
                                   & (0U != (0x7fU 
                                             & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__58__val)))));
                }(), (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__58__Vfuncout)))) {
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__56__match = 1U;
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__56__ulp = 0ULL;
    } else {
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__56__match 
            = ((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__56__expected_val));
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__59__b 
            = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__56__expected_val;
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__59__a 
            = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result;
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
            = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__59__a))
                ? (0x7fffffffULL - (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__59__a)))))
                : (0x80000000ULL + (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__59__a))))));
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
            = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__59__b))
                ? (0x7fffffffULL - (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__59__b)))))
                : (0x80000000ULL + (QData)((IData)(
                                                   (0x7fffU 
                                                    & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__59__b))))));
        __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__59__Vfuncout 
            = (VL_GTS_IQQ(64, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                ? (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
                   - vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                : (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
                   - vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a));
        __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__56__ulp 
            = __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__59__Vfuncout;
    }
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
        = (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
           + __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__56__ulp);
    if (VL_LTS_IQQ(64, 1ULL, __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__56__ulp)) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count);
    }
    if (VL_GTS_IQQ(64, __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__56__ulp, 
                   VL_EXTENDS_QI(64,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp))) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp 
            = (IData)(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__56__ulp);
    }
    if (__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__56__match) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count);
    } else {
        if (VL_UNLIKELY((VL_GTS_III(32, 0xaU, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count)))) {
            VL_WRITEF_NX("FAIL: %@ | A=%x B=%x C=%x D=%x Got=%x Exp=%x AdderGot=%x | ULP=%0d\n",0,
                         -1,&(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__56__casename),
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a),
                         16,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b,
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c),
                         16,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d,
                         16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result),
                         16,__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__56__expected_val,
                         35,vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out,
                         64,__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__56__ulp);
        }
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count);
    }
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fd 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(14, Vadd4_fp32accum_bf16_tb_softfloat__ConstPool__CONST_hc773bd16_0)
                      , std::string{"r"});
    ;
    if (VL_UNLIKELY(((0U == vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fd)))) {
        VL_WRITEF_NX("ERROR: cannot open test vectors!\n",0);
        VL_FINISH_MT("tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 216, "");
    }
    (void)VL_FGETS_NI(add4_fp32accum_bf16_tb_softfloat__DOT__header, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fd);
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_count = 0U;
    while ((! (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fd ? feof(VL_CVT_I_FP(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fd)) : true))) {
        {
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__ret 
                = VL_FSCANF_INX(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fd,"%x,%x,%x,%x,%x\n",0,
                                16,&(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__a),
                                16,&(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__b),
                                16,&(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__c),
                                16,&(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__d),
                                16,&(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__expected)) ;
            if ((5U != vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__unnamedblk1__DOT__ret)) {
                goto __Vlabel1;
            }
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_count 
                = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_count);
            if (VL_UNLIKELY(((0U == VL_MODDIVS_III(32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_count, (IData)(0x186a0U)))))) {
                VL_WRITEF_NX("%0d test cases, %0d failed\n",0,
                             32,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_count,
                             32,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count);
            }
            co_await vlSelfRef.__VtrigSched_h44fc30c7__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge add4_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                                 "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                                                 227);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a 
                = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__a;
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b 
                = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__b;
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c 
                = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__c;
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d 
                = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__d;
            co_await vlSelfRef.__VdlySched.delay(0x1f40ULL, 
                                                 nullptr, 
                                                 "tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 
                                                 229);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__60__expected_val 
                = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__expected;
            __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__60__casename 
                = VL_SFORMATF_N_NX("Random case %0d",0,
                                   32,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_count) ;
            __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__60__match = 0;
            __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__60__ulp = 0;
            if ((([&]() {
                            __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__61__val 
                                = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result;
                            __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__61__Vfuncout 
                                = (IData)(((0x7f80U 
                                            == (0x7f80U 
                                                & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__61__val))) 
                                           & (0U != 
                                              (0x7fU 
                                               & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__61__val)))));
                        }(), (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__61__Vfuncout)) 
                 & ([&]() {
                            __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__62__val 
                                = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__60__expected_val;
                            __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__62__Vfuncout 
                                = (IData)(((0x7f80U 
                                            == (0x7f80U 
                                                & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__62__val))) 
                                           & (0U != 
                                              (0x7fU 
                                               & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__62__val)))));
                        }(), (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__is_nan__62__Vfuncout)))) {
                __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__60__match = 1U;
                __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__60__ulp = 0ULL;
            } else {
                __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__60__match 
                    = ((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result) 
                       == (IData)(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__60__expected_val));
                __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__63__b 
                    = __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__60__expected_val;
                __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__63__a 
                    = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result;
                vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
                    = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__63__a))
                        ? (0x7fffffffULL - (QData)((IData)(
                                                           (0x7fffU 
                                                            & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__63__a)))))
                        : (0x80000000ULL + (QData)((IData)(
                                                           (0x7fffU 
                                                            & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__63__a))))));
                vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
                    = ((0x8000U & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__63__b))
                        ? (0x7fffffffULL - (QData)((IData)(
                                                           (0x7fffU 
                                                            & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__63__b)))))
                        : (0x80000000ULL + (QData)((IData)(
                                                           (0x7fffU 
                                                            & (IData)(__Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__63__b))))));
                __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__63__Vfuncout 
                    = (VL_GTS_IQQ(64, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                        ? (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
                           - vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                        : (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
                           - vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a));
                __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__60__ulp 
                    = __Vfunc_add4_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__63__Vfuncout;
            }
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
                = (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
                   + __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__60__ulp);
            if (VL_LTS_IQQ(64, 1ULL, __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__60__ulp)) {
                vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count 
                    = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count);
            }
            if (VL_GTS_IQQ(64, __Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__60__ulp, 
                           VL_EXTENDS_QI(64,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp))) {
                vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp 
                    = (IData)(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__60__ulp);
            }
            if (__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__60__match) {
                vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count 
                    = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count);
            } else {
                if (VL_UNLIKELY((VL_GTS_III(32, 0xaU, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count)))) {
                    VL_WRITEF_NX("FAIL: %@ | A=%x B=%x C=%x D=%x Got=%x Exp=%x AdderGot=%x | ULP=%0d\n",0,
                                 -1,&(__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__60__casename),
                                 16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_a),
                                 16,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_b,
                                 16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_c),
                                 16,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_d,
                                 16,(IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result),
                                 16,__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__60__expected_val,
                                 35,vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out,
                                 64,__Vtask_add4_fp32accum_bf16_tb_softfloat__DOT__check_case__60__ulp);
                }
                vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count 
                    = ((IData)(1U) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count);
            }
            __Vlabel1: ;
        }
    }
    VL_WRITEF_NX("\n====================\nTOTAL CASES: %0d\nPASS: %0d\nFAIL: %0d\nAverage ULP error: %0f\nLargest ULP error: %0d\nNumber of cases with ULP > 1: %0d\n====================\n\n",0,
                 32,((IData)(0xcU) + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_count),
                 32,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count,
                 32,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count,
                 64,((0U != (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count 
                             + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count))
                      ? ((1.0 * VL_ISTOR_D_Q(64, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff)) 
                         / VL_ISTOR_D_I(32, (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__fail_count 
                                             + vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__pass_count)))
                      : 0.0),32,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__largest_ulp,
                 32,vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count);
    VL_FINISH_MT("tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv", 244, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4_fp32accum_bf16_tb_softfloat___024root___dump_triggers__act(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG

void Vadd4_fp32accum_bf16_tb_softfloat___024root___eval_triggers__act(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root___eval_triggers__act\n"); );
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__norm_val 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__norm_val__1));
    vlSelfRef.__VactTriggered.setBit(1U, ((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__add4_fp32accum_bf16_tb_softfloat__DOT__tb_clk__0))));
    vlSelfRef.__VactTriggered.setBit(2U, ((~ (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_nrst)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__add4_fp32accum_bf16_tb_softfloat__DOT__tb_nrst__0)));
    vlSelfRef.__VactTriggered.setBit(3U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__VactTriggered.setBit(4U, ((~ (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_clk)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__add4_fp32accum_bf16_tb_softfloat__DOT__tb_clk__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__norm_val__1 
        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__norm_val;
    vlSelfRef.__Vtrigprevexpr___TOP__add4_fp32accum_bf16_tb_softfloat__DOT__tb_clk__0 
        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__add4_fp32accum_bf16_tb_softfloat__DOT__tb_nrst__0 
        = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_nrst;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VactDidInit)))))) {
        vlSelfRef.__VactDidInit = 1U;
        vlSelfRef.__VactTriggered.setBit(0U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vadd4_fp32accum_bf16_tb_softfloat___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vadd4_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__1(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__1\n"); );
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out 
        = ((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_nrst)
            ? vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__result_out
            : 0ULL);
    if ((0U == vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_sum_mag)) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan = 0U;
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros = 0x1dU;
    } else {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan 
            = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_sum_mag;
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros = 0U;
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan, 0xeU))) {
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros 
                = (0x1fU & ((IData)(0x10U) + (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros)));
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan, 0x10U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan, 0x16U))) {
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros 
                = (0x1fU & ((IData)(8U) + (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros)));
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan, 8U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan, 0x1aU))) {
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros 
                = (0x1fU & ((IData)(4U) + (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros)));
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan, 4U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan, 0x1cU))) {
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros 
                = (0x1fU & ((IData)(2U) + (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros)));
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan, 2U));
        }
        if ((0U == VL_SHIFTR_III(32,32,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan, 0x1dU))) {
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros)));
            vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan 
                = (0x3fffffffU & VL_SHIFTL_III(30,30,32, vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lzd_scan, 1U));
        }
    }
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__norm_val 
        = (0x3fffffffU & (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_sum_mag 
                          << (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros)));
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__final_mant 
        = (0x3ffffffU & vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__rounded_mant_int);
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros 
        = (0x1fU & ((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros) 
                    - ((0x4000000U & vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__rounded_mant_int)
                        ? 1U : 0U)));
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(3U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,7, (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__lead_zeros))));
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__result_out 
        = ((((0U == vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_sum_mag) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_exp_base)))
            ? 0ULL : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__final_exp_calc)))
                       ? (0x3fc000000ULL | ((QData)((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_res_sign)) 
                                            << 0x22U))
                       : (((QData)((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_res_sign)) 
                           << 0x22U) | (((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__final_exp_calc)))) 
                                         << 0x1aU) 
                                        | (QData)((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__final_mant))))));
    if (vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_special) {
        vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__result_out 
            = vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__bf16adder__DOT__st2_spec_res;
    }
}

VL_INLINE_OPT void Vadd4_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__2(Vadd4_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__2\n"); );
    Vadd4_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__guard 
        = (1U & (IData)((vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out 
                         >> 0x12U)));
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__rnd 
        = (1U & (IData)((vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out 
                         >> 0x11U)));
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__sticky 
        = (0U != (0x1ffffU & (IData)(vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out)));
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__round_up 
        = ((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__guard) 
           & (((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__rnd) 
               | (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__sticky)) 
              | (IData)((vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out 
                         >> 0x13U))));
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__rounded 
        = (0xffU & ((0x7fU & (IData)((vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out 
                                      >> 0x13U))) + (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__round_up)));
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__new_exp 
        = (0x3ffU & (VL_EXTENDS_II(10,10, (0xffU & (IData)(
                                                           (vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out 
                                                            >> 0x1aU)))) 
                     + VL_EXTENDS_II(10,10, (1U & ((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__rounded) 
                                                   >> 7U)))));
    vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__tb_result 
        = ((0xffU == (0xffU & (IData)((vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out 
                                       >> 0x1aU))))
            ? (0x7f80U | ((0x8000U & ((IData)((vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out 
                                               >> 0x22U)) 
                                      << 0xfU)) | (
                                                   (0U 
                                                    != 
                                                    (0x3ffffffU 
                                                     & (IData)(vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out)))
                                                    ? 0x40U
                                                    : 0U)))
            : (VL_LTES_III(10, 0xffU, (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__new_exp))
                ? (0x7f80U | (0x8000U & ((IData)((vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out 
                                                  >> 0x22U)) 
                                         << 0xfU)))
                : (VL_GTES_III(32, 0U, VL_EXTENDS_II(32,10, (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__new_exp)))
                    ? (0x8000U & ((IData)((vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out 
                                           >> 0x22U)) 
                                  << 0xfU)) : ((0x8000U 
                                                & ((IData)(
                                                           (vlSymsp->TOP__add4_fp32accum_bf16_tb_softfloat__DOT__add_if.out 
                                                            >> 0x22U)) 
                                                   << 0xfU)) 
                                               | ((0x7f80U 
                                                   & ((IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__new_exp) 
                                                      << 7U)) 
                                                  | ((0x80U 
                                                      & (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__rounded))
                                                      ? 0U
                                                      : 
                                                     (0x7fU 
                                                      & (IData)(vlSelfRef.add4_fp32accum_bf16_tb_softfloat__DOT__reduce__DOT__rounded))))))));
}
