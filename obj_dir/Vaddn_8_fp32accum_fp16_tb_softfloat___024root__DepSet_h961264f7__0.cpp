// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaddn_8_fp32accum_fp16_tb_softfloat.h for the primary calling header

#include "Vaddn_8_fp32accum_fp16_tb_softfloat__pch.h"
#include "Vaddn_8_fp32accum_fp16_tb_softfloat__Syms.h"
#include "Vaddn_8_fp32accum_fp16_tb_softfloat___024root.h"

extern const VlWide<10>/*319:0*/ Vaddn_8_fp32accum_fp16_tb_softfloat__ConstPool__CONST_hef8811a1_0;
extern const VlWide<10>/*319:0*/ Vaddn_8_fp32accum_fp16_tb_softfloat__ConstPool__CONST_haabea970_0;
extern const VlWide<11>/*351:0*/ Vaddn_8_fp32accum_fp16_tb_softfloat__ConstPool__CONST_h2348213b_0;

VL_INLINE_OPT VlCoroutine Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__0(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    std::string addn_8_fp32accum_fp16_tb_softfloat__DOT__header;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__a;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__a = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__b;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__b = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__c;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__c = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__d;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__d = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__e;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__e = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__f;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__f = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__g;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__g = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__h;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__h = 0;
    std::string __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__1__casename;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__1__expected;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__1__expected = 0;
    CData/*0:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__1__match;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__1__match = 0;
    CData/*0:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__Vfuncout;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__val;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__val = 0;
    CData/*0:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__Vfuncout;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__val;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__val = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__a;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__a = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__b;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__b = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__c;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__c = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__d;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__d = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__e;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__e = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__f;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__f = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__g;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__g = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__h;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__h = 0;
    std::string __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__5__casename;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__5__expected;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__5__expected = 0;
    CData/*0:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__5__match;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__5__match = 0;
    CData/*0:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__Vfuncout;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__val;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__val = 0;
    CData/*0:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__Vfuncout;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__val;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__val = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__a;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__a = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__b;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__b = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__c;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__c = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__d;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__d = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__e;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__e = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__f;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__f = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__g;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__g = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__h;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__h = 0;
    std::string __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__9__casename;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__9__expected;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__9__expected = 0;
    CData/*0:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__9__match;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__9__match = 0;
    CData/*0:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__Vfuncout;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__val;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__val = 0;
    CData/*0:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__Vfuncout;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__val;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__val = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__a;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__a = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__b;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__b = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__c;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__c = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__d;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__d = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__e;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__e = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__f;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__f = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__g;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__g = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__h;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__h = 0;
    std::string __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__13__casename;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__13__expected;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__13__expected = 0;
    CData/*0:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__13__match;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__13__match = 0;
    CData/*0:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__Vfuncout;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__val;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__val = 0;
    CData/*0:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__Vfuncout;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__val;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__val = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__a;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__a = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__b;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__b = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__c;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__c = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__d;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__d = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__e;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__e = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__f;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__f = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__g;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__g = 0;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__h;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__h = 0;
    std::string __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__17__casename;
    SData/*15:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__17__expected;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__17__expected = 0;
    CData/*0:0*/ __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__17__match;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__17__match = 0;
    CData/*0:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__Vfuncout;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__val;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__val = 0;
    CData/*0:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__Vfuncout;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__val;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__val = 0;
    CData/*0:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__20__Vfuncout;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__20__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__20__val;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__20__val = 0;
    CData/*0:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__21__Vfuncout;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__21__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__21__val;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__21__val = 0;
    QData/*63:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__22__Vfuncout;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__22__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__22__a;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__22__a = 0;
    SData/*15:0*/ __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__22__b;
    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__22__b = 0;
    // Body
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(10, Vaddn_8_fp32accum_fp16_tb_softfloat__ConstPool__CONST_hef8811a1_0));
    vlSymsp->_traceDumpOpen();
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_fd 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(10, Vaddn_8_fp32accum_fp16_tb_softfloat__ConstPool__CONST_haabea970_0)
                      , std::string{"w"});
    ;
    VL_FWRITEF_NX(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"in0,in1,in2,in3,in4,in5,in6,in7,expected,got\n",0);
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__pass_count = 0U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_count = 0U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__ulp_big_count = 0U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__total_ulp_diff = 0.0;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__total_count = 0U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst = 0U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U] = 0U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U] = 0U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U] = 0U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U] = 0U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__unnamedblk1__DOT__i = 8U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv", 
                                         134);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv", 
                                         134);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("--- Hardcoded 8-input Addition Cases ---\n",0);
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__h = 0x3c00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__g = 0x3c00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__f = 0x3c00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__e = 0x3c00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__d = 0x3c00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__c = 0x3c00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__b = 0x3c00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__a = 0x3c00U;
    co_await vlSelfRef.__VtrigSched_h1382584b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_8_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv", 
                                                         66);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U] 
        = (((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__b) 
            << 0x10U) | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__a));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U] 
        = (IData)((((QData)((IData)((((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__f) 
                                      << 0x10U) | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__e)))) 
                    << 0x20U) | (QData)((IData)((((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__d) 
                                                  << 0x10U) 
                                                 | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__c))))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U] 
        = (IData)(((((QData)((IData)((((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__f) 
                                       << 0x10U) | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__e)))) 
                     << 0x20U) | (QData)((IData)((((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__d) 
                                                   << 0x10U) 
                                                  | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__c))))) 
                   >> 0x20U));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U] 
        = (((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__h) 
            << 0x10U) | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__0__g));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__exp = 0x4800U;
    co_await vlSelfRef.__VdlySched.delay(0x3e80ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv", 
                                         141);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__1__expected 
        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__1__casename = 
        std::string{"8 * 1.0 = 8.0"};
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__1__match = 0;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__1__match 
        = ((([&]() {
                    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__val 
                        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__val)))));
                }(), (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__2__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__val 
                        = __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__1__expected;
                    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__val)))));
                }(), (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__3__Vfuncout))) 
           || ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__1__expected)));
    if (VL_LIKELY((__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__1__match))) {
        VL_WRITEF_NX("passed %@ -> %x\n",0,-1,&(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__1__casename),
                     16,(IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__1__casename),
                     16,(IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__1__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x,%x,%x,%x,%x\n",0,
                      16,(0xffffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U]),
                      16,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U] 
                          >> 0x10U),16,(0xffffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U]),
                      16,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U] 
                          >> 0x10U),16,(0xffffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U]),
                      16,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U] 
                          >> 0x10U),16,(0xffffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U]),
                      16,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U] 
                          >> 0x10U),16,(IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__1__expected),
                      16,vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv", 
                                         141);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__h = 0U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__g = 0U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__f = 0U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__e = 0U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__d = 0U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__c = 0U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__b = 0U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__a = 0U;
    co_await vlSelfRef.__VtrigSched_h1382584b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_8_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv", 
                                                         66);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U] 
        = (((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__b) 
            << 0x10U) | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__a));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U] 
        = (IData)((((QData)((IData)((((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__f) 
                                      << 0x10U) | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__e)))) 
                    << 0x20U) | (QData)((IData)((((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__d) 
                                                  << 0x10U) 
                                                 | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__c))))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U] 
        = (IData)(((((QData)((IData)((((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__f) 
                                       << 0x10U) | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__e)))) 
                     << 0x20U) | (QData)((IData)((((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__d) 
                                                   << 0x10U) 
                                                  | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__c))))) 
                   >> 0x20U));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U] 
        = (((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__h) 
            << 0x10U) | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__4__g));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__exp = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x3e80ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv", 
                                         146);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__5__expected 
        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__5__casename = 
        std::string{"8 * 0.0 = 0.0"};
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__5__match = 0;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__5__match 
        = ((([&]() {
                    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__val 
                        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__val)))));
                }(), (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__6__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__val 
                        = __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__5__expected;
                    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__val)))));
                }(), (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__7__Vfuncout))) 
           || ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__5__expected)));
    if (VL_LIKELY((__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__5__match))) {
        VL_WRITEF_NX("passed %@ -> %x\n",0,-1,&(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__5__casename),
                     16,(IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__5__casename),
                     16,(IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__5__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x,%x,%x,%x,%x\n",0,
                      16,(0xffffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U]),
                      16,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U] 
                          >> 0x10U),16,(0xffffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U]),
                      16,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U] 
                          >> 0x10U),16,(0xffffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U]),
                      16,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U] 
                          >> 0x10U),16,(0xffffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U]),
                      16,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U] 
                          >> 0x10U),16,(IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__5__expected),
                      16,vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv", 
                                         146);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__h = 0xbc00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__g = 0xbc00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__f = 0xbc00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__e = 0xbc00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__d = 0x3c00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__c = 0x3c00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__b = 0x3c00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__a = 0x3c00U;
    co_await vlSelfRef.__VtrigSched_h1382584b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_8_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv", 
                                                         66);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U] 
        = (((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__b) 
            << 0x10U) | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__a));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U] 
        = (IData)((((QData)((IData)((((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__f) 
                                      << 0x10U) | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__e)))) 
                    << 0x20U) | (QData)((IData)((((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__d) 
                                                  << 0x10U) 
                                                 | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__c))))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U] 
        = (IData)(((((QData)((IData)((((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__f) 
                                       << 0x10U) | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__e)))) 
                     << 0x20U) | (QData)((IData)((((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__d) 
                                                   << 0x10U) 
                                                  | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__c))))) 
                   >> 0x20U));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U] 
        = (((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__h) 
            << 0x10U) | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__8__g));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__exp = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x3e80ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv", 
                                         151);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__9__expected 
        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__9__casename = 
        std::string{"4*(1) + 4*(-1) = 0"};
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__9__match = 0;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__9__match 
        = ((([&]() {
                    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__val 
                        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__val)))));
                }(), (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__10__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__val 
                        = __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__9__expected;
                    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__val)))));
                }(), (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__11__Vfuncout))) 
           || ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__9__expected)));
    if (VL_LIKELY((__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__9__match))) {
        VL_WRITEF_NX("passed %@ -> %x\n",0,-1,&(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__9__casename),
                     16,(IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__9__casename),
                     16,(IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__9__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x,%x,%x,%x,%x\n",0,
                      16,(0xffffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U]),
                      16,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U] 
                          >> 0x10U),16,(0xffffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U]),
                      16,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U] 
                          >> 0x10U),16,(0xffffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U]),
                      16,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U] 
                          >> 0x10U),16,(0xffffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U]),
                      16,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U] 
                          >> 0x10U),16,(IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__9__expected),
                      16,vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv", 
                                         151);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__h = 0x3c00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__g = 0x3c00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__f = 0x3c00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__e = 0x3c00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__d = 0x3c00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__c = 0x3c00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__b = 0x3c00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__a = 0x7c00U;
    co_await vlSelfRef.__VtrigSched_h1382584b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_8_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv", 
                                                         66);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U] 
        = (((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__b) 
            << 0x10U) | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__a));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U] 
        = (IData)((((QData)((IData)((((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__f) 
                                      << 0x10U) | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__e)))) 
                    << 0x20U) | (QData)((IData)((((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__d) 
                                                  << 0x10U) 
                                                 | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__c))))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U] 
        = (IData)(((((QData)((IData)((((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__f) 
                                       << 0x10U) | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__e)))) 
                     << 0x20U) | (QData)((IData)((((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__d) 
                                                   << 0x10U) 
                                                  | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__c))))) 
                   >> 0x20U));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U] 
        = (((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__h) 
            << 0x10U) | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__12__g));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__exp = 0x7c00U;
    co_await vlSelfRef.__VdlySched.delay(0x3e80ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv", 
                                         156);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__13__expected 
        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__13__casename = 
        std::string{"Inf + 7*1 = Inf"};
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__13__match = 0;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__13__match 
        = ((([&]() {
                    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__val 
                        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__val)))));
                }(), (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__14__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__val 
                        = __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__13__expected;
                    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__val)))));
                }(), (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__15__Vfuncout))) 
           || ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__13__expected)));
    if (VL_LIKELY((__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__13__match))) {
        VL_WRITEF_NX("passed %@ -> %x\n",0,-1,&(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__13__casename),
                     16,(IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__13__casename),
                     16,(IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__13__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x,%x,%x,%x,%x\n",0,
                      16,(0xffffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U]),
                      16,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U] 
                          >> 0x10U),16,(0xffffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U]),
                      16,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U] 
                          >> 0x10U),16,(0xffffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U]),
                      16,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U] 
                          >> 0x10U),16,(0xffffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U]),
                      16,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U] 
                          >> 0x10U),16,(IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__13__expected),
                      16,vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv", 
                                         156);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__h = 0x3c00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__g = 0x3c00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__f = 0x3c00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__e = 0x3c00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__d = 0x3c00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__c = 0x3c00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__b = 0xfc00U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__a = 0x7c00U;
    co_await vlSelfRef.__VtrigSched_h1382584b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge addn_8_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                         "tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv", 
                                                         66);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U] 
        = (((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__b) 
            << 0x10U) | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__a));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U] 
        = (IData)((((QData)((IData)((((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__f) 
                                      << 0x10U) | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__e)))) 
                    << 0x20U) | (QData)((IData)((((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__d) 
                                                  << 0x10U) 
                                                 | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__c))))));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U] 
        = (IData)(((((QData)((IData)((((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__f) 
                                       << 0x10U) | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__e)))) 
                     << 0x20U) | (QData)((IData)((((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__d) 
                                                   << 0x10U) 
                                                  | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__c))))) 
                   >> 0x20U));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U] 
        = (((IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__h) 
            << 0x10U) | (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__test_case__16__g));
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__exp = 0x7d00U;
    co_await vlSelfRef.__VdlySched.delay(0x3e80ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv", 
                                         161);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__17__expected 
        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__exp;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__17__casename = 
        std::string{"+Inf + -Inf + 6*1 = NaN"};
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__17__match = 0;
    __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__17__match 
        = ((([&]() {
                    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__val 
                        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__val)))));
                }(), (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__18__Vfuncout)) 
            & ([&]() {
                    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__val 
                        = __Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__17__expected;
                    __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__val)))));
                }(), (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__19__Vfuncout))) 
           || ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
               == (IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__17__expected)));
    if (VL_LIKELY((__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__17__match))) {
        VL_WRITEF_NX("passed %@ -> %x\n",0,-1,&(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__17__casename),
                     16,(IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result));
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__pass_count);
    } else {
        VL_WRITEF_NX("failed test for %@: Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__17__casename),
                     16,(IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result),
                     16,__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__17__expected);
        VL_FWRITEF_NX(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x,%x,%x,%x,%x\n",0,
                      16,(0xffffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U]),
                      16,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U] 
                          >> 0x10U),16,(0xffffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U]),
                      16,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U] 
                          >> 0x10U),16,(0xffffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U]),
                      16,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U] 
                          >> 0x10U),16,(0xffffU & vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U]),
                      16,(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U] 
                          >> 0x10U),16,(IData)(__Vtask_addn_8_fp32accum_fp16_tb_softfloat__DOT__check_case__17__expected),
                      16,vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result);
        vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv", 
                                         161);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("\n--- Berkeley SoftFloat Random Test Cases ---\n",0);
    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fd 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(11, Vaddn_8_fp32accum_fp16_tb_softfloat__ConstPool__CONST_h2348213b_0)
                      , std::string{"r"});
    ;
    if (VL_UNLIKELY(((0U == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fd)))) {
        VL_WRITEF_NX("error: could not open testfloat_cases_8_pure_fp32accum_fp16.csv\nmake sure you generated an 8-input CSV!\n",0);
        VL_FINISH_MT("tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv", 170, "");
    }
    (void)VL_FGETS_NI(addn_8_fp32accum_fp16_tb_softfloat__DOT__header, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fd);
    while ((! (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fd ? feof(VL_CVT_I_FP(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fd)) : true))) {
        {
            vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__unnamedblk2__DOT__ret 
                = VL_FSCANF_INX(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fd,"%x,%x,%x,%x,%x,%x,%x,%x,%x\n",0,
                                16,&(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__a),
                                16,&(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__b),
                                16,&(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__c),
                                16,&(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__d),
                                16,&(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__e),
                                16,&(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__f),
                                16,&(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__g),
                                16,&(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__h),
                                16,&(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__expected)) ;
            if ((9U != vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__unnamedblk2__DOT__ret)) {
                goto __Vlabel1;
            }
            vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__total_count 
                = ((IData)(1U) + vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__total_count);
            co_await vlSelfRef.__VtrigSched_h1382584b__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge addn_8_fp32accum_fp16_tb_softfloat.tb_clk)", 
                                                                 "tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv", 
                                                                 185);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[0U] 
                = (((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__b) 
                    << 0x10U) | (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__a));
            vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[1U] 
                = (IData)((((QData)((IData)((((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__f) 
                                              << 0x10U) 
                                             | (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__e)))) 
                            << 0x20U) | (QData)((IData)(
                                                        (((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__d) 
                                                          << 0x10U) 
                                                         | (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__c))))));
            vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[2U] 
                = (IData)(((((QData)((IData)((((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__f) 
                                               << 0x10U) 
                                              | (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__e)))) 
                             << 0x20U) | (QData)((IData)(
                                                         (((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__d) 
                                                           << 0x10U) 
                                                          | (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__c))))) 
                           >> 0x20U));
            vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_in_data[3U] 
                = (((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__h) 
                    << 0x10U) | (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__g));
            co_await vlSelfRef.__VdlySched.delay(0x36b0ULL, 
                                                 nullptr, 
                                                 "tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv", 
                                                 189);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__unnamedblk2__DOT__is_zero_result 
                = (((0U == (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result)) 
                    | (0x8000U == (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result))) 
                   & ((0U == (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__expected)) 
                      | (0x8000U == (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__expected))));
            if ((([&]() {
                            __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__20__val 
                                = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                            __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__20__Vfuncout 
                                = (IData)(((0x7c00U 
                                            == (0x7c00U 
                                                & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__20__val))) 
                                           & (0U != 
                                              (0x3ffU 
                                               & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__20__val)))));
                        }(), (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__20__Vfuncout)) 
                 & ([&]() {
                            __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__21__val 
                                = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__expected;
                            __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__21__Vfuncout 
                                = (IData)(((0x7c00U 
                                            == (0x7c00U 
                                                & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__21__val))) 
                                           & (0U != 
                                              (0x3ffU 
                                               & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__21__val)))));
                        }(), (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__is_nan__21__Vfuncout)))) {
                vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__pass_count 
                    = ((IData)(1U) + vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__pass_count);
            } else if (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__unnamedblk2__DOT__is_zero_result) {
                vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__pass_count 
                    = ((IData)(1U) + vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__pass_count);
            } else if (VL_UNLIKELY((((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result) 
                                     != (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__expected))))) {
                VL_FWRITEF_NX(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_fd,"%x,%x,%x,%x,%x,%x,%x,%x,%x,%x\n",0,
                              16,vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__a,
                              16,(IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__b),
                              16,vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__c,
                              16,(IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__d),
                              16,vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__e,
                              16,(IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__f),
                              16,vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__g,
                              16,(IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__h),
                              16,vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__expected,
                              16,(IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result));
                vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_count 
                    = ((IData)(1U) + vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_count);
                if (VL_UNLIKELY((VL_GTES_III(32, 0xaU, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_count)))) {
                    VL_WRITEF_NX("FAIL: Got_fp16=%x, Got_fp32=%x, Exp=%x\n",0,
                                 16,vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result,
                                 32,vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_raw_out,
                                 16,(IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__expected));
                } else if (VL_UNLIKELY(((0xbU == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_count)))) {
                    VL_WRITEF_NX("... (suppressing terminal output) ...\n",0);
                }
                vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__ulp_diff 
                    = (IData)(([&]() {
                            __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__22__b 
                                = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__expected;
                            __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__22__a 
                                = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result;
                            vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
                                = ((0x8000U & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__22__a))
                                    ? (0x7fffffffULL 
                                       - (QData)((IData)(
                                                         (0x7fffU 
                                                          & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__22__a)))))
                                    : (0x80000000ULL 
                                       + (QData)((IData)(
                                                         (0x7fffU 
                                                          & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__22__a))))));
                            vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
                                = ((0x8000U & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__22__b))
                                    ? (0x7fffffffULL 
                                       - (QData)((IData)(
                                                         (0x7fffU 
                                                          & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__22__b)))))
                                    : (0x80000000ULL 
                                       + (QData)((IData)(
                                                         (0x7fffU 
                                                          & (IData)(__Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__22__b))))));
                            __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__22__Vfuncout 
                                = (VL_GTS_IQQ(64, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                                    ? (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a 
                                       - vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b)
                                    : (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_b 
                                       - vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__Vstatic__int_a));
                        }(), __Vfunc_addn_8_fp32accum_fp16_tb_softfloat__DOT__get_ulp_distance__22__Vfuncout));
                vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__total_ulp_diff 
                    = (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__total_ulp_diff 
                       + VL_ISTOR_D_I(32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__ulp_diff));
                if (VL_UNLIKELY(((VL_LTES_III(32, 0xaU, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__ulp_diff) 
                                  & VL_GTS_III(32, 0xaU, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__ulp_big_count))))) {
                    VL_WRITEF_NX("FAIL ULP>=10: Got_fp16=%x, Exp=%x | ULP diff: %0d\n",0,
                                 16,vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_result,
                                 16,(IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__expected),
                                 32,vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__ulp_diff);
                    vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__ulp_big_count 
                        = ((IData)(1U) + vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__ulp_big_count);
                }
            } else {
                vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__pass_count 
                    = ((IData)(1U) + vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__pass_count);
            }
            if (VL_UNLIKELY(((0U == VL_MODDIVS_III(32, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__total_count, (IData)(0x186a0U)))))) {
                VL_WRITEF_NX("progress: %0d tested (%0d pass, %0d fail)...\n",0,
                             32,vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__total_count,
                             32,vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__pass_count,
                             32,vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_count);
            }
            __Vlabel1: ;
        }
    }
    VL_FCLOSE_I(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fd); VL_FCLOSE_I(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_fd); VL_WRITEF_NX("\n=== test summary ===\nNUM_INPUTS: 8\nPRECISION_BITS: 1\nPASSED: %0d\nFAILED: %0d\nAverage ULP difference: %f\n",0,
                                                                                32,
                                                                                vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__pass_count,
                                                                                32,
                                                                                vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_count,
                                                                                64,
                                                                                (vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__total_ulp_diff 
                                                                                / 
                                                                                VL_ISTOR_D_I(32, 
                                                                                (VL_LTS_III(32, 0U, vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_count)
                                                                                 ? vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_count
                                                                                 : 1U))));
    if ((0U == vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__fail_count)) {
        VL_WRITEF_NX("ALL TESTS PASSED!\n",0);
    } else {
        VL_WRITEF_NX("SOME TESTS FAILED!\n",0);
    }
    VL_FINISH_MT("tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv", 237, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___dump_triggers__act(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG

void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_triggers__act(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_triggers__act\n"); );
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_clk__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst__0)));
    vlSelfRef.__VactTriggered.setBit(2U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__VactTriggered.setBit(3U, ((~ (IData)(vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_clk)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_clk__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_clk__0 
        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst__0 
        = vlSelfRef.addn_8_fp32accum_fp16_tb_softfloat__DOT__tb_nrst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vaddn_8_fp32accum_fp16_tb_softfloat___024root___dump_triggers__act(vlSelf);
    }
#endif
}
