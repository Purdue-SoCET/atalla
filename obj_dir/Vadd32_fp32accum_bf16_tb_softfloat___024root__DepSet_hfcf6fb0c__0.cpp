// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd32_fp32accum_bf16_tb_softfloat.h for the primary calling header

#include "Vadd32_fp32accum_bf16_tb_softfloat__pch.h"
#include "Vadd32_fp32accum_bf16_tb_softfloat__Syms.h"
#include "Vadd32_fp32accum_bf16_tb_softfloat___024root.h"

extern const VlWide<14>/*447:0*/ Vadd32_fp32accum_bf16_tb_softfloat__ConstPool__CONST_h4e1d0cf8_0;

VL_INLINE_OPT VlCoroutine Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_initial__TOP__Vtiming__0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    std::string add32_fp32accum_bf16_tb_softfloat__DOT__header;
    std::string __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__casename;
    SData/*15:0*/ __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__expected_val;
    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__expected_val = 0;
    IData/*31:0*/ __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k;
    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 0;
    CData/*0:0*/ __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__match;
    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__match = 0;
    QData/*63:0*/ __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__ulp;
    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__ulp = 0;
    CData/*0:0*/ __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__1__Vfuncout;
    __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__1__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__1__val;
    __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__1__val = 0;
    CData/*0:0*/ __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__Vfuncout;
    __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__val;
    __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__val = 0;
    QData/*63:0*/ __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__Vfuncout;
    __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__a;
    __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__a = 0;
    SData/*15:0*/ __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__b;
    __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__b = 0;
    QData/*63:0*/ __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_a;
    __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_a = 0;
    QData/*63:0*/ __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_b;
    __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_b = 0;
    VlWide<7>/*223:0*/ __Vtemp_1;
    VlWide<5>/*159:0*/ __Vtemp_2;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x74726565U;
    __Vtemp_1[2U] = 0x6631365fU;
    __Vtemp_1[3U] = 0x33325f62U;
    __Vtemp_1[4U] = 0x2f616464U;
    __Vtemp_1[5U] = 0x61766573U;
    __Vtemp_1[6U] = 0x77U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(7, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[3U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[4U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[5U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[6U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[7U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[8U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[9U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0xaU] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0xbU] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0xcU] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0xdU] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0xeU] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0xfU] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x10U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x11U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x12U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x13U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x14U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x15U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x16U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x17U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x18U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x19U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x1aU] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x1bU] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x1cU] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x1dU] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x1eU] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x1fU] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk2__DOT__i = 0x20U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                         163);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst = 1U;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                         165);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("Starting 32-input Tree Simulation...\n",0);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fd 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(14, Vadd32_fp32accum_bf16_tb_softfloat__ConstPool__CONST_h4e1d0cf8_0)
                      , std::string{"r"});
    ;
    if (VL_UNLIKELY(((0U == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fd)))) {
        VL_WRITEF_NX("ERROR: Cannot open test vectors file!\n",0);
        VL_FINISH_MT("tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 172, "");
    }
    __Vtemp_2[0U] = 0x2e637376U;
    __Vtemp_2[1U] = 0x75726573U;
    __Vtemp_2[2U] = 0x6661696cU;
    __Vtemp_2[3U] = 0x7265655fU;
    __Vtemp_2[4U] = 0x74U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(5, __Vtemp_2)
                      , std::string{"w"});
    ;
    if (VL_LIKELY(((0U == vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd)))) {
        VL_WRITEF_NX("ERROR: Could not create tree_failures.csv\n",0);
    } else {
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i0,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 1U;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i1,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 2U;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i2,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 3U;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i3,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 4U;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i4,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 5U;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i5,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 6U;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i6,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 7U;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i7,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 8U;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i8,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 9U;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i9,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 0xaU;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i10,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 0xbU;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i11,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 0xcU;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i12,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 0xdU;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i13,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 0xeU;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i14,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 0xfU;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i15,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 0x10U;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i16,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 0x11U;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i17,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 0x12U;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i18,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 0x13U;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i19,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 0x14U;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i20,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 0x15U;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i21,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 0x16U;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i22,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 0x17U;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i23,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 0x18U;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i24,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 0x19U;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i25,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 0x1aU;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i26,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 0x1bU;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i27,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 0x1cU;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i28,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 0x1dU;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i29,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 0x1eU;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i30,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 0x1fU;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"i31,",0);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk3__DOT__k = 0x20U;
        VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"expected,got,ulp\n",0);
    }
    (void)VL_FGETS_NI(add32_fp32accum_bf16_tb_softfloat__DOT__header, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fd);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__total_count = 0U;
    while ((! (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fd ? feof(VL_CVT_I_FP(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fd)) : true))) {
        {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__ret 
                = VL_FSCANF_INX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fd,"%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x\n",0,
                                16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                     [0U]),16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                                [1U]),
                                16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                     [2U]),16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                                [3U]),
                                16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                     [4U]),16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                                [5U]),
                                16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                     [6U]),16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                                [7U]),
                                16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                     [8U]),16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                                [9U]),
                                16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                     [0xaU]),16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                                  [0xbU]),
                                16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                     [0xcU]),16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                                  [0xdU]),
                                16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                     [0xeU]),16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                                  [0xfU]),
                                16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                     [0x10U]),16,&(
                                                   vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                                   [0x11U]),
                                16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                     [0x12U]),16,&(
                                                   vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                                   [0x13U]),
                                16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                     [0x14U]),16,&(
                                                   vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                                   [0x15U]),
                                16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                     [0x16U]),16,&(
                                                   vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                                   [0x17U]),
                                16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                     [0x18U]),16,&(
                                                   vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                                   [0x19U]),
                                16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                     [0x1aU]),16,&(
                                                   vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                                   [0x1bU]),
                                16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                     [0x1cU]),16,&(
                                                   vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                                   [0x1dU]),
                                16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                     [0x1eU]),16,&(
                                                   vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                                                   [0x1fU]),
                                16,&(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_exp)) ;
            if ((0x21U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__ret)) {
                goto __Vlabel1;
            }
            co_await vlSelfRef.__VtrigSched_he33aaeae__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge add32_fp32accum_bf16_tb_softfloat.tb_clk)", 
                                                                 "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                                 203);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0U] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 1U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[1U] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 2U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[2U] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 3U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[3U] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [3U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 4U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[4U] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [4U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 5U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[5U] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [5U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 6U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[6U] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [6U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 7U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[7U] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [7U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 8U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[8U] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [8U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 9U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[9U] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [9U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 0xaU;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0xaU] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [0xaU];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 0xbU;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0xbU] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [0xbU];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 0xcU;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0xcU] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [0xcU];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 0xdU;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0xdU] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [0xdU];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 0xeU;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0xeU] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [0xeU];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 0xfU;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0xfU] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [0xfU];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 0x10U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x10U] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [0x10U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 0x11U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x11U] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [0x11U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 0x12U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x12U] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [0x12U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 0x13U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x13U] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [0x13U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 0x14U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x14U] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [0x14U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 0x15U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x15U] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [0x15U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 0x16U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x16U] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [0x16U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 0x17U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x17U] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [0x17U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 0x18U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x18U] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [0x18U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 0x19U;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x19U] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [0x19U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 0x1aU;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x1aU] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [0x1aU];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 0x1bU;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x1bU] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [0x1bU];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 0x1cU;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x1cU] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [0x1cU];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 0x1dU;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x1dU] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [0x1dU];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 0x1eU;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x1eU] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [0x1eU];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 0x1fU;
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs[0x1fU] 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_in
                [0x1fU];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__unnamedblk5__DOT__k = 0x20U;
            co_await vlSelfRef.__VdlySched.delay(0x4e20ULL, 
                                                 nullptr, 
                                                 "tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 
                                                 207);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__expected_val 
                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__unnamedblk4__DOT__csv_exp;
            __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__casename 
                = VL_SFORMATF_N_NX("Row %0d",0,32,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__total_count) ;
            __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 0;
            __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__match = 0;
            __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__ulp = 0;
            if ((([&]() {
                            __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__1__val 
                                = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_result;
                            __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__1__Vfuncout 
                                = (IData)(((0x7f80U 
                                            == (0x7f80U 
                                                & (IData)(__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__1__val))) 
                                           & (0U != 
                                              (0x7fU 
                                               & (IData)(__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__1__val)))));
                        }(), (IData)(__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__1__Vfuncout)) 
                 & ([&]() {
                            __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__val 
                                = __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__expected_val;
                            __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__Vfuncout 
                                = (IData)(((0x7f80U 
                                            == (0x7f80U 
                                                & (IData)(__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__val))) 
                                           & (0U != 
                                              (0x7fU 
                                               & (IData)(__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__val)))));
                        }(), (IData)(__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__is_nan__2__Vfuncout)))) {
                __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__match = 1U;
                __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__ulp = 0ULL;
            } else {
                __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__match 
                    = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_result) 
                       == (IData)(__Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__expected_val));
                __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__b 
                    = __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__expected_val;
                __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__a 
                    = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_result;
                __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_a = 0;
                __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_b = 0;
                __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_a 
                    = ((0x8000U & (IData)(__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__a))
                        ? (0x7fffffffULL - (QData)((IData)(
                                                           (0x7fffU 
                                                            & (IData)(__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__a)))))
                        : (0x80000000ULL + (QData)((IData)(
                                                           (0x7fffU 
                                                            & (IData)(__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__a))))));
                __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_b 
                    = ((0x8000U & (IData)(__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__b))
                        ? (0x7fffffffULL - (QData)((IData)(
                                                           (0x7fffU 
                                                            & (IData)(__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__b)))))
                        : (0x80000000ULL + (QData)((IData)(
                                                           (0x7fffU 
                                                            & (IData)(__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__b))))));
                __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__Vfuncout 
                    = (VL_GTS_IQQ(64, __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_a, __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_b)
                        ? (__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_a 
                           - __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_b)
                        : (__Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_b 
                           - __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__int_a));
                __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__ulp 
                    = __Vfunc_add32_fp32accum_bf16_tb_softfloat__DOT__get_ulp_distance__3__Vfuncout;
            }
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
                = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff 
                   + __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__ulp);
            if (VL_LTS_IQQ(64, 1ULL, __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__ulp)) {
                vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count 
                    = ((IData)(1U) + vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count);
            }
            if (VL_GTS_IQQ(64, __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__ulp, 
                           VL_EXTENDS_QI(64,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__largest_ulp))) {
                vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__largest_ulp 
                    = (IData)(__Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__ulp);
            }
            if (__Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__match) {
                vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__pass_count 
                    = ((IData)(1U) + vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__pass_count);
            } else {
                if (VL_UNLIKELY((VL_GTS_III(32, 0x14U, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_count)))) {
                    VL_WRITEF_NX("FAIL: %@ | Got=%x Exp=%x | ULP=%0d\n",0,
                                 -1,&(__Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__casename),
                                 16,(IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_result),
                                 16,__Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__expected_val,
                                 64,__Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__ulp);
                }
                if (VL_UNLIKELY(((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd)))) {
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [0U]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 1U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [1U]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 2U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [2U]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 3U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [3U]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 4U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [4U]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 5U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [5U]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 6U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [6U]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 7U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [7U]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 8U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [8U]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 9U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [9U]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 0xaU;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [0xaU]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 0xbU;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [0xbU]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 0xcU;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [0xcU]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 0xdU;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [0xdU]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 0xeU;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [0xeU]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 0xfU;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [0xfU]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 0x10U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [0x10U]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 0x11U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [0x11U]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 0x12U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [0x12U]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 0x13U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [0x13U]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 0x14U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [0x14U]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 0x15U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [0x15U]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 0x16U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [0x16U]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 0x17U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [0x17U]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 0x18U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [0x18U]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 0x19U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [0x19U]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 0x1aU;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [0x1aU]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 0x1bU;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [0x1bU]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 0x1cU;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [0x1cU]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 0x1dU;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [0x1dU]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 0x1eU;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [0x1eU]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 0x1fU;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,",0,
                                  16,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__inputs
                                  [0x1fU]);
                    __Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__unnamedblk1__DOT__k = 0x20U;
                    VL_FWRITEF_NX(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd,"%x,%x,%0d\n",0,
                                  16,__Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__expected_val,
                                  16,(IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_result),
                                  64,__Vtask_add32_fp32accum_bf16_tb_softfloat__DOT__check_case__0__ulp);
                }
                vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_count 
                    = ((IData)(1U) + vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_count);
            }
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__total_count 
                = ((IData)(1U) + vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__total_count);
            if (VL_UNLIKELY(((0U == VL_MODDIVS_III(32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__total_count, (IData)(0x186a0U)))))) {
                VL_WRITEF_NX("Processed %0d cases...\n",0,
                             32,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__total_count);
            }
            __Vlabel1: ;
        }
    }
    VL_WRITEF_NX("\n========================================\nSIMULATION FINISHED\nTOTAL CASES: %0d\nPASSED:      %0d\nFAILED:      %0d\n",0,
                 32,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__total_count,
                 32,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__pass_count,
                 32,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_count);
    if (VL_UNLIKELY((VL_LTS_III(32, 0U, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__total_count)))) {
        VL_WRITEF_NX("AVG ULP ERR: %0f\n",0,64,((1.0 
                                                 * 
                                                 VL_ISTOR_D_Q(64, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__total_ulp_diff)) 
                                                / VL_ISTOR_D_I(32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__total_count)));
    }
    VL_WRITEF_NX("MAX ULP ERR: %0d\nULP > 1:     %0d\n========================================\n\n",0,
                 32,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__largest_ulp,
                 32,vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__ulp_big_count);
    VL_FCLOSE_I(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fd); if (VL_UNLIKELY((
                                                                                (0U 
                                                                                != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd)))) {
        VL_FCLOSE_I(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__fail_fd); }
    VL_FINISH_MT("tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv", 231, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd32_fp32accum_bf16_tb_softfloat___024root___dump_triggers__act(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG

void Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_triggers__act(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_triggers__act\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__norm_val 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__norm_val__1));
    vlSelfRef.__VactTriggered.setBit(1U, (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val__1));
    vlSelfRef.__VactTriggered.setBit(2U, (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val__1));
    vlSelfRef.__VactTriggered.setBit(3U, (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val__1));
    vlSelfRef.__VactTriggered.setBit(4U, (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val__1));
    vlSelfRef.__VactTriggered.setBit(5U, (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val__1));
    vlSelfRef.__VactTriggered.setBit(6U, (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val__1));
    vlSelfRef.__VactTriggered.setBit(7U, (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val__1));
    vlSelfRef.__VactTriggered.setBit(8U, (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val__1));
    vlSelfRef.__VactTriggered.setBit(9U, (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val 
                                          != vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val__1));
    vlSelfRef.__VactTriggered.setBit(0xaU, (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val 
                                            != vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val__1));
    vlSelfRef.__VactTriggered.setBit(0xbU, ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_clk) 
                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__tb_clk__0))));
    vlSelfRef.__VactTriggered.setBit(0xcU, ((~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst)) 
                                            & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst__0)));
    vlSelfRef.__VactTriggered.setBit(0xdU, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__VactTriggered.setBit(0xeU, ((~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_clk)) 
                                            & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__tb_clk__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__norm_val__1 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__norm_val;
    vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val__1 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val;
    vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val__1 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val;
    vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val__1 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val;
    vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val__1 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val;
    vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val__1 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val;
    vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val__1 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val;
    vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val__1 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val;
    vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val__1 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val;
    vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val__1 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val;
    vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val__1 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val;
    vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__tb_clk__0 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst__0 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VactDidInit)))))) {
        vlSelfRef.__VactDidInit = 1U;
        vlSelfRef.__VactTriggered.setBit(0U, 1U);
        vlSelfRef.__VactTriggered.setBit(1U, 1U);
        vlSelfRef.__VactTriggered.setBit(2U, 1U);
        vlSelfRef.__VactTriggered.setBit(3U, 1U);
        vlSelfRef.__VactTriggered.setBit(4U, 1U);
        vlSelfRef.__VactTriggered.setBit(5U, 1U);
        vlSelfRef.__VactTriggered.setBit(6U, 1U);
        vlSelfRef.__VactTriggered.setBit(7U, 1U);
        vlSelfRef.__VactTriggered.setBit(8U, 1U);
        vlSelfRef.__VactTriggered.setBit(9U, 1U);
        vlSelfRef.__VactTriggered.setBit(0xaU, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vadd32_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__1(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__1\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) {
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage3_if.out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__result_out;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage2_if__BRA__1__KET__.out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__result_out;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage2_if__BRA__0__KET__.out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__result_out;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__7__KET__.out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__result_out;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__6__KET__.out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__result_out;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__5__KET__.out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__result_out;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__4__KET__.out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__result_out;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__3__KET__.out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__result_out;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__2__KET__.out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__result_out;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__1__KET__.out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__result_out;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__0__KET__.out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__result_out;
    } else {
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage3_if.out = 0U;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage2_if__BRA__1__KET__.out = 0U;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage2_if__BRA__0__KET__.out = 0U;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__7__KET__.out = 0U;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__6__KET__.out = 0U;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__5__KET__.out = 0U;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__4__KET__.out = 0U;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__3__KET__.out = 0U;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__2__KET__.out = 0U;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__1__KET__.out = 0U;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__0__KET__.out = 0U;
    }
}

VL_INLINE_OPT void Vadd32_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__2(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__2\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__guard 
        = (1U & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage3_if.out 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__rnd 
        = (1U & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage3_if.out 
                 >> 0xeU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__sticky 
        = (0U != (0x3fffU & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage3_if.out));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__round_up 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__guard) 
           & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__rnd) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__sticky)) 
              | (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage3_if.out 
                 >> 0x10U)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__rounded 
        = (0xffU & ((0x7fU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage3_if.out 
                              >> 0x10U)) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__round_up)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__new_exp 
        = (0x3ffU & (VL_EXTENDS_II(10,10, (0xffU & 
                                           (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage3_if.out 
                                            >> 0x17U))) 
                     + VL_EXTENDS_II(10,10, (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__rounded) 
                                                   >> 7U)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_result 
        = ((0xffU == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage3_if.out 
                               >> 0x17U))) ? (0x7f80U 
                                              | ((0x8000U 
                                                  & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage3_if.out 
                                                     >> 0x10U)) 
                                                 | ((0U 
                                                     != 
                                                     (0x7fffffU 
                                                      & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage3_if.out))
                                                     ? 0x40U
                                                     : 0U)))
            : (VL_LTES_III(10, 0xffU, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__new_exp))
                ? (0x7f80U | (0x8000U & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage3_if.out 
                                         >> 0x10U)))
                : (VL_GTES_III(32, 0U, VL_EXTENDS_II(32,10, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__new_exp)))
                    ? (0x8000U & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage3_if.out 
                                  >> 0x10U)) : ((0x8000U 
                                                 & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage3_if.out 
                                                    >> 0x10U)) 
                                                | ((0x7f80U 
                                                    & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__new_exp) 
                                                       << 7U)) 
                                                   | ((0x80U 
                                                       & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__rounded))
                                                       ? 0U
                                                       : 
                                                      (0x7fU 
                                                       & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__final_reduce__DOT__rounded))))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__a_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage2_if__BRA__0__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage2_if__BRA__0__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage2_if__BRA__0__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__b_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage2_if__BRA__1__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage2_if__BRA__1__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage2_if__BRA__1__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__c_daz = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__d_daz = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_a 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__a_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_a 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__a_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_a 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__a_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_b 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__b_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_b 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__b_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_b 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__b_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_c = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_c = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_c = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_d = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_d = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_d = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__is_nan_any 
        = (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_a)) 
            & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_a)) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_b)) 
              & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_b)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__any_pos_inf 
        = ((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_a)) 
             & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_a))) 
            & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_a)))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_b)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_b))) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_b)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__any_neg_inf 
        = ((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_a)) 
             & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_a)) 
            & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_a)))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_b)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_b)) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_b)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_a;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_r 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_c;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_r 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_c;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_r 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_c;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_n 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_d;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_n 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_d;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_n 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_d;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__x_mant 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_x))) 
            << 0x1aU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_x 
                         << 3U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_y))) 
            << 0x1aU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_y 
                         << 3U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_mx))) 
            << 0x1aU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_mx 
                         << 3U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__exp_nx))) 
            << 0x1aU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__frac_nx 
                         << 3U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sticky_y 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sticky_y))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sticky_m 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sticky_m))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sticky_n 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sticky_n))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_x 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__x_mant;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_y 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__y_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_m 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__m_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_n 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__n_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__csa_s1 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_x 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_y) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_m);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__csa_c1 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_x 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_y) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_y 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_m)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_m 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__csa_s2 
        = (0x3fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__csa_s1 
                           ^ VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__csa_c1, 1U)) 
                          ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_n));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__csa_c2 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__csa_s1 
             & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__csa_c1, 1U)) 
            | (VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__csa_c1, 1U) 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_n)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__op_n 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__adder_s3__DOT__csa_s1));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__a_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__4__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__4__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__4__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__b_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__5__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__5__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__5__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__c_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__6__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__6__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__6__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__d_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__7__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__7__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__7__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_a 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__a_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_a 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__a_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_a 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__a_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_b 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__b_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_b 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__b_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_b 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__b_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_c 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__c_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_c 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__c_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_c 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__c_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_d 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__d_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_d 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__d_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_d 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__d_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_a)) 
              & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_a)) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_b)) 
                & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_b))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_c)) 
               & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_c))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_d)) 
              & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_d)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_a))) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_a)))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_b))) 
                & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_b))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_c))) 
               & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_c))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_d))) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_d)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_a)) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_a)))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_b)) 
                & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_b))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_c)) 
               & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_c))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_d)) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_d)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__x_mant 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x))) 
            << 0x1aU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_x 
                         << 3U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_y))) 
            << 0x1aU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_y 
                         << 3U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_mx))) 
            << 0x1aU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_mx 
                         << 3U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_nx))) 
            << 0x1aU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_nx 
                         << 3U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_y 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_y))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_m 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_m))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_n 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_n))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_x 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__x_mant;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_x 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c1 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_x 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s2 
        = (0x3fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1 
                           ^ VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c1, 1U)) 
                          ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c2 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1 
             & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c1, 1U)) 
            | (VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c1, 1U) 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__a_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__0__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__0__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__0__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__b_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__1__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__1__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__1__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__c_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__2__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__2__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__2__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__d_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__3__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__3__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__stage1_if__BRA__3__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_a 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__a_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_a 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__a_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_a 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__a_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_b 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__b_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_b 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__b_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_b 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__b_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_c 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__c_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_c 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__c_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_c 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__c_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_d 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__d_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_d 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__d_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_d 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__d_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_a)) 
              & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_a)) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_b)) 
                & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_b))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_c)) 
               & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_c))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_d)) 
              & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_d)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_a))) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_a)))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_b))) 
                & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_b))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_c))) 
               & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_c))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_d))) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_d)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_a)) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_a)))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_b)) 
                & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_b))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_c)) 
               & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_c))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_d)) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_d)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__x_mant 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x))) 
            << 0x1aU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_x 
                         << 3U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_y))) 
            << 0x1aU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_y 
                         << 3U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_mx))) 
            << 0x1aU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_mx 
                         << 3U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_mant_base 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_nx))) 
            << 0x1aU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_nx 
                         << 3U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_y 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_y))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_m 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_m))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_n 
        = (0U != (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_mant_base 
                  & (~ VL_SHIFTL_III(27,27,9, (IData)(0x7ffffffU), (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shift)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted 
        = ((0x1bU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shift))
            ? 0U : (0x7ffffffU & VL_SHIFTR_III(32,32,9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shift))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted 
        = ((0x7fffffeU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted) 
           | (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted 
                    | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_n))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_x 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__x_mant;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n 
        = (0x3fffffffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_op)
                           ? (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted)
                           : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_x 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c1 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_x 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s2 
        = (0x3fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1 
                           ^ VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c1, 1U)) 
                          ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c2 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1 
             & VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c1, 1U)) 
            | (VL_SHIFTL_III(30,30,32, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c1, 1U) 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n)) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1));
}
