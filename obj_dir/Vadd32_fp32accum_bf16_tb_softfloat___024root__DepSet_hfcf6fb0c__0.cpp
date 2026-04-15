// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd32_fp32accum_bf16_tb_softfloat.h for the primary calling header

#include "Vadd32_fp32accum_bf16_tb_softfloat__pch.h"
#include "Vadd32_fp32accum_bf16_tb_softfloat__Syms.h"
#include "Vadd32_fp32accum_bf16_tb_softfloat___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd32_fp32accum_bf16_tb_softfloat___024root___dump_triggers__act(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG

void Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_triggers__act(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_triggers__act\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__tb_clk__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst__0)));
    vlSelfRef.__VactTriggered.setBit(2U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__VactTriggered.setBit(3U, ((~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_clk)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__tb_clk__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__tb_clk__0 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst__0 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vadd32_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__0\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*127:0*/ __Vtemp_47;
    VlWide<5>/*159:0*/ __Vtemp_48;
    VlWide<4>/*127:0*/ __Vtemp_50;
    VlWide<4>/*127:0*/ __Vtemp_53;
    VlWide<4>/*127:0*/ __Vtemp_54;
    VlWide<5>/*159:0*/ __Vtemp_55;
    VlWide<4>/*127:0*/ __Vtemp_57;
    VlWide<4>/*127:0*/ __Vtemp_58;
    VlWide<4>/*127:0*/ __Vtemp_60;
    VlWide<4>/*127:0*/ __Vtemp_61;
    VlWide<4>/*127:0*/ __Vtemp_63;
    VlWide<4>/*127:0*/ __Vtemp_64;
    VlWide<4>/*127:0*/ __Vtemp_65;
    VlWide<4>/*127:0*/ __Vtemp_71;
    VlWide<5>/*159:0*/ __Vtemp_72;
    VlWide<4>/*127:0*/ __Vtemp_74;
    VlWide<4>/*127:0*/ __Vtemp_77;
    VlWide<4>/*127:0*/ __Vtemp_78;
    VlWide<5>/*159:0*/ __Vtemp_79;
    VlWide<4>/*127:0*/ __Vtemp_81;
    VlWide<4>/*127:0*/ __Vtemp_82;
    VlWide<4>/*127:0*/ __Vtemp_84;
    VlWide<4>/*127:0*/ __Vtemp_85;
    VlWide<4>/*127:0*/ __Vtemp_87;
    VlWide<4>/*127:0*/ __Vtemp_88;
    VlWide<4>/*127:0*/ __Vtemp_89;
    VlWide<4>/*127:0*/ __Vtemp_95;
    VlWide<5>/*159:0*/ __Vtemp_96;
    VlWide<4>/*127:0*/ __Vtemp_98;
    VlWide<4>/*127:0*/ __Vtemp_101;
    VlWide<4>/*127:0*/ __Vtemp_102;
    VlWide<5>/*159:0*/ __Vtemp_103;
    VlWide<4>/*127:0*/ __Vtemp_105;
    VlWide<4>/*127:0*/ __Vtemp_106;
    VlWide<4>/*127:0*/ __Vtemp_108;
    VlWide<4>/*127:0*/ __Vtemp_109;
    VlWide<4>/*127:0*/ __Vtemp_111;
    VlWide<4>/*127:0*/ __Vtemp_112;
    VlWide<4>/*127:0*/ __Vtemp_113;
    VlWide<4>/*127:0*/ __Vtemp_119;
    VlWide<5>/*159:0*/ __Vtemp_120;
    VlWide<4>/*127:0*/ __Vtemp_122;
    VlWide<4>/*127:0*/ __Vtemp_125;
    VlWide<4>/*127:0*/ __Vtemp_126;
    VlWide<5>/*159:0*/ __Vtemp_127;
    VlWide<4>/*127:0*/ __Vtemp_129;
    VlWide<4>/*127:0*/ __Vtemp_130;
    VlWide<4>/*127:0*/ __Vtemp_132;
    VlWide<4>/*127:0*/ __Vtemp_133;
    VlWide<4>/*127:0*/ __Vtemp_135;
    VlWide<4>/*127:0*/ __Vtemp_136;
    VlWide<4>/*127:0*/ __Vtemp_137;
    VlWide<4>/*127:0*/ __Vtemp_143;
    VlWide<5>/*159:0*/ __Vtemp_144;
    VlWide<4>/*127:0*/ __Vtemp_146;
    VlWide<4>/*127:0*/ __Vtemp_149;
    VlWide<4>/*127:0*/ __Vtemp_150;
    VlWide<5>/*159:0*/ __Vtemp_151;
    VlWide<4>/*127:0*/ __Vtemp_153;
    VlWide<4>/*127:0*/ __Vtemp_154;
    VlWide<4>/*127:0*/ __Vtemp_156;
    VlWide<4>/*127:0*/ __Vtemp_157;
    VlWide<4>/*127:0*/ __Vtemp_159;
    VlWide<4>/*127:0*/ __Vtemp_160;
    VlWide<4>/*127:0*/ __Vtemp_161;
    VlWide<4>/*127:0*/ __Vtemp_167;
    VlWide<5>/*159:0*/ __Vtemp_168;
    VlWide<4>/*127:0*/ __Vtemp_170;
    VlWide<4>/*127:0*/ __Vtemp_173;
    VlWide<4>/*127:0*/ __Vtemp_174;
    VlWide<5>/*159:0*/ __Vtemp_175;
    VlWide<4>/*127:0*/ __Vtemp_177;
    VlWide<4>/*127:0*/ __Vtemp_178;
    VlWide<4>/*127:0*/ __Vtemp_180;
    VlWide<4>/*127:0*/ __Vtemp_181;
    VlWide<4>/*127:0*/ __Vtemp_183;
    VlWide<4>/*127:0*/ __Vtemp_184;
    VlWide<4>/*127:0*/ __Vtemp_185;
    VlWide<4>/*127:0*/ __Vtemp_191;
    VlWide<5>/*159:0*/ __Vtemp_192;
    VlWide<4>/*127:0*/ __Vtemp_194;
    VlWide<4>/*127:0*/ __Vtemp_197;
    VlWide<4>/*127:0*/ __Vtemp_198;
    VlWide<5>/*159:0*/ __Vtemp_199;
    VlWide<4>/*127:0*/ __Vtemp_201;
    VlWide<4>/*127:0*/ __Vtemp_202;
    VlWide<4>/*127:0*/ __Vtemp_204;
    VlWide<4>/*127:0*/ __Vtemp_205;
    VlWide<4>/*127:0*/ __Vtemp_207;
    VlWide<4>/*127:0*/ __Vtemp_208;
    VlWide<4>/*127:0*/ __Vtemp_209;
    VlWide<4>/*127:0*/ __Vtemp_215;
    VlWide<5>/*159:0*/ __Vtemp_216;
    VlWide<4>/*127:0*/ __Vtemp_218;
    VlWide<4>/*127:0*/ __Vtemp_221;
    VlWide<4>/*127:0*/ __Vtemp_222;
    VlWide<5>/*159:0*/ __Vtemp_223;
    VlWide<4>/*127:0*/ __Vtemp_225;
    VlWide<4>/*127:0*/ __Vtemp_226;
    VlWide<4>/*127:0*/ __Vtemp_228;
    VlWide<4>/*127:0*/ __Vtemp_229;
    VlWide<4>/*127:0*/ __Vtemp_231;
    VlWide<4>/*127:0*/ __Vtemp_232;
    VlWide<4>/*127:0*/ __Vtemp_233;
    VlWide<4>/*127:0*/ __Vtemp_239;
    VlWide<5>/*159:0*/ __Vtemp_240;
    VlWide<4>/*127:0*/ __Vtemp_242;
    VlWide<4>/*127:0*/ __Vtemp_245;
    VlWide<4>/*127:0*/ __Vtemp_246;
    VlWide<5>/*159:0*/ __Vtemp_247;
    VlWide<4>/*127:0*/ __Vtemp_249;
    VlWide<4>/*127:0*/ __Vtemp_250;
    VlWide<4>/*127:0*/ __Vtemp_252;
    VlWide<4>/*127:0*/ __Vtemp_253;
    VlWide<4>/*127:0*/ __Vtemp_255;
    VlWide<4>/*127:0*/ __Vtemp_256;
    VlWide<4>/*127:0*/ __Vtemp_257;
    VlWide<4>/*127:0*/ __Vtemp_263;
    VlWide<5>/*159:0*/ __Vtemp_264;
    VlWide<4>/*127:0*/ __Vtemp_266;
    VlWide<4>/*127:0*/ __Vtemp_269;
    VlWide<4>/*127:0*/ __Vtemp_270;
    VlWide<5>/*159:0*/ __Vtemp_271;
    VlWide<4>/*127:0*/ __Vtemp_273;
    VlWide<4>/*127:0*/ __Vtemp_274;
    VlWide<4>/*127:0*/ __Vtemp_276;
    VlWide<4>/*127:0*/ __Vtemp_277;
    VlWide<4>/*127:0*/ __Vtemp_279;
    VlWide<4>/*127:0*/ __Vtemp_280;
    VlWide<4>/*127:0*/ __Vtemp_281;
    VlWide<4>/*127:0*/ __Vtemp_287;
    VlWide<5>/*159:0*/ __Vtemp_288;
    VlWide<4>/*127:0*/ __Vtemp_290;
    VlWide<4>/*127:0*/ __Vtemp_293;
    VlWide<4>/*127:0*/ __Vtemp_294;
    VlWide<5>/*159:0*/ __Vtemp_295;
    VlWide<4>/*127:0*/ __Vtemp_297;
    VlWide<4>/*127:0*/ __Vtemp_298;
    VlWide<4>/*127:0*/ __Vtemp_300;
    VlWide<4>/*127:0*/ __Vtemp_301;
    VlWide<4>/*127:0*/ __Vtemp_303;
    VlWide<4>/*127:0*/ __Vtemp_304;
    VlWide<4>/*127:0*/ __Vtemp_305;
    VlWide<4>/*127:0*/ __Vtemp_312;
    VlWide<4>/*127:0*/ __Vtemp_317;
    VlWide<4>/*127:0*/ __Vtemp_320;
    VlWide<4>/*127:0*/ __Vtemp_325;
    VlWide<4>/*127:0*/ __Vtemp_328;
    VlWide<4>/*127:0*/ __Vtemp_333;
    VlWide<4>/*127:0*/ __Vtemp_336;
    VlWide<4>/*127:0*/ __Vtemp_341;
    VlWide<4>/*127:0*/ __Vtemp_344;
    VlWide<4>/*127:0*/ __Vtemp_349;
    VlWide<4>/*127:0*/ __Vtemp_352;
    VlWide<4>/*127:0*/ __Vtemp_357;
    VlWide<4>/*127:0*/ __Vtemp_360;
    VlWide<4>/*127:0*/ __Vtemp_365;
    VlWide<4>/*127:0*/ __Vtemp_367;
    // Body
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) {
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__result_out;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__mag_sum[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__mag_sum[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__mag_sum[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__mag_sum[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__mag_sum[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__mag_sum[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__mag_sum[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__mag_sum[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__mag_sum[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__mag_sum[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__mag_sum[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__mag_sum[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__mag_sum[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__mag_sum[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__mag_sum[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__mag_sum[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__mag_sum[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__mag_sum[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__mag_sum[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__mag_sum[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__mag_sum[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__mag_sum[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__mag_sum[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__mag_sum[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__mag_sum[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__mag_sum[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__mag_sum[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__mag_sum[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__mag_sum[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__mag_sum[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__mag_sum[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__mag_sum[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__mag_sum[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__mag_sum[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__mag_sum[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__mag_sum[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__mag_sum[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__mag_sum[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__mag_sum[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__mag_sum[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__mag_sum[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__mag_sum[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__mag_sum[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__mag_sum[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_carry_vec[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c2[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_carry_vec[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c2[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_carry_vec[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c2[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_carry_vec[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c2[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_sum_vec[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s2[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_sum_vec[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s2[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_sum_vec[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s2[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_sum_vec[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s2[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_carry_vec[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c2[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_carry_vec[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c2[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_carry_vec[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c2[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_carry_vec[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c2[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_sum_vec[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s2[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_sum_vec[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s2[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_sum_vec[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s2[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_sum_vec[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s2[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_carry_vec[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c2[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_carry_vec[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c2[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_carry_vec[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c2[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_carry_vec[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c2[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_sum_vec[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s2[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_sum_vec[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s2[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_sum_vec[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s2[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_sum_vec[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s2[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_carry_vec[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c2[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_carry_vec[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c2[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_carry_vec[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c2[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_carry_vec[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c2[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_sum_vec[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s2[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_sum_vec[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s2[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_sum_vec[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s2[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_sum_vec[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s2[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_carry_vec[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c2[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_carry_vec[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c2[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_carry_vec[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c2[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_carry_vec[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c2[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_sum_vec[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s2[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_sum_vec[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s2[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_sum_vec[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s2[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_sum_vec[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s2[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_carry_vec[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c2[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_carry_vec[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c2[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_carry_vec[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c2[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_carry_vec[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c2[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_sum_vec[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s2[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_sum_vec[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s2[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_sum_vec[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s2[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_sum_vec[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s2[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_carry_vec[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c2[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_carry_vec[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c2[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_carry_vec[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c2[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_carry_vec[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c2[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_sum_vec[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s2[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_sum_vec[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s2[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_sum_vec[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s2[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_sum_vec[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s2[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_carry_vec[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c2[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_carry_vec[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c2[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_carry_vec[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c2[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_carry_vec[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c2[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_sum_vec[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s2[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_sum_vec[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s2[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_sum_vec[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s2[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_sum_vec[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s2[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_carry_vec[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_c2[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_carry_vec[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_c2[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_carry_vec[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_c2[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_carry_vec[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_c2[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_sum_vec[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s2[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_sum_vec[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s2[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_sum_vec[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s2[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_sum_vec[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s2[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_carry_vec[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c2[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_carry_vec[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c2[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_carry_vec[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c2[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_carry_vec[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c2[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_sum_vec[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s2[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_sum_vec[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s2[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_sum_vec[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s2[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_sum_vec[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s2[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_carry_vec[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c2[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_carry_vec[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c2[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_carry_vec[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c2[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_carry_vec[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c2[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_sum_vec[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s2[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_sum_vec[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s2[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_sum_vec[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s2[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_sum_vec[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s2[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_hot_ones 
            = (3U & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_op) 
                      + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_op)) 
                     + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_op)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_hot_ones 
            = (3U & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_op) 
                      + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_op)) 
                     + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_op)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_hot_ones 
            = (3U & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_op) 
                      + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_op)) 
                     + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_op)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_hot_ones 
            = (3U & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_op) 
                      + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_op)) 
                     + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_op)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_hot_ones 
            = (3U & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_op) 
                      + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_op)) 
                     + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_op)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_hot_ones 
            = (3U & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_op) 
                      + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_op)) 
                     + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_op)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_hot_ones 
            = (3U & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_op) 
                      + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_op)) 
                     + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_op)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_hot_ones 
            = (3U & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_op) 
                      + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_op)) 
                     + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_op)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_hot_ones 
            = (3U & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_op) 
                      + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_op)) 
                     + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_op)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_hot_ones 
            = (3U & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_op) 
                      + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_op)) 
                     + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_op)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_hot_ones 
            = (3U & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_op) 
                      + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_op)) 
                     + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_op)));
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_exp_base 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_a_e;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_spec_res 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_exp_base 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_a_e;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_spec_res 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_exp_base 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_a_e;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_spec_res 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_exp_base 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_a_e;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_spec_res 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_exp_base 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_a_e;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_spec_res 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_exp_base 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_a_e;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_spec_res 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_exp_base 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_a_e;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_spec_res 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_exp_base 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_a_e;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_spec_res 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_exp_base 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_a_e;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_spec_res 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_exp_base 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_a_e;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_spec_res 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_exp_base 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_a_e;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_spec_res 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_a_e 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_special_result 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_a_e 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_special_result 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_a_e 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_special_result 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_a_e 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_special_result 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_a_e 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_special_result 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_a_e 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_special_result 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_a_e 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_special_result 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_a_e 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_special_result 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_a_e 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_x;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_special_result 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_a_e 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_special_result 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_result;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_a_e 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_special_result 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_result;
    } else {
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_carry_vec[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_carry_vec[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_carry_vec[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_carry_vec[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_sum_vec[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_sum_vec[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_sum_vec[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_sum_vec[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_carry_vec[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_carry_vec[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_carry_vec[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_carry_vec[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_sum_vec[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_sum_vec[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_sum_vec[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_sum_vec[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_carry_vec[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_carry_vec[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_carry_vec[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_carry_vec[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_sum_vec[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_sum_vec[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_sum_vec[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_sum_vec[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_carry_vec[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_carry_vec[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_carry_vec[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_carry_vec[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_sum_vec[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_sum_vec[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_sum_vec[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_sum_vec[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_carry_vec[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_carry_vec[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_carry_vec[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_carry_vec[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_sum_vec[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_sum_vec[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_sum_vec[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_sum_vec[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_carry_vec[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_carry_vec[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_carry_vec[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_carry_vec[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_sum_vec[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_sum_vec[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_sum_vec[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_sum_vec[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_carry_vec[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_carry_vec[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_carry_vec[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_carry_vec[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_sum_vec[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_sum_vec[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_sum_vec[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_sum_vec[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_carry_vec[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_carry_vec[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_carry_vec[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_carry_vec[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_sum_vec[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_sum_vec[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_sum_vec[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_sum_vec[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_carry_vec[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_carry_vec[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_carry_vec[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_carry_vec[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_sum_vec[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_sum_vec[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_sum_vec[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_sum_vec[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_carry_vec[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_carry_vec[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_carry_vec[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_carry_vec[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_sum_vec[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_sum_vec[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_sum_vec[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_sum_vec[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_carry_vec[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_carry_vec[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_carry_vec[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_carry_vec[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_sum_vec[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_sum_vec[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_sum_vec[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_sum_vec[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_hot_ones = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_hot_ones = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_hot_ones = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_hot_ones = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_hot_ones = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_hot_ones = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_hot_ones = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_hot_ones = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_hot_ones = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_hot_ones = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_hot_ones = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_exp_base = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_spec_res = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_exp_base = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_spec_res = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_exp_base = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_spec_res = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_exp_base = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_spec_res = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_exp_base = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_spec_res = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_exp_base = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_spec_res = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_exp_base = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_spec_res = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_exp_base = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_spec_res = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_exp_base = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_spec_res = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_exp_base = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_spec_res = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_exp_base = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_spec_res = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_a_e = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_special_result = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_a_e = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_special_result = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_a_e = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_special_result = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_a_e = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_special_result = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_a_e = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_special_result = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_a_e = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_special_result = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_a_e = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_special_result = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_a_e = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_special_result = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_a_e = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_special_result = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_a_e = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_special_result = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_a_e = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_special_result = 0U;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__res_sign));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__res_sign));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__res_sign));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__res_sign));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__res_sign));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__res_sign));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__res_sign));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__res_sign));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__res_sign));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__res_sign));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_res_sign 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__res_sign));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_a_s 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_a_s 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_a_s 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_a_s 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_a_s 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_a_s 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_a_s 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_a_s 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_a_s 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_a_s 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_a_s 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_x));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_special 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_special 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_special 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_special 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_special 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_special 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_special 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_special 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_special 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_special 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_special 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_align_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_align_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_align_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_align_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_align_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_align_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_align_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_align_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_align_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_align_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_align_sticky));
    if ((0U != (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag[0U] 
                  | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag[1U]) 
                 | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag[2U]) 
                | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag[3U]))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
                  | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag[1U]) 
                 | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag[2U]) 
                | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag[3U]))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
                  | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag[1U]) 
                 | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag[2U]) 
                | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag[3U]))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
                  | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag[1U]) 
                 | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag[2U]) 
                | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag[3U]))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
                  | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag[1U]) 
                 | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag[2U]) 
                | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag[3U]))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
                  | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag[1U]) 
                 | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag[2U]) 
                | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag[3U]))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
                  | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag[1U]) 
                 | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag[2U]) 
                | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag[3U]))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
                  | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag[1U]) 
                 | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag[2U]) 
                | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag[3U]))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
                  | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag[1U]) 
                 | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag[2U]) 
                | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag[3U]))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag[0U] 
                  | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag[1U]) 
                 | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag[2U]) 
                | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag[3U]))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    if ((0U != (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag[0U] 
                  | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag[1U]) 
                 | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag[2U]) 
                | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag[3U]))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__stage3_logic__DOT__unnamedblk1__DOT__i = 0xffffffffU;
    }
    __Vtemp_47[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_sum_vec[0U];
    __Vtemp_47[1U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_sum_vec[1U];
    __Vtemp_47[2U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_sum_vec[2U];
    __Vtemp_47[3U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_sum_vec[3U];
    VL_EXTENDS_WW(129,128, __Vtemp_48, __Vtemp_47);
    __Vtemp_50[0U] = __Vtemp_48[0U];
    __Vtemp_50[1U] = __Vtemp_48[1U];
    __Vtemp_50[2U] = __Vtemp_48[2U];
    __Vtemp_50[3U] = __Vtemp_48[3U];
    VL_SHIFTL_WWI(127,127,32, __Vtemp_53, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U);
    __Vtemp_54[0U] = __Vtemp_53[0U];
    __Vtemp_54[1U] = __Vtemp_53[1U];
    __Vtemp_54[2U] = __Vtemp_53[2U];
    __Vtemp_54[3U] = (0x7fffffffU & __Vtemp_53[3U]);
    VL_EXTENDS_WW(129,127, __Vtemp_55, __Vtemp_54);
    __Vtemp_57[0U] = __Vtemp_55[0U];
    __Vtemp_57[1U] = __Vtemp_55[1U];
    __Vtemp_57[2U] = __Vtemp_55[2U];
    __Vtemp_57[3U] = __Vtemp_55[3U];
    VL_ADD_W(4, __Vtemp_58, __Vtemp_50, __Vtemp_57);
    __Vtemp_60[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_hot_ones;
    __Vtemp_60[1U] = 0U;
    __Vtemp_60[2U] = 0U;
    __Vtemp_60[3U] = 0U;
    VL_ADD_W(4, __Vtemp_61, __Vtemp_58, __Vtemp_60);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum[0U] 
        = __Vtemp_61[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum[1U] 
        = __Vtemp_61[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum[2U] 
        = __Vtemp_61[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum[3U] 
        = (0x7fffffffU & __Vtemp_61[3U]);
    if ((0x40000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum[3U])) {
        __Vtemp_63[0U] = 1U;
        __Vtemp_63[1U] = 0U;
        __Vtemp_63[2U] = 0U;
        __Vtemp_63[3U] = 0U;
        __Vtemp_64[0U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum[0U]);
        __Vtemp_64[1U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum[1U]);
        __Vtemp_64[2U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum[2U]);
        __Vtemp_64[3U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum[3U]);
        VL_ADD_W(4, __Vtemp_65, __Vtemp_63, __Vtemp_64);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__mag_sum[0U] 
            = __Vtemp_65[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__mag_sum[1U] 
            = __Vtemp_65[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__mag_sum[2U] 
            = __Vtemp_65[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__mag_sum[3U] 
            = (0x7fffffffU & __Vtemp_65[3U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__mag_sum[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__mag_sum[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__mag_sum[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__mag_sum[3U] 
            = (0x3fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum[3U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_a_s;
    }
    __Vtemp_71[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_sum_vec[0U];
    __Vtemp_71[1U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_sum_vec[1U];
    __Vtemp_71[2U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_sum_vec[2U];
    __Vtemp_71[3U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_sum_vec[3U];
    VL_EXTENDS_WW(129,128, __Vtemp_72, __Vtemp_71);
    __Vtemp_74[0U] = __Vtemp_72[0U];
    __Vtemp_74[1U] = __Vtemp_72[1U];
    __Vtemp_74[2U] = __Vtemp_72[2U];
    __Vtemp_74[3U] = __Vtemp_72[3U];
    VL_SHIFTL_WWI(127,127,32, __Vtemp_77, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U);
    __Vtemp_78[0U] = __Vtemp_77[0U];
    __Vtemp_78[1U] = __Vtemp_77[1U];
    __Vtemp_78[2U] = __Vtemp_77[2U];
    __Vtemp_78[3U] = (0x7fffffffU & __Vtemp_77[3U]);
    VL_EXTENDS_WW(129,127, __Vtemp_79, __Vtemp_78);
    __Vtemp_81[0U] = __Vtemp_79[0U];
    __Vtemp_81[1U] = __Vtemp_79[1U];
    __Vtemp_81[2U] = __Vtemp_79[2U];
    __Vtemp_81[3U] = __Vtemp_79[3U];
    VL_ADD_W(4, __Vtemp_82, __Vtemp_74, __Vtemp_81);
    __Vtemp_84[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_hot_ones;
    __Vtemp_84[1U] = 0U;
    __Vtemp_84[2U] = 0U;
    __Vtemp_84[3U] = 0U;
    VL_ADD_W(4, __Vtemp_85, __Vtemp_82, __Vtemp_84);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum[0U] 
        = __Vtemp_85[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum[1U] 
        = __Vtemp_85[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum[2U] 
        = __Vtemp_85[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum[3U] 
        = (0x7fffffffU & __Vtemp_85[3U]);
    if ((0x40000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum[3U])) {
        __Vtemp_87[0U] = 1U;
        __Vtemp_87[1U] = 0U;
        __Vtemp_87[2U] = 0U;
        __Vtemp_87[3U] = 0U;
        __Vtemp_88[0U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum[0U]);
        __Vtemp_88[1U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum[1U]);
        __Vtemp_88[2U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum[2U]);
        __Vtemp_88[3U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum[3U]);
        VL_ADD_W(4, __Vtemp_89, __Vtemp_87, __Vtemp_88);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__mag_sum[0U] 
            = __Vtemp_89[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__mag_sum[1U] 
            = __Vtemp_89[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__mag_sum[2U] 
            = __Vtemp_89[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__mag_sum[3U] 
            = (0x7fffffffU & __Vtemp_89[3U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__mag_sum[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__mag_sum[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__mag_sum[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__mag_sum[3U] 
            = (0x3fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum[3U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_a_s;
    }
    __Vtemp_95[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_sum_vec[0U];
    __Vtemp_95[1U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_sum_vec[1U];
    __Vtemp_95[2U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_sum_vec[2U];
    __Vtemp_95[3U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_sum_vec[3U];
    VL_EXTENDS_WW(129,128, __Vtemp_96, __Vtemp_95);
    __Vtemp_98[0U] = __Vtemp_96[0U];
    __Vtemp_98[1U] = __Vtemp_96[1U];
    __Vtemp_98[2U] = __Vtemp_96[2U];
    __Vtemp_98[3U] = __Vtemp_96[3U];
    VL_SHIFTL_WWI(127,127,32, __Vtemp_101, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U);
    __Vtemp_102[0U] = __Vtemp_101[0U];
    __Vtemp_102[1U] = __Vtemp_101[1U];
    __Vtemp_102[2U] = __Vtemp_101[2U];
    __Vtemp_102[3U] = (0x7fffffffU & __Vtemp_101[3U]);
    VL_EXTENDS_WW(129,127, __Vtemp_103, __Vtemp_102);
    __Vtemp_105[0U] = __Vtemp_103[0U];
    __Vtemp_105[1U] = __Vtemp_103[1U];
    __Vtemp_105[2U] = __Vtemp_103[2U];
    __Vtemp_105[3U] = __Vtemp_103[3U];
    VL_ADD_W(4, __Vtemp_106, __Vtemp_98, __Vtemp_105);
    __Vtemp_108[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_hot_ones;
    __Vtemp_108[1U] = 0U;
    __Vtemp_108[2U] = 0U;
    __Vtemp_108[3U] = 0U;
    VL_ADD_W(4, __Vtemp_109, __Vtemp_106, __Vtemp_108);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum[0U] 
        = __Vtemp_109[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum[1U] 
        = __Vtemp_109[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum[2U] 
        = __Vtemp_109[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum[3U] 
        = (0x7fffffffU & __Vtemp_109[3U]);
    if ((0x40000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum[3U])) {
        __Vtemp_111[0U] = 1U;
        __Vtemp_111[1U] = 0U;
        __Vtemp_111[2U] = 0U;
        __Vtemp_111[3U] = 0U;
        __Vtemp_112[0U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum[0U]);
        __Vtemp_112[1U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum[1U]);
        __Vtemp_112[2U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum[2U]);
        __Vtemp_112[3U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum[3U]);
        VL_ADD_W(4, __Vtemp_113, __Vtemp_111, __Vtemp_112);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__mag_sum[0U] 
            = __Vtemp_113[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__mag_sum[1U] 
            = __Vtemp_113[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__mag_sum[2U] 
            = __Vtemp_113[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__mag_sum[3U] 
            = (0x7fffffffU & __Vtemp_113[3U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__mag_sum[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__mag_sum[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__mag_sum[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__mag_sum[3U] 
            = (0x3fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum[3U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_a_s;
    }
    __Vtemp_119[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_sum_vec[0U];
    __Vtemp_119[1U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_sum_vec[1U];
    __Vtemp_119[2U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_sum_vec[2U];
    __Vtemp_119[3U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_sum_vec[3U];
    VL_EXTENDS_WW(129,128, __Vtemp_120, __Vtemp_119);
    __Vtemp_122[0U] = __Vtemp_120[0U];
    __Vtemp_122[1U] = __Vtemp_120[1U];
    __Vtemp_122[2U] = __Vtemp_120[2U];
    __Vtemp_122[3U] = __Vtemp_120[3U];
    VL_SHIFTL_WWI(127,127,32, __Vtemp_125, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U);
    __Vtemp_126[0U] = __Vtemp_125[0U];
    __Vtemp_126[1U] = __Vtemp_125[1U];
    __Vtemp_126[2U] = __Vtemp_125[2U];
    __Vtemp_126[3U] = (0x7fffffffU & __Vtemp_125[3U]);
    VL_EXTENDS_WW(129,127, __Vtemp_127, __Vtemp_126);
    __Vtemp_129[0U] = __Vtemp_127[0U];
    __Vtemp_129[1U] = __Vtemp_127[1U];
    __Vtemp_129[2U] = __Vtemp_127[2U];
    __Vtemp_129[3U] = __Vtemp_127[3U];
    VL_ADD_W(4, __Vtemp_130, __Vtemp_122, __Vtemp_129);
    __Vtemp_132[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_hot_ones;
    __Vtemp_132[1U] = 0U;
    __Vtemp_132[2U] = 0U;
    __Vtemp_132[3U] = 0U;
    VL_ADD_W(4, __Vtemp_133, __Vtemp_130, __Vtemp_132);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum[0U] 
        = __Vtemp_133[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum[1U] 
        = __Vtemp_133[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum[2U] 
        = __Vtemp_133[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum[3U] 
        = (0x7fffffffU & __Vtemp_133[3U]);
    if ((0x40000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum[3U])) {
        __Vtemp_135[0U] = 1U;
        __Vtemp_135[1U] = 0U;
        __Vtemp_135[2U] = 0U;
        __Vtemp_135[3U] = 0U;
        __Vtemp_136[0U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum[0U]);
        __Vtemp_136[1U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum[1U]);
        __Vtemp_136[2U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum[2U]);
        __Vtemp_136[3U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum[3U]);
        VL_ADD_W(4, __Vtemp_137, __Vtemp_135, __Vtemp_136);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__mag_sum[0U] 
            = __Vtemp_137[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__mag_sum[1U] 
            = __Vtemp_137[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__mag_sum[2U] 
            = __Vtemp_137[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__mag_sum[3U] 
            = (0x7fffffffU & __Vtemp_137[3U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__mag_sum[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__mag_sum[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__mag_sum[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__mag_sum[3U] 
            = (0x3fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum[3U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_a_s;
    }
    __Vtemp_143[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_sum_vec[0U];
    __Vtemp_143[1U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_sum_vec[1U];
    __Vtemp_143[2U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_sum_vec[2U];
    __Vtemp_143[3U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_sum_vec[3U];
    VL_EXTENDS_WW(129,128, __Vtemp_144, __Vtemp_143);
    __Vtemp_146[0U] = __Vtemp_144[0U];
    __Vtemp_146[1U] = __Vtemp_144[1U];
    __Vtemp_146[2U] = __Vtemp_144[2U];
    __Vtemp_146[3U] = __Vtemp_144[3U];
    VL_SHIFTL_WWI(127,127,32, __Vtemp_149, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U);
    __Vtemp_150[0U] = __Vtemp_149[0U];
    __Vtemp_150[1U] = __Vtemp_149[1U];
    __Vtemp_150[2U] = __Vtemp_149[2U];
    __Vtemp_150[3U] = (0x7fffffffU & __Vtemp_149[3U]);
    VL_EXTENDS_WW(129,127, __Vtemp_151, __Vtemp_150);
    __Vtemp_153[0U] = __Vtemp_151[0U];
    __Vtemp_153[1U] = __Vtemp_151[1U];
    __Vtemp_153[2U] = __Vtemp_151[2U];
    __Vtemp_153[3U] = __Vtemp_151[3U];
    VL_ADD_W(4, __Vtemp_154, __Vtemp_146, __Vtemp_153);
    __Vtemp_156[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_hot_ones;
    __Vtemp_156[1U] = 0U;
    __Vtemp_156[2U] = 0U;
    __Vtemp_156[3U] = 0U;
    VL_ADD_W(4, __Vtemp_157, __Vtemp_154, __Vtemp_156);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum[0U] 
        = __Vtemp_157[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum[1U] 
        = __Vtemp_157[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum[2U] 
        = __Vtemp_157[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum[3U] 
        = (0x7fffffffU & __Vtemp_157[3U]);
    if ((0x40000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum[3U])) {
        __Vtemp_159[0U] = 1U;
        __Vtemp_159[1U] = 0U;
        __Vtemp_159[2U] = 0U;
        __Vtemp_159[3U] = 0U;
        __Vtemp_160[0U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum[0U]);
        __Vtemp_160[1U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum[1U]);
        __Vtemp_160[2U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum[2U]);
        __Vtemp_160[3U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum[3U]);
        VL_ADD_W(4, __Vtemp_161, __Vtemp_159, __Vtemp_160);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__mag_sum[0U] 
            = __Vtemp_161[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__mag_sum[1U] 
            = __Vtemp_161[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__mag_sum[2U] 
            = __Vtemp_161[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__mag_sum[3U] 
            = (0x7fffffffU & __Vtemp_161[3U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__mag_sum[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__mag_sum[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__mag_sum[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__mag_sum[3U] 
            = (0x3fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum[3U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_a_s;
    }
    __Vtemp_167[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_sum_vec[0U];
    __Vtemp_167[1U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_sum_vec[1U];
    __Vtemp_167[2U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_sum_vec[2U];
    __Vtemp_167[3U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_sum_vec[3U];
    VL_EXTENDS_WW(129,128, __Vtemp_168, __Vtemp_167);
    __Vtemp_170[0U] = __Vtemp_168[0U];
    __Vtemp_170[1U] = __Vtemp_168[1U];
    __Vtemp_170[2U] = __Vtemp_168[2U];
    __Vtemp_170[3U] = __Vtemp_168[3U];
    VL_SHIFTL_WWI(127,127,32, __Vtemp_173, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U);
    __Vtemp_174[0U] = __Vtemp_173[0U];
    __Vtemp_174[1U] = __Vtemp_173[1U];
    __Vtemp_174[2U] = __Vtemp_173[2U];
    __Vtemp_174[3U] = (0x7fffffffU & __Vtemp_173[3U]);
    VL_EXTENDS_WW(129,127, __Vtemp_175, __Vtemp_174);
    __Vtemp_177[0U] = __Vtemp_175[0U];
    __Vtemp_177[1U] = __Vtemp_175[1U];
    __Vtemp_177[2U] = __Vtemp_175[2U];
    __Vtemp_177[3U] = __Vtemp_175[3U];
    VL_ADD_W(4, __Vtemp_178, __Vtemp_170, __Vtemp_177);
    __Vtemp_180[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_hot_ones;
    __Vtemp_180[1U] = 0U;
    __Vtemp_180[2U] = 0U;
    __Vtemp_180[3U] = 0U;
    VL_ADD_W(4, __Vtemp_181, __Vtemp_178, __Vtemp_180);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum[0U] 
        = __Vtemp_181[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum[1U] 
        = __Vtemp_181[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum[2U] 
        = __Vtemp_181[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum[3U] 
        = (0x7fffffffU & __Vtemp_181[3U]);
    if ((0x40000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum[3U])) {
        __Vtemp_183[0U] = 1U;
        __Vtemp_183[1U] = 0U;
        __Vtemp_183[2U] = 0U;
        __Vtemp_183[3U] = 0U;
        __Vtemp_184[0U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum[0U]);
        __Vtemp_184[1U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum[1U]);
        __Vtemp_184[2U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum[2U]);
        __Vtemp_184[3U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum[3U]);
        VL_ADD_W(4, __Vtemp_185, __Vtemp_183, __Vtemp_184);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__mag_sum[0U] 
            = __Vtemp_185[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__mag_sum[1U] 
            = __Vtemp_185[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__mag_sum[2U] 
            = __Vtemp_185[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__mag_sum[3U] 
            = (0x7fffffffU & __Vtemp_185[3U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__mag_sum[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__mag_sum[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__mag_sum[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__mag_sum[3U] 
            = (0x3fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum[3U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_a_s;
    }
    __Vtemp_191[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_sum_vec[0U];
    __Vtemp_191[1U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_sum_vec[1U];
    __Vtemp_191[2U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_sum_vec[2U];
    __Vtemp_191[3U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_sum_vec[3U];
    VL_EXTENDS_WW(129,128, __Vtemp_192, __Vtemp_191);
    __Vtemp_194[0U] = __Vtemp_192[0U];
    __Vtemp_194[1U] = __Vtemp_192[1U];
    __Vtemp_194[2U] = __Vtemp_192[2U];
    __Vtemp_194[3U] = __Vtemp_192[3U];
    VL_SHIFTL_WWI(127,127,32, __Vtemp_197, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U);
    __Vtemp_198[0U] = __Vtemp_197[0U];
    __Vtemp_198[1U] = __Vtemp_197[1U];
    __Vtemp_198[2U] = __Vtemp_197[2U];
    __Vtemp_198[3U] = (0x7fffffffU & __Vtemp_197[3U]);
    VL_EXTENDS_WW(129,127, __Vtemp_199, __Vtemp_198);
    __Vtemp_201[0U] = __Vtemp_199[0U];
    __Vtemp_201[1U] = __Vtemp_199[1U];
    __Vtemp_201[2U] = __Vtemp_199[2U];
    __Vtemp_201[3U] = __Vtemp_199[3U];
    VL_ADD_W(4, __Vtemp_202, __Vtemp_194, __Vtemp_201);
    __Vtemp_204[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_hot_ones;
    __Vtemp_204[1U] = 0U;
    __Vtemp_204[2U] = 0U;
    __Vtemp_204[3U] = 0U;
    VL_ADD_W(4, __Vtemp_205, __Vtemp_202, __Vtemp_204);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum[0U] 
        = __Vtemp_205[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum[1U] 
        = __Vtemp_205[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum[2U] 
        = __Vtemp_205[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum[3U] 
        = (0x7fffffffU & __Vtemp_205[3U]);
    if ((0x40000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum[3U])) {
        __Vtemp_207[0U] = 1U;
        __Vtemp_207[1U] = 0U;
        __Vtemp_207[2U] = 0U;
        __Vtemp_207[3U] = 0U;
        __Vtemp_208[0U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum[0U]);
        __Vtemp_208[1U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum[1U]);
        __Vtemp_208[2U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum[2U]);
        __Vtemp_208[3U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum[3U]);
        VL_ADD_W(4, __Vtemp_209, __Vtemp_207, __Vtemp_208);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__mag_sum[0U] 
            = __Vtemp_209[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__mag_sum[1U] 
            = __Vtemp_209[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__mag_sum[2U] 
            = __Vtemp_209[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__mag_sum[3U] 
            = (0x7fffffffU & __Vtemp_209[3U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__mag_sum[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__mag_sum[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__mag_sum[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__mag_sum[3U] 
            = (0x3fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum[3U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_a_s;
    }
    __Vtemp_215[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_sum_vec[0U];
    __Vtemp_215[1U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_sum_vec[1U];
    __Vtemp_215[2U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_sum_vec[2U];
    __Vtemp_215[3U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_sum_vec[3U];
    VL_EXTENDS_WW(129,128, __Vtemp_216, __Vtemp_215);
    __Vtemp_218[0U] = __Vtemp_216[0U];
    __Vtemp_218[1U] = __Vtemp_216[1U];
    __Vtemp_218[2U] = __Vtemp_216[2U];
    __Vtemp_218[3U] = __Vtemp_216[3U];
    VL_SHIFTL_WWI(127,127,32, __Vtemp_221, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U);
    __Vtemp_222[0U] = __Vtemp_221[0U];
    __Vtemp_222[1U] = __Vtemp_221[1U];
    __Vtemp_222[2U] = __Vtemp_221[2U];
    __Vtemp_222[3U] = (0x7fffffffU & __Vtemp_221[3U]);
    VL_EXTENDS_WW(129,127, __Vtemp_223, __Vtemp_222);
    __Vtemp_225[0U] = __Vtemp_223[0U];
    __Vtemp_225[1U] = __Vtemp_223[1U];
    __Vtemp_225[2U] = __Vtemp_223[2U];
    __Vtemp_225[3U] = __Vtemp_223[3U];
    VL_ADD_W(4, __Vtemp_226, __Vtemp_218, __Vtemp_225);
    __Vtemp_228[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_hot_ones;
    __Vtemp_228[1U] = 0U;
    __Vtemp_228[2U] = 0U;
    __Vtemp_228[3U] = 0U;
    VL_ADD_W(4, __Vtemp_229, __Vtemp_226, __Vtemp_228);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum[0U] 
        = __Vtemp_229[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum[1U] 
        = __Vtemp_229[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum[2U] 
        = __Vtemp_229[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum[3U] 
        = (0x7fffffffU & __Vtemp_229[3U]);
    if ((0x40000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum[3U])) {
        __Vtemp_231[0U] = 1U;
        __Vtemp_231[1U] = 0U;
        __Vtemp_231[2U] = 0U;
        __Vtemp_231[3U] = 0U;
        __Vtemp_232[0U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum[0U]);
        __Vtemp_232[1U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum[1U]);
        __Vtemp_232[2U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum[2U]);
        __Vtemp_232[3U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum[3U]);
        VL_ADD_W(4, __Vtemp_233, __Vtemp_231, __Vtemp_232);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__mag_sum[0U] 
            = __Vtemp_233[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__mag_sum[1U] 
            = __Vtemp_233[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__mag_sum[2U] 
            = __Vtemp_233[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__mag_sum[3U] 
            = (0x7fffffffU & __Vtemp_233[3U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__mag_sum[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__mag_sum[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__mag_sum[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__mag_sum[3U] 
            = (0x3fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum[3U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_a_s;
    }
    __Vtemp_239[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_sum_vec[0U];
    __Vtemp_239[1U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_sum_vec[1U];
    __Vtemp_239[2U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_sum_vec[2U];
    __Vtemp_239[3U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_sum_vec[3U];
    VL_EXTENDS_WW(129,128, __Vtemp_240, __Vtemp_239);
    __Vtemp_242[0U] = __Vtemp_240[0U];
    __Vtemp_242[1U] = __Vtemp_240[1U];
    __Vtemp_242[2U] = __Vtemp_240[2U];
    __Vtemp_242[3U] = __Vtemp_240[3U];
    VL_SHIFTL_WWI(127,127,32, __Vtemp_245, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_carry_vec, 1U);
    __Vtemp_246[0U] = __Vtemp_245[0U];
    __Vtemp_246[1U] = __Vtemp_245[1U];
    __Vtemp_246[2U] = __Vtemp_245[2U];
    __Vtemp_246[3U] = (0x7fffffffU & __Vtemp_245[3U]);
    VL_EXTENDS_WW(129,127, __Vtemp_247, __Vtemp_246);
    __Vtemp_249[0U] = __Vtemp_247[0U];
    __Vtemp_249[1U] = __Vtemp_247[1U];
    __Vtemp_249[2U] = __Vtemp_247[2U];
    __Vtemp_249[3U] = __Vtemp_247[3U];
    VL_ADD_W(4, __Vtemp_250, __Vtemp_242, __Vtemp_249);
    __Vtemp_252[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_hot_ones;
    __Vtemp_252[1U] = 0U;
    __Vtemp_252[2U] = 0U;
    __Vtemp_252[3U] = 0U;
    VL_ADD_W(4, __Vtemp_253, __Vtemp_250, __Vtemp_252);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__raw_sum[0U] 
        = __Vtemp_253[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__raw_sum[1U] 
        = __Vtemp_253[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__raw_sum[2U] 
        = __Vtemp_253[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__raw_sum[3U] 
        = (0x7fffffffU & __Vtemp_253[3U]);
    if ((0x40000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__raw_sum[3U])) {
        __Vtemp_255[0U] = 1U;
        __Vtemp_255[1U] = 0U;
        __Vtemp_255[2U] = 0U;
        __Vtemp_255[3U] = 0U;
        __Vtemp_256[0U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__raw_sum[0U]);
        __Vtemp_256[1U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__raw_sum[1U]);
        __Vtemp_256[2U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__raw_sum[2U]);
        __Vtemp_256[3U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__raw_sum[3U]);
        VL_ADD_W(4, __Vtemp_257, __Vtemp_255, __Vtemp_256);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__mag_sum[0U] 
            = __Vtemp_257[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__mag_sum[1U] 
            = __Vtemp_257[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__mag_sum[2U] 
            = __Vtemp_257[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__mag_sum[3U] 
            = (0x7fffffffU & __Vtemp_257[3U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__mag_sum[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__raw_sum[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__mag_sum[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__raw_sum[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__mag_sum[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__raw_sum[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__mag_sum[3U] 
            = (0x3fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__raw_sum[3U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_a_s;
    }
    __Vtemp_263[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_sum_vec[0U];
    __Vtemp_263[1U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_sum_vec[1U];
    __Vtemp_263[2U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_sum_vec[2U];
    __Vtemp_263[3U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_sum_vec[3U];
    VL_EXTENDS_WW(129,128, __Vtemp_264, __Vtemp_263);
    __Vtemp_266[0U] = __Vtemp_264[0U];
    __Vtemp_266[1U] = __Vtemp_264[1U];
    __Vtemp_266[2U] = __Vtemp_264[2U];
    __Vtemp_266[3U] = __Vtemp_264[3U];
    VL_SHIFTL_WWI(127,127,32, __Vtemp_269, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_carry_vec, 1U);
    __Vtemp_270[0U] = __Vtemp_269[0U];
    __Vtemp_270[1U] = __Vtemp_269[1U];
    __Vtemp_270[2U] = __Vtemp_269[2U];
    __Vtemp_270[3U] = (0x7fffffffU & __Vtemp_269[3U]);
    VL_EXTENDS_WW(129,127, __Vtemp_271, __Vtemp_270);
    __Vtemp_273[0U] = __Vtemp_271[0U];
    __Vtemp_273[1U] = __Vtemp_271[1U];
    __Vtemp_273[2U] = __Vtemp_271[2U];
    __Vtemp_273[3U] = __Vtemp_271[3U];
    VL_ADD_W(4, __Vtemp_274, __Vtemp_266, __Vtemp_273);
    __Vtemp_276[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_hot_ones;
    __Vtemp_276[1U] = 0U;
    __Vtemp_276[2U] = 0U;
    __Vtemp_276[3U] = 0U;
    VL_ADD_W(4, __Vtemp_277, __Vtemp_274, __Vtemp_276);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum[0U] 
        = __Vtemp_277[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum[1U] 
        = __Vtemp_277[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum[2U] 
        = __Vtemp_277[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum[3U] 
        = (0x7fffffffU & __Vtemp_277[3U]);
    if ((0x40000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum[3U])) {
        __Vtemp_279[0U] = 1U;
        __Vtemp_279[1U] = 0U;
        __Vtemp_279[2U] = 0U;
        __Vtemp_279[3U] = 0U;
        __Vtemp_280[0U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum[0U]);
        __Vtemp_280[1U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum[1U]);
        __Vtemp_280[2U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum[2U]);
        __Vtemp_280[3U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum[3U]);
        VL_ADD_W(4, __Vtemp_281, __Vtemp_279, __Vtemp_280);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__mag_sum[0U] 
            = __Vtemp_281[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__mag_sum[1U] 
            = __Vtemp_281[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__mag_sum[2U] 
            = __Vtemp_281[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__mag_sum[3U] 
            = (0x7fffffffU & __Vtemp_281[3U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__mag_sum[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__mag_sum[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__mag_sum[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__mag_sum[3U] 
            = (0x3fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum[3U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_a_s;
    }
    __Vtemp_287[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_sum_vec[0U];
    __Vtemp_287[1U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_sum_vec[1U];
    __Vtemp_287[2U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_sum_vec[2U];
    __Vtemp_287[3U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_sum_vec[3U];
    VL_EXTENDS_WW(129,128, __Vtemp_288, __Vtemp_287);
    __Vtemp_290[0U] = __Vtemp_288[0U];
    __Vtemp_290[1U] = __Vtemp_288[1U];
    __Vtemp_290[2U] = __Vtemp_288[2U];
    __Vtemp_290[3U] = __Vtemp_288[3U];
    VL_SHIFTL_WWI(127,127,32, __Vtemp_293, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_carry_vec, 1U);
    __Vtemp_294[0U] = __Vtemp_293[0U];
    __Vtemp_294[1U] = __Vtemp_293[1U];
    __Vtemp_294[2U] = __Vtemp_293[2U];
    __Vtemp_294[3U] = (0x7fffffffU & __Vtemp_293[3U]);
    VL_EXTENDS_WW(129,127, __Vtemp_295, __Vtemp_294);
    __Vtemp_297[0U] = __Vtemp_295[0U];
    __Vtemp_297[1U] = __Vtemp_295[1U];
    __Vtemp_297[2U] = __Vtemp_295[2U];
    __Vtemp_297[3U] = __Vtemp_295[3U];
    VL_ADD_W(4, __Vtemp_298, __Vtemp_290, __Vtemp_297);
    __Vtemp_300[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_hot_ones;
    __Vtemp_300[1U] = 0U;
    __Vtemp_300[2U] = 0U;
    __Vtemp_300[3U] = 0U;
    VL_ADD_W(4, __Vtemp_301, __Vtemp_298, __Vtemp_300);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum[0U] 
        = __Vtemp_301[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum[1U] 
        = __Vtemp_301[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum[2U] 
        = __Vtemp_301[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum[3U] 
        = (0x7fffffffU & __Vtemp_301[3U]);
    if ((0x40000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum[3U])) {
        __Vtemp_303[0U] = 1U;
        __Vtemp_303[1U] = 0U;
        __Vtemp_303[2U] = 0U;
        __Vtemp_303[3U] = 0U;
        __Vtemp_304[0U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum[0U]);
        __Vtemp_304[1U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum[1U]);
        __Vtemp_304[2U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum[2U]);
        __Vtemp_304[3U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum[3U]);
        VL_ADD_W(4, __Vtemp_305, __Vtemp_303, __Vtemp_304);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__mag_sum[0U] 
            = __Vtemp_305[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__mag_sum[1U] 
            = __Vtemp_305[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__mag_sum[2U] 
            = __Vtemp_305[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__mag_sum[3U] 
            = (0x7fffffffU & __Vtemp_305[3U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__res_sign 
            = (1U & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_a_s)));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__mag_sum[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__mag_sum[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__mag_sum[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__mag_sum[3U] 
            = (0x3fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum[3U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__res_sign 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_a_s;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_special_case 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_special_case 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_special_case 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_special_case 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_special_case 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_special_case 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_special_case 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_special_case 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_special_case 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_special_case 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_special_case 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_case));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_align_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_y) 
                | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_m)) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_n)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_align_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_y) 
                | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_m)) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_n)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_align_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_y) 
                | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_m)) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_n)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_align_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_y) 
                | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_m)) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_n)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_align_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_y) 
                | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_m)) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_n)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_align_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_y) 
                | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_m)) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_n)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_align_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_y) 
                | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_m)) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_n)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_align_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_y) 
                | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_m)) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_n)));
    if ((0U == (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag[0U] 
                  | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag[1U]) 
                 | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag[2U]) 
                | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag[3U]))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros = 0x7eU;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros = 0U;
        VL_SHIFTR_WWI(127,127,32, __Vtemp_312, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 0x3fU);
        if ((0U == (((__Vtemp_312[0U] | __Vtemp_312[1U]) 
                     | __Vtemp_312[2U]) | (0x7fffffffU 
                                           & __Vtemp_312[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x40U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_317, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 0x40U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[0U] 
                = __Vtemp_317[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[1U] 
                = __Vtemp_317[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[2U] 
                = __Vtemp_317[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_317[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_320, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 0x5fU);
        if ((0U == (((__Vtemp_320[0U] | __Vtemp_320[1U]) 
                     | __Vtemp_320[2U]) | (0x7fffffffU 
                                           & __Vtemp_320[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x20U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_325, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 0x20U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[0U] 
                = __Vtemp_325[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[1U] 
                = __Vtemp_325[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[2U] 
                = __Vtemp_325[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_325[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_328, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 0x6fU);
        if ((0U == (((__Vtemp_328[0U] | __Vtemp_328[1U]) 
                     | __Vtemp_328[2U]) | (0x7fffffffU 
                                           & __Vtemp_328[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_333, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 0x10U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[0U] 
                = __Vtemp_333[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[1U] 
                = __Vtemp_333[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[2U] 
                = __Vtemp_333[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_333[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_336, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 0x77U);
        if ((0U == (((__Vtemp_336[0U] | __Vtemp_336[1U]) 
                     | __Vtemp_336[2U]) | (0x7fffffffU 
                                           & __Vtemp_336[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros 
                = (0x7fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_341, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 8U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[0U] 
                = __Vtemp_341[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[1U] 
                = __Vtemp_341[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[2U] 
                = __Vtemp_341[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_341[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_344, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 0x7bU);
        if ((0U == (((__Vtemp_344[0U] | __Vtemp_344[1U]) 
                     | __Vtemp_344[2U]) | (0x7fffffffU 
                                           & __Vtemp_344[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros 
                = (0x7fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_349, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 4U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[0U] 
                = __Vtemp_349[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[1U] 
                = __Vtemp_349[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[2U] 
                = __Vtemp_349[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_349[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_352, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 0x7dU);
        if ((0U == (((__Vtemp_352[0U] | __Vtemp_352[1U]) 
                     | __Vtemp_352[2U]) | (0x7fffffffU 
                                           & __Vtemp_352[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros 
                = (0x7fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_357, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 2U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[0U] 
                = __Vtemp_357[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[1U] 
                = __Vtemp_357[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[2U] 
                = __Vtemp_357[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_357[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_360, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 0x7eU);
        if ((0U == (((__Vtemp_360[0U] | __Vtemp_360[1U]) 
                     | __Vtemp_360[2U]) | (0x7fffffffU 
                                           & __Vtemp_360[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros 
                = (0x7fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_365, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 1U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[0U] 
                = __Vtemp_365[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[1U] 
                = __Vtemp_365[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[2U] 
                = __Vtemp_365[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_365[3U]);
        }
    }
    VL_SHIFTL_WWI(127,127,7, __Vtemp_367, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__norm_val[0U] 
        = __Vtemp_367[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__norm_val[1U] 
        = __Vtemp_367[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__norm_val[2U] 
        = __Vtemp_367[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__norm_val[3U] 
        = (0x7fffffffU & __Vtemp_367[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__guard_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__norm_val[3U] 
                 >> 6U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__round_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__norm_val[3U] 
                 >> 5U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sticky_bit 
        = ((0U != (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__norm_val[0U] 
                     | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__norm_val[1U]) 
                    | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__norm_val[2U]) 
                   | (0x1fU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__norm_val[3U]))) 
           | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__l_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__norm_val[3U] 
                 >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__round_up 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__guard_bit) 
           & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__round_bit) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sticky_bit)) 
              | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__l_bit)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__rounded_mant_int 
        = (0xffffffU & ((0x7fffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__norm_val[3U] 
                                      >> 7U)) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__round_up)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__final_mant 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__rounded_mant_int);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros 
        = (0x7fU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros) 
                    - ((0x800000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__rounded_mant_int)
                        ? 1U : 0U)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(3U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,9, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__result_out 
        = ((((0U == (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag[0U] 
                       | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag[1U]) 
                      | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag[2U]) 
                     | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag[3U])) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_exp_base)))
            ? 0U : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__final_exp_calc)))
                     ? (0x7f800000U | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_res_sign) 
                                       << 0x1fU)) : 
                    (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_res_sign) 
                      << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__final_exp_calc) 
                                                   << 0x17U)) 
                                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__final_mant))));
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_special) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__result_out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_spec_res;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_align_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sticky_y) 
                | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sticky_m)) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sticky_n)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_align_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_y) 
                | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_m)) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_n)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_align_sticky 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) 
           && (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_y) 
                | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_m)) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_n)));
}

VL_INLINE_OPT void Vadd32_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__1(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__1\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*127:0*/ __Vtemp_4;
    VlWide<4>/*127:0*/ __Vtemp_9;
    VlWide<4>/*127:0*/ __Vtemp_12;
    VlWide<4>/*127:0*/ __Vtemp_17;
    VlWide<4>/*127:0*/ __Vtemp_20;
    VlWide<4>/*127:0*/ __Vtemp_25;
    VlWide<4>/*127:0*/ __Vtemp_28;
    VlWide<4>/*127:0*/ __Vtemp_33;
    VlWide<4>/*127:0*/ __Vtemp_36;
    VlWide<4>/*127:0*/ __Vtemp_41;
    VlWide<4>/*127:0*/ __Vtemp_44;
    VlWide<4>/*127:0*/ __Vtemp_49;
    VlWide<4>/*127:0*/ __Vtemp_52;
    VlWide<4>/*127:0*/ __Vtemp_57;
    VlWide<4>/*127:0*/ __Vtemp_59;
    VlWide<4>/*127:0*/ __Vtemp_68;
    VlWide<4>/*127:0*/ __Vtemp_73;
    VlWide<4>/*127:0*/ __Vtemp_76;
    VlWide<4>/*127:0*/ __Vtemp_81;
    VlWide<4>/*127:0*/ __Vtemp_84;
    VlWide<4>/*127:0*/ __Vtemp_89;
    VlWide<4>/*127:0*/ __Vtemp_92;
    VlWide<4>/*127:0*/ __Vtemp_97;
    VlWide<4>/*127:0*/ __Vtemp_100;
    VlWide<4>/*127:0*/ __Vtemp_105;
    VlWide<4>/*127:0*/ __Vtemp_108;
    VlWide<4>/*127:0*/ __Vtemp_113;
    VlWide<4>/*127:0*/ __Vtemp_116;
    VlWide<4>/*127:0*/ __Vtemp_121;
    VlWide<4>/*127:0*/ __Vtemp_123;
    VlWide<4>/*127:0*/ __Vtemp_132;
    VlWide<4>/*127:0*/ __Vtemp_137;
    VlWide<4>/*127:0*/ __Vtemp_140;
    VlWide<4>/*127:0*/ __Vtemp_145;
    VlWide<4>/*127:0*/ __Vtemp_148;
    VlWide<4>/*127:0*/ __Vtemp_153;
    VlWide<4>/*127:0*/ __Vtemp_156;
    VlWide<4>/*127:0*/ __Vtemp_161;
    VlWide<4>/*127:0*/ __Vtemp_164;
    VlWide<4>/*127:0*/ __Vtemp_169;
    VlWide<4>/*127:0*/ __Vtemp_172;
    VlWide<4>/*127:0*/ __Vtemp_177;
    VlWide<4>/*127:0*/ __Vtemp_180;
    VlWide<4>/*127:0*/ __Vtemp_185;
    VlWide<4>/*127:0*/ __Vtemp_187;
    VlWide<4>/*127:0*/ __Vtemp_196;
    VlWide<4>/*127:0*/ __Vtemp_201;
    VlWide<4>/*127:0*/ __Vtemp_204;
    VlWide<4>/*127:0*/ __Vtemp_209;
    VlWide<4>/*127:0*/ __Vtemp_212;
    VlWide<4>/*127:0*/ __Vtemp_217;
    VlWide<4>/*127:0*/ __Vtemp_220;
    VlWide<4>/*127:0*/ __Vtemp_225;
    VlWide<4>/*127:0*/ __Vtemp_228;
    VlWide<4>/*127:0*/ __Vtemp_233;
    VlWide<4>/*127:0*/ __Vtemp_236;
    VlWide<4>/*127:0*/ __Vtemp_241;
    VlWide<4>/*127:0*/ __Vtemp_244;
    VlWide<4>/*127:0*/ __Vtemp_249;
    VlWide<4>/*127:0*/ __Vtemp_251;
    VlWide<4>/*127:0*/ __Vtemp_260;
    VlWide<4>/*127:0*/ __Vtemp_265;
    VlWide<4>/*127:0*/ __Vtemp_268;
    VlWide<4>/*127:0*/ __Vtemp_273;
    VlWide<4>/*127:0*/ __Vtemp_276;
    VlWide<4>/*127:0*/ __Vtemp_281;
    VlWide<4>/*127:0*/ __Vtemp_284;
    VlWide<4>/*127:0*/ __Vtemp_289;
    VlWide<4>/*127:0*/ __Vtemp_292;
    VlWide<4>/*127:0*/ __Vtemp_297;
    VlWide<4>/*127:0*/ __Vtemp_300;
    VlWide<4>/*127:0*/ __Vtemp_305;
    VlWide<4>/*127:0*/ __Vtemp_308;
    VlWide<4>/*127:0*/ __Vtemp_313;
    VlWide<4>/*127:0*/ __Vtemp_315;
    VlWide<4>/*127:0*/ __Vtemp_324;
    VlWide<4>/*127:0*/ __Vtemp_329;
    VlWide<4>/*127:0*/ __Vtemp_332;
    VlWide<4>/*127:0*/ __Vtemp_337;
    VlWide<4>/*127:0*/ __Vtemp_340;
    VlWide<4>/*127:0*/ __Vtemp_345;
    VlWide<4>/*127:0*/ __Vtemp_348;
    VlWide<4>/*127:0*/ __Vtemp_353;
    VlWide<4>/*127:0*/ __Vtemp_356;
    VlWide<4>/*127:0*/ __Vtemp_361;
    VlWide<4>/*127:0*/ __Vtemp_364;
    VlWide<4>/*127:0*/ __Vtemp_369;
    VlWide<4>/*127:0*/ __Vtemp_372;
    VlWide<4>/*127:0*/ __Vtemp_377;
    VlWide<4>/*127:0*/ __Vtemp_379;
    VlWide<4>/*127:0*/ __Vtemp_388;
    VlWide<4>/*127:0*/ __Vtemp_393;
    VlWide<4>/*127:0*/ __Vtemp_396;
    VlWide<4>/*127:0*/ __Vtemp_401;
    VlWide<4>/*127:0*/ __Vtemp_404;
    VlWide<4>/*127:0*/ __Vtemp_409;
    VlWide<4>/*127:0*/ __Vtemp_412;
    VlWide<4>/*127:0*/ __Vtemp_417;
    VlWide<4>/*127:0*/ __Vtemp_420;
    VlWide<4>/*127:0*/ __Vtemp_425;
    VlWide<4>/*127:0*/ __Vtemp_428;
    VlWide<4>/*127:0*/ __Vtemp_433;
    VlWide<4>/*127:0*/ __Vtemp_436;
    VlWide<4>/*127:0*/ __Vtemp_441;
    VlWide<4>/*127:0*/ __Vtemp_443;
    VlWide<4>/*127:0*/ __Vtemp_452;
    VlWide<4>/*127:0*/ __Vtemp_457;
    VlWide<4>/*127:0*/ __Vtemp_460;
    VlWide<4>/*127:0*/ __Vtemp_465;
    VlWide<4>/*127:0*/ __Vtemp_468;
    VlWide<4>/*127:0*/ __Vtemp_473;
    VlWide<4>/*127:0*/ __Vtemp_476;
    VlWide<4>/*127:0*/ __Vtemp_481;
    VlWide<4>/*127:0*/ __Vtemp_484;
    VlWide<4>/*127:0*/ __Vtemp_489;
    VlWide<4>/*127:0*/ __Vtemp_492;
    VlWide<4>/*127:0*/ __Vtemp_497;
    VlWide<4>/*127:0*/ __Vtemp_500;
    VlWide<4>/*127:0*/ __Vtemp_505;
    VlWide<4>/*127:0*/ __Vtemp_507;
    VlWide<4>/*127:0*/ __Vtemp_516;
    VlWide<4>/*127:0*/ __Vtemp_521;
    VlWide<4>/*127:0*/ __Vtemp_524;
    VlWide<4>/*127:0*/ __Vtemp_529;
    VlWide<4>/*127:0*/ __Vtemp_532;
    VlWide<4>/*127:0*/ __Vtemp_537;
    VlWide<4>/*127:0*/ __Vtemp_540;
    VlWide<4>/*127:0*/ __Vtemp_545;
    VlWide<4>/*127:0*/ __Vtemp_548;
    VlWide<4>/*127:0*/ __Vtemp_553;
    VlWide<4>/*127:0*/ __Vtemp_556;
    VlWide<4>/*127:0*/ __Vtemp_561;
    VlWide<4>/*127:0*/ __Vtemp_564;
    VlWide<4>/*127:0*/ __Vtemp_569;
    VlWide<4>/*127:0*/ __Vtemp_571;
    VlWide<4>/*127:0*/ __Vtemp_580;
    VlWide<4>/*127:0*/ __Vtemp_585;
    VlWide<4>/*127:0*/ __Vtemp_588;
    VlWide<4>/*127:0*/ __Vtemp_593;
    VlWide<4>/*127:0*/ __Vtemp_596;
    VlWide<4>/*127:0*/ __Vtemp_601;
    VlWide<4>/*127:0*/ __Vtemp_604;
    VlWide<4>/*127:0*/ __Vtemp_609;
    VlWide<4>/*127:0*/ __Vtemp_612;
    VlWide<4>/*127:0*/ __Vtemp_617;
    VlWide<4>/*127:0*/ __Vtemp_620;
    VlWide<4>/*127:0*/ __Vtemp_625;
    VlWide<4>/*127:0*/ __Vtemp_628;
    VlWide<4>/*127:0*/ __Vtemp_633;
    VlWide<4>/*127:0*/ __Vtemp_635;
    // Body
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_nrst) {
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage2_if__BRA__1__KET__.out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__result_out;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage2_if__BRA__0__KET__.out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__result_out;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__7__KET__.out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__result_out;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__6__KET__.out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__result_out;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__5__KET__.out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__result_out;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__4__KET__.out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__result_out;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__3__KET__.out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__result_out;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__2__KET__.out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__result_out;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__1__KET__.out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__result_out;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__0__KET__.out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__result_out;
    } else {
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage2_if__BRA__1__KET__.out = 0U;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage2_if__BRA__0__KET__.out = 0U;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__7__KET__.out = 0U;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__6__KET__.out = 0U;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__5__KET__.out = 0U;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__4__KET__.out = 0U;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__3__KET__.out = 0U;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__2__KET__.out = 0U;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__1__KET__.out = 0U;
        vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__0__KET__.out = 0U;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__final_reduce__DOT__guard 
        = (1U & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__final_reduce__DOT__rnd 
        = (1U & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out 
                 >> 0xeU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__final_reduce__DOT__sticky 
        = (0U != (0x3fffU & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__final_reduce__DOT__round_up 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__final_reduce__DOT__guard) 
           & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__final_reduce__DOT__rnd) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__final_reduce__DOT__sticky)) 
              | (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out 
                 >> 0x10U)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__final_reduce__DOT__rounded 
        = (0xffU & ((0x7fU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out 
                              >> 0x10U)) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__final_reduce__DOT__round_up)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__final_reduce__DOT__new_exp 
        = (0x3ffU & (VL_EXTENDS_II(10,10, (0xffU & 
                                           (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out 
                                            >> 0x17U))) 
                     + VL_EXTENDS_II(10,10, (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__final_reduce__DOT__rounded) 
                                                   >> 7U)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_result 
        = ((0xffU == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out 
                               >> 0x17U))) ? (0x7f80U 
                                              | ((0x8000U 
                                                  & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out 
                                                     >> 0x10U)) 
                                                 | ((0U 
                                                     != 
                                                     (0x7fffffU 
                                                      & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out))
                                                     ? 0x40U
                                                     : 0U)))
            : (VL_LTES_III(10, 0xffU, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__final_reduce__DOT__new_exp))
                ? (0x7f80U | (0x8000U & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out 
                                         >> 0x10U)))
                : (VL_GTES_III(32, 0U, VL_EXTENDS_II(32,10, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__final_reduce__DOT__new_exp)))
                    ? (0x8000U & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out 
                                  >> 0x10U)) : ((0x8000U 
                                                 & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage3_if.out 
                                                    >> 0x10U)) 
                                                | ((0x7f80U 
                                                    & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__final_reduce__DOT__new_exp) 
                                                       << 7U)) 
                                                   | ((0x80U 
                                                       & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__final_reduce__DOT__rounded))
                                                       ? 0U
                                                       : 
                                                      (0x7fU 
                                                       & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__final_reduce__DOT__rounded))))))));
    if ((0U == (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag[0U] 
                  | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag[1U]) 
                 | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag[2U]) 
                | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag[3U]))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros = 0x7eU;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros = 0U;
        VL_SHIFTR_WWI(127,127,32, __Vtemp_4, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 0x3fU);
        if ((0U == (((__Vtemp_4[0U] | __Vtemp_4[1U]) 
                     | __Vtemp_4[2U]) | (0x7fffffffU 
                                         & __Vtemp_4[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x40U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_9, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 0x40U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_9[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_9[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_9[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_9[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_12, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 0x5fU);
        if ((0U == (((__Vtemp_12[0U] | __Vtemp_12[1U]) 
                     | __Vtemp_12[2U]) | (0x7fffffffU 
                                          & __Vtemp_12[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x20U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_17, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 0x20U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_17[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_17[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_17[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_17[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_20, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 0x6fU);
        if ((0U == (((__Vtemp_20[0U] | __Vtemp_20[1U]) 
                     | __Vtemp_20[2U]) | (0x7fffffffU 
                                          & __Vtemp_20[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_25, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 0x10U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_25[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_25[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_25[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_25[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_28, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 0x77U);
        if ((0U == (((__Vtemp_28[0U] | __Vtemp_28[1U]) 
                     | __Vtemp_28[2U]) | (0x7fffffffU 
                                          & __Vtemp_28[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_33, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 8U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_33[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_33[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_33[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_33[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_36, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 0x7bU);
        if ((0U == (((__Vtemp_36[0U] | __Vtemp_36[1U]) 
                     | __Vtemp_36[2U]) | (0x7fffffffU 
                                          & __Vtemp_36[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_41, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 4U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_41[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_41[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_41[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_41[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_44, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 0x7dU);
        if ((0U == (((__Vtemp_44[0U] | __Vtemp_44[1U]) 
                     | __Vtemp_44[2U]) | (0x7fffffffU 
                                          & __Vtemp_44[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_49, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 2U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_49[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_49[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_49[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_49[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_52, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 0x7eU);
        if ((0U == (((__Vtemp_52[0U] | __Vtemp_52[1U]) 
                     | __Vtemp_52[2U]) | (0x7fffffffU 
                                          & __Vtemp_52[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_57, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 1U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_57[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_57[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_57[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_57[3U]);
        }
    }
    VL_SHIFTL_WWI(127,127,7, __Vtemp_59, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val[0U] 
        = __Vtemp_59[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val[1U] 
        = __Vtemp_59[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val[2U] 
        = __Vtemp_59[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val[3U] 
        = (0x7fffffffU & __Vtemp_59[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__guard_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val[3U] 
                 >> 6U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__round_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val[3U] 
                 >> 5U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_bit 
        = ((0U != (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val[0U] 
                     | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val[1U]) 
                    | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val[2U]) 
                   | (0x1fU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val[3U]))) 
           | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__l_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val[3U] 
                 >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__round_up 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__guard_bit) 
           & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__round_bit) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_bit)) 
              | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__l_bit)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__rounded_mant_int 
        = (0xffffffU & ((0x7fffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val[3U] 
                                      >> 7U)) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__round_up)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__final_mant 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__rounded_mant_int);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros 
        = (0x7fU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros) 
                    - ((0x800000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__rounded_mant_int)
                        ? 1U : 0U)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(3U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,9, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__result_out 
        = ((((0U == (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag[0U] 
                       | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag[1U]) 
                      | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag[2U]) 
                     | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag[3U])) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_exp_base)))
            ? 0U : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__final_exp_calc)))
                     ? (0x7f800000U | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_res_sign) 
                                       << 0x1fU)) : 
                    (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_res_sign) 
                      << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__final_exp_calc) 
                                                   << 0x17U)) 
                                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__final_mant))));
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_special) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__result_out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_spec_res;
    }
    if ((0U == (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag[0U] 
                  | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag[1U]) 
                 | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag[2U]) 
                | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag[3U]))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros = 0x7eU;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros = 0U;
        VL_SHIFTR_WWI(127,127,32, __Vtemp_68, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 0x3fU);
        if ((0U == (((__Vtemp_68[0U] | __Vtemp_68[1U]) 
                     | __Vtemp_68[2U]) | (0x7fffffffU 
                                          & __Vtemp_68[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x40U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_73, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 0x40U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_73[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_73[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_73[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_73[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_76, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 0x5fU);
        if ((0U == (((__Vtemp_76[0U] | __Vtemp_76[1U]) 
                     | __Vtemp_76[2U]) | (0x7fffffffU 
                                          & __Vtemp_76[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x20U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_81, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 0x20U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_81[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_81[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_81[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_81[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_84, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 0x6fU);
        if ((0U == (((__Vtemp_84[0U] | __Vtemp_84[1U]) 
                     | __Vtemp_84[2U]) | (0x7fffffffU 
                                          & __Vtemp_84[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_89, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 0x10U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_89[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_89[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_89[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_89[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_92, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 0x77U);
        if ((0U == (((__Vtemp_92[0U] | __Vtemp_92[1U]) 
                     | __Vtemp_92[2U]) | (0x7fffffffU 
                                          & __Vtemp_92[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_97, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 8U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_97[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_97[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_97[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_97[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_100, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 0x7bU);
        if ((0U == (((__Vtemp_100[0U] | __Vtemp_100[1U]) 
                     | __Vtemp_100[2U]) | (0x7fffffffU 
                                           & __Vtemp_100[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_105, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 4U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_105[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_105[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_105[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_105[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_108, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 0x7dU);
        if ((0U == (((__Vtemp_108[0U] | __Vtemp_108[1U]) 
                     | __Vtemp_108[2U]) | (0x7fffffffU 
                                           & __Vtemp_108[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_113, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 2U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_113[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_113[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_113[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_113[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_116, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 0x7eU);
        if ((0U == (((__Vtemp_116[0U] | __Vtemp_116[1U]) 
                     | __Vtemp_116[2U]) | (0x7fffffffU 
                                           & __Vtemp_116[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_121, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 1U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_121[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_121[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_121[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_121[3U]);
        }
    }
    VL_SHIFTL_WWI(127,127,7, __Vtemp_123, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val[0U] 
        = __Vtemp_123[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val[1U] 
        = __Vtemp_123[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val[2U] 
        = __Vtemp_123[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val[3U] 
        = (0x7fffffffU & __Vtemp_123[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__guard_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val[3U] 
                 >> 6U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__round_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val[3U] 
                 >> 5U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_bit 
        = ((0U != (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val[0U] 
                     | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val[1U]) 
                    | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val[2U]) 
                   | (0x1fU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val[3U]))) 
           | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__l_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val[3U] 
                 >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__round_up 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__guard_bit) 
           & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__round_bit) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_bit)) 
              | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__l_bit)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__rounded_mant_int 
        = (0xffffffU & ((0x7fffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val[3U] 
                                      >> 7U)) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__round_up)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__final_mant 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__rounded_mant_int);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros 
        = (0x7fU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros) 
                    - ((0x800000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__rounded_mant_int)
                        ? 1U : 0U)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(3U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,9, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__result_out 
        = ((((0U == (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag[0U] 
                       | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag[1U]) 
                      | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag[2U]) 
                     | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag[3U])) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_exp_base)))
            ? 0U : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__final_exp_calc)))
                     ? (0x7f800000U | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_res_sign) 
                                       << 0x1fU)) : 
                    (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_res_sign) 
                      << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__final_exp_calc) 
                                                   << 0x17U)) 
                                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__final_mant))));
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_special) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__result_out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_spec_res;
    }
    if ((0U == (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
                  | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag[1U]) 
                 | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag[2U]) 
                | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag[3U]))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros = 0x7eU;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros = 0U;
        VL_SHIFTR_WWI(127,127,32, __Vtemp_132, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 0x3fU);
        if ((0U == (((__Vtemp_132[0U] | __Vtemp_132[1U]) 
                     | __Vtemp_132[2U]) | (0x7fffffffU 
                                           & __Vtemp_132[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x40U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_137, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 0x40U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_137[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_137[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_137[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_137[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_140, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 0x5fU);
        if ((0U == (((__Vtemp_140[0U] | __Vtemp_140[1U]) 
                     | __Vtemp_140[2U]) | (0x7fffffffU 
                                           & __Vtemp_140[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x20U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_145, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 0x20U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_145[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_145[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_145[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_145[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_148, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 0x6fU);
        if ((0U == (((__Vtemp_148[0U] | __Vtemp_148[1U]) 
                     | __Vtemp_148[2U]) | (0x7fffffffU 
                                           & __Vtemp_148[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_153, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 0x10U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_153[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_153[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_153[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_153[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_156, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 0x77U);
        if ((0U == (((__Vtemp_156[0U] | __Vtemp_156[1U]) 
                     | __Vtemp_156[2U]) | (0x7fffffffU 
                                           & __Vtemp_156[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_161, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 8U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_161[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_161[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_161[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_161[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_164, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 0x7bU);
        if ((0U == (((__Vtemp_164[0U] | __Vtemp_164[1U]) 
                     | __Vtemp_164[2U]) | (0x7fffffffU 
                                           & __Vtemp_164[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_169, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 4U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_169[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_169[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_169[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_169[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_172, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 0x7dU);
        if ((0U == (((__Vtemp_172[0U] | __Vtemp_172[1U]) 
                     | __Vtemp_172[2U]) | (0x7fffffffU 
                                           & __Vtemp_172[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_177, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 2U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_177[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_177[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_177[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_177[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_180, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 0x7eU);
        if ((0U == (((__Vtemp_180[0U] | __Vtemp_180[1U]) 
                     | __Vtemp_180[2U]) | (0x7fffffffU 
                                           & __Vtemp_180[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_185, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 1U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_185[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_185[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_185[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_185[3U]);
        }
    }
    VL_SHIFTL_WWI(127,127,7, __Vtemp_187, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val[0U] 
        = __Vtemp_187[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val[1U] 
        = __Vtemp_187[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val[2U] 
        = __Vtemp_187[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val[3U] 
        = (0x7fffffffU & __Vtemp_187[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__guard_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val[3U] 
                 >> 6U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__round_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val[3U] 
                 >> 5U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_bit 
        = ((0U != (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val[0U] 
                     | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val[1U]) 
                    | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val[2U]) 
                   | (0x1fU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val[3U]))) 
           | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__l_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val[3U] 
                 >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__round_up 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__guard_bit) 
           & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__round_bit) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_bit)) 
              | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__l_bit)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__rounded_mant_int 
        = (0xffffffU & ((0x7fffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val[3U] 
                                      >> 7U)) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__round_up)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__final_mant 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__rounded_mant_int);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros 
        = (0x7fU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros) 
                    - ((0x800000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__rounded_mant_int)
                        ? 1U : 0U)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(3U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,9, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__result_out 
        = ((((0U == (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
                       | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag[1U]) 
                      | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag[2U]) 
                     | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag[3U])) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_exp_base)))
            ? 0U : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__final_exp_calc)))
                     ? (0x7f800000U | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_res_sign) 
                                       << 0x1fU)) : 
                    (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_res_sign) 
                      << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__final_exp_calc) 
                                                   << 0x17U)) 
                                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__final_mant))));
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_special) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__result_out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_spec_res;
    }
    if ((0U == (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
                  | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag[1U]) 
                 | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag[2U]) 
                | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag[3U]))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros = 0x7eU;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros = 0U;
        VL_SHIFTR_WWI(127,127,32, __Vtemp_196, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 0x3fU);
        if ((0U == (((__Vtemp_196[0U] | __Vtemp_196[1U]) 
                     | __Vtemp_196[2U]) | (0x7fffffffU 
                                           & __Vtemp_196[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x40U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_201, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 0x40U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_201[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_201[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_201[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_201[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_204, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 0x5fU);
        if ((0U == (((__Vtemp_204[0U] | __Vtemp_204[1U]) 
                     | __Vtemp_204[2U]) | (0x7fffffffU 
                                           & __Vtemp_204[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x20U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_209, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 0x20U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_209[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_209[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_209[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_209[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_212, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 0x6fU);
        if ((0U == (((__Vtemp_212[0U] | __Vtemp_212[1U]) 
                     | __Vtemp_212[2U]) | (0x7fffffffU 
                                           & __Vtemp_212[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_217, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 0x10U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_217[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_217[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_217[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_217[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_220, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 0x77U);
        if ((0U == (((__Vtemp_220[0U] | __Vtemp_220[1U]) 
                     | __Vtemp_220[2U]) | (0x7fffffffU 
                                           & __Vtemp_220[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_225, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 8U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_225[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_225[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_225[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_225[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_228, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 0x7bU);
        if ((0U == (((__Vtemp_228[0U] | __Vtemp_228[1U]) 
                     | __Vtemp_228[2U]) | (0x7fffffffU 
                                           & __Vtemp_228[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_233, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 4U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_233[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_233[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_233[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_233[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_236, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 0x7dU);
        if ((0U == (((__Vtemp_236[0U] | __Vtemp_236[1U]) 
                     | __Vtemp_236[2U]) | (0x7fffffffU 
                                           & __Vtemp_236[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_241, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 2U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_241[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_241[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_241[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_241[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_244, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 0x7eU);
        if ((0U == (((__Vtemp_244[0U] | __Vtemp_244[1U]) 
                     | __Vtemp_244[2U]) | (0x7fffffffU 
                                           & __Vtemp_244[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_249, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 1U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_249[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_249[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_249[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_249[3U]);
        }
    }
    VL_SHIFTL_WWI(127,127,7, __Vtemp_251, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val[0U] 
        = __Vtemp_251[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val[1U] 
        = __Vtemp_251[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val[2U] 
        = __Vtemp_251[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val[3U] 
        = (0x7fffffffU & __Vtemp_251[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__guard_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val[3U] 
                 >> 6U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__round_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val[3U] 
                 >> 5U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_bit 
        = ((0U != (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val[0U] 
                     | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val[1U]) 
                    | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val[2U]) 
                   | (0x1fU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val[3U]))) 
           | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__l_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val[3U] 
                 >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__round_up 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__guard_bit) 
           & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__round_bit) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_bit)) 
              | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__l_bit)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__rounded_mant_int 
        = (0xffffffU & ((0x7fffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val[3U] 
                                      >> 7U)) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__round_up)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__final_mant 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__rounded_mant_int);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros 
        = (0x7fU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros) 
                    - ((0x800000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__rounded_mant_int)
                        ? 1U : 0U)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(3U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,9, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__result_out 
        = ((((0U == (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
                       | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag[1U]) 
                      | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag[2U]) 
                     | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag[3U])) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_exp_base)))
            ? 0U : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__final_exp_calc)))
                     ? (0x7f800000U | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_res_sign) 
                                       << 0x1fU)) : 
                    (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_res_sign) 
                      << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__final_exp_calc) 
                                                   << 0x17U)) 
                                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__final_mant))));
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_special) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__result_out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_spec_res;
    }
    if ((0U == (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
                  | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag[1U]) 
                 | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag[2U]) 
                | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag[3U]))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros = 0x7eU;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros = 0U;
        VL_SHIFTR_WWI(127,127,32, __Vtemp_260, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 0x3fU);
        if ((0U == (((__Vtemp_260[0U] | __Vtemp_260[1U]) 
                     | __Vtemp_260[2U]) | (0x7fffffffU 
                                           & __Vtemp_260[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x40U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_265, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 0x40U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_265[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_265[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_265[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_265[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_268, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 0x5fU);
        if ((0U == (((__Vtemp_268[0U] | __Vtemp_268[1U]) 
                     | __Vtemp_268[2U]) | (0x7fffffffU 
                                           & __Vtemp_268[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x20U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_273, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 0x20U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_273[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_273[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_273[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_273[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_276, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 0x6fU);
        if ((0U == (((__Vtemp_276[0U] | __Vtemp_276[1U]) 
                     | __Vtemp_276[2U]) | (0x7fffffffU 
                                           & __Vtemp_276[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_281, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 0x10U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_281[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_281[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_281[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_281[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_284, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 0x77U);
        if ((0U == (((__Vtemp_284[0U] | __Vtemp_284[1U]) 
                     | __Vtemp_284[2U]) | (0x7fffffffU 
                                           & __Vtemp_284[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_289, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 8U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_289[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_289[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_289[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_289[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_292, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 0x7bU);
        if ((0U == (((__Vtemp_292[0U] | __Vtemp_292[1U]) 
                     | __Vtemp_292[2U]) | (0x7fffffffU 
                                           & __Vtemp_292[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_297, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 4U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_297[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_297[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_297[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_297[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_300, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 0x7dU);
        if ((0U == (((__Vtemp_300[0U] | __Vtemp_300[1U]) 
                     | __Vtemp_300[2U]) | (0x7fffffffU 
                                           & __Vtemp_300[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_305, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 2U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_305[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_305[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_305[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_305[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_308, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 0x7eU);
        if ((0U == (((__Vtemp_308[0U] | __Vtemp_308[1U]) 
                     | __Vtemp_308[2U]) | (0x7fffffffU 
                                           & __Vtemp_308[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_313, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 1U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_313[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_313[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_313[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_313[3U]);
        }
    }
    VL_SHIFTL_WWI(127,127,7, __Vtemp_315, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val[0U] 
        = __Vtemp_315[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val[1U] 
        = __Vtemp_315[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val[2U] 
        = __Vtemp_315[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val[3U] 
        = (0x7fffffffU & __Vtemp_315[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__guard_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val[3U] 
                 >> 6U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__round_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val[3U] 
                 >> 5U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_bit 
        = ((0U != (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val[0U] 
                     | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val[1U]) 
                    | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val[2U]) 
                   | (0x1fU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val[3U]))) 
           | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__l_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val[3U] 
                 >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__round_up 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__guard_bit) 
           & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__round_bit) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_bit)) 
              | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__l_bit)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__rounded_mant_int 
        = (0xffffffU & ((0x7fffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val[3U] 
                                      >> 7U)) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__round_up)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__final_mant 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__rounded_mant_int);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros 
        = (0x7fU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros) 
                    - ((0x800000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__rounded_mant_int)
                        ? 1U : 0U)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(3U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,9, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__result_out 
        = ((((0U == (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
                       | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag[1U]) 
                      | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag[2U]) 
                     | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag[3U])) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_exp_base)))
            ? 0U : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__final_exp_calc)))
                     ? (0x7f800000U | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_res_sign) 
                                       << 0x1fU)) : 
                    (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_res_sign) 
                      << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__final_exp_calc) 
                                                   << 0x17U)) 
                                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__final_mant))));
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_special) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__result_out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_spec_res;
    }
    if ((0U == (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
                  | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag[1U]) 
                 | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag[2U]) 
                | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag[3U]))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros = 0x7eU;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros = 0U;
        VL_SHIFTR_WWI(127,127,32, __Vtemp_324, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 0x3fU);
        if ((0U == (((__Vtemp_324[0U] | __Vtemp_324[1U]) 
                     | __Vtemp_324[2U]) | (0x7fffffffU 
                                           & __Vtemp_324[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x40U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_329, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 0x40U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_329[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_329[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_329[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_329[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_332, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 0x5fU);
        if ((0U == (((__Vtemp_332[0U] | __Vtemp_332[1U]) 
                     | __Vtemp_332[2U]) | (0x7fffffffU 
                                           & __Vtemp_332[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x20U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_337, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 0x20U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_337[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_337[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_337[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_337[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_340, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 0x6fU);
        if ((0U == (((__Vtemp_340[0U] | __Vtemp_340[1U]) 
                     | __Vtemp_340[2U]) | (0x7fffffffU 
                                           & __Vtemp_340[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_345, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 0x10U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_345[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_345[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_345[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_345[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_348, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 0x77U);
        if ((0U == (((__Vtemp_348[0U] | __Vtemp_348[1U]) 
                     | __Vtemp_348[2U]) | (0x7fffffffU 
                                           & __Vtemp_348[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_353, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 8U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_353[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_353[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_353[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_353[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_356, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 0x7bU);
        if ((0U == (((__Vtemp_356[0U] | __Vtemp_356[1U]) 
                     | __Vtemp_356[2U]) | (0x7fffffffU 
                                           & __Vtemp_356[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_361, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 4U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_361[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_361[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_361[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_361[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_364, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 0x7dU);
        if ((0U == (((__Vtemp_364[0U] | __Vtemp_364[1U]) 
                     | __Vtemp_364[2U]) | (0x7fffffffU 
                                           & __Vtemp_364[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_369, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 2U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_369[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_369[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_369[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_369[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_372, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 0x7eU);
        if ((0U == (((__Vtemp_372[0U] | __Vtemp_372[1U]) 
                     | __Vtemp_372[2U]) | (0x7fffffffU 
                                           & __Vtemp_372[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_377, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 1U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_377[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_377[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_377[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_377[3U]);
        }
    }
    VL_SHIFTL_WWI(127,127,7, __Vtemp_379, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val[0U] 
        = __Vtemp_379[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val[1U] 
        = __Vtemp_379[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val[2U] 
        = __Vtemp_379[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val[3U] 
        = (0x7fffffffU & __Vtemp_379[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__guard_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val[3U] 
                 >> 6U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__round_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val[3U] 
                 >> 5U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_bit 
        = ((0U != (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val[0U] 
                     | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val[1U]) 
                    | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val[2U]) 
                   | (0x1fU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val[3U]))) 
           | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__l_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val[3U] 
                 >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__round_up 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__guard_bit) 
           & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__round_bit) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_bit)) 
              | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__l_bit)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__rounded_mant_int 
        = (0xffffffU & ((0x7fffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val[3U] 
                                      >> 7U)) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__round_up)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__final_mant 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__rounded_mant_int);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros 
        = (0x7fU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros) 
                    - ((0x800000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__rounded_mant_int)
                        ? 1U : 0U)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(3U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,9, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__result_out 
        = ((((0U == (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
                       | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag[1U]) 
                      | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag[2U]) 
                     | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag[3U])) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_exp_base)))
            ? 0U : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__final_exp_calc)))
                     ? (0x7f800000U | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_res_sign) 
                                       << 0x1fU)) : 
                    (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_res_sign) 
                      << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__final_exp_calc) 
                                                   << 0x17U)) 
                                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__final_mant))));
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_special) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__result_out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_spec_res;
    }
    if ((0U == (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
                  | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag[1U]) 
                 | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag[2U]) 
                | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag[3U]))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros = 0x7eU;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros = 0U;
        VL_SHIFTR_WWI(127,127,32, __Vtemp_388, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 0x3fU);
        if ((0U == (((__Vtemp_388[0U] | __Vtemp_388[1U]) 
                     | __Vtemp_388[2U]) | (0x7fffffffU 
                                           & __Vtemp_388[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x40U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_393, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 0x40U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_393[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_393[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_393[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_393[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_396, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 0x5fU);
        if ((0U == (((__Vtemp_396[0U] | __Vtemp_396[1U]) 
                     | __Vtemp_396[2U]) | (0x7fffffffU 
                                           & __Vtemp_396[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x20U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_401, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 0x20U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_401[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_401[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_401[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_401[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_404, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 0x6fU);
        if ((0U == (((__Vtemp_404[0U] | __Vtemp_404[1U]) 
                     | __Vtemp_404[2U]) | (0x7fffffffU 
                                           & __Vtemp_404[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_409, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 0x10U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_409[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_409[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_409[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_409[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_412, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 0x77U);
        if ((0U == (((__Vtemp_412[0U] | __Vtemp_412[1U]) 
                     | __Vtemp_412[2U]) | (0x7fffffffU 
                                           & __Vtemp_412[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_417, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 8U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_417[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_417[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_417[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_417[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_420, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 0x7bU);
        if ((0U == (((__Vtemp_420[0U] | __Vtemp_420[1U]) 
                     | __Vtemp_420[2U]) | (0x7fffffffU 
                                           & __Vtemp_420[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_425, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 4U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_425[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_425[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_425[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_425[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_428, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 0x7dU);
        if ((0U == (((__Vtemp_428[0U] | __Vtemp_428[1U]) 
                     | __Vtemp_428[2U]) | (0x7fffffffU 
                                           & __Vtemp_428[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_433, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 2U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_433[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_433[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_433[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_433[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_436, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 0x7eU);
        if ((0U == (((__Vtemp_436[0U] | __Vtemp_436[1U]) 
                     | __Vtemp_436[2U]) | (0x7fffffffU 
                                           & __Vtemp_436[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_441, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 1U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_441[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_441[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_441[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_441[3U]);
        }
    }
    VL_SHIFTL_WWI(127,127,7, __Vtemp_443, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val[0U] 
        = __Vtemp_443[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val[1U] 
        = __Vtemp_443[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val[2U] 
        = __Vtemp_443[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val[3U] 
        = (0x7fffffffU & __Vtemp_443[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__guard_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val[3U] 
                 >> 6U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__round_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val[3U] 
                 >> 5U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_bit 
        = ((0U != (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val[0U] 
                     | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val[1U]) 
                    | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val[2U]) 
                   | (0x1fU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val[3U]))) 
           | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__l_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val[3U] 
                 >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__round_up 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__guard_bit) 
           & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__round_bit) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_bit)) 
              | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__l_bit)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__rounded_mant_int 
        = (0xffffffU & ((0x7fffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val[3U] 
                                      >> 7U)) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__round_up)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__final_mant 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__rounded_mant_int);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros 
        = (0x7fU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros) 
                    - ((0x800000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__rounded_mant_int)
                        ? 1U : 0U)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(3U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,9, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__result_out 
        = ((((0U == (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
                       | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag[1U]) 
                      | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag[2U]) 
                     | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag[3U])) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_exp_base)))
            ? 0U : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__final_exp_calc)))
                     ? (0x7f800000U | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_res_sign) 
                                       << 0x1fU)) : 
                    (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_res_sign) 
                      << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__final_exp_calc) 
                                                   << 0x17U)) 
                                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__final_mant))));
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_special) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__result_out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_spec_res;
    }
    if ((0U == (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
                  | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag[1U]) 
                 | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag[2U]) 
                | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag[3U]))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros = 0x7eU;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros = 0U;
        VL_SHIFTR_WWI(127,127,32, __Vtemp_452, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 0x3fU);
        if ((0U == (((__Vtemp_452[0U] | __Vtemp_452[1U]) 
                     | __Vtemp_452[2U]) | (0x7fffffffU 
                                           & __Vtemp_452[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x40U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_457, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 0x40U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_457[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_457[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_457[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_457[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_460, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 0x5fU);
        if ((0U == (((__Vtemp_460[0U] | __Vtemp_460[1U]) 
                     | __Vtemp_460[2U]) | (0x7fffffffU 
                                           & __Vtemp_460[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x20U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_465, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 0x20U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_465[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_465[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_465[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_465[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_468, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 0x6fU);
        if ((0U == (((__Vtemp_468[0U] | __Vtemp_468[1U]) 
                     | __Vtemp_468[2U]) | (0x7fffffffU 
                                           & __Vtemp_468[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_473, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 0x10U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_473[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_473[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_473[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_473[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_476, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 0x77U);
        if ((0U == (((__Vtemp_476[0U] | __Vtemp_476[1U]) 
                     | __Vtemp_476[2U]) | (0x7fffffffU 
                                           & __Vtemp_476[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_481, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 8U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_481[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_481[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_481[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_481[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_484, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 0x7bU);
        if ((0U == (((__Vtemp_484[0U] | __Vtemp_484[1U]) 
                     | __Vtemp_484[2U]) | (0x7fffffffU 
                                           & __Vtemp_484[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_489, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 4U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_489[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_489[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_489[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_489[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_492, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 0x7dU);
        if ((0U == (((__Vtemp_492[0U] | __Vtemp_492[1U]) 
                     | __Vtemp_492[2U]) | (0x7fffffffU 
                                           & __Vtemp_492[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_497, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 2U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_497[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_497[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_497[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_497[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_500, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 0x7eU);
        if ((0U == (((__Vtemp_500[0U] | __Vtemp_500[1U]) 
                     | __Vtemp_500[2U]) | (0x7fffffffU 
                                           & __Vtemp_500[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_505, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 1U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_505[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_505[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_505[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_505[3U]);
        }
    }
    VL_SHIFTL_WWI(127,127,7, __Vtemp_507, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val[0U] 
        = __Vtemp_507[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val[1U] 
        = __Vtemp_507[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val[2U] 
        = __Vtemp_507[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val[3U] 
        = (0x7fffffffU & __Vtemp_507[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__guard_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val[3U] 
                 >> 6U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__round_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val[3U] 
                 >> 5U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_bit 
        = ((0U != (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val[0U] 
                     | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val[1U]) 
                    | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val[2U]) 
                   | (0x1fU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val[3U]))) 
           | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__l_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val[3U] 
                 >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__round_up 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__guard_bit) 
           & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__round_bit) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_bit)) 
              | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__l_bit)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__rounded_mant_int 
        = (0xffffffU & ((0x7fffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val[3U] 
                                      >> 7U)) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__round_up)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__final_mant 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__rounded_mant_int);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros 
        = (0x7fU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros) 
                    - ((0x800000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__rounded_mant_int)
                        ? 1U : 0U)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(3U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,9, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__result_out 
        = ((((0U == (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
                       | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag[1U]) 
                      | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag[2U]) 
                     | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag[3U])) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_exp_base)))
            ? 0U : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__final_exp_calc)))
                     ? (0x7f800000U | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_res_sign) 
                                       << 0x1fU)) : 
                    (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_res_sign) 
                      << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__final_exp_calc) 
                                                   << 0x17U)) 
                                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__final_mant))));
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_special) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__result_out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_spec_res;
    }
    if ((0U == (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
                  | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag[1U]) 
                 | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag[2U]) 
                | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag[3U]))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros = 0x7eU;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros = 0U;
        VL_SHIFTR_WWI(127,127,32, __Vtemp_516, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 0x3fU);
        if ((0U == (((__Vtemp_516[0U] | __Vtemp_516[1U]) 
                     | __Vtemp_516[2U]) | (0x7fffffffU 
                                           & __Vtemp_516[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x40U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_521, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 0x40U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_521[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_521[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_521[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_521[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_524, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 0x5fU);
        if ((0U == (((__Vtemp_524[0U] | __Vtemp_524[1U]) 
                     | __Vtemp_524[2U]) | (0x7fffffffU 
                                           & __Vtemp_524[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x20U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_529, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 0x20U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_529[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_529[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_529[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_529[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_532, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 0x6fU);
        if ((0U == (((__Vtemp_532[0U] | __Vtemp_532[1U]) 
                     | __Vtemp_532[2U]) | (0x7fffffffU 
                                           & __Vtemp_532[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_537, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 0x10U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_537[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_537[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_537[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_537[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_540, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 0x77U);
        if ((0U == (((__Vtemp_540[0U] | __Vtemp_540[1U]) 
                     | __Vtemp_540[2U]) | (0x7fffffffU 
                                           & __Vtemp_540[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_545, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 8U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_545[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_545[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_545[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_545[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_548, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 0x7bU);
        if ((0U == (((__Vtemp_548[0U] | __Vtemp_548[1U]) 
                     | __Vtemp_548[2U]) | (0x7fffffffU 
                                           & __Vtemp_548[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_553, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 4U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_553[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_553[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_553[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_553[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_556, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 0x7dU);
        if ((0U == (((__Vtemp_556[0U] | __Vtemp_556[1U]) 
                     | __Vtemp_556[2U]) | (0x7fffffffU 
                                           & __Vtemp_556[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_561, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 2U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_561[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_561[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_561[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_561[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_564, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 0x7eU);
        if ((0U == (((__Vtemp_564[0U] | __Vtemp_564[1U]) 
                     | __Vtemp_564[2U]) | (0x7fffffffU 
                                           & __Vtemp_564[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_569, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 1U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_569[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_569[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_569[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_569[3U]);
        }
    }
    VL_SHIFTL_WWI(127,127,7, __Vtemp_571, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val[0U] 
        = __Vtemp_571[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val[1U] 
        = __Vtemp_571[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val[2U] 
        = __Vtemp_571[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val[3U] 
        = (0x7fffffffU & __Vtemp_571[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__guard_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val[3U] 
                 >> 6U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__round_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val[3U] 
                 >> 5U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_bit 
        = ((0U != (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val[0U] 
                     | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val[1U]) 
                    | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val[2U]) 
                   | (0x1fU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val[3U]))) 
           | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__l_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val[3U] 
                 >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__round_up 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__guard_bit) 
           & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__round_bit) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_bit)) 
              | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__l_bit)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__rounded_mant_int 
        = (0xffffffU & ((0x7fffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val[3U] 
                                      >> 7U)) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__round_up)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__final_mant 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__rounded_mant_int);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros 
        = (0x7fU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros) 
                    - ((0x800000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__rounded_mant_int)
                        ? 1U : 0U)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(3U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,9, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__result_out 
        = ((((0U == (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
                       | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag[1U]) 
                      | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag[2U]) 
                     | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag[3U])) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_exp_base)))
            ? 0U : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__final_exp_calc)))
                     ? (0x7f800000U | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_res_sign) 
                                       << 0x1fU)) : 
                    (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_res_sign) 
                      << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__final_exp_calc) 
                                                   << 0x17U)) 
                                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__final_mant))));
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_special) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__result_out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_spec_res;
    }
    if ((0U == (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
                  | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag[1U]) 
                 | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag[2U]) 
                | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag[3U]))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[3U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros = 0x7eU;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag[3U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros = 0U;
        VL_SHIFTR_WWI(127,127,32, __Vtemp_580, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 0x3fU);
        if ((0U == (((__Vtemp_580[0U] | __Vtemp_580[1U]) 
                     | __Vtemp_580[2U]) | (0x7fffffffU 
                                           & __Vtemp_580[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x40U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_585, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 0x40U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_585[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_585[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_585[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_585[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_588, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 0x5fU);
        if ((0U == (((__Vtemp_588[0U] | __Vtemp_588[1U]) 
                     | __Vtemp_588[2U]) | (0x7fffffffU 
                                           & __Vtemp_588[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x20U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_593, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 0x20U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_593[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_593[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_593[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_593[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_596, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 0x6fU);
        if ((0U == (((__Vtemp_596[0U] | __Vtemp_596[1U]) 
                     | __Vtemp_596[2U]) | (0x7fffffffU 
                                           & __Vtemp_596[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_601, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 0x10U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_601[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_601[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_601[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_601[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_604, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 0x77U);
        if ((0U == (((__Vtemp_604[0U] | __Vtemp_604[1U]) 
                     | __Vtemp_604[2U]) | (0x7fffffffU 
                                           & __Vtemp_604[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_609, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 8U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_609[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_609[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_609[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_609[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_612, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 0x7bU);
        if ((0U == (((__Vtemp_612[0U] | __Vtemp_612[1U]) 
                     | __Vtemp_612[2U]) | (0x7fffffffU 
                                           & __Vtemp_612[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_617, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 4U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_617[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_617[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_617[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_617[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_620, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 0x7dU);
        if ((0U == (((__Vtemp_620[0U] | __Vtemp_620[1U]) 
                     | __Vtemp_620[2U]) | (0x7fffffffU 
                                           & __Vtemp_620[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_625, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 2U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_625[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_625[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_625[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_625[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_628, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 0x7eU);
        if ((0U == (((__Vtemp_628[0U] | __Vtemp_628[1U]) 
                     | __Vtemp_628[2U]) | (0x7fffffffU 
                                           & __Vtemp_628[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_633, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 1U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_633[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_633[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_633[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_633[3U]);
        }
    }
    VL_SHIFTL_WWI(127,127,7, __Vtemp_635, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val[0U] 
        = __Vtemp_635[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val[1U] 
        = __Vtemp_635[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val[2U] 
        = __Vtemp_635[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val[3U] 
        = (0x7fffffffU & __Vtemp_635[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__guard_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val[3U] 
                 >> 6U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__round_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val[3U] 
                 >> 5U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_bit 
        = ((0U != (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val[0U] 
                     | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val[1U]) 
                    | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val[2U]) 
                   | (0x1fU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val[3U]))) 
           | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sticky));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__l_bit 
        = (1U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val[3U] 
                 >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__round_up 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__guard_bit) 
           & (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__round_bit) 
               | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_bit)) 
              | (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__l_bit)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__rounded_mant_int 
        = (0xffffffU & ((0x7fffffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val[3U] 
                                      >> 7U)) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__round_up)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__final_mant 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__rounded_mant_int);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros 
        = (0x7fU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros) 
                    - ((0x800000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__rounded_mant_int)
                        ? 1U : 0U)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__final_exp_calc 
        = (0x7ffU & (((IData)(3U) + VL_EXTENDS_II(11,10, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_exp_base))) 
                     - VL_EXTENDS_II(11,9, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__result_out 
        = ((((0U == (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag[0U] 
                       | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag[1U]) 
                      | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag[2U]) 
                     | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag[3U])) 
             | VL_GTES_III(32, 0U, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__final_exp_calc)))) 
            | (0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_exp_base)))
            ? 0U : (VL_LTES_III(32, 0xffU, VL_EXTENDS_II(32,11, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__final_exp_calc)))
                     ? (0x7f800000U | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_res_sign) 
                                       << 0x1fU)) : 
                    (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_res_sign) 
                      << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__final_exp_calc) 
                                                   << 0x17U)) 
                                   | vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__final_mant))));
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_special) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__result_out 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_spec_res;
    }
}

VL_INLINE_OPT void Vadd32_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__2(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___nba_sequent__TOP__2\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*127:0*/ __Vtemp_9;
    VlWide<4>/*127:0*/ __Vtemp_10;
    VlWide<4>/*127:0*/ __Vtemp_15;
    VlWide<4>/*127:0*/ __Vtemp_18;
    VlWide<4>/*127:0*/ __Vtemp_19;
    VlWide<4>/*127:0*/ __Vtemp_24;
    VlWide<4>/*127:0*/ __Vtemp_27;
    VlWide<4>/*127:0*/ __Vtemp_28;
    VlWide<4>/*127:0*/ __Vtemp_33;
    VlWide<4>/*127:0*/ __Vtemp_57;
    VlWide<4>/*127:0*/ __Vtemp_60;
    VlWide<4>/*127:0*/ __Vtemp_62;
    VlWide<4>/*127:0*/ __Vtemp_74;
    VlWide<4>/*127:0*/ __Vtemp_75;
    VlWide<4>/*127:0*/ __Vtemp_80;
    VlWide<4>/*127:0*/ __Vtemp_83;
    VlWide<4>/*127:0*/ __Vtemp_84;
    VlWide<4>/*127:0*/ __Vtemp_89;
    VlWide<4>/*127:0*/ __Vtemp_92;
    VlWide<4>/*127:0*/ __Vtemp_93;
    VlWide<4>/*127:0*/ __Vtemp_98;
    VlWide<4>/*127:0*/ __Vtemp_122;
    VlWide<4>/*127:0*/ __Vtemp_125;
    VlWide<4>/*127:0*/ __Vtemp_127;
    VlWide<4>/*127:0*/ __Vtemp_139;
    VlWide<4>/*127:0*/ __Vtemp_140;
    VlWide<4>/*127:0*/ __Vtemp_145;
    VlWide<4>/*127:0*/ __Vtemp_148;
    VlWide<4>/*127:0*/ __Vtemp_149;
    VlWide<4>/*127:0*/ __Vtemp_154;
    VlWide<4>/*127:0*/ __Vtemp_157;
    VlWide<4>/*127:0*/ __Vtemp_158;
    VlWide<4>/*127:0*/ __Vtemp_163;
    VlWide<4>/*127:0*/ __Vtemp_187;
    VlWide<4>/*127:0*/ __Vtemp_190;
    VlWide<4>/*127:0*/ __Vtemp_192;
    // Body
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__a_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage2_if__BRA__0__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage2_if__BRA__0__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage2_if__BRA__0__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__b_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage2_if__BRA__1__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage2_if__BRA__1__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage2_if__BRA__1__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__c_daz = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__d_daz = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_a 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__a_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_a 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__a_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_a 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__a_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_b 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__b_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_b 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__b_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_b 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__b_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_c = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_c = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_c = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_d = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_d = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_d = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__is_nan_any 
        = (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_a)) 
            & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_a)) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_b)) 
              & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_b)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__any_pos_inf 
        = ((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_a)) 
             & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_a))) 
            & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_a)))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_b)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_b))) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_b)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__any_neg_inf 
        = ((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_a)) 
             & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_a)) 
            & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_a)))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_b)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_b)) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_b)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_a;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_r 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_c;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_r 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_c;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_r 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_c;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_n 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_d;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_n 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_d;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_n 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_d;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__x_mant[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__x_mant[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__x_mant[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__x_mant[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_x))) 
            << 0x1bU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_x 
                         << 4U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_y))) 
            << 0x1bU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_y 
                         << 4U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_mx))) 
            << 0x1bU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_mx 
                         << 4U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__exp_nx))) 
            << 0x1bU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__frac_nx 
                         << 4U));
    __Vtemp_9[0U] = 0xffffffffU;
    __Vtemp_9[1U] = 0xffffffffU;
    __Vtemp_9[2U] = 0xffffffffU;
    __Vtemp_9[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_10, __Vtemp_9, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sticky_y 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_mant_base[0U] 
                     & (~ __Vtemp_10[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_mant_base[1U] 
                                              & (~ 
                                                 __Vtemp_10[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_mant_base[2U] 
                      & (~ __Vtemp_10[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_mant_base[3U] 
                                                & (~ 
                                                   __Vtemp_10[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_15, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shifted[0U] 
            = __Vtemp_15[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shifted[1U] 
            = __Vtemp_15[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shifted[2U] 
            = __Vtemp_15[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shifted[3U] 
            = (0xfffffffU & __Vtemp_15[3U]);
    }
    __Vtemp_18[0U] = 0xffffffffU;
    __Vtemp_18[1U] = 0xffffffffU;
    __Vtemp_18[2U] = 0xffffffffU;
    __Vtemp_18[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_19, __Vtemp_18, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sticky_m 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_mant_base[0U] 
                     & (~ __Vtemp_19[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_mant_base[1U] 
                                              & (~ 
                                                 __Vtemp_19[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_mant_base[2U] 
                      & (~ __Vtemp_19[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_mant_base[3U] 
                                                & (~ 
                                                   __Vtemp_19[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_24, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shifted[0U] 
            = __Vtemp_24[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shifted[1U] 
            = __Vtemp_24[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shifted[2U] 
            = __Vtemp_24[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shifted[3U] 
            = (0xfffffffU & __Vtemp_24[3U]);
    }
    __Vtemp_27[0U] = 0xffffffffU;
    __Vtemp_27[1U] = 0xffffffffU;
    __Vtemp_27[2U] = 0xffffffffU;
    __Vtemp_27[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_28, __Vtemp_27, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sticky_n 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_mant_base[0U] 
                     & (~ __Vtemp_28[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_mant_base[1U] 
                                              & (~ 
                                                 __Vtemp_28[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_mant_base[2U] 
                      & (~ __Vtemp_28[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_mant_base[3U] 
                                                & (~ 
                                                   __Vtemp_28[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_33, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shifted[0U] 
            = __Vtemp_33[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shifted[1U] 
            = __Vtemp_33[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shifted[2U] 
            = __Vtemp_33[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shifted[3U] 
            = (0xfffffffU & __Vtemp_33[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_x[0U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__x_mant[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_x[1U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__x_mant[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_x[2U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__x_mant[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_x[3U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__x_mant[3U];
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_y[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_y[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_y[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_y[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_y[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_y[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_y[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_y[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_m[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_m[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_m[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_m[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_m[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_m[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_m[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_m[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shifted[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_x[0U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_y[0U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_m[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_x[1U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_y[1U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_m[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_x[2U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_y[2U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_m[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[3U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_x[3U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_y[3U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_m[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_c1[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_x[0U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_y[0U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_y[0U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_m[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_m[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_x[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_c1[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_x[1U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_y[1U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_y[1U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_m[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_m[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_x[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_c1[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_x[2U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_y[2U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_y[2U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_m[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_m[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_x[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_c1[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_x[3U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_y[3U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_y[3U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_m[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_m[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_x[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_57, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s2[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[0U] 
            ^ __Vtemp_57[0U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s2[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[1U] 
            ^ __Vtemp_57[1U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s2[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[2U] 
            ^ __Vtemp_57[2U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s2[3U] 
        = (0x7fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[3U] 
                           ^ __Vtemp_57[3U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_60, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_c1, 1U);
    VL_SHIFTL_WWI(127,127,32, __Vtemp_62, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_c2[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[0U] 
             & __Vtemp_60[0U]) | (__Vtemp_62[0U] & 
                                  vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_c2[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[1U] 
             & __Vtemp_60[1U]) | (__Vtemp_62[1U] & 
                                  vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_c2[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[2U] 
             & __Vtemp_60[2U]) | (__Vtemp_62[2U] & 
                                  vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_c2[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[3U] 
             & __Vtemp_60[3U]) | (__Vtemp_62[3U] & 
                                  vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[3U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__a_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__4__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__4__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__4__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__b_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__5__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__5__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__5__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__c_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__6__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__6__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__6__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__d_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__7__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__7__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__7__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_a 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__a_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_a 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__a_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_a 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__a_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_b 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__b_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_b 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__b_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_b 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__b_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_c 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__c_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_c 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__c_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_c 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__c_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_d 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__d_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_d 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__d_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_d 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__d_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_a)) 
              & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_a)) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_b)) 
                & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_b))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_c)) 
               & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_c))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_d)) 
              & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_d)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_a))) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_a)))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_b))) 
                & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_b))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_c))) 
               & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_c))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_d))) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_d)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_a)) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_a)))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_b)) 
                & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_b))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_c)) 
               & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_c))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_d)) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_d)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__x_mant[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__x_mant[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__x_mant[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__x_mant[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_x))) 
            << 0x1bU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_x 
                         << 4U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_y))) 
            << 0x1bU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_y 
                         << 4U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_mx))) 
            << 0x1bU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_mx 
                         << 4U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__exp_nx))) 
            << 0x1bU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__frac_nx 
                         << 4U));
    __Vtemp_74[0U] = 0xffffffffU;
    __Vtemp_74[1U] = 0xffffffffU;
    __Vtemp_74[2U] = 0xffffffffU;
    __Vtemp_74[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_75, __Vtemp_74, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_y 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_mant_base[0U] 
                     & (~ __Vtemp_75[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_mant_base[1U] 
                                              & (~ 
                                                 __Vtemp_75[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_mant_base[2U] 
                      & (~ __Vtemp_75[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_mant_base[3U] 
                                                & (~ 
                                                   __Vtemp_75[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_80, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted[0U] 
            = __Vtemp_80[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted[1U] 
            = __Vtemp_80[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted[2U] 
            = __Vtemp_80[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted[3U] 
            = (0xfffffffU & __Vtemp_80[3U]);
    }
    __Vtemp_83[0U] = 0xffffffffU;
    __Vtemp_83[1U] = 0xffffffffU;
    __Vtemp_83[2U] = 0xffffffffU;
    __Vtemp_83[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_84, __Vtemp_83, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_m 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_mant_base[0U] 
                     & (~ __Vtemp_84[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_mant_base[1U] 
                                              & (~ 
                                                 __Vtemp_84[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_mant_base[2U] 
                      & (~ __Vtemp_84[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_mant_base[3U] 
                                                & (~ 
                                                   __Vtemp_84[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_89, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted[0U] 
            = __Vtemp_89[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted[1U] 
            = __Vtemp_89[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted[2U] 
            = __Vtemp_89[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted[3U] 
            = (0xfffffffU & __Vtemp_89[3U]);
    }
    __Vtemp_92[0U] = 0xffffffffU;
    __Vtemp_92[1U] = 0xffffffffU;
    __Vtemp_92[2U] = 0xffffffffU;
    __Vtemp_92[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_93, __Vtemp_92, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_n 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_mant_base[0U] 
                     & (~ __Vtemp_93[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_mant_base[1U] 
                                              & (~ 
                                                 __Vtemp_93[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_mant_base[2U] 
                      & (~ __Vtemp_93[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_mant_base[3U] 
                                                & (~ 
                                                   __Vtemp_93[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_98, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted[0U] 
            = __Vtemp_98[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted[1U] 
            = __Vtemp_98[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted[2U] 
            = __Vtemp_98[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted[3U] 
            = (0xfffffffU & __Vtemp_98[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_x[0U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__x_mant[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_x[1U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__x_mant[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_x[2U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__x_mant[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_x[3U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__x_mant[3U];
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_x[0U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y[0U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_x[1U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y[1U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_x[2U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y[2U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[3U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_x[3U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y[3U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c1[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_x[0U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y[0U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y[0U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_x[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c1[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_x[1U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y[1U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y[1U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_x[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c1[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_x[2U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y[2U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y[2U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_x[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c1[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_x[3U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y[3U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_y[3U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_m[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_x[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_122, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s2[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[0U] 
            ^ __Vtemp_122[0U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s2[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[1U] 
            ^ __Vtemp_122[1U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s2[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[2U] 
            ^ __Vtemp_122[2U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s2[3U] 
        = (0x7fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[3U] 
                           ^ __Vtemp_122[3U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_125, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c1, 1U);
    VL_SHIFTL_WWI(127,127,32, __Vtemp_127, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c2[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[0U] 
             & __Vtemp_125[0U]) | (__Vtemp_127[0U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c2[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[1U] 
             & __Vtemp_125[1U]) | (__Vtemp_127[1U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c2[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[2U] 
             & __Vtemp_125[2U]) | (__Vtemp_127[2U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c2[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[3U] 
             & __Vtemp_125[3U]) | (__Vtemp_127[3U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[3U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__a_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__0__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__0__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__0__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__b_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__1__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__1__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__1__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__c_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__2__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__2__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__2__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__d_daz 
        = ((0U == (0xffU & (vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__3__KET__.out 
                            >> 0x17U))) ? (0x80000000U 
                                           & vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__3__KET__.out)
            : vlSymsp->TOP__add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__stage1_if__BRA__3__KET__.out);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_a 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__a_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_a 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__a_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_a 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__a_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_b 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__b_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_b 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__b_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_b 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__b_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_c 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__c_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_c 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__c_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_c 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__c_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_d 
        = (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__d_daz 
           >> 0x1fU);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_d 
        = (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__d_daz 
                    >> 0x17U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_d 
        = (0x7fffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__d_daz);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_a)) 
              & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_a)) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_b)) 
                & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_b))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_c)) 
               & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_c))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_d)) 
              & (0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_d)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_a))) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_a)))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_b))) 
                & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_b))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_c))) 
               & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_c))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_d))) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_d)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_a)) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_a)))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_b)) 
                & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_b))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_c)) 
               & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_c))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_d)) 
              & (~ (IData)((0U != vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_d)))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__x_mant[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__x_mant[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__x_mant[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__x_mant[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_x))) 
            << 0x1bU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_x 
                         << 4U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_y))) 
            << 0x1bU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_y 
                         << 4U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_mx))) 
            << 0x1bU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_mx 
                         << 4U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__exp_nx))) 
            << 0x1bU) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__frac_nx 
                         << 4U));
    __Vtemp_139[0U] = 0xffffffffU;
    __Vtemp_139[1U] = 0xffffffffU;
    __Vtemp_139[2U] = 0xffffffffU;
    __Vtemp_139[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_140, __Vtemp_139, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_y 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_mant_base[0U] 
                     & (~ __Vtemp_140[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_mant_base[1U] 
                                               & (~ 
                                                  __Vtemp_140[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_mant_base[2U] 
                      & (~ __Vtemp_140[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_mant_base[3U] 
                                                 & (~ 
                                                    __Vtemp_140[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_145, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted[0U] 
            = __Vtemp_145[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted[1U] 
            = __Vtemp_145[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted[2U] 
            = __Vtemp_145[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted[3U] 
            = (0xfffffffU & __Vtemp_145[3U]);
    }
    __Vtemp_148[0U] = 0xffffffffU;
    __Vtemp_148[1U] = 0xffffffffU;
    __Vtemp_148[2U] = 0xffffffffU;
    __Vtemp_148[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_149, __Vtemp_148, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_m 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_mant_base[0U] 
                     & (~ __Vtemp_149[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_mant_base[1U] 
                                               & (~ 
                                                  __Vtemp_149[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_mant_base[2U] 
                      & (~ __Vtemp_149[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_mant_base[3U] 
                                                 & (~ 
                                                    __Vtemp_149[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_154, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted[0U] 
            = __Vtemp_154[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted[1U] 
            = __Vtemp_154[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted[2U] 
            = __Vtemp_154[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted[3U] 
            = (0xfffffffU & __Vtemp_154[3U]);
    }
    __Vtemp_157[0U] = 0xffffffffU;
    __Vtemp_157[1U] = 0xffffffffU;
    __Vtemp_157[2U] = 0xffffffffU;
    __Vtemp_157[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_158, __Vtemp_157, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_n 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_mant_base[0U] 
                     & (~ __Vtemp_158[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_mant_base[1U] 
                                               & (~ 
                                                  __Vtemp_158[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_mant_base[2U] 
                      & (~ __Vtemp_158[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_mant_base[3U] 
                                                 & (~ 
                                                    __Vtemp_158[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_163, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted[0U] 
            = __Vtemp_163[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted[1U] 
            = __Vtemp_163[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted[2U] 
            = __Vtemp_163[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted[3U] 
            = (0xfffffffU & __Vtemp_163[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_x[0U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__x_mant[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_x[1U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__x_mant[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_x[2U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__x_mant[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_x[3U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__x_mant[3U];
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_x[0U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y[0U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_x[1U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y[1U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_x[2U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y[2U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[3U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_x[3U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y[3U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c1[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_x[0U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y[0U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y[0U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_x[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c1[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_x[1U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y[1U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y[1U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_x[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c1[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_x[2U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y[2U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y[2U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_x[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c1[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_x[3U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y[3U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_y[3U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_m[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_x[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_187, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s2[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[0U] 
            ^ __Vtemp_187[0U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s2[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[1U] 
            ^ __Vtemp_187[1U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s2[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[2U] 
            ^ __Vtemp_187[2U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s2[3U] 
        = (0x7fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[3U] 
                           ^ __Vtemp_187[3U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_190, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c1, 1U);
    VL_SHIFTL_WWI(127,127,32, __Vtemp_192, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c2[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[0U] 
             & __Vtemp_190[0U]) | (__Vtemp_192[0U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c2[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[1U] 
             & __Vtemp_190[1U]) | (__Vtemp_192[1U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c2[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[2U] 
             & __Vtemp_190[2U]) | (__Vtemp_192[2U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c2[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[3U] 
             & __Vtemp_190[3U]) | (__Vtemp_192[3U] 
                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[3U]));
}
