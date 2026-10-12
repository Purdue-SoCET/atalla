// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd_bf16_tb.h for the primary calling header

#include "Vadd_bf16_tb__pch.h"
#include "Vadd_bf16_tb__Syms.h"
#include "Vadd_bf16_tb___024root.h"

extern const VlWide<12>/*383:0*/ Vadd_bf16_tb__ConstPool__CONST_hfc1f2f8f_0;
extern const VlWide<8>/*255:0*/ Vadd_bf16_tb__ConstPool__CONST_h0ce2c098_0;

VL_INLINE_OPT VlCoroutine Vadd_bf16_tb___024root___eval_initial__TOP__Vtiming__0(Vadd_bf16_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd_bf16_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vadd_bf16_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    std::string add_bf16_tb__DOT__header;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_he018c797__0;
    add_bf16_tb__DOT____Vlvbound_he018c797__0 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h88feca01__0;
    add_bf16_tb__DOT____Vlvbound_h88feca01__0 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_hf107fd1b__0;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__0 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_he018c797__1;
    add_bf16_tb__DOT____Vlvbound_he018c797__1 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h88feca01__1;
    add_bf16_tb__DOT____Vlvbound_h88feca01__1 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_hf107fd1b__1;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__1 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_he018c797__2;
    add_bf16_tb__DOT____Vlvbound_he018c797__2 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h88feca01__2;
    add_bf16_tb__DOT____Vlvbound_h88feca01__2 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_hf107fd1b__2;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__2 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_he018c797__3;
    add_bf16_tb__DOT____Vlvbound_he018c797__3 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h88feca01__3;
    add_bf16_tb__DOT____Vlvbound_h88feca01__3 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_hf107fd1b__3;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__3 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_he018c797__4;
    add_bf16_tb__DOT____Vlvbound_he018c797__4 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h88feca01__4;
    add_bf16_tb__DOT____Vlvbound_h88feca01__4 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_hf107fd1b__4;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__4 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_he018c797__5;
    add_bf16_tb__DOT____Vlvbound_he018c797__5 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h88feca01__5;
    add_bf16_tb__DOT____Vlvbound_h88feca01__5 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_hf107fd1b__5;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__5 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_he018c797__6;
    add_bf16_tb__DOT____Vlvbound_he018c797__6 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h88feca01__6;
    add_bf16_tb__DOT____Vlvbound_h88feca01__6 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_hf107fd1b__6;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__6 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_he018c797__7;
    add_bf16_tb__DOT____Vlvbound_he018c797__7 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h88feca01__7;
    add_bf16_tb__DOT____Vlvbound_h88feca01__7 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_hf107fd1b__7;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__7 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_he018c797__8;
    add_bf16_tb__DOT____Vlvbound_he018c797__8 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h88feca01__8;
    add_bf16_tb__DOT____Vlvbound_h88feca01__8 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_hf107fd1b__8;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__8 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_he018c797__9;
    add_bf16_tb__DOT____Vlvbound_he018c797__9 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h88feca01__9;
    add_bf16_tb__DOT____Vlvbound_h88feca01__9 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_hf107fd1b__9;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__9 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_he018c797__10;
    add_bf16_tb__DOT____Vlvbound_he018c797__10 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h88feca01__10;
    add_bf16_tb__DOT____Vlvbound_h88feca01__10 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_hf107fd1b__10;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__10 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_he018c797__11;
    add_bf16_tb__DOT____Vlvbound_he018c797__11 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h88feca01__11;
    add_bf16_tb__DOT____Vlvbound_h88feca01__11 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_hf107fd1b__11;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__11 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_he018c797__12;
    add_bf16_tb__DOT____Vlvbound_he018c797__12 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h88feca01__12;
    add_bf16_tb__DOT____Vlvbound_h88feca01__12 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_hf107fd1b__12;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__12 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_he018c797__13;
    add_bf16_tb__DOT____Vlvbound_he018c797__13 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h88feca01__13;
    add_bf16_tb__DOT____Vlvbound_h88feca01__13 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_hf107fd1b__13;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__13 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_he018c797__14;
    add_bf16_tb__DOT____Vlvbound_he018c797__14 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h88feca01__14;
    add_bf16_tb__DOT____Vlvbound_h88feca01__14 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_hf107fd1b__14;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__14 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_he018c797__15;
    add_bf16_tb__DOT____Vlvbound_he018c797__15 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h88feca01__15;
    add_bf16_tb__DOT____Vlvbound_h88feca01__15 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_hf107fd1b__15;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__15 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_he018c797__16;
    add_bf16_tb__DOT____Vlvbound_he018c797__16 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h88feca01__16;
    add_bf16_tb__DOT____Vlvbound_h88feca01__16 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_hf107fd1b__16;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__16 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_he018c797__17;
    add_bf16_tb__DOT____Vlvbound_he018c797__17 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h88feca01__17;
    add_bf16_tb__DOT____Vlvbound_h88feca01__17 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_hf107fd1b__17;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__17 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_he018c797__18;
    add_bf16_tb__DOT____Vlvbound_he018c797__18 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h88feca01__18;
    add_bf16_tb__DOT____Vlvbound_h88feca01__18 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_hf107fd1b__18;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__18 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_he018c797__19;
    add_bf16_tb__DOT____Vlvbound_he018c797__19 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h88feca01__19;
    add_bf16_tb__DOT____Vlvbound_h88feca01__19 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_hf107fd1b__19;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__19 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_he018c797__20;
    add_bf16_tb__DOT____Vlvbound_he018c797__20 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h88feca01__20;
    add_bf16_tb__DOT____Vlvbound_h88feca01__20 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_hf107fd1b__20;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__20 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_he018c797__21;
    add_bf16_tb__DOT____Vlvbound_he018c797__21 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h88feca01__21;
    add_bf16_tb__DOT____Vlvbound_h88feca01__21 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_hf107fd1b__21;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__21 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_he018c797__22;
    add_bf16_tb__DOT____Vlvbound_he018c797__22 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h88feca01__22;
    add_bf16_tb__DOT____Vlvbound_h88feca01__22 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_hf107fd1b__22;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__22 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_he018c797__23;
    add_bf16_tb__DOT____Vlvbound_he018c797__23 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h88feca01__23;
    add_bf16_tb__DOT____Vlvbound_h88feca01__23 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_hf107fd1b__23;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__23 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_he018c797__24;
    add_bf16_tb__DOT____Vlvbound_he018c797__24 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_h88feca01__24;
    add_bf16_tb__DOT____Vlvbound_h88feca01__24 = 0;
    SData/*15:0*/ add_bf16_tb__DOT____Vlvbound_hf107fd1b__24;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__24 = 0;
    SData/*15:0*/ __Vtask_add_bf16_tb__DOT__apply_and_wait__0__a;
    __Vtask_add_bf16_tb__DOT__apply_and_wait__0__a = 0;
    SData/*15:0*/ __Vtask_add_bf16_tb__DOT__apply_and_wait__0__b;
    __Vtask_add_bf16_tb__DOT__apply_and_wait__0__b = 0;
    CData/*0:0*/ __Vtask_add_bf16_tb__DOT__apply_and_wait__0__sub;
    __Vtask_add_bf16_tb__DOT__apply_and_wait__0__sub = 0;
    SData/*15:0*/ __Vtask_add_bf16_tb__DOT__apply_and_wait__1__a;
    __Vtask_add_bf16_tb__DOT__apply_and_wait__1__a = 0;
    SData/*15:0*/ __Vtask_add_bf16_tb__DOT__apply_and_wait__1__b;
    __Vtask_add_bf16_tb__DOT__apply_and_wait__1__b = 0;
    CData/*0:0*/ __Vtask_add_bf16_tb__DOT__apply_and_wait__1__sub;
    __Vtask_add_bf16_tb__DOT__apply_and_wait__1__sub = 0;
    CData/*0:0*/ __Vfunc_add_bf16_tb__DOT__match__2__Vfuncout;
    __Vfunc_add_bf16_tb__DOT__match__2__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_bf16_tb__DOT__match__2__got;
    __Vfunc_add_bf16_tb__DOT__match__2__got = 0;
    SData/*15:0*/ __Vfunc_add_bf16_tb__DOT__match__2__exp;
    __Vfunc_add_bf16_tb__DOT__match__2__exp = 0;
    CData/*0:0*/ __Vfunc_add_bf16_tb__DOT__is_nan__3__Vfuncout;
    __Vfunc_add_bf16_tb__DOT__is_nan__3__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_bf16_tb__DOT__is_nan__3__v;
    __Vfunc_add_bf16_tb__DOT__is_nan__3__v = 0;
    CData/*0:0*/ __Vfunc_add_bf16_tb__DOT__is_nan__4__Vfuncout;
    __Vfunc_add_bf16_tb__DOT__is_nan__4__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_bf16_tb__DOT__is_nan__4__v;
    __Vfunc_add_bf16_tb__DOT__is_nan__4__v = 0;
    CData/*0:0*/ __Vfunc_add_bf16_tb__DOT__is_zero_equiv__5__Vfuncout;
    __Vfunc_add_bf16_tb__DOT__is_zero_equiv__5__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_bf16_tb__DOT__is_zero_equiv__5__a;
    __Vfunc_add_bf16_tb__DOT__is_zero_equiv__5__a = 0;
    SData/*15:0*/ __Vfunc_add_bf16_tb__DOT__is_zero_equiv__5__b;
    __Vfunc_add_bf16_tb__DOT__is_zero_equiv__5__b = 0;
    SData/*15:0*/ __Vtask_add_bf16_tb__DOT__apply_and_wait__6__a;
    __Vtask_add_bf16_tb__DOT__apply_and_wait__6__a = 0;
    SData/*15:0*/ __Vtask_add_bf16_tb__DOT__apply_and_wait__6__b;
    __Vtask_add_bf16_tb__DOT__apply_and_wait__6__b = 0;
    CData/*0:0*/ __Vtask_add_bf16_tb__DOT__apply_and_wait__6__sub;
    __Vtask_add_bf16_tb__DOT__apply_and_wait__6__sub = 0;
    CData/*0:0*/ __Vfunc_add_bf16_tb__DOT__match__7__Vfuncout;
    __Vfunc_add_bf16_tb__DOT__match__7__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_bf16_tb__DOT__match__7__got;
    __Vfunc_add_bf16_tb__DOT__match__7__got = 0;
    SData/*15:0*/ __Vfunc_add_bf16_tb__DOT__match__7__exp;
    __Vfunc_add_bf16_tb__DOT__match__7__exp = 0;
    CData/*0:0*/ __Vfunc_add_bf16_tb__DOT__is_nan__8__Vfuncout;
    __Vfunc_add_bf16_tb__DOT__is_nan__8__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_bf16_tb__DOT__is_nan__8__v;
    __Vfunc_add_bf16_tb__DOT__is_nan__8__v = 0;
    CData/*0:0*/ __Vfunc_add_bf16_tb__DOT__is_nan__9__Vfuncout;
    __Vfunc_add_bf16_tb__DOT__is_nan__9__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_bf16_tb__DOT__is_nan__9__v;
    __Vfunc_add_bf16_tb__DOT__is_nan__9__v = 0;
    CData/*0:0*/ __Vfunc_add_bf16_tb__DOT__is_zero_equiv__10__Vfuncout;
    __Vfunc_add_bf16_tb__DOT__is_zero_equiv__10__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add_bf16_tb__DOT__is_zero_equiv__10__a;
    __Vfunc_add_bf16_tb__DOT__is_zero_equiv__10__a = 0;
    SData/*15:0*/ __Vfunc_add_bf16_tb__DOT__is_zero_equiv__10__b;
    __Vfunc_add_bf16_tb__DOT__is_zero_equiv__10__b = 0;
    // Body
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(12, Vadd_bf16_tb__ConstPool__CONST_hfc1f2f8f_0));
    vlSymsp->_traceDumpOpen();
    vlSelfRef.add_bf16_tb__DOT__pass_cnt = 0U;
    vlSelfRef.add_bf16_tb__DOT__fail_cnt = 0U;
    vlSelfRef.add_bf16_tb__DOT__idx = 0U;
    vlSelfRef.add_bf16_tb__DOT__tb_nrst = 0U;
    vlSelfRef.add_bf16_tb__DOT__tb_a = 0U;
    vlSelfRef.add_bf16_tb__DOT__tb_b = 0U;
    vlSelfRef.add_bf16_tb__DOT__tb_sub = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "systolic_array_utils/add_bf16_tb.sv", 
                                         92);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_bf16_tb__DOT__tb_nrst = 1U;
    add_bf16_tb__DOT____Vlvbound_he018c797__0 = 0x3fc0U;
    add_bf16_tb__DOT____Vlvbound_h88feca01__0 = 0x4020U;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__0 = 0x4080U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__A[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_he018c797__0;
        vlSelfRef.add_bf16_tb__DOT__B[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h88feca01__0;
        vlSelfRef.add_bf16_tb__DOT__EXP[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_hf107fd1b__0;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_he018c797__1 = 0x4200U;
    add_bf16_tb__DOT____Vlvbound_h88feca01__1 = 0x3f00U;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__1 = 0x4202U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__A[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_he018c797__1;
        vlSelfRef.add_bf16_tb__DOT__B[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h88feca01__1;
        vlSelfRef.add_bf16_tb__DOT__EXP[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_hf107fd1b__1;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_he018c797__2 = 0x4100U;
    add_bf16_tb__DOT____Vlvbound_h88feca01__2 = 0x4100U;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__2 = 0x4180U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__A[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_he018c797__2;
        vlSelfRef.add_bf16_tb__DOT__B[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h88feca01__2;
        vlSelfRef.add_bf16_tb__DOT__EXP[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_hf107fd1b__2;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_he018c797__3 = 0x4480U;
    add_bf16_tb__DOT____Vlvbound_h88feca01__3 = 0x4100U;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__3 = 0x4481U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__A[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_he018c797__3;
        vlSelfRef.add_bf16_tb__DOT__B[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h88feca01__3;
        vlSelfRef.add_bf16_tb__DOT__EXP[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_hf107fd1b__3;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_he018c797__4 = 0U;
    add_bf16_tb__DOT____Vlvbound_h88feca01__4 = 0U;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__4 = 0U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__A[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_he018c797__4;
        vlSelfRef.add_bf16_tb__DOT__B[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h88feca01__4;
        vlSelfRef.add_bf16_tb__DOT__EXP[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_hf107fd1b__4;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_he018c797__5 = 0x8000U;
    add_bf16_tb__DOT____Vlvbound_h88feca01__5 = 0U;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__5 = 0U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__A[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_he018c797__5;
        vlSelfRef.add_bf16_tb__DOT__B[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h88feca01__5;
        vlSelfRef.add_bf16_tb__DOT__EXP[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_hf107fd1b__5;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_he018c797__6 = 0x8000U;
    add_bf16_tb__DOT____Vlvbound_h88feca01__6 = 0x8000U;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__6 = 0x8000U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__A[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_he018c797__6;
        vlSelfRef.add_bf16_tb__DOT__B[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h88feca01__6;
        vlSelfRef.add_bf16_tb__DOT__EXP[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_hf107fd1b__6;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_he018c797__7 = 0U;
    add_bf16_tb__DOT____Vlvbound_h88feca01__7 = 0x4100U;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__7 = 0x4100U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__A[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_he018c797__7;
        vlSelfRef.add_bf16_tb__DOT__B[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h88feca01__7;
        vlSelfRef.add_bf16_tb__DOT__EXP[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_hf107fd1b__7;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_he018c797__8 = 0x7f80U;
    add_bf16_tb__DOT____Vlvbound_h88feca01__8 = 0x4080U;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__8 = 0x7f80U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__A[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_he018c797__8;
        vlSelfRef.add_bf16_tb__DOT__B[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h88feca01__8;
        vlSelfRef.add_bf16_tb__DOT__EXP[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_hf107fd1b__8;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_he018c797__9 = 0x7f80U;
    add_bf16_tb__DOT____Vlvbound_h88feca01__9 = 0xff80U;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__9 = 0x7fc0U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__A[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_he018c797__9;
        vlSelfRef.add_bf16_tb__DOT__B[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h88feca01__9;
        vlSelfRef.add_bf16_tb__DOT__EXP[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_hf107fd1b__9;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_he018c797__10 = 0xff80U;
    add_bf16_tb__DOT____Vlvbound_h88feca01__10 = 0x4080U;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__10 = 0xff80U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__A[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_he018c797__10;
        vlSelfRef.add_bf16_tb__DOT__B[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h88feca01__10;
        vlSelfRef.add_bf16_tb__DOT__EXP[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_hf107fd1b__10;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_he018c797__11 = 0xff80U;
    add_bf16_tb__DOT____Vlvbound_h88feca01__11 = 0xff80U;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__11 = 0xff80U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__A[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_he018c797__11;
        vlSelfRef.add_bf16_tb__DOT__B[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h88feca01__11;
        vlSelfRef.add_bf16_tb__DOT__EXP[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_hf107fd1b__11;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_he018c797__12 = 0x7f80U;
    add_bf16_tb__DOT____Vlvbound_h88feca01__12 = 0x7f80U;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__12 = 0x7f80U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__A[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_he018c797__12;
        vlSelfRef.add_bf16_tb__DOT__B[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h88feca01__12;
        vlSelfRef.add_bf16_tb__DOT__EXP[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_hf107fd1b__12;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_he018c797__13 = 0x7fc0U;
    add_bf16_tb__DOT____Vlvbound_h88feca01__13 = 0x3f80U;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__13 = 0x7fc0U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__A[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_he018c797__13;
        vlSelfRef.add_bf16_tb__DOT__B[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h88feca01__13;
        vlSelfRef.add_bf16_tb__DOT__EXP[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_hf107fd1b__13;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_he018c797__14 = 0x7fc0U;
    add_bf16_tb__DOT____Vlvbound_h88feca01__14 = 0x7fc0U;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__14 = 0x7fc0U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__A[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_he018c797__14;
        vlSelfRef.add_bf16_tb__DOT__B[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h88feca01__14;
        vlSelfRef.add_bf16_tb__DOT__EXP[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_hf107fd1b__14;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_he018c797__15 = 0x7f7fU;
    add_bf16_tb__DOT____Vlvbound_h88feca01__15 = 0x7f00U;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__15 = 0x7f80U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__A[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_he018c797__15;
        vlSelfRef.add_bf16_tb__DOT__B[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h88feca01__15;
        vlSelfRef.add_bf16_tb__DOT__EXP[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_hf107fd1b__15;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_he018c797__16 = 0xff7fU;
    add_bf16_tb__DOT____Vlvbound_h88feca01__16 = 0xff7fU;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__16 = 0xff80U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__A[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_he018c797__16;
        vlSelfRef.add_bf16_tb__DOT__B[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h88feca01__16;
        vlSelfRef.add_bf16_tb__DOT__EXP[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_hf107fd1b__16;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_he018c797__17 = 0x80U;
    add_bf16_tb__DOT____Vlvbound_h88feca01__17 = 0x80U;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__17 = 0x100U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__A[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_he018c797__17;
        vlSelfRef.add_bf16_tb__DOT__B[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h88feca01__17;
        vlSelfRef.add_bf16_tb__DOT__EXP[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_hf107fd1b__17;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_he018c797__18 = 1U;
    add_bf16_tb__DOT____Vlvbound_h88feca01__18 = 1U;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__18 = 0U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__A[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_he018c797__18;
        vlSelfRef.add_bf16_tb__DOT__B[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h88feca01__18;
        vlSelfRef.add_bf16_tb__DOT__EXP[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_hf107fd1b__18;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_he018c797__19 = 0x81U;
    add_bf16_tb__DOT____Vlvbound_h88feca01__19 = 0x8080U;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__19 = 0U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__A[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_he018c797__19;
        vlSelfRef.add_bf16_tb__DOT__B[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h88feca01__19;
        vlSelfRef.add_bf16_tb__DOT__EXP[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_hf107fd1b__19;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_he018c797__20 = 0x7000U;
    add_bf16_tb__DOT____Vlvbound_h88feca01__20 = 0x3000U;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__20 = 0x7000U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__A[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_he018c797__20;
        vlSelfRef.add_bf16_tb__DOT__B[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h88feca01__20;
        vlSelfRef.add_bf16_tb__DOT__EXP[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_hf107fd1b__20;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_he018c797__21 = 0x5a00U;
    add_bf16_tb__DOT____Vlvbound_h88feca01__21 = 1U;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__21 = 0x5a00U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__A[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_he018c797__21;
        vlSelfRef.add_bf16_tb__DOT__B[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h88feca01__21;
        vlSelfRef.add_bf16_tb__DOT__EXP[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_hf107fd1b__21;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_he018c797__22 = 0x4000U;
    add_bf16_tb__DOT____Vlvbound_h88feca01__22 = 0xc000U;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__22 = 0U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__A[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_he018c797__22;
        vlSelfRef.add_bf16_tb__DOT__B[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h88feca01__22;
        vlSelfRef.add_bf16_tb__DOT__EXP[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_hf107fd1b__22;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_he018c797__23 = 0x4200U;
    add_bf16_tb__DOT____Vlvbound_h88feca01__23 = 0xc1fcU;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__23 = 0x3f00U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__A[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_he018c797__23;
        vlSelfRef.add_bf16_tb__DOT__B[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h88feca01__23;
        vlSelfRef.add_bf16_tb__DOT__EXP[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_hf107fd1b__23;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    add_bf16_tb__DOT____Vlvbound_he018c797__24 = 0xc000U;
    add_bf16_tb__DOT____Vlvbound_h88feca01__24 = 0x3f80U;
    add_bf16_tb__DOT____Vlvbound_hf107fd1b__24 = 0xbf80U;
    if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__idx))) {
        vlSelfRef.add_bf16_tb__DOT__A[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_he018c797__24;
        vlSelfRef.add_bf16_tb__DOT__B[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_h88feca01__24;
        vlSelfRef.add_bf16_tb__DOT__EXP[(0x1fU & vlSelfRef.add_bf16_tb__DOT__idx)] 
            = add_bf16_tb__DOT____Vlvbound_hf107fd1b__24;
    }
    vlSelfRef.add_bf16_tb__DOT__idx = ((IData)(1U) 
                                       + vlSelfRef.add_bf16_tb__DOT__idx);
    __Vtask_add_bf16_tb__DOT__apply_and_wait__0__sub = 0U;
    __Vtask_add_bf16_tb__DOT__apply_and_wait__0__b = 0U;
    __Vtask_add_bf16_tb__DOT__apply_and_wait__0__a = 0U;
    co_await vlSelfRef.__VtrigSched_hf547ea9c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge add_bf16_tb.tb_clk)", 
                                                         "systolic_array_utils/add_bf16_tb.sv", 
                                                         50);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add_bf16_tb__DOT__tb_a = __Vtask_add_bf16_tb__DOT__apply_and_wait__0__a;
    vlSelfRef.add_bf16_tb__DOT__tb_b = __Vtask_add_bf16_tb__DOT__apply_and_wait__0__b;
    vlSelfRef.add_bf16_tb__DOT__tb_sub = __Vtask_add_bf16_tb__DOT__apply_and_wait__0__sub;
    co_await vlSelfRef.__VtrigSched_hf547eadd__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge add_bf16_tb.tb_clk)", 
                                                         "systolic_array_utils/add_bf16_tb.sv", 
                                                         54);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "systolic_array_utils/add_bf16_tb.sv", 
                                         55);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("BF16 Manual Edge Cases\n",0);
    vlSelfRef.add_bf16_tb__DOT__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.add_bf16_tb__DOT__i, vlSelfRef.add_bf16_tb__DOT__idx)) {
        __Vtask_add_bf16_tb__DOT__apply_and_wait__1__sub = 0U;
        if ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__i))) {
            __Vtask_add_bf16_tb__DOT__apply_and_wait__1__b 
                = vlSelfRef.add_bf16_tb__DOT__B[(0x1fU 
                                                 & vlSelfRef.add_bf16_tb__DOT__i)];
            __Vtask_add_bf16_tb__DOT__apply_and_wait__1__a 
                = vlSelfRef.add_bf16_tb__DOT__A[(0x1fU 
                                                 & vlSelfRef.add_bf16_tb__DOT__i)];
        } else {
            __Vtask_add_bf16_tb__DOT__apply_and_wait__1__b = 0U;
            __Vtask_add_bf16_tb__DOT__apply_and_wait__1__a = 0U;
        }
        co_await vlSelfRef.__VtrigSched_hf547ea9c__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge add_bf16_tb.tb_clk)", 
                                                             "systolic_array_utils/add_bf16_tb.sv", 
                                                             50);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSelfRef.add_bf16_tb__DOT__tb_a = __Vtask_add_bf16_tb__DOT__apply_and_wait__1__a;
        vlSelfRef.add_bf16_tb__DOT__tb_b = __Vtask_add_bf16_tb__DOT__apply_and_wait__1__b;
        vlSelfRef.add_bf16_tb__DOT__tb_sub = __Vtask_add_bf16_tb__DOT__apply_and_wait__1__sub;
        co_await vlSelfRef.__VtrigSched_hf547eadd__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge add_bf16_tb.tb_clk)", 
                                                             "systolic_array_utils/add_bf16_tb.sv", 
                                                             54);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        co_await vlSelfRef.__VdlySched.delay(1ULL, 
                                             nullptr, 
                                             "systolic_array_utils/add_bf16_tb.sv", 
                                             55);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        if (([&]() {
                    __Vfunc_add_bf16_tb__DOT__match__2__exp 
                        = ((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__i))
                            ? vlSelfRef.add_bf16_tb__DOT__EXP
                           [(0x1fU & vlSelfRef.add_bf16_tb__DOT__i)]
                            : 0U);
                    __Vfunc_add_bf16_tb__DOT__match__2__got 
                        = vlSelfRef.add_bf16_tb__DOT__tb_result;
                    {
                        if ((([&]() {
                                        __Vfunc_add_bf16_tb__DOT__is_nan__3__v 
                                            = __Vfunc_add_bf16_tb__DOT__match__2__got;
                                        __Vfunc_add_bf16_tb__DOT__is_nan__3__Vfuncout 
                                            = (IData)(
                                                      ((0x7f80U 
                                                        == 
                                                        (0x7f80U 
                                                         & (IData)(__Vfunc_add_bf16_tb__DOT__is_nan__3__v))) 
                                                       & (0U 
                                                          != 
                                                          (0x7fU 
                                                           & (IData)(__Vfunc_add_bf16_tb__DOT__is_nan__3__v)))));
                                    }(), (IData)(__Vfunc_add_bf16_tb__DOT__is_nan__3__Vfuncout)) 
                             & ([&]() {
                                        __Vfunc_add_bf16_tb__DOT__is_nan__4__v 
                                            = __Vfunc_add_bf16_tb__DOT__match__2__exp;
                                        __Vfunc_add_bf16_tb__DOT__is_nan__4__Vfuncout 
                                            = (IData)(
                                                      ((0x7f80U 
                                                        == 
                                                        (0x7f80U 
                                                         & (IData)(__Vfunc_add_bf16_tb__DOT__is_nan__4__v))) 
                                                       & (0U 
                                                          != 
                                                          (0x7fU 
                                                           & (IData)(__Vfunc_add_bf16_tb__DOT__is_nan__4__v)))));
                                    }(), (IData)(__Vfunc_add_bf16_tb__DOT__is_nan__4__Vfuncout)))) {
                            __Vfunc_add_bf16_tb__DOT__match__2__Vfuncout = 1U;
                            goto __Vlabel1;
                        }
                        if (([&]() {
                                    __Vfunc_add_bf16_tb__DOT__is_zero_equiv__5__b 
                                        = __Vfunc_add_bf16_tb__DOT__match__2__exp;
                                    __Vfunc_add_bf16_tb__DOT__is_zero_equiv__5__a 
                                        = __Vfunc_add_bf16_tb__DOT__match__2__got;
                                    __Vfunc_add_bf16_tb__DOT__is_zero_equiv__5__Vfuncout 
                                        = (((0U == (IData)(__Vfunc_add_bf16_tb__DOT__is_zero_equiv__5__a)) 
                                            | (0x8000U 
                                               == (IData)(__Vfunc_add_bf16_tb__DOT__is_zero_equiv__5__a))) 
                                           & ((0U == (IData)(__Vfunc_add_bf16_tb__DOT__is_zero_equiv__5__b)) 
                                              | (0x8000U 
                                                 == (IData)(__Vfunc_add_bf16_tb__DOT__is_zero_equiv__5__b))));
                                }(), (IData)(__Vfunc_add_bf16_tb__DOT__is_zero_equiv__5__Vfuncout))) {
                            __Vfunc_add_bf16_tb__DOT__match__2__Vfuncout = 1U;
                            goto __Vlabel1;
                        }
                        __Vfunc_add_bf16_tb__DOT__match__2__Vfuncout 
                            = ((IData)(__Vfunc_add_bf16_tb__DOT__match__2__got) 
                               == (IData)(__Vfunc_add_bf16_tb__DOT__match__2__exp));
                        __Vlabel1: ;
                    }
                }(), (IData)(__Vfunc_add_bf16_tb__DOT__match__2__Vfuncout))) {
            vlSelfRef.add_bf16_tb__DOT__pass_cnt = 
                ((IData)(1U) + vlSelfRef.add_bf16_tb__DOT__pass_cnt);
            VL_WRITEF_NX("PASS [%0d] A=%x B=%x OUT=%x\n",0,
                         32,vlSelfRef.add_bf16_tb__DOT__i,
                         16,((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__i))
                              ? vlSelfRef.add_bf16_tb__DOT__A
                             [(0x1fU & vlSelfRef.add_bf16_tb__DOT__i)]
                              : 0U),16,((0x18U >= (0x1fU 
                                                   & vlSelfRef.add_bf16_tb__DOT__i))
                                         ? vlSelfRef.add_bf16_tb__DOT__B
                                        [(0x1fU & vlSelfRef.add_bf16_tb__DOT__i)]
                                         : 0U),16,(IData)(vlSelfRef.add_bf16_tb__DOT__tb_result));
        } else {
            vlSelfRef.add_bf16_tb__DOT__fail_cnt = 
                ((IData)(1U) + vlSelfRef.add_bf16_tb__DOT__fail_cnt);
            VL_WRITEF_NX("FAIL [%0d] A=%x B=%x GOT=%x EXP=%x\n",0,
                         32,vlSelfRef.add_bf16_tb__DOT__i,
                         16,((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__i))
                              ? vlSelfRef.add_bf16_tb__DOT__A
                             [(0x1fU & vlSelfRef.add_bf16_tb__DOT__i)]
                              : 0U),16,((0x18U >= (0x1fU 
                                                   & vlSelfRef.add_bf16_tb__DOT__i))
                                         ? vlSelfRef.add_bf16_tb__DOT__B
                                        [(0x1fU & vlSelfRef.add_bf16_tb__DOT__i)]
                                         : 0U),16,(IData)(vlSelfRef.add_bf16_tb__DOT__tb_result),
                         16,((0x18U >= (0x1fU & vlSelfRef.add_bf16_tb__DOT__i))
                              ? vlSelfRef.add_bf16_tb__DOT__EXP
                             [(0x1fU & vlSelfRef.add_bf16_tb__DOT__i)]
                              : 0U));
        }
        vlSelfRef.add_bf16_tb__DOT__i = ((IData)(1U) 
                                         + vlSelfRef.add_bf16_tb__DOT__i);
    }
    vlSelfRef.add_bf16_tb__DOT__fd = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(8, Vadd_bf16_tb__ConstPool__CONST_h0ce2c098_0)
                                                 , 
                                                 std::string{"r"});
    ;
    if (VL_UNLIKELY(((0U == vlSelfRef.add_bf16_tb__DOT__fd)))) {
        VL_FINISH_MT("systolic_array_utils/add_bf16_tb.sv", 149, "");
    }
    (void)VL_FGETS_NI(add_bf16_tb__DOT__header, vlSelfRef.add_bf16_tb__DOT__fd);
    while ((! (vlSelfRef.add_bf16_tb__DOT__fd ? feof(VL_CVT_I_FP(vlSelfRef.add_bf16_tb__DOT__fd)) : true))) {
        if ((4U == VL_FSCANF_INX(vlSelfRef.add_bf16_tb__DOT__fd,"%x,%x,%#,%x\n",0,
                                 16,&(vlSelfRef.add_bf16_tb__DOT__csv_a),
                                 16,&(vlSelfRef.add_bf16_tb__DOT__csv_b),
                                 32,&(vlSelfRef.add_bf16_tb__DOT__csv_sub_i),
                                 16,&(vlSelfRef.add_bf16_tb__DOT__csv_exp)) )) {
            vlSelfRef.add_bf16_tb__DOT__csv_sub = (1U 
                                                   & vlSelfRef.add_bf16_tb__DOT__csv_sub_i);
            __Vtask_add_bf16_tb__DOT__apply_and_wait__6__sub 
                = vlSelfRef.add_bf16_tb__DOT__csv_sub;
            __Vtask_add_bf16_tb__DOT__apply_and_wait__6__b 
                = vlSelfRef.add_bf16_tb__DOT__csv_b;
            __Vtask_add_bf16_tb__DOT__apply_and_wait__6__a 
                = vlSelfRef.add_bf16_tb__DOT__csv_a;
            co_await vlSelfRef.__VtrigSched_hf547ea9c__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge add_bf16_tb.tb_clk)", 
                                                                 "systolic_array_utils/add_bf16_tb.sv", 
                                                                 50);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSelfRef.add_bf16_tb__DOT__tb_a = __Vtask_add_bf16_tb__DOT__apply_and_wait__6__a;
            vlSelfRef.add_bf16_tb__DOT__tb_b = __Vtask_add_bf16_tb__DOT__apply_and_wait__6__b;
            vlSelfRef.add_bf16_tb__DOT__tb_sub = __Vtask_add_bf16_tb__DOT__apply_and_wait__6__sub;
            co_await vlSelfRef.__VtrigSched_hf547eadd__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge add_bf16_tb.tb_clk)", 
                                                                 "systolic_array_utils/add_bf16_tb.sv", 
                                                                 54);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            co_await vlSelfRef.__VdlySched.delay(1ULL, 
                                                 nullptr, 
                                                 "systolic_array_utils/add_bf16_tb.sv", 
                                                 55);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            if (([&]() {
                        __Vfunc_add_bf16_tb__DOT__match__7__exp 
                            = vlSelfRef.add_bf16_tb__DOT__csv_exp;
                        __Vfunc_add_bf16_tb__DOT__match__7__got 
                            = vlSelfRef.add_bf16_tb__DOT__tb_result;
                        {
                            if ((([&]() {
                                            __Vfunc_add_bf16_tb__DOT__is_nan__8__v 
                                                = __Vfunc_add_bf16_tb__DOT__match__7__got;
                                            __Vfunc_add_bf16_tb__DOT__is_nan__8__Vfuncout 
                                                = (IData)(
                                                          ((0x7f80U 
                                                            == 
                                                            (0x7f80U 
                                                             & (IData)(__Vfunc_add_bf16_tb__DOT__is_nan__8__v))) 
                                                           & (0U 
                                                              != 
                                                              (0x7fU 
                                                               & (IData)(__Vfunc_add_bf16_tb__DOT__is_nan__8__v)))));
                                        }(), (IData)(__Vfunc_add_bf16_tb__DOT__is_nan__8__Vfuncout)) 
                                 & ([&]() {
                                            __Vfunc_add_bf16_tb__DOT__is_nan__9__v 
                                                = __Vfunc_add_bf16_tb__DOT__match__7__exp;
                                            __Vfunc_add_bf16_tb__DOT__is_nan__9__Vfuncout 
                                                = (IData)(
                                                          ((0x7f80U 
                                                            == 
                                                            (0x7f80U 
                                                             & (IData)(__Vfunc_add_bf16_tb__DOT__is_nan__9__v))) 
                                                           & (0U 
                                                              != 
                                                              (0x7fU 
                                                               & (IData)(__Vfunc_add_bf16_tb__DOT__is_nan__9__v)))));
                                        }(), (IData)(__Vfunc_add_bf16_tb__DOT__is_nan__9__Vfuncout)))) {
                                __Vfunc_add_bf16_tb__DOT__match__7__Vfuncout = 1U;
                                goto __Vlabel2;
                            }
                            if (([&]() {
                                        __Vfunc_add_bf16_tb__DOT__is_zero_equiv__10__b 
                                            = __Vfunc_add_bf16_tb__DOT__match__7__exp;
                                        __Vfunc_add_bf16_tb__DOT__is_zero_equiv__10__a 
                                            = __Vfunc_add_bf16_tb__DOT__match__7__got;
                                        __Vfunc_add_bf16_tb__DOT__is_zero_equiv__10__Vfuncout 
                                            = (((0U 
                                                 == (IData)(__Vfunc_add_bf16_tb__DOT__is_zero_equiv__10__a)) 
                                                | (0x8000U 
                                                   == (IData)(__Vfunc_add_bf16_tb__DOT__is_zero_equiv__10__a))) 
                                               & ((0U 
                                                   == (IData)(__Vfunc_add_bf16_tb__DOT__is_zero_equiv__10__b)) 
                                                  | (0x8000U 
                                                     == (IData)(__Vfunc_add_bf16_tb__DOT__is_zero_equiv__10__b))));
                                    }(), (IData)(__Vfunc_add_bf16_tb__DOT__is_zero_equiv__10__Vfuncout))) {
                                __Vfunc_add_bf16_tb__DOT__match__7__Vfuncout = 1U;
                                goto __Vlabel2;
                            }
                            __Vfunc_add_bf16_tb__DOT__match__7__Vfuncout 
                                = ((IData)(__Vfunc_add_bf16_tb__DOT__match__7__got) 
                                   == (IData)(__Vfunc_add_bf16_tb__DOT__match__7__exp));
                            __Vlabel2: ;
                        }
                    }(), (IData)(__Vfunc_add_bf16_tb__DOT__match__7__Vfuncout))) {
                vlSelfRef.add_bf16_tb__DOT__pass_cnt 
                    = ((IData)(1U) + vlSelfRef.add_bf16_tb__DOT__pass_cnt);
            } else {
                vlSelfRef.add_bf16_tb__DOT__fail_cnt 
                    = ((IData)(1U) + vlSelfRef.add_bf16_tb__DOT__fail_cnt);
            }
        }
    }
    VL_FCLOSE_I(vlSelfRef.add_bf16_tb__DOT__fd); VL_WRITEF_NX("\nBF16 ADD/SUB TEST SUMMARY\nPASSED : %0d\nFAILED : %0d\n",0,
                                                              32,
                                                              vlSelfRef.add_bf16_tb__DOT__pass_cnt,
                                                              32,
                                                              vlSelfRef.add_bf16_tb__DOT__fail_cnt);
    if ((0U == vlSelfRef.add_bf16_tb__DOT__fail_cnt)) {
        VL_WRITEF_NX("STATUS : PASS\n",0);
    } else {
        VL_WRITEF_NX("STATUS : FAIL\n",0);
    }
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "systolic_array_utils/add_bf16_tb.sv", 
                                         171);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_FINISH_MT("systolic_array_utils/add_bf16_tb.sv", 172, "");
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
    vlSelfRef.__VactTriggered.setBit(3U, ((~ (IData)(vlSelfRef.add_bf16_tb__DOT__tb_clk)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__add_bf16_tb__DOT__tb_clk__0)));
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
