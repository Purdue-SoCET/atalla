// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd_fp16_tb_full.h for the primary calling header

#include "Vadd_fp16_tb_full__pch.h"
#include "Vadd_fp16_tb_full___024root.h"

VlCoroutine Vadd_fp16_tb_full___024root___eval_initial__TOP__Vtiming__0(Vadd_fp16_tb_full___024root* vlSelf);
VlCoroutine Vadd_fp16_tb_full___024root___eval_initial__TOP__Vtiming__1(Vadd_fp16_tb_full___024root* vlSelf);

void Vadd_fp16_tb_full___024root___eval_initial(Vadd_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root___eval_initial\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vadd_fp16_tb_full___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vadd_fp16_tb_full___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

extern const VlWide<10>/*319:0*/ Vadd_fp16_tb_full__ConstPool__CONST_h94864378_0;

VL_INLINE_OPT VlCoroutine Vadd_fp16_tb_full___024root___eval_initial__TOP__Vtiming__0(Vadd_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    std::string add_fp16_tb_full__DOT__header;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__0__a;
    __Vtask_add_fp16_tb_full__DOT__test_case__0__a = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__0__b;
    __Vtask_add_fp16_tb_full__DOT__test_case__0__b = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__0__is_sub;
    __Vtask_add_fp16_tb_full__DOT__test_case__0__is_sub = 0;
    std::string __Vtask_add_fp16_tb_full__DOT__check_case__1__casename;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__1__expected;
    __Vtask_add_fp16_tb_full__DOT__check_case__1__expected = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__1__match;
    __Vtask_add_fp16_tb_full__DOT__check_case__1__match = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__2__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__2__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__2__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__2__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__3__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__3__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__3__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__3__val = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__4__a;
    __Vtask_add_fp16_tb_full__DOT__test_case__4__a = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__4__b;
    __Vtask_add_fp16_tb_full__DOT__test_case__4__b = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__4__is_sub;
    __Vtask_add_fp16_tb_full__DOT__test_case__4__is_sub = 0;
    std::string __Vtask_add_fp16_tb_full__DOT__check_case__5__casename;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__5__expected;
    __Vtask_add_fp16_tb_full__DOT__check_case__5__expected = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__5__match;
    __Vtask_add_fp16_tb_full__DOT__check_case__5__match = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__6__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__6__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__6__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__6__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__7__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__7__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__7__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__7__val = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__8__a;
    __Vtask_add_fp16_tb_full__DOT__test_case__8__a = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__8__b;
    __Vtask_add_fp16_tb_full__DOT__test_case__8__b = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__8__is_sub;
    __Vtask_add_fp16_tb_full__DOT__test_case__8__is_sub = 0;
    std::string __Vtask_add_fp16_tb_full__DOT__check_case__9__casename;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__9__expected;
    __Vtask_add_fp16_tb_full__DOT__check_case__9__expected = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__9__match;
    __Vtask_add_fp16_tb_full__DOT__check_case__9__match = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__10__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__10__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__10__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__10__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__11__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__11__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__11__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__11__val = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__12__a;
    __Vtask_add_fp16_tb_full__DOT__test_case__12__a = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__12__b;
    __Vtask_add_fp16_tb_full__DOT__test_case__12__b = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__12__is_sub;
    __Vtask_add_fp16_tb_full__DOT__test_case__12__is_sub = 0;
    std::string __Vtask_add_fp16_tb_full__DOT__check_case__13__casename;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__13__expected;
    __Vtask_add_fp16_tb_full__DOT__check_case__13__expected = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__13__match;
    __Vtask_add_fp16_tb_full__DOT__check_case__13__match = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__14__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__14__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__14__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__14__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__15__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__15__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__15__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__15__val = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__16__a;
    __Vtask_add_fp16_tb_full__DOT__test_case__16__a = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__16__b;
    __Vtask_add_fp16_tb_full__DOT__test_case__16__b = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__16__is_sub;
    __Vtask_add_fp16_tb_full__DOT__test_case__16__is_sub = 0;
    std::string __Vtask_add_fp16_tb_full__DOT__check_case__17__casename;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__17__expected;
    __Vtask_add_fp16_tb_full__DOT__check_case__17__expected = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__17__match;
    __Vtask_add_fp16_tb_full__DOT__check_case__17__match = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__18__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__18__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__18__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__18__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__19__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__19__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__19__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__19__val = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__20__a;
    __Vtask_add_fp16_tb_full__DOT__test_case__20__a = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__20__b;
    __Vtask_add_fp16_tb_full__DOT__test_case__20__b = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__20__is_sub;
    __Vtask_add_fp16_tb_full__DOT__test_case__20__is_sub = 0;
    std::string __Vtask_add_fp16_tb_full__DOT__check_case__21__casename;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__21__expected;
    __Vtask_add_fp16_tb_full__DOT__check_case__21__expected = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__21__match;
    __Vtask_add_fp16_tb_full__DOT__check_case__21__match = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__22__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__22__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__22__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__22__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__23__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__23__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__23__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__23__val = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__24__a;
    __Vtask_add_fp16_tb_full__DOT__test_case__24__a = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__24__b;
    __Vtask_add_fp16_tb_full__DOT__test_case__24__b = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__24__is_sub;
    __Vtask_add_fp16_tb_full__DOT__test_case__24__is_sub = 0;
    std::string __Vtask_add_fp16_tb_full__DOT__check_case__25__casename;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__25__expected;
    __Vtask_add_fp16_tb_full__DOT__check_case__25__expected = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__25__match;
    __Vtask_add_fp16_tb_full__DOT__check_case__25__match = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__26__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__26__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__26__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__26__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__27__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__27__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__27__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__27__val = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__28__a;
    __Vtask_add_fp16_tb_full__DOT__test_case__28__a = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__28__b;
    __Vtask_add_fp16_tb_full__DOT__test_case__28__b = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__28__is_sub;
    __Vtask_add_fp16_tb_full__DOT__test_case__28__is_sub = 0;
    std::string __Vtask_add_fp16_tb_full__DOT__check_case__29__casename;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__29__expected;
    __Vtask_add_fp16_tb_full__DOT__check_case__29__expected = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__29__match;
    __Vtask_add_fp16_tb_full__DOT__check_case__29__match = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__30__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__30__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__30__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__30__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__31__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__31__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__31__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__31__val = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__32__a;
    __Vtask_add_fp16_tb_full__DOT__test_case__32__a = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__32__b;
    __Vtask_add_fp16_tb_full__DOT__test_case__32__b = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__32__is_sub;
    __Vtask_add_fp16_tb_full__DOT__test_case__32__is_sub = 0;
    std::string __Vtask_add_fp16_tb_full__DOT__check_case__33__casename;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__33__expected;
    __Vtask_add_fp16_tb_full__DOT__check_case__33__expected = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__33__match;
    __Vtask_add_fp16_tb_full__DOT__check_case__33__match = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__34__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__34__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__34__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__34__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__35__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__35__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__35__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__35__val = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__36__a;
    __Vtask_add_fp16_tb_full__DOT__test_case__36__a = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__36__b;
    __Vtask_add_fp16_tb_full__DOT__test_case__36__b = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__36__is_sub;
    __Vtask_add_fp16_tb_full__DOT__test_case__36__is_sub = 0;
    std::string __Vtask_add_fp16_tb_full__DOT__check_case__37__casename;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__37__expected;
    __Vtask_add_fp16_tb_full__DOT__check_case__37__expected = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__37__match;
    __Vtask_add_fp16_tb_full__DOT__check_case__37__match = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__38__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__38__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__38__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__38__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__39__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__39__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__39__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__39__val = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__40__a;
    __Vtask_add_fp16_tb_full__DOT__test_case__40__a = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__40__b;
    __Vtask_add_fp16_tb_full__DOT__test_case__40__b = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__40__is_sub;
    __Vtask_add_fp16_tb_full__DOT__test_case__40__is_sub = 0;
    std::string __Vtask_add_fp16_tb_full__DOT__check_case__41__casename;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__41__expected;
    __Vtask_add_fp16_tb_full__DOT__check_case__41__expected = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__41__match;
    __Vtask_add_fp16_tb_full__DOT__check_case__41__match = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__42__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__42__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__42__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__42__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__43__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__43__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__43__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__43__val = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__44__a;
    __Vtask_add_fp16_tb_full__DOT__test_case__44__a = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__44__b;
    __Vtask_add_fp16_tb_full__DOT__test_case__44__b = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__44__is_sub;
    __Vtask_add_fp16_tb_full__DOT__test_case__44__is_sub = 0;
    std::string __Vtask_add_fp16_tb_full__DOT__check_case__45__casename;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__45__expected;
    __Vtask_add_fp16_tb_full__DOT__check_case__45__expected = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__45__match;
    __Vtask_add_fp16_tb_full__DOT__check_case__45__match = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__46__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__46__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__46__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__46__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__47__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__47__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__47__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__47__val = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__48__a;
    __Vtask_add_fp16_tb_full__DOT__test_case__48__a = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__48__b;
    __Vtask_add_fp16_tb_full__DOT__test_case__48__b = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__48__is_sub;
    __Vtask_add_fp16_tb_full__DOT__test_case__48__is_sub = 0;
    std::string __Vtask_add_fp16_tb_full__DOT__check_case__49__casename;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__49__expected;
    __Vtask_add_fp16_tb_full__DOT__check_case__49__expected = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__49__match;
    __Vtask_add_fp16_tb_full__DOT__check_case__49__match = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__50__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__50__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__50__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__50__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__51__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__51__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__51__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__51__val = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__52__a;
    __Vtask_add_fp16_tb_full__DOT__test_case__52__a = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__52__b;
    __Vtask_add_fp16_tb_full__DOT__test_case__52__b = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__52__is_sub;
    __Vtask_add_fp16_tb_full__DOT__test_case__52__is_sub = 0;
    std::string __Vtask_add_fp16_tb_full__DOT__check_case__53__casename;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__53__expected;
    __Vtask_add_fp16_tb_full__DOT__check_case__53__expected = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__53__match;
    __Vtask_add_fp16_tb_full__DOT__check_case__53__match = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__54__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__54__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__54__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__54__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__55__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__55__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__55__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__55__val = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__56__a;
    __Vtask_add_fp16_tb_full__DOT__test_case__56__a = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__56__b;
    __Vtask_add_fp16_tb_full__DOT__test_case__56__b = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__56__is_sub;
    __Vtask_add_fp16_tb_full__DOT__test_case__56__is_sub = 0;
    std::string __Vtask_add_fp16_tb_full__DOT__check_case__57__casename;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__57__expected;
    __Vtask_add_fp16_tb_full__DOT__check_case__57__expected = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__57__match;
    __Vtask_add_fp16_tb_full__DOT__check_case__57__match = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__58__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__58__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__58__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__58__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__59__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__59__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__59__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__59__val = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__60__a;
    __Vtask_add_fp16_tb_full__DOT__test_case__60__a = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__60__b;
    __Vtask_add_fp16_tb_full__DOT__test_case__60__b = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__60__is_sub;
    __Vtask_add_fp16_tb_full__DOT__test_case__60__is_sub = 0;
    std::string __Vtask_add_fp16_tb_full__DOT__check_case__61__casename;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__61__expected;
    __Vtask_add_fp16_tb_full__DOT__check_case__61__expected = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__61__match;
    __Vtask_add_fp16_tb_full__DOT__check_case__61__match = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__62__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__62__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__62__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__62__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__63__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__63__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__63__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__63__val = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__64__a;
    __Vtask_add_fp16_tb_full__DOT__test_case__64__a = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__64__b;
    __Vtask_add_fp16_tb_full__DOT__test_case__64__b = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__64__is_sub;
    __Vtask_add_fp16_tb_full__DOT__test_case__64__is_sub = 0;
    std::string __Vtask_add_fp16_tb_full__DOT__check_case__65__casename;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__65__expected;
    __Vtask_add_fp16_tb_full__DOT__check_case__65__expected = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__65__match;
    __Vtask_add_fp16_tb_full__DOT__check_case__65__match = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__66__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__66__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__66__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__66__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__67__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__67__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__67__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__67__val = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__68__a;
    __Vtask_add_fp16_tb_full__DOT__test_case__68__a = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__68__b;
    __Vtask_add_fp16_tb_full__DOT__test_case__68__b = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__68__is_sub;
    __Vtask_add_fp16_tb_full__DOT__test_case__68__is_sub = 0;
    std::string __Vtask_add_fp16_tb_full__DOT__check_case__69__casename;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__69__expected;
    __Vtask_add_fp16_tb_full__DOT__check_case__69__expected = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__69__match;
    __Vtask_add_fp16_tb_full__DOT__check_case__69__match = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__70__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__70__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__70__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__70__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__71__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__71__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__71__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__71__val = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__72__a;
    __Vtask_add_fp16_tb_full__DOT__test_case__72__a = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__72__b;
    __Vtask_add_fp16_tb_full__DOT__test_case__72__b = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__72__is_sub;
    __Vtask_add_fp16_tb_full__DOT__test_case__72__is_sub = 0;
    std::string __Vtask_add_fp16_tb_full__DOT__check_case__73__casename;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__73__expected;
    __Vtask_add_fp16_tb_full__DOT__check_case__73__expected = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__73__match;
    __Vtask_add_fp16_tb_full__DOT__check_case__73__match = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__74__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__74__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__74__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__74__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__75__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__75__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__75__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__75__val = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__76__a;
    __Vtask_add_fp16_tb_full__DOT__test_case__76__a = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__76__b;
    __Vtask_add_fp16_tb_full__DOT__test_case__76__b = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__76__is_sub;
    __Vtask_add_fp16_tb_full__DOT__test_case__76__is_sub = 0;
    std::string __Vtask_add_fp16_tb_full__DOT__check_case__77__casename;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__77__expected;
    __Vtask_add_fp16_tb_full__DOT__check_case__77__expected = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__77__match;
    __Vtask_add_fp16_tb_full__DOT__check_case__77__match = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__78__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__78__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__78__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__78__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__79__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__79__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__79__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__79__val = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__80__a;
    __Vtask_add_fp16_tb_full__DOT__test_case__80__a = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__80__b;
    __Vtask_add_fp16_tb_full__DOT__test_case__80__b = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__80__is_sub;
    __Vtask_add_fp16_tb_full__DOT__test_case__80__is_sub = 0;
    std::string __Vtask_add_fp16_tb_full__DOT__check_case__81__casename;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__81__expected;
    __Vtask_add_fp16_tb_full__DOT__check_case__81__expected = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__81__match;
    __Vtask_add_fp16_tb_full__DOT__check_case__81__match = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__82__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__82__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__82__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__82__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__83__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__83__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__83__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__83__val = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__84__a;
    __Vtask_add_fp16_tb_full__DOT__test_case__84__a = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__84__b;
    __Vtask_add_fp16_tb_full__DOT__test_case__84__b = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__84__is_sub;
    __Vtask_add_fp16_tb_full__DOT__test_case__84__is_sub = 0;
    std::string __Vtask_add_fp16_tb_full__DOT__check_case__85__casename;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__85__expected;
    __Vtask_add_fp16_tb_full__DOT__check_case__85__expected = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__85__match;
    __Vtask_add_fp16_tb_full__DOT__check_case__85__match = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__86__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__86__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__86__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__86__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__87__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__87__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__87__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__87__val = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__88__a;
    __Vtask_add_fp16_tb_full__DOT__test_case__88__a = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__88__b;
    __Vtask_add_fp16_tb_full__DOT__test_case__88__b = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__88__is_sub;
    __Vtask_add_fp16_tb_full__DOT__test_case__88__is_sub = 0;
    std::string __Vtask_add_fp16_tb_full__DOT__check_case__89__casename;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__89__expected;
    __Vtask_add_fp16_tb_full__DOT__check_case__89__expected = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__89__match;
    __Vtask_add_fp16_tb_full__DOT__check_case__89__match = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__90__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__90__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__90__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__90__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__91__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__91__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__91__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__91__val = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__92__a;
    __Vtask_add_fp16_tb_full__DOT__test_case__92__a = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__92__b;
    __Vtask_add_fp16_tb_full__DOT__test_case__92__b = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__92__is_sub;
    __Vtask_add_fp16_tb_full__DOT__test_case__92__is_sub = 0;
    std::string __Vtask_add_fp16_tb_full__DOT__check_case__93__casename;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__93__expected;
    __Vtask_add_fp16_tb_full__DOT__check_case__93__expected = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__93__match;
    __Vtask_add_fp16_tb_full__DOT__check_case__93__match = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__94__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__94__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__94__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__94__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__95__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__95__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__95__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__95__val = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__96__a;
    __Vtask_add_fp16_tb_full__DOT__test_case__96__a = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__96__b;
    __Vtask_add_fp16_tb_full__DOT__test_case__96__b = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__96__is_sub;
    __Vtask_add_fp16_tb_full__DOT__test_case__96__is_sub = 0;
    std::string __Vtask_add_fp16_tb_full__DOT__check_case__97__casename;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__97__expected;
    __Vtask_add_fp16_tb_full__DOT__check_case__97__expected = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__97__match;
    __Vtask_add_fp16_tb_full__DOT__check_case__97__match = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__98__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__98__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__98__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__98__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__99__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__99__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__99__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__99__val = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__100__a;
    __Vtask_add_fp16_tb_full__DOT__test_case__100__a = 0;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__100__b;
    __Vtask_add_fp16_tb_full__DOT__test_case__100__b = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__test_case__100__is_sub;
    __Vtask_add_fp16_tb_full__DOT__test_case__100__is_sub = 0;
    std::string __Vtask_add_fp16_tb_full__DOT__check_case__101__casename;
    SData/*15:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__101__expected;
    __Vtask_add_fp16_tb_full__DOT__check_case__101__expected = 0;
    CData/*0:0*/ __Vtask_add_fp16_tb_full__DOT__check_case__101__match;
    __Vtask_add_fp16_tb_full__DOT__check_case__101__match = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__102__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__102__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__102__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__102__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__103__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__103__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__103__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__103__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__104__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__104__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__104__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__104__val = 0;
    CData/*0:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__105__Vfuncout;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__105__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_fp16_tb_full__DOT__is_nan__105__val;
    __Vfunc_add_fp16_tb_full__DOT__is_nan__105__val = 0;
    // Body
    vlSelfRef.add_fp16_tb_full__DOT__pass_count = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__fail_count = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_nrst = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         100);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_nrst = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         102);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("--- hardcoded addition cases ---\n",0);
    __Vtask_add_fp16_tb_full__DOT__test_case__0__is_sub = 0U;
    __Vtask_add_fp16_tb_full__DOT__test_case__0__b = 0x3c00U;
    __Vtask_add_fp16_tb_full__DOT__test_case__0__a = 0x3c00U;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = __Vtask_add_fp16_tb_full__DOT__test_case__0__a;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = __Vtask_add_fp16_tb_full__DOT__test_case__0__b;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = __Vtask_add_fp16_tb_full__DOT__test_case__0__is_sub;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__exp = 0x4000U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         109);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__check_case__1__expected 
        = vlSelfRef.add_fp16_tb_full__DOT__exp;
    __Vtask_add_fp16_tb_full__DOT__check_case__1__casename = 
        std::string{"1 + 1 = 2"};
    __Vtask_add_fp16_tb_full__DOT__check_case__1__match = 0;
    __Vtask_add_fp16_tb_full__DOT__check_case__1__match 
        = ((([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__2__val 
                        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__2__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__2__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__2__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__2__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__3__val 
                        = __Vtask_add_fp16_tb_full__DOT__check_case__1__expected;
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__3__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__3__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__3__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__3__Vfuncout))) 
           || (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add_fp16_tb_full__DOT__check_case__1__expected)));
    if (__Vtask_add_fp16_tb_full__DOT__check_case__1__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x SUB=%b -> %x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__1__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))));
        vlSelfRef.add_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x SUB=%b Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__1__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add_fp16_tb_full__DOT__check_case__1__expected));
        vlSelfRef.add_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         111);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__4__is_sub = 0U;
    __Vtask_add_fp16_tb_full__DOT__test_case__4__b = 0x4000U;
    __Vtask_add_fp16_tb_full__DOT__test_case__4__a = 0xc200U;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = __Vtask_add_fp16_tb_full__DOT__test_case__4__a;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = __Vtask_add_fp16_tb_full__DOT__test_case__4__b;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = __Vtask_add_fp16_tb_full__DOT__test_case__4__is_sub;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__exp = 0xbc00U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         115);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__check_case__5__expected 
        = vlSelfRef.add_fp16_tb_full__DOT__exp;
    __Vtask_add_fp16_tb_full__DOT__check_case__5__casename = 
        std::string{"(-3) + 2 = -1"};
    __Vtask_add_fp16_tb_full__DOT__check_case__5__match = 0;
    __Vtask_add_fp16_tb_full__DOT__check_case__5__match 
        = ((([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__6__val 
                        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__6__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__6__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__6__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__6__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__7__val 
                        = __Vtask_add_fp16_tb_full__DOT__check_case__5__expected;
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__7__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__7__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__7__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__7__Vfuncout))) 
           || (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add_fp16_tb_full__DOT__check_case__5__expected)));
    if (__Vtask_add_fp16_tb_full__DOT__check_case__5__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x SUB=%b -> %x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__5__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))));
        vlSelfRef.add_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x SUB=%b Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__5__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add_fp16_tb_full__DOT__check_case__5__expected));
        vlSelfRef.add_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         117);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__8__is_sub = 0U;
    __Vtask_add_fp16_tb_full__DOT__test_case__8__b = 0U;
    __Vtask_add_fp16_tb_full__DOT__test_case__8__a = 0U;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = __Vtask_add_fp16_tb_full__DOT__test_case__8__a;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = __Vtask_add_fp16_tb_full__DOT__test_case__8__b;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = __Vtask_add_fp16_tb_full__DOT__test_case__8__is_sub;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__exp = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         122);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__check_case__9__expected 
        = vlSelfRef.add_fp16_tb_full__DOT__exp;
    __Vtask_add_fp16_tb_full__DOT__check_case__9__casename = 
        std::string{"+0 + +0 = +0"};
    __Vtask_add_fp16_tb_full__DOT__check_case__9__match = 0;
    __Vtask_add_fp16_tb_full__DOT__check_case__9__match 
        = ((([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__10__val 
                        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__10__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__10__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__10__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__10__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__11__val 
                        = __Vtask_add_fp16_tb_full__DOT__check_case__9__expected;
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__11__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__11__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__11__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__11__Vfuncout))) 
           || (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add_fp16_tb_full__DOT__check_case__9__expected)));
    if (__Vtask_add_fp16_tb_full__DOT__check_case__9__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x SUB=%b -> %x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__9__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))));
        vlSelfRef.add_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x SUB=%b Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__9__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add_fp16_tb_full__DOT__check_case__9__expected));
        vlSelfRef.add_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         124);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__12__is_sub = 0U;
    __Vtask_add_fp16_tb_full__DOT__test_case__12__b = 0x8000U;
    __Vtask_add_fp16_tb_full__DOT__test_case__12__a = 0U;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = __Vtask_add_fp16_tb_full__DOT__test_case__12__a;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = __Vtask_add_fp16_tb_full__DOT__test_case__12__b;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = __Vtask_add_fp16_tb_full__DOT__test_case__12__is_sub;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__exp = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         128);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__check_case__13__expected 
        = vlSelfRef.add_fp16_tb_full__DOT__exp;
    __Vtask_add_fp16_tb_full__DOT__check_case__13__casename = 
        std::string{"+0 + -0 = +0"};
    __Vtask_add_fp16_tb_full__DOT__check_case__13__match = 0;
    __Vtask_add_fp16_tb_full__DOT__check_case__13__match 
        = ((([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__14__val 
                        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__14__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__14__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__14__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__14__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__15__val 
                        = __Vtask_add_fp16_tb_full__DOT__check_case__13__expected;
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__15__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__15__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__15__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__15__Vfuncout))) 
           || (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add_fp16_tb_full__DOT__check_case__13__expected)));
    if (__Vtask_add_fp16_tb_full__DOT__check_case__13__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x SUB=%b -> %x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__13__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))));
        vlSelfRef.add_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x SUB=%b Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__13__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add_fp16_tb_full__DOT__check_case__13__expected));
        vlSelfRef.add_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         130);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__16__is_sub = 0U;
    __Vtask_add_fp16_tb_full__DOT__test_case__16__b = 0U;
    __Vtask_add_fp16_tb_full__DOT__test_case__16__a = 0x3c00U;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = __Vtask_add_fp16_tb_full__DOT__test_case__16__a;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = __Vtask_add_fp16_tb_full__DOT__test_case__16__b;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = __Vtask_add_fp16_tb_full__DOT__test_case__16__is_sub;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__exp = 0x3c00U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         134);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__check_case__17__expected 
        = vlSelfRef.add_fp16_tb_full__DOT__exp;
    __Vtask_add_fp16_tb_full__DOT__check_case__17__casename = 
        std::string{"1 + 0 = 1"};
    __Vtask_add_fp16_tb_full__DOT__check_case__17__match = 0;
    __Vtask_add_fp16_tb_full__DOT__check_case__17__match 
        = ((([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__18__val 
                        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__18__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__18__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__18__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__18__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__19__val 
                        = __Vtask_add_fp16_tb_full__DOT__check_case__17__expected;
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__19__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__19__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__19__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__19__Vfuncout))) 
           || (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add_fp16_tb_full__DOT__check_case__17__expected)));
    if (__Vtask_add_fp16_tb_full__DOT__check_case__17__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x SUB=%b -> %x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__17__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))));
        vlSelfRef.add_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x SUB=%b Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__17__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add_fp16_tb_full__DOT__check_case__17__expected));
        vlSelfRef.add_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         136);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__20__is_sub = 0U;
    __Vtask_add_fp16_tb_full__DOT__test_case__20__b = 0x3c00U;
    __Vtask_add_fp16_tb_full__DOT__test_case__20__a = 0x7c00U;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = __Vtask_add_fp16_tb_full__DOT__test_case__20__a;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = __Vtask_add_fp16_tb_full__DOT__test_case__20__b;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = __Vtask_add_fp16_tb_full__DOT__test_case__20__is_sub;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__exp = 0x7c00U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         141);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__check_case__21__expected 
        = vlSelfRef.add_fp16_tb_full__DOT__exp;
    __Vtask_add_fp16_tb_full__DOT__check_case__21__casename = 
        std::string{"+Inf + 1 = +Inf"};
    __Vtask_add_fp16_tb_full__DOT__check_case__21__match = 0;
    __Vtask_add_fp16_tb_full__DOT__check_case__21__match 
        = ((([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__22__val 
                        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__22__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__22__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__22__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__22__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__23__val 
                        = __Vtask_add_fp16_tb_full__DOT__check_case__21__expected;
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__23__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__23__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__23__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__23__Vfuncout))) 
           || (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add_fp16_tb_full__DOT__check_case__21__expected)));
    if (__Vtask_add_fp16_tb_full__DOT__check_case__21__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x SUB=%b -> %x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__21__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))));
        vlSelfRef.add_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x SUB=%b Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__21__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add_fp16_tb_full__DOT__check_case__21__expected));
        vlSelfRef.add_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         143);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__24__is_sub = 0U;
    __Vtask_add_fp16_tb_full__DOT__test_case__24__b = 0x7c00U;
    __Vtask_add_fp16_tb_full__DOT__test_case__24__a = 0x7c00U;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = __Vtask_add_fp16_tb_full__DOT__test_case__24__a;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = __Vtask_add_fp16_tb_full__DOT__test_case__24__b;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = __Vtask_add_fp16_tb_full__DOT__test_case__24__is_sub;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__exp = 0x7c00U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         147);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__check_case__25__expected 
        = vlSelfRef.add_fp16_tb_full__DOT__exp;
    __Vtask_add_fp16_tb_full__DOT__check_case__25__casename = 
        std::string{"+Inf + +Inf = +Inf"};
    __Vtask_add_fp16_tb_full__DOT__check_case__25__match = 0;
    __Vtask_add_fp16_tb_full__DOT__check_case__25__match 
        = ((([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__26__val 
                        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__26__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__26__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__26__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__26__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__27__val 
                        = __Vtask_add_fp16_tb_full__DOT__check_case__25__expected;
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__27__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__27__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__27__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__27__Vfuncout))) 
           || (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add_fp16_tb_full__DOT__check_case__25__expected)));
    if (__Vtask_add_fp16_tb_full__DOT__check_case__25__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x SUB=%b -> %x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__25__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))));
        vlSelfRef.add_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x SUB=%b Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__25__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add_fp16_tb_full__DOT__check_case__25__expected));
        vlSelfRef.add_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         149);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__28__is_sub = 0U;
    __Vtask_add_fp16_tb_full__DOT__test_case__28__b = 0xfc00U;
    __Vtask_add_fp16_tb_full__DOT__test_case__28__a = 0xfc00U;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = __Vtask_add_fp16_tb_full__DOT__test_case__28__a;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = __Vtask_add_fp16_tb_full__DOT__test_case__28__b;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = __Vtask_add_fp16_tb_full__DOT__test_case__28__is_sub;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__exp = 0xfc00U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         153);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__check_case__29__expected 
        = vlSelfRef.add_fp16_tb_full__DOT__exp;
    __Vtask_add_fp16_tb_full__DOT__check_case__29__casename = 
        std::string{"-Inf + -Inf = -Inf"};
    __Vtask_add_fp16_tb_full__DOT__check_case__29__match = 0;
    __Vtask_add_fp16_tb_full__DOT__check_case__29__match 
        = ((([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__30__val 
                        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__30__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__30__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__30__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__30__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__31__val 
                        = __Vtask_add_fp16_tb_full__DOT__check_case__29__expected;
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__31__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__31__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__31__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__31__Vfuncout))) 
           || (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add_fp16_tb_full__DOT__check_case__29__expected)));
    if (__Vtask_add_fp16_tb_full__DOT__check_case__29__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x SUB=%b -> %x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__29__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))));
        vlSelfRef.add_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x SUB=%b Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__29__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add_fp16_tb_full__DOT__check_case__29__expected));
        vlSelfRef.add_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         155);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__32__is_sub = 0U;
    __Vtask_add_fp16_tb_full__DOT__test_case__32__b = 0xfc00U;
    __Vtask_add_fp16_tb_full__DOT__test_case__32__a = 0x7c00U;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = __Vtask_add_fp16_tb_full__DOT__test_case__32__a;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = __Vtask_add_fp16_tb_full__DOT__test_case__32__b;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = __Vtask_add_fp16_tb_full__DOT__test_case__32__is_sub;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__exp = 0x7d00U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         159);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__check_case__33__expected 
        = vlSelfRef.add_fp16_tb_full__DOT__exp;
    __Vtask_add_fp16_tb_full__DOT__check_case__33__casename = 
        std::string{"+Inf + -Inf = NaN"};
    __Vtask_add_fp16_tb_full__DOT__check_case__33__match = 0;
    __Vtask_add_fp16_tb_full__DOT__check_case__33__match 
        = ((([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__34__val 
                        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__34__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__34__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__34__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__34__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__35__val 
                        = __Vtask_add_fp16_tb_full__DOT__check_case__33__expected;
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__35__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__35__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__35__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__35__Vfuncout))) 
           || (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add_fp16_tb_full__DOT__check_case__33__expected)));
    if (__Vtask_add_fp16_tb_full__DOT__check_case__33__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x SUB=%b -> %x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__33__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))));
        vlSelfRef.add_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x SUB=%b Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__33__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add_fp16_tb_full__DOT__check_case__33__expected));
        vlSelfRef.add_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         161);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__36__is_sub = 0U;
    __Vtask_add_fp16_tb_full__DOT__test_case__36__b = 0x3c00U;
    __Vtask_add_fp16_tb_full__DOT__test_case__36__a = 0x7d00U;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = __Vtask_add_fp16_tb_full__DOT__test_case__36__a;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = __Vtask_add_fp16_tb_full__DOT__test_case__36__b;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = __Vtask_add_fp16_tb_full__DOT__test_case__36__is_sub;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__exp = 0x7d00U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         166);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__check_case__37__expected 
        = vlSelfRef.add_fp16_tb_full__DOT__exp;
    __Vtask_add_fp16_tb_full__DOT__check_case__37__casename = 
        std::string{"NaN + 1 = NaN"};
    __Vtask_add_fp16_tb_full__DOT__check_case__37__match = 0;
    __Vtask_add_fp16_tb_full__DOT__check_case__37__match 
        = ((([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__38__val 
                        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__38__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__38__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__38__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__38__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__39__val 
                        = __Vtask_add_fp16_tb_full__DOT__check_case__37__expected;
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__39__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__39__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__39__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__39__Vfuncout))) 
           || (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add_fp16_tb_full__DOT__check_case__37__expected)));
    if (__Vtask_add_fp16_tb_full__DOT__check_case__37__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x SUB=%b -> %x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__37__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))));
        vlSelfRef.add_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x SUB=%b Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__37__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add_fp16_tb_full__DOT__check_case__37__expected));
        vlSelfRef.add_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         168);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__40__is_sub = 0U;
    __Vtask_add_fp16_tb_full__DOT__test_case__40__b = 0x3c00U;
    __Vtask_add_fp16_tb_full__DOT__test_case__40__a = 1U;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = __Vtask_add_fp16_tb_full__DOT__test_case__40__a;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = __Vtask_add_fp16_tb_full__DOT__test_case__40__b;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = __Vtask_add_fp16_tb_full__DOT__test_case__40__is_sub;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__exp = 0x3c00U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         173);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__check_case__41__expected 
        = vlSelfRef.add_fp16_tb_full__DOT__exp;
    __Vtask_add_fp16_tb_full__DOT__check_case__41__casename = 
        std::string{"subnormal + 1 = 1 (DAZ)"};
    __Vtask_add_fp16_tb_full__DOT__check_case__41__match = 0;
    __Vtask_add_fp16_tb_full__DOT__check_case__41__match 
        = ((([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__42__val 
                        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__42__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__42__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__42__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__42__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__43__val 
                        = __Vtask_add_fp16_tb_full__DOT__check_case__41__expected;
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__43__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__43__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__43__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__43__Vfuncout))) 
           || (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add_fp16_tb_full__DOT__check_case__41__expected)));
    if (__Vtask_add_fp16_tb_full__DOT__check_case__41__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x SUB=%b -> %x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__41__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))));
        vlSelfRef.add_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x SUB=%b Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__41__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add_fp16_tb_full__DOT__check_case__41__expected));
        vlSelfRef.add_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         175);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__44__is_sub = 0U;
    __Vtask_add_fp16_tb_full__DOT__test_case__44__b = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__44__a = 1U;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = __Vtask_add_fp16_tb_full__DOT__test_case__44__a;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = __Vtask_add_fp16_tb_full__DOT__test_case__44__b;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = __Vtask_add_fp16_tb_full__DOT__test_case__44__is_sub;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__exp = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         179);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__check_case__45__expected 
        = vlSelfRef.add_fp16_tb_full__DOT__exp;
    __Vtask_add_fp16_tb_full__DOT__check_case__45__casename = 
        std::string{"subnormal + subnormal = 0 (DAZ)"};
    __Vtask_add_fp16_tb_full__DOT__check_case__45__match = 0;
    __Vtask_add_fp16_tb_full__DOT__check_case__45__match 
        = ((([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__46__val 
                        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__46__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__46__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__46__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__46__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__47__val 
                        = __Vtask_add_fp16_tb_full__DOT__check_case__45__expected;
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__47__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__47__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__47__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__47__Vfuncout))) 
           || (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add_fp16_tb_full__DOT__check_case__45__expected)));
    if (__Vtask_add_fp16_tb_full__DOT__check_case__45__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x SUB=%b -> %x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__45__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))));
        vlSelfRef.add_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x SUB=%b Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__45__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add_fp16_tb_full__DOT__check_case__45__expected));
        vlSelfRef.add_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         181);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__48__is_sub = 0U;
    __Vtask_add_fp16_tb_full__DOT__test_case__48__b = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__48__a = 0x4000U;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = __Vtask_add_fp16_tb_full__DOT__test_case__48__a;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = __Vtask_add_fp16_tb_full__DOT__test_case__48__b;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = __Vtask_add_fp16_tb_full__DOT__test_case__48__is_sub;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__exp = 0x4000U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         185);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__check_case__49__expected 
        = vlSelfRef.add_fp16_tb_full__DOT__exp;
    __Vtask_add_fp16_tb_full__DOT__check_case__49__casename = 
        std::string{"2 + subnormal = 2 (DAZ)"};
    __Vtask_add_fp16_tb_full__DOT__check_case__49__match = 0;
    __Vtask_add_fp16_tb_full__DOT__check_case__49__match 
        = ((([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__50__val 
                        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__50__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__50__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__50__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__50__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__51__val 
                        = __Vtask_add_fp16_tb_full__DOT__check_case__49__expected;
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__51__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__51__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__51__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__51__Vfuncout))) 
           || (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add_fp16_tb_full__DOT__check_case__49__expected)));
    if (__Vtask_add_fp16_tb_full__DOT__check_case__49__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x SUB=%b -> %x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__49__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))));
        vlSelfRef.add_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x SUB=%b Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__49__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add_fp16_tb_full__DOT__check_case__49__expected));
        vlSelfRef.add_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         187);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__52__is_sub = 0U;
    __Vtask_add_fp16_tb_full__DOT__test_case__52__b = 0x7bffU;
    __Vtask_add_fp16_tb_full__DOT__test_case__52__a = 0x7bffU;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = __Vtask_add_fp16_tb_full__DOT__test_case__52__a;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = __Vtask_add_fp16_tb_full__DOT__test_case__52__b;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = __Vtask_add_fp16_tb_full__DOT__test_case__52__is_sub;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__exp = 0x7c00U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         192);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__check_case__53__expected 
        = vlSelfRef.add_fp16_tb_full__DOT__exp;
    __Vtask_add_fp16_tb_full__DOT__check_case__53__casename = 
        std::string{"max + max = +Inf (overflow)"};
    __Vtask_add_fp16_tb_full__DOT__check_case__53__match = 0;
    __Vtask_add_fp16_tb_full__DOT__check_case__53__match 
        = ((([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__54__val 
                        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__54__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__54__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__54__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__54__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__55__val 
                        = __Vtask_add_fp16_tb_full__DOT__check_case__53__expected;
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__55__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__55__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__55__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__55__Vfuncout))) 
           || (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add_fp16_tb_full__DOT__check_case__53__expected)));
    if (__Vtask_add_fp16_tb_full__DOT__check_case__53__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x SUB=%b -> %x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__53__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))));
        vlSelfRef.add_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x SUB=%b Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__53__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add_fp16_tb_full__DOT__check_case__53__expected));
        vlSelfRef.add_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         194);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__56__is_sub = 0U;
    __Vtask_add_fp16_tb_full__DOT__test_case__56__b = 0xfbffU;
    __Vtask_add_fp16_tb_full__DOT__test_case__56__a = 0xfbffU;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = __Vtask_add_fp16_tb_full__DOT__test_case__56__a;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = __Vtask_add_fp16_tb_full__DOT__test_case__56__b;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = __Vtask_add_fp16_tb_full__DOT__test_case__56__is_sub;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__exp = 0xfc00U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         198);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__check_case__57__expected 
        = vlSelfRef.add_fp16_tb_full__DOT__exp;
    __Vtask_add_fp16_tb_full__DOT__check_case__57__casename = 
        std::string{"-max + -max = -Inf (overflow)"};
    __Vtask_add_fp16_tb_full__DOT__check_case__57__match = 0;
    __Vtask_add_fp16_tb_full__DOT__check_case__57__match 
        = ((([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__58__val 
                        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__58__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__58__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__58__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__58__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__59__val 
                        = __Vtask_add_fp16_tb_full__DOT__check_case__57__expected;
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__59__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__59__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__59__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__59__Vfuncout))) 
           || (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add_fp16_tb_full__DOT__check_case__57__expected)));
    if (__Vtask_add_fp16_tb_full__DOT__check_case__57__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x SUB=%b -> %x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__57__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))));
        vlSelfRef.add_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x SUB=%b Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__57__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add_fp16_tb_full__DOT__check_case__57__expected));
        vlSelfRef.add_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         200);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__60__is_sub = 0U;
    __Vtask_add_fp16_tb_full__DOT__test_case__60__b = 0xc200U;
    __Vtask_add_fp16_tb_full__DOT__test_case__60__a = 0x4200U;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = __Vtask_add_fp16_tb_full__DOT__test_case__60__a;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = __Vtask_add_fp16_tb_full__DOT__test_case__60__b;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = __Vtask_add_fp16_tb_full__DOT__test_case__60__is_sub;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__exp = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         205);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__check_case__61__expected 
        = vlSelfRef.add_fp16_tb_full__DOT__exp;
    __Vtask_add_fp16_tb_full__DOT__check_case__61__casename = 
        std::string{"x + (-x) = +0 (cancellation)"};
    __Vtask_add_fp16_tb_full__DOT__check_case__61__match = 0;
    __Vtask_add_fp16_tb_full__DOT__check_case__61__match 
        = ((([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__62__val 
                        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__62__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__62__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__62__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__62__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__63__val 
                        = __Vtask_add_fp16_tb_full__DOT__check_case__61__expected;
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__63__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__63__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__63__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__63__Vfuncout))) 
           || (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add_fp16_tb_full__DOT__check_case__61__expected)));
    if (__Vtask_add_fp16_tb_full__DOT__check_case__61__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x SUB=%b -> %x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__61__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))));
        vlSelfRef.add_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x SUB=%b Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__61__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add_fp16_tb_full__DOT__check_case__61__expected));
        vlSelfRef.add_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         207);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__64__is_sub = 0U;
    __Vtask_add_fp16_tb_full__DOT__test_case__64__b = 0x4000U;
    __Vtask_add_fp16_tb_full__DOT__test_case__64__a = 0x4000U;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = __Vtask_add_fp16_tb_full__DOT__test_case__64__a;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = __Vtask_add_fp16_tb_full__DOT__test_case__64__b;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = __Vtask_add_fp16_tb_full__DOT__test_case__64__is_sub;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__exp = 0x4400U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         212);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__check_case__65__expected 
        = vlSelfRef.add_fp16_tb_full__DOT__exp;
    __Vtask_add_fp16_tb_full__DOT__check_case__65__casename = 
        std::string{"+2 + +2 = +4"};
    __Vtask_add_fp16_tb_full__DOT__check_case__65__match = 0;
    __Vtask_add_fp16_tb_full__DOT__check_case__65__match 
        = ((([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__66__val 
                        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__66__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__66__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__66__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__66__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__67__val 
                        = __Vtask_add_fp16_tb_full__DOT__check_case__65__expected;
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__67__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__67__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__67__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__67__Vfuncout))) 
           || (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add_fp16_tb_full__DOT__check_case__65__expected)));
    if (__Vtask_add_fp16_tb_full__DOT__check_case__65__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x SUB=%b -> %x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__65__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))));
        vlSelfRef.add_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x SUB=%b Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__65__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add_fp16_tb_full__DOT__check_case__65__expected));
        vlSelfRef.add_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         214);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__68__is_sub = 0U;
    __Vtask_add_fp16_tb_full__DOT__test_case__68__b = 0xc000U;
    __Vtask_add_fp16_tb_full__DOT__test_case__68__a = 0xc000U;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = __Vtask_add_fp16_tb_full__DOT__test_case__68__a;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = __Vtask_add_fp16_tb_full__DOT__test_case__68__b;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = __Vtask_add_fp16_tb_full__DOT__test_case__68__is_sub;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__exp = 0xc400U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         218);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__check_case__69__expected 
        = vlSelfRef.add_fp16_tb_full__DOT__exp;
    __Vtask_add_fp16_tb_full__DOT__check_case__69__casename = 
        std::string{"-2 + -2 = -4"};
    __Vtask_add_fp16_tb_full__DOT__check_case__69__match = 0;
    __Vtask_add_fp16_tb_full__DOT__check_case__69__match 
        = ((([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__70__val 
                        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__70__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__70__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__70__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__70__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__71__val 
                        = __Vtask_add_fp16_tb_full__DOT__check_case__69__expected;
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__71__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__71__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__71__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__71__Vfuncout))) 
           || (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add_fp16_tb_full__DOT__check_case__69__expected)));
    if (__Vtask_add_fp16_tb_full__DOT__check_case__69__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x SUB=%b -> %x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__69__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))));
        vlSelfRef.add_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x SUB=%b Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__69__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add_fp16_tb_full__DOT__check_case__69__expected));
        vlSelfRef.add_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         220);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("\n=== Manual Subtraction Test Cases ===\n",0);
    __Vtask_add_fp16_tb_full__DOT__test_case__72__is_sub = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__72__b = 0x3c00U;
    __Vtask_add_fp16_tb_full__DOT__test_case__72__a = 0x4000U;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = __Vtask_add_fp16_tb_full__DOT__test_case__72__a;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = __Vtask_add_fp16_tb_full__DOT__test_case__72__b;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = __Vtask_add_fp16_tb_full__DOT__test_case__72__is_sub;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__exp = 0x3c00U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         228);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__check_case__73__expected 
        = vlSelfRef.add_fp16_tb_full__DOT__exp;
    __Vtask_add_fp16_tb_full__DOT__check_case__73__casename = 
        std::string{"2 - 1 = 1"};
    __Vtask_add_fp16_tb_full__DOT__check_case__73__match = 0;
    __Vtask_add_fp16_tb_full__DOT__check_case__73__match 
        = ((([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__74__val 
                        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__74__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__74__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__74__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__74__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__75__val 
                        = __Vtask_add_fp16_tb_full__DOT__check_case__73__expected;
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__75__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__75__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__75__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__75__Vfuncout))) 
           || (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add_fp16_tb_full__DOT__check_case__73__expected)));
    if (__Vtask_add_fp16_tb_full__DOT__check_case__73__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x SUB=%b -> %x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__73__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))));
        vlSelfRef.add_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x SUB=%b Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__73__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add_fp16_tb_full__DOT__check_case__73__expected));
        vlSelfRef.add_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         230);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__76__is_sub = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__76__b = 0x4000U;
    __Vtask_add_fp16_tb_full__DOT__test_case__76__a = 0x3c00U;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = __Vtask_add_fp16_tb_full__DOT__test_case__76__a;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = __Vtask_add_fp16_tb_full__DOT__test_case__76__b;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = __Vtask_add_fp16_tb_full__DOT__test_case__76__is_sub;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__exp = 0xbc00U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         234);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__check_case__77__expected 
        = vlSelfRef.add_fp16_tb_full__DOT__exp;
    __Vtask_add_fp16_tb_full__DOT__check_case__77__casename = 
        std::string{"1 - 2 = -1"};
    __Vtask_add_fp16_tb_full__DOT__check_case__77__match = 0;
    __Vtask_add_fp16_tb_full__DOT__check_case__77__match 
        = ((([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__78__val 
                        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__78__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__78__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__78__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__78__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__79__val 
                        = __Vtask_add_fp16_tb_full__DOT__check_case__77__expected;
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__79__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__79__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__79__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__79__Vfuncout))) 
           || (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add_fp16_tb_full__DOT__check_case__77__expected)));
    if (__Vtask_add_fp16_tb_full__DOT__check_case__77__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x SUB=%b -> %x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__77__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))));
        vlSelfRef.add_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x SUB=%b Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__77__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add_fp16_tb_full__DOT__check_case__77__expected));
        vlSelfRef.add_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         236);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__80__is_sub = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__80__b = 0x4000U;
    __Vtask_add_fp16_tb_full__DOT__test_case__80__a = 0x4200U;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = __Vtask_add_fp16_tb_full__DOT__test_case__80__a;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = __Vtask_add_fp16_tb_full__DOT__test_case__80__b;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = __Vtask_add_fp16_tb_full__DOT__test_case__80__is_sub;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__exp = 0x3c00U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         240);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__check_case__81__expected 
        = vlSelfRef.add_fp16_tb_full__DOT__exp;
    __Vtask_add_fp16_tb_full__DOT__check_case__81__casename = 
        std::string{"3 - 2 = 1"};
    __Vtask_add_fp16_tb_full__DOT__check_case__81__match = 0;
    __Vtask_add_fp16_tb_full__DOT__check_case__81__match 
        = ((([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__82__val 
                        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__82__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__82__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__82__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__82__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__83__val 
                        = __Vtask_add_fp16_tb_full__DOT__check_case__81__expected;
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__83__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__83__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__83__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__83__Vfuncout))) 
           || (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add_fp16_tb_full__DOT__check_case__81__expected)));
    if (__Vtask_add_fp16_tb_full__DOT__check_case__81__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x SUB=%b -> %x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__81__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))));
        vlSelfRef.add_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x SUB=%b Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__81__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add_fp16_tb_full__DOT__check_case__81__expected));
        vlSelfRef.add_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         242);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__84__is_sub = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__84__b = 0x4000U;
    __Vtask_add_fp16_tb_full__DOT__test_case__84__a = 0x4000U;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = __Vtask_add_fp16_tb_full__DOT__test_case__84__a;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = __Vtask_add_fp16_tb_full__DOT__test_case__84__b;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = __Vtask_add_fp16_tb_full__DOT__test_case__84__is_sub;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__exp = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         247);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__check_case__85__expected 
        = vlSelfRef.add_fp16_tb_full__DOT__exp;
    __Vtask_add_fp16_tb_full__DOT__check_case__85__casename = 
        std::string{"2 - 2 = 0"};
    __Vtask_add_fp16_tb_full__DOT__check_case__85__match = 0;
    __Vtask_add_fp16_tb_full__DOT__check_case__85__match 
        = ((([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__86__val 
                        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__86__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__86__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__86__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__86__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__87__val 
                        = __Vtask_add_fp16_tb_full__DOT__check_case__85__expected;
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__87__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__87__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__87__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__87__Vfuncout))) 
           || (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add_fp16_tb_full__DOT__check_case__85__expected)));
    if (__Vtask_add_fp16_tb_full__DOT__check_case__85__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x SUB=%b -> %x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__85__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))));
        vlSelfRef.add_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x SUB=%b Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__85__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add_fp16_tb_full__DOT__check_case__85__expected));
        vlSelfRef.add_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         249);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__88__is_sub = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__88__b = 0x3c00U;
    __Vtask_add_fp16_tb_full__DOT__test_case__88__a = 0x7c00U;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = __Vtask_add_fp16_tb_full__DOT__test_case__88__a;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = __Vtask_add_fp16_tb_full__DOT__test_case__88__b;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = __Vtask_add_fp16_tb_full__DOT__test_case__88__is_sub;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__exp = 0x7c00U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         254);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__check_case__89__expected 
        = vlSelfRef.add_fp16_tb_full__DOT__exp;
    __Vtask_add_fp16_tb_full__DOT__check_case__89__casename = 
        std::string{"+Inf - 1 = +Inf"};
    __Vtask_add_fp16_tb_full__DOT__check_case__89__match = 0;
    __Vtask_add_fp16_tb_full__DOT__check_case__89__match 
        = ((([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__90__val 
                        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__90__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__90__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__90__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__90__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__91__val 
                        = __Vtask_add_fp16_tb_full__DOT__check_case__89__expected;
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__91__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__91__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__91__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__91__Vfuncout))) 
           || (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add_fp16_tb_full__DOT__check_case__89__expected)));
    if (__Vtask_add_fp16_tb_full__DOT__check_case__89__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x SUB=%b -> %x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__89__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))));
        vlSelfRef.add_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x SUB=%b Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__89__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add_fp16_tb_full__DOT__check_case__89__expected));
        vlSelfRef.add_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         256);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__92__is_sub = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__92__b = 0x7c00U;
    __Vtask_add_fp16_tb_full__DOT__test_case__92__a = 0x7c00U;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = __Vtask_add_fp16_tb_full__DOT__test_case__92__a;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = __Vtask_add_fp16_tb_full__DOT__test_case__92__b;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = __Vtask_add_fp16_tb_full__DOT__test_case__92__is_sub;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__exp = 0x7d00U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         260);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__check_case__93__expected 
        = vlSelfRef.add_fp16_tb_full__DOT__exp;
    __Vtask_add_fp16_tb_full__DOT__check_case__93__casename = 
        std::string{"+Inf - +Inf = NaN"};
    __Vtask_add_fp16_tb_full__DOT__check_case__93__match = 0;
    __Vtask_add_fp16_tb_full__DOT__check_case__93__match 
        = ((([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__94__val 
                        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__94__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__94__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__94__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__94__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__95__val 
                        = __Vtask_add_fp16_tb_full__DOT__check_case__93__expected;
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__95__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__95__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__95__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__95__Vfuncout))) 
           || (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add_fp16_tb_full__DOT__check_case__93__expected)));
    if (__Vtask_add_fp16_tb_full__DOT__check_case__93__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x SUB=%b -> %x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__93__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))));
        vlSelfRef.add_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x SUB=%b Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__93__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add_fp16_tb_full__DOT__check_case__93__expected));
        vlSelfRef.add_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         262);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__96__is_sub = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__96__b = 0xfc00U;
    __Vtask_add_fp16_tb_full__DOT__test_case__96__a = 0x7c00U;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = __Vtask_add_fp16_tb_full__DOT__test_case__96__a;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = __Vtask_add_fp16_tb_full__DOT__test_case__96__b;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = __Vtask_add_fp16_tb_full__DOT__test_case__96__is_sub;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__exp = 0x7c00U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         266);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__check_case__97__expected 
        = vlSelfRef.add_fp16_tb_full__DOT__exp;
    __Vtask_add_fp16_tb_full__DOT__check_case__97__casename = 
        std::string{"+Inf - -Inf = +Inf"};
    __Vtask_add_fp16_tb_full__DOT__check_case__97__match = 0;
    __Vtask_add_fp16_tb_full__DOT__check_case__97__match 
        = ((([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__98__val 
                        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__98__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__98__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__98__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__98__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__99__val 
                        = __Vtask_add_fp16_tb_full__DOT__check_case__97__expected;
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__99__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__99__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__99__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__99__Vfuncout))) 
           || (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add_fp16_tb_full__DOT__check_case__97__expected)));
    if (__Vtask_add_fp16_tb_full__DOT__check_case__97__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x SUB=%b -> %x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__97__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))));
        vlSelfRef.add_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x SUB=%b Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__97__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add_fp16_tb_full__DOT__check_case__97__expected));
        vlSelfRef.add_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         268);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__100__is_sub = 1U;
    __Vtask_add_fp16_tb_full__DOT__test_case__100__b = 0x3c00U;
    __Vtask_add_fp16_tb_full__DOT__test_case__100__a = 0x7d00U;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_a = __Vtask_add_fp16_tb_full__DOT__test_case__100__a;
    vlSelfRef.add_fp16_tb_full__DOT__tb_b = __Vtask_add_fp16_tb_full__DOT__test_case__100__b;
    vlSelfRef.add_fp16_tb_full__DOT__tb_sub = __Vtask_add_fp16_tb_full__DOT__test_case__100__is_sub;
    co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_fp16_tb_full.tb_clk)", 
                                                         "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
    vlSelfRef.add_fp16_tb_full__DOT__exp = 0x7d00U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         273);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_add_fp16_tb_full__DOT__check_case__101__expected 
        = vlSelfRef.add_fp16_tb_full__DOT__exp;
    __Vtask_add_fp16_tb_full__DOT__check_case__101__casename = 
        std::string{"NaN - 1 = NaN"};
    __Vtask_add_fp16_tb_full__DOT__check_case__101__match = 0;
    __Vtask_add_fp16_tb_full__DOT__check_case__101__match 
        = ((([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__102__val 
                        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                            ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                            : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                   << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU)
                                                : (
                                                   ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                       << 0xaU) 
                                                      | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__102__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__102__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__102__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__102__Vfuncout)) 
            & ([&]() {
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__103__val 
                        = __Vtask_add_fp16_tb_full__DOT__check_case__101__expected;
                    __Vfunc_add_fp16_tb_full__DOT__is_nan__103__Vfuncout 
                        = (IData)(((0x7c00U == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__103__val))) 
                                   & (0U != (0x3ffU 
                                             & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__103__val)))));
                }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__103__Vfuncout))) 
           || (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                 ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                 : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                        << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                     ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) : 
                                    (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                      << 0xfU) | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
               == (IData)(__Vtask_add_fp16_tb_full__DOT__check_case__101__expected)));
    if (__Vtask_add_fp16_tb_full__DOT__check_case__101__match) {
        VL_WRITEF_NX("Passed %@ | A=%x B=%x SUB=%b -> %x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__101__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))));
        vlSelfRef.add_fp16_tb_full__DOT__pass_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
    } else {
        VL_WRITEF_NX("Failed Test for %@: A=%x B=%x SUB=%b Got=%x Exp=%x\n",0,
                     -1,&(__Vtask_add_fp16_tb_full__DOT__check_case__101__casename),
                     16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_a),
                     16,vlSelfRef.add_fp16_tb_full__DOT__tb_b,
                     1,(IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub),
                     16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                          ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                          : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                 << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                              ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                              : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                     16,(IData)(__Vtask_add_fp16_tb_full__DOT__check_case__101__expected));
        vlSelfRef.add_fp16_tb_full__DOT__fail_count 
            = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    }
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                         275);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("\n--- Random Test Cases from CSV ---\n",0);
    vlSelfRef.add_fp16_tb_full__DOT__fd = VL_FOPEN_NN(
                                                      VL_CVT_PACK_STR_NW(10, Vadd_fp16_tb_full__ConstPool__CONST_h94864378_0)
                                                      , 
                                                      std::string{"r"});
    ;
    if (VL_UNLIKELY(((0U == vlSelfRef.add_fp16_tb_full__DOT__fd)))) {
        VL_WRITEF_NX("ERROR: Could not open scripts/systolic_array/random_cases.csv - run: python3 scripts/systolic_array/random_fpgen.py\n",0);
        VL_FINISH_MT("tb/unit/systolic_array/add_fp16_tb_full.sv", 283, "");
    }
    (void)VL_FGETS_NI(add_fp16_tb_full__DOT__header, vlSelfRef.add_fp16_tb_full__DOT__fd);
    while ((! (vlSelfRef.add_fp16_tb_full__DOT__fd ? feof(VL_CVT_I_FP(vlSelfRef.add_fp16_tb_full__DOT__fd)) : true))) {
        {
            vlSelfRef.add_fp16_tb_full__DOT__unnamedblk1__DOT__ret 
                = VL_FSCANF_INX(vlSelfRef.add_fp16_tb_full__DOT__fd,"%x,%x,%#,%x\n",0,
                                16,&(vlSelfRef.add_fp16_tb_full__DOT__a),
                                16,&(vlSelfRef.add_fp16_tb_full__DOT__b),
                                32,&(vlSelfRef.add_fp16_tb_full__DOT__unnamedblk1__DOT__sub_flag),
                                16,&(vlSelfRef.add_fp16_tb_full__DOT__expected)) ;
            if ((4U != vlSelfRef.add_fp16_tb_full__DOT__unnamedblk1__DOT__ret)) {
                goto __Vlabel1;
            }
            co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge add_fp16_tb_full.tb_clk)", 
                                                                 "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                                 295);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSelfRef.add_fp16_tb_full__DOT__tb_start = 1U;
            vlSelfRef.add_fp16_tb_full__DOT__tb_a = vlSelfRef.add_fp16_tb_full__DOT__a;
            vlSelfRef.add_fp16_tb_full__DOT__tb_b = vlSelfRef.add_fp16_tb_full__DOT__b;
            vlSelfRef.add_fp16_tb_full__DOT__tb_sub 
                = (1U & vlSelfRef.add_fp16_tb_full__DOT__unnamedblk1__DOT__sub_flag);
            co_await vlSelfRef.__VtrigSched_h9c6897a4__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge add_fp16_tb_full.tb_clk)", 
                                                                 "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                                 301);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSelfRef.add_fp16_tb_full__DOT__tb_start = 0U;
            co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                                 nullptr, 
                                                 "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                                 303);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSelfRef.add_fp16_tb_full__DOT__unnamedblk1__DOT__is_zero_result 
                = (((0U == ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                             ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                             : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                 ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                    << 0xfU) : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                                 ? 
                                                ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                 << 0xfU)
                                                 : 
                                                (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU) 
                                                 | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                     << 0xaU) 
                                                    | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))))) 
                    | (0x8000U == ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                                    ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                                    : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                        ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                           << 0xfU)
                                        : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                            ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                               << 0xfU)
                                            : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                << 0xfU) 
                                               | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))))) 
                   & ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__expected)) 
                      | (0x8000U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__expected))));
            if ((([&]() {
                            __Vfunc_add_fp16_tb_full__DOT__is_nan__104__val 
                                = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                                    ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                                    : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                        ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                           << 0xfU)
                                        : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                            ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                               << 0xfU)
                                            : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                << 0xfU) 
                                               | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                   << 0xaU) 
                                                  | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final))))));
                            __Vfunc_add_fp16_tb_full__DOT__is_nan__104__Vfuncout 
                                = (IData)(((0x7c00U 
                                            == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__104__val))) 
                                           & (0U != 
                                              (0x3ffU 
                                               & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__104__val)))));
                        }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__104__Vfuncout)) 
                 & ([&]() {
                            __Vfunc_add_fp16_tb_full__DOT__is_nan__105__val 
                                = vlSelfRef.add_fp16_tb_full__DOT__expected;
                            __Vfunc_add_fp16_tb_full__DOT__is_nan__105__Vfuncout 
                                = (IData)(((0x7c00U 
                                            == (0x7c00U 
                                                & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__105__val))) 
                                           & (0U != 
                                              (0x3ffU 
                                               & (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__105__val)))));
                        }(), (IData)(__Vfunc_add_fp16_tb_full__DOT__is_nan__105__Vfuncout)))) {
                vlSelfRef.add_fp16_tb_full__DOT__pass_count 
                    = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
            } else if (vlSelfRef.add_fp16_tb_full__DOT__unnamedblk1__DOT__is_zero_result) {
                vlSelfRef.add_fp16_tb_full__DOT__pass_count 
                    = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
            } else if (VL_UNLIKELY(((((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                                       ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                                       : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                           ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                              << 0xfU)
                                           : ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                               ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                  << 0xfU)
                                               : (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                                   << 0xfU) 
                                                  | (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                                      << 0xaU) 
                                                     | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))) 
                                     != (IData)(vlSelfRef.add_fp16_tb_full__DOT__expected))))) {
                VL_WRITEF_NX("FAIL: A=%x B=%x SUB=%11d Got=%x Exp=%x\n",0,
                             16,vlSelfRef.add_fp16_tb_full__DOT__a,
                             16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__b),
                             32,vlSelfRef.add_fp16_tb_full__DOT__unnamedblk1__DOT__sub_flag,
                             16,((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l)
                                  ? (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l)
                                  : ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))
                                      ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                         << 0xfU) : 
                                     ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under)
                                       ? ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                          << 0xfU) : 
                                      (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign) 
                                        << 0xfU) | 
                                       (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final) 
                                         << 0xaU) | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final)))))),
                             16,(IData)(vlSelfRef.add_fp16_tb_full__DOT__expected));
                vlSelfRef.add_fp16_tb_full__DOT__fail_count 
                    = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__fail_count);
            } else {
                vlSelfRef.add_fp16_tb_full__DOT__pass_count 
                    = ((IData)(1U) + vlSelfRef.add_fp16_tb_full__DOT__pass_count);
            }
            __Vlabel1: ;
        }
    }
    VL_FCLOSE_I(vlSelfRef.add_fp16_tb_full__DOT__fd); VL_WRITEF_NX("\n=== Test Summary ===\nPASSED: %0d\nFAILED: %0d\n",0,
                                                                   32,
                                                                   vlSelfRef.add_fp16_tb_full__DOT__pass_count,
                                                                   32,
                                                                   vlSelfRef.add_fp16_tb_full__DOT__fail_count);
    if ((0U == vlSelfRef.add_fp16_tb_full__DOT__fail_count)) {
        VL_WRITEF_NX("ALL TESTS PASSED!\n",0);
    } else {
        VL_WRITEF_NX("SOME TESTS FAILED!\n",0);
    }
    VL_FINISH_MT("tb/unit/systolic_array/add_fp16_tb_full.sv", 334, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

VL_INLINE_OPT VlCoroutine Vadd_fp16_tb_full___024root___eval_initial__TOP__Vtiming__1(Vadd_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        vlSelfRef.add_fp16_tb_full__DOT__tb_clk = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                             nullptr, 
                                             "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                             18);
        vlSelfRef.add_fp16_tb_full__DOT__tb_clk = 1U;
        co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                             nullptr, 
                                             "tb/unit/systolic_array/add_fp16_tb_full.sv", 
                                             20);
    }
}

void Vadd_fp16_tb_full___024root___act_comb__TOP__0(Vadd_fp16_tb_full___024root* vlSelf);

void Vadd_fp16_tb_full___024root___eval_act(Vadd_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root___eval_act\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0xcULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vadd_fp16_tb_full___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void Vadd_fp16_tb_full___024root___act_comb__TOP__0(Vadd_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root___act_comb__TOP__0\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a = vlSelfRef.add_fp16_tb_full__DOT__tb_a;
    if ((IData)(((0U == (0x7c00U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a))) 
                 & (0U != (0x3ffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a)))))) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a 
            = (0x8000U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a));
    }
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b = 
        ((IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_sub)
          ? ((0x8000U & ((~ ((IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_b) 
                             >> 0xfU)) << 0xfU)) | 
             (0x7fffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_b)))
          : (IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_b));
    if ((IData)(((0U == (0x7c00U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b))) 
                 & (0U != (0x3ffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b)))))) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b 
            = (0x8000U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b));
    }
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_nan_a 
        = (IData)(((0x7c00U == (0x7c00U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a))) 
                   & (0U != (0x3ffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a)))));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_nan_b 
        = (IData)(((0x7c00U == (0x7c00U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b))) 
                   & (0U != (0x3ffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b)))));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_inf_a 
        = (IData)((0x7c00U == (0x7fffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a))));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_inf_b 
        = (IData)((0x7c00U == (0x7fffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b))));
    if (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_nan_a) 
         | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_nan_b))) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case = 1U;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result 
            = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_nan_a)
                ? (0x200U | (0xfdffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a)))
                : (0x200U | (0xfdffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b))));
    } else if (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_inf_a) 
                & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_inf_b))) {
        if (((1U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a) 
                    >> 0xfU)) == (1U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b) 
                                        >> 0xfU)))) {
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case = 1U;
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result 
                = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a;
        } else {
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case = 1U;
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result = 0x7e00U;
        }
    } else if (vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_inf_a) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case = 1U;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a;
    } else if (vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__is_inf_b) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case = 1U;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b;
    }
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__op_swap 
        = ((0x1fU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a) 
                     >> 0xaU)) < (0x1fU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b) 
                                           >> 0xaU)));
    if (vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__op_swap) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__high_op 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__low_op 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a;
    } else {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__high_op 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__a;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__low_op 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__b;
    }
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__high_exp 
        = (0x1fU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__high_op) 
                    >> 0xaU));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__low_exp 
        = (0x1fU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__low_op) 
                    >> 0xaU));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_diff 
        = (0x1fU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__high_exp) 
                    - (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__low_exp)));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_max 
        = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__high_exp;
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_hi 
        = (((IData)((0U != (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__high_exp))) 
            << 0xcU) | (0xffcU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__high_op) 
                                  << 2U)));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo 
        = (((IData)((0U != (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__low_exp))) 
            << 0xcU) | (0xffcU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__low_op) 
                                  << 2U)));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo_aligned = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sticky_align_local = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sticky_lost = 0U;
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mask_align = 0U;
    if ((0xdU <= (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_diff))) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo_aligned = 0U;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sticky_lost = 0U;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo_aligned 
            = ((0x1ffeU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo_aligned)) 
               | (0U != (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo)));
    } else if ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_diff))) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo_aligned 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sticky_lost = 0U;
    } else {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo_aligned 
            = (0x1fffU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo) 
                          >> (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_diff)));
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mask_align 
            = (0x1fffU & (((IData)(1U) << (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_diff)) 
                          - (IData)(1U)));
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sticky_align_local 
            = (0U != ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo) 
                      & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mask_align)));
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sticky_lost 
            = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sticky_align_local) 
               & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo_aligned));
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo_aligned 
            = ((0x1ffeU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo_aligned)) 
               | (1U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo_aligned) 
                        | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sticky_align_local))));
    }
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_not_shifted 
        = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_hi;
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_shifted 
        = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mant_lo_aligned;
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_not_shifted 
        = (1U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__high_op) 
                 >> 0xfU));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_shifted 
        = (1U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__low_op) 
                 >> 0xfU));
    if (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_shifted) 
         > (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_not_shifted))) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__smaller_mantissa 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_not_shifted;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_shifted;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa_sign 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_shifted;
    } else {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__smaller_mantissa 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_shifted;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_not_shifted;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa_sign 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_not_shifted;
    }
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sub_has_lost_sticky 
        = (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_shifted) 
            <= (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_not_shifted)) 
           && (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sticky_lost));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sub_has_added_sticky 
        = (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_shifted) 
            <= (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_not_shifted)) 
           && ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sticky_align_local) 
               & (~ (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sticky_lost))));
}

void Vadd_fp16_tb_full___024root___nba_sequent__TOP__0(Vadd_fp16_tb_full___024root* vlSelf);

void Vadd_fp16_tb_full___024root___eval_nba(Vadd_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root___eval_nba\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadd_fp16_tb_full___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((0xcULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vadd_fp16_tb_full___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
}

VL_INLINE_OPT void Vadd_fp16_tb_full___024root___nba_sequent__TOP__0(Vadd_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root___nba_sequent__TOP__0\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.add_fp16_tb_full__DOT__tb_done = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_nrst) 
                                                && (IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_start));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case_l 
        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_case));
    if (vlSelfRef.add_fp16_tb_full__DOT__tb_nrst) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_max_l 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_max;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__smaller_mantissa_l 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__smaller_mantissa;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa_l 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa;
    } else {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__special_result_l = 0U;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_max_l = 0U;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__smaller_mantissa_l = 0U;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa_l = 0U;
    }
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa_sign_l 
        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa_sign));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sub_has_lost_sticky_l 
        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sub_has_lost_sticky));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sub_has_added_sticky_l 
        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sub_has_added_sticky));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_not_shifted_l 
        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_not_shifted));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_shifted_l 
        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_shifted));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__signs_differ_l 
        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__tb_nrst) 
           && ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_shifted) 
               ^ (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_not_shifted)));
    if (vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__signs_differ_l) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa_sign_l;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum 
            = (0x3fffU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa_l) 
                          - (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__smaller_mantissa_l)));
    } else {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__result_sign 
            = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_shifted_l) 
               & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sign_not_shifted_l));
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum 
            = (0x3fffU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__smaller_mantissa_l) 
                          + (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__larger_mantissa_l)));
    }
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_overflow 
        = (1U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                 >> 0xdU));
    if (((((((((0x800U == (0x1800U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))) 
               | (0x400U == (0x1c00U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) 
              | (0x200U == (0x1e00U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) 
             | (0x100U == (0x1f00U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) 
            | (0x80U == (0x1f80U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) 
           | (0x40U == (0x1fc0U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) 
          | (0x20U == (0x1fe0U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) 
         | (0x10U == (0x1ff0U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))))) {
        if ((0x800U == (0x1800U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) {
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = 1U;
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1ffeU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                                         << 1U)));
        } else if ((0x400U == (0x1c00U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) {
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = 2U;
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1ffcU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                                         << 2U)));
        } else if ((0x200U == (0x1e00U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) {
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = 3U;
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1ff8U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                                         << 3U)));
        } else if ((0x100U == (0x1f00U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) {
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = 4U;
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1ff0U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                                         << 4U)));
        } else if ((0x80U == (0x1f80U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) {
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = 5U;
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1fe0U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                                         << 5U)));
        } else if ((0x40U == (0x1fc0U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) {
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = 6U;
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1fc0U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                                         << 6U)));
        } else if ((0x20U == (0x1fe0U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) {
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = 7U;
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1f80U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                                         << 7U)));
        } else {
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = 8U;
            vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum 
                = (0x1fffU & (0x1f00U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                                         << 8U)));
        }
    } else if ((8U == (0x1ff8U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = 9U;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum 
            = (0x1fffU & (0x1e00U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                                     << 9U)));
    } else if ((4U == (0x1ffcU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = 0xaU;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum 
            = (0x1fffU & (0x1c00U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                                     << 0xaU)));
    } else if ((2U == (0x1ffeU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = 0xbU;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum 
            = (0x1fffU & (0x1800U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                                     << 0xbU)));
    } else if ((1U == (0x1fffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum)))) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = 0xcU;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum 
            = (0x1fffU & (0x1000U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                                     << 0xcU)));
    } else {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount = 0U;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum 
            = (0x1fffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum));
    }
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_norm_s 
        = ((0U == (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum))
            ? 0U : (0x7fU & (VL_EXTENDS_II(7,6, (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_max_l)) 
                             - (0xfU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT____Vcellout__normalizer__shifted_amount)))));
    if (vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_overflow) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_this 
            = (0xfffU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum) 
                         >> 1U));
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_this 
            = ((0xffeU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_this)) 
               | (1U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_this) 
                        | (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_sum))));
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_base 
            = (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_max_l)));
    } else {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_this 
            = (0xfffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__normalized_mantissa_sum));
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_base 
            = (0x3fU & (VL_GTES_III(7, 0U, (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_norm_s))
                         ? 0U : (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_norm_s)));
    }
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__ftz_under 
        = ((1U & (~ (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__mantissa_overflow))) 
           && VL_GTES_III(7, 0U, (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_norm_s)));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_inc 
        = ((1U & (~ (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__signs_differ_l) 
                      & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sub_has_lost_sticky_l)) 
                     & (2U == (3U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_this)))))) 
           && ((((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__signs_differ_l) 
                 & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__sub_has_added_sticky_l)) 
                & (2U == (3U & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_this)))) 
               || (1U & (((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_this) 
                          >> 1U) & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_this) 
                                    | ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_this) 
                                       >> 2U))))));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_sum 
        = (0x7ffU & ((0x3ffU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_this) 
                                >> 2U)) + (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__round_inc)));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_carry 
        = (1U & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_sum) 
                 >> 0xaU));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out 
        = (0x3fU & ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_base) 
                    + (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_carry)));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction 
        = ((IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_carry)
            ? 0U : (0x3ffU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__frac_sum)));
    vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__overflow 
        = (0x1eU < (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out));
    if (vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__overflow) {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final = 0x1fU;
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final = 0U;
    } else {
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out_final 
            = (0x1fU & (IData)(vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__exp_out));
        vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction_final 
            = vlSelfRef.add_fp16_tb_full__DOT__dut__DOT__rounded_fraction;
    }
}

void Vadd_fp16_tb_full___024root___timing_resume(Vadd_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root___timing_resume\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h9c6897a4__0.resume(
                                                   "@(negedge add_fp16_tb_full.tb_clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vadd_fp16_tb_full___024root___timing_commit(Vadd_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root___timing_commit\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (8ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h9c6897a4__0.commit(
                                                   "@(negedge add_fp16_tb_full.tb_clk)");
    }
}

void Vadd_fp16_tb_full___024root___eval_triggers__act(Vadd_fp16_tb_full___024root* vlSelf);

bool Vadd_fp16_tb_full___024root___eval_phase__act(Vadd_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root___eval_phase__act\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vadd_fp16_tb_full___024root___eval_triggers__act(vlSelf);
    Vadd_fp16_tb_full___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vadd_fp16_tb_full___024root___timing_resume(vlSelf);
        Vadd_fp16_tb_full___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vadd_fp16_tb_full___024root___eval_phase__nba(Vadd_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root___eval_phase__nba\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vadd_fp16_tb_full___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_fp16_tb_full___024root___dump_triggers__nba(Vadd_fp16_tb_full___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd_fp16_tb_full___024root___dump_triggers__act(Vadd_fp16_tb_full___024root* vlSelf);
#endif  // VL_DEBUG

void Vadd_fp16_tb_full___024root___eval(Vadd_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root___eval\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vadd_fp16_tb_full___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/unit/systolic_array/add_fp16_tb_full.sv", 9, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vadd_fp16_tb_full___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/unit/systolic_array/add_fp16_tb_full.sv", 9, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vadd_fp16_tb_full___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vadd_fp16_tb_full___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vadd_fp16_tb_full___024root___eval_debug_assertions(Vadd_fp16_tb_full___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_fp16_tb_full___024root___eval_debug_assertions\n"); );
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
